////////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \brief Class ��
//!  \details ����ת���顣
//!  \author ����ת���顣
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef AFX_UGMAPSERVICEPARAMSMANAGER_H__INCLUDED_
#define AFX_UGMAPSERVICEPARAMSMANAGER_H__INCLUDED_

//#if _MSC_VER > 1000
//#pragma once
//#endif // _MSC_VER > 1000

#include "Stream/ugdefs.h"
#include "MapServiceStub/UGMapServiceParams.h"


namespace UGC {

//! \brief ת����������	
class MAPSERVICESTUB_API UGMapServiceParamsManager  
{
public:

	//! \brief ���캯����
	UGMapServiceParamsManager();

	//! \brief ����������
	virtual ~UGMapServiceParamsManager();

public:

	//! \brief �õ���Ӧ��ʽ�ĵ���\��ȡ������
	//! \param nType [in]�ļ����͡�
	//! \return ʧ�ܷ���NULL��
	//! \remarks �û�������ڴ档
	//! \attention �ļ��������С�
	static UGMapServiceParams* MakeParams(UGint nType);	

	//! \brief ���������Ч�Լ�顣
	static UGbool IsValidParams(UGint nFileType, const UGMapServiceParams& impParams);	

};

};

#endif // !defined(AFX_UGMAPSERVICEPARAMSMANAGER_H__AB19AA8C_B64E_42F0_BFF3_DDE67CDBA62F__INCLUDED_)

