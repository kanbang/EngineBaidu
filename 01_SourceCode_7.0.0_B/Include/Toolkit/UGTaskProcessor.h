// UGTaskProcessor.h: interface for the UGTaskProcessor class.
//
//////////////////////////////////////////////////////////////////////

/*!
**************************************************************************************
\file     UGTaskProcessor.h
**************************************************************************************
\author   ����Ǭ
\brief    ���߳�����������                                                           
\attention   
----------------------------------------------------------------------------------<br>
Copyright (c) 2000-2012 SuperMap Software Co., Ltd.                           <br>
All Rights Reserved.                                                             <br>
----------------------------------------------------------------------------------<br> 
*/

#if !defined(AFX_UGTASKPROCESSOR_H__869EEDDC_C92D_4D07_9903_4345F3138D0A__INCLUDED_)
#define AFX_UGTASKPROCESSOR_H__869EEDDC_C92D_4D07_9903_4345F3138D0A__INCLUDED_

#include "Toolkit/UGThread.h"

namespace UGC {

//////////////////////////////////////////////////////////////////////////
//
/*!
**************************************************************************************
�����ࣨ���ࣩ

1. ���������඼�Ӵ�������
**************************************************************************************
*/
class TOOLKIT_API UGTaskBase
{
public:
	enum TaskState
	{
		TS_Default		= 0,	// ȱʡ״̬
		TS_Add			= 1,	// ���״̬
		TS_Get			= 2,	// ��ȡ״̬
		TS_Processing	= 3,	// ����״̬
		TS_Finish		= 4,	// ���״̬
	};
public:
	//! \brief ��ȡ��������
	virtual UGString GetClassName() = 0;

	//! \brief ʵ��������ľ������
	virtual UGbool Execute() = 0;

	//! \brief ��¡����
	virtual UGTaskBase* Clone() = 0;

	//! \brief ��������
	virtual ~UGTaskBase() { }; 
};


//////////////////////////////////////////////////////////////////////////
//
/*!
**************************************************************************************
�������ࣨ�ӿڣ�

ע�⣺
	���������Ĺ����Ƚϼ򵥣������ֱ��ʵ��UGTaskBase���Execute
�������ɣ�����Ҫʵ��UGTaskProcessor�ӿڣ��������Ĳ�����Ҫ�Ĳ���
�Ƚ϶࣬����ʵ�ָýӿ�
**************************************************************************************
*/
class TOOLKIT_API UGTaskProcessor
{
public:
	virtual UGbool ProcessTask(UGTaskBase* pTask) = 0;
};


//////////////////////////////////////////////////////////////////////////
//
/*!
**************************************************************************************
��������ࣨ�ӿڣ�

1. ��������������֮ǰ���û��ṩԤ����Ľӿ�
**************************************************************************************
*/
class TOOLKIT_API UGTaskFilter
{
public:
	//! \brief Ԥ������������
	//! \param eTaskState ����ǰ��״̬��
	//! \param pTask ��ǰ������
	//! \param bHandle ����Ĵ���״̬: true��ʾ�û��Ѵ����˸�����ֱ��������false��ʾ����������Ҫ�������������
	//! \return �ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual UGbool PreTranslateTask(UGTaskBase::TaskState eTaskState, UGTaskBase* pTask, UGbool& bHandle) = 0;
};


//////////////////////////////////////////////////////////////////////////
//
/*!
**************************************************************************************
�����߳���

1. ִ��������߳��࣬��Ҫ��ѭ��ִ���������ĵ�����
**************************************************************************************
*/
class UGTaskMessageLoop;

class TOOLKIT_API UGTaskWorkThread : public UGThread
{
public:
	UGTaskWorkThread();
	virtual ~UGTaskWorkThread();

	//! \brief ���߳����е��������
	UGbool Attach(UGTaskMessageLoop* pTaskLoop);

	//! \brief ����/ֹͣ�߳�
	UGbool StartThread();
	void StopThread();

protected:
	UGint run();

private:
	//! \brief ��������������ָ��
	UGTaskMessageLoop* m_pTaskLoop;

