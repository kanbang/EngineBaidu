//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details ���ļ������˽����ļ����ʵ����нӿڡ�
//!  \author �����ں��顣
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
#ifndef __SUPERMAP_UGC_AHCOMPACTFILE_H__INCLUDE_
#define __SUPERMAP_UGC_AHCOMPACTFILE_H__INCLUDE_

#include "Stream/ugdefs.h"
#include "Stream/UGByteArray.h"
#include "Stream/UGFile64.h"
#include "Stream/UGFile32.h"
#include "Stream/UGFileStream.h"
#include "Stream/UGCacheFile.h"
#include "Toolkit/UGThread.h"
#include "Toolkit/UGProcess.h"
#include "Toolkit/UGTextCodec.h"


namespace UGC {
typedef UGint UGResult;

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
#define UG_FILE_HEADER_FLAG "CF"
#define UG_COMPACTFILE_EXT _U(".cf")

// ÿ��Grid�����������е��ֽڴ�С ��һ�����ֽڱ�ʾ״̬, �����߸���ʾƫ����
#define UGC_CFGRID_IDXSIZE 8
// ÿ��Naming�����������е��ֽڴ�С ��һ�����ֽڱ�ʾ״̬ �м��߸���ʾƫ���� ���8����ʾhashcode
#define UGC_CFNAMING_IDXSIZE 16

#define UGC_CF_INIT_VERSION 20111111
#define UGC_CF_UNICODE_VERSION 20120214 

#if defined(WIN32) && _MSC_VER <= 1200
#define UGC_CF_POS_MASK 0x00FFFFFFFFFFFFFF
#else
#define UGC_CF_POS_MASK 0x00FFFFFFFFFFFFFFLL
#endif
#define UGC_CF_POSBIT 56

#define  UGC_CF_NAMING_POSBIT 112

#define CF_IDXVALUE(CFSTAT, CFPOS) (((UGulong)CFSTAT << UGC_CF_POSBIT) | CFPOS)

//! \brief �õ�Index�����ֵ��ֵ��ָ��IndexData��ָ��
//! \param INDEXDATA��ʼ��ַUGbyte*
//! \param INDEX���
//! \return ��Ӧ��ƫ�� 
//! \remarks 8�������UGulong���ֽڳ���
#define CF_NAMING_IDXVALUE(INDEXDATA, INDEX) (((*(UGulong*)(INDEXDATA+INDEX*UGC_CFNAMING_IDXSIZE))))
//! \brief �õ�Index�����HASHCODE
//! \param INDEXDATA��ʼ��ַUGbyte*
//! \param INDEX���
//! \return ��IndexData�д洢��Index��
//! \remark 8������������������8���ֽڴ洢����hashcode����UGC_CFNAMING_IDXSIZE
#define CF_NAMING_IDXHASHCODE(INDEXDATA, INDEX) ((*(UGulong*)(INDEXDATA+INDEX*UGC_CFNAMING_IDXSIZE+8)))


//! \brief �����ļ�
class COMPACTFILE_API UGCompactFile
{

public:
	//! \brief ���������ļ��д洢��ָ���ļ���״̬
	enum UGStatus
	{
		CF_NotExist = 0x00,	//	�ļ�������
		CF_Exist = 0x01,		//	�ļ�����
		CF_Incomplete = 0x02,	//	�ļ�������
		CF_Unknown = 0x04,	//���쳣״̬
	};
	//! \brief �����ļ���������ʽ
	enum UGIndexMode
	{
		CF_GRID=0,		// ����������ʽ
		CF_NAMING=1,	// ����������ʽ
		CF_MIXED=2,		// ���������ʽ��֧�ֶ���������ʽ����
		CF_CACHEFILE =3, //����ǰ�ļ���һ��cachefile
	};
	
	//! \brief �����ļ��Ĵ򿪷�ʽ
	enum UGOpenMode
	{
		CF_OM_ForceDestroy = 0x00000001, //����ļ����ڣ���ɾ���ļ����½���һ���ļ�
		CF_OM_ReadOnly = 0x00000002, //ֻ����ʽ���ļ���
		CF_OM_ReadWrite = 0x00000004, //��д��ʽ���ļ�
		CF_OM_Single = 0x00000008, //��ռ���ļ����ļ�ֻ�ܱ���һ�Σ�
	};

	//! \brief �����õ��ĳ���
	enum
	{
		CF_KeyLength = 256,
		CF_NAMEBYTELEN = 256
	};

	// ������������ʹ�ã����hashcode�����������е�����index
	typedef UGDict<UGulong,UGint> UGHashCodeMap;
//! \brief ����ͷ���õ���ѡ��
	enum
	{
		CF_OP_VERSION = 0x00000001, // �Ƿ������ð汾
	};

public:
	#pragma pack(1)
	//! \breif CF�ļ�ͷ�ṹ
	struct CFHeader
	{
	public:
		CFHeader()
		{
			m_cFlag[0] = UG_FILE_HEADER_FLAG[0];
			m_cFlag[1] = UG_FILE_HEADER_FLAG[1];
			m_bEndian = 0;
			m_nVersion = UGC_CF_INIT_VERSION;
			m_tmUpdate = 0.0;
			m_eIndexMode = CF_GRID;
			m_nIndexPosition = 0;
			memset(m_pPlaceholder,0,37);
		}
		UGachar m_cFlag[2];
		UGbyte m_bEndian;	// �ֽ���Ϊ1��ʾBig-Endian��Ϊ0��ʾLittle-Endian
		UGuint m_nVersion;  // UGC_CF_UNICODE_VERSION�汾��Namingģʽ�²�����Unicode���롣
		UGuint m_eIndexMode;
		UGdouble m_tmUpdate;
		UGulong m_nIndexPosition;
		UGuchar m_pPlaceholder[37];	//��ռλ��,���ļ�ͷ�Ĵ�С�ﵽ64�ֽ�
	};
	#pragma pack()

	#pragma pack(4)
	struct CFGridDataIndexHeader
	{
		CFGridDataIndexHeader()
		{
			m_nIndexRow = 0;
			m_nIndexColumn = 0;
			m_nFlags = 0;
		}
		UGuint m_nIndexRow;
		UGuint m_nIndexColumn;
		UGuint m_nFlags;
	};
	#pragma pack()

	#pragma pack(4)
	// ������ʽ�������ṹ
	struct CFNamingDataIndexHeader
	{
		CFNamingDataIndexHeader()
		{
			m_nIndexCapacity = 0;
			m_nIndexLength = 0;
			m_dMaxSize = 0.0;
			m_dReservedSize = 0.0;
			m_nFlags = 0;
		}
		// ����������Ԥ�����������(����)
		UGulong  m_nIndexCapacity;
		// ����������ʵ�ʳ���
		UGulong  m_nIndexLength;
		// ��������������С�����������СҪɾ��
		UGdouble m_dMaxSize;
		// ���������ı�������
		UGdouble m_dReservedSize;
		// ״̬
		UGuint m_nFlags;
	};
	#pragma pack()

	struct CFVersion
	{
		UGulong m_nVersionNum;
		// ״̬��Ϣ��λ��ƫ�Ƶ��ۺ���
		UGulong m_nDataPos;
	};
	//! \brief CF��Gird���������ݴ洢��ʽ
	struct CFGridData
	{
		CFGridData()
		{
			m_nTotalLength = 0;
			m_nDataCapacity = 0;
			m_nDataLength = 0;
			m_pData = NULL;
			m_nVersionCount = 0;
			m_pVersions = NULL;
		}
		UGulong m_nTotalLength;
		UGulong m_nDataCapacity;
		UGulong m_nDataLength;
		UGbyte *m_pData;
		// ����������Ա���ڱ�ʾ���ð汾�����ݵİ汾��Ϣ����û�а汾ʱ�����洢�������������
		UGuint m_nVersionCount;
		CFVersion *m_pVersions;
	};

	// �������ݽṹ
	//! \brief CF��Naming���������ݴ洢��ʽ
	struct CFNamingData
	{
		CFNamingData()
		{
			m_nTotalLength = 0;
			m_nCodeType = 0;
			m_nNameByteLength = 0;
			m_pName = NULL;	
			m_nDataCapacity = 0;
			m_nDataLength = 0;
			m_pData = NULL;
			m_nVersionCount = 0;
			m_pData = NULL;
			m_pVersions = NULL;
		}
		UGulong m_nTotalLength;
		UGint m_nCodeType;
		UGuint m_nNameByteLength;  // �ֽڳ���
		UGchar *m_pName;
		// ���ݵ��ܴ�С
		UGulong m_nDataCapacity;
		// ���ݵ�ʵ�ʴ�С
		UGulong m_nDataLength;
		// ʵ�ʵ�����
		UGbyte *m_pData;
		// ����������Ա���ڱ�ʾ���ð汾�����ݵİ汾��Ϣ����û�а汾ʱ�����洢�������������
		UGuint m_nVersionCount;
		CFVersion *m_pVersions;
	};

public:
    //! \brief ���캯��
    UGCompactFile();

    //! \brief ��������
    ~UGCompactFile();

private:
	UGCompactFile(const UGCompactFile &in);
	UGCompactFile &operator=(const UGCompactFile&);

public:
	//! \brief	��������������ʽ�Ľ����ļ�����Ҫָ����������������һ��ָ���������޸�
	//! \param	&strCFPath[in] �����ļ�·����
	//! \param 	nRowNum[in] ���������ļ�������
	//! \param 	nColNum[in] ���������ļ�������
	//! \param 	&strPwd[in] ��������
	//! \param	&eOpenMode[in] ���ļ���ģʽ��CF_OM_ReadOnly��create�ӿ��в�������
	//			CF_OM_ReadWrite���û��ָ����Ҳ��Ĭ�ϴ��ϵ�
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks �������һ���ļ�strCFPath������չ���֣����Զ���������ϱ�׼��չ����UG_COMPACTFILE_EXT
	//! \remarks ��Ҫ������scΪ��β���ļ��������ᵼ�´��ж�ʧ�ܡ�
	UGResult Create(const UGString &strCFPath, UGuint nRowNum, UGuint nColNum, const UGString &strPwd=_U(""),UGOpenMode eOpenMode = CF_OM_ReadWrite);

	//! \brief 	��������������ʽ�Ľ����ļ� 
	//! \param 	������&strCFPath[in] �����ļ�·����
	//! \param 	nInitialSize[in] ����������ʽ�ĳ�ʼ������Ŀ
	//! \param 	&strPwd[in] ��������
	//! \param	&eOpenMode[in] ���ļ���ģʽ��CF_OM_ReadOnly��create�ӿ��в�������
	//			CF_OM_ReadWrite���û��ָ����Ҳ��Ĭ�ϴ��ϵ�
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks �������һ���ļ�strCFPath������չ���֣����Զ���������ϱ�׼��չ����UG_COMPACTFILE_EXT
	//! \remarks ��Ҫ������scΪ��β���ļ��������ᵼ�´��ж�ʧ�ܡ�
	UGResult Create(const UGString &strCFPath, UGuint nInitialSize=5120, const UGString &strPwd=_U(""), UGOpenMode eOpenMode = CF_OM_ReadWrite);

