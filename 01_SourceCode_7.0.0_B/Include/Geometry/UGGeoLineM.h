// UGGeoLineM.h: interface for the UGGeoLineM class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOLINEM_H__4D04C30B_CF4B_411E_A107_6ABEE27A07C7__INCLUDED_)
#define AFX_UGGEOLINEM_H__4D04C30B_CF4B_411E_A107_6ABEE27A07C7__INCLUDED_

#include "Geometry/UGGeometry.h"
#include "Geometry/UGGeoPoint.h"

namespace UGC {

#define UG_NO_MEASURE -9999 //��ֵ����
//! \brief���ڶԲ���LineM�ĵ������
	typedef struct tagMeasurePointInfo 
	{
		UGlong nIndex;
		UGlong nIndexOld;
		UGdouble dDistance;
		UGint nError;
		UGbool flag;
	}MeasurePointInfo;

	//!brief ��μ���Mֵ��ö��

//! \brief GeoLineM����(·�ɶ���),��GeoLine����������������ÿ���㶼��һ��Mֵ,�������Measure�ĺ���
//! \remarks GeoLineM�����ڲ��õ���Point3D,����z������M; GeoLineM��Ҫ���ڶ�̬�ֶκ������������ı��
class GEOMETRY_API UGGeoLineM : public UGGeometry  
{
public:
	//! \brief ���캯��
	UGGeoLineM();
	//! \brief ��������
	virtual ~UGGeoLineM();

	//add by shuxl	09.6.16
	UGGeoLineM( const UGGeoLineM &otherLineM);
	
public:
	//! \brief ��յ�������
	virtual void Clear();
	
	//! \brief �õ�ά��, �̶�Ϊ1
	//! \return �õ�ά��,�̶�Ϊ1g
	virtual UGint GetDimension() const;

	//! \brief �õ�����, �̶�Ϊ GeoLineM
	virtual Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \remarks Ϊ���������Ӷ��� ���м��(�м�����ĵ�, �������м����ĵ�)
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief �õ����󳤶�,���������
	//! \return ���س���	
	virtual UGdouble GetLength() const;
	
	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
	//! \brief �õ��ռ�����, ��Ҫ������Ҫ����ά����ͬʱ
	//! ����ͳһ�����ʱ��, ����һЩ�ռ��жϺͲ������㷨
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual UGbool GetSpatialData( UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief �õ��Ӷ���ĸ���
	//! \return �����Ӷ���ĸ���
	virtual UGint GetSubCount() const;
	
	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid()const;
	
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	//! \param dRatioM Mֵ�����ű���
	void Inflate(UGdouble dRatioX, UGdouble dRatioY, UGdouble dRatioM);
	
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	//! \remarks M������
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief ����
	//! \param dRatio ���ű���(X,Y,M��ͬ)
	virtual void Inflate( UGdouble dRatio);
	
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
	
	//! \brief ��ת
	//! \param pntOrigin ��ת�����ĵ�(ê��,������)
	//! \param dAngle ��ת�Ƕ�
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief ��ת,����һЩ����,�Ա��ڲ����Բ��ý���cos,sin, �����������ʱ�����������Ч��
	//! \remarks dAngle���ƶ���,��GeoText��Ҫ,����Ҫ����
	//! \param pntOrigin ��ת�����ĵ�(ê��,������)
	//! \param dCosAngle ��ת��cosֵ
	//! \param dSinAngle ��ת��sinֵ
	//! \param dAngle ��ת�Ƕ�
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, UGdouble dAngle = 0);
	
	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 
	
	virtual UGint GetDataSize() const;

public:	
	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator ͶӰת����
	//! \param bForward ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);
	
	//! \brief �Ӿ�γ����ϵͳת��ΪͶӰ����ϵͳ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJForward( UGPrjCoordSys *pCoordSys );

	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );
	
public:
	
	//! \brief ��������GeoLineM
	//! \param geolineM [in] ����LineM����
	//! \return �����߶���Ƿ�, ����false��
	UGbool Make( const UGGeoLineM& geoLineM);
	
	//! \brief ����һ���Ӷ����GeoLineM
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�ĵ���Ŀ��
	//! \return ����С��2��,����false��
	UGbool Make( const UGPoint3D* pPoints, UGint nPntCount );
	
	//! \brief �������Ӷ���ĸ���GeoLineM
	//! \param pPoints [in] �㴮ָ�롣
	//! \param pPolyCount [in] �Ӷ����е��������顣
	//! \param nSubCount [in] �Ӷ�����Ŀ��
	//! \return �����Ӷ���ĵ�����С��2��,����false��
	virtual UGbool Make( const UGPoint3D* pPoints, const UGint* pPolyCount, UGint nSubCount );

	//! \brief ���������һ���Ӷ���
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�ĵ���Ŀ��
	//! \return �㴮����С��2��, ����false��
	UGbool AddSub( const UGPoint3D* pPoints, UGint nPntCount );
	
	//! \brief �����Ӷ���
	//! \param nIndex [in] Ҫ�����λ��������
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�е�ĸ�����
	//! \return �����С��2��������λ�÷Ƿ�,����false��
	UGbool InsertSub(UGint nIndex, const UGPoint3D* pPoints, UGint nPntCount);
	
