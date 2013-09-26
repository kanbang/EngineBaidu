// UGDatasetVectorOgdc.h: interface for the UGDatasetVectorOgdc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDATASETVECTOROGDC_H__296CEA92_1643_444F_82CC_1DA2F9B31DB7__INCLUDED_)
#define AFX_UGDATASETVECTOROGDC_H__296CEA92_1643_444F_82CC_1DA2F9B31DB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OGDC/OgdcDatasetVector.h"
#include "Engine/UGDatasetVector.h"
#include "UGRecordsetOgdc.h"

namespace UGC {

class UGDataSourceOgdc;

//##ModelId=483BB70A0157
class ENGINEOGDC_API UGDatasetVectorOgdc : public OgdcDatasetVector  
{
public:
	//##ModelId=483BB70A0168
	UGDatasetVectorOgdc();
	//##ModelId=483BB70A0169
	virtual ~UGDatasetVectorOgdc();

public:
	//##ModelId=483BB70A016B
	virtual OgdcBool Open();	
	
	//! \brief �ر����ݼ���
	//! \return �Ƿ�ɹ��ر����ݼ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A016D
	virtual void Close();	

	//! \brief �ж����ݼ��Ƿ��Ѿ��򿪡�
	//! \return �򿪷���TRUE�����򷵻�FALSE��
	//##ModelId=483BB70A0178
	virtual OgdcBool IsOpen() const;
	
	//! \brief ��ȡ���ݼ����͡�
	//! \return ���ݼ�����ö��ֵ��
	//##ModelId=483BB70A017A
	virtual OgdcInt GetType() const;	
	
	//! \brief ��ȡ���ݼ�����
	//! \return ���ݼ�����
	//! \remarks ���ݼ������Ժͱ�����ͬ��
	//##ModelId=483BB70A017C
	virtual OgdcString GetName();
	
	//! \brief ���������ݼ���
	//! \param strNewName �µ����ݼ���[in]��
	//! \return �Ƿ�ɹ����������ݼ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ֻ�ı����ݼ���,�������䡣
	//##ModelId=483BB70A0187
	virtual OgdcBool Rename(const OgdcString& strNewName);		

	//! \brief �жϵ�ǰ���ݼ��Ƿ�ɱ༭��
	//! \return �ɱ༭����TRUE�����ɷ���FALSE��
	//##ModelId=483BB70A018A
	virtual OgdcBool CanUpdate();	
	
	//! \brief �������ݼ��ķ��ά����
	//! \return ���ݼ���ά�����㡢�ߡ�����Ϊ0��1��2ά����Ϊ-1ά
	//##ModelId=483BB70A018C
	virtual OgdcInt GetStyleDimension();	
	
	//! \brief �ж����ݼ��Ƿ���դ�����ݼ�
	//! \return ���ݼ���դ�����ݼ�����TRUE�����򷵻�FALSE��
	//##ModelId=483BB70A0197
	virtual OgdcBool IsRaster();	
	
	//! \brief ��ȡ���ݼ��ĵ���Χ��
	//! \return ���ݼ��ĵ���Χ��
	//##ModelId=483BB70A0199
	virtual OgdcRect2D GetBounds();	
	
	//! \brief �������ݼ��ĵ���Χ��
	//! \param rc2Bounds ���ݼ��ĵ���Χ[in]��
	//##ModelId=483BB70A019B
	virtual void SetBounds(const OgdcRect2D& rc2Bounds);	
	
	//! \brief �����ݼ�������Ϣ���浽���ݿ��С�
	//! \return �Ƿ�ɹ����棬�ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A01A5
	virtual OgdcBool SaveInfo();	
	
	//! \brief ˢ�����ݼ���Ϣ��
	//! \return �Ƿ�ɹ�ˢ�£��ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks �����ݿ��ж�ȡ���ݼ��ĸ������ԣ�ˢ�µ�ǰ���ݼ�����Ϣ��
	//##ModelId=483BB70A01A7
	virtual OgdcBool RefreshInfo();	

