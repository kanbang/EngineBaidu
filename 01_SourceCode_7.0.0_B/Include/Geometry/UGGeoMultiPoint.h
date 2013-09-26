#ifndef INCLUDE_GEOMETRY_UGGEOMULTIPOINT_H_HEADER_INCLUDED_BE224D0F
#define INCLUDE_GEOMETRY_UGGEOMULTIPOINT_H_HEADER_INCLUDED_BE224D0F

#include "Geometry/UGGeometry.h"
#include "Geometry/UGGeoPoint.h"

namespace UGC {

//! \brief ������
//! \remarks GeoPoint��GeoLine,GeoRegion��һ�㲻һ��, GeoPointû�и��Ӷ���һ˵,��GeoPointֻ����һ����,
//! �����ж���Ӷ���(�����ݼ�Ҳֻ����GeoPoint����,�����ж�����);
//! ��Ҫ�����ʱ, ʹ��GeoMultiPoint(ע��,GeoMultiPoint���ܼ��뵽�����ݼ���,ֻ�ܼ��뵽�������ݼ���)
class GEOMETRY_API UGGeoMultiPoint : public UGGeometry
{
public:
	//! \brief ���캯��
    UGGeoMultiPoint();

	//! \brief ��������
    virtual ~UGGeoMultiPoint();

public: //pure virtual 

	//! \brief ���Geometry�ڲ�����
	virtual void Clear();

	//! \brief �õ�ά��, �̶�Ϊ0
	virtual UGint GetDimension() const;

	//! \brief �õ�����, �̶�Ϊ GeoMultiPoint
	virtual Type GetType() const;

	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \remarks ��ʱ�ȷ����м�˳��ĵ�,�Ժ���Կ����þ���Bounds��������ĵ�
	//! \return �����ڵ�
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief �õ��Ӷ�����Ŀ��
	//! \return �����Ӷ������ݡ�
	virtual UGint GetSubCount() const;	
	
	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;

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

	//! \brief �õ��ռ�����, ��Ҫ������Ҫ����ά����ͬʱ
	//! ����ͳһ�����ʱ��, ����һЩ�ռ��жϺͲ������㷨
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
				UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	//! \brief ���ζ����Ƿ���Ч
	//! \return �Ӷ���Ϊ0,����true
	virtual UGbool IsValid()const;
	
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief ����
	//! \param dRatio ���ű���(X,Y������ͬ)
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
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dCosAngle,
						UGdouble dSinAngle, double dAngle = 0);

	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \remarks ������ΪBounds�����ĵ�
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
#if !defined (IOS) 
	//! \brief Geometry��Element��ת��
	//! \param pElement,���ص�pElementָ���ں����ڷ����ڴ�,���渺��ɾ������������ڴ�й©
	virtual UGbool ToElement(OgdcElement*& pElement)  const;

	//! \brief Geometry��Element��ת��
	//! \param pElement,�����Element������޷�ת���򷵻�False�����򷵻�True
	virtual UGbool FromElement(const OgdcElement* pElement);
#endif
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
	
	//! \brief ���ƹ��������
	//! \param geoMultiPoint [in] ���еĶ�����
	//! \return ���ж���Ƿ�������false��
	UGbool Make(const UGGeoMultiPoint& geoMultiPoint);	

	//! \brief ͨ���㴮���������
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�е�ĸ�����
	//! \return ����Ϊ0������false��
	UGbool Make(const UGPoint2D* pPoints, UGint nPntCount);	

	//! \brief �õ��ڲ��㴮��
	//! \return ���ص㴮��Ϊconst���ͣ�����һ�㲻Ҫ�޸ġ�
	const UGPoint2D *GetPoints();    

	//! \brief �õ���ĸ�����
	//! \return ���ص�ĸ�����
	UGint GetPointCount();    

	//! \brief �õ�ָ�������ĵ����ꡣ
	//! \param nIndex [in] ָ����������
	//! \param pntPoint [out] ��������ꡣ
	//! \return �����Ƿ�������false��
	UGbool GetPoint(UGint nIndex, UGPoint2D& pntPoint);    

