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
//!  \author linwenyu��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGFILEPARSERCONFIGPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_)
#define AFX_UGFILEPARSERCONFIGPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_

#include "Projection/UGPrjCoordSys.h"
#include "Element/OgdcFieldInfo.h"
#include "Geometry/UGDataCodec.h"
#include "Geometry/UGFeature.h"

namespace UGC {

//! \brief ת���������ࡣ
class FILEPARSER_API UGExchangeParams  
{
	friend class UGExchangeParamsManager;
	friend class UGFileParseToolkit;

public:
	
	//! \brief ���캯����
	UGExchangeParams();
	
	//! \brief ����������
	virtual ~UGExchangeParams();

public:
	
	//! \brief ���������ļ���	
	//! \param strFilePathName  �ļ�ȫ·����[in]
	void SetFilePathName(const UGString& strFilePathName);	
	
	//! \brief �õ������ļ��� 	
	//! \param  [in]��
	//! \return �ļ�ȫ·����
	UGString GetFilePathName() const;

	//! \brief �õ��Ƿ�ʹ�õ���FME����ģʽ��
	//! \param  [out]��
	//! \return �Ƿ�
    UGbool GetIsUseFME() const;

	//! \brief �����Ƿ�ʹ�õ���FME����ģʽ��
	//! \param  [in]��
	//! \return �Ƿ�
	void SetIsUseFME(UGbool bIsUserFME = FALSE);
	
	//! \brief �õ��ļ����͡�
	//! \param  [in]��
	//! \return �ļ����͡�
	//! \remarks ���������Լ�ʵ�֡�
	virtual inline UGint GetFileType() const {return 0;}

public:

	//! \brief �����Ƿ���ʾ���ȡ�
	//! \param TRUE  ��ʾ���ȡ�[in]
	void SetShowProgress(UGbool bProgress = TRUE);	

	//! \brief �õ��Ƿ���ʾ���ȡ�
	UGbool GetShowProgress() const;	

	//! \brief �����Ƿ�ǿ�Ƹ��ǡ�
	void SetOverWrite(UGbool bOverwrite= TRUE);

	//! \brief �õ��Ƿ�ǿ�Ƹ��ǡ�
	UGbool GetOverWrite() const;

	////! \brief ���ûص�������Ϣ
	//void SetProgressProcFun(void* ProgressProcFun){m_pProgressProcFun=ProgressProcFun;};

	//void* GetProgressProcFun() const{return m_pProgressProcFun;};
	
	//! \brief �жϵ�ǰʹ�õ�ת�������Ƿ��ǵ��������
	//! \param  [in]��
	//! \return ��
	//! \remarks ��Ҫ����ת�������Ϸ��Լ�飬��GetFileType���ʹ�ã������жϳ���ǰʹ��
	//!          �Ĳ����Ƿ���ָ���ļ����͵ĵ��������
	//! \attention ��
	virtual inline UGbool IsImportParams() const {return FALSE;};
	
	//! \brief �жϵ�ǰʹ�õ�ת�������Ƿ��ǵ���������
	//! \param  [in]��
	//! \return ��
	//! \remarks ��Ҫ����ת�������Ϸ��Լ�飬��GetFileType���ʹ�ã������жϳ���ǰʹ��
	//!          �Ĳ����Ƿ���ָ���ļ����͵ĵ���������
	//! \attention ��
	virtual inline UGbool IsExportParams()  const {return FALSE;};

	UGString::Charset GetImportOrExportCharset() const;
	//! \brief ���õ��뵼�����룬ĳЩ�ļ������ǲ������޸ĵģ������ļ����Ͷ�����
	virtual UGbool SetImportOrExportCharset(UGString::Charset Charset);
	
protected:

	
	enum ExchangeOptions
	{	
		//! \brief ��ʾ����
		ShowProgress			= 0x00000001,	
		//! \brief �������ԣ�ʸ������������Ϣ��դ�����ݵ����Ա�
		IgnoreAttribute			= 0x00000002,				
		//! \brief ��������ϵͳ		
		IgnoreCoordSys			= 0x00000004,		
		//! \brief ���Կ����ݣ�û�пռ����ݵ�Ҫ�أ���mif��ʽ		
		IgnoreEmptySpatialData = 0x00000008,
		//! \brief ���ռ�����		
		BuildSpatialIndex		= 0x00000010,		
		//! \brief ����CAD�����еġ��顱��DGN�����еġ���Ԫ��
		IgnoreSymbol			= 0x00000020,			
		//! \brief ���Է��
		IgnoreStyle				= 0x00000040,			
		//! \brief ����Ϊ�ನ��
		ImportAsMultiBands		= 0x00000080,	
		//! \brief �Զ�����Ӱ�������	
		AutoBuildPyramid		= 0x00000100,		
		//!	\brief �Ƿ���ⲿ�ļ���ȡͶӰ
		SpatialRefFromFile		= 0x00000200,	
		//! \brief ��������
		IgnoreTopo				= 0x00000400,
		//! \brief �Ƿ��յ����ζ�ȡ����
		ReadAsOneBand			= 0x00000800,
		//! \brief �Ƿ���ǿ��λ��ת������
		ForcePixelEnable		= 0x00001000,
	};

