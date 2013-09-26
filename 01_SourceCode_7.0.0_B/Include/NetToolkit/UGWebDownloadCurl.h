////////////////////////////////////////////////////////////////////////////////
//!  Project UGC
//! \file UGWebDownloadCurl.h
//! \author UGC Group
//! \brief ����libCurlʵ�ֵ�����������
//! \attention Ŀǰ������ά�����ʹ�ù�
//!  Copyright (c)copy;  1997-2009 SuperMap Software Co., Ltd.<br> 
//!  All Rights Reserved.
//! \version 6.0
//! \date 2009��8��28��
////////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGWEBDOWNLOADCURL_H__12D804A9_E79A_4E43_A93B_5FF0B6D39920__INCLUDED_)
#define AFX_UGWEBDOWNLOADCURL_H__12D804A9_E79A_4E43_A93B_5FF0B6D39920__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NetToolkit/UGWebDownload.h"
namespace UGC
{
	//class UGWebDownloadCurl
	//! \brief ����libCurlʵ�ֵ�����������
class NETTOOLKIT_API UGWebDownloadCurl : public UGWebDownload  
{
public:

    //! \fn UGWebDownloadCurl();
    //! \brief Ĭ�Ϲ��캯��
	UGWebDownloadCurl();
	
    //! \fn virtual ~UGWebDownloadCurl();
    //! \brief Ĭ����������
	virtual ~UGWebDownloadCurl();


    //! \fn virtual UGbool Download();
	//! \brief ����ִ�У������첽���أ������߳��лص�
	//! \remarks �������ʧ���򴴽�datռλ��������libcurlʵ�����أ����سɹ�ֱ�����ļ�ȫ·���������ļ�
	//! \return ������Ϸ���true 
	virtual UGbool Download();

    //! \fn virtual void Cancel();
	//! \brief ȡ�������ڽ��е��첽����
	//! \remarks �ͷŵ������̣߳������ض������
	virtual void Cancel();

    //! \fn virtual void DownloadSingleInForeground(const UGGeoSpatialDownloadRequest& request);
	//! \brief ͬ������һ��ָ��������
	//! \param const UGGeoSpatialDownloadRequest& request [in] ������������
	//! \remarks ������Ӱ�񣬵��Σ�ģ�ͻ����ļ��������ļ����������ļ���
	virtual void DownloadSingleInForeground(UGGeoSpatialDownloadRequest& request);

// 	virtual void BackgroundDownloadFile( DownloadCompleteHandler completeCallback );
// 
// 	virtual void BackgroundDownloadFile( UGDownloadType dlType );

// 	void BackgroundDownloadMemory();
// 
// 	void BackgroundDownloadMemory( DownloadCompleteHandler completeCallback );
// 
// 	void BackgroundDownloadMemory( UGDownloadType dlType );
// 
// 	void DownloadMemory();
// 
// 	void DownloadMemory( UGDownloadType dlType );
// 
// 	void DownloadMemory( DownloadProgressHandler progressCallback );

//	void SaveMemoryDownloadToFile(UGString destinationFilePath );
	
	//! \fn void void OnProgressCallback(UGint completeNum);
	//! \brief ���ڻص���ʾ���ؽ���
	//! \param UGint completeNum [in] �Ѿ���ɵ�����������
	void OnProgressCallback(UGint completeNum);
    
	//! \fn void OnCompleteCallback();
    //! \brief ���ڻص������ض�����������������µ�����
	void OnCompleteCallback();

protected:
	//! \fn virtual void BackgroundDownloadFile();
	//! \brief �첽����HTTPЭ����ļ�
	//! \remarks ���û���첽�����߳����ڲ�����
	virtual void BackgroundDownloadFile();

private:

    //! \fn void HttpHelperPerform();
    //! \brief ��ʼ���ص����ļ����ڲ����zip�ļ����н�ѹ��
	void HttpHelperPerform(UGGeoSpatialDownloadRequest& request);

	//! \fn void DownloadIntoSmCahe();
	//! \brief ���س�Ϊ����ļ����档
	void DownloadIntoMixedFiles();

	//! \fn void DownloadIntoSmCahe();
	//! \brief ���س�Ϊ���ļ����档
	void DownloadIntoSingleFile();

	//! \brief ���س�Ϊ��ͨ�ļ���
	void DownloadIntoPureFiles();

	//! \brief ������س�Ϊ���ļ����档
	void DownloadIntoZipFiles();

// 	static void OnDownloadEnded(UGWebDownload* pwd, void* pCaller);

};

}

#endif // !defined(AFX_UGWEBDOWNLOADCURL_H__12D804A9_E79A_4E43_A93B_5FF0B6D39920__INCLUDED_)