	//! \brief	���ļ�
	//! \param	������&strPathin] ���ļ�·����
	//! \param	&strPwd[in] ����������
	//! \param	&eOpenMode[in] ���ļ���ģʽ��CF_OM_ForceDestroy ���ģʽOpen�ӿ��в�������,CF_OM_ReadWrite 
	//			CF_OM_ReadOnly��������ָ������һ�������û��ָ������Ĭ�ϰ���CF_OM_ReadWrite��
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	���ջ����ļ������Ѵ���
	//! \remarks ����CacheFile�ļ����� Open�ӿڡ�
	//! \remarks  �����һ��CacheFile��ֻͨ����չ����".sc"�����жϡ����������չ������ƽ����ʽ�򿪡�
	//! \remarks �������һ���ļ�strCFPath������չ���֣����Զ���������ϱ�׼��չ����UG_COMPACTFILE_EXT
	UGResult Open(const UGString& strPath, const UGString& strPwd=_U(""),UGOpenMode eOpenMode = CF_OM_ReadWrite);

	//! \brief	�ж��Ƿ��Ѿ����ļ���
	//! \return	�����Ƿ��Ѿ��򿪣��Ǹ�boolֵ������ֱ���ж� ��
	//! \remarks ����CacheFile�ļ����� IsOpen�ӿڡ�
	UGbool IsOpen();

	//! \brief	�ر��ļ�(��һ������Ҫ���ã�����������ʱ����Զ�����)
	//! \param ������Դ
	//! \return	�Ƿ�رճɹ�
	//! \remarks ����CacheFile�ļ����� Close�ӿڡ�
	UGbool Close();

	//! \brief	��������
	//! \param	&strNewPwd[in] �趨������
	//! \return	���أ��Ƿ����óɹ�
	//! \remarks ����CacheFile�ļ����� SetPassword�ӿڡ�
	UGbool SetPassword(const UGString& strNewPwd);

	//! \brief	�����������ʽ�Ľ����ļ������һ����������
	//! \param	nRow[in] ���������ļ����к�
	//! \param	nCol[in] ���������ļ����к�
	//! \param	&context[in] Ҫ��ӵ�����
	//! \param	lDataSize[in] ��ʾcontext�������ݵĴ�С.���Ƕϵ����������,���context��ʾ�����ݲ�����,ҲҪд�������ļ���
	//! \param	lOffset[in] ��ʾcontextд����ջ���ʱ��ƫ��λ
	//! \param  nVersionNum[in] �汾��
	//! \return	����ֵ�����ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	ע�⣺�ò����������ڸ���������ʽ�Ľ����ļ�.ͬʱ�÷���Ҳ֧�����ô�ɫ������,�����ֽ����ĳ���С��64λʱ,�ֽ����ĳ��ȱ�ʾ��ɫ��λ��,�ֽ��������ݱ�ʾ��ɫֵ.
	UGResult SetAt(UGuint nRow, UGuint nCol, const UGByteArray & context, UGulong lDataSize = 0, UGulong lOffset = 0, const UGulong nVersionNum = 0);

	//! \brief	�����������ʽ�Ľ����ļ������һ���ļ�
	//! \param	nRow[in] ���������ļ����к�
	//! \param	nCol[in] ���������ļ����к�
	//! \param	&strFilePath[in] Ҫ��ӵ��ļ��ľ���·��
	//! \param  nVersionNum[in] �汾��
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	�ò����������ڸ���������ʽ�Ľ����ļ�
	UGResult SetAt(UGuint nRow, UGuint nCol, const UGString &strFilePath, const UGulong nVersionNum = 0);

	//! \brief	�Ӹ���������ʽ�Ľ����ļ��ж�ȡָ�����ļ�,�Զ���������ʽ��¼
	//! \param	nRow[in] ���������ļ����к�
	//! \param	nCol[in] ���������ļ����к�
	//! \param	&context[out] ��ȡ�Ķ�������
	//! \param	&lValidByte[out] context����Ч���ֽ���,���������context�ĳ�����lValidByte��ͬ,�����ǵ����ڵ����ļ��Ķϵ�����Ҫ��,ͨ���ò����������������Ƿ�����
	//! \param  nVersionNum[in]�汾�ţ����û�иð汾��ѯ�����ľ������°汾
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	�ò����������ڸ���������ʽ�Ľ����ļ�
	UGResult Lookup(UGuint nRow, UGuint nCol, UGByteArray &context, UGulong &lValidByte, const UGulong nVersionNum = 0);


	//! \brief	�Ӹ���������ʽ�Ľ����ļ����Ƴ�ָ�����ļ�
	//! \param	nRow[in] ���������ļ����к�
	//! \param	nCol[in] ���������ļ����к�
	//! \param  nVersionNum[in]�汾����û�иð汾����UGE_SUCCESS
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	�ò����������ڸ���������ʽ�Ľ����ļ�,�Ƴ��ļ������ͷ���Ӧ�Ŀռ�,��Ҫ������Ӧ�Ľ����ռ�ķ���
	UGResult Remove(const UGuint nRow, const UGuint nCol, const UGulong nVersionNum = 0);

	//! \brief	�Ӹ���������ʽ�Ľ����ļ��в�ѯָ�����ļ�,����������,����,�ļ����������쳣����״̬
	//! \param	nRow[in] ���������ļ����к�
	//! \param	nCol[in] ���������ļ����к�
	//! \return	���ر�ʶָ���ļ��ڽ����ļ��е�״̬ 
	//! \remarks	�ò����������ڸ���������ʽ�Ľ����ļ�
	UGStatus GetStatus(UGuint nRow, UGuint nCol);

