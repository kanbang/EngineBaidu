//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGHttpHelper.h
//!  \brief  Http���֣��ṩWeb����Դʹ�õ���Http���󼰽�������ز�����
//!  \details �ļ���ϸ��Ϣ��
//!  \author UGC Team��
//!  \attention 
//!   Copyright (c) 2000-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGHTTPHELPER_H
#define UGHTTPHELPER_H

#include "Stream/ugexports.h"
#include "Stream/ugdefs.h"
#include "Stream/ugplatform.h"
#include "Toolkit/UGThread.h"
#include "NetToolkit/UGGeoSpatialDownloadRequest.h"
#include "Stream/UGByteArray.h"

// ���vc6�±���Windows.h winsock.h mswsock.h winsock2.h֮�����ذ�����ɱ��벻��������
#ifdef WIN32
	#if(_WIN32_WINNT >= 0x0400)
		#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
		#endif
	#endif
#endif

namespace UGC
{
	typedef UGint (*CURLWirteDataFunc)(void *buffer, UGuint size, UGuint nmemb, void *stream);

	typedef UGint (*CURLProgressFunc)(void *buffer, double dltotal, double dlnow);

class NETTOOLKIT_API UGCurl
{
public:
	friend class UGCurlPool;


	enum UGCurlType
	{
		//δ֪
		UnKnown     =0,
		//����
		Download	=1,
		//�ϴ�
		Upload		=2,
	};

	//! \brief ��ʼ���������ص�curl handle
	//! \param writedatapara curl����ʱ������
	//! \param writefunc curl���ػص�д�뺯��
	//! \param pUrl url�ַ���
	//! \param strUser �û���
	//! \param strPW ����
	void InitializeEasyHandle2WriteData(void* writeDataPara, CURLWirteDataFunc writeFunc, const char* pUrl, const UGString& strUser, const UGString& strPasswd);


	//! \brief ��ʼ������post��curl handle �ϴ��ַ�����ע�ⲻ���ļ���
	//! \param strURL ������URL��ַ[in]��
	//! \param strPOSTFIELDS Ҫ�������ϴ����ַ���[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	void InitializeEasyHandle2Post(const char* pPostFields, const char* pUrl, const UGString& strUser = _U(""), const UGString& strPasswd = _U(""));


	//! \brief ��ʼ�����ڽ������ӵĵ�curl handle �����ڽ������ӡ�
	//! \param strURL ������URL��ַ[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	void InitializeEasyHandle2Connect(const char* pUrl, const UGString& strUser = _U(""), const UGString& strPasswd = _U(""));

	//! \brief ��ʼ���������ص�curl handle
	//! \param writedatapara curl����ʱ������
	//! \param writefunc curl���ػص�д�뺯��
	//! \param progressFunc curl���ػص����Ⱥ���
	//! \param localFileLen curl������дλ��
	//! \param pUrl url�ַ���
	//! \param strUser �û���
	//! \param strPW ����
	void InitializeEasyHandle2BreakWriteData(void* writeDataPara, CURLWirteDataFunc writeFunc, CURLProgressFunc progressFunc, UGlong localFileLen,
		const char* pUrl, const UGString& strUser, const UGString& strPasswd);

	//! \brief ִ������
	//! \return �Ƿ�ɹ�
	UGbool Perform();

	//! \brief �õ�HTTPͷ�е�content-type
	//! \return content-type
	UGString GetContentType();

	//! \brief �õ�HTTP������
	//! \return HTTP������
	UGint GetResponseCode();

	//! \brief �õ�HTTP���ӵ��׽���
	//! \return �׽���
	UGlong GetLastSocket();

	//! \brief ������������ķ�����
	//! \param nRespCode httpЭ��ķ�����
	//! \param strURL ����˵����url������Ϊ��
	UGbool ResovleCURLCode(UGlong nRespCode, const UGString& strURL);

	//! \brief �ͷſ���Ȩ,�����ù���Curl��CurlPool
	void Release();

private:
	UGCurl();
	~UGCurl();

