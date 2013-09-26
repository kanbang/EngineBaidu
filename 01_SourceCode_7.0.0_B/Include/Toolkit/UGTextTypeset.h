// UGTextTypeset.h: interface for the UGTextTypeset class.
//
//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGTextTypeset.h
//!  \brief ��Щ���ҵ�������Ⱦ��Ҫһ�����Ű���򣬱��簢����������Ҫ����������д�ȵȸ��ӹ���
//!  \details UGTextTypeset.h��cpp�ļ���Ϊ���������������Ⱦ���������
//!  \author wangxh 2012.04.25
//!  \attention 
//!   Copyright (c) 1996-2012 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTEXTTYPESET_H__E87F3D39_C520_427D_9F11_72CB26885C13__INCLUDED_)
#define AFX_UGTEXTTYPESET_H__E87F3D39_C520_427D_9F11_72CB26885C13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugdefs.h"
#include "Base/OgdcArray.h"

#ifdef _UGUNICODE
#include "Toolkit/UGStringEx.h"
#define UGStringW UGString
#else
#include "Toolkit/UGStringW.h"
#endif

namespace UGC 
{
	//������Ҫ����Ķ�����ԣ���Ҫ��������Դ���������Ҫ�ڴ˶���һ�������Է���
	//���������һ����Χ
	enum UGMultiLanguageType
	{
		ARABIC_TYPE =0,					//��������
		ENGLISH_TYPE =1,				//Ӣ��
		CHINESE_TYPE =2,				//����
		JAPANESE_TYPE =3,			//����
		/*
			�м������������
		*/
		UNKNOWN_TYPE =0xFFFF
	};

	//����ÿ�����Ե�Unicode��Χ
	//����
	//��һ���ַ�������ʾ����ķ�Χ�����ĸ�ö�٣����簢�������������Χ�ı�־��Ϊ0
	//0x0600~0x06FF:�����������ַ�
	//0xFB50~0xFDFF:�����������ʽA
	//0xFE70~0xFEFF:�����������ʽB
	const UGwchar MultiLanguageUnicodeRange[] =
	{
		0x0000,0x0600,0x06FF,0x0000,0xFB50,0xFDFF,0x0000,0xFE70,0xFEFF,	//��������Χ
		0x0001,0x0000,0x007F,											//Ӣ�ﷶΧ
		0x0002,0x4E00,0x9FA5,											//���ַ�Χ
		0x0003,0x3040,0x309F,0x0003,0x30A0,0x30FF,0x0003,0x31F0,0x31FF,	//���������Χ
	};

