#if !defined(AFX_UGCHARTLAYER_H)
#define AFX_UGCHARTLAYER_H

#include "Drawing/UGDrawing.h"
#include "Engine/UGDataSource.h"
#include "Engine/UGDatasetGroup.h"
#include "Map/UGTheme.h"
#include "Map/UGSelection.h"
#include "Map/UGThemes.h"
#include "Stream/ugdefs.h"
#include "Map/UGLayer.h"
#include "ChartToolkit/UGS57SpatialLineManger.h"
#include "ChartToolkit/UGS57SpatialRelationshipParser.h"
//#include "ChartToolkit/UGS57DatasetGroupExt.h"
#include "ChartToolkit/UGChartDatasetGroup.h"
#include "Map/UGChartObjectInfo.h"
#include "ChartBase/UGChartDisplayCategory.h"

#define  MAX_S52PRIORITY 10
#define  SELECTED_MARKERID  60000001

#define  S57_DEPARE_LABEL 42
#define  S57_DEPCNT_LABEL 43
#define  S57_DRGARE_LABEL 46
#define  S57_UNSARE_LABEL 154
#define  S57_OBSTRN_LABEL 86
#define  S57_UWTROC_LABEL 153
#define  S57_WRECKS_LABEL 159


namespace UGC {

class UGLayers;
class UGChartSetting;
class UGChartSubLayer;

typedef UGArray<UGGeometry*> UGGeometrys;
typedef UGDict<UGint, UGArray<UGDataset*> > UGS57DatasetDict;

class MAP_API UGS57Edge 
{
public:
	UGS57Edge();
	~UGS57Edge();

	UGuint m_nEdgeId;
	UGbool m_bValid;
	UGint m_nOrient;
	UGGeoLine *m_pGeoLine;
};

class MAP_API UGS57FeatureStyle{

public:
	UGS57FeatureStyle();
	~UGS57FeatureStyle();

	UGint m_nCode;
	UGint m_nPriority;
	UGuint m_nFeatureID;
	UGlong m_nSCAMIN;
	UGChartDisplayCategory::UGS52DisplayCategory m_eCategory;
	UGGeometry::Type m_eGeoType;
	UGGeometry *m_pGeometry;
	UGArray<UGStyle> m_styles;
	UGArray<UGGeoPoint *> m_centerPnt;
	UGArray<UGGeoLine *> m_litarcs;
	UGArray<UGS57Edge *> m_edgeStyles;
	UGArray<UGGeoText *> m_texts;
};


class MAP_API UGChartLayer : public UGLayer
{
	friend class UGChartSubLayer;

public:
	MAP_APIF UGChartLayer();
	MAP_APIF ~UGChartLayer();
	MAP_APIF UGChartLayer(const UGChartLayer& chartLayer);	
	MAP_APIF UGChartLayer& operator =(const UGChartLayer& chartLayer);	

public:	
	
	//! \brief ����XML��Ϣ
	MAP_APIF UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��ȡXML��Ϣ
	MAP_APIF UGbool FromXML(const UGString& strXML,UGbool bIgnoreCaption = true, UGint nVersion = 0);

	//! \brief ��������ͼ����Ϣ
	MAP_APIF void Reset(UGbool bChangeStyle = true);
	
	//! \brief �����ʾ�õļ�¼��
	MAP_APIF void ClearDisplayRecordset();
	//! \brief �ͷ����м�¼�����ڹر����ݼ����޸����ݼ��Ӷνṹ֮ǰ�������
	MAP_APIF void ClearRecordsets();
	//! \brief ����༭�õļ�¼��	
	MAP_APIF void ClearEditRecordset();
	//! \brief ׼����ʾ�õļ�¼��,UGQueryDef *pQueryDef�Ǳ༭��¼����ѯ��������
	MAP_APIF void PrepareEditRecordset(const UGQueryDef *pQueryDef = NULL);
	//! \brief ���ñ༭�õļ�¼��
	MAP_APIF void SetEditRecordset(UGRecordset *pEditRecordset);
	//! \brief �õ��༭�õļ�¼��
	MAP_APIF UGRecordset* GetEditRecordset() const;
	//! \brief �õ���ʾ�õļ�¼��
	MAP_APIF UGRecordset* GetDisplayRecordset() const;	