	//! \brief ɾ���Ӷ���
	//! \param nIndex [in] Ҫɾ�����Ӷ����λ��������
	//! \return �����Ƿ�, ����false��
	UGbool DelSub( UGint nIndex );
	
	//! \brief ��ָ����λ�������õ�����ꡣ
	//! \param nIndex [in] λ��������
	//! \param point [in] �����ꡣ
	//! \return �����Ƿ�, ����false��
	//! \remarks �����Ӷ���ĵ���һ�������������, ������û�������Ӷ���, ��ͷ��ʼ����������
	UGbool SetPoint( UGint nIndex, const UGPoint3D& point );
	
	//! \brief �õ��Ӷ�����Ŀ������ָ�롣
	//! \return �����Ӷ�����Ŀ������ָ�롣
	const UGint* GetPolyCounts() const;
	
	//! \brief �õ�ĳ���Ӷ���ĵ�ĸ�����
	//! \param nSubIndex [in] �Ӷ���������
	//! \return ����ĳ���Ӷ���ĵ�ĸ�����
	UGint GetSubPntCount(UGint nSubIndex) const;
	
	//! \brief �õ������Ӷ���ĵ�ĸ����ܺ͡�
	//! \return ���������Ӷ���ĵ�ĸ����ܺ͡�
	UGint GetPointCount() const;
	
	//! \brief �õ�ָ���Ӷ���ĵ㴮��ָ�롣
	//! \param nSubIndex [in] �Ӷ���������
	//! \return �����Ӷ���ĵ㴮��ָ�롣
	const UGPoint3D* GetPoints(UGint nSubIndex=0) const;
	
	//! \brief �õ�ָ��Index����ĵ�
	//! \param Index��������
	//! \return ʧ�ܷ���false
	UGPoint2D GetPointAtIndex(const UGint Index=0);
	UGbool GetPointAtIndex( UGPoint2D &point2d,const UGint Index=0);

	//! \brief �жϿ̶�ֵ�Ƿ��ڶ���·�ɷ�Χ��
	//! \param measure�̶�ֵ
	//! \return ��·���Ϸ���true�����ڷ���false
	UGbool IsMOnLineMSect(UGdouble dMeasrue);
	
public:
	enum UGWhereToComputeM
	{
		//! ��ȥ����
		NotToComputeM = 0,  
		//! ֻ�������֮ǰ��Section
		ExtropolateBefore = 1,   
		//! ֻ�����յ�֮���Section
		ExtropolateAfter  = 2,   
		//! �ڲ�����֮��Ŀ��Ƶ�
		Interpolate		= 4    
	};

	//! �����Ե�ö��
	enum UGMonotonicStyle
	{
		//! ��������
		MeasureAscending   = 0,   
		//! �����ݼ�
		MeasureDescending	 =1,    
		//! �ǵ���
		MeasureNotMonotonic=2     
	};

	//!brief Mֵ�ü��㷽��
	enum UGCalibrateBy
	{
		//! ���������
		ByDistance = 1,		
		//! ���߱����
		ByMeasure  = 2		
	};
	
	/*! \brief �ڲ�Measure modified by shanqc 2010-12-31
	*  \param nFromIndex   ��ʼ������
	*  \param nToIndex     ��ֹ������
	*  \param nFromSubObjID ��ʼ�Ӷ���ID
	*  \param nToSubObjID   ��ֹ�Ӷ���ID
	*  \param bIgnoreGap    �Ƿ�����Ӷ���֮��ļ��
	*  \return �ڲ����ɹ�����True,���򷵻�False
	*  \remarks 
	1�����nFromSubObjIDС��nToSubObjID,��������ʼ����ֹ�Ӷ����ID������
	   Ҳ����˵����С��ID������Ϊ��ʼ����
	2�������ʼ�Ӷ������ֹ�Ӷ���֮������ж���������β������������԰�
	   ������Ϊһ�������ڲ塣����������bIgnoreGap�Ƿ�Ϊ�棬������������Ӷ���֮���ڲ塣
	3����ǰֻ���������Ӷ���������β���������������Ӷ���֮���м������ʱ���������ڶ��ܴ���
	4�������nFromIndex��nToIndexΪ�Ӷ����ϵĵ���������������Ҫ������������·�ϵ�����
	*/
    GEOMETRY_APIF UGbool InterpolateMeasure(UGuint nFromIndex, UGuint nToIndex,
											UGuint nFromSubObjID =0,UGuint nToSubObjID =0,
											UGCalibrateBy calibrateby=ByDistance,UGbool bIgnoreGap = FALSE);

