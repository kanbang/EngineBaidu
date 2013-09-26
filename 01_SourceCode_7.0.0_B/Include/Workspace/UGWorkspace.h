// UGWorkspace.h: interface for the UGWorkspace class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGWorkspace.h
   **************************************************************************************
    \author   �¹���
    \brief    �����ռ�����࣬������������Դ���ϣ���ͼ���ϣ����ּ��ϣ���ά�������ϣ�
			  ��Դ���ϵȹ�������ʾ������Ϣ��                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                          <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
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
	//! \brief ���ܹ����ռ�,added by macx 2008.8.4 ��
	//! \param strDes ���ؼ��ܺ���ַ�����[out]
	//! \param strWorkspaceName �����ռ���[in]��
	//! \param key=�����ռ����룬�ӽ��ܵ�key Ĭ��Ϊ��[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static UGbool EncryptString(UGString& strDes,const UGString& strSrc,const UGString& strPWD = (""));
	//! \brief ���ܹ����ռ�,added by macx 2008.8.4 ��
	//! \param strDes ���ؽ��ܺ���ַ�����[out]
	//! \param strWorkspaceName �����ռ���[in]��
	//! \param strKey�����ռ����룬�ӽ��ܵ�key Ĭ��Ϊ��[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static UGbool DecryptString(UGString& strDes,const UGString& strSrc,const UGString& strPWD = (""));	
*/
class UGCompactFile;
class WORKSPACE_API UGWorkspace  
{
public: 
	enum UGWorkspaceType
	{
		//! \brief 	û�й����ռ�
		WS_Version_NO       = 1, 
		//! \brief 	3.0SXW�����ռ�
		//	WS_Version_SXW30    = 2, 
		//! \brief 	3.0SMW�����ռ�
		//	WS_Version_SMW30    = 3, 
		//! \brief 	SXW�����ռ䣬��֧��SFCϵ��
		WS_Version_SXW		= 4, 
		//! \brief 	SUW��SMW�����ռ䣬��֧��SFCϵ��
		WS_Version_SUW		= 5, 
		//! \brief 	Oracle�����ռ�
		WS_Version_Oracle   = 6, 
		//! \brief 	Sql�����ռ� 
		WS_Version_Sql		= 7	,
		//! \brief 	SXWU�����ռ�,��֧��Uϵ��,���ʹ�ã�
		WS_Version_SXWU		= 8, 
		//! \brief 	SUWU��SMWU�����ռ䣬,��֧��Uϵ�У����ʹ�ã�
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
	//! \brief 		�򿪹����ռ䡣
	//! \return 	UGbool ����򿪳ɹ��ͷ���true������ͷ���false��
	//! \param 		strWorkspaceName ȫ·�������ռ��ļ�����
	//! \param 		strPassword �Ƿ���ܣ��������룬���벻��Ϊ�գ�Ϊ�վͱ�ʾû������
	UGbool Open(const UGString& strWorkspaceName, const UGString& strPassword = (_U(""))); 
	//========================================================
	//! \brief 		�򿪹����ռ䡣
	//! \return 	UGbool ����򿪳ɹ��ͷ���true������ͷ���false��
	//! \param 		workspaceConnection �����ռ�������Ϣ
	UGbool Open(const UGWorkspaceConnection& workspaceConnection); 
	//========================================================
	//! \brief 		�رչ����ռ䡣	
	void Close();
	//========================================================
	//! \brief 		empty the current workspace
	void Reset();	

	//========================================================
	//! \brief 		���ع����ռ�����ƣ���ʵ��ȫ·���ļ�����
	UGString GetName()const;
	//========================================================
	//! \brief 		�õ�SUW�����ռ����룬Ҫ��֤��
	UGString GetPassword()const;
	//========================================================
	//! \brief 		�޸Ĺ����ռ����롣
	void ChangePassword(const UGString& strNewPassword);
	//========================================================
	//! \brief 		�õ���ǰ�����ռ�汾��
	UGuint GetVersion();