	//! \brief ����ͼ��
	/**
	\param pGraphics			���Ƶ���Graphics[in]
	\param pDrawing				������[in]
	\param pRecordSet           ���Ƶļ�¼��[in]
	\param bSingle              ��¼���Ƿ����ɸ�ͼ���Լ�ʹ��[in]
	\return                     ���Ƴɹ�����true����֮Ϊfalse
	*/
	MAP_APIF UGbool OnDraw(UGGraphics* pGraphics, UGDrawing *pDrawing, UGProgress* pProgress = NULL);

	MAP_APIF UGLayer* AddDataset(UGDataset *pDataset);

	MAP_APIF UGLayer* GetSubLayer(UGint nIndex);
	MAP_APIF UGint GetSubLayersCount();

	MAP_APIF void SetChartSetting(UGChartSetting *pChartSetting);
	MAP_APIF UGChartSetting * GetChartSetting();

	//! \brief �������ú�ͼ��ͼ�����ʾ��񣨼����ұ����ݣ�
	//! \brief �����ݺ�ͼ��ͼ�����ȼ���������
	MAP_APIF void ResetChartStyles(UGbool bOnlyResetPoint = false, UGbool bOnlyResetArea = false);

	MAP_APIF void ComputeBounds(UGLayer *pSubLayer);

	MAP_APIF UGRect2D GetBounds();

	MAP_APIF const UGPrjCoordSys& GetPrjCoordSys();

	// �������Կ���ȥ�� ��ΪDatasetGroup������Ի�ȡ��
	MAP_APIF void SetDataSource(UGDataSource *pDatasource);

	MAP_APIF void SetDatasetGroup(UGDatasetGroup *pDatasetGroup);
	MAP_APIF UGDatasetGroup * GetDatasetGroup();

	MAP_APIF UGS57SpatialRelationshipParserDisplay* LoadSpatialRelationship();
	MAP_APIF UGS57SpatialRelationshipParserDisplay* GetSpatialRelationship();
	MAP_APIF UGS57SpatialLineManger *LoadSpatialLineManger();
	MAP_APIF UGS57SpatialLineManger *GetSpatialLineManger();

	//FromXML��ʼ�����ݼ�
	UGbool ValidateDatasets();

	//FromXML��ʼ�����ݼ�����
	UGbool ValidateDatasetGroup();

	//  [7/13/2011 zhoujt]
	void ClearLayersSelection();
	//  [7/13/2011 zhoujt]
	//! \brief ��ȡ����ѡ�ж���ĸ���
	UGint GetSelectedGeometryCount();
	//  [7/13/2011 zhoujt]
	UGbool SelectWithRegion(UGGeoRegion &regSelection, UGbool bShiftMode = false, UGbool bControlMode = false, UGint nSelectionMode = 0);
	UGbool SelectWithLine(UGGeoLine &geoLine, UGbool bShiftMode/* = false*/, UGbool bControlMode/* = false*/, UGint nToleranceSelection = 0);
	//  [7/13/2011 zhoujt]
	//! \brief   ����ѡ�¼�
	UGbool HitTest(UGPoint2D pntHitTest, UGdouble dTolerance, UGbool bAppendMode = false,
		UGbool bControlMode = false);

	// ѡ�ж��������ʾ
	void HighlightSelection(UGGraphics* pGraphics, UGDrawing* pDrawing);

	// UGArray<UGChartObjectInfo*> GetSelectedObjectInfo();

	UGbool DeleteSubLayer(UGDataset* pDataset);

	void SetNeedHighlight(UGbool bNeedHighlight);

	// ָ��ѡ����ĳ���������featureID��SmID���������˶��������ʾ��ѡ���е�������겻�ٸ�����
	// ����ѡ��󣬴����ĸ�����ʾ��ʧЧ
	void HighlightObject(UGuint nRCID, UGint nSoundingID, UGbool bMoveToCenter);

	void SetEditAttribute(UGbool bEditAttribute);

	//void SetEditGeometry(UGbool bEditGeometry);

	// �����ı��ü���,�ü�ͼ���еĵ��߶��󣬵����ü���
	void SetTextClipRegion(const UGGeoRegion& geoTextClipRegion);
	const UGGeoRegion& GetTextClipRegion() const;

	void SetModifiedS57EdgeStyle(UGArray<UGS57EdgeStyle>& s57EdgeStyles);

	UGbool IsInflateBounds();

	void SetEditable(UGbool bEditable = TRUE);

	UGint FindSubLayer(UGLayer *pLayer) const;

	UGLayer* GetCurrentSubLayer();
	void SetCurrentSubLayer(UGLayer* pCurrentSubLayer);

	UGLayer* GetSubLayer(UGuint nFeatureOBJL, UGDataset::DatasetType featureType);

	// ��װUGS57EditDatasetGroup��ͬ������
	UGString GetUniqueFeatureObjectID();
	UGuint GetUniqueFeatureRCID();

	void RefershS57EditGroup();

	// ����ͼ��ѡ�ж����ID����ת��Recordset�����ҳ�ʼ��ѡ�ж�����Ϣ
	UGRecordset* SelectionToRecordset(UGChartSubLayer *pSubLayer, UGDrawParamaters* pDrawParam);
	
private:
	void ReleaseGeometryAry();

	void DrawGeometry(UGGeometrys& aryGeometry,  UGDrawing *pDrawing, UGGraphics* pGraphics);
	void DrawGeoText(UGDrawing *pDrawing, UGGraphics* pGraphics);

	void MakeGeoLines(UGArray<UGGeometrys> &aryGeoLines, UGDrawing *pDrawing);

	//! \brief ���Ƽ��ζ���
	void DrawGeometrys(UGGraphics* pGraphics, UGDrawing *pDrawing);

	void DrawPaperChartGeometrys(UGGraphics *pGraphics, UGDrawing *pDrawing);

	//! \brief �ȼ���ó���Ҫ���ƵĶ�������
	//! \remark ֻҪ��һ��ͼ�����ɹ��ˣ��ͷ���true
	UGbool ComputeGeometrys(UGGraphics* pGraphics, UGDrawing *pDrawing);

	UGbool ComputeGeometrysPaperChart(UGGraphics* pGraphics, UGDrawing *pDrawing);

	void DrawCellDSNM(UGPoint2D& posPoint, UGDrawing* pDrawing);

	UGDatasetVector* GetCurrentLayerVCDataset();
	UGDatasetVector* GetCurrentLayerVIDataset();

	void AddCodeDatasetDict(UGDataset *pDataset, UGint nCode=0);

	UGbool GetCodeDataset(UGint nCode, UGArray<UGDataset*> &aryDataset);

//	void AddS57AttiRecordset(UGint nCode);

// 	UGFeature* GetS57AttiFeature(UGint nCode, UGint nSmID);
// 
// 	UGFeature* GetS57AttiFeature(UGuint nRCID);

	UGVariant GetS57AttiFeature(UGint nCode, UGint nSmID);

	UGVariant GetS57AttiFeature(UGuint nRCID);

	// ������ʾˮ���
	UGbool HighlightSNDFRMText(UGGeometry *pGeometry, UGDrawing *pDrawing, UGfloat dDepth);

	// ���ѡ�еĶ�����Ϣ
	// void ClearSelectedObjectInfo();

	// �����ļ����ͱ����߻�ö�Ӧ�����ݼ����飬�ݹ����
	UGDatasetGroup* FindChartGroup(UGDatasetGroup *pDatasetGroupRoot);

	//UGFeature* GetVIFeature(UGuint nRCID);
	//UGFeature* GetVCFeature(UGuint nRCID);

	UGshort GetVIQuaposValue(UGuint nRCID);
	UGshort GetVCQuaposValue(UGuint nRCID);


	void ClearCache();

	void SetClearCache(UGbool bClear);
	
	UGDatasetVector *GetFeatureDataset(UGint nCode, UGDataset::DatasetType eType);