	/*! \brief �ڲ�Measure added by shanqc 2010-12-31
	*  \param pntFrom		��ʼ��
	*  \param pntTo			��ֹ��
	*  \param nFromMeasure  ��ʼ�����ֵ
	*  \param nToMeasure    ��ֹ�����ֵ
	*  \param tolerance     ����
	*  \param calibrateby   ���㷽�������뻹�����ֵ
	*  \return �ڲ����ɹ�����True,���򷵻�False
	*  \remarks 
	1������������ϣ�������ԭ��������Ϣ�ĵ㣬�����
	2��ֻҪһ���㲻�����Ͼͷ���False
	3����ǰ�Ӷ���֮���м�����򲻺��ԣ����ڸ���bIgnoreGap�Ƿ�Ϊ��������
	*/
	GEOMETRY_APIF UGbool InterpolateMeasure(UGPoint2D pntFrom, UGPoint2D pntTo,
											UGdouble nFromMeasure,UGdouble nToMeasure, 
											UGdouble tolerance,UGCalibrateBy calibrateby,UGbool bIgnoreGap = FALSE);
	/*! \brief ����Measure
	*  \param nExtropolateStyle  ���Ʒ�ʽ
	*  \param nFromIndex		 �Ӷ�����ʼ������
	*  \param nToIndex			 �Ӷ�����ֹ������
	*  \param nFromSubObjID		 ��ʼ�Ӷ���ID
	*  \param nToSubObjID		 ��ֹ�Ӷ���ID
	*  \param bIgnoreGap		 �Ƿ�����Ӷ���֮��ļ��
	*  \return ���Ƽ���ɹ�����True,���򷵻�False
	*  \remarks
	1�����nFromSubObjIDС��nToSubObjID,��������ʼ����ֹ�Ӷ����ID������
	   Ҳ����˵����С��ID������Ϊ��ʼ����
    2�������ʼ�Ӷ������ֹ�Ӷ���֮������ж���������β������������԰�
	   ������Ϊһ�������ڲ塣����������bIgnoreGap�Ƿ�Ϊ�棬������������Ӷ���֮���ڲ塣
	3.�����nFromIndex��nToIndexΪ�Ӷ����ϵĵ���������������Ҫ������������·�ϵ�����
	*/
	GEOMETRY_APIF UGbool ExtrapolateMeasure(UGuint nFromIndex,UGuint nToIndex ,
											UGWhereToComputeM nExtropolateStyle = ExtropolateBefore,
											UGuint nFromSubObjID =0,UGuint nToSubObjID =0, UGbool bIgnoreGap = FALSE);
/*! \brief ����Measure added by shanqc 2010-12-31
	*  \param pntFrom		��ʼ��
	*  \param pntTo			��ֹ��
	*  \param nFromMeasure  ��ʼ�����ֵ
	*  \param nToMeasure    ��ֹ�����ֵ
	*  \param tolerance     ����
	*  \param calibrateby   ���㷽�������뻹�����ֵ
	*  \param bIgnoreGap    �Ƿ�����Ӷ���֮��ļ��
	*  \return ���Ƽ���ɹ�����True,���򷵻�False
	*  \remarks 
	1������������ϣ�������ԭ��������Ϣ�ĵ㣬�����
	2��ֻҪһ���㲻�����Ͼͷ���False
	3������Ӷ���֮���м�������趨�Ƿ����
	*/
	GEOMETRY_APIF UGbool ExtrapolateMeasure(UGPoint2D pntFrom, UGPoint2D pntTo,
											UGdouble nFromMeasure,UGdouble nToMeasure, 
											UGdouble tolerance,UGCalibrateBy calibrateby,UGbool bIgnoreGap = FALSE);
	
	/*! \brief ���¼����߱�
	  *  \param nFromIndex   ��ʼ������
	  *  \param nToIndex     ��ֹ������
	  *  \param dFromM
	  *  \param dToM 
	  *  \param nHowToComputeMeasure
	  *  \param nCalibrateBy
	  *  \param nFromSubObjID ��ʼ�Ӷ���ID  ���ڻ�û���õ�
	  *  \param nToSubObjID   ��ֹ�Ӷ���ID  ���ڻ�û���õ�
	  *  \param bIgnoreGap    �Ƿ�����Ӷ���֮��ļ��
	  *  \return ���³ɹ�����True,���򷵻�False
	  *  \remarks
	  1�����nFromSubObjIDС��nToSubObjID,��������ʼ����ֹ�Ӷ����ID������
	  Ҳ����˵����С��ID������Ϊ��ʼ����
	  2�������ʼ�Ӷ������ֹ�Ӷ���֮������ж���������β������������԰�
	  ������Ϊһ���������㡣����������bIgnoreGap�Ƿ�Ϊ�棬������������Ӷ���֮���ڲ塣
	*/
	GEOMETRY_APIF UGbool UpdateMeasure(UGuint nFromIndex,UGuint nToIndex ,
					   UGdouble dFromM,UGdouble dToM, 	
					   UGWhereToComputeM nWhereToComputeMeasure = Interpolate,
					   UGCalibrateBy nCalibrateBy = ByDistance,
					   UGuint nFromSubObjID =0,UGuint nToSubObjID =0,UGbool bIgnoreGap = FALSE);

