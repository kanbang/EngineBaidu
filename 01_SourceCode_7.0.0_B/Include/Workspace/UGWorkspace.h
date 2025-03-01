// UGWorkspace.h: interface for the UGWorkspace class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGWorkspace.h
   **************************************************************************************
    \author   陈国雄
    \brief    工作空间管理类，用来管理数据源集合，地图集合，布局集合，三维场景集合，
			  资源集合等工作、显示环境信息。                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                          <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGWORKSPACE_H__A39D6DBA_DE0F_413A_B80C_FB5E2AFBC138__INCLUDED_)
#define AFX_UGWORKSPACE_H__A39D6DBA_DE0F_413A_B80C_FB5E2AFBC138__INCLUDED_

#include "Workspace/UGDataSourceStorages.h"
#include "Engine/UGDataSources.h"
#include "Workspace/UGResources.h"
#include "Workspace/UGLayoutStorages.h"
#include "Workspace/UGMapStorages.h"
#include "Workspace/UGSceneStorages.h"
#include "Engine/UGDataSourceManager.h"
#include "Stream/UGFileStream.h"
#include "Stream/ugdefs.h"
#include "Toolkit/UGThread.h"
#include "UGWorkspaceConnection.h"
#include "Toolkit/UGMarkup.h"
namespace UGC {	
/*
	//! \brief 加密工作空间,added by macx 2008.8.4 。
	//! \param strDes 返回加密后的字符串，[out]
	//! \param strWorkspaceName 工作空间名[in]。
	//! \param key=工作空间密码，加解密的key 默认为空[in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	static UGbool EncryptString(UGString& strDes,const UGString& strSrc,const UGString& strPWD = (""));
	//! \brief 解密工作空间,added by macx 2008.8.4 。
	//! \param strDes 返回解密后的字符串，[out]
	//! \param strWorkspaceName 工作空间名[in]。
	//! \param strKey工作空间密码，加解密的key 默认为空[in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	static UGbool DecryptString(UGString& strDes,const UGString& strSrc,const UGString& strPWD = (""));	
*/
class UGCompactFile;
class WORKSPACE_API UGWorkspace  
{
public: 
	enum UGWorkspaceType
	{
		//! \brief 	没有工作空间
		WS_Version_NO       = 1, 
		//! \brief 	3.0SXW工作空间
		//	WS_Version_SXW30    = 2, 
		//! \brief 	3.0SMW工作空间
		//	WS_Version_SMW30    = 3, 
		//! \brief 	SXW工作空间，仅支持SFC系列
		WS_Version_SXW		= 4, 
		//! \brief 	SUW或SMW工作空间，仅支持SFC系列
		WS_Version_SUW		= 5, 
		//! \brief 	Oracle工作空间
		WS_Version_Oracle   = 6, 
		//! \brief 	Sql工作空间 
		WS_Version_Sql		= 7	,
		//! \brief 	SXWU工作空间,仅支持U系列,组件使用！
		WS_Version_SXWU		= 8, 
		//! \brief 	SUWU或SMWU工作空间，,仅支持U系列，组件使用！
		WS_Version_SUWU		= 9,

		WS_Version_PgSql    = 10,

		WS_Version_KingBase = 11,

		WS_Version_DM = 12,

		WS_Version_Informix = 13,

		WS_Version_DB2 = 14
	};

public:
	UGWorkspace();
#ifdef SYMBIAN60
	~UGWorkspace();
#else
	virtual ~UGWorkspace();
#endif

public:
	//========================================================
	//! \brief 		打开工作空间。
	//! \return 	UGbool 如果打开成功就返回true，否则就返回false。
	//! \param 		strWorkspaceName 全路径工作空间文件名。
	//! \param 		strPassword 是否加密，输入密码，密码不能为空，为空就表示没有密码
	UGbool Open(const UGString& strWorkspaceName, const UGString& strPassword = (_U(""))); 
	//========================================================
	//! \brief 		打开工作空间。
	//! \return 	UGbool 如果打开成功就返回true，否则就返回false。
	//! \param 		workspaceConnection 工作空间连接信息
	UGbool Open(const UGWorkspaceConnection& workspaceConnection); 
	//========================================================
	//! \brief 		关闭工作空间。	
	void Close();
	//========================================================
	//! \brief 		empty the current workspace
	void Reset();	

	//========================================================
	//! \brief 		返回工作空间的名称，其实是全路径文件名。
	UGString GetName()const;
	//========================================================
	//! \brief 		得到SUW工作空间密码，要验证。
	UGString GetPassword()const;
	//========================================================
	//! \brief 		修改工作空间密码。
	void ChangePassword(const UGString& strNewPassword);
	//========================================================
	//! \brief 		得到当前工作空间版本。
	UGuint GetVersion();

