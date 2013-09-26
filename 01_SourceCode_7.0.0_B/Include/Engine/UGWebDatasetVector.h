//////////////////////////////////////////////////////////////////////////
//!  \file UGWebDatasetVector.h:
//!  \brief UGWebDatasetVector ʧ���͵��������ݼ���Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br>
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////
#if !defined(AFX_UGWEBDATASETVECTOR_H__1339C8A2_FB74_4AC0_B82A_42284D72C19E__INCLUDED_)
#define AFX_UGWEBDATASETVECTOR_H__1339C8A2_FB74_4AC0_B82A_42284D72C19E__INCLUDED_

#include "Engine/UGDataset.h"
#include "Engine/UGDatasetVector.h"
#include "Engine/UGRecordset.h"
#include "Engine/UGDatasetVectorInfo.h"

namespace UGC{

//! \brief ʧ���͵��������ݼ��ࡣ
class ENGINE_API UGWebDatasetVector :public UGDatasetVector
{
public:
	UGWebDatasetVector();
	UGWebDatasetVector(UGDatasetVectorInfo& vInfo);

	virtual ~UGWebDatasetVector();


public:
		//!�����ж���Ĵ��麯��
		
		//! \brief �����ݼ���
		//! \return �򿪳ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool Open();
		
		//! \brief �ر����ݼ���
		//! \remarks ��
		//! \attention ��
		virtual void Close();
		
		//! \brief �������ݼ���Ϣ��
		//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool SaveInfo();
		
		//! \brief ˢ�����ݼ���Ϣ��
		//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool RefreshInfo();
		
		//! \brief �������ݼ���
		//! \param strName ���ݼ���[in]��
		//! \param *pDatasetParent ���ݼ���������Դ��ָ��[in]��
		//! \param vInfo ʧ�����ݼ�����[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		UGbool Create(const UGString & strName, 
			UGDataset *pDatasetParent,
			const UGDatasetVectorInfo & vInfo);
		
		//! \brief �õ�������ʱ�䡣
		//! \return ������ʱ�䡣
		//! \remarks ��
		//! \attention ��
		virtual UGTime GetDateLastUpdated();
		
		//! \brief �õ�����ʱ�䡣
		//! \return ����ʱ�䡣
		//! \remarks ��
		//! \attention ��
		virtual UGTime GetDateCreated();
		
		
		//! \brief ���ݼ���������
		//! \param strNewName [in]��
		//! \return �������ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ֻ�ı����ݼ���,�������䡣
		//! \attention ��
		virtual UGbool Rename(const UGString& strNewName);		
		
