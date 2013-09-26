/*!
   **************************************************************************************
    \file     UGProcess.h
   **************************************************************************************
    \author   ������
    \brief    ���̼��д�����࣬����ʵ�ֶ���д������                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2012 SuperMap Software Co., Ltd.                              <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
	\remarks <em>���ڶ���д������˵��</em>
	
	һ���򵥽��ܣ�
		Toolkit/UGProcess.h����д���࣬��Ҫ���ڶ���̲�����д���ƣ�����ͬһ����Դ һ��ʱ������ж�����̶���
	��ͬʱֻ��һ������д����д֮���ǻ���ģ������ź����͹����ڴ�ʵ�֡�
		�������ͨ�Ķ�д���������д�����ӻص�����������н��̽���д���������֪ͨ�������̣�����д����Դ��

	��������ԭ��

	PVԭ��ĺ���
		P������V�����ǲ����жϵĳ���Σ���Ϊԭ�PVԭ�Ｐ�ź����ĸ�����ɺ�����ѧ��E.W.Dijkstra����ġ�
	�ź���sem��һ������sem���ڵ�����ʱ����ɹ���������ʹ�õ���Դʵ��������semС����ʱ���ʾ���ڵȴ�ʹ���ٽ����Ľ�������
	Pԭ������Ķ����ǣ�
		(1)sem��1;
		(2)��sem��1���Դ��ڻ�����㣬����̼���ִ��;
		(3)��sem��1��С���㣬��ý��̱��������������ź����Ӧ�Ķ����У�Ȼ��ת���̵���
	Vԭ������Ķ�����:
		(1)sem��1;
		(2)����ӽ�������㣬����̼���ִ��;
		(3)����ӽ��С�ڻ�����㣬��Ӹ��źŵĵȴ������л���һ�ȴ����̣�Ȼ���ٷ���ԭ���̼���ִ�л�ת���̵��ȡ�
		   PV��������ÿһ��������˵����ֻ�ܽ���һ�Σ����ұ���ɶ�ʹ�á���PVԭ��ִ���ڼ䲻�������жϵķ�����

	�Ľ�ǰ��Ҳ�����ϵ�����
	///r_w����˭ʹ�úڰ�,mutex�����ٽ�������ֵ��Ϊ1
	int read_account =0; 
	semaphore r_w,mutex; 


	reader - (���߽���):    
	While (true) 
	{ 
		P(mutex); 
		read_account++; 
		if(read_account=1) 
			P(r_w); 
		V(mutex); 
       
		Read(); //���߲���
		
		P(mutex); 
		read_account--; 
		if(read_account=0) 
			V(r_w);
		V(mutex); 
	}
	writer - (д�߽���):   
	While (true) 
	{ 
		P(r_w); //��ע������һ��������� P(mutex)��
		
		Write(); //д���� 
		
		V(r_w);  //��ע������һ��������� V(mutex)��
	} 

	�Ľ���,Ҳ�Ƕ�д����ʵ�ֵĻ���ԭ��

	//r_w����˭ʹ�úڰ�,mutex�����ٽ�������ֵ��Ϊ1
	//writer_countΪ�����ڴ����
	����m_writer_count Ϊ�����ڴ����
	int read_account =0; 
	semaphore r_w,mutex; 
	shared_int writer_count = 0; 
	int m_writer_count = writer_count;

	reader - (���߽���):    
	While (true) 
	{ 
		P(mutex); 
		++read_account; 
		if(read_account=1) 
			P(r_w); 
		if(m_writer_count != writer_count)
			RefreshDirty();
		V(mutex); 

		Read(); //���߲���

		P(mutex); 
		read_account--; 
		if(read_account=0) 
			V(r_w);
		V(mutex); 
	}
	writer - (д�߽���):   
	While (true) 
	{ 
		P(r_w); 
		if(m_writer_count != writer_count)
			RefreshDirty();
		++writer_count;
		m_writer_count = writer_count;

		Write(); //д���� 

		V(r_w);  
	} 

	�� ʹ�÷�ʽ��
	
	void ProcessCallBack(void * )
	{
		///
	}
	
	UGProcess m_RWlock;

	void Reader()
	{
		UGProcessReaderLock reader(m_RWlock);
		//�����������Զ�����
	}

	void Writer()
	{
		UGProcessWriterLock writer(m_RWlock);
		//д���������Զ�����
	}
	
	
	int main()
	{
		
		m_RWlock.SetCallBack(&ProcessCallBack,(void*)this);
		//������һ����Ч���ļ����֣���������֮��ͨ�����ֽ��б�ʶ��ͬһ����������
		UGString strFileName = "file/name";
		readwriterlock.ProcessLockInit(strFileName);
		for()
		{
			Reader();
			Writer();
		}
		readwriterlock.ProcessLockRelease();
	}

	�ģ�ע�����
	1.	ProcessLockInit ProcessLockRelease �����ǳɶ�ƥ�䣬������ͬһ��������ֻ��һ�β��������������Դй¶
	2.	strFileName ����������֮��Ҫ���л��⣬����Ҫ�󱣳�һ�£�������һ����Ч���ļ����֣�����ļ���ɾ���������½���
		������ʹ������ļ�������Ϊ����Ψһ��ʶ�ǲ��ɿ��ġ�
	3.	��һ�����̵Ķ��߳�֮�䣬���������ȷ������Ч�ġ�
	4.  ������Ǳ�֤�̰߳�ȫ�ģ�����֧�ֿ������ģʽ��
	5.	�����һ������ͻȻ������������Ƽ��������н��̣���������������ļ��ʡ�

   **************************************************************************************
*/