	//! \brief �߳��˳���ʶ
	UGbool m_bStopThread;

};


//////////////////////////////////////////////////////////////////////////
//
/*!
**************************************************************************************
������������

1. ��Ҫ�ǹ����������ĵ��������
**************************************************************************************
*/
typedef UGList<UGTaskBase*> UGTaskQueue;

class TOOLKIT_API UGTaskMessageLoop
{
	friend class UGTaskWorkThread;
public:
	UGTaskMessageLoop();
	virtual ~UGTaskMessageLoop();

	//! \brief ���/�Ƴ�������ӿ�
	UGbool AddTaskProcessor(UGTaskProcessor* pTaskProcessor);
	UGbool RemoveTaskProcessor(UGTaskProcessor* pTaskProcessor);

	//! \brief ���/�Ƴ�������˽ӿ�
	UGbool AddTaskFilter(UGTaskFilter* pTaskFilter);
	UGbool RemoveTaskFilter(UGTaskFilter* pTaskFilter);

	//! \brief ����/��ȡ������д�С
	void SetTaskQueueSize(UGint nQueueSize = 200);
	UGint GetTaskQueueSize();

	//! \brief �Ƿ�����������ִ��
	UGbool IsTaskRunning();

	// �ú���һ����ã������������޸Ķ���
	UGTaskQueue& GetTaskQueue();

public:
	// ���º������̰߳�ȫ��
	//! \brief ��ȡ�Ƿ�������
	UGbool IsTaskEmpty();
	//! \brief ��ȡ��������
	UGTaskBase* GetTask();
	//! \brief ����һ������
	UGbool AddTask(UGTaskBase* pTask, UGbool bTail = true);
	//! \brief ɾ��һ������
	UGbool RemoveTask(UGTaskBase* pTask);
	//! \brief �����������
	UGint RemoveAllTask();
	//! \brief ��ȡ�������
	UGint GetTaskCount();
	//! \brief ���ź�����1�������˳��߳�ʱʹ�̲߳�������
	void PostTask(UGint nTaskCount);

protected:
	// �̵߳���
	UGbool Run();

private:
	UGArray<UGTaskProcessor*> m_TaskProcessors;
	UGArray<UGTaskFilter*> m_TaskFilters;

private:
	//! \brief �������������󳤶ȣ�Ĭ����200
	UGint m_nMaxQueueLength;
	//! \brief ֻ���������к����ض��еĲ�������
	UGTaskQueue m_TaskQueue;
	//! \brief ������������
	UGMutex m_mutexQueue;
	// ����ָʾGetTask�Ƿ�ȡ������
	UGSemaphore m_semQueue;

	//! \brief ������������
	UGbool m_bTaskRunning;

};


//////////////////////////////////////////////////////////////////////////
//
/*!
**************************************************************************************
�������Ĺ�����

1. ��Ҫ�ǹ������̺߳���������
**************************************************************************************
*/
class TOOLKIT_API UGTaskManager
{
public:
	UGTaskManager();
	virtual ~UGTaskManager();

	//! \brief ����/��ȡ�̸߳���
	void SetThreadCount(UGint nThreadsSize = 1);
	UGint GetThreadCount();

	//! \brief ������������
	UGbool Start();
	//! \brief ֹͣ��������
	UGbool Stop();

public:
	//! \brief �����������������
	UGbool PostTask(UGTaskBase* pTask, UGbool bTail = true);

	//! \brief ��ȡ���������Ķ���
	UGTaskMessageLoop& GetMessageLoop();
	
private:
	UGTaskMessageLoop m_TaskLoop;
	UGArray<UGTaskWorkThread*> m_TaskThreads;

	UGint m_nWorkThreadSize;

};

}

#endif // !defined(AFX_UGTASKPROCESSOR_H__869EEDDC_C92D_4D07_9903_4345F3138D0A__INCLUDED_)

