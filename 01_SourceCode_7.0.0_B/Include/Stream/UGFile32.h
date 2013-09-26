//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGFile32.h
//!  \brief UGFile32��Ľӿڶ��塣
//!  \details UDBPLUS�пռ������ļ�
//!  \author wangmao
//!  \attention 
//!   Copyright (c) 2000-2010 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
#ifndef UGFile32_H
#define UGFile32_H

#if defined(_WIN32) || defined(WIN32)
/* This needs to come before any includes for MSVC compiler */
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Stream/ugdefs.h"
#include "Stream/UGStream.h"
#include "Stream/UGByteArray.h"

namespace UGC{
#ifdef SYMBIAN60
class STREAM_APIC UGFile32 :  public UGStream
#else
class STREAM_API UGFile32 :  public UGStream
#endif
{

public:
	//! \brief ���캯��
	STREAM_APIF UGFile32();
	//! \brief ��������
	virtual STREAM_APIF ~UGFile32();

private:
#ifndef SYMBIAN60
	STREAM_APIF UGFile32(const UGFile32& file32);
	STREAM_APIF UGFile32& operator=(const UGFile32& file32);
#endif

public:
	//! \brief �����ļ������ļ��������ļ� 
	//! \param strName �ļ�����
	//! \param nDirection �ַ�����С
	//! \return ���ش��Ƿ�ɹ�
	//! \remarks UGStreamDirection ����UGStreamSave UGStreamLoad UGStreamLoadSave ����ģʽ ����ģʽ�޷���
	//!    �������ļ�û��close,�ظ��򿪣����ᱣ��ԭ���򿪵���Ϣ�� 
	//!    �� UGStreamSave ģʽ�� �������ļ����ڣ�����������ļ��ĳ���Ϊ�㡣����ģʽ�¿ɶ�����д��
	//!    �� UGStreamLoad ģʽ�� �������ļ������ڣ����ᴴ�����ļ����᷵��ʧ��,�ڴ��ļ�һ������»���ڡ�����ģʽ
    //!                           ����ģʽ������д��
	//! \attention �����һ���ڴ��ļ����ڴ�һ�������ļ����ڴ��ļ�����ɾ�����������Ҫ�����������Close()���෴Ҳ����ˡ�
	STREAM_APIF UGbool Open(const UGString& strFileName, UGStreamDirection nDirection,UGbool bIsSwapEndian = FALSE);


	//! \brief ���ڴ�����ת�����ļ���,�ͷ�ԭ�����ڴ��ļ�ת���ɴ����ļ���
	//! \param &strName �����ļ���·��[in]��
	//! \param flag ת���ɴ����ļ�������[in]��
	STREAM_APIF UGbool MemoryToFile(UGString &strName);

	//! \brief �жϵ�ǰ�ļ��Ƿ��,
	//! \return �ļ��Ƿ��
	STREAM_APIF UGbool IsOpen() const{return m_FileHandle != -1;}

    //! \brief �����ļ���λ�ô��ļ���ʼ��λ������
	//! \param whence �ƶ�λ��
	//! \remarks �ƶ���λ�ò���С��0�����Գ����ļ��ĳ���
	//! \return ���������Ƿ�ɹ�
	virtual STREAM_APIF UGbool SetPosition(UGulong nOffset);

	//! \brief �õ���ȫ���ռ�Ĵ�С���ļ���ʱ��ͬ���ڲ��������Ĵ�С��
	virtual STREAM_APIF UGSizeT GetSpace() const{return (UGSizeT)m_nFileLength;}

	//! \brief ��ȡ�ļ�ָ���λ��,���ļ�ͷ��ƫ������
	//! \return �ļ���ָ�롣
	STREAM_APIF UGulong GetPosition() const{return m_nCurPosition;}

	//! \brief ��ȡ�ļ��ĳ���,��λ�ֽ�
	//! \return �ļ��ĳ���
	virtual STREAM_APIF UGulong GetLength();
	
	//! \brief �ӵ�ǰ�ļ�ָ��λ�ÿ�ʼ���ļ�
	//! \param pContext �ַ����ļ�ָ��,
	//! \param nSize �ַ�����С
	//! \remarks ��ҪԤ�ȿ����ڴ�
	//! \return ���ض�ȡ�Ƿ�ɹ�
	STREAM_APIF UGbool Read(void* pContext,UGSizeT nSize);

	//! \brief �ӵ�ǰ�ļ�ָ��λ�ÿ�ʼд�ļ�������ļ���С���������Զ�����
	//! \param pContext �ַ����ļ�ָ��
	//! \param nSize �ַ�����С
	//! \return ����ʵ��д����ֽ���,���д��ʧ�ܷ���-1
	STREAM_APIF UGbool Write(const void* pContext,UGSizeT nSize);
	
	//! \brief �ر�һ���ļ���
	//! \return �Ƿ�ɹ��رա�
	//! \remarks ����ļ��Ѿ��ر��˷���TRUE��
	STREAM_APIF UGbool Close();	
	
	//! \brief �ļ�ͬ����
	//! \return ͬ���Ƿ�ɹ���
	STREAM_APIF UGbool Sync();
	
	//! \brief ����ˢ�£������ļ�����Ч�����ѻ����е�����д�뵽�ļ��С�
	virtual STREAM_APIF UGbool Flush();  
	
	//! \brief �ض��ļ�
	STREAM_APIF UGbool Truncate(UGulong nPosition);


	//! \brief �õ��ڴ��ļ������ݿ�ʼָ�롣
	//! \return �ڴ��ļ������ݿ�ʼָ�롣
	const STREAM_APIF UGuchar* GetMemoryData();		
	
	//! \brief ���ļ��������nCount�� UGuchar
	STREAM_APIF UGStream&  Load(UGuchar* pContext,UGSizeT nCount);
	
	//! \brief ���ļ��������nCount�� UGchar
	STREAM_APIF UGStream&  Load(UGachar* pContext,UGSizeT nCount);
#if _MSC_VER > 1200
	STREAM_APIF UGStream&  Load(UGwchar* pContext,UGSizeT nCount){return Load((UGushort*)pContext, nCount);}
#endif
	
	//! \brief ���ļ��������nCount�� UGushort
	STREAM_APIF UGStream&  Load(UGushort* pContext,UGSizeT nCount);
	
	//! \brief ���ļ��������nCount�� UGshort
	STREAM_APIF UGStream&  Load(UGshort* pContext,UGSizeT nCount);
	
	//! \brief ���ļ��������nCount�� UGuint
	STREAM_APIF UGStream&  Load(UGuint* pContext,UGSizeT nCount);
	
	//! \brief ���ļ��������nCount�� UGint
	STREAM_APIF UGStream&  Load(UGint* pContext,UGSizeT nCount);
	
	//! \brief ���ļ��������nCount�� UGfloat
	STREAM_APIF UGStream&  Load(UGfloat* pContext,UGSizeT nCount);
	
	//! \brief ���ļ��������nCount�� UGdouble
	STREAM_APIF UGStream&  Load(UGdouble* pContext,UGSizeT nCount);
	
	//! \brief ���ļ��������nCount�� UGlong
	STREAM_APIF UGStream&  Load(UGlong* pContext,UGSizeT nCount);
	
	//! \brief ���ļ��������nCount�� UGulong
	STREAM_APIF UGStream&  Load(UGulong* pContext,UGSizeT nCount);

	//! \brief ���ļ��������һ�� UGuchar
	STREAM_APIF UGStream&  operator>>(UGuchar& v){ Load(&v,1);  return *this; }

	//! \brief ���ļ��������һ�� UGchar
	STREAM_APIF UGStream&  operator>>(UGachar& v){ Load(&v,1);  return *this; }
#if _MSC_VER > 1200
	STREAM_APIF UGStream&  operator>>(UGwchar& v){ Load(&v,1);  return *this; }
#endif

	//! \brief ���ļ��������һ�� UGushort
	STREAM_APIF UGStream&  operator>>(UGushort& v){ Load(&v,1);  return *this; }

	//! \brief ���ļ��������һ�� UGshort
	STREAM_APIF UGStream&  operator>>(UGshort& v){ Load(&v,1);  return *this; }

	//! \brief ���ļ��������һ�� UGuint
	STREAM_APIF UGStream&  operator>>(UGuint& v){ Load(&v,1);  return *this; }

	//! \brief ���ļ��������һ�� UGint
	STREAM_APIF UGStream&  operator>>(UGint& v){ Load(&v,1);  return *this; }

	//! \brief ���ļ��������һ�� UGfloat
	STREAM_APIF UGStream&  operator>>(UGfloat& v){ Load(&v,1); return *this; }

	//! \brief ���ļ��������һ�� UGdouble
	STREAM_APIF UGStream&  operator>>(UGdouble& v){Load(&v,1); return *this; }

	//! \brief ���ļ��������һ�� UGlong
	STREAM_APIF UGStream&  operator>>(UGlong& v){ Load(&v,1);  return *this; }
	
	//! \brief ���ļ��������һ�� UGulong
	STREAM_APIF UGStream&  operator>>(UGulong& v){ Load(&v,1);  return *this; }
	
	//! \brief ����nCount�� UGuchar ���ļ�����
	STREAM_APIF UGStream&  Save(const UGuchar* pContext,UGSizeT nCount);

	//! \brief ����nCount�� UGchar ���ļ�����
	STREAM_APIF UGStream&  Save(const UGachar* pContext,UGSizeT nCount);
#if _MSC_VER > 1200
	STREAM_APIF UGStream&  Save(const UGwchar* pContext,UGSizeT nCount){return Save((UGushort*)pContext, nCount);}
#endif

	//! \brief ����nCount�� UGushort ���ļ�����
	STREAM_APIF UGStream&  Save(const UGushort* pContext,UGSizeT nCount);

	//! \brief ����nCount�� UGshort ���ļ�����
	STREAM_APIF UGStream&  Save(const UGshort* pContext,UGSizeT nCount);

	//! \brief ����nCount�� UGuint ���ļ�����
	STREAM_APIF UGStream&  Save(const UGuint* pContext,UGSizeT nCount);

	//! \brief ����nCount�� UGint ���ļ�����
	STREAM_APIF UGStream&  Save(const UGint* pContext,UGSizeT nCount);

	//! \brief ����nCount�� UGfloat ���ļ�����
	STREAM_APIF UGStream&  Save(const UGfloat* pContext,UGSizeT nCount);

	//! \brief ����nCount�� UGdouble ���ļ�����
	STREAM_APIF UGStream&  Save(const UGdouble* pContext,UGSizeT nCount);

	//! \brief ����nCount�� UGlong ���ļ�����
	STREAM_APIF UGStream&  Save(const UGlong* pContext,UGSizeT nCount);

	//! \brief ����nCount�� UGulong ���ļ�����
	STREAM_APIF UGStream&  Save(const UGulong* pContext,UGSizeT nCount);
	
	//! \brief ����һ�� UGuchar ���ļ�����
	STREAM_APIF UGStream&  operator<<(const UGuchar& v){ Save(&v,1); return *this; }

	//! \brief ����һ�� UGchar ���ļ�����
	STREAM_APIF UGStream&  operator<<(const UGachar& v){ Save(&v,1); return *this; }
#if _MSC_VER > 1200
	STREAM_APIF UGStream&  operator<<(const UGwchar& v){ Save(&v,1); return *this; }
#endif

	//! \brief ����һ�� UGushort ���ļ�����
	STREAM_APIF UGStream&  operator<<(const UGushort& v){ Save(&v,1); return *this; }

	//! \brief ����һ�� UGshort ���ļ�����
	STREAM_APIF UGStream&  operator<<(const UGshort& v){ Save(&v,1); return *this; }

	//! \brief ����һ�� UGuint ���ļ�����
	STREAM_APIF UGStream&  operator<<(const UGuint& v){ Save(&v,1); return *this; }

	//! \brief ����һ�� UGint ���ļ�����
	STREAM_APIF UGStream&  operator<<(const UGint& v){ Save(&v,1); return *this; }

	//! \brief ����һ�� UGfloat ���ļ�����
	STREAM_APIF UGStream&  operator<<(const UGfloat& v){ Save(&v,1); return *this; }

	//! \brief ����һ�� UGdouble ���ļ�����
	STREAM_APIF UGStream&  operator<<(const UGdouble& v){ Save(&v,1); return *this; }

	//! \brief ����һ�� UGlong ���ļ�����
	STREAM_APIF UGStream&  operator<<(const UGlong& v){ Save(&v,1); return *this; }

	//! \brief ����һ�� UGulong ���ļ�����
	STREAM_APIF UGStream&  operator<<(const UGulong& v){ Save(&v,1); return *this; }

	STREAM_APIF UGbool IsMemoryFile(){return m_bIsMemoryFile;}

public:
	//����2�ֽڵĴ�С�˽���,nSize��Ҫ�����ĸ���
	STREAM_APIF static void Swap2Byte(void*pContext,UGSizeT nSize);
	//����4�ֽڵĴ�С�˽���,nSize��Ҫ�����ĸ���
	STREAM_APIF static void Swap4Byte(void*pContext,UGSizeT nSize);
	//����8�ֽڵĴ�С�˽���,nSize��Ҫ�����ĸ���
	STREAM_APIF static void Swap8Byte(void*pContext,UGSizeT nSize);
	//���һ�»������Ƿ��㹻,����������Զ�������,�������ʧ�ܻ᷵��FALSE
	STREAM_APIF UGbool CheckBufferSize(UGSizeT nSize);
	//���ص�ǰ�ļ��Ƿ���ֻ���򿪵�
	STREAM_APIF UGbool IsReadOnly(){return m_bReadOnly;}
private:
	//�������ƶ��ļ���λ��
	STREAM_APIF UGbool SyncPosition();

	//��ʼ����Ա����
	STREAM_APIF void InitializeMember();

	//�ͷ�ռ�е���Դ
	STREAM_APIF void ReleaseResources();

	//! \brief �Ƿ��Ƕ�����
	UGbool m_bLastIsReadOP;

	//! \brief �Ƿ���Ҫ���д�С�˵Ľ���
	UGbool m_bIsSwapEndian;

	//! \brief �Ƿ���Ҫ���������ļ�λ��
	UGbool m_bSyncPosition;	

	//! \brief �Ƿ����ڴ��ļ�
	UGbool m_bIsMemoryFile;

	//! \brief �ļ�ָ��
	UGint m_FileHandle;

	//! \���ƴ�С�˵Ķ�ȡ
	UGuchar*  m_pSwapBuffer;
	
	//! \Buffer�Ĵ�С
	UGulong m_nBufferSize;

	//! \brief ���ļ�ָ�뵱ǰλ��
	UGulong m_nCurPosition;
	
	//! \brief �ļ�����Ч����
	UGulong m_nFileLength;

	//! \brief �ڴ��ļ���
	UGByteArray m_MemFile;
	//�Ƿ���ֻ��ģʽ����ǰ�ļ�
	UGbool  m_bReadOnly;
};

}

#endif // !defined(AFX_UGFile32_H__52E31DC2_8E36_4136_9D5F_C372D533EEC4__INCLUDED_)