	//! \brief	������������ʽ�Ľ����ļ������һ����������
	//! \param	&strName[in] ׼����ӵ������ڽ��ջ����е�����,Ҳ����Ϊ��ȡ���ļ���Ψһ��ʶ
	//! \param	&context[in] Ҫ��ӵ�����
	//! \param	lDataSize[in] ��ʾcontext�������ݵĴ�С.���Ƕϵ����������,���context��ʾ�����ݲ�����,ҲҪд�������ļ���
	//! \param	lOffset[in] ��ʾcontextд����ջ���ʱ��ƫ��λ��
	//! \param  nVersionNum[in]�汾��
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	�ò���������������������ʽ�Ľ����ļ�,[�ݲ�֧�ִ�ɫ]ͬʱ�÷���Ҳ֧�����ô�ɫ������,�����ֽ����ĳ���С��64λʱ,�ֽ����ĳ��ȱ�ʾ��ɫ��λ��,�ֽ��������ݱ�ʾ��ɫֵ.
	//! \�ļ��д洢�����ĸ�ʽ�ǣ��ܳ��Ȳ�������¼�ܳ��ȵ�UGulong
	//! \ �ܳ���[UGulong]+���Ƶı����ʽ[UGuint]+���Ƴ���[UGuint]+����+�ļ���С[UGulong]+�ļ���ʵ��С[UGulong]+����
	//! \remarks ����CacheFile�ļ����� AddFile(const UGByteArray& context, const UGString& archivePath);
	//				archivePath ��Ӧ strName��context ��Ӧ contex
	UGResult SetAt(const UGString &strName , const UGByteArray & context, UGulong lDataSize = 0, UGulong lOffset = 0, const UGulong nVersionNum = 0);


	//! \brief	������������ʽ�Ľ����ļ������һ����������
	//! \param	&strName[in] ׼����ӵ������ڽ��ջ����е�����,Ҳ����Ϊ��ȡ���ļ���Ψһ��ʶ
	//! \param	&strFilePath[in] Ҫ��ӵ��ļ��ľ���·��
	//! \param  nVersionNum[in]�汾��
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	�ò���������������������ʽ�Ľ����ļ�
	//! \remarks ����CacheFile�ļ����� AddFile(const UGByteArray& context, const UGString& archivePath);
	//				archivePath ��Ӧ strName��strFilePath ��Ӧ strName
	UGResult SetAt(const UGString &strName, const UGString &strFilePath, const UGulong nVersionNum = 0);

	//! \brief	������������ʽ�Ľ����ļ����Զ���������ʽ��ȡ�ļ�
	//! \param	&strName[in] �ļ��ڽ��ջ����е�����
	//! \param	&context[out] �����������
	//! \param	&lValidByte[out] context����Ч���ֽ���,���������context�ĳ�����lValidByte��ͬ,�����ǵ����ڵ����ļ��Ķϵ�����Ҫ��,ͨ���ò����������������Ƿ�����
	//! \param  nVersionNum[in]�汾�ţ����û�иð汾�ͷ������°汾
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	�ò���������������������ʽ�Ľ����ļ�
	//! \remarks ����CacheFile�ļ����� ReadFile(const UGString& filepath, UGByteArray& context);
	//		     �� IsFileExist(const UGString& archivePath); �൱�� UGResult��not found
	UGResult Lookup(const UGString &strName, UGByteArray &context, UGulong &lValidByte, const UGulong nVersionNum = 0);

	//! \brief	������������ʽ�Ľ����ļ����Ƴ�ָ�����ļ�
	//! \param	&strName[in] �ļ��ڽ��ջ����е�����
	//! \param  nVersionNum[in] �汾��
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	�ò���������������������ʽ�Ľ����ļ�
	//! \remarks ����CacheFile�ļ����� RemoveFile(const UGString& filepath, FILE_TYPE file_type = NORMAL ,UGbool reconstruction=FALSE);
	UGResult Remove(const UGString &strName, const UGulong nVersionNum = 0);

	//! \brief	���ؽ����ļ�����������
	//! \param	nRow[out] ����������ΪGridʱ,��ʾ����;����������ΪNamingʱ,��ʾ��������;
	//! \param	nCol[out] ����������ΪGridʱ,��ʾ����;����������ΪNamingʱ,��ʾ����ʵ������;
	//! \return �����������͡�
	//! \remarks	�ò���������������������ʽ�Ľ����ļ�
	//! \remarks ����CacheFile�ļ����� GetStatus( CacheFileStatus &status ,UGbool& bNeedReconstruction );
	//      nRow ��ʾ status.NumOfFiles��nCol ��ʾ status.NumOfValidFiles,���� CF_CACHEFILE
	UGIndexMode GetIndexInfo(UGuint &nRow, UGuint &nCol);

	//! \brief	������������ʽ�Ľ����ļ��в�ѯָ�����ļ�,����������,����,�ļ����������쳣����״̬
	//! \param	&strName[in] �ļ��ڽ��ջ����е�����
	//! \return	���ر�ʶָ���ļ��ڽ����ļ��е�״̬ 
	//! \remarks	�ò���������������������ʽ�Ľ����ļ�
	UGStatus GetStatus(const UGString &strName);

	//! \brief ��ѯ������������Ч���ݵ������б�
	//! \param aryList[out] �����б�
	//! \remarks ����CacheFile�ļ����� ListFiles�ӿ�
	UGbool GetValidNamingList(UGArray<UGString> &aryList);

	//! \brief	��������������ʽ�Ľ����ļ�������մ�С�ͻ��տռ�ʱ�����Ŀռ��С
	//! \param	dMaxSize[in] �����ļ�������մ�С
	//! \param	dReserveSize[in] ���տռ�ʱ�����Ŀռ��С
	//! \return 
	//! \remarks	�ò���������������������ʽ�Ľ����ļ�
	void SetMaxSize(UGdouble dMaxSize, UGdouble dReserveSize);