	//UGChartQFind<UGint >* ReadAttiFeature(UGDatasetVector *pDataset,
	//						UGArray<UGFeature *>& arrFeature, UGArray<UGint>& arrID,
	//						UGbool bNeedSpatialQuery, UGbool bNeedReadAttiFeature);

	UGChartQFind<UGint >* ReadAttiFeature(UGDatasetVector *pDataset, UGint nCode,
		UGArray<UGVariant >& arrFeature, UGArray<UGint>& arrID,
		UGbool bNeedSpatialQuery, UGbool bNeedReadAttiFeature);

	//UGChartQFind<UGuint >* ReadVectorPoint(UGDatasetVector *pDataset,
	//					UGArray<UGFeature *>& arrFeature, UGArray<UGuint>& arrRCID);

	UGChartQFind<UGuint >* ReadVectorPoint(UGDatasetVector *pDataset,
		UGArray<UGshort>& arrQuaposValue, UGArray<UGuint>& arrRCID);

	void SpatialQueryFeatures(UGDatasetVector *pDataset, UGRecordset *pRecordDEPARE, 
							  UGRecordset *pRecordDRGARE, UGRecordset *pRecordUNSARE,
							  UGArray< UGArray<UGint> >& arrIDs);

	void SpatialQueryFeatures( UGRecordset *pRecord, UGRecordset *pRecordDEPARE, 
							   UGRecordset *pRecordDRGARE, UGRecordset *pRecordUNSARE,
							   UGint nCode, UGChartSubLayer *pSubLayer);

	void SetSpatialQueryFeatureIDs(UGChartSubLayer* pSubLayer, UGRecordset *pRecordDEPARE, 
							UGRecordset *pRecordDRGARE, UGRecordset *pRecordUNSARE, UGDatasetVector *pDataset, UGint nCode);

	UGbool CreatTextClipRgn(UGGraphics* pGraphics, UGDrawing *pDrawing);

	UGdouble CalculateSymScale(UGDrawing* pDrawing);

	void AddS57FeatureStyle(UGS57FeatureStyle* pS57FeatureStyle);
	void DrawTextPaperChart(UGDrawing *pDrawing, UGGraphics* pGraphics, UGS57FeatureStyle *pS57FeatureStyle, UGdouble dCos, UGdouble dSin);
	void DrawCenterPointPaperChart(UGDrawing *pDrawing, UGGraphics* pGraphics, UGS57FeatureStyle *pS57FeatureStyle, UGdouble dCos, UGdouble dSin);
	void DrawEdgePaperChart(UGDrawing *pDrawing, UGGraphics* pGraphics, UGS57FeatureStyle *pS57FeatureStyle, UGdouble dCos, UGdouble dSin);
	void DrawGeometryPaperChart(UGDrawing *pDrawing, UGGraphics* pGraphics, UGS57FeatureStyle *pS57FeatureStyle, UGdouble dCos, UGdouble dSin);
	void DrawLitArc(UGDrawing *pDrawing, UGGraphics* pGraphics, UGS57FeatureStyle *pS57FeatureStyle, UGdouble dCos, UGdouble dSin);

	UGS57FeatureStyle* GetS57FeatureStyle(UGuint nFeatureID);

private:
	UGChartSetting* m_pChartSetting;

	UGRect2D m_rcBounds;

	UGS57SpatialLineManger *m_pSpatialLineManger;
	UGS57SpatialRelationshipParserDisplay *m_pSpatialRSParser;

	UGDataSource *m_pDatasource;// �������Կ���ȥ��
	UGDatasetGroup *m_pDatasetGroup;

	UGDatasetVector *m_pVIDataset;
	UGDatasetVector *m_pVCDataset;

	UGS57DatasetDict m_dictDataset;

	//UGDict<UGuint, UGFeature* > m_dictAttiFeature;

	//UGS57DatasetGroupExt* m_pS57GroupInfo;
	UGChartDatasetGroup* m_pChartDatasetGroup;

	// UGArray<UGChartObjectInfo*> m_arrSelectedObjectInfo;

	// ѡ��ʱ�Ƿ���Ҫ������ʾ
	// remarks ��һѡ��ģʽʱ��������ͼ�㶼��Ϊ����Ҫ����
	UGbool m_bNeedHighlight;

