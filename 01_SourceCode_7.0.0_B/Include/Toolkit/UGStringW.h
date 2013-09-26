//$Id: UGStringW.h,v 1.9 2009/11/05 09:36:47 siyh Exp $
//$Author: siyh $
//$Date: 2009/11/05 09:36:47 $
//$Source: /home/cvsroot/UGC60/01_SourceCode/Include/Toolkit/UGStringW.h,v $
//$Revision&
//$Log: UGStringW.h,v $
//Revision 1.9  2009/11/05 09:36:47  siyh
//�޸�ͷ�ļ�ע��
//
//Revision 1.8  2009/05/26 09:17:28  cuiwz
//����ע��
//
//Revision 1.7  2009/05/25 06:25:12  cuiwz
//����ע��
//
//Revision 1.6  2009/05/15 01:53:25  chenzhao
//*** empty log message ***
//
//Revision 1.5  2009/05/15 01:35:02  chenzhao
//*** empty log message ***
//
//Revision 1.4  2008/12/11 07:31:34  cuiwz
//LoadString �ĳ�LoadresString
//
//Revision 1.3  2008/07/18 09:36:37  chengx
//LPCTSTR�滻��UGPCTSTR
//
//Revision 1.2  2008/05/28 07:14:15  cuiwz
//���Ӷ�UGByteArray��֧��
//
//Revision 1.1  2008/04/28 11:40:23  chengx
//����Toolkit������
//
//Revision 1.22  2007/11/01 08:40:01  zengzm
//���� utf8 �ַ�����
//
//Revision 1.21  2007/10/29 10:34:04  zengzm
//��UGStringUCS2LE�ļ�����������const����
//
//Revision 1.20  2007/10/29 09:12:34  liwl
//�ַ�������utf_16
//
//Revision 1.19  2007/07/20 08:44:43  xielin
//���Ż�ȡ�ڲ���Ա�����Ľӿ�
//
//Revision 1.18  2007/07/18 09:53:30  zengzm
//����==����,ɾ������û�õĺ���
//
//Revision 1.17  2007/05/10 13:54:43  zengzm
//���� UGStringU GetLength����
//
//Revision 1.16  2007/04/19 08:39:48  zengzm
//ɾ��û���õĺ���
//
//Revision 1.15  2007/04/07 08:57:50  zengzm
//�Ѹ����ĵ��е�UGFile����ΪUGFileLogical,�����Base�е�UGFile����
//
//Revision 1.14  2007/04/07 07:50:23  zengzm
//�޸�UGStringU,���������linux�±���ͨ��
//
//Revision 1.13  2007/04/07 05:55:03  zengzm
//����UGStringU��,���ں�SFC�����ݼ���,�Լ����ֽ��ַ����洢��ͳһ.
//
//Revision 1.12  2006/12/30 06:04:34  xielin
//��������ƽ̨���ַ���ת������
//
//Revision 1.11  2005/12/07 02:48:12  caogf
//����һ����������
//
//Revision 1.10  2005/06/08 01:49:34  caogf
//no message
//
//Revision 1.9  2005/06/07 08:07:27  caogf
//no message
//
//Revision 1.8  2005/05/31 02:40:26  caogf
//no message
//
//Revision 1.7  2005/05/31 02:28:51  caogf
//no message
//
//Revision 1.6  2005/05/30 05:07:40  chengx
//no message
//
//Revision 1.5  2005/05/27 08:38:58  caogf
//no message
//
//Revision 1.4  2005/05/27 08:31:40  caogf
//no message
//
//Revision 1.3  2005/05/24 07:10:05  jifang
//Modified by jifang.
//append a CR at bottom.
//
//Revision 1.2  2005/05/23 02:53:38  caogf
//no message
//
#ifndef UGSTRINGW_H
#define UGSTRINGW_H

#include "Stream/ugdefs.h"
#include "Stream/UGStream.h"
#include "Toolkit/UGTextCodec.h"
#include "Stream/UGByteArray.h"

