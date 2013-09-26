/*!
**************************************************************************************
\file    UGPerformanceProfile.h 
**************************************************************************************
\author  ��־�� 
\brief   ����ͳ���࣬�����ڲ��ԣ��벻Ҫ�ڷ����Ĵ����������ش���
\attention   
----------------------------------------------------------------------------------<br>
Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                           <br>
All Rights Reserved.                                                             <br>
----------------------------------------------------------------------------------<br> 

**************************************************************************************
\remarks <em>����ͳ����ʹ��˵��</em>

����ͳ�����������ͳ�Ʒ���ָ���������ĵ�ʱ�䣬������ʱ�侫�ȣ�һ�����Ժ���Ϊ��λ��
��һ������CPU��Ƶ��Ϊ��λ��ͨ����QUERYPERFORMANCECOUNTER�����Ƿ�ʹ�ø߾��ȵļ�������
����ͳ�����ʹ�÷�ʽ�Ƚϼ򵥣���Ҫͳ��ĳ������ķ�����ֻ���ڸ÷�������ڶ���һ����
�ܼ���������UGProfileCounter��,ͬʱָ��һ�����ƻ������ú�"__FUNCTION__"��������
�����֮ǰʹ��UGProfileManager��ͳ����ص�����ָ�ꡣ


void SubFun()
{
	UGProfileCounter counter(__FUNCTION__);
	// SubFun�����ʵ�ִ���
	...
}
void AnotherSubFun()
{
	// AnotherSubFun�����ʵ�ִ���
	...
	UGProfileCounter *pCounter = new UGProfileCounter("ͳ��AnthorSubFun�еĲ��ַ�����ʱ");
	...
	delete pCounter;
	...
}
void Fun()
{
	UGProfileCounter counter(__FUNCTION__);
	// Fun�����ʵ�ִ���
	...
	SubFun();
	...
	AnotherSubFun();
	...
}

void main()
{
	// ����Fun����
	Fun();
	// ���ͳ����Ϣ������̨�������Fun(), SubFun(), AnotherSubFun()��������������ʱ��ͳ����Ϣ
	UGProfileManager.GetInstance().PrintAll();
	// ���ͳ����Ϣ���ļ���
	UGProfileManager.GetInstance().WriteToFile("name", "fileName", UGStreamLoadSave);
	// ���ͳ����Ϣ
	UGProfileManager.GetInstance().ClearAll();
}

**************************************************************************************
*/
#if !defined(UGPerformanceProfile_H)
#define UGPerformanceProfile_H

#include "Stream/UGFileStdio.h"
#include "Toolkit/UGThread.h"

//#define QUERYPERFORMANCECOUNTER
#if defined WIN32
#include <windows.h>
#else
#include   <sys/time.h>   
#include   <unistd.h> 
#endif
#ifdef _UGUNICODE
#define __UGFUNCTION__ __FUNCTIONW__
#else
#define __UGFUNCTION__ __FUNCTION__
#endif
// �ú������־�ļ��м�¼��ǰ�ķ����ʹ�����
#define UGPROFILE_DEBUG	UGProfileManager::GetInstance().Debug(_U("%s: %d"), __UGFUNCTION__, __LINE__);
using namespace UGC;
class UGProfileData
{
public:
	UGProfileData(UGbool bSimpleMode = TRUE)
	{
		m_bSimple = bSimpleMode;
		if(m_bSimple)
		{
			m_aryData.Add(0);
		}
	}
	~UGProfileData(){m_aryData.RemoveAll();}

	UGArray<OgdcLong>& GetData(){return m_aryData;}

	void Add(OgdcLong nData)
	{
		if(m_bSimple)
		{
			m_aryData[0] += nData;
		}
		else
		{
			m_aryData.Add(nData);
		}
	}

	UGlong Sum()
	{
		OgdcLong sum = 0;
		for(UGint i = 0; i < m_aryData.GetSize(); i++)
		{
			sum+=m_aryData[i];
		}
		return sum;
	}
	UGint Count()
	{
		return m_aryData.GetSize();
	}

	OgdcLong Average()
	{
		return (OgdcLong)Sum()/Count();
	}
private:
	UGArray<OgdcLong> m_aryData;
	UGbool m_bSimple;
};

