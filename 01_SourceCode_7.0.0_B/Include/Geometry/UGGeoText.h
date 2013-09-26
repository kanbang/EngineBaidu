/*! \file	 UGGeoText.h
 *  \brief	 �ı�������
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
 *  All Rights Reserved
<<<<<<< UGGeoText.h
 *  \version $Id: UGGeoText.h,v 1.11 2010/03/17 06:16:11 majt Exp $
=======
 *  \version $Id: UGGeoText.h,v 1.11 2010/03/17 06:16:11 majt Exp $
>>>>>>> 1.34.2.1
 */


#ifndef UGGEOTEXT_H
#define UGGEOTEXT_H

#include "Geometry/UGGeometry.h"
#include "Toolkit/UGTextStyle.h"

namespace UGC {

//! \brief �ı��Ӷ���
#ifdef SYMBIAN60
class GEOMETRY_APIC UGSubText 
#else
class GEOMETRY_API UGSubText 
#endif
{
public:
	//! \brief Ĭ�Ϲ��캯��
	GEOMETRY_APIF UGSubText();

	//! \brief �������캯����
	//! \param subText [in] ���е��ı��Ӷ���
	GEOMETRY_APIF UGSubText(const UGSubText& subText);	

	//! \brief ���ı������ַ������й���
	//! \param strText [in] �ı������ַ�����
	//! \param dAngle [in] ��ת�Ƕ�,Ĭ��Ϊ0
	GEOMETRY_APIF UGSubText(const UGString& strText, UGdouble dAngle=0);
	
	//! \brief �õ���ת�Ƕȡ�
	//! \return ������ת�Ƕȡ�
	GEOMETRY_APIF UGdouble GetAngle() const;	

	//! \brief ������ת�Ƕȡ�
	//! \param dAngle [in] ��ת�Ƕȡ�
	GEOMETRY_APIF void SetAngle(UGdouble dAngle);	
	
	//! \brief �õ��ı����ݡ�
	//! \return �����ı����ݡ�
	GEOMETRY_APIF UGString GetText() const;	

	//! \brief �����ı����ݡ�
	//! \param strText [in] �ı����ݡ�
	GEOMETRY_APIF void SetText(const UGString& strText);	
	
	//! \brief ��ֵ������
	//! \param subText [in] ���е��ı��Ӷ���
	GEOMETRY_APIF void operator=(const UGSubText& subText);
	
private:
	// modified by zengzm 2007-4-27 
	//UGint m_nAngle; //! ���ı�����ǣ���λΪ 0.1��, ��ʱ�뷽��
	//! \brief ���ı�����ת�Ƕ�, ��λΪ:��, ��ʱ�뷽��
	//! \remarks �ڴ��и�Ϊdouble,�Ƕȵ�λ,�洢ʱ��SFC���ּ���
	UGdouble m_dAngle;
	
	//! \brief Ԥ��
	//UGint m_nReserved;

	//! \brief �ı������ַ���
	UGString m_strText;
};



//! \brief �ı�������
//! \remarks ���ı�����,�����ж���ı��Ӷ���,ÿ���ı��Ӷ������Լ���ê�����ת�Ƕ�,
//! ���ı��ķ����ͳһ��,ֻ���ı�������һ��.
#ifdef SYMBIAN60
class GEOMETRY_APIC UGGeoText : public UGGeometry
#else
class GEOMETRY_API UGGeoText : public UGGeometry
#endif
{
public:
	//! \brief ���캯��
	GEOMETRY_APIF UGGeoText();

#ifdef SYMBIAN60
	GEOMETRY_APIF UGGeoText(const UGGeoText& geoText);
	GEOMETRY_APIF UGGeoText& operator=(const UGGeoText& geoText);
#endif
	
	//! \brief ��������
	virtual GEOMETRY_APIF ~UGGeoText();
	
public: 
	
	//! \brief ��յ�������
	virtual GEOMETRY_APIF void Clear();
	
	//! \brief �õ�ά��, �̶�Ϊ-1
	virtual GEOMETRY_APIF UGint GetDimension() const;
	
	//! \brief �õ�����,�̶�ΪGeoText
	virtual GEOMETRY_APIF Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \return ���ص�һ���Ӷ����ê��
	virtual GEOMETRY_APIF UGPoint2D GetInnerPoint() const;
	
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
	virtual GEOMETRY_APIF void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, double dAngle = 0);
	
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