namespace UGC {
#ifndef _UGUNICODE
	  //!  \brief Toolkit
class UGStringW;
	  //!  \brief Toolkit
typedef const UGwchar* UGPCTSTRW;
	  //!  \brief Toolkit
typedef UGArray<UGStringW> UGStrWArray;

/* ����UGC�и���ƽ̨�ַ���ʹ�õ�˵��
1, ����һ����ַ���,����UGString, ���ֽڷ�ʽ(MBCS), �� ��Ӣ�ĵȿ��Ի�����һ��
2, ���ַ�����Ҫ��Unicode��ʽ��ȡʱ,Ϊ�˺�SFC����һ��, ����UGStringU������, Ȼ��ת��ΪUGString��ʹ��
3, �����Ҫ��UGString�л��ӵ���Ӣ�ķ��뿪,�����ת��ΪUGStringW, UGStringW����ø���ƽ̨�Զ���Unicode���뷽ʽ,
   ����ƽ̨�ı��뷽ʽ���ǲ�һ�µ�. ���,���ܲ���UGStringW�����д�ȡ,��ʵ��,UGStringW ��Stream֮��Ĵ�ȡ����
   �Ѿ���ע�͵���, ������ܵ�����.
*/

//! \brief ���ֽ��ַ����ࡣ
/**
	\remarks �ر���Ҫע�����: UGStringW�ڲ�����stl��wstringʵ��,wstring�ڲ��õ���wchar_t*,
	������ƽ̨��wchar_t���ֽڳ��Ⱥ��ֽ�˳���ǲ�һ����,����Windowsһ����2�ֽ�,LittleEndian;
	Solaris(Sparc)Ҳ��2�ֽ�,BigEndian; LinuxΪ4�ֽ�. ���,������Ϊ����ƽ̨ͬ�����ݵ�UGStringW���ڲ��洢��һ�µ�.
	Ҳ����˵, UGStringW����������֤����ƽ̨�Ͽ��ֽ�(Unicode)�ַ����洢��ͳһ. ��һְ�ܱ�����һ����UGStringUCS2LE
	���е�, UGStringUCS2LE��֤��ȡ������ Windows�ϵ� UCS2,LittleEndian��ʽ����,�Ա��ָ���ƽ̨��ͳһ����SFC���ݵļ���.
	UGStringW��Ҫ���������ַ����в��.
*/
class TOOLKIT_API UGStringW
{
public:
	  //!  \brief Toolkit
	UGStringW();
	  //!  \brief Toolkit
	  //!  \brief Toolkit
	UGStringW(const UGMBString& str);
	  //!  \brief Toolkit
	UGStringW(const UGStringW& str);
	  //!  \brief Toolkit
	UGStringW(const UGwchar* str);
	  //!  \brief Toolkit
	UGStringW(const UGwchar* str,const UGint nSize);
	  //!  \brief Toolkit
	UGStringW(const std::wstring& str);
	  //!  \brief Toolkit
	~UGStringW();
	  //!  \brief Toolkit
	operator UGPCTSTRW() const;
	//! \brief ת��MBCS�����
	UGMBString ToString(UGMBString::Charset enTarget = UGMBString::Default);
	//! \brief ͨ����ͨ�ַ�������
	void FromString(const UGMBString& str,UGMBString::Charset enSource = UGMBString::Default);

	  //!  \brief Toolkit
	bool operator==(const UGwchar* pch) const;
	  //!  \brief Toolkit
	bool operator!=(const UGwchar* pch) const;

	// commited by zengzm 2007-4-19 ��������������UGStringU�����,���������
	//add by xielin 2006.10.23
	//���ڰ�windows�϶�ȡ��Stringw��char��ת�����ʺϸ���ƽ̨��StringW����ȡ���ݵ�ʱ��
	//������������ת��һ�£�������ܳ�����������
	//UGMBString WinOSStringWToString();
	//���ڰѸ���ƽ̨�ϵ�StringWת����Windowsƽ̨�ϵ�Stringw��char������дStringw���ļ�
	//��ʱ����������������ת��һ�¡������Ժ��ȡ���ܾͻ�����⡣
	//void WinOSStringWFromString(const UGMBString& str);
	
	
	
	  //!  \brief Toolkit
	const UGwchar* Cstr()const;
	
	  //!  \brief Toolkit
	UGwchar GetAt(UGint nIndex)const;
	  //!  \brief Toolkit
	void SetAt(UGint nIndex,UGwchar wch);
	  //!  \brief Toolkit
	UGwchar operator[](UGint nIndex)const;
	  //!  \brief Toolkit
	UGwchar& operator[](UGint nIndex);
	
	  //!  \brief Toolkit
	void SetCapacity(UGint nCapacity);
	  //!  \brief Toolkit
	UGint GetCapacity()const;
	  //!  \brief Toolkit
	const UGwchar* GetData()const;
	  //!  \brief Toolkit
	
	  //!  \brief Toolkit
	UGint GetLength()const;
	  //!  \brief Toolkit
	void  MakeUpper();
	  //!  \brief Toolkit
	void	MakeLower();
	  //!  \brief Toolkit
	void  MakeInverse();
	
