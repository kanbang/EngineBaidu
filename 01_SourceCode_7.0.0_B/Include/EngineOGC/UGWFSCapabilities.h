// WFSCapabilities.h: interface for the WFSCapabilities class.
//
//////////////////////////////////////////////////////////////////////

#ifndef OGCPARAERWFSCAPABILITIES_H
#define OGCPARAERWFSCAPABILITIES_H

#include "Stream/ugexports.h"
#include "EngineOGC/UGOGCCapabilities.h"

namespace UGC
{

class WFSCapabilities : public OGCCapabilities  
{
public:
	//! \brief  Ĭ�ϵĹ��캯��
	WFSCapabilities();
	//! \brief  Ĭ�ϵ���������
	virtual ~WFSCapabilities();
	
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
	//! \brief ���WFS����ĳ�Ա����
	WFSRequest m_OLRequest;
	//! \brief �洢WFS�Ĳ������顣
	UGArray<UGString> m_arrOperations;
	//! \brief �洢�������������  
	UGArray<WFSFeatureType*> m_arrFeatureType;
};

///////////////////////// WFS 1.0.0 ///////////////////////////////////////
class WFSCapabilities100 : public WFSCapabilities
{
public:	
	//! \brief  Ĭ�ϵĹ��캯��
	WFSCapabilities100();
	//! \brief  Ĭ�ϵ���������
	virtual ~WFSCapabilities100();
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
	//! \brief ����markup����ȡ��������Ϣ��
	//! \remarks ��
	//! \attention 
	UGbool ParseOnlineResource(UGMarkup* PDomTree, UGString strNS);
};	

///////////////////////// WFS 1.1.0 ///////////////////////////////////////
class WFSCapabilities110 : public WFSCapabilities
{
public:	
	//! \brief  Ĭ�ϵĹ��캯��
	WFSCapabilities110();
	//! \brief  Ĭ�ϵ���������
	virtual ~WFSCapabilities110();
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
	//! \brief ����markup����ȡ��������Ϣ��
	//! \remarks ��
	//! \attention 	
	UGbool ParseOnlineResource(UGMarkup* PDomTree, UGString strNS);

};	

}
#endif // !defined(WFSCAPABILITIES_H)

