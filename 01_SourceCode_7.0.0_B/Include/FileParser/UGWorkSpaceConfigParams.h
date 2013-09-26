// UGVectorImportParams.h: interface for the UGVectorImportParams class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG_WORKSPACE_IMPORTPARAMS_H__INCLUDED_)
#define AFX_UG_WORKSPACE_IMPORTPARAMS_H__INCLUDED_

#include "Stream/ugexports.h"
#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGRasterConfigParams.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace UGC {

//���幤���ռ�����ӣ����ﶨ����Ϊ�˲�Ҫ���¹��̼����������
// struct UGWorkspaceConn
// {
// 	//! \brief �����ռ�����
// 	UGint	m_nWorkspaceType;
// 
// 	//! \brief ���ݿ���
// 	UGString		m_strDatabase;
// 
// 	//! \brief ��������������ļ��͹����ռ䣬��ô����ȫ·�������ļ���
// 	UGString		m_strServer;
// 
// 	//! \brief �û���
// 	UGString		m_strUser;
// 
// 	//! \brief ����
// 	UGString		m_strPassword;
// 
// 	//! \brief �����ռ�����
// 	UGString		m_strWorkspaceName;
// 
// 	//! \brief ����ļ��͹����ռ���Ч������ļ��Ѿ������Ƿ񷵻�ʧ��,Ĭ����true
// 	UGbool			m_bFailIfExists;
// 
// 	//! \brief	�����ռ�İ汾��Ĭ����0
// 	UGint			m_nVersion;
// 
// 	//! \brief ODBC Driver
// 	UGString		m_strDriver;
// };

class UGWorkspace;

//! \brief  ʸ���������	
class FILEPARSER_API UGWorkspaceImportParams  : public UGImportParams
{


public:
	//! \brief ���캯����
	UGWorkspaceImportParams();
	
	//! \brief ����������
	virtual ~UGWorkspaceImportParams();

	//! \brief ��ȡ�����ռ�
	UGWorkspace* GetWorkspace();

	//! \brief ���ù����ռ�(���Բ����ڿ��Դ���)
	void SetWorkspace(UGWorkspace* wsc);

	//! \brief ��ȡ����ʸ�����ݵĲ�����
	UGbool GetVectorImportParams(UGVectorImportParams& impParams);

	//! \brief ��ȡ����դ�����ݵĲ�����
	UGbool GetRasterImportParams(UGRasterImportParams& impParams);
	
	//! \brief ����Ҫ�������������ݼ���
	UGbool SetRenameTabNames(const UGDict<UGString, UGString>& rnTabNames);

	//! \brief ��ȡҪ�������������ݼ���
	UGbool GetRenameTabNames(UGDict<UGString, UGString>& rnTabNames);

	//! \brief ��ȡҪ���������ĵ�ͼ��
	UGbool SetRenameMapNames(const UGDict<UGString, UGString>& rnMapNames);

	//! \brief ����Ҫ���������ĵ�ͼ��
	UGbool GetRenameMapNames(UGDict<UGString, UGString>& rnMapNames);


private:
	UGDict<UGString, UGString> m_rnTabNames;
	UGDict<UGString, UGString> m_rnMapNames;

	UGWorkspace* m_workspace;
};


//////////////////////////////////////////////////////////////////////////


} //namespace UGC

#endif // !defined(AFX_UG_WORKSPACE_IMPORTPARAMS_H__INCLUDED_)