	  //!  \brief Toolkit
	UGStringW Left(UGint nCount)const;
	  //!  \brief Toolkit
	UGStringW Right(UGint nCount)const;
	  //!  \brief Toolkit
	UGStringW Mid(UGint nFirst)const;
	  //!  \brief Toolkit
	UGStringW Mid(UGint nFirst,UGint nCount)const;
	  //!  \brief Toolkit
	
	  //!  \brief Toolkit
	UGint Delete(UGint nIndex,UGint nCount  = 1);
	  //!  \brief Toolkit
	UGint Insert(UGint nIndex,UGwchar* pstr);
	  //!  \brief Toolkit
	UGint Insert(UGint nIndex,UGwchar ch,UGint nCount = 1);
	  //!  \brief Toolkit
	UGint Remove(UGwchar ch);
	
	  //!  \brief Toolkit
	UGStringW& TrimLeft();
	  //!  \brief Toolkit
	UGStringW& TrimLeft(UGwchar ch);
	  //!  \brief Toolkit
	UGStringW& TrimLeft(const UGwchar* pstr);
	  //!  \brief Toolkit
	UGStringW& TrimRight();
	  //!  \brief Toolkit
	UGStringW& TrimRight(UGwchar ch);
	  //!  \brief Toolkit
	UGStringW& TrimRight(const UGwchar* pstr);
	
	  //!  \brief Toolkit
	UGbool IsEmpty()const;
	  //!  \brief Toolkit
	void Empty();
	
	  //!  \brief Toolkit
	UGint Compare(const UGwchar* pstr)const;
	  //!  \brief Toolkit
	UGint CompareNoCase(const UGwchar* pstr)const;
	
	  //!  \brief Toolkit
	UGint Find(UGwchar ch) const;	
	  //!  \brief Toolkit
	UGint ReverseFind(UGwchar ch) const;	
	  //!  \brief Toolkit
	UGint Find(UGwchar ch,UGint nStart) const;	
	  //!  \brief Toolkit
	UGint FindOneOf(const UGwchar* lpszCharSet) const;	
	  //!  \brief Toolkit
	UGint Find(const UGwchar* lpszSub) const;	
	  //!  \brief Toolkit
	UGint Find(const UGwchar* lpszSub, UGint nStart) const;
	
	  //!  \brief Toolkit
	UGStringW SpanIncluding(const UGwchar* lpszCharSet) const;	
	  //!  \brief Toolkit
	UGStringW SpanExcluding(const UGwchar* lpszCharSet) const;
	
	  //!  \brief Toolkit
	UGint Replace(UGwchar chOld,UGwchar chNew);
	  //!  \brief Toolkit
	UGint Replace(const UGwchar* lpszOld,const UGwchar* lpszNew);
	
	// commited by zengzm 2007-7-17 UGStringW���ṩ
	  //!  \brief Toolkit
	//UGuint HashVal() const;
	
	// commited by zengzm 2007-4-7 UGStringW���ṩ��Щ�Ƚϲ���
	  //!  \brief Toolkit
	//UGbool LoadResString(UGuint nID);
	  //!  \brief Toolkit
	//void Format(const UGwchar* fmt,...);
	  //!  \brief Toolkit
	//void Format(UGuint nID,...);
	
	// commited by zengzm 2007-7-17 UGStringW���ṩ
	//Convert string to a integer number, assuming given number base
	  //!  \brief Toolkit
	//friend BASE_API UGint UGIntVal(const UGStringW& s,UGint base=10);
	  //!  \brief Toolkit
	//friend BASE_API UGuint UGUIntVal(const UGStringW& s,UGint base=10);
	
	//Convert string into real number
	  //!  \brief Toolkit
	//friend BASE_API UGfloat UGFloatVal(const UGStringW& s);
	  //!  \brief Toolkit
	//friend BASE_API UGdouble UGDoubleVal(const UGStringW& s);	
	
	  //!  \brief Toolkit
	//! \brief �Ե�ǰ�ַ������в�֡�
	//! \param &dest ��ֺ����ɵ��ַ�������[in]��
	//! \param delims ��ֵı�־���ţ����ж�����Ŵ��ڵ�ʱ��ÿ�����Ŷ��Ǳ�ʶ��[in]��
	//! \return ��
	//! \remarks delims ���Ƕ�����Ŵ���һ����ַ��ţ�������Ŵ�������ַ���,
	//! \attention ֻ֧��һ���ַ��Ĳ�֡�
	UGint Split(UGArray<UGStringW> &dest,const UGStringW& delims=L"\r\n") const;
	
