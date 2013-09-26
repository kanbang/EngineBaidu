// WMSCapabilities.h: interface for the WMSCapabilities class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WMSCAPABILITIES_H__242599E7_D70B_4B0B_99B5_6D5970EFC6A3__INCLUDED_)
#define AFX_WMSCAPABILITIES_H__242599E7_D70B_4B0B_99B5_6D5970EFC6A3__INCLUDED_

#include "Stream/ugexports.h"
#include "EngineOGC/UGOGCCapabilities.h"

namespace UGC
{

class WMSCapabilities : public OGCCapabilities  
{
public:
	//! \brief  Ĭ�ϵĹ��캯��
	WMSCapabilities();
	//! \brief  Ĭ�ϵ���������
	virtual ~WMSCapabilities();

public:
	//! \brief ��GetCapbilities�ļ����л��õ�OGC Web�����������
	//! \param strXMLFile GetCapbilities����õ���XML�ļ�·��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��
	//! \attention ��
	virtual UGbool Serialize(UGString strXMLFile);	
	
	//! \brief ��GetCapbilities�ļ��򿪵�Makup Dom �����л��õ�OGC Web�����������
	//! \param PDomTree Dom����ָ��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��XML �ļ��Ѿ�����Ҫ�ٴ�һ��ֱ����Dom�����ɡ�
	//! \attention ��
	virtual UGbool Serialize(UGMarkup* PDomTree);
	
	//! \brief ���������������л��õĶ���ͬ������������Դ��
	//! \param pDataSource ��������Դָ��[in]��
	//! \return �Ƿ�ͬ�����
	//! \remarks ��
	//! \attention ��
	virtual UGbool SyncToDataSource(UGDataSourceOGC* pDataSource);

private:
	//! \brief ���عؼ����ֵ� 
	//! \attention ��
	void LoadDict();	

public:
	//! \brief ���WMS����ĳ�Ա����
	WMSRequest m_OLRequest;
	//! \brief ���ͼ��
	WMSLayer* m_pLayers;

};

///////////////////////// WMS 1.0.0 ///////////////////////////////////////
class WMSCapabilities100 : public WMSCapabilities
{
public:	
	//! \brief  Ĭ�ϵĹ��캯��
	WMSCapabilities100();
	//! \brief  Ĭ�ϵ���������
	virtual ~WMSCapabilities100();
public:
	//! \brief ��GetCapbilities�ļ����л��õ�OGC Web�����������
	//! \param strXMLFile GetCapbilities����õ���XML�ļ�·��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��
	//! \attention ��
	virtual UGbool Serialize(UGString strXMLFile);	
	
	//! \brief ��GetCapbilities�ļ��򿪵�Makup Dom �����л��õ�OGC Web�����������
	//! \param PDomTree Dom����ָ��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��XML �ļ��Ѿ�����Ҫ�ٴ�һ��ֱ����Dom�����ɡ�
	//! \attention ��
	virtual UGbool Serialize(UGMarkup* PDomTree);
private:

	WMSLayer* ParseLayerRecursion(UGMarkup* PDomTree, UGString strNS, 
		WMSLayer* pParentLayer);
    //! \brief ����markup����ȡ��������Ϣ��
	//! \remarks ��
	//! \attention 
	UGbool ParseOnlineResource(UGMarkup* PDomTree, UGString strNS);

};	

///////////////////////// WMS 1.1.0 ///////////////////////////////////////
class WMSCapabilities110 : public WMSCapabilities
{
public:	
	//! \brief  Ĭ�ϵĹ��캯��
	WMSCapabilities110();
	//! \brief  Ĭ�ϵ���������
	virtual ~WMSCapabilities110();
public:
	//! \brief ��GetCapbilities�ļ����л��õ�OGC Web�����������
	//! \param strXMLFile GetCapbilities����õ���XML�ļ�·��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��
	//! \attention ��
	virtual UGbool Serialize(UGString strXMLFile);	
	
