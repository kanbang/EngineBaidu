/*! \file	 UGDatasetRasterInfo.h
 *  \brief	 դ�����ݼ���Ϣ����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDatasetRasterInfo.h,v 1.20 2009/11/05 09:22:22 siyh Exp $
 */

#ifndef UGDATASETRASTERINFO_H
#define UGDATASETRASTERINFO_H

#include "Geometry/UGDataCodec.h"

#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined (IOS)
#include "OGDC/OgdcDatasetRasterInfo.h"
#endif

namespace UGC {

class ENGINE_API UGBandInfo
{
public:
	UGBandInfo();
	
	//! \brief ��������
#ifdef SYMBIAN60
	~UGBandInfo();
#else
	virtual ~UGBandInfo();
#endif
	
	void operator=(const UGBandInfo& bInfo);

	//! \brief �������ݿ�������
	UGint m_nBandID;
	//! \brief ��������
	UGint m_nIndex;
	//! \brief ���ε�����
	UGString m_strName;
	//! \brief �������ڵ�����
	UGString m_strFieldName;
	//!��ǰ�����Ƿ���Ч
	UGbool m_bAvail;
	//! \brief ���ε�������Ϣ
	UGString m_strDescription;
	//! \brief ���εĸ�����Ϣ
	UGString m_strExtInfo;
	//! \brief ���ε�Ӱ�����ֽ���
	UGint m_nWidthBytes;
	//! \brief ѡ����Ϣ
	UGint m_nOptions;
	//! \brief ���ݱ�������
	UGDataCodec::CodecType m_nCodecType;
	//! \brief ��άBounds����Сֵ
	UGdouble m_dMinZ;
	//! \brief ��άBounds�����ֵ
	UGdouble m_dMaxZ;
	//! \brief ��ɫ��
	UGColorset m_Colorset;
	//! \brief ���blockSize
	UGint m_nMaxBlockSize;
 	//! \brief ��ǰ���α����֣���Ҫ��������ӵ����ظ�ʽ
 	UGint m_nScalar;
	
	inline UGdouble GetNoValue() const { return m_dbNoValue; };

	void SetNoValue(UGdouble dNoValue, UGbool bCheck = FALSE);

	inline OGDC::PixelFormat GetPixelFormat() const { return m_ePixelFormat; };

	void SetPixelFormat(OGDC::PixelFormat pixelFormat);

private:

	//! \brief ��Чֵ�����ĳһ���ֵ��m_NoValue,����Ϊ��һ��û��ֵ
	UGdouble m_dbNoValue;

	//! \brief ��ʶ�û��Ƿ���������ֵ
	UGbool m_bIsSetNoValue;

	//! \brief ���ε����ظ�ʽ
	OGDC::PixelFormat m_ePixelFormat;
};
	
//! \brief դ�����ݼ���Ϣ
//##ModelId=48203054004E
class ENGINE_API UGDatasetRasterInfo  
{
public:
	
	//! \brief Ӱ����Сѡ��
	//##ModelId=48203054008F
	enum IBSizeOption 
	{
		//! \brief 64*64
		//##ModelId=482030540091
		IBS_64				= 64,
		//! \brief 128*128
		//##ModelId=48203054009C
		IBS_128				= 128,
		//! \brief 256*256
		//##ModelId=48203054009D
		IBS_256				= 256,
		//! \brief 512*512
		//##ModelId=48203054009E
		IBS_512				= 512,
		//! \brief 1024*1024
		//##ModelId=48203054009F
		IBS_1024			= 1024,
		//! \brief 2048*2048
		//##ModelId=4820305400A0
		IBS_2048			= 2048,	
		//! \brief 4096*4096
		//##ModelId=4820305400AB
		IBS_4096			= 4096,	
		//! \brief 8192*8192
		//##ModelId=4820305400AC
		IBS_8192			= 8192	
	};

	
public:
	//! \brief ���캯��
	//##ModelId=48203054004F
	UGDatasetRasterInfo();

	UGDatasetRasterInfo(UGString strName, UGString strTableName, UGint nType, UGint nWidth, UGint nHeight, 
		IBSizeOption eBlockSize, OGDC::PixelFormat ePixelFormat, UGDataCodec::CodecType nCodecType,
		UGRect2D rc2Bounds, UGint nBandCount = 1);

	//! \brief ��������
	//##ModelId=48203054005D
	~UGDatasetRasterInfo();

	//##ModelId=48203054005E
	void operator=(const UGDatasetRasterInfo& rInfo);

public:

#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined (IOS)
	//##ModelId=483BB70B02FD
	UGbool ToOgdcDatasetRasterInfo(OgdcDatasetRasterInfo& OgdcInfo) const;

	//##ModelId=483BB70B0300
	UGbool FromOgdcDatasetRasterInfo(const OgdcDatasetRasterInfo& OgdcInfo);
#endif

public:
	//! \brief ���ݼ�����
	//##ModelId=482030540060
	UGString m_strName;

	//! \brief �ײ������
	//##ModelId=482030540061
	UGString m_strTableName;
	
