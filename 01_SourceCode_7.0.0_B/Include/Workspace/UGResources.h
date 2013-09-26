// UGResources.h: interface for the UGResources class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGResources.h
   **************************************************************************************
    \author   �¹���
    \brief    �㡢�ߡ���ȷ��ſ���Դ�����ࡣ                                          
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                          <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGRESOURCES_H__EBC0EC27_5D78_474D_AFDD_177B32BBB357__INCLUDED_)
#define AFX_UGRESOURCES_H__EBC0EC27_5D78_474D_AFDD_177B32BBB357__INCLUDED_

#include "SymbolMarker/UGMarkerSymbolLib.h"
#include "SymbolLine/UGLineSymbolLib.h"
#include "SymbolFill/UGFillSymbolLib.h"

namespace UGC {

class UGCompactFile;
class WORKSPACE_API UGResources  
{
public:
	enum ResourcesType
	{
		WorkspaceResources = 0,
		MapResources = 1
	};
public:
	UGResources();
#ifdef SYMBIAN60
	~UGResources();
#else
	virtual ~UGResources();
#endif

public:
	//========================================================
	//! \brief 		�ر���Դ�⣬��ո��ַ��ſ⡣
	void Close();
	//========================================================
	//! \brief 		�ر���Դ�⣬������Ĭ�ϵķ��ſ⡣
	void Reset();
	//========================================================
	//! \brief 		�����޸ı�ʶ��
	//! \return 	void
	//! \param 		bModified �޸ı�ʶ��
	void SetModifiedFlag(UGbool bModified = true);
	//========================================================
	//! \brief 		�ж��Ƿ����޸ġ�
	//! \return 	UGbool ������޸ľͷ���true������ͷ���false��
	UGbool IsModified()const;

	//========================================================
	//! \brief 		�����������ſ��ļ�·����Ϣ��XML�ַ������򿪷��ſ⡣
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		strXML �������ſ��ļ�·����Ϣ��XML�ַ�����
	//! \param 		strWorkspaceName �����ռ�ȫ·������
	//! \param 		nVersion �����ռ�汾�š�
	UGbool FromXML(const UGString &strXML, const UGString &strWorkspaceName, UGint nVersion = 0);
	//========================================================
	//! \brief 		�ѷ��ſ��ļ�·����Ϣ����ΪXML�ַ�����
	//! \return 	UGString ���ذ������ſ��ļ�·����Ϣ��XML�ַ�����������ɹ��ͷ��ؿ��ַ�����
	//! \param 		strWorkspaceName �����ռ�ȫ·������
	//! \param 		nVersion �����ռ�汾�š�
	UGString ToXML(const UGString &strWorkspaceName, UGint nVersion = 0)const;
	
	//========================================================
	//! \brief 		�ѷ��ſⱣ��Ϊ�ڴ�顣
	//! \return 	UGbool
	//! \param 		stream
	//! \param 		nVersion �����ռ�汾�š�
	UGbool Load(UGStream& stream, UGint nVersion = 0);	
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;
	
	//========================================================
	//! \brief 		�õ���״���ſ⡣
	UGMarkerSymbolLib* GetMarkerSymbolLib() const;	
	//========================================================
	//! \brief 		�õ���״���ſ⡣
	UGLineSymbolLib* GetLineSymbolLib() const;
	//========================================================
	//! \brief 		�õ���״���ſ⡣
	UGFillSymbolLib* GetFillSymbolLib() const;

	//! \brief 		������Դ�������ͣ������ռ伶�Ļ��ǵ�ͼ���ķ��ſ�
	//! \param 	nType ��Դ��������[in]
	void SetResourcesType(ResourcesType nType);
	//! \brief 		��ȡ��Դ��������
	//! \return 	ResourcesType ��ȡ��Դ��������
	ResourcesType GetResourcesType();

#ifdef _UGUNICODE
	void SetExternalStorage(UGCompactFile *pStorage) {m_pExternalStorage = pStorage;}
#endif

	//! \brief 	������ſ���ά�����ļ�����
	//! \param 	stream �ļ���[in/out]���������ļ������ڴ������ݴ�ʱ��ʧ�ܣ�
	void SaveSymbolLibCache( UGStream& stream ) const;
	
	//! \brief 	�����ж�ȡ���ſ���ά�����ļ�
	//! \param 	stream �ļ���[in/out]
	void LoadSymbolLibCache( UGStream& stream );

protected:
	//! \brief 		�޸ı�ʶ��
	UGbool m_bModified;
	//! \brief 		��״���ſ⡣
	UGMarkerSymbolLib *m_pMarkerSymLib;
	//! \brief 		��״���ſ⡣
	UGLineSymbolLib *m_pLineSymLib;
	//! \brief 		��״���ſ⡣
	UGFillSymbolLib *m_pFillSymLib;
	ResourcesType m_nType;
#ifdef _UGUNICODE
	UGCompactFile *m_pExternalStorage;
#endif

};

}

#endif // !defined(AFX_UGRESOURCES_H__EBC0EC27_5D78_474D_AFDD_177B32BBB357__INCLUDED_)

