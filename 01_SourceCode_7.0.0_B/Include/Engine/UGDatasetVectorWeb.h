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

#if !defined(AFX_UGDATASETVECTORWEB_H__7681AA6D_BDCB_4A18_A9A3_EC39CEBB7BE4__INCLUDED_)
#define AFX_UGDATASETVECTORWEB_H__7681AA6D_BDCB_4A18_A9A3_EC39CEBB7BE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDatasetVector.h"
namespace UGC
{
	class UGDownloadTileInfo;

	typedef void (UGSTDCALL * DownloadResponseFunc) (UGDownloadTileInfo result, UGlong pWnd);

	class ENGINE_API UGDatasetVectorWeb : public UGDatasetVector  
	{
	public:
		UGDatasetVectorWeb();
		virtual ~UGDatasetVectorWeb();

	public:

		//! \brief �����ݼ�
		virtual UGbool Open() = 0;

		//! \brief �ر����ݼ�
		virtual void Close() = 0;	

		//! \brief �ж��Ƿ�������դ�����ݼ�
		virtual UGbool IsWebVector();

		//!	\brief	���û����ļ���λ��
		virtual UGbool SetBufferPath(const UGString& strBuffPath);

		//! \brief ��ȡ�����ļ���λ��
		virtual UGString GetBufferPath() const;	

		//! \brief ���ûص�����
		virtual void SetDownloadResponseFunc(DownloadResponseFunc pFunc, UGlong pWnd) = 0;

		//! \brief �ж�һ�������Ƿ��Ѿ���ɣ�Request֮�����
		//! \return ��ɷ���True�����򷵻�False
		virtual UGbool IsComplete() = 0;

		//! \brief ����������Ƭ��
		//! \brief �����������
		//! \dScale param[in] ��ǰ��ͼ�ı�����
		//! \bound param[in] ��ǰ��ͼ��Χ
		//! \bCallBack ������Ƭ����ʱ�Ƿ�ص�
		virtual UGbool Request(const UGdouble& dScale, const UGRect2D& bound, UGbool bCallBack = TRUE) = 0;

	private:
		//! \brief �����ļ���λ��
		UGString m_strBufferPath;
	};

}

#endif // !defined(AFX_UGDATASETRASTERWEB_H__7681AA6D_BDCB_4A18_A9A3_EC39CEBB7BE4__INCLUDED_)