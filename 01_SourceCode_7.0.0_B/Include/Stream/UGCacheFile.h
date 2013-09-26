//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details ���ļ�������GTiff�ļ���������Ҫ�ӿڡ�
//!  \author ���֡�
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
#ifndef __SUPERMAP_UGC_AHCACHEFILE_H__INCLUDE_
#define __SUPERMAP_UGC_AHCACHEFILE_H__INCLUDE_

//#include "sysdef.h"
//#include "const.h"
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <vector>
#include <fstream>
#include <exception>
#include <time.h>
#include <math.h>
#include <sstream>  

//#include "Toolkit/UGHashCode.h"
#include "ugdefs.h"
#include "UGByteArray.h"
#include "Stream/UGFile.h"
#include "Stream/ugplatform.h"


#ifdef WIN32
#include "windows.h"
#endif

#ifndef WIN32
typedef long long int UGPosType;//λ��ָ������,��ʱĬ�϶���64λ		//	WhiteBox_Ignore
#else
typedef __int64 UGPosType;
#endif

//#if define(_DEBUG) || define(DEBUG)
//#define ENABLE_CACHE_FILE_LOG
//#endif // _DEBUG



using namespace std;

namespace UGC {
typedef UGint UGResult;

//���ļ���ʽ�йصĳ�������
#define BOXCOUNT 256
#define STR_SC_FILETYPE _U("SC")
#define STR_SCD_FILETYPE _U("SCD")
#define STR_SCD_FILETYPE_LEN 3
#define STR_SC_FILE_POSTFIX _U(".sc")
#define DEF_FILE_MAXSIZE 2000 /*��λ��M*/
#define FILE_MAXSIZE 2000 /*��λ��M*/
#define DFILE_MIN_POS 3 /*�����ļ������ݵ���Сλ��*/
#define LITTLE_ENDIAN_MARK 0 /*С�ֽ����־*/
#define BIG_ENDIAN_MARK 1 /*���ֽ����־*/
//�ļ��汾��
#define INIT_VERSION 20100401 //���ļ�����ĳ�ʼ�汾����2010.4.1
#define VERSION_1_1 20100901 //���ļ�����İ汾��2010.9.1

//
#define EMPTY_STR_CODE 757602046 //���ַ����Ĺ�ϣֵ
#define DEFAULT_DATA_ENCODE_LENGTH 64 //ArchiveSubHead.EncodeDataLen��Ĭ��ֵ

//������
#define UGE_SUCCESS      0
#define UGE_OPEN_FALSE   1
#define UGE_CREATE_FALSE 2
#define UGE_ERROR_FORMAT 3
#define UGE_OUTOF_RANGE  4
#define UGE_NO_FOUND	 5
#define UGE_UNOPEN		 6
#define UGE_INVALID_ARGUMENT 7
#define UGE_UNSUPPORTED 8
#define UGE_ERROR_READ 9
#define UGE_ERROR_WRITE 10

#define	SC_ISTAT_OVERWRITE	0    //�ļ�������
//#define SC_ISTAT_DELETED	-1   
//#define SC_ISTAT_APPENDING -2

#define SCD_FILE_STATUS_APPENDING 1//����׷���е��ļ�
#define SCD_FILE_STATUS_NORMAL 0//�����ļ�
#define SCD_FILE_STATUS_GARBAGE 2//�����ļ���������ʹ��

// #ifdef WIN32
// #define UGtell _telli64
// #define UGaccess _access
// #define UGchsize _chsize
// //#define UGseek _lseeki64
// #define UGsleep Sleep
// #else
// #define UGaccess access
// #define UGchsize ftruncate
// //#define UGseek lseek64
// #if defined(UGtell)
// #undef UGtell
// #endif
// #define UGtell(h) (UGPosType)lseek(h, 0, SEEK_CUR)
// #define UGsleep(s) sleep(s/1000.0)
// #endif

//! \brief ��������
enum StoreType	// TODO ����Ϊ StorageType����֤�����Ƴ�ͻ
{
	PURE_FILES=0, //���ļ��ͻ���,��ǰС�ļ����͵Ļ���
	MIXED_FILES, //����ļ���,�ʺϷ�������ɻ���(��Ȼ�ͻ���Ҳ�������ɴ�����)
	SINGLE_FILE, //���ļ���,�ʺϿͻ������ɻ���
};

//! \brief �鵵��
class STREAM_API UGCacheFile
{
public:
#pragma pack(1)
//! \breif �����sc�ļ���
struct HashItem{
	UGint HashCode;//��ϣֵ
	UGbyte FileId;//���������ļ�
	UGint DataPos;//���ݿ�ʼ(����������Чλ��)
};
#pragma pack()

//! \breif ׷�ӷ�ʽ
enum ADD_TYPE{ 
	NEW , //���½����µ����ݿ�
	APPEND //׷�ӵ��������ݿ�
};

enum FILE_TYPE{
	NORMAL = 0,
	APPENDING = 1
};

//! \brief ����ĵĴ�ģʽ  ��ʱֻ��ֻ���Ͷ�д 
enum CacheFileDirection
{
//	! \brief ֻд
//	CF_OnlyWrite	=0,
	//! \brief ֻ��
	CF_OnlyRead		=1,
	//! \brief ��д
	CF_ReadAndWrite =2,
};

struct CacheFileStatus{
	UGint NumOfFiles; // �ļ������������Ѿ�ɾ���˵��ռ�û�б����յ��ļ�
	UGint NumOfValidFiles;//��Ч�ļ�����Ŀ
	UGint TotalSpaceSize; // �����ļ����ܴ�С
	UGint ValidSpaceSize; //��Ч�ռ��С
};

private:
//! \breif sc�ļ�ͷ�ṹ
struct ArchiveHead{
	UGbyte  FileType1;//�ļ���ʾ,��Զ��SC
	UGbyte  FileType2;//�ļ���ʾ,��Զ��SC
    UGbyte	Ext1;//
	UGbyte EndianType;//�ֽ���Ϊ1��ʾBig-Endian��Ϊ0��ʾLittle-Endian
	UGint Version;//�汾��
	UGint MaxSize;//���Ĵ�С,MΪ��λ
	UGint MagicNumber;//�����ж��Ƿ��Ǵ��ļ������ֵӦ����INIT_VERSION
    UGbyte  Flag[48];//48����չ�ֶ�ƴ��64�ֽ�
};

//! \brief scd �ļ���
struct ArchiveSubHead{
	UGint FileNameLen;//�ļ����ĳ���
	UGint DataLen;//���ݵĳ���
	UGint EndodeDataLen;//�ļ����ݱ����ܵĳ���(���ܴ����ļ����ݵĳ���)
	UGbyte FileStatus;//�ļ�״̬(��־����ļ�����;������ֻ��׷��ʹ�ã�0Ϊ�����ļ���1��ʾ�ļ�����׷����)
	UGbyte Reserve[3];//�����������ֽ�
	
