/*!	\file UGEfficiency.h
	\brief UGC�������ܲ��Թ��ߡ�
	\author zengzm
	\attention
	Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
	All Rights Reserved
	\remarks ���ܲ��Թ��ߵ�Ŀ������: 1)�ܷ���ļ�¼ĳ������һ�����е�ʱ��
	2)�ܷ����¼һ�δ���һ�����е�ʱ��.
	����1),�ں�������ڴ����� UGEFF_FUN(fun_name), 
	����2),�ڿ�ʼ�ĵط�д�� UGEFF_BEGIN, (ע:UGEFF_FUN���Զ���ʼ��������ܵļ�¼)
	����Ҫ�������ܵĵط�д�� UGEFF_REPORT(strReport), (UGEFF_REPORT������ʹ��)
	�ڶ���_UG_ENABLE_EFF�����debug�汾��,	���ܱ�����Ϣ�ͻ��Զ�д�뵽��־�ļ���,����Ϊdebug.
	��������:
1) ֻ��¼������������
ClassName::FunName()
{
	UGEFF_FUN("ClassName::FunName") // ���Զ���¼���������Ϊһ������,һ�����е�ʱ��
}
2) ֻ��¼���������
ClassName::FunName()
{
	// ���ü�¼�Ĵ����
	UGEFF_BEGIN //��ʼ��¼
	// ��Ҫ��¼���ܵĴ����
	UGEFF_REPORT("�������������")
	// ��Ҫ��¼���ܵĴ����
	UGEFF_REPORT("�������������")
}
3) ͬʱ��¼�����������ܺʹ��������
ClassName::FunName()
{
	UGEFF_FUN("ClassName::FunName") // ���Զ���¼���������Ϊһ������,һ�����е�ʱ��. ͬʱ��ʼ��������ܵĲ���
	// ��Ҫ��¼���ܵĴ����
	UGEFF_REPORT("�������������")
	// ��Ҫ��¼���ܵĴ����
	UGEFF_REPORT("�������������")
	// ����Ҫ��¼�Ĵ����
	UGEFF_BEGIN //��ʼ��¼
	// ��Ҫ��¼���ܵĴ����
	UGEFF_REPORT("�������������")
}
	<b>����˵������</b>
	<em>1����һ��˵����
	<em>2���ڶ���˵����
*/

#if !defined(AFX_UGEFFICIENT_H__3F256D18_BBDE_49E5_9AD1_D502D554FD16__INCLUDED_)
#define AFX_UGEFFICIENT_H__3F256D18_BBDE_49E5_9AD1_D502D554FD16__INCLUDED_

#include "Stream/ugdefs.h"
#include "UGLogFile.h"

// modified by zengzm 2007-6-11 Ĭ�϶�����������־�ļ������������Ƿ��������Ϣд����־�ļ��У�debug�����д�룩
#if !defined(_UG_ENABLE_EFF) //| defined(_DEBUG)
	#define _UG_ENABLE_EFF
#endif
#ifdef _UG_ENABLE_EFF
	#define UGEFF_FUN(strFunName)	UGC::UGEfficiency _ug_eff_fun(strFunName, __UGFILE__, __LINE__)
	#define UGEFF_BEGIN()				UGC::UGEfficiency::Begin(__UGFILE__, __LINE__) 
	#define UGEFF_REPORT(strReport) UGC::UGEfficiency::Report(strReport, __UGFILE__, __LINE__) 
#else
	#define UGEFF_FUN(strFunName)
	#define UGEFF_BEGIN			
	#define UGEFF_REPORT(strReport)
#endif


namespace UGC{

//! \brief ���ܲ����ࡣ
//!	\remarks ���Ƽ�ֱ��ʹ��,���ǲ���UGEFF_***�ļ��������������ܵĲ��ԡ�

class TOOLKIT_API UGEfficiency
{
public:
	//! \brief ������,����ʼ�Ժ�������ļ�ʱ,ͬʱ����մ���εļ�¼
	//! \param strFunName ��Ҫ������������,�����Ա����,�Ƽ�����ClassName::FunName�ķ�ʽ
	//! \param strCodeFile ��ʼ��¼�Ĵ����
	//! \param nCodeLine ��ʼ��¼�Ĵ�����
	UGEfficiency(const UGString& strFunName, const UGString& strCodeFile, int nCodeLine);
	//! \brief �������ʱ, �Զ��Ѻ������������ʱ���¼����־�ļ���
	~UGEfficiency();

	//! \brief ��ʼ��ʱ, �� ����һ�δ���(������һ������)ʱʹ��
	//! \param strCodeFile ��ʼ��¼�Ĵ����
	//! \param nCodeLine ��ʼ��¼�Ĵ�����
	static void Begin(const UGString& strCodeFile, int nCodeLine);

	//! \brief �������ε����ܲ��Լ�¼,��¼����־�ļ���
	//! \param strReport   ��Ҫ��¼�������Զ�����Ϣ
	//! \param strCodeFile ��ʼ��¼�Ĵ����
	//! \param nCodeLine ��ʼ��¼�Ĵ�����
	static void Report(const UGString& strReport, const UGString& strCodeFile, int nCodeLine);
	
private:
	UGString m_strFunName; 
	int m_nFunBegin;

	static int ms_nCodeBegin;
	static UGString ms_strCodeFile;
	static int ms_nCodeLine;
	static UGMutex ms_mutex;
private:
	// ��Ҫ�ֲ���ϵͳд, �Ա��ø���ȷ��ʱ��
	static int GetTime();
};


} //namespace UGC



#endif // !defined(AFX_UGEFFICIENT_H__3F256D18_BBDE_49E5_9AD1_D502D554FD16__INCLUDED_)

