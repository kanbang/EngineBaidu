// UGFileParserConfigParams.h: interface for the UGFileParserConfigParams class.
//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class ��ʵ��PNG���뵼��
//!  \details ��
//!  \author ��˷��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG_PNG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_PNG_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGRasterConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{


//! \brief PNG�ĵ���������á�
class FILEPARSER_API UGPngImportParams : public UGRasterImportParams
{
	
public:

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual UGint GetFileType() const	{ return UGFileType::PNG; }

	//! \brief �������ɵĵ��������ļ���·����
	void SetWorldFilePath(const UGString& strWorldFile) { m_strWorldFile = strWorldFile; }

	//! \brief �õ����������ļ�·��
	UGString GetWorldFilePath() const { return m_strWorldFile; }

protected:

	UGString m_strWorldFile;
	

private:
};



//! \brief PNG�ĵ����������á�
class FILEPARSER_API UGPngExportParams : public UGRasterExportParams
{

public:

	//! \brief ����png��ͼѹ����
	enum PngQuality {
		NO_COMPRESSION,		//��ѹ��
		BEST_SPEED,			//����ѹ����ѹ����Ϊ1���ٶȽϿ�
		DEFAULT,			//Ĭ��ѹ����ѹ����Ϊ6
		BEST_COMPRESSION	//����ѹ����ѹ����Ϊ9���ٶȽ���
	};

	//! \brief ���캯����
	//! \remarks ��
	UGPngExportParams();
	
	//! \brief ����������
	//! \remarks ��
	~UGPngExportParams();


	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual UGint GetFileType() const	{ return UGFileType::PNG; }

	//! \brief �������ɵĵ��������ļ���·����
	void SetWorldFilePath(const UGString& strWorldFile) { m_strWorldFile = strWorldFile; }

	//! \brief �õ����������ļ�·��
	UGString GetWorldFilePath() const { return m_strWorldFile; }

	//! \brief ��ȡpng��ͼѹ����
	PngQuality GetPngQuality() const { return m_enumPngQuality; }

	//! \brief ����PNG��ͼѹ����
	void SetPngQuality(PngQuality pngQ = UGPngExportParams::DEFAULT) { m_enumPngQuality = pngQ; 	}


	//! \brief ����ͼ��ķֱ���/DPI.
	//! \param ndpi [in] ͼ���DPI��
	//! \remarks �˽ӿ����ڵ�ͼ��ͼ��
	//! \attention Ŀǰ֧��JPG��
	virtual void SetResolution(UGint ndpi) {m_ndpi=ndpi;};

	////! \brief ����ͼ��ķֱ���/DPI.
	//! \param ��
	//! \remarks ��
	//! \attention ����ĸ�ʽ���ò�����Ҫ��д�˺�����
	virtual UGint GetResolution() {return m_ndpi;};

	////! \brief ��ȡ�Ƿ񵼳�Ϊ8λpng.
	//! \param   Ĭ��ΪFalse��
	//! \remarks ��
	//! \attention ��
	UGbool GetSaveAs8Bit(){return m_bIsSaveAs8Bit;}

	////! \brief �����Ƿ񵼳�Ϊ8λpng.
	//! \param ��
	//! \remarks ��
	//! \attention ��
	void SetSaveAs8Bit(UGbool bIsSaveAs8Bit){m_bIsSaveAs8Bit = bIsSaveAs8Bit;}

protected:

	UGString m_strWorldFile;

	UGint m_ndpi;

private:
	//! \brief pngѹ����
	PngQuality m_enumPngQuality;

	//! \brief png����Ϊ8λ��ʶ��Ĭ��ΪFalse
	UGbool m_bIsSaveAs8Bit;
};


} //namespace UGC
#endif // !defined(AFX_UG_PNG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

