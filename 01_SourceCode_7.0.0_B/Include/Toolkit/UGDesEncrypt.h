// UGDesEncrypt.h: interface for the UGDesEncrypt class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDESENCRYPT_H__C364698C_5E89_4C16_8850_63871A01DC07__INCLUDED_)
#define AFX_UGDESENCRYPT_H__C364698C_5E89_4C16_8850_63871A01DC07__INCLUDED_


#include "Stream/ugdefs.h"

namespace UGC {	
	  //!  \brief Toolkit
const static UGuchar Des_key[17] = "~@!#(*&)_OP%#_*!";	
	  //!  \brief Toolkit
const static UGint Des_key_length = 16;

#ifdef OS_ANDROID // androidĿǰ����ɹ���ʽ��Ҫʹ�õ��⼸����������ͷ�ļ�������һ��
enum    {ENCRYPT,DECRYPT};

// Type��ENCRYPT:����,DECRYPT:����
// ���������(Out)�ĳ��� >= ((datalen+7)/8)*8,����datalen�������8�ı�������С������
// In ����= Out,��ʱ��/���ܺ󽫸������뻺����(In)������
// ��keylen>8ʱϵͳ�Զ�ʹ��3��DES��/����,����ʹ�ñ�׼DES��/����.����16�ֽں�ֻȡǰ16�ֽ�
bool Des_Go(char *Out,char *In,UGuint datalen,const char *Key,int keylen,bool Type = ENCRYPT);
#endif

	  //!  \brief Toolkit
class TOOLKIT_API UGDesEncrypt  
{
	
	
public:
	  //!  \brief Toolkit
	enum WorkMode
	{
	//! \brief
	  //!  \brief Toolkit
		ENCRYPT,
	//! \brief
	  //!  \brief Toolkit
		DECRYPT,
	};
	
	//! \brief
	  //!  \brief Toolkit
	UGDesEncrypt();
	//! \brief
	  //!  \brief Toolkit
	virtual ~UGDesEncrypt();
	//! \brief
	  //!  \brief Toolkit
	static UGbool Work(UGbyte *&szOut, 
					     UGbyte *szIn, 
                        UGint& datalen, 
                    const UGbyte *Key, 
                          UGint keylen, 
                     WorkMode emMode);
	//! \brief ���ܹ����ռ�,added by macx 2008.8.4 ��
	//! \param strDes ���ؼ��ܺ���ַ�����[out]
	//! \param strWorkspaceName �����ռ���[in]��
	//! \param key ���룬�ӽ��ܵ�key Ĭ��Ϊ��,��ʾ������[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static UGbool EncryptString(UGString& strDes,const UGString& strSrc,const UGString& strPWD = (_U("")));
	//! \brief ���ܹ����ռ�,added by macx 2008.8.4 ��
	//! \param strDes ���ؽ��ܺ���ַ�����[out]
	//! \param strWorkspaceName �����ռ���[in]��
	//! \param strKey ���룬�ӽ��ܵ�key Ĭ��Ϊ�գ���ʾδ����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static UGbool DecryptString(UGString& strDes,const UGString& strSrc,const UGString& strPWD = (_U("")));	
	
};

}

#endif // !defined(AFX_UGDESENCRYPT_H__C364698C_5E89_4C16_8850_63871A01DC07__INCLUDED_)

