// UGVectorManager.h: interface for the UGVectorManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGVectorManager_H__D47A6033_C470_4B3B_9AE7_70EAE68D0BC2__INCLUDED_)
#define AFX_UGVectorManager_H__D47A6033_C470_4B3B_9AE7_70EAE68D0BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UGPluginDefine.h"
#include "UGVectorPlugin.h"

namespace UGC
{

class FILEPARSER_API UGVectorManager  
{
public:
	UGVectorManager();
	virtual ~UGVectorManager();

public:	
	//! \brief �õ�Ӱ��������Ŀ��
	static UGint GetPluginCount();	

	//! \brief ����һ��ָ���ļ�����ʸ�������
	//! \param strPathName [in]��
	//! \return ���سɹ�����true��
	static UGbool LoadPlugin(const UGString& strPathName);	

	//! \brief ж��ʸ�������
	//! \param hHandle [in] ��̬������
	//! \return �ɹ�ж�ط���true��
	static UGbool UnloadPlugin(void* hHandle);	

	//! \brief �õ����ι������塣
	//! \param nIndex [in] ������
	//! \return ��
	static UGPluginDefine* GetAt(UGint nIndex);	

	//! \brief ����һ��ʸ�����ʵ�塣
	//! \param nFileType [in] ������͡�
	static UGVectorPlugin* CreateVectorPlugin(const UGint& nFileType);

	// ���ʸ����������ھ�̬���� for Android by liucq
	UGbool AddVectorProvider(void* handle);

private:
	UGPluginDefine* Check(void* hHandle);
	UGPluginDefine* Find(const UGint& nFileType);
	void LoadPlugin();
	void UnloadPlugin();

private:
	UGbool m_bLoaded;
	UGArray<UGPluginDefine*> m_PluginDefines;	
};

extern FILEPARSER_API UGVectorManager g_vectorManager;

}

#endif // !defined(AFX_UGVectorManager_H__D47A6033_C470_4B3B_9AE7_70EAE68D0BC2__INCLUDED_)