	ArchiveSubHead()
	{
		FileNameLen = 0;
		DataLen = 0;
		EndodeDataLen = 0;
		FileStatus = SCD_FILE_STATUS_GARBAGE;
        memset(Reserve,0,3);
	}
};

//! \breif ����ͷ�ṹ��sc�ļ���
struct HashListHead{
	UGint UpdateTime;//������ʱ��
	UGint Count;//һ������Hash
	UGint EndFile;//�ڵڼ����ļ�����
	UGint EndPos;//��ʲôλ�ý���
	UGint EndHashItem;//���ڵ��ڼ���Item��
};

//! \breif ���ҽ��
enum SEARCH_RESULT{ 
	NOFOUND , //û�ҵ�
	FOUND, //�ҵ���
	//FOUNDINSERT,
};

//! \breif HashItem�б��װ
struct HashItemArray
{
	//�ڲ�����
	HashItem* m_data;
	//�ڲ���С
	UGint m_size;
public:
	//! \breif ���캯��
	HashItemArray();
	//! \breif ��������
	~HashItemArray();
	//! \breif �����С
	inline void SetSize(UGint size)
	{
		if (m_data!=NULL) delete[] m_data; 
		m_size = size; 
		m_data = new HashItem[size];
	}
	//! \brief ��ȡ�ڵ�����
	UGint GetSize()
	{
		return m_size;
	}
	//! \breif ��������
	inline HashItem* GetItem(UGint i)
	{
		if (i>=m_size)
			return NULL;
		return (HashItem*)(m_data+i);
	}
};



public:
	
    //! \brief ���캯��
    UGCacheFile(/*ArchiveHash* hash = 0*/);

    //! \brief ��������
    ~UGCacheFile();

	//! \brief ���ļ���
	//! \param path[in] ���ļ�·����
	//! \param password[in] ����������
	//! \return ���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks ���ָ���ļ�·�������ڣ����Զ�����һ���ļ���
	//! \attention ��
    UGResult Open(const UGString& path, const UGString& password=_U(""), CacheFileDirection save_or_load = CF_ReadAndWrite);

