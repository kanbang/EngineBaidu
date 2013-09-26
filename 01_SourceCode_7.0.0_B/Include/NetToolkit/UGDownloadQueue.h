////////////////////////////////////////////////////////////////////////////////
//!  Project UGC
//! \file UGDownloadQueue.h
//! \author UGC Group
//! \brief  ����������У��ڲ�����������������أ����ڶ��̺߳�̨���������������ǰ̨���ص�������
//! \attention Ŀǰ������ά�����ʹ�ù�
//!  Copyright (c)copy;  1997-2009 SuperMap Software Co., Ltd.<br> 
//!  All Rights Reserved.
//! \version 6.0
//! \date 2009��8��28��
////////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDOWNLOADQUEUE_H__60981696_A715_41E9_9E8A_0E555E41284B__INCLUDED_)
#define AFX_UGDOWNLOADQUEUE_H__60981696_A715_41E9_9E8A_0E555E41284B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugexports.h"
#include "Stream/ugdefs.h"
#include "Toolkit/UGThread.h"

#include "NetToolkit/UGGeoSpatialDownloadRequest.h"

namespace UGC
{
	class UGCacheFile;
	class UGWebDownload;

	typedef void (UGSTDCALL * DownloadQueueCompleteFunc) (UGArray<UGGeoSpatialDownloadRequest> CompleteDownloads, UGlong pWnd);

	//! \brief class UGDownloadQueue
	//! \brief ���ض���
class NETTOOLKIT_API UGDownloadQueue  
{
public:

    //! \fn UGDownloadQueue();

    //! \brief ���캯��
	UGDownloadQueue();

	//! \fn virtual ~UGDownloadQueue();

    //! \brief ��������
	virtual ~UGDownloadQueue();

    //! \fn		void Clear();

    //! \brief ��ʱ����������Ļ���ض��У������������Ļ�߳��ͷŵ������ٽ������ء�
	void Stop();

    //! \fn UGbool Add(const UGGeoSpatialDownloadRequest& newRequest, UGbool bTail = TRUE);

    //! \brief ������������ص����ض�����
    //! \param const UGGeoSpatialDownloadRequest& newRequest [in] �����������
    //! \param UGCacheFile* pCacheFile [in] ����Ǵ��ļ���ʽ���������ж��ڴ��ļ����Ƿ����
    //! \param const UGString& strpath [in]
    //! \param UGbool bTail [in] �Ƿ�ӵ����е�ĩβ��Ĭ��Ϊtrue
	//! \remarks �������������Ѿ������ڶ����л����������Ķ��������ٽ��м��أ�
	//! ��������������Ѿ���Ա���򶪵������󣬲��ټ��롣
    //! \return �ɹ����뷵��true��
	UGbool Add(const UGGeoSpatialDownloadRequest& newRequest, UGCacheFile* pCacheFile = NULL, const UGString& strpath = _U(""), UGbool bTail = TRUE);

    //! \fn UGbool Remove( const UGGeoSpatialDownloadRequest& geoRequest);

    //! \brief ��ָ������������������������Ƴ���
    //! \param const UGGeoSpatialDownloadRequest& geoRequest [in] ָ�����������
    //! \remarks ������������в�Ϊ����ָ�������������ڶ����У�����Խ����Ƴ��� 
    //! \return �Ƴ��ɹ�����true�� 
	UGbool Remove( const UGGeoSpatialDownloadRequest& geoRequest);

    //! \fn void OnComplete();

    //! \brief �����������߳���ɺ����лص���
    //! \remarks �����ڴ˺�������������߳̽��������β�������������ϲ���Ϣ�ص������� 
	void OnComplete();

	//! \fn void OnProgress();

	//! \brief ���������ع����м�¼���ؽ��ȡ� 
	void OnProgress(UGint completeNum);

    //! \fn void BackgroundDownloadFile();

    //! \brief �������������к�̨���߳����ء�
    //! \remarks ��������в�Ϊ�գ����������Ѿ������������������е�����������������ж��߳����ء�
	void BackgroundDownloadFile();

    //! \fn void DownloadQueueInForeground();

    //! \brief ��������������ǰ̨���ء�
    //! \remarks �ڲ������ö��̣߳��в�֧�����̨����ͬʱʹ�ã��ݲ����š�
//	void DownloadQueueInForeground();


    //! \fn void DownloadFileInForeground(const UGGeoSpatialDownloadRequest& request);