	// commited by zengzm 2007-4-7 ��ȡ�����齻��UGStringUCS2LE����
	  //!  \brief Toolkit
	//friend BASE_API UGStream& operator<<(UGStream& store,const UGStringW& s);
	  //!  \brief Toolkit
	//friend BASE_API UGStream& operator>>(UGStream& store,UGStringW& s);
	
private:
	// void FormatV(const UGwchar* fmt, va_list argList);
	
protected:
	std::wstring m_string;  
};

//! \brief ����UCS2-LE�ķ�ʽ�����ַ����������,���ڸ���ƽ̨�ַ�����ȡ��ͳһ��
//! \remarks SFC��Unicode��ȡʱ,���ǰ���UCS2-LE������е�; UGStringUCS2LE�ɱ�֤��SFC�����ݼ��ݡ�
//!	UGStringUCS2LE�ṩ�Ĺ��ܰ���: 1)��Stream�д�ȡUCS2LE��ʽ���ַ���;2)��UGString֮�����ת��
//!	<\br>���Ӷ�ֱ��ʹ��UGStringUCS2LE�е��ַ�����֧�֣���Ҫ���������ַ������������Լ�����Cstr����
	  //!  \brief Toolkit
class TOOLKIT_API UGStringUCS2LE
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGStringUCS2LE();

	//! \brief �ṩͨ��UGString�����й��졣
	UGStringUCS2LE(const UGMBString& str, UGMBString::Charset enTarget = UGMBString::Default);	

	//! \brief ת��ΪUGString
	UGMBString ToString(UGMBString::Charset enTarget = UGMBString::Default) const;

	//! \brief �õ��ַ�����
	//! \return �����ַ������������ֽڳ���/2��
	UGint GetLength() const;

	//! \brief �õ�UGushort*��ʽ���ַ���
	const UGushort* Cstr() const;

	//! \brief д���洢����
	friend TOOLKIT_API UGStream& operator<<(UGStream& store,const UGStringUCS2LE& s);
	//! \brief �Ӵ洢���ж���
	friend TOOLKIT_API UGStream& operator>>(UGStream& store,UGStringUCS2LE& s);

	// add by cuiwz 2008-5-28 ֧�� UGByteArray
	//! \brief д���洢����
	friend TOOLKIT_API UGByteArray& operator<<(UGByteArray& store,const UGStringUCS2LE& s);
	//! \brief �Ӵ洢���ж���
	friend TOOLKIT_API UGByteArray& operator>>(UGByteArray& store,UGStringUCS2LE& s);
	
	//! \brief ��ȡ��Ա����m_string������Ϳ��������������һЩ����
	const UGArray<UGushort>& GetChars() const;
protected:
	//typedef std::basic_string<UGushort, std::char_traits<UGushort>, std::allocator<UGushort> > ustring;
	//ustring m_string;
	UGArray<UGushort> m_string;
};

//! \brief ��UGStringUCS2LE ȡһ����һ�������
typedef UGStringUCS2LE UGStringU;


//! \brief ����UTF8�ķ�ʽ�����ַ����������,���ڰѸ�����붼ת��Ϊutf8֮���ٴ��ݸ��ܶ��ƽ̨����ʹ��
class TOOLKIT_API UGStringUTF8
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGStringUTF8();

	//! \brief �ṩͨ��UGString�����й��졣
	UGStringUTF8(const UGMBString& str, UGMBString::Charset enTarget = UGMBString::Default);	

	//! \brief ת��ΪUGString
	UGMBString ToString(UGMBString::Charset enTarget = UGMBString::Default) const;

	//! \brief �õ��ֽڸ���
	//! \remarks ��ΪUTF8�����������,�������ǵõ��ֽڵĳ���;�����Ҫ�ַ�����,����ת��Ϊ����������ַ���
	//! \return �����ֽڸ���
	UGint GetLength() const;

	//! \brief �õ�char *��ʽ���ַ���
	const UGachar* Cstr() const;

	// ��д�����У��ݲ�֧�֣�����Ҫ��˵һ�����ٿ����������
	//! \brief д���洢����
	//friend BASE_API UGStream& operator<<(UGStream& store,const UGStringUCS2LE& s);
	//! \brief �Ӵ洢���ж���
	//friend BASE_API UGStream& operator>>(UGStream& store,UGStringUCS2LE& s);
	
	//! \brief ��ȡ��Ա����m_string������Ϳ��������������һЩ����
	// const UGArray<UGushort>& GetChars() const;
protected:
	//typedef std::basic_string<UGushort, std::char_traits<UGushort>, std::allocator<UGushort> > ustring;
	std::string m_string; // �ڲ�����std��stringʵ��
	//UGArray<UGushort> m_string;
};
#endif //_UGUNICODE
}

#endif

