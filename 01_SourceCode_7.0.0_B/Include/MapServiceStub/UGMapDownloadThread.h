////////////////////////////////////////////////////////////////////////////////
//!  Project UGC
//! \file UGMapDownloadThread.h
//! \author ����ת����
//! \brief �����̣߳��������Ͻ��������ص��ڴ���
//! \attention 
//!  Copyright (c)copy;  1997-2009 SuperMap Software Co., Ltd.<br> 
//!  All Rights Reserved.
//! \version 6.0
//! \date 2011��10��18��
////////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMAPDOWNLOADTHREAD_H__4A50E4DC_4371_4DAA_AF32_76DD8B65566E__INCLUDED_)
#define AFX_UGMAPDOWNLOADTHREAD_H__4A50E4DC_4371_4DAA_AF32_76DD8B65566E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Toolkit/UGThread.h"
#include "Stream/UGByteArray.h"
#include "MapServiceStub/UGMapDownloadRequest.h"
namespace UGC
{

//! \brief ����������ɺ�Ļص�����
typedef void (UGSTDCALL * MapDownloadFunc)(void* , UGuint);

//! \brief �����߳�
class MAPSERVICESTUB_API UGMapDownloadThread : public UGThread  
{
public:

	UGMapDownloadThread(UGuint nGlobalID);

	~UGMapDownloadThread();

	//! \brief ����������ɺ�Ļص������ľ��������������ɺ�ص���������������
	//! \param void* pHandeler [in] �������
	void SetMapDownloadFunc(MapDownloadFunc pFunc);

	//! \brief �����ⲿ����ľ��������������ɺ�ص���������������
	//! \param void* pHandeler [in] ������
	void SetHandeler(void* pHandle);

	//! \brief �����̵߳���������
	void SetRequest(const UGMapDownloadRequest& pRequest);

	//! \brief ��ȡ�߳�ִ�е���������
	UGMapDownloadRequest* GetRequest();

	//! \brief ��ȡ�߳���ʹ�õ�curl_easy
	void* GetCurl();

protected:

	//! \brief ��д����run������
	//! \return �߳������˳�����0��ʧ���򷵻�-1��
	virtual UGint run();	

private:
	//! \brief �ص�����ָ��
	MapDownloadFunc m_pRunHandler;

	//! \brief �ⲿ������
	void* m_pHandler;

	//��������
	UGMapDownloadRequest m_mapRequest;

	UGuint m_nGlobalID;

	void* m_curl;
};

}

#endif // !defined(AFX_UGMapDOWNLOADTHREAD_H__4A50E4DC_4371_4DAA_AF32_76DD8B65566E__INCLUDED_)

