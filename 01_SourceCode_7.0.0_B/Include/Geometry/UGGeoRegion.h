/*! \file	 UGGeoRegion.h
 *  \brief	 �漸�ζ���
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
 *  All Rights Reserved
 *  \version $Id: UGGeoRegion.h,v 1.16 2009/10/28 02:40:05 machx Exp $
 *  \version $Id: UGGeoRegion.h,v 1.16 2009/10/28 02:40:05 machx Exp $
*/


#ifndef UGGEOREGION_H
#define UGGEOREGION_H

#include "Geometry/UGGeometry.h"

namespace UGC {

//! \brief �漸�ζ���
#ifdef SYMBIAN60
class GEOMETRY_APIC UGGeoRegion  : public UGGeometry
#else
class GEOMETRY_API UGGeoRegion  : public UGGeometry
#endif
{
public:
	//! \brief ���캯��
	GEOMETRY_APIF UGGeoRegion();


	GEOMETRY_APIF UGGeoRegion(const UGGeoRegion& geoRegion);
	GEOMETRY_APIF UGGeoRegion& operator=(const UGGeoRegion& goeRegion);

	
	//! \brief ��������
	virtual GEOMETRY_APIF ~UGGeoRegion();
	
public: //pure virtual GEOMETRY_APIF 
	
	//! \brief ��ռ�������
	virtual GEOMETRY_APIF void Clear();
	
	//! \brief �õ�ά��, Region�̶�Ϊ2ά
	//! \return ����ά��,�̶�Ϊ2
	virtual GEOMETRY_APIF UGint GetDimension() const;
	
	//! \brief �õ�����, �̶�ΪGeoRegion
	//! \return ��������, �̶�ΪGeoRegion
	virtual GEOMETRY_APIF Type GetType() const;
	
	//! \brief �õ��ڵ�
	//! \remarks �ڲ�����UGOpRegions::InnerPointʵ��
	//! \return �����ڵ�
	virtual GEOMETRY_APIF UGPoint2D GetInnerPoint() const;
	
	//! \brief �õ����󳤶�
	//! \attention DimensionΪ1or2�Ķ����֧��
	//! \return ���س���
	virtual GEOMETRY_APIF UGdouble GetLength() const;
	
	//! \brief ����õ����
	//! \return �������
	virtual GEOMETRY_APIF UGdouble GetArea() const;

	//! \brief ����õ���ĳ��ͶӰϵͳ�µĵ������(�Ǽ������)
	//! \param pPJCoordSys ͶӰ����ϵ
	//! \return ������ͶӰ����ϵ�µĵ�������������λΪ��ƽ���ס�
	UGdouble GetArea(UGPrjCoordSys* pPJCoordSys);

	//! \brief ��ȷ����ͶӰ�ο�ϵ�¶���ε�����������λΪ��ƽ���ס�
	//! \param ͶӰ����ϵ
	//! \remark �÷�����SFC60����������ֲ������
	UGdouble GetPreciseArea(UGPrjCoordSys* pPJCoordSys);

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
	virtual GEOMETRY_APIF UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
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
	virtual GEOMETRY_APIF void Rotate(const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, double dAngle = 0);
	
	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool Resize(const UGRect2D& rcNewBounds); 
	
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
	//! \brief �����������
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�ĵ���Ŀ��
	//! \remarks �γ�һ���Ӷ��󣬴���ĵ�ĸ�������Ҫ3��; ���û�бպϣ������ڲ����Զ��պ�
	//! \return ����С��3��,����false��
	GEOMETRY_APIF UGbool Make(const UGPoint2D* pPoints, UGint nPntCount);

	//! \brief �������������
	//! \param pPoints [in] �㴮ָ�롣
	//! \param pPolyCount [in] �Ӷ����е��������顣
	//! \param nSubCount [in] �Ӷ�����Ŀ��
	//! \return �����Ӷ���ĵ�����С��3��,����false��
	virtual GEOMETRY_APIF	UGbool Make(const UGPoint2D* pPoints, const UGint* pPolyCount, UGint nSubCount);
	
	//! \brief ��������GeoRegion
	//! \param geoRegion [in] ���������
	//! \return ���������Ƿ�, ����false��
	GEOMETRY_APIF UGbool Make(const UGGeoRegion& geoRegion);
	
	//! \brief ͨ�����ι��������
	//! \param rect [in] ���Ρ�
	//! \param 0 [in] ���εı߲����ĸ���,һ����Ĭ��ֵ0���ɡ�
	//! \return ����Ϊ��,����false��
	GEOMETRY_APIF UGbool Make(const UGRect2D& rect, UGint nSegmentCount = 0);	
	
	//! \brief �����Ӷ���
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮������
	//! \return ��ĸ�������3��,����false��
	GEOMETRY_APIF UGbool AddSub(const UGPoint2D* pPoints, UGint nPntCount);	
	
	//! \brief �����Ӷ��� added by chenp 2010.1125
	//! \param geoRegion [in]  ������Ӷ���
	//! \return ��ĸ�������3��,����false��
	GEOMETRY_APIF UGbool AddSub(UGGeoRegion *geoRegion);
	//! \brief �����Ӷ���
	//! \param nIndex [in] Ҫ�����λ��������
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�е�ĸ�����
	//! \return �����С��3��������λ�÷Ƿ�,����false��
	GEOMETRY_APIF UGbool InsertSub(UGint nIndex, const UGPoint2D* pPoints, UGint nPntCount);	
	
	//! \brief ɾ���Ӷ���
	//! \param nIndex [in] Ҫɾ�����Ӷ����λ��������
	//! \return �����Ƿ�, ����false��
	GEOMETRY_APIF UGbool DelSub(UGint nIndex);
	
	//! \brief �õ�ĳ���Ӷ���, ������õ�GeoRegion��
	//! \param nSubIndex [in] �Ӷ���������
	//! \param pGeoRegion [out] ͨ�����Ӷ�����õ���GeoRegion; ���pGeoRegionΪNULL,�����ڲ���new������
	//! \return �����Ƿ�, ����false��
	GEOMETRY_APIF UGbool GetSub(UGint nSubIndex, UGGeoRegion *&pGeoRegion);
	
	//! \brief �õ��Ӷ�����Ŀ������ָ�롣
	//! \return �����Ӷ�����Ŀ������ָ�롣
	const GEOMETRY_APIF UGint* GetPolyCounts() const;
	
	//! \brief �õ�ĳ���Ӷ���ĵ�ĸ�����
	//! \param nSubIndex [in] �Ӷ���������
	//! \return ����ĳ���Ӷ���ĵ�ĸ�����
	GEOMETRY_APIF UGint GetSubPntCount(UGint nSubIndex) const;
	
	//! \brief �õ������Ӷ���ĵ�ĸ����ܺ͡�
	//! \return ���������Ӷ���ĵ�ĸ����ܺ͡�
	GEOMETRY_APIF UGint GetPointCount() const;
	
	//! \brief �õ�ָ���Ӷ���ĵ㴮��ָ�롣
	//! \param nSubIndex [in] �Ӷ���������
	//! \return �����Ӷ���ĵ㴮��ָ�롣
	const GEOMETRY_APIF UGPoint2D* GetPoints(UGint nSubIndex=0) const;
	
	//! \brief ɾ���ٽ��㷽��
	//! \param dInterval�����ٽ�������
	//! \return �ɹ�����true��ʧ��Ϊfalse�����������������ٽ�����Ϊfalse��
	GEOMETRY_APIF UGbool DelClosedNode(UGdouble dInterval = EP);


public:
	//! \brief �жϵ��Ƿ�������
	//! \param &point [in] Ҫ�жϵĵ㡣
	//! \param bBorder [in] �ж�ʱ�Ƿ�����߽硣
	//! \return ��������(bBorderΪtrueʱ,�ڱ߽�Ҳ��)ʱ,����true;���򷵻�false��
	//modified by shuxl	��������ж�!!
	GEOMETRY_APIF UGbool PtInRegion(const UGPoint2D &point, UGbool bBorder = true, UGdouble dInterval = EP);	

	//! \brief �洢��Stream��
	//! \remarks �ο�UGGeometry��˵��
	virtual GEOMETRY_APIF UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE)  const;

	//! \brief ��Stream������Geometry
	//! \remarks �ο�UGGeometry��˵��
	virtual GEOMETRY_APIF UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );

	void SaveIndexData(UGStream& stream);
	void LoadIndexData(UGStream& stream);

	void GetIndexData(UGArray<UGuint>& arrSubCounts, UGArray<UGArray<UGushort> >& arrIndexes);
	void SetIndexData(UGArray<UGuint>& arrSubCounts, UGArray<UGArray<UGushort> >& arrIndexes);

	void GetIndexData(UGArray<UGuint>& arrSubCounts, UGArray<UGArray<UGuint> >& arrIndexes);
	void SetIndexData(UGArray<UGuint>& arrSubCounts, UGArray<UGArray<UGuint> >& arrIndexes);
	
	//! \brief ת��Ϊ�߶���
	//! \param geoLine[out] �õ����߶���
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��; �������в�������
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;
	
	//! \brief ת��Ϊ�����
	//! \param geoRegion[out] �õ��������
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��; �������в�������
	//! \return �ɹ�����true,ʧ�ܷ���false
	//! \remarks ���ر���
	virtual GEOMETRY_APIF UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;
	
	//! \brief �ж���֮�䵺����ϵ�ĺ���
	//! \attention ������Ǻ�GeoRegion���ܰ�, ����ŵ� UGOpRegions������, GeoRegion��ʹ�þͿ�����.
	GEOMETRY_APIF void CheckPolygon(const UGPoint2D *pPoints, const UGint *plPolyCounts, UGint nSubCount, UGint *plPolyArea) const;

	//! \brief �ж϶����ָ���Ӷ����ǵ����Ƕ���Ӧ�������������	 add by shuxl 09.1.7
	//! \param nSubID �Ӷ���ID
	//! \return ������true,������false
	GEOMETRY_APIF UGbool CheckSubPolygon(UGint nSubID) const;

	//! \brief �滻�Ӷ���	 add by shuxl 09.3.5
	//! \param lSubObjID �Ӷ���ID
	//! \param	pPoint �滻�����ʼ��ַ
	//! \param	lPointCount �滻��ĸ���
	//! \return 
	GEOMETRY_APIF UGbool SetSub( UGint lSubObjID, UGPoint2D * pPoint ,UGint lPointCount);
	
	//! \brief �ж��Ӷ���ε�����
	//! \param nIndex �Ӷ�������
	//! \remarks ����-1��������쳣������0 ˳ʱ�룻����1 ��ʱ�룻
	GEOMETRY_APIF UGint IsCounterClockwise(UGint nIndex);

	//! \brief �ж��Ƿ��ж�
	//! \return ������Ч����ֻ��һ���Ӷ���ʱ����-1,���ж���Ӷ��󵫲���������0�����ж���Ӷ��󵫺��ж�����1
	GEOMETRY_APIF UGint HasHollow();

	//! \brief ����ĳ���Ӷ����е��˳��
	//! \param nSubIndex [in] Ҫ������Ӷ���������
	//! \return �����Ƿ�,����false��
	GEOMETRY_APIF UGbool Reverse(UGint nSubIndex);	

	virtual GEOMETRY_APIF UGint GetDataSize() const;