	//! \brief ����ָ�������ĵ����ꡣ
	//! \param nIndex [in] ָ����������
	//! \param pntPoint [in] �����ꡣ
	//! \return �����Ƿ�������false��
	UGbool SetPoint(UGint nIndex, const UGPoint2D &pntPoint);    

	//! \brief ���ӵ㡣
	//! \param pntPoint [in] �����ꡣ
	//! \return ����true��
	UGbool AddPoint(const UGPoint2D &pntPoint);    
	
	//! \brief ͨ��ָ���������Ӷ��󣬹���������
	//! \param nIndex [in] ָ����������
	//! \param pGeoPoint [out] �õ��ĵ�������ָ�봫��ʱΪNULL���ڲ���new������
	//! \return �����Ƿ�������false��
	UGbool GetSub(UGint nIndex, UGGeoPoint *&pGeoPoint);	
	
	//! \brief ����㡣
	//! \param nIndex [in] �����λ��������
	//! \param pntPoint [in] Ҫ����ĵ㡣
	//! \return �����Ƿ�,����false��
	UGbool InsertPoint(UGint nIndex,const UGPoint2D &pntPoint);    

	//! \brief �Ƴ�ָ��λ�õĵ㡣
	//! \param nIndex [in] ָ��λ��������
	//! \return �����Ƿ�,����false��
	UGbool RemovePoint(UGint nIndex);    

	//! \brief ���ӵ㴮��
	//! \param pPoints [in] �㴮��ָ�롣
	//! \param nPointCount [in] �㴮�ĵ������
	//! \return ����true��
	UGbool AddPoints(const UGPoint2D *pPoints, UGint nPointCount);    

	//! \brief ��ָ��λ�ò���һ���㴮��
	//! \param nIndex [in] ָ��������λ�á�
	//! \param pPoints [in] ����ĵ㴮��
	//! \param nPointCount [in] �㴮�ĵ������
	//! \return ����λ�÷Ƿ�,����false��
	UGbool InsertPoints(UGint nIndex, const UGPoint2D *pPoints, UGint nPointCount);    

	//! \brief �Ƴ����ɸ��㡣
	//! \param nIndex [in] Ҫ��ʼ�Ƴ���λ��������
	//! \param nPointCount [in] Ҫ�Ƴ��ĵ������
	//! \return λ�������Ƿ�,����false��
	UGbool RemovePoints(UGint nIndex, UGint nPointCount);    
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


	 //! \brief ���ݴ���ĵ㴮���ɶ�����Ҫ���ڱ༭�еĲ�������û���ڲ����鱣��㴮�Ķ���
	 //Ҳ�����Զ������,�������ڲ����鱣��㴮�Ķ��󣬸ú���ֱ��return�ȿɣ�����GeoLine
	 //GeoLine�ȶ����ֱ����AddHandle�����ɣ�Ч�ʱȽϸ� 
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
     virtual void MakeWithPoints(UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType=UGEditType::ET_Default);

	 //! \brief ��ȡ������Ҫ��׽�ĵ㴮
	//! \param aryPnts �㴮������ȥ��Ҫ��׽�ĵ㴮
	//! \return �����true��ʾ����Ҫ��׽�ĵ㴮���������false��ʾ�ö���û����Ҫ��׽�ĵ㴮
	virtual UGbool GetSnapPoints(UGArray<UGPoint2D>& aryPnts);

	//! \brief ��ȡ������Ҫ��׽���߶�����
	//! \param aryLines ��Ҫ��׽�������飨����ж��part����ôaryLines��Ӧ���ж��ٸ�count��
	//! \return �����true��ʾ����Ҫ��׽���ߣ��������false��ʾ�ö���û����Ҫ��׽����
	virtual UGbool GetSnapLines(UGLineArray& aryLines);

	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ end
protected:
	virtual UGRect2D ComputeBounds() const;
	
	/*virtual UGRect2D GetBoundsInside() const;

	virtual void SetBoundsInside( const UGRect2D & rcBounds );*/
	
	//! \brief �洢��Stream��
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	//! \brief ��Stream�м���Geometry
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );

private:
	//! \brief �ڲ��õ��������洢���������
	UGArray<UGPoint2D> m_Points;

};

} // namespace UGC



#endif /* INCLUDE_GEOMETRY_UGGEOMULTIPOINT_H_HEADER_INCLUDED_BE224D0F */