	//! \brief �Ƿ��Ѿ����ļ���
	//! \param path[in] ��
	//! \param password[in] 
	//! \return 
	//! \remarks ��
	//! \attention ��
	UGbool IsOpen();

	//! \brief �����ļ������Զ�������С��Ĭ����2G���ֵ��
	//! \param schpath[in] �����ļ�·����
	//! \param maxsize[in] �����ļ���С(Ĭ��2G��ֻ��С���ɴ�����Ϊ0Ϊ������)��
	//! \param password[in] ��������
	//! \return ���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks �������ֻ���𴴽�(�ڲ��Ѿ��ر�)��������򿪡�Ҫ�򿪣�������Ҫ�ٵ���һ��Open
	//! \attention ��
    static UGResult Create(const UGString& schpath ,const UGString& password=_U("")
		,UGint maxsize=DEF_FILE_MAXSIZE,UGbool bBigIndian = FALSE
		,UGint version =VERSION_1_1);

	//! \brief �ر��ļ�
	//! \param [in] 
	//! \return 
	//! \remarks 
	//! \attention ��
    UGbool Close();

	//! \breif ��������
	//! \param newpassword[in] �趨������
	//! \return �Ƿ����óɹ�
	//! \remarks 
	//! \attention ��
	UGbool SetPassword(const UGString& newpassword);

	//! \brief ���һ���ļ�
	//! \param filepath[in] Ҫ��ӵ��ļ�·��
	//! \param archivePath[in] Ҫ��ӵ��ļ��ڻ����д洢��·��(���·��)
	//! \return ���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks ����浵�д洢��·���Ѵ��ڣ���ô�Ḳ������ļ�����
	//! \attention ��
    UGResult AddFile(const UGString& filepath, const UGString& archivePath);

	//! \brief ���һ���ļ�(ֱ�ӼӶ�����)
	//! \param context[in] Ҫ��ӵ��ļ�����
	//! \param archivePath[in] Ҫ��ӵ��ļ��ڻ����д洢��·��(���·��)
	//! \return ���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks ����浵�д洢��·���Ѵ��ڣ���ô�Ḳ������ļ�����
	//! \attention ��
	UGResult AddFile(const UGByteArray& context, const UGString& archivePath);

	//! \brief ׷��ģʽ��������
	//! \param context[in] Ҫ��ӵ��ļ�
	//! \param archivePath[in] Ҫ��ӵ��ļ��ڻ����д洢��·��(���·��)
	//! \param bLast[in] �Ƿ����һ��׷������
	//! \remark ��׷��ģʽ���ӵ������൱��һ����ʱ���ݣ�������������£�����ReadFile��ʱ��
	//! �Ƕ�����������ݵģ�ֻ����bLastΪtrue����׷�����һ������֮��ReadFile����
	//! ��������
	UGResult AppendFile(const UGByteArray& context, const UGString& archivePath ,UGbool bLast = FALSE);

	//! \brief �ж��ļ��Ƿ����
	//! \param archivePath[in] Ҫ��ӵ��ļ��ڻ����д洢��·��(���·��)
	//! \return �����Ƿ���ڡ�
	//! \remarks ע�⣺������ж��ļ��Ƿ���ڵ�ͬʱ��Ҫ�����ݣ�Ӧ��ֱ����ReadFile�ķ���ֵ���жϡ���Ҫ���ñ�����������ReadFile������Ӱ��Ч�ʡ�
	//! \attention ��
	UGbool IsFileExist(const UGString& archivePath);

	//! \brief ��ȡ�鵵�е��ļ�
	//! \param filepath[in] Ҫ��ȡ���ļ�·��
	//! \param context[in] �ļ�����
	//! \return ���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks
	//! \attention ��
	UGResult ReadFile(const UGString& filepath, UGByteArray& context);

	//! \brief �ӹ鵵��ɾ���ļ�(��ʱ����ɾ����Ϊ�޶���С�Ѿ�����ɾ����)
	//! \param filepath[in] Ҫɾ�����ļ�·��
	//! \param reconstruction[in] Ҫ��Ҫ�������ٴ�С(Ĭ�ϲ�����)
	//! \return ���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks
	//! \attention ��
	UGResult RemoveFile(const UGString& filepath, FILE_TYPE file_type = NORMAL ,UGbool reconstruction=FALSE);

	//! \brief �ع�(�����ļ�)
	//! \param [in]
	//! \return 
	//! \remarks
	//! \attention ��
	UGResult Reconstruction();