	// ѡ��ĵ�һ�����RCIDֵ
	UGuint m_nSingleSelectedRCID;

	// ѡ���ˮ����SmID��ˮ��㲻��ͨ��RCIDΨһ��ʶ��
	UGint m_nSelectedRecordsetID;

	// ��ͼ���ݼ���������ƣ�7C������
	UGString m_strDatasetGroupName;

	// ��ͼ�ļ���Ӧ���ļ���
	UGString m_strCellDSNM;

	// ��ͼ�ļ���Ӧ�ı����߷�ĸ
	UGlong m_nCellScale;

	UGArray< UGArray<UGint> > m_OBSTRNP_IDs;
	UGArray< UGArray<UGint> > m_OBSTRNL_IDs;
	UGArray< UGArray<UGint> > m_OBSTRNA_IDs;
	UGArray< UGArray<UGint> > m_UWTROCP_IDs;
	UGArray< UGArray<UGint> > m_WRECKSP_IDs;
	UGArray< UGArray<UGint> > m_WRECKSA_IDs;
		
	UGbool m_bSpatialQuery;
	
	UGDict<UGuint, UGVariant> m_dictAttiFeature;

	UGChartQFind<UGint > *m_pDEPAREAtti;
	UGChartQFind<UGint > *m_pDRGAREAtti;
	UGChartQFind<UGint > *m_pDEPCNTAtti;

	// ������������ֱ�洢����DRVAL1��VALDCO�����ֶε��ֶ�ֵ��
	// DEPARE �� DRGAREֻ��洢DRVAL1��DEPCNTֻ��洢VALDCO

	//UGArray<UGFeature *> m_arrFeatureDEPARE;
	UGArray<UGVariant> m_arrValDRVAL1DEPARE;
	UGArray<UGint> m_arrIDDEPARE;

	UGArray<UGVariant> m_arrValDRVAL1DRGARE;
	//UGArray<UGFeature *> m_arrFeatureDRGARE;
	UGArray<UGint> m_arrIDDRGARE;

	UGArray<UGVariant> m_arrValVALDCODEPCNT;
	//UGArray<UGFeature *> m_arrFeatureDEPCNT;
	UGArray<UGint> m_arrIDDEPCN;

	UGChartQFind<UGuint > *m_pFeatureVI;
	UGChartQFind<UGuint > *m_pFeatureVC;

	//UGArray<UGFeature *> m_arrFeatureVI;
	UGArray<UGshort> m_arrValQuaposVI;
	UGArray<UGuint> m_arrRCIDVI;

	//UGArray<UGFeature *> m_arrFeatureVC;
	UGArray<UGshort> m_arrValQuaposVC;
	UGArray<UGuint> m_arrRCIDVC;

	// UGbool m_bClearCache;

	UGbool m_bAttributeEdit;

	// UGbool m_bGeometryEdit;

	UGGeoRegion m_TextClipRegion;

	UGRgn* m_pTextClipRgn;

	UGArray<UGS57EdgeStyle> m_modifiedS57EdgeStyles;

	UGbool m_bIsInflateBounds;

	UGLayer* m_pCurrentLayer;

protected:

	UGDrawing *m_pDrawing;

public:
	// �洢�桢��(CSP�ڲ���������)
	UGArray<UGGeometrys> m_aryDrawingGeometrys;

	// �洢����������
	UGArray<UGGeometrys> m_aryDrawingGeoPoints;

	UGGeometrys m_aryDrawingGeoText;

	// ������Ӧ����ʾ���
	UGDict< UGuint, UGArray<UGStyle> > m_dictPointStyle;
	// ��������Ӧ�����ߵ���ʾ���

	UGList<UGLayer*> m_SubChartLayers;

	// ֽ�ʺ�ͼ���洢��
	UGArray<UGS57FeatureStyle *> m_s57FeatureStyles;
	UGint m_naryIndex;
};

}

#endif // !defined(AFX_UGLAYER_H__A4B430F7_6A63_4275_BB13_EF15BA12DDAD__INCLUDED_)


