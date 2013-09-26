//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class ��
//!  \details ��
//!  \author linwenyu��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGFILEPARSE_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
#define AFX_UGFILEPARSE_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_

#include "FileParser/UGFileParserConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{

//! \brief �ļ�����ࡣ
//! \remarks �����й��ļ��Ĳ㶼Ҫ�̳д��ࡣ
class FILEPARSER_API UGFileLayer
{
public:
	enum FILELAYER_TYPE
	{
		FL_VECTOR,//ʸ����Layer
		FL_RASTER,//դ���Layer
		FL_CONFIG,//�����ļ�Layer
		FL_OTHER,//������Layer
	};
public:
	virtual FILELAYER_TYPE GetType() = 0;
};

//! \brief �ļ��������ࡣ
//! \remarks �����й��ļ������Ķ�Ҫ�̳д��ࡣ
class FILEPARSER_API UGFileParser  
{
public:

	//! \brief ���캯����
	UGFileParser();

	//! \brief ����������
	virtual ~UGFileParser();
	
public:
	//! \brief ���ļ���
	//! \param impParams [in]��
	//! \return �ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention ��ȡ�ļ�ǰ���á�
	virtual UGbool Open(const UGImportParams& impParams) = 0;
	
	//! \brief �ر��ļ�	
	virtual void Close() = 0;

	//! \brief �����ļ���ʽ�����ж����ָ�ʽ������һ���顣
	virtual UGFileType::EmGroup GetFileGroup() const = 0; 		

	//! \brief ��FMEWorkBench�ķ�ʽ����
	//! \param ע��˽ӿ����ҽ���FMEWorkBench�ĵ��뷽ʽʹ��  �������ʹ�� 
	virtual UGint ImportByFMEWorkBench(const UGImportParams& impParams, UGString& resultFilePath){return -1;}
public:	
	//! \brief ��ȡԴ���ݵĿռ�����ϵ��
//	virtual const UGPrjCoordSys* GetSpatialRef();	

	//! \brief ��ȡԴ�����е����ݼ���Ŀ��
	//! \param  [in]��
	virtual UGint GetLayerCount();

	//! \brief ͨ�������õ�Դ�����е�һ�����ݼ���
	//! \param nlayer [in]��
	virtual UGFileLayer* GetLayer(UGint nlayer);	
	
public:
	//! \brief �ļ��Ƿ�򿪡�
	//! \param  [in]��
	UGbool IsOpen() const;	
	
	//! \brief �Ƿ���ʸ�����͡�
	UGbool IsVector() const; 	
	
	//! \brief �Ƿ���դ�����͡�
	UGbool IsRaster() const; 
	
	//! \brief �Ƿ��ǹ����ռ����͡�
	UGbool IsWorkspace() const; 	
	
protected:
	
	//! \brief �ļ��򿪱�־��
	UGbool m_bOpen;

};

} //namespace UGC

#endif // !defined(AFX_UGFILEPARSE_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)

