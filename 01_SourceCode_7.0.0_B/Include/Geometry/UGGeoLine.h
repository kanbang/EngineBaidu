/*! \file	 UGGeoLine.h
 *  \brief	 �߼��ζ���
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
 *  All Rights Reserved
 *  \version $Id: UGGeoLine.h,v 1.12 2009/11/06 05:45:17 shuxl Exp $
 */


#ifndef UGGEOLINE_H
#define UGGEOLINE_H

#include "Geometry/UGGeometry.h"

namespace UGC {

//! \brief �߼��ζ���
#ifdef SYMBIAN60
class GEOMETRY_APIC UGGeoLine : public UGGeometry
#else
class GEOMETRY_API UGGeoLine : public UGGeometry
#endif
{
public:
	//! \brief ���캯��
	GEOMETRY_APIF UGGeoLine();

	//! \brief ��������
	virtual GEOMETRY_APIF ~UGGeoLine();

public: //pure virtual GEOMETRY_APIF 

	//! \brief ��յ�������
	virtual GEOMETRY_APIF void Clear();

	//! \brief �õ�ά��, �̶�Ϊ1
	//! \return �õ�ά��,�̶�Ϊ1
	virtual GEOMETRY_APIF UGint GetDimension() const;

	//! \brief �õ�����, �̶�Ϊ GeoLine
	virtual GEOMETRY_APIF Type GetType() const;

	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \remarks Ϊ���������Ӷ��� ���м��(�м�����ĵ�, �������м����ĵ�)
	virtual GEOMETRY_APIF UGPoint2D GetInnerPoint() const;
	
	//! \brief �õ����󳤶�
	//! \return ���س���
	virtual GEOMETRY_APIF UGdouble GetLength() const;
	
	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual GEOMETRY_APIF UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;	

	//! \brief �õ��ռ�����, ��Ҫ������Ҫ����ά����ͬʱ
	//! ����ͳһ�����ʱ��, ����һЩ�ռ��жϺͲ������㷨
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual GEOMETRY_APIF UGbool GetSpatialData( UGAutoPtr<UGPoint2D>& pPoints, 
				UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	//! \brief �õ��Ӷ���ĸ���
	//! \return �����Ӷ���ĸ���
	virtual GEOMETRY_APIF UGint GetSubCount() const;
	
	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
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
	virtual GEOMETRY_APIF void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, double dAngle = 0);
	
	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool Resize(const UGRect2D& rcNewBounds); 

	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);

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

public:
	//added by zengzm 2001.11.27
	//����� ��lSubIndex���Ӷ���lSubIndex��0��nSubCount-1��pGeoLine����ʱӦΪnull���û��������ⲿ���������ɾ����
    GEOMETRY_APIF UGbool GetSubLine(UGlong lSubIndex, UGGeoLine *&pGeoLine);
	//! \brief ����ֻ��һ���Ӷ���(������)��GeoLine
	//! \param pnt1 ��һ����
	//! \param pnt2 �ڶ�����
	//! \return ����true
	GEOMETRY_APIF UGbool Make(const UGPoint2D& pnt1, const UGPoint2D& pnt2);
	
	//! \brief ����һ���Ӷ����GeoLine
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�ĵ���Ŀ��
	//! \return ����С��2��,����false��
	GEOMETRY_APIF UGbool Make( const UGPoint2D* pPoints, UGint nPntCount );	

	//! \brief �������Ӷ���ĸ���GeoLine
	//! \param pPoints [in] �㴮ָ�롣
	//! \param pPolyCount [in] �Ӷ����е��������顣
	//! \param nSubCount [in] �Ӷ�����Ŀ��
	//! \return �����Ӷ���ĵ�����С��2��,����false��
	virtual GEOMETRY_APIF	UGbool Make( const UGPoint2D* pPoints, const UGint* pPolyCount, UGint nSubCount );	
	
	//! \brief ��������GeoLine
	//! \param geoline [in] �����߶���
	//! \return �����߶���Ƿ�, ����false��
	GEOMETRY_APIF UGbool Make( const UGGeoLine& geoline);	

	//! \brief ���������һ���Ӷ���
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�ĵ���Ŀ��
	//! \return �㴮����С��2��, ����false��
	GEOMETRY_APIF UGbool AddSub( const UGPoint2D* pPoints, UGint nPntCount );	
	
	//! \brief �����Ӷ���
	//! \param nIndex [in] Ҫ�����λ��������
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�е�ĸ�����
	//! \return �����С��2��������λ�÷Ƿ�,����false��
	GEOMETRY_APIF UGbool InsertSub(UGint nIndex, const UGPoint2D* pPoints, UGint nPntCount);	

