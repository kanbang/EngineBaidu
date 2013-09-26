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
	//! \brief ��յ�������
	virtual void Clear();
	
	//! \brief �õ�ά��, �̶�Ϊ2
	//! \return �õ�ά��,�̶�Ϊ2
	virtual UGint GetDimension() const;
	
	//! \brief �õ�����, �̶�Ϊ GeoRect
	virtual Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩,��Ϊ���ĵ�
	virtual UGPoint2D GetInnerPoint() const;

	//! \brief �õ����󳤶�
	//! \attention DimensionΪ1or2�Ķ����֧��
	//! \return ���س���
	virtual UGdouble GetLength() const;
	
	//! \brief �õ����
	//! \return �������
	virtual UGdouble GetArea() const;
	
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
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& arrpPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
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
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, double dAngle = 0);
	
	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);

public:
#if !defined OS_ANDROID && !defined IOS
	//! \brief Geometry��Element��ת��
	//! \param pElement,���ص�pElementָ���ں����ڷ����ڴ�,���渺��ɾ������������ڴ�й©
	virtual UGbool ToElement(OgdcElement*& pElement)  const;
	
	//! \brief Geometry��Element��ת��
	//! \param pElement,�����Element������޷�ת���򷵻�False�����򷵻�True
	virtual UGbool FromElement(const OgdcElement* pElement);
#endif
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
	//! \brief ��������ͼƬ����
	//! \param geoPicture [in] ����ͼƬ����
	//! \return ����true��
	UGbool Make(const UGGeoPicture& geoPicture);	
	
	//! \brief �����ĵ�/Size/��ת�Ƕȹ�����ζ���
	//! \param pntCenter	[in] ���ĵ㡣
	//! \param szSize		[in] size��x��Ϊ���,y��Ϊ�߶ȡ�
	//! \param dAngle		[in] ��ת�Ƕȡ�
	//! \param bCopyData	[in] �Ƿ���Copy��ʽ����ImageData��Ϣ��Ĭ��Ϊ������ʽ
	//! \return ����true��
	UGbool Make(UGArray<UGImageData*>& aryImageData, const UGPoint2D &pntCenter, const UGSize2D& szSize, UGdouble dAngle = 0, UGbool bCopyData = TRUE);    
	
	//! \brief �þ��νṹ����ת�Ƕȹ�����ζ���
	//! \param rcRect [in] ���νṹ��
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \param bCopyData	[in] �Ƿ���Copy��ʽ����ImageData��Ϣ��Ĭ��Ϊ������ʽ
	//! \return ����true��
	UGbool Make(UGArray<UGImageData*>& aryImageData, const UGRect2D& rcRect, UGdouble dAngle = 0, UGbool bCopyData = TRUE);	
	
	//! \brief �õ����ĵ㡣
	//! \return �������ĵ㡣
	UGPoint2D GetCenterPoint() const;    
	
	//! \brief �������ĵ㡣
	//! \param pntCenter [in] ���ĵ㡣
	void SetCenterPoint( const UGPoint2D& pntCenter );    
	
	//! \brief �õ��߶ȡ�
	//! \return ���ظ߶ȡ�
	//! \remarks �ø߶Ȳ��ǿ���ȥ�ĸ߶�,����û�н�����ת֮ǰ�ĸ߶ȡ�
	UGdouble GetHeight() const;	
	
	//! \brief ���ø߶ȡ�
	//! \param dHeight [in] Ҫ���õĸ߶ȡ�
	//! \return dHeightС�ڵ���0, ����false��
	UGbool SetHeight( UGdouble dHeight );	
	
	//! \brief �õ���ȡ�
	//! \return ���ؿ�ȡ�
	//! \remarks �ÿ�Ȳ��ǿ���ȥ�Ŀ��,����û�н�����ת֮ǰ�Ŀ�ȡ�
	UGdouble GetWidth() const;
	
	//! \brief ���ÿ�ȡ�
	//! \param dWidth [in] Ҫ���õĿ�ȡ�
	//! \return dWidthС�ڵ���0,����false��
	UGbool SetWidth( UGdouble dWidth );	
	
	//! \brief �õ���ת�Ƕȡ�
	//! \return ������ת�Ƕȡ�
	UGdouble GetAngle() const;    
	
	//! \brief ������ת�Ƕȡ�
	//! \param dAngle [in] Ҫ���õ���ת�Ƕȡ�
	void SetAngle( UGdouble dAngle );    

	//! \brief ���ó���ʱ��
	//! \remarks
	inline void SetDelayTime(UGshort ntime){ m_nDelayTime = ntime; }

	//! \brief ��ȡ����ʱ��
	//! \remarks
	inline UGshort GetDelayTime() const { return m_nDelayTime; }

	//! \brief ת��Ϊ�߶���
	//! \param geoLine[out] �õ����߶���
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��; �������в�������
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;
	
	//! \brief ת��Ϊ�����
	//! \param geoRegion[out] �õ��������
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��; �������в�������
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;

	//! \brief ���Image����
	//! \param pImageData[in] ����ӵ�Image
	//! \return ����Image�ĸ���
	UGint AddImageData(UGImageData* pImageData);

	//! \brief ����Image����
	//! \param nIndex ����Image��������
	//! \param pImageData[in] ����ӵ�Image
	void InsertAtImageData(UGint nIndex, UGImageData* pImageData);

	//! \brief ��ȡ Image ����
	//! \param nIndex Image��������
	//! \return ���ػ�ȡ�� Image ָ��
	UGImageData* GetImageData(UGint nIndex);
	
	//! \brief �Ƴ� Image ָ�룬��ʵ��ɾ������
	//! \param nIndex ���Ƴ��� Image��������
	//! \return ���ر��Ƴ��� Image ָ��
	UGImageData* RemoveImageData(UGint nIndex);

	//! \brief �ͷ� Image ���ݣ�����ڴ�
	//! \param nIndex ���Ƴ��� Image��������
	//! \param nCount �Ƴ�����
	//! \return ����ʣ���Image����
	UGint ReleaseImageData(UGint nIndex, UGint nCount = 1);
	
	//! \brief �ͷ��������ݣ�����ڴ�
	void ReleaseAllImageData();

	//! \brief ��ȡImage����
	UGint GetFrameCount() const;

	//! \brief ��ȡ��ǰ������
	UGint GetCurrentFrame() const;

	//! \brief ���õ�ǰ������
	void SetCurrentFrame(UGint nCurFrame);

	virtual UGint GetDataSize() const;
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
	