	//! \brief	�Ƿ����������ļ��İ汾������,���ð汾����,�ļ����º�,���ļ����԰汾��ʽ����,�汾��ʱ����ķ�ʽ��¼
	//! \param	bEnable[in] �Ƿ����ð汾��,True����,False����
// 	void EnableVersion(UGbool bEnable);

	//! \brief �Ƿ������ð汾
	UGbool IsVersionEnabled();
	
	//! \brief	�Խ����ļ����п��пռ�Ļ���
	//! \param	
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks ����CacheFile�ļ����� Reconstruction�ӿ�
	UGResult Compact();

	//! \brief	��鵱ǰ�����Ƿ�����������
	//! \param	
	//! \return	����true�����ڵ����̣��������TRUE�������������������FLASE����û����������
	//					  ���ڶ���̣����̳߳��� ���������TRUE�����н��̻��߳����ڶ�д��
	UGbool IsDeadLocked();

	//!\ brief �ѻ����е�����д���ļ�
	UGbool Flush();

	UGString GetFullPath();

private:
	UGbool CreateGrid(UGuint nRowNum, UGuint nColNum);
	UGbool CreateNaming(UGuint nInitialSize);
	UGbool ProcessLockInit();


	//! \brief	�Ƿ���������д��,�����д�������
	//! \param	
	//! \return	
	void BulkAdd(UGbool bStart);

	void BulkFlush();

	void BulkRollback();

public: // �������
	//! \brief ������Կ
	//! \param pwd[in] ����
	//! \return ���ɵ���Կ
	static UGint GenerateKey(const UGchar *pwd);

	//! \brief �����ֽ�
	//! \param c1, c2Ҫ�������ֽ�
	//! \return 
	static void SwapByte(UGbyte& c1, UGbyte& c2);

	//! \brief ����stream
	//! \param pStream[out] Ҫ���ɵ���
	//! \param nKey[in] ��Կ
	static void GenerateStream(UGbyte *pStream, UGint nKey);

	//! \brief ����Xor�ַ���
	//! \param pDes[out]Ҫ���ɵ�Xor�ַ���
	//! \param pSrc[in]Դ�ַ���
	static void GenerateXorString(UGbyte* pDes, UGbyte* pSrc);

	//! \brief ����Xor�ַ���
	//! \param pDes[out]Ҫ�����ܵ�Stream
	//! \param nLength[in]����
	//! \param pXor[in]Ҫ��xor������ַ���
	static void ReMakeStream(UGbyte* pDes, UGint nLength ,UGbyte *pXor);

private: // HashCode��ء������������
	//! \brief ���ַ���ת��ΪUGintֵ���ڴ洢�����ļ����õ�����ʱʹ��
	//! \param strIn[in] Ҫ��ת�����ַ���
	//! \return �õ��Ĺ�ϣ��
	UGulong GetHashCode(const UGString& strIn);

	//! \brief �õ��ļ����Ѿ��洢��Hashcode���ļ���Index��Map
	//! \param pIndexData �洢���ǿ��������ڴ�
	//! \return ��䵽m_HashCodeMap��
	UGbool InitHashCodeMap(const UGbyte* pIndexData);

	//! \brief �������������е���������
	//! \param status[in]������Ӧ���ݵ�״̬�������Ƿ��Ƕϵ��������߰汾���� 
	//! \param nDatapos[in]����λ��
	//! \param nHashCode[in]��Ӧ�Ĺ�ϣֵ
	//! \remarks �������ĸ�������Ԥ����������������½�Ԥ�����������һ��
	UGbool UpdateNamingIndex(UGStatus status, UGulong nDatapos, UGulong nHashCode);

	//! \brief �������Ŀ����Ԥ����Ŀ��ʱ��Ҫ��������������
	//! \remark ���������ֻ������Namingģʽ
	UGbool IncreaseNamingIndexCapacity();

	//! \brief ����������ģʽ�µõ����ݿ��д洢��String(����)
	//! \param nIndex[in]���������ݵ�ƫ��
	//! \param nByteLen[out] m_pName�е��ֽڳ���
	//! \remark ���ж�����ʱ�õ������m_strName����
	UGbool GetKeyString(UGint nIndex, UGint& nByteLen);

	//! \brief �����������������µõ�HashCode������ƫ����
	//! \param strName[in]��Ϊ�����洢��name
	//! \param nNewHashCode[out]�µ�Ҫ���趨��HashCode
	//! \param nNewIndexValue[out]�µ�Ҫ���趨��ƫ����
	UGbool ReSetHashCodeAndIndexValue(const UGString strName,UGulong& nNewHashCode, UGulong& nNewIndexValue);

	//! \brief �õ���һ�������hashcode��ֵ
	//! \param nHashCode ��ǰ��ϣֵ
	//! \remark ��������µ��ڸ��ֽڼ�һ���hashcode
	UGulong GetNextHashCode(UGulong nOldHashCode);

	//! \brief �õ�����ĸ���
	//! \param nHashCode ��ǰ�Ĺ�ϣֵ ��������Ǵ����Ƶõ���HashCode,���ֽ���0X00.
	UGint GetSameHashCodeCount(UGulong nCurHashCode);
	
private:
	UGbool GetGridIdxValue(UGuint nRow, UGuint nCol, UGulong &nIdxValue);

	//! \brief �õ�Naming������
	//! \param strName[in] �ļ�����
	//! \param nIdxValue[out] �õ����������ֵ
	//! \param nHashCode[out] �õ��ַ����Ĺ�ϣֵ
	UGbool GetNamingIdxValue(const UGString &strName, UGulong &nIdxValue, UGulong &nHashCode);

	//! \brief �����ݶ��뽻���ռ�(m_cfDataSwap)��
	UGbool ReadDataFromDataFile(UGulong nDataPos);

	//! \brief �ѽ����ռ�(m_cfDataSwap)�е�����д���ļ�
	UGulong WriteDataToDataFile(UGulong nDataPos, UGbool bFileEnd = FALSE);

