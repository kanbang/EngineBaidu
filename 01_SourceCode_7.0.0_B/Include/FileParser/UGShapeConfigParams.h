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
//!  \author ��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG_SHAPE_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_SHAPE_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{


//! \brief shp�ĵ���������á�
class FILEPARSER_API UGShapeImportParams : public UGVectorImportParams
{
public:
	//! \brief ���캯����
	UGShapeImportParams();

	//! \brief ����������
	~UGShapeImportParams();

public:

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual inline UGint GetFileType() const	{ return UGFileType::Shape; }

	//! \brief �����Ƿ���3D���ݼ��ı�־��
	void SetImportAs3DDataset(UGbool bImport3D);

	//! \brief ��ȡ����3D���ݼ��ı�־��
	UGbool GetImportAs3DDataset();	

protected:
	UGbool m_bImportAs3DData;
};


//! \brief shp�ĵ����������á�
class FILEPARSER_API UGShapeExportParams : public UGVectorExportParams
{

public:
	//! \brief ���캯����
	UGShapeExportParams();

	//! \brief ����������
	~UGShapeExportParams();

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual inline UGint GetFileType() const	{ return UGFileType::Shape; }
	
};

typedef UGShapeImportParams UGShpImportParams;
typedef UGShapeExportParams UGShpExportParams;

} //namespace UGC
#endif // !defined(AFX_UG_PNG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

