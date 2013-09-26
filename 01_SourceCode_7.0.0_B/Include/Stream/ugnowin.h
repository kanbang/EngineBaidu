/* 
	\file ugnowin.h
	\brief ��Windowsƽ̨��Linux��Unix�ȣ���ͷ�ļ�����
	\author zengzm
	\attention
	Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef _UGNOWIN_H
#define _UGNOWIN_H

// commited by zengzm 2007-3-30 ��link.h�������������Solaris�б��벻����
// ��Ϊ����ᶨ��_FILE_OFFSET_BITSΪ64����link.h��include��libelf.h��
// �ж�_FILE_OFFSET_BITS������32����_ILP32Ҳ�Ѿ������壬�ͻ�����������
// �������м��ĳ��ͷ�ļ��ж�����_ILP32����˰�link.h�ŵ���ǰ���У��Ա���˱������
// modified by yanbg 08.1.7 ���Ӷ�hpux��֧��
#if defined(_AIX) || defined(hpux) || defined(SYMBIAN60) || defined(OS_ANDROID) || defined IOS || defined (IOS3D)
#include <dlfcn.h> // for dlopen() & dlsym()
#else 
#include <link.h>  // for dlopen() & dlsym()
#endif               

// ͷ�ļ�����
// ����꣬ʹ�ÿ��Դ�����ļ���>4GB��
#undef _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <dirent.h>	
#include <fcntl.h>

#include "Base/ogdcdefs.h"
#include "Stream/ugexports.h"
using namespace OGDC;

#ifdef _UGUNICODE
	EXTERN_C STREAM_API OgdcInt UG_open(const OgdcChar* pFileName, OgdcInt nOpenFlag, OgdcInt nPermissionMode = 0);
	#define UGopen UG_open	//���ļ�
	EXTERN_C STREAM_API OgdcInt UG_access(const OgdcChar *path, OgdcInt mode );
	#define UGaccess UG_access	//���ļ�
	EXTERN_C STREAM_API OgdcInt UG_remove(const OgdcChar *path);
	#define UGremove UG_remove	//���ļ�
	EXTERN_C STREAM_API OgdcInt UG_rename(const OgdcChar *oldname, const OgdcChar *newname );
	#define UGrename UG_rename	//���ļ�
	EXTERN_C STREAM_API FILE* UG_fopen(const OgdcChar *path, const OgdcChar *mode);
	#define UGfopen UG_fopen	//���ļ�
	EXTERN_C STREAM_API FILE* UG_fopen64(const OgdcChar *path, const OgdcChar *mode);
	#define UGfopen64 UG_fopen64	//���ļ�
	//EXTERN_C STREAM_API OgdcInt UG_strlen(const OgdcChar *s);
	//#define UGstrlen UG_strlen	//���ļ�
	//EXTERN_C STREAM_API OgdcInt UG_strcpy(char *dest, const char *src);
	//#define UGstrcpy UG_strcpy	//���ļ�
#else
	#define UGopen	open	//���ļ�
	#define UGaccess access
	#define UGremove remove
	#define UGrename rename
	#define UGfopen fopen
	#define UGfopen64 fopen64
	#define UGstrlen strlen
	#define UGstrcpy strcpy
#endif


#define UGwrite	write	//д�ļ�
#define UGread	read	//���ļ�
#define UGseek	lseek	//��λ�ļ�
#define UGclose	close	//�ر��ļ�
#define UGchsize ftruncate
//#define UGseek lseek64
#if defined(UGtell)
#undef UGtell
#endif
// ��ѯ�ļ�λ��
#define UGtell(h) (UGlong)lseek(h, 0, SEEK_CUR)
#define UGsleep(s) sleep(s/1000)
#define UGfwrite	fwrite
#define UGfclose	fclose
#define UGfread		fread
#if !defined  OS_ANDROID && !defined (IOS) && !defined SYMBIAN60
#define UGfseek		fseeko64
#else
#define UGfseek		fseek
#endif

//�Ƿ���binary�ļ�
#define UGBINARY 0
//�Ƿ���read/write�ļ�
#define UGREADWRITE 0666

// �Ƿ���Ŀ¼
#define UGDIRECTORY 0x4000


#ifndef O_BINARY
	#define O_BINARY 0
#endif	//O_BINARY
//·��sep
#define PATHSEP _U('/')
//·��sep
#define PATHSEPSTRING _U("/")
//·��listSep
#define PATHLISTSEP _U(':')
//·��listSep
#define PATHLISTSEPSTRING _U(":")
//�Ƿ���·�� sep
#define ISPATHSEP(c) ((c)==_U('/'))
#define EOLSTRING _U("\n")
#define UGCALLBACK  
#define UGSTDCALL 

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS) && !defined (IOS3D)
#include <X11/Xlib.h>  
#endif
namespace UGC {

// �������Ͷ���
typedef unsigned long UGThreadID;	//	WhiteBox_Ignore
typedef void*		  UGHandle;		

//deleted by xielin 2007-06-26 ������û���û������ͻ��ɾ��
//typedef ::Display*  Display;
//typedef ::Window   DisplayWnd;

}


#endif // _UGNOWIN_H

