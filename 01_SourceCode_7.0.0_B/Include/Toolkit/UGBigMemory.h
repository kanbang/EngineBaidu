#ifndef _UGUGBIGMEMORY
#define _UGUGBIGMEMORY

#include "Stream/ugdefs.h"
#include "Toolkit/UGToolkit.h"

#define UGBIGMEM_MAX_SEG_COUNT	16		// Ĭ�����ֶ���
#define UGBIGMEM_MINI_SEG_SIZE	4194304	// Ĭ����С�ֶδ�С4M
#define UGBIGMEM_ALIGN_SIZE	128			// UGBIGMEM_MAX_SEG_COUNT * 8
#define UGBIGMEM_ALIGN(size)	(((size) + (UGBIGMEM_ALIGN_SIZE-1)) & ~(UGBIGMEM_ALIGN_SIZE-1))

namespace UGC
{

class  UGBigMemoryException
{
};

template<class T>
class UGEXPORT UGBigMemory
{
private:
	UGBigMemory(UGBigMemory &);
	UGBigMemory& operator=(UGBigMemory &);
public:
	UGBigMemory(UGSizeT size)
	{
		//����ʼ���ڴ������Ϊ��
		if(size == 0)
		{
			m_nSegCount = m_nSegSize = m_nSize = m_nSegEleCount = 0;
			return;
		}

		UGSizeT nNeedCount = sizeof(T) * size;
		// ��ֱ�ӷ���,�ܷ��������ֱ������
		UGbyte *pTemp = NULL;
		try
		{
			pTemp = new UGbyte[nNeedCount];	
			m_pMemArray[0] = pTemp;
			m_nSegCount = 1;
			m_nSegSize = nNeedCount;
			m_nSize = m_nSegEleCount = size;
			return;
		}
		catch (std::exception &)
		{
			pTemp = NULL;
		}

		UGSizeT nAvailableMemory = UGToolkit::GetAvailablePhysicalMemory();
		if((nNeedCount>>10) >= nAvailableMemory)		// nAvailableMemory��λ��KB
		{
			m_nSegCount = m_nSegSize = m_nSize = m_nSegEleCount = 0;
			return;
		}
		// �����ڴ�ֶ�
		// ��Ҫ���ڴ�С����С��,�����滹û�������,ֱ����Ϊʧ��
		if(nNeedCount <= UGBIGMEM_MINI_SEG_SIZE)
		{
			m_nSegCount = m_nSegSize = m_nSize = m_nSegEleCount = 0;
			return;
		}
		else 
		{
			nNeedCount = UGBIGMEM_ALIGN(nNeedCount);
			m_nSegCount = (nNeedCount + UGBIGMEM_MINI_SEG_SIZE - 1) / UGBIGMEM_MINI_SEG_SIZE;
			// �ֶ�������Ĭ�Ϸֶ�����,�������ֶ�ʱ,��߷����Ĵ�С
			if(m_nSegCount > UGBIGMEM_MAX_SEG_COUNT)
			{
				m_nSegCount = UGBIGMEM_MAX_SEG_COUNT;
				m_nSegSize = nNeedCount / UGBIGMEM_MAX_SEG_COUNT;
			}
			else
			{
				m_nSegSize = UGBIGMEM_MINI_SEG_SIZE;
			}

		}
		// 		memset(m_pMemArray, 0, sizeof(void*) * UGBIGMEM_MAX_SEG_COUNT);
		// 		memset(m_pMemAllocIdx, 0, UGBIGMEM_MAX_SEG_COUNT);

		// �����ڴ�,�ȳ��԰���������� 
		UGSizeT nCount=0, idx = 0, offset = 0, blockSize = m_nSegCount>>1;
		bool bSucceed = FALSE;
		while(TRUE)
		{
			if(nNeedCount < m_nSegSize)
			{
				// FAIL
				break;
			}

			try
			{
				pTemp = new UGbyte[nNeedCount];
				offset = 0;
				for(UGSizeT i = 0; i < blockSize ; i++)
				{
					if(idx == m_nSegCount)
					{
						bSucceed = TRUE;
						break;
					}
					m_pMemArray[i+idx] = pTemp + offset;
					offset += m_nSegSize;
				}	
				m_pMemAllocIdx[nCount] = idx;
				nCount ++;
				idx += blockSize;
				if(idx == m_nSegCount)
				{
					bSucceed = TRUE;
					break;
				}
			}
			catch (std::exception &)
			{
				nNeedCount = (blockSize>>1)*m_nSegSize;
				blockSize = (blockSize>>1);
			}
		}
		if(nCount != UGBIGMEM_MAX_SEG_COUNT)
		{
			m_pMemAllocIdx[nCount] = 0;
		}
		if(!bSucceed)
		{
			ReleaseAll();
			return;
		}
		m_nSize = size;
		m_nSegEleCount = m_nSegSize / sizeof(T);
	}
	~UGBigMemory()
	{
		ReleaseAll();
	}

public:
	UGSizeT GetBytesCount() const
	{
		return sizeof(T) * m_nSize;
	}