	//========================================================
	//! \brief 		是否在这个实例构造之前，同一个进程中有重复的Workspace实例，我们不推荐在一个进程中有两个Workspace。
	UGbool IsDuplicatedInProgress()const;	
	//========================================================
	//! \brief 		是否修改过，包括任一成员的修改，您可以通过这个函数来确定是否需要提示用户存盘
	UGbool IsModified()const;
	//========================================================
	//! \brief		设置是否修改标志,默认参数修改为true
	void SetModifiedFlag(UGbool bModified = true);	
	
	//========================================================
	//! \brief 		打开数据源
	//! \return 	UGDataSource* 如果打开成功就返回数据源指针，否则就返回NULL。
	//! \param 		strDataSourceName 数据源连接字符串
		// 对于文件引擎，本参数为数据源文件名
		// 对于ADO数据引擎，此参数为服务器信息，格式为："provider=MyProvider;server=MyServerName;database=MyDatabase"
		// 其中MyProvider为OLEDB Provider类型，比如SQLOLEDB为SQL Server；MyServerName为服务器计算机名，MyDatabase为ArcSDE数据库名。
		// 对于SDE数据引擎，此参数为服务器信息，格式为：
		// "server=MyServerName;instance=MyInstanceName;database=MyDatabase"
		// 或"server=MyServerName;instance=MyInstanceName;"。
		// 其中MyServerName为服务器计算机名，MyInstanceName为服务器端实例名，MyDatabase为ArcSDE数据库名，若服务器端底层为Oracle或SQL Server则不需要提供数据库名信息，采用第二种格式。 
	//! \param 		strAlias 别名，打开之后用这个名字来查找访问指定的数据源。
	//! \param 		nEngineType 数据引擎类型。
	//! \param 		bReadOnly 是否用只读方式打开。
	UGDataSource * OpenDataSource(const UGString &strDataSourceName, const UGString &strAlias,	UGEngineType nEngineType, UGbool bReadOnly = true);
	
	//! \brief 		打开数据源
	//! \param 		conn 数据连接
	//! \return 	UGDataSource* 如果打开成功就返回数据源指针，否则就返回NULL。
	UGDataSource * OpenDataSource(const UGDsConnection &conn);
	//========================================================
	//! \brief 		create an empty workspace without template
	//! \return 	UGbool 如果创建成功就返回数据源指针，否则就返回NULL。
	//! \param 		strWorkspaceName 工作空间文件名，带路径
	//! \param 		bFailIfExists 如果文件存在，是否创建失败
	//! \param 		strPassword 是否加密，输入密码，密码不能为空，为空就表示没有密码
	UGbool CreateDefault(const UGString &strWorkspaceName, UGbool bFailIfExists = true, const UGString& strPassword = (_U("")));							
	
	//========================================================
	//! \brief 		create a workspace
	//! \return 	UGbool 如果创建成功就返回数据源指针，否则就返回NULL。
	//! \param 		strWorkspaceName 工作空间文件名，带路径
	//! \param 		strTemplateFileName 模版文件，目前用的少	
	//! \param 		bFailIfExists 如果文件存在，是否创建失败
	//! \param 		strPassword 是否加密，输入密码，密码不能为空，为空就表示没有密码,如果使用模版文件，这个密码要求输入的是模板文件的密码。
	UGbool Create(const UGString &strWorkspaceName, const UGString &strTemplateFileName = (_U("")), UGbool bFailIfExists = true,	const UGString& strPassword = (_U("")));	//========================================================
	//! \brief 		save workspace to a file specified by m_strWorkspaceName member varible
	UGbool Save();		
	
	//========================================================
	//! \brief 		另存工作空间.
	//! \return 	UGbool 如果保存成功就返回true，否则就返回false。
	//! \param 		strWorkspaceName 工作空间文件名，带路径
	//! \param 		bFailIfExists如果文件存在，是否创建失败
	//! \param 		bIsXMLFormat 是否把工作空间存成为XML类型,默认不为XML。
	//! \param 		strNewPassword 允许修改密码,输入新的密码。
	//! \param 		nVersion 版本
	UGbool SaveAs(const UGString& strWorkspaceName,	UGbool bFailIfExists = true,
		UGbool bIsXMLFormat = false,UGint nVersion = 0,const UGString& strNewPassword = (_U("")));
	//========================================================
	//! \brief 		另存工作空间.
	//! \return 	UGbool 如果保存成功就返回true，否则就返回false。
	//! \param 		workspaceConnection 工作空间连接参数
	UGbool SaveAs(const UGWorkspaceConnection& workspaceConnection);

