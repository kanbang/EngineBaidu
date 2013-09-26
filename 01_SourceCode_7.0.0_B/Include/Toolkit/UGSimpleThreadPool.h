#ifndef _SIMPLETHREADPOOL
#define _SIMPLETHREADPOOL
#include "Toolkit/UGThread.h"
#include "Toolkit/UGToolkit.h"
#ifdef WIN32
#include "windows.h"
#include "winbase.h"
#endif

namespace UGC
{
// �̳߳���: ������õ���ģʽ,���״λ�ȡ�̳߳�ʵ��ʱ��ʼ���̳߳��е�ִ���߳�
// �̳߳س�ʼ����,ֻ��Ҫ���̳߳����������,ִ���߳̾ͻᰴ˳��������б���ȡ����,��ִ��

typedef UGint (*SimpleTaskFun)(void* param);

class TOOLKIT_API UGSimpleTask
{
	friend class UGSimpleThreadPool;
private:
	enum TaskStatus
	{
		Error = 0,
		Finished = 1,
		Waiting = 2,
		Running = 4,
	};
	UGSimpleTask();
	UGSimpleTask(const UGSimpleTask& in);

	UGSimpleTask(SimpleTaskFun f, void* pa)
	{
		fun = f;
		param = pa;
		m_status = Waiting;
		m_bManaged = FALSE;
	}

	UGSimpleTask(SimpleTaskFun f, void* pa, UGbool bManaged)
	{
		fun = f;
		param = pa;
		m_status = Waiting;
		m_bManaged = TRUE;
	}
public:
	TaskStatus GetStatus()
	{
		return m_status;
	}

private:
	UGint run();

private:
	SimpleTaskFun fun;
	void *param;
	TaskStatus m_status;

	UGuint m_nThreadID;
//#ifdef _AIX
	UGMutex* m_pEvent;
//#else
//	UGCondition* m_pEvent;
//#endif
	UGbool m_bManaged;
};


class TOOLKIT_API UGSimpleThreadPool
{
private:
	UGSimpleThreadPool();
	
	enum PoolStatus
	{
		UnInitialized = 0,
		Initializing = 1,
		Initialized,
		Destroying,
		Destroyed,
	};

public:
	// �̳߳ع����ʱ����Զ���CPU��������Init�������̳߳�
	// �̳߳��Ѿ���ʼ��,�ٴε��ø÷�������ʧ��
	// �����Ҫ�޸��̳߳��е�Ĭ���߳���,���¹����̳߳�,������ȵ���Destroy,�ٵ���Init
	UGbool Init(UGint nCount);
	// �ͷ��̳߳ص�������Դ,�ʺ�����Ҫ���¹����̳߳�.�������û�ʹ��.
	void Destroy();
	
	~UGSimpleThreadPool();

	static UGSimpleThreadPool& GetInstance()
	{
		ms_instanceMutex.lock();
		static UGSimpleThreadPool s_SimpleThreadPool;
		ms_instanceMutex.unlock();
		if(s_SimpleThreadPool.m_eStatus == UnInitialized)
		{
			s_SimpleThreadPool.Init(UGToolkit::GetCPUCount());
		}
		return s_SimpleThreadPool;
	}

public:
	// ��������,�Զ���ӵ������б�ĩβ,�ȴ�ִ��,δִ�е��������ͨ��RemoveTask�Ƴ�
	// ���ǵ��ṩ��Wait�ӿ�,���ص�����ָ����Ҫ���û��ͷ�,�������û��ִ�оͱ��ͷ�,���ܻᵼ�²���Ԥ�ڵĴ���
	UGSimpleTask* AddTask(SimpleTaskFun f, void* param);

	// �����й�����,�Զ���ӵ������б�ĩβ,�ȴ�ִ��
	// �й�������ִ����ɺ������ɾ��,���������б��,�û��޷��Ƴ�,Ҳ�޷�ͨ�������ȡ״̬
	void AddManagedTask(SimpleTaskFun f, void* param);

	// �ڵȴ��������б����Ƴ�ָ������,����ִ�е��������Ƴ�
	// �Ƴ�����ɹ����Զ�����task,�������ֶ�����
	UGbool RemoveTask(UGSimpleTask *&task);

	// ��ȡʣ��������
	inline UGint GetWaitingTaskCount() const;

	// ��ǰ�̵߳������б��е�����ִ�����
	// ���Է���AIX������Wait���ɿ�,��Ҫ��ʵ�ִ����н��Wait������
	void Wait(UGArray<UGSimpleTask *> aryTasks);

private:
	// �ڲ��ӿڣ�ר���ṩ���̳߳ص�ѭ���̷߳���ʹ��
	UGbool GetATask(UGSimpleTask *&task);

	// Task���ȡ��ǰTask��Ӧ�Ľ����¼�
//#ifdef _AIX
	UGMutex* GetEvent(UGuint nThreadID);
//#else
//	UGCondition* GetEvent(UGuint nThreadID);
//#endif

	// �̳߳�����ʱ,�ͷ��̳߳��е��߳�,�¼�
	PoolStatus GetStatus()
	{
		return m_eStatus;
	}
	static UGint LoopFun(void*);

private:
	UGMutex m_mutexTaskList;
	UGCondition m_eventTaskAdded;

	// ר�Ÿ�����ģʽ��GetInstance���̰߳�ȫ
	static UGMutex ms_instanceMutex;

private:
	// �̳߳��е��߳�
	OGDC::OgdcDict<UGuint, UGThreadEx*> m_poolThreads;
	UGint m_nStartedThread;

	// �����̳߳���ĳ�������ʱ���¼����ڲ�ʹ��, ��AIX����Condition������,ֻ����Mutex�㶨��,
	// ��ʵ����ƽ̨Ҳ��Mutex����,������ڹ㲥��Ϣ�����,��������
//#ifdef _AIX
	OGDC::OgdcDict<UGuint, UGMutex*> m_eventsTaskFinished;
//#else
//	OGDC::OgdcDict<UGuint, UGCondition*> m_eventsTaskFinished;
//#endif
	PoolStatus m_eStatus;

	// List Task,FIFO 
	OGDC::OgdcList<UGSimpleTask*> m_taskList;
};

}
#endif

