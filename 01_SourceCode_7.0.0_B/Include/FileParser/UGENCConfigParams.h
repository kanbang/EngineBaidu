// UGFileParserConfigParams.h: interface for the UGFileParserConfigParams class.
//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author zhongdz
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG_ENC_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_ENC_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC {




//! \brief ENC(���Ӻ�ͼ)�ĵ���������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGENCImportParams : public UGVectorImportParams
{	
public:
	//! \brief ���캯����
	//! \param ��
	UGENCImportParams();

public:
	enum emOptions
	{
		UPDATES					 = 0x01,
		//LNAM_REFS                = 0x02, // �����ſ���
		//SPLIT_MULTIPOINT         = 0x04, // �����ſ���
		//ADD_SOUNDG_DEPTH         = 0x08, // �����ſ���
		//PRESERVE_EMPTY_NUMBERS   = 0x10, // �����ſ���
		//RETURN_PRIMITIVES        = 0x20,
		//RETURN_LINKAGES          = 0x40, // �����ſ���
		//RETURN_DSID              = 0x80,
	};

	//! \brief ���ص�ǰ��ʽת���������͡�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const { return UGFileType::ENC; }

	//! \brief �õ��Ƿ����������
	//! \return TRUE �������
	//! \return FALSE ���������
	UGbool GetImportUpdate()
	{
		return ( (m_nOption & UPDATES ) != 0 );
	}
	
	//! \brief �����Ƿ����������
	//! \param [in] �Ƿ����������
	void SetImportUpdate(UGbool bUpdate = TRUE)
	{
		if(bUpdate)
			m_nOption |= UPDATES;
		else 
			m_nOption &= ~UPDATES;
	}

// 	//! \brief �õ��Ƿ����һ����¼��ȵ��ֶ�
// 	//! \return TRUE ����ֶ�
// 	//! \return FALSE ������ֶ�
// 	UGbool GetAddSoundDepth()
// 	{
// 		return ( (m_nOption & ADD_SOUNDG_DEPTH ) != 0 );
// 	}
// 	
// 	//! \brief �����Ƿ����һ����¼��ȵ��ֶ�
// 	//! \param [in] �Ƿ�����ֶ�
// 	void SetAddSoundDepth(UGbool bAdd)
// 	{
// 		if(bAdd)
// 			m_nOption |= ADD_SOUNDG_DEPTH;
// 		else 
// 			m_nOption &= ~ADD_SOUNDG_DEPTH;
// 	}

// 	//! \brief �õ��Ƿ������ֶ�
// 	//! \return TRUE ����
// 	//! \return FALSE ������
// 	UGbool GetPreserveEmptyNumbers()
// 	{
// 		return ( (m_nOption & PRESERVE_EMPTY_NUMBERS ) != 0 );
// 	}
// 	
// 	//! \brief �����Ƿ������ֶ�
// 	//! \param [in] �Ƿ���
// 	void SetPreserveEmptyNumbers(UGbool bPreserve)
// 	{
// 		if(bPreserve)
// 			m_nOption |= PRESERVE_EMPTY_NUMBERS;
// 		else
// 			m_nOption &= ~PRESERVE_EMPTY_NUMBERS;
// 	}

// 	//! \brief �õ��Ƿ���ռ��������
// 	//! \return TRUE ����
// 	//! \return FALSE ������
// 	UGbool GetReturnPrimitives()
// 	{
// 		return ( (m_nOption & RETURN_PRIMITIVES ) != 0 );
// 	}
// 	
// 	//! \brief �����Ƿ���ռ��������
// 	//! \param [in] �Ƿ���
// 	void SetReturnPrimitives(UGbool bReturn)
// 	{
// 		if( bReturn )
// 			m_nOption |= RETURN_PRIMITIVES;
// 		else
// 			m_nOption &= ~RETURN_PRIMITIVES;
// 	}

// 	//! \brief �õ��Ƿ������ݼ�������Ϣ�����ݼ���S57�ĸ��һ��ָ����һ���ļ���
// 	//! \return TRUE ����
// 	//! \return FALSE ������
// 	UGbool GetReturnDSID()
// 	{
// 		return ( (m_nOption & RETURN_DSID ) != 0 );
// 	}
// 	
// 	//! \brief �����Ƿ������ݼ�������Ϣ
// 	//! \param [in] �Ƿ���
// 	void SetReturnDSID(UGbool bReturn = TRUE )
// 	{
// 		if( bReturn )
// 			m_nOption |= RETURN_DSID;
// 		else 
// 			m_nOption &= RETURN_DSID;
// 	}

	//! \brief ��ȡĿ¼���ŵ�·��
	virtual const UGString& GetCatoFileDir() const { return m_CatoFileDir ;}

	//! \brief ��ȡĿ¼���ŵ�·��
	virtual void SetCatoFileDir(const UGString &strDir )
	{ 
		m_CatoFileDir =  strDir;
	}

// 	//! \biref ��ȡ�Ƿ�ʹ�ñ��ػ������ݼ�����
// 	UGbool IsUseNativeDatasetName() const{ return m_bUseNativeDatasetName; }
// 	//! \biref ����ʹ�ñ��ػ������ݼ�����
// 	void UseNativeDatasetName(UGbool bNativeDatasetName)
// 	{
// 		m_bUseNativeDatasetName = bNativeDatasetName;
// 	}

	UGbool IsConvertToMercatorProjection() const;
	void ConvertToMercatorProjection(UGbool bMercator);

private:
	//! \brief Ŀ¼���ŵ�Ŀ¼
	UGString m_CatoFileDir; //���Ŀ¼��
	//! \brief 
	UGuint m_nOption;

	//! \brief �Ƿ�ʹ�ñ������Ե����ݼ�����
	//! \remarks S57����ʹ��
	// UGbool m_bUseNativeDatasetName;
	//! \brief DSNMֵ��Ӧ��һ����ʶ��
	//! \remarks S57ʹ��
	UGushort m_nDSNMCode;
	//! �Ƿ��ڵ���ʱ������ת����ī����ͶӰ��
	UGbool m_bConvertToMercator;
};


//! \brief ENC(���Ӻ�ͼ)�ĵ����������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGENCExportParams : public UGVectorExportParams
{
public:

	//! \brief ���캯����
	//! \param ��
	UGENCExportParams();

	//! \brief ���ص�ǰ��ʽת���������͡�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual inline UGint GetFileType() const { return UGFileType::ENC; }

	//! \brief ��ȡĿ¼���ŵ�·��
	virtual const UGString& GetCatoFileDir() const { return m_CatoFileDir ;}

	//! \brief ��ȡĿ¼���ŵ�·��
	virtual void SetCatoFileDir(const UGString &strDir )
	{ 
		m_CatoFileDir =  strDir;
	}

	//! \brief
	virtual void SetDtNameToBeExported(const UGString& name);

	//! \brief ��ȡҪ������ʸ�����ݼ��������顣
	//! \param  [in]��
	//! \return ��
	//! \remarks ���ݼ��������顣
	//! \attention Ϊ�˶�����ݼ�����ʹ�á�
	virtual UGbool GetDtNamesBeExported(UGStrings& arrNames) const ;

	//! \brief ����Ҫ������ʸ�����ݼ��������顣
	//! \param  name [in] ���õ����ơ�
	//! \return ��
	//! \remarks ��
	//! \attention Ϊ�˶�����ݼ�����ʹ�á�
	virtual void SetDtNamesBeExported(const UGStrings& arrNames);

private:
	//! \brief Ҫ���������ݼ���������
	UGStrings m_arrNames;

	//! \brief Ŀ¼���ŵ�Ŀ¼
	UGString m_CatoFileDir; //���Ŀ¼��
	
};

} //namespace UGC
#endif // !defined(AFX_UG_MITAB_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

