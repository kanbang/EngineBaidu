// UGVersionManager.h: interface for the UGVersionManager class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGVersionManager.h
   **************************************************************************************
    \author   ��־��
    \brief    �汾������࣬������汾��صĲ�������װ���������                                                    
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2008-12-10  ��־��														 <br>
   **************************************************************************************
*/
#ifndef UGVERSIONMANAGER_H
#define UGVERSIONMANAGER_H

#include "UGDataSource.h"
#include "UGDataset.h"
#include "UGDatasetVector.h"
#include "UGDatasetRaster.h"

namespace UGC {	

class ENGINE_API UGVersionManager  
{
public:
	UGVersionManager();
	UGVersionManager(UGDataSource *pDataSource);

	virtual ~UGVersionManager();

public:
	//! \brief �����汾
	//! \param &versionInfo     �汾��Ϣ[in]
	//! \return UGbool
	//! \remarks
	//! \attention
	virtual UGbool CreateVersion(UGVersionInfo &versionInfo);

	//! \brief �����汾
	//! \param &strVersionName	�汾����[in]
	//! \param &strParentName	���汾����[in]
	//! \param &strDescription	�汾������Ϣ[in]
	//! \return UGbool
	//! \remarks
	//! \attention
	virtual UGbool CreateVersion(const UGString &strVersionName, const UGString &strParentName, const UGString &strDescription);
	
	//! \brief ɾ���汾
	//! \param &strVersionName	ָ���汾����[in], nVersionID �汾��[in]
	//! \return
	//! \remarks
	//! \attention��ɾ���ð汾���ð汾�Ĳ��������ϣ�ֻ��ɾ���汾����ĩ�˵İ汾
	virtual UGbool DeleteVersion(const UGString &strVersionName);
	virtual UGbool DeleteVersion(UGint nVersionID);
	
	//! \brief ����Դ�л��汾����Ϊ����Դ���õ�ǰ�İ汾,Ĭ��ΪROOT�汾 
	//! \param &strVersionName	ָ���汾����[in], nVersionID �汾��[in]
	//! \return 
	//! \remarks
	//! \attention
	virtual UGbool SetCurrentVersion(const UGString &strVersionName);
	virtual UGbool SetCurrentVersion(UGint nVersionID);
	
	//! \brief ��ȡ��ǰ�汾
	//! \param 
	//! \return ���ص�ǰ�汾��Ϣ
	//! \remarks
	//! \attention
	virtual UGVersionInfo GetCurrentVersion();
	virtual UGint GetCurrentVersionID();
	
	//! \brief �޸ĸ�����Դ��ָ���汾����Ϣ�����޸İ汾���ƺͰ汾����
	//! \param &strVersionName		ָ���汾����[in]
	//! \param &strDestName			�°汾��Ϣ[in]��&strDestDescription�°汾����[in]
	//! \return UGbool
	//! \remarks
	//! \attention
	virtual UGbool UpdataVersionName(const UGString &strName, const UGString &strDestName);

	//! \brief �޸ĸ�����Դ��ָ���汾����Ϣ�����޸İ汾���ƺͰ汾����
	//! \param &strVersionName		ָ���汾����[in]
	//! \param &strDestName			�°汾��Ϣ[in]��&strDestDescription�°汾����[in]
	//! \return UGbool
	//! \remarks
	//! \attention
	virtual UGbool UpdateVersionDescription(const UGString &strVersionName, const UGString &strDestDescription);

	//! \brief ȡ�ø��汾����Ϣ
	//! \return UGVersionInfo
	virtual UGVersionInfo GetRootVersionInfo();

	//! \brief �õ�������Դ��ָ���汾����Ϣ
	//! \param &strVersionName		ָ���汾����[in], nVersionID �汾��[in]
	//! \param &VersionInfo			�汾��Ϣ[out]
	//! \return UGbool
	//! \remarks
	//! \attention
	virtual UGbool GetVersionInfo(const UGString &strVersionName, UGVersionInfo &versionInfo) const;
	virtual UGbool GetVersionInfo(UGint nVersionID, UGVersionInfo &versionInfo) const;
	
