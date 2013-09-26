//  ʵ�ֶ�zip�ļ��Ĳ���
//  UGZipFile ��������Zip�ļ���д�ļ��ġ�
// 	#define APPEND_STATUS_CREATE        (0)
// 	#define APPEND_STATUS_CREATEAFTER   (1)
// 	#define APPEND_STATUS_ADDINZIP      (2)
// 	Create������Ӧ����APPEND_STATUS_CREATE
// 	Open������Ӧ����APPEND_STATUS_ADDINZIP
//
//  UGunZipFile ��������Zip��ȡ�ļ����ݵġ�

#ifndef UGZIPFILE_H
#define UGZIPFILE_H

#include "Stream/UGMemoryStream.h"
namespace UGC {

class TOOLKIT_API UGZipFile
{
enum UGZipAppendStatus
{
	UGZipAppendStatusCreate = 0,
	UGZipAppendStatusCreateAfter = 1,
	UGZipAppendStatusAddInZip = 2
};

public:
	UGZipFile();
	~UGZipFile();
	// ��zip�ļ�
	// param strFilePath[in] zipfile��·��
	// param strPWD[in] ����
	// param appendStatus[in] ����zip��״̬
	UGbool Open(const UGString& strFilePath, const UGString& strPWD = _U(""), UGZipFile::UGZipAppendStatus appendStatus = UGZipFile::UGZipAppendStatusCreate);

	// �ر�zip�ļ�
	UGbool Close();

	// ����ļ�
	// param strFileNameInZip[in] zip���ļ������ư���·����
	// param strFileName[in] Ҫ����ӵ��ļ�
	UGbool AddFile(const UGString& strFileNameInZip, const UGString& strFileName);

	// ���stream��zip��
	// param strFileNameInZip[in] zip���ļ������ư���·����
	// param stream [in] Ҫ��ӵ�stream
	UGbool AddFile(const UGString& strFileNameInZip, UGMemoryStream& stream);

	// ����ļ���
	// param strForlderPath[in] �ļ���
	// param strForlderPathInZip[in] ��Zip���ļ��е����·��
	UGbool AddForlder(const UGString& strForlderPath, const UGString& strRelPath = _U(""));
private:
	// ��Zip����ӿ��ļ���
	// param strFolderPathInZip[in]  Zip�е��ļ���λ��
	// remark ���ļ��к��ļ������־������ļ�����zip_fileinfo.external_fa����16 ���ļ���32 ��winrarһ��
	UGbool AddEmptyFolder(const UGString& strFolderPathInZip);
private:
	UGZipFile(const UGZipFile&);
	UGZipFile& operator=(const UGZipFile&);
private:
	// zipFile����
	void* m_pZipFile;
	enum
	{
		KEYLENGTH=256,
	};
	// zip ���� ����UTF8����
	UGachar m_pPassWord[KEYLENGTH];
};

class TOOLKIT_API UGunZipFile
{
public:
	UGunZipFile();
	~UGunZipFile();
	// ��zip�ļ�
	// param strFilePath[in] zip�ļ�·��
	// param strPWD[in] ����
	UGbool Open(const UGString& strFilePath, const UGString& strPWD=_U(""));

	// �ر�zip�ļ�
	UGbool Close();

	// �õ��ļ���stream
	// param strFileNameInZip[in] zip�ļ��е����ư���·��
	// param stream[out] �õ�����
	UGbool GetFile(const UGString& strFileNameInZip, UGMemoryStream& stream);

	// �õ��ļ�
	// param strFileNameInZip[in] zip�е��ļ�����
	// param strFileName[in] Ҫ������ļ����ƣ�(ȫ·��)
	UGbool GetFile(const UGString& strFileNameInZip, const UGString& strFileName);

	// �õ��ļ���
	// param strRelFolderPath[in] �ļ��е�·��
	// param strFolderPahth[in] ��ѹ�����ļ��е�·��
	UGbool GetFolder(const UGString& strRelFolderPathInZip, const UGString& strForlderPath);

private:
	UGunZipFile(const UGunZipFile&);
	UGunZipFile& operator=(const UGunZipFile&);
private:
	// zipFile����
	void* m_pZipFile;
	enum
	{
		KEYLENGTH=256,
	};
	// zip ���� ����utf8����
	UGachar m_pPassWord[KEYLENGTH];
};


}
#endif

