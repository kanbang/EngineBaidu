//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file OGCCapabilities.h
//!  \brief OGC �����������Ļ���Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef OGCCAPABILITIES_H
#define OGCCAPABILITIES_H

#include "Stream/ugexports.h"
#include "EngineOGC/UGOGCLayerInfo.h"
#include "Toolkit/UGMarkup.h"

namespace UGC
{

class UGDataSourceOGC;
class UGMarkup;

class OGCCapabilities  
{
	//! \brief �������ڷ��������ӵĹ����� 
	typedef struct ogcServer 
	{
		ogcServer()
		{
			m_strName = _U("");
			m_strTitle = _U("");
			m_strAbstract = _U("");
			m_arrKeywords.RemoveAll();
			m_strOnlineResource = _U("");
			m_strFees = _U("");
			m_strAccessConstraints = _U("");
			m_strServiceType = _U("");
			m_arrServiceTypeVersion.RemoveAll();
		}
		//! \brief wms�����ơ�
 		UGString m_strName;
		//! \brief wms�ı��⡣
		UGString m_strTitle;
		//! \brief wms��ժҪ��
		UGString m_strAbstract;
		//! \brief wms�Ĺؽ������顣
		UGArray<UGString> m_arrKeywords;
		//! \brief wms�������ַ��
		UGString m_strOnlineResource;
		//! \brief wms�ķ��á�
		UGString m_strFees;
		//! \brief wms�ķ������ơ�
		UGString m_strAccessConstraints;
		//! \brief wms�ķ�������
		UGString m_strServiceType;
		//! \brief wms�İ汾��
		UGArray<UGString> m_arrServiceTypeVersion;
	} server;
	
	typedef struct ContactInfo
	{
		ContactInfo()
		{
			m_strPhoneVoice=_U("");
			m_strPhoneFacsimile=_U("");		
			m_strDeliveryPoint.RemoveAll();
			m_strAddressType=_U("");
			m_strAddress=_U("");
			m_strCity=_U("");
			m_strAdministrativeArea=_U("");
			m_strPostalCode=_U("");
			m_strCountry=_U("");
			m_strElectronicMailAddress=_U("");	
			m_strOnlineResource=_U("");
			m_strHoursOfService=_U("");
			m_strContactInstructions=_U("");				
		}		
		//! \brief �����绰��	
		UGString m_strPhoneVoice;

		//! \brief ����
		UGString m_strPhoneFacsimile;

		//! \brief ���͵�ַ
		UGStrings m_strDeliveryPoint;

		//  \brief ��ʱ�������ָʲô,wms111���ֵı�ǩ
		UGString  m_strAddressType;

		//  \brief ��ʱ�������ָʲô,wms111���ֵı�ǩ
		UGString  m_strAddress;

		//! \brief ����
		UGString m_strCity;

		//! \brief ��������ֱϽ�л��������µ���
		UGString m_strAdministrativeArea;

		//! \brief �ʱ�
		UGString m_strPostalCode;

		//! \brief ����
		UGString m_strCountry;

		//! \brief Email
		UGString m_strElectronicMailAddress;

		//! \brief ������Դ
		UGString m_strOnlineResource;

		//! \brief  ����ʱ��
		UGString m_strHoursOfService;

		//! \brief ��ϵ��ʽ
		UGString m_strContactInstructions;		
	} ;	 

	typedef struct ServiceContact
	{
		ServiceContact()
		{
			m_strIndividualName = _U("");
			m_strPositionName   = _U("");
		}

		//! \brief ��ϵ��������
		UGString m_strIndividualName;

		//! \brief ��ϵ��ְλ��
		UGString m_strPositionName;

		//! \brief �����ṩ��������ϵ��Ϣ
		ContactInfo m_contactInfo;
	};

	typedef struct serviceProvider
	{
		serviceProvider()
		{
			m_strProviderName=_U("");
			m_strProviderSite=_U("");		
		}		
		//! \brief �����ṩ�̻���֯
		UGString m_strProviderName;

		//! \brief �����ṩ�̴������ϵ��
		UGString m_strProviderDelegate;

		//! \brief �����ṩ�̵��Ż���վ
		UGString m_strProviderSite;

		//! \brief �����ṩ���ص�(����ĵ�ַ)
		UGString m_strIndividualName;

		//! \brief �����ṩ����ַ(һ����Χ�ĵ�ַ)
		UGString m_strPositionName;

		//! \brief �����ṩ��������ϵ��Ϣ
		ServiceContact m_serviceContact;

		//! \brief �����ṩ���Ľ�ɫ
		UGString m_strRole;		 
	};
public:
	//! \brief  Ĭ�ϵĹ��캯��
	OGCCapabilities();
	//! \brief  Ĭ�ϵ���������
	virtual ~OGCCapabilities();

public:
	//! \brief ��GetCapbilities�ļ����л��õ�OGC Web�����������
	//! \param strXMLFile GetCapbilities����õ���XML�ļ�·��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual UGbool Serialize(UGString strXMLFile) = 0;	

	//! \brief ��GetCapbilities�ļ��򿪵�Makup Dom �����л��õ�OGC Web�����������
	//! \param PDomTree Dom����ָ��[in]��
	//! \return �Ƿ�ɹ����л����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��XML �ļ��Ѿ�����Ҫ�ٴ�һ��ֱ����Dom�����ɡ�
	virtual UGbool Serialize(UGMarkup* PDomTree) = 0;	

	//! \brief ���������������л��õĶ���ͬ������������Դ��
	//! \param pDataSource ��������Դָ��[in]��
	//! \return �Ƿ�ͬ���ɹ���
	virtual UGbool SyncToDataSource(UGDataSourceOGC* pDataSource) = 0;	

	//! \brief �Ƚ�������ǩ�Ƿ���ͬ  
	virtual UGbool SameXMLTag(const UGString& strTagLeft, const UGString& strTagRight);
	//! \brief �ӱ�ǩ�л�ȡ�����ռ� 
	virtual UGString TagNameSpace(const UGString& strTag);
    //! \brief �ӵ�ַ�л�ȡ�ֽ�ֵ���еĹؽ���
	virtual UGString TrimKeyWord(const UGString& strURL);	
public:
	//! \brief ���������ӽṹ�����
	//! \remarks ��ע��Ϣ��
	ogcServer m_InfoServer;

	//! \brief �����ṩ����Ϣ
	//! \remarks ��ע��Ϣ��
	serviceProvider m_serviceProvider;

	//! \brief �������İ汾
	UGString m_strVersion;

	//! \brief ���������������͡�
	//! \remarks ��ע��Ϣ��
	UGString m_strType;

protected:
	// ����һ��OGC URL ����Ĺؼ����ֵ�
	UGDict<UGString,int>  m_dictKeyWords;
};

}
#endif // !defined(OGCCAPABILITIES_H)

