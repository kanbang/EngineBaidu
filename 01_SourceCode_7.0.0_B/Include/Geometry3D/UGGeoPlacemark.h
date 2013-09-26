//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGGeoPlacemark.h
//!  \brief ��ά�ر����
//!  \author UGCTeam��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOPLACEMARK_H__265A401E_78C8_435F_BEBF_9AFF34F46EFE__INCLUDED_)
#define AFX_UGGEOPLACEMARK_H__265A401E_78C8_435F_BEBF_9AFF34F46EFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Geometry3D/UGGeometry3D.h"
#include "Base3D/UGStyle3D.h"
#include "Toolkit/UGTextStyle.h"

namespace UGC
{
 
//! \brief ��ά�ر����
class GEOMETRY3D_API UGGeoPlacemark : public UGGeometry3D
{
public:
	//! \brief ȱʡ���캯��
	UGGeoPlacemark();

	//! \brief Ĭ����������
	//! \remarks �ڲ�����Clear()��ɡ�
	virtual ~UGGeoPlacemark();	

	//! \brief ��յ�������
	virtual void Clear();
	
	//! \brief �õ����ζ������͡�
	//! \return �̶�Ϊ GeoPlacemark��
	virtual UGGeometry::Type GetType() const;	

	//! \brief �õ�ά�ȡ�
	//! \return �̶�Ϊ-1��
	//! \remarks UGGeoPlacemark�����ά����-1���ڲ�����װ��Geometry��ά����
	virtual UGint GetDimension() const;
	
	//! \brief �õ��ڵ�
	//! \return �����ڵ㣬�̶�Ϊ��(0,0)
	virtual UGPoint2D GetInnerPoint() const;

	//! \brief �õ��ڵ㣬������Geometry3D���ʵ�
	//! \return �����ڵ㣬�̶�Ϊ��(0,0,0)
	virtual UGPoint3D GetInnerPoint3D() const;
	
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

	//! \brief �������м��ζ����ָ�룬��������һ����ά�ر����
	//! \param pGeometry [in] ���м��ζ���ָ�롣
	//! \return ����ɹ�����true��
	//! \remarks �ڲ�����make����ȥʵ�֡�
	virtual UGbool MakeWithGeometry(const UGGeometry* pGeometry);	

	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid() const;
	
	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	//! \remarks ����m_pGeometry���ͣ�������HitTest()��
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
	//! \brief ����
	//! \param dRatioX [in] X�������ű��ʡ�
	//! \param dRatioY [in] Y�������ű��ʡ�
	//! \remarks ��δʵ�֡�
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief ����
	//! \param dRatio [in] ���ű���(X,Y������ͬ)��
	//! \remarks ��δʵ�֡�
	virtual void Inflate( UGdouble dRatio);
	
	//! \brief ƽ�ơ�
	//! \param dX [in] ƽ�Ƶ�Xƫ������
	//! \param dY [in] ƽ�Ƶ�Yƫ������
	//! \remarks ��δʵ�֡�
	virtual void Offset( UGdouble dX, UGdouble dY);
	
	//! \brief ƽ�ơ�
	//! \param dOffset [in] ƫ����(X,Y������ͬ)��
	//! \remarks ��δʵ�֡�
	virtual void Offset( UGdouble dOffset);
	
	//! \brief ƽ��
	//! \param szOffset [in] ƽ�Ƶ�ƫ����(�ֱ���UGSize2D�е�x,y����X,Y�����ƫ����)��
	//! \remarks ��δʵ�֡�
	virtual void Offset( const UGSize2D &szOffset);
	
	//! \brief ��ת
	//! \param pntOrigin [in] ��ת�����ĵ�(ê��,������)��
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \remarks ��δʵ�֡�
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle,double dAngle = 0);
	
	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds [in] �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	//! \remarks ��δʵ�֡�
	virtual UGbool Resize(const UGRect2D& rcNewBounds);
	
