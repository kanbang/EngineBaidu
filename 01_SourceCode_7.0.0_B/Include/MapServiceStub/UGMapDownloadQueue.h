////////////////////////////////////////////////////////////////////////////////
//!  Project UGC
//! \file UGMapDownloadQueue.h
//! \author ����ת����
//! \brief  ����������У��ڲ�ʹ�ö��̺߳�̨��������
//! \attention 
//!  Copyright (c)copy;  1997-2009 SuperMap Software Co., Ltd.<br> 
//!  All Rights Reserved.
//! \version 6.0
//! \date 2011��10��18��
/*
���ں�̨������������ڲ������ض��к������̳߳�ʵ�֣����ڵ�Ҫ���������̳߳صĴ�С
������10�����ض��еĴ�С������200������ﵽ200���û�����µ�������ӵ�β����
��ȥ��ͷ������������ӵ�ͷ������ȥ��β�������󣩡��û��������������ʱ�������Ҫ�������أ�
����ӵ�����ͷ����������ӵ�����β���������Ҫ�ж��Ƿ�������ɣ���Ҫ�ڵ���BackgroundDownloadFile()
֮������жϣ��������δ֪�Ĵ���Ŀǰֻ������������������ʹ�á�
*/
////////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMAPDOWNLOADQUEUE_H__60981696_A715_41E9_9E8A_0E555E41284B__INCLUDED_)
#define AFX_UGMAPDOWNLOADQUEUE_H__60981696_A715_41E9_9E8A_0E555E41284B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugexports.h"
#include "Stream/ugdefs.h"
#include "Toolkit/UGThread.h"

#include "MapServiceStub/UGMapDownloadThread.h"
#include "FileParser/UGImagePlugin.h"

namespace UGC
{

typedef void (UGSTDCALL * MapDownloadCompleteFunc) (const UGMapDownloadRequest*, const UGByteArray*, UGint, UGlong);

typedef void (UGSTDCALL * RequestFinishedProc) (UGlong pWnd);

class MAPSERVICESTUB_API UGMapDownloadRequests:public UGList<UGMapDownloadRequest>
{
public:

	//! \brief ���캯��
	UGMapDownloadRequests();

	//!  \brief ��������
	~UGMapDownloadRequests();

	//! \brief ��ȡ��������
	UGbool GetTask(UGMapDownloadRequest& request);

	//! \brief ����һ������
	//! \return �������������û���滻ԭ��������ΪTrue������Ϊfalse
	UGbool AddTask(const UGMapDownloadRequest& newRequest, UGbool bTail);

	//! \brief ɾ��һ������
	UGbool RemoveTask(const UGMapDownloadRequest& request);

	//! \brief�����������
	void RemoveAll();

	//! \brief ����n����Դ,��stop��ʱ����
	void PostTask(UGint nTaskCount);
public:
	//! \brief �������������󳤶ȣ�Ĭ����200
	static UGint ms_nMaxQueueLength;
private:
	//! \brief ֻ���������к����ض��еĲ�������
	UGMutex m_mutex;

	UGSemaphore m_semDownloadTasks;

};

class MAPSERVICESTUB_API UGMapDownloadQueue
{
public:
	//! \brief ����
	UGMapDownloadQueue();

	//! \brief ����
	~UGMapDownloadQueue();

	//! \brief ������Ƭ������ɵĻص�����
	//! \param pFunc �ص�����[in]��
	//! \param pWnd ���[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetMapDownloadCompleteFunc(MapDownloadCompleteFunc pFunc,UGlong pWnd);

	//! \brief ���ø����û�������Ƭ������ɵĻص�����
	//! \param pFunc �ص�����[in]��
	//! \param pWnd ���[in]��
	void SetRequestFinishedFunc(RequestFinishedProc pFunc,UGlong pWnd);

	//! \brief ��ȡ����������� ���ⲿ�����޸������������ȼ���
	//! \return �õ������������
	//UGList<UGMapDownloadRequest>* GetRequests();