	//! \brief ��ȡ���ݼ��ж��������
	//! \param  [in]��
	//! \return ���������
	//! \remarks �ٶ���,��ֵ�Ƚ���ȷ��
	//! \attention ͨ��Register���ȡ��
	//##ModelId=483BB70A01A9
	virtual OgdcInt GetObjectCount();

	//! \brief ���ؼ�¼��������
	//! \return ��¼��������
	//##ModelId=483BB70A01B5
	virtual OgdcInt GetRecordsetCount();	
	
	//! \brief ͨ����¼��ָ���ͷż�¼���ڴ�ռ䡣
	//! \param *pRecordset ��¼��ָ��[in]��
	//! \return �Ƿ��ͷųɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A01B7
	virtual OgdcBool ReleaseRecordset(OgdcRecordset *pRecordset);	

	//! \brief �ͷ����м�¼��
	//##ModelId=483BB70A01BA
	virtual void ReleaseAllRecordsets();	

	//! \brief ȡ�����ݼ���ĳ������Ҫ�ء�
	//! \param nID ���ݼ���¼ID��[in]��
	//! \return ������Ҫ��ָ�롣
	//##ModelId=483BB70A01BC
	virtual OgdcFeature* GetFeature(OgdcInt nID);	

	//! \brief ������Ҫ�ظ��µ����ݼ��С�
	//! \param pFeature ����Ҫ��ָ��[in]��
	//! \return �Ƿ񱣴�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A01C5
	virtual OgdcBool UpdateFeature(const OgdcFeature* pFeature);
	
	//! \brief ������Ҫ��׷�ӵ����ݼ�δβ��
	//! \param pFeature ����Ҫ��ָ��[in]��
	//! \return �Ƿ�׷�ӳɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ׷��ʱ����Ҫ�ع��������ݼ���¼ID���������á�
	//##ModelId=483BB70A01C8
	virtual OgdcBool AddFeature(const OgdcFeature* pFeature);	

	//! \brief ������Ҫ�ش����ݼ���ɾ����
	//! \param nID ���ݼ���¼ID��[in]��
	//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A01CB
	virtual OgdcBool DeleteFeature(OgdcInt nID);	
	
	//! \brief ͨ��ID����ɾ�����ݼ��еļ�¼��
	//! \param pIDs ID����ָ��[in]��
	//! \param nCount ID����Ԫ�ظ���[in]��
	//! \return �ɹ�ɾ������TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A01D4
	virtual OgdcBool DeleteFeatures(const OgdcInt* pIDs, OgdcInt nCount);	
	
	//! \brief ɾ�������������ݡ�
	//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��ձ����е��ֶ���Ȼ������
	//##ModelId=483BB70A01D8
	virtual OgdcBool Truncate();	

	//! \brief ���ݵ�ǰ����״̬�ؽ�����
	//! \return �Ƿ��ؽ��ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A01DA
	virtual OgdcBool BuildSpatialIndex();
	
	//! \brief ����ռ�����,Ϊû��������״̬
	//! \return �Ƿ�����ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A01DC
	virtual OgdcBool DropSpatialIndex();
	
	//! \brief �Ƿ���Ҫ�ؽ��ռ�����
	//! \return ��Ҫ�ؽ�����TRUE������Ҫ����FALSE��
	//! \remarks �涨:���û����������FALSE,�����������������
	//##ModelId=483BB70A01E4
	virtual OgdcBool IsSpatialIndexDirty();

	//! \brief ��ѯͨ����ڣ��õ���¼����
	//##ModelId=483BB70A01E6
	virtual OgdcRecordset* Query(const OgdcQueryDef& querydef);
	
	//! \brief ͨ�����ʽ�����ֶ�ֵ��
	//! \param strFieldName ���µ��ֶ���[in]��
	//! \param strExpress ����������ʽ�ַ�����
	//!        �ֶ�ֵ��ĳ������������ʽ��ֵ����strFieldName = Col1 + col2 * 2[in]��
	//! \param strFilter �����ֶ�ʱ�������еĹ���������
	//!        Ĭ�Ϲ��������ÿգ��������м�¼[in]��
	//! \return �Ƿ�����ֶ�ֵ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A01E9
	virtual OgdcBool UpdateField(
		const OgdcString& strFieldName,
		const OgdcString& strExpress,
		const OgdcString& strFilter = _U(""));	
	