	//! \brief ���뵼���ַ�����
	//         ��������ļ���Ĭ�Ϻ�m_FileCharset����һ�£��ⲿ�û��������á�
	//		   ��������ļ�����������ǵ�ǰϵͳ��������ļ��ı��룬���ݵ�ǰ�ļ��ĸ�ʽ��ĳЩ�ļ����ͣ������޷��޸ġ�			
	UGString::Charset m_ImportOrExportCharset;	


	//! \brief ��¼�ļ�·����û�б��,�������Ϊ���ݵ����ʱ�򣬶�ȡ�ļ������õġ�
	//         ͨ��������������ļ���ȡ�����ʱ��Ͳ����ظ����ļ���
	UGbool m_bFileChange;	
	
	//! \brief �ļ�·��
	UGString m_strFilePathName;

	
	//! \brief ת���е�ѡ�
	//! \remarks ֻ����ExchangeOptions�е�ѡ�� ��
	UGuint m_nOption;

	//! \brief ������������
	//! \remarks
	UGbool m_bOverWrite;

	//! \brief �Ƿ�ʹ��FME�ķ�ʽ����
	UGbool m_bIsUseFME;

	//void* m_pProgressProcFun;

};



//////////////////////////////////////////////////////////////////////////
// import
//////////////////////////////////////////////////////////////////////////

//! \brief ���������
class FILEPARSER_API UGImportParams : public UGExchangeParams
{
	friend class UGExchangeParamsManager;

public:
	
	//! \brief ���캯����
	UGImportParams();
	
	//! \brief ����������
	virtual ~UGImportParams();

	//! \brief ���ظ�ֵ=��
	UGImportParams& operator=(const UGImportParams& imp);	

public:
	
	// \brief ����ģʽ��
	enum ImportMode
	{
		ModeGIS		= 0,// ����Ϊ�����ݼ�
		ModeCAD		= 1,// ����Ϊ�������ݼ�
		ModeIMG		= 2,// ����ΪIMG���ݼ�
		ModeGrid	= 3,// ����ΪGrid���ݼ�
		ModeDEM		= 4,// ����ΪDem���ݼ�		
	};

	//! \brief ���õ���ģʽ��
	//! \param impMode ����ģʽ��[in]
	void SetImportMode(UGint nimpMode);	

	//! \brief �õ�����ģʽ��
	//! \param  [in]��
	//! \return ����ģʽ��
	UGint GetImportMode() const;

	//! \brief ��ȡ�Ƿ�����û����ò�������
	UGbool GetIsUserSetting(){return m_bUserSetting;}
	
	//! \brief ����׷�ӵ���
	//! \param bAppend �Ƿ�׷�ӵ���[in]
	//! \attention ��������������󽫺����Ƿ񸲸����ݼ��Ĳ�������
	void SetAppend(UGbool append = TRUE);

	//! \brief �õ��Ƿ�׷�ӵ���
	UGbool GetAppend() const;

	//! \brief �����Ƿ�������ԡ�
	//! \param FALSE  �Ƿ�������ԡ�[in]
	//! \remarks ����ʸ������������Ϣ��դ������դ�����Ա�
	void SetIgnoreAttribute(UGbool bIgonreAttribue = FALSE);

	//! \brief �õ��Ƿ�������ԡ�
	//! \param   �Ƿ�������ԡ�[in]
	//! \return �Ƿ�������ԡ�
	UGbool GetIgnoreAttribute() const;	


	//! \brief �����Ƿ��������ϵͳ��
	//! \param TRUE �Ƿ��������ϵͳ��[in]
	void SetIgnoreCoordSys(UGbool bIgnoreCoordSys = FALSE);	

	//! \brief �õ��Ƿ��������ϵͳ��
	//! \param  [in]��
	//! \return �Ƿ��������ϵͳ��
	UGbool GetIgnoreCoordSys() const;	

	//! \brief ���������Ŀ�����ݼ�������ϵͳ��	
	//! \param spatialRef [in]��
	//! \remarks ������Ϊ�����д����ͶӰ�����ݵ���ʵͶӰ��
	//!          ��������ͶӰ�Ƿ�һ�£�����ͶӰת����������ͶӰ����
	void SetDestCoordSys(const UGPrjCoordSys& spatialRef);	