class TOOLKIT_API UGProfileManager
{
	friend class UGProfileCounter;
public:
	// ��ȡProfileManager��Ψһʵ��
	static UGProfileManager& GetInstance()
	{
		static UGProfileManager s_profileManager;
		return s_profileManager;
	}

	~UGProfileManager()
	{
		ClearAll();
		if(m_pFileHandle != NULL)
		{
			((UGFileStdio*)m_pFileHandle)->Close();
		}
		delete (UGFileStdio*)m_pFileHandle;
		m_pFileHandle = NULL;
	}
	
	void Debug(UGchar* format, ...);

	// ���ָ�����Ƶ�����ͳ������
	void Clear(const UGchar* pName);

	// ���ȫ��������ͳ������
	void ClearAll();

	// ��ָ����������ָ��ĺ�ʱ�ܺ�
	UGlong Sum(const UGchar* pName);

	// ��ָ����������ָ���ͳ�ƴ���
	UGint Count(const UGchar* pName);

	// ��ָ����������ָ���ƽ����ʱ
	UGlong Average(const UGchar* pName);
	
	// �ڿ���̨��ӡ������е�����ָ��
	void PrintAll();

	// �����ܲ���������ļ���,��Ҫָ���ļ���
	UGbool WriteToFile(const UGchar* pName, const UGchar* pFileName, UGStreamDirection dir, UGbool bFullContent = FALSE);

	// ��ȫ�����ܲ���������ļ���,��Ҫָ���ļ���
	UGbool WriteAllToFile(const UGchar* pFileName, UGStreamDirection dir);

protected:
	void RecordLog(const UGchar* pName, OgdcLong nCounter)
	{
		UGMutexLock lock(m_mutex);
		lock.lock();
		UGProfileData *pData = NULL;
		m_data.Lookup(pName, pData);
		if(pData == NULL)
		{
			pData = new UGProfileData;
			m_data.SetAt(pName, pData);
		}
		pData->Add(nCounter);
	}
private:
	UGProfileManager() : m_pFileHandle(NULL) {}

private:
	UGDict<UGString, UGProfileData *> m_data;
	UGMutex m_mutex;
	void* m_pFileHandle;
};

class TOOLKIT_API UGProfileCounter
{
public:
	explicit UGProfileCounter(const UGchar* pName) 
	{
		m_pName = pName;
#if defined QUERYPERFORMANCECOUNTER && defined WIN32
		QueryPerformanceCounter(&m_begin);
#elif defined WIN32
		m_begin = clock();	
#else
		gettimeofday(&m_tmStart,0);
#endif
	}

	~UGProfileCounter()
	{
#if defined QUERYPERFORMANCECOUNTER && defined WIN32
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		OgdcLong timeLast = end.QuadPart-m_begin.QuadPart;
#elif defined WIN32
		UGlong timeLast=clock()-m_begin;
#else
		gettimeofday(&m_tmStop,0);
		ogdc_locale_timeval_subtract(&m_tmDiff,&m_tmStart,&m_tmStop);
		OgdcLong timeLast = m_tmDiff.tv_sec*1000000+m_tmDiff.tv_usec;
#endif
		// ��¼��ǰ��־
		UGProfileManager::GetInstance().RecordLog(m_pName, timeLast);
	}

#if defined QUERYPERFORMANCECOUNTER && defined WIN32
#else
	int  ogdc_locale_timeval_subtract(struct   timeval*   result,   struct   timeval*   x,   struct   timeval*   y)   
	{   
		if   (   x->tv_sec>y->tv_sec   )   
			return   -1;   

		if   (   (x->tv_sec==y->tv_sec)   &&   (x->tv_usec>y->tv_usec)   )   
			return   -1;   

		result->tv_sec   =   (   y->tv_sec-x->tv_sec   );   
		result->tv_usec   =   (   y->tv_usec-x->tv_usec   );   

		if   (result->tv_usec<0)   
		{   
			result->tv_sec--;   
			result->tv_usec+=1000000;   
		}  
		return   0;   
	}
#endif

private:
#if defined QUERYPERFORMANCECOUNTER && defined WIN32
	LARGE_INTEGER m_begin;
#elif defined WIN32
	UGlong m_begin;
#else
	struct  timeval   m_tmStart,m_tmStop,m_tmDiff;
#endif
	const UGchar *m_pName;
};
#endif //#define UGPerformanceProfile_H