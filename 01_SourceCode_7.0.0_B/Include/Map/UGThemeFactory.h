// UGThemeFactory.h: interface for the UGThemeFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTHEMEFACTORY_H__5DA9AD4A_4CC8_46A4_AD27_0177352099F4__INCLUDED_)
#define AFX_UGTHEMEFACTORY_H__5DA9AD4A_4CC8_46A4_AD27_0177352099F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Stream/ugdefs.h"
#include "Map/UGTheme.h"

namespace UGC{
#ifdef SYMBIAN60
class MAP_APIC UGThemeFactory  
#else
class MAP_API UGThemeFactory  
#endif
{
public:
	MAP_APIF UGThemeFactory();
	virtual MAP_APIF ~UGThemeFactory();

public:
	//! \brief �Ƿ�֧�ָ�ר��ͼ
	virtual MAP_APIF UGbool IsSupportTheme(UGint nThemeType) = 0;
	//! \brief �õ�����֧�ֵ�ר��ͼ����
	virtual MAP_APIF UGint GetSupportThemeType(UGArray<UGint>& nTypeArray) = 0;
	//! \brief �õ���������
	virtual MAP_APIF UGString GetName() = 0;
	//! \brief ����ר��ͼ
	virtual MAP_APIF UGTheme* NewTheme(UGint nType) = 0;
	//! \brief Copyר��ͼ
	virtual MAP_APIF UGTheme* CloneTheme(UGTheme* pTheme) = 0;
};

}

#endif // !defined(AFX_UGTHEMEFACTORY_H__5DA9AD4A_4CC8_46A4_AD27_0177352099F4__INCLUDED_)

