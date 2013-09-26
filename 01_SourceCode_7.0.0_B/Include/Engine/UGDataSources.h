// UGDataSources.h: interface for the UGDataSources class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDataSources.h
   **************************************************************************************
    \author   �¹���
    \brief    ����Դָ������࣬ͨ������Դָ��������Դ������һһ��Ӧ��ϵ���й���
			  ����֤����Դ������Ψһ�ԡ�                                                    
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGDATASOURCES_H__70B46E96_726D_4AAD_A846_D57BCD50C9D0__INCLUDED_)
#define AFX_UGDATASOURCES_H__70B46E96_726D_4AAD_A846_D57BCD50C9D0__INCLUDED_

#include "Base/OgdcDict.h"
#include "Engine/UGDataSource.h"

namespace UGC {

typedef void (UGSTDCALL *DatasourcesXMLProc)(UGString* xml);


//##ModelId=48203051033C
class ENGINE_API UGDataSources  
{	
public:
	//##ModelId=48203051033D
	UGDataSources();
	//##ModelId=48203051033E
#ifdef SYMBIAN60
	~UGDataSources();
#else
	virtual ~UGDataSources();
#endif
	

public:
	//========================================================
	//! \brief 		ͨ������Դ������������Դָ�롣
	//! \return 	UGbool ����ҵ��ͷ���true������ͷ���false��
	//! \param 		strAlias ����Դ������
	//! \param 		pResDataSource ��������Դָ�롣
	//##ModelId=48203051034B
	UGbool Lookup (const UGString& strAlias, UGDataSource* &pResDataSource)const;
	//========================================================
	//! \brief 		�õ�����Դ����Ŀ��
	//! \return 	UGint ���û������Դ�ͷ���0��
	//##ModelId=48203051034F
	UGint GetCount()const;
	//========================================================
	//! \brief 		�Ƿ񲻴�������Դ��
	//! \return 	UGbool ���û������Դ�ͷ���true������ͷ���false��
	//##ModelId=482030510351
	UGbool IsEmpty()const;
	//========================================================
	//! \brief 		��ղ��ͷ�����Դָ�롣
	//##ModelId=482030510353
	void RemoveAll();
	//========================================================
	//! \brief 		�����޸�ָ������������Դָ�룬������������ھ�����һ������Դָ�롣
	//! \return 	void
	//! \param 		strAlias ����Դ����������Ϊ���ַ�����
	//! \param 		pDataSource ����Դָ�룬����ΪNULL��
	//##ModelId=48203051035B
	void SetAt(const UGString& strAlias, UGDataSource *pDataSource);	
	//========================================================
	//! \brief 		�õ�ָ������������Դ������ָ�롣
	//! \return 	UGbool ����ҵ��ͷ���true������ͷ���false��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	//! \param 		strAlias ��������Դ������
	//! \param 		pDataSource ��������Դָ�롣
	//##ModelId=48203051035E
	UGbool GetAt(UGint nIndex, UGString& strAlias, UGDataSource *&pDataSource)const;

	//========================================================
	//! \brief 		����ָ������������Դָ�룬���ͷ�����Դָ�롣
	//! \return 	UGbool ����������ھͷ���true������ͷ���false��
	//! \param 		strAlias ����Դ������
	//##ModelId=482030510363
	UGbool ReleaseAt(const UGString& strAlias);
	//========================================================
	//! \brief 		����ָ������λ�õ�����Դָ�룬���ͷ�����Դָ�롣
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	//##ModelId=48203051036B
	UGbool ReleaseAt(UGint nIndex);
	
	//========================================================
	//! \brief 		ͨ������Դ��������������
	//! \return 	UGint ����������ҵ��ͷ�������������ͷ���-1��
	//! \param 		UGString ����Դ������
	//##ModelId=48203051036D
	UGint FindAlias(const UGString& strAlias)const;	
	
	//========================================================
	//! \brief 		ͨ������Դָ���������Դ������
	//! \return 	UGString ����Դ����������ҵ��ͷ�������Դ����������ͷ��ؿ��ַ�����
	//! \param 		pDataSource ����Դָ�룬����ΪNULL��
	//##ModelId=482030510370
	UGString GetAlias(UGDataSource* pDataSource)const;

