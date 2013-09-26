////////////////////////////////////////////////////////////////////////////////
//!  Project UGC
//! \file UGWebDownload.h
//! \author UGC Group
//! \brief ������������������࣬Ŀǰʵ����libcurl�ģ����������ٿ���ʵ����������
//! \attention Ŀǰ������ά�����ʹ�ù�
//!  Copyright (c)copy;  1997-2009 SuperMap Software Co., Ltd.<br> 
//!  All Rights Reserved.
//! \version 6.0
//! \date 2009��8��28��
////////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGWEBDOWNLOAD_H__1F98835A_D61F_43AE_A290_E23BB63021D8__INCLUDED_)
#define AFX_UGWEBDOWNLOAD_H__1F98835A_D61F_43AE_A290_E23BB63021D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugexports.h"
#include "Stream/ugdefs.h"
#include "Stream/ugplatform.h"

#include "NetToolkit/UGGeoSpatialDownloadRequest.h"

namespace UGC
{
class UGWebDownloadThread;
class UGMemoryStream;

typedef void (UGSTDCALL * DownloadProgressHandler) (void* pfeedback, UGint completeNum);
typedef void (UGSTDCALL * DownloadCompleteHandler) (void* pfeedback);

//! \brief class UGWebDownload 
//! \brief �������������������
class NETTOOLKIT_API UGWebDownload  
{
public:	

	friend class UGDownloadQueue;

	enum UGDownloadType
	{
		Unspecified = -1,
		WMS = 0,
		WFS = 1,
		Custom = 99,
		SMCacheMixedFiles = 1001,
		SMCacheSingleFile = 1002,

		SMZipFiles2SingleFile = 2001,
	};
	
    //! \fn UGWebDownload();

    //! \brief Ĭ�Ϲ��캯��
	UGWebDownload();

    //! \fn virtual ~UGWebDownload();
    //! \brief Ĭ����������
	virtual ~UGWebDownload();
	
    //! \fn virtual UGbool Download() = 0;
    //! \brief ����ִ�У������첽���أ������߳��лص�
    //! \return ������Ϸ���true 
	// ������ⲿ�ص�������Ҫ���ã�û�취�ĳ�public��
	virtual UGbool Download() = 0; 

//	virtual void Release();

    //! \fn virtual void Cancel();
    //! \brief ȡ�������ڽ��е��첽����
    //! \remarks �ͷŵ������̣߳������ض������
	virtual void Cancel();

    //! \fn virtual void DownloadSingleInForeground(const UGGeoSpatialDownloadRequest& request);
    //! \brief ������������ʵ�֣�ͬ������һ��ָ��������
    //! \param const UGGeoSpatialDownloadRequest& request [in] ������������
    //! \remarks ������Ӱ�񣬵��Σ�ģ�ͻ����ļ��������ļ����������ļ���
	virtual void DownloadSingleInForeground(UGGeoSpatialDownloadRequest& request);

//	UGbool AddRequest(const UGGeoSpatialDownloadRequest& request);

//	UGbool RemoveRequest(const UGGeoSpatialDownloadRequest& request);

    //! \fn void SetFeedBack(void* pfeedback);
    //! \brief ����
    //! \param void* pfeedback [in]
    //! \remarks void 
	void SetFeedBack(void* pfeedback);

	//! \brief ����ռλ���ļ�
	static void CreatePlaceHolderFile(UGString strDatFilePath);

protected:

    //! \fn void ReleaseWorkThread();
	//! \brief �ͷŹ����߳�
	void ReleaseWorkThread();

	// �ɽ�UGDownloadType��չ��ȥ
	//! \fn virtual void BackgroundDownloadFile();
	//! \brief �첽����
	virtual void BackgroundDownloadFile();
	
// Static proxy properties
// public:
// 	static UGbool ms_bLog404Errors;
// 	
// 	static UGbool ms_buseWindowsDefaultProxy;
// 	
// 	static UGString ms_strproxyUrl;
// 	
// 	static UGbool ms_buseDynamicProxy;
// 	
// 	static UGString ms_strproxyUserName;
// 	
// 	static UGString ms_strproxyPassword;
// 	
// 	static UGString ms_strUserAgent;

public:


//! \brief ���ع����лص����ƽ��������ȣ�Ŀǰ��δʹ��
	DownloadProgressHandler m_pProgressCallback;

//! \brief ������ɺ󣬻ص�����ָ��
	DownloadCompleteHandler m_pCompleteCallback;

//! \brief �����ж��Ƿ��Ǵ��ļ��������ͻ�����ͨ�ļ����ͣ�Ĭ������ͨ�ļ����͡�
	UGDownloadType m_DownloadType;
	
//! \brief Ŀǰ��δ�õ���Ԥ��
	UGString m_strContentType;

//! \brief ����ʱ���ʷ�����õ����û�����Ĭ���ǿ�
	UGString m_strUser;

//! \brief ����ʱ���ʷ�����õ������룬Ĭ���ǿ�
	UGString m_strPasswd;

	//! \brief ʹ�ô��ļ�����ʱ�Ļ�������
	UGString m_strCachePassword;

protected:
	
//	UGbool m_IsComplete;	

	// �����ڴ棬�������٣�û�и��ӵ��м���룬ɾ��Ԫ�صĲ���������array
	// �����������ÿ���һ���Ϳ��Խ�������ǰ����
//! \brief ���ڽ������ص���������
	UGArray<UGGeoSpatialDownloadRequest> m_arrActiveDownloads;

//! \brief Ԥ������ʶ������������
	UGint m_nBytesProcessed;

//! \brief Ԥ��
	UGint m_nContentLength;

//! \brief Ԥ�����Ƿ���������ѹ��
	UGbool m_bCompressed;

//! \brief Ԥ����������ѹ������
	UGString m_strContentEncoding;

//! \brief Ԥ�����첽���ؿ�ʼʱ��
	UGlong m_lDownloadStartTime;

//! \brief Ԥ���������ڴ������ݱ���Ϊ�ļ�������
	UGMemoryStream* m_pContentStream;
	
// 	static DownloadCompleteHandler ms_pDebugCallback;
// 
// 	static DownloadCompleteHandler ms_pDownloadEnded;

//! \brief Ԥ�����Ƿ������ص��ڴ�
	UGbool m_IsMemoryDownload;

//! \brief ��ʶ�Ƿ�ȡ������ֹͣ���첽����
	UGbool m_bstopFlag;

//! \brief �첽�����߳�
	UGWebDownloadThread* m_pdlThread;

//! \brief �����������ĵ����ߣ���Ϊ������������ɺ���Ϣ�ķ�������
	void* m_pFeedback;

};


}

#endif // !defined(AFX_UGWEBDOWNLOAD_H__1F98835A_D61F_43AE_A290_E23BB63021D8__INCLUDED_)

