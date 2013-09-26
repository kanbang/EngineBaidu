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


#if !defined(AFX_UGRESTPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_)
#define AFX_UGRESTPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_

#include "MapServiceStub/UGMapServiceParams.h"
#include "MapServiceStub/UGMapServiceType.h"

namespace UGC {

	//! \brief ��ͼGoogleMaps����������á�
	class MAPSERVICESTUB_API UGRestParams : public UGMapServiceParams
	{
	public:
		//! \brief ���캯����
		//! \remarks ��
		UGRestParams();

		//! \brief ����������
		//! \remarks ��
		~UGRestParams();

	public:

		//! \brief ���ػ�ȡ�������͵ĺ�����
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGint GetServiceType() const	{ return UGMapServiceType::Rest; }

		//! \brief ͨ��URL��ʼ����ͼ����
		virtual UGbool InitParams();

		//! \brief ͨ������sci�ļ���ʼ����ͼ����
		virtual UGbool FromLocalCache(const UGString& strCacheFile);

		//! \brief ��ȡ���ػ�������Ŀ¼����webcache֮���Ŀ¼
		virtual UGString GetRelativePath();

	private:
		UGbool ParseURL();

	public:
		//! \brief �Ƿ����ÿɼ�������
		UGbool m_bVisibleScalesEnabled;

		//! \brief ����������
		UGString m_strHost;

		//! \brief �������˿ں�
		UGString m_strPort;

		//! \brief ��������
		UGString m_strServer;

	};

} //namespace UGC
#endif // !defined(AFX_UGRESTPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_)

