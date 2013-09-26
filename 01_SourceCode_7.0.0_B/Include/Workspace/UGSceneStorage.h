// UGSceneStorage.h: interface for the UGSceneStorage class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGSceneStorage.h
   **************************************************************************************
    \author   �¹���
    \brief    ��ά����XML�ַ����洢�ࡣ                                          
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                          <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGSCENESTORAGE_H__83180122_F19C_4C57_9AC2_41C962B884B8__INCLUDED_)
#define AFX_UGSCENESTORAGE_H__83180122_F19C_4C57_9AC2_41C962B884B8__INCLUDED_

#include "Stream/ugdefs.h"

namespace UGC {

class WORKSPACE_API UGSceneStorage  
{
public:
	UGSceneStorage();
#ifdef SYMBIAN60
	~UGSceneStorage();
#else
	virtual ~UGSceneStorage();
#endif
	UGSceneStorage& operator = (const UGSceneStorage& storage);

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
	//! \brief 		�õ���ά�������ơ�
	UGString GetName()const;
	//========================================================
	//! \brief 		������ά�������ơ�
	void SetName(const UGString& strName);
	//========================================================
	//! \brief 		�õ���ά������ϢXML�ַ�����
	UGString GetXML()const;
	//========================================================
	//! \brief 		������ά������ϢXML�ַ�����
	void SetXML(const UGString& strXML, UGint nVersion = 0);
	//========================================================
	//! \brief 		�õ���ͼ�汾��
	UGint GetVersion()const;

protected:
	//! \brief 		�޸ı�ʶ��
	UGbool m_bModified;
	//! \brief 		��ά������ϢXML�ַ�����
	UGString m_strXML;
	//! \brief 		��ά�������ơ�
	UGString m_strName;
	//! \brief 		��ά�����汾��
	UGint m_nVersion;

};

}

#endif // !defined(AFX_UGSCENESTORAGE_H__83180122_F19C_4C57_9AC2_41C962B884B8__INCLUDED_)

