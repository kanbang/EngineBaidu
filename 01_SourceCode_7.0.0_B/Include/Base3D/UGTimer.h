//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief ��
//!  \details ��
//!  \author ��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTIMER_H__77F37090_FF08_46BD_9EEB_312314BBBD47__INCLUDED_)
#define AFX_UGTIMER_H__77F37090_FF08_46BD_9EEB_312314BBBD47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGPrerequisites3D.h"

#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#endif

//! \brief ��ʼ��ʱ
#define UGTIMERSTART()	UGC::UGTimer::GetInstance().Start();

//! \brief ֹͣ��ʱ
#define UGTIMERSTOP(strFuncName)	UGC::UGTimer::GetInstance().Stop(strFuncName, __UGFILE__, __LINE__);

namespace  UGC 
{
// �÷�:
//	 1.����Ҫ���ļ���#include "Base3D/UGTimer.h"
// 	 3.��ʼ��ʱUGTIMERSTART;
// 	 4.������ʱUGTIMERSTOP(strFuncName);��Ϣ��д����־�ļ���

class BASE3D_API UGTimer  
{
public:
	UGTimer();
	~UGTimer();

	static UGTimer& GetInstance();

	//! \brief ��ʼ��ʱ
	void Start();

	//! \brief ֹͣ��ʱ
	//! \param strCodeFile �����ļ�,ʹ��__FILE__��Ϊ����
	//! \param nLineNumber��Stop���ڵ���,ʹ��__LINE__��Ϊ����
	void Stop(const UGString& strFuncName,const UGString& strCodeFile, UGint nLineNumber);

	//! \��ȡ���ʱ��,����Ϊ��λ
	UGdouble GetElapsedTimeInSec();

	//! \��ȡ���ʱ��,�Ժ���Ϊ��λ
	UGdouble GetElapsedTimeInMilliSec();

	//! \��ȡ���ʱ��,��΢�뵥λ
	UGdouble GetElapsedTimeInMicroSec();

private:
	UGdouble m_dStartTimeInMicroSec;
	UGdouble m_dEndTimeInMicroSec;
	UGbool m_bStopped;
#ifdef WIN32
	LARGE_INTEGER freguency;
	LARGE_INTEGER startCount;
	LARGE_INTEGER endCount;
#else
	timeval freguency;
	timeval startCount;
	timeval endCount;
#endif

};

}
#endif // !defined(AFX_UGTIMER_H__77F37090_FF08_46BD_9EEB_312314BBBD47__INCLUDED_)


