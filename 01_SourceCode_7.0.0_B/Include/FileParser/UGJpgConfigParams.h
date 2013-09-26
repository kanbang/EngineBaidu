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
//!  \author linwenyu��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG_JPG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_JPG_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGRasterConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC {

//! \brief JPEG�ĵ���������á�
class FILEPARSER_API UGJpgImportParams : public UGRasterImportParams
{	
public:

	//! \brief ���캯��	
	//! \return ��
	UGJpgImportParams() {};
	
	//! \brief ��������	
	//! \return ��
	~UGJpgImportParams() {};

public:


	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::JPG; }

	//! \brief �������ɵĵ��������ļ���·����
	void SetWorldFilePath(const UGString& strWorldFile) { m_strWorldFile = strWorldFile; }

	//! \brief �õ����������ļ�·��
	UGString GetWorldFilePath() const { return m_strWorldFile; }


protected:

	UGString m_strWorldFile;


	
};


//! \brief JPEG�ĵ����������á�
class FILEPARSER_API UGJpgExportParams : public UGRasterExportParams
{
public:

	//! \brief ���캯��	
	UGJpgExportParams(){ m_nquality = 75;m_nDpi=0; }

	//! \brief ��������	
	~UGJpgExportParams() {}

public:

	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::JPG; }


	//! \brief �������ɵĵ��������ļ���·����
	void SetWorldFilePath(const UGString& strWorldFile) {m_strWorldFile = strWorldFile;}

	//! \brief �õ����������ļ�·��
	UGString GetWorldFilePath() const { return m_strWorldFile; }

	//! \brief ����Jpeg�ļ���ѹ���ʡ�
	//! \param  nQuality [in]  Ĭ��ѹ����Ϊ75��nQualityȡֵ��Χ[10, 100]
	//! \attention nQualityֵԽС��ͼ��ѹ����Խ�ߣ�����Խ���
	virtual void SetQuality(UGint nQuality) { m_nquality = nQuality; }

	//! \brief �õ�ѹ���ʡ�	
	virtual UGint GetQuality() const {return m_nquality;}

	//! \brief ����ͼ��ķֱ���/DPI.
	//! \param ndpi [in] ͼ���DPI��
	//! \remarks �˽ӿ����ڵ�ͼ��ͼ��
	//! \attention Ŀǰ֧��JPG��
	virtual void SetResolution(UGint ndpi) {m_nDpi = ndpi;}

	////! \brief ����ͼ��ķֱ���/DPI.
	//! \param ��
	//! \remarks ��
	//! \attention ��
	virtual UGint GetResolution() {return m_nDpi;};


protected:

	UGint m_nquality;

	UGString m_strWorldFile;

	UGint m_nDpi;
};

} //namespace UGC
#endif // !defined(AFX_UG_JPG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