		//! \brief ��ѯ���ͼ����һ��ͼ��������
		//! \param nLibTileID ͼ����[in]��
		//! \param arFields �ֶ�������[in]��
		//! \return ��¼��ָ�롣
		//! \remarks ��
		//! \attention ��
		virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
			UGArray<UGString> & arFields,UGdouble dGranule);
		
		//! \brief ��
		//! \param rc2SearchBounds [in]��
		//! \param strLibTile [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		UGbool GetLibTileSQL(const UGRect2D& rc2SearchBounds,
			UGString& strLibTile);
		
		//! \brief ͨ�����η�Χ��ѯͼ����š�
		//! \param rc2Bounds ���ݼ��ķ�Χ[in]��
		//! \param arLibTileIDs [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
			UGArray<UGint>& arLibTileIDs);
		
		//! \brief �õ�һ��ͼ������Ϣ��
		//! \param nTileID ͼ����[in]��
		//! \param rc2TileBounds ���ݼ��ķ�Χ[in]��
		//! \param nRecCount [in]��
		//! \param nVersion [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
			UGint& nRecCount,UGint& nVersion);
		
		
		//! \brief ����������,ǩ����
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CheckOut();
		
		//! \brief ����������,ǩ�롣
		//! \param bKeepCheckedOut [in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CheckIn(UGbool bKeepCheckedOut);
		
		//! \brief ����������,����ǩ����
		//! \param bKeepCheckedOut [in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);
		
		//! \brief �õ��������û���ID��
		//! \return �������û���ID��
		//! \remarks ��
		//! \attention ��
		UGint GetLockedUserID();
		
		//! \brief �õ�ǩ���û���ID��
		//! \return ǩ���û���ID��
		//! \remarks ��
		//! \attention ��
		UGint GetCheckedUserID();
		
		
		//! \brief ͨ����ֵ���������ֶ�ֵ��
		//! \param strFieldName Ҫ���µ��ֶ�����
		//! \param varValue Ҫ���µ��ֶ�ֵ��
		//! \param strFilter ��������Where Info ����"Where �ؼ���"��
		//! \return ���³ɹ�����TRUE,ʧ�ܷ���FALSE ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool UpdateField(const UGString& strFieldName,
			const UGVariant& varValue,const UGString& strFilter = _U(""));
		
		//! \brief ͨ�����ʽ�����ֶ�ֵ��
		//! \param strFieldName ׼�����µ��ֶ�����
		//! \param strExpress ׼�����µ��ֶ�ֵ��
		//! \param strFilter  ��������Where Info ����"Where �ؼ���",Ĭ��Ϊ�ա�
		//! \return ���³ɹ�����TRUE,ʧ�ܷ���FALSE ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool UpdateFieldEx(const UGString& strFieldName,
			const UGString& strExpress,const UGString& strFilter = _U(""));
		
		
		//! \brief �����ֶ�ֵ��
		//! \param strSrcField Դ�ֶ���[in]��
		//! \param strDestField Ŀ���ֶ���[in]��
		//! \return ���Ƴɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CopyField(const UGString& strSrcField,
			const UGString& strDestField);
		
		//! \brief ͨ��ָ��ͼ���Ĵ�С����������������
		//! \param &rc2TileBounds ͼ���߽�[in]��
		//! \param bShowProgressCtrl �Ƿ���ʾ������,Ĭ����ʾ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool BuildHierarchicalSpatialIndex(const UGRect2D &rc2TileBounds,UGbool bShowProgressCtrl = TRUE);
		
		//! \brief ͨ��ָ����ŵ��ֶ�����������������
		//! \param nFieldIndex �ֶ����[in]��
		//! \param bShowProgressCtrl �Ƿ���ʾ������,Ĭ����ʾ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool BuildHierarchicalSpatialIndex(UGint nFieldIndex,UGbool bShowProgressCtrl = TRUE);
		
		
		//! \brief ͨ��ָ�����Ƶ��ֶ�����������������
		//! \param strFieldName �ֶε�����[in]��
		//! \param bShowProgressCtrl �Ƿ���ʾ������,Ĭ����ʾ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool BuildHierarchicalSpatialIndex(const UGString & strFieldName,UGbool bShowProgressCtrl = TRUE);
		
	
		//! \brief �����ռ�����
		//! \remarks �˷���ֻ�����������Ĳ���������R������,ͼ�������������ĺ���,�����IDXNone
		//!          ��ôĬ���ؽ��Ĳ���������R������
		virtual UGbool BuildSpatialIndex(UGSpatialIndexInfo &spatial);

		//! \brief ���ݵ�ǰ����״̬�ؽ�����
		virtual UGbool ReBuildSpatialIndex();

		//! \brief �����ݵĿռ���������
		//! \param *pDataset [in]��
		//! \return ��
		virtual UGbool UpdateSpatialIndex();
		
		//! \brief ����ռ�������
		//! \return ��������ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool DropSpatialIndex();
		
		//! \brief �Ƿ���Ҫ�ؽ��ռ�������
		//! \return ��Ҫ�ؽ�����TRUE,����Ҫ����FALSE��
		//! \remarks ���ݿռ�������ļ�¼����Ŀ�жϡ�
		//! \attention ��
		virtual UGbool IsSpatialIndexDirty();
		
		//! \brief ���ؿռ�������ļ�¼����Ŀ��Ϊ�Ƿ���Ҫ�ؽ��ռ������ṩ�ο���
		//! \return �ռ�������ļ�¼����Ŀ��
		//! \remarks ��
		//! \attention ��
		virtual UGint GetDirtyRecordCount();
		
		//! \brief ����ͨ������
		//! \param strFieldNameList �����ֶ��б�,���ֶ���Ҫ�� "," ����,���� fld1,fld2,fld3[in]��
		//! \param strIndexName ������[in]��
		//! \return ���������ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CreateIndex(const UGString& strFieldNameList,
			const UGString& strIndexName);
		
		//! \brief ɾ������ ��
		//! \param strIndexName ������[in]��
		//! \return ɾ�������ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool DropIndex(const UGString& strIndexName);
		
		//! \brief R����������,����Ҷ�ڵ㡣
		//! \param nID Ҷ�ڵ�ID[in]��
		//! \param &stream Ҷ�ڵ����ݰ�[in]��
		//! \return ���Ĵ�С��
		//! \remarks ��
		//! \attention ��
		virtual UGint LoadRTreeLeaf(UGint nID,UGStream &stream);
		
		//! \brief R����������,�洢Ҷ�ڵ㡣
		//! \param nID Ҷ�ڵ�ID[in]��
		//! \param &stream Ҷ�ڵ����ݰ�[in]��
		//! \return �洢�ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);
		
		//! \brief R����������,�洢���ڵ㡣
		//! \param &stream ���ڵ����ݰ�[in]��
		//! \return �洢�ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool StoreRTreeTrunk(UGStream &stream);
		
		//! \brief ��
		//! \param SearchBounds [in]��
		//! \param aryItemIDs [in]��
		//! \param aryCertainLeafIDs [in]��
		//! \param aryMaybeLeafIDs [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		UGbool ExtractLeafData(const UGRectUInt& SearchBounds, 
			UGArray<UGint>& aryItemIDs, 
			UGArray<UGint>& aryCertainLeafIDs, 
			UGArray<UGint>& aryMaybeLeafIDs);
		
		//! \brief �õ��ռ������е��ֶ�����
		//! \return �ռ������е��ֶ�����
		//! \remarks ��
		//! \attention ��
		virtual UGString GetGeoColName() const;
		
		//! \brief �Ƿ��м������ݡ�
		//! \return �м������ݷ���TRUE,û�з���FALSE��
		//! \remarks ����Tablur���ݼ������м������ݡ�
		//! \attention ��
		virtual UGbool HasGeometry() const;
		
		//! \brief ��ѯͨ����ڡ�
		//! \param querydef ��ѯ�������[in]��
		//! \return UGRecordset ��¼��ָ�롣
		//! \remarks ��
		//! \attention ��
		virtual UGRecordset* Query(const UGQueryDef& querydef);
		
		//! \brief ��������ֶΡ�
		//! \param fieldInfos �ֶ���Ϣ����[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CreateFields(const UGFieldInfos& fieldInfos);
		
		//! \brief ͨ��FieldInfo�����ֶΡ�
		//! \param fieldInfo �ֶ���Ϣ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CreateField(const UGFieldInfo& fieldInfo);
		
		//! \brief �����ֶΡ�
		//! \param strName �ֶ�����[in]��
		//! \param nType �ֶ�����[in]��
		//! \param nSize �ֶγ���(�ֽ�)[in]��
		//! \param nAttributes �ֶ�����[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CreateField(const UGString& strName,UGFieldInfo::FieldType nType,
			UGint nSize,UGint nAttributes = 0);
		
		//! \brief ͨ���ֶ�����ɾ���ֶΡ�
		//! \param strName �ֶ�����[in]��
		//! \return ɾ���ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool DeleteField(const UGString& strName);
		
		//! \brief ͨ��������ɾ���ֶΡ�
		//! \param nIndex ������[in]��
		//! \return ɾ���ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool DeleteField(UGint nIndex);
		
		//! \brief �ռ������ֶε���Ϣ��
		//! \param fieldInfos �ֶ���Ϣ����[in]��
		//! \param bSystemFieldExcluded �Ƿ��ϵͳ�ֶ��ų�����[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos,
			UGbool bSystemFieldExcluded = FALSE);
		
		//! \brief ͨ���ֶ�����ȡ�ֶ���Ϣ��
		//! \param strName �ֶ�����[in]��
		//! \param fieldInfo �ֶ���Ϣ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetFieldInfo(const UGString& strName,
			UGFieldInfo& fieldInfo);
		
		//! \brief ͨ��������ȡ�ֶ���Ϣ��
		//! \param nIndex ������[in]��
		//! \param fieldInfo �ֶ���Ϣ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetFieldInfo(UGint nIndex,
			UGFieldInfo& fieldInfo);
		
		//! \brief ͨ���ֶ��������ֶ���Ϣ��
		//! \param strName �ֶ���[in]��
		//! \param fieldInfo �ֶ���Ϣ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool SetFieldInfo(const UGString& strName,
			const UGFieldInfo& fieldInfo);
		
		//! \brief ͨ�����������ֶ���Ϣ��
		//! \param nIndex ������[in]��
		//! \param fieldInfo �ֶ���Ϣ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool SetFieldInfo(UGint nIndex,
			const UGFieldInfo& fieldInfo);
		
		//! \brief ��ȡ�ֶθ�����
		//! \return �ֶθ�����
		//! \remarks ��
		//! \attention ��
		virtual UGint GetFieldCount();
		
		//! \brief �����ֶμ�ֵ��
		//! \param strFieldName �ֶ���[in]��
		//! \param dMin ��Сֵ[out]��
		//! \param dMax ���ֵ[out]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CalculateExtremum(const UGString& strFieldName,
			UGdouble& dMin,UGdouble& dMax);
		
		//! \brief ɾ�������������ݡ�
		//! \return ɾ���ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool Truncate();
		
		//! \brief ͳ���ֶ�ֵ��
		//! \param strField Ҫͳ�Ƶ��ֶ�[in]��
		//! \param nMode ͳ�Ʒ�ʽ[in]��
		//! \return ͳ�ƽ��,��UGStatisticModeͳ�Ʒ�ʽ����0��
		//! \remarks ��UGStatisticModeͳ�Ʒ�ʽ����0��
		//! \attention ��
		virtual UGVariant Statistic(const UGString& strField,
			UGStatisticMode nMode);
		
		//! \brief �����ֶε�ֵ������
		//! \param &strFieldName �ֶ���[in]��
		//! \param varKeys ��ͬ��ֵ�ļ���[out]��
		//! \return �����ɹ�����0,ʧ�ܷ��ظ�����
		//! \remarks ��
		//! \attention ��
		virtual UGint CalculateUniqueValues(const UGString &strFieldName,
			UGArray<UGVariant>& varKeys);
		
		//! \brief ������SQL��ѯ��¼����,����Register��
		//! \return �ɹ�����Register����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool ComputeRecCount();
		
		//! \brief ��ȡ���ռ������ֽڴ�С��
		//! \return ���ռ������ֽڴ�С��
		//! \remarks ��
		//! \attention ��
		virtual UGint GetMaxGeoSize();
		
		//! \brief �������ռ������ֽڴ�С��
		//! \param nMaxGeoSize ���ռ������ֽڴ�С[in]��
		//! \return ���óɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool SetMaxGeoSize(UGint nMaxGeoSize);
		
		//! \brief �õ�ʱ�����ݵ�ע��ʱ�䡣
		//! \return ʱ�����ݵ�ע��ʱ�䡣
		//! \remarks ��
		//! \attention ��
		virtual UGTime GetRegistSequenceTime();
		
		//! \brief �õ�ʱ�����ݵ����¸���ʱ�䡣
		//! \return ʱ�����ݵ����¸���ʱ�䡣
		//! \remarks ��
		//! \attention ��
		virtual UGTime GetLUSequenceTime();
		
		//! \brief ͨ��ID����ɾ�����ݼ��еļ�¼��
		//! \param pIDs ID����ָ��[in]��
		//! \param nCount Ҫɾ���ļ�¼��������ID����ĸ������[in]��
		//! \return ɾ���ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool DeleteRecords(const UGint* pIDs,UGint nCount);
		
		//! \brief ׷�Ӽ�¼��
		//! \param pSrcRecordset Դ���ݼ�[in]��
		//! \param bShowProgress  �Ƿ���ʾ��������Ĭ����ʾ[in]��
		//! \param strTileName ͼ������,Ĭ��Ϊ��[in]��
		//! \return ׷�Ӽ�¼�ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool Append(UGRecordset* pSrcRecordset,UGbool bShowProgress = TRUE,UGString strTileName = _U(""));
		
		//! \brief ׷���������ݼ���¼��
		//! \param pNetRecordset �������ݼ�ָ��[in]��
		//! \param bShowProgress �Ƿ���ʾ��������Ĭ����ʾ[in]��
		//! \return ׷�Ӽ�¼�ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool AppendNetwork(UGRecordset *pNetRecordset,
			UGbool bShowProgress = TRUE);
		
		//! \brief �ز��������������ݼ���Ч��
		//! \param dTolerance [in]��
		//! \param bShowProgress �Ƿ���ʾ��������Ĭ����ʾ[in]��
		//! \return �ز����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool Resample(UGdouble dTolerance,
			UGbool bShowProgress=TRUE);	
		
		//! \brief �õ���¼��������
		//! \return ��¼��������
		//! \remarks ��
		//! \attention ��
		virtual UGint GetRecordsetCount();
		
		//! \brief ����ָ�����������ݼ�ָ�롣
		//! \param nIndex ������[in]��
		//! \return ���ݼ�ָ�롣
		//! \remarks ��
		//! \attention ��
		virtual UGRecordset* GetRecordsetAt(UGint nIndex);
		
		//! \brief ͨ�������ͷż�¼����
		//! \param nIndex ������[in]��
		//! \return �ͷųɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool ReleaseRecordset(UGint nIndex);
		
		//! \brief ͨ�������ͷż�¼����
		//! \param pRecordset ���ݼ�ָ��in]��
		//! \return �ͷųɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool ReleaseRecordset(UGRecordset *pRecordset);
		
		//! \brief �����Ƿ�ÿ���������Լ��ķ��
		//! \param nOption [in]��
		//! \param bHas �Ƿ�ÿ���Լ��ķ��[in]��
		//! \remarks ��
		//! \attention ��
		virtual void SetFlag(UGint nOption,UGbool bHas);
		
		//! \brief �ж��ֶ����Ƿ���Ч��
		//! \param strFieldName [in]��
		//! \return ��Ч����TRUE,��Ч����FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool IsAvailableFieldName(const UGString& strFieldName);
		
		
		//! \brief �õ�ͼ������ͼ������	
		virtual UGString GetMiniatureDtName();
		
		
		//! \brief ͨ������ȡ�ֶ���
		virtual UGString GetFieldNameBySign(UGFieldInfo::FieldSign nSign);
		
		//! \brief �����ֶε����
		virtual UGbool SetFieldSign(const UGString& strFieldName,UGFieldInfo::FieldSign nSign);
		
		//! \brief �жϵ�ǰ���ݼ��Ƿ�ɱ༭
		virtual UGbool CanUpdate();
		
		//! \brief ע��ѡ����Ϣ
		virtual UGbool RegisterOption(UGint nOption);
		
		//! \brief ��ע��ѡ����Ϣ
		virtual UGbool UnRegisterOption(UGint nOption);
		
		//! \brief ���ݼ��Ƿ�֧��ĳ�ֲ���ģʽ
		virtual UGbool HasAbility(UGEngAbility dwEngAbility);
		
		virtual UGbool IsSupport(UGEngAction nAction);
		
		//! \brief �������ݼ���Χ,һ�������ݼ���Ԫ�ر�ɾ�����޸ĺ�ʹ��,
		//!        ���ܺķѽ϶�ʱ��
		virtual UGbool ComputeBounds();
		
		//! \brief �����ݿ��ж�ȡ��ǰ���ݼ���Bounds��Ϣ
		//! \remarks �˺�����CDatasetVector::GetBounds�������𣬴˺����Ǵ����ݿ��ж�ȡ���õ��������µ�Bounds����������ֱ�Ӵ��ڴ��ж�ȡm_DatasetInfo�д洢��Bounds��Ϣ���ٶ�Ҫ��ö�
		//!          sa	CDatasetVector::GetBounds
		UGRect2D GetBoundsDirectly();
		
		UGbool RegisterUser(UGint nLogID,UGbool bRecordsetLevel = FALSE);
		
		void CheckError() const;

public:

	//! \brief ������Դ�õ�������URL��
	//! \return ������URL��
	UGString GetBasalURL();	
public:

	//! \brief �ڴ�����Դ��ָ�����顣
	//! \remarks ��ע��Ϣ��
	UGArray<UGDataSource *> m_MemDataSource;

	UGFieldInfos m_fieldInfos;
};
}
#endif // !defined(AFX_UGWEBDATASETVECTOR_H__1339C8A2_FB74_4AC0_B82A_42284D72C19E__INCLUDED_)