	//typedef void CURL;
	void* m_pCurl;
	UGbool m_bUsing;
	UGCurlType m_CurlType;
};


class NETTOOLKIT_API UGCurlPool
{
public:
	//�õ����е�Curl
	UGCurl* GetIdleCurl();
	UGCurl* GetIdleCurl(UGCurl::UGCurlType curlType);

	UGCurlPool();
	~UGCurlPool();

private:
	UGArray<UGCurl*> m_arrCurl;
	UGMutex m_mutex;
};


class NETTOOLKIT_API SyncThreadMap : public UGDict<UGuint, UGuint>
{
public:
	SyncThreadMap()
	{
		
	}
	virtual ~SyncThreadMap(){};
	void inline Lock()
	{
		m_mutex.lock();
	}
	void inline Unlock()
	{
		m_mutex.unlock();
	}
protected:
	UGMutex m_mutex;
};

class NETTOOLKIT_API UGHttpHelper
{
	friend UGbool UGSTDCALL DownLoadSmCacheCallBack(void* pHandeler);
	friend UGbool UGSTDCALL DownLoadPureFilesCallBack(void* pHandeler);

public:
	//! \brief  װ��thread��idֵ�����ڶ��߳��첽�������ص�ʱ�������⵽�����߳�idֵ�����������У�������ѭ����Ѹ�ٽ���
	//! \remarks ��ʵʹ��std::set�����ʣ������ǵ�ʱ�������Լ�UGC��δ�ṩUGSetʵ�֣����Բ���std::map��ʵ���ˣ��޷Ƕ�ռ�ÿռ䡣
	//! \remarks ���ڿ��ǵ�Ҫ�ڶ��߳�֮�乲������std::mapҪ�����һ������
	static SyncThreadMap ms_threadmap;


	static UGCurlPool ms_curlPool;

public:
	//! \brief  Ĭ�ϵĹ��캯��
	UGHttpHelper();
	//! \brief  Ĭ�ϵ���������
 	virtual ~UGHttpHelper();

	//! \brief ����ʽ��ö��ֵ
	enum RequestMethod
	{
		//Get��ʽ
		GET = 0,	
		//post��ʽ
		POST = 1    
	};

	//! \brief http�ļ�������
	enum HttpFileType
	{	
		//�ı��ļ�
		CHARACTER = 0,  	
		//�������ļ�
		BINARY = 1	
	};

	//! \brief Э�������
	enum ProtocolType
	{ 
		//ftp
		FTP = 1,
		//gopher
		GOPHER = 2,	
		//http
		HTTP = 3	
	};

	enum ErrorType
	{
		SUCCESS = 0,
		ERROR_REQUEST	= 1,
		NO_RESOURCE		= 2,
		NO_ACCESS		= 3,
		ERROR_PASSWORD	= 4,
		ERROR_INSERVER	= 5,
		CANNOT_CONNECT	= 6,
		UNKNOWN			= 7,
	};

	//! \brief ͨ��URL����õ���������Ӧ�ļ���
	//! \param strURL ������URL��ַ[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \param reqMmethod http����ʽ,post��get,Ĭ���ÿ�[in]��
	//! \param fileType �����ļ�����ʽ,�����ƻ��ı�,Ĭ���ÿ�[in]��
	//! \return ����õ����ļ�·�����ļ���,�������ʱ·����
	//! \remarks ��
	//! \attention ��
	static UGString RequestFile(UGString strURL, UGString strUser, 
								UGString strPasswd, RequestMethod reqMmethod, 
								HttpFileType fileType);

	//! \brief ͨ��URL����õ���������Ӧ�ļ���
	//! \param strURL ������URL��ַ[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \param reqMmethod http����ʽ,post��get,Ĭ���ÿ�[in]��
	//! \param fileType �����ļ�����ʽ,�����ƻ��ı�,Ĭ���ÿ�[in]��
	//! \param strFileContext �ļ���MIME��ʽ[out]��
	//! \return ����õ����ļ�·�����ļ���,�������ʱ·����
	//! \remarks ��
	//! \attention 
	static UGString RequestFile(UGString strURL, UGString strUser, 
								UGString strPasswd, RequestMethod reqMmethod, 
								HttpFileType fileType,UGString& strFileContext);