	//! \brief �������ϵͳ
	//! \param  [in]��
	//! \return �õ�����ϵͳ�ɹ�������TRUE��
	UGPrjCoordSys* GetDestCoordSys() const;
	
	//! \brief �������ݱ��뷽ʽ
	//! \param encType ���뷽ʽ�� [in]
	void SetDatasetEncType(UGDataCodec::CodecType encType);	

	//! \brief �õ����ݱ��뷽ʽ��
	//! \param  [in] ��
	//! \return ���ݱ��뷽ʽ��
	UGDataCodec::CodecType GetDatasetEncType() const;

	//! \brief ����Ŀ�����ݼ�����
	//! \param strDTName Ŀ�����ݼ�����[in]
	void SetDestDTName(const UGString& strDTName);

	//! \brief ��ȡĿ�����ݼ�����
	//! \return Ŀ�����ݼ�����
	UGString GetDestDTName() const;

	//! \brief �жϵ�����ȫͼ���߶�㵼�롣
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual UGbool GetImportByLayer() const{return FALSE;}

	//! \brief ��ȡ�����ļ�����,����ļ��������ã����Ҫ���»�ȡ��ͬʱGetImportOrExportCharset
	//         �п��ܱ����
	// �����ʽû�й涨ʹ���ض��ı��룬��ô�Ͳ����û����õı���
	virtual UGString::Charset GetFileCharset();

protected:
	
	
	//! \brief �жϵ�ǰʹ�õ�ת�������Ƿ��ǵ��������
	//! \remarks ��Ҫ����ת�������Ϸ��Լ�飬��GetFileType���ʹ�ã������жϳ���ǰʹ��
	//!          �Ĳ����Ƿ���ָ���ļ����͵ĵ��������
	virtual inline UGbool IsImportParams() const {return TRUE;};
	
	//! \brief �жϵ�ǰʹ�õ�ת�������Ƿ��ǵ���������
	//! \remarks ��Ҫ����ת�������Ϸ��Լ�飬��GetFileType���ʹ�ã������жϳ���ǰʹ��
	//!          �Ĳ����Ƿ���ָ���ļ����͵ĵ���������
	virtual inline UGbool IsExportParams()  const {return FALSE;};


protected:

	//! \brief ����ģʽ��
	ImportMode m_ImportMode;
	
	//! \brief �Ƿ�Ϊ׷�ӵ���
	UGbool m_bAppend;
	
	//! \brief ������ݼ����뷽ʽ
	UGDataCodec::CodecType m_encType;

	//! \brief Ŀ������ϵͳ��
	UGPrjCoordSys* m_pSpatialRef;	

	//! \brief �Ƿ�����û����ã�Ĭ��ΪFalse����ʱȫ����Ĭ�ϵ���
	//         ���û�����SetImportDatasetInfosʱ�������û�����
	UGbool m_bUserSetting;

	//! \brief Ŀ�����ݼ�����
	UGString m_strDTName;
	//! \brief ��Ե����ļ��ı��룬����������Զ�����ļ�����֮�󣬴洢�ļ��ı��롣
	UGString::Charset m_FileCharset;
private:


};


//////////////////////////////////////////////////////////////////////////


//! \brief ����������
class FILEPARSER_API UGExportParams : public UGExchangeParams
{
	friend class UGExchangeParamsManager;

public:

	//! \brief ���캯����
	UGExportParams();

	//! \brief ����������
	virtual ~UGExportParams();
	
	//! \brief ���ظ�ֵ=��
	//! \param imp [in]��
	UGExportParams& operator=(const UGExportParams& exp);	


	
protected:	
	
	//! \brief �жϵ�ǰʹ�õ�ת�������Ƿ��ǵ��������
	//! \remarks ��Ҫ����ת�������Ϸ��Լ�飬��GetFileType���ʹ�ã������жϳ���ǰʹ��
	//!          �Ĳ����Ƿ���ָ���ļ����͵ĵ��������
	virtual inline UGbool IsImportParams() const {return FALSE;}
	
	//! \brief �жϵ�ǰʹ�õ�ת�������Ƿ��ǵ���������
	//! \remarks ��Ҫ����ת�������Ϸ��Լ�飬��GetFileType���ʹ�ã������жϳ���ǰʹ��
	//!          �Ĳ����Ƿ���ָ���ļ����͵ĵ���������
	virtual inline UGbool IsExportParams()  const {return TRUE;}
	
};

} //namespace UGC
#endif // !defined(AFX_UGFILEPARSERCONFIGPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_)

