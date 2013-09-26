/* 
	\file UGSpatialIndex.h
	\brief	�������������һ��
			���������Ĵ������ؽ���ɾ��
			������������֮ǰ�����ݵķ������������������������Լ���������Ӧ��
			���������Ƿ�֧��ĳ�������Ŀ���

	\author ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
*/
	// UGSpatialIndex.h: interface for the UGSpatialIndex class.
//
//////////////////////////////////////////////////////////////////////
#ifndef UGSPATIALINDEX_H
#define UGSPATIALINDEX_H

#include "Stream/ugdefs.h"
#include "Engine/UGDatasetVector.h"
#include "SpatialIndex/UGSpatialIndexInfo.h"
#include "Toolkit/UGProgress.h"

namespace UGC {
#if !defined SYMBIAN60 && !defined  OS_ANDROID 
class UGDBRTree;
#endif
//##ModelId=482030500148
#ifdef SYMBIAN60
class ENGINE_APIC UGSpatialIndex
#else
class ENGINE_API UGSpatialIndex
#endif
{
	friend class UGDatasetVector;
#if !defined SYMBIAN60 /*&& !defined  OS_ANDROID */
	friend class UGDBRTreeBranch;
	friend class UGDBRTreeLeaf;	
#endif
public:
	//##ModelId=482030500149
	ENGINE_APIF UGSpatialIndex();

	//##ModelId=48203050014A
	ENGINE_APIF UGSpatialIndex(UGDatasetVector *pDataset);
	//##ModelId=482030500157
	virtual ENGINE_APIF ~UGSpatialIndex();

public:	
	///////////////////////	DatasetVecotor���õķ��� ///////////////////////////////////////////////////

	//! \brief ��������
	//! \param *pDataset [in]��
	//! \return
	//! \remarks
	//! \attention 
	//##ModelId=482030500159
	ENGINE_APIF UGbool BuildSpatialIndex(UGSpatialIndexInfo &spatial);

	//! \brief ɾ������
	//! \param *pDataset [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	//##ModelId=482030500168
	ENGINE_APIF UGbool DropSpatialIndex();
#if !defined SYMBIAN60 /*&& !defined  OS_ANDROID */
	//! \brief ���ݵ�ǰ����״̬�ؽ�����
	//! \param *pDataset [in]��
	//! \return
	//! \remarks
	//! \attention 
	//##ModelId=48203050015B
	ENGINE_APIF UGbool ReBuildSpatialIndex();

	//! \brief �����ݵĿռ���������
	//! \param *pDataset [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	//##ModelId=482030500167
	ENGINE_APIF UGbool UpdateSpatialIndex();

	//! \brief �����Ƿ�����
	//! \param *pDataset [in]��
	//! \return ��
	//! \remarks TRUE ��ʾ�ࣻ���򣬲���
	//! \attention ��
	//##ModelId=48203050016A
	ENGINE_APIF UGbool IsSpatialIndexDirty();
	
	//! \brief ���� RTree
	//##ModelId=483BB70800DA
	ENGINE_APIF UGbool LoadDBRTree(UGMemoryStream& stream);

	//! \brief ����Ŀ�����ݼ�
	//##ModelId=48203050016B
	ENGINE_APIF UGbool SetDataset(UGDatasetVector* pDataset);
	
	//##ModelId=482030500178
	ENGINE_APIF UGDatasetVector* GetDataset();

	//! \brief �༭��������ĸ������, pGeometry ֻ�ڶ༶��������ʱ����ǿգ���������NULL
	//##ModelId=483BB70800EA
	ENGINE_APIF UGbool UpdateIndexItem(UGint nID, const UGint nEditState, UGGeometry *pGeometry,
			   const UGRect2D &rc2Org, const UGRect2D &rc2New);

	//! \brief R�������Ĵ�С
	ENGINE_APIF UGint GetMaxIndexSize();

	ENGINE_APIF UGbool SetMaxIndexSize(UGint nMaxSize);
	///////////////////////	DatasetVecotor���õķ��� ///////////////////////////////////////////////////
	
	//! \brief ��ǰ���ݼ��Ƿ������֧��
	//! \param *pDataset [in]��
	//! \param nIdxType [in]��
	//! \return 
	//! \remarks 
	//! \attention 
	//##ModelId=482030500179
	virtual ENGINE_APIF UGbool IsSupported(IndexType nIdxType);

	//##ModelId=482030500186
	ENGINE_APIF UGbool AnalyzeDataset(UGSpatialIndexInfo &info);
	
	//##ModelId=482030500188
	ENGINE_APIF UGshort RecommendSpatialIndexLevel();

	// fansc Add 2011-12-16
	//! \brief ��ѯR���������Ķ���ID
	//! \brief nLeafID    ��������ID[in]
	//! \brief aryIDs     �������Ķ���ID[out]
	virtual ENGINE_APIF UGbool GetIDsInLeaf(UGint nLeafID, UGArray<UGint>& aryIDs);


protected:
	//! \brief R����������
	//! \remarks ����Ҫ����
	//##ModelId=483BB70800F0
	ENGINE_APIF UGbool StoreRTreeTrunk(UGStream &stream);

	//! \brief ȡR��Ҷ�ӽ��
	//##ModelId=483BB70800FA
	virtual ENGINE_APIF UGint LoadRTreeLeaf(UGint nID,UGStream &stream);
	
	//! \brief �洢R��Ҷ�ӽ��
	//##ModelId=483BB70800FE
	virtual ENGINE_APIF UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);
		
