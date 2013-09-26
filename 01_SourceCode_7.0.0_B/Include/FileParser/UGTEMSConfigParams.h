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
//!  \author zhongdz��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG_TEMS_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_TEMS_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"
#include "FileParser/UGRasterConfigParams.h"

namespace UGC 
{


//! \brief ��������Vector�ĵ���������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGTemsVectorImportParams : public UGVectorImportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGTemsVectorImportParams();

	//! \brief ����������
	//! \remarks ��
	~UGTemsVectorImportParams();

public:
	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const	{ return UGFileType::TEMSVector; }

	//! \brief �жϵ�����ȫͼ���߶�㵼�롣
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual UGbool GetImportByLayer() const{return TRUE;}

};


//! \brief ��������Vector�ĵ����������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGTemsVectorExportParams : public UGVectorExportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGTemsVectorExportParams();

	//! \brief ����������
	//! \remarks ��
	~UGTemsVectorExportParams();

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const	{ return UGFileType::TEMSVector;}

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

protected:
	//! \brief ��Ҫ���������ݼ�����
	UGStrings m_strDatasetNames;

};



//! \brief ��������Building vector�ĵ���������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGTemsBldngVctrImportParams : public UGVectorImportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGTemsBldngVctrImportParams();

	//! \brief ����������
	//! \remarks ��
	~UGTemsBldngVctrImportParams();

	//! \brief �жϵ�����ȫͼ���߶�㵼�롣
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual UGbool GetImportByLayer() const{return TRUE;}

public:
	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const	{ return UGFileType::TEMSBldngVctr;}

};


//! \brief ��������Building vector�ĵ����������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGTemsBldngVctrExportParams : public UGVectorExportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGTemsBldngVctrExportParams();

	//! \brief ����������
	//! \remarks ��
	~UGTemsBldngVctrExportParams();

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const	{ return UGFileType::TEMSBldngVctr ;}

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

protected:
	//! \brief ��Ҫ���������ݼ�����
	UGStrings m_strDatasetNames;

};



//! \brief ��������Clutter�ĵ���������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGTemsClutterImportParams : public UGRasterImportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGTemsClutterImportParams();

	//! \brief ����������
	//! \remarks ��
	~UGTemsClutterImportParams();

public:
	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const	{ return UGFileType::TEMSClutter; }

	//! \brief �������ɵĵ��������ļ���·����
	//! \param strWorldFile [in]��
	void SetWorldFilePath(const UGString& strWorldFile) { m_strWorldFile = strWorldFile; }

	//! \brief �õ����������ļ�·��
	//! \param strWorldFile [in]��
	UGString GetWorldFilePath() const { return m_strWorldFile; }

protected:

	UGString m_strWorldFile;

};


//! \brief ��������Clutter�ĵ����������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGTemsClutterExportParams : public UGRasterExportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGTemsClutterExportParams();

	//! \brief ����������
	//! \remarks ��
	~UGTemsClutterExportParams();

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const	{ return UGFileType::TEMSClutter; }

	//! \brief �������ɵĵ��������ļ���·����
	//! \param strWorldFile [in]��
	void SetWorldFilePath(const UGString& strWorldFile) { m_strWorldFile = strWorldFile; }

	//! \brief �õ����������ļ�·��
	//! \param strWorldFile [in]��
	UGString GetWorldFilePath() const { return m_strWorldFile; }

protected:

	UGString m_strWorldFile;

};


} //namespace UGC

#endif // !defined(AFX_UG_TEMS_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

