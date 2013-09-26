// UGDuplicateManager.h: interface for the UGDuplicateManager class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDuplicateManager.h
   **************************************************************************************
    \author   ��־��
    \brief    ���ݸ��ƺ�ͬ������                                                   
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2009-2-18  ��־��														 <br>
   **************************************************************************************
*/
#ifndef UGDUPLICATEMANAGER_H
#define UGDUPLICATEMANAGER_H

#include "UGDataSource.h"
#include "UGDataset.h"
#include "UGDatasetVector.h"
#include "UGDatasetRaster.h"

namespace UGC {	
class ENGINE_API UGDuplicateManager  
{
public:
	UGDuplicateManager();
	UGDuplicateManager(UGDataSource *pDS);

	virtual ~UGDuplicateManager();

public:
//! \brief ��������
	//! \param *pDT ���ݼ�ָ��[in]
	//! \param &querydef ��������������[in]
	//! \param *pDestDS Ŀ������Դָ��[in]
	//! \param &strName ��������[in]
	//! \param nType ��������[in]
	//! \param &strDescription ��������[in]
	//!	\param	nExchangeState 0��ʾ���ݷ���Դ��1��ʾ���ݽ���Դ
	//! \return UGbool
	//! \remarks ��������ʱ�������Դ����ΪSDBPlus��ֻ�ܴ��������͸���
	//!          �����SQLPlus��OraclePlus���ܴ���������¸�����˫��ͬ������
	//! \attention
	virtual UGbool CreateDuplicate(UGDatasetVector *pDT, 
								   const UGQueryDef &querydef,
								   UGDataSource *pDestDS, 
								   const UGString &strName, 
								   UGDuplicateType nType, 
								   UGint nExchangeState = 0,
								   const UGString &strDescription = _U(""), 
								   UGString strObjIDName = _U(""));
	
	//! \brief	��ȡ������Ϣ
	virtual UGbool GetDuplicateInfos(UGArray<UGDuplicateInfo> &aryInfo);
	virtual UGbool GetDuplicateInfo(const UGString &strName, UGDuplicateInfo &info);
	virtual UGbool GetInfoByID(const UGString &strDuplicateID, UGDuplicateInfo &info);

	//! \brief	���¸������ơ�����
	//! \param	&strName ������[in]
	//! \param	&strNewName �¸�����[in]��������Ϣ[in]
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual UGbool UpdateName(const UGString &strName, UGString &strNewName);
	virtual void UpdateDescription(const UGString &strName, UGString &strDescription);

	//! \brief	ɾ������
	//! \param	&strName ������[in]
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual UGbool DropDuplicate(const UGString &strName);

	//! \brief	ɾ������Դ�µ����и���
	virtual void DropAllDuplicate();

	//! \brief	ɾ�����ݼ������и���
	virtual void DropAllDuplicate(UGDataset *pDT);

	//! \brief	���������
	//! \param	&strName ��������[in]
	//! \param	*pDS �������������Դָ��[in]
	//! \param	&strDiffMsgName ���������[in]
	//! \return  ��
	//! \remarks	*pDSָ�������Դ����ΪSDBPlus����Դ
	//! \attention ��
	virtual UGbool ExportDiffMessage(const UGString &strName, UGDataSource *pDS, const UGString &strDiffMsgName);
	
	//! \brief	׼����������
	//! \param	&strName	׼���������ݵĸ�������[in]
	//! \param	*pDS		�������������Դ[in]
	//! \param	&aryObjIDs	��ͻ����ID����[out]
	//! \param	nTranOption	Ĭ�ϳ�ͻ����ʽ��0:�Ը�������Ϊ׼,1:�Բ����������Ϊ׼[in]
	//! \remarks	
	//! \attention	�ڵ���ImportDiffMsg()����ǰ�����ȵ��ô˷�����Ҫȡ��ImportDiffMsg�������CancleImport()����
	virtual UGbool PrepareToImport(const UGString &strName, UGDataSource *pDS, UGStrArray &aryObjIDs, UGint nTranOption = 1);
	
	//! \brief	ȡ����׼���ĵ������
	//! \param	&strName	��������[in]��
	virtual void CancleImport(const UGString &strName);
		