	//! \brief �����ڴ��е�����
	UGbool UpdateSwapData(const UGByteArray & context, UGulong lDataSize, UGulong lOffset, UGulong nDataPos);
	
	UGByteArray* GetSwapData();

	//! \brief�õ����ݸ��µ����,�Ͱ汾˳��
	//! \param &nUpDatetatus[out]�õ�Ҫ���д�������Ŀǰ�ǣ�1, 2, 3, 4
	//! \param &nVersionOrder[out]Ҫ����İ汾��˳��
	//! \param &nUpdateDatapos[out]�����Ҫ���µ�λ��
	//! \param &nDataOffset[out]������м�汾ʱ��Ҫ����汾��ƫ����
	//! \param nVersionNump[in]�汾��
	//! \remarks // 1.������°汾����,2.����м�汾����,3.���µ�ǰ�汾����,4.����֮ǰ�汾���ݣ�
	//! \5.�ް汾�����ݸ���, 0.�ް汾��������ݡ�Ŀǰû���ް汾����� 
	UGbool GetStatusAndVersionOrder(UGuint& nUpdateStatus, UGuint& nVersionOrder, UGulong &nUpdateDatapos, UGulong& nDataOffset, const UGulong nDataPos, const UGulong nVersionNum);

	//! \brief����°汾����:
	//! param &status[out]���ݵ�״̬
	//! param context[in]Ҫ��������
	//! param lDataSizeIn[in]���ݴ�С
	//! param nVersionNum[in]�汾��
	//! param strKeyString[in]namingģʽ�µ�����������namingģʽ������
	//! remark ��������� ������°汾���ݣ�
	//! nUpdataStatus״̬:�˽����ݸ��µ����,��Ϊ����״̬:1.������°汾����,2.����м�汾����,3.���µ�ǰ�汾����,4.����֮ǰ�汾����, 5.�ް汾�����ݸ���, 0.�ް汾���������
	UGulong AddMaxNewVersionData(UGStatus& status, const UGByteArray& context, const UGulong lDataSizeIn, const UGulong nOffset, const UGulong nVersionNum, UGString strKeyString=_U(""));

	//! \brief����°汾����:
	//! param context[in]Ҫ��������
	//! param lDataSizeIn[in]���ݴ�С
	//! param nVersionOrder[in]����ƫ��
	//! param nVersionNum[in]�汾��
	//! remark ��������� ������°汾���ݣ�����м�汾����
	//! nUpdataStatus״̬:�˽����ݸ��µ����,��Ϊ����״̬:1.������°汾����,2.����м�汾����,3.���µ�ǰ�汾����,4.����֮ǰ�汾����, 5.�ް汾�����ݸ���, 0.�ް汾���������
	UGulong AddOldVersionData(const UGByteArray& context, const UGulong lDataSizeIn, const UGulong nOffset, const UGulong nVersionOrder, const UGulong nVersionNum);

	//! \brief ����֮ǰ�汾������ ��Ϊ�ϵ������͸��ǵ����
	//! \param nUpdataDataPos[in]Ҫ���µ�����λ��
	//! \param nDataPos[in]���汾���ļ��е�λ��
	//! \param nDataPosOffset[in]�����м�汾ʱ��Ҫ���µİ汾�����°汾�е�ƫ��
	//! \param context[in]��������
	//! \param lDataSizeIn[in]����������С
	//! \param lOffset[in]ƫ��
	//! \remarks���UpdateStatusΪ4�����:����֮ǰ�汾����
	UGbool UpdateOlderVersion(UGulong& nUpdateDataPos, const UGulong nDataPos, const UGulong nDataPosOffset,const UGByteArray& context, const UGulong lDataSizeIn, const UGulong lOffset);

	//! \brief ���������
	//! \param stauts[out]״̬
	//! \param context[in]Ҫ����ӵ�����
	//! \param DataSize[in]���ݴ�С
	//! \param nOffset[in]ƫ��
	//! \param nVersionNum[in]�汾��
	//! \param strKeyString[in]ֻ����Namingģʽ�����������,namingģʽ������
	UGulong AddNewData(UGStatus& status, const UGByteArray& context, const UGulong nDataSize, const UGulong nOffset, const UGulong nVersionNum, UGString strKeyString=_U(""));

//����̿��ƴ���
	UGbool LookUp_Inner(UGulong nDataPos, UGByteArray & context, UGulong &lValidByte, const UGulong nVersionNum );
public:
	//�����д��ˢ�Ļ��棬��ˢ������
	UGResult RefreshIndex();
private:
	//! \brief ����Charset�õ�TextCodec�������ڴ洢��������ʱ���������洢ΪUnicode
	//! \param to �ַ�������
	//! \param from �ַ�������
	UGTextCodec* GetTextCodec(UGMBString::Charset to, UGMBString::Charset from);

private:
	UGbool ReadIndex();
	//���̶�д�� ��֧�ֿ��������
	UGProcess m_processRWLock;

	//��Ҫ������RefreshIndex���Ƿ񣬷�ֹ��Refresh���������Ȼ������Refresh�������������ѭ��Ƕ�׵�����
	// ����ʱ����m_bRefreshIndexing����Ƿ��Ѽӽ�����
	UGbool m_bRefreshIndexing;
private:
	// �ļ����
	UGFile64 m_fileHandle;

	CFHeader m_header;
	CFGridDataIndexHeader m_headerGrid;
	CFNamingDataIndexHeader m_headerNaming;

	UGuchar *m_pIndexData;
	UGbool m_bNeedSwap;
	UGbool m_bOpend;

