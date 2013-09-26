#ifndef UGCOMPRESS_H
#define UGCOMPRESS_H
#include "Stream/ugdefs.h"

namespace UGC {

//! \brief ѹ���㷨�ࡣ
//! \remarks Ŀǰ���ṩZip��ѹ���ͽ�ѹ����
class TOOLKIT_API UGCompress  
{
public:
	//! \brief Zip ѹ������
	/** \details ����C++����淶,Ŀ�Ĳ�����ǰ,Դ�����ں�,�ʶ���Sm30�в�����λ�ú�����������Ӧ�ĸĶ�
	ѹ�����ݲ���˵��
	void *pvDestBuffer: Ŀ���ڴ����� ,dwDestLen: Ŀ���ڴ������С
	const void *pvSrcBuffer: Դ����; UGuint dwSrcLen:Դ���ݳ���
	
	  Ŀ���ڴ�������Ҫ���ȿ��٣�����Ҫ�� dwSrcLen * 1% + 12,	����ѹ����
	  dwDestLen������compressBound�������м��㣻
	  �ڴ�Ĵ�С��ı䣬dwDestLen �����ı��Ĵ�С;
	  pvSrcBuffer��pvDestBuffer������ͬ
	  ����UGint nLevel ����ȡ1��9֮�������.
	  nLevelԽС��ѹ���������õ��ڴ����٣�����ѹ���ٶ�����ѹ���ʵ�;
	  nLevelԽ��ѹ���������õ��ڴ���࣬����ѹ���ٶȿ죬ѹ���ʸ�;
	  
		compress returns Z_OK if success, Z_MEM_ERROR if there was not enough
		memory, Z_BUF_ERROR if there was not enough room in the output buffer,
		Z_STREAM_ERROR if the level parameter is invalid.
		compress2 (dest, dwDesLen, source, dwDesLen, level)
	*/
	  //!  \brief Toolkit
	static UGbool Zip(UGbyte *pvDestBuffer, UGuint &dwDestLen, 
		const UGbyte *pvSrcBuffer, UGuint dwSrcLen, UGint nLevel=8);
	
	//! \brief UnZip��ѹ������
	/** \details ����C++����淶,Ŀ�Ĳ�����ǰ,Դ�����ں�,�ʶ���Sm30�в�����λ�ú�����������Ӧ�ĸĶ�
	��ѹ�����ݲ���˵��
	void *pvDestBuffer: Ŀ���ڴ����� ,dwDestLen: Ŀ���ڴ������С
	const void *pvSrcBuffer: Դ����; UGuint dwSrcLen:Դ���ݳ���
	
	  Ŀ���ڴ�������Ҫ���ȿ��٣�����Ҫ�� dwSrcLen * 101% + 12,���н�ѹ����
	  �ڴ�Ĵ�С��ı䣬dwDestLen�����ı��Ĵ�С;
	  pvSrcBuffer��pvDestBuffer������ͬ
	  Decompress returns Z_OK if success, Z_MEM_ERROR if there was not
	  enough memory, Z_BUF_ERROR if there was not enough room in the output
	  buffer, or Z_DATA_ERROR if the input data was corrupted.
	*/
	  //!  \brief Toolkit
	static UGbool UnZip(UGbyte *pvDestBuffer, UGuint &dwDestLen, 
		const UGbyte *pvSrcBuffer, UGuint dwSrcLen);

	//!  \brief ���ڼ������ѹ��ʱ����Ҫ���ٵ�Ŀ��洢����Ĵ�С
	//!  \param nSrcSize ��Ҫѹ����Դbuf�Ĵ�С
	//!  \return ѹ����Ĵ洢�������迪�ٵĴ洢�ռ�������ܴ�С
	static UGint CompressBound(UGint nSrcSize);
	
