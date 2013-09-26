// UGLayoutStorages.h: interface for the UGLayoutStorages class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGLayoutStorages.h
   **************************************************************************************
    \author   �¹���
    \brief    ���ּ��Ϲ����࣬ͨ������XML�洢ָ���벼�����Ƶ�һһ��Ӧ��ϵ���й���
			  ����֤�������Ƶ�Ψһ�ԡ�                                                              
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                          <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGLAYOUTSTORAGES_H__E2F7C6E2_0990_4741_B37D_86155AD90D67__INCLUDED_)
#define AFX_UGLAYOUTSTORAGES_H__E2F7C6E2_0990_4741_B37D_86155AD90D67__INCLUDED_

#include "Workspace/UGLayoutStorage.h"
#include "Stream/ugdefs.h"
#include "Engine/UGDataSource.h"

namespace UGC {

	class UGWorkspace;
typedef void (*LATOUTVERSIONPROC)(UGLayoutStorage* pLayoutStorage, UGint nVersion, UGWorkspace* pWorkspace);
class WORKSPACE_API UGLayoutStorages  
{
public:
	UGLayoutStorages();
#ifdef SYMBIAN60
	~UGLayoutStorages();
#else 
	virtual ~UGLayoutStorages();
#endif

public:	
	static void SetLayoutVersionFunc(LATOUTVERSIONPROC pLayoutVersionFunc);
	//! \brief �޸�Xml���ݡ�
	//! \param strSrc Դ����[in]��
	//! \param strFileName �����ļ���[out]��
	//! \return �޸ĺ�����ݡ�
	static UGbool ChangeLayoutXML(const UGString& strSrc,UGString& strFileName,UGString& strDes);
	//! \brief �ƶ������ļ���ָ��Ŀ¼��
	//! \param SrcFile Դ�ļ�[in]��
	//! \param DesDir Ŀ���ļ����ڵ��ļ���[in]��
	//! \return �Ƿ��ƶ��ɹ���
	//! \remarks ��
	static UGbool MoveLayoutFile(const UGString& SrcFile,const UGString& DesDir);	
	//========================================================
	//! \brief 		�õ�����ռ�õĲ��������������Ĳ����������ھ��ô���Ĳ�������������Ƽ�һ������ռ�õĲ�������
	//! \return 	UGString ���ز���ռ�õĲ�������
	//! \param 		strName ϣ���Ĳ�������
	UGString GetUnoccupiedLytName(const UGString& strName);
	//========================================================
	//! \brief 		�ж��Ƿ����޸ģ�������һ��Ա���޸ġ�
	//! \return 	UGbool ������޸ľͷ���true������ͷ���false��
	UGbool IsModified()const;
	//========================================================
	//! \brief 		�����޸ı�ʶ���������Լ������ã����Ҷ��������޸ı�ʶ�ĳ�Ա�������á�
	void SetModifiedFlag(UGbool bModified = true);

	//========================================================
	//! \brief 		�õ�ָ�������Ĳ������ơ�
	//! \return 	UGString ���ز������ơ�
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	UGString GetNameAt(UGint nIndex)const;
	//========================================================
	//! \brief 		�õ�ָ�������Ĳ��ִ洢����ָ�롣
	//! \return 	UGLayoutStorage ������ھͷ��ز��ִ洢����ָ�룬����ͷ���NULL��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	UGLayoutStorage * GetLayoutAt(UGint nIndex)const;

	//========================================================
	//! \brief 		���߲�ɾ��ָ���������ƵĲ��ִ洢����
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		strName ��������
	UGbool Remove(const UGString &strName,UGbool bDelFile = false);
	//========================================================
	//! \brief 		���߲�ɾ��ָ�������Ĳ��ִ洢����
	//! \return 	UGint ����ɾ�����ִ洢�������Ŀ�����û��ɾ���ɷ���-1��
	//! \param 		nIndex ��ʼ������������ڵ���0��С���������
	//! \param 		nCount ��ʼ������ʼ����Ҫɾ�����ִ洢�������Ŀ��
	UGint Remove(UGint nIndex, UGint nCount = 1,UGbool bDelFile = false);
	//========================================================
	//! \brief 		��ղ�ɾ�����в��ִ洢����
	void RemoveAll(UGbool bDelFile = false);
	//========================================================
	//! \brief 		��¡һ��ָ�����ƵĲ��ִ洢����
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		strOldName ����¡�Ĳ��ִ洢��������ơ�
	//! \param 		strNewName ��¡������ִ洢��������ơ�
	UGbool CloneLayout(const UGString &strOldName, const UGString &strNewName);

	//========================================================
	//! \brief 		�������������ơ�
	//! \return 	UGbool ����ɵĲ������ƴ��ڣ������µĲ�������û�б�ռ�þͷ���true������ͷ���false��
	//! \param 		strOldName �ɵĲ������ơ�
	//! \param 		strNewName �µĲ������ơ�
	UGbool Rename(const UGString &strOldName, const UGString &strNewName);
	//========================================================
	//! \brief 		����ָ�����ƵĲ��ִ洢����
	//! \return 	UGLayoutStorage* ����ɹ��Ͳ��ִ洢���󣬷��򷵻�NULL��
	//! \param 		strName �������ơ�
	UGLayoutStorage* Find(const UGString &strName) const;
	//========================================================
	//! \brief 		����һ��ָ�����ƵĲ��ִ洢����
	//! \return 	UGbool �����������û�б�ռ�ò��ɹ��������ִ洢����ͷ���true������ͷ���false��
	//! \param 		strName �������ơ�
	UGbool Add(const UGString &strName);

