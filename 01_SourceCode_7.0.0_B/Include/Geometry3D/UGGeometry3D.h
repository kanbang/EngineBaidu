//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGGeometry3D.h
//!  \brief ��ά���ζ�����ࡣ
//!  \author UGCteam��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOMETRY3D_H__0D8126C6_CAE8_4AD5_91D7_47DF8BD75819__INCLUDED_)
#define AFX_UGGEOMETRY3D_H__0D8126C6_CAE8_4AD5_91D7_47DF8BD75819__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Geometry/UGGeometry.h"
#include "Base3D/UGVector3d.h"
#include "Base3D/UGBoundingBox.h"
#include "Geometry3D/UGEditType3D.h"
#include "Base3D/UGStyle3D.h"

namespace UGC
{
//class UGStyle3D;
class UGGeoModel;

//! \brief ��ά���ζ�����ࡣ
class GEOMETRY3D_API UGGeometry3D : public UGGeometry
{
public:
	//! \brief ȱʡ���캯����
	UGGeometry3D();	
	
	//! \brief Ĭ������������
	virtual ~UGGeometry3D();

	//! \brief ��յ�������
	virtual void Clear();

	//! \brief �õ�ά�ȡ�
	//! \return ά����
	//! \remarks ��Ϊ0ά, ��/���ߵ�Ϊ1ά, ��/�����Ϊ2ά, GeoCompound/GeoText��Ϊ-1�������ݿ�洢ʱ�á�
	virtual UGint GetDimension() const;	

	//! \brief �õ����ζ������͡�
	//! \return �̶�Ϊ Null��
	virtual UGGeometry::Type GetType() const;	
	
	//! \brief �Ƿ�����ά���ζ���
	//! \return ����Ƿ���TRUE��
	virtual UGbool Is3D() const;

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
	
	//! \brief �õ��ڵ㣨��Geometry3D���Ӧ��Geometry�ڲ�����������ĵ㣩
	//! \return �����ڵ�
	virtual UGPoint2D GetInnerPoint() const;	

	//! \brief �õ��ڵ㣨������Geometry3D���ʵ㣩
	//! \return �����ڵ�
	virtual UGPoint3D GetInnerPoint3D() const;

	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid() const;
	
	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;

      //! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual UGbool HitTest3D( const UGPoint3D &pntHitTest, UGdouble dTolerance) const;


	//! \brief �������, ������ά��������ά�ռ��е�ѡ��
	//! \param vecStart [in] ��ʼ�㡣
	//! \param vecEnd [in] ��ֹ�㡣
	//! \param dTolerance [in] ���ޡ�
	//! \return ѡ�з���true, ���򷵻�false��
	//! \remarks ����������߼�ⷨ����ʱû��ʵ�֡�
	virtual UGbool HitTest3D(const UGVector3d& vecStart, const UGVector3d& vecEnd, UGdouble dTolerance) const;	
	
	//! \brief ����
	//! \param dRatioX [in] X�������ű��ʡ�
	//! \param dRatioY [in] Y�������ű��ʡ�
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ�֡�
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);	
	
	//! \brief ����
	//! \param dRatio [in] ���ű���(X,Y������ͬ)��
	virtual void Inflate( UGdouble dRatio);	
	
	//! \brief ƽ�ơ�
	//! \param dX [in] ƽ�Ƶ�Xƫ������
	//! \param dY [in] ƽ�Ƶ�Yƫ������
	virtual void Offset( UGdouble dX, UGdouble dY);	
	
	//! \brief ƽ�ơ�
	//! \param dOffset [in] ƫ����(X,Y������ͬ)��
	virtual void Offset( UGdouble dOffset);	
	
	//! \brief ƽ��
	//! \param szOffset [in] ƽ�Ƶ�ƫ����(�ֱ���UGSize2D�е�x,y����X,Y�����ƫ����)��
	virtual void Offset( const UGSize2D &szOffset);	
	
	//! \brief ��ת
	//! \param pntOrigin [in] ��ת�����ĵ�(ê��,������)��
	//! \param dAngle [in] ��ת�Ƕȡ�
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief ��ת,����һЩ����,�Ա��ڲ����Բ��ý���cos,sin, �����������ʱ�����������Ч�ʡ�
	//! \param pntOrigin [in] ��ת�����ĵ�(ê��,������)��
	//! \param dCosAngle [in] ��ת��cosֵ��
	//! \param dSinAngle [in] ��ת��sinֵ��
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \remarks dAngle���ƶ���,��GeoText��Ҫ,����Ҫ������
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle,UGdouble dAngle = 0);	
	
	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds [in] �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Resize(const UGRect2D& rcNewBounds);

	//! \brief ���㾵��
	//! \param pntMirror1 [in] ���ɾ���ĵ�һ����
	//! \param pntMirror2 [in] ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);

	//! \brief ���㾵��
	//! \param pntMirror1 [in] ���ɾ���ĵ�һ����
	//! \param pntMirror2 [in] ���ɾ���ĵڶ�����
	//! \param pntMirror3 [in] ���ɾ���ĵ�������
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror3D(const UGPoint3D &pntMirror1, const UGPoint3D &pntMirror2, const UGPoint3D &pntMirror3);//liuy 2009-5-20

	//! \brief ����
	//! \param vecNormal [in] ����ķ�������	
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror3D(const UGVector3d &vecNormal); //liuy 2009-5-20

	
	
public:
	// ������Geometry3D���Ӧ�ķ���...

	//! \brief ��ά��������
	//! \param dRatioX [in] X�������ű���
	//! \param dRatioY [in] Y�������ű���
	//! \param dRatioZ [in] Z�������ű���
	virtual void Inflate3D( UGdouble dRatioX, UGdouble dRatioY, UGdouble dRatioZ);

	//! \brief ��ά��������
	//! \param dRatio [in] ���ű���(X,Y,Z������ͬ)	
	virtual void Inflate3D( UGdouble dRatio);

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

	//! \brief ��ά������ת
	//! \param pntOrigin [in] ��ת�����ĵ�(ê��,������)
	//! \param dAngle [in] ��ת�Ƕ�
	virtual void Rotate3D(const UGPoint3D& pntOrigin, UGdouble dAngle);
	
	//! \brief ��ά������ת,����һЩ����,�Ա��ڲ����Բ��ý���cos,sin, �����������ʱ�����������Ч��
	//! \param pntOrigin [in] ��ת�����ĵ�(ê��,������)
	//! \param dCosAngle [in] ��ת��cosֵ
	//! \param dSinAngle [in] ��ת��sinֵ
	//! \param dAngle [in] ��ת�Ƕ�	
	//! \remarks dAngle���ƶ���,��GeoText��Ҫ,����Ҫ����
	virtual void Rotate3D( const UGPoint3D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, UGdouble dAngle = 0);

	//! \brief ��ά������ת
	//! \param vecAxis [in] ��ת�� ��ԭ��
	//! \param dAngle [in] ��ת�Ƕ�
	virtual void Rotate3D(const UGVector3d& vecAxis, UGdouble dAngle);

	//! \brief ��ά��������������ݣ��޶����µ�BoundingBox��
	//! \param rcNewBox [in] �µ�,�޶���Χ��BoundingBox
	//! \return �ɹ�����true,ʧ�ܷ���false	
	virtual UGbool Resize3D(const UGBoundingBox& rcNewBox);

	//! \brief ֻ���漸�����ݲ��֡�
	//! \param stream [in] �洢��, ����֮ǰӦ����Open��
	//! \param eCodecType [in] �洢�ı��뷽ʽ��
	//! \param FALSE [in] �Ƿ�洢ΪSDBPlus�ĸ�ʽ��
	//! \return �ɹ�����true,ʧ�ܷ���false��
	//! \remarks ����SDBPlus��������ݿ�����Ĵ洢�ϲ��ϴ�,���Ա���ֱ�ӵ��øú���,�����ӱ������зֱ���
	//! \attention ��SDBPlus����,���ò�public֮��
	virtual UGbool SaveGeoData(UGStream& stream, 
		UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	//! \brief ֻת�ؼ������ݲ���
	//! \param stream [in] �� 
	//! \param eCodecType [in] ���뷽ʽ
	//! \attention ����Ҫ���� UGbool bSDBPlus = FALSE �Ĳ���
	//! \return �ɹ�����true,ʧ�ܷ���false	
	virtual UGbool LoadGeoData( UGStream& stream , 
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );

	//! \brief ��Geometry����XML�ַ���
	//! \param versionType [in] GML�İ汾
	//! \param nPace [in] �����Ŀո���Ŀ,ʹ��xml�ַ������������˹��Ķ�; 
	//! ��Ҫ����������ص�xml�ַ�����һ�����ǩ�е�һ����, ͨ��ָ���ո���Ŀ,����ʹ�������
	//! \return ����ָ��GML�汾��xml�ַ���
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGString ToXML(GMLVersionType versionType, UGint nPace = 0)  const;

	//! \brief ��XML�ַ���������Geometry
	//! \param strXML [in] xml��ʽ�ַ���
	//! \param versionType [in] xml�ַ�����GML�汾
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual UGbool FromXML(const UGString& strXML, GMLVersionType versionType);

	//! \brief ����ά���ζ�������XML�ַ���
	//! \param versionType [in] GML�İ汾
	//! \param nPace [in] �����Ŀո���Ŀ,ʹ��xml�ַ������������˹��Ķ�; 
	//! ��Ҫ����������ص�xml�ַ�����һ�����ǩ�е�һ����, ͨ��ָ���ո���Ŀ,����ʹ�������
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual UGString ToXML3D(GMLVersionType versionType, UGint nPace = 0)  const;

	//! \brief ��XML�ַ�����������άGeometry
	//! \param strXML [in] xml��ʽ�ַ���
	//! \param versionType [in] xml�ַ�����GML�汾
	//! \return ����ָ��GML�汾��xml�ַ���	
	virtual UGbool FromXML3D(const UGString& strXML, GMLVersionType versionType);
#if !defined (IOS3D)
	//! \brief Geometry��Element��ת��
	//! \param pElement [in] ���ص�pElementָ���ں����ڷ����ڴ�,���渺��ɾ������������ڴ�й©
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGbool ToElement(OgdcElement*& pElement)  const;
	
	//! \brief Geometry��Element��ת��
	//! \param pElement [in] �����Element������޷�ת���򷵻�False�����򷵻�True
	virtual UGbool FromElement(const OgdcElement* pElement);

	//! \brief Geometry3D��Element��ת��
	//! \param pElement [in] ���ص�pElementָ���ں����ڷ����ڴ�,���渺��ɾ������������ڴ�й©
	virtual UGbool ToElement3D(OgdcElement*& pElement)  const;

	//! \brief Geometry3D��Element��ת��
	//! \param pElement [in] �����Element������޷�ת���򷵻�False�����򷵻�True	
	virtual UGbool FromElement3D(const OgdcElement* pElement);
#endif
	//! \brief ���򼸺���������ǻ������ɼ���ģ�͡�
	//! \param nStacks [in] ����ּ��ݡ�
	//! \param nSlices [in] ����ּ��Ρ�
	//! \return ����ģ��ָ�롣
	virtual UGGeoModel* GetModel(UGint nStacks, UGint nSlices);
public:
	
	// �༭��غ���,�ѱ༭��geometryͳһ...
	
	//! \brief ��ñ༭����ľ������Ŀ
	//! \remarks ���ڹ̶��������Ϊ9�����˸ı��С��8�����Ƶ��һ����ת���Ƶ�
	//! ת��2ά��Geometry�󣬵������ķ���ʵ��
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
	//! \param nHandle [in] ���Ƶ���
	//! \param point [in] �����Ӧ�Ŀ��Ƶ������ֵ
	//! \return ���ظ����������
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGint GetHandle( UGint nHandle, UGPoint2D& point);
	
	//! \brief �ƶ����Ƶ㵽ָ������,��Ҫ���ڻ��ƶ����޸Ķ���ڵ�Ȳ���
	//! \param nHandle [in] ���Ƶ���
	//! \param point [in] ���Ƶ�����
	//! \remarks ����ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual void MoveHandle( UGint nHandle, const UGPoint2D& pnt2D,
		UGEditType::EditToolShape nEditType=UGEditType::ET_Default);

	//! \brief �ڵ�༭ʱ����������һ�����Ƶ�,Ҳ�������ڻ��ƶ���ʱ����ڵ�
	//! \param nHandle [in] ����λ��
	//! \param pnt2D [in] �����ĵ�������
	//! \remarks ����ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual void AddHandle( UGint nHandle, const UGPoint2D& pnt2D,
		UGEditType::EditToolShape nEditType=UGEditType::ET_Default);

	//! \brief ɾ���༭�����ָ���ڵ�
	//! \param nHandle [in] �ڵ���
	//! \remarks ����ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGuint DelNode( UGint nHandle );

	//! \brief ����������ʱ�ĸ����ߣ����ص���һ�����϶���
	//! \param pPoints [in] �㴮
	//! \param nPntCount [in] ��ĸ���
	//! \param nEditType [in] ���ƶ�������ͣ��ο�UGEditType
	//! \param pStyle [in] �����ߵķ���������ΪNULL����Ĭ�ϵķ��
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints,
		UGint nPntCount,UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);
	
	//! \brief ����������ʱ�ĸ����㣬���ص��ǵ����Ŀ,
	//! nHandleType���ص��Ǹ����������,�ο�UGEditType::EditHandleType
	//! \param pPoints [in] �㴮
	//! \param nPntCount [in] ��ĸ���
	//! \param eAssistantPoints [in] �㴮,���صĸ�����㴮
	//! \param nEditType [in] ���ƶ�������ͣ��ο�UGEditType
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual void CalAssistantPoints(const UGPoint2D* pPoints, UGint nPntCount,
		UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,
		UGEditType::EditToolShape nEditType);
	
	//! \brief ���ݴ���ĵ㴮���ɶ�����Ҫ���ڱ༭�еĲ�������û���ڲ����鱣��㴮�Ķ���
	//! Ҳ�����Զ������,�������ڲ����鱣��㴮�Ķ��󣬸ú���ֱ��return�ȿɣ�
	//! ����GeoLine�ȶ����ֱ����AddHandle�����ɣ�Ч�ʱȽϸ� 
	//! \param pPoints [in] �㴮
	//! \param nPntCount [in] ��ĸ���
	//! \remarks ����ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual void MakeWithPoints(UGPoint2D* pPoints,UGint nPntCount,
		UGEditType::EditToolShape nEditType=UGEditType::ET_Default);

	//! \brief �������м��ζ����ָ�룬��������һ����ά���ζ���
	//! \param pGeometry [in] ���м��ζ���ָ�롣
	//! \return ����ɹ�����true��
	//! \remarks ����geometry���ͣ��ڲ����ø��Ե�make����ȥʵ�֡�
	virtual UGbool MakeWithGeometry(const UGGeometry* pGeometry);	

	//! \brief ������ά�㴮����һ����ά���ζ���
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] ��ĸ�����
	//! \param UGEditType3D::ET3D_NULL [in] �༭������״����ѡ����
	//! \return ����ɹ�����true��
	//! \remarks ����geometry���ͣ��ڲ����ø��Ե�make����ȥʵ�֣������ڱ༭�ж�̬�������
	virtual UGbool MakeWithPoints3D(UGPoint3D* pPoints,UGint nPntCount,
		UGEditType3D::EditToolShape3D nEditType = UGEditType3D::ET3D_NULL);	

	//! \brief ��ȡ������Ҫ��׽�ĵ㴮
	//! \param aryPnts [in] �㴮������ȥ��Ҫ��׽�ĵ㴮
	//! \return �����true��ʾ����Ҫ��׽�ĵ㴮���������false��ʾ�ö���û����Ҫ��׽�ĵ㴮
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGbool GetSnapPoints(UGArray<UGPoint2D>& aryPnts);
	
	//! \brief ��ȡ������Ҫ��׽���߶�����
	//! \param aryLines [in] ��Ҫ��׽�������飨����ж��part����ôaryLines��Ӧ���ж��ٸ�count��
	//! \return �����true��ʾ����Ҫ��׽���ߣ��������false��ʾ�ö���û����Ҫ��׽����
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGbool GetSnapLines(UGLineArray& aryLines);
	
	//! \brief �༭�����죬�༭�ڵ㣩������֪ͨgeometry������ı༭�����ˣ�
	//! ��Ҫ���geomap�����Ķ�����Ϊ��Ҫ�ڽ����༭��ȥˢ�µ�ͼ����
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual void AfterModified();
	
	//! \brief ���ü��ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���,ֻset����ת���ַ�������
	//! \param nCharset [in] �ַ��������͡�
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual void SetTextCharset(UGString::Charset nCharset);	
	
	//! \brief �ı伸�ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���,ת���ַ�������
	//! \param nCharset [in] �ַ��������͡�
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual void ChangeTextCharset(UGString::Charset nCharset);

public:		
	//! \brief �õ�ģ�������
	//! \return �ѿ�������ϵ�µ������
	virtual UGdouble GetVolume();	

	//! \brief �õ��������
	//! \attention DimensionΪ2�Ķ����֧��
	//! \return �������
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGdouble GetArea() const;

	//! \brief �õ���ά����ı����
	//! \attention DimensionΪ2�Ķ����֧��
	//! \return �������
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
	
	//! \brief �õ���ά���󳤶ȡ�
	//! \pjType ��������
	//! \return ���س��ȡ�
	virtual UGdouble GetLength3D(EmPrjCoordSysType pjType);

	//! \brief �õ��Ӷ���ĸ���
	//! \return �����Ӷ���ĸ���
	//! \remarks �ο�2άʵ��
	virtual UGint GetSubCount() const;

public:	
	//! \brief ������ά���ζ���ķ��
	//! \param pStyle3D [in] Ҫ���õķ���ָ�룬�ڲ��´��һ�ݣ��������new�Ļ��ǵ��ͷš�
	virtual void SetStyle3D(const UGStyle3D* pStyle3D);		
	
	//! \brief �õ���ά���ζ���ķ��
	//! \return �õ���ά���ζ���ķ���ָ�롣
	virtual UGStyle3D* GetStyle3D() const;	

	//! \brief ���ö����λ�ã��������ֻ��ģ�ͺ͹��򼸺������壬λ��Ϊģ�͵�����ĵ������ĵ�
	//! x,yΪ��γ�ȣ�z��ָ������ľ�������ǵ����ĵľ���
	//! \param value [in] ָ����λ�õ㣬������ϡ�
	virtual void SetPosition(const UGPoint3D& value);	

	//! \brief ���ö�������Ŵ�С���������ֻ��ģ�ͺ͹��򼸺�������
	//! \param fScaleX [in] X�������ű��ʡ�
	//! \param fScaleY [in] Y�������ű��ʡ�
	//! \param fScaleZ [in] Z�������ű��ʡ�
	virtual void SetScale(UGdouble fScaleX,UGdouble fScaleY,UGdouble fScaleZ);	

	//! \brief ���ö�������Ŵ�С���������ֻ��ģ�ͺ͹��򼸺������� 
	//! \param fScaleXYZ [in] ���������������Ͻ���ͬ����С������ 
	virtual void SetScale(UGdouble fScaleXYZ);

	//! \brief ���ö������ת�����������ֻ��ģ�ͺ͹��򼸺������� 
	//! \param fRotateX [in] X�������ת�Ƕȡ�
	//! \param fRotateY [in] Y�������ת�Ƕȡ�
	//! \param fRotateZ [in] Z�������ת�Ƕȡ�
	virtual void SetRotation(UGdouble fRotateX,UGdouble fRotateY,UGdouble fRotateZ);	

	//! \brief �õ������λ�ã��������ֻ��ģ�ͺ͹��򼸺������壬λ��Ϊģ�͵�����ĵ������ĵ�
	//! \return �����λ�á�
	virtual UGPoint3D GetPosition() const;

	//! \brief �õ��������������ű��ʣ��������ֻ��ģ�ͺ͹��򼸺���������
	//! \return �������������ű��ʡ�
	UGPoint3D GetScale() const;	
	

	//! \brief �õ�������������ת�Ƕȣ��������ֻ��ģ�ͺ͹��򼸺���������
	//! \return ������������ת�Ƕȡ�
	UGPoint3D GetRotation() const;

	//! \brief ����Geometry�����еĳ�Ա����, ����ID, Style, Bounds,�Լ�Geometry3D�еĳ�Ա����,����Style3D, BoundingBox, Point3D�����
	//! \param geo3d [in] �ṩ��Ϣ��Gemetry3D
	//! \return ����ж�����Ŀ�����������ָ��Ϊ�գ��򷵻�false
	UGbool CopyAllBaseData(const UGGeometry3D& geo3d);

	//! \brief ������ά�����Ƿ�ı䣬��ת��ƽ�ơ����ŵ�ʱ������������ΪTrue
	//! \param bModified [in] ���õ�״̬��
	void SetModified(UGbool bModified);	
	
	//! \brief �õ���ά�����Ƿ�ı�
	//! \return �õ�״̬
	UGbool IsModified();

protected:

	//! \brief ��������Bounds
	//! \return ���صõ���Bounds
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGRect2D ComputeBounds() const;	

	//! \brief ��������BoundingBox
	//! \return ���صõ���BoundingBox
	virtual UGBoundingBox ComputeBoundingBox() const;

public:
	//! \brief ת��Ϊ�߶���
	//! \param geoLine [out] �õ����߶���
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
	
	//! \brief ת�������Ӧ��2άGeometry����
	//! \param geometry [out] ���2άGeometry����	
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToGeometry2D( UGGeometry& geometry ) const;

public:
	//Projection..
	
	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator [in] ͶӰת����
	//! \param bForward [in] ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);

	//! \brief ������άͶӰ����ϵͳת��
	//! \attention ��δʵ�֡�
	virtual void PJConvert3D( UGRefTranslator *pPJTranslator, UGbool bForward = true);	
	
	//! \brief �Ӿ�γ����ϵͳת��ΪͶӰ����ϵͳ
	//! \param pCoordSys [in] ͶӰ����ϵͳ
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual void PJForward( UGPrjCoordSys *pCoordSys );

	//! \brief �Ӿ�γ����ϵͳת��Ϊ��άͶӰ����ϵͳ
	//! \attention ��δʵ�֡�
	virtual void PJForward3D( UGPrjCoordSys *pCoordSys );
	
	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����
	//! \param pCoordSys ͶӰ����ϵͳ
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );	

	//! \brief ��ͶӰ����ϵͳת��Ϊ��ά����ϵͳ
	//! \attention ��δʵ�֡�
	virtual void PJInverse3D( UGPrjCoordSys *pCoordSys );	

	//! \brief ������ά���ζ���İ�Χ�С�
	//! \param box [in] �°�Χ�е�ֵ��
	virtual void SetBoundingBox(const UGBoundingBox& box)	{m_BoundingBox = box;};

	//! \brief �õ���ά���ζ���İ�Χ�С�
	//! \return ���ذ�Χ�е�ֵ��
	// virtual const UGBoundingBox& GetBoundingBox()	const;
	const UGBoundingBox& GetBoundingBox()	const;

public:
	//! \brief �洢����ĸ�������,����Geometry�洢��һ�������
	//! \brief ģ����ߴ洢�����ģ�ͷֿ�
	//! \return �ɹ�����TRUE,ʧ�ܷ���FLASE
	virtual UGbool SaveExtData(UGArray<UGTextureInfo>& arryTextureInfo);

	//! \brief ͨ�����ζ����б��������·����ʼ��������Ϣ
	//! \return �ɹ�����TRUE,ʧ�ܷ���FLASE
	virtual UGbool InitialTextureInfo(UGArray<UGTextureInfo>& arrayTextureInfos);

	//! \brief ���ض����������ݵ�ȫ�ֵĹ������� �� UGGeoModel
	//! \return �ɹ�����TRUE,ʧ�ܷ���FLASE
	virtual UGbool LoadExtData(const UGArray<UGTextureInfo>& arrayTextureInfos);

protected:
	UGbool IsInLatLong() const; 
protected:

	//! \brief ��ά���ζ���İ�Χ��
	UGBoundingBox m_BoundingBox;

	//! \brief ��ά�����λ�ã��Թ��򼸺��壬ģ�ͣ�������Ч
	UGPoint3D m_pntPos;

	//! \brief ��ά���������ϵ�����Թ��򼸺��壬ģ�ͣ�������Ч
	UGPoint3D m_pntScale;

	//! \brief ��ά�������ת�����Թ��򼸺��壬ģ�ͣ�������Ч
	UGPoint3D m_pntRotate;
		 
};

}

#endif // !defined(AFX_UGGEOMETRY3D_H__0D8126C6_CAE8_4AD5_91D7_47DF8BD75819__INCLUDED_)