public:	
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

protected:

	//! \brief ���㷶Χ
	virtual UGRect2D ComputeBounds() const;
	
	//! \brief �洢��Stream��
	virtual UGbool SaveGeoData(UGStream& stream, 
		UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	
	//! \brief ��Stream������Geometry
	virtual UGbool LoadGeoData( UGStream& stream , 
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE, UGbool bSDBPlus = FALSE );

	//! \brief ����õ������ĸ���������꣬�����Զ���ա�
	//! \param pPoints ���ڷ��ص������ָ�롣
	//! \attention �����߱��뱣֤pPoints�Ŀռ�������㡣
	void GetVertexes(UGPoint2D* pPoints) const;

protected:
	UGArray<UGImageData*> m_aryImageData;
	UGint m_nCurFrame;

	//! \brief ���ĵ�
	UGPoint2D m_pntCenter;
	
	//! \brief ���
	UGdouble m_dWidth;
	
	//! \brief �߶�
	UGdouble m_dHeight;
	
	//! \brief ��ת�Ƕ�
	//! \remarks �Ƕȵ�λ
	UGdouble m_dAngle;

	//! \brief ����ʱ��
	//! \remarks
	UGshort m_nDelayTime;
};

}

#endif // !defined(AFX_UGGEOPICTURE_H__CE2185C5_6495_4227_8A12_809373AC5CE3__INCLUDED_)

