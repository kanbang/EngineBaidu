// UGRecordsetOgdc.h: interface for the UGRecordsetOgdc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGRECORDSETOGDC_H__3447382C_208C_40E4_A613_E5790100E935__INCLUDED_)
#define AFX_UGRECORDSETOGDC_H__3447382C_208C_40E4_A613_E5790100E935__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGRecordset.h"

namespace UGC {

class UGDatasetVectorOgdc;

//##ModelId=483BB70801D4
class ENGINEOGDC_API  UGRecordsetOgdc : public OgdcRecordset  
{
public:
	//##ModelId=483BB70801E4
	UGRecordsetOgdc();
	//##ModelId=483BB70801E5
	virtual ~UGRecordsetOgdc();

public:
	//##ModelId=483BB70801E7
	virtual OgdcBool IsEmpty(); 	
	
	//! \brief �жϵ�ǰ��¼ָ���Ƿ�ָ��ͷ��
	//! \return ָ��ָ��ͷ����TRUE�����򷵻�FALSE��
	//##ModelId=483BB70801E9
	virtual OgdcBool IsBOF();	
	
	//! \brief �жϵ�ǰ��¼ָ���Ƿ�ָ��β��
	//! \return ָ��ָ��β����TRUE�����򷵻�FALSE��
	//##ModelId=483BB70801EB
	virtual OgdcBool IsEOF();	
	
	//! \brief �رռ�¼��
	//##ModelId=483BB70801F4
	virtual void Close();
	
	//! \brief ͨ���ֶ�����ȡ�ֶ�ֵ��
	//! \param strName �ֶ���[in]��
	//! \param varVal �ֶ�ֵ[out]��
	//! \return �Ƿ�ɹ���ȡ���ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70801F6
	virtual OgdcBool GetFieldValue(const OgdcString& strName, OgdcVariant& varVal);	
	
	//! \brief ͨ���ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nIndex �ֶ����[in]��
	//! \param varVal �ֶ�ֵ[out]��
	//! \return �Ƿ�ɹ���ȡ���ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70801FA
	virtual OgdcBool GetFieldValue(OgdcInt nIndex,OgdcVariant& varVal);	
	
	//! \brief ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ��
	//! \param strName �ֶ���[in]��
	//! \param varVal �ֶ�ֵ[in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks �ֶ�ֵΪ��������
	//##ModelId=483BB7080203
	virtual OgdcBool SetFieldValue(const OgdcString& strName,const OgdcVariant& varVal);	
	
	//! \brief ͨ���ֶ�������õ�ǰ��¼���ֶ�ֵ��
	//! \param nIndex �ֶ����[in]��
	//! \param varVal �ֶ�ֵ[in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks �ֶ�ֵΪ�������͡�
	//##ModelId=483BB7080207
	virtual OgdcBool SetFieldValue(OgdcInt nIndex,const OgdcVariant& varVal);	
	
	//##ModelId=483BB708020B
	virtual OgdcBool Find(const OgdcString& strFilter, 
		OgdcRecordset::FindMode nFindMode = OgdcRecordset::First);	
	
	//##ModelId=483BB7080213
	virtual OgdcBool Move(OgdcRecordset::MovePosition nFromPosition = OgdcRecordset::Current, 
		OgdcInt nRows = 1);	
	
	//! \brief ��ȡ��¼������
	//! \return ��¼������
	//##ModelId=483BB7080217
	virtual OgdcInt GetRecordCount();	
	
	//! \brief �ռ������ֶε���Ϣ��
	//! \param fieldInfos �����ռ������ֶε��ֶ���Ϣ���������[out]��
	//! \return �Ƿ��ռ��ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7080219
	virtual OgdcBool GetFieldInfos(OgdcFieldInfos& fieldInfos);	
	
	//! \brief ͨ���ֶ�����ȡ�ֶ���Ϣ��
	//! \param strName �ֶ���[in]��
	//! \param fieldInfo �ֶ���Ϣ����[out]��
	//! \return �Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB708021C
	virtual OgdcBool GetFieldInfo(const OgdcString& strName,OgdcFieldInfo& fieldInfo);			

	//! \brief ��ĳ��ͳ�Ʒ���ͳ��ĳ���ֶΡ�
	//! \param strFieldName ͳ�Ƶ��ֶ���[in]��
	//! \param nMode ͳ��ģʽ[in]��
	//! \return ͳ��ֵ��
	//##ModelId=483BB7080222
	virtual OgdcVariant Statistic(const OgdcString& strFieldName,
		OgdcStatisticMode nMode);	

	//! \brief ���²�ѯ��ˢ�¼�¼����
	//! \return �Ƿ�ɹ���ѯ���ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7080226
	virtual OgdcBool ReQuery();	