	//! \brief ȡĳ���汾������ֱ���Ӱ汾���������ͨ���ݹ���øú���ȡ���汾����Ϣ
	//! \param &strVersionName	Ŀ��汾����[in], nVersionID �汾��[in]
	//! \param &arrVersionInfos ��ǰ�汾������ֱ���Ӱ汾��Ϣ[out]	
	virtual UGbool GetSubVersionInfos(const UGString & strVersionName, UGArray<UGVersionInfo> &aryVersionInfos) const;
	virtual UGbool GetSubVersionInfos(const UGint nVersionID, UGArray<UGVersionInfo> &aryVersionInfos) const;

	//! \brief �жϵ�ǰ�汾�Ƿ�Ŀ��汾���Ӱ汾
	//! \param &strCurName ��ǰ�汾[in]
	//! \param &strDestName	Ŀ��汾[in]
	//! \return UGbool �Ƿ���TRUE,�񷵻�FALSE
	virtual UGbool CheckRelation(const UGString &strCurName, const UGString &strDestName) const;

	//! \brief ע�����ݼ�Ϊ֧�ְ汾
	//! \param *pDT ���ݼ�ָ��[in]
	//! \return
	//! \remarks		���A��D��
	//! \attention		֧�ֵ㡢�ߡ��桢�ı���CAD�����ݼ�����
	virtual UGbool Register(UGDataset *pDT);
	
	//! \brief ���ݼ���ע��Ϊ��ͨ���ݼ�
	//! \param *pDT ���ݼ�ָ��[in]
	//! \param bUnionToBasic �Ƿ�ϲ����汾��������[in]
	//! \return
	virtual UGbool UnRegister(UGDataset *pDT, UGbool bUnionToBasic = TRUE);

	//! \brief ˢ�����ݼ��ĵ�ǰ�汾�����ݼ����ܴ��ڱ༭״̬
	//! \param *pDT ���ݼ�ָ��[in]
	//! \return
	//! \remarks �����ݼ���ĳ�汾�ڱ𴦱����º󣬿���ͨ���汾ˢ������ȡ����״̬
	//! \attention	
	virtual UGbool Refresh(UGDataset *pDT);
	
	//! \brief �汾Э��
	//! \param *pDT ���ݼ�ָ��[in]
	//! \param &strDestVersionName		Ŀ��汾����[in]
	//! \return	UGint	0�쳣ʧ��
	//!					1�ɹ�
	//!					-1Ŀ��汾�����������汾Э����Э��ʧ��
	//!					-2��ǰ�汾���ڱ�Э����Э��ʧ��
	//!					-3��ǰ�汾�������ط����ڱ༭״̬�����ܽ���Э����Э��ʧ��
	//!					-4Ŀ��ϵ�����ⲿ���޸ģ����ܽ���Э����Э��ʧ��
	//! \remarks ���ݼ��ĵ�ǰ�汾��Ŀ��汾����Э����Ŀ��汾�����ǵ�ǰ�汾�ĸ��汾
	//! \attention		
	virtual UGint Reconcile(UGDataset *pDT, const UGString &strDestVersionName, UGPostOption nPostOption);

	//! \brief �汾�ύ
	//! \param *pDT ���ݼ�ָ��[in]
	//! \return UGint	0�쳣ʧ��
	//!					1�ɹ�
	//!					-1Ŀ��汾�����仯,Ҫ����Э��
	//! \remarks
	//! \attention	Э��֮������ύ������Э�����ύ�ĵ�ǰ��Ŀ��汾���뱣��һ��
	virtual UGint Post(UGDataset *pDT);

	//! \brief�������ͻ
	//! \param	*pDT ���ݼ�ָ��[in]
	//! \param	nSmID ��ͻ�����ID[in]
	//! \param	nPostOption ��ͻ����ʽ[in]
	//! \return
	//! \remarks
	//! \attention	����汾Э�����Ҵ��ڳ�ͻ���ܽ��г�ͻ����
	virtual UGbool TransactConflict(UGDataset *pDT, UGint nSmID, UGPostOption nPostOption);

