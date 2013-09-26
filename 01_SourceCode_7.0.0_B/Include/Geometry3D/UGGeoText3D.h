//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGGeoText3D.h 
//!  \brief ��ά�ı����ζ���
//!  \author UGCTeam��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOTEXT3D_H__2D5F3146_41B7_47C7_BAE2_D21CFFCCB499__INCLUDED_)
#define AFX_UGGEOTEXT3D_H__2D5F3146_41B7_47C7_BAE2_D21CFFCCB499__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Geometry3D/UGGeometry3D.h"
#include "Toolkit/UGTextStyle.h"

namespace UGC
{
//! \brief �ı��Ӷ���
class GEOMETRY3D_API UGSubText3D
{
public:
	//! \brief ȱʡ���캯��
	UGSubText3D();
	
	//! \brief Ĭ����������
	~UGSubText3D();

	//! \brief �������캯����
	//! \param subText [in] ���е��ı��Ӷ���
	UGSubText3D(const UGSubText3D& subText);	
	
	//! \brief ���ı������ַ������й���
	//! \param strText [in] �ı������ַ�����
	//! \param dAngle [in] ��ת�Ƕ�,Ĭ��Ϊ0
	UGSubText3D(const UGString& strText, UGdouble dAngle=0.0);
	
	//! \brief �õ���ת�Ƕȡ�
	//! \return ������ת�Ƕȡ�
	UGdouble GetAngle() const;	
	
	//! \brief ������ת�Ƕȡ�
	//! \param dAngle [in] ��ת�Ƕȡ�
	void SetAngle(UGdouble dAngle);	
	
	//! \brief �õ��ı����ݡ�
	//! \return �����ı����ݡ�
	UGString GetText() const;	
	
	//! \brief �����ı����ݡ�
	//! \param strText [in] �ı����ݡ�
	void SetText(const UGString& strText);	
	
	//! \brief ��ֵ������
	//! \param subText [in] ���е��ı��Ӷ���
	void operator=(const UGSubText3D& subText);

private:
	
	//! \brief ���ı�����ת�Ƕ�, ��λΪ:��, ��ʱ�뷽��
	//! \remarks �ڴ��и�Ϊdouble,�Ƕȵ�λ,�洢ʱ��SFC���ּ���
	//! ���ı�����ǣ���λΪ 0.1��, ��ʱ�뷽��
	UGdouble m_dAngle;
	
	//! \brief Ԥ��
	//UGint m_nReserved;
	
	//! \brief �ı������ַ���
	UGString m_strText;
};

//! \brief ��ά�ı����ζ���
class GEOMETRY3D_API UGGeoText3D : public UGGeometry3D
{
public:
	//! \brief ȱʡ���캯��
	UGGeoText3D();

	//! \brief Ĭ����������
	virtual ~UGGeoText3D();

	//! \brief ��յ�������
	virtual void Clear();

	//! \brief �õ����ζ������͡�
	//! \return �̶�Ϊ GeoText3D��
	virtual UGGeometry::Type GetType() const;

	//! \brief �õ��Ӷ���ĸ���
	//! \return ���ظ���
	virtual UGint GetSubCount() const;

	//! \brief �������ж����ָ�룬��������һ��UGGeoText3D��
	//! \param pGeometry [in] �����߶���ָ�롣
	//! \return ����ɹ�����true��
	//! \remarks �ڲ�����make����ȥʵ�֡�
	virtual UGbool MakeWithGeometry(const UGGeometry* pGeometry);	


	//! group �����ı�����
	//! \brief ͨ���ı�����/ê��/��ת�Ƕ��������ı�����
	//! \param strText [in] �ı����ݡ�
	//! \param pntAnchor [in] ê�㡣
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \return ����true��
	UGbool Make(const UGString& strText, const UGPoint3D& pntAnchor, UGdouble dAngle=0.0);	
		