	//��������Unicode����дת���� Arabic Presentation Form-B, first, last, middle, alone
	/*
	����1��
	�������ı���:
	��������ַ����ֳ�first��last��middle��alone���������ж��Ƿ��Ǵʵ�ǰ����ǰ���ַ��ڼ���1�У��������������ַ��ڼ���2�У����м䣨��ǰ������ǰ���ַ��ڼ���1�У������ַ��ڼ���2�У��򵥶�һ���ʣ����б��Ρ�
	�ݷ������������ε�����:�ֱ��Ӧ���������������������������еģ�����κ�������ͬ��
	*/
	const UGwchar Arbic_Position[][4]=
	{
		{ 0xfe80, 0xfe80, 0xfe80, 0xfe80},    // 0x621
		{ 0xfe82, 0xfe81, 0xfe82, 0xfe81},
		{ 0xfe84, 0xfe83, 0xfe84, 0xfe83},
		{ 0xfe86, 0xfe85, 0xfe86, 0xfe85},
		{ 0xfe88, 0xfe87, 0xfe88, 0xfe87},
		{ 0xfe8a, 0xfe8b, 0xfe8c, 0xfe89},
		{ 0xfe8e, 0xfe8d, 0xfe8e, 0xfe8d},
		{ 0xfe90, 0xfe91, 0xfe92, 0xfe8f},   // 0x628
		{ 0xfe94, 0xfe93, 0xfe93, 0xfe93},
		{ 0xfe96, 0xfe97, 0xfe98, 0xfe95},   // 0x62A
		{ 0xfe9a, 0xfe9b, 0xfe9c, 0xfe99},
		{ 0xfe9e, 0xfe9f, 0xfea0, 0xfe9d},
		{ 0xfea2, 0xfea3, 0xfea4, 0xfea1},
		{ 0xfea6, 0xfea7, 0xfea8, 0xfea5},
		{ 0xfeaa, 0xfea9, 0xfeaa, 0xfea9},
		{ 0xfeac, 0xfeab, 0xfeac, 0xfeab},   // 0x630  
		{ 0xfeae, 0xfead, 0xfeae, 0xfead},
		{ 0xfeb0, 0xfeaf, 0xfeb0, 0xfeaf},
		{ 0xfeb2, 0xfeb3, 0xfeb4, 0xfeb1},
		{ 0xfeb6, 0xfeb7, 0xfeb8, 0xfeb5},
		{ 0xfeba, 0xfebb, 0xfebc, 0xfeb9},
		{ 0xfebe, 0xfebf, 0xfec0, 0xfebd},
		{ 0xfec2, 0xfec3, 0xfec4, 0xfec1},
		{ 0xfec6, 0xfec7, 0xfec8, 0xfec5},  // 0x638
		{ 0xfeca, 0xfecb, 0xfecc, 0xfec9},
		{ 0xfece, 0xfecf, 0xfed0, 0xfecd},  //0x63A
		{ 0x63b, 0x63b, 0x63b, 0x63b},
		{ 0x63c, 0x63c, 0x63c, 0x63c},
		{ 0x63d, 0x63d, 0x63d, 0x63d},
		{ 0x63e, 0x63e, 0x63e, 0x63e},
		{ 0x63f, 0x63f, 0x63f, 0x63f},
		{ 0x640, 0x640, 0x640, 0x640},   // 0x640
		{ 0xfed2, 0xfed3, 0xfed4, 0xfed1},
		{ 0xfed6, 0xfed7, 0xfed8, 0xfed5},
		{ 0xfeda, 0xfedb, 0xfedc, 0xfed9},
		{ 0xfede, 0xfedf, 0xfee0, 0xfedd},
		{ 0xfee2, 0xfee3, 0xfee4, 0xfee1},
		{ 0xfee6, 0xfee7, 0xfee8, 0xfee5},
		{ 0xfeea, 0xfeeb, 0xfeec, 0xfee9},
		{ 0xfeee, 0xfeed, 0xfeee, 0xfeed},   // 0x648
		{ 0xfef0, 0xfeef, 0xfef0, 0xfeef},
		{0xfef2, 0xfef3, 0xfef4, 0xfef1},   // 0x64A
	};


	/*//Arabic Find Table1
	�ж��Ƿ�������ǰ��ģ������жϸ��ַ�ǰһ���ַ����ж������������ǣ�
	��ǰһ���ַ��Ƿ��ڼ���set1�С�����ڣ�����������ǰ��ġ�����1����:
	*/
	const UGwchar theSet1[27]={
		0x62c, 0x62d, 0x62e, 0x647, 0x639, 0x63a, 0x641, 0x642,
		0x62b, 0x635, 0x636, 0x637, 0x643, 0x645, 0x646, 0x62a,
		0x644, 0x628, 0x64a, 0x633, 0x634, 0x638, 0x626,0x6af,0x6a9,0x686,0x67e};

	/*	//Arabic Find Table2
	�ж��Ƿ������Ӻ���ģ������жϸ��ַ���һ���ַ����ж������������ǣ�
	����һ���ַ��Ƿ��ڼ���set2�С�����ڣ����������Ӻ���ġ�����2����:
	*/
	const UGwchar theSet2[40]={
		0x62c,0x62d, 0x62e, 0x647, 0x639, 0x63a, 0x641, 0x642,
		0x62b, 0x635, 0x636, 0x637, 0x643, 0x645, 0x646, 0x62a,
		0x644, 0x628, 0x64a, 0x633, 0x634, 0x638, 0x626,0x6af,0x6a9,0x686,0x67e,
		0x627, 0x623, 0x625, 0x622, 0x62f, 0x630, 0x631, 0x632,
		0x648, 0x624, 0x629, 0x649,0x698};

