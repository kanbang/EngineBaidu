// UGLayoutStorage.h: interface for the UGLayoutStorage class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGLayoutStorage.h
   **************************************************************************************
    \author   �¹���
    \brief    ���ֶ����ƴ洢�ࡣ                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                          <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGLAYOUTSTORAGE_H__3514CA02_9B5F_4C46_937B_79CF456279A8__INCLUDED_)
#define AFX_UGLAYOUTSTORAGE_H__3514CA02_9B5F_4C46_937B_79CF456279A8__INCLUDED_

#include "Stream/ugdefs.h"
#include "Stream/UGStream.h"

namespace UGC {

class WORKSPACE_API UGLayoutStorage  
{
public:
	UGLayoutStorage();
#ifdef SYMBIAN60
	~UGLayoutStorage();
#else
	virtual ~UGLayoutStorage();
#endif
	
	UGLayoutStorage& operator = (const UGLayoutStorage& storage);

public:
	//========================================================
	//! \brief 		�����޸ı�ʶ��
	//! \return 	void
	//! \param 		bModified �޸ı�ʶ��
	void SetModifiedFlag(UGbool bModified = true);
	//========================================================
	//! \brief 		�ж��Ƿ����޸ġ�
	//! \return 	UGbool ������޸ľͷ���true������ͷ���false��
	UGbool IsModified()const;
	
	//========================================================
	//! \brief 		���ò������ơ�
	//! \return 	void
	//! \param 		strName �������ƣ�����Ϊ���ַ�����
	void SetName(const UGString& strName);
	//========================================================
	//! \brief 		�õ��������ơ�
	//! \return 	UGString ���ز������ơ�
	UGString GetName()const;

	//========================================================
	//! \brief 		���벼�֡�
	//! \return 	UGbool
	//! \param 		pData
	//! \param 		nSize �ڴ���ֽڴ�С��
	//UGbool Load(const UGuchar* pData, UGint nSize);
	//========================================================
	//! \brief 		���沼�֡�
	//! \return 	UGbool
	//! \param 		pData �����ȷ�����ڴ�
	//! \param 		nSize �ڴ���ֽڴ�С��
	//UGbool Save(UGuchar* pData, UGint nSize) const;
	//========================================================
	//! \brief 		�õ������ڴ����ֽڴ�С��
	//! \return 	UGuint
	//UGuint GetSize()const;
	//========================================================
	//! \brief 		�õ������ڴ��ָ�롣
	//! \return 	UGuchar*
	//const UGuchar* GetData() const;

	UGString GetXML()const;
	//========================================================
	//! \brief 		���ò�����ϢXML�ַ�����
	void SetXML(const UGString& strXML, UGint nVersion = 0);
	//========================================================
	//! \brief 		�õ����ְ汾��
	UGint GetVersion()const;

protected:
	//! \brief 		�޸ı�ʶ��
	UGbool m_bModified;
// 	//! \brief 		������Ϣ�ڴ�顣
// 	UGArray<UGuchar> m_LytData;	
	//! \brief 		�������ơ�
	UGString m_strName;
	//! \brief 		������ϢXML�ַ�����
	UGString m_strXML;
	//! \brief 		���ְ汾��
	UGint m_nVersion;
};

}

#endif // !defined(AFX_UGLAYOUTSTORAGE_H__3514CA02_9B5F_4C46_937B_79CF456279A8__INCLUDED_)