	//! \brief �����¼���ĵ���Χ��
	//! \param rc2Bounds ��¼���ĵ���Χ[out]��
	//! \param &dMinZ ��¼����С�߳�[in]��
	//! \param &dMaxZ ��¼�����߳�[in]��
	//! \return �Ƿ����ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7080228
	virtual OgdcBool ComputeBounds(OgdcRect2D &rc2Bounds,
		OgdcDouble &dMinZ, OgdcDouble &dMaxZ);	

public:
	//! \brief �����ֶ�ֵ��
	//! \param strSrcField Դ�ֶ���[in]��
	//! \param strDestField Ŀ���ֶ���[in]��
	//! \return �Ƿ�ɹ����ƣ��ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention strSrcField��trDestField���붼�������ֶ�����ƥ�䡣
	//##ModelId=483BB708022D
	virtual OgdcBool CopyField(const OgdcString& strSrcExpression,
		const OgdcString& strDestFieldName);	
	
	//! \brief ��ȡ��ǰ��¼��ID��
	//! \return ��ǰ��¼��ID��
	//##ModelId=483BB7080235
	virtual OgdcInt GetID();	

	//! \brief ��ȡ���ζ��󣬷��صļ��ζ���ָ���ں����ڷ����ڴ棬��
	//! \param pElement �ռ��ζ���ָ������ȡ�����ζ���[in]��
	//! \return �Ƿ�ȡ���ζ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention ���渺��ɾ������������ڴ�й©��
	//##ModelId=483BB7080237
	virtual OgdcBool GetElement(OgdcElement*& pElement);	

	//! \brief ���õ�ǰ��¼�ļ��ζ���
	//! \param pElement ���ζ���ָ��[in]��
	//! \return �Ƿ����ü��ζ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB708023A
	virtual OgdcBool SetElement(OgdcElement* pElement);	

	//! \brief �����¼�¼,�ɹ�������TRUEֵ��ʧ�ܷ���FALSEֵ��
	//! \param *pGeometry [in] ��ӵ�Geometryָ��
	//! \param bReturnID=FALSE [in] �˲����Ѿ��������á�
	//! \return True �� False ��ֵ
	//! \remarks �����õ��¶����ID����ô���ϵ���GetId����
	//##ModelId=483BB708023D
	virtual OgdcInt AddNew(OgdcElement *pElement, OgdcBool bReturnID=FALSE);

	//! \brief ȡ�����ݼ���ĳ������Ҫ�ء�
	//! \param nID ���ݼ���¼ID��[in]��
	//! \return ����Ҫ��ָ�롣
	//##ModelId=483BB7080243
	virtual OgdcFeature* GetFeature();	

	//! \brief ������Ҫ�ظ��µ����ݼ��С�
	//! \param pFeature ����Ҫ��ָ��[in]��
	//! \return �Ƿ񱣴�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7080245
	virtual OgdcBool UpdateFeature(const OgdcFeature* pFeature);
	
	//! \brief ������Ҫ��׷�ӵ����ݼ�δβ��
	//! \param pFeature ����Ҫ��ָ��[in]��
	//! \return �Ƿ�׷�ӳɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ׷��ʱ����Ҫ�ع��������ݼ���¼ID���������á�
	//##ModelId=483BB7080248
	virtual OgdcBool AddFeature(const OgdcFeature* pFeature);

	//! \brief ͨ��ID��λ��¼ָ�롣
	//! \param nID ��¼ID[in]��
	//! \return ��λ�ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB708024B
	virtual OgdcBool SeekID(OgdcInt nID);	

	//! \brief ����¼�����µ����ݼ���
	//! \return ���¼�¼��ID��
	//##ModelId=483BB708024E
	virtual OgdcInt Update();	

	//! \brief ȡ���޸ġ�
	//! \return �ɹ�ȡ������TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7080252
	virtual OgdcBool CancelUpdate();	
	
	//! \brief ��ʼ�޸����ݡ�
	//! \return �ɹ���ʼ����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7080254
	virtual OgdcBool Edit();	

	//! \brief �Ƿ�ɸ���
	//! \return �ɸ��·���TRUE�����򷵻�FALSE��
	//##ModelId=483BB7080256
	virtual OgdcBool CanUpdate();	
	
	//! \brief ɾ����ǰ��¼��
	//! \return �Ƿ�ɹ�ɾ�����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7080258
	virtual OgdcBool Delete();	

	//! \brief ɾ�����м�¼��
	//! \return ɾ���ɹ�����TRRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB708025A
	virtual OgdcBool DeleteAll();

	//##ModelId=483BB708025C
	virtual OgdcDatasetVector* GetDataset();

	//##ModelId=483BB708025E
	UGRecordset* GetRecordset() const;
	//##ModelId=483BB7080262
	void SetRecordset(UGRecordset* pRecordset);

protected:	
	//##ModelId=483BB7080265
	UGRecordset* m_pRecordset;
	//##ModelId=483BB708026A
	UGDatasetVectorOgdc* m_pDtOgdc;

	UGGeometry* m_pGeometry;
};

}

#endif // !defined(AFX_UGRECORDSETOGDC_H__3447382C_208C_40E4_A613_E5790100E935__INCLUDED_)

