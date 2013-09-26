// UGChartSubLayer.h
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGChartSubLayer.h 
   **************************************************************************************
    \author   �ܽ���
    \brief    ��չ�ĺ�ͼͼ���࣬�������ݼ�������ʾ��ר��ͼ��ʾ��                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2011 SuperMap Software Co., Ltd.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2011-04-13 �ܽ���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGCHARTSUBLAYER_H_)
#define AFX_UGCHARTSUBLAYER_H_

#include "Stream/ugdefs.h"
#include "Toolkit/UGMarkup.h"
#include "Toolkit/UGStyle.h"
#include "Engine/UGDataset.h"
#include "Engine/UGRecordset.h"
#include "FileParser/UGFileParseVector.h"
#include "ChartBase/UGChartLookupTable.h"
#include "ChartBase/UGChartColorTable.h"
#include "ChartBase/UGChartColorMode.h"
#include "ChartBase/UGChartColorTable.h"
#include "ChartBase/UGChartDisplayCategory.h"
#include "Drawing/UGDrawing.h"
#include "Map/UGChartSetting.h"
#include "Map/UGChartLayer.h"
#include "Map/UGMap.h"
#include "ChartToolkit/UGS57DatasetExtInfo.h"

#define  S52DASHLINE 60000998
#define  S52DOTLINE  60000999

#define  TEXT_COLOR _U("CHBLK")
#define  TEXT_BKCOLOR _U("DEPMD")
#define  TEXT_OFFSETUNIT 350    //3.5mm���ı�ƫ�ƵĻ�����λ��10��������ָ�

#define  S52TRANSPARENCYSTEP 25	//ֻ�� 1:25%͸����2:50%͸����3:75%͸��

#pragma once
namespace UGC {

	class MAP_API UGChartSubLayer : public UGLayer
	{
		friend class UGChartSetting;

		// CSP�ڲ�������ͼ������Ҫע���һЩ������Ϣ��
		struct UGCSPInnerLayerInfo{
			UGChartDisplayCategory::UGS52DisplayCategory eDisplayCategory;
			UGlong  bIgnoreMinscale;
			UGint nPriority;

			UGCSPInnerLayerInfo()
			{
				eDisplayCategory = UGChartDisplayCategory::Standard;
				bIgnoreMinscale = false;
				nPriority = 8;
			}
		};

		// CSP�ڲ������ĵ�������Ϣ��
		struct UGCSPPointStyle{
			UGString strSymbol;
			UGCSPInnerLayerInfo innerLayerInfo;

			UGCSPPointStyle()
			{
				strSymbol.Empty();
			}
		};

	public:
		UGChartSubLayer(UGChartLayer *pParentLayer);
		~UGChartSubLayer(void);
		UGChartSubLayer& operator =(const UGChartSubLayer& layer);
	public:
		//! \brief ����ͼ��
		UGbool OnDraw(UGDrawing *pDrawing, UGRecordset *pDisplayRecordset);
		//! \brief ����XML��Ϣ
		UGString ToXML(UGint nVersion = 0)const;
		//! \brief ��ȡXML��Ϣ
		UGbool FromXML(const UGString& strXML, UGint nVersion = 0);

		//! \brief ���������
		void SetFeatureAcronym(const UGString &strFeatureAcronym);

		//! \brief ����������
		void SetFeatureCode(UGint nCode);

		UGint GetFeatureCode();

		//! \brief ���õ�������͵�S52���ұ���Ϣ
		void ResetPointStyleItems();
		//! \brief ������������͵�S52���ұ���Ϣ
		void ResetLineStyleItems();
		//! \brief ������������͵�S52���ұ���Ϣ
		void ResetAreaStyleItems();

		void SetQueryDef(UGQueryDef& QueryDef);

		void ResetLookupItems(UGbool bOnlyResetPoint = false, UGbool bOnlyResetArea = false);

		void SetDataset(UGDataset *pDataset, UGbool bInit = true, UGbool bClearRecordsets = true);

		void SetRecord(UGRecordset *pRecord, UGint nCode);

