////////////////////////////////////////////////////////////////////////////////
//!  Project UGC
//! \file UGWebDownloadThread.h
//! \author UGC Group
//! \brief �����̣߳��ڲ����ûص����������ⲿʹ����ָ���ɻ������
//! \attention Ŀǰ������ά�����ʹ�ù�
//!  Copyright (c)copy;  1997-2009 SuperMap Software Co., Ltd.<br> 
//!  All Rights Reserved.
//! \version 6.0
//! \date 2009��8��28��
////////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGWEBDOWNLOADTHREAD_H__4A50E4DC_4371_4DAA_AF32_76DD8B65566E__INCLUDED_)
#define AFX_UGWEBDOWNLOADTHREAD_H__4A50E4DC_4371_4DAA_AF32_76DD8B65566E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Toolkit/UGThread.h"

namespace UGC
{

	//! \brief �ص����������ڴӿ����̵߳�ִ��
//	typedef void (UGWebDownload::* WebDownloadHandler)();
	
	//! \brief �����ⲿ�ص����������ڴӿ����̵߳�ִ��
	//! \attention ����ʹ����ķǾ�̬��Ա����
	typedef UGbool (UGSTDCALL * WebDownloadHandler)(void* );

//! \brief class UGWebDownloadThread
//! \brief �����߳�
class NETTOOLKIT_API UGWebDownloadThread : public UGThread  
{
public:

    //! \fn UGWebDownloadThread(WebDownloadHandler pCallback);
    //! \brief Ĭ�Ϲ��캯������Ҫָ���ⲿ�ص�������ָ��
    //! \param WebDownloadHandler pCallback
	UGWebDownloadThread(WebDownloadHandler pCallback);
	

    //! \fn virtual ~UGWebDownloadThread();
    //! \brief Ĭ����������
	virtual ~UGWebDownloadThread();

    //! \fn void SetHandeler(void* pHandeler);
    //! \brief �����������߳����ɻ���ⲿ���ã�Ŀǰ���������ָ�룬
	//!	�ⲿ�ص������ڲ��ٽ�������ת�����Ϳ��Ե������ڲ��ĳ�Ա����ȥ�ɻ��ˡ� 
    //! \param void* pHandeler [in] ������
	void SetHandeler(void* pHandeler);

protected:
	
	//! \brief ��д����run������
	//! \return �߳������˳�����0��ʧ���򷵻�-1��
	virtual UGint run();	

private:
	//! \brief �ص�����ָ��
	WebDownloadHandler m_pRunHandler;

	//! \brief �ⲿ������
	void* m_pHandeler;

};

}

#endif // !defined(AFX_UGWEBDOWNLOADTHREAD_H__4A50E4DC_4371_4DAA_AF32_76DD8B65566E__INCLUDED_)
 