	T& operator[](UGSizeT idx)
	{
		if(idx >= m_nSize)
		{
			throw UGBigMemoryException();
		}
		return *(T*)Locate(idx);
	}

	T Get(UGSizeT idx)
	{
		if(idx >= m_nSize)
		{
			throw UGBigMemoryException();
		}
		return (*this)[idx];
	}

	void Set(UGSizeT idx, T& value)
	{
		if(idx >= m_nSize)
		{
			throw UGBigMemoryException();
		}
		(*this)[idx] = value;
	}

	void Set(UGSizeT idx, T value)
	{
		if(idx >= m_nSize)
		{
			throw UGBigMemoryException();
		}
		(*this)[idx] = value;
	}

	void ReleaseAll()
	{
		if(m_nSegCount == 0)
		{
			return;
		}
		for(UGSizeT i = 1; i <  m_nSegCount; i++)
		{
			if(m_pMemAllocIdx[i] == 0)
			{
				break;
			}
			delete []m_pMemArray[m_pMemAllocIdx[i]];
		}
		if(m_pMemArray[0] != NULL)
		{
			delete []m_pMemArray[0];
		}
		// 		memset(m_pMemArray, 0, sizeof(void*) * UGBIGMEM_MAX_SEG_COUNT);
		// 		memset(m_pMemAllocIdx, 0, UGBIGMEM_MAX_SEG_COUNT);
		m_nSize = 0;
		m_nSegSize = 0;
		m_nSegCount = 0;
	}

public:
	static void *Copy( void *dest, const UGBigMemory &src, UGSizeT size )
	{
		if(src.GetBytesCount() < size)
		{
			throw UGBigMemoryException();
		}
		// 		return memcpy(dest, src.m_pMem, size);
		void *pCursor = 0;
		UGSizeT nPos = 0, nTmpSize = 0;
		for(UGSizeT i = 1; i < src.m_nSegCount; i++)
		{
			nTmpSize = (i-nPos)*src.m_nSegSize;
			if(&src.m_pMemArray[i] != &src.m_pMemArray[nPos] + nTmpSize)
			{
				memcpy((UGbyte*)dest+nPos*nTmpSize, src.m_pMemArray[nPos], nTmpSize);
				nPos = i;
			}
		}
		return dest;
	}
	// 	static UGBigMemory& Copy( UGBigMemory &dest, const void *src, UGSizeT size )
	// 	{
	// 		if(dest.GetBytesCount() < size)
	// 		{
	// 			throw UGBigMemoryException();
	// 		}
	// 		memcpy(dest.m_pMem, src, size);
	// 	}
	// 	static UGBigMemory& Copy( UGBigMemory &dest, const UGBigMemory &src, UGSizeT size )
	// 	{
	// 		if(src.GetBytesCount() < size || dest.GetBytesCount() < size)
	// 		{
	// 			throw UGBigMemoryException();
	// 		}
	// 		memcpy(dest.m_pMem, src.m_pMem, size);
	// 	}
private:
	
	// ��λidx��Ӧ���ڴ�λ��
	T* Locate(UGSizeT idx)
	{
		return (m_nSegCount > 1) ? ((T*)(m_pMemArray[idx/m_nSegEleCount]) + idx%m_nSegEleCount) : ((T*)(m_pMemArray[0]) + idx);
	}
private:
	// ����������
	void *m_pMemArray[UGBIGMEM_MAX_SEG_COUNT];
	// �ڴ�η�������
	UGbyte m_pMemAllocIdx[UGBIGMEM_MAX_SEG_COUNT];
	// TԪ�ظ���
	UGSizeT m_nSize;
	// �ֶεĶδ�С
	UGSizeT m_nSegSize;
	// ÿ���ε�Ԫ�ظ���
	UGSizeT m_nSegEleCount;
		// �ֶ���
	UGSizeT m_nSegCount;
};

}
#endif
