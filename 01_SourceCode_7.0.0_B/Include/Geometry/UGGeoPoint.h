/*! \file	 UGGeoPoint.h
 *  \brief	 �㼸�ζ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
 *  All Rights Reserved
 *  \version $Id: UGGeoPoint.h,v 1.8 2009/09/07 10:33:28 duxm Exp $
 */


#ifndef UGGEOPOINT_H
#define UGGEOPOINT_H

#include "Geometry/UGGeometry.h"

namespace UGC {

//! \brief �㼸�ζ�����
//! \sa UGGeoMultiPoint
#ifdef SYMBIAN60
class GEOMETRY_APIC UGGeoPoint : public UGGeometry
#else
class GEOMETRY_API UGGeoPoint : public UGGeometry
#endif
{
public:
	//! \brief ���캯��
	GEOMETRY_APIF UGGeoPoint();
	
	//! \brief ��������
	virtual GEOMETRY_APIF ~UGGeoPoint();
	
public: //pure virtual GEOMETRY_APIF 

	//! \brief ���Geometry�ڲ�����
	virtual GEOMETRY_APIF void Clear();
	
	//! \brief �õ�ά��, �̶�Ϊ0
	virtual GEOMETRY_APIF UGint GetDimension() const;
	
	//! \brief �õ�����, �̶�Ϊ GeoPoint
	virtual GEOMETRY_APIF Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩, ��Ϊ����ĵ�
	//! \return �����ڵ�
	virtual GEOMETRY_APIF UGPoint2D GetInnerPoint() const;

	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual GEOMETRY_APIF UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;

	//! \brief �������, ���ڶ����ѡ(���ȱȽϸ�,���ڵ�ͼ�����߱Ƚϴ�,���������ǳ��������)
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	// �޸�ȱ��UGOVI-1047(added by hp 2011-5-31)
	virtual GEOMETRY_APIF UGbool HitTestH( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
	//! \brief �õ��ռ�����, ��Ҫ������Ҫ����ά����ͬʱ
	//! ����ͳһ�����ʱ��, ����һЩ�ռ��жϺͲ������㷨
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual GEOMETRY_APIF UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief ���ζ����Ƿ���Ч
	//! \return ����true; ��Ϊ�޷��ж��Ƿ���Ч
	virtual GEOMETRY_APIF UGbool IsValid()const;
	
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	virtual GEOMETRY_APIF void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief ����
	//! \param dRatio ���ű���(X,Y������ͬ)
	virtual GEOMETRY_APIF void Inflate( UGdouble dRatio);
	
	//! \brief ƽ��
	//! \param dX ƽ�Ƶ�Xƫ����
	//! \param dY ƽ�Ƶ�Yƫ����
	virtual GEOMETRY_APIF void Offset( UGdouble dX, UGdouble dY);
	
	//! \brief ƽ��
	//! \param ƫ����(X,Y������ͬ)
	virtual GEOMETRY_APIF void Offset( UGdouble dOffset);
	
	//! \brief ƽ��
	//! \param ƽ�Ƶ�ƫ����(�ֱ���UGSize2D�е�x,y����X,Y�����ƫ����)
	virtual GEOMETRY_APIF void Offset( const UGSize2D &szOffset);
	
	//! \brief ��ת
	//! \param pntOrigin ��ת�����ĵ�(ê��,������)
	//! \param dAngle ��ת�Ƕ�
	virtual GEOMETRY_APIF void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief ��ת,����һЩ����,�Ա��ڲ����Բ��ý���cos,sin, �����������ʱ�����������Ч��
	//! \remarks dAngle���ƶ���,��GeoText��Ҫ,����Ҫ����
	//! \param pntOrigin ��ת�����ĵ�(ê��,������)
	//! \param dCosAngle ��ת��cosֵ
	//! \param dSinAngle ��ת��sinֵ
	//! \param dAngle ��ת�Ƕ�
	virtual GEOMETRY_APIF void Rotate(const UGPoint2D& pntOrigin, UGdouble dCosAngle,
						UGdouble dSinAngle, double dAngle = 0);
	
	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \remarks ������ΪBounds�����ĵ�
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool Resize(const UGRect2D& rcNewBounds); 
	
	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
public: // �õ���������Ϣ

	//! \brief ��������
	//! \param pnt [in] �����ꡣ
	//! \return ����true��
	GEOMETRY_APIF UGbool Make(const UGPoint2D& pnt);	

	//! \brief ��������
	//! \param dx [in] Xֵ��
	//! \param dy [in] Yֵ��
	//! \return ����true��
	GEOMETRY_APIF UGbool Make(UGdouble dx, UGdouble dy);	
	
	//! \brief ������������
	//! \param geoPoint [in] ���е����
	//! \return ����true��
	GEOMETRY_APIF UGbool Make(const UGGeoPoint& geoPoint);	

	//! \brief �������Ӷ���ĸ���Geometry.
	//! \param pPoints [in] �㴮ָ�롣
	//! \param pPolyCount [in] �Ӷ����е��������顣
	//! \param nSubCount [in] �Ӷ�����Ŀ��
	//! \return �����Ӷ���ĵ�����С��2��,����false��
	virtual GEOMETRY_APIF UGbool Make( const UGPoint2D* pPoints, const UGint* pPolyCount, UGint nSubCount );

	//! \brief �õ��Ӷ������
	//! \return �����Ӷ������
	//! \remarks �̶�Ϊ1��
	virtual GEOMETRY_APIF UGint GetSubCount() const;	
	
	virtual GEOMETRY_APIF UGint GetDataSize() const;
public:
	//! \brief ���õ�����
	//! \param pnt ������
	GEOMETRY_APIF void SetPoint(const UGPoint2D& pnt);

	//! \brief �õ�������
	//! \return ���ص�����
	const GEOMETRY_APIF UGPoint2D& GetPoint() const;

	//! \brief �õ������ꡣ
	//! \return ���ص����ꡣ
	GEOMETRY_APIF UGPoint2D& GetPoint();	
	
	//! \brief ����Xֵ
	//! \param dX �������Xֵ
	GEOMETRY_APIF void SetX(UGdouble dX);
	
	//! \brief �õ�Xֵ
	//! \return ����Xֵ
	GEOMETRY_APIF UGdouble GetX() const;
	
	//! \brief ����Yֵ
	//! \param dY �������Yֵ
	GEOMETRY_APIF void SetY(UGdouble dY);
	
	//! \brief �õ�Yֵ
	//! \return ����Yֵ
	GEOMETRY_APIF UGdouble GetY() const;
	GEOMETRY_APIF UGPoint2D* GetPoint2D();

public:
	
	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator ͶӰת����
	//! \param bForward ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	virtual GEOMETRY_APIF void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);

	//! \brief �Ӿ�γ����ϵͳת��ΪͶӰ����ϵͳ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual GEOMETRY_APIF void PJForward( UGPrjCoordSys *pCoordSys );

	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual GEOMETRY_APIF void PJInverse( UGPrjCoordSys *pCoordSys );

#if PACKAGE_TYPE==PACKAGE_UGC

	//! \brief ����XML��ʽ����Ϣ
	//! \param versionType GML�İ汾
	//! \param nPace �����Ŀո���Ŀ,ʹ��xml�ַ������������˹��Ķ�; 
	//! ��Ҫ����������ص�xml�ַ�����һ�����ǩ�е�һ����, ͨ��ָ���ո���Ŀ,����ʹ�������
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual GEOMETRY_APIF UGString ToXML(GMLVersionType versionType, UGint nPace = 0) const;

	//! \brief ��XML�ַ���������Geometry
	//! \param strXML xml��ʽ�ַ���
	//! \param versionType xml�ַ�����GML�汾
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual GEOMETRY_APIF UGbool FromXML(const UGString& strXML, GMLVersionType versionType = SML);
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//! \brief Geometry��Element��ת��
	//! \param pElement,���ص�pElementָ���ں����ڷ����ڴ�,���渺��ɾ������������ڴ�й©
	virtual GEOMETRY_APIF UGbool ToElement(OgdcElement*& pElement)  const;

	//! \brief Geometry��Element��ת��
	//! \param pElement,�����Element������޷�ת���򷵻�False�����򷵻�True
	virtual GEOMETRY_APIF UGbool FromElement(const OgdcElement* pElement);
#endif

#endif // end declare ugc sdk

public:
	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ
	
	//! \brief ��ñ༭����ľ������Ŀ
	//! \remarks ���ڹ̶��������Ϊ9�����˸ı��С��8�����Ƶ��һ����ת���Ƶ�
     virtual GEOMETRY_APIF UGint  GetHandleCount();

	
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
	 virtual GEOMETRY_APIF UGint GetHandle( UGint nHandle, UGPoint2D& point);


	//! \brief �ƶ����Ƶ㵽ָ������,��Ҫ���ڻ��ƶ����޸Ķ���ڵ�Ȳ���
	//! \param nHandle ���Ƶ���
	//! \param point ���Ƶ�����
	virtual GEOMETRY_APIF void MoveHandle( UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_Default);

	//! \brief �ڵ�༭ʱ����������һ�����Ƶ�,Ҳ�������ڻ��ƶ���ʱ����ڵ�
	//! \param nHandle ����λ��
	//! \param pnt2D �����ĵ�������
	virtual GEOMETRY_APIF void AddHandle( UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_Default);
	
	//! \brief ɾ���༭�����ָ���ڵ�
	//! \param nHandle �ڵ���
     virtual GEOMETRY_APIF UGuint DelNode( UGint nHandle );

	//! \brief ����������ʱ�ĸ����ߣ����ص���һ�����϶���
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	//! \param pStyle	 �����ߵķ���������ΪNULL����Ĭ�ϵķ��
     virtual GEOMETRY_APIF UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);

	 
	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ end
private:
	//! \brief �ڲ���������
	UGPoint2D m_pnt;
	
protected: //! ������Ҫʵ�ֵ�һЩ����������
	//! \brief 
	virtual GEOMETRY_APIF UGRect2D ComputeBounds() const;
	/*virtual GEOMETRY_APIF UGRect2D GetBoundsInside() const;
	virtual GEOMETRY_APIF void SetBoundsInside(const UGRect2D & rcBounds);*/
	
	//! \brief �洢��Stream��
	virtual GEOMETRY_APIF UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE)  const;
	//! \brief ��Stream������Geometry
	virtual GEOMETRY_APIF UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );
};

}

#endif

