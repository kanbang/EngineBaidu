// UGImgBlocksManager.h: interface for the UGImgBlockManager class.
//
//////////////////////////////////////////////////////////////////////
/* 
	\file UGImgBlocksManager.h
	\brief ������߳�Block������
	\author ������
	\attention �̰߳�ȫ
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

//////////////////////////////////////////////////////////////////////////
//!  \file UGImgBlocksManager.h
//!  \brief UGImgBlocksManager �Ľӿڶ��塣
//!  \details UGImgBlocksManager����Ӱ�����ݼ��Ļ���ӿڶ��塣
//!  \Modified Date: 2013-4-7
//!  \Modified Author:Conversion-zby
//!  \Details Comments:����UGImgBlocksManager�ӿڲ����Լ��ӿ����,��ҪĿ�����ڻ���ӿ�����Ӷ��ڶನ��դ�����ݼ�����չ֧��;
//!  \Details Comments:���ε�����Ҫ��������������:(1) ����ԭ�нӿ����Ӳ�����������֧��;(2)�����޸�դ�����ݼ��Լ��ನ��դ�����ݼ�
//!  \Details Comments:���ڻ���ӿڹ��õ���ʽ!
//!  \Details Comments:�˴ε����漰����դ�����ݼ��ṹ�ĵ��������ڼ�����Աˮƽ�����Լ�ʱ��Ĳִ٣�����������������������,������
//!  \Details Comments:����Conversion-zby��ϵ!
//!  \Version OGDC-1-1(2013-4-7)


#if !defined(AFX_UGIMGBLOCKMANAGER_H__1A2DC698_B9F7_40D2_8DE3_2C83B9380D68__INCLUDED_)
#define AFX_UGIMGBLOCKMANAGER_H__1A2DC698_B9F7_40D2_8DE3_2C83B9380D68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugdefs.h"
#include "Geometry/UGDataCodec.h"
#include "Toolkit/UGThread.h"

namespace UGC {

class UGDatasetRaster;
class UGImgBlocksManager;
class UGImgBlockRef;

//##ModelId=48203050030E
class ENGINE_API UGImgBlocksManager  
{
	friend class UGDatasetRasterCollectionUdb;

public:
	//!	\brief	����ģʽ��cmNoCache��ʾ������Ӱ��飬cmCacheBlocks���沿��Ӱ������ڴ��У�
	//!	\remark	Ӧ��ά�����󣬵���Block���������ƣ����Ӳ������ģʽ��cmNoCache����cmNoCacheģʽ��
	//			Ӱ��齫ֱ�ӴӴ��̶�ȡ
	enum CacheMode { cmNoCache = 0, cmCacheBlocks = 1 };

	//�ڴ����ģʽ
	enum MemoryAdjustMode{		
		Seq = 0,				//���϶��µ���
		Rev = 1,				//���¶��ϵ���
		//Dual = 2,				//˫�����
		Protect = 3				//��������������
	};

public:
	//##ModelId=48203050031C
	UGImgBlocksManager();
	//##ModelId=48203050031D
	UGImgBlocksManager(UGDatasetRaster *pDtRaster, CacheMode cm = cmNoCache);

	UGImgBlocksManager(const UGImgBlocksManager& ImgBlocksManager);
	
	//! \brief 		���� = 	
	UGImgBlocksManager& operator=(const UGImgBlocksManager& ImgBlocksManager);

	//##ModelId=48203050031F
#ifdef SYMBIAN60
	~UGImgBlocksManager();
#else
	virtual ~UGImgBlocksManager();
#endif

	//! \brief ����ָ���Ļ����Block
	//! \param y [in] ���ݿ���ĵڼ��� ��Ӧ����ΪSmColumn
	//! \param x [in] ���ݿ���ĵڼ��� ��Ӧ���ݿ����SmRow
	//! \param *pImgBlock [out] ������ָ��
	//! \param nBandIndex[in] ��ȡ��ɫ��ֵ���ڵĲ�������ֵ��Ĭ��Ϊ0
	//! \return  ÿ���߳�ά���Լ����ڴ�
	//! \remarks �����ǰλ���Ѿ��������ݵ�ָ�룬��ôɾ��֮
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \attention 
	//##ModelId=482030500321
	UGbool SetBlockAt(UGint y,UGint x,UGImgBlock *pImgBlock,UGint nBandIndex=0);

	//! \brief ����ָ���Ļ����Block
	//! \param nIndex [in] Position
	//! \param *pImgBlock [in] ImgBlock
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \return ��
	//! \remarks ��
	//! \attention ��
	//##ModelId=48203050032C
	UGbool SetBlockAt(UGint nIndex,UGImgBlock *pImgBlock,UGint nBandIndex=0);	

	//! \brief �õ�ָ���Ļ����Block
	//! \param y [in] ���ݿ���ĵڼ��� ��Ӧ����ΪSmColumn
	//! \param x [in] ���ݿ���ĵڼ��� ��Ӧ���ݿ����SmRow
	//! \param *pImgBlock [out] ���ص�ָ��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \return ÿ���߳�ά���Լ����ڴ�
	//! \remarks 
	//! \attention 
	//##ModelId=48203050032F
	UGImgBlock * GetBlockAt(UGint y,UGint x,UGint nBandIndex=0);
	

	//! \brief ��ȡָ�����кŵ�Block���������ڷ���NULL
	//! \param nRow [in] ��
	//! \param nCol [in] ��
	//! \return ��
	//! \remarks ��GetBlockAt�����𣺲�ȥȡ���ݡ�
	//! \attention ��
	//##ModelId=482030500332
	UGImgBlock * GetAt(UGint nRow, UGint nCol);		

	
	//! \brief �õ�ָ��λ�õĻ���Block
	//! \param nIndex [in] һά�����λ�ã���nIndex��Ӱ�������λ���޹�
	//! \return ��
	//! \remarks ��
	//! \attention ע�⣺����Ǹ����������ֵ䡢���飩���±�ȥȡBlock,ʵ��Ϊ����ʹ�ã���Ϊ��λBlcok��
	//##ModelId=482030500332
	UGImgBlock * GetAt(UGint nIndex);		

	//! \brief ��ȡ����ָ��ļ��ϵĳ���
	UGuint  GetSize();	

	//! \brief �ͷŵ�ǰ�̻߳��������
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \return TRUE 
	//! \remarks 
	//! \attention ���Block�޸��ˣ�Ҫ�����޸ĵ����ݿ�
	//##ModelId=482030500334
	UGbool ReleaseBlocks(UGint nBandIndex=0);

	//! \brief ����ָ��������ɾ������Ӱ���
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \return TRUE 
	//! \remarks 
	//! \attention ���Block�޸��ˣ�Ҫ�����޸ĵ����ݿ�
	UGbool ReleaseBlock(UGint index,UGint nBandIndex=0);

	//! \brief ����UDBդ�����ݼ���׷�ӵ�ʱ��
	//! \return TRUE 
	//! \remarks 
	//! \attention ���Block�޸��ˣ�Ҫ�����޸ĵ����ݿ�
	//##ModelId=482030500334
	UGbool ReleaseBlocksForUDBRaterAppend();

	UGbool SaveBlocksForUDBRasterAppend();

	//! \brief �������е�block��
    //! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0	
	UGbool SaveAllBlocks(UGint nBandIndex=0);

	//! \brief �������е�block��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	UGbool SaveBlock(UGImgBlock* pImgBlock,UGint nBandIndex=0);

	//�ڴ����
	UGulong GetBestMemo();

	//! \brief �����ڴ�
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \return �ɹ�����true��ʧ�ܷ���false
	UGbool AdjustMemory(UGint nBandIndex=0);

	//! \brief ˳������ڴ棺��ǰ����
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \return �ɹ�����true��ʧ�ܷ���false
	UGbool AdjustMemorySeq(UGint nBandIndex=0);

	//! \brief  ��������ڴ棺�Ӻ���ǰ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \return �ɹ�����true��ʧ�ܷ���false
	UGbool AdjustMemoryRev(UGint nBandIndex=0);

	//�÷���������������еĻ���飬û�б�Ҫ��ȡ���еĻ����ָ������
	//GetBlockAt�Ϳ�����
	//! \brief �õ����е�Img��ָ��Ϊ�˿��ٱ���Щ����
	//! \return TRUE
	//! \remarks ���ص�ָ��ֻ��������ɾ��
	//! \attention ��
	//##ModelId=48203050033C
	//UGImgBlock** GetAllBlocks(UGuint &nSize);

	//! \brief ��ʼ����
	//! \param *pDataset [in]��
	//! \param FALSE [in]��
	//! \return True
	//! \remarks Ĭ����֧�ֶ��̵߳ģ�������SDB���治֧����ô���ò�֧�ַ�ʽ������
	//! \attention ��
	//##ModelId=48203050033D
	UGbool SetDataset(UGDatasetRaster *pDataset,UGbool bSingleThread = FALSE);	

	UGDatasetRaster* GetDataset();

	//!	\brief	�����ڴ����ģʽ��Ŀǰ֧�ִ������ºʹ�����������ģʽ��Ĭ���Ǵ������µ���
	//!	\remark	���Ը��ݲ�ͬ����Ҫ���ò�ͬ���ڴ����ģʽ
	void SetMemoryAdjustMode(MemoryAdjustMode md);	
	
	UGbool StatisticsBlocks( UGArray<UGImgBlock*> & updateBlocks ,UGArray<UGImgBlock*> & insertBlocks );

	MemoryAdjustMode GetMemoryAdjustMode(){return m_nMemoMode;};
	
	void BMReleaseBlockRef(UGImgBlock* pImgBlock);
	
	UGbool BMFindBlock(UGint y,UGint x,UGImgBlock*& pImgBlock,UGint nBandIndex);

	void BMAddToLRUList(UGImgBlock* pImgBlock);
	
	void BMRemoveFromLRUList(UGImgBlock* pImgBlock);

	inline UGint BMGetRecyclableCount() { return m_nRecyclableCount; };

protected:

	// LRU�����е�Ӱ����������ɻ��յ�Ӱ�����
	UGint m_nRecyclableCount;

	// LRU����ͷ
	UGImgBlock* m_pLruHead;

	// LRU����β
	UGImgBlock* m_pLruTail;

	//����ڴ��Ƿ��㹻
	UGbool CheckMemeoryEnough();

	//դ�����ݼ���ָ��
	UGDatasetRaster *m_pRaster;

	UGDict<UGlong,UGImgBlock*> m_dictBlocks;

	//�����Block������
	//UGDict<UGint,UGImgBlock*> m_aryPos;
	UGImgBlock** m_aryPos;

	//��¼��Ҫ���µ�Block������
	UGArray<UGImgBlock*> m_tempAryPos;

	//��С�ڴ���ֵ
	UGulong m_dwMemoLimited;

	//�����Block������Ĵ�С
	UGuint m_nArraySize;

	//�ڴ��ʹ��
	UGuint m_dwMemoUsed;

	MemoryAdjustMode m_nMemoMode;	

	//�ܵĵ�ǰBlockManager���ڴ�ʹ��
	UGuint m_nTotal;

	//! \brief �������
	UGMutex m_mutex;

	//!	\brief	����ģʽ
	CacheMode m_eCacheMode;

// 	//!	\brief	cmNoCacheģʽ�¼�¼��ǰȡ�õ�Ӱ���
// 	UGImgBlock *m_pImgBlock;
// 
// 	//!	\brief	cmNoCacheģʽ�¼�¼��ǰȡ�õ�Ӱ������������ݼ��е�����
// 	UGint m_nImgBlckIndex;

	private:
		//!	\brief	���û���ģʽ������ģʽӦ�����ʵ������Block���������ʱ���ã�ʹ�ù����в�Ӧȥ�����ģ�
		//!	\remark	����SetDataset֮ǰ���úû���ģʽ
		void SetCacheMode(CacheMode cm);
};

}

#endif // !defined(AFX_UGIMGBLOCKMANAGER_H__1A2DC698_B9F7_40D2_8DE3_2C83B9380D68__INCLUDED_)