	//! \brief ɾ���Ӷ���
	//! \param nIndex [in] Ҫɾ�����Ӷ����λ��������
	//! \return �����Ƿ�, ����false��
	GEOMETRY_APIF UGbool DelSub( UGint nIndex );	

	//��SFC53������		add by shuxl	2009.11.5
	//! \brief	��ָ�����Ӷ����ָ��λ�ÿ�ʼȥ�� lPointCount ���ڵ�
	//! \param ������lSubObjID	Ŀ���Ӷ���
	//! \param 	lPointID	ɾ������ʼλ��
	//! \param 	lPointCount	ɾ���ĵ���
	//! \return �ɹ�����TRUE, ʧ�ܷ���FALSE
	GEOMETRY_APIF UGbool RemovePoints( UGint lSubObjID, UGint lPointID , UGint lPointCount);


	//! \brief ��ָ����λ�������õ�����ꡣ
	//! \param nIndex [in] λ��������
	//! \param point [in] �����ꡣ
	//! \return �����Ƿ�, ����false��
	//! \remarks �����Ӷ���ĵ���һ�������������, ������û�������Ӷ���, ��ͷ��ʼ����������
	GEOMETRY_APIF UGbool SetPoint( UGint nIndex, const UGPoint2D& point );	

	//! \brief �õ��Ӷ�����Ŀ������ָ�롣
	//! \return �����Ӷ�����Ŀ������ָ�롣
	const GEOMETRY_APIF UGint* GetPolyCounts() const;	

	//! \brief �õ�ĳ���Ӷ���ĵ�ĸ�����
	//! \param nSubIndex [in] �Ӷ���������
	//! \return ����ĳ���Ӷ���ĵ�ĸ�����
	GEOMETRY_APIF UGint GetSubPntCount(UGint nSubIndex) const;	
	
	//! \brief �õ�ĳ���Ӷ���, ������õ�GeoLine��
	//! \param nSubIndex [in] �Ӷ���������
	//! \param pGeoLine [out] ͨ�����Ӷ�����õ���GeoLine; ���pGeoLineΪNULL,�����ڲ���new������
	//! \return �����Ƿ�, ����false��
	GEOMETRY_APIF UGbool GetSub(UGint nSubIndex, UGGeoLine *&pGeoLine) const;	

	//! \brief �滻�Ӷ���	 add by shuxl 09.3.5
	//! \param lSubObjID �Ӷ���ID
	//! \param	pPoint �滻�����ʼ��ַ
	//! \param	lPointCount �滻��ĸ���
	//! \return 
	GEOMETRY_APIF UGbool SetSub( UGint lSubObjID, UGPoint2D * pPoint ,UGint lPointCount);

	
	//! \brief �õ������Ӷ���ĵ�ĸ����ܺ͡�
	//! \return ���������Ӷ���ĵ�ĸ����ܺ͡�
	GEOMETRY_APIF UGint GetPointCount() const;	

	//! \brief ɾ���ٽ��㷽��
	//! \param dInterval�����ٽ�������
	//! \return �ɹ�����true��ʧ��Ϊfalse�����������������ٽ�����Ϊfalse��
	GEOMETRY_APIF UGbool DelClosedNode(UGdouble dInterval = EP);

	//! \brief �õ�ָ���Ӷ���ĵ㴮��ָ�롣
	//! \param nSubIndex [in] �Ӷ���������
	//! \return �����Ӷ���ĵ㴮��ָ�롣
	const GEOMETRY_APIF UGPoint2D* GetPoints(UGint nSubIndex=0) const;	
	
	//! \brief ��ת�����Ĵ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	//! \remarks ֻ��תÿ���Ӷ����еĵ�Ĵ���,������ת�Ӷ����˳��
	GEOMETRY_APIF UGbool Reverse();

	//! \brief ����һ��GeoLine
	//! \param pGeoLine Ҫ�����ӵ�GeoLine
	//! \remarks ����GeoLine������ֻ��һ���Ӷ���; ���Ӻ��γ�һ���������Ӷ���
	//!			����ʱ,�������Ӷ�����ͷ����ȽϽ�����������; 
	//! \return �ɹ�����true,ʧ�ܷ���false
	GEOMETRY_APIF UGbool Joint(UGGeoLine *pGeoLine);

	//! \brief �Ⱦ����ز���
	//! \param geoLineOut ������Ľ��[out] 
	//! \param dResampleDistance  ��������[in]
	//! \remarks ������Ľ��ͨ����������
	GEOMETRY_APIF UGbool ResampleEquidistantly(UGGeoLine& geoLineOut, UGdouble dResampleDistance);