	//! \brief �����ֶ�ֵ,strSrcField�͡�
	//! \param strSrcFieldName Դ�ֶ�����[in]��
	//! \param strDestFieldName Ŀ���ֶ�����[in]��
	//! \return �Ƿ����ֶγɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention Ŀ���ֶ������붼������Ŀ���ֶ�Ҫ��Դ�ֶ�����ƥ�䡣
	//##ModelId=483BB70A01EE
	virtual OgdcBool CopyField(
		const OgdcString& strSrcFieldName,
		const OgdcString& strDestFieldName);	
	
	//! \brief ������ͨ������
	//! \param strFieldNameList �����������ֶ��б�����ֶ��м���","����[in]��
	//! \param strIndexName ������[in]��
	//! \return ������ͨ�����Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A01F5
	virtual OgdcBool CreateFieldIndex(
		const OgdcString& strFieldNameList,
		const OgdcString& strIndexName);	

	//! \brief ɾ��������
	//! \param strIndexName ������[in]��
	//! \return ɾ�������Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A01F9
	virtual OgdcBool DropFieldIndex(const OgdcString& strIndexName);	

	//! \brief ���һ��������
	//! \param �ޡ�
	//! \return ����ֵ--���������ֶζ�ӦMap��
	virtual std::map<OgdcString,OgdcString> GetFieldIndexes();	

	//! \brief ��������ֶΡ�
	//! \param fieldInfos �ֶ�������Ϣ��������[in]��
	//! \return ��������ֶ��Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A01FC
	virtual OgdcBool CreateFields(const OgdcFieldInfos& fieldInfos);	
		
	//! \brief ͨ���ֶ�����ɾ���ֶΡ�
	//! \param strFieldName �ֶ���[in]��
	//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A01FF
	virtual OgdcBool DeleteField(const OgdcString& strFieldName);
	
	//! \brief ��ȡ���ݱ��������ֶε�������Ϣ��
	//! \param fieldInfos ���ݱ��������ֶε�������Ϣ����[out]��
	//! \param bSystemFieldExcluded �Ƿ��ȡϵͳ�ֶΣ�Ĭ�ϲ�ȡ[in]��
	//! \return �Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A0204
	virtual OgdcBool GetFieldInfos(
		OgdcFieldInfos& fieldInfos,
		OgdcBool bSystemFieldExcluded = FALSE);	
	
	//! \brief ͨ���ֶ�����ȡ�ֶ�������Ϣ��
	//! \param strFieldName �ֶ���[in]��
	//! \param fieldInfo �ֶ�������Ϣ[out]��
	//! \return �Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A0208
	virtual OgdcBool GetFieldInfo(
		const OgdcString& strFieldName,
		OgdcFieldInfo& fieldInfo);
	
	//! \brief ͨ���ֶ��������ֶ���Ϣ��
	//! \param strFieldName �ֶ���[in]��
	//! \param fieldInfo �ֶ�������Ϣ��������[in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70A020C
	virtual OgdcBool SetFieldInfo(
		const OgdcString& strFieldName,
		const OgdcFieldInfo& fieldInfo);	
	
	//! \brief ͳ���ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \param nMode ͳ��ģʽ[in]��
	//! \return ͳ��ֵ��
	//##ModelId=483BB70A0213
	virtual OgdcVariant Statistic(
		const OgdcString& strFieldName,
		OgdcRecordset::OgdcStatisticMode nMode);	
	
	//! \brief ��������Դָ��
	virtual OgdcDataSource* GetDataSource() const;
	
	//! \brief ��������Դָ��
	virtual void SetDataSource(UGDataSourceOgdc* pDataSource);

public:
	//! \brief �������ݼ���Ӧ����
	//##ModelId=483BB70A0217
	virtual OgdcString GetTableName();	
	
	//! \brief ��ȡ���������ݼ���ʱ�̡�
	//! \return ���������ݼ���ʱ�̡�
	//##ModelId=483BB70A0219
	virtual OgdcTime GetDateLastUpdated();	
	
