// UGGeoPyramid.h: interface for the UGGeoPyramid class.
//
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGGeoPyramid.h
//!  \brief ��׶�����塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author ���񻪡�
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOPYRAMID_H__A3248C65_DD9E_4FC6_BC02_3699C9D43C09__INCLUDED_)
#define AFX_UGGEOPYRAMID_H__A3248C65_DD9E_4FC6_BC02_3699C9D43C09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry3D/UGGeometry3D.h"

namespace UGC
{
class GEOMETRY3D_API UGGeoPyramid : public UGGeometry3D  
{
public:
	//! \brief ���캯����
	UGGeoPyramid();

	//! \brief ����������
	virtual ~UGGeoPyramid();
public: //pure virtual 

	//! \brief ��յ�������
	virtual void Clear();

	//! \brief �õ�ά��, ��Ϊ0ά, ��/���ߵ�Ϊ1ά, ��/�����Ϊ2ά, GeoCompound/GeoText��Ϊ-1�������ݿ�洢ʱ��
	virtual UGint GetDimension() const;

	//! \brief �õ�����, �̶�ΪGeoCircle
	virtual Type GetType() const;

	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩, ��ΪԲ��
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
    
	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false	
	virtual UGbool HitTest3D( const UGPoint3D &pntHitTest, UGdouble dTolerance) const;
	
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	//! \attention ��Բ�޷���������ͬ��������, ���dRatioX��dRatioY������Ȳ���
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief ����
	//! \param dRatio ���ű���(X,Y������ͬ)
	virtual void Inflate( UGdouble dRatio);

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
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dCos, UGdouble dSin, UGdouble dAngle);
		
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
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

	//! \brief ��ȡ���ݴ洢ʱ�Ĵ�С
	//! \return ���ش洢��С
	//! \remarks ��δ���Ǳ����������SaveGeoData()һ��ά��
	//! \attention �ַ����ĳ���Ҫ+4
	virtual UGint GetDataSize() const;
public:
#ifndef IOS3D
	//! \brief Geometry��Element��ת��
	//! \param pElement,���ص�pElementָ���ں����ڷ����ڴ�,���渺��ɾ������������ڴ�й©
	virtual UGbool ToElement(OgdcElement*& pElement)  const;
	
	//! \brief Geometry��Element��ת��
	//! \param pElement,�����Element������޷�ת���򷵻�False�����򷵻�True
	virtual UGbool FromElement(const OgdcElement* pElement);
#endif
public:
	//! \brief ת��Ϊ�߶���
	//! \param geoLine[out] �õ����߶���
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;
	
	//! \brief ת��Ϊ�����
	//! \param geoRegion[out] �õ��������
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;
public:	
	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator ͶӰת����
	//! \param bForward ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);

	
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
	
	//! \brief �������ƶ���
	//! \param geoCircle ���ж���
	//! \return ���ж���Ƿ�, ����false
	UGbool Make(const UGGeoPyramid& geoPyramid);

	//! \brief ͨ��Բ�ĺͰ뾶������Բ��
	//! \param pntCenter [in] Բ�ġ�
	//! \param dRadius [in] �뾶��
	//! \return �뾶С��0, ����false��
	UGbool Make(const UGPoint3D &pntCenter, const UGSize2D &szSize, UGdouble dHeight, UGdouble dAngle);    

	//! \brief ���㹲Բ�ķ�ʽ��Բ��
	//! \param pnt1 [in] ��һ���㡣
	//! \param pnt2 [in] �ڶ����㡣
	//! \param pnt3 [in] �������㡣
	//! \return ��������ͬһ��ֱ����, ����false��
	UGbool Make(const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3);    

	//! \brief ����(ֱ���ϵ�����)��Բ��
	//! \param pnt1 [in] ��һ���㡣
	//! \param pnt2 [in] �ڶ����㡣
	//! \return ����true��
	UGbool Make(const UGPoint2D& pnt1, const UGPoint2D& pnt2);    

	//! \brief �õ�Բ�ġ�
	//! \return ����Բ�ġ�
	UGPoint3D GetCenterPoint();    

	//! \brief �����׶�ĸ߶�(y)��
	//! \return �߶�(y)��
	UGdouble GetPyramidHeight() const;	

	//! \brief ������׶�ĸ߶�(y)��
	//! \param dHeight �߶�(y)[in]��
	//! \return �Ƿ�Ϸ���
	UGbool SetPyramidHeight( UGdouble dHeight );	

	//! \brief �����׶�Ŀ��(x)��
	//! \return ���(x)����
	UGdouble GetPyramidWidth() const;
	
	//! \brief ������׶�Ŀ��(x)��
	//! \param dWidth ���(x)[in]��
	//! \return �Ƿ�Ϸ���
	UGbool SetPyramidWidth( UGdouble dWidth );	

	//! \brief �����׶�ĳ���(z)��
	//! \return ����(z)��
	UGdouble GetPyramidLength(void);

	//! \brief ������׶�ĳ���(z)��
	//! \param dWidth ����(z)[in]��
	//! \return �Ƿ�Ϸ���
	UGbool SetPyramidLength( UGdouble dLength );

public:

	//! \brief ��ñ༭����ľ������Ŀ
	//! \remarks ���ڹ̶��������Ϊ9�����˸ı��С��8�����Ƶ��һ����ת���Ƶ�
     virtual UGint  GetHandleCount();

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

	//! \brief ��ö��㴮��
	//! \param pPoints �㴮[out]��
	void GetVertexes(UGPoint2D* pPoints) const;	

	//!\brief �õ�Boundingbox
	virtual  UGBoundingBox ComputeBoundingBox() const;

private:
	//! \brief ���(x)��
	UGdouble m_dPyramidWidth;   

	//! \brief �߶�(y)��
	UGdouble m_dPyramidHeight;  

	//! \brief ����(z)��
	UGdouble m_dPyramidLength;  
	
	//! \brief ��ת�Ƕȡ�
	UGdouble m_dAngle;
};
}
#endif // !defined(AFX_UGGEOPYRAMID_H__A3248C65_DD9E_4FC6_BC02_3699C9D43C09__INCLUDED_)