	UGSize2D* m_pSize2D;
	
public://��Ҫ����ʵ�ֵķ���
	
	//! \brief ���÷��
	//! \param pStyle ���ָ��
	//! \remarks ���pStyle==NULL,��Geometry�ڲ����ָ�뱻delete; ����Ḵ��һ�ݷ��
	//! �����ı������, ���÷��������,��Ϊ�ı��������Լ���TextStyle
	virtual GEOMETRY_APIF void SetStyle(const UGStyle* pStyle);
	
	virtual GEOMETRY_APIF UGint GetDataSize() const;
public: //! group �����ı�����
	//! \brief ͨ���ı�����/ê��/��ת�Ƕ��������ı�����
	//! \param strText [in] �ı����ݡ�
	//! \param pntAnchor [in] ê�㡣
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \return ����true��
	GEOMETRY_APIF UGbool Make(const UGString& strText, const UGPoint2D& pntAnchor, UGdouble dAngle=0.0);	
	
	//! \brief �����ı�����(�����ı�)
	//! \param strText [in] �ı����ݡ�
	//! \param geoline [in] Ҫ���ߵ��ߡ�
	//! \param bFixedAngle [in] �Ƿ�̶��Ƕȡ�
	//! \param dAngle [in] �̶��Ƕ�ʱ���ı��Ƕȡ�
	//! \return ����ı�Ϊ��,�����߶���Ƿ�,����false��
	GEOMETRY_APIF UGbool Make(const UGString& strText, const UGGeoLine& geoline, 
						UGbool bFixedAngle=FALSE, UGdouble dAngle=0.0);	
	
	//! \brief �����ı�����(Ĭ�Ϸ��)
	//! \param pntAnchor [in] ê��(�ı�����Ķ�λ��)��
	//! \param subText [in] �ı��Ӷ���
	//! \return ����true
	GEOMETRY_APIF UGbool Make(const UGPoint2D& pntAnchor, const UGSubText& subText);	

	//! \brief �����ı�����(ָ�����,���ж���Ӷ���)
	//! \param textStyle [in] �ı����
	//! \param pPoints [in] �ı��Ӷ���Ķ�λ��㴮ָ�롣
	//! \param pSubText [in] �ı��Ӷ����ָ�롣
	//! \param nSubCount [in] �ı��Ӷ������Ŀ��
	//! \return ����true��
	GEOMETRY_APIF UGbool Make(const UGTextStyle& textStyle, const UGPoint2D* pPoints, const UGSubText* pSubText, UGint nSubCount);	

	//! \brief ͨ�����ƹ����ı�����
	//! \param geotext [in] ���е��ı�����
	//! \return ����true��
	GEOMETRY_APIF UGbool Make(const UGGeoText& geotext);	
	
	//! \brief �����ı��Ӷ���
	//! \param strText [in] �ı����ݡ�
	//! \param pntAnchor [in] �Ӷ����ê�㡣
	//! \param dAngle=0.0 [in] �Ӷ������ת�Ƕȡ�
	//! \return ����true��
	GEOMETRY_APIF UGbool AddSub(const UGString& strText, const UGPoint2D& pntAnchor, UGdouble dAngle=0.0);	

	//! \brief �����ı��Ӷ���
	//! \param pntAnchor [in] ê�㡣
	//! \param subText [in] �ı��Ӷ���
	//! \return ����true��
	GEOMETRY_APIF UGbool AddSub(const UGPoint2D& pntAnchor, const UGSubText& subText);	

