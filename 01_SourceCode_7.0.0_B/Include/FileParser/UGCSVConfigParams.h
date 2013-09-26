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


#ifndef __FILEPARSE_UGCSVCONFIGPARAMS_H_INCLUDE_
#define __FILEPARSE_UGCSVCONFIGPARAMS_H_INCLUDE_


#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{


//! \brief csv�ĵ���������á�
class FILEPARSER_API UGCSVImportParams : public UGVectorImportParams
{
public:
	//! \brief ���캯����
	UGCSVImportParams() {
		//m_bHasFieldInFirstLine=FALSE;
		m_strSeparator		= _U(",");
		m_bHasFieldInFirstRow = FALSE;
		m_bSetTargetFieldInfosByUse = FALSE;
	}

	//! \brief ����������
	virtual ~UGCSVImportParams() {};

public:

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual inline UGint GetFileType() const	{ return UGFileType::CSV; }

	UGbool GetHasTargetFieldInfosByUse() const { return m_bSetTargetFieldInfosByUse;}
	void SetHasTargetFieldInfosByUse(UGbool bhasField) {m_bSetTargetFieldInfosByUse = bhasField;}

	UGString GetSeparator() const { return m_strSeparator;};
	void SetSeparator(const UGString& strSeparator) { m_strSeparator = strSeparator;};
	
	void SetHasFieldInFirstRow(const UGbool bHasFieldInFirstRow)  {m_bHasFieldInFirstRow = bHasFieldInFirstRow;}
	UGbool GetHasFieldInFirstRow() const {return m_bHasFieldInFirstRow;}

	virtual UGString::Charset GetFileCharset();

protected:

	// �����Ƿ����ֶ�
	UGbool m_bHasFieldInFirstRow;
	UGString m_strSeparator;
	// �Ƿ�������SetTargetFieldInfos��ʹ����
	UGbool m_bSetTargetFieldInfosByUse;
};


//! \brief shp�ĵ����������á�
class FILEPARSER_API UGCSVExportParams : public UGVectorExportParams
{

public:
	//! \brief ���캯����
	UGCSVExportParams(){};

	//! \brief ����������
	virtual ~UGCSVExportParams(){};

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual inline UGint GetFileType() const	{ return UGFileType::CSV; }
	
};


} //namespace UGC
#endif // !defined(__FILEPARSE_UGCSVCONFIGPARAMS_H_INCLUDE_)