	//! \brief	��������
	//! \param	&strName ��������
	//! \param	*pDS �������������Դָ��[in]
	//! \param	nOption Ĭ�ϳ�ͻ����ʽ 0:�����汾Ϊ��,1:���Ӹ���Ϊ��
	//! \return ��
	//! \remarks	*pDSָ�������Դ����ΪSDBPlus����Դ
	//! \attention ��
	virtual UGint ImportDiffMessage(const UGString &strName, UGDataSource *pDS);

	//! \brief	����������Ϣ
	//! \param	&strName	��������
	//! \param	&strMsgFile	�ļ�ȫ·���������ļ���
	//! \param	bReplace	����ļ��Ѵ��ڣ��Ƿ񸲸�֮
	//! \return ��
	virtual UGbool ExportAcknowledgeMsg(const UGString &strName, const UGString &strMsgFile, UGbool bRepalce = TRUE);

	//! \brief	���뷴����Ϣ
	//! \param	&strMsgFile ������Ϣ�ļ�
	//! \param	bDelFile �Ƿ��ڵ�����Ϣ��ɾ�����ļ�
	//! \param	bDelInValidData �Ƿ�ɾ����ͬ��������
	//! \return	
	virtual UGbool ImportAcknowledgeMsg(const UGString &strMsgFile, UGbool bDelFile = FALSE, UGbool bDelInvalidData = TRUE);


	//! \brief	׼��ͬ������
	//! \param	&strName	��������[in]
	//! \param	*pDestDS	ͬ��Ŀ������[in]
	//! \param	nTranOption Ĭ�ϳ�ͻ����0,��Դ����Ϊ׼��1,��Ŀ������Ϊ׼[in]
	//! \remarks
	//! \attention	�ڵ���SynchroDumplicate()����ǰ�����ȵ��ô˷�����Ҫȡ��SynchroDumplicate�������CancleSynchro()
	virtual UGbool PrepareToSynchro(UGString strName, UGDataSource *pDestDS, UGStrArray &aryObjIDs, UGint nTranOption = 0);
	
	//! \brief	ȡ����׼����ͬ������
	//! \param	&strName	��������[in]
	virtual void CancleSynchro(const UGString &strName);

	//! \brief	ͬ������
	//! \param	&strName	��������[in]
	//! \param	*pDestDS	ͬ��Ŀ������[in]
	//! \return
	//! \remarks
	//! \attention Ҫ������ͬһ�����ռ��д���������������Դ���Ӹ�����������Դ
	//! 		   ���߸������ܲ��ô˷�����������º�˫����¿��Բ��ô˷���ͬ��
	virtual UGbool SynchroDumplicate(UGString strName, UGDataSource *pDestDS);
	

	//! \brief	��ȡ����Դ�еĲ������Ϣ
	virtual UGDiffMsgInfo GetDiffMsgInfo(const UGString &strDuplicateID);
	virtual UGbool GetDiffMsgInfos(UGArray<UGDiffMsgInfo > &aryDiffMsgInfos);
		
	//! \brief	���������ͻ����	
	//! \param	&strName	��������[in]
	//! \param	&strObjID	����Ψһ��ʶ[in]
	//! \param	nTranOption	����ʽ��0:�Ը�������Ϊ׼,1:�Բ����������Ϊ׼[in]
	virtual void SetTranOption(const UGString &strName, const UGString &strObjID, UGint nTranOption);

	//! \brief	���ݸ�������ȡ���ݼ�ָ��
	//! \param	&strName ��������[in]
	virtual UGDataset* GetDuplicateDataset(const UGString &strName);

//���漸���������ڸ���ͬ����������ʱ�ֱ��ȡ��Ӧ�����ݼ��ͼ�¼
	//!	\brief	��ȡ��ǰ�������ݼ�
	//! \param	&strName	��ǰ������
	//!	\return	�������ݼ�ָ��
	virtual UGDataset* GetCurDataset(const UGString &strName);

	//!	\brief	��ȡĿ�긴�����ݼ�
	//! \param	&strName	��ǰ������
	//! \param	*pDestDS	Ŀ�긴����������Դ
	//!	\return	�������ݼ�ָ��
	virtual UGDataset* GetDestDataset(const UGString &strName, UGDataSource *pDestDS);

