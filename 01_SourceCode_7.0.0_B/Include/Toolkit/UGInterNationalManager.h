// UGInterNationalManager.h: interface for the UGInterNationalManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGINTERNATIONALMANAGER_H__29AC9857_8580_4118_8304_123CC237449E__INCLUDED_)
#define AFX_UGINTERNATIONALMANAGER_H__29AC9857_8580_4118_8304_123CC237449E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Toolkit/UGInterNationalDefine.h"
using namespace UGC;
namespace UGC
{

class TOOLKIT_API UGInterNationalManager  
{
public:
	  //!  \brief Toolkit
	UGInterNationalManager();
	  //!  \brief Toolkit
	~UGInterNationalManager();
public:	
	//! \brief �õ����ʻ�����Ŀ��
	static UGint GetInterCount();	
	
	//! \brief ����InterNational���ͣ���ȡָ������InterNational������
	//! \param nType �����InterNational������
	static UGString GetInterNationName(UGInterNational::Type nType);		
	
	//! \brief ����InterNational���ͣ�����InterNational
	//! \param nType Ҫ�����ļ��ζ������ͣ����Դ���Element���ͣ�Ҳ���Դ���InterNational����
	//! \attention ���ص�InterNationalָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����InterNational��ָ��; ʧ�ܷ���NULL
	static UGInterNational* CreateInterNational(UGint nType);
	
	
	//! \brief �ж��Ƿ�֧�ָü�������
	//! \param nType�������InterNational����
	static UGbool IsSupport(UGint nGeoType);
	
	
	
private:
	UGInterNationalDefine* Check(void* hHandle);
	UGInterNationalDefine* Find(UGint nGeoType);
	void LoadInterNationalFactory();
	void UnloadInterNationalFactory();
	
private:
	UGArray<UGInterNationalDefine*> m_InterNationalDefines;
};

extern TOOLKIT_API UGInterNationalManager g_InterNationManager;


}

#endif // !defined(AFX_UGINTERNATIONALMANAGER_H__29AC9857_8580_4118_8304_123CC237449E__INCLUDED_)