	//========================================================
	//! \brief 		�Ӳ����ļ����벼����Ϣ�����첢�򿪲��֡�
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		strFileName �����ļ�ȫ·������
	UGbool LoadFromFile(const UGString &strFileName);
	//========================================================
	//! \brief 		�Ѳ�����Ϣ����Ϊ�����ļ�������ļ����ھ͸�������
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		strFileName �����ļ�ȫ·������
	UGbool SaveToFile(const UGString &strFileName)const;

	//========================================================
	//! \brief 		�����޸�ָ���������ƵĲ��ִ洢����ָ�룬����������Ʋ����ھ�����һ�����ִ洢����
	//! \return 	void
	//! \param 		strName �������ƣ�����Ϊ���ַ�����
	//! \param 		pLytStorage ���ִ洢����ָ�롣
	void SetAt(const UGString &strName, UGLayoutStorage* pLytStorage);
	//========================================================
	//! \brief 		�õ�ָ�������Ĳ������ƺͲ��ִ洢����ָ�롣
	//! \return 	UGbool ����ҵ��ͷ���true������ͷ���false��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	//! \param 		strName ���ز������ơ�
	//! \param 		pLytStorage ���ز��ִ洢����ָ�롣
	UGbool GetAt(UGint nIndex, UGString &strName, UGLayoutStorage *&pLytStorage);
	//========================================================
	//! \brief 		����ָ�����ƵĲ��ִ洢����
	//! \return 	UGbool ����ҵ��ͷ���true������ͷ���false��
	//! \param 		strName �������ơ�
	//! \param 		pLytStorage ���ز��ִ洢����ָ�롣
	UGbool Lookup (const UGString &strName, UGLayoutStorage* &pLytStorage) const;

	//========================================================
	//! \brief 		�������ã��൱��RemoveAll()��
	void Reset();	
	//========================================================
	//! \brief 		�õ����ִ洢������Ŀ��
	UGint GetCount()const;
	//========================================================
	//! \brief 		�Ƿ�û�в��ִ洢�������û�о�Ϊtrue�������Ϊfalse��
	UGbool IsEmpty()const;
	
	//========================================================
	//! \brief 		�������������ļ�·����Ϣ��XML�ַ��������첢�򿪲��ּ��ϡ�
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		strXML ���������ļ�·����Ϣ��XML�ַ�����
	//! \param 		strWorkspaceName �����ռ�ȫ·������
	//! \param 		nVersion �����ռ�汾
	UGbool FromXML(const UGString &strXML, const UGString &strWorkspaceName, UGint nVersion = 0);
	//========================================================
	//! \brief 		�Ѳ����ļ�·����Ϣ����δXML�ַ�����
	//! \return 	UGString ���ذ��������ļ�·����Ϣ��XML�ַ�����������ɹ��ͷ��ؿ��ַ�����
	//! \param 		strWorkspaceName �����ռ�ȫ·������
	//! \param 		nVersion �����ռ�汾
	UGString ToXML(const UGString &strWorkspaceName, UGint nVersion = 0)const;
	
	UGbool Load(UGStream& stream);	
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

	void AttachWorkspace(UGWorkspace* pWorkspace);
	
	//! \brief ��ȡ�ļ�����
	//! \param strWorkspacePath �����ռ�ȫ·��[in]��
	//! \param strMapName layout������[in]��
	//! \param strSave  ���沼�ֵ����·��[out]��
	//! \return ����ȫ·����
	//! \remarks ��
	//! \attention ��
	static	UGString GetFileName(const UGString& strWorkspacePath,const UGString& strMapName, UGString& strSave,UGbool bCreateIfNo = false);

	// �������ļ����а汾ת��
	// param strLayoutPath[in] �����ļ�����·��
	// param nToVersion[in] Ŀ��汾
	// param nFromVersion[in] ԭ�汾
	// ���ڲ����������汾UG_WORKSPACE_VERSION_20090106 �� UG_WORKSPACE_VERSION_20120328
	static UGbool ChangeVersion(UGString strLayoutPath, UGint nToVersion, UGint nFromVersion);

	UGString m_strSaveWorkspaceName;
protected:
	//! \brief 		��̬��ͼ�汾����ص�������
	static LATOUTVERSIONPROC m_pLayoutVersionFunc;
	//! \brief 		�޸ı�ʶ��
	UGbool m_bModified;
	//! \brief �����ռ�
	UGWorkspace* m_pWorkspace;
public:
	//! \brief 		���ִ洢���󼯺ϡ�
	UGDict<UGString, UGLayoutStorage*> m_LayoutStorages;
	//! \brief 		�������Ƽ��ϡ�
	UGArray<UGString>  m_strArrNames;
};

}

#endif // !defined(AFX_UGLAYOUTSTORAGES_H__E2F7C6E2_0990_4741_B37D_86155AD90D67__INCLUDED_)