	//! \brief �汾����
	//! \param *pDT ���ݼ�ָ��[in]
	//! \return			0:����ʧ��
	//!					1:�ɹ�
	//!					2:���ڳ�ͻ����Ҫ���±���
	//! \remarks
	//! \attention	�汾���棬����SmVersions���������Ϣ���汾�༭����Ҫ���汾�������
	virtual UGint Save(UGDataset *pDT);

	//! \brief �汾����
	//! \param *pDT ���ݼ�ָ��[in]
	//! \param &strDestName Ŀ�����ݼ�����[in]
	//! \return
	//! \remarks
	//! \attention
	virtual UGDataset* SnapShot(UGDataset *pDT, const UGString &strDestName);
	
	//! \brief ��ʼ�༭�汾
	//! \param *pDT ���ݼ�ָ��[in]
	//! \return��������Կ�ʼ�༭����������TRUE,���򷵻�FALSE
	//! \remarks
	//! \attention
	virtual UGbool StartEdit(UGDataset *pDT);

	//! \brief �����༭�汾
	//! \param *pDT ���ݼ�ָ��[in]
	//! \return��������Խ����༭����������TRUE,���򷵻�FALSE
	//! \remarks
	//! \attention
	virtual UGbool FinishEdit(UGDataset *pDT);

	//! \brief ������չ��ϢExtInfo
	virtual UGbool RefreshExtInfo(UGDataset *pDT, UGint nVersionID);
	//��ȡ���ݼ�����չ��Ϣ����������ڣ���SmRegister�л�ȡ��Ӧ��Ϣ������ʼ��SmExtInfo
	virtual UGbool GetExtInfo(UGDataset *pDT);

	//! \brief����ȡ�ɱ༭��ϵ��
	//! \param *pDT ���ݼ�ָ��[in]
	//! \return BOOL
	virtual UGbool GetEditableSeries(UGDataset *pDT);

	//! \brief �����ݼ��ĵ�ǰϵ�в����µĲ�����
	//! \param *pDT ���ݼ�ָ��[in]
	//! \return ���ز����ţ����������<=0����ʾ����ʧ��
	virtual UGint InsertNewActionID(UGDataset *pDT, UGint &nSeriesID);

	//! \brief ��ȡһ���µĲ�����ActionID
	//! \param 
	//! \return�����ػ�ȡ�Ĳ����ţ�ʧ���򷵻�0,�������0
	//! \remarks
	//! \attention
	virtual UGint GetNextAction();

	//! \brief  ת���ǰ汾��ѯ��SQL���Ϊ�汾��ѯSQL
	//! \param	*pDT ���ݼ�ָ��
	//! \param	*strSQLIn ������ݼ�pDT��ѯ��SQL���
	//! \param	&bBind SQL�Ƿ������Ϣ
	//! \return	����������ݼ��汾�Ĳ�ѯ���
	//! \remarks ���Ի��������SQLת����Ӧ��Ӧ�İ汾��ͼ
	virtual UGString TranscatSQL(UGDataset *pDT, const UGString &strSQLIn);

	//! \brief ��հ汾����������ϵͳ���
	virtual void ClearVersionEnvironment();
	
	//! \brief  ����汾��ѯ��ͼ
	virtual void CreateQueryView(UGDataset *pDT);

	//! \brief �ж����ݼ��ĵ�ǰ�汾�ܷ���Ŀ��汾Э��
	//! \param *pDT ���ݼ�ָ��[in]
	//! \param &strDestVersionName		Ŀ��汾����[in]
	//! \return	UGint	0�쳣ʧ��
	//!					1�ɹ�
	//!					-1Ŀ��汾���ǵ�ǰ�汾�ĸ��汾
	//!					-2��ǰ�汾���������ط����ڱ༭״̬������Э��
	//!					-3��ǰ�汾���ڱ�Э��������Э��
	//!					-4Ŀ��汾����Э��������Э��
	virtual UGint CanReconcile(UGDataset *pDT, const UGString &strDestVersionName);