	//========================================================
	//! \brief 		�Ƿ������ʵ������֮ǰ��ͬһ�����������ظ���Workspaceʵ�������ǲ��Ƽ���һ��������������Workspace��
	UGbool IsDuplicatedInProgress()const;	
	//========================================================
	//! \brief 		�Ƿ��޸Ĺ���������һ��Ա���޸ģ�������ͨ�����������ȷ���Ƿ���Ҫ��ʾ�û�����
	UGbool IsModified()const;
	//========================================================
	//! \brief		�����Ƿ��޸ı�־,Ĭ�ϲ����޸�Ϊtrue
	void SetModifiedFlag(UGbool bModified = true);	
	
	//========================================================
	//! \brief 		������Դ
	//! \return 	UGDataSource* ����򿪳ɹ��ͷ�������Դָ�룬����ͷ���NULL��
	//! \param 		strDataSourceName ����Դ�����ַ���
		// �����ļ����棬������Ϊ����Դ�ļ���
		// ����ADO�������棬�˲���Ϊ��������Ϣ����ʽΪ��"provider=MyProvider;server=MyServerName;database=MyDatabase"
		// ����MyProviderΪOLEDB Provider���ͣ�����SQLOLEDBΪSQL Server��MyServerNameΪ���������������MyDatabaseΪArcSDE���ݿ�����
		// ����SDE�������棬�˲���Ϊ��������Ϣ����ʽΪ��
		// "server=MyServerName;instance=MyInstanceName;database=MyDatabase"
		// ��"server=MyServerName;instance=MyInstanceName;"��
		// ����MyServerNameΪ���������������MyInstanceNameΪ��������ʵ������MyDatabaseΪArcSDE���ݿ��������������˵ײ�ΪOracle��SQL Server����Ҫ�ṩ���ݿ�����Ϣ�����õڶ��ָ�ʽ�� 
	//! \param 		strAlias ��������֮����������������ҷ���ָ��������Դ��
	//! \param 		nEngineType �����������͡�
	//! \param 		bReadOnly �Ƿ���ֻ����ʽ�򿪡�
	UGDataSource * OpenDataSource(const UGString &strDataSourceName, const UGString &strAlias,	UGEngineType nEngineType, UGbool bReadOnly = true);
	
	//! \brief 		������Դ
	//! \param 		conn ��������
	//! \return 	UGDataSource* ����򿪳ɹ��ͷ�������Դָ�룬����ͷ���NULL��
	UGDataSource * OpenDataSource(const UGDsConnection &conn);
	//========================================================
	//! \brief 		create an empty workspace without template
	//! \return 	UGbool ��������ɹ��ͷ�������Դָ�룬����ͷ���NULL��
	//! \param 		strWorkspaceName �����ռ��ļ�������·��
	//! \param 		bFailIfExists ����ļ����ڣ��Ƿ񴴽�ʧ��
	//! \param 		strPassword �Ƿ���ܣ��������룬���벻��Ϊ�գ�Ϊ�վͱ�ʾû������
	UGbool CreateDefault(const UGString &strWorkspaceName, UGbool bFailIfExists = true, const UGString& strPassword = (_U("")));							
	
	//========================================================
	//! \brief 		create a workspace
	//! \return 	UGbool ��������ɹ��ͷ�������Դָ�룬����ͷ���NULL��
	//! \param 		strWorkspaceName �����ռ��ļ�������·��
	//! \param 		strTemplateFileName ģ���ļ���Ŀǰ�õ���	
	//! \param 		bFailIfExists ����ļ����ڣ��Ƿ񴴽�ʧ��
	//! \param 		strPassword �Ƿ���ܣ��������룬���벻��Ϊ�գ�Ϊ�վͱ�ʾû������,���ʹ��ģ���ļ����������Ҫ���������ģ���ļ������롣
	UGbool Create(const UGString &strWorkspaceName, const UGString &strTemplateFileName = (_U("")), UGbool bFailIfExists = true,	const UGString& strPassword = (_U("")));	//========================================================
	//! \brief 		save workspace to a file specified by m_strWorkspaceName member varible
	UGbool Save();		
	