	//! \brief �����ı��Ӷ���
	//! \param nIndex [in] �����λ��������
	//! \param strText [in] �ı����ݡ�
	//! \param pntAnchor [in] ê�㡣
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \return 
	GEOMETRY_APIF UGbool InsertSub(UGint nIndex, const UGString& strText, const UGPoint2D& pntAnchor,UGdouble dAngle);	

	//! \brief �����ı��Ӷ���
	//! \param nIndex [in] �����λ��������
	//! \param pntAnchor [in] ê�㡣
	//! \param subText [in] �ı��Ӷ���
	//! \return ��
	GEOMETRY_APIF UGbool InsertSub(UGint nIndex, const UGPoint2D& pntAnchor, const UGSubText& subText);	
	
	//! \brief ɾ���ı��Ӷ���
	//! \param nIndex [in] Ҫɾ�����Ӷ���λ��������
	//! \return �����Ƿ�,����false��
	GEOMETRY_APIF UGbool DelSub(UGint nIndex);	
	
	//! \brief �����ı��Ӷ���
	//! \param nIndex [in] ���õ�������
	//! \param strText [in] �ı����ݡ�
	//! \param pntAnchor [in] ê�㡣
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \return ��
	GEOMETRY_APIF UGbool SetSub(UGint nIndex, const UGString& strText, 
				const UGPoint2D& pntAnchor, UGdouble dAngle=0.0);	
	
	//! \brief �����ı��Ӷ���
	//! \param nIndex [in] ���õ�������
	//! \param pntAnchor [in] ê�㡣
	//! \param subText [in] �ı��Ӷ���
	//! \return ��
	GEOMETRY_APIF UGbool SetSub(UGint nIndex, const UGPoint2D& pntAnchor, const UGSubText& subText);	
	
	//! \brief �õ��ı��Ӷ���
	//! \param nIndex [in] λ��������
	//! \return �����ı��Ӷ���
	const GEOMETRY_APIF UGSubText& GetSub(UGint nIndex) const {return m_SubTexts[nIndex];}	

	//! \brief �õ��ı��Ӷ���
	//! \param nIndex [in] λ��������
	//! \return �����ı��Ӷ���
	GEOMETRY_APIF UGSubText& GetSub(UGint nIndex) {return m_SubTexts[nIndex];}
	
	//! \brief �õ��ı��Ӷ����ê�㡣
	//! \param nIndex [in] Ҫ�õ��Ӷ����λ��������
	//! \return ����ê�������á�
	const GEOMETRY_APIF UGPoint2D& GetSubAnchor(UGint nIndex) const {return m_Points[nIndex];}	

	//! \brief �õ��ı��Ӷ����ê�㡣
	//! \param nIndex [in] Ҫ�õ��Ӷ����λ��������
	//! \return ����ê�������á�
	GEOMETRY_APIF UGPoint2D& GetSubAnchor(UGint nIndex) {return m_Points[nIndex];}
	
	//! \brief �����ı����
	//! \param textStyle [in] �ı����
	GEOMETRY_APIF void SetTextStyle(const UGTextStyle& textStyle, UGbool bChangeSubTextAngle = false);	

	//! \brief �õ��ı����
	//! \return �����ı����
	const GEOMETRY_APIF UGTextStyle& GetTextStyle() const;	
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
	GEOMETRY_APIF UGString GetIndexString() const;		
	
	//! \brief ת��Ϊ�߶���
	//! \param geoLine[out] �õ����߶���
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��
	//! \remarks �ı������޷�ת��,�̶�����false
	//! \return ����false
	virtual GEOMETRY_APIF UGbool ConvertToLine( UGGeoLine &geoLine, UGlong nSegmentCount = 0 ) const;
	
	//! \brief ת��Ϊ�����
	//! \param geoRegion[out] �õ��������
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��
	//! \remarks �ı������޷�ת��,�̶�����false
	//! \return ����false
	virtual GEOMETRY_APIF UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGlong nSegmentCount = 0 ) const;

