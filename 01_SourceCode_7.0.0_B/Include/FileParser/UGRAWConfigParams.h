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

#ifndef AFX_UG_RAW_FILEPARSERCONFIGPARAMS_H__INCLUDED_
#define AFX_UG_RAW_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGRasterConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC {

//! \brief RAW�ĵ���������á�
class FILEPARSER_API UGRAWImportParams : public UGRasterImportParams
{	
public:
	//! \brief ���캯����
	UGRAWImportParams();
	
	//! \brief ����������
	virtual ~UGRAWImportParams();

	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::RAW; }
	
};


//! \brief TGA�ĵ����������á�
class FILEPARSER_API UGRAWExportParams : public UGRasterExportParams
{
public:

	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::RAW; }
	
};

} //namespace UGC
#endif // !defined(AFX_UG_RAW_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

