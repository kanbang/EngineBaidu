//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGRecordsetTile.h
//!  \brief UGRecordsetTile��Ľӿڶ��塣
//!  \details UDB��¼ֻ����¼���ࡣ
//!  \author Engine��
//!  \attention 
//!   Copyright (c) 2000-2010 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGRECORDSETTILE_H
#define UGRECORDSETTILE_H

#include "Geometry/UGGeometry.h"
#include "Geometry/UGFeature.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace UGC
{

//! \brief ʸ�������RecordsetTile��
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGRecordsetTile  
{
		 
public:
	UGRecordsetTile(){};

	virtual ~UGRecordsetTile(){};

public:
	//! \brief ��ȡ��¼����
	//! \remarks ֻ�ǴӼ������л�ȡ����������ͳ�ơ�
	//! \attention ��
	virtual UGint GetRecordCount() = 0;	

	//! \brief ��ȡ�ֶθ���
	virtual UGint GetFieldCount() = 0;

	//! \brief ��ȡ��ǰ��¼��ID
	virtual UGint GetID() = 0;
	
	//! \brief ͨ������ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(UGint nIndex, UGFieldInfo& fieldInfo) = 0;

	//! \brief �ƶ���¼ָ�뵽��ǰ
	virtual UGbool MoveFirst() = 0;

		//! \brief �ƶ���¼ָ�뵽��ǰ
	virtual UGbool MoveNext() = 0;
	
	//! \brief �жϵ�ǰ��¼ָ���Ƿ�ָ��β
	virtual UGbool IsEOF() = 0;

	//! \brief ȡ�ü��ζ��󣬷��صļ��ζ���ָ���ں����ڷ����ڴ棬
	//! ���渺��ɾ������������ڴ�й©
	virtual UGbool GetGeometry(UGGeometry*& pGeometry) = 0;
	
	//! \brief ͨ���ֶ�����ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(const UGString& strName,UGVariant& varVal) = 0;
	
// 	//! \brief ͨ��������Ż�ȡ�ֶ�ֵ
 	virtual UGbool GetFieldValue(UGint nIndex,UGVariant& varVal) = 0;

	//! \brief �رռ�¼��
	virtual void Close() = 0;

private:

};

}
#endif // !defined(UGRECORDSETUDB_H)

