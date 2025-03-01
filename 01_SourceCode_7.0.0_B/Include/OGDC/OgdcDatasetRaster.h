//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcDatasetRaster.h
//!  \brief OgdcDatasetRaster 的接口定义。
//!  \details Ogdc关于影像数据集的接口定义。
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//!  \file OgdcDatasetRaster.h
//!  \brief OgdcDatasetRaster 的接口定义。
//!  \details Ogdc关于影像数据集的接口定义。
//!  \Modified Date: 2013-4-7
//!  \Modified Author:Conversion-zby
//!  \Details Comments:调整OGDC接口参数开放形式以及接口组成数目，主要目的是在OGDC接口中添加多波段栅格数据集的扩展支持;
//!  \Details Comments:本次调整主要包含两方面内容:(1) 对于原有接口增加波段索引参数支持;(2) 增加多波段栅格数据集特有接口
//!  \Details Comments:此次调整涉及整个栅格数据集结构的调整，由于技术人员水平所限以及时间的仓促，难免会产生这样那样的问题,有问题
//!  \Details Comments:请与Conversion-zby联系!
//!  \Version OGDC-1-1(2013-4-7)

#ifndef OGDCDATASETRASTER_H
#define OGDCDATASETRASTER_H

#include "OGDC/OgdcDatasetRasterInfo.h"
#include "Base/OgdcColorTable.h"
#include "Base/OgdcDict.h"
#include "Element/OgdcElemRegion.h"
#include "Element/OgdcRasterBlock.h"
#include "OGDC/OgdcDataset.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace OGDC
{

//! \brief OGDC栅格数据集颜色空间波段选择信息记录
struct OgdcColorSpaceBand
{
	OgdcColorSpaceBand()
	{
		m_nColorSpaceSelected = ICS_UNKNOW;
	};
	//当前组合色彩的模式
	ImgColorSpace	m_nColorSpaceSelected;
	//当前如果为组合色彩，要显示的波段索引
	OgdcArray<OgdcInt>	m_arrBandSelected;
};


//! \brief Ogdc栅格数据集。
//! \remarks 栅格数据集包括Image和Grid数据集。
class OGDC_API OgdcDatasetRaster : public OgdcDataset  
{
public:
	//! \brief 默认构造函数
	OgdcDatasetRaster();
	//! \brief 默认析构函数
	virtual ~OgdcDatasetRaster();

public:
	//! \brief 创建影像金字塔。
	//! \param bShhowProgress 是否显示进度条[in]。
	//! \return 是否创建成功，是返回TRUE，否则返回FALSE。
	virtual OgdcBool BuildPyramid() =0;	

	//! \brief 移除影像金字塔。
	//! \return 是否移除成功，是返回TRUE，否则返回FALSE。
	virtual OgdcBool DropPyramid() = 0;	
	//! \brief 判断是否已经建立影像金字塔。
	virtual OgdcBool IsBuildPyramid() const =0;
	
	//! \brief 获取影像数据集指定行列某一像素点的颜色值。
	//! \param nCol 像素点列号[in]。
	//! \param nRow 像素点行号[in]。
	//! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为0
	//! \return 颜色值。
	//! \remarks 颜色值的数值因数据集的像素格式不同而不同。
	virtual OgdcColor GetPixel(OgdcInt nCol, OgdcInt nRow,OgdcInt nBandIndex=0) = 0;	
	
	//! \brief  设置影像数据集指定行列某一像素点的颜色值。
	//! \param nCol 像素点列号[in]。
	//! \param nRow 像素点行号[in]。
	//! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为0
	//! \param nColor 颜色值[in]。
	//! \remarks 要根据数据集的像素格式正确设置像素点的颜色值。
	virtual void SetPixel(OgdcInt nCol, OgdcInt nRow, OgdcColor nColor,OgdcInt nBandIndex=0) = 0;	
	
	//! \brief 获取Grid数据集指定行列某一点的特性值。
	//! \param nCol 网格列号[in]。
	//! \param nRow 网格行号[in]。
	//! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为0
	//! \return 特性值。
	virtual OgdcDouble GetValue(OgdcInt nCol, OgdcInt nRow,OgdcInt nBandIndex=0) = 0;
	
	//! \brief 设置Grid数据集指定行列某一点的特性值。
	//! \param nCol 网格列号[in]。
	//! \param nRow 网格行号[in]。
	//! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为0
	//! \param dValue 特性值[in]。
	//! \remarks 要根据数据集的白化值正确设置网格点的特性值。
	virtual void SetValue(OgdcInt nCol, OgdcInt nRow, OgdcDouble dValue,OgdcInt nBandIndex=0) = 0;
	
	//! \brief 获取可见栅格块
	//! \param rcView 可见范围
	//! \param nDeviceWidth  显示设备的宽度
	//! \param nDeviceHeight 显示设备的高度
	virtual OgdcRasterBlock* GetViewBlock(const OgdcRect2D& rcView, 
		OgdcInt nDeviceWidth, OgdcInt nDeviceHeight) = 0;


public:
	//! \brief 获取数据集类型。
	virtual OgdcInt GetType() const;

	//! \brief 获取数据集名。
	//! \return 数据集名字符串。
	virtual OgdcString GetName();

	//! \brief 判断是否为栅格数据集
	OgdcBool IsRaster();
    
	//! \brief 获取数据集描述信息。
	//! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为-1
	//! \return 数据集最描述信息字符串。
	virtual OgdcString GetDescription(OgdcInt nBandIndex=0) const;

	//! \brief 设置数据集描述信息。
	//! \param strtDescription 数据集描述信息字符串[in]
	//! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为-1
	virtual void SetDescription(const OgdcString& strtDescription,OgdcInt nBandIndex = 0);	

	//! \brief 返回数据集的维数。
	//! \return 数据集的空间维数, 栅格为-1维。
	virtual OgdcInt GetStyleDimension();		
	
	//! \brief 返回数据集的地理范围。
	//! \return 数据集地理范围矩形。
	virtual OgdcRect2D GetBounds();	
	
	//! \brief 设置数据集的地理范围。
	//! \param rcBunds 数据集地理范围矩形[in]。
	virtual void SetBounds(const OgdcRect2D& rcBounds);	
	//! \brief 获取波段数
	virtual OgdcInt GetBandCount() const;
	//! \brief 设置波段合成方式
	//! \param aryBand		多波段
	//! \param nColorSpace	色彩空间格式
// 	virtual void SetBandCombineMode(const OgdcArray<OgdcInt>& aryBand, ImgColorSpace nColorSpace);
	//! \brief 获取波段合成方式
	//! \param aryBand		多波段
	//! \param nColorSpace	色彩空间格式
// 	virtual OgdcBool GetBandCombineMode(OgdcArray<OgdcInt>& aryBand, ImgColorSpace& nColorSpace) const;
	
	//! \brief 获取栅格数据集宽度。
	//! \return 栅格数据集宽度，以象素值为单位。
	virtual OgdcInt GetWidth() const;	
	
	//! \brief 获取栅格数据集高度，以象素值为单位
	//! \return 栅格数据集高度，以象素值为单位
	virtual OgdcInt GetHeight() const;	

	//! \brief 获取栅格数据集定义的无效值
	//! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为-1
	//! \return 无效值
	//! \remarks Grid数据集的白化值，也由此接口获取
	virtual OgdcDouble GetNoValue(OgdcInt nBandIndex=0) const;	
	
	//! \brief 定义栅格数据集的无效值
	//! \param dbNoValue [in]
	//! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为-1
	//! \remarks Grid数据集的白化值，也由此接口设置。
	virtual void SetNoValue(OgdcDouble dbNoValue,OgdcInt nBandIndex=0);

	//! \brief 获取影像的象素格式
    //! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为-1
	//! \return 像素格式枚举值。
	virtual PixelFormat GetPixelFormat(OgdcInt nBandIndex =0) const;	

	//! \brief 得到扫描线
	//! \param nRowIndex 扫描线行索引[in]
	//! \param scanLine 扫描线数据[out]
	//! \param nStartCol 扫描线起始列[in]
    //! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为0
	//! \return 是否获取成功。
	virtual OgdcBool GetScanline(OgdcInt nRowIndex,OgdcRasterScanline& scanLine, OgdcInt nStartCol = 0,OgdcInt nBandIndex=0);
  
	//! \brief 通过行列索引设置扫描线
	//! \param nRowIndex 扫描线行索引[in]
	//! \param nColIndex 扫描线列索引[in]
	//! \param scanLine 扫描线数据[in]
	//! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为0
	//! \return 是否设置成功
	virtual OgdcBool SetScanline(OgdcInt nRowIndex,OgdcInt nColIndex, const OgdcRasterScanline& scanLine,OgdcInt nBandIndex=0);

	//! \brief 读入指定块数据
	//! \param nRowBlock 影像块行号[in]
	//! \param nColBlock 影像块列号[in]
	//! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为0
	//! \return 影像块指针
	virtual OgdcRasterBlock* LoadBlock(OgdcInt nRowBlock, OgdcInt nColBlock,OgdcInt nBandIndex=0);	
    
	//! \brief 将一内存中的影像块存入磁盘
	//! \param pImgBlock 影像块指针[in]
	//! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为0
	//! \return 是否成功保存，成功返回TRUE，失败返回FALSE。
	virtual OgdcBool SaveBlock(OgdcRasterBlock* pImgBlock,OgdcInt nBandIndex=0);	
	
	//! \brief 释放影像块数据。
	//! \param nBandIndex[in] 获取颜色数值所在的波段索引值，默认为-1
	virtual void ReleaseAllBlocks(OgdcInt nBandIndex=0);	

	
	//! \brief 是否是多波段信息
	virtual OgdcBool IsMBRaster();

	// 修改成员变量需要调用SetModified
public:
	//! \brief 多边形剪裁区域。
	OgdcElemRegion* m_pClipRgn;
    //! \brief 栅格数据集信息
	OgdcDatasetRasterInfo m_info;
	//! \brief 颜色表
	OgdcColorTable m_colorTable;
    //! \brief 当前显示选择的波段数值
	OgdcDict<OgdcInt,OgdcColorSpaceBand> m_dicColorSpace;
};
}
#endif // !defined(OGDCDATASETRASTER_H)

