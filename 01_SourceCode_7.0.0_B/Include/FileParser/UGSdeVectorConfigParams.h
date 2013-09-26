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

#if !defined(AFX_UG_SDEVECTOR_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_SDEVECTOR_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{	
//  Ŀǰ�˲���û��ʹ��  �ڲ����ж�����û���д���ļ�·��  �Ǿ��ǰ��ļ�·���ķ�ʽ
// 	enum SDEImportMode // �ڲ���sde��2�ִ򿪷�ʽ
// 	{
// 		SDE_Parms,  // ͨ��������
// 		SDE_File,   // ͨ���ļ���
// 	};
	//! \brief shp�ĵ���������á�
	class FILEPARSER_API UGSdeVectorImportParams : public UGVectorImportParams
	{	
	public:
		//! \brief ���캯����
		UGSdeVectorImportParams(const UGString strServer,
								const UGString strDbName,
								const UGString strUser,
								const UGString strPassword,
								const UGString strPort);

		UGSdeVectorImportParams(const UGString strFilePath);

		UGSdeVectorImportParams();

		//! \brief ����������
		virtual ~UGSdeVectorImportParams();

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

// 		//! \brief ����sde����ķ�ʽ��
// 		void SetSDEImportMode(const UGint nImportMode){m_nImportMode = nImportMode;}
// 
// 		//! \brief ��ȡsde����ķ�ʽ��
// 		UGint GetSDEImportMode() const {return m_nImportMode;}
		
		//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
		virtual inline UGint GetFileType() const	{ return UGFileType::SDEVector; }

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
/*		UGint    m_nImportMode;*/
	};


	//! \brief shp�ĵ����������á�
	class FILEPARSER_API UGSdeVectorExportParams : public UGVectorExportParams
	{

	public:
		//! \brief ���캯����
		UGSdeVectorExportParams();

		//! \brief ����������
		~UGSdeVectorExportParams();

		//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
		virtual inline UGint GetFileType() const	{ return UGFileType::Shape; }

	};

} //namespace UGC
#endif // !defined(AFX_UG_SDEVector_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