		void SetArrs(UGArray<UGint>& ArrTagIDs, UGArray<UGint>& ArrSrcIDs, UGArray<UGint>& ArrSrcIDCount, UGint nCode);

		//! \brief ���ÿռ��ϵ
		void SetSpatialRelationship();
		//! \brief ���ÿռ��߹�����ָ�� 
		void SetSpatialLineManger();

		UGLayer* GetParentLayer() const;

		UGDataset* GetDataset();	

	private:

		//! \brief		���ƺ�ͼ���
		//! \remarks	�ӿ�����ֻ�ᴦ��ǰ��¼���������������Ƶ�ָ����¼
		UGbool DrawChartObject(UGRecordset *pRecord, UGFieldInfo& fieldInfo, UGDrawing *pDrawing);

		//! \brief	�����߻����������ĵ����
		//! \param	arrCenterMarkerStyle [in] ���ĵ���ŵķ�����飨���������ɶ�����ű�ʾ��
		//! \param  pGeometry [in] ���ķ���λ�õ����
		void DrawCenterPointMarker(UGArray<UGStyle>& arrCenterMarkerStyle, UGGeometry* pGeometry, UGDrawing *pDrawing);

		// ֽ�ʺ�ͼ�������ĵ����
		void DrawCenterPointMarker(UGArray<UGStyle>& arrCenterMarkerStyle, UGGeometry* pGeometry, 
			                   UGDrawing *pDrawing, UGS57FeatureStyle *pS57FeatureStyle);

		//! \brief	��ȡ���ĵ����λ�õ�
		//! \param	pGeometry ��Ҫ�������ĵ���ŵĶ����������
		//! \return �������ķ���λ�õ㡣 
		UGbool GetCenterPoint(UGGeometry* pGeometry,UGGeoPoint *pCenterPoint, UGDrawing *pDrawing);

		UGbool GetCenterPointPaperChart(UGGeometry* pGeometry,UGGeoPoint *pCenterPoint);

		//! \brief �������ĵ����UGStyle
		//! \param style [out] ��Ҫ���õ�UGStyle
		//! \param symbolMarkerStyle [in] ��ͼ����ŷ��
		//! \param pRecord [in] ��¼��ָ��
		//! \return	�Ƿ���������Ч�ĵ���ŷ��(��Ч�ż������ĵ���ŵķ������)
		UGbool SetObjectMarkerStyle(UGArray<UGStyle>& styles, UGDrawMaker* pDrawMaker, UGArray<UGChartSymbolMarkerStyle>& symbolMarkerStyles, UGRecordset* pRecord);
		//! \brief ���������߷��UGStyle
		//! \param style [out] ��Ҫ���õ�UGStyle
		//! \param strLineSymbolName [in] ��ͼ�������͵ķ�����
		//! \param simpleLineStyle [in] ��ͼ������
		void SetObjectLineStyle(UGStyle& style, UGDrawMaker* pDrawMaker, const UGString& strLineSymbolName, const UGChartLineStyle& simpleLineStyle);
		//! \brief �������������UGStyle
		//! \param style [out] ��Ҫ���õ�UGStyle
		//! \param strAreaPattern [in] ��ͼ���ͼ���ķ�����
		//! \param strAreaColor [in] ��ͼ�����ɫ�ı���
		void SetObjectFillStyle(UGStyle& style, UGDrawMaker* pDrawMaker, const UGString& strAreaPattern, const UGString& strAreaColor, const UGint nTransparency = 0);

		//! \brief		�ڵ�ǰ�������Ƿ�̫Сʹ��겻��ʾ
		//! \remarks	���Ƿ��趨��ʾ����С����������Լ�����SCAMIN�ֶ�ֵ�й�
		UGbool IsMinScaleVisible(UGRecordset *pDisplayRecordset, UGDrawing *pDrawing);
		//! \brief �ڵ�ǰ��ͼ��ʾ����£�����Ƿ���ʾ
		UGbool IsShowOnDisplayCategory(UGChartDisplayCategory::UGS52DisplayCategory eObjectDisplayCategory);