	//! \brief �ж����ݼ��ĵ�ǰ�汾�ܷ���Ŀ��汾�ύ
	//! \param *pDT ���ݼ�ָ��[in]
	//! \param &strDestVersionName		Ŀ��汾����[in]
	//! \return UGint	0�쳣ʧ��
	//!					1�ɹ�
	//!					-1Ŀ��汾���ǵ�ǰ�汾�ĸ��汾
	//!					-2Ŀ��汾�����£�������Э��
	//! \remarks
	//! \attention	Э��֮������ύ������Э�����ύ�ĵ�ǰ��Ŀ��汾���뱣��һ��
	virtual UGint CanPost(UGDataset *pDT, const UGString &strDestVersionName);

//����Ҫ����ʵ�ֵ�
public:
	//! \brief �Ƿ���Ҫ����
	//! \param *pDT ���ݼ�ָ��[in]
	//! \return
	//! \remarks �ж����ݼ��ĵ�ǰ�汾�Ƿ���Ҫ���棬���ڱ༭��Э���󲻱��潫��ʧδ��������
	UGbool BeNeedSave(UGDataset *pDT);

	//! \brief	Э����ȡ�õ�ǰ�汾�ļ�¼��
	//! \param	*pDT ���ݼ�ָ��[in]
	//! \return	���ؼ�¼��
	//! \attention ������Э�������ȡ����Ч���ݣ����򷵻�NULL
	//!            ��ѯ���������Ǿ�̬�α꣬�����¼����֧���޸�,��Ҫ���ⲿRelease
	UGRecordset *GetCurRecordset(UGDataset *pDT, UGQueryDef &querydef);

	//! \brief	Э����ȡ��Ŀ��汾�ļ�¼��
	//! \param	*pDT ���ݼ�ָ��[in]
	//! \return	���ؼ�¼��
	//! \attention ������Э�������ȡ����Ч���ݣ����򷵻�NULL
	//!            ��ѯ���������Ǿ�̬�α꣬�����¼����֧���޸�,��Ҫ���ⲿRelease
	UGRecordset *GetConflictRecordset(UGDataset *pDT, UGQueryDef &querydef);

	//! \brief	Э����ȡ�ù����汾�ļ�¼��
	//! \param	*pDT ���ݼ�ָ��[in]
	//! \return	���ؼ�¼��
	//! \attention ������Э�������ȡ����Ч���ݣ����򷵻�NULL
	//!            ��ѯ���������Ǿ�̬�α꣬�����¼����֧���޸�,��Ҫ���ⲿRelease
	UGRecordset *GetCommonRecordset(UGDataset *pDT, UGQueryDef &querydef);

	void SetTranMode(UGbool bTran = FALSE);

	UGbool GetEditMode();

protected:
	//! \brief	����ϵ�в�����ѯ���ݼ�
	//! \param	*pDT			���������ݼ�[in]
	//! \param	nSeriesID		ϵ�к�[in]
	//! \param	nLastActionID	ϵ�е���������[in]
	//! \param	&querydef		��ѯ����,Ҫ���ѯ�α���þ�̬��ѯ[in]
	//! \return	���ز�ѯ���
	//! \attention �ò�ѯ������Ҫ������ʾ��ͻ��Ϣ�������Ƚ�רҵ��������ʹ��
	virtual UGRecordset *QueryBySeries(UGDataset *pDT, UGint nSeriesID, UGint nLastActionID, UGQueryDef &querydef);

	//! \brief	��ROOT�汾�ϲ���������,�����ݼ���ע��֮ǰ����
	//! \param	���������ݼ�[in]
	//! \return UGbool
	//! \attention
	virtual UGbool UnionRootToBasic(UGDataset *pDT);
	