	//! \brief ͨ��URL����õ���������Ӧ�ļ������浽ָ��·����
	//! \param strURL ������URL��ַ[in]��
	//! \param strDstPath ����õ����ļ��ĵ�ַ���ļ���[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \param reqMmethod http����ʽ,post��get,Ĭ���ÿ�[in]��
	//! \param fileType �����ļ�����ʽ,�����ƻ��ı�,Ĭ���ÿ�[in]��
	//! \return �Ƿ�ɹ��õ��ļ�,�ɹ�����TRUE,ʧ�ܷ���FALSE����
	//! \remarks ��
	//! \attention ��
	static UGbool RequestFile2(UGString strURL,UGString strDstPath, 
							   UGString strUser, UGString strPasswd, 
							   RequestMethod reqMmethod, HttpFileType fileType);

	//! \brief ͨ��URL����õ���������Ӧ�ļ������浽ָ��·����
	//! \param strURL ������URL��ַ[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \param reqMmethod http����ʽ,post��get,Ĭ���ÿ�[in]��
	//! \param fileType �����ļ�����ʽ,�����ƻ��ı�,Ĭ���ÿ�[in]��
	//! \param pBitArrayData ������ݵ�BitArray[out]��
	//! \param eErrorType ��������[out]��
	//! \return �Ƿ�ɹ��õ��ļ�,�ɹ�����TRUE,ʧ�ܷ���FALSE����
	//! \remarks ��
	//! \attention ��
	static UGbool RequestFile2ByteArray(UGString strURL, UGString strUser, UGString strPasswd, 
		RequestMethod reqMmethod, HttpFileType fileType, 
		UGByteArray* pBitArrayData, UGint& eErrorType, void* curl);


	//! \brief ��ָ���ķ�����ϴ��ַ�����ע�ⲻ���ļ���
	//! \param strURL ������URL��ַ[in]��
	//! \param strPOSTFIELDS Ҫ�������ϴ����ַ���[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \return �ϴ��ɹ�����true��
	static UGbool PostFields(UGString strURL, UGString strPOSTFIELDS, UGString strUser, 
		UGString strPasswd);

	//! \brief ͨ��URL�����Զϵ�������ʽ�õ���������Ӧ�ļ������浽ָ��·����
	//! \param strURL ������URL��ַ[in]��
	//! \param strDstPath ����õ����ļ��ĵ�ַ���ļ���[in]��
	//! \param progressFunc ���ؽ��Ȼص�����[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \return �Ƿ�ɹ��õ��ļ�,�ɹ�����TRUE,ʧ�ܷ���FALSE����
	//! \remarks ��
	//! \attention ��
	static UGbool RequestFileByBreakpoint(UGString strURL, UGString strDstPath, CURLProgressFunc progressFunc, UGString strUser, UGString strPasswd);

	//! \brief ��ָ���ķ�����ϴ��ļ���
	//! \param strURL ������URL��ַ[in]��
	//! \param strFilename Ҫ�������ϴ����ļ���[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \return �ϴ��ɹ�����true��
// 	static UGbool PostFile(UGString strURL, UGString strFilename, UGString strUser, 
// 		UGString strPasswd);

	//! \brief ��ָ���ķ���˸����ļ���
	//! \param strURL ������URL��ַ[in]��
	//! \param strFilename Ҫ�������ϴ����ļ���[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \return �ϴ��ɹ�����true��
// 	static UGbool PutFile(UGString strURL, UGString strFilename, UGString strUser, 
// 		UGString strPasswd);

    //! \brief �����ļ�Ϊ���ļ������ʽ(һ��һ������ʽ����)
    //! \param downloadRequests	�ļ����������
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \param strCacheAccesswd ���ļ�����������룬��û��������Ϊ��[in]��
	//! \param pWebDownloadCurl �������ؽ���[in]��
	//! \remarks �ڲ�ʹ�õ���SyncThreadMap��
	//! \remarks ��downloadRequestsֻ�ı��ڲ������سɹ���ǩ�����������ı�
	static void RequestFile2SmCacheST(UGArray<UGGeoSpatialDownloadRequest>& downloadRequests,UGString strUser, UGString strPasswd,UGString strCacheAccesswd,void* pWebDownloadCurl, UGbool bIsIndex = true);