	//! \brief ���ݼ�����
	//##ModelId=482030540062
	UGint m_nType;

	//! \brief ѡ����Ϣ
	//##ModelId=482030540063
	UGint m_nOptions;

	//! \brief Ӱ����
	//##ModelId=48203054006E
	UGint m_nWidth;

	//! \brief Ӱ��߶�
	//##ModelId=48203054006F
	UGint m_nHeight;

	//! \brief Ӱ��ֿ�߳�
	//##ModelId=482030540071
	IBSizeOption m_eBlockSize;

	//! \brief ���ݼ���Bounds
	//##ModelId=482030540072
	UGRect2D m_rc2Bounds;
		
	//! \brief ����ֿ�����(��������)
	//##ModelId=48203054007E
	UGint m_nColBlocks;		
	
	//! \brief ����ֿ�����(��������)
	//##ModelId=48203054007F
	UGint m_nRowBlocks;		
	
	//##ModelId=48203054008E
	UGString m_strDescription;	//�����ݼ���������Ϣ

	//##ModelId=48203054008E
	UGString m_strExtInfo;	//���ݼ�������Ϣ

	void Add(const UGBandInfo& BandInfo);
	//! \brief ���ص�ǰ���ε���Array�����е�����
	//! \remarks ���ɹ�����-1��
	UGint Get(UGint nBandIndex,UGBandInfo &bandInfo) const;
	//! \brief ���ص�ǰ���ε���Array�����е�����
	//! \remarks ���ɹ�����-1��
	UGint Get(UGint nBandIndex) const;
	//! \brief �Ƴ�ĳ������
	UGbool Remove(UGint nBandIndex);
	//! \brief �Ƴ����в���
	void RemoveAll();
	//! \brief ��ȡ��UGArray �� nIndexλ��
	UGBandInfo& GetAt(UGint nIndex);
	const UGBandInfo& GetAt(UGint nIndex) const;

	inline UGint GetBandCount() const { return m_arrBandInfo.GetSize(); }

	UGdouble GetNoValue(UGint nBandIndex = 0) const;

	void SetNoValue(UGdouble dNoValue, UGint nBandIndex = 0, UGbool bCheck = FALSE);

	OGDC::PixelFormat GetPixelFormat(UGint nBandIndex = 0) const;

	void SetPixelFormat(OGDC::PixelFormat pixelFormat, UGint nBandIndex = 0);

private:

	UGArray<UGBandInfo> m_arrBandInfo;

	// �����ǵ�����Ҫɾ��������
// public:
// 	//! \brief Ӱ�����ֽ���
// 	//##ModelId=482030540070
// 	UGint m_nWidthBytes;
// 
// 	//! \brief ���ݱ�������
// 	//##ModelId=48203054007D
// 	UGDataCodec::CodecType m_nCodecType;	
// 	
// 	//! \brief ��άBounds����Сֵ
// 	//##ModelId=482030540080
// 	UGdouble m_dMinZ;
// 	
// 	//! \brief ��άBounds�����ֵ
// 	//##ModelId=482030540081
// 	UGdouble m_dMaxZ;	
// 	//! \brief ��ɫ��
// 	//##ModelId=48203054008C
// 	UGColorset m_Colorset;
// 
// 	//##ModelId=483BB70B030D
// 	//! \brief �ನ�����ݼ��Ĳ�������
// 	//! \attention ���εĸ����Ѿ����ڲ�ά�������治Ҫ���й���
// 	UGint m_nBandCount;
// 
// 	//! \brief �������ݼ��Ĳ�����ţ�Base 0��
// 	UGint m_nBandIndex;
// 	
// 	//! \brief �����������ݱ�������ơ�
// 	UGString m_strFieldName;
// // 	inline OGDC::PixelFormat GetPixelFormat() const { return m_ePixelFormat; };
// // 
// // 	void SetPixelFormat(OGDC::PixelFormat pixelFormat);
// 
// private:
// // 	UGArray<UGBandInfo> m_arrBandInfo;
// 
// 	//! \brief ��Чֵ�����ĳһ���ֵ��m_NoValue,����Ϊ��һ��û��ֵ
// 	//##ModelId=48203054008D
// 	UGdouble m_dbNoValue;
// 
// 	//! \brief ��ʶ�û��Ƿ���������ֵ
// 	UGbool m_bIsSetNoValue;
// 
// 	//! \brief ���صĸ�ʽ
// 	//##ModelId=48203054006D
// 	OGDC::PixelFormat m_ePixelFormat;
};

//  [added by zhangshuo at 6/8/2010]
//NetCDFά����
//ÿ��ά�ȵ�����,bX_Axis��bY_Axis��bOptionalDimֻ����һ��Ϊ��
//����nEndIndex - nStartIndexһ��Ҫ >= 0, = 0 ʱ����ȡ����
class ENGINE_API UGNetCDFDim
{
	friend class UGDataSourceNetCDF;
public:
	UGNetCDFDim()
	{
		m_strDimName = _U("");
		m_nStartIndex = 0;
		m_nEndIndex = 1;
		m_nDimSize = 0;
		m_bX_Axis = FALSE;
		m_bY_Axis = FALSE;
		m_bOptionalDim = FALSE;
	}
	~UGNetCDFDim(){};

public:
	UGString GetName()
	{
		return m_strDimName;
	};

