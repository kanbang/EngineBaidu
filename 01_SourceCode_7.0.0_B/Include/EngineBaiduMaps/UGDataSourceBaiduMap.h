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
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0


#if !defined(AFX_UGDATASOURBAIDUMAPS_H__995B3D09_52BE_4B64_A81F_2302C09B00DC__INCLUDED_)
#define AFX_UGDATASOURBAIDUMAPS_H__995B3D09_52BE_4B64_A81F_2302C09B00DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDataSource.h"

namespace UGC
{   
	class ENGINEBAIDUMAPS_API UGDataSourceBaiduMap : public UGDataSource  
	{
	public:
		UGDataSourceBaiduMap();
		virtual ~UGDataSourceBaiduMap();

	public:
		//! \brief ������Դ,��ҪԤ�����ú�������Ϣ
		virtual UGbool Open();

		//! \brief �ر�����Դ
		virtual void Close();	

		//! \brief ����������Ϣ
		virtual UGbool SaveInfo();

	public:
		//! \brief ��ȡ��������
		virtual UGString GetEngineName() const;

		//##ModelId=48203052013C
		virtual UGint GetVersion();		

		//! \brief �Ƿ�������
		virtual UGbool IsConnected();

	public:
		//! \brief ��ȡ���п���ʾ��ͼ��
		virtual void GetAllLayers(UGArray<UGString>& arrLayers) const;
	private:
        
		//! \brief ���س���������Ϣ
		void Create3DMapDatasetS();

	};
#if !defined OS_ANDROID && !defined IOS
	extern "C" ENGINEBAIDUMAPS_API UGDataSource* CreateDataSource();
	extern "C" ENGINEBAIDUMAPS_API OgdcDataSource* CreateOgdcDataSource();
#else
	extern "C" ENGINEBAIDUMAPS_API UGDataSource* CreateBaiduMapDataSource();
#endif
}

#endif // !defined(AFX_UGDATASOURCEWEB_H__995B3D09_52BE_4B64_A81F_2302C09B00DC__INCLUDED_)