	//!  \brief ����ѹ���ļ������ļ��������ݣ��ڴ���������zip��ʽ�ļ�
	//! \param strSrcPath  Ҫѹ���ļ������ļ����ڴ����ϵ�·��[in]
	//! \param strDesPath  ���zip�ļ��ڴ����ϵ�·����Ĭ���ǿգ�����Դ�ļ���ͬ��Ŀ¼��[in]
	//! \remarks �ݲ��������Ѿ����ɺõ�zip���︽�ӻ��߸��ǣ�CRC32У�飬���룬�������ļ�·����Ϣ��
	//!          ѹ����������ã�ĿǰWin32ƽ̨����ѹ�������ļ������ļ����������ļ�������ƽ̨����ѹ�������ļ��������ļ�����û��Ƕ���ļ��е����Ҳ����ѹ��
	//! \return  ѹ���ɹ�����true��
	static UGbool MiniZip(const UGString& strSrcPath, const UGString& strDesPath = _U(""));

	//! \brief ��ѹ��zip��ʽ��ѹ��������ͬ������Ŀ¼������ѹ�����ڵ��ļ����Լ��ļ���
	//! \param strName [in] zip�ļ��ڴ����ϵ�·����ͬ������Ҳû�п��ų���������ѹ·����
	//! \param bOutHere Ĭ��Ϊtrue����ͬ��Ŀ¼��ѹ��falseʱ��ѹ����zip�ļ����������ļ�����
	//! \return ��ѹ���ɹ�����true��û�м�¼��ѹ�������ļ��ṹ��������ʹ��UGFile::FindFileExtPaths�����ж��β���
	static UGbool MiniUnZip(const UGString& strFileName,UGbool bExtractHere = TRUE);

	//! \brief   ����ѹ���ڴ�,ѹ���㷨7zip
	//! \return  ѹ���ɹ�����true
	static UGbool Compress7Zip(UGbyte *pvDestBuffer, UGuint &dwDestLen,const UGbyte *pvSrcBuffer, UGuint dwSrcLen);

	//! \brief   ���ڽ�ѹ���ڴ�,ѹ���㷨7zip
	//! \return ��ѹ���ɹ�����true
	static UGbool UnCompress7Zip(UGbyte *pvDestBuffer, UGuint &dwDestLen, 
		const UGbyte *pvSrcBuffer, UGuint dwSrcLen);

	//! \brief ����ѹ���ļ������ļ��������ݣ��ڴ���������7-zip��ʽ�ļ�
	//! \param arraySrcPath [in] ��Ҫѹ�����ļ�·�����顣
	//! \param targetFileName [in] ѹ����Ŀ���ļ�����׺�����û�еĻ�Ĭ��Ϊ.7z
	//! \param strPassword [in] ѹ���ļ���������,���������Բ�������
	//! \param bOverWrite[in] Ŀ���ļ������ڻ��½�,����Ѿ�����bOverWrite=true��ɾ��ԭ���ļ������´���,bOverWrite=flase�Ļ�����ԭ�����ļ���׷��
	//! \return  ѹ���ɹ�����true
	static UGbool Compress7ZipFile(const UGArray<UGString>& arraySrcPath, const UGString& strTargetFileName,const UGString& strPassword=_U(""),UGbool bOverWrite=TRUE);

	//! \brief ��ѹ��7-zip��ʽ��ѹ��������Ŀ��Ŀ¼�½�ѹ
	//! \param strFileName[in]��Ҫ��ѹ��7zip�ļ�,��׺����һ����.7z
	//! \param targetFloder[in]��Ҫ��ѹ�ĵ�Ŀ���ļ���
	//! \param strPassword [in] ��ѹ����,���û�в�������
	//! \return ��ѹ���ɹ�����true
	static UGbool UnCompress7ZipFile(const UGString& strFileName,const UGString& strTargetFloder,const UGString& strPassword=_U(""));

public:

	UGCompress() {m_uzFile = NULL;};

	virtual ~UGCompress() {};
private:
	
	UGbool OpenZip(const UGString& szFilePath, UGbool bAppend = FALSE);

	UGbool CloseZip(); 

	UGbool AddFileToZip(const UGString& szFilePath, const UGString& strRelPath = _U(""), UGbool bIgnoreFilePath = FALSE);
	
	UGbool AddFolderToZip(const UGString& szFolderPath, const UGString& strRelPath = _U(""), UGbool bIgnoreFilePath = FALSE);

	UGulong GetAttribute(const UGString& strPath);

	UGbool GetStatus(const UGString& strFileName, UGTime& statustime);

private:

	void* m_uzFile;
};

}

#endif