#if !defined(UGPROCESSS_H)
#define UGPROCESSS_H

#include "Stream/ugdefs.h"
#include "Toolkit/UGThread.h"


#ifdef WIN32
#include <windows.h>
#endif

namespace UGC {

;
//! \brief ��־�ļ���ص�����
//! \brief ��д�������ࡣ

//!  \brief �ص����������ڴ�������������Ĵ���
typedef  void (*DirtyWriteCallBack)(void* pObj);

class TOOLKIT_API UGProcess  
{
	struct FileMappingData 
	{
		UGlong m_nMappingWriterC;
		UGlong m_nMappingReaderC;
		UGlong m_nMappingProcessC;
		FileMappingData()
		{
			m_nMappingWriterC = 0;
			m_nMappingReaderC = 0;
			m_nMappingProcessC = 0;
		}
	};
public:
	//! \brief ���캯��
	UGProcess();
	//! \brief ��������
	~UGProcess();
	//! \brief	�������̼���
	//! \param  bCallBack �Ƿ����callback�ĺ������������ΪFALSE���򲻻����callback����
	//! \return ����pWriterCount�ж��ļ������Ƿ��࣬����࣬����true,����������н��̵���WriterLock
	//! \remarks ��� pWriterCount Ϊnull������Զ����false���ļ����ڸɾ�״̬��Ҳ����û������
	//			 ���̸��¡���֧�ֿ�����ģʽ��
	//������ģʽ����ͨ������ֵ���߻ص���������
	UGbool ReaderLock(UGbool bCallBack = TRUE);
	//! \brief	�������̽���
	//! \remarks ReaderLock ReaderUnlock һ��Ҫ�ɶ�ƥ����֣����û�гɶԣ����п��ܳ���������
	void ReaderUnlock();
	//! \brief	��д���̼���
	//! \param  bCallBack �Ƿ����callback�ĺ������������ΪFALSE���򲻻����callback����
	//			��Զ����false;
	//! \return ����pWriterCount�ж��ļ������Ƿ��࣬����࣬����true,����������н��̵���WriterLock
	//! \remarks ��Ϊͬһʱ��ֻ����һ��д���̴��ڣ����Բ�Ҫ�ظ����ã�
	//			 ������Ҫ�������� ReaderLock WriterLock ReaderUnlock WriterUnlock�Ȼ��ҵ��ã��п��ܳ���������
	//           ��֧�ֿ�����ģʽ��
	UGbool WriterLock(UGbool bCallBack = TRUE);
	//! \brief	��д���̽���
	//! \remarks WriterLock WriterUnlock һ��Ҫ�ɶ�ƥ����֣����û�гɶԣ����п��ܳ���������
	void WriterUnlock();
	//! \brief	��������ʼ��
	//! \param 	strName[in] �ļ����ֵģ��������Ҫ��ȡͬһ���ļ�������,
	//! \param 	pWriterCount[in] �ڲ��ж��ļ��Ƿ���ļ�����
	//! \remarks �ڽ��̿�ʼ��ʱ��һ��Ҫ���ã�����ֻ����һ�Ρ�
	//            ProcessLockInit ProcessLockRelease �ǳɶ�ƥ��ģ���֧�ֿ�����ģʽ
	//���ز������ӵĽ�����Ŀ���������0�����ʼ��δ�ɹ��������������⣬��鿴��־
	//��AIX ����һ�������ڴ��������Ӳ�������11��
	//����ͨ�����û�������
	//export EXTSHM=ON,�����䲢��������
	UGulong ProcessLockInit(const UGString& strName);
	//! \brief	����������
	//! \remarks �ڽ��̽�����ʱ��һ��Ҫ���ã�����ֻ����һ�Ρ���֧�ֿ�����ģʽ
	void ProcessLockRelease();
	//! \brief	�жϵ�ǰ�Ķ����RWLock �Ƿ�����ס����
	//! \remarks ���ڵ���Ҫ�ô�����Ҫ�����������������
	UGbool isLocked();
	void SetIsValied(UGbool bIsValied){m_bIsValied = bIsValied;};
	void SetCallBack(DirtyWriteCallBack pCallBack,void *pCallBackParam);

#ifdef WIN32
	inline DWORD WaitForValidSignal(
		HANDLE hHandle        // handle to object to wait for
		);
#endif
//���������װ��������ò�Ҫ����
private:
	UGProcess(const UGProcess&);
	UGProcess& operator=(const UGProcess&);
	//const UGProcess *operator()const{ return this};
	UGProcess *operator&(); 
private:
	//! \brief ��¼���������õĴ���
	UGlong m_nReaderLockCount;
	//! \brief ��¼д�������õĴ���
	UGlong m_nWriterLockCount;
	//! \breif��¼�Ƿ��ʼ�����൱���Ƿ�open
	UGbool m_bInit;
    //! \brief ���ڴ���д�ߵļ���
	UGlong m_nWriterCount;
	
