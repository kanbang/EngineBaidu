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

#if !defined(AFX_UGMAPDOWNLOADREQUEST_H__4A50E4DC_4371_4DAA_AF32_76DD8B65566E__INCLUDED_)
#define AFX_UGMAPDOWNLOADREQUEST_H__4A50E4DC_4371_4DAA_AF32_76DD8B65566E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugexports.h"
#include "Stream/ugdefs.h"
#include "Stream/ugplatform.h"

namespace UGC
{

class MAPSERVICESTUB_API UGMapDownloadRequest
{
public:
	//! \brief ����
	UGMapDownloadRequest();

	~UGMapDownloadRequest();

	//! \brief ���� ==
	//! \param const UGMapDownloadRequest& request
	//! \return	 ��������������򷵻�true
	UGbool operator==(const UGMapDownloadRequest& request) const;

	//! \brief ����=��
	//! \param &request [in]��
	void operator = (const UGMapDownloadRequest &request);

public:

	//! \brief ������Ƭ��URL��ַ
	UGString m_strURL;

	//! \brief ������Ƭ�Ĵ洢·��
	UGString m_strFileName;

	//! \brief ������Ƭ�ļ�����ļ�Ŀ¼
	UGuint m_nScalePath;

	//! \brief ������Ƭ�ı�����
	UGdouble m_dScale;

	//! \brief ������Ƭ���к�
	UGint m_nRow;

	//! \brief ������Ƭ���к�
	UGint m_nCol;
};

}
#endif // !defined(AFX_UGMAPDOWNLOADREQUEST_H__4A50E4DC_4371_4DAA_AF32_76DD8B65566E__INCLUDED_)