	/*! \brief ���¼����߱� added by shanqc 2011-01-09
	  *  \param pntFrom		��ʼ��
	  *  \param pntTo		��ֹ��
	  *  \param nFromMeasure
	  *  \param nToMeasure 
	  *  \param dTolerance
	  *  \param nHowToComputeMeasure
	  *  \param nCalibrateBy
	  *  \return ���Ƽ���ɹ�����True,���򷵻�False
	  *  \remarks
	  1�����nFromSubObjIDС��nToSubObjID,��������ʼ����ֹ�Ӷ����ID������
	  Ҳ����˵����С��ID������Ϊ��ʼ����
	  2�������ʼ�Ӷ������ֹ�Ӷ���֮������ж���������β������������԰�
	  ������Ϊһ���������㡣����������bIgnoreGap�Ƿ�Ϊ�棬������������Ӷ���֮���ڲ塣
	*/
	GEOMETRY_APIF UGbool UpdateMeasure(UGPoint2D pntFrom,UGPoint2D pntTo,
									   UGdouble dFromM,UGdouble dToM, UGdouble dTolerance,
									   UGWhereToComputeM nWhereToComputeMeasure = Interpolate,
									   UGCalibrateBy nCalibrateBy = ByDistance,UGbool bIgnoreGap = FALSE);

	/*! \brief ���¼����߱�,����ָ����(��Ҫ���ҵ�����)��ǰ��ĵ㡢����ĺ͵�֮�����ֵ
	  *  \param nIndex		 ָ��������
	  *  \param dMeasure     ָ�������ֵ
	  *  \param nFromIndex   ��ʼ������
	  *  \param nToIndex     ��ֹ������
	  *  \param nCalibrateBy ���㷽���������뻹�����������
	  *  \param dFromM		 ��ʼ�����ֵ
	  *  \param dToM		 ��ֹ�����ֵ
	  *  \remarks
	  1.����·У�����ֽܷ�Ϊ�����֣��������ô��룬���ṩ���෽��
	  2.UpdateMeasureBefore�������Ǵ��׵�Mֵ�仯��dMeasure���Ǵ�0�仯��dMeasure�����ǲ��ô��׵�Mֵ�仯��dMeasure
	  3.UpdateMeasureAfter�������Ǵ�dMeasure�仯��δ��Mֵ���Ǵ�dMeasure������仯�����ǲ��ô�dMeasure�仯��δ��Mֵ 
	*/
	UGbool UpdateMeasureBefore(UGuint nIndex,UGdouble dMeasure,UGCalibrateBy nCalibrateBy,UGbool bIgnoreGap= FALSE);
	UGbool UpdateMeasureAfter(UGuint nIndex,UGdouble dMeasure,UGCalibrateBy nCalibrateBy,UGbool bIgnoreGap = FALSE);
	UGbool UpdateMeasureInterval(UGuint nFromIndex,UGuint nToIndex,UGdouble dFromM,UGdouble dToM,
								 UGCalibrateBy nCalibrateBy,UGbool bIgnoreGap = FALSE);

	/*! \brief ���¼����߱�,����dRatio�����ǰ����������ֵ��У����
	  *  \param nIndex		 ָ��������
	  *  \param dMeasure     ָ�������ֵ
	  *  \param dRatio		 �������:��Mֵ�仯�����仯�ı���
	  *  \remarks	  ����У�����ܣ��������ô��룬���ṩ���෽�������
	*/
	UGbool UpdateMeasureBefore(UGuint nIndex,UGdouble dMeasure,UGdouble dRatio,UGbool bIgnoreGap= FALSE);
	UGbool UpdateMeasureAfter(UGuint nIndex,UGdouble dMeasure,UGdouble dRatio,UGbool bIgnoreGap = FALSE);
	/*! \brief �߱�ƽ��
	*  \param dOffset   ƽ����
	*  \return 
	*  \remarks
	*/
	GEOMETRY_APIF void OffsetMeasure(UGdouble dOffset);	  
	
	/*! \brief �Ӿ���õ��߱�
	*  \param  dDistance   ���߶����ľ���
	*  \param  nSubObjID   ��ʼ�Ӷ���ID(�����1��ʼ���ײ��0��ʼ)
	*  \param  bIgnoreGap  �Ƿ�����Ӷ���֮��ļ��
	*  \return �߱�
	*  \remarks
	*/
	GEOMETRY_APIF UGdouble GetMAtDistance(UGdouble dDistance,UGbool bIgnoreGap);
	GEOMETRY_APIF UGdouble GetMAtDistance(UGdouble dDistance, UGint nStartSubObjID, UGbool bIgnoreGap);
	GEOMETRY_APIF UGdouble GetSubMAtDistance(UGdouble dDistance, UGuint nSubObjID);
	//	UGdouble GetMAtDistance_test(UGdouble dDistance, UGuint nSubObjID = 0);
	
	/*! \brief �ӵ�����õ��߱�
	*  \param  resPoint    ��ά��
	*  \param  dMeasure    Ҫ���ص��߱�
	*  \param  dTolerance  ����
	*  \param  bIgnoreGap  �Ƿ�����Ӷ���֮��ļ��
	*  \return �߱�
	*  \remarks
	*/
	GEOMETRY_APIF UGbool GetMAtPoint(UGPoint2D resPoint, UGdouble &dMeasure, UGdouble tolerance , UGbool bIgnoreGap);