	//! \brief ��GeoLine���ҵ����뿪ʼ��ָ�����ȵĵ㡣
	//! \param dDistance ָ���ľ��볤��[in]��
	//! \return �ҵ��ĵ㡣
	//! \remarks dDistanceС��0ʱ���᷵����ʼ�㣻���dDistance�����ߵĳ��ȣ������ߵ���ֹ�㣻
	//! �����ж���Ӷ�����ߣ���ǰһ���Ӷ�����dDistanceû�����꣬������һ���Ӷ����м����ң�ʹ��ʣ���dDistance��
	//! ֱ��dDistance���꣬�ҵ���Ӧ�ĵ㣬���߷������һ���Ӷ������ֹ��
	//! \attention ���ҵĵ㲻һ�����ߵĽڵ㣨vertex���������������ϣ���������ĵ�
	GEOMETRY_APIF UGPoint2D FindPointOnLineByDistance(UGdouble dDistance);	
    
	//! \brief ת��Ϊ�߶���
	//! \param geoLine[out] �õ����߶���
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��; �������в�������
	//! \return �ɹ�����true,ʧ�ܷ���false
	//! \remarks ���ر���
	virtual GEOMETRY_APIF UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;

	//! \brief ת��Ϊ�����
	//! \param geoRegion[out] �õ��������
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��; �������в�������
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;

	virtual GEOMETRY_APIF UGint GetDataSize() const;

#if PACKAGE_TYPE==PACKAGE_UGC
public:	
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS) 
	//! \brief Geometry��Element��ת��
	//! \param pElement,���ص�pElementָ���ں����ڷ����ڴ�,���渺��ɾ������������ڴ�й©
	virtual GEOMETRY_APIF UGbool ToElement(OgdcElement*& pElement)  const;

	//! \brief Geometry��Element��ת��
	//! \param pElement,�����Element������޷�ת���򷵻�False�����򷵻�True
	virtual GEOMETRY_APIF UGbool FromElement(const OgdcElement* pElement);
#endif	
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
	virtual GEOMETRY_APIF UGbool FromXML(const UGString& strXML, GMLVersionType versionType);
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
     virtual GEOMETRY_APIF void MakeWithPoints(UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType=UGEditType::ET_Default);
	
	 //! \brief ��ȡ������Ҫ��׽�ĵ㴮
	//! \param aryPnts �㴮������ȥ��Ҫ��׽�ĵ㴮
	//! \return �����true��ʾ����Ҫ��׽�ĵ㴮���������false��ʾ�ö���û����Ҫ��׽�ĵ㴮
	virtual GEOMETRY_APIF UGbool GetSnapPoints(UGArray<UGPoint2D>& aryPnts);

	//! \brief ��ȡ������Ҫ��׽���߶�����
	//! \param aryLines ��Ҫ��׽�������飨����ж��part����ôaryLines��Ӧ���ж��ٸ�count��
	//! \return �����true��ʾ����Ҫ��׽���ߣ��������false��ʾ�ö���û����Ҫ��׽����
	virtual GEOMETRY_APIF UGbool GetSnapLines(UGLineArray& aryLines);
	 
	 //added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ end

	//�����������õ���������dPos�ٷֱ�λ�õĵ�pntXY�������ظõ������
    GEOMETRY_APIF UGint GetXYAtPos(UGdouble dPos, UGPoint2D& pntXY);

	//added by wangsh
	//! \brief ��ȡ�����������
	GEOMETRY_APIF UGPoint2D GetStartNode();
	
	//! \brief ��ȡ����β�����
	GEOMETRY_APIF UGPoint2D GetEndNode();

	//! \brief ���߶����ϲ���һ����	
	//! \param nSubIndex �ֶ���������
	//! \param nPointIndex �Ӷ����ϲ�����������
	//! \param nPointIndex ������ĵ�����
	//! \return 
	GEOMETRY_APIF UGbool InsertPoint(UGint nSubIndex, UGint nPointIndex, UGPoint2D &pnt);
	

#endif // end declare ugc sdk



protected: //! ������Ҫʵ�ֵ�һЩ����������
	virtual GEOMETRY_APIF UGRect2D ComputeBounds() const;

	/*virtual GEOMETRY_APIF UGRect2D GetBoundsInside() const;

	virtual GEOMETRY_APIF void SetBoundsInside(const UGRect2D & rcBounds);*/

	//! \brief �洢��Stream��
	virtual GEOMETRY_APIF UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE)  const;



	//! \brief ��Stream������Geometry
	virtual GEOMETRY_APIF UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE ,UGbool bSDBPlus = FALSE);
	
private:
	//! \brief �����㴮
	UGArray<UGPoint2D> m_Points;

	//! \brief ������� �����Ӷ���ĵ�ĸ��� ��Ϣ����������
	UGArray<UGint> m_PolyCounts;
};

}

#endif // !defined(AFX_UGGEOLINE_H__4537A657_5833_4314_BEFA_DBF9F5946A18__INCLUDED_)