	//========================================================
	//! \brief 		��湤���ռ�.
	//! \return 	UGbool �������ɹ��ͷ���true������ͷ���false��
	//! \param 		strWorkspaceName �����ռ��ļ�������·��
	//! \param 		bFailIfExists����ļ����ڣ��Ƿ񴴽�ʧ��
	//! \param 		bIsXMLFormat �Ƿ�ѹ����ռ���ΪXML����,Ĭ�ϲ�ΪXML��
	//! \param 		strNewPassword �����޸�����,�����µ����롣
	//! \param 		nVersion �汾
	UGbool SaveAs(const UGString& strWorkspaceName,	UGbool bFailIfExists = true,
		UGbool bIsXMLFormat = false,UGint nVersion = 0,const UGString& strNewPassword = (_U("")));
	//========================================================
	//! \brief 		��湤���ռ�.
	//! \return 	UGbool �������ɹ��ͷ���true������ͷ���false��
	//! \param 		workspaceConnection �����ռ����Ӳ���
	UGbool SaveAs(const UGWorkspaceConnection& workspaceConnection);

	//========================================================
	//! \brief 		�õ������ռ����ͣ��ο�ö��UGWorkspaceType.
	UGint GetType()const;

	/*!
		\pref ������ݿ�汾�����ռ����Ϣ
	 	\param strConn    ���ݿ������ַ���,����:
				"Provider = SQLOLEDB;Driver = SQL Server;SERVER = liwenlong;Database = test;"
	    \param strPwd     �û��������ַ���,����:
				"UID =SA;PWD = SA"
		\param arrWorkSpace      ���ع����ռ���Ϣ��
		\remarks ֻ�����ݿ�汾�Ĺ����ռ�ſ���
	*/
	UGbool GetInfo(const UGString& strConn, const UGString& strPwd, UGArray<UGString>& arrWorkSpace);

	void SetDescription(const UGString& strDescription);
	UGString GetDescription()const;
	
	void SetCaption(const UGString& strCaption);
	UGString GetCaption()const;

	UGDataSource* GetDataSource(const UGString& strAlias);
	UGDataSource* GetDataSource(UGint nIndex);

	//! \brief ɾ�������ռ�
	UGbool DeleteWorkspace(const UGWorkspaceConnection& workspaceConnection);

	//! \brief �޸Ĺ����ռ�����
	//! \param 	 strOldPassworld �����ռ������
	//! \param 	 strNewPassworld �����ռ�������
	//! \return  ���������Ƿ�ɹ� 
	//! \remarks ��������ʱ�����ִ�Сд
	UGbool ChangePassword(const UGString& strOldPassworld ,const UGString& strNewPassworld );

	//! \brief ɾ��Ŀ¼
	static UGbool RemoveDir(const UGString& strDir);
	static UGbool CopyWorkspaceFile(const UGString& strExistedFileName, const UGString& strNewFileName, UGbool bFailIfExists);

	UGbool GetLastUpdateTime(UGTime &updateTime);

protected:
	UGbool OpenSMW(const UGString& strWorkspaceName, UGbool bConnectDataSource,const UGString& strPWD = (_U("")));
	UGbool OpenSXW(const UGString& strWorkspaceName, UGbool bConnectDataSource,const UGString& strPWD = (_U("")));
	UGbool Open50SMW(UGStream& stream, UGbool bConnectDataSource,const UGString& strPWD = (_U("")));
	//UGbool OpenSUW(const UGString& strWorkspaceName, UGbool bConnectDataSource);