	GEOMETRY_APIF UGbool GetMsAtPoint(UGPoint2D resPoint, UGArray<UGdouble> &arrMeasure, UGdouble tolerance);

	/*! \brief �õ������߱�M(���)֮�����·
	*  \param  geoLineM		�����߶���
	*  \param  dFromMeasure ��ʼ�߱�
	*  \param  dToMeasure   ��ֹ�߱�
	*  \param  dOffset	    ƫ����
	*  \param  bIgnoreGap   �Ƿ�����Ӷ���֮��ļ��
	*  \return �߱�
	*  \remarks
	*/
	GEOMETRY_APIF UGlong GetLineMAtM(UGGeoLineM& geoLineM, UGdouble dFromMeasure, UGdouble dToMeasure, 
									 UGdouble dOffset, UGbool bIgnoreGap= TRUE);
	
	/*! \brief У����·
	*  \param  pCbPoints	�����׼��
	*  \param  dFromMeasure ��ʼ�߱�
	*  \param  nCalibrate   У�����������뻹�����
	*  \param  nComputeStyleУ����ʽ
	*  \param  bIgnoreGap   �Ƿ�����Ӷ���֮��ļ��
	*  \param  pErrorType   ��������(ĿǰΪ��̬�ֶ�ʹ��)
	*  \return �߱�
	*  \remarks
	*/
	GEOMETRY_APIF UGbool Calibrate(UGPoint3D* pCbPoints,UGlong nPointsCount, UGCalibrateBy nCalibrate,
						  UGint nComputeStyle, UGbool bIgnoreGap,UGdouble dTolerance = EP,UGint* pErrorType = NULL);
	
	GEOMETRY_APIF void Empty();
	void q_MeasureSort(MeasurePointInfo *pData, UGlong nCount);

	/* \brief �ڵ� lSubObjID ���Ӷ���� lPointID λ������� lPointCount ����
	* \param  lSubObjID	Ŀ���Ӷ���
	* \param  lPointID	Ŀ��λ��
	* \param  pPoints		Ҫ��ӵĵ����괮
	* \param  lPointCount	Ҫ��ӵĵ���
	* \return 
	* \note
	*/	
	GEOMETRY_APIF UGbool InsertPoints(UGint lSubObjID, UGint lPointID, UGPoint3D *pPoints , UGint lPointCount);
	GEOMETRY_APIF UGbool InsertPoint(UGint lSubObjID, UGint lPointID, UGPoint3D &pntPoint);
	/* \brief  �ڵ� lSubObjID ���Ӷ��������һ����
	* \param  lSubObjID	Ŀ���Ӷ���
	* \param  pntPoint	Ҫ��ӵĵ�
	* \return 
	* \note
	*/
	GEOMETRY_APIF UGbool AddPoint(UGint lSubObjID ,UGPoint3D &pntPoint);
	GEOMETRY_APIF UGbool AddPoints(UGint lSubObjID ,UGPoint3D *pPoints , UGint lPointCount);

	/* \brief �õ��Ӷ�������ָ�롢�Ӷ����������Ӷ�������·
	* \param  nIndex   λ��������
	* \param  geoLineM �Ӷ���
	* \return �����Ƿ�, ����false��
	*! \remarks �����Ӷ���ĵ���һ�������������
	*/
	GEOMETRY_APIF const UGPoint3D * GetSubPointer(UGint nIndex);
	GEOMETRY_APIF UGlong GetSubPointCount(UGint nIndex);
	GEOMETRY_APIF UGbool GetSubLine(UGint lSubIndex, UGGeoLineM& geoLineM);

	GEOMETRY_APIF const UGPoint3D * GetPointer();

	/*! \brief  ���ݾ��������߱�
	*  \param OriginM     ����ֵ
	*  \param dScale      �������� 
	*  \param bIgnoreGap  �Ƿ�����Ӷ���֮��ļ��
	*  \return
	*  \remarks  ԭ��pntOriginָ���˾��������λ�á���������߱궼�Ժ�ԭ�����̾�������
	*/
	GEOMETRY_APIF void SetMAsDistance(UGdouble OriginM =0.0,UGdouble dScale = 1.0);//dOffsetΪ����ֵ
	GEOMETRY_APIF void SetMAsDistance(UGdouble OriginM ,UGdouble dScale ,UGbool bIgnoreGap);

	/*! \brief  ���ݵ������߱�
	*  \param pPoints		���������
	*  \param pMeasures		������Ŀ̶�����
	*  \param nCount	    Ҫ��ɵĵ��� 
	*  \param pErrors	    ÿ����Ĵ��󷵻�ֵ���� 
	*  \param dTolerance    ���� 
	*  \param bIgnoreGap	�Ƿ�����Ӷ���֮��ļ��
	*  \return
	*  \remarks  ԭ��pntOriginָ���˾��������λ�á���������߱궼�Ժ�ԭ�����̾�������
	*/
	GEOMETRY_APIF UGlong SetMByPoints(UGPoint2D* pPoints, UGdouble* pMeasures, UGlong nCount, UGlong* pErrors, 
		UGdouble dTolerance, UGbool bIgnoreGap);