	//! \brief	��ȡ��ǰ������������ݼ�
	//! \param	&strName	��ǰ������
	//! \param	*pDestDS	�������������Դ
	//!	\return	�������ݼ�ָ��
	virtual UGDataset* GetDiffMsgDataset(const UGString &strName, UGDataSource *pDestDS);

	//! \brief	���ݶ����ʶ��ѯ��ͻ����
	//! \param	&strName	��ǰ������
	//!	\param	���ݼ�ָ��	
	//!	\param	&strObjID	����Ψһ��ʶ
	//!	\return	���ؼ�¼��, NULL���ʾ����ʧ��
	//!	\attention	��ѯ������In�﷨���죬һ�β�ѯ�����ܳ���1000������¼����Ҫ���ⲿRelease
	virtual UGRecordset* GetConflictObject(const UGString &strName, UGDatasetVector *pDV, const UGStrArray &aryObjIDs);
	

// ����ڲ����÷���
public:
	//! \brief	������������ݼ�[in]
	//! \param	&diffMsgInfo	�������Ϣ[in]
	//! \param	*pRcd			�����¼[in]
	//! \param	&attrFieldInfos ������Ϣ���ֶνṹ[in]
	//! \param	*pDataBuffer	��������[in]
	//! \attention �÷�����ExportDiffMessage(),�ɲ������������Դ����
	virtual UGDataset* CreateDiffMsg(const UGDiffMsgInfo &diffMsgInfo,  
		UGRecordset *pRcd,
		UGFieldInfos &attrFieldInfos, 
		UGbyte *pDataBuffer);

	//! \brief	��ȡ������е�����
	//! \param	&diffMsgInfo	�������Ϣ[in]
	//! \param	nUpdateSequence	��������������[in]
	//! \param	*pRcd			�����¼[out]
	//! \param	&nAttrCount		������Ϣ��[out]
	//! \param	&attrFieldInfos ������Ϣ���ֶνṹ[out]
	//! \param	*pDataBuffer	��������[out]
	//! \attention	*&pRcd, *&pDataBuffer����Ҫ���ⲿ�ͷ�
	virtual UGbool FetchDataFromDiffMsg(UGDiffMsgInfo &diffMsgInfo, 
		UGint nUpdateSequence,
		const UGString &strIDFieldName, 
		UGRecordset *&pRcd,
		UGint &nAttrCount, 
		UGFieldInfos &attrFieldInfos, 
		UGbyte *&pDataBuffer);
		
	//! \brief	�����Ӹ���
	//! \param	&info ��������Ϣ[in]
	//! \param	*pDT �Ӹ������ݼ�[in]
	//! \return
	//!	\attention �÷����ɴ���������ʱ��Ŀ������Դ����,����ǰ�ȴ����Ӹ������ݼ�
	virtual UGbool CreateSubDuplicate(const UGDuplicateInfo &info, UGDataset *pDT);

	//! \brief �����������ݡ�
	//! \param *pDT ���ݼ�ָ��[in]��
	//! \param nEditMode �༭ģʽ��ɾ��-1, ����1, �޸�0[in]��
	//! \param &strIDFieldValue ��ʶ�ֶ�ֵ [in]��
	//! \param nVersionID ����ǰ汾���ݼ���Ҫָ����ǰ�汾�� [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual UGbool UpdateData(UGDataset *pDT, UGint nEditMode, const UGString &strIDFieldValue = _U(""), UGint nVersionID = 1);	

	//! \brief ����ͬ����Ϣ��
	//! \param &strName �汾��[in]��
	//! \param nUpdateSequence �������[in]��
	//! \param nSynchroSequence ͬ�����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual void UpdateSynchroInfo(const UGString &strName, UGint nUpdateSequence, UGint nSynchroSequence);
protected:
	//! \brief ע�Ḵ��ϵͳ��
	//! \param *pDS ����Դָ��
	//! \return
	//! \remarks 
	virtual UGbool RegSysTable(UGDataset *pDT);
	
protected:
	UGDataSource *m_pDataSource;
};
}
#endif // !defined(AFX_UGDUPLICATEMANAGER_H__56BFAEC6_99C1_47BF_BDF3_C7CB7BE0F817__INCLUDED_)