	//! \brief ������ʱ�洢һ������,�����ڴ����Ĵ���,��Dict�洢��ÿ���̶߳�Ӧһ��
	OgdcDict<UGuint, UGByteArray*> m_dictDataSwap;
	UGMutex m_mutex;

	// ���������ģʽ��Hashcode��������Index��Map
	UGHashCodeMap m_HashCodeMap;
	
	// ������Կ
	UGbyte m_btXorOld[CF_KeyLength];

	// ��������������˵���洢���ݿ������(KeyString)����������new��
	// ���ڵ�һ�汾���ԣ�����洢���ǵķ�Unicodes�ı��롣����Unicode�汾��˵�����洢����Unicode������
	UGbyte m_pName[CF_NAMEBYTELEN];
	
	// �����Ϊ��ʱ��һ�黺������
	UGbyte m_pTemp[CF_NAMEBYTELEN];

	UGString m_strFilePath;
	UGString m_strPassword;
	UGOpenMode m_nOpenMode;
	UGCacheFile* m_pCacheFile;

	// UGulong �洢����To~~From��charset
	UGDict<UGulong, UGTextCodec*>m_dictTextCodec;

};


//! \brief �����ļ�������
class COMPACTFILE_API UGCompactFileReader
{
public:
	UGCompactFileReader();
	~UGCompactFileReader();

public:
	//! \brief	���ļ�
	//! \param	������&strPathin] ���ļ�·����
	//! \param	&strPwd[in] ����������
	//! \param	&eOpenMode[in] ���ļ���ģʽ��CF_OM_ForceDestroy ���ģʽOpen�ӿ��в�������,CF_OM_ReadWrite 
	//			CF_OM_ReadOnly��������ָ������һ�������û��ָ������Ĭ�ϰ���CF_OM_ReadWrite��
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	���ջ����ļ������Ѵ���
	//! \remarks ����CacheFile�ļ����� Open�ӿڡ�
	//! \remarks  �����һ��CacheFile��ֻͨ����չ����".sc"�����жϡ����������չ������ƽ����ʽ�򿪡�
	//! \remarks �������һ���ļ�strCFPath������չ���֣����Զ���������ϱ�׼��չ����UG_COMPACTFILE_EXT
	UGResult Open(const UGString& strPath, const UGString& strPwd = _U(""), UGCompactFile::UGOpenMode eOpenMode = UGCompactFile::CF_OM_ReadWrite);

	//! \brief	�ж��Ƿ��Ѿ����ļ���
	//! \return	�����Ƿ��Ѿ��򿪣��Ǹ�boolֵ������ֱ���ж� ��
	//! \remarks ����CacheFile�ļ����� IsOpen�ӿڡ�
	UGbool IsOpen();

	//! \brief	�ر��ļ�(��һ������Ҫ���ã�����������ʱ����Զ�����)
	//! \param ������Դ
	//! \return	�Ƿ�رճɹ�
	//! \remarks ����CacheFile�ļ����� Close�ӿڡ�
	UGbool Close();

	//! \brief	�Ӹ���������ʽ�Ľ����ļ��ж�ȡָ�����ļ�,�Զ���������ʽ��¼
	//! \param	nRow[in] ���������ļ����к�
	//! \param	nCol[in] ���������ļ����к�
	//! \param	&context[out] ��ȡ�Ķ�������
	//! \param	&lValidByte[out] context����Ч���ֽ���,���������context�ĳ�����lValidByte��ͬ,�����ǵ����ڵ����ļ��Ķϵ�����Ҫ��,ͨ���ò����������������Ƿ�����
	//! \param  nVersionNum[in]�汾�ţ����û�иð汾��ѯ�����ľ������°汾
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	�ò����������ڸ���������ʽ�Ľ����ļ�
	UGResult Lookup(UGuint nRow, UGuint nCol, UGByteArray &context, UGulong &lValidByte, const UGulong nVersionNum = 0);

	//! \brief	�Ӹ���������ʽ�Ľ����ļ��в�ѯָ�����ļ�,����������,����,�ļ����������쳣����״̬
	//! \param	nRow[in] ���������ļ����к�
	//! \param	nCol[in] ���������ļ����к�
	//! \return	���ر�ʶָ���ļ��ڽ����ļ��е�״̬ 
	//! \remarks	�ò����������ڸ���������ʽ�Ľ����ļ�
	UGCompactFile::UGStatus GetStatus(UGuint nRow, UGuint nCol);

private:
	UGResult ReadHeader();
	UGResult ReadHeaderGrid();

	UGbool ReadIndexValue(UGuint nRow, UGuint nCol, UGulong &nIdxValue);

private:
	// �ļ����
	UGFile32 m_fileHandle;

	UGCompactFile::UGOpenMode m_nOpenMode;
	UGCompactFile::CFHeader m_header;
	UGCompactFile::CFGridDataIndexHeader m_headerGrid;

	UGbool m_bNeedSwap;
	UGbool m_bOpend;

	// ������Կ
	UGbyte m_btXorOld[UGCompactFile::CF_KeyLength];

	UGString m_strFilePath;
	UGString m_strPassword;

};


//! \brief �����ļ�������
class COMPACTFILE_API UGCompactFileWriter
{
public:
	UGCompactFileWriter();
	~UGCompactFileWriter();

public:
	//! \brief	��������������ʽ�Ľ����ļ�����Ҫָ����������������һ��ָ���������޸�
	//! \param	&strCFPath[in] �����ļ�·����
	//! \param 	nRowNum[in] ���������ļ�������
	//! \param 	nColNum[in] ���������ļ�������
	//! \param 	&strPwd[in] ��������
	//! \param	&eOpenMode[in] ���ļ���ģʽ��CF_OM_ReadOnly��create�ӿ��в�������
	//			CF_OM_ReadWrite���û��ָ����Ҳ��Ĭ�ϴ��ϵ�
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks �������һ���ļ�strCFPath������չ���֣����Զ���������ϱ�׼��չ����UG_COMPACTFILE_EXT
	//! \remarks ��Ҫ������scΪ��β���ļ��������ᵼ�´��ж�ʧ�ܡ�
	UGResult Create(const UGString &strCFPath, UGuint nRowNum, UGuint nColNum, const UGString &strPwd=_U(""), UGCompactFile::UGOpenMode eOpenMode = UGCompactFile::CF_OM_ReadWrite);

