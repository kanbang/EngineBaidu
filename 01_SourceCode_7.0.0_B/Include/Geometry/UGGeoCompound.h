#ifndef UGGEOCOMPOUND_H
#define UGGEOCOMPOUND_H

#include "Geometry/UGGeometry.h"

namespace UGC {

//! \brief ���϶���
//! \remarks ���϶���ʹ�������ģʽ�е�"�ۺ�ģʽ",�����԰��������⼸�ζ���(�������϶�����)�ۺ���һ��,
//! �γ�һ����״�Ľṹ;ֵ��ע�����,�����϶���ۺϵļ��ζ��������ָ�����ʽ,��֮��͹鸴�϶����������ڴ���.
#ifdef SYMBIAN60
class GEOMETRY_APIC UGGeoCompound : public UGGeometry
#else
class GEOMETRY_API UGGeoCompound : public UGGeometry
#endif
{
public:
	//! \brief ���캯��
    GEOMETRY_APIF UGGeoCompound();
	GEOMETRY_APIF UGGeoCompound(const UGGeoCompound& geoCompound);
	//! \brief ��������
    virtual GEOMETRY_APIF ~UGGeoCompound();

	static UGGeometry::Type GetCompoundType(UGGeometry* pGeometry);
	
public: //pure virtual GEOMETRY_APIF 
	
	//! \brief ��յ�������
	virtual GEOMETRY_APIF void Clear();
	
	//! \brief �õ�ά��,�̶�Ϊ-1
	virtual GEOMETRY_APIF UGint GetDimension() const;

	//! \brief �õ�����,�̶�ΪGeoCompound
	virtual GEOMETRY_APIF Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \remarks �ڵ�Ϊ�����м�˳��(�����м�λ��)�ļ��ζ�����ڵ�
	//! \return �����ڵ�
	virtual GEOMETRY_APIF UGPoint2D GetInnerPoint() const;
	
	//! \brief �õ��������
	//! \return �������
	virtual GEOMETRY_APIF UGdouble GetArea() const;
	
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
	virtual GEOMETRY_APIF void Rotate(const UGPoint2D& pntOrigin, UGdouble dCosAngle,
						UGdouble dSinAngle, double dAngle = 0);
	
	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool Resize(const UGRect2D& rcNewBounds); 
	
	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
// 	//! \brief ���÷��
// 	//! \param pStyle ���ָ��
// 	//! \remarks ���pStyle==NULL,��Geometry�ڲ����ָ�뱻ɾ��; ����Ḵ��һ�ݷ��
// 	//! �����ı������, ���÷��������,��Ϊ�ı��������Լ���TextStyle
// 	virtual GEOMETRY_APIF void SetStyle(const UGStyle* pStyle);
public:
	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator ͶӰת����
	//! \param bForward ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	virtual GEOMETRY_APIF void PJConvert( UGRefTranslator *pRefTranslator, UGbool bForward = true);
	
	//! \brief �Ӿ�γ����ϵͳת��ΪͶӰ����ϵͳ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual GEOMETRY_APIF void PJForward( UGPrjCoordSys *pCoordSys );

	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual GEOMETRY_APIF void PJInverse( UGPrjCoordSys *pCoordSys );
	
public:

	
	//! \brief ���ƹ��츴�϶���
	//! \param geoCompound [in] ���еĸ��϶���
	//! \return ���и��϶���Ƿ�,����false��
	GEOMETRY_APIF UGbool Make(const UGGeoCompound& geoCompound);	
	
	//! \brief ����һ�����ζ���
	//! \param pGeometry [in] ���ζ���ָ�롣
	//! \param bByDimension [in] ���bByDimensionΪtrueʱ,��������������ӵļ��ζ�������ж����ס
	//!			ֱ���ҵ�һ����ά�����Ҳ��ᱻ�����Ӷ�����ȫ���ǵĶ���Ϊֹ,����ֱ����ײ㡣
	//! \return �����ӵļ��ζ���ָ�벻ΪNULL,����true��
	GEOMETRY_APIF UGbool AddCompound(UGGeometry *pGeometry, UGbool bByDimension = TRUE);    
	
	//! \brief ��ָ����λ�����ý�϶���
	//! \param nIndex [in] ָ����λ��������
	//! \param pGeometry [in] ���ζ���ָ�롣
	//! \return ���ζ���ָ�벻ΪNULL,����true��
	//! \remarks ָ��λ����ԭ�еļ��ζ��󽫱�delete����
	GEOMETRY_APIF UGbool SetCompound(UGint nIndex, UGGeometry *pGeometry);    
	
	//! \brief ��ָ����λ�ò���һ�����ζ���
	//! \param nIndex [in] ָ����λ��������
	//! \param pGeometry [in] ���ζ���ָ�롣
	//! \return ���ζ���ָ�벻ΪNULL,����true��
	GEOMETRY_APIF UGbool InsertCompound(UGint nIndex, UGGeometry *pGeometry);    
	
	//! \brief �Ƴ�(��delete)ָ��λ�õ��Ӷ���
	//! \param nIndex			[in] ָ����λ��������
	//! \param bDeleteGeometry	[in] �Ƿ�ɾ�����Ӷ���
	//! \return �����Ƿ�,����false��
	GEOMETRY_APIF UGbool RemoveGeometry(UGint nIndex,UGbool bDeleteGeometry = true);    
	
	//! \brief �����Ӷ���Bounds�Ĵ�С���������и��϶����и����Ӷ��������˳��
	//! \param bMoveUptheMinObj [in] Ϊtrueʱ,С����������;ΪfalseʱС���������档
	GEOMETRY_APIF void Adjust(UGbool bMoveUptheMinObj = true);    
	
	//! \brief �õ�ָ��λ�õ��Ӷ���(Ҳ��Geometry)ָ�롣
	//! \param nIndex [in] ָ����λ��������
	//! \return �Ӷ���ָ��, λ�÷Ƿ�ʱ,����NULL��
	GEOMETRY_APIF UGGeometry *GetGeometry( UGint nIndex );	

	//! \brief �õ�ָ��λ�õ��Ӷ���(Ҳ��Geometry)ָ�롣
	//! \param nIndex [in] ָ����λ��������
	//! \return const�����Ӷ���ָ��,���治���޸�, λ�÷Ƿ�ʱ,����NULL��
    GEOMETRY_APIF const UGGeometry *GetGeometry( UGint nIndex ) const;
	
	//! \brief �ֽ⸴�϶���
	//! \param arrGeometry [out] �ֽ��õ����Ӷ��������
	//! \param bToLeaf �Ƿ�ֽ⵽Ҷ����, Ĭ��Ϊfalse
	//! \remarks ���϶�����һ����, ������ֽ⵽Ҷ����, �򴫳���arrGeometry��Ȼ���ܴ��ڸ��϶���(��Ҷ)
	//  ���bToLeaf =true, �򴫳���arrGeometry�п϶�û�� ���϶���
	//! \attention ȡ�����ļ��ζ���ָ������, ��Щָ����Ȼ��ָ��GeoCompound�ڲ����ڴ��ַ, ����ʹ�ú�Ҫdelete;
	//! ��GeoCompound�����仯(������Ӷ���,������յ�)��,��Ҫ��ʹ����Щָ��,��Ϊ�п���ΪҰָ��
	GEOMETRY_APIF UGbool Divide(UGArray<UGGeometry *> &arrGeometry, UGbool bToLeaf=false);

	//! \brief ת��Ϊ�����
	//! \param geoRegion [out] �õ��������
	//! \param nSegmentCount [in] ����������ÿ�εĲ�ֵ�ĵ�����
	//! \return ���������Ӷ���ɹ�,����true��
	//! \remarks �ڲ�ʵ�־��ǰ�GeoCompound�е�ÿһ���Ӷ���ת��ΪRegion,�ټ��뵽geoRegion���ò����С�
	virtual GEOMETRY_APIF UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;		
	
	//! \brief ת��Ϊ�߶���
	//! \param geoLine [out] �õ����߶���
	//! \param nSegmentCount [in] ����������ÿ�εĲ�ֵ�ĵ�����
	//! \return �߶�������Ӷ���ɹ�,����true��
	//! \remarks �ڲ�ʵ�־��ǰ�GeoCompound�е�ÿһ���Ӷ���ת��ΪLine,�ټ��뵽geoLine���ò����С�
	virtual GEOMETRY_APIF UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;	

	virtual GEOMETRY_APIF UGint GetDataSize() const;

#if PACKAGE_TYPE==PACKAGE_UGC
public:			
	//! \brief ��GeoCompound�в�Ϊ�����ε��ߺ���״���ζ�����뵽�����Ͳ��С�
	//! \param geoLine [out] ȡ�����ݵ��߶���
	//! \param nSegmentCount [in] ����ת��Ϊ��,ÿһ�εĲ�ֵ������
	//! \return �����Ӷ���ɹ�,����true��
	GEOMETRY_APIF UGbool GetLine(UGGeoLine &geoLine, UGint nSegmentCount) const;    

	//! \brief ��GeoCompound����������ΪGeoRegion���Ӷ������ӵ������Ͳ����з��ء�
	//! \param geoRegion [out] ��GeoCompound��ȡ������ΪGeoRegion�������Ͳ�����
	//! \return �Ӷ������ӳɹ�,����true��
	GEOMETRY_APIF UGbool GetRegion(UGGeoRegion &geoRegion) const;    

	//! \brief ����XML��ʽ����Ϣ
	//! \param versionType GML�İ汾
	//! \param nPace �����Ŀո���Ŀ,ʹ��xml�ַ������������˹��Ķ�; 
	//! ��Ҫ����������ص�xml�ַ�����һ�����ǩ�е�һ����, ͨ��ָ���ո���Ŀ,����ʹ�������
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual GEOMETRY_APIF UGString ToXML(GMLVersionType versionType, UGint nPace = 0) const;
	
	//! \brief ��XML�ַ���������Geometry
	//! \param strXML xml��ʽ�ַ���
	//! \param versionType xml�ַ�����GML�汾
	//! \return ת���ɹ�������TRUE
	virtual GEOMETRY_APIF UGbool FromXML(const UGString& strXML, GMLVersionType versionType);
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//! \brief ��OgdcElement ���� UGGeoCompound
	//! \return ����ɹ�������TRUE
	virtual GEOMETRY_APIF UGbool FromElement(const OgdcElement* pElement);

	//! \brief UGGeoCompound ���� ��OgdcElement
	//! \return ����ɹ�������TRUE
	virtual GEOMETRY_APIF UGbool ToElement(OgdcElement*& pElement)  const;
#endif
	
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
	GEOMETRY_APIF void CalAssistantPoints(const UGPoint2D* pPoints,UGint nPntCount,UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,UGEditType::EditToolShape nEditType);


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

	
	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ end

	//! \brief ���ü��ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���
	virtual GEOMETRY_APIF void SetTextCharset(UGString::Charset nCharset);

	//! \brief �ı伸�ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���,ת���ַ�������
	virtual GEOMETRY_APIF void ChangeTextCharset(UGString::Charset nCharset);

#endif // end declare ugc sdk
protected:
	//! \brief ���㷶Χ
	virtual GEOMETRY_APIF UGRect2D ComputeBounds() const;
	
	//virtual GEOMETRY_APIF UGRect2D GetBoundsInside() const;
	
	//virtual GEOMETRY_APIF void SetBoundsInside( const UGRect2D & rcBounds );
	
	//! \brief �ռ�����д��Stream
	virtual GEOMETRY_APIF UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	
	//! \brief ��Stream���ؿռ�����
	virtual GEOMETRY_APIF UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );
	
private:
	//! \brief ������ż��ζ���(��Ϊ�Ӷ��󿴴�)ָ�������
	UGArray< UGGeometry* > m_GeometryArray;
};

}



#endif 

