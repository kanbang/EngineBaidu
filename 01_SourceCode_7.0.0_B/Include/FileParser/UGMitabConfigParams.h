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

#if !defined(AFX_UG_MITAB_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_MITAB_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGWorkSpaceConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC {

class FILEPARSER_API UGMiWorImportParams : public UGWorkspaceImportParams
{	
public:

	//! \brief ���캯����
	UGMiWorImportParams();

	//! \brief ���ص�ǰ��ʽת���������͡�

	//! \param  [in]��
	//! \return ���ſ��·����
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const { return UGFileType::WOR; }

	//! \brief ���ص���ſ��·����
	//! \param  [in]��
	//! \return ���ſ��·����
	//! \remarks ��
	//! \attention ��
	UGString GetMarkerStyleLibPath() const {return m_markerStyleLibPath;}

	//! \brief �����߷��ſ��·����
	//! \param  [in]��
	//! \return ���ſ��·����
	//! \remarks ��
	//! \attention ��
	UGString GetLineStyleLibPath() const {return m_lineStyleLibPath;}

	//! \brief ���������ſ��·����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGString GetFillStyleLibPath() const {return m_fillStyleLibPath;}

	//! \brief ���õ���ſ��·����
	//! \param path [in] ���ſ��·����
	//! \return ��
	//! \remarks �����û�Ϊ�ճ���Ĭ����BinĿ¼�µ�MapInfo.sym��
	//! \attention ��
	void SetMarkerStyleLibPath(UGString path) {m_markerStyleLibPath = path;}

	//! \brief �����߷��ſ��·����
	//! \param path [in] ���ſ��·����
	//! \return ��
	//! \remarks �����û�Ϊ�ճ���Ĭ����BinĿ¼�µ�MapInfo.lsl��
	//! \attention ��
	void SetLineStyleLibPath(UGString path) {m_lineStyleLibPath = path;}

	//! \brief ���������ſ��·����
	//! \param path [in] ���ſ��·����
	//! \return ��
	//! \remarks �����û�Ϊ�ճ���Ĭ����BinĿ¼�µ�MapInfo.bru��
	//! \attention ��
	void SetFillStyleLibPath(UGString path) {m_fillStyleLibPath = path;}

	//! \brief ���÷����ձ��·����
	//! \param [in] ��
	//! \return �����ձ��·����
	//! \remarks �����û�Ϊ�ճ���Ĭ����BinĿ¼�µ�MiStyMap.conf��
	//! \attention ��
	UGString GetStyleMapFilePath() {return m_StyleMapFilePath;}

	//! \brief ����������ձ��·����
	//! \param path [in] �����ձ��·����
	//! \return ��
	//! \remarks �����û�Ϊ�ճ���Ĭ����BinĿ¼�µ�MiStyMap.conf��
	//! \attention ��
	void SetStyleMapFilePath(UGString path) {m_StyleMapFilePath = path;}

private:
	//����ſ��·��
	UGString m_markerStyleLibPath;

	//�߷��ſ��·��
	UGString m_lineStyleLibPath;

	//�����ſ��·��
	UGString m_fillStyleLibPath;


	//�����ձ�·��
	UGString m_StyleMapFilePath;
};

//! \brief MapInfo(TAB)�ĵ���������á�
class FILEPARSER_API UGMitabImportParams : public UGVectorImportParams
{	
public:

	//! \brief ���캯����
	UGMitabImportParams();

	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::TAB; }

	//! \brief �Ƿ����CAD��ʽ��Ĭ���Ǽ����ݼ���ʽ����
	//UGbool IsImportToCAD() const {return m_bImToCAD;}

	//! \brief �����Ƿ����CAD��ʽ��Ĭ���Ǽ����ݼ���ʽ����
	//void SetImportToCAD(UGbool toCAD){m_bImToCAD = toCAD;}

	//! \brief ���÷����ձ��·����
	//! \param [in] ��
	//! \return �����ձ��·����
	//! \remarks �����û�Ϊ�ճ���Ĭ����BinĿ¼�µ�MiStyMap.conf��
	//! \attention ��
	UGString GetStyleMapFilePath() {return m_StyleMapFilePath;}

	//! \brief ����������ձ��·����
	//! \param path [in] �����ձ��·����
	//! \return ��
	//! \remarks �����û�Ϊ�ճ���Ĭ����BinĿ¼�µ�MiStyMap.conf��
	//! \attention ��
	void SetStyleMapFilePath(UGString path) {m_StyleMapFilePath = path;}

private:
	//UGbool m_bImToCAD;

	//�����ձ�·��
	UGString m_StyleMapFilePath;
};

//! \brief MapInfo(MIF)�ĵ���������á�
class FILEPARSER_API UGMifImportParams : public UGVectorImportParams
{	
public:

	//! \brief ���캯����
	UGMifImportParams(){}

	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::MIF; }

	//! \brief ���÷����ձ��·����
	//! \param [in] ��
	//! \return �����ձ��·����
	//! \remarks �����û�Ϊ�ճ���Ĭ����BinĿ¼�µ�MiStyMap.conf��
	//! \attention ��
	UGString GetStyleMapFilePath() {return m_StyleMapFilePath;}

	//! \brief ����������ձ��·����
	//! \param path [in] �����ձ��·����
	//! \return ��
	//! \remarks �����û�Ϊ�ճ���Ĭ����BinĿ¼�µ�MiStyMap.conf��
	//! \attention ��
	void SetStyleMapFilePath(UGString path) {m_StyleMapFilePath = path;}

private:

	//�����ձ�·��
	UGString m_StyleMapFilePath;
};


//! \brief MapInfo(TAB)�ĵ����������á�
class FILEPARSER_API UGMitabExportParams : public UGVectorExportParams
{
public:

	//! \brief ���캯����
	UGMitabExportParams();

	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::TAB; }

	//����ֱ�Ӱ�����չ������𣬲������ò�����������������ȡ��
	//! \brief �Ƿ񵼳���mif��ʽ��Ĭ����Mif��ʽ����
	//UGbool IsExportToMif() const {return m_bExpToMif;}

	//! \brief �����Ƿ񵼳���mif��ʽ��Ĭ����Mif��ʽ����
	//void SetExportToMif(UGbool toMif){m_bExpToMif = toMif;}

private:
	//UGbool m_bExpToMif;
	
};

//! \brief MapInfo(MIF)�ĵ����������á�
class FILEPARSER_API UGMifExportParams : public UGVectorExportParams
{
public:

	//! \brief ���캯����
	UGMifExportParams(){}

	//! \brief ���ص�ǰ��ʽת���������͡�
	virtual inline UGint GetFileType() const { return UGFileType::MIF; }

private:

};

} //namespace UGC
#endif // !defined(AFX_UG_MITAB_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

