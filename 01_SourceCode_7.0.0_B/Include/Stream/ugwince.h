/* 
	\file ugwince.h
	\brief WinCEƽ̨��ͷ�ļ�����
	\author zengzm
	\attention
	Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef _UGWINCE_H
#define _UGWINCE_H

//_WIN32_WCE
// UGC 2.0�ݲ�֧��WinCE, ����Ҫ֧��ʱ,�ٽ��д���ĵ�������ֲ
//���ļ���fopen()
#define UGopen	fopen
//д�ļ���fwrite()
#define UGwrite	fwrite
//���ļ���fread()
#define UGread	fread
//��λ�ļ���fseek()
#define UGseek	fseek
//�ر��ļ���fclose()
#define UGclose	fclose
// CE�����£��ļ�����ֻ������Ľӿ�
//���ļ���fopen()
//д�ļ���fwrite()
//���ļ���fread()
//��λ�ļ���fseek()
//�ر��ļ���fclose()


//CE�����������º궨�壺
//_MAX_DRIVE
//_MAX_DIR
//_MAX_FNAME
//_MAX_EXT


//CE���������������ݣ�
//time_t
//clock_t
//clock()
//time()
//mktime()
//asctime()
//ctime()
//difftime()
//gmtime()
//localtime()
//strftime()

//��hypot()��CE�¶���Ϊ_hypot()
//��CE��������getenv()�ӿ�


#endif