	UGlong GetSize()
	{
		return m_nDimSize;
	};

	UGbool IsXAxis()
	{
		return m_bX_Axis;
	};

	UGbool IsYAxis()
	{
		return m_bY_Axis;
	};

	UGbool IsOptionalDim()
	{
		return m_bOptionalDim;
	};

	void SetXAxis(UGbool b = TRUE)
	{
		m_bX_Axis = b;
	};

	void SetYAxis(UGbool b = TRUE)
	{
		m_bY_Axis = b;
	};

	void SetOptionalDim(UGbool b = TRUE)
	{
		m_bOptionalDim = b;
	};

protected:
	void SetName(UGString strName)
	{
		m_strDimName = strName;
	};

	void SetSize(UGlong nSize)
	{
		m_nDimSize = nSize;
	};

public:
	//! \brief ά�ȵ���ʼֵ������ֵ�����е�������
	//! \remarks ��
	UGint m_nStartIndex;
	//! \brief ά�ȵ���ֵֹ������ֵ�����е�������
	//! \remarks ��
	UGint m_nEndIndex;

private:
	//! \brief ��ά����
	//! \remarks ��
	UGString m_strDimName;
	//! \brief �жϵ�ǰά����ΪX����ʾ��
	//! \remarks ��
	UGbool m_bX_Axis;
	//! \brief �жϵ�ǰά����ΪY����ʾ��
	//! \remarks ��
	UGbool m_bY_Axis;
	//! \brief �жϵ�ǰά����Ϊoptional����ʾ��
	//! \remarks ��
	UGbool m_bOptionalDim;
	//! \brief ��ά�ȳ���
	//! \remarks ��
	UGlong m_nDimSize;
};

class ENGINE_API UGNetCDFDatasetRasterInfo : public UGDatasetRasterInfo
{
	friend class UGDataSourceNetCDF;
	friend class UGDatasetRasterNetCDF;
public:
	//! \brief ���캯����
	//! \remarks ��
	UGNetCDFDatasetRasterInfo()
	{
		m_strVarName = _U("");
		m_arrDims.RemoveAll();
		X_AxisIndex = -1;
		Y_AxisIndex = -1;
		OptionalDimIndex = -1;
		m_strVarType = 0;//ncNoType;
		m_nType = 83;//UGDataset::Grid;
		m_strUnit = _U("");
		m_strLongName = _U("");
	};

	//! \brief ����������
	//! \remarks ��
	~UGNetCDFDatasetRasterInfo(){};

public:
	UGString GetVarName()
	{
		return m_strVarName;
	};

	void SetVarName(UGString name)
	{
		m_strVarName = name;
	};

	// 	UGbool UGNetCDFDatasetRasterInfo::operator==(const UGNetCDFDatasetRasterInfo &info)
	// 	{
	// 		if(	this->m_strVarName == info.m_strVarName &&
	// 			this->X_AxisIndex == info.X_AxisIndex &&
	// 			this->m_arrDims[this->X_AxisIndex].m_nStartIndex == info.m_arrDims[info.X_AxisIndex].m_nStartIndex &&
	// 			this->m_arrDims[this->X_AxisIndex].m_nEndIndex == info.m_arrDims[info.X_AxisIndex].m_nEndIndex &&
	// 			this->Y_AxisIndex == info.Y_AxisIndex &&
	// 			this->m_arrDims[this->Y_AxisIndex].m_nStartIndex == info.m_arrDims[info.Y_AxisIndex].m_nStartIndex &&
	// 			this->m_arrDims[this->Y_AxisIndex].m_nEndIndex == info.m_arrDims[info.Y_AxisIndex].m_nEndIndex &&
	// 			this->OptionalDimIndex == info.OptionalDimIndex &&
	// 			this->m_arrDims[this->OptionalDimIndex].m_nStartIndex == info.m_arrDims[info.OptionalDimIndex].m_nStartIndex)
	// 		{
	// 			return TRUE;
	// 		}
	// 		return FALSE;
	// 	}

public:
	//! \brief ��X axis index
	//! \remarks ��
	UGint X_AxisIndex;

	//! \brief ��Y axis index
	//! \remarks ��
	UGint Y_AxisIndex;

	//! \brief ��optional dim index
	//! \remarks ��
	UGint OptionalDimIndex;

	//! \brief ��dim array
	//! \remarks ��
	UGArray<UGNetCDFDim> m_arrDims;

	//! \brief ��the var unit
	//! \remarks ��
	UGString m_strUnit;

	//! \brief ��the var longname
	//! \remarks ��
	UGString m_strLongName;
protected:
	//! \brief ��the var name
	//! \remarks ��
	UGString m_strVarName;

	//! \brief ��the var type
	//! \remarks ��
	UGint m_strVarType;
};

}

#endif


