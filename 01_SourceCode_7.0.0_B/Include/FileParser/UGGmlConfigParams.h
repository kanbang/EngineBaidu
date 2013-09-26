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
//!  \author ����ת��С�顣
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

#ifndef __UGGMLIMPORTPARAMS_H__
#define __UGGMLIMPORTPARAMS_H__

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC
{
	//                           ����
	//-------------------------------------------------------------------->
	//! \brief GMl�����������
	class FILEPARSER_API UGGMLImportParams : public UGVectorImportParams
	{
	public:

		//! \brief GML �汾��
		//! \remarks ��
		enum EmVersion
		{
			GML    = 0, //֧�ֵ㡢�ߡ������ݼ��Լ��������ݼ�����֧���ı����ݵ�д��֧�ֶ�
			GMLSF  = 1, //֧�ֵ㡢�ߡ������ݼ��Լ��������ݼ�����֧���ı����ݵ�д��֧�ֶ�
			GML212 = 2  //֧�ֵ㡢�ߡ��桢�ı��Լ��������ݼ����ı����������ݼ�������Fixed Mode������FMEObjectĬ��ΪFixed Mode��
		};

		//! \brief ���캯����
		//! \remarks ��
		UGGMLImportParams();

		//! \brief ����������
		//! \remarks ��
		virtual ~UGGMLImportParams();
	public:
		//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual inline UGint GetFileType()const {return UGFileType::GML;}

		//! \brief �����Ƿ���3D���ݼ��ı�־��
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual void SetImportAs3DDataset(UGbool bImport3D);

		//! \brief ��ȡ����3D���ݼ��ı�־��
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetImportAs3DDataset();	

		//! \brief ��ȡ�汾
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGint GetVersion()const{return m_nVersion;} 

		//! \brief ���ð汾
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual  void SetVersion(UGint nVersion){m_nVersion=nVersion;}

		//! \brief ��CADģʽ����ʱ�������Ƿ���ԭʼCAD�ֲ�ṹ����
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		void SetImportByLayer(UGbool bByLayer = FALSE);

		//! \brief �ж�CAD������ȫͼ���߶�㵼�롣
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		UGbool GetImportByLayer() const;

	protected:
		//! \brief 3D���ݼ��ı�־��Ĭ��ΪTRUE.
		UGbool m_bImportAs3DData;

		//! \brief GML�汾����,Ĭ��ΪGMLSF
		//! ע������Ĭ�ϰ汾������ΪGML����߰汾��������߰汾����Ͱ汾������text��ʽ������
		//!     ��������Ĭ�ϰ汾ΪGMLSF���Ƚ���˰汾֮��ļ������⣬����������Ĭ�ϰ汾ΪGML
		UGint m_nVersion;

		//! \brief ��ʶCAD������ȫͼ���뻻�Ƕ�㵼�롣
		//! \remarks m_bMLayerImport = FALSE,ȫͼ����
		UGbool m_bMLayerImport;
	};

	//                                      ����
	//------------------------------------------------------------------------------>
	class FILEPARSER_API UGGMLExportParams : public UGVectorExportParams
	{
		//! \brief GML �汾��
		//! \remarks ��
		enum EmVersion
		{
			GML    = 0, //֧�ֵ㡢�ߡ������ݼ��Լ��������ݼ�����֧���ı����ݵ�д��֧�ֶ�
			GMLSF  = 1, //֧�ֵ㡢�ߡ������ݼ��Լ��������ݼ�����֧���ı����ݵ�д��֧�ֶ�
			GML212 = 2  //֧�ֵ㡢�ߡ��桢�ı��Լ��������ݼ����ı����������ݼ�������Fixed Mode������FMEObjectĬ��ΪFixed Mode��
		};

	public:
		//! \brief ���캯����
		//! \remarks ��
		UGGMLExportParams();

		//! \brief ����������
		//! \remarks ��
		virtual ~UGGMLExportParams();

	public:
		//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual inline UGint GetFileType()const {return UGFileType::GML;}

		//! \brief ��ȡ�汾
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGint GetVersion()const{return m_nVersion;} 

		//! \brief ���ð汾
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual  void SetVersion(UGint nVersion){m_nVersion=nVersion;}

	protected:
		//! \brief GML�汾����,Ĭ��ΪGML
		UGint m_nVersion;
	};
}

#endif