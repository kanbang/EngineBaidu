//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGGeoRegion3D.h
//!  \brief ��ά�漸�ζ���
//!  \author UGCTeam��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOREGION3D_H__0C5189B8_3750_4468_8FAD_EE5C1969F4EB__INCLUDED_)
#define AFX_UGGEOREGION3D_H__0C5189B8_3750_4468_8FAD_EE5C1969F4EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry3D/UGGeometry3D.h"
#include "Geometry3D/UGEditType3D.h"

namespace UGC
{
//! \brief ��ά�漸�ζ���
class GEOMETRY3D_API UGGeoRegion3D : public UGGeometry3D
{
public:
	
	//! \brief ȱʡ���캯��
	UGGeoRegion3D();

	//! \brief Ĭ����������
	virtual ~UGGeoRegion3D();
public:
	
	//! \brief �õ�ά��, ��Ϊ0ά, ��/���ߵ�Ϊ1ά, ��/�����Ϊ2ά, GeoCompound/GeoText��Ϊ-1
	virtual UGint GetDimension() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \return �����ڵ�
	//! \remarks Ϊ���������Ӷ��� ���м��(�м�����ĵ�, �������м����ĵ�)
	virtual UGPoint2D GetInnerPoint() const;

	//! \brief �õ��ڵ㣨������Geometry3D���ʵ㣩
	//! \return �����ڵ�
	virtual UGPoint3D GetInnerPoint3D() const;

	//! \brief �õ��ռ�����, ��Ҫ������Ҫ����ά����ͬʱ
	//! ����ͳһ�����ʱ��, ����һЩ�ռ��жϺͲ������㷨
	//! \param pPoints [out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	//! �˽ӿ���δʵ��
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid()const;

	//! \brief �������ж����ָ�룬��������һ����ά�漸�ζ���
	//! \param pGeometry [in] ���ж���ָ�롣
	//! \return ����ɹ�����true��
	//! \remarks �ڲ�����make����ȥʵ�֡�
	virtual UGbool MakeWithGeometry(const UGGeometry* pGeometry);
	
	//! \brief ������ά�㴮����һ����ά�漸�ζ���
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] ��ĸ�����
	//! \param UGEditType3D::ET3D_NULL [in] �༭������״����ѡ����
	//! \return ����ɹ�����true��
	//! \remarks �ڲ�����make����ȥʵ�֣������ڱ༭�ж�̬�������GeoLine��
	virtual UGbool MakeWithPoints3D(UGPoint3D* pPoints,UGint nPntCount,
		UGEditType3D::EditToolShape3D nEditType = UGEditType3D::ET3D_NULL);	

	//! \brief ���ݴ���ĵ㴮���ɶ�����Ҫ���ڱ༭�еĲ�������û���ڲ����鱣��㴮�Ķ���
	//! Ҳ�����Զ������,�������ڲ����鱣��㴮�Ķ��󣬸ú���ֱ��return�ȿɣ�
	//! ����GeoLine�ȶ����ֱ����AddHandle�����ɣ�Ч�ʱȽϸ� 
	//! \param pPoints 3ά�㴮
	//! \param nPntCount  ��ĸ���
	virtual void MakeWithPoints(UGPoint3D* pPoints,UGint nPntCount,
				UGEditType::EditToolShape nEditType=UGEditType::ET_Default);
	//! \brief ����������ʱ�ĸ����ߣ����ص���һ�����϶���
	//! \param pPoints [in] �㴮
	//! \param nPntCount [in] ��ĸ���
	//! \param nEditType [in] ���ƶ�������ͣ��ο�UGEditType3D
	//! \param pStyle [in] �����ߵķ���������ΪNULL����Ĭ�ϵķ��
	//! \return ������ļ��ζ���
	UGGeometry* CalAssistantLine(const UGPoint3D* pPoints,UGint nPntCount,UGEditType3D::EditToolShape3D nEditType);

	//! \brief �õ������λ�ã��������ֻ��ģ�ͺ͹��򼸺������壬λ��Ϊģ�͵�����ĵ������ĵ㣬��������ģ��Ϊ��Ӧ���ڵ㣩
	//! \return �����λ�á�
	virtual UGPoint3D GetPosition() const;

	//! \brief ��ȡ���ݴ洢ʱ�Ĵ�С
	//! \return ���ش洢��С
	//! \remarks ��δ���Ǳ����������SaveGeoData()һ��ά��
	//! \attention �ַ����ĳ���Ҫ+4
	virtual UGint GetDataSize() const;

public:
	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ
	
	//! \brief ��ñ༭����ľ������Ŀ
	//! \remarks ���ڹ̶��������Ϊ9�����˸ı��С��8�����Ƶ��һ����ת���Ƶ�
	virtual UGint  GetHandleCount();
	
	
	//nHandle:��ֵ����Ƶ�Ĺ�ϵ����ͼ                         
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
	
	//! \brief ���ݾ�������Ӧ���Ƶ��ֵ
	//! \param nHandle ���Ƶ���
	//! \param point �����Ӧ�Ŀ��Ƶ������ֵ
	//! \return ���ظ����������
	 virtual UGint GetHandle( UGint nHandle, UGPoint2D& point);
	 //! \brief �ƶ����Ƶ㵽ָ������,��Ҫ���ڻ��ƶ����޸Ķ���ڵ�Ȳ���
	 //! \param nHandle ���Ƶ���
	 //! \param point ���Ƶ�����
	 virtual void MoveHandle( UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_Default);
	 
	 //! \brief �ڵ�༭ʱ����������һ�����Ƶ�,Ҳ�������ڻ��ƶ���ʱ����ڵ�
	 //! \param nHandle ����λ��
	 //! \param pnt2D �����ĵ�������
	 virtual void AddHandle( UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_Default);
	 
	 //! \brief ɾ���༭�����ָ���ڵ�
	 //! \param nHandle �ڵ���
     virtual UGuint DelNode( UGint nHandle );
	 
	 //! \brief ����������ʱ�ĸ����ߣ����ص���һ�����϶���
	 //! \param pPoints �㴮
	 //! \param nPntCount  ��ĸ���
	 //! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	 //! \param pStyle	 �����ߵķ���������ΪNULL����Ĭ�ϵķ��
     virtual UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);
	 
	 
	 //! \brief ����������ʱ�ĸ����㣬���ص��ǵ����Ŀ,nHandleType���ص��Ǹ����������,�ο�UGEditType::EditHandleType
	 //! \param pPoints �㴮
	 //! \param nPntCount  ��ĸ���
	 //! \param eAssistantPoints �㴮,���صĸ�����㴮
	 //! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	 void CalAssistantPoints(const UGPoint2D* pPoints,UGint nPntCount,UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,UGEditType::EditToolShape nEditType);
	 
	 
	 
	 //! \brief ���ݴ���ĵ㴮���ɶ�����Ҫ���ڱ༭�еĲ�������û���ڲ����鱣��㴮�Ķ���
	 //Ҳ�����Զ������,�������ڲ����鱣��㴮�Ķ��󣬸ú���ֱ��return�ȿɣ�����GeoLine
	 //GeoLine�ȶ����ֱ����AddHandle�����ɣ�Ч�ʱȽϸ�,���������ƽ���ߣ�������������
	 //! \param pPoints �㴮
	 //! \param nPntCount  ��ĸ���
    // virtual void MakeWithPoints(UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType=UGEditType::ET_Default);
	 
	 //! \brief ��ȡ������Ҫ��׽�ĵ㴮
	 //! \param aryPnts �㴮������ȥ��Ҫ��׽�ĵ㴮
	 //! \return �����true��ʾ����Ҫ��׽�ĵ㴮���������false��ʾ�ö���û����Ҫ��׽�ĵ㴮
	 virtual UGbool GetSnapPoints(UGArray<UGPoint2D>& aryPnts);
	 
	 //! \brief ��ȡ������Ҫ��׽���߶�����
	 //! \param aryLines ��Ҫ��׽�������飨����ж��part����ôaryLines��Ӧ���ж��ٸ�count��
	 //! \return �����true��ʾ����Ҫ��׽���ߣ��������false��ʾ�ö���û����Ҫ��׽����
	 virtual UGbool GetSnapLines(UGLineArray& aryLines);
	 
	 //added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ end
	 
	 //! \brief ������������,�޶����µ�Bounds��
	 //! \param rcNewBounds �µ�,�޶���Χ��Bounds
	 //! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

	//! \brief ���󱣻��Էֽ�
	//! \param arrOutRegion	���صı��ֽ�Ķ���
	//! \return 
	UGbool ProtectedDecomposeEx(UGArray<UGGeoRegion3D*> &arrOutRegion3D);

protected:
	//! \brief ��������Bounds
	//! \return ���صõ���Bounds
	virtual UGRect2D ComputeBounds() const;	
	
	//! \brief ֻ���漸�����ݲ���
	//! \param stream [in] �洢��, ����֮ǰӦ����Open
	//! \param eCodecType [in] �洢�ı��뷽ʽ
	//! \param bSDBPlus [in] �Ƿ�洢ΪSDBPlus�ĸ�ʽ
	//! \remarks ����SDBPlus��������ݿ�����Ĵ洢�ϲ��ϴ�,���Ա���ֱ�ӵ��øú���,
	//! �����ӱ������зֱ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool SaveGeoData(UGStream& stream, 
		UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	
	//! \brief ֻת�ؼ������ݲ���
	//! \param stream [in] �� 
	//! \param eCodecType [in] ���뷽ʽ
	//! \attention [in] ����Ҫ���� UGbool bSDBPlus = FALSE �Ĳ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool LoadGeoData( UGStream& stream , 
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );

	//!\brief �õ�Boundingbox
	virtual UGBoundingBox ComputeBoundingBox() const;

public:		
	
	//! \brief �õ��������
	//! \attention DimensionΪ2�Ķ����֧��
	//! \return �������
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGdouble GetArea() const;
	
	//! \brief �õ���ά����ı����
	//! \attention DimensionΪ2�Ķ����֧��
	//! \return ���ر����
	virtual UGdouble GetArea3D() const;
	
	//! \brief �õ����󳤶�
	//! \attention DimensionΪ1or2�Ķ����֧��
	//! \return ���س���
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGdouble GetLength() const;
	
	//! \brief �õ���ά���󳤶�
	//! \attention DimensionΪ1or2�Ķ����֧��
	//! \return ���س���
	virtual UGdouble GetLength3D() const;
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	//! \param dRatioY Z�������ű���
	//! \attention ��Բ�޷���������ͬ��������, ���dRatioX��dRatioY������Ȳ���
	virtual void Inflate3D( UGdouble dRatioX, UGdouble dRatioY,UGdouble dRatioZ);
	
	//! \brief ����
	//! \param dRatio ���ű���(X,Y������ͬ)
	virtual void Inflate3D( UGdouble dRatio);

	//! \brief ��ά������ת
	//! \param vecAxis [in] ��ת�� ��ԭ��
	//! \param dAngle [in] ��ת�Ƕ�
	virtual void Rotate3D(const UGVector3d& vecAxis, UGdouble dAngle);

	//! \brief ƽ��
	//! \param dX ƽ�Ƶ�Xƫ����
	//! \param dY ƽ�Ƶ�Yƫ����
	virtual void Offset( UGdouble dX, UGdouble dY);
	
	//! \brief ƽ��
	//! \param ƫ����(X,Y������ͬ)
	virtual void Offset( UGdouble dOffset);
	
	//! \brief ƽ��
	//! \param ƽ�Ƶ�ƫ����(�ֱ���UGSize2D�е�x,y����X,Y�����ƫ����)
	virtual void Offset( const UGSize2D &szOffset);
	
	//! \brief ��ά����ƽ��
	//! \param dX [in] ƽ�Ƶ�Xƫ����
	//! \param dY [in] ƽ�Ƶ�Yƫ����	
	//! \param dZ [in] ƽ�Ƶ�Zƫ����	
	virtual void Offset3D( UGdouble dX, UGdouble dY, UGdouble dZ);
	
	//! \brief ��ά����ƽ��
	//! \param dOffset [in] ƫ����(X,Y,Z������ͬ)	
	virtual void Offset3D( UGdouble dOffset);
	
	//! \brief ��ά����ƽ��
	//! \param vecOffset [in] ƽ�Ƶ�ƫ����(�ֱ���UGVector3d�е�x,y,z����X,Y,Z�����ƫ����)��
	virtual void Offset3D( const UGVector3d &vecOffset);	

	//! \brief ���㾵��
	//! \param pntMirror1 [in] ���ɾ���ĵ�һ����
	//! \param pntMirror2 [in] ���ɾ���ĵڶ�����
	//! \param pntMirror3 [in] ���ɾ���ĵ�������
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror3D(const UGPoint3D &pntMirror1, const UGPoint3D &pntMirror2, const UGPoint3D &pntMirror3);
	
	
	//! \brief ����
	//! \param vecNormal [in] ����ķ�������	
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror3D(const UGVector3d &vecNormal);


public:
	//! \brief ת��Ϊ�߶���
	//! \param geoLine[out] �õ����߶���
	//! \param nSegmentCount [in] ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;
	
	//! \brief ת��Ϊ�����
	//! \param geoRegion[out] �õ��������
	//! \param nSegmentCount [in] ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;
	
	//! \brief ת���ɶ����󣬿��԰�3D�㡢3D������ת���ɶ�������ʾ��
	//! \param geoMultiPoint [out] �����㼸�ζ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToPoint( UGGeoMultiPoint &geoMultiPoint) const;	

	//! \brief ת����ͼƬ��3D���ͼ��ζ����Լ��û����ͼ��ζ������ͨ����ת����ͼƬ������ʾ��
	//! \param geoPicture [out] ���ͼƬ���ζ���
	//! \param dResolution [in] �ֱ��ʡ�
	//! \param dXAngle [in] ˮƽ��ǡ�
	//! \param dZAngle [in] ��ת��ǡ�
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToPicture( UGGeoPicture &geoPicture, UGdouble dResolution, 
								UGdouble dXAngle = 0, UGdouble dZAngle = 0) const;	
	
public:
	//Projection..
	
	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator [in] ͶӰת����
	//! \param bForward [in] ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);

	
	//! \brief ������άͶӰ����ϵͳת��
	//! \attention ��δʵ�֡�
	virtual void PJConvert3D( UGRefTranslator *pPJTranslator, UGbool bForward = true);	
	
	//! \brief �Ӿ�γ����ϵͳת��ΪͶӰ����ϵͳ
	//! \param pCoordSys [in] ͶӰ����ϵͳ
	virtual void PJForward( UGPrjCoordSys *pCoordSys );
	
	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����
	//! \param pCoordSys [in] ͶӰ����ϵͳ
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );

	//! \brief �Ӿ�γ����ϵͳת��Ϊ��άͶӰ����ϵͳ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJForward3D( UGPrjCoordSys *pCoordSys );
	
	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����ϵ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJInverse3D( UGPrjCoordSys *pCoordSys );