	//! \brief	���ļ�
	//! \param	������&strPathin] ���ļ�·����
	//! \param	&strPwd[in] ����������
	//! \param	&eOpenMode[in] ���ļ���ģʽ��CF_OM_ForceDestroy ���ģʽOpen�ӿ��в�������,CF_OM_ReadWrite 
	//			CF_OM_ReadOnly��������ָ������һ�������û��ָ������Ĭ�ϰ���CF_OM_ReadWrite��
	//! \return	���ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	���ջ����ļ������Ѵ���
	//! \remarks ����CacheFile�ļ����� Open�ӿڡ�
	//! \remarks  �����һ��CacheFile��ֻͨ����չ����".sc"�����жϡ����������չ������ƽ����ʽ�򿪡�
	//! \remarks �������һ���ļ�strCFPath������չ���֣����Զ���������ϱ�׼��չ����UG_COMPACTFILE_EXT
	UGResult Open(const UGString& strPath, const UGString& strPwd = _U(""), UGCompactFile::UGOpenMode eOpenMode = UGCompactFile::CF_OM_ReadWrite);

	//! \brief	�ж��Ƿ��Ѿ����ļ���
	//! \return	�����Ƿ��Ѿ��򿪣��Ǹ�boolֵ������ֱ���ж� ��
	//! \remarks ����CacheFile�ļ����� IsOpen�ӿڡ�
	UGbool IsOpen();

	//! \brief	�ر��ļ�(��һ������Ҫ���ã�����������ʱ����Զ�����)
	//! \param ������Դ
	//! \return	�Ƿ�رճɹ�
	//! \remarks ����CacheFile�ļ����� Close�ӿڡ�
	UGbool Close();

	//! \brief	�����������ʽ�Ľ����ļ������һ����������
	//! \param	nRow[in] ���������ļ����к�
	//! \param	nCol[in] ���������ļ����к�
	//! \param	&context[in] Ҫ��ӵ�����
	//! \param	lDataSize[in] ��ʾcontext�������ݵĴ�С.���Ƕϵ����������,���context��ʾ�����ݲ�����,ҲҪд�������ļ���
	//! \param	lOffset[in] ��ʾcontextд����ջ���ʱ��ƫ��λ
	//! \param  nVersionNum[in] �汾��
	//! \return	����ֵ�����ؽ����(������״̬)��ע�⣬Ҫ��UGE_SUCCESS(0)�жϣ�����ֱ�ӵ�Bool�жϣ���Ϊ�����ȫ�෴��
	//! \remarks	ע�⣺�ò����������ڸ���������ʽ�Ľ����ļ�.ͬʱ�÷���Ҳ֧�����ô�ɫ������,�����ֽ����ĳ���С��64λʱ,�ֽ����ĳ��ȱ�ʾ��ɫ��λ��,�ֽ��������ݱ�ʾ��ɫֵ.
	UGResult SetAt(UGuint nRow, UGuint nCol, const UGByteArray & context, UGulong lDataSize = 0, UGulong lOffset = 0, const UGulong nVersionNum = 0);

	//! \brief	�Ӹ���������ʽ�Ľ����ļ��в�ѯָ�����ļ�,����������,����,�ļ����������쳣����״̬
	//! \param	nRow[in] ���������ļ����к�
	//! \param	nCol[in] ���������ļ����к�
	//! \return	���ر�ʶָ���ļ��ڽ����ļ��е�״̬ 
	//! \remarks	�ò����������ڸ���������ʽ�Ľ����ļ�
	UGCompactFile::UGStatus GetStatus(UGuint nRow, UGuint nCol);

	UGString GetFilePath();

private:
	UGResult ReadHeader();
	UGResult ReadHeaderGrid();
	UGResult WriteHeader();
	UGResult WriteHeaderGrid(UGuint nRowNum, UGuint nColNum);

	UGbool WriteIndexValue(UGuint nRow, UGuint nCol, UGulong nIdxValue);
	UGbool ReadIndexValue(UGuint nRow, UGuint nCol, UGulong &nIdxValue);

	//! \brief ���������
	//! \param stauts[out]״̬
	//! \param context[in]Ҫ����ӵ�����
	//! \param DataSize[in]���ݴ�С
	//! \param nOffset[in]ƫ��
	//! \param nVersionNum[in]�汾��
	//! \param strKeyString[in]ֻ����Namingģʽ�����������,namingģʽ������
	UGulong WriteDataToFile(UGCompactFile::UGStatus& status, const UGByteArray& context, UGulong nDataSize, UGulong nOffset, UGulong nVersionNum, UGulong nDataPos);

	//! \brief �Ƿ������ð汾
	UGbool IsVersionEnabled();

	//!\ brief �ѻ����е�����д���ļ�
	UGbool Flush();

private:
	// �ļ����
	UGFile32 m_fileHandle;

	UGCompactFile::UGOpenMode m_nOpenMode;
	UGCompactFile::CFHeader m_header;
	UGCompactFile::CFGridDataIndexHeader m_headerGrid;

	UGbool m_bNeedSwap;
	UGbool m_bOpend;

	// ������Կ
	UGbyte m_btXorOld[UGCompactFile::CF_KeyLength];

	UGString m_strFilePath;
	UGString m_strPassword;

};

}

#endif

