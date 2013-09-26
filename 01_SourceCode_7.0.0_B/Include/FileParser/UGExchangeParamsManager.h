////////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \brief Class ��
//!  \details ��ʽת���顣
//!  \author linwenyu��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef AFX_UGEXCHANGEPARAMSMANAGER_H__INCLUDED_
#define AFX_UGEXCHANGEPARAMSMANAGER_H__INCLUDED_

//#if _MSC_VER > 1000
//#pragma once
//#endif // _MSC_VER > 1000

#include "Stream/ugdefs.h"
#include "FileParser/UGFileParserConfigParams.h"


namespace UGC {

//! \brief ת����������	
class FILEPARSER_API UGExchangeParamsManager  
{
public:

	//! \brief ���캯����
	UGExchangeParamsManager();

	//! \brief ����������
	virtual ~UGExchangeParamsManager();

public:

	//! \brief �õ���Ӧ��ʽ�ĵ���\��ȡ������
	//! \param nType [in]�ļ����͡�
	//! \return ʧ�ܷ���NULL��
	//! \remarks �û�������ڴ档
	//! \attention �ļ��������С�
	static UGImportParams* MakeImportParams(UGint nType);	

	//! \brief �õ���Ӧ��ʽ�ĵ���\����������
	//! \param nType [in]�ļ����͡�
	//! \return ʧ�ܷ���NULL��
	//! \remarks �û����ͷ��ڴ档
	//! \attention �ļ��������С�
	static UGExportParams* MakeExportParams(UGint nType);


	//! \brief �ͷŵ�����������
	//! \param pFileParser �ͷŴ������
	//! \return void 
	static void DestoryImportParams(UGImportParams* &pImportParams);
    
	//! \brief �ͷŵ�����������
	//! \param pFileParser �ͷŴ������
	//! \return void 
	static void DestoryExportParams(UGExportParams* &pExportParams);


	//! \brief ���������Ч�Լ�顣
	static UGbool IsValidImportParams(UGint nFileType, const UGImportParams& impParams);	

	//! \brief ����������Ч�Լ�顣
	static UGbool IsValidExportParams(UGint nFileType, const UGExportParams& expParams);

};

};

#endif // !defined(AFX_UGEXCHANGEPARAMSMANAGER_H__AB19AA8C_B64E_42F0_BFF3_DDE67CDBA62F__INCLUDED_)