	//! \brief	ͨ��SQL���ӿ���ȡ����
	//! \param	*pDT			���������ݼ�[in]
	//! \param	&strSQL			SQL���[in]
	//! \param	&fieldInfos		����ȡ�õ��ֶ���Ϣ[out]
	//! \param	nObjectCount	����ȡ�õĶ�����
	//! \param	*pAttrBuffer	������������[out]
	//! \param	*pGeoBuffer		���ؼ�������[out]
	//! \param	*pInds			���ز�ѯ�����ʾ��[out]
	//! \return	UGbool
	//! \attention				pAttrBuffer��pGeoBuffer�ں������ڷ����ڴ�,��Ҫ��ʹ�ú��ֶ��ͷ�,
	//!							pAttrBuffer��pGeoBufferҪ��fieldInfos����ʹ��
	virtual UGbool FetchDataBySQL(UGDataset *pDT, UGString &strSQL, UGFieldInfos &fieldInfos, UGint &nObjectCount, UGbyte *&pAttrBuffer, UGbyte *&pGeoBuffer, UGint *&pInds);

	//! \brief ����ϵ�в�������ϵ�е�LastAction֮ǰ�Ĳ������Ƶ�һ���µ�ϵ��
	//! \param nSrcSeriesID ����Դϵ�к�[in]
	//! \param nSrcLastActionID ����Դ������[in]
	//! \param nDestSeriesID ����Ŀ��ϵ�к�[in]
	virtual UGbool CopySeries(UGint nSrcSeriesID, UGint nSrcLastActionID, UGint nDestSeriesID);

	//�ϲ�A��������SQL��ѯ�ļ�¼Ϊһ���²�����ͬʱ����ԭ����
	virtual UGbool UnionActionInA(UGDataset *pDT, UGString strSQL, UGint nNewActionID);

	//! \brief	ɾ��ʧЧ���ݣ�SmSeriesOpers��AD��
	//! \param	*pDT ���ݼ�ָ��[in]
	//! \param	nVersionID = 0,�汾�ţ�Ĭ�ϴ���ǰ�汾[in]
	//! \remarks 
	virtual UGbool DropInvalidData(UGDataset *pDT, UGint nVersionID = 0);
	
	//! \brief	ѹ��ϵ�в���
	//! \param	*pDT ���ݼ�ָ��[in]
	//! \param	bAll �Ƿ�ѹ���������ݼ����ǣ�Ҫ��ָ�����ݼ��Ĳ��ܴ��ڱ༭״̬
	//!              ��ѹ�����ݼ���ǰϵ��
	//! \remark
	virtual UGbool CompressData(UGDataset *pDT, UGbool bAll = FALSE);

protected:
	/*����������������ʹ�ã���ͨ������汾��ͼ�����������
	//! \brief �Ӹ������л�ȡSQL��ͳ�ƹؼ��� 
	//! \return ���عؼ��֣�����ʧ���򷵻�""
	//! \attention ������Ҫ��"("��β
	//! \remarks ���贫���SQL����ȷ�ģ�����������Ԥ��
	UGbool IsStatKeyWord(UGString strKeyIn);
	
	//Ϊ�˺ϲ��������A���ͳ�Ʋ�ѯ�����ͨ���˷�������ԭSQL���ﵽͳ�Ʋ�ѯ��Ŀ
	//��"Select Count(smid) from Test"�����Ϊ"Select smid from Test"���ٰ�SQL����Ϊ���A���
	//"Select smid from SM_V_A",�ϲ��������A����ͳ��
	//"Select Count(smid) from (select smid from test UNION all select smid from sm_v_a)"
	//���ԭSQL��䲻�ܰ����Ӳ�ѯ�����ԭSQL��䲻��ͳ�Ʋ�ѯ�����ؿմ�
	UGString SetAliasForStatSQL(UGString strSQLIn);*/

protected:
	//����Դָ��
	UGDataSource *m_pDataSource;
	//��ǰ�汾��
	UGint m_nCurVersionID;
	UGbool m_bTranMode;
};
}
#endif // !defined(AFX_UGVERSIONMANAGER_H__56BFAEC6_99C1_47BF_BDF3_C7CB7BE0F817__INCLUDED_)