	UGbool SaveAsSUW(const UGString& strWorkspaceName, UGint nVersion = 0);
	//!\brief added by macx �������UGString����
	UGbool SaveAsSXW(const UGString& strWorkspaceName, UGint nVersion = 0,const UGString& strPWD = (_U("")));
	UGbool SaveAsSMW(const UGString& strWorkspaceName, UGint nVersion = 0,const UGString& strPWD = (_U("")));
	UGbool SaveAs50SMW(const UGString& strWorkspaceName, UGint nVersion = 0,const UGString& strPWD = (_U("")));

	UGbool LoadInfo();			// ��SM_WORKSPACE_INFO stream�ж���Info��Ϣ���������SUW�ļ��汾�ź�������Ϣ
	UGbool SaveInfo();			// ����SM_WORKSPACE_INFO���μ�LoadInfo

	// ����XML�ĵ��Ķ���ṹ��ʹ��XML�ĵ���η�����
	// strFileName �������XML�ĵ���ȫ·��
	UGbool AdjustXMLFile(const UGString& strFileName);

	// �� ����AdjustXmlFile()���õ��ĸ�����������б�����жϵ�ǰ��ǩ��Ӧ�е�λ�ã���Ҫ�������ٸ�Tab����
	//  </#######/> sprit б�ܡ�/������˼��
	// bHasSprit1, ��ǰ��ǩ�Ƿ��е�һ��б��		//bHasSprit2, ��ǰ��ǩ�Ƿ��еڶ���б��
	// bHasLastSprit1, ��һ����ǩ�Ƿ��е�һ��б��	//bHasLastSprit2, ��һ����ǩ�Ƿ��еڶ���б��
	UGint GetTabAdjust(UGbool bHasSprit1, UGbool bHasSprit2, UGbool bHasLastSprit1, UGbool bHasLastSprit2);
	
	// �ں���AdjustXmlFile()���õ��ĸ���������������ȡfile����pbFileContent����ռ���������
	// ���ش�file�ж�ȡ���ֽڵ���Ŀ
	UGint ReadContent(UGFileStream &file, UGbyte *&pbFileContent);

	/* \pref ��װSXW�����ռ��BYTE
	 * \param strPath SXW�����ռ��·��
	   \param nByteSize ���س���
	   \param pByte ��װ��Ĵ�
	   \return �ɹ�����TRUE
	   \remarks :
				��װ�����ռ��ʶ
				{
					SXW  = 1��
					LYT  = 2��
					SYM  = 3��
					LSL  = 4��
					BRU  = 5��
				}
		
	 */
	UGbool BoxingSXW(const UGString& strPath, UGuint& dwByteSize, UGbyte *&pByte,UGint nVersion);

private:
	UGbool LoadXMLInfo(UGMarkup& markup,UGString strWorkspaceName);

	// �ع����룬��ȡ�ѹ����ռ�д�뵽�ڴ����ķ���
	// ���ô˷���ʱ���������ģģ�ͻ���������ļ���ֱ��д����Ӧ���ļ��������Ҫ�ύ׼��д�뻷����
	// ��Unicode�汾�����ռ���Ҫ�ȴ򿪽����ļ���
	UGbool SaveToStream(UGStream &mem, const UGString& strWorkspaceName, UGint nVersion);
	UGbool LoadFromStream(UGStream &mem, const UGString& strWorkspaceName, UGint nVersion);


public:
	//! \brief ����Դ���ϡ���Open������bConnectDataSource����ΪTRUE(Ĭ��)ʱ����������ݷ�������
	UGDataSources m_DataSources;

	//! \brief ����ԴStorage���ϡ���Open������bConnectDataSource����ΪFALSEʱ����������ݷ�������
	UGDataSourceStorages m_DataSourceStorages;	
	UGbool m_bConnectDataSource;