	//========================================================
	//! \brief 		得到工作空间类型，参考枚举UGWorkspaceType.
	UGint GetType()const;

	/*!
		\pref 获得数据库版本工作空间的信息
	 	\param strConn    数据库连接字符串,例如:
				"Provider = SQLOLEDB;Driver = SQL Server;SERVER = liwenlong;Database = test;"
	    \param strPwd     用户名密码字符串,例如:
				"UID =SA;PWD = SA"
		\param arrWorkSpace      返回工作空间信息；
		\remarks 只有数据库版本的工作空间才可以
	*/
	UGbool GetInfo(const UGString& strConn, const UGString& strPwd, UGArray<UGString>& arrWorkSpace);

	void SetDescription(const UGString& strDescription);
	UGString GetDescription()const;
	
	void SetCaption(const UGString& strCaption);
	UGString GetCaption()const;

	UGDataSource* GetDataSource(const UGString& strAlias);
	UGDataSource* GetDataSource(UGint nIndex);

	//! \brief 删除工作空间
	UGbool DeleteWorkspace(const UGWorkspaceConnection& workspaceConnection);

	//! \brief 修改工作空间密码
	//! \param 	 strOldPassworld 工作空间旧密码
	//! \param 	 strNewPassworld 工作空间新密码
	//! \return  密码设置是否成功 
	//! \remarks 设置密码时不区分大小写
	UGbool ChangePassword(const UGString& strOldPassworld ,const UGString& strNewPassworld );

	//! \brief 删除目录
	static UGbool RemoveDir(const UGString& strDir);
	static UGbool CopyWorkspaceFile(const UGString& strExistedFileName, const UGString& strNewFileName, UGbool bFailIfExists);

	UGbool GetLastUpdateTime(UGTime &updateTime);

protected:
	UGbool OpenSMW(const UGString& strWorkspaceName, UGbool bConnectDataSource,const UGString& strPWD = (_U("")));
	UGbool OpenSXW(const UGString& strWorkspaceName, UGbool bConnectDataSource,const UGString& strPWD = (_U("")));
	UGbool Open50SMW(UGStream& stream, UGbool bConnectDataSource,const UGString& strPWD = (_U("")));
	//UGbool OpenSUW(const UGString& strWorkspaceName, UGbool bConnectDataSource);

	UGbool SaveAsSUW(const UGString& strWorkspaceName, UGint nVersion = 0);
	//!\brief added by macx 添加密码UGString参数
	UGbool SaveAsSXW(const UGString& strWorkspaceName, UGint nVersion = 0,const UGString& strPWD = (_U("")));
	UGbool SaveAsSMW(const UGString& strWorkspaceName, UGint nVersion = 0,const UGString& strPWD = (_U("")));
	UGbool SaveAs50SMW(const UGString& strWorkspaceName, UGint nVersion = 0,const UGString& strPWD = (_U("")));

	UGbool LoadInfo();			// 从SM_WORKSPACE_INFO stream中读入Info信息，里面包括SUW文件版本号和描述信息
	UGbool SaveInfo();			// 保存SM_WORKSPACE_INFO，参见LoadInfo

	// 调整XML文档的段落结构，使得XML文档层次分明，
	// strFileName 是输入的XML文档的全路径
	UGbool AdjustXMLFile(const UGString& strFileName);

	// 在 函数AdjustXmlFile()中用到的辅助函数，用斜杠来判断当前标签的应有的位置，需要调整多少个Tab缩进
	//  </#######/> sprit 斜杠“/”的意思，
	// bHasSprit1, 当前标签是否有第一个斜杠		//bHasSprit2, 当前标签是否有第二个斜杠
	// bHasLastSprit1, 上一个标签是否有第一个斜杠	//bHasLastSprit2, 上一个标签是否有第二个斜杠
	UGint GetTabAdjust(UGbool bHasSprit1, UGbool bHasSprit2, UGbool bHasLastSprit1, UGbool bHasLastSprit2);
	
	// 在函数AdjustXmlFile()中用到的辅助函数，用来读取file，给pbFileContent分配空间和填充内容
	// 返回从file中读取的字节的数目
	UGint ReadContent(UGFileStream &file, UGbyte *&pbFileContent);

	/* \pref 包装SXW工作空间成BYTE
	 * \param strPath SXW工作空间的路径
	   \param nByteSize 返回长度
	   \param pByte 包装后的串
	   \return 成功返回TRUE
	   \remarks :
				包装工作空间表识
				{
					SXW  = 1，
					LYT  = 2，
					SYM  = 3，
					LSL  = 4，
					BRU  = 5，
				}
		
	 */
	UGbool BoxingSXW(const UGString& strPath, UGuint& dwByteSize, UGbyte *&pByte,UGint nVersion);

private:
	UGbool LoadXMLInfo(UGMarkup& markup,UGString strWorkspaceName);

