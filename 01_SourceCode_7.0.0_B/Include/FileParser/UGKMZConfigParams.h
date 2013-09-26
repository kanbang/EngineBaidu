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
//!  \author ����ǿ��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

#ifndef __UGKMZIMPORTPARAMS_H__
#define __UGKMZIMPORTPARAMS_H__

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{
//! \brief Dxf�ĵ���������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGKMZImportParams : public UGVectorImportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGKMZImportParams();

	//! \brief ����������
	//! \remarks ��
	~UGKMZImportParams();

public:

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const	{ return UGFileType::KMZ; }

	//! \brief �����Ƿ���ɼ������־
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	inline void SetImportVisible(UGbool bImport) { m_bImportVisible = bImport; }

	//! \brief ��ȡ�Ƿ���ɼ������־
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	inline UGbool GetImportVisible() const	{ return m_bImportVisible; }
	//! \brief ���õ��뵼�����룬ĳЩ�ļ������ǲ������޸ĵģ������ļ����Ͷ�����
	virtual UGbool SetImportOrExportCharset(UGString::Charset Charset){ return FALSE;};
	virtual UGString::Charset GetFileCharset(){return UGString::UTF8;};
protected:
	//! \brief �Ƿ���ɼ�����Ĭ��ΪTUE.
	UGbool m_bImportVisible;//
};

//! \brief Dxf�ĵ����������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGKMZExportParams : public UGVectorExportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGKMZExportParams();

	//! \brief ����������
	//! \remarks ��
	~UGKMZExportParams();
public:
	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const	{ return UGFileType::KMZ; }
public:
	
	//! \brief ��ȡҪ������ʸ�����ݰ汾�š�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGdouble GetVersion() const;	

	//! \brief ����Ҫ������ʸ�����ݰ汾�š�
	//! \param  nVer [in] ���õİ汾�š�
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetVersion(UGdouble nVer = 0.1);
	//! \brief ��ȡҪ������ʸ�����ݼ��������顣
	//! \param  [in]��
	//! \return ��
	//! \remarks ���ݼ��������顣
	//! \attention Ϊ�˶�����ݼ�����ʹ�á�
	//! ע��˽ӿ����麯��, ֧�ֶ����ݼ��������ܵĸ�ʽ��Ҫ����
	virtual UGbool GetDtNamesBeExported(UGStrings& arrNames) const;

	//! \brief ����Ҫ������ʸ�����ݼ��������顣
	//! \param  name [in] ���õ����ơ�
	//! \return ��
	//! \remarks ��
	//! \attention Ϊ�˶�����ݼ�����ʹ�á�
	//! ע��˽ӿ����麯��, ֧�ֶ����ݼ��������ܵĸ�ʽ��Ҫ����
	virtual void SetDtNamesBeExported(const UGStrings& arrNames);
	//! \brief ���õ��뵼�����룬ĳЩ�ļ������ǲ������޸ĵģ������ļ����Ͷ�����
	virtual UGbool SetImportOrExportCharset(UGString::Charset Charset){ return FALSE;};
protected:
	//! \brief ʸ������Ҫ�������ļ��汾�š�
	//! \remarks ��	
	UGdouble m_dFileVersion;
	//! \brief ��Ҫ���������ݼ�����
	UGStrings m_strDatasetNames;
};
} //namespace UGC
#endif // !defined(AFX_UG_PNG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

