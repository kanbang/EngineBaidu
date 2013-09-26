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

#if !defined(AFX_UG_BMP_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_BMP_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGRasterConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC {

//! \brief BMP�ĵ���������á�
class FILEPARSER_API UGBmpImportParams : public UGRasterImportParams
{	
public:
	
	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::BMP; }


	//! \brief �������ɵĵ��������ļ���·����
	//! \param strWorldFile [in]��
	void SetWorldFilePath(const UGString& strWorldFile) { m_strWorldFile = strWorldFile; }

	//! \brief �õ����������ļ�·��
	//! \param strWorldFile [in]��
	UGString GetWorldFilePath() const { return m_strWorldFile; }

protected:

	UGString m_strWorldFile;


};


//! \brief BMP�ĵ����������á�
class FILEPARSER_API UGBmpExportParams : public UGRasterExportParams
{
public:

	UGBmpExportParams() {}
	~UGBmpExportParams() {}	
	
public:
	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::BMP; }


	//! \brief �������ɵĵ��������ļ���·����
	//! \param strWorldFile [in]��
	void SetWorldFilePath(const UGString& strWorldFile) { m_strWorldFile = strWorldFile;}

	//! \brief �õ����������ļ�·��
	//! \param strWorldFile [in]��
	UGString GetWorldFilePath() const { return m_strWorldFile; }

protected:

	UGString m_strWorldFile;

};

} //namespace UGC
#endif // !defined(AFX_UG_BMP_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

