/////////////////////////////////////////////////////////////////////////
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

#ifndef UGFILEGDBRasterPARAMS_H
#define UGFILEGDBRasterPARAMS_H

#include "FileParser/UGRasterConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC
{
	class FILEPARSER_API UGGDBFRasterImportParams : public UGRasterImportParams
	{	
	public:

		//! \brief ���캯����
		UGGDBFRasterImportParams();

		//! \brief ��������
		virtual ~UGGDBFRasterImportParams();

		//! \brief ���ص�ǰ��ʽת���������͡�
		virtual UGint GetFileType() const { return UGFileType::GDBFRaster; }

		//! \brief �жϵ�����ȫͼ���߶�㵼�롣
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetImportByLayer() const{return TRUE;}
	};
}

#endif