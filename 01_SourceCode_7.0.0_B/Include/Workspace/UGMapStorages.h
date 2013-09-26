// UGMapStorages.h: interface for the UGMapStorages class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGMapStorages.h
   **************************************************************************************
    \author   �¹���
    \brief    ��ͼ���Ϲ����࣬ͨ����ͼXML�洢ָ�����ͼ���Ƶ�һһ��Ӧ��ϵ���й���
			  ����֤��ͼ���Ƶ�Ψһ�ԡ�                                                   
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                          <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGMAPSTORAGES_H__5F39D6B3_F5CA_48E7_84A0_A1CC4EFA93CD__INCLUDED_)
#define AFX_UGMAPSTORAGES_H__5F39D6B3_F5CA_48E7_84A0_A1CC4EFA93CD__INCLUDED_

#include "Workspace/UGMapStorage.h"
#include "Stream/ugdefs.h"
#include "Workspace/UGResources.h"

namespace UGC {
	
	class UGWorkspace;
typedef void (*MAPVERSIONPROC)(UGMapStorage* pMapStorage, UGint nVersion, UGWorkspace* pWorkspace);

class WORKSPACE_API UGMapStorages  
{
public:
	UGMapStorages();
#ifdef SYMBIAN60
	~UGMapStorages();
#else
	virtual ~UGMapStorages();
#endif

public:
	static void SetMapVersionFunc(MAPVERSIONPROC pMapVersionFunc);
	//========================================================
	//! \brief 		�õ�����ռ�õĵ�ͼ�����������ĵ�ͼ�������ھ��ô���ĵ�ͼ����������Ƽ�һ������ռ�õĵ�ͼ����
	//! \return 	UGString ���ز���ռ�õĵ�ͼ����
	//! \param 		strName ϣ���ĵ�ͼ����
	UGString GetUnoccupiedMapName(const UGString& strName);

	//========================================================
	//! \brief 		�����޸ı�ʶ���������Լ������ã����Ҷ��������޸ı�ʶ�ĳ�Ա�������á�
	void SetModifiedFlag(UGbool bModified = true);
	//========================================================
	//! \brief 		�ж��Ƿ����޸ģ�������һ��Ա���޸ġ�
	//! \return 	UGbool ������޸ľͷ���true������ͷ���false��
	UGbool IsModified()const;

	//========================================================
	//! \brief 		���߲�ɾ��ָ����ͼ���Ƶĵ�ͼ�洢����
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		&strName ��ͼ����
	UGbool Remove(const UGString &strName);
	//========================================================
	//! \brief 		���߲�ɾ��ָ�������ĵ�ͼ�洢����
	//! \return 	UGint ��������ɾ����ͼ�洢�������Ŀ�����û��ɾ���ɷ���-1��
	//! \param 		nIndex ��ʼ������������ڵ���0��С���������
	//! \param 		nCount ��ʼ������ʼ����Ҫɾ����ͼ�洢�������Ŀ��
	UGint Remove(UGint nIndex, UGint nCount = 1);
	//========================================================
	//! \brief 		��ղ�ɾ�����е�ͼ�洢����
	//! \return 	void
	void RemoveAll();
	//========================================================
	//! \brief 		�õ�ָ�������ĵ�ͼ�洢����ָ�롣
	//! \return 	UGMapStorage* ������ھͷ��ص�ͼ�洢����ָ�룬����ͷ���NULL��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	UGMapStorage* GetMapAt(UGint nIndex)const;
	//========================================================
	//! \brief 		�õ�ָ�������ĵ�ͼ���ơ�
	//! \return 	UGString ���ص�ͼ���ơ�
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	UGString GetNameAt(UGint nIndex)const;

	//========================================================
	//! \brief 		��¡һ��ָ�����Ƶĵ�ͼ�洢����
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		&strOldMap ����¡�ĵ�ͼ�洢��������ơ�
	//! \param 		&strNewMap ��¡�����ͼ�洢��������ơ�
	UGbool CloneMap(const UGString &strOldMap, const UGString &strNewMap);
	//========================================================
	//! \brief 		�������ã��൱��RemoveAll()��
	void Reset();

	//========================================================
	//! \brief 		��������ͼ���ơ�
	//! \return 	UGbool ����ɵĵ�ͼ���ƴ��ڣ������µĵ�ͼ����û�б�ռ�þͷ���true������ͷ���false��
	//! \param 		&strOldName �ɵĵ�ͼ���ơ�
	//! \param 		&strNewName �µĵ�ͼ���ơ�
	UGbool Rename(const UGString &strOldName, const UGString &strNewName);
	//========================================================
	//! \brief 		����ָ�����Ƶĵ�ͼ�洢����
	//! \return 	UGMapStorage* ����ɹ��͵�ͼ�洢���󣬷��򷵻�NULL��
	//! \param 		&strName ��ͼ���ơ�
	UGMapStorage* Find(const UGString &strName) const;
	//========================================================
	//! \brief 		����һ��ָ�����Ƶĵ�ͼ�洢����
	//! \return 	UGbool �����ͼ����û�б�ռ�ò��ɹ�������ͼ�洢����ͷ���true������ͷ���false��
	//! \param 		strName ��ͼ���ơ�
	UGbool Add(const UGString &strName);
	
	//========================================================
	//! \brief 		�ѵ�ͼ��Ϣ����δXML�ַ�����
	//! \return 	UGString ���ذ�����ͼ��Ϣ��XML�ַ�����������ɹ��ͷ��ؿ��ַ�����
	//! \param 		nVersion �����ռ�汾��
	UGString ToXML(UGint nVersion = 0)const;
	//========================================================
	//! \brief 		����������ͼ��Ϣ��XML�ַ����������ͼ���ϡ�
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		strXML ������ͼ��Ϣ��XML�ַ�����
	//! \param 		nVersion �����ռ�汾��
	UGbool FromXML(const UGString &strXML, UGint nVersion = 0);

	//========================================================
	//! \brief 		�����޸�ָ����ͼ���Ƶĵ�ͼ�洢����ָ�룬�����ͼ���Ʋ����ھ�����һ����ͼ�洢����
	//! \return 	void
	//! \param 		strName ��ͼ���ƣ�����Ϊ���ַ�����
	//! \param 		pMapStorage ��ͼ�洢����ָ�롣
	void SetAt (const UGString &strName, UGMapStorage* pMapStorage);
	//========================================================
	//! \brief 		�õ�ָ�������ĵ�ͼ���ƺ͵�ͼ�洢����ָ�롣
	//! \return 	UGbool ����ҵ��ͷ���true������ͷ���false��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	//! \param 		strName ���ص�ͼ���ơ�
	//! \param 		pMapStorage ���ص�ͼ�洢����ָ�롣
	UGbool GetAt (UGint nIndex, UGString &strName, UGMapStorage *&pMapStorage);
	//========================================================
	//! \brief 		����ָ�����Ƶĵ�ͼ�洢����
	//! \return 	UGbool ����ҵ��ͷ���true������ͷ���false��
	//! \param 		strName ��ͼ���ơ�
	//! \param 		pMapStorage ���ص�ͼ�洢����ָ�롣
	UGbool Lookup (const UGString &strName, UGMapStorage *&pMapStorage ) const;

	//========================================================
	//! \brief 		�õ���ͼ�洢������Ŀ��
	UGint GetCount()const;
	//========================================================
	//! \brief 		�Ƿ�û�е�ͼ�洢�������û�о�Ϊtrue�������Ϊfalse��
	//! \return 	UGbool
	UGbool IsEmpty()const;

	void AttachWorkspace(UGWorkspace* pWorkspace);
	static UGString GetMapFilePath(const UGString& strWorkspaceName,const UGString& strMapName,UGbool bCreateIfNo = false);
protected:
	//! \brief 		�޸ı�ʶ��
	UGbool m_bModified;
	//! \brief 		��̬��ͼ�汾����ص�������
	static MAPVERSIONPROC m_pMapVersionFunc;

	UGWorkspace* m_pWorkspace;
	
public:
	//! \brief 		��ͼ�洢���󼯺ϡ�
	UGDict<UGString, UGMapStorage*> m_MapStorages;
	//! \brief 		��ͼ���Ƽ��ϡ�
	UGArray<UGString> m_strArrNames;
	UGString m_strSaveWorkspaceName;
	//! \brief 		��ͼ���ſ���Ϣ���������⿪�ţ�
	//! \remarks �ڵ�ͼ��Ϣ�Ĵ洢�У���������ռ�Ϊ�ջ�����湤���ռ������£���ͼ��������Ϣ����Ҫ���£�ֱ�ӱ��漴�ɣ�����ͼ�����ļ�����Ҫ���ݹ����ռ�λ�õı仯����Ӧ�ĵ������������Ӵ˽ӿ��������ڲ�����������⡣����Ĺ���������£��������ʱ�ļ�������ģ�����е�ָ�����湤���ռ����ļ����У��ļ���Ϊ�����ռ���_Maps�����ڲ�����ʱ�ļ����£���ճ����ָ�����湤���ռ��µ��ļ�����
	UGDict<UGString, UGResources*> m_MapDataStorages;

	//! \brief 		��ͼ���ſ���Ϣ���������⿪�ţ�
	UGbool m_bWorkspaceTypeChange;

};

}

#endif // !defined(AFX_UGMAPSTORAGES_H__5F39D6B3_F5CA_48E7_84A0_A1CC4EFA93CD__INCLUDED_)

