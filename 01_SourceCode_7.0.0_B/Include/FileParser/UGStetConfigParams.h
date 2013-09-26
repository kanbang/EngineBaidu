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
//!  \author zby��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

#ifndef AFX_UG_STET_FILEPARSERCONFIGPARAMS_H__INCLUDED_
#define AFX_UG_STET_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGRasterConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{

//! \brief stet�ĵ���������á�
class FILEPARSER_API UGStetImportParams : public UGRasterImportParams
{
	
public:
	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	UGStetImportParams(){}
	~UGStetImportParams(){}

	virtual UGint GetFileType() const	{ return UGFileType::STET; }
};


//! \brief stet�ĵ����������á�
class FILEPARSER_API UGStetExportParams : public UGRasterExportParams
{

public:
	//! ���캯��
	UGStetExportParams(){m_nType=-1;}

	//! ��������
	~UGStetExportParams(){}

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual UGint GetFileType() const	{ return UGFileType::STET; }

	//! \brief ���ñ�������
	void SetEncodeType(UGint enType){ this->m_nType = enType;}

	//! \brief ��ȡ��������
	UGint GetEncodeType(){return m_nType;}

private:
	//! brief ��������
	//! remark ��ʼֵΪ-1
	UGint m_nType;
};

} //namespace UGC
#endif // !defined(AFX_UG_STET_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

