// UGGeoEllipsoid.h: interface for the UGGeoEllipsoid class.
//
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGGeoEllipsoid.h
//!  \brief ���򼸺��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author ���񻪡�
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOELLIPSOID_H__FF022F33_ED20_4A1F_B0ED_7FAB12182C22__INCLUDED_)
#define AFX_UGGEOELLIPSOID_H__FF022F33_ED20_4A1F_B0ED_7FAB12182C22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry3D/UGGeometry3D.h"

namespace UGC
{
class GEOMETRY3D_API UGGeoEllipsoid : public UGGeometry3D  
{
public:
	//! \brief ���캯����
	UGGeoEllipsoid();

	//! \brief ����������
	virtual ~UGGeoEllipsoid();
public:
	//! \brief ��յ�������
	virtual void Clear();
	
	//! \brief �õ�ά��, ��Ϊ0ά, ��/���ߵ�Ϊ1ά, ��/�����Ϊ2ά, GeoCompound/GeoText��Ϊ-1�������ݿ�洢ʱ��
	virtual UGint GetDimension() const;
	
	//! \brief �õ�����, �̶�Ϊ GeoEllipse
	virtual Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \remarks ��Ϊ��ԲԲ��
	virtual UGPoint2D GetInnerPoint() const;

	//! \brief �õ����󳤶�
	//! \attention DimensionΪ1�Ķ����֧��
	//! \return ���س���
	virtual UGdouble GetLength() const;

	//! \brief �õ��������
	//! \return �������
	virtual UGdouble GetArea() const;

	
	//! \brief �õ��������
	//! \return �������
	virtual UGdouble GetArea3D() const;
	
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
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid()const;
	
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief ����
	//! \param dRatio ���ű���(X,Y������ͬ)
	virtual void Inflate( UGdouble dRatio);

	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	//! \param dRatioY Z�������ű���
	//! \remarks M������
	virtual void Inflate3D( UGdouble dRatioX, UGdouble dRatioY, UGdouble dRatioZ);
	
	//! \brief ����
	//! \param dRatio ���ű���(X,Y,Z��ͬ)
	virtual void Inflate3D( UGdouble dRatio);
	
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

	//! \brief ��ά������ת
	//! \param vecAxis [in] ��ת�� ��ԭ��
	//! \param dAngle [in] ��ת�Ƕ�
	virtual void Rotate3D(const UGVector3d& vecAxis, UGdouble dAngle);

	
	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);

	//! \brief ����geometry���ͣ��ٵ��ø��Ե�make����ȥʵ�֡�
	//! \param pGeometry [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ����ɹ�����true��
	virtual UGbool MakeWithGeometry(const UGGeometry* pGeometry);	

	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \remarks б��Բresize��, ���ܲ�����ȫ����µ�bounds; 
	//!			 �ټ���õ���BoundsҲ�п��ܲ�����resize�Ĳ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

	//! \brief ��ȡ���ݴ洢ʱ�Ĵ�С
	//! \return ���ش洢��С
	//! \remarks ��δ���Ǳ����������SaveGeoData()һ��ά��
	//! \attention �ַ����ĳ���Ҫ+4
	virtual UGint GetDataSize() const;
public:
#if !defined (IOS3D)
	//! \brief Geometry��Element��ת��
	//! \param pElement,���ص�pElementָ���ں����ڷ����ڴ�,���渺��ɾ������������ڴ�й©
	virtual UGbool ToElement(OgdcElement*& pElement)  const;
	
	//! \brief Geometry��Element��ת��
	//! \param pElement,�����Element������޷�ת���򷵻�False�����򷵻�True
	virtual UGbool FromElement(const OgdcElement* pElement);
#endif
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

	
public:
	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator ͶӰת����
	//! \param bForward ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	virtual void PJConvert( UGRefTranslator *pRefTranslator, UGbool bForward = true);

	//! \brief ������άͶӰ����ϵͳת��
	//! \attention ��δʵ�֡�
	virtual void PJConvert3D( UGRefTranslator *pPJTranslator, UGbool bForward = true);	
	

	
	//! \brief �Ӿ�γ����ϵͳת��ΪͶӰ����ϵͳ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJForward( UGPrjCoordSys *pCoordSys );

	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );

	//! \brief �Ӿ�γ����ϵͳת��Ϊ��άͶӰ����ϵͳ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJForward3D( UGPrjCoordSys *pCoordSys );
	
	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����ϵ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJInverse3D( UGPrjCoordSys *pCoordSys );


