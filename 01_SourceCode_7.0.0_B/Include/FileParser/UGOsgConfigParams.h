// UG3dsConfigParams.h: interface for the UGFileParserConfigParams class.
//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class osg�Լ�osgb,osgt��ģ���ļ����뵼������
//!  \details ��
//!  \author zby,2012-8-6
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG_OSG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_OSG_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGFileParserConfigParams.h"
#include "FileParser/UGExchangeFileType.h"
#include "FileParser/UGModelConfigParams.h"

namespace UGC 
{	
class FILEPARSER_API UGOsgImportParams : public UGModelImportParams
{
public:
    
	//! \brief osg ���캯��
	UGOsgImportParams();
    
	//! \brief osg ��������
    virtual ~UGOsgImportParams();

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ���
	virtual UGint GetFileType() const;
    
	//! \brief ����ģ�͵Ķ�λ��
	//! \return
	void SetPosition(const UGPoint3D pntPosition3D);
    
	//! \brief ����ģ�͵Ķ�λ�ص�
	UGPoint3D GetPosition()const;

private:
	//! \brief ģ�͵���Ķ�λ�㣻
	//! \attention ����������û������ݽ���
	UGPoint3D m_pntPosition;
};


//! \brief OSG�ĵ����������á�
class FILEPARSER_API UGOsgExportParams : public UGExportParams
{
public:
	//! \brief osg �������ò������캯��
	UGOsgExportParams();

	//! \brief osg osg����������������
	virtual ~UGOsgExportParams();

	//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
	virtual UGint GetFileType() const;
};

} //namespace UGC
#endif // !defined(AFX_UG_OSG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

