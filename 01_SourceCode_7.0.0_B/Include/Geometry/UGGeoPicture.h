// UGGeoPicture.h: interface for the UGGeoPicture class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOPICTURE_H__CE2185C5_6495_4227_8A12_809373AC5CE3__INCLUDED_)
#define AFX_UGGEOPICTURE_H__CE2185C5_6495_4227_8A12_809373AC5CE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry/UGGeometry.h"
#include "Toolkit/UGPalette.h"

namespace UGC {

class GEOMETRY_API UGGeoPicture : public UGGeometry  
{
public:
	UGGeoPicture();
	virtual ~UGGeoPicture();	

public: //pure virtual 
	//! \brief 清空地理数据
	virtual void Clear();
	
	//! \brief 得到维度, 固定为2
	//! \return 得到维度,固定为2
	virtual UGint GetDimension() const;
	
	//! \brief 得到类型, 固定为 GeoRect
	virtual Type GetType() const;
	
	//! \brief 得到内点（在Geometry内部，靠近中央的点）,即为中心点
	virtual UGPoint2D GetInnerPoint() const;

	//! \brief 得到对象长度
	//! \attention Dimension为1or2的对象才支持
	//! \return 返回长度
	virtual UGdouble GetLength() const;
	
	//! \brief 得到面积
	//! \return 返回面积
	virtual UGdouble GetArea() const;
	
	//! \brief 点击测试, 用于对象点选
	//! \param pntHitTest 用来测试选中的点
	//! \param dTolerance 容限
	//! \return 选中返回true, 否则返回false	
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
	//! \brief 得到空间数据, 主要用于需要按照维度相同时
	//! 来做统一处理的时候, 例如一些空间判断和操作的算法
	//! \param pPoints 传出的点坐标数组[out]。
	//! \param pPolyCount 传出的每个子对象点个数的数组[out]。
	//! \param nSubCount 传出的子对象个数[out]。
	//! \param nSegmentCount 对参数化对象, 每个弧段分割点的个数[in]。
	//! \remarks 参数采用了智能指针的技术,调用者不用释放内存空间
	//! \return 成功返回true,否则返回false。
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& arrpPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief 几何对象是否有效
	//! \return 有效返回true,无效返回false
	virtual UGbool IsValid()const;
	
	//! \brief 缩放
	//! \param dRatioX X方向缩放比率
	//! \param dRatioY Y方向缩放比率
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief 缩放
	//! \param dRatio 缩放比率(X,Y方向相同)
	virtual void Inflate( UGdouble dRatio);
	
	//! \brief 平移
	//! \param dX 平移的X偏移量
	//! \param dY 平移的Y偏移量
	virtual void Offset( UGdouble dX, UGdouble dY);
	
	//! \brief 平移
	//! \param 偏移量(X,Y方向相同)
	virtual void Offset( UGdouble dOffset);
	
	//! \brief 平移
	//! \param 平移的偏移量(分别用UGSize2D中的x,y代表X,Y方向的偏移量)
	virtual void Offset( const UGSize2D &szOffset);
	
	//! \brief 旋转
	//! \param pntOrigin 旋转的中心点(锚点,不动点)
	//! \param dAngle 旋转角度
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief 旋转,增加一些参数,以便内部可以不用进行cos,sin, 在批量处理的时候有利于提高效率
	//! \remarks dAngle看似多余,但GeoText需要,所以要保留
	//! \param pntOrigin 旋转的中心点(锚点,不动点)
	//! \param dCosAngle 旋转的cos值
	//! \param dSinAngle 旋转的sin值
	//! \param dAngle 旋转角度
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, double dAngle = 0);
	
	//! \brief 调整几何数据,限定在新的Bounds中
	//! \param rcNewBounds 新的,限定范围的Bounds
	//! \return 成功返回true,失败返回false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

	//! \brief 两点镜像
	//! \param pntMirror1 构成镜面的第一个点
	//! \param pntMirror2 构成镜面的第二个点
	//! \return 成功返回true,失败返回false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);

public:
#if !defined OS_ANDROID && !defined IOS
	//! \brief Geometry与Element的转换
	//! \param pElement,返回的pElement指针在函数内分配内存,外面负责删除，否则会有内存泄漏
	virtual UGbool ToElement(OgdcElement*& pElement)  const;
	
	//! \brief Geometry与Element的转换
	//! \param pElement,传入的Element，如果无法转换则返回False，否则返回True
	virtual UGbool FromElement(const OgdcElement* pElement);
#endif
	//! \brief 根据投影转化器的设置和转化方向要求, 进行投影转化
	//! \param pPJTranslator 投影转化器
	//! \param bForward 转化方向, true代表从UGRefTranslator的源(Src)转化到目的(Des), false则相反
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);

	//! \brief 从经纬坐标系统转化为投影坐标系统
	//! \param pCoordSys 投影坐标系统
	virtual void PJForward( UGPrjCoordSys *pCoordSys );
	
	//! \brief 从投影坐标系统转化为经纬坐标
	//! \param pCoordSys 投影坐标系统
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );	
	