	//! \brief �����ı�����(Ĭ�Ϸ��)
	//! \param pntAnchor [in] ê��(�ı�����Ķ�λ��)��
	//! \param subText [in] �ı��Ӷ���
	//! \return ����true
	UGbool Make(const UGPoint3D& pntAnchor, const UGSubText3D& subText);	
	
	//! \brief �����ı�����(ָ�����,���ж���Ӷ���)
	//! \param textStyle [in] �ı����
	//! \param pPoints [in] �ı��Ӷ���Ķ�λ��㴮ָ�롣
	//! \param pSubText [in] �ı��Ӷ����ָ�롣
	//! \param nSubCount [in] �ı��Ӷ������Ŀ��
	//! \return ����true��
	UGbool Make(const UGTextStyle& textStyle, const UGPoint3D* pPoints, const UGSubText3D* pSubText, UGint nSubCount);	
	
	//! \brief ͨ�����ƹ����ı�����
	//! \param geotext [in] ���е��ı�����
	//! \return ����true��
	UGbool Make(const UGGeoText3D& geotext);	
	
	//! \brief �����ı��Ӷ���
	//! \param strText [in] �ı����ݡ�
	//! \param pntAnchor [in] �Ӷ����ê�㡣
	//! \param dAngle=0.0 [in] �Ӷ������ת�Ƕȡ�
	//! \return ����true��
	UGbool AddSub(const UGString& strText, const UGPoint3D& pntAnchor, UGdouble dAngle=0.0);	
	
	//! \brief �����ı��Ӷ���
	//! \param pntAnchor [in] ê�㡣
	//! \param subText [in] �ı��Ӷ���
	//! \return ����true��
	UGbool AddSub(const UGPoint3D& pntAnchor, const UGSubText3D& subText);	
	
	//! \brief �����ı��Ӷ���
	//! \param nIndex [in] �����λ��������
	//! \param strText [in] �ı����ݡ�
	//! \param pntAnchor [in] ê�㡣
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \return ����true
	UGbool InsertSub(UGint nIndex, const UGString& strText, const UGPoint3D& pntAnchor,UGdouble dAngle=0.0);	
	
	//! \brief �����ı��Ӷ���
	//! \param nIndex [in] �����λ��������
	//! \param pntAnchor [in] ê�㡣
	//! \param subText [in] �ı��Ӷ���
	//! \return ����true��
	UGbool InsertSub(UGint nIndex, const UGPoint3D& pntAnchor, const UGSubText3D& subText);	
	
	//! \brief ɾ���ı��Ӷ���
	//! \param nIndex [in] Ҫɾ�����Ӷ���λ��������
	//! \return �����Ƿ�,����false��
	UGbool DelSub(UGint nIndex);	
	
	//! \brief �����ı��Ӷ���
	//! \param nIndex [in] ���õ�������
	//! \param strText [in] �ı����ݡ�
	//! \param pntAnchor [in] ê�㡣
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \return ����true��
	UGbool SetSub(UGint nIndex, const UGString& strText, 
		const UGPoint3D& pntAnchor, UGdouble dAngle=0.0);	
	
	//! \brief �����ı��Ӷ���
	//! \param nIndex [in] ���õ�������
	//! \param pntAnchor [in] ê�㡣
	//! \param subText [in] �ı��Ӷ���
	//! \return ����true��
	UGbool SetSub(UGint nIndex, const UGPoint3D& pntAnchor, const UGSubText3D& subText);	
	
	//! \brief �õ��ı��Ӷ���
	//! \param nIndex [in] λ��������
	//! \return �����ı��Ӷ���
	const UGSubText3D& GetSub(UGint nIndex) const {return m_SubTexts[nIndex];}	
	
	//! \brief �õ��ı��Ӷ���
	//! \param nIndex [in] λ��������
	//! \return �����ı��Ӷ���
	UGSubText3D& GetSub(UGint nIndex) {return m_SubTexts[nIndex];}

	//! \brief �õ��ı��Ӷ����ê�㡣
	//! \param nIndex [in] Ҫ�õ��Ӷ����λ��������
	//! \return ����ê�������á�
	const UGPoint3D& GetSubAnchor(UGint nIndex) const {return m_Points[nIndex];}	
	
