// UG3DesEncrypt.h: interface for the UG3DesEncrypt class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG3DesEncrypt_H__C364698C_5E89_4C16_8850_63871A01DC07__INCLUDED_)
#define AFX_UG3DesEncrypt_H__C364698C_5E89_4C16_8850_63871A01DC07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef uint8
#define uint8  unsigned char
#endif
#ifndef uint32
#pragma message("unsigned long int should be unsigned int,line=18")		// WhiteBox_Ignore
#define uint32 unsigned long int		// WhiteBox_Ignore
#endif

#include "Stream/ugdefs.h"

namespace UGC {	
//!  \brief Toolkit
const static uint8 UDes_key[17] = "~@!#(*&)_OP%#_*!";	
//!  \brief Toolkit
const static int UDes_key_length = 16;

	  //!  \brief Toolkit
class TOOLKIT_API UG3DesEncrypt  
{
	
	
public:
	  //!  \brief Toolkit
	enum WorkMode
	{
	//! \brief ��
	  //!  \brief Toolkit
		ENCRYPT,
	//! \brief ��
	  //!  \brief Toolkit
		DECRYPT,
	};
	
	//! \brief ��
	UG3DesEncrypt();
	  //!  \brief 
	~UG3DesEncrypt();
	//! \brief ���ܺ�����
	//! \param *szOut ���[in]��
	//! \param *szIn ����[in]��
	//! \param datalen ���볤��[in]��
	//! \param *Key key[in]��
	//! \param emMode [in]��
	//! \return ��
	//! \remarks key���ȱ�����16λ��
	//! \attention ��
	static void Work(uint8 *&szOut, 
		uint8 *szIn, 
		int& datalen, 
		const uint8 *Key, 
		int keylen, 
		WorkMode emMode);

// 	static void Work(uint8 *szOut, 
// 		uint8 *szIn, 
// 		int& datalen, 
// 		const uint8 *Key, 
// 		int keylen, 
// 		WorkMode emMode);
	//added by macx 2008.8.4 ��
	//! \brief ���ܹ����ռ�
	//! \param strDes ���ؼ��ܺ���ַ�����[out]
	//! \param strWorkspaceName �����ռ���[in]��
	//! \param key ���룬�ӽ��ܵ�key Ĭ��Ϊ��,��ʾ������[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static UGbool EncryptString(UGString& strDes,const UGString& strSrc,const UGString& strPWD = _U(""));
	//added by macx 2008.8.4 ��
	//! \brief ���ܹ����ռ�
	//! \param strDes ���ؽ��ܺ���ַ�����[out]
	//! \param strWorkspaceName �����ռ���[in]��
	//! \param strKey ���룬�ӽ��ܵ�key Ĭ��Ϊ�գ���ʾδ����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static UGbool DecryptString(UGString& strDes,const UGString& strSrc,const UGString& strPWD = _U(""));	

	static UGbool DeEncrypt(UGString& strDes,const UGString& strSrc,const UGString& strPWD = _U(""),WorkMode emMode = ENCRYPT);	
	
};

}

#endif // !defined(AFX_UG3DesEncrypt_H__C364698C_5E89_4C16_8850_63871A01DC07__INCLUDED_)

