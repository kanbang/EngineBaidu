//========================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 0.9
// ��  �ߣ�			������
// ��  λ��			������ͼ����ɷ����޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//------------------------------------------------------------------------
//��Ȩ����:         ��Ȩ���� 2000-2010 ������ͼ����ɷ����޹�˾����������Ȩ�� 
//	                Copyright (c) 2000-2010 SuperMap Software Co., Ltd. 
//	                All rights reserved
// ��Ҫ������		1. 
//					2. 
//					
//------------------------------------------------------------------------
// �ļ�����			SmRefTranslator.h
// ��  ����			UGRefTranslator
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		����ϵת��������(����ͶӰ�任������ϵ�任)
// ����˵����		
/*-------------------------------------�汾����---------------------------
V 0.92
��    �ߣ��������ߣ����޸��ߣ�����
������ڣ�2002��10��20��
����˵����

V 0.91
��    �ߣ��������ߣ����޸��ߣ�����
������ڣ�2001��7��20��
����˵����

V 0.9 
ԭ����  ��������
������ڣ�
========================================================================*/

#if !defined(UGC_SMREFTRANSLATOR_H__9153EB7D_C880_4A7B_8184_754D69D0FDF0__INCLUDED_)
#define UGC_SMREFTRANSLATOR_H__9153EB7D_C880_4A7B_8184_754D69D0FDF0__INCLUDED_


#include "Toolkit/UGErrorObj.h"

#include "Projection/UGPrjTranslator.h"
#include "Projection/UGGeoTranslator.h"
#include "Stream/ugdefs.h"



namespace UGC{


class PROJECTION_API UGRefTranslator  
{
public:
	enum EmTransType
	{
		//! \brief m_PJCoordSysSrc ͶӰ����-->m_PJCoordSysDes ͶӰ����
		XY1ToXY2	= 0,
		//! \brief m_PJCoordSysSrc ͶӰ����-->m_PJCoordSysDes ����γ����
		XY1ToGeo2	= 1,
		//! \brief m_PJCoordSysSrc ����γ����-->m_PJCoordSysDes ͶӰ����
		Geo1ToXY2	= 2,
		//! \brief m_PJCoordSysSrc ����γ����-->m_PJCoordSysDes ����γ����
		Geo1ToGeo2	= 3,
		//! \brief m_PJCoordSysSrc ͶӰ����-->m_PJCoordSysSrc ����γ����
		XY1ToGeo1	= 4,
		//! \brief m_PJCoordSysSrc ����γ����-->m_PJCoordSysSrc ͶӰ����
		Geo1ToXY1	= 5,
		//! \brief m_PJCoordSysDes ͶӰ����-->m_PJCoordSysDes ����γ����
		XY2ToGeo2	= 6,
		//! \brief m_PJCoordSysDes ����γ����-->m_PJCoordSysDes ͶӰ����
		Geo2ToXY2	= 7
		
	};
	//! \brief Ĭ�Ϲ��캯��
	UGRefTranslator();
#ifdef SYMBIAN60
	~UGRefTranslator();
#else
	virtual ~UGRefTranslator();
#endif
	//! \brief ͨ��Դ�ο�ϵ��Ŀ��ο�ϵ����ο�ϵת��������
	UGRefTranslator(UGSpatialRef* pSpatialRefSrc,UGSpatialRef* pSpatialRefDes);

	//! \brief ��������ת��
	UGbool Translate(UGdouble& x, UGdouble& y, UGdouble& dH,  UGbool bForward = true);
	//! \brief ��������ת��
	UGbool Translate(UGdouble& x, UGdouble& y, UGbool bForward = true);
	//! \brief ��������ת��
	UGbool Translate(UGPoint2D* pPoints, UGlong nPointCount,UGbool bForward = true);
	//! \brief ��������ת��
	UGbool Translate(UGPoint3D* pPoints, UGlong nPointCount,UGbool bForward = true);

	//! \brief ����Ŀ��ο�ϵ�ĵ�������
	//! \remarks ��������Ŀ��ο�ϵΪĳ���ض���������ϵ ��������Ŀ������ϵ�еĵ�������ϵ
	UGint SetGeoCoordSysDes(const UGGeoCoordSys& GeoCoordSysDes);	
	//! \brief ����Դ�ο�ϵ�ĵ�������
	UGint SetGeoCoordSysSrc(const UGGeoCoordSys& GeoCoordSysSrc);