#if PACKAGE_TYPE==PACKAGE_UGC
		
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


	//! \brief ����������ʱ�ĸ����㣬���ص��ǵ����Ŀ,nHandleType���ص��Ǹ����������,�ο�UGEditType::EditHandleType
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param eAssistantPoints �㴮,���صĸ�����㴮
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	 virtual GEOMETRY_APIF void CalAssistantPoints(const UGPoint2D* pPoints,UGint nPntCount,UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,UGEditType::EditToolShape nEditType);

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

#if !defined _UGUNICODE
	//! \brief ���ü��ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���
	virtual GEOMETRY_APIF void SetTextCharset(UGString::Charset nCharset);

	//! \brief �ı伸�ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���,ת���ַ�������
	virtual GEOMETRY_APIF void ChangeTextCharset(UGString::Charset nCharset);
#endif
private: //! �ڲ���������
	//! \brief �ı�ͷ
	UGTextStyle m_textStyle;
	
	//! \brief �Ӷ���λ��
	UGArray<UGPoint2D> m_Points;
	
	//! \brief �Ӷ�������
	UGArray<UGSubText> m_SubTexts;
	
protected: //! ������Ҫʵ�ֵ�һЩ����������
	//! \brief 
	virtual GEOMETRY_APIF UGRect2D ComputeBounds() const;
	/*virtual GEOMETRY_APIF UGRect2D GetBoundsInside() const;
	virtual GEOMETRY_APIF void SetBoundsInside(const UGRect2D & rcBounds);*/
	
	//! \brief �洢��Stream��
	virtual GEOMETRY_APIF UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE)  const;
	//! \brief ��Stream������Geometry
	virtual GEOMETRY_APIF UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );
	
private:
	//! \brief ����һ���Ӷ����Bounds
	//! \param bConsiderRotation : �Ƿ�����ת
	//! \param bAlignOffset : �Ƿ���Align == 3,4,5 ʱ, �ı���ʾλ�õ�ƫ��	
	UGRect2D ComputeSubBounds(UGint nSubIndex, 
		UGbool bConsiderRotation=true, UGbool bAlignOffset=false) const;
	
	//! \brief �����ı���Bounds�������Ѿ��ṩ�㹻�����Ϣ��
	static UGRect2D ComputeTextBounds(const UGString& strText,
		double dFontHeight, double dFontWidth, 
		const UGPoint2D& pntAnchor, 
		UGint nAlign, double dRadian=0, UGbool bAlignOffset=false);
	
	//! \brief �����ı����뷽ʽ������ƫ��
	//! \remarks ���뷽ʽΪ3 4 5 ʱ��������������룬����Baseline
	static UGRect2D AlignOffset(const UGRect2D& rcBounds, 
		UGint nAlign, double dFontHeight);
	
	// �ı��� Align == 3 4 5 ʱ, ��ʾ�����Ǿ��е�, ����BaseLine, 
	// ��ʾλ��Ҫ���� ƫ��һЩ, ������һ��ͳһ�ĺ�������ƫ�Ʊ���
	static double GetTextAlignOffset(UGbyte nAlign, double dFontHeight);
	
	//! \brief �õ��һ�е��ַ�����,  �������ַ���������
	//! \return ����ֵ:	UGSize::cx = �һ�е��ַ�����
	//!					UGSize::cy = �����ַ���������	
	static UGSize GetTextSize(const UGString& strText);
	
	//!  ������, ������ת֮��ľ���
	//! \param bAlign: ���뷽ʽ, ͬbCenterType
	//! \param dRadian: ��λ�ǻ���
	static UGRect2D UnionRotate(const UGRect2D& rcBounds, UGbyte bAlign, UGdouble dRadian); 
	
	//! \brief ��תһ��Rect2D�����ͨ��pPntResult���أ�pPntResult������4����Ŀռ�
	static void RotateRect(const UGRect2D& rcBounds, UGbyte bCenterType, UGdouble dRadian,
							UGPoint2D *pPntResult);
	
	//! \brief ��ȡ�Ӷ���ı߽��
	void GetVertexes(UGint nIndex, UGPoint2D* pPoints) const;
};

}

#endif

