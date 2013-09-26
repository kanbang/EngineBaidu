#ifndef UGIMGBLOCKREF_H
#define UGIMGBLOCKREF_H

#include "Engine/ugeng.h"
#include "Engine/UGEngDefs.h"
#include "Engine/UGDatasetRaster.h"

namespace UGC
{	
	class ENGINE_API UGImgBlockRef
	{
	public:
		UGImgBlockRef();
		//! \brief Ĭ�Ϲ��캯��
// 		UGImgBlockRef(UGImgBlock *pImgBlock);
		//! \brief Ĭ����������
#ifdef SYMBIAN60
	~UGImgBlockRef();
#else
	virtual ~UGImgBlockRef();
#endif

		//! \brief ��ȡImgBlockָ��
		inline UGImgBlock *GetImgBlock() { return m_pImgBlock; }	
		inline UGint GetPreBandIndex() { return m_nBandIndex; }

		inline void SetImgBlock(UGImgBlock *pImgBlock, UGDatasetRaster* pRaster = NULL, UGint nBandIndex = 0)
		{
			m_pRaster = pRaster;
			m_pImgBlock = pImgBlock;
			m_nBandIndex = nBandIndex;
			if (pImgBlock != NULL)
			{
				pImgBlock->AddRefCount();
			}
		}

	private:
		UGImgBlock *m_pImgBlock;

		UGDatasetRaster* m_pRaster;
		UGint m_nBandIndex;
	};
}
#endif

