////////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \brief Class ��
//!  \details ����ת���顣
//!  \author ����ת����
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef AFX_UGMAPSERVICESTUBMANAGER_H__INCLUDED_
#define AFX_UGMAPSERVICESTUBMANAGER_H__INCLUDED_

//#if _MSC_VER > 1000
//#pragma once
//#endif // _MSC_VER > 1000

#include "Stream/ugdefs.h"
#include "MapServiceStub/UGMapServiceType.h"
#include "MapServiceStub/UGMapServiceStubDefine.h"
#include "MapServiceStub/UGMapServiceStub.h"


namespace UGC {

//! \brief ת����������	
class MAPSERVICESTUB_API UGMapServiceStubManager  
{

public:
	//! \brief ���캯����
	UGMapServiceStubManager();

	//! \brief ����������
	virtual ~UGMapServiceStubManager();

// 	//! \brief �õ��������������Ŀ��
// 	static UGint GetCount();		
// 
// 	//! \brief �õ�������������塣
// 	//! \param nIndex [in] ������
// 	//! \return ��
// 	static UGMapServiceStubDefine* GetAt(UGint nIndex);	
// 
// 	//! \brief ����һ��ָ���ļ����ķ����������
// 	//! \param strPathName [in]��
// 	//! \return ���سɹ�����true��
// 	static UGbool LoadWPI(const UGString& strPathName);	
// 
// 	//! \brief ж�ط����������
// 	//! \param hHandle [in] ��̬������
// 	//! \return �ɹ�ж�ط���true��
// 	static UGbool UnloadWPI(void* hHandle);		

	//! \brief ����һ����������ࡣ
	static UGMapServiceStub* CreateMapServiceStub(UGint nSeviceType);

// 	//! \brief ɾ����������ࡣ
// 	static void DestroyMapServiceStub(UGMapServiceStub*& pWebStub);
// 
// 	//! \brief �õ��ܹ�֧�ֵķ���������͡�
// 	static void GetSupportServiceTypes(UGArray<UGint>& arrSeviceTypes);
// 
// 	// ��ӷ����������ھ�̬���� for Android by liucq
// 	UGbool AddServiceProvider(void* handle);
// 
// private:
// 	UGMapServiceStubDefine* Check(void* hHandle);
// 	UGMapServiceStubDefine* Find(UGint nServiceType);
// 	void LoadWPI();
// 	void UnloadWPI();
// private:
// 	UGbool m_bLoaded;
// 	UGMutex m_mutex;
// 	UGArray<UGMapServiceStubDefine*> m_MapServiceStubDefines;
};

/*extern MAPSERVICESTUB_API UGMapServiceStubManager g_MapServiceStubManager;*/

}//namespace UGC

#endif // !defined(AFX_UGMAPSERVICESTUBMANAGER_H__AB19AA8C_B64E_42F0_BFF3_DDE67CDBA62F__INCLUDED_)