		//! \brief	�����������ų���
		UGbool CallConditionalSymbology(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing,
										UGChartDisplayCategory::UGS52DisplayCategory eObjectDisplayCategory,
										UGS57FeatureStyle *pS57FeatureStyle = NULL);


		UGChartPointObjectStyle* MatchAttribsPoint(UGRecordset *pRecord, UGFieldInfo &fieldInfo/*, UGChartPointObjectStyle** pPointStyle*/);
		UGChartLineObjectStyle* MatchAttribsLine(UGRecordset *pRecord, UGFieldInfo &fieldInfo/*, UGChartLineObjectStyle& lineStyle*/);
		UGChartAreaObjectStyle* MatchAttribsArea(UGRecordset *pRecord, UGFieldInfo &fieldInfo/*, UGChartAreaObjectStyle& areaStyle*/);
		UGbool IsMatchAttribs(UGVariant &valValue, UGFieldInfo &fieldInfo, const UGChartAttributeCondition &attribCondition);
		
		//! DEPARE02�������ų�������㷨
		UGbool CS_DEPARE02(UGRecordset *pRecord, UGGeometry* pGeometry, UGDrawing *pDrawing);
		UGColor CS_SEABED01(UGRecordset *pRecord, UGfloat dfDRVAL1, UGfloat dfDRVAL2, UGString &strFillPattern);
		UGbool CS_SAFCON01(UGfloat dfDepthValue, UGGeometry *pGeo, UGDrawing *pDrawing);

		UGbool CS_LIGHTS05(UGRecordset *pRecord, UGGeometry* pGeometry, UGDrawing *pDrawing);
		UGbool LIGHTS05ContinuationA(UGRecordset *pRecord, UGGeometry* pGeometry, UGDrawing *pDrawing,
									const UGString& strCATLIT, const UGString &strColor);
		UGbool LIGHTS05ContinuationB(UGRecordset *pRecord, UGGeometry* pGeometry, UGDrawing *pDrawing,
									const UGString &strColor,  UGVariant &valSector1, UGVariant &valSector2);

		UGbool CS_LIGHTSPaperChart(UGRecordset *pRecord, UGGeometry* pGeometry, UGDrawing *pDrawing, UGS57FeatureStyle *pS57FeatureStyle);

		void SetGeoTextStyle(UGDrawing *pDrawing, UGChartTextFormat &textFromat, UGGeoText *pGeoText, UGTextStyle &textStyle);

		UGString CS_LITDSN01(UGRecordset *pRecord, const UGString& strCATLIT, const UGString& strColor);


		void LitdsnCategory(const UGString& strCATLIT, UGString &strDescription);
		void LitdsnCharacteristic(UGint &nLITCHR, UGchar cchr[10]);
		UGint LitdsnSigGroup(const UGString& strSIGGRP, UGchar cgrp[10][10]);
		UGint LitdsnColor(const UGString& strColor, UGchar ccol[5][3]);
		UGint LitdsnStatus(const UGString& strSTATUS, UGchar cstat[4][10]);



		UGbool IsExtendRadius(UGuint unFeatureID, UGfloat dfSector1, UGfloat dfSector2);
		UGbool LIGHTS05DrawingSectorLine(UGRecordset *pRecord, UGGeometry* pGeometry, UGDrawing *pDrawing,
										UGfloat dfSector1Agnle, UGfloat dfSector2Angle, UGfloat dfLEGLEN, 
										UGS57FeatureStyle *pS57FeatureStyle = NULL);

		UGbool CS_DEPCNT03(UGRecordset *pRecord, UGGeometry* pGeometry, UGDrawing *pDrawing);

		UGbool CS_QUAPOS01(UGRecordset *pRecord, UGGeometry* pGeometry, UGDrawing *pDrawing);

		UGbool CS_QUALIN01(UGRecordset *pRecord, UGDrawing *pDrawing);
		// �������ֵ�ǿգ����صķ�����SY(LOWACC01)
		UGString CS_QUAPNT02(UGRecordset *pRecord);
		UGbool	IsPointFeatureSpatialAccurate(UGuint unFeatureId);
		UGbool	IsLineRegionFeatureSpatialAccurate(UGuint unFeatureId);