	// 重构代码，提取把工作空间写入到内存流的方法
	// 调用此方法时，如果有三模模型或其他外挂文件会直接写入相应的文件，因此需要提交准备写入环境．
	// 如Unicode版本工作空间需要先打开紧凑文件．
	UGbool SaveToStream(UGStream &mem, const UGString& strWorkspaceName, UGint nVersion);
	UGbool LoadFromStream(UGStream &mem, const UGString& strWorkspaceName, UGint nVersion);


public:
	//! \brief 数据源集合。当Open函数的bConnectDataSource参数为TRUE(默认)时，读入的数据放在这里
	UGDataSources m_DataSources;

	//! \brief 数据源Storage集合。当Open函数的bConnectDataSource参数为FALSE时，读入的数据放在这里
	UGDataSourceStorages m_DataSourceStorages;	
	UGbool m_bConnectDataSource;

	//! \brief 地图集合
	UGMapStorages m_MapStorages;
	//! \brief 资源集合
	UGResources m_Resources;
	//! \brief 布局集合
	UGLayoutStorages m_LytStorages;
	//! \brief 三维场景集合
	UGSceneStorages m_SceneStorages;
	//! \brief 风格对照表，与DGN，TAB、DXF等交换数据的时候需要
	//	UGString m_strStyleMappingTable;
	//! \brief DGN颜色对照表，与DGN交换数据的时候需要
	//	UGString m_strDgnColorMappingTable;
	//	UGList<UGWorkspace**> m_ConnectedWorkspacePtrList;
	//added by xielin 2007-09-24 通过UGWorkspaceConnection打开的工作空间，用一个变量
	//! \brief 来保存打开的参数，那么保存的时候就可以通过参数来判断是否保存
	UGWorkspaceConnection m_WorkspaceConnection;

	//! \brief 加密工作空间,added by macx 2008.8.4 。
	//! \param strDes 返回加密后的字符串，[out]
	//! \param strWorkspaceName 工作空间名[in]。
	//! \param key=工作空间密码，加解密的key 默认为空[in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	static UGbool EncryptString(UGString& strDes,const UGString& strSrc,const UGString& strPWD = (_U("")));
	//! \brief 解密工作空间,added by macx 2008.8.4 。
	//! \param strDes 返回解密后的字符串，[out]
	//! \param strWorkspaceName 工作空间名[in]。
	//! \param strKey 工作空间密码，加解密的key 默认为空[in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	static UGbool DecryptString(UGString& strDes,const UGString& strSrc,const UGString& strPWD = (_U("")));	

	//! \brief 设置工作空间路径名称，内部使用，不对外开放！
	void SetName(UGString strName);
	void SetType(UGint nType);

protected:
	// 打开和保存工作空间固定下来的，唯一
	UGString m_strCaption;
	UGint m_nVersion;

	UGString m_strName;					// the file name associated with the current workspace
	UGString m_strDescription;			// 工作空间的描述
	UGString m_strPassword;				// 工作空间密码
//	UGFileStream m_WorkspaceFile;		// 工作空间指向的复合文档对象，CSmCompoundFile定义再SmALib20
	static UGbool m_bDuplicatedInProgress;		// 是否在这个实例构造之前，同一个进程中有重复的Workspace实例，我们不推荐在一个进程中有两个Workspace，本变量在构造函数中赋值，您可以使用IsDuplicatedInProgress()函数只读访问该变量的值。
	UGString m_strLastUpdateTime;		//最后更新时间
	
	// 用来判断数据库版本工作空间是需要新建，还是覆盖原来的工作空间。如果内存中的版本与数据库
	// 中一致，覆盖！否则，新加！
//	UGint m_nDBWsVersion;
	UGbool m_bModified;					// 是否修改，用于判断是否存盘
	UGuint m_unXMLBlockSize;
	UGint m_nType;
//	UGString m_strSavePath;				// 为了在保存SUW工作空间时，存储和数据源的相对路径区分开。
	UGMutex m_mutex;
	//!brief 保存SFC布局，在保存回去时不丢失
	UGbyte* m_pLytBuffer;
	UGint m_nLytSize;
	UGString m_strLytInfo;

#ifdef _UGUNICODE
	UGCompactFile *m_pExternalStorage;
#endif
};	

}

#endif // !defined(AFX_UGWORKSPACE_H__A39D6DBA_DE0F_413A_B80C_FB5E2AFBC138__INCLUDED_)

