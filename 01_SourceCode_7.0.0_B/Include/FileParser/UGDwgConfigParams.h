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
//!  \author ����ǿ��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG_DWG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_DWG_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGAcadConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{
//! \brief dwg�ĵ���������á�
class FILEPARSER_API UGDwgImportParams : public UGAcadImportParams
{
public:
	//! \brief ���캯����
	UGDwgImportParams();

	//! \brief ����������
	~UGDwgImportParams();

public:

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual inline UGint GetFileType() const	{ return UGFileType::DWG; }
	//! \brief ���õ��뵼�����룬ĳЩ�ļ������ǲ������޸ĵģ������ļ����Ͷ�����
	virtual UGbool SetImportOrExportCharset(UGString::Charset Charset){ return FALSE;};
	virtual UGString::Charset GetFileCharset(){return UGString::UCS2LE;};
};


//! \brief dwg�ĵ����������á�
class FILEPARSER_API UGDwgExportParams : public UGAcadExportParams
{

public:
	//! \brief ���캯����
	UGDwgExportParams();

	//! \brief ����������
	~UGDwgExportParams();
public:
	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual inline UGint GetFileType() const	{ return UGFileType::DWG; }
	//! \brief ���õ��뵼�����룬ĳЩ�ļ������ǲ������޸ĵģ������ļ����Ͷ�����
	virtual UGbool SetImportOrExportCharset(UGString::Charset Charset){ return FALSE;};
	virtual UGString::Charset GetFileCharset(){return UGString::UCS2LE;};
	
};
} //namespace UGC
#endif // !defined(AFX_UG_PNG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