public:
	//! \brief ���ǻ��ֹ����ɼ���ģ�ͣ�����һ����
	//! \param nStacks [in] ����ּ��ݡ�
	//! \param nSlices [in] ����ּ��Ρ�
	//! \return ����ģ��ָ�롣
	//! \remarks ��
	//! \attention ��
	UGGeoModel* GetModel(UGint nStacks, UGint nSlices);

	//! \brief �õ�ģ�������
	virtual UGdouble GetVolume();

	//! \brief �õ���ά���ζ�����ڵ�
	virtual UGPoint3D GetInnerPoint3D() const;

	//! \brief ��Բ��/������/�̰���/��ת�Ƕ�������б��Բ��
	//! \param pntCenter [in] Բ�ġ�
	//! \param dSemiMajorAxis [in] �����ᡣ
	//! \param dSemiMinorAxis [in] �̰��ᡣ
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \return �������̰���С��0ʱ,����false��
	UGbool Make(const UGPoint2D &pntCenter, UGdouble dPriAxis, 
				UGdouble dSecAxis, UGdouble dThiAxis,  UGdouble dAngle = 0,UGdouble z = 0);	
	
	//! \brief �þ��κ���ת�Ƕ�������б��Բ
	//! \param rect [in] ���Ρ�
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \return ����true��
	//! \remarks ����ķ�ʽ��: ���þ��ι��������Բ, Ȼ������ת�����ĽǶȡ�
//	UGbool Make(const UGRect2D &rect, UGdouble dHeight, UGdouble dAngle = 0);    
	
	//! \brief �����е�б��Բ��������б��Բ��
	//! \param geoEllipse [in]���е�б��Բ��
	//! \return ����true��
	UGbool Make(const UGGeoEllipsoid &geoEllipsoid);     
	
	//! \brief �õ�Բ�ġ�
	//! \return ����Բ�ġ�
	UGPoint3D GetCenterPoint();    

	//! \brief �õ����ᣨX�ᣩ��
	//! \return ���ذ��ᣨX�ᣩ��	
	UGdouble GetPriAxis();    
	
	//! \brief ���ð��ᣨX�ᣩ��
	//! \param dSemiMajorAxis [in] ���ᣨX�ᣩ��
	//! \return ����С��0, ����false
	UGbool SetPriAxis( UGdouble dPriAxis );    
	
	//! \brief �õ����ᣨZ�ᣩ��
	//! \return ���ذ��ᣨZ�ᣩ��
	UGdouble GetSecAxis();    
	
	//! \brief ���ð��ᣨZ�ᣩ��
	//! \param dSemiMinorAxis [in] ���ᣨZ�ᣩ��
	//! \return ����С��0, ����false��
	UGbool SetSecAxis( UGdouble dSecAxis );    

	//! \brief �õ����ᣨY�ᣩ��
	//! \return ���ذ��ᣨY�ᣩ��
	UGdouble GetThiAxis();

	//! \brief ���ð��ᣨY�ᣩ��
	//! \param dSemiMinorAxis [in] ���ᣨY�ᣩ��
	//! \return ����С��0, ����false��
	UGbool SetThiAxis( UGdouble dThiAxis );

	//! \brief �õ���ת�Ƕȡ�
	//! \return ������ת�Ƕȡ�
	UGdouble GetAngle();    
	
	//! \brief ������ת�Ƕȡ�
	//! \param dAngle [in] ��ת�Ƕȡ�
	void SetAngle(UGdouble dAngle);   
	
protected:
	//! \brief ����Bounds��
	//! \return Bounds��
	virtual UGRect2D ComputeBounds() const;	

	//! \brief ֻ���漸�����ݲ��֡�
	//! \param stream �洢��, ����֮ǰӦ����Open[in]��
	//! \param eCodecType �洢�ı��뷽ʽ[in]��
	//! \param bSDBPlus �Ƿ�洢ΪSDBPlus�ĸ�ʽ[in]��
	//! \return �ɹ�����true,ʧ�ܷ���false��
	//! \remarks ����SDBPlus��������ݿ�����Ĵ洢�ϲ��ϴ�,���Ա���ֱ�ӵ��øú���,
	//! �����ӱ������зֱ���
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const	;
	
	//! \brief ֻת�ؼ������ݲ��֡�
	//! \param stream ��[in]��
	//! \param eCodecType ���뷽ʽ[in]��
	//! \param bSDBPlus �Ƿ�洢ΪSDBPlus�ĸ�ʽ[in] [in]��
	//! \return �ɹ�����true,ʧ�ܷ���false��
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE ,UGbool bSDBPlus = FALSE);	
    
	//!\brief �õ�Boundingbox
	virtual UGBoundingBox ComputeBoundingBox() const;

	//! \brief ��ö��㴮��
	//! \param pPoints �㴮[out]��
	void GetVertexes(UGPoint2D* pPoints) const;	

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

private:
	//! \brief X����
	//! \remarks PriAxis��X��
	UGdouble m_dPriAxis;
	
	//! \brief Z����
	//! \remarks SecAxis��Z��
	UGdouble m_dSecAxis;

	//! \brief Y����
	//! \remarks ThiAxis��Y��
	UGdouble m_dThiAxis;

	//! \brief ��ת�Ƕ�
	//! \remarks �ڴ��и�Ϊdouble,�Ƕȵ�λ,�洢ʱ��SFC���ּ���
	UGdouble m_dAngle;
	
};
}
#endif // !defined(AFX_UGGEOELLIPSOID_H__FF022F33_ED20_4A1F_B0ED_7FAB12182C22__INCLUDED_)