		UGbool CS_SOUNDG02(UGRecordset *pRecord, UGGeometry* pGeometry, UGDrawing *pDrawing);

		UGbool CS_SOUNDG02PaperChart(UGRecordset *pRecord, UGGeometry* pGeometry, UGDrawing *pDrawing, UGS57FeatureStyle *pS57FeatureStyle);

		// ��������ͰѶ�������ˣ� CS_SOUNDG02����
		UGbool CS_SNDFRM03(UGRecordset *pRecord, UGfloat dfDepth, UGStrings &arySymbols);
		
		// �ڵ���������CS_SNDFRM03�ӿں���Ҫ����ShowSNDFRMText�ӿڲ��ܻ���ˮ���ע��
		UGbool ShowSNDFRMText(UGGeometry *pGeometry, UGDrawing *pDrawing, UGfloat dfDepthValue, UGS57FeatureStyle *pS57FeatureStyle = NULL);

		UGbool CS_TOPMAR01(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing);

		//{{ CSP WRECKSnn
		UGbool CS_WRECKS04( UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing,
							UGChartDisplayCategory::UGS52DisplayCategory eObjectDisplayCategory);

		UGbool WRECKS04Point(   UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing,
								UGCSPPointStyle &cspPointStyle, UGbool bShowISODanger, 
								UGbool bScaleVisible, UGbool bDisplayCategory,
								UGStrings arySoundingSymbol, UGfloat dfDepthValue, 
								UGbool bGivenVALSOU, UGfloat dfValsou,
								UGint nCATWRK, UGint nWATLEV,
								const UGString &strLowAccySymbol);

		 UGbool WRECKS04Region( UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing,
								UGCSPPointStyle &cspPointStyle, UGbool bShowISODanger, 
								UGbool bScaleVisible, UGbool bDisplayCategory,
								UGStrings arySymbolsSounding, UGbool bGivenVALSOU,
								UGfloat dfValsou, UGint nWATLEV, UGfloat dfDepthValue, 
								const UGString &strLowAccySymbol);
		
		// ����CS_WRECKS04���������ڲ�������ͼ�㡣
		UGbool CS_WRECKS04Inner(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing);
		//}} CSP WRECKSnn

		UGbool CS_DEPVAL02( UGRecordset *pRecord, UGGeometry *pGeometry, UGint nWATLEV, UGint nEXPSOU, 
							UGfloat &dfLeastDepth, UGfloat &dfSeabedDepth);
		UGbool DEPVAL02GetLeastDepth(UGRecordset *pRecordset, UGint nCode, UGfloat &dfLeastDepth);

		UGbool CS_UDWHAZ04( UGRecordset *pRecord, UGfloat dfDepthValue,
							UGCSPPointStyle &cspPointStyle);

		UGbool UDWHAZ04IsDanger(UGRecordset *pRecordset, UGint nCode, UGbool bNeedDeeper);

		// {{CSP OBSTRNnn
		UGbool CS_OBSTRN06(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing,
							UGChartDisplayCategory::UGS52DisplayCategory eObjectDisplayCategory);
		
		UGbool OBSTRN06ContinuationA( UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing,
									  UGCSPPointStyle &cspPointStyle, UGbool bShowISODanger, 
									  UGbool bScaleVisible, UGbool bDisplayCategory,
									  UGStrings arySoundingSymbol, UGfloat dfDepthValue,
									  UGbool bGivenVALSOU, UGfloat dfValsou,
									  UGbool bGivenWATLEV, UGint nWATLEV,
									  UGint nCATBOS);

		UGbool OBSTRN06ContinuationB( UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing,
									  UGCSPPointStyle &cspPointStyle, UGbool bShowISODanger, 
									  UGbool bScaleVisible, UGbool bDisplayCategory,
									  UGStrings arySoundingSymbol, UGfloat dfDepthValue,
									  UGbool bGivenVALSOU, UGfloat dfValsou);
		