public:
	//! \brief 拷贝构造图片对象。
	//! \param geoPicture [in] 已有图片对象。
	//! \return 返回true。
	UGbool Make(const UGGeoPicture& geoPicture);	
	
	//! \brief 用中心点/Size/旋转角度构造矩形对象。
	//! \param pntCenter	[in] 中心点。
	//! \param szSize		[in] size的x作为宽度,y作为高度。
	//! \param dAngle		[in] 旋转角度。
	//! \param bCopyData	[in] 是否以Copy方式复制ImageData信息，默认为拷贝方式
	//! \return 返回true。
	UGbool Make(UGArray<UGImageData*>& aryImageData, const UGPoint2D &pntCenter, const UGSize2D& szSize, UGdouble dAngle = 0, UGbool bCopyData = TRUE);    
	
	//! \brief 用矩形结构和旋转角度构造矩形对象。
	//! \param rcRect [in] 矩形结构。
	//! \param dAngle [in] 旋转角度。
	//! \param bCopyData	[in] 是否以Copy方式复制ImageData信息，默认为拷贝方式
	//! \return 返回true。
	UGbool Make(UGArray<UGImageData*>& aryImageData, const UGRect2D& rcRect, UGdouble dAngle = 0, UGbool bCopyData = TRUE);	
	
	//! \brief 得到中心点。
	//! \return 返回中心点。
	UGPoint2D GetCenterPoint() const;    
	
	//! \brief 设置中心点。
	//! \param pntCenter [in] 中心点。
	void SetCenterPoint( const UGPoint2D& pntCenter );    
	
	//! \brief 得到高度。
	//! \return 返回高度。
	//! \remarks 该高度不是看上去的高度,而是没有进行旋转之前的高度。
	UGdouble GetHeight() const;	
	
	//! \brief 设置高度。
	//! \param dHeight [in] 要设置的高度。
	//! \return dHeight小于等于0, 返回false。
	UGbool SetHeight( UGdouble dHeight );	
	
	//! \brief 得到宽度。
	//! \return 返回宽度。
	//! \remarks 该宽度不是看上去的宽度,而是没有进行旋转之前的宽度。
	UGdouble GetWidth() const;
	
	//! \brief 设置宽度。
	//! \param dWidth [in] 要设置的宽度。
	//! \return dWidth小于等于0,返回false。
	UGbool SetWidth( UGdouble dWidth );	
	
	//! \brief 得到旋转角度。
	//! \return 返回旋转角度。
	UGdouble GetAngle() const;    
	
	//! \brief 设置旋转角度。
	//! \param dAngle [in] 要设置的旋转角度。
	void SetAngle( UGdouble dAngle );    

	//! \brief 设置持续时间
	//! \remarks
	inline void SetDelayTime(UGshort ntime){ m_nDelayTime = ntime; }

	//! \brief 获取持续时间
	//! \remarks
	inline UGshort GetDelayTime() const { return m_nDelayTime; }

	//! \brief 转化为线对象
	//! \param geoLine[out] 得到的线对象
	//! \param nSegmentCount 当曲线转化为线时,每一段用多少个点来模拟; 本函数中不起作用
	//! \return 成功返回true,失败返回false
	virtual UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;
	
	//! \brief 转化为面对象
	//! \param geoRegion[out] 得到的面对象
	//! \param nSegmentCount 当曲面转化为面时,每一段用多少个点来模拟; 本函数中不起作用
	//! \return 成功返回true,失败返回false
	virtual UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;

	//! \brief 添加Image数据
	//! \param pImageData[in] 待添加的Image
	//! \return 返回Image的个数
	UGint AddImageData(UGImageData* pImageData);

	//! \brief 插入Image数据
	//! \param nIndex 插入Image的索引号
	//! \param pImageData[in] 待添加的Image
	void InsertAtImageData(UGint nIndex, UGImageData* pImageData);

	//! \brief 获取 Image 数据
	//! \param nIndex Image的索引号
	//! \return 返回获取的 Image 指针
	UGImageData* GetImageData(UGint nIndex);
	
	//! \brief 移除 Image 指针，不实际删除数据
	//! \param nIndex 待移除的 Image的索引号
	//! \return 返回被移除的 Image 指针
	UGImageData* RemoveImageData(UGint nIndex);

	//! \brief 释放 Image 数据，清空内存
	//! \param nIndex 待移除的 Image的索引号
	//! \param nCount 移除个数
	//! \return 返回剩余的Image个数
	UGint ReleaseImageData(UGint nIndex, UGint nCount = 1);
	
	//! \brief 释放所有数据，清空内存
	void ReleaseAllImageData();

	//! \brief 获取Image个数
	UGint GetFrameCount() const;

	//! \brief 获取当前索引号
	UGint GetCurrentFrame() const;

	//! \brief 设置当前索引号
	void SetCurrentFrame(UGint nCurFrame);

	virtual UGint GetDataSize() const;