	//========================================================
	//! \brief 		�õ�ָ������λ�õ�����Դ������
	//! \return 	UGString ����Դ����������ҵ��ͷ�������Դ����������ͷ��ؿ��ַ�����
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	//##ModelId=48203051037A
	UGString GetAliasAt(UGint nIndex)const;
	//========================================================
	//! \brief 		�����޸ı�ʶ���������Լ������ã����Ҷ��������޸ı�ʶ�ĳ�Ա�������á�
	//! \return 	void
	//! \param 		bModified �޸ı�ʶ��
	//##ModelId=48203051037D
	void SetModifiedFlag(UGbool bModified = true);
	//========================================================
	//! \brief 		�ж��Ƿ����޸ģ�������һ��Ա���޸ġ�
	//! \return 	UGbool ������޸ľͷ���true������ͷ���false��
	//##ModelId=48203051037F
	UGbool IsModified()const;
	//========================================================
	//! \brief 		����ָ������������Դָ�룬�����ͷ�����Դָ�롣
	//! \return 	UGDataSource* ��������Դָ�룬����Ƴ����ɹ��ͷ���NULL��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	//##ModelId=482030510381
	UGDataSource* RemoveAt(UGint nIndex);
	//========================================================
	//! \brief 		����һ��ָ������������Դָ�롣
	//! \return 	UGbool ����������ھ;ͷ���false������ͷ���true��
	//! \param 		strAlias ����Դ����������Ϊ���ַ�����
	//! \param 		pDataSource ����Դָ�룬����ΪNULL��
	//##ModelId=48203051038B
	UGbool Insert(const UGString& strAlias, UGDataSource* pDataSource);	
	//========================================================
	//! \brief 		�൱��RemoveAll()��
	//! \return 	void
	//##ModelId=48203051038E
	void Reset();												
	//========================================================
	//! \brief 	������	
	//! \return 	UGbool
	//! \param 		strAlias
	//! \param 		strNewAlias
	//##ModelId=48203051038F
	UGbool Rename(const UGString& strAlias, const UGString& strNewAlias);	
	//========================================================
	//! \brief 		����Դ�����Ƿ���ڡ�
	//! \return 	UGbool ����������ھͷ���true������ͷ���false��
	//! \param 		strAlias ����Դ������
	//##ModelId=482030510399
	UGbool IsAliasExisted(const UGString& strAlias)const;					
		
	//========================================================
	//! \brief 		������������Դ��Ϣ��XML�ַ�������������Դָ�뼯�ϣ������ӻ������Դ��
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		strXML ��������Դ��Ϣ��XML�ַ�����
	//! \param 		strWorkspaceName �����ռ�ȫ·������
	//! \param 		nVersion �����ռ�汾�š�
	//##ModelId=48203051039C
	UGbool FromXML(const UGString &strXML, const UGString &strWorkspaceName, UGint nVersion = 0,const UGString& strPWD = (_U("")));//!\modified by macx 2008.8.4 ֧�ֹ����ռ�����
	//========================================================
	//! \brief 		������Դ������Ϣ����δXML�ַ�����
	//! \return 	UGString ���ذ�������Դ��Ϣ��XML�ַ�����������ɹ��ͷ��ؿ��ַ�����
	//! \param 		strWorkspaceName �����ռ�ȫ·������
	//! \param 		nVersion �����ռ�汾�š�
	//##ModelId=4820305103A0
	UGString ToXML(const UGString &strWorkspaceName, UGint nVersion = 0, const UGString& strPWD = (_U("")))const;//!\modified by macx 2008.8.4 ֧�ֹ����ռ�����

public:
	//! \brief 		�Ƿ��޸ı�ʶ��
	//##ModelId=4820305103A4
	UGbool m_bModified;		
	//! \brief 		����Դ���ϡ�
	//##ModelId=4820305103A9
	UGDict<UGString,UGDataSource*> m_Datasources;	
	//! \brief 		����Դ�������顣
	//##ModelId=4820305103AA
	UGArray<UGString> m_strArrNames;	

	// ��Ҫ���ⲿ��һ�����һ������汾�Ĺ����ռ�Ĺ��ߣ�����Ϊ����С���
	// �����κε�sdx�����´򿪹����ռ�ʱ��ʧ������Դ��Ϣ���ٱ����ʱ������Դ�ڵ��û�е���
	// ����ͨ���������ص��ڶ�ȡ��ʱ������Դxml���ݵ����汣�棬�洢��ʱ��xml������
	// д���ļ����棬��ugc��������û��ʹ�ã����ǲ�Ҫ���ɾ��
	// add by gouyu 2012-9-18
	static DatasourcesXMLProc g_DatasourcesToXML;
	static DatasourcesXMLProc g_DatasourcesFromXML;
};

}

#endif // !defined(AFX_UGDATASOURCES_H__70B46E96_726D_4AAD_A846_D57BCD50C9D0__INCLUDED_)

