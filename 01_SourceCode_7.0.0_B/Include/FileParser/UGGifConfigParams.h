// UGGifConfigParams.h: interface for the UGGifImportParams class.
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
//!  \author ��˷��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGIFCONFIGPARAMS_H__8A9955CA_A1E3_4409_9CB4_33A2EAD59B43__INCLUDED_)
#define AFX_UGGIFCONFIGPARAMS_H__8A9955CA_A1E3_4409_9CB4_33A2EAD59B43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// #include "..\..\..\INCLUDE\FILEPARSER\UGRasterConfigParams.h"

#include "FileParser/UGRasterConfigParams.h"
#include "FileParser/UGExchangeFileType.h"


namespace UGC 
{


class FILEPARSER_API UGGifImportParams : public UGRasterImportParams  
{
public:

	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::GIF; }

	//! \brief �������ɵĵ��������ļ���·����
	void SetWorldFilePath(const UGString& strWorldFile) { m_strWorldFile = strWorldFile; }

	//! \brief �õ����������ļ�·��
	UGString GetWorldFilePath() const { return m_strWorldFile; }

protected:

	UGString m_strWorldFile;

};


class FILEPARSER_API UGGifExportParams : public UGRasterExportParams  
{
public:
	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::GIF; }

	//! \brief �������ɵĵ��������ļ���·����
	void SetWorldFilePath(const UGString& strWorldFile) { m_strWorldFile = strWorldFile; }

	//! \brief �õ����������ļ�·��
	UGString GetWorldFilePath() const { return m_strWorldFile; }

protected:

	UGString m_strWorldFile;


};


} //namespace UGC
#endif // !defined(AFX_UGGIFCONFIGPARAMS_H__8A9955CA_A1E3_4409_9CB4_33A2EAD59B43__INCLUDED_)

