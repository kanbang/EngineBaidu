// UG3dsConfigParams.h: interface for the UGFileParserConfigParams class.
//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class 3dsģ�͵��뵼������
//!  \details ��
//!  \author sunye��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG_3DS_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_3DS_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGFileParserConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{	
class FILEPARSER_API UG3dsImportParams : public UGImportParams
{
public:
	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual UGint GetFileType() const	{ return UGFileType::Model3DS; }
};

//! \brief 3DS�ĵ����������á�
class FILEPARSER_API UG3dsExportParams : public UGExportParams
{
public:
	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual UGint GetFileType() const	{ return UGFileType::Model3DS; }
};

} //namespace UGC
#endif // !defined(AFX_UG_3DS_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