	/*! \brief  ���ݵ������߱� added by shanqc 2010-12-28
	*  \param point3dSrc	��ά��
	*  \param point2dSrc	��ά��
	*  \param Px			�����ĺ�����
	*  \param Py			������������
	*  \param MeasurZ		���ֵ
	*  \param bOnSegment=FALSE ������߶��ϣ��͸�ΪTRUE
	*  \param whereToCompute���¼���Mֵ�������õ�ǰ���
	*  \return	�㲻������ʱ���� -1��������ʱ���ص��������������߶��ϣ�����벢���ص�����
	*  \remarks �ο�TransCAD���Բο��Ĺ���,���趨��ǰ��ĵ���д�0��MeasurZ�仯������İ���������
	*/
	GEOMETRY_APIF UGint SetMAtPoint(UGPoint2D point2dSrc, UGdouble MeasurZ, UGdouble dTolerenceSrc, 
									UGint whereToCompute,UGbool& bOnSegment);
	
	/*! \brief   ���߱�õ�����
	*  \param   dMeasure    �߱�
	*  \param   nSubObjID   �Ӷ���ID,����������õ��ľ����Ǿ��Ӷ������ľ��룬������·���
	*  \param   bIgnoreGap  �Ƿ�����Ӷ���֮��ļ�� 
	*  \return  ����
	*  \remarks
	*/
	GEOMETRY_APIF UGdouble GetDistanceAtM(UGdouble dMeasure,UGuint nSubObjID,UGbool bIgnoreGap);
	GEOMETRY_APIF UGdouble GetDistanceAtM(UGdouble dMeasure,UGbool bIgnoreGap);
	
	/*! \brief  ���߱�õ�����
	*  \param  dMeasure  �߱�
	*  \param  dOffset   ����߶εľ���
	*  \param  pIndex    �����֮ǰ���߶ο��Ƶ�����,����ֵ
	*  \param  bIgnoreGap�Ƿ�����Ӷ���֮��ļ��
	*  \return
	*  \remarks һ���߱�����Ӧ���������ܲ�ֹһ��.�������Ӷ���Ĵ洢˳�����β���,���ص�һ����
	*/
	GEOMETRY_APIF UGPoint2D GetCoordinateAtM(UGdouble dMeasure, UGdouble dOffset = 0.0, UGint* pIndex = NULL);
	GEOMETRY_APIF UGPoint2D GetCoordinateAtM2(UGdouble dMeasure, UGdouble dOffset, UGint* pIndex= NULL, UGbool bIgnoreGap= TRUE);
	//CPoint2D GetCoordinateAtM( double dMeasure, double dOffset = 0.0 , LONG* pIndex = NULL, BOOL bIgnoreGap = TRUE);
	
	/*! \brief���߱�õ�����
	*  \param   GeoLine		  �������
	*  \param   dFromMeasure  �����߱�
	*  \param   dToMeasure    �յ���߱�
	*  \return
	*  \remarks
	*/
	GEOMETRY_APIF UGbool GetSubCurveAtM(UGGeoLine& GeoLine,UGdouble dFromMeasure,UGdouble dToMeasure);
	
	/*! \brief   �������߱�λ�ô����߱�ֵ
	*  \param  bIgnoreGap�Ƿ�����Ӷ���֮��ļ��
	*  \return
	*  \remarks
	*/
	GEOMETRY_APIF void CaculateNoM(); 
	GEOMETRY_APIF void CaculateNoM(UGbool bIgnoreGap);
	
	/*! \brief   ��ת�߱�
	*  \param 
	*  \return
	*  \remarks
	*/
	GEOMETRY_APIF UGbool ReversMOrder();      
		
	/*! \brief   �õ�����߱�ֵ
	*  \param 
	*  \return
	*  \remarks
	*/
	GEOMETRY_APIF UGdouble GetMaxMeasure();
	
	/*! \brief  �õ���С�߱�ֵ
	*  \param 
	*  \return
	*  \remarks
	*/
	GEOMETRY_APIF UGdouble GetMinMeasure();
	
	/*! \brief   �õ�·�ߵĵ�����
	*  \param  
	*  \return
	*  \remarks
	*/
	GEOMETRY_APIF UGGeoLineM::UGMonotonicStyle GetMonotonicStyle();
	
	/*! \brief �ϲ��߶��󣬹����һ�������߶���
	*  \param pGeoLineM �ϲ����߶���
	*  \return
	*  \attetion ��δʵ��
	*/
	GEOMETRY_APIF UGbool Combination(UGGeoLineM *pGeoLineM );

	/*! \brief �ϲ��߶��󣬹����һ�������߶���
	*  \param pGeoLine �ϲ����߶���
	*  \return
	*  \attetion ��δʵ��
	*/
	GEOMETRY_APIF UGbool Combination(UGGeoLine* pGeoLine);
	
	/*! \brief  ��ת�����Ĵ���
	*  \return
	*  \remarks
	*/
	GEOMETRY_APIF UGbool Reverse();
	
