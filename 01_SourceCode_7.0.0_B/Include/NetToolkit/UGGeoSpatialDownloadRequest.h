////////////////////////////////////////////////////////////////////////////////
//!  Project UGC
//! \file UGGeoSpatialDownloadRequest.h
//! \author UGC Group
//! \brief ����ռ��������������࣬����������iServer���͵�Http URL����
//! \attention Ŀǰ������ά�����ʹ�ù�
//!  Copyright (c)copy;  1997-2009 SuperMap Software Co., Ltd.<br> 
//!  All Rights Reserved.
//! \version 6.0
//! \date 2009��8��28��
////////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOSPATIALDOWNLOADREQUEST_H__0BCDA7DE_B5FB_46A1_9A81_7B7EAABA3E36__INCLUDED_)
#define AFX_UGGEOSPATIALDOWNLOADREQUEST_H__0BCDA7DE_B5FB_46A1_9A81_7B7EAABA3E36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugexports.h"
#include "Stream/ugdefs.h"
#include "Stream/ugplatform.h"
#include "Toolkit/UGTextCodec.h"
#include "Geometry/UGDataCodec.h"

namespace UGC
{
	//! \brief class UGGeoSpatialDownloadRequest
	//! \brief ����ռ���������������
class NETTOOLKIT_API UGGeoSpatialDownloadRequest
{
public:
	//! \brief �����������͡�
	enum UGRequestDataType
	{
		UnKnown		= 0,
		SCVB		= 1,		
		SCVD		= 2,	
		Texture     = 3,	
	};

public:
	
    //! \fn UGGeoSpatialDownloadRequest();
    //! \brief Ĭ�Ϲ��캯��
	UGGeoSpatialDownloadRequest();

    //! \fn virtual ~UGGeoSpatialDownloadRequest();
    //! \brief Ĭ����������
	virtual ~UGGeoSpatialDownloadRequest();

    //! \fn		UGbool operator==(const UGGeoSpatialDownloadRequest& request) const;
	//! \brief ���� ==
    //! \param const UGGeoSpatialDownloadRequest& request
    //! \return	 ��������������򷵻�true
	UGbool operator==(const UGGeoSpatialDownloadRequest& request) const;

	//! \brief ����=��
	//! \param &request [in]��
	void operator = (const UGGeoSpatialDownloadRequest &request);

    //! \brief ͨ��ָ���ļ������ͼ�����ڷ���˵ĸ�Ŀ¼·������ȡ���������ļ���http url
    //! \param const UGString& strNetPath [in] ����˵�ַ
    //! \param const UGString& strDataname [in] ͼ����
    //! \param const UGString& strfilepath [in] �ļ������ͼ���Ŀ¼��·����ע��Ҫ�ж�Ӧ�������ļ���
    //! \param UGint ndataversion = 0 [in] �����ļ����ݵİ汾��Ĭ����0
    //! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
    //! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
    //! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \remarks ����kml����ģ������ʱʹ�á�����kml���ԣ��ļ�����ͼ������һ��!
    //! \return	����http url ����
	static UGString UrlGetDataByPath(const UGString& strNetPath, const UGString& strDataname, const UGString& strfilepath, UGint ndataversion = 0, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);

    //! \fn		static UGString UrlGetDataByIndex(const UGString& strNetPath, const UGString& strdataname, UGint nlevel, UGint nRow, UGint nCol, UGint ndataversion = 0, const UGString& strfileExtent = "", const UGString& strUsername = "", const UGString& strPassword = "", UGfloat fserviceVersion = 1.0f);
    //! \brief ͨ��ָ��ͼ�������������������ݵ� http url ����
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strdataname [in] ͼ����
    //! \param UGint nlevel [in] ����������
    //! \param UGint nRow [in] �������к�
    //! \param UGint nCol [in] �������к�
    //! \param UGint ndataversion = 0 [in] �����ļ����ݵİ汾��Ĭ����0
    //! \param const UGString& strfileExtent = "" [in] �ļ���չ����Ĭ��Ϊ�գ���Ĭ��ȥ��png bil sgm��׺��������
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \param UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE [in] ����ѹ����ʽ
    //! \remarks �����������ݡ��������ݡ�ģ����������ʱʹ��
    //! \return	����http url ����
	static UGString UrlGetDataByIndex(const UGString& strNetPath, const UGString& strdataname, UGint nlevel, UGint nRow, UGint nCol, const UGString& strfileExtent, UGint ndataversion = 0, 
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);