	//! \brief �����ļ�Ϊ���ļ������ʽ(�ڲ�ʹ�ö��߳�)
	//! \param downloadRequests	�ļ����������
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \param strCacheAccesswd ���ļ�����������룬��û��������Ϊ��[in]��
	//! \param pWebDownloadCurl �������ؽ���[in]��
	//! \remarks �ڲ�ʹ�õ���SyncThreadMap��
	//! \remarks ��downloadRequestsֻ�ı��ڲ������سɹ���ǩ�����������ı�
	//! \remarks �ڲ���������߳̽������أ����ݱ���Ϊ���ļ������ʽ����������ֻ��һ����Ա���Ͳ�Ҫʹ������ӿ��ˣ������˷�Ч�ʡ�
	static void RequestFile2SmCacheMT(UGArray<UGGeoSpatialDownloadRequest>& downloadRequests, UGString strUser, UGString strPasswd, UGString strCacheAccesswd,void* pWebDownloadCurl);

	//! \brief ���ض���ļ�(�ڲ�ʹ�ö��߳�)
	//! \param strURLs	�ļ����������
	//! \param strFileNames ����õ����ļ��ĵ�ַ���ļ�������
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \remarks �ڲ�ʹ�õ���SyncThreadMap��
	//! \remarks �ڲ���������߳̽������أ����ݱ���Ϊָ����ʽ����������ֻ��һ����Ա���Ͳ�Ҫʹ������ӿ��ˣ������˷�Ч�ʡ�
	static void RequestFilesMT(const UGArray<UGString>& strURLs, const UGArray<UGString>& strFileNames, UGString strUser, UGString strPasswd);

    //! \brief ������˵�ַ�Ƿ���Ч
    //! \param strURL ������URL��ַ[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
    //! \return ������˵�ַ��Ч�򷵻�true
	static UGbool IsHostValide(UGString strURL, UGString strUser = _U(""), UGString strPasswd = _U(""));

	//! \brief URL����������
	//! \param pstrURL URL�ַ���[in]��
	//! \param dwServiceType ����Э������[out]��
	//! \param strServer �������������IP��ַ[out]��
	//! \param strObject URL�е�Path�Ͳ�ѯѡ��[out]��
	//! \param nPort �˿ں�[out]��
	//! \return �Ƿ�����ɹ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	static UGbool UGParseURL(UGString strURL, UGuint& dwServiceType, 
							 UGString& strServer, UGString& strObject, 
							 UGushort& nPort );