	//! \brief ������������������н��в���ʱ���������
	void Lock();

	//! \brief ������
	void Unlock();

	//! \brief �������������߳�����
	//! \param nMaxThreadCount[in] ����ܳ���10������10�����ó�10
	void SetMaxThreadCount(UGint nMaxThreadCount);

	//! \brief ��ʱ����������Ļ���ض��У������������Ļ�߳��ͷŵ������ٽ������ء�
	void Stop();

	//! \brief ������������ص����ض�����
	//! \param const UGMapDownloadRequest& newRequest [in] �����������
	//! \param UGbool bTail [in] �Ƿ�ӵ����е�ĩβ��Ĭ��Ϊtrue
	//! \remarks �������������Ѿ������ڶ����л����������Ķ��������ٽ��м��أ�
	//! ��������������Ѿ���Ա���򶪵������󣬲��ټ��롣
	//! \return �ɹ����뷵��true��
	UGbool Add(const UGMapDownloadRequest& newRequest, UGbool bTail = TRUE);

	//! \brief ��ָ������������������������Ƴ���
	//! \param mapRequest [in] ָ�����������
	//! \remarks ������������в�Ϊ����ָ�������������ڶ����У�����Խ����Ƴ��� 
	//! \return �Ƴ��ɹ�����true�� 
	UGbool Remove( const UGMapDownloadRequest& mapRequest);

	//! \brief �������������С�
	void RemoveAll( );

	//! \brief �������������к�̨���߳����ء�
	//! \remarks ��������в�Ϊ�գ����������Ѿ������������������е�����������������ж��߳����ء�
	void BackgroundDownloadFile();

	//! \brief �������ʱ�ص�
	//! \remarks �������߳������������ʱ��������������
	void OnComplete(UGuint threadID);

	//! \brief ���ⲿ�����ж��Ƿ�����������ɡ�
	//! \return ���������߳��Ƿ����
	UGbool IsComplete();

protected:
	//! \brief ������Ƭ���������Ϣ
	void SendMapDownloadCompleteFunc(const UGMapDownloadRequest* CompleteRequest, const UGByteArray* pByteArrayData, const UGint& eErrorType);

	//! \brief ����������Ƭ���������Ϣ
	void SendRequestFinishedFunc();

	//! \brief �ͷ��̳߳������е��߳�
	//! \attention �������ص��̻߳�ȡ�����ء�
	void ReleaseWorkThread();

	//! \brief �ͷ��̳߳���������ص��߳�
	//! \attention û����ɵ��̻߳�ȴ���ɡ�
	void ReleaseCompleteThread();

protected:

	//! \brief ���ض������������߳����ʱ�����õĻص�����
	MapDownloadCompleteFunc m_pMapDownloadCompleteHandler;

	//! \brief �¼���ر�����
	UGlong m_pEventView;

	//! \brief ȫ����Ƭ�������ʱ�����õĻص�����
	RequestFinishedProc m_RequestFinishHandler;

	//! \brief ȫ����Ƭ��������¼���ر�����
	UGlong  m_RequestFinishEnv;

	// ����һЩ���룬ɾ������Ӳ��������������Ա�ϣ�������list����array��Щ
	//! \brief �����������
	UGMapDownloadRequests m_mapRequests;

	//! \brief ֻ���������к����ض��еĲ�������
	UGMutex m_mutex;

	//! \brief ����ɵ���������
	UGint m_nCompleteRequest;

	//! \brief �ܹ�����������
	UGint m_nTotalRequest;

	//! \brief ����ʱ����������߳���
	UGint m_nMaxThreadCount;

	//! \brief �첽�����̳߳�
	UGArray<UGMapDownloadThread*> m_pdlThreadPool;

	UGbool m_bComplete;

};
}
#endif // !defined(AFX_UGMAPDOWNLOADQUEUE_H__60981696_A715_41E9_9E8A_0E555E41284B__INCLUDED_)