	//! \brief ȡ����������������(��Բ)����
	//! \param dRadius ����뾶(��λΪǧ��)
	//! \param nDistUnits ����ϵͳ�еľ��뵥λ
	//! \return ���ش��򳤶�
	GEOMETRY_APIF UGdouble GetRadianDistance(UGdouble dRadius = 6371118, UGint nDistUnits = AU_METER);
	
	//! \brief �õ�ָ������ĵ����ꡣ
	//! \param dDistance [in] ָ���ľ��롣
	//! \return ���ط��������ĵ����ꡣ
	GEOMETRY_APIF UGPoint2D GetPointAtDistance(UGdouble dDistance, UGbool bIsIgnoreGap = TRUE);	

	/*! \brief �õ�ָ���̶ȣ���̣����ĵ����
	*  \param dDistance [in] ָ���ľ��롣
	*  \param  dMeasure  �߱�
	*  \param  dOffset   ƫ����
	*  \param  bIgnoreGap�Ƿ�����Ӷ���֮��ļ��
	*  \return ���ط��������ĵ�������Ҫ�õ������꣬��Ҫת��
	*/
	GEOMETRY_APIF UGlong GetPointAtM(UGGeoPoint& geoPoint, UGdouble dMeasure, 
									 UGdouble dOffset = 0.0,UGbool bIgnoreGap = TRUE);
	// 	UGlong GetPointAtM(UGGeoPoint& geoPoint, UGdouble dMeasure, UGdouble dOffset /* = 0::0 */);
	//	LONG GetPointAtM(CGeoPoint& geoPoint, double dMeasure, double dOffset = 0.0,BOOL bIgnoreGap = TRUE);

	//! \brief �ü� ֧��LineM�Ĳü����ܣ�added by shanqc 2010-12-15
	//! \param pGeoSource �μӲ����ļ��ζ���ָ��, ����ΪNULL
	//! \param pGeoClip   �μӲ����ļ��ζ���ָ��, ����ΪNULL
	//! \param pPoint3ds  �ü���õ��㴮
	//! \param pPolyCount �Ӷ���ĵ�ĸ��� ��Ϣ����������
	//! \param nSubCount  �Ӷ������
	//! \attention        ��Ȼ�������UGGeoLineM����Ҳ֧�������Ķ��󣬵��桢���ߡ����ߡ����桢����֮���󽻣�
	//!					  ���֮������ͬ��; ����������� = ��
	//! \return ������Ϊ��,����FALSE
	GEOMETRY_APIF UGbool ClipLineM(UGGeometry* pGeoSource,UGGeometry* pGeoClip, 
								   UGPoint3Ds* pPoint3ds,UGint*& pPolyCount, UGint& nSubCount);
	
	//! \brief ���� ����·һ��Ϊ����֧��LineM��added by shanqc 2010-12-15
	//! \param splitPoint	 �ָ��, ����ΪNULL
	//! \param geolinemNew1  �����ɶ���
	//! \param geolinemNew2  �����ɶ���
	//! \attention 
	//! \return �ɹ�����TRUE,����FALSE
	GEOMETRY_APIF UGbool SplitLineM(UGPoint2D splitPoint,UGGeoLineM*& geolinemNew1,UGGeoLineM*& geolinemNew2);

	//! \brief ��������Ϲ���GeoLineM����added by shanqc 2010-12-15
	//! \param pLinesSrc	[in] �߶���ָ�롣
	//! \param pPoint3Ds	[in] ��ά�����顣
	//! \param nPointCount	[in] ������ĳ��ȡ�
	//! \attention ��Ҫ�ⲿ������һ���ն��󣬺������޸Ŀն�������ݣ��������������
	//! \return  �ɹ�����TRUE,����FALSE��
	GEOMETRY_APIF UGbool Make(UGGeoLine* pLinesSrc,UGPoint3D* pPoint3Ds,UGint nPointCount);

	//! \brief �õ��Ӷ��󳤶� added by shanqc 2010-12-23
	//! \param SubID �Ӷ�����š�
	//! \return ���س���	
	GEOMETRY_APIF UGdouble GetSubLength(UGint SubIndex);

	GEOMETRY_APIF UGGeoLine GetLine();
#if PACKAGE_TYPE==PACKAGE_UGC
public:	
#if !defined (IOS) 
	//! \brief Geometry��Element��ת��
	//! \param pElement,���ص�pElementָ���ں����ڷ����ڴ�,���渺��ɾ������������ڴ�й©
	virtual UGbool ToElement(OgdcElement*& pElement)  const;

	//! \brief Geometry��Element��ת��
	//! \param pElement,�����Element������޷�ת���򷵻�False�����򷵻�True
	virtual UGbool FromElement(const OgdcElement* pElement);
#endif	
	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
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
	virtual void MoveHandle(UGint nHandle, const UGPoint2D& pnt2D,
							UGEditType::EditToolShape nEditType=UGEditType::ET_Default);

	//! \brief �ڵ�༭ʱ����������һ�����Ƶ�,Ҳ�������ڻ��ƶ���ʱ����ڵ�
	//! \param nHandle ����λ��
	//! \param pnt2D �����ĵ�������
	virtual void AddHandle(UGint nHandle, const UGPoint2D& pnt2D,
						   UGEditType::EditToolShape nEditType=UGEditType::ET_Default);
	
