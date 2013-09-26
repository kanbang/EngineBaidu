// UGFileParserConfigParams.h: interface for the UGFileParserConfigParams class.
//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author linwenyu��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

#ifndef AFX_UG_SIT_FILEPARSERCONFIGPARAMS_H__INCLUDED_
#define AFX_UG_SIT_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGRasterConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{


//! \brief GeoTiff�ĵ���������á�
class FILEPARSER_API UGSitImportParams : public UGRasterImportParams
{
	
public:

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual UGint GetFileType() const	{ return UGFileType::SIT; }
	
	//! \brief ��ȡ�����롣
	UGString GetPassWord() const {return m_strPassWord;}

	//! \brief ���ô����롣
	//! \param password  [in] ���ô����롣
	void SetPassWord(UGString password){m_strPassWord = password;}

private:
	//! ����
	UGString m_strPassWord;
};


//! \brief GeoTIFF�ĵ����������á�
class FILEPARSER_API UGSitExportParams : public UGRasterExportParams
{

public:
	//! ���캯��
	UGSitExportParams();

	//! ��������
	~UGSitExportParams();

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual UGint GetFileType() const	{ return UGFileType::SIT; }

	//! \brief ���ñ�������
	void SetEncodeType(UGint enType){ this->m_nType = enType;}

	//! \brief ��ȡ��������
	UGint GetEncodeType(){return m_nType;}

	void SetPassword(const UGString strPasswrod);

	UGString GetPassword() const;
	
private:
	//! brief ��������
	//! remark ��ʼֵΪ-1
	UGint m_nType;

	UGString m_strPassword;
};

} //namespace UGC
#endif // !defined(AFX_UG_SIT_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

