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
// �ļ�����			SmPrjFactory.h
// ��  ����			UGPrjFactory
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		��׼���͵� ͶӰ����ϵ��
//							   ��������ϵ��
//							   ��ز���ϵ��
//							   ��λ��
//							   �����塢
//							   ���뾭��
//                   �����칤��
//                  
// ����˵����	1��	������CreateObjectϵ�к���,����ID�źͶ�����ָ�룬���ܵõ�
//                  ��Ҫ�����ֶ���

//                  ����:���д���õ���һ����׼UTMͶӰ����ϵ
//					UGPrjCoordSys PrjCoordSys;
//					UGPrjFactory::CreateOjbect(PCS_WGS_1984_UTM_1N,&PrjCoordSys);
//				2�� ���಻�����������ò���	
/*-------------------------------------�汾����---------------------------
V 0.92
��    �ߣ��������ߣ����޸��ߣ�����
������ڣ�
����˵����

V 0.91
��    �ߣ��������ߣ����޸��ߣ�����
������ڣ�
����˵����

V 0.9 
ԭ����  ��������
������ڣ�
========================================================================*/

#if !defined(AFX_SMPRJFACTORY_H__F6CA93D6_6D2B_47F0_9CD3_5CB0E1C0D27A__INCLUDED_)
#define AFX_SMPRJFACTORY_H__F6CA93D6_6D2B_47F0_9CD3_5CB0E1C0D27A__INCLUDED_


#include "Projection/UGPjCon.h"
#include "Projection/UGPrjCoordSys.h"
#include "Projection/UGTranslateParams.h"
#include "Toolkit/UGMarkup.h"

namespace UGC{

class PROJECTION_API UGPrjFactory  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGPrjFactory();

#ifdef SYMBIAN60
	~UGPrjFactory();
#else
	virtual ~UGPrjFactory();
#endif

public:
	//! \brief �������������
	static	UGbool CreateObject(EmSpheroidType SpheroidID, UGSpheroid* pSpheroid );
	//! \brief ����ˮƽ�ο�ϵ����
	static  UGbool CreateObject(EmHorizonDatumType HorizonDatumID, 
						UGHorizonDatum* pHorizonDatum);
	//! \brief �������뾭�߶���
	static  UGbool CreateObject(EmPrimeMeridianType PrimeMeridianID, 
					UGPrimeMeridian* pPrimeMeridian );
	//! \brief ����ͶӰ����ϵ����
	static  UGbool CreateObject(EmPrjCoordSysType PrjCoordSysID,
					UGPrjCoordSys* pPrjCoordSys);
	//! \brief  ������������ϵ����
	static  UGbool CreateObject(EmGeoCoordSysType GeoCoordSysID,
					UGGeoCoordSys* pGeoCoordSys);

//	static  UGbool CreateObject(UGlong UnitID,
//					UGUnit* pUnit);
	//! \brief ����ͶӰ��ʽ����
	static  UGbool CreateObject(EmPrjObjectType ProjectionID,
					UGProjection* pProjection);
	//! \brief ������������ϵת������ ��δʵ��
	static  UGbool CreateObject(EmGeoCoordSysType GeoCoordSysID1,
		EmGeoCoordSysType GeoCoordSysID2,UGGeoTransParams& GeoTransParams);
	
	//! \brief added by dongfei 2007-04-02
//	static UGbool FromXML();
//	static UGString ToXML(UGint nVersion = 0);
	//! \brief added by dongfei 2007-04-03
//	static UGString ToXMLGeo(UGint nVersion = 0);
//	static UGString ToXMLPrimeMeridian(UGint nVersion = 0);
//	static UGString ToXMLSpheriod(UGint nVersion = 0);
//	static UGString ToXMLHorizonDatum(UGint nVersion = 0);
//	static UGString ToXMLPrjObj(UGint nVersion = 0);
//	static UGString WriteXML(UGint nVersion = 0);
	//! \brief ��ȡ�����ļ� added by dongfei 2007-04-04
//	static UGString 

};

//extern  PROJECT_API UGMarkup *  GetMarkup();
}//namespace UGC

#endif // !defined(AFX_SMPRJFACTORY_H__F6CA93D6_6D2B_47F0_9CD3_5CB0E1C0D27A__INCLUDED_)