	//! \brief ȡ������Geometry��ID�����������R���������ڽ���R������ʱ����
	//##ModelId=483BB7080109
	virtual ENGINE_APIF void GetAllNodeItems(UGDBRTreeNodeItems &NodeItems,
		UGProgress *pProgress,UGString strSort);
	
	//! \brief ͨ��ָ��ͼ���Ĵ�С��������������
	//##ModelId=483BB708010E
	virtual ENGINE_APIF UGbool RegisterLibraryByGridSize(UGdouble dWidth, UGdouble dHeight);
	
	//! \brief ͨ��ָ�����Ƶ��ֶ���������������
	//##ModelId=483BB708011A
	virtual ENGINE_APIF UGbool RegisterLibraryByField(const UGString &strFieldName);

	//! \brief �����༶��������
	//##ModelId=483BB708011D
	virtual ENGINE_APIF UGbool BuildSpatialIndexDynamic(UGSpatialIndexInfo &spatial);
	
	//! \brief �����Ĳ�������
	//##ModelId=483BB7080120
	virtual ENGINE_APIF UGbool BuildSpatialIndexQTree(UGSpatialIndexInfo &spatial);
	
	//! \brief ����������Ϣ
	//##ModelId=483BB708012A
	virtual ENGINE_APIF UGbool SaveIndexInfo();

	//! \brief ���ؿռ�������ļ�¼����Ŀ��Ϊ�Ƿ���Ҫ�ؽ��ռ������ṩ�ο�
	//##ModelId=483BB708012C
 	virtual ENGINE_APIF UGint GetDirtyRecordCount();

	//! \brief Drop�ռ�����ʱʹ��
	//##ModelId=483BB708012E
	virtual ENGINE_APIF UGbool ClearDynamicIndex();

	//##ModelId=483BB7080139
	virtual ENGINE_APIF UGbool ClearRTreeIndex();

	//##ModelId=483BB708013B
	virtual ENGINE_APIF UGbool ClearQTreeIndex();

	////////////////	�༭ʱ��������	//////////////////////////
	//! \brief				����RTree����Ҷ�ڵ�
	//! \param nID			���µļ�¼��ID
	//! \param nEditState	�Լ�¼�����ĸ��²���	
	//! \param rc2Org		��¼ԭ����Bounds
	//! \param rc2Des		��¼�µ�Bounds��ֻ��SetGeometryʱrc2Org��rc2Dest��ͬ
	//! \return				���������Ĳ����ɹ����
	//##ModelId=483BB708013D
	virtual ENGINE_APIF UGbool UpdateRTreeItem(	UGint nID, const UGint nEditState, 
		const UGRect2D &rc2Org, const UGRect2D &rc2New);

	//! \brief ����ͼ��������ͼ����Ϣ
	//##ModelId=483BB708014D
	virtual ENGINE_APIF UGbool UpdateLibVersion(const UGuint dwLibID, const UGint nID, 
		const UGint nEditMode, const UGRect2D &rc2New);
	
	//! \brief ���¶༶��������
	//##ModelId=483BB7080159
	virtual ENGINE_APIF UGbool UpdateDynamicIdx(UGint nID, const UGint nEditMode, UGGeometry *pGeometry);
	
	//! \brief ���´��Ĳ�������
	//##ModelId=483BB708015E
	virtual ENGINE_APIF UGbool UpdateQTreeIdx(UGint nID, const UGint nEditMode, const UGRect2D &rc2New);

	//���·����� BuildSpatialIndex �е��ã����ڽ�����ͬ���͵�����	
	//! \brief ����R������
	//##ModelId=483BB708016A
	virtual ENGINE_APIF UGbool BuildSpatialIndexRTree(UGSpatialIndexInfo &spatial);

	////////////////	�༭ʱ��������	//////////////////////////
private:
	//##ModelId=482030500189
	ENGINE_APIF UGbool IsNeedBuiltIndex();

	//! \brief ����ͼ������
	//##ModelId=483BB7080178
	ENGINE_APIF UGbool BuildSpatialIndexTile(UGSpatialIndexInfo &spatial);
	
	//##ModelId=48203050018A
	ENGINE_APIF UGbool ConfigIndexByDataDistributing(UGSpatialIndexInfo &info);

public:
	//##ModelId=483BB70801A6
	UGDBRTree* m_pRTreeIndex;

protected:
	//##ModelId=483BB70801B5
	UGint m_nMaxIndexSize;	
#endif

protected:
	//##ModelId=482030500196
	UGDatasetVector* m_pDataset;
};
}

#endif // !defined(AFX_UGSPATIALINDEX_H__AAA6D3A9_BE41_415A_8BB9_122FF427F2D0__INCLUDED_)

