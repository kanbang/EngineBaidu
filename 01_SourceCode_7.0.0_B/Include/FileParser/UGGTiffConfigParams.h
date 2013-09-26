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
//!  \author linwenyu��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG_GTIFF_FILEPARSERCONFIGPARAMS_H__INCLUDED_)
#define AFX_UG_GTIFF_FILEPARSERCONFIGPARAMS_H__INCLUDED_

#include "FileParser/UGRasterConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{


//! \brief GeoTiff�ĵ���������á�
class FILEPARSER_API UGGTiffImportParams : public UGRasterImportParams
{
	
public:

	//! \brief ���캯����
	UGGTiffImportParams();

	//! \brief ��ȡ�ļ����͡�
	//! \return ����GTiff���͡�
	virtual inline UGint GetFileType() const { return UGFileType::GTiff; }

	//! \brief ��ȡҪ����Ĳ���������
	//! \return ����Ҫ����Ĳ���������
	UGArray<UGint> GetImportBandIndexs(){return m_arrBandsRaster;}

	//! \brief ǿ������Ҫ����Ĳ���������
	//! \param  [in] Ҫ����Ĳ���������
	void SetImportBandIndexs(const UGArray<UGint>& indexs){m_arrBandsRaster.Copy(indexs);}

	//! \brief �������ɵĵ��������ļ���·����
	//! \param strWorldFile [in]��
	void SetWorldFilePath(const UGString& strWorldFile) { m_strWorldFile = strWorldFile; }

	//! \brief �õ����������ļ�·��
	//! \param strWorldFile [in]��
	UGString GetWorldFilePath() const { return m_strWorldFile; }

protected:

	//! \brief  Ŀ�����ݼ����ظ�ʽ
	PixelFormat m_nPixelFormat;

	//! \brief ѡ����Ĳ���������
	UGArray <UGint> m_arrBandsRaster;

	//! \brief ����ο��ļ�
	UGString m_strWorldFile;

};


//! \brief GeoTIFF�ĵ����������á�
class FILEPARSER_API UGGTiffExportParams : public UGRasterExportParams
{
public:

	//! \brief ���ڷ�����������ô���
	enum EmExpTran{
		//! \brief �������κη�������
		ET_NOEXP,
		//! \brief ������tif�ļ��ڲ�
		ET_INNER,
		//! \brief ������tfw
		ET_OUTER
	};

	//! \brief ���ڷ�����������ô���
	enum EmExpPrj{
		//! \brief �������κ�����ϵ����
		EP_NOEXP, 
		//! \brief ������tif�ļ��ڲ�
		EP_INNER,
		//! \brief ������prj
		EP_OUTER
	};

	//! \brief ���ڵ����ɶನ�ε�ǿ������
	enum EmExpMB{
		//! \brief ���ı�ԭͼ������
		EMB_SAME, 
		//! \brief ǿ�Ƶ���������
		EMB_SBIMG,
		//! \brief ǿ�Ƶ����ನ��
		EMB_MBIMG
	};

public:

	//! \brief ���캯����
	UGGTiffExportParams();

	//! \brief ��ȡ�ļ����͡�
	//! \param  [in]��
	//! \return ����GTiff���͡�
	virtual inline UGint GetFileType() const{ return UGFileType::GTiff; }

	//! \brief ��ȡ���������������͡�
	inline EmExpTran GetExportTranType() const  {return m_eExportTran;}

	//! \brief ��ȡ����ͶӰ����ϵ���͡�
	inline EmExpPrj GetExportPrjType() const  {return m_eExportPrj;}
	
	//! \brief ��ȡ����ͶӰ����ϵ���͡�
	inline void SetExportTranType(EmExpTran ttype) {m_eExportTran = ttype;}

	//! \brief ��ȡ����ͶӰ����ϵ���͡�
	inline void SetExportPrjType(EmExpPrj ptype) {m_eExportPrj = ptype;}

	//! \brief ��ȡ�Ƿ�ǿ�Ƶ����ɶನ�Ρ�
	inline EmExpMB GetExportMuliBand() const  {return m_eExpMuliBand;}
	
	//! \brief ����ǿ�Ƶ����ನ�Ρ�
	inline void ExportMuliBand(EmExpMB mbtype) {m_eExpMuliBand = mbtype;}


	//! \brief ����ͼ��ķֱ���/DPI.
	//! \param ndpi [in] ͼ���DPI��
	//! \remarks �˽ӿ����ڵ�ͼ��ͼ��
	//! \attention 
	virtual void SetResolution(UGint ndpi) {m_ndpi=ndpi;};

	////! \brief ����ͼ��ķֱ���/DPI.
	//! \param ��
	//! \remarks ��
	//! \attention ����ĸ�ʽ���ò�����Ҫ��д�˺�����
	virtual UGint GetResolution() {return m_ndpi;};

protected:

	UGint m_ndpi;

private:
	
	//! \brief ���õ��������������͡�
	EmExpTran m_eExportTran;

	//! \brief ���õ���ͶӰ����ϵ���͡�
	EmExpPrj m_eExportPrj;

	//! \brief �����Ƿ񵼳��ɶನ��
	EmExpMB m_eExpMuliBand;

private:
};

} //namespace UGC
#endif // !defined(AFX_UG_GTIFF_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