	//! \brief ��ȡ�������ݼ���ʱ�̡�
	//! \return �������ݼ���ʱ�̡�
	//##ModelId=483BB70A021B
	virtual OgdcTime GetDateCreated();	
	
	//! \brief �ж����ݼ��Ƿ��ڴ򿪺��й��޸ġ�
	//! \return �й��޸ķ���TRUE��û�з���FALSE��
	//##ModelId=483BB70A021D
	virtual OgdcBool IsModified() const;
	
	//! \brief �������ݼ��Ƿ��й��޸ġ�
	//! \param bModified ���ݼ��Ƿ��й��޸ģ�Ĭ�����޸�[in]��
	//##ModelId=483BB70A021F
	virtual void SetModifiedFlag(OgdcBool bModified = TRUE);
	
	//! \brief �������ݼ��ַ����뷽ʽ
	//! \param textCodec ���ݼ��ַ����뷽ʽ[in]��
	//##ModelId=483BB70A0223
	virtual void SetCharset(OgdcString::Charset nCharset);

	//! \brief ��ȡ���ݼ��ַ����뷽ʽ��
	//! \return ���ݼ��ַ���ö�١�
	//##ModelId=483BB70A0226
	virtual OgdcString::Charset GetCharset() const;

	//! \brief ����ͶӰ����ϵ��
	//! \param coordSys [in]��
	//##ModelId=483BB70A0228
	virtual OgdcBool SetCoordSys(const OgdcCoordSys& coordSys);	

	//! \brief �õ�ͶӰ����ϵ��
	//##ModelId=483BB70A022B
	virtual OgdcBool GetCoordSys(OgdcCoordSys& coordSys) const;		

	//! \brief ��ȡ���ݼ�������Ϣ��
	//! \return ���ݼ�������Ϣ��
	//##ModelId=483BB70A022E
	virtual OgdcString GetDescription() const;	
	
	//! \brief �������ݼ�������Ϣ
	//! \param strDesc [���ݼ�������Ϣin]��
	//##ModelId=483BB70A0232
	virtual void SetDescription(const OgdcString& strDesc);	

	//! \brief �õ�δ��ռ�õ��ֶ�����
	//! \param strFieldName ָ����һ���ֶ���[in]��
	//! \return δ��ռ�õ��ֶ�����
	//##ModelId=483BB70A0235
	virtual OgdcString GetUnoccupiedFieldName(const OgdcString& strFieldName);

	//! \brief �ж��ֶ����Ƿ���Ч��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��Ч����TRUE����Ч����FALSE��
	//##ModelId=483BB70A0238
	virtual OgdcBool IsAvailableFieldName(const OgdcString& strFieldName);

	//! \brief ��ȡ�����ݼ�
	//! \return ����������ݼ���������ݼ�ָ�����飬��������Ϊ��
	virtual OgdcBool GetChildDataset(OgdcArray<OgdcDatasetVector *>& arrSubDatasets) const;

	//! \brief  ��ȡ�����ݼ�ָ��
	//! \return ����и����ݼ����򷵻ظ����ݼ�ָ�룻���򷵻�NULL
	virtual OgdcDatasetVector* GetParentDataset() const;

	//! \brief ʸ�����ݼ�����������Provider�����Ƿ�֧����ز�ѯ
	virtual UGbool IsSupportQueryType(UGQueryDef::QueryType queryType) const;

	//##ModelId=483BB70A023B
	UGDatasetVector* GetDatasetVector() const;	
	
	//##ModelId=483BB70A023D
	void SetDatasetVector(UGDatasetVector* pDatasetVector);

	void SetParentDatasetVector(OgdcDatasetVector* pDatasetVector);

protected:	
	UGDataSourceOgdc* m_pDsOgdc;
	//##ModelId=483BB70A0243
	UGDatasetVector* m_pDatasetVector;
	//##ModelId=483BB70A0245
	UGArray<UGRecordsetOgdc*> m_Recordsets;

	OgdcArray<OgdcDatasetVector *> m_SubDatasets;

	OgdcDatasetVector *m_pParentDataset;
};

}

#endif // !defined(AFX_UGDATASETVECTOROGDC_H__296CEA92_1643_444F_82CC_1DA2F9B31DB7__INCLUDED_)