		UGbool OBSTRN06ContinuationC( UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing,
									  UGCSPPointStyle &cspPointStyle, UGbool bShowISODanger, 
			                          UGbool bScaleVisible, UGbool bDisplayCategory,
			                          UGStrings arySoundingSymbol, UGfloat dfDepthValue,
			                          UGbool bGivenVALSOU, UGfloat dfValsou,
			                          UGbool bGivenWATLEV, UGint nWATLEV,
			                          UGint nCATBOS);

		UGbool CS_OBSTRN06Inner(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing);
		// }}CSP OBSTRNnn
		
		UGbool CS_SLCONS03(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing);
		UGbool SLCONS03Point(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing, UGuint unFeatureID);
		UGbool SLCONS03Line(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing, UGuint unFeatureID);

		// {{CSP RESAREnn
		UGbool CS_RESARE03(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing);

		UGbool RESARE03ContinuationA(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing, 
									 const UGString& strRESTRNValue);

		UGbool RESARE03ContinuationB(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing, 
									const UGString& strRESTRNValue);
		
		UGbool RESARE03ContinuationC(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing, 
									const UGString& strRESTRNValue);
		
		UGbool RESARE03ContinuationD(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing, 
									const UGString& strRESTRNValue);

		UGbool RESARE03ContinuationE(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing);
		// }}CSP RESAREnn

		UGbool CS_RESTRN01(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing);

		UGbool CS_RESCSP02(UGRecordset *pRecord, UGGeometry *pGeometry, UGDrawing *pDrawing, const UGString& strRESTRN);
		
		// ���ƿ����������
		UGbool DrawArea( UGGeometry *pGeometry, UGDrawing *pDrawing, 
						 const UGString& strAreaPattern, 
						 const UGString& strAreaColor);

		UGbool DrawArea(UGRecordset *pRecordset, UGGeometry *pGeometry, UGDrawing *pDrawing, 
						const UGString& strAreaPattern,	const UGString& strAreaColor,
						UGint nLineStyleID = UGPen::PenNull,
						const UGString& strLineColor = _U("CHBLK"), UGint nLineWidth = 1);

		UGbool DrawArea(UGRecordset *pRecordset, UGGeometry *pGeometry, UGDrawing *pDrawing,
			            UGStyle &style, UGArray<UGStyle>& arrCenterMarkerStyle);

		UGbool DrawArea(UGRecordset *pRecordset, UGGeometry *pGeometry, UGDrawing *pDrawing,
			UGStyle &style, UGArray<UGStyle>& arrCenterMarkerStyle, UGS57FeatureStyle *pS57FeatureStyle);

		// ���Ƶ����
		UGbool DrawMarker(UGGeometry *pGeometry, UGDrawing *pDrawing, const UGString& strMarkSymbol, UGshort nPriority, UGuint nRCID = 0, UGfloat dAngle=0.0);

		// ���Ƽ���
		UGbool DrawSimpleLine( UGGeometry *pGeometry, UGDrawing *pDrawing,
								UGint nLineId, UGint nWide, const UGString& strColor);

		UGStyle GetSimpleLineStyle(UGDrawing *pDrawing, UGint nLineId, UGint nWide, const UGString& strColor);
		// ���Ƹ�����
		UGbool DrawComplexLine(UGGeometry *pGeometry, UGDrawing *pDrawing, const UGString &strLineSymbol);

		UGStyle GetComplexLineStyle(UGDrawing *pDrawing, const UGString &strLineSymbol);

		UGbool DrawLine(UGRecordset *pRecord, UGDrawing *pDrawing, UGGeometry *pGeometry,
						UGStyle &style, UGArray<UGStyle>& arrCenterMarkerStyle);

		UGbool DrawLine( UGRecordset *pRecordset, UGint nLineStyleID, const UGString& strLineColor, UGint nLineWidth);

		UGbool DrawLine(UGRecordset *pRecord, UGDrawing *pDrawing, UGGeometry *pGeometry,
			UGStyle &style, UGArray<UGStyle>& arrCenterMarkerStyle, UGS57FeatureStyle *pS57FeatureStyle);
		