public:
	//! \brief ����XML��ʽ����Ϣ
	//! \param versionType GML�İ汾
	//! \param nPace �����Ŀո���Ŀ,ʹ��xml�ַ������������˹��Ķ�; 
	//! ��Ҫ����������ص�xml�ַ�����һ�����ǩ�е�һ����, ͨ��ָ���ո���Ŀ,����ʹ�������
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual UGString ToXML(GMLVersionType versionType, UGint nPace = 0) const;
	
	//! \brief ��XML�ַ���������Geometry
	//! \param strXML xml��ʽ�ַ���
	//! \param versionType xml�ַ�����GML�汾
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual UGbool FromXML(const UGString& strXML, GMLVersionType versionType);
	//! \brief �õ����ζ������͡�
	//! \return �̶�Ϊ GeoRegion3D��
	virtual UGGeometry::Type GetType() const;
	
	//! \brief ��յ�������
	virtual void Clear();

	//! \brief �õ�ָ���Ӷ���ĵ㴮��ָ�롣
	//! \param nSubIndex [in] �Ӷ���������
	//! \return �����Ӷ���ĵ㴮��ָ�롣
	const UGPoint3D* GetPoints(UGint nSubIndex=0) const;	
	
	//! \brief ����һ���Ӷ����GeoRegion
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�ĵ���Ŀ��
	//! \return ����С��3��,����false��
	UGbool Make( const UGPoint3D* pPoints, UGint nPntCount );

	//! \brief �������������
	//! \param pPoints [in] �㴮ָ�롣
	//! \param pPolyCount [in] �Ӷ����е��������顣
	//! \param nSubCount [in] �Ӷ�����Ŀ��
	//! \return �����Ӷ���ĵ�����С��3��,����false��
	virtual	UGbool Make(const UGPoint3D* pPoints, const UGint* pPolyCount, UGint nSubCount);

	//! \brief ��������GeoRegion3D
	//! \param geoRegion [in] ���������
	//! \return ���������Ƿ�, ����false��
	UGbool Make(const UGGeoRegion3D& geoRegion);

	//! \brief �����Ӷ���
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮������
	//! \return ��ĸ�������3��,����false��
	UGbool AddSub(const UGPoint3D* pPoints, UGint nPntCount);	

	//! \brief �����Ӷ���
	//! \param geoRegion3D [in]��
	UGbool AddSub(UGGeoRegion3D *geoRegion3D);

	//! \brief �����Ӷ���
	//! \param nIndex [in] Ҫ�����λ��������
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�е�ĸ�����
	//! \return �����С��3��������λ�÷Ƿ�,����false��
	UGbool InsertSub(UGint nIndex, const UGPoint3D* pPoints, UGint nPntCount);	

	//! \brief ɾ���Ӷ���
	//! \param nIndex [in] Ҫɾ�����Ӷ����λ��������
	//! \return �����Ƿ�, ����false��
	UGbool DelSub(UGint nIndex);

	//! \brief �õ�ĳ���Ӷ���, ������õ�GeoRegion3D��
	//! \param nSubIndex [in] �Ӷ���������
	//! \param pGeoRegion3D [out] ͨ�����Ӷ�����õ���GeoRegion3D; ���pGeoRegion3DΪNULL,�����ڲ���new������
	//! \return �����Ƿ�, ����false��
	UGbool GetSub(UGint nSubIndex, UGGeoRegion3D *&pGeoRegion3D);

	//! \brief �õ��Ӷ�����Ŀ������ָ�롣
	//! \return �����Ӷ�����Ŀ������ָ�롣
	const UGint* GetPolyCounts() const;

	//! \brief �õ������Ӷ���ĵ�ĸ����ܺ͡�
	//! \return ���ظ�����
	UGint GetPointCount() const;	
	
	//! \brief �õ��Ӷ���ĸ���
	//! \return ���ظ���
	virtual UGint GetSubCount() const;
	
	//! \brief �õ�ĳ���Ӷ���ĵ�ĸ�����
	//! \param nSubIndex [in] �Ӷ���������
	//! \return ���ظ�����
	UGint GetSubPntCount(UGint nSubIndex) const;

	void GetIndexData(UGArray<UGuint>& arrSubCounts, UGArray<UGArray<UGushort> >& arrIndexes);
	void SetIndexData(UGArray<UGuint>& arrSubCounts, UGArray<UGArray<UGushort> >& arrIndexes);

	void GetIndexData(UGArray<UGuint>& arrSubCounts, UGArray<UGArray<UGuint> >& arrIndexes);
	void SetIndexData(UGArray<UGuint>& arrSubCounts, UGArray<UGArray<UGuint> >& arrIndexes);
	

private:

	//! \brief ���ڲ�����ά������ת�ɶ�ά��
	//! \return ���ض�ά��ָ�룬����ע��ʹ�ú��ͷš�	
	const UGPoint2D* GetPoint2D() const;

	const UGPoint3D* GetPoint3D() const;
	
	//! \brief ����������е㡣
	UGArray<UGPoint3D> m_Points;

	//! \brief ����Ӷ��������
	UGArray<UGint> m_PolyCounts;


	//��������
	UGushort* m_pIndexes;

	//������������
	UGbool m_bUseIndexUint;


	//ÿ���ʷֵ�λ�� ��������
	UGuint* m_pSubIndexCounts;

	//ÿ���ʷֵ�λ�� SubRegion����
	UGuint* m_pSubRegionCounts;

	//��С�ʷֵ�λ����
	UGuint m_nSubCount;
};

}

#endif // !defined(AFX_UGGEOREGION3D_H__0C5189B8_3750_4468_8FAD_EE5C1969F4EB__INCLUDED_)

