//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief �����ࡣ
//!  \details ��ɶԵ�����ķ�װ��
//!  \author zhangshuai��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGSINGLETON_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_)
#define AFX_UGSINGLETON_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGPrerequisites3D.h"
# pragma warning(disable:4661)
namespace UGC
{
template<typename T>
//! \brief ���ģʽ�еĵ����ࡣ
class UGSingleton  
{ 
protected:
	//! \brief ��̬������Ա����ֻ֤��ʼ��һ�Ρ�
	static T* ms_pSingleton;
public:
	//! \brief ���캯����
	UGSingleton()	
	{
		if(!ms_pSingleton)
		{
#if defined(_MSC_VER) && _MSC_VER < 1200

			UGint nOffSet = (UGint)(T*)1 - (UGint)(UGSingleton<T>*)(T*)1;
			ms_pSingleton = (T*)((UGint)this + nOffSet);
#else

			ms_pSingleton = static_cast<T*>(this);
#endif
		}
	}
	//! \brief ����������
	~UGSingleton()
	{
		if(ms_pSingleton != NULL)
		{
			ms_pSingleton = NULL;
		}
	}
	//! \brief �õ���̬��Ա��
	static T& GetSingleton()
	{
		UGASSERT(ms_pSingleton);	
		return(*ms_pSingleton);
		
	}
	//! \brief �õ���̬��Աָ�롣
	static T* GetSingletonPtr()
	{
		UGASSERT(ms_pSingleton);
		return ms_pSingleton;
	}
};
}
#endif // !defined(AFX_UGSINGLETON_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_)

