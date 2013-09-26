// UGSceneStorages.h: interface for the UGSceneStorages class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGSceneStorages.h
   **************************************************************************************
    \author   �¹���
    \brief    ��ά�������Ϲ����࣬ͨ����ά����XML�洢ָ������ά�������Ƶ�һһ��Ӧ��ϵ
			  ���й�������֤��ά�������Ƶ�Ψһ�ԡ�                                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                          <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGSCENESTORAGES_H__9DCDABD7_A8F5_4424_89CF_0EDCF63CDE61__INCLUDED_)
#define AFX_UGSCENESTORAGES_H__9DCDABD7_A8F5_4424_89CF_0EDCF63CDE61__INCLUDED_

#include "Workspace/UGSceneStorage.h"
#include "Stream/ugdefs.h"
#include "Workspace/UGResources.h"

namespace UGC {
class UGWorkspace;
typedef void (*SCENEVERSIONPROC)(UGSceneStorage* pSceneStorage, UGint nVersion, UGWorkspace* pWorkspace);

class WORKSPACE_API UGSceneStorages  
{
public:
	UGSceneStorages();
#ifdef SYMBIAN60
	~UGSceneStorages();
#else
	virtual ~UGSceneStorages();
#endif

public:
	static void SetSceneVersionFunc(SCENEVERSIONPROC pSceneVersionFunc);
	//========================================================
	//! \brief 		�õ�����ռ�õ���ά������������������ά�����������ھ��ô������ά��������������Ƽ�һ������ռ�õ���ά��������
	//! \return 	UGString ���ز���ռ�õ���ά��������
	//! \param 		strName ϣ������ά��������
	UGString GetUnoccupiedSceneName(const UGString& strName);
	
	//========================================================
	//! \brief 		�����޸ı�ʶ���������Լ������ã����Ҷ��������޸ı�ʶ�ĳ�Ա�������á�
	void SetModifiedFlag(UGbool bModified = true);
	//========================================================
	//! \brief 		�ж��Ƿ����޸ģ�������һ��Ա���޸ġ�
	//! \return 	UGbool ������޸ľͷ���true������ͷ���false��
	UGbool IsModified()const;
	
	//========================================================
	//! \brief 		���߲�ɾ��ָ����ά�������Ƶ���ά�����洢����
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		&strName ��ά��������
	UGbool Remove(const UGString &strName);
	//========================================================
	//! \brief 		���߲�ɾ��ָ����������ά�����洢����
	//! \return 	UGint ��������ɾ����ά�����洢�������Ŀ�����û��ɾ���ɷ���-1��
	//! \param 		nIndex ��ʼ������������ڵ���0��С���������
	//! \param 		nCount ��ʼ������ʼ����Ҫɾ����ά�����洢�������Ŀ��
	UGint Remove(UGint nIndex, UGint nCount = 1);
	//========================================================
	//! \brief 		��ղ�ɾ��������ά�����洢����
	//! \return 	void
	void RemoveAll();
	//========================================================
	//! \brief 		�õ�ָ����������ά�����洢����ָ�롣
	//! \return 	UGSceneStorage* ������ھͷ�����ά�����洢����ָ�룬����ͷ���NULL��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	UGSceneStorage* GetSceneAt(UGint nIndex)const;
	//========================================================
	//! \brief 		�õ�ָ����������ά�������ơ�
	//! \return 	UGString ������ά�������ơ�
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	UGString GetNameAt(UGint nIndex)const;

	//========================================================
	//! \brief 		��¡һ��ָ�����Ƶ���ά�����洢����
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		&strOldScene ����¡����ά�����洢��������ơ�
	//! \param 		&strNewScene ��¡�����ά�����洢��������ơ�
	UGbool CloneScene(const UGString &strOldScene, const UGString &strNewScene);
	//========================================================
	//! \brief 		�������ã��൱��RemoveAll()��
	void Reset();

