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

#ifndef UGSCVCONFIGPARAMS_H
#define UGSCVCONFIGPARAMS_H

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC {
	
//! \brief GeoTiff�ĵ���������á�
class FILEPARSER_API UGSCVImportParams : public UGVectorImportParams
{	
public:
	
	//! \brief ���캯����
	UGSCVImportParams();
	
	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::SCV; }

	//! \brief �õ������ַ�����
	UGString GetPassword() const { return m_strPassword; }

	//! \brief ���������ַ�����
	void SetPassword(UGString val) { m_strPassword = val; }

private:
	UGString m_strPassword;
};


//! \brief GeoTIFF�ĵ����������á�
class FILEPARSER_API UGSCVExportParams : public UGVectorExportParams
{
public:
	
	//! \brief ���캯����
	UGSCVExportParams();
	
	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::SCV; }
	};
	
} //namespace UGC
#endif // !defined(UGSCVCONFIGPARAMS_H)