	//! \brief ��ȡ�����ļ���״̬��Ϣ
	//! \param status[out] ���ص��ļ�״̬��Ϣ
	//! \param bNeedReconstruction[out] �Ƿ�������ع�����
	//! \return TRUE ��ȡ�ɹ�
	//! \return FALSE ��ȡʧ��
	//! \remarks
	//! \attention
	UGbool GetStatus( CacheFileStatus &status ,UGbool& bNeedReconstruction );

	//! \brief �г����й鵵���ļ��Ĺ鵵·��
	//! \param filepaths[in] ��Ź鵵�ļ�·��������
	//! \return 
	//! \remarks
	//! \attention ��
	UGResult ListFiles(UGArray<UGString>& filepaths);

private:
	//! \brief �����ļ�
	UGbool LockFile();

	//! \brief �����ļ�
	void UnlockFile();

	//! \brief �ж��ļ��Ƿ�����
	//UGbool IsLocked();

	//��ӡlog������ʱ���ã�
	void PrintLog(const UGString& log, UGbool newline=FALSE);

	//! \brief �����ϣֵ
	UGint Codec2UGint(const UGString& instr) const;

	//! \brief �ӽ���
	static void ReMakeStream(UGbyte* stream, UGint len ,UGbyte *pXor);

	//! \brief �����ϣֵ
	UGint GetHashCode(const UGString& instr);

	//! \brief ��ȡ����ʱ��
	static UGint GetNowTime();

	//! \brief ��ȡָ���浵·������
	UGint GetHashItem(const UGString& archpath, UGint& iitem, HashItem** item
		, HashItemArray* itemArr 
		, UGbool bAppendingFile = FALSE);

	//! \brief ��ȡ��ַ��ָ�ļ��Ĵ�С(�������ļ�����)
	UGint GetFileLenFromDataFile(UGint handle, UGint pos);

	//! \brief 
	UGResult AddFileInner(const UGByteArray& context, const UGString& _archivePath ,ADD_TYPE addtype = NEW ,UGbool bLastAppend = FALSE);

	//��ȡĳ��ҳ�Ŀ�ʼ��ַ
	//UGPosType GetPagePos(UGint ipage, UGint ibox=-1);

	//���ļ����浽scd��
	//UGint ArchiveFileToDataFile(const char* filepath, const char* archpath, UGPosType& pos, UGint& len, HashItemArray& itemArr);

	//���ļ����ݱ��浽scd��
	//UGint ArchiveByteArrayToDataFile(const UGByteArray& bytearr, const char* archpath, UGPosType& pos, UGint& len, HashItemArray& itemArr);

	//! \brief ��ȡָ��λ�õ��ļ��鵵��
	UGbool GetFilePathFromDataFile(UGint handle, UGint pos, UGMBString& path);

	//! \brief
	inline UGbool ReadArchiveSubHead(UGint handle ,UGint pos ,ArchiveSubHead &head);

	//! \brief
	inline UGbool WriteArchiveSubHead(UGint handle ,UGint pos ,ArchiveSubHead head);

	//! \brief 
	inline UGbool GetDataFileHandle(UGint fileid ,UGint& handle ,UGbool& bNeedClose);

	//! \brief ��ȡ���ʵĿ��пռ�
	UGbool GetFreeRoom(HashItemArray &arrItem ,UGint DataSize ,const UGString &arName ,UGint &iitem);

	//! \brief 
	UGint GetSizeInDataFile(UGint DataSize ,const UGString &arName);

	//! \brief �������ļ��л�ȡ����������
	//! \param dhandle[in] �����ļ����
	//! \param pos[in] λ��
	//! \param context[out] ��ȡ���������ļ�
	UGbool ReadDataFromDataFile(UGint dhandle ,UGint pos ,const UGString &arName ,UGByteArray& context);

	//! \brief д���ݵ������ļ�
	UGbool WriteDataToDataFile(UGint dhandle ,UGint pos ,const UGByteArray& context 
		,const UGString &arName ,UGbyte byFileStatus = SCD_FILE_STATUS_NORMAL);


	//! \breif ���¹鵵��Ϊ"/"��ʽ�ķָ���
	UGString ReMakeAhPath(const UGString& oldPath);