    //! \fn		static UGString GetDownloadUrlByBounds(const UGString& strNetPath, const UGString& strlayername, const UGString& strdatatype,		UGint nlevel, UGdouble left, UGdouble top, UGdouble right, UGdouble bottom,UGint ndataversion = 0, const UGString& strfileExtent = "", UGint npicWidth = 0, UGint npicHeight = 0, const UGString& strUsername = "", const UGString& strPassword = "", UGfloat fserviceVersion = 1.0f);
    //! \brief ͨ��ָ��ͼ�����;�γ�ȷ�Χ���������ݵ� http url ����
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strlayername [in] ͼ����
	//! \param const UGString& strdatatype [in] �������ݵ����ͷ�ΪIMG DEM SGM����
    //! \param UGint nlevel [in] ����������
    //! \param UGdouble left [in] ����
    //! \param UGdouble top [in] ��γ
    //! \param UGdouble right [in] ����
    //! \param UGdouble bottom [in] ��γ
	//! \param UGint ndataversion = 0 [in] �����ļ����ݵİ汾��Ĭ����0
	//! \param const UGString& strfileExtent = "" [in] �ļ���չ����Ĭ��Ϊ�գ���Ĭ��ȥ��png bil sgm��׺��������
    //! \param UGint npicWidth = 0 [in] ����x��������㣬
	//! �������ͼƬ���ݾ������أ����ڵ������ݾ���ÿ����������̵߳�ĸ�����Ĭ����0������ͼƬ���ݾ���256 �������ݾ���32
    //! \param UGint npicHeight = 0 [in] ����y���������
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
    //! \remarks �����������ݡ��������ݡ�ģ����������ʱʹ��
    //! \return	����http url ����
	static UGString GetDownloadUrlByBounds(const UGString& strNetPath, const UGString& strlayername, const UGString& strdatatype,
		UGdouble left, UGdouble top, UGdouble right, UGdouble bottom,UGint ndataversion = 0, const UGString& strfileExtent = _U(""), UGint npicWidth = 0, UGint npicHeight = 0, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);
	
	//! \fn		static UGString UrlGetDataConfig(const UGString& strNetPath, const UGString& strdataName, const UGString& strUsername = "", const UGString& strPassword = "", UGfloat fserviceVersion = 1.0f);
	//! \brief ��������˷���������������Ϣhttp url ����
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strdataName [in] ָ������������
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \remarks �������ݵ�������Ϣsci3d sct scm�ļ�ʱʹ��
	//! \return	����http url ����
	
	// �ɵ� UGint nLevel [in] ���ģ�͵ķֲ�ȡscm���������������ò��������ַ�����
	// Ŀǰģ��Ҳ����Ҫ���ˣ�����������ģ��ͼ�㶼�ж�����ͼ����
	static UGString UrlGetDataConfig(const UGString& strNetPath, const UGString& strdataName, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);

    //! \fn		static UGString UrlGetLayerListInfo(const UGString& strNetPath, const UGString& strSceneName, const UGString& strUsername = "", const UGString& strPassword = "", UGfloat fserviceVersion = 1.0f);
    //! \brief ��������˷�����ͼ���б���Ϣhttp url����
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strSceneName [in] ָ������������
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \return	����http url ����
	static UGString UrlGetLayerListInfo(const UGString& strNetPath, const UGString& strSceneName, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);

    //! \fn		static UGString UrlGetLayerInfo(const UGString& strNetPath, const UGString& strSceneName, const UGString& strlayername, const UGString& strUsername = "", const UGString& strPassword = "", UGfloat fserviceVersion = 1.0f);
    //! \brief ��������˷�����ָ��ͼ���ͼ����Ϣhttp url ����
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strSceneName [in] ָ������������
	//! \param const UGString& strlayername [in] ͼ����
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \return	����http url ����
	static UGString UrlGetLayerInfo(const UGString& strNetPath, const UGString& strSceneName, const UGString& strlayername, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);

	//! \brief ��������˷�����ָ��ͼ���ͼ������Ϣhttp url ����
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strSceneName [in] ָ������������
	//! \param const UGString& strlayername [in] ͼ����
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \return	����http url ����
	static UGString UrlGetLayerStyleInfo(const UGString& strNetPath, const UGString& strSceneName, const UGString& strlayername, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);

	//! \fn		static UGString UrlGetSceneListInfo(const UGString& strNetPath, const UGString& strUsername = "", const UGString& strPassword = "", UGfloat fserviceVersion = 1.0f);
	//! \brief ��������˷����ĳ����б�http url����
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \return	����http url ����
	static UGString UrlGetSceneListInfo(const UGString& strNetPath, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);

	//! \fn		static UGString UrlGetSceneInfo(const UGString& strNetPath, const UGString& strSceneName, const UGString& strUsername = "", const UGString& strPassword = "", UGfloat fserviceVersion = 1.0f);
	//! \brief ��������˷�����ָ��������Ϣ http url ����
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strSceneName [in] ָ������������
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \return	����http url ����
	static UGString UrlGetSceneInfo(const UGString& strNetPath, const UGString& strSceneName, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);

    //! \fn static UGString UrlGetModelIndex(const UGString& strNetPath, const UGString& strdataname, const UGString& strUsername = "", const UGString& strPassword = "", UGfloat fserviceVersion = 1.0f);
    //! \brief ������ȡģ��������http url ����
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strdataname [in] ͼ����
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \return	����http url ����
	static UGString UrlGetModelIndex(const UGString& strNetPath, const UGString& strdataname, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);

	//! \brief ������ȡʸ��������http url ����
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strdataname [in] ͼ����
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \return	����http url ����
	static UGString UrlGetVectorIndex(const UGString& strNetPath, const UGString& strdataname, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);