	//! \brief URL����������
	//! \param pstrURL URL�ַ���[in]��
	//! \param dwServiceType ����Э������[out]��
	//! \param strServer �������������IP��ַ[out]��
	//! \param strPath URL�е�Path[out]��
	//! \param strPath URL�еĲ�ѯѡ��[out]��
	//! \param nPort �˿ں�[out]��
	//! \return �Ƿ�����ɹ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	static UGbool UGParseURL2(UGString strURL, UGuint& dwServiceType, 
							  UGString& strServer, UGString& strPath, 
							  UGString& strQuery, UGushort& nPort);

	//! \brief URL����������
	//! \param pstrURL URL�ַ���[in]��
	//! \param strServerPath URL�е�ServerName��Port��Path��[out]��
	//! \param strQuery URL�еĲ�ѯѡ��[out]��
	//! \return �Ƿ�����ɹ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	static UGbool UGParseURL3(UGString strURL, 
							  UGString& strServerPath, UGString& strQuery);	
	
	//! \brief URLת���ɻ���ַ�Ͳ�ѯ��ֵ�ԡ�
	//! \param strURLsrc ԴURL�ַ���[in]��
	//! \param strBaseURL ����ַ[out]��
	//! \param dictQueryPairs ��׼�Ĳ�ѯѡ��[out]��
	//! \return �Ƿ�ɹ�ת��,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	//! \remarks ��
	//! \attention ��
	static UGbool URLtoKVPairs(const UGString& strURLsrc,
							   UGString& strBaseURL, UGDict<UGString,UGString>& dictQueryPairs);	

	//! \brief ����ַ�Ͳ�ѯ��ֵ��ת����URL��
	//! \param strBaseURL ����ַ[in]��
	//! \param dictQueryPairs ��׼�Ĳ�ѯѡ��[in]��
	//! \param strURLdes ת����Ŀ��URL[out]��
	//! \return �Ƿ�ɹ�ת��,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	static UGbool KVPairstoURL(const UGString& strBaseURL, 
		const UGDict<UGString,UGString>& dictQueryPairsUGString, 
							   UGString& strURLdes);	

	//! \brief ��URL�еõ�������Ϣ��
	//! \param strURL �����URL�ַ���[in]��
	//! \param rcGeoRef ������Ϣ[out]��
	//! \return �Ƿ�����ɹ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	static UGbool GetBBox(const UGString& strURL,UGRect2D& rcGeoRef);

	//! \brief �Ƚ�����XML��ǩ�����Ƿ�������ͬ��
	//! \param strTagLeft ��ֵ[in]��
	//! \param strTagRight ��ֵ[in]��
	//! \return �Ƿ���ͬ��
	static UGbool SameXMLTag(const UGString& strTagLeft, const UGString& strTagRight);	

	//! \brief ��ȡXML��ǩ�������ռ䡣
	//! \param strTag XML��ǩ[in]��
	//! \return �����ռ䡣
	static UGString TagNameSpace(const UGString& strTag);	

	//! \brief ����һ��OGC Web����Դ�������Ƿ�ɹ���
	//! \param strURL OGC Web����Դ������,����GetCapabilitys,DescribFeature��[in]��
	//! \param strUser Http���ʵ��û���[in]��
	//! \param strPasswd Http���ʵ�����[in]��
	//! \return �ɹ�����TRUE,ʧ�ܷ���FALSE����
	static UGint CheckOGCRequest(UGString strURL,
								  UGString strUser = _U(""),UGString strPasswd= _U(""));

	//! \brief ��ʼ��curl_global_init()
	static void Global_Init();

	//! \brief cleanup curl_global
	static void Global_Cleanup();

	//! \brief ��ʼ��curl_easy
	static void* Easy_Init();
	
	//! \brief ���crul_easy
	static void Easy_Cleanup(void* curl);
private:

	static UGMBString URLEncode(const UGachar* pCurl);

    //! \brief ������������ķ�����
    //! \param nCurlcode curl�ķ�����
    //! \param nRespCode httpЭ��ķ�����
    //! \param strURL ����˵����url������Ϊ��
	static UGbool ResovleCURLCode(UGlong nCurlcode, UGlong nRespCode, const UGString& strURL);

	//! \brief ������������ķ�����
	//! \param nCurlcode curl�ķ�����
	//! \param nRespCode httpЭ��ķ�����
	//! \param strURL ����˵����url������Ϊ��
	static ErrorType GetErrorType(UGlong nCurlcode, UGlong nRespCode, const UGString& strURL);

    //! \brief ��ʼ���������ص�curl handle
    //! \param easyhanle curl handle���������Ϊ��
    //! \param writedatapara curl����ʱ������
    //! \param writefunc curl���ػص�д�뺯��
    //! \param pUrl url�ַ���
    //! \param strUser �û���
    //! \param strPW ����
    //! \param UGbool bEncoded �Ƿ��Url������ܣ�Ĭ����false������
    //! \return �Ƿ��ʼ���ɹ�
	static UGbool InitializeEasyHandle2WriteData(void * easyhanle, void* writedatapara, CURLWirteDataFunc writefunc, const char * pUrl, const UGString& strUser, const UGString& strPW);

	//! \brief �滻�����ַ�
	//! \param strURL url�ַ���
	static void ReplaceSpecialChar(UGString& strURL);
};
	
}
#endif // !defined(UGHTTPHELPER_H)

