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
//!  \author conversion��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGFILEGDBVECTORPARAMS_H
#define UGFILEGDBVECTORPARAMS_H

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC {

	//! \brief GeoTiff�ĵ���������á�
	class FILEPARSER_API UGGDBFVectorImportParams : public UGVectorImportParams
	{	
	public:

		//! \brief ���캯����
		UGGDBFVectorImportParams();

		//! \brief ���ص�ǰ��ʽת���������͡�
		virtual inline UGint GetFileType() const { return UGFileType::GDBFVector; }

		//! \brief �жϵ�����ȫͼ���߶�㵼�롣
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetImportByLayer() const{return TRUE;}

	};


	//! \brief GeoTIFF�ĵ����������á�
	class FILEPARSER_API UGGDBFVectorExportParams : public UGVectorExportParams
	{
	public:

		//! \brief ���캯����
		UGGDBFVectorExportParams();

		//! \brief ���ص�ǰ��ʽת���������͡�
		virtual inline UGint GetFileType() const { return UGFileType::GDBFVector; }
	};

} //namespace UGC
#endif // !defined(UGSCVCONFIGPARAMS_H)