	//! \brief ɾ���༭�����ָ���ڵ�
	//! \param nHandle �ڵ���
     virtual UGuint DelNode( UGint nHandle );

	//! \brief ����������ʱ�ĸ����ߣ����ص���һ�����϶���
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	//! \param pStyle	 �����ߵķ���������ΪNULL����Ĭ�ϵķ��
     virtual UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints, UGint nPntCount,
										   UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);

	//! \brief ����������ʱ�ĸ����㣬���ص��ǵ����Ŀ,nHandleType���ص��Ǹ����������,�ο�UGEditType::EditHandleType
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param eAssistantPoints �㴮,���صĸ�����㴮
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	void CalAssistantPoints(const UGPoint2D* pPoints,UGint nPntCount,
							UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,
							UGEditType::EditToolShape nEditType);



	//! \brief ���ݴ���ĵ㴮���ɶ�����Ҫ���ڱ༭�еĲ�������û���ڲ����鱣��㴮�Ķ���
	//	Ҳ�����Զ������,�������ڲ����鱣��㴮�Ķ��󣬸ú���ֱ��return�ȿɣ�����GeoLine
	//	GeoLine�ȶ����ֱ����AddHandle�����ɣ�Ч�ʱȽϸ�,���������ƽ���ߣ�������������
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
     virtual void MakeWithPoints(UGPoint2D* pPoints,UGint nPntCount,
								 UGEditType::EditToolShape nEditType=UGEditType::ET_Default);

	//������������Ժ����Ҫ�á�commented by shanqc 2010-12-13
	// virtual void MakeWithPoints(UGPoint3D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType=UGEditType::ET_Default);
	//! \brief ��ȡ������Ҫ��׽�ĵ㴮
	//! \param aryPnts �㴮������ȥ��Ҫ��׽�ĵ㴮
	//! \return �����true��ʾ����Ҫ��׽�ĵ㴮���������false��ʾ�ö���û����Ҫ��׽�ĵ㴮
	virtual UGbool GetSnapPoints(UGArray<UGPoint2D>& aryPnts);

	//! \brief ��ȡ������Ҫ��׽���߶�����
	//! \param aryLines ��Ҫ��׽�������飨����ж��part����ôaryLines��Ӧ���ж��ٸ�count��
	//! \return �����true��ʾ����Ҫ��׽���ߣ��������false��ʾ�ö���û����Ҫ��׽����
	virtual UGbool GetSnapLines(UGLineArray& aryLines);
	 
	 //added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ end


#endif // end declare ugc sdk
	
protected: //! ������Ҫʵ�ֵ�һЩ����������
	virtual UGRect2D ComputeBounds() const;
	
	/*virtual UGRect2D GetBoundsInside() const;
	
	virtual void SetBoundsInside(const UGRect2D & rcBounds);*/
	
	//! \brief �洢��Stream��
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE)  const;
	
	//! \brief ��Stream������Geometry
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE ,UGbool bSDBPlus = FALSE);
	
	// ���߶��Ƿ�����
	UGbool IsHasGapBetween(UGuint nFromSubObjID ,UGuint nToSubObjID);
	UGint GetSubIDFromPointID(UGuint nPointID);	
	/*! \brief  ���������õ����� added by longzheng 2011-08-16
	*  \param point2dSrc	��ά��
	*  \param dFindM		ԭ���ֵ
	*  \param bOnSegment=FALSE ������߶��ϣ��͸�ΪTRUE
	*  \return	�㲻������ʱ���� -1��������ʱ���ص��������������߶��ϣ�����벢���ص�����
	*/
	UGint GetIndexAtPoint(UGPoint2D point2dSrc, UGdouble& dFindM, UGdouble Tolerence,UGbool& bOnSegment);

#if PACKAGE_TYPE==PACKAGE_UGC
	UGString SubLineToSML(int nIndex, int nIndentCount);
	UGString Point3DToSML(const UGPoint3D* pPoints, int nPntCount, int nIndentCount);
	void GetDoubleArry(UGString& str, std::vector<UGdouble>& doubleDataArray );
	void AddSubLineFromSML(const UGString& strSubSml);
#endif // end declare ugc sdk

private:
	//! \brief �����㴮, z�������Mֵ
	UGArray<UGPoint3D> m_Points;
	
	//! \brief ������� �����Ӷ���ĵ�ĸ��� ��Ϣ����������
	UGArray<UGint> m_PolyCounts;

	//! \brief ���Mֵ,Ĭ��Ϊ0
	mutable UGdouble m_dMaxMeasure;
	//! \brief ��СMֵ,Ĭ��Ϊ0
	mutable UGdouble m_dMinMeasure;

	//UGint m_nLineMID;

	//! \brief ������,Ĭ��ΪMeasureNotMonotonic,�ǵ���
	mutable UGMonotonicStyle m_nMeasureMonotonic;
};

}
#endif // !defined(AFX_UGGEOLINEM_H__4D04C30B_CF4B_411E_A107_6ABEE27A07C7__INCLUDED_)


