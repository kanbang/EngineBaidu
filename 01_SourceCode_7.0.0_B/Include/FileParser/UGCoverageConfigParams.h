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

#ifndef AFX_UG_CONVERAGR_FILEPARSERCONFIGPARAMS_H__INCLUDED_
#define AFX_UG_CONVERAGR_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC
{
	class FILEPARSER_API UGCoverageImportParams:public UGVectorImportParams
	{
	public:
		UGCoverageImportParams();
		virtual ~UGCoverageImportParams();

	public:
		//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
		virtual inline UGint GetFileType() const {return UGFileType::AIBinCov;}

		//! \brief �����Ƿ���3D���ݼ��ı�־��
		void SetImportAs3DDataset(UGbool bImport3D);

		//! \brief ��ȡ����3D���ݼ��ı�־��
		UGbool GetImportAs3DDataset();	

		//! \brief �жϵ�����ȫͼ���߶�㵼�롣
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetImportByLayer() const{return TRUE;}

	protected:
		UGbool m_bImportAs3DDataset;

	};
}

#endif