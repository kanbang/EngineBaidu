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

#ifndef __UGMAPGISIMPORTPARAMS_H__
#define __UGMAPGISIMPORTPARAMS_H__

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{
//! \brief Dxf�ĵ���������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGMapGisImportParams : public UGVectorImportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGMapGisImportParams();

	//! \brief ����������
	//! \remarks ��
	~UGMapGisImportParams();

public:

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const	{ return UGFileType::MAPGIS; }
public:
	//! \brief ��ȡMAPGIS��ɫ�����ļ�·����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGString GetColorIndexFilePath()const;
	//! \brief ����MAPGIS��ɫ�����ļ�·����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetColorIndexFilePath(const UGString & strPath);
protected:
	//! \brief MAPGIS��ɫ�����ļ�·����Ĭ��ΪBinD�µ�"\MapGISColor.wat"�ļ�
	UGString m_strColorIndexFilePath;
};

//! \brief Dxf�ĵ����������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGMapGisExportParams : public UGVectorExportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGMapGisExportParams();

	//! \brief ����������
	//! \remarks ��
	~UGMapGisExportParams();
public:
	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const	{ return UGFileType::MAPGIS; }
public:
	
	//! \brief ��ȡҪ������ʸ�����ݰ汾�š�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGint GetVersion() const;	

	//! \brief ����Ҫ������ʸ�����ݰ汾�š�
	//! \param  nVer [in] ���õİ汾�š�
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetVersion(UGint nVer);
protected:
	//! \brief ʸ������Ҫ�������ļ��汾�š�
	//! \remarks ��	
	UGint m_dFileVersion;
};
} //namespace UGC
#endif // !defined(AFX_UG_PNG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