	//������Ⱦ�Ű�ת��������
	class TOOLKIT_API UGTextTypesetMultiLanguage
	{
	public:
		virtual void Convert(const UGStringW& strOriginal,UGStringW &strAfterConversion) =0;
		virtual ~UGTextTypesetMultiLanguage(){}
	};


	//���������Ű�ת������
	class TOOLKIT_API UGTextTypesetArabic : public UGTextTypesetMultiLanguage
	{
	public:
		//���죺��ʼ�����ұ�
		UGTextTypesetArabic();
		//������ɾ�����ұ�
		~UGTextTypesetArabic();
		//ת������
		void Convert(const UGStringW& strOriginal,UGStringW &strAfterConversion);

	private:
		//���ұ�1
		std::vector<UGwchar> m_vecArbicFindTable1;
		//���ұ�2
		std::vector<UGwchar> m_vecArbicFindTable2;

		//ת��һ������������
		inline void ConvertOneWord(const UGStringW& strOriginal,UGStringW &strAfterConversion);

		//�ж��Ƿ��ǰ�������ĸ
		inline UGbool IsArabicChar(UGwchar nChar);

		/*		//�������ַ�
		�����������ַ�����:
		���ַ�����0x644��ͷ�����������0x622��0x623��0x625��0x627�����������ȡ������ַ�����0��1�����0x644ǰһ���ַ����ڼ���1��ͬ����ļ���1���м䣬��ôȡ����1������ȡ����0��
		��������:
		static U16 arabic_specs[][2]=
		{
		{0xFEF5��0xFEF6}��
		{0xFEF7��0xFEF8}��
		{0xFEF9��0xFEFA}��
		{0xFEFB��0xFEFC}��
		};

		��1�� 0x064A�� 0x0644�� 0x0622������
		0x064A �ĺ���һ���ַ� 0x0644 �ڼ���2�У����ݱ������1�ó����Ǻ����ַ���last������ת����: 0xFEF3.  
		��0x064A�ڼ���1 �У����� 0xFEF6 ��� 0x0644 0x0622 ���������롣     

		��2�� 0x0632�� 0x0644�� 0x0622������
		0x0632 �ĺ���һ���ַ� 0x0644 �ڼ���2�У����ݱ������1�ó����Ǻ����ַ���last���� ��ת����: 0xFEAF.  
		�� 0x0632 ���ڼ���1 �У����� 0xFEF5 ��� 0x0644 0x0622 ���������롣  
		*/
		inline UGbool DealWithLinkChar(UGwchar nCharPre,UGwchar& nCur,UGwchar nNext,UGbool &bFindResult);

		//�ڱ������
		inline UGbool FindInTable(std::vector<UGwchar> &vec,UGwchar T);
	};

	//����ӿ�,ͨ������Convert����ʵ���ı��Ű�ת��
	class TOOLKIT_API UGTextTypeset
	{
		//����UGTextTypesetArabicΪ��Ԫ
		friend class UGTextTypesetArabic;

	public:
		//���캯��
		UGTextTypeset();
		//����:��ɾ��ת�����ֵ�
		~UGTextTypeset();

		//str1:ת��ǰ�汾
		//str2:ת����汾
		static void Convert(const UGStringW& strOriginal,UGStringW &strAfterConversion);

		//��ȡָ������ĵ��������ĸ���������
		static UGMultiLanguageType GetWhichLanguage(UGwchar nwChar);

	protected:

		//����ת������ת������û�ҵ����ʵ�ת�����򷵻�str1
		static inline void DoConvert(UGMultiLanguageType nType,const UGStringW&strOriginal,UGStringW &strAfterConversion);

		//�����������ͣ������ҵ��Ŀ���ת����
		static inline UGTextTypesetMultiLanguage *CreateConverter(UGMultiLanguageType nType);

		//ת�����ֵ䣬��δ�ҵ������½�ת���������Ž���
		static UGDict<UGMultiLanguageType ,UGTextTypesetMultiLanguage*> m_dictLangTypeset;

	private:
		//������String��������������-_-...stringw��û�ṩ+�š���
		static void StringAdd(UGStringW &strDest,const UGStringW &strEx);
	};

}

#endif // !defined(AFX_UGTEXTTYPESET_H__E87F3D39_C520_427D_9F11_72CB26885C13__INCLUDED_)
