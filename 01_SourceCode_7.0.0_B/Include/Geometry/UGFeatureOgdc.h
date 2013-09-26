// UGFeatureOgdc.h: interface for the UGFeatureOgdc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFEATUREOGDC_H__8FC0C4F6_9CB9_4E1A_9F44_F579DFDEC94F__INCLUDED_)
#define AFX_UGFEATUREOGDC_H__8FC0C4F6_9CB9_4E1A_9F44_F579DFDEC94F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry/UGFeature.h"

namespace UGC {

//##ModelId=483BB708036B
class GEOMETRY_API UGFeatureOgdc : public OgdcFeature  
{
public:
	//##ModelId=483BB708036D
	UGFeatureOgdc();
	//##ModelId=483BB708036E
	virtual ~UGFeatureOgdc();

public:
	//##ModelId=483BB7080370
	virtual OgdcInt GetID() const;	
	
	//! \brief ���ü��ζ���ID��
	//! \param nID ���ζ���ID[in]��
	//##ModelId=483BB708037B
	virtual void SetID(OgdcInt nID);	

	//! \brief ��ȡ���ζ������治���ͷš�
	//! \return �Ƿ�ȡ���ζ���ɹ����ɹ����ؼ��ζ���ʧ�ܷ���NULL��
	//##ModelId=483BB708037E
	virtual OgdcElement* GetElement();	
	
	//! \brief ���õ�ǰ����Ҫ�صļ��ζ��������Ժ����治���ͷš�
	//! \param pElement ���ζ���ָ��[in]��
	//##ModelId=483BB7080380
	virtual void SetElement(OgdcElement* pElement);	

	//! \brief �����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nIndex �ֶ����[in]��
	//##ModelId=483BB708038C
	virtual OgdcBool GetValue(OgdcInt nIndex, OgdcVariant& varValue);

	//! \brief �����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//##ModelId=483BB7080390
	virtual OgdcBool GetValue(const OgdcString& strFieldName, OgdcVariant& varValue);	

	//! \brief �����ֶ���������ֶ�ֵ��
	//! \param nIndex �ֶ����[in]��
	//! \param varValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7080394
	virtual OgdcBool SetValue(OgdcInt nIndex, const OgdcVariant& varValue);    

	//! \brief �����ֶ��������ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \param varValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7080399
	virtual OgdcBool SetValue(const OgdcString& strFieldName, const OgdcVariant& varValue);	

	//! \brief �����ֶ���Ϣ��
	//! \param fieldInfos �ֶ���Ϣ����[in]��
	//##ModelId=483BB708039D
	virtual void SetFieldInfos(const OgdcFieldInfos& fieldInfos);
	
	//! \brief ��ȡ�ַ�����
	//! \param nCharset [in]��
	//##ModelId=483BB70803A0
	virtual OgdcString::Charset GetCharset() const;
	
	//! \brief �����ַ�����
	//! \param nCharset [in]��
	//##ModelId=483BB70803A2
	virtual void SetCharset(OgdcString::Charset nCharset);

	//! \brief ��ȡUGFeatureָ�롣
	//##ModelId=483BB70803A5
	UGFeature* GetFeature() const;

	//! \brief ��UGFeature����UGFeatureOgdc��
	//! \param pFeature [in]��
	//##ModelId=483BB70803A7
	void SetFeature(UGFeature* pFeature);

protected:	
	//##ModelId=483BB70803AB
	UGFeature* m_pFeature;
	//##ModelId=483BB70803AF
	OgdcElement* m_pElement;
};

}

#endif // !defined(AFX_UGFEATUREOGDC_H__8FC0C4F6_9CB9_4E1A_9F44_F579DFDEC94F__INCLUDED_)

