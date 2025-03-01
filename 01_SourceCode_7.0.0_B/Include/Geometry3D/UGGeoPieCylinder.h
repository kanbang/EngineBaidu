// UGGeoPieCylinder.h: interface for the UGGeoPieCylinder class.
//
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGGeoPieCylinder.h
//!  \brief 扇面柱状几何体。
//!  \details 文件详细信息。
//!  \author 冯振华。
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOPIECYLINDER_H__A5D81352_F683_4B67_8180_B73E6DF3AA8D__INCLUDED_)
#define AFX_UGGEOPIECYLINDER_H__A5D81352_F683_4B67_8180_B73E6DF3AA8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry3D/UGGeometry3D.h"

namespace UGC
{
class GEOMETRY3D_API UGGeoPieCylinder : public UGGeometry3D  
{
public:
	//! \brief 构造函数。 
	UGGeoPieCylinder();

	//! \brief 析构函数。
	virtual ~UGGeoPieCylinder();
public: 
	//! \brief 清空地理数据
	virtual void Clear();

	//! \brief 得到维度, 点为0维, 线/曲线等为1维, 面/曲面等为2维, GeoCompound/GeoText等为-1，在数据库存储时用
	virtual UGint GetDimension() const;

	//! \brief 得到类型, 固定为 GeoPie
	virtual Type GetType() const;

	//! \brief 得到内点（在Geometry内部，靠近中央的点）
	//! \remarks 为Pie中间角度和椭圆边的交点到圆心一半位置的点
	virtual UGPoint2D GetInnerPoint() const;

	//! \brief 得到对象面积
	//! \return 返回面积
	virtual UGdouble GetArea3D() const;	
	
	//! \brief 点击测试, 用于对象点选
	//! \param pntHitTest 用来测试选中的点
	//! \param dTolerance 容限
	//! \return 选中返回true, 否则返回false	
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;

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

	//! \brief 得到空间数据, 主要用于需要按照维度相同时
	//! 来做统一处理的时候, 例如一些空间判断和操作的算法
	//! \param pPoints 传出的点坐标数组[out]。
	//! \param pPolyCount 传出的每个子对象点个数的数组[out]。
	//! \param nSubCount 传出的子对象个数[out]。
	//! \param nSegmentCount 对参数化对象, 每个弧段分割点的个数[in]。
	//! \remarks 参数采用了智能指针的技术,调用者不用释放内存空间
	//! \return 成功返回true,否则返回false。
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
				UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief 几何对象是否有效
	//! \return 长半轴或短半轴小于0,则为非法
	virtual UGbool IsValid()const;
	
	//! \brief 缩放
	//! \param dRatioX X方向缩放比率
	//! \param dRatioY Y方向缩放比率
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief 缩放
	//! \param dRatio 缩放比率(X,Y方向相同)
	virtual void Inflate( UGdouble dRatio);

	//! \brief 缩放
	//! \param dRatioX X方向缩放比率
	//! \param dRatioY Y方向缩放比率
	//! \param dRatioY Z方向缩放比率
	//! \attention 正圆无法在两个不同方向缩放, 因此dRatioX和dRatioY必须相等才行
	virtual void Inflate3D( UGdouble dRatioX, UGdouble dRatioY,UGdouble dRatioZ);
	
	//! \brief 缩放
	//! \param dRatio 缩放比率(X,Y方向相同)
	virtual void Inflate3D( UGdouble dRatio);

	//! \brief 三维对象旋转
	//! \param vecAxis [in] 旋转轴 过原点
	//! \param dAngle [in] 旋转角度
	virtual void Rotate3D(const UGVector3d& vecAxis, UGdouble dAngle);
	
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

	//! \brief 三维对象平移
	//! \param dX [in] 平移的X偏移量
	//! \param dY [in] 平移的Y偏移量	
	//! \param dZ [in] 平移的Z偏移量	
	virtual void Offset3D( UGdouble dX, UGdouble dY, UGdouble dZ);
	
	//! \brief 三维对象平移
	//! \param dOffset [in] 偏移量(X,Y,Z方向相同)	
	virtual void Offset3D( UGdouble dOffset);
	
	//! \brief 三维对象平移
	//! \param vecOffset [in] 平移的偏移量(分别用UGVector3d中的x,y,z代表X,Y,Z方向的偏移量)。
	virtual void Offset3D( const UGVector3d &vecOffset);	
	
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
	//! \remarks 斜椭圆resize后, 可能不能完全填充新的bounds; 
	//!			 再计算得到的Bounds也有可能不等于resize的参数
	//! \return 成功返回true,失败返回false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 
	