    //! \brief ��������������ǰ̨����
    //! \param const UGGeoSpatialDownloadRequest& request [in] Ҫ����ǰ̨���ص��������
    //! \remarks �ڲ������ö��̣߳�������ȥ���ص���������� 
	void DownloadFileInForeground(UGGeoSpatialDownloadRequest& request);


    //! \fn void SetWebDownloader(UGWebDownload* pwd);

    //! \brief �������󶨡�
    //! \param UGWebDownload* pwd [in] �ⲿnew������������
    //! \remarks Ŀ��֧������ʱ�󶨣�����������ʱ���ϲ�ͬ�������� 
    //! \return void 
	void SetWebDownloader(UGWebDownload* pwd);
	

    //! \fn void SetSmCacheAccessPW(const UGString& strpw);
    //! \brief �����������з��ʴ��ļ�����ʱ�Ļ�������
    //! \param const UGString& strpw ��������
    //! \return void 
	void SetSmCacheAccessPW(const UGString& strpw);

	void SetDownloadType(UGint type);

    //! \fn UGbool IsComplete() {return m_bIsComplete;};

    //! \brief ���ⲿ�����ж��ڲ������߳��Ƿ�������ɡ�
    //! \return ���������߳��Ƿ����
	UGbool IsComplete() {return m_bIsComplete;};

	//! \brief ���ⲿ���õõ����ؽ��ȡ�
	//! \return �õ�����ɵ���������������������
	void GetProgress(UGint& completeRequestNum, UGint& totalRequestNum);

	//! \brief ���ⲿ���õõ����ؽ��ȡ�
	//UGfloat GetDataStreamingProgress();

	//! \brief ����������ɵĻص�����
	//! \param pFunc �ص�����[in]��
	//! \param pWnd ���[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetDownloadQueueCompleteFunc(DownloadQueueCompleteFunc pFunc,UGlong pWnd);

	//! \brief ��ȡ����������� ���ⲿ�����޸������������ȼ���
	//! \return �õ������������
	UGList<UGGeoSpatialDownloadRequest>* GetRequests();

	//! \brief ������������������н��в���ʱ���������
	void Lock();

	//! \brief ������
	void Unlock();

	//! \brief ����ÿ�����ص����������
	void SetTurnRequestNum(UGint turnRequestNum);

public:

//! \brief �������������󳤶ȣ�Ĭ����200
	static UGint ms_nMaxQueueLength;

//! \brief Ԥ��
//	static UGint ms_nMaxConcurrentDownloads;

protected:

	//! \brief ���غ�������������ɵĻص���
	//! \param ��Ч��������Ϊ�˺�������
	void BackgroundDownloadFile(char invalid);

    //! \fn virtual void ServiceDownloadQueue();
    //! \brief Ԥ��
//	virtual void ServiceDownloadQueue();

	//! \brief �������������Ϣ
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SendDownloadQueueCompleteFunc(const UGArray<UGGeoSpatialDownloadRequest>& CompleteDownloads);

protected:

	//! \brief ���ض������ʱҲ�������������ʱ�Ļص�����
	DownloadQueueCompleteFunc m_pDownloadQueueCompleteHandler;

	//! \brief �¼���ر�����
	UGlong m_pEventView;  //�����¼��ص������Ķ���ָ�룬ͳһΪһ���ɣ���ʡ�ڴ�

	// ����һЩ���룬ɾ������Ӳ��������������Ա�ϣ�������list����array��Щ
	//! \brief �����������
	UGList<UGGeoSpatialDownloadRequest> m_Requests;

//! \brief �ڲ��������������У������޷��������ء�
	UGWebDownload* m_pWebDownload;

//! \brief ֻ���������к����ض��еĲ�������
	UGMutex m_mutex;

//! \brief �������߳��Ѿ����һ���������أ�����Ϊtrue
	UGbool m_bIsComplete;

//! \brief ����ɵ���������
	UGint m_nCompleteRequest;

//! \brief �ܹ�����������
	UGint m_nTotalRequest;
	
	//! \brief �׶���ɵ���������
	UGint m_nStageCompleteRequest;

	//! \brief ÿ�δӴӶ������õ������������صĸ���
	UGint m_nTurnRequest;

};

}
#endif // !defined(AFX_UGDOWNLOADQUEUE_H__60981696_A715_41E9_9E8A_0E555E41284B__INCLUDED_)