	//! \brief ֻ���漸�����ݲ��֡�
	//! \param stream [in] �洢��, ����֮ǰӦ����Open��
	//! \param eCodecType [in] �洢�ı��뷽ʽ��
	//! \param FALSE [in] �Ƿ�洢ΪSDBPlus�ĸ�ʽ��
	//! \return �ɹ�����true,ʧ�ܷ���false��
	//! \remarks ����SDBPlus��������ݿ�����Ĵ洢�ϲ��ϴ�,���Ա���ֱ�ӵ��øú���,�����ӱ������зֱ���
	//! ��δʵ�֡�
	virtual UGbool SaveGeoData(UGStream& stream, 
		UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	
	//! \brief ֻת�ؼ������ݲ���
	//! \param stream [in] �� 
	//! \param eCodecType [in] ���뷽ʽ
	//! \attention ����Ҫ���� UGbool bSDBPlus = FALSE �Ĳ���
	//! \return �ɹ�����true,ʧ�ܷ���false	
	//! \remarks ��δʵ�֡�
	virtual UGbool LoadGeoData( UGStream& stream , 
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );
	
	//! \brief ��Geometry����XML�ַ���
	//! \param versionType [in] GML�İ汾
	//! \param nPace [in] �����Ŀո���Ŀ,ʹ��xml�ַ������������˹��Ķ�; 
	//! ��Ҫ����������ص�xml�ַ�����һ�����ǩ�е�һ����, ͨ��ָ���ո���Ŀ,����ʹ�������
	//! \return ����ָ��GML�汾��xml�ַ���
	//! \remarks ��δʵ�֡�
	virtual UGString ToXML(GMLVersionType versionType, UGint nPace = 0)  const;
	
	//! \brief ��XML�ַ���������Geometry
	//! \param strXML [in] xml��ʽ�ַ���
	//! \param versionType [in] xml�ַ�����GML�汾
	//! \return ����ָ��GML�汾��xml�ַ���
	//! \remarks ��δʵ�֡�
	virtual UGbool FromXML(const UGString& strXML, GMLVersionType versionType);
	
	//! \brief ��������Bounds
	//! \return ���ع̶�ΪUGRect2D(0, 0, 0, 0)
	virtual UGRect2D ComputeBounds() const;	


	//! \brief ���õر���ڲ����ζ���
	//! \param pGeo [in] �µļ��ζ����ָ�롣
	//! \attention �ڲ�ָ��û�ж�pGeo���п������������������겻���ͷţ��Ҳ����Ǿֲ�����ĵ�ַ��
	//! �ͷ����ڲ����
	void SetGeometry(UGGeometry* pGeo);		
	
	//! \brief ��ȡ��GeoPlacemark��Geometry��
	//! \return ��GeoPlacemark��Geometry��
	UGGeometry* GetInnestGeometry();
	
	//! \brief ��ȡ�ر���ڲ����ζ���
	//! \return �ڲ����ζ����ָ�롣
	UGGeometry* GetGeometry();	

	//! \brief ���õر�ĸ������
	//! \param pStyle [in]��
	//! \remarks �ڲ���pStyle���п������ⲿ�����ͷ�pStyle��
	void SetHighLightStyle(const UGStyle3D* pStyle);	
	
	//! \brief ��ȡ�ر�ĸ������
	//! \return �ر��������ָ�롣
	UGStyle3D* GetHighLightStyle();	

	//! \brief ��������GeoPlacemark
	//! \param geoplacemark [in] ���еر����
	//! \return ���еر����Ƿ�, ����false��
	UGbool Make(const UGGeoPlacemark& geoplacemark);	
	
	//! \brief ���õر������
	void SetName(UGString strName);
	
	//! \brief ��õر������
	UGString GetName();
	
	//! \brief �����ڲ����ζ����3D���
	//! \param pStyle3D [in]��
	//! \attention ���ڲ����ζ���Ϊ�ǿ�or�ڲ����ζ�����3D�������pStyle3D���п������ⲿ�����ͷ�pStyle3D��
	virtual void SetStyle3D(const UGStyle3D* pStyle3D);	
	
	//! \brief ��ȡ�ڲ����ζ����3D���
	//! \return �ڲ����ζ������ָ�롣
	//! \attention ���ڲ����ζ���Ϊ��or�ڲ����ζ����3D�����򷵻�null��
	virtual UGStyle3D* GetStyle3D() const;	
	
	//! \brief �����ڲ����ζ���ķ��
	//! \param pStyle [in] ���ָ��
	//! \remarks ���pStyle==NULL,��Geometry�ڲ����ָ�뱻ɾ��; ����Ḵ��һ�ݷ��
	//! �����ı������, ���÷��������,��Ϊ�ı��������Լ���TextStyle
	virtual void SetStyle(const UGStyle* pStyle);

	//! \brief �õ��������ָ��,���û�з���NULL
	//! \return ���ط���ָ��,�п���ΪNULL
	virtual UGStyle* GetStyle() const;
	
	
	//! \brief ���������ֵĵر���ı����
	//! \param textStyle [in] �ı����
	//! \remarks ��������ı�������ʾʱ�������ΪҪ��ʾ���ı��ķ����������geometry�Լ����ı����
	//! \attention �ڲ����ptextStyle���п������ⲿ������ɺ�����ͷš�
	void SetNameTextStyle(const UGTextStyle* ptextStyle);	
	
	//! \brief �õ����ָ��,����ΪNULL
	//! \return ���ڲ����ζ�����GeoText����GeoText3D�����򷵻����ı������������m_pTextStyle��
	UGTextStyle* GetNameTextStyle() const;	
	
	//! \brief �����ڲ����ζ���ΪNULL������δdelete
	void SetGeometryNull();

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

	//! \brief �õ��������������ű��ʣ��������ֻ��ģ�ͺ͹��򼸺���������
	//! \return �������������ű��ʡ�
	UGPoint3D GetScale() const;	

	//! \brief �õ������λ�ã��������ֻ��ģ�ͺ͹��򼸺������壬λ��Ϊģ�͵�����ĵ������ĵ㣨������Ϊ������ڵ㣩
	//! \return �����λ�á�
	virtual UGPoint3D GetPosition() const;

	//! \brief �õ�������������ת�Ƕȣ��������ֻ��ģ�ͺ͹��򼸺���������
	//! \return ������������ת�Ƕȡ�
	UGPoint3D GetRotation() const;

	//! \brief ��ȡ���ݴ洢ʱ�Ĵ�С
	//! \return ���ش洢��С
	//! \remarks ��δ���Ǳ����������SaveGeoData()һ��ά��
	//! \attention �ַ����ĳ���Ҫ+4
	virtual UGint GetDataSize() const;

private:
	
	//! \brief GeoPlacemark��װ�ļ��ζ���
	//! \remarks ����ʹ��GeoPlacemarkʱ����Ҫ��װ������ζ��󣬰�����GeoPlacemark�����ļ������ݡ�
	UGGeometry *m_pGeometry;
	
	//! \brief �ر�ĸ������
	UGStyle3D m_highlightStyle;
	
	//! \brief �ر�����֡�
	UGString m_strName;
	
	//! \brief ��¼�ı�����ڵ���ʾʱ�����õ���
	//! \remarks ��������ı�������ʾʱ�������ΪҪ��ʾ���ı��ķ����������geometry�Լ����ı����
	UGTextStyle* m_pTextStyle;
};

}
#endif // !defined(AFX_UGGEOPLACEMARK_H__265A401E_78C8_435F_BEBF_9AFF34F46EFE__INCLUDED_)