	//! \brief ת�������ֽ���
	static void SwapBytesArchiveHead(ArchiveHead& head);
	static void SwapBytesHashItemHead( HashListHead& listhead);
	static void SwapBytesHashItem(HashItem& item);
	static void SwapBytesArchiveSubHead(ArchiveSubHead &SubHead);

private:
	//! \breif ��Unicode�汾�£���֮ǰ��UGString�ַ���ת��ΪUGMBString
	//! \param strUnicode[in]Ҫ��ת����UnicodeString
	//! \param strMB[out]ת��֮��Ķ��ֽ��ַ���
	static inline UGMBString& Unicode2MBString(const UGString& strUnicode, UGMBString& strMB)
	{
#ifdef _UGUNICODE
		strUnicode.ToMBString(strMB);
#else
		strMB = strUnicode;
#endif
		return strMB;
	}

	//! \brief ��UGMBStringת��ΪUnicodeString
	//! \param strMB[in]Ҫ��ת���ĵ�strMB
	//! \param strUnicode[out]ת��֮���Unicode�ַ���
	static inline UGString& MBString2Unicode(const UGMBString& strMB, UGString& strUnicode)
	{
#ifdef _UGUNICODE
		strUnicode.FromMBString(strMB.Cstr(), strlen(strMB.Cstr()));
#else
		strUnicode=strMB;
#endif
		return strUnicode;
	}


private:
	//sc�ļ��������
    UGint m_handler;
	//scd�ļ��������
	UGint m_dhandler;
	//scd�ļ����������Ӧ��FileID
	UGint m_scdFileID;

	//�ļ�ͷ����λ��
    //UGPosType m_HeadPos;

	//�ļ�ͷ����
    ArchiveHead m_head;

	//������ʼλ��(����������Ϣͷ)
	UGPosType m_idxBegin;

	//sc�ļ�·��
	UGString m_scPath;
	//scd�ļ�·��
	//UGString m_scdPath;

	//�ӽ�����Կ
	UGbyte btXorOld[256];

	//�Ƿ���Ҫת���ֽ���
	UGbool m_bNeedSwap;

	CacheFileDirection m_efileDir;

#ifdef WIN32
	//lock�ļ����
	//UGint m_lh;
	HANDLE m_lh;

	//lock�ļ��ļ���
	UGString m_lockFileName;
#endif

#ifdef ENABLE_CACHE_FILE_LOG
	//��־�ļ�
	UGint m_hLogFile;
#endif //ENABLE_CACHE_FILE_LOG

};

inline UGbool UGCacheFile::WriteArchiveSubHead(UGint handle ,UGint pos ,ArchiveSubHead head)
{	
	if(m_efileDir == CF_OnlyRead)// ֻ��
		return FALSE;

	UGASSERT(handle != -1);
	UGASSERT(head.DataLen > 0 && head.FileNameLen > 0);
	UGint errCode;

	errCode = UGseek(handle ,pos ,SEEK_SET);
	UGASSERT(errCode != -1);
	if(m_bNeedSwap)
	{
		SwapBytesArchiveSubHead(head);
	}
	ReMakeStream((UGbyte*)&head ,sizeof(ArchiveSubHead) ,btXorOld);
	errCode = UGwrite(handle ,&head ,sizeof(ArchiveSubHead));
	UGASSERT(errCode >= 0);
	
	return TRUE;
}

inline UGbool UGCacheFile::ReadArchiveSubHead(UGint handle ,UGint pos ,ArchiveSubHead &head)
{
	UGASSERT(handle != -1);
	UGint errCode;

	errCode = UGseek(handle ,pos ,SEEK_SET);
	UGASSERT(errCode != -1);
	errCode = UGread(handle ,&head ,sizeof(ArchiveSubHead));
	UGASSERT(errCode >= 0);
	ReMakeStream((UGbyte*)&head ,sizeof(ArchiveSubHead) ,btXorOld);
	if(m_bNeedSwap)
	{
		SwapBytesArchiveSubHead(head);
	}
	return TRUE;
}

inline UGbool UGCacheFile::GetDataFileHandle(UGint fileid ,UGint& handle ,UGbool& bNeedClose)
{
	if(fileid < 0)
		return FALSE;

	handle = m_dhandler;
	bNeedClose = FALSE;
	if( fileid != m_scdFileID)
	{
		//���µ��ļ�
		UGString scdpath;
		scdpath.Format(_U("%s%02X") ,m_scPath.Cstr() ,fileid);
		if(m_efileDir == CF_OnlyRead)
		{
			handle = UGopen(scdpath.Cstr() ,O_RDONLY | UGBINARY ,999);
		}
		else
		{
			handle = UGopen(scdpath.Cstr() ,O_RDWR | UGBINARY ,999);
		}
		if(handle == -1)
		{
			return FALSE;
		}
		bNeedClose = TRUE;
	}
	return TRUE;
}

}

#endif