	//! \brief ��ͼ����
	UGMapStorages m_MapStorages;
	//! \brief ��Դ����
	UGResources m_Resources;
	//! \brief ���ּ���
	UGLayoutStorages m_LytStorages;
	//! \brief ��ά��������
	UGSceneStorages m_SceneStorages;
	//! \brief �����ձ���DGN��TAB��DXF�Ƚ������ݵ�ʱ����Ҫ
	//	UGString m_strStyleMappingTable;
	//! \brief DGN��ɫ���ձ���DGN�������ݵ�ʱ����Ҫ
	//	UGString m_strDgnColorMappingTable;
	//	UGList<UGWorkspace**> m_ConnectedWorkspacePtrList;
	//added by xielin 2007-09-24 ͨ��UGWorkspaceConnection�򿪵Ĺ����ռ䣬��һ������
	//! \brief ������򿪵Ĳ�������ô�����ʱ��Ϳ���ͨ���������ж��Ƿ񱣴�
	UGWorkspaceConnection m_WorkspaceConnection;

	//! \brief ���ܹ����ռ�,added by macx 2008.8.4 ��
	//! \param strDes ���ؼ��ܺ���ַ�����[out]
	//! \param strWorkspaceName �����ռ���[in]��
	//! \param key=�����ռ����룬�ӽ��ܵ�key Ĭ��Ϊ��[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static UGbool EncryptString(UGString& strDes,const UGString& strSrc,const UGString& strPWD = (_U("")));
	//! \brief ���ܹ����ռ�,added by macx 2008.8.4 ��
	//! \param strDes ���ؽ��ܺ���ַ�����[out]
	//! \param strWorkspaceName �����ռ���[in]��
	//! \param strKey �����ռ����룬�ӽ��ܵ�key Ĭ��Ϊ��[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static UGbool DecryptString(UGString& strDes,const UGString& strSrc,const UGString& strPWD = (_U("")));	

	//! \brief ���ù����ռ�·�����ƣ��ڲ�ʹ�ã������⿪�ţ�
	void SetName(UGString strName);
	void SetType(UGint nType);

protected:
	// �򿪺ͱ��湤���ռ�̶������ģ�Ψһ
	UGString m_strCaption;
	UGint m_nVersion;

	UGString m_strName;					// the file name associated with the current workspace
	UGString m_strDescription;			// �����ռ������
	UGString m_strPassword;				// �����ռ�����
//	UGFileStream m_WorkspaceFile;		// �����ռ�ָ��ĸ����ĵ�����CSmCompoundFile������SmALib20
	static UGbool m_bDuplicatedInProgress;		// �Ƿ������ʵ������֮ǰ��ͬһ�����������ظ���Workspaceʵ�������ǲ��Ƽ���һ��������������Workspace���������ڹ��캯���и�ֵ��������ʹ��IsDuplicatedInProgress()����ֻ�����ʸñ�����ֵ��
	UGString m_strLastUpdateTime;		//������ʱ��
	
	// �����ж����ݿ�汾�����ռ�����Ҫ�½������Ǹ���ԭ���Ĺ����ռ䡣����ڴ��еİ汾�����ݿ�
	// ��һ�£����ǣ������¼ӣ�
//	UGint m_nDBWsVersion;
	UGbool m_bModified;					// �Ƿ��޸ģ������ж��Ƿ����
	UGuint m_unXMLBlockSize;
	UGint m_nType;
//	UGString m_strSavePath;				// Ϊ���ڱ���SUW�����ռ�ʱ���洢������Դ�����·�����ֿ���
	UGMutex m_mutex;
	//!brief ����SFC���֣��ڱ����ȥʱ����ʧ
	UGbyte* m_pLytBuffer;
	UGint m_nLytSize;
	UGString m_strLytInfo;

#ifdef _UGUNICODE
	UGCompactFile *m_pExternalStorage;
#endif
};	

}

#endif // !defined(AFX_UGWORKSPACE_H__A39D6DBA_DE0F_413A_B80C_FB5E2AFBC138__INCLUDED_)