	//! \brief ��GetCapbilities�ļ��򿪵�Makup Dom �����л��õ�OGC Web�����������
	//! \param PDomTree Dom����ָ��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��XML �ļ��Ѿ�����Ҫ�ٴ�һ��ֱ����Dom�����ɡ�
	//! \attention ��
	virtual UGbool Serialize(UGMarkup* PDomTree);
private:
	//! \brief ����markup����ȡͼ����Ϣ��
	//! \remarks ��
	//! \attention 
	WMSLayer* ParseLayerRecursion(UGMarkup* PDomTree, UGString strNS, 
		WMSLayer* pParentLayer);
    //! \brief ����markup����ȡ��������Ϣ��
	//! \remarks ��
	//! \attention 
	UGbool ParseOnlineResource(UGMarkup* PDomTree, UGString strNS);

};	

///////////////////////// WMS 1.1.1 ///////////////////////////////////////
class WMSCapabilities111 : public WMSCapabilities
{
public:	
	//! \brief  Ĭ�ϵĹ��캯��
	WMSCapabilities111();
	//! \brief  Ĭ�ϵ���������
	virtual ~WMSCapabilities111();
public:
	//! \brief ��GetCapbilities�ļ����л��õ�OGC Web�����������
	//! \param strXMLFile GetCapbilities����õ���XML�ļ�·��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��
	//! \attention ��
	virtual UGbool Serialize(UGString strXMLFile);	
	
	//! \brief ��GetCapbilities�ļ��򿪵�Makup Dom �����л��õ�OGC Web�����������
	//! \param PDomTree Dom����ָ��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��XML �ļ��Ѿ�����Ҫ�ٴ�һ��ֱ����Dom�����ɡ�
	//! \attention ��
	virtual UGbool Serialize(UGMarkup* PDomTree);
private:
	//! \brief ����markup����ȡͼ����Ϣ��
	//! \remarks ��
	//! \attention 
	WMSLayer* ParseLayerRecursion(UGMarkup* PDomTree, UGString strNS, 
		WMSLayer* pParentLayer);
	//! \brief ����markup����ȡ��������Ϣ��
	//! \remarks ��
	//! \attention 
	UGbool ParseOnlineResource(UGMarkup* PDomTree, UGString strNS);
	
};	

///////////////////////// WMS 1.3.0 ///////////////////////////////////////
class WMSCapabilities130 : public WMSCapabilities
{
public:	
	//! \brief  Ĭ�ϵĹ��캯��
	WMSCapabilities130();
	//! \brief  Ĭ�ϵ���������
	virtual ~WMSCapabilities130();
public:
	//! \brief ��GetCapbilities�ļ����л��õ�OGC Web�����������
	//! \param strXMLFile GetCapbilities����õ���XML�ļ�·��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��
	//! \attention ��
	virtual UGbool Serialize(UGString strXMLFile);	
	
	//! \brief ��GetCapbilities�ļ��򿪵�Makup Dom �����л��õ�OGC Web�����������
	//! \param PDomTree Dom����ָ��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��XML �ļ��Ѿ�����Ҫ�ٴ�һ��ֱ����Dom�����ɡ�
	//! \attention ��
	virtual UGbool Serialize(UGMarkup* PDomTree);
private:
	//! \brief ����markup����ȡͼ����Ϣ��
	//! \remarks ��
	//! \attention 
	WMSLayer* ParseLayerRecursion(UGMarkup* PDomTree, UGString strNS, 
		WMSLayer* pParentLayer);
	//! \brief ����markup����ȡ��������Ϣ��
	//! \remarks ��
	//! \attention 
	UGbool ParseOnlineResource(UGMarkup* PDomTree, UGString strNS);
};	

}
#endif // !defined(AFX_WMSCAPABILITIES_H__242599E7_D70B_4B0B_99B5_6D5970EFC6A3__INCLUDED_)