	//! \brief 两点镜像
	//! \param pntMirror1 构成镜面的第一个点
	//! \param pntMirror2 构成镜面的第二个点
	//! \return 成功返回true,失败返回false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);

	//! \brief 根据geometry类型，再调用各自的make方法去实现。
	//! \param pGeometry [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 构造成功返回true。
	virtual UGbool MakeWithGeometry(const UGGeometry* pGeometry);

	//! \brief 获取数据存储时的大小
	//! \return 返回存储大小
	//! \remarks 暂未考虑编码情况，与SaveGeoData()一起维护
	//! \attention 字符串的长度要+4
	virtual UGint GetDataSize() const;

public:
#if !defined (IOS3D)
	//! \brief Geometry与Element的转换
	//! \param pElement,返回的pElement指针在函数内分配内存,外面负责删除，否则会有内存泄漏
	virtual UGbool ToElement(OgdcElement*& pElement)  const;
	
	//! \brief Geometry与Element的转换
	//! \param pElement,传入的Element，如果无法转换则返回False，否则返回True
	virtual UGbool FromElement(const OgdcElement* pElement);
#endif
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


public:
	//! \brief 根据投影转化器的设置和转化方向要求, 进行投影转化
	//! \param pPJTranslator 投影转化器
	//! \param bForward 转化方向, true代表从UGRefTranslator的源(Src)转化到目的(Des), false则相反
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);

	//! \brief 进行三维投影坐标系统转化
	//! \attention 暂未实现。
	virtual void PJConvert3D( UGRefTranslator *pPJTranslator, UGbool bForward = true);	

	//! \brief 从经纬坐标系统转化为投影坐标系统
	//! \param pCoordSys 投影坐标系统
	virtual void PJForward( UGPrjCoordSys *pCoordSys );

	//! \brief 从投影坐标系统转化为经纬坐标
	//! \param pCoordSys 投影坐标系统
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );

	//! \brief 从经纬坐标系统转化为三维投影坐标系统
	//! \param pCoordSys 投影坐标系统
	virtual void PJForward3D( UGPrjCoordSys *pCoordSys );
	
	//! \brief 从投影坐标系统转化为经纬坐标系
	//! \param pCoordSys 投影坐标系统
	virtual void PJInverse3D( UGPrjCoordSys *pCoordSys );


