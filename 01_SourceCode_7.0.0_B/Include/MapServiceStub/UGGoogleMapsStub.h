//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class ��
//!  \details ��
//!  \author ����ת���顣
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGGOOGLEMAPSSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
#define AFX_UGGOOGLEMAPSSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_

#include "MapServiceStub/UGMapServiceStub.h"

namespace UGC 
{
	class UGHMACSHA1;
//! \brief ����������ࡣ
//! \remarks �����йط�������Ķ�Ҫ�̳д��ࡣ
class MAPSERVICESTUB_API UGGoogleMapsStub : public UGMapServiceStub 
{
public:
	//! \brief ���캯����
	UGGoogleMapsStub();

	//! \brief ����������
	virtual ~UGGoogleMapsStub();
	
public:
	//! \brief �򿪷���
	//! \param impParams [in]��
	//! \return �ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention ���ط���ǰ���á�
	virtual UGbool Open(const UGMapServiceParams* impParams, UGbool bReSave = TRUE);

	//! \brief ����ClientID����ʱֻ��GoogleMapsʹ��
	virtual void SetUser(const UGString& strClientID);

	//! \brief ����ǩ������ʱֻ��GoogleMapsʹ��
	virtual void SetPassword(const UGString& strPassword);

	//! \brief ���ػ�ȡ�������͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual UGint GetServiceType() const	{ return UGMapServiceType::GoogleMaps; }

protected:

	//! \brief ����URL����
	//! \param tileInfo[in]����URL����Ƭ
	//! \param strURL[out]�����URL
	virtual void GenerateURL(const UGTileInfo& tileInfo, UGString& strURL);

	//! \brief ����URLʱ�Ƿ����TileInfo������
	virtual UGbool IsGenerateURLByTileInfo(){return TRUE;}

	UGString m_strMapType;

	const UGint GetGoogleMapsZoom(const UGdouble dScale);

private:
	UGString m_strClientID;
	UGString m_strKey;

	UGHMACSHA1 *m_pSHA1;
	
};

} //namespace UGC

#endif // !defined(AFX_UGSMCLOUDSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)