	//! \brief �õ��ı��Ӷ����ê�㡣
	//! \param nIndex [in] Ҫ�õ��Ӷ����λ��������
	//! \return ����ê�������á�
	UGPoint3D& GetSubAnchor(UGint nIndex) {return m_Points[nIndex];}
	
	//! \brief �����ı����
	//! \param textStyle [in] �ı����
	void SetTextStyle(const UGTextStyle& textStyle);	
	
	//! \brief �õ��ı����
	//! \return �����ı����
	const UGTextStyle& GetTextStyle() const;	
	
	//! \remarks 
	//! 1) ȥ��ǰ��� �ո�/�س�����/Tab ���ַ�
	//! 2) �м�� �ո�/�س�����/Tab , ���ǰ���� ����/���� ��, Ҳȥ��
	//! 3) ���ǰ���� Ӣ��(or���ֵ�ACSII��), �� ����һ���ո�(�س�����/Tab��Ҳת��Ϊһ���ո�)
	//! ԭ��: ����ӿھ������� ���� �ַ����Ƚϲ�ѯ��, �� �����ı����ݼ��� ToString ��, 
	//! ���浽�ı��ֶ���, Ȼ�� �û��Ϳ��Ժܷ���� ���ֶ��н��� ����, 
	//! �� ��ͼ����ʾ�� ��Ҫ д��" I am   \r\n a student.   ", �� �û������Ա��в�ѯʱ, 
	//! ֻ��Ҫ ���� "I am a student.", �ﵽ���뼴���� ��Ч��
	//!	��:��" I am   \r\n a student.   " ��Ϊ "I am a student."
    //!					 "Hello, \r�й� "  			  ��Ϊ "Hello,�й�"
    //!					 "Abc\rABC"					  ��Ϊ "Abc ABC"
	//! \return �����ı�����ĺϲ����
	//! \brief ȡ���ı������������(���е��Ӷ�������ִ��ĺϲ�,ȥ���ո񡢻��е�)
	UGString GetIndexString() const;	

	//! \brief ��ȡ���ݴ洢ʱ�Ĵ�С
	//! \return ���ش洢��С
	//! \remarks ��δ���Ǳ����������SaveGeoData()һ��ά��
	//! \attention �ַ����ĳ���Ҫ+4
	virtual UGint GetDataSize() const;
	

public:
	
	//! \brief �õ�ά��
	//! \return ��Ϊ0ά, ��/���ߵ�Ϊ1ά, ��/�����Ϊ2ά, GeoCompound/GeoText��Ϊ-1
	virtual UGint GetDimension() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \return �����ڵ�
	//! \remarks Ϊ���������Ӷ��� ���м��(�м�����ĵ�, �������м����ĵ�)
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief �õ��ڵ㣨������Geometry3D���ʵ㣩
	//! \return �����ڵ�
	virtual UGPoint3D GetInnerPoint3D() const;
	
	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest [in] ��������ѡ�еĵ�
	//! \param dTolerance [in] ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid() const;

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
	
protected:
	//! \brief ��������Bounds
	//! \return ���صõ���Bounds
	virtual UGRect2D ComputeBounds() const;	
	
	//! \brief ֻ���漸�����ݲ���
	//! \param stream [in] �洢��, ����֮ǰӦ����Open
	//! \param eCodecType [in] �洢�ı��뷽ʽ
	//! \param bSDBPlus [in] �Ƿ�洢ΪSDBPlus�ĸ�ʽ
	//! \remarks ����SDBPlus��������ݿ�����Ĵ洢�ϲ��ϴ�,���Ա���ֱ�ӵ��øú���,
	//! �����ӱ������зֱ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool SaveGeoData(UGStream& stream, 
		UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	
	//! \brief ֻת�ؼ������ݲ���
	//! \param stream [in] �� 
	//! \param eCodecType [in] ���뷽ʽ
	//! \attention [in] ����Ҫ���� UGbool bSDBPlus = FALSE �Ĳ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool LoadGeoData( UGStream& stream , 
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );

	//!\brief �õ�Boundingbox
	virtual UGBoundingBox ComputeBoundingBox() const;
	
	
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
	
	//! \brief ת���ɶ����󣬿��԰�3D�㡢3D������ת���ɶ�������ʾ��
	//! \param geoMultiPoint [out] �����㼸�ζ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToPoint( UGGeoMultiPoint &geoMultiPoint) const;	
	
	//! \brief ת����ͼƬ��3D���ͼ��ζ����Լ��û����ͼ��ζ������ͨ����ת����ͼƬ������ʾ��
	//! \param geoPicture [out] ���ͼƬ���ζ���
	//! \param dResolution [in] �ֱ��ʡ�
	//! \param dXAngle [in] ˮƽ��ǡ�
	//! \param dZAngle [in] ��ת��ǡ�
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToPicture( UGGeoPicture &geoPicture, UGdouble dResolution, 
								UGdouble dXAngle = 0, UGdouble dZAngle = 0) const;	

	//��ȡ������λ��
	virtual UGPoint3D GetPosition() const;

	
public:
	//Projection..
	
	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator [in] ͶӰת����
	//! \param bForward [in] ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);
	
	//! \brief �Ӿ�γ����ϵͳת��ΪͶӰ����ϵͳ
	//! \param pCoordSys [in] ͶӰ����ϵͳ
	virtual void PJForward( UGPrjCoordSys *pCoordSys );
	
	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����
	//! \param pCoordSys [in] ͶӰ����ϵͳ
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );
	
	//! \brief ���������õ��Ӷ���λ��
	//! \return ��ά�㡣
	UGPoint3D GetSubPointAt(UGint i) const;

private:
	//! \brief ����һ���Ӷ����Bounds
	//! \param nSubIndex [in] �Ӷ���������
	//! \param bConsiderRotation [in] �Ƿ�����ת��
	//! \param bAlignOffset [in] �Ƿ���Align == 3,4,5 ʱ, �ı���ʾλ�õ�ƫ�ơ�
	//! \return ���ذ�Ҫ�������Bounds��
	UGRect2D ComputeSubBounds(UGint nSubIndex, 
		UGbool bConsiderRotation=true, UGbool bAlignOffset=false) const;
	
	//! \brief �����ı���Bounds�������Ѿ��ṩ�㹻�����Ϣ��
	//! \param strText [in] �ַ�����
	//! \param dFontHeight [in] ����ĸߡ�
	//! \param dFontWidth [in] ����Ŀ�
	//! \param pntAnchor [in] ê�㡣
	//! \param nAlign [in] ���뷽ʽ��
	//! \param dRadian [in] ��λ�ǻ��ȡ�
	//! \param bAlignOffset [in] �Ƿ����ı����뷽ʽ������ƫ�ơ�
	//! \return �ı���Bounds��
	static UGRect2D ComputeTextBounds(const UGString& strText,
		UGdouble dFontHeight, UGdouble dFontWidth, 
		const UGPoint3D& pntAnchor, 
		UGint nAlign, UGdouble dRadian=0, UGbool bAlignOffset=false);

	//! \brief �õ��һ�е��ַ�����,  �������ַ���������
	//! \param strText [in] �ַ�����
	//! \return ����ֵ:	UGSize::cx = �һ�е��ַ�����
	//!					UGSize::cy = �����ַ���������	
	static UGSize GetTextSize(const UGString& strText);	


private: //! �ڲ���������
	
	//! \brief �ı�ͷ
	UGTextStyle m_textStyle;
	
	//! \brief �Ӷ���λ��
	UGArray<UGPoint3D> m_Points;
	
	//! \brief �Ӷ�������
	UGArray<UGSubText3D> m_SubTexts;

};

}

#endif // !defined(AFX_UGGEOTEXT3D_H__2D5F3146_41B7_47C7_BAE2_D21CFFCCB499__INCLUDED_)

