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
//!  \author ����ת���顣
//!  \attention �벻Ҫ����޸�����ĳ������塣
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMAPSERVICETYPE_H__EAB125D4_D53A_4784_A77E_5A8636BC43BD__INCLUDED_)
#define AFX_UGMAPSERVICETYPE_H__EAB125D4_D53A_4784_A77E_5A8636BC43BD__INCLUDED_

#include "Stream/ugdefs.h"

namespace UGC {

//! \brief ����ת��֧�ֵ��ļ����͡�
class MAPSERVICESTUB_API UGMapServiceType
{
public:

	// �����ʽ����	
	// �û��Զ����100��ʼ
	enum EmType
	{
		// ����ʶ	
		none					= 0, 

		WMTS					= 26,
        
		//�ȸ��ͼ����
		GoogleMaps				= 223,
		// ��ͼ�Ʒ���
		SuperMapCloud			= 224,
        
		//rest ��ͼ����
		Rest					= 225,
        
		//���ͼ
		MapWorldMaps		    = 226,
		
		//�ٶȵ�ͼ
		BaiDu                   = 227,
		//���Žֵ���ͼ
		OpenStreetMaps          = 228

	};

};

} //namespace UGC

#endif // !defined(AFX_UGMAPSERVICETYPE_H__EAB125D4_D53A_4784_A77E_5A8636BC43BD__INCLUDED_)