	//! \brief ������ȡ����˸��ͻ��˻�����ܵ���������url
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \return	����http url ����
	static UGString UrlGetCacheAccessKey(const UGString& strNetPath, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);

	// Ԥ���ӿڸ���ģ��id��������������ģ��sgm�Լ���������
//	static UGString UrlGetModelDataByID();

    //! \fn		static UGString UrlGetDataVersionByIndex(const UGString& strNetPath, const UGString& strdataname, UGint nlevel, UGint nCol, UGint nRow, const UGString& strfileExtent = "", const UGString& strUsername = "", const UGString& strPassword = "", UGfloat fserviceVersion = 1.0f);
    //! \brief ������ȡָ��ͼ���������������ݵİ汾 http url����
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strdataname [in] ͼ����
	//! \param UGint nlevel [in] ����������
	//! \param UGint nRow [in] �������к�
	//! \param UGint nCol [in] �������к�
	//! \param const UGString& strfileExtent = "" [in] �ļ���չ����Ĭ��Ϊ�գ���Ĭ��ȥ��png bil sgm��׺��������
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \remarks �����������ݡ��������ݡ�ģ���������ݰ汾��ʱʹ��
	//! \return	����http url ����

	// �ɵ� const UGString& strdatatype [in] �������ݵ����ͷ�ΪIMG DEM SGM����
	// ���ļ���չ���ظ�
	static UGString UrlGetDataVersionByIndex(const UGString& strNetPath, const UGString& strdataname,
		UGint nlevel, UGint nRow, UGint nCol, const UGString& strfileExtent, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);


    //! \fn		static UGString GetDataVersionByBoundsUrl(const UGString& strNetPath, const UGString& strlayername, const UGString& strdatatype,		UGint nlevel, UGdouble left, UGdouble top, UGdouble right, UGdouble bottom, const UGString& strfileExtent = "", UGint npicWidth = 0, UGint npicHeight = 0, const UGString& strUsername = "", const UGString& strPassword = "", UGfloat fserviceVersion = 1.0f);
    //! \brief ������ȡָ������Χ��ͼ���������ݵİ汾�� http url ����
	//! \param const UGString& strNetPath [in] ����˵�ַ
	//! \param const UGString& strlayername [in] ͼ����
	//! \param const UGString& strdatatype [in] �������ݵ����ͷ�ΪIMG DEM SGM����
	//! \param UGint nlevel [in] ����������
	//! \param UGdouble left [in] ����
	//! \param UGdouble top [in] ��γ
	//! \param UGdouble right [in] ����
	//! \param UGdouble bottom [in] ��γ
	//! \param const UGString& strfileExtent = "" [in] �ļ���չ����Ĭ��Ϊ�գ���Ĭ��ȥ��png bil sgm��׺��������
	//! \param UGint npicWidth = 0 [in] ����x��������㣬
	//! �������ͼƬ���ݾ������أ����ڵ������ݾ���ÿ����������̵߳�ĸ�����Ĭ����0������ͼƬ���ݾ���256 �������ݾ���32
	//! \param UGint npicHeight = 0 [in] ����y���������
	//! \param const UGString& strUsername = "" [in] �û�����Ĭ��Ϊ��
	//! \param const UGString& strPassword = "" [in] ���룬Ĭ���ǿ�
	//! \param UGfloat fserviceVersion = 1.0f [in] ����˰汾
	//! \remarks �����������ݡ��������ݡ�ģ����������ʱʹ��
	//! \return	����http url ����
	static UGString GetDataVersionByBoundsUrl(const UGString& strNetPath, const UGString& strlayername, const UGString& strdatatype,
		UGdouble left, UGdouble top, UGdouble right, UGdouble bottom, const UGString& strfileExtent = _U(""), UGint npicWidth = 0, UGint npicHeight = 0, const UGString& strUsername = _U(""), const UGString& strPassword = _U(""), UGfloat fserviceVersion = 1.0f);


//! \brief ָ�������ļ����ص����ص�ȫ·���������ߴ��ļ������·����
	UGString m_strFileName;

//! \brief http url ����
	UGString m_strUrl;

//! \brief ��ʶ�������Ƿ��Ѿ����سɹ�
	UGbool m_bIsDownload;

//! \brief �ļ�����չ�������ļ��ڴ��ļ������е�������
	UGString m_strFileExtend;

//! \brief ���ͻ��˻�ȡÿһ�������ַ�����κ�ÿ��������Ҫ���ϵ�idֵ��ʶ����û�о�Ϊ�ա�
	static UGDict<UGString, UGString> ms_strJsessionIDs;	// �����Ƿ����ַ��ֵ��JsessionID

//! \brief �������Ӧ�����ݿ�Ĳ����кš�
	UGint m_nLevel;
	UGint m_nRow;
	UGint m_nCol;
	UGRequestDataType m_dataType;
};

}

#endif // !defined(AFX_UGGEOSPATIALDOWNLOADREQUEST_H__0BCDA7DE_B5FB_46A1_9A81_7B7EAABA3E36__INCLUDED_)

