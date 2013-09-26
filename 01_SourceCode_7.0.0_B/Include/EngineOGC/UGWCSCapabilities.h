//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file WCSCapabilities.h
//!  \brief WCS������������Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef WCSCAPABILITIES_H
#define WCSCAPABILITIES_H

#include "Stream/ugexports.h"
#include "EngineOGC/UGOGCCapabilities.h"

namespace UGC
{

class WCSCapabilities : public OGCCapabilities  
{
public:
	//! \brief  Ĭ�ϵĹ��캯��
	WCSCapabilities();
	//! \brief  Ĭ�ϵ���������
	virtual ~WCSCapabilities();
	
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
	virtual UGbool Serialize(UGMarkup* PDomTree);

	//! \brief ���������������л��õĶ���ͬ������������Դ��
	//! \param pDataSource ��������Դָ��[in]��
	//! \return �Ƿ�ͬ���ɹ���
	virtual UGbool SyncToDataSource(UGDataSourceOGC* pDataSource);

	//! \brief ��ȡ�ַ���ָ�����ַ��浽�����С�
	//! \param strSrc ԭ�ַ�����[in]
	//! \param arrStrDst ��Ž�ȡ����ַ��������顣[in]
	//! \param strseparator ��ȡ��ԭ��[in]
	void Split(UGString strSrc, UGArray<UGString>& arrStrDst, UGString strseparator);	
private:	
	//! \brief ���عؼ����ֵ�
	void LoadDict();

public:
	//! \brief ���WCS����ĳ�Ա����
 	WCSRequest m_OLRequest;	
	//! \brief ���ͼ������� 
 	UGArray<WCSCoverage*> m_arrCoverage;
};
///////////////////////// WCS 1.0.0 ///////////////////////////////////////
class WCSCapabilities100 : public WCSCapabilities
{
public:	
	//! \brief  Ĭ�ϵĹ��캯��
	WCSCapabilities100();
	//! \brief  Ĭ�ϵ���������
	virtual ~WCSCapabilities100();
public:
	//! \brief ��GetCapbilities�ļ����л��õ�OGC Web�����������
	//! \param strXMLFile GetCapbilities����õ���XML�ļ�·��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual UGbool Serialize(UGString strXMLFile);	
	
	//! \brief ��GetCapbilities�ļ��򿪵�Makup Dom �����л��õ�OGC Web�����������
	//! \param PDomTree Dom����ָ��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��XML �ļ��Ѿ�����Ҫ�ٴ�һ��ֱ����Dom�����ɡ�
	virtual UGbool Serialize(UGMarkup* PDomTree);
private:
	
	//! \brief ����markup����ȡ��������Ϣ��
	UGbool ParseOnlineResource(UGMarkup* PDomTree, UGString strNS);

};	

///////////////////////// WCS 1.1.0 ///////////////////////////////////////
class WCSCapabilities110 : public WCSCapabilities
{
public:	
	//! \brief  Ĭ�ϵĹ��캯��
	WCSCapabilities110();
	//! \brief  Ĭ�ϵ���������
	virtual ~WCSCapabilities110();
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
	//! \attention ��
	UGbool ParseOnlineResource(UGMarkup* PDomTree, UGString strNS);

};

///////////////////////////// WCS 1.1.*ϵ�У�1.1.1��1.1.2��///////////////////////////////////
class WCSCapabilities112 : public WCSCapabilities
{
public:
	//! \brief  Ĭ�ϵĹ��캯��
	WCSCapabilities112();
	//! \brief  Ĭ�ϵ���������
	virtual ~WCSCapabilities112();
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
	virtual UGbool Serialize(UGMarkup* pDomTree);

	//! \brief ����wcs�������ServiceIdentification����ȡ������Ϣ����
	//! \param PDomTree [in]Dom����ָ�롣��	
	//! \return ��
	UGbool ParseWCSServiceIdentification(UGMarkup* pDomTree);  

	//! \brief ����wcs�������ServiceProvider����ȡ������Ϣ����
	//! \param PDomTree [in]Dom����ָ�롣��	
	//! \return ��
	UGbool ParseWCSServiceProvider(UGMarkup* pDomTree);

	//! \brief ����wcs�������OperationsMetadata����ȡ������Ϣ����
	//! \param PDomTree [in]Dom����ָ�롣��	
	//! \return ��
	UGbool ParseWCSOperationsMetadata(UGMarkup* pDomTree);

	//! \brief ����wcs�������Contents����ȡ������Ϣ����
	//! \param PDomTree [in]Dom����ָ�롣��	
	//! \return ��
	UGbool ParseWCSContents(UGMarkup* pDomTree);  
};
}
#endif // !defined(WCSCAPABILITIES_H)