		UGbool IsSharedGroup1(UGS57Features aryFeature, UGuint unFeatureID);
		UGbool IsSharedRives(UGS57Features aryFeature, UGuint unFeatureID);
		
		UGbool DrawText(UGArray<UGChartTextFormat>& arrTextFormat, UGRecordset *pRecord,
			UGGeometry* pGeometry, UGFieldInfo &fieldInfo, UGDrawing *pDrawing);

		UGbool DrawText(UGArray<UGChartTextFormat>& arrTextFormat, UGRecordset *pRecord,
			UGGeometry* pGeometry, UGFieldInfo &fieldInfo, UGDrawing *pDrawing, UGS57FeatureStyle *pS57FeatureStyle);

		UGbool ComputeLineMaxPriority(UGS57SpatialLine *pSpatialLine, UGshort nPriority);

		// ���ݵ�ǰ����ɫģʽ�õ���Ӧ�ķ���������ͬ����ɫģʽʹ�ò�ͬ�ķ��ţ�
		UGString GetSymbolNameOnColorMode(const UGString& strSymbolName);

		UGGeoLine *MakeSpatialLine(UGDrawing *pDrawing, UGGeoLine *pGeoLine, UGint nORNT);

	private:


		//void SetS57DatasetGroup();
		//void SetVCDataset();
		//void SetVIDataset();

	    UGbool UDWHAZ04IsDanger(UGRecordset *pTagRecordset,UGint nCode, 
			                    UGArray<UGint>& ArrTagIDs, UGArray<UGint>& ArrSrcIDs, 
								UGArray<UGint>& ArrSrcIDCount, UGbool bNeedDeeper);

		UGbool DEPVAL02GetLeastDepth(UGRecordset *pTagRecordset, UGint nCode,
									UGArray<UGint>& ArrTagIDs, UGArray<UGint>& ArrSrcIDs, 
									UGArray<UGint>& ArrSrcIDCount, UGfloat &dfLeastDepth);

		UGbool HaveSrcRecord(UGRecordset *pTagRecordset, UGint nCode, 
								UGArray<UGint>& ArrTagIDs, UGArray<UGint>& ArrSrcIDs, 
								UGArray<UGint>& ArrSrcIDCount);

	public:

		UGArray<UGChartPointObjectStyle *> m_pointStyles;
		UGArray<UGChartLineObjectStyle *> m_lineStyles;
		UGArray<UGChartAreaObjectStyle *> m_areaStyles;

		//! \brief �����
		UGString m_strFeatureAcronym;

		//! \brief �������ų�������
		UGString m_strCSPName;

		UGS57SpatialRelationshipParserDisplay *m_pSpatialRSParser;

		UGChartSetting *m_pChartSetting;

		UGS57SpatialLineManger *m_pSpatialLineManger;

		//UGS57DatasetGroupExt *m_pS57Group;

	private:
		//UGDatasetVector *m_pVIDataset;
		//UGDatasetVector *m_pVCDataset;
		UGChartLayer *m_pParentLayer;
		//! \brief ��ʾ���ȼ�
		UGint m_nPriority;

		//UGRecordset *m_pReDEPARE;
		//UGRecordset *m_pReDRGARE;
		//UGRecordset *m_pReUNSARE;

		// 0x01 DEPARE
		// 0x20 DRGARE
		// 0x40 UNSARE
		UGbyte m_HaveDangerRecord; 

		UGArray<UGint> m_nArrTagIDs_DEPARE;
		UGArray<UGint> m_nArrSrcIDs_DEPARE;
		UGArray<UGint> m_nArrSrcIDCount_DEPARE;

		UGArray<UGint> m_nArrTagIDs_DRGARE;
		UGArray<UGint> m_nArrSrcIDs_DRGARE;
		UGArray<UGint> m_nArrSrcIDCount_DRGARE;

		UGArray<UGint> m_nArrTagIDs_UNSARE;
		UGArray<UGint> m_nArrSrcIDs_UNSARE;
		UGArray<UGint> m_nArrSrcIDCount_UNSARE;

		UGint m_nCode;
	};
}

#endif //!defined(AFX_UGChartSubLayer_H_)

