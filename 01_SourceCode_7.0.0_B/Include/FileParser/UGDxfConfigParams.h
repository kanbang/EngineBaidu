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

#if !defined(AFX_UG_DXF_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_DXF_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGAcadConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{
//! \brief Dxf�ĵ���������á�
class FILEPARSER_API UGDxfImportParams : public UGAcadImportParams
{
public:
	//! \brief ���캯����
	UGDxfImportParams();

	//! \brief ����������
	~UGDxfImportParams();

public:

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual inline UGint GetFileType() const	{ return UGFileType::DXF; }	
	//! \brief ���õ��뵼�����룬ĳЩ�ļ������ǲ������޸ĵģ������ļ����Ͷ�����
	virtual UGbool SetImportOrExportCharset(UGString::Charset Charset){ return FALSE;};
	virtual UGString::Charset GetFileCharset(){return UGString::UCS2LE;};
};


//! \brief Dxf�ĵ����������á�
class FILEPARSER_API UGDxfExportParams : public UGAcadExportParams
{
public:
	//! \brief ���캯����
	UGDxfExportParams();

	//! \brief ����������
	~UGDxfExportParams();

public:
	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual inline UGint GetFileType() const	{ return UGFileType::DXF; }
	//! \brief ���õ��뵼�����룬ĳЩ�ļ������ǲ������޸ĵģ������ļ����Ͷ�����
	virtual UGbool SetImportOrExportCharset(UGString::Charset Charset){ return FALSE;};
	virtual UGString::Charset GetFileCharset(){return UGString::UCS2LE;};
};
} //namespace UGC
#endif // !defined(AFX_UG_PNG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

