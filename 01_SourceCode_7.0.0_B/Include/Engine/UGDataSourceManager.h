// UGDataSourceManager.h: interface for the UGDataSourceManager class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDataSourceManager.h
   **************************************************************************************
    \author   �¹���
    \brief    �������涯̬������࣬����̬���غ��ͷ�sdx���涯̬�⣬�������������ͺ�
			  ��̬����������ͬ���͵�����Դ��                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/


#if !defined(AFX_UGDATASOURCEMANAGER_H__EA4836B3_3C1F_4535_A920_07AC41C17303__INCLUDED_)
#define AFX_UGDATASOURCEMANAGER_H__EA4836B3_3C1F_4535_A920_07AC41C17303__INCLUDED_

#include "Engine/UGDataSource.h"
#include "OGDC/OgdcProviderManager.h"

namespace UGC {
  
//##ModelId=4820305103AB
typedef OgdcProvider UGProvider;

//##ModelId=4820305103BA
class ENGINE_API UGDataSourceManager  
{
public:
	//##ModelId=4820305103BB
	UGDataSourceManager();
	//##ModelId=4820305103BC
#ifdef SYMBIAN60
	~UGDataSourceManager();
#else
	virtual ~UGDataSourceManager();
#endif
	

public:
	//========================================================
	//! \remarks 		��������Դʵ������������������������һ������Դ����������Oracle��SQL Server���ݿ⣬
	//!			    	��������ָ��������Դ���ʹ���һ��UGDataSourceĳ�������ʵ������������ָ�롣
	//! \return 	UGDataSource*  newһ������Դָ�룬����������ɹ��ͷ���NULL��
	//! \param 		nEngineType �����������ͣ��������û���չ���������͡�
	//##ModelId=4820305103BE
	//! \brief 		��������Դʵ��
	static UGDataSource* CreateDataSource(UGEngineType nEngineType);

	//##ModelId=4820305103CC
	//! \brief 		��������Դʵ��
	static UGint GetProviderCount();	

	//! \brief �õ����������塣
	//! \param nIndex [in] ������
	//##ModelId=4820305103CE
	static UGProvider GetAt(UGint nIndex);	

	//! \brief ��ȡ����������
	//! \param nType �������������
	//##ModelId=4820305103D1
	static UGString GetProviderName(UGEngineType nEngineType);	

	//! \brief ����һ����׺��Ϊsdxָ���ļ�����OGDC��������̬�⡣
	//! \param strPathName [in]��
	//! \return ���سɹ�����true��
	//##ModelId=4820305103D4
	static UGbool LoadProvider(const UGString& strPathName);	

	//! \brief ж�غ�׺��Ϊsdx��OGDC��������̬�⡣
	//! \param hHandle [in] ��̬������
	//! \return �ɹ�ж�ط���true��
	//##ModelId=4820305103D8
	static UGbool UnloadProvider(void* hHandle);

	// ���� ������ ���ھ�̬����  for Android by liucq
	UGbool AddEngineProvider(void* handle);
};

extern ENGINE_API UGDataSourceManager g_DataSourceManager;

}

#endif // !defined(AFX_UGDATASOURCEMANAGER_H__EA4836B3_3C1F_4535_A920_07AC41C17303__INCLUDED_)

