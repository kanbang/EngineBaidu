// UGImageManager.h: interface for the UGImageManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGIMAGEMANAGER_H__D47A6033_C470_4B3B_9AE7_70EAE68D0BC2__INCLUDED_)
#define AFX_UGIMAGEMANAGER_H__D47A6033_C470_4B3B_9AE7_70EAE68D0BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UGPluginDefine.h"
#include "UGImagePlugin.h"

namespace UGC
{

class FILEPARSER_API UGImageManager  
{
public:
	UGImageManager();
	virtual ~UGImageManager();

public:	
	//! \brief �õ�Ӱ��������Ŀ��
	static UGint GetPluginCount();	

	//! \brief �õ���������ơ�
	static UGString GetPluginName(const UGString& strExtName);	

	//! \brief �ж��Ƿ�֧�ָ���չ���ļ���
	//! \param strExtName���������չ����
	static UGbool IsSupportExtName(const UGString& strExtName);

	//! \brief ����һ��ָ���ļ�����Ӱ������
	//! \param strPathName [in]��
	//! \return ���سɹ�����true��
	static UGbool LoadPlugin(const UGString& strPathName);	

	//! \brief ж��Ӱ������
	//! \param hHandle [in] ��̬������
	//! \return �ɹ�ж�ط���true��
	static UGbool UnloadPlugin(void* hHandle);	

	//! \brief �õ����ι������塣
	//! \param nIndex [in] ������
	//! \return ��
	static UGPluginDefine* GetAt(UGint nIndex);	
	
	//! \brief ����һ��Ӱ����ʵ�塣
	static UGImagePlugin* CreateImagePlugin(const UGString& strExtName);
	
	//! \brief ����һ��Ӱ����ʵ�塣
	//! \param nFileType [in] ������͡�
	static UGImagePlugin* CreateImagePlugin(const UGint& nFileType);

	//! \brief ���뻺�������ļ���·����
	static void SetCacheConfigFilePathName(const UGString& strPathName);

	// ���ͼ���������ھ�̬���� for Android by liucq
	UGbool AddImageProvider(void* handle);

private:
	UGPluginDefine* Check(void* hHandle);
	UGPluginDefine* Find(const UGString& strExtName);
	UGPluginDefine* Find(const UGint& nFileType);
	void LoadPlugin();
	void UnloadPlugin();
	// �жϻ���汾�Ƿ�Ϊ5.0����
	UGbool CheckVersion(UGString strPath);
	// �жϻ���汾�Ƿ�Ϊ7.0����
	UGbool CheckVersionV70(UGString strPath);
	// ��ȡ����汾
	UGint GetVersionFromFile(UGString strPath);

	//�ж��Ƿ�Ϊ�����ͼ����
	UGbool CheckWebCache(UGString strPath);

private:
	UGbool m_bLoaded;
	UGArray<UGPluginDefine*> m_pluginDefines;
	static UGString m_strCacheConfigFile;				// ���������ļ�·����
};

extern FILEPARSER_API UGImageManager g_imageManager;

}

#endif // !defined(AFX_UGIMAGEMANAGER_H__D47A6033_C470_4B3B_9AE7_70EAE68D0BC2__INCLUDED_)