public:
	//! \brief 生成XML格式的信息
	//! \param versionType GML的版本
	//! \param nPace 缩进的空格数目,使得xml字符串更加易于人工阅读; 
	//! 主要用于如果返回的xml字符串是一个大标签中的一部分, 通过指定空格数目,可以使层次清晰
	//! \return 返回指定GML版本的xml字符串
	virtual UGString ToXML(GMLVersionType versionType, UGint nPace = 0) const;
	
	//! \brief 从XML字符串中生成Geometry
	//! \param strXML xml格式字符串
	//! \param versionType xml字符串的GML版本
	//! \return 返回指定GML版本的xml字符串
	virtual UGbool FromXML(const UGString& strXML, GMLVersionType versionType);
	
public:	
	//! \brief 获得编辑对象的句柄的数目
	//! \remarks 对于固定句柄对象为9包括了改变大小的8个控制点和一个旋转控制点
     virtual UGint  GetHandleCount();
	
	//nHandle:的值与控制点的关系如右图                         
	//									1---+   	  +--2    	+----3	
	//                                      |         |         |  
	//                                      |         |         |  
	//										x---------x---------x     9
    //										|   ____________    |     |
    //										|  /            \   | x---+
	//									4---x |              |  x-----5
	//										|  \____________/   |
	//										|                   |
	//										x---------x---------x
	//										|		  |         |
	//										|		  |         |
	//								    6---+         +-----7   +-----8
	
	//! \brief 根据句柄获得相应控制点的值
	//! \param nHandle 控制点句柄
	//! \param point 句柄对应的控制点的坐标值
	//! \return 返回辅助点的类型
	 virtual UGint GetHandle( UGint nHandle, UGPoint2D& point);


	//! \brief 移动控制点到指定坐标,主要用于绘制对象，修改对象节点等操作
	//! \param nHandle 控制点句柄
	//! \param point 控制点坐标
	virtual void MoveHandle( UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_Default);

	//! \brief 节点编辑时可用来插入一个控制点,也可以用于绘制对象时加入节点
	//! \param nHandle 插入位置
	//! \param pnt2D 插入点的地理坐标
	virtual void AddHandle( UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_Default);
	
	//! \brief 删除编辑对象的指定节点
	//! \param nHandle 节点句柄
     virtual UGuint DelNode( UGint nHandle );

	//! \brief 计算对象绘制时的辅助线，返回的是一个复合对象
	//! \param pPoints 点串
	//! \param nPntCount  点的个数
	//! \param nEditType 绘制对象的类型，参考UGEditType
	//! \param pStyle	 辅助线的风格，如果传入为NULL，用默认的风格
     virtual UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);

	 //! \brief 根据传入的点串生成对象，主要用于编辑中的参数化等没有内部数组保存点串的对象，
	 //也用于自定义对象,对于有内部数组保存点串的对象，该函数直接return既可，比如GeoLine
	 //GeoLine等对象就直接用AddHandle来生成，效率比较高 
	//! \param pPoints 点串
	//! \param nPntCount  点的个数
     virtual void MakeWithPoints(UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType=UGEditType::ET_Default);

	//! \brief 获取对象需要捕捉的点串
	//! \param aryPnts 点串，传出去的要捕捉的点串
	//! \return 如果是true表示有需要捕捉的点串，如果返回false表示该对象没有需要捕捉的点串
	virtual UGbool GetSnapPoints(UGArray<UGPoint2D>& aryPnts);

	//! \brief 获取对象需要捕捉的线段数组
	//! \param aryLines 需要捕捉的线数组（如果有多个part，那么aryLines就应该有多少个count）
	//! \return 如果是true表示有需要捕捉的线，如果返回false表示该对象没有需要捕捉的线
	virtual UGbool GetSnapLines(UGLineArray& aryLines);

protected:

	//! \brief 计算范围
	virtual UGRect2D ComputeBounds() const;
	
	//! \brief 存储到Stream中
	virtual UGbool SaveGeoData(UGStream& stream, 
		UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	
	//! \brief 从Stream中生成Geometry
	virtual UGbool LoadGeoData( UGStream& stream , 
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE, UGbool bSDBPlus = FALSE );

	//! \brief 计算得到矩形四个顶点的坐标，并会自动封闭。
	//! \param pPoints 用于返回点数组的指针。
	//! \attention 调用者必须保证pPoints的空间有五个点。
	void GetVertexes(UGPoint2D* pPoints) const;

protected:
	UGArray<UGImageData*> m_aryImageData;
	UGint m_nCurFrame;

	//! \brief 中心点
	UGPoint2D m_pntCenter;
	
	//! \brief 宽度
	UGdouble m_dWidth;
	
	//! \brief 高度
	UGdouble m_dHeight;
	
	//! \brief 旋转角度
	//! \remarks 角度单位
	UGdouble m_dAngle;

	//! \brief 持续时间
	//! \remarks
	UGshort m_nDelayTime;
};

}

#endif // !defined(AFX_UGGEOPICTURE_H__CE2185C5_6495_4227_8A12_809373AC5CE3__INCLUDED_)

