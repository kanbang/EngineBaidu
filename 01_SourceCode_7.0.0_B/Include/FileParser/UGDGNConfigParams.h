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

#ifndef  __UGDGNIMPORTPARAMS_H__
#define  __UGDGNIMPORTPARAMS_H__

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC
{
	//                         ����
	//----------------------------------------------------------------------->
	//! \brief DGN�����������
	class FILEPARSER_API UGDGNImportParams : public UGVectorImportParams
	{
	public:
		//! \brief ���캯����
		//! \remarks ��
		UGDGNImportParams();

		//! \brief ����������
		//! \remarks ��
		virtual ~UGDGNImportParams();

	public:
		//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual inline UGint GetFileType()const {return UGFileType::DGN;}

		//! \brief ��CADģʽ����ʱ�������Ƿ���ԭʼCAD�ֲ�ṹ����
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual void SetImportByLayer(UGbool bByLayer = FALSE);

		//! \brief �ж�CAD������ȫͼ���߶�㵼�롣
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetImportByLayer() const;

		//! \brief �����Ƿ�Cell�����������Cell hearder���Ե����ʽ��,��CAD�еĿ�������Ӧ��
		//! \param bResolve [in]��
		//! \return ��
		//! \remarks ����ΪTRUEʱ��Cell���󼸺���Ϣ���ԣ�Cell����ֵ����Cell header�Ե����ʽ��ʾ       
		//! \attention ��
		virtual void SetCellAsPoint(UGbool bAsPoint = FALSE);

		//! \brief ��ȡ�Ƿ�Cell�����������Cell hearder���Ե����ʽ����
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetCellAsPoint()const ;

		//! \brief �����Ƿ����Polyline��LWPline�Ŀ�ȡ�͹����Ϣ
		//! \param bResolve [in]��
		//! \return ��
		//! \remarks ����ΪTRUEʱ������ߵġ�͹�ȡ�������ȡ���Ϣ��ʧ���������������ߡ���
		//! \attention ��
		void SetIgnoreLwplineWidth(UGbool bIgnore = FALSE);

		//! \brief �õ��Ƿ����Polyline��LWPline�Ŀ�ȡ�͹����Ϣ
		//! \param bResolve [in]��
		//! \return ��
		//! \remarks 
		//! \attention ��
		UGbool GetIgnoreLwplineWidth() const;

		//! \brief ���÷�����·����
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		void SetStyleMapFilePath(const UGString& strPath);
		
		//! \brief ��ȡ������·����
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		UGString GetStyleMapFilePath() const;
		
	protected:
		//! \brief ��ʶCAD������ȫͼ���뻻�Ƕ�㵼�롣
		//! \remarks m_bMLayerImport = FALSE,ȫͼ����
		UGbool m_bMLayerImport;

		//! \brief Cell�����Ƿ���Ϊ�㣨Cell header������
		UGbool m_bAsPoint;
        
		//! \brief �����ձ��ļ�·��
		UGString m_strStyleMapPath;

		//! \brief �����Ż�����ߵ��߿�
		//! \remarks ��
		UGbool m_bIgnoreLwplineWidth;
	};

	//                                ����
	//----------------------------------------------------------------->
	class FILEPARSER_API UGDGNExportParams : public UGVectorExportParams
	{
		//! \brief DGN �汾��
		//! \remarks ��
		enum EmVersion
		{
			DGNV7 = 0, //DGN v7�汾
			DGNV8 = 1  //DGN v8�汾
		};

	public:
		//! \brief ���캯����
		//! \remarks ��
		UGDGNExportParams();

		//! \brief ����������
		//! \remarks ��
		virtual ~UGDGNExportParams();
	public:
		//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual  UGint GetFileType() const { return UGFileType::DGN; }

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
		//! \brief GML�汾����,Ĭ��ΪGMLSF
		//! Ĭ��Ϊv8�汾 
		UGint m_nVersion;
	};
}
#endif