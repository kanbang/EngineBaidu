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

#if !defined(AFX_UG_SDERASTER_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_SDERASTER_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGRasterConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC
{
	//! \brief sde�ĵ���������á�
	class FILEPARSER_API UGSdeRasterImportParams:public UGRasterImportParams
	{
	public:
		//! \brief ���캯����
		UGSdeRasterImportParams(
				const UGString strServer,
				const UGString strDbName,
				const UGString strUser,
				const UGString strPassword,
				const UGString strPort);

		UGSdeRasterImportParams(const UGString strFilePath);

		UGSdeRasterImportParams();

		UGSdeRasterImportParams(const UGSdeRasterImportParams& params);

		virtual ~UGSdeRasterImportParams();
	public:
		//! \brief ���÷��������ƻ�Ip��
		void SetServer(const UGString strServer){m_strServer = strServer;}

		//! \brief ��ȡ���������ƻ�Ip��
		UGString GetServer() const {return m_strServer;}

		//! \brief ����SDE���ݿ����ơ�
		void SetDbName(const UGString strDbName){m_strDbName = strDbName;}

		//! \brief ��ȡSDE���ݿ����ơ�
		UGString GetDbName() const {return m_strDbName;}

		//! \brief ����SDE���ݿ��û�����
		void SetUser(const UGString strUser){m_strUser = strUser;}

		//! \brief ��ȡSDE���ݿ��û�����
		UGString GetUser() const {return m_strUser;}

		//! \brief ����SDE���ݿ����롣
		void SetPassword(const UGString strPassword){m_strPassword = strPassword;}

		//! \brief ��ȡSDE���ݿ����롣
		UGString GetPasswrod() const {return m_strPassword;}

		//! \brief ��ȡSDE�˿����ơ�
		//! \param strPortName [in]��
		//! \attention ��ʽ��port:+�˿ں�  Ĭ��Ϊport:5151
		void SetPortName(const UGString strPortName){m_strPortName = strPortName;}

		//! \brief ��ȡSDE�˿����ơ�
		UGString GetPortName() const {return m_strPortName;}

		//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
		virtual inline UGint GetFileType() const	{ return UGFileType::SDERaster; }

		//! \brief �жϵ�����ȫͼ���߶�㵼�롣
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetImportByLayer() const{return TRUE;}

	protected:
		UGString m_strServer;
		UGString m_strDbName;
		UGString m_strUser;
		UGString m_strPassword;
		UGString m_strPortName;
	};
}
#endif