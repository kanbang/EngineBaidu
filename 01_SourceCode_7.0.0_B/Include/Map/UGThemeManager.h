// UGThemeManager.h: interface for the UGThemeManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTHEMEMANAGER_H__FC3BDA35_5F4C_460F_B9E6_CAD1D82B029C__INCLUDED_)
#define AFX_UGTHEMEMANAGER_H__FC3BDA35_5F4C_460F_B9E6_CAD1D82B029C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Stream/ugdefs.h"
#include "Map/UGThemeDefine.h"

namespace UGC{

class MAP_API UGThemeManager  
{
public:
	UGThemeManager();
#ifdef SYMBIAN60
	~UGThemeManager();
#else
	virtual ~UGThemeManager();
#endif


public:
	//! \brief ����һ��ָ���ļ����Ķ�̬�⡣
	//! \param strPathName [in]��
	//! \return ���سɹ�����true��
	static UGbool LoadTheme(const UGString& strPathName);	

	//! \brief ж�ض�̬�⡣
	//! \param hHandle [in] ��̬������
	//! \return �ɹ�ж�ط���true��
	static UGbool UnloadTheme(void* hHandle);

	//! \brief ��ȡָ��������ר��ͼϵͳ�������
	static UGThemeDefine* GetThemeDefine(UGint nIndex);
	//! \brief ����ר��ͼ
	static UGTheme* NewTheme(UGTheme::UGThemeType nType);
	static UGTheme* NewTheme(UGString strThemeTypeName);

	static UGTheme* CloneTheme(UGTheme* pTheme);

	//!\ ���ר��ͼ��������ھ�̬���� for Android by liucq
	UGbool AddThemeProvider(void* handle);

private:
	//! \brief װ��ר��ͼϵͳ���
	void LoadThemes();
	//! \brief ж��ר��ͼϵͳ���
	void UnloadThemes();
	//! \brief ���ݶ�̬�������ר��ͼϵͳ�������
	UGThemeDefine* CheckThemeDef(void* hHandle)const;
	//! \brief ���������ҵ�ר��ͼϵͳ�������
	UGThemeDefine* Find(UGint nType);
private:
	UGArray<UGThemeDefine* > m_themeDefs;

};

extern MAP_API UGThemeManager g_themeManger;

}

#endif // !defined(AFX_UGTHEMEMANAGER_H__FC3BDA35_5F4C_460F_B9E6_CAD1D82B029C__INCLUDED_)

