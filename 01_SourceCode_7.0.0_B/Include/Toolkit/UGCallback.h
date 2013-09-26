/* 
	\file UGCallback.h
	\brief �ص������ࡣ
	\author zengzm
	\attention
	Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����
	<em>2���ڶ���˵����
*/

#ifndef UGCALLBACK_H
#define UGCALLBACK_H

#include "Stream/ugdefs.h"

namespace UGC {

//! \brief ������Ϣ�ص�����
// typedef void (*ErrorInfoProc)(const UGchar* pchErrorInfo);

//! \brief ��������Ϣ�ص�����
//! \remarks add the argument bCancel to communicate with the outside functions.caogf
// typedef void (*ProgressProc)(const UGchar* pchTitle,const UGchar* pchMessage,
//							 UGint nPercent, const UGchar* pchRemainTime,UGbool& bCancel);

//! \brief �ص������ࡣ
/**
	\attention ����UGC��ʹ�ûص������ĵط��������ӣ����еĻص��ĵط����ŵ���֮��ص����У�
	��������������Ϣ�ص�Ҳ�ֱ�ŵ�UGErrorObj��UGProgress�У�UGCallback�������ϣ���غ������
*/

/*
class BASE_API UGCallback  
{
public:	
	//! \brief ��ջص�����ָ��
	//static void Clear();
	
	//! \brief ���ô�����Ļص�����ָ��
	//static void SetErrorInfoProc(ErrorInfoProc pErrorInfoFun);	

	// by zengzm 2007-4-10 û��ʹ��,��ʱ���
	//static ErrorInfoProc GetErrorInfoProc();

	//! \brief ���ý�������Ϣ�Ļص�����ָ��
	//static void SetProgressProc(ProgressProc pProgressFun);	
	
	// by zengzm 2007-4-10 û��ʹ��,��ʱ���
	//static ProgressProc GetProgressProc();

private: // by zengzm 2007-4-10 �ѻص������ĵ��÷ŵ�private��,�������������
	// ��UGErrorObj��UGProgress�е�������Ļص�����
	friend class UGErrorObj;
	friend class UGProgress;

	//! \brief ���ô�����Ϣ�ص�����,����UGErrorObj��ʹ��
	static void CallErrorInfo(const UGchar* pchErrorInfo);	
	//! \brief ���ý������ص�����,����UGProgress��ʹ��
	static void CallProgress(const UGchar* pchTitle,const UGchar* pchMessage,
							 UGint nPercent, const UGchar* pchRemainTime,UGbool& bCancel);
private:
	//! \brief ������Ϣ�ص�����ָ��
	static ErrorInfoProc m_pErrorInfoFun;
	//! \brief �������ص�����ָ��
	static ProgressProc	m_pProgressFun;
};
*/
}

#endif 