public:
	//! \brief 三角划分构建成几何模型，并归一化。
	//! \param nStacks [in] 横向分几份。
	//! \param nSlices [in] 竖向分几段。
	//! \return 几何模型指针。
	//! \remarks 。
	//! \attention 。
	UGGeoModel* GetModel(UGint nStacks, UGint nSlices);
	//! \brief 得到模型体积。
	virtual UGdouble GetVolume();
	//! \brief 得到三维几何对象的内点
	virtual UGPoint3D GetInnerPoint3D() const;
	//! \brief 用已有的Pie拷贝构造Pie。
	//! \param geoPie [in]已有的Pie。
	//! \return 已有Pie非法,返回false。
	UGbool Make(const UGGeoPieCylinder& geoPieCylinder);

	//! \brief 用圆心/长半轴/短半轴/旋转角度/起始角度/终止角度来构造Pie。
	//! \param pntCenter [in] 圆心。
	//! \param dSemiMajorAxis [in] 长半轴。
	//! \param dSemiMinorAxis [in] 短半轴。
	//! \param dRotationAngle [in] 旋转角度。
	//! \param dStartAngle [in] 起始角度。
	//! \param dEndAngle [in] 终止角度。
	//! \return 长半轴或短半轴小于0,返回false。
	UGbool Make(const UGPoint3D& pntCenter, UGdouble dSemiMajorAxis, UGdouble dSemiMinorAxis, 
				UGdouble dRotationAngle, UGdouble dStartAngle, UGdouble dEndAngle , UGdouble dHeight);	

	//! \brief 通过起始点/中间点/终止点来构造Pie。
	//! \param pntStart [in] 起始点。
	//! \param pntMiddle [in] 中间点。
	//! \param pntEnd [in] 终止点。
	//! \return 如果三点共线,则返回false。
	UGbool Make(const UGPoint2D& pntStart, const UGPoint2D& pntMiddle, const UGPoint2D& pntEnd , UGdouble z, UGdouble dHeight);    

	//! \brief 得到圆心。
	//! \return 返回圆心。
	UGPoint3D GetCenterPoint() const;    

	//! \brief 得到长半轴。
	//! \return 返回长半轴。
	UGdouble GetSemiMajorAxis() const;    

	//! \brief 设置长半轴。
	//! \param dSemiMajorAxis [in] 长半轴。
	void SetSemiMajorAxis( UGdouble dSemiMajorAxis );    

	//! \brief 得到短半轴。
	//! \return 返回短半轴。
	UGdouble GetSemiMinorAxis() const;    

	//! \brief 设置短半轴。
	//! \param dSemiMinorAxis [in] 短半轴。
	void SetSemiMinorAxis( UGdouble dSemiMinorAxis );    

	//! \brief 得到旋转角度。
	//! \return 返回旋转角度。
	UGdouble GetAngle() const;    

	//! \brief 设置旋转角度。
	//! \param dRotationAngle [in] 旋转角度。
	void SetAngle( UGdouble dRotationAngle );    

	//! \brief 得到起始角度。
	//! \return 返回起始角度。
	UGdouble GetStartAngle() const;    

	//! \brief 设置起始角度。
	//! \param dStartAngle [in] 起始角度。
	void SetStartAngle( UGdouble dStartAngle );    

	//! \brief 得到终止角度。
	//! \return 返回终止角度。
	UGdouble GetEndAngle() const;    

	//! \brief 设置终止角度。
	//! \param dEndAngle [in] 终止角度。
	void SetEndAngle( UGdouble dEndAngle );    

	//! \brief 得到起始点(即起始角度和斜椭圆的交点)。
	//! \return 返回起始点。
	UGPoint2D GetStartPoint() const;	

	//! \brief 得到终止点(即终止角度和斜椭圆的交点)。
	//! \return 返回终止点。
	UGPoint2D GetEndPoint() const;	

	//! \brief 获得柱体高度。
	//! \return 高度。
	UGdouble GetHeight() const;

	//! \brief 设置柱体高度。
	//! \param dHeight 高度[in] 。
	void SetHeight( UGdouble dHeight );
	
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

	 //! \brief 计算对象绘制时的辅助点，返回的是点的数目,nHandleType返回的是辅助点的类型,参考UGEditType::EditHandleType
	//! \param pPoints 点串
	//! \param nPntCount  点的个数
	//! \param eAssistantPoints 点串,返回的辅助点点串
	//! \param nEditType 绘制对象的类型，参考UGEditType
	 virtual void CalAssistantPoints(const UGPoint2D* pPoints,UGint nPntCount,UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,UGEditType::EditToolShape nEditType);


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
	//! \brief 计算Bounds。
	//! \return Bounds。
	virtual UGRect2D ComputeBounds() const;	

	//! \brief 只保存几何数据部分。
	//! \param stream 存储流, 调用之前应该先Open[in]。
	//! \param eCodecType 存储的编码方式[in]。
	//! \param bSDBPlus 是否存储为SDBPlus的格式[in]。
	//! \return 成功返回true,失败返回false。
	//! \remarks 由于SDBPlus引擎和数据库引擎的存储上差别较大,所以必须直接调用该函数,
	//! 并增加变量进行分别处理
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const	;
	
	//! \brief 只转载几何数据部分。
	//! \param stream 流[in]。
	//! \param eCodecType 编码方式[in]。
	//! \param bSDBPlus 是否存储为SDBPlus的格式[in] [in]。
	//! \return 成功返回true,失败返回false。
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE ,UGbool bSDBPlus = FALSE);	
    
	//!\brief 得到Boundingbox
	virtual UGBoundingBox ComputeBoundingBox() const;

	//! \brief 获得顶点串。
	//! \param pPoints 点串[out]。
	void GetVertexes(UGPoint2D* pPoints) const;	


private:
	//! \brief 长半轴
	UGdouble m_dSemiMajorAxis;
	
	//! \brief 短半轴
	UGdouble m_dSemiMinorAxis;

	//! \brief 旋转角度
	//! \remarks 内存中改为double,角度单位,存储时和SFC保持兼容
	UGdouble m_dRotationAngle;

	//! \brief 起始角度
	//! \remarks 内存中改为double,角度单位,存储时和SFC保持兼容
	UGdouble m_dStartAngle;//起角

	//! \brief 终止角度
	//! \remarks 内存中改为double,角度单位,存储时和SFC保持兼容
	UGdouble m_dEndAngle;//终角

	//! \brief 柱体高度
	UGdouble m_dHeight;
	
};
}
#endif // !defined(AFX_UGGEOPIECYLINDER_H__A5D81352_F683_4B67_8180_B73E6DF3AA8D__INCLUDED_)