	DirtyWriteCallBack m_pCallBack;
	void *m_pCallBackParam;
	//���ڱ������Ĺ�����ԭ�Ӳ���
	//���ڻ���������Ҫ
	//����������ΪFALSE����WriterLock WriterUnLock ReaderLock 
	//ReaderUnLockû��Ч��
	UGbool m_bIsValied;
	UGMutex m_mutexR;
	UGMutex m_mutexW;
	UGMutex m_mutexInit;
	struct FileMappingData *m_pFileMappingData;
private:
#if defined(WIN32)
	HANDLE m_hMutexRW;
	HANDLE m_hMutexR;
	HANDLE m_hFileMapping;
#else
	UGint m_hSem;
	UGint m_hShm;
#endif




};

class TOOLKIT_API UGProcessReaderLock {
private:
	UGProcess& pro;
private:
	UGProcessReaderLock();
	UGProcessReaderLock(const UGProcessReaderLock&);
	UGProcessReaderLock& operator=(const UGProcessReaderLock&);
	UGProcessReaderLock *operator&(); 
public:

	//Construct & lock associated UGProcess
	inline UGProcessReaderLock(UGProcess& p,UGbool bCallBack = TRUE):pro(p){Lock(bCallBack);}
	inline UGbool Lock(UGbool bCallBack = TRUE){ return pro.ReaderLock(bCallBack);}
	inline ~UGProcessReaderLock(){ pro.ReaderUnlock(); };
};

class TOOLKIT_API UGProcessWriterLock {
private:
	UGProcess& pro;
private:
	UGProcessWriterLock();
	UGProcessWriterLock(const UGProcessWriterLock&);
	UGProcessWriterLock& operator=(const UGProcessWriterLock&);
	UGProcessWriterLock *operator&(); 
public:

	//Construct & lock associated UGProcess
	 inline UGProcessWriterLock(UGProcess& p,UGbool bCallBack = TRUE):pro(p){Lock(bCallBack);}
	 inline UGbool Lock(UGbool bCallBack = TRUE){ return pro.WriterLock(bCallBack);}
	 inline ~UGProcessWriterLock(){ pro.WriterUnlock(); };
};

}

#endif // !defined(UGPROCESSS_H)


