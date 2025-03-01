// UGResources.h: interface for the UGResources class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGResources.h
   **************************************************************************************
    \author   陈国雄
    \brief    点、线、面等符号库资源管理类。                                          
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                          <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  陈国雄    初始化版本.                                       <br>
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
	//! \brief 		关闭资源库，清空各种符号库。
	void Close();
	//========================================================
	//! \brief 		关闭资源库，并导入默认的符号库。
	void Reset();
	//========================================================
	//! \brief 		设置修改标识。
	//! \return 	void
	//! \param 		bModified 修改标识。
	void SetModifiedFlag(UGbool bModified = true);
	//========================================================
	//! \brief 		判断是否有修改。
	//! \return 	UGbool 如果有修改就返回true，否则就返回false。
	UGbool IsModified()const;

	//========================================================
	//! \brief 		解析包含符号库文件路径信息的XML字符串，打开符号库。
	//! \return 	UGbool 如果成功就返回true，否则就返回false。
	//! \param 		strXML 包含符号库文件路径信息的XML字符串。
	//! \param 		strWorkspaceName 工作空间全路径名。
	//! \param 		nVersion 工作空间版本号。
	UGbool FromXML(const UGString &strXML, const UGString &strWorkspaceName, UGint nVersion = 0);
	//========================================================
	//! \brief 		把符号库文件路径信息保存为XML字符串。
	//! \return 	UGString 返回包含符号库文件路径信息的XML字符串，如果不成功就返回空字符串。
	//! \param 		strWorkspaceName 工作空间全路径名。
	//! \param 		nVersion 工作空间版本号。
	UGString ToXML(const UGString &strWorkspaceName, UGint nVersion = 0)const;
	
	//========================================================
	//! \brief 		把符号库保存为内存块。
	//! \return 	UGbool
	//! \param 		stream
	//! \param 		nVersion 工作空间版本号。
	UGbool Load(UGStream& stream, UGint nVersion = 0);	
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;
	
	//========================================================
	//! \brief 		得到点状符号库。
	UGMarkerSymbolLib* GetMarkerSymbolLib() const;	
	//========================================================
	//! \brief 		得到线状符号库。
	UGLineSymbolLib* GetLineSymbolLib() const;
	//========================================================
	//! \brief 		得到面状符号库。
	UGFillSymbolLib* GetFillSymbolLib() const;

	//! \brief 		设置资源符号类型，工作空间级的还是地图级的符号库
	//! \param 	nType 资源符号类型[in]
	void SetResourcesType(ResourcesType nType);
	//! \brief 		获取资源符号类型
	//! \return 	ResourcesType 获取资源符号类型
	ResourcesType GetResourcesType();

#ifdef _UGUNICODE
	void SetExternalStorage(UGCompactFile *pStorage) {m_pExternalStorage = pStorage;}
#endif

	//! \brief 	保存符号库三维缓存文件到流
	//! \param 	stream 文件流[in/out]（必须用文件流，内存流数据大时会失败）
	void SaveSymbolLibCache( UGStream& stream ) const;
	
	//! \brief 	从流中读取符号库三维缓存文件
	//! \param 	stream 文件流[in/out]
	void LoadSymbolLibCache( UGStream& stream );

protected:
	//! \brief 		修改标识。
	UGbool m_bModified;
	//! \brief 		点状符号库。
	UGMarkerSymbolLib *m_pMarkerSymLib;
	//! \brief 		线状符号库。
	UGLineSymbolLib *m_pLineSymLib;
	//! \brief 		面状符号库。
	UGFillSymbolLib *m_pFillSymLib;
	ResourcesType m_nType;
#ifdef _UGUNICODE
	UGCompactFile *m_pExternalStorage;
#endif

};

}

#endif // !defined(AFX_UGRESOURCES_H__EBC0EC27_5D78_474D_AFDD_177B32BBB357__INCLUDED_)