	//========================================================
	//! \brief 		��������ά�������ơ�
	//! \return 	UGbool ����ɵ���ά�������ƴ��ڣ������µ���ά��������û�б�ռ�þͷ���true������ͷ���false��
	//! \param 		&strOldName �ɵ���ά�������ơ�
	//! \param 		&strNewName �µ���ά�������ơ�
	UGbool Rename(const UGString &strOldName, const UGString &strNewName);
	//========================================================
	//! \brief 		����ָ�����Ƶ���ά�����洢����
	//! \return 	UGSceneStorage* ����ɹ�����ά�����洢���󣬷��򷵻�NULL��
	//! \param 		&strName ��ά�������ơ�
	UGSceneStorage* Find(const UGString &strName)const;
	//========================================================
	//! \brief 		����һ��ָ�����Ƶ���ά�����洢����
	//! \return 	UGbool �����ά��������û�б�ռ�ò��ɹ�������ά�����洢����ͷ���true������ͷ���false��
	//! \param 		strName ��ά�������ơ�
	UGbool Add(const UGString &strName);
	
	//========================================================
	//! \brief 		����ά������Ϣ����δXML�ַ�����
	//! \return 	UGString ���ذ�����ά������Ϣ��XML�ַ�����������ɹ��ͷ��ؿ��ַ�����
	//! \param 		nVersion �����ռ�汾��
	UGString ToXML(UGint nVersion = 0)const;
	//========================================================
	//! \brief 		����������ά������Ϣ��XML�ַ�����������ά�������ϡ�
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		strXML ������ά������Ϣ��XML�ַ�����
	//! \param 		nVersion �����ռ�汾��
	UGbool FromXML(const UGString &strXML, UGint nVersion = 0);

	//========================================================
	//! \brief 		�����޸�ָ����ά�������Ƶ���ά�����洢����ָ�룬�����ά�������Ʋ����ھ�����һ����ά�����洢����
	//! \return 	void
	//! \param 		strName ��ά�������ƣ�����Ϊ���ַ�����
	//! \param 		pSceneStorage ��ά�����洢����ָ�롣
	void SetAt (const UGString &strName, UGSceneStorage* pSceneStorage);
	//========================================================
	//! \brief 		�õ�ָ����������ά�������ƺ���ά�����洢����ָ�롣
	//! \return 	UGbool ����ҵ��ͷ���true������ͷ���false��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	//! \param 		strName ������ά�������ơ�
	//! \param 		pSceneStorage ������ά�����洢����ָ�롣
	UGbool GetAt (UGint nIndex, UGString &strName, UGSceneStorage *&pSceneStorage);
	//========================================================
	//! \brief 		����ָ�����Ƶ���ά�����洢����
	//! \return 	UGbool ����ҵ��ͷ���true������ͷ���false��
	//! \param 		strName ��ά�������ơ�
	//! \param 		pSceneStorage ������ά�����洢����ָ�롣
	UGbool Lookup (const UGString &strName, UGSceneStorage *&pSceneStorage ) const;

	//========================================================
	//! \brief 		�õ���ά�����洢������Ŀ��
	UGint GetCount()const;
	//========================================================
	//! \brief 		�Ƿ�û����ά�����洢�������û�о�Ϊtrue�������Ϊfalse��
	//! \return 	UGbool
	UGbool IsEmpty()const;

	void AttachWorkspace(UGWorkspace* pWorkspace);

public:
	//! \brief 		��ά�����洢���󼯺ϡ�
	UGDict<UGString, UGSceneStorage*> m_SceneStorages;
	//! \brief 		��ά�������Ƽ��ϡ�
	UGArray<UGString> m_strArrNames;
protected:
	
	//! \brief 		�޸ı�ʶ��
	UGbool m_bModified;

	//! \brief 		��̬��ͼ�汾����ص�������
	static SCENEVERSIONPROC m_pSceneVersionFunc;

	UGWorkspace* m_pWorkspace;
};

}

#endif // !defined(AFX_UGSCENESTORAGES_H__9DCDABD7_A8F5_4424_89CF_0EDCF63CDE61__INCLUDED_)