	//! \brief ����Ŀ��ͶӰ����ϵ
	UGint SetPrjCoordSysDes(const UGPrjCoordSys& PrjCoordSysDes);
	//! \brief ��ȡĿ��ͶӰ����ϵ
	const UGPrjCoordSys& GetPrjCoordSysDes();
	
	//! \brief ����ԴͶӰ����ϵ
	UGint SetPrjCoordSysSrc(const UGPrjCoordSys& PrjCoordSysSrc);	
	//! \brief ��ȡԴͶӰ����ϵ
	const UGPrjCoordSys& GetPrjCoordSysSrc();	

	//! \brief ���õ�������ת����ʽ
	void SetGeoTransMethod(EmGeoTransMethod nGeoTransMethod);
	//! \brief ��ȡ��������ת����ʽ
	EmGeoTransMethod GetGeoTransMethod(); 
	//! \brief ��ȡת����״̬
	//! \return lResult = -1;// �����ܵķ���ֵ
	//!		lResult = 0;// Դ����ϵΪ��
	//!		lResult = 1;// Դ����ϵΪͶӰ����ϵ��Ŀ������ϵΪ��
	//!		lResult = 2;// Դ����ϵ��ΪͶӰ����ϵ��Ŀ������ϵΪ��
	//!		lResult = 3;// Դ����ϵ��Ŀ������ϵ��һ����ƽ������ϵ
	//!		lResult = 4;// ��γ�� ==> ��γ��,�ο�ϵת��
	//!		lResult = 5;// ��γ�� ==> ��γ��,����ϵ��ͬ
	//!		lResult = 6;// ��γ�� ==> ͶӰ��ͬʱ�任����ϵ
	//!		lResult = 7; // ��γ�� ==> ͶӰ������ϵ��ͬ
	//!		lResult = 8; // ͶӰ ==> ��γ�ȣ�����ϵ��ͬ
	//!		lResult = 9; // ͶӰ ==> ��γ�ȣ�����ϵ��ͬ
	//!		lResult = 10; // ͶӰ==>ͶӰ������ϵ��ͬ
	//!		lResult = 11; // ͶӰ==>ͶӰ������ϵ��ͬ
	//!		lResult = 12; // ͶӰ==>ͶӰ������ϵ��ͬ������
	//!		lResult = 13; ͶӰ==>ͶӰ������ϵ��ͬ,ͶӰ������ͬ�����굥λ��ͬ
	UGint GetTranslatorSatus();
	//! \brief �Ƿ����ת��
	UGbool IsValid();

	//! \brief ���õ�������ϵת����������
	void SetGeoTransParams (const UGGeoTransParams& GeoTransParams);

	//! \brief ��ȡ��������ϵת����������
	UGGeoTransParams&  GetGeoTransParams ();

	//! \brief ��ȡ��������
	UGint GetParamsCount();
	//! \brief ͨ��������ȡ��������
	UGString GetParamName(UGint nIndex);
	//! \brief ͨ��������ȡ����ֵ
	UGdouble GetParamValue(UGint nIndex);
	//! \brief ͨ�����ƻ�ȡ����ֵ
	UGdouble GetParamValue(const UGString& strName);
	//! \brief ͨ���������ò���ֵ
	UGbool SetParamValue(UGint nIndex,UGdouble dValue);
	//! \brief ͨ���������ò���ֵ
	UGbool SetParamValue(const UGString& strName,UGdouble dValue);

protected:
	UGint Schedule();

protected:
	UGint m_lStatus;
	EmGeoTransMethod m_nGeoTransMethod;

	UGPrjCoordSys  m_PrjCoordSysSrc;
	UGPrjCoordSys  m_PrjCoordSysDes;
	
	UGPrjTranslator m_PrjTranslator1;
	UGPrjTranslator m_PrjTranslator2;
	
	UGGeoTranslator m_GeoTranslator;

	double m_dUnitRatio;// Դ����ϵ��λ��Ŀ������ϵ��λ�ı���
	
//	UGGeoTranslator m_GeoTranslator1;
//	UGGeoTranslator m_GeoTranslator2;
};


}//namespace UGC


#endif // !defined(UGC_SMREFTRANSLATOR_H__9153EB7D_C880_4A7B_8184_754D69D0FDF0__INCLUDED_)

