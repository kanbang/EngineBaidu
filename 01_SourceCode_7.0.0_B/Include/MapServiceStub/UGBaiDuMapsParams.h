//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details ���������ϸ��Ϣ��
//!  \author ����ת���顣
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGBAIDUPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_)
#define AFX_UGBAIDUPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_

#include "MapServiceStub/UGMapServiceParams.h"
#include "MapServiceStub/UGMapServiceType.h"

namespace UGC {

	//! \brief ��ͼGoogleMaps����������á�
	class MAPSERVICESTUB_API UGBaiDuMapsParams : public UGMapServiceParams
	{
	public:
		//! \brief ���캯����
		//! \remarks ��
		UGBaiDuMapsParams();

		//! \brief ����������
		//! \remarks ��
		~UGBaiDuMapsParams();

	public:

		//! \brief ���ػ�ȡ�������͵ĺ�����
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGint GetServiceType() const	{ return UGMapServiceType::BaiDu; }
	
	public:

		//! \brief BaiDu��ͼ���͡�
		//! \param  [in]��
		UGString m_strMapType;
	    
		// ����˵�������������������������Ϊ�ٶ�2.5ά��ͼURL��������
		//! \brief URL���б�ʾ
        UGString m_strCityMark;

		//! \brief URL�������ݱ���
		UGint m_nCityNumber;

	};

} //namespace UGC
#endif // !defined(AFX_UGBAIDUPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_)