#if PACKAGE_TYPE==PACKAGE_UGC
public:		
			
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
		
	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
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

	//! \brief ���ݴ���ĵ㴮���ɶ�����Ҫ���ڱ༭�еĲ�������û���ڲ����鱣��㴮�Ķ���
	//Ҳ�����Զ������,�������ڲ����鱣��㴮�Ķ��󣬸ú���ֱ��return�ȿɣ�����GeoLine
	//GeoLine�ȶ����ֱ����AddHandle�����ɣ�Ч�ʱȽϸ� 
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
	
	//! \brief �ϲ�����
	//! \param 
	//! \return 
	GEOMETRY_APIF UGbool Combination(UGGeoRegion *pGeoRegion);

	//! \brief ���󱣻��Էֽ�
	//! \param arrOutRegion	���صı��ֽ�Ķ���
	//! \return 
	GEOMETRY_APIF UGbool ProtectedDecomposeEx(UGArray<UGGeoRegion*> &arrOutRegion);

	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ end
protected:
	
	//! \brief ��Χ�͵����
	struct BoundsNode 
	{
		UGint  lNumber;
		UGRect2D  rcBounds;
		UGdouble GetArea() { return rcBounds.Width() * rcBounds.Height(); }
		void operator =(BoundsNode node) { lNumber = node.lNumber; rcBounds = node.rcBounds; };
	};
	
	typedef UGArray<BoundsNode*> BoundsNodes;
	
	//! \brief �ж���֮�䵺����ϵ�ĺ���
	//! \attention ������Ǻ�GeoRegion���ܰ�, ����ŵ� UGOpRegions������, GeoRegion��ʹ�þͿ�����.
	GEOMETRY_APIF void CheckPolyCounts( const UGPoint2D *pPoints, const UGint *plPolyCounts, UGint nSubCount,UGint* plPolyArea ) const; 
	
	//! \brief �ж���֮�䵺����ϵ�ĺ���
	//! \attention ������Ǻ�GeoRegion���ܰ�, ����ŵ� UGOpRegions������, GeoRegion��ʹ�þͿ�����.
	GEOMETRY_APIF void CheckPolygon( const UGPoint2D *pPoints, const UGint *pPolyCounts1, const UGint *pPolyCounts2, BoundsNodes &Polygons, UGint *pPolyCountsAll, UGint nSubCount ) const;

	//���ù���������׼�����������϶�������
	//! \brief �������һЩ���������������� û����ȫ�չ��������ı�׼
	//! \param ͶӰ����ϵ
	//! \remark �÷�����SFC60����������ֲ������
	double GetPreciseArea2(UGPrjCoordSys* pPJCoordSys);

protected: //! �ڲ���������
	//! \brief �����㴮
	UGArray<UGPoint2D> m_Points;

	//! \brief ������� �����Ӷ���ĵ�ĸ��� ��Ϣ����������
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
	
protected: //! ������Ҫʵ�ֵ�һЩ����������
	//! \brief ʵ�ʼ���Bounds
	virtual GEOMETRY_APIF UGRect2D ComputeBounds() const;
	/*virtual GEOMETRY_APIF UGRect2D GetBoundsInside() const;
	virtual GEOMETRY_APIF void SetBoundsInside(const UGRect2D & rcBounds);*/
};

}

#endif

