// UGLayer.h: interface for the UGLayer class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGLayer.h 
   **************************************************************************************
    \author   �¹���
    \brief    ͼ���࣬�������ݼ�������ʾ��ר��ͼ��ʾ��                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGLAYER_H__A4B430F7_6A63_4275_BB13_EF15BA12DDAD__INCLUDED_)
#define AFX_UGLAYER_H__A4B430F7_6A63_4275_BB13_EF15BA12DDAD__INCLUDED_

#include "Drawing/UGDrawing.h"
#include "Engine/UGDataSource.h"
#include "Map/UGTheme.h"
#include "Map/UGSelection.h"
#include "Map/UGThemes.h"
#include "Stream/ugdefs.h"
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
#include "Representation/UGRepresentation.h"
#endif

namespace UGC {

class UGProgress;
class UGLayers;
class UGWebMapStub;

//! \brief AfterGeometryDraw �¼��ص�����
typedef void (UGSTDCALL *AfterGeometryDrawProc)(UGlong pWnd,UGString strLayerName,UGGeometry* pGeoGeometry,UGGraphics* pGraphics);
//! \brief AfterGeoMapDraw �¼��ص�����
typedef void (UGSTDCALL *AfterGeoMapDrawProc)(/*UGlong pWnd,*/UGDataset *pDataset, UGRecordset *pDisplayRecordset, UGGeometry* pGeometry);
//! \brief BeforeGeometryDraw �¼��ص�����
typedef void (UGSTDCALL *BeforeGeometryDrawProc)(UGlong pWnd,UGbool& bCancel,UGString strLayerName,UGGeometry* pGeoGeometry,UGGraphics* pGraphics);
//! \brief BeforeLytGeometryDraw �¼��ص�����
typedef void (UGSTDCALL *BeforeLytGeometryDrawProc)(UGlong pWnd,UGbool& bCancel,UGGeometry* pGeoGeometry/*,UGGraphics* pGraphics*/);
typedef UGArray<UGbyte> UGbyteArray;

enum UGLayerOptions
{
	//! \brief �Ƿ���ʾ
	UG_LO_VISIBLE						=	0x00000001,	
	//! \brief �Ƿ��ѡ��
	UG_LO_SELECTABLE					=	0x00000002,	
	//! \brief �Ƿ�ɱ༭
	UG_LO_EDITABLE						=	0x00000004,	
	//! \brief �Ƿ�ɲ�׽
	UG_LO_SNAPABLE						=	0x00000008,
	//! \brief �Ƿ����ŷ���
	UG_LO_SYMBOL_SCALABLE				=	0x00000010,	
	//! \brief �Ƿ�������ʾ������ʵ��
	
	UG_LO_LINE_ADJUST   				=	0x00000100,	
	//! \brief �Ƿ�����ʾ��ʱ��ID����,ֻ��SDX����������Ч(SDB,DGN�Ѿ�Ĭ�ϰ���ID����)
	UG_LO_KEEP_ORDER					=	0x00000020,	
	//! \brief �Ƿ���3D������������ʾ�����������ʾ������Ҫ�趨�߶��ֶ� m_strHeightField
	UG_LO_IS_3D							=	0x00000040,	
	//! \brief �Ƿ��Ѿ��޸ģ��Ƿ���Ҫ����
	UG_LO_IS_MODIFIED					=   0x00000080, 
	
	//! \brief �Ƿ������ݿ��������ݣ���SDB���Ӧ
	UG_LO_DATABASE_MODE					=	0x00040000,
	//! \brief �Ƿ���SuperMap�����ݿ�����
	UG_LO_SPATIAL_DB_MODE				=	0x00080000, 
	//! \brief �Ƿ�����ʾ��ʱ����Ҫ���bounds
	UG_LO_NEED_CK_GEO_BOUND				=	0x00100000,	
	
	//! \brief �༭����
	UG_LO_EDITABLE_LOCK					=   0x00200000, 
	//! \brief �Ƿ�������ͼ�� 
	UG_LO_IS_VIRTUAL					=   0x01000000, 
	//! \brief false:����Ҫͼ�㻺�棬true����Ҫͼ�㻺��
	UG_LO_USE_LAYER_CACHE				=   0x02000000, 
	//! \brief ͼ�㻺���Ƿ���Ҫˢ��
	UG_LO_CACHE_NEED_REFRESH			=   0x04000000, 
	//! \brief �Ƿ�������ʾ�ص��ı�
	UG_LO_ALLOW_TEXT_OVERLAP			=	0x10000000,	
	//added by dongfei 2007-04-27
	//! \brief �Ƿ���ͼ���ڵĶ���ѹ��˳��
	UG_LO_IS_ORDER_OVERLAP		    	=   0x20000000,	
	
	
	//! \brief �Ƿ�ʹ����ʾ�ü�����
	UG_LO_IS_DISPLAYCLIP				=   0x40000000, 
	//! \brief �Ƿ�ʹ�õ�·�Ż���ʾ
	UG_LO_CROSSROAD_OPTIMIZED			=   0x80000000 
};

struct ScaleStyle
{	
	UGdouble dMinScale;
	UGdouble dMaxScale;
	UGStyle  style;
} ;


#ifdef SYMBIAN60
class MAP_APIC UGLayer
#else
class MAP_API UGLayer
#endif
{
public:
	enum UGLayerType
	{
		//! \brief ��ͨͼ��
		UG_Layer_Normal                     = 1,
		//! \brief �����߲�
		UG_Layer_NetworkLine                = 2,
		//! \brief ������
		UG_Layer_NetworkPoint               = 3,
		//! \brief ���˴��󸸲�
		UG_Layer_TopoParent                 = 4,
		//! \brief ���˴������ݲ�
		UG_Layer_TopoLayer                  = 5,
		//! \brief ���˴�����
		UG_Layer_TopoPointError             = 6,
		//! \brief ���˴�����
		UG_Layer_TopoPointException         = 7,
		//! \brief ���˴����߲�
		UG_Layer_TopoLineError              = 8,
		//! \brief ���˴����߲�
		UG_Layer_TopoLineException          = 9,
		//! \brief ���˴������
		UG_Layer_TopoRegionError            = 10,
		//! \brief ���˴������
		UG_Layer_TopoRegionException        = 11,
		//! \brief ������������ûʹ��
		UG_Layer_TopoDirty                  = 12,
		//! \brief ��ͼͼ��
		UG_Layer_Chart		                = 13,
		//�޸ĺ������Ӳ������
		//UG_Layer_Child                      = 13,//�Ӳ�
		UG_Layer_SCM		                = 14,
		//! \brief ��ͼ��ͼ��
		UG_Layer_ChartChild					= 15
	};
	


public:
	MAP_APIF UGLayer();
	virtual MAP_APIF ~UGLayer();
	MAP_APIF UGLayer(const UGLayer& layer);	
	MAP_APIF UGLayer& operator =(const UGLayer& layer);	

public:	
	//*********����Options***********//
	//! \brief ĳ��ѡ���Ƿ����
	MAP_APIF UGbool Enable(UGLayerOptions unOptions);
	//! \brief �Ƿ�����ĳ��ѡ��
	MAP_APIF UGbool IsSupportOptions(UGLayerOptions unOptions)const;
	//! \brief ����ʹ��ĳ��ѡ��
	virtual MAP_APIF void SetOptions(UGLayerOptions unOptions);
	//! \brief ���ý���ĳ��ѡ��
	virtual MAP_APIF void UnsetOptions(UGLayerOptions unOptions);	
	//! \brief �õ�ͼ��ѡ�����õ���Ϣ
	MAP_APIF UGuint GetOptionsInfo()const;
	//! \brief ����ͼ��ѡ�����Ϣ
	MAP_APIF void SetOptionsInfo(UGuint unOptions);

	//! \brief �Ƿ���ʾ
	MAP_APIF UGbool IsVisible()const;
	//! \brief ����Ϊ����ʾ
	MAP_APIF void SetVisible(UGbool bVisible = true);

	//! \brief �Ƿ����ѡ��
	MAP_APIF UGbool IsSelectable()const;	
	//! \brief ����Ϊ��ѡ��
	MAP_APIF void SetSelectable(UGbool bSelectable = true);			

	//! \brief �Ƿ���Ա༭
	MAP_APIF UGbool IsEditable()const;
	//added by xielin 2007.8.9
	//! \brief  �����Ƿ���Ա༭
	//! \remarks �������ڲ�ʹ�ã��ⲿ�͵���UGLayers::SetEditableLayer
	virtual MAP_APIF void SetEditable(UGbool bEditable = true);

	//! \brief �Ƿ���Բ�׽
	MAP_APIF UGbool IsSnapable()const;									// �Ƿ���Բ�׽
	//! \brief ����Ϊ�ɲ�׽
	MAP_APIF void SetSnapable(UGbool bSnapable = true);				// 

	//! \brief �Ƿ������༭
	MAP_APIF UGbool IsEditableLock()const;
	//! \brief ���������༭
	MAP_APIF void SetEditableLock(UGbool bEditableLock = true);   

	//! \brief �Ƿ��������ͼ������Ŷ�����
	MAP_APIF UGbool IsSymbolScalable()const;
	//! \brief ���÷��ſ�����
	MAP_APIF void SetSymbolScalable(UGbool bSymbolScalable = true);

	//! \brief ���ͻ���ʱ�Ƿ�������ʾ��ʵ����
	//! \return �Ƿ�������ʾ��ʵ����1�����ǣ�0�����Ĭ��Ϊ1��
	MAP_APIF UGbool IsLineAdjust() const;
	//! \brief ���ͻ���ʱ����������ʾ��ʵ����
	/**
	�趨�Ƿ�������ʾ��ʵ�����ڷŴ���Сʱ����������ʾ���͡�
	\param bFixed  �Ƿ�������ʾ��ʵ��[in]
	\remarks Ĭ���»������ͻ���ô˷�����
	*/
	MAP_APIF void SetLineAdjust(UGbool bLineAdjust = true);

	//! \brief �Ƿ������ʾʱ����ID����
	MAP_APIF UGbool IsKeepOrder()const;	
	//! \brief ���ö�����ʾʱ���Ƿ�ID����
	MAP_APIF void SetKeepOrder(UGbool bKeepOrder = true);		

	//! \brief ��ͼ��������Ƿ��޸Ĺ�
	MAP_APIF UGbool IsModified()const;		
	//! \brief ����ͼ���޸ı�־
	MAP_APIF void SetModifiedFlag(UGbool bModified = true);

	//! \brief �����Ƿ�����ͼ�㻺����
	MAP_APIF UGbool IsAllowCache()const;		
	//! \brief �����Ƿ�����ͼ�㻺����
	MAP_APIF void SetAllowCache(UGbool bCache = true);				
	
	//! \brief ȡ��ͼ��ˢ�±��
	MAP_APIF UGbool GetRefreshFlag()const;								
	//! \brief ����ͼ��ˢ�±�־��ǿ��ˢ��ͼ��
	MAP_APIF void SetRefreshFlag(UGbool bRefresh = true);			
	
	//! \brief ͼ��Ļ������Ƿ����
	MAP_APIF UGbool IsCacheAvailable()const;						
	//*********��ʾ����Options***********//

	//! \brief �õ�դ��͸����
	MAP_APIF UGint GetRasterOpaqueRate()const;					
	//! \brief ����դ��͸����
	MAP_APIF void SetRasterOpaqueRate(UGint nRasterOpaqueRate);		
	
	//! \brief ����ͼ����
	MAP_APIF void SetStyle(const UGStyle& style);
	//! \brief �õ�դ��͸����
	MAP_APIF const UGStyle& GetStyle()const;

	//! \brief �õ�ͼ���ѯ���
	MAP_APIF const UGQueryDef& GetQueryDef()const;
	//! \brief �õ�ͼ���ѯ���
	/**
	\param QueryDef  ��ѯ���[in\out]
	*/
	MAP_APIF void GetQueryDef(UGQueryDef& QueryDef)const;	
	//! \brief ����ͼ���ѯ���
	MAP_APIF void SetQueryDef(UGQueryDef& QueryDef);
	//! \brief �������ݼ���ά���������0ά������1ά������2ά����������-1
	MAP_APIF UGint GetDimension()const;								
	
	//! \brief �������ר��ͼ�������Ƿ�Ϸ�
	/**
	\param strExpression   �ֶα��ʽ[in]
	\remarks ������ѯ����������ֵ����,���ʧ��,����0
	*/
	MAP_APIF UGFieldInfo::FieldType CheckThemeExpression(const UGString& strExpression);
	//! \brief ���¼���Bounds
	MAP_APIF UGRect2D RecalcBounds(UGDrawParamaters *pDrawParam, UGbool bComputeDatasetBounds = false);

	//! \brief ����XML��Ϣ
	MAP_APIF virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��ȡXML��Ϣ
	MAP_APIF virtual UGbool FromXML(const UGString& strXML,UGbool bIgnoreCaption = true, UGint nVersion = 0);

	//! \brief �õ�����,���û����Ϊ��
	MAP_APIF virtual UGLayer* GetParentLayer()const;
	//! \brief ���������ͼ�㣬���ؽڵ�ͼ��
	MAP_APIF UGLayer* GetChildLayer()const;						

	//! \brief ���ø���,���û����Ϊ��
	MAP_APIF void SetParentLayer(UGLayer* pLayer);
	//! \brief ���������ͼ�㣬���ýڵ�ͼ��
	MAP_APIF void SetChildLayer(UGLayer* pLayer);								
	
//	UGString GetName()const;										// ͼ����

	//! \brief  ����������Ϣ
	MAP_APIF void SetDescription(const UGString&  strDescription);		
	//! \brief ��ȡͼ��������Ϣ
	MAP_APIF UGString GetDescription()const;								

	//! \brief �������ݼ�����
	MAP_APIF void SetDatasetName(const UGString&  strDatasetName);		
	//! \brief ��ȡ���ݼ�����
	MAP_APIF UGString GetDatasetName()const;								

	//! \brief ��������Դ����
	MAP_APIF void SetDataSourceAlias(const UGString& strDataSourceAlias);	
	//! \brief ��ȡ����Դ����
	MAP_APIF UGString GetDataSourceAlias()const;

	//! \brief ����ͼ�����
	MAP_APIF void SetCaption(const UGString&  strCaption);		
	//! \brief ��ȡͼ�����
	MAP_APIF UGString GetCaption()const;								

	//! \brief ��ȡͼ����������
	MAP_APIF UGdouble GetVisibleScaleMax()const;
	//! \brief ��ȡͼ����С������
	MAP_APIF UGdouble GetVisibleScaleMin()const;
	//! \brief ����ͼ����������
	MAP_APIF void SetVisibleScaleMax(UGdouble dVisibleScaleMax);
	//! \brief ȡ��ͼ����������
	MAP_APIF void CancelVisibleScaleMax();
	//! \brief ����ͼ����С������
	MAP_APIF void SetVisibleScaleMin(UGdouble dVisibleScaleMin);
	//! \brief ȡ��ͼ����С������
	MAP_APIF void CancelVisibleScaleMin();

	//! \brief ��������ͼ����Ϣ
	MAP_APIF void Reset(UGbool bChangeStyle = true);	

	//! \brief ���ͼ�㲻����ʾ��Geometry��ID
	MAP_APIF void AddInvisibleGeoID(UGint nID);
	//! \brief ���ͼ�㲻����ʾ��Geometry��IDs
	MAP_APIF void ClearInvisibleGeoIDs();
	
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

	//! \brief �����Ƿ������ʾ�õļ�¼������Ҫ���������ƶ��ͼ�㹲����ʾ���ݼ�ʱ˭�ͷż�¼��������
	MAP_APIF void SetClearDisplayRecordset(UGbool bClear = true);

	//! \brief �����ݼ���������
	// param bClearRecordsets �Ƿ���Ҫ������ݼ�,���ز���ģ��ʱ������Ϊfalse(��ֹm_pDatasetΪҰָ�뵼�±���)(added by hp 2011-3-21)
	MAP_APIF virtual void SetDataset(UGDataset *pDataset, UGbool bInit = true, UGbool bClearRecordsets = true);
	//! \brief ��ȡ��ǰ���ӵ����ݼ�	
	MAP_APIF virtual UGDataset* GetDataset();	

	//! \brief �жϵ�ǰ���������Ƿ���Ҫ��ʾͼ��(ʹ�ã�m_dVisibleScaleMax��m_dVisibleScaleMin�ж�)
	MAP_APIF UGbool IsVisibleScale(UGdouble dScale,UGDrawParamaters* pDrawParam = NULL)const;
	//! \brief ���ͼ���¼�
	/**
	\param pntHitTest           �����Ӧ�㣬��������[in]
	\param dTolerance           �������,����λ[in]
	\param Selection            [in]
	\param nByPassCount         [in]
	\param pDrawing             ������[in]
	\return                     ����ɹ�����true����֮Ϊfalse
	\remark                     ��������nByPassCountֵΪ-1ʱ��ʾ����������Geometryȫ��ѡ�ϡ�������ԭ��������һ��[����ʵ��ѭ��ѡ�е�Ч��]
    */
	virtual MAP_APIF UGbool HitTest(const UGPoint2D& pntHitTest, UGdouble dTolerance, UGSelection &Selection, UGint &nByPassCount, UGDrawing *pDrawing, UGbool bControlMode = false, UGbool bShiftMode = false);
	//! \brief ������ŵĴ�С
	/**
	\param dScale           ������[in]
	\return                 �������ŵı���
	*/
	MAP_APIF UGdouble CalculateSymbolScale(UGdouble dScale)const;

	//! \brief �õ�ϵͳ������
	MAP_APIF UGdouble GetSymScaleDefinition() const;
	//! \brief ����ϵͳ������
	MAP_APIF void SetSymScaleDefinition(UGdouble dSymScaleDefinition);
	
	//! \brief ��ȡ���ԭ���ģʽ
	MAP_APIF UGGraphics::BrushOrgMode GetFillOrgMode() const;				
	//! \brief �������ԭ��ģʽ
	MAP_APIF UGGraphics::BrushOrgMode SetFillOrgMode(UGGraphics::BrushOrgMode nFillOrgMode);		
	
	//! \brief ��ȡ��С��ʾ��С
	MAP_APIF UGdouble GetMinimumVisible() const;				
	//! \brief ������С��ʾ��С
	MAP_APIF void SetMinimumVisible(UGdouble dMinimumVisible);	

	//! \brief ����ͼ��
	/**
	\param pGraphics			���Ƶ���Graphics[in]
	\param pDrawing				������[in]
	\param pRecordSet           ���Ƶļ�¼��[in]
	\param bBlank				���Ƶ��Ƿ��ǰ�ͼ[out]
	\param bSingle              ��¼���Ƿ����ɸ�ͼ���Լ�ʹ��[in]
	\return                     ���Ƴɹ�����true����֮Ϊfalse
	*/
	MAP_APIF UGbool OnDraw(UGGraphics* pGraphics, UGDrawing *pDrawing, UGRecordset* pRecordSet, UGbool *pbBlank, UGbool bSingle = false,UGProgress* pProgress = NULL);
	//! \brief ���Ƽ��ζ���
	MAP_APIF UGbool OnDrawElement(UGDrawing *pDrawing, UGGeometry *pGeometry, UGRecordset* pDisplayRecordset, UGTheme::UGActionData* pActionData = NULL);
	//! \brief ��ȡ���ζ��󼰷�Χ��Ϊ����ϻ��Ƽ��ζ������������һЩ�ص�
	MAP_APIF void GetElementAndBounds(UGDrawing *pDrawing, UGRecordset* pDisplayRecordset, UGGeometry*& resultGeo, UGRect2D &bounds, UGTheme::UGActionData* pActionData = NULL);

	//! \brief ת���ı���ר��ͼΪ�������ݼ�
	MAP_APIF UGbool ConvertTextOrThemeLayerToDataset(UGDrawing* pDrawing, UGDatasetVector *pDatasetCAD, UGbool bProgress = true);
	
	//! \brief  ��pRecordset�е�ר��ͼ����ת��ΪGeometry��Ŀǰֻ֧�ֵ㵥ֵ���ֶΡ��Զ���ר��ͼ�� add by wangna 2011-05-31
	//! \param pDrawing         ��ʾ��ָ��[in]
	//! \param pRecordset         ��Ҫ��ר��ͼ����ת��ΪGeometry�Ķ����¼��[in]
	//! \param geometryArray         ��¼���ж����Ӧ��ר��ͼ����ת��ΪGeometry����[in/out]
	//! \return �Ƿ�ת���ɹ�
	MAP_APIF UGbool ConvertThemeObjectsToGeometrys(UGDrawing* pDrawing, UGRecordset *pRecordset, UGArray<UGGeometry *> &geometryArray);

	//added by xielin 2007-04-13
	//! \brief ����ͼ���е�ѡ�� 
	MAP_APIF UGSelection* GetSelection();

	//added by lugw 2007-04-12
	//! \brief  ��ǩר��ͼͼ�����¼�
	/**
	\param pntHitTest           �����Ӧ�㣬��������[in]
	\param dTolerance			������ޣ�����λ[in]
	\param pGraphics            pDrawing���ж�Ӧ��pGraphics[in]
	\param pDrawing             ������Ϣ[in]
	\param geoTextArray         ѡ�б�ǩ���ֶα�ǩ��Ϣ[in/out]
	\param strFieldExpression   �����ѯ���ֶα��ʽ��Ĭ��Ϊ��
	\return                     �ɹ�����true����֮Ϊfalse
	\remarks                    ���ڲ�ѯ���geoTextArray������û�ֻ��Ҫ�õ�ѡ�б�ǩ���ֶ���Ϣ��������齫ÿ����ǩ����Ϣ��GeoText����ʽ���������ֶα��ʽ��Ϊ�ն��ұ��ʽ��ȷ�������鰴�գ������������ı�ǩ��Ϣ���ñ�ǩ���ֶα��ʽ��ֵ������ʽ��������ڴ�Bounds�µı�ǩ��
	*/
	MAP_APIF UGbool HitTestThemeLable(const UGPoint2D& pntHitTest,UGdouble dTolerance,/*UGThemeLabel* pThemeLabel,*/UGGraphics* pGraphics, UGDrawing *pDrawing,UGArray<UGGeoText>& geoTextArray,UGString strFieldExpression = (_U("")));
	MAP_APIF UGbool HitTestThemeLable(const UGPoint2D& pntHitTest,UGdouble dTolerance,UGGraphics* pGraphics, UGDrawing *pDrawing,UGArray<UGGeoCompound>& geoCompoundArray,UGString strFieldExpression = (_U("")));
	//! \brief  ��ǩר��ͼͼ�����¼�,�������ӿ�û���������ã����ڲ��Ƽ�ʹ�ã�ֻ��Ϊ�˱�֤������
	MAP_APIF UGbool HitTestThemeLable(const UGPoint2D& pntHitTest,/*UGThemeLabel* pThemeLabel,*/UGGraphics* pGraphics, UGDrawing *pDrawing,UGArray<UGGeoText>& geoTextArray,UGString strFieldExpression = (_U("")));
	MAP_APIF UGbool HitTestThemeLable(const UGPoint2D& pntHitTest,UGGraphics* pGraphics, UGDrawing *pDrawing,UGArray<UGGeoCompound>& geoCompoundArray,UGString strFieldExpression = (_U("")));
	//! \brief ͳ��ר��ͼ�����Ӧ
	/*
	\param pntHitTest    ���λ��[in]
	\param dTolerance    ������ޣ�����λ[in]
	\param pDrawing      ���Ʋ���[in]
	\param pLayer        ר��ͼ���ڲ�[in]
	\param geoTextArray  �����ֶ���Ϣ[in/out]
	**
	*/
	MAP_APIF UGbool HitTestThemeGraph(const UGPoint2D& pntHitTest,UGdouble dTolerance, UGDrawing *pDrawing,UGArray<UGGeoText>& geoTextArray);
	//! \brief ���Tinͼ���¼�
	/**
	\param pntHitTest           �����Ӧ�㣬��������[in]
	\param dTolerance           ������ޣ�����λ[in]
	\param triInfo				����Tin��������Ϣ[in\out]
	\param pDrawing             ������[in]
	\return                     ����ɹ�����true����֮Ϊfalse
	*/
	//UGbool HitTestTinBlock(const UGPoint2D& pntHitTest,UGdouble dTolerance, TriInfo& triInfo, UGDrawing *pDrawing);
	
	//added by dongfei 2007-04-24 
	//! \brief ����/���� ͼ����,�ڲ�ʹ�ã������޸ģ������ṩ����caption
	MAP_APIF void SetName(UGString strLayerName);
	MAP_APIF UGString GetName()const {return m_strName;};
	//! \brief ����/�����ض���������ͼ����
	MAP_APIF void SetStyle(UGdouble dMinScale,UGdouble dMaxScale,const UGStyle& style);
	MAP_APIF UGStyle GetStyle(UGdouble dScale)const;
	//! \brief ɾ�����з�Ĭ�Ϸ��(����Ĭ��)
	MAP_APIF void RemoveAllStyle();
	//! \brief ��ȡ������(������Ĭ�Ϸ��)
	MAP_APIF UGint GetStyleCount()const {return m_scaleStyle.GetSize();};
	//! \brief ��ȡ����ָ���������·��
	MAP_APIF void GetScalStyle(UGArray<ScaleStyle>& styles){styles = m_scaleStyle;};
	//! \brief ����/��ȡ��ѯ�����ֶ�,�ýӿ���Ҫ���ڵ���ͬһ��ͼ�㼸�ζ���ĵ��ǹ�ϵ�����ֶ��������Ϊ�Զ������ֶ�
	MAP_APIF UGbool SetOrderField(UGString strField);
	//! \brief ����/����Ƿ�ĳһ�ֶ�(��SmID)˳���ѯ
	MAP_APIF UGString GetOrderField();
	//! \brief �Ѹ���ID�ŵĶ���ŵ���ǰ��
	MAP_APIF UGbool BringToFront(UGlong nID);
	//! \brief �Ѹ���ID�ŵĶ���ŵ������
	MAP_APIF UGbool SendToBack(UGlong nID);
	//! \brief ����ͼ��ѹ�Ǵ���
	MAP_APIF void SetOrderOverlap(UGbool bOrderOverlap = true);
	//! \brief �Ƿ��ͼ��ѹ�Ǵ���
	MAP_APIF UGbool IsOrderOverlap();
	
	//! \brief ���ζ����Ƿ�ɼ�
	/**
	\param pGeometry             ���ζ���[in]
	\param dMinimumVisible       ��С��ʾ������[in]
	\return                      �ɼ�����true����֮Ϊfalse
	*/
	MAP_APIF UGbool IsGeometryVisible(UGGeometry *pGeometry, UGdouble dMinimumVisible)const;

	//! \brief ���ζ����Ƿ�ɼ�
	/**
	\param pGraphics            ���Ƶ���Graphics[in]
	\param pDrawing				������[in]
	\param querfdef				�õ��Ĳ�ѯ���[in]
	\return                     �ɹ�����true����֮Ϊfalse
	*/
	MAP_APIF UGbool PrepareQueryDef(UGGraphics* pGraphics, UGDrawing* pDrawing, UGQueryDef*& querfdef,UGbool bIsflateBounds = false);

	//added by lugw 2007-06-05 
	//! \brief �õ�ͼ������
	MAP_APIF UGLayer::UGLayerType GetType();
	//! \brief ����ͼ������
	MAP_APIF virtual void SetType(UGLayer::UGLayerType nType);

	//! \brief ���ø�ͼ������
	MAP_APIF void SetParentDsName(UGString strName);
	//! \brief �õ���ͼ������
	MAP_APIF UGString GetParentDsName();

	//! \brief ���ζ���������Ļص�����
	MAP_APIF void SetAfterGeometryDrawFunc(AfterGeometryDrawProc pAfterGeometryDrawFunc,UGlong pWnd);
	//! \brief ���ζ������ǰ�Ļص�����
	MAP_APIF void SetBeforeGeometryDrawFunc(BeforeGeometryDrawProc pBeforeGeometryDrawFunc,UGlong pWnd);
	MAP_APIF void SendAfterGeometryDrawFunc(UGString strLayerName,UGGeometry* pGeoGeometry,UGGraphics* pGraphics);
	MAP_APIF void SendBeforeGeometryDrawFunc(UGbool& bCancel,UGString strLayerName,UGGeometry* pGeoGeometry,UGGraphics* pGraphics);
	
	MAP_APIF void SetBeforeLytGeometryDrawFunc(BeforeLytGeometryDrawProc pBeforeLytGeometryDrawFunc,UGlong pWnd);
	MAP_APIF void SendBeforeLytGeometryDrawFunc(UGbool& bCancel,UGGeometry* pGeoGeometry/*,UGGraphics* pGraphics*/);

//added by qianjn in 2010-4-23 11:29:48 ����ԭ��geomap ������ɺ���Ҫ�ж��ǲ�����Ҫ����ͼ������

	//! \brief GeoMap�������Ļص�����
	MAP_APIF void SetAfterGeoMapDrawFunc(AfterGeoMapDrawProc pAfterGeometryDrawFunc/*,UGlong pWnd*/);
	MAP_APIF void SendAfterGeoMapDrawFunc(UGDataset *pDataset, UGRecordset *pDisplayRecordset, UGGeometry* pGeometry);

//added by qianjn in 2010-4-23 11:29:48 �������
	
	//! \brief �õ�դ��͸����
	MAP_APIF UGint GetOpaqueRate();	
	//! \brief ����դ��͸����
	MAP_APIF void SetOpaqueRate(UGint nOpaqueRate);	
	
	//! \brief �õ�����
	MAP_APIF UGint GetBrightness();
	//! \brief ��������
	MAP_APIF void SetBrightness(UGint nBrightness);

	//! \brief �õ��Աȶ�
	MAP_APIF UGint GetContrast();
	//! \brief ���öԱȶ�
	MAP_APIF void SetContrast(UGint nContrast);

	//! \brief �Ƿ񱳾�͸��
	MAP_APIF UGbool IsRasterBackTransparent() const;
	//! \brief �����Ƿ񱳾�͸��
	MAP_APIF void SetRasterBackTransparent(UGbool bBackTransparent);

	//! \brief �õ�������ɫ����
	MAP_APIF UGbyte GetRasterBackColorTolerance() const;
	//! \brief ���ñ�����ɫ����
	MAP_APIF void SetRasterBackColorTolerance(UGbyte nBackColorTolerance);

	//! \brief ��ȡGrid��ֵ���
	MAP_APIF UGint GetGridNoData() const;
	//! \brief ����Grid��ֵ���
	MAP_APIF void SetGridNoData(UGint nGridNoData);

	//! \brief �õ�դ�񱳾�ɫ
	MAP_APIF UGColor GetImageBackColor() const;
	//! \brief ����դ�񱳾�ɫ
	MAP_APIF void SetImageBackColor(UGColor crBack);

	//! \brief �õ���ֵ���
	MAP_APIF UGColor GetGridNoDataColor() const;
	//! \brief ������ֵ���
	MAP_APIF void SetGridNoDataColor(UGColor crNoDataColor);
	
	//! \brief �õ������Ƿ�ʹ����ʾ�ü�����
	MAP_APIF UGbool IsDisplayClip() const;							
	//! \brief �õ��Ƿ�ʹ����ʾ�ü�����
	MAP_APIF void SetDisplayClip(UGbool bIsDisplayClip);		

	//! \brief �Ƿ��Ż�ʮ��·��
	MAP_APIF UGbool IsCrossroadOptimized()const;
	//! \brief �����Ƿ��Ż�ʮ��·��
	MAP_APIF void SetCrossroadOptimized(UGbool bIsCrossroadOptimized);
	//! \brief �ڲ����ú���
	MAP_APIF void SetLayers(UGLayers *pLayers);

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//! \brief ��ȡ�������ݼ�����ͼ��
	MAP_APIF UGbool GetWebSubLayers(UGArray<UGString>& aryLayerNames) const;
	//! \brief ��ȡ�������ݼ�����ͼ�����
	MAP_APIF UGbool GetWebSubLayersTitle(UGArray<UGString>& aryLayerTitle) const;
	//! \brief �����������ݼ�����ͼ���Ƿ�ɼ�����
	MAP_APIF void SetWebSubLayersVisble(const UGbyteArray& arrLayersVisible);
	//! \brief �õ��������ݼ�����ͼ���Ƿ�ɼ�����
	MAP_APIF void GetWebSubLayersVisble(UGbyteArray& arrLayersVisible) const;

	//! \brief ���öನ��դ�����ݼ��ĸ�������ʾ���ԡ�
	//! \param arrMultiBandVisible ��������ʾ����[in]��
	MAP_APIF void SetMultiBandVisible(const UGArray<UGint>& arrMultiBandVisible);	
	//! \brief ���öನ��դ�����ݼ��ĸ�������ʾ���ԡ�
	//! \param arrMultiBandVisible ��������ʾ����[in]��
	MAP_APIF void GetMultiBandVisible(UGArray<UGint>& arrMultiBandVisible);
	//! \brief ���öನ��դ�����ݼ�����ʾ��ɫ�ռ�ģʽ��
	MAP_APIF void SetImgColorSpace(ImgColorSpace nImgCS);
	//! \brief ��ȡ�ನ��դ�����ݼ�����ʾ��ɫ�ռ�ģʽ
	MAP_APIF ImgColorSpace GetImgColorSpace();
#endif
	//! \brief ����ͼ���͸����
	/*
	\param nTransPercent	͸����[in]
	*/	
	MAP_APIF void SetTransPercent(UGuint nTransPercent);
	//! \brief ��ȡͼ���͸����
	MAP_APIF UGuint GetTransPercent();

	MAP_APIF UGColorTable m_ColorsetTable;

	// ��ɫ���ձ� 
	MAP_APIF UGColorDictTable m_clrDictTable;
//{{�޸�ԭ�����ü���ȡ��ͼ������� �޸���:macx 2008-8-11 17:23:31
// 	//! \brief ������ͼ������͡�
// 	//! \param nRepStyleType ��ͼ�������[in]��
// 	MAP_APIF void SetRepStyleType(UGint nRepStyleType);	
// 	//! \brief ��ȡ��ͼ������͡�
// 	//! \return ��ͼ������͡�
// 	UGint GeRepStyleType();	
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//added by macx 200-8-26 
	//! \brief ������ͼ�ֶ�����
	//! \param strRepreFiledName [in]��
	MAP_APIF void SetRepresentationFieldName(const UGString &strRepreFiledName);	

	//! \brief ��ȡ��ͼ�ֶ�����
	//! \return ��ͼ�ֶ�����
	const UGString& GetRepresentationFieldName();	
	//added by macx 2008-8-26 
	//! \brief ������ͼ����־ true��ʹ����ͼ��false����ʹ��
	MAP_APIF void SetUseRepresentation(UGbool bRepresentation);
	//! \brief ��ȡ�Ƿ�ʹ����ͼ����
	UGbool IsUseRepresentation();
	//! \brief ����ͼ��Ĭ�ϱ�����ͼ���
	MAP_APIF void SetRepresentationSaveType(UGRepresentationElement::UGRepresentationElementType nType);
	UGRepresentationElement::UGRepresentationElementType GetRepresentationSaveType();
	
	//! \brief ���ñ��òο��ֶ�
	MAP_APIF void SetRefFieldName(const UGString& strRefFieldName);
	MAP_APIF UGString GetRefFieldName();
	
	//! \brief ר��ͼ��ͼ�ֶΣ��Ա�ǩ��ͳ�ƣ��ȼ�������
	MAP_APIF void SetSaveRepresentationFieldName(const UGString &strSaveRepreFiledName);
	const MAP_APIF  UGString& GetSaveRepresentationFieldName();
	//! \brief ������ͼ���ʹ��
	MAP_APIF void SetIgnoreRepreStyle(UGbool bIgnore);
	MAP_APIF UGbool IsIgnoreRepreStyle();
#endif


	//added by macx �˴����÷���Ȩ��Ϊpublic����Ҫԭ������m_selection�������ʾҪʹ��
	//! \brief �����Ƿ�ʹ����ͼ������ȡ��Ӧ��Geometry��
	//! \param pRecordset ��¼��[in]��
	//! \param pGeometry ��ȡ��Geometry[out]��
	//! \param bMemoryEngine �Ƿ����ڴ�����[in]��
	//! \param bGetSrcGeo ���ֶ�Ϊ��ʱ���Ƿ��ȡԭʼ����,����ר��ͼ��Ҫ���á�in��
	//! \param bTheme �Ƿ�ʱ��ȡר��ͼ��ͼ�ֶΡ�in��
	//! \return �Ƿ��ȡ�ɹ���true Ϊ�ɹ���falseΪʧ�ܡ�
	//! \remarks �ڱ�ǩ��ͳ�ƣ��ȼ�ר��ͼʱ��bGetSrcGeo��Ϊ�գ���Ϊ���ƵĲ�Ӧ��ʱԭʼ����
	MAP_APIF UGbool GetDrawGeometry(UGRecordset *pRecordset,UGGeometry*& pGeometry,UGbool bMemoryEngine = FALSE, UGbool bGetSrcGeo = true,UGbool bTheme = false,UGGeometry *pGeoRef = NULL);
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//! \brief �����Ƿ�����ͼ���������Geometry��
	//! \param pRecordset ��¼��[in]��
	//! \param pGeometry Ҫ�����geometry[in]��
	//! \param bTheme �Ƿ��Զ�����ר��ͼ���͡�in��
	//! \param bSaveRepre �Ƿ񱣴浽��ͼ����trueΪ���浽��ͼ�ֶΣ�falseΪ���浽ԭʼ���ݼ���¼�У�Ĭ��Ϊfalse
	MAP_APIF void SaveDrawGeometry(UGRecordset *pRecordset,UGRepresentationElement::UGRepresentationElementType nType = UGRepresentationElement::UGREPRESENTATIONSTYLE_GEOMETRY_STYLE,  UGStyle* pStyle = NULL,UGTextStyle* pTextStyle = NULL,UGGeometry* pGeometry = NULL,UGbool bTheme = true, UGbool bSaveRepre = FALSE);
#endif

	//! \brief �Ƿ��û�ȡ�����ڲ�ʹ�ýӿ�
	UGbool IsCancelByUser(UGDrawing *pDrawing) const; 

	//! \brief  Geometry�Ƿ�ɼ�
	//! \param nID Geometry��ID[in]��
	//! \return �Ƿ�ɼ� 
	UGbool IsVisibleByGeoID(const UGint& nID)const;
	
	//! \brief �û����õ��ⲿ��Ϣ
	//! \param value �ⲿ��Ϣ�ַ���
	MAP_APIF void SetExternalInfo(const UGString& value);

	//! \brief �û����õ��ⲿ��Ϣ
	//! \return �ⲿ��Ϣ�ַ���
	MAP_APIF const UGString& GetExternalInfo();

// 	MAP_APIF void SetRepresentation(UGRepresentation *pRepresentation);
// 	UGRepresentation* GetRepresentation();
	
// 	//! \brief ����Geometry��
// 	//! \param pDateset ���ݼ�[in]��
// 	//! \param pGeometry Geometry[in]��
// 	//! \param bRepre �Ƿ��ȡRepresentation true ��ȡ�������ݣ�ʹ�ã�false ����ȡ��ʹ��ԭʼGIS����[in]��
// 	//! \return �Ƿ�ɹ���
// 	//! \remarks ������ͼ�������ȡGeometry��
// 	UGbool GetDrawingGeometry(UGRecordset* pRecordset, UGGeometry** pGeometry/*,UGbool bRepre = FALSE*/);
// 
// 	UGbool	GetDrawingGeometryDirect(UGRecordset* pRecordset, UGGeometry** pGeometry);
// 	UGbool SaveDrawingGeometry(UGRecordset *pRecordset,UGString &strFiledName,UGGeometry *pGeometry);
//}}�޸�ԭ�����ü���ȡ��ͼ��� �޸���:macx  2008-8-11 17:23:31
	
public:
	//! \brief ������ѯ��¼��ʱ�ķ�Χ����ר��ͼʱ�������ѯ��Χʱ����
	//! \brief �ú���ʵ�ֽ�rcSearchBounds������ڵ�ͼ���Ͻǵ�Ĵ���ӵķ�Χ�󲢣��������Ϊ�µ�rcSearchBounds�����ڲ�ѯ��¼��
	//! \brief ʵ�ָú�������������һ���̶��ϱ�֤ר��ͼ����Ļ���˳������������ͼƬ�ϱ���һ��
	void AdjustSearchBounds(UGDrawing* pDrawing, UGRect2D &rcSearchBounds);

	//! \brief ��ʼ�����ӵĿ����ӿ����ȣ�
	void InitGridWidth(UGDrawing* pDrawing);

	UGint m_nGridWidth;   //���ӵĿ�����������ڵ�ͼ�����Ͻǵ���л��ֵ�

protected:
	MAP_APIF UGbool OnDrawRaster(UGGraphics* pGraphics, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	MAP_APIF UGbool OnDrawVector(UGGraphics* pGraphics, UGDrawing *pDrawing,UGProgress* pProgress = NULL);

	MAP_APIF UGbool OnDrawThemeNone(UGDrawing *pDrawing,UGProgress* pProgress = NULL,UGTheme::UGActionData* pActionData = NULL);	

	//! \brief ���ڻ�ȡ���ζ���Ϊ����ϻ��Ƽ��ζ������������һЩ�ص�
	MAP_APIF UGGeometry* GetThemeNoneElement(UGDrawing *pDrawing,UGRecordset* pDisplayRecordset);
	//! \brief ���Ƽ��ζ���
	MAP_APIF UGbool OnDrawThemeNoneElement(UGDrawing *pDrawing, UGGeometry *pGeometry, UGRecordset* pDisplayRecordset, UGTheme::UGActionData* pActionData = NULL);
	/*
	UGbool OnDrawThemeStyle(UGThemeStyle* pThemeStyle, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	UGbool OnDrawThemeGraph(UGThemeGraph* pThemeGraph, UGDrawing *pDrawing,UGProgress* pProgress = NULL);	
	UGbool OnDrawThemeGraduatedSymbol(UGThemeGraduatedSymbol* pThemeGraduatedSymbol, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	UGbool OnDrawThemeDotDensity(UGThemeDotDensity* pThemeDotDensity, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	UGbool OnDrawThemeLabel(UGThemeLabel* pThemeLabel, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	*/

	MAP_APIF UGbool OnDrawThemeNoneCrossroad(UGDrawing *pDrawing);

	//UGbool OnDrawStyleThemeCrossroad(UGThemeUnique *pThemeUnique, UGDrawing *pDrawing);

	/*
	UGbool ThemeStyleToDataset(UGThemeStyle *pThemeStyle, UGRecordset *pRecordset, UGDrawParamaters *pDrawParam, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGbool ThemeDotDensityToDataset(UGThemeDotDensity *pThemeDotDensity, UGRecordset *pRecordset, UGDrawParamaters *pDrawParam, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGbool ThemeGraphToDataset(UGThemeGraph *pThemeGraph, UGRecordset *pRecordset, UGDrawParamaters *pDrawParam, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGbool ThemeGraduatedSymbolToDataset(UGThemeGraduatedSymbol *pThemeGraduatedSymbol, UGRecordset *pRecordset, UGDrawParamaters *pDrawParam, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGbool ThemeLabelToDataset(UGThemeLabel *pThemeLabel, UGRecordset *pRecordset, UGDrawing *pDrawing, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGGeometry* ThemeLabelBackToGeometry(UGThemeLabel *pThemeLabel, UGGeoText* pGeoText, UGDrawParamaters *pDrawParam,const UGPoint2D& pntObjCenter);
	UGGeometry* LabelBoundsToGeometry(const UGRect2D& rcBounds, const UGPoint2D& pntCentroid, UGdouble dAngle, UGint nLabelBackType, const UGStyle& backStyle,  UGDrawParamaters *pDrawParam);
	*/
	//added by dongfei 2007-04-23
	//! \brief ����ǣ���߶�������������ں���Ҫǣ���ߵĶ�����
	/*
	\param rect			��Ҫǣ���߶������Ӿ���
	\param pntFrom      ǣ������ʼ��  
	\param pntAnchor		��ת����
	\param dAngle	          ��ת�Ƕ�
	\return				ǣ���ֶ��� Ϊ��ʼ��;������ĵ㸽������Χ�ɵĵ���������		
	\remarks			��Ҫ�ⲿ�ͷŷ��ص�region			
	*/	
	MAP_APIF UGGeoRegion* GetLeaderObject(const UGRect2D& rect,const UGPoint2D& pntFrom, const UGPoint2D& pntAnchor, UGdouble dAngle);

//{{{added by qianjn in 2008-11-19 14:20:03 ����ԭ��֧��դ�����ݼ��Ķ�̬ͶӰ
	
	//! \brief ����ͼ����������ݼ����㶯̬ͶӰ������ݼ���
	//! \param pDatasource ��ͶӰת�������ݼ�������Դ������ȥ��ֵΪ��ֵ[in]��
	//! \param pRefTranslator ����ϵת������[in]��
	//! \return ������óɹ����ض�̬ͶӰ������ݼ������򷵻�NULL��
	MAP_APIF UGDatasetRaster* GetDatasetFromFlyPrj(UGDataSource*& pDatasource, UGRefTranslator* pRefTranslator, UGDrawing *pDrawing, UGString& strDatasource); 

public:

	//! \brief ��ͼ����������ݼ��ÿ�,����ʹ�ã�û��������ֱ���ÿյģ���ҪӦ������������ݼ���ɾ���˵������
	MAP_APIF void SetNullDataset();
	
	//! \brief ���βü�
	//! \return ����ü��ɹ��� ���� true�� ���򷵻�ʧ��
	static MAP_APIF UGbool Clip(const UGGeometry* pGeometry, const UGRect2D& rectClip, UGGeometry*& pGeoResult);

	//! \brief ��ʱ��Ա�������ط����á�
	UGbool m_bViewGlobal;

	//! \brief �������������������ݼ�����ʱ���������ʱ�м����,�����ط���Ҫʹ�á�
	UGRectUInt m_rectSearch;

	//! \brief ��ȡͼ�㷶Χ��ע��Ŀǰ�˽ӿڲ����ں�ͼͼ�㣬��ͼ����ʵ��
	MAP_APIF UGRect2D GetBounds();

public:
	//��ȡ��ͱ�ǩһ����˵ĵ�ͼ��
	UGLayer* GetPointLayer();
	//���õ�ͱ�ǩһ����˵ĵ�ͼ��
	void SetPointLayer(UGLayer* pPointLayer);

	// ��ȡӰ��ನ����������
	UGRasterStretchOption* GetRasterStretchOption();

	UGbool IsBackMapData();
	void SetBackMapData(UGbool bBackMapData);

public:
	//! \brief ��ʼ�������ͼ�����Ϣ
	void InitWebMapInfo();
	//! \brief ����ʼ�������ͼ�����Ϣ
	void UnInitWebMapInfo();
	//! \brief �������������ͼ�����Ϣ
	void ResetWebMapInfo();

	//! \brief �ж��Ƿ��������ͼͼ��
	UGbool IsWebRaster();

	//! \brief ���ݵ�ǰ����ͼ��Χ��m_pDrawTileImage���Ƶ�pGraphics��
	UGbool OnDrawTileImage(UGDrawing* pDrawing, UGbool bIsPrinting);

	//! \brief ͼ�������ݼ�������Ƭ
	void RequestTile(UGdouble dScale, UGRect2D& rcViewBounds, UGbool bPanMode = false, UGbool bForceUpdate = false);

	//! \brief ͼ�������ݼ�������Ƭ
	void RequestTileEx(UGdouble dScale, UGRect2D& rcBounds);

	//! \brief ���»����ImageData
	UGbool UpdateCacheTile(UGint nExtTileSize = 1, UGbool bRemoveAll = true);

	//! \brief ��ȡ��ǰ������ƬDP-->LP��ת������
	UGdouble GetTileCoordRatio();

	UGWebMapStub* m_pWebMapLayerStub;
	
public:	
	//! \brief ר��ͼ����
	// SFC�����ռ��У����ר��ͼ����λ��ͬһ��ͼ���£��ñ�����������ͼ���µ�����ר��ͼ��
	//�ڵ�ǰ����У��ñ�����Ҫ���ڶ�������SFC�����ռ�ʱ�õ�
	//UGC�����ռ��иñ���ΪNULL
	UGThemes m_Themes;
	//! \brief ר��ͼ 
	//����UGC�����ռ䣬һ��ר��ͼ��Ӧһ��ͼ�㣬�����ͼ��Ϊר��ͼ����m_pTheme��������ר��ͼ����Ӧ��������֮����ֵΪNULL
	UGTheme* m_pTheme;
	//added by xielin 2007-04-13
	//! \brief ��ͼ��༭ģʽ�£�ÿ��Layer����һ��selection 
	UGSelection m_Selection;  
	
	//! \brief ͼ���Ƿ��ܻ��Ƶı�������������������Ƹ�ͼ���Ƿ���Ի���
	//�Ժ����ͼ�㣬�ж�visibleΪtrue�����Ҹñ���Ϊtrue��������Ƶ�ԭ����
	//��Ϊsfc�е�ͼ������е�ֵר��ͼ����ȡ��ugc�зֲ㣬����Ϊ���Ż�����Ҫ����ԭʼ
	//ͼ���visibleΪfalse�����������͵��±��湤���ռ��ʱ��ͼ��״̬�ʹ���
	//(��ȡhashcode��ʱ��Ҳ���ˣ������Ծ����Ӹñ�����ר���������ƣ�����ȥ�ı�ͼ��Ŀɼ�״̬
	//UGbool m_bCanDraw;
	//added by litao,2001/8/3
	//! \brief ͼ���в��ɼ��ļ��ζ����ID
	UGArray<UGint> m_arrInvisibleGeoIDs;  
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//{{�޸�ԭ�򣺹�����ͼ��� �޸���:macx 2008-8-11 14:45:01
	//! \brief ��ͼ����ֶ�
	UGRepresentation *m_pRepresentation;

	//! \brief Ĭ����ͼ������
	UGRepresentationElement::UGRepresentationElementType m_nRepresentationElementType;	
#endif
	//! \brief �Ƿ���Ա�����ݵķ����Ϣ,��Ҫ���ר��ͼ
	UGbool m_bIgnore;
	//{{�޸�ԭ��:����ͼ��ü�  �޸���:lidl 2008-9-8  9:15:15
	//! \brief �洢ͼ��Ĳü�����,�ڲ���ʱ����ÿհ�,�������´�����ʱ����ʾ��ǰ�Ĳü�����
	UGGeoRegion m_DisplayClipRegion;
	//! \brief �洢ԭʼ�Ĳü�����
	UGGeoRegion m_OldDisplayClipRegion;
protected:
	//! \brief ��0.1mmΪ��λ
	UGint m_nMinimumVisible;
	
	UGRecordset *m_pDisplayRecordset;	
	UGRecordset *m_pEditRecordset;		
	//! \brief ͼ����ʾ���
	UGStyle m_Style;					
public:
	//! \brief ��ѯ����
	UGQueryDef m_QueryDef;

	//added by xielin 2007-09-29 ��¼���ڵ�ͼ�㼯�ϣ������޸�ͼ��������༭״̬��
	//! \brief  ͨ��Layers�лص�����֪ͨ��Ӧ��ģ��
	UGLayers* m_pLayers; 

protected:	
	//! \brief  ͼ������
	UGString m_strDescription;			
	//! \brief  caption for this layer
	UGString m_strCaption;			
	//! \brief  �����ͼ������ݼ����ڵ�����Դ����
	UGString m_strDataSourceAlias;		

	UGString m_strDatasetName;

	//!added by macx 2008.7.23 ��������
	//! \brief ����������֡�
	//! \remarks �������õ����������֡�
	UGString m_strGeoName;

//! \brief  ����ͼ�����ߴ��ڸ�ֵ��ʱ�򣬱�ͼ�㲻��ʾ������ֵ����0�����������Ч��Ĭ��Ϊ0
	UGdouble m_dVisibleScaleMax;		
//! \brief  ����ͼ������С�ڸ�ֵ��ʱ�򣬱�ͼ�㲻��ʾ������ֵ����0�����������Ч��Ĭ��Ϊ0
	UGdouble m_dVisibleScaleMin;		
//! \brief  �����ͼ�ķ�������ͼ�����Ŷ����ţ�����ͼ�����ߵ��ڸ�ֵ��ʱ��ͼ��ķ��Ű�geoStyle�ķ��Ŵ�С��ʾ
	UGdouble m_dSymScaleDefinition;		

	UGLayer* m_pParentLayer;
	UGLayer* m_pChildLayer;
	UGDataset *m_pDataset;
	UGuint m_unOptions;

	//! \brief ��ˢԭ��ģʽ
	UGGraphics::BrushOrgMode m_nFillOrgMode;					
	UGbool m_bSingle;
	UGLayer::UGLayerType m_nType;
	UGString m_strParentDsName;
	
	
	
	//added by dongfei 2007-04-24
	//! \brief ͼ���� ��һ���ǡ����ݼ�@����Դ����
	UGString m_strName;

//{{�޸�ԭ����� PDF ʹ���޸���:macx 2008-8-11 10:17:38
	//! \brief PDFʹ�ã�ͼ����
	UGint m_nLayerHandle; 
	//! \brief Geometryͼ������PDFʹ��
	UGint m_nGeoHandle;
	//! \brief Geometry��������
	UGint m_nGeometryCount;
//}}�޸�ԭ�� �޸���:macx  2008-8-11 10:17:38
	
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//! \brief ������ͼ�ֶ�
	UGString m_strRepreFiledName;
	//! \brief �ο��ֶ�
	UGString m_strFieldNameRef;
	//! \brief ר��ͼ��ͼ�����ֶ�
	UGString m_strThemeRepreFiledName;
	//! \brief �Ƿ�ʹ����ͼ����
	//! \remarks true ʹ�ã�false ��ʹ�á�
	UGbool m_bRepresentation;
#endif
	

	//! \brief ��ͬ�������µķ��
	UGArray<ScaleStyle> m_scaleStyle;
	UGString m_strOrderField;
	
	//! \brief դ��ͼ�����ȣ�ֵ��ΧΪ-100��100����������Ϊ������������Ϊ��
	UGchar m_btBrightness;	

	//! \brief  դ��ͼ��Աȶȣ�ֵ��ΧΪ-100��100����ǿ�Աȶ�Ϊ���������Աȶ�Ϊ��
	UGchar m_btContrast;		
	//! \brief  ��͸����0----100% 100Ϊ��͸����0Ϊ��ȫ͸����ֻ��դ�����ݼ���Ч
	UGbyte m_btOpaqueRate;			
	//! \brief  դ�񱳾�ɫ��
	UGColor m_ImageBackColor;  
	//! \brief  ��ֵ���
	UGColor m_GridNoDataStyle; 
	//! \brief  ����͸����
	UGbool m_bRasterBackTransparent; 
	//! \brief  ������ɫ����
	UGbyte m_btBackColorTolerance; 
	//! \brief  Grid��ֵ
	UGint m_nGridNoData;
	
	AfterGeometryDrawProc m_pAfterGeometryDrawFunc;
	BeforeGeometryDrawProc m_pBeforeGeometryDrawFunc;
	BeforeLytGeometryDrawProc m_pBeforeLytGeometryDrawFunc;
	AfterGeoMapDrawProc m_pAfterGeoMapDrawFunc;
	//! \brief �����¼��ص������Ķ���ָ�룬ͳһΪһ���ɣ���ʡ�ڴ�
	UGlong m_pEventView;  
	
	UGbyteArray m_arrWebLayersVisible;

	//  [added by zhangshuo at 5/17/2010]
	UGNetCDFDatasetRasterInfo m_NetCDFInfo;

	//! \brief �ನ����ʾ����
	UGArray<UGint> m_arrMultiBandVisible;
	//! \brief �ನ����ʾ��ɫ�ռ�ģʽ
	ImgColorSpace m_nImgCS;
	//! \brief ��ͼ��͸����
	UGuint m_nTransPercent;

	//! \brief �ನ���������
	UGRasterStretchOption m_RasterStretch;

	UGGraphics* m_pTransPercentGraphics;
	UGImage* m_pTransPercentImage;
	UGBrush* m_pTransPercentBrush;
	UGPen* m_pTransPercentPen;

	//���ڵ�ͱ�ǩһ�������ʾ�ĵ�ͼ��
	UGLayer* m_pPointLayer;

	//! \brief �ⲿ��Ϣ�ַ���
	UGString m_strExternalInfo;
	
	// �ж��Ƿ��Ǳ������ݣ�Ƕ��ʽ�����Ƿ��Ǳ������ݻ���ҵ�����ݣ�
	UGbool m_bBackMapData;
};

}

#endif // !defined(AFX_UGLAYER_H__A4B430F7_6A63_4275_BB13_EF15BA12DDAD__INCLUDED_)


