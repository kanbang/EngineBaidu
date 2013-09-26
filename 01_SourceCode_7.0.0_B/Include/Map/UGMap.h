// UGMap.h: interface for the UGMap class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGMap.h   
   **************************************************************************************
    \author   �¹���
    \brief    ��ͼ�࣬�����ͼ��ʾ�����Ĺ���                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGMAP_H__37037E0D_8ABC_413E_B8BE_2B8916F0319E__INCLUDED_)
#define AFX_UGMAP_H__37037E0D_8ABC_413E_B8BE_2B8916F0319E__INCLUDED_

#include "Map/UGLayers.h"
#include "Map/UGTrackingLayer.h"
#include "Projection/UGSpatialRef.h"

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
#include "Map/UGDeviceTrackingLayer.h"
#endif

//add by xiaoys
#include "Map/UGTrackingLayerEx.h"

#include "SymbolMarker/UGMarkerSymbolLib.h"
#include "FileParser/UGExchangeFileType.h"
#include <queue>

namespace UGC {
	
	class UGCacheFile;
#if !defined OS_ANDROID && !defined IOS
	class UGChartSetting;
#endif
class MAP_API UGMapVersionManager  
{
public:
	UGMapVersionManager();
	void init(); // added by liucq 20130610 �Ӻ��ʼ�������ƶ�ƽ̨�ֶ����ó�ʼ��
#ifdef SYMBIAN60
	~UGMapVersionManager();
#else
	virtual ~UGMapVersionManager();
#endif
};

extern MAP_API UGMapVersionManager g_MapVersionManager;


//! \brief MapOpened�¼��ص�����
typedef void (UGSTDCALL *MapOpenedProc)(UGlong pWnd);

//! \brief BeforeMapDraw �¼��ص�����
typedef void (UGSTDCALL *BeforeMapDrawProc)(UGlong pWnd,UGbool& bCancel,UGGraphics* pGraphics);

//! \brief AfterMapDraw �¼��ص�����
typedef void (UGSTDCALL *AfterMapDrawProc)(UGlong pWnd,UGGraphics* pGraphics);

//! \brief SnapableChangedProc �¼��ص�����
typedef void (UGSTDCALL *SnapableChangedProc)(UGlong pWnd);


class UGFishingNetArithmetic;
class UGTrackingMap;

class MAP_API UGMap  
{
public:
	enum UGGridType
	{
		//! \brief ������
		UGGridGrid,
		//! \brief ʮ�ֲ�˿
		UGGridCross,
		//! \brief ��
		UGGridPoint
	};
public:
	UGMap();
	UGMap(UGbool bTrackingMap);
	UGMap(const UGMap& Map);
	~UGMap();
	UGMap& operator = (const UGMap &Map);

	enum OnTopType
	{
		//! \brief ��ǩ�ö�
		LabelOnTop = 1,        
        //! \brief ͳ��ר��ͼ�ö�
		GraphOnTop = 2,                    
		//! \brief �ȼ������ö�
		GraduatedSymbolOnTop = 4          
	};
//! \brief PDF������ͣ�added by macx 2008.7.31 ��
//! \remarks ��ע��Ϣ��	
	enum UGTypeOption
	{
		//! \brief Ĭ�Ϸ�ʽ����ʸ����ʽ���
		NORMAL  = 0,
		//! \brief ��դ��ͼ��������ɱ�֤ԭʼ״̬�������ʱ���������޸�
		IMAGE	= 1,		
	};

public:
	//! \brief  �빤���ռ佨����ϵ,���ù����ռ�
	void SetWorkspace(UGWorkspace *pWorkspace);
	//! \brief  �õ����ù����ռ�
	UGWorkspace* GetWorkspace()const;
#if !defined OS_ANDROID && !defined IOS
	//! \brief ��ȡ��ͼ���ö���ָ��
	UGChartSetting* GetChartSetting()const;
#endif
	//! \brief ��ȡ��ǰ��ͼ���Ƿ������ͼͼ��
	UGbool ContainLayerChart() const;

	//! \brief  ��ʼ����ͼģʽ���˺������ı� pGraphics ��ָ�����ӳ��ģʽ�����Ͻǵ� LP ���ꡣ
	// �ú����������֮��pGraphics �� LP��DP ֮�������ת����ϵ���Ѿ�����
	// ���ڸú�������ϸ���ͣ���μ���ʵ���롣
	/*  \param pGraphics ���Ƶ���Graphics[in/out]
	    \param rcDevBounds �����豸���豸���귶Χ[in]
	*/
	void MapModeInitialize(UGGraphics* pGraphics, const UGRect& rcDevBounds);

	//! \brief  �ָ�pGraphics��ӳ��ģʽ��ԭ������
	void MapModeRestore(UGGraphics* pGraphics);

	//! \brief  �õ���ͼ����
	UGString GetName()const;
	//! \brief  �õ���ͼ������Ϣ
	UGString GetDescription()const;
	//! \brief  ���õ�ͼ������Ϣ
	void SetDescription(const UGString& strDescription);

	//! \brief  �������ó�ʼ��״̬
	void Reset();
	//! \brief  ����ˢ�±�־
	void SetRefreshFlag(UGbool bRefresh = true);

	//! \brief  ���ø��±�־
	void SetModifiedFlag(UGbool bModified = true);
	//! \brief  �Ƿ����
	UGbool IsModified()const;

	//! \brief  ���õ�ͼͶӰ��Ϣ
	void SetPrjCoordSys(const UGPrjCoordSys& PrjCoordSys);
	const UGPrjCoordSys& GetPrjCoordSys()const;
	void SetPrjCoordSysUnit(UGlong nUnits);
	UGlong GetPrjCoordSysUnit();

	//! \brief  �õ���ɫģʽ
	UGint GetColorMode()const;
	//! \brief  ������ɫģʽ
	void SetColorMode(UGint nColorMode);

	//! \brief  �Ƿ��ı��̶��Ƕ�
	UGbool IsTextFixedAngle()const;
	//! \brief  ����Ϊ�ı��̶��Ƕ�
	void SetTextFixedAngle(UGbool bTextFixedAngle = true);
	//! \brief  �Ƿ���Ź̶��Ƕ�
	UGbool IsMarkerFixedAngle()const;
	//! \brief  ����Ϊ���Ź̶��Ƕ�
	void SetMarkerFixedAngle(UGbool bMarkerFixedAngle = true);

	//! \brief ������ǲ������ŵ�ͼ��ת��������������ת���
	UGbool GetIsFillAngle()const;
	void SetIsFillAngle(UGbool bIsFillAngle = false);

	//! \brief �����Ƿ���Է�����䣬add by tanzw,2011-1-13
	//! \param bIsSymbolFillIgnored�Ƿ���Է�����䣬Ĭ��false��֧��
	//! \remarks ���ú��Է������ʱ��ֻ�����������ı���ɫ�������з��ŵĻ���
	UGbool IsSymbolFillIgnored()const;
	void SetSymbolFillIgnored(UGbool bIsSymbolFillIgnored = false);
	
	//���ı����߷ֿ�����SFC����һ��
	//UGbool IsSmoothingMode()const;									
	//void SetSmoothingMode(UGbool bSmoothingMode = true);
	//! \brief  �Ƿ�Ϊ�߹⻬ģʽ
	UGbool IsLineSmoothingMode()const;
	//! \brief  �����߹⻬ģʽ
	void SetLineSmoothingMode(UGbool bSmoothingMode = true);			
	//! \brief  �Ƿ�Ϊ�ı��⻬ģʽ
	UGbool IsTextSmoothingMode()const;									
	//! \brief  �����ı��⻬ģʽ
	void SetTextSmoothingMode(UGbool bSmoothingMode = true);			
	
	//! \brief ����\��ȡ��ͼƽ����ʾ������¼�� dongfei 2007-03-26
	void SetSmoothingMaxRecord(UGint nRecordCount);	
	UGint GetSmoothingMaxRecord()const;

	//! \brief   �Ƿ�������ʾ�ص��ı� 
	UGbool IsAllowTextOverlap()const;
	//! \brief   ����Ϊ�����ص��ı�
	void SetAllowTextOverlap(UGbool bAllowTextOverlap = false);	
	//! \brief��ȡѹ�ǹ���ѡ��
	UGMapOverlapDisplayedOptions& GetOverlapDisplayedOptions();
	//! \brief��ȡѹ�ǹ���ѡ��
	const UGMapOverlapDisplayedOptions& GetOverlapDisplayedOptions() const;
	//! \brief����ѹ�ǹ���ѡ��
	void SetOverlapDisplayedOptions(const UGMapOverlapDisplayedOptions& options);
	//! \brief   �Ƿ�̶��ı�����
	UGbool IsFixedTextOrientation()const;							
	//! \brief   ����Ϊ�̶��ı�����
	void SetFixedTextOrientation(UGbool bFixedTextOrientation = true);	

	//! \brief   �Ƿ��ǩר��ͼ�ö�	
	UGbool IsLabelAlwaysOnTop()const;								
	//! \brief   ���ñ�ǩר��ͼ�ö�
	void SetLabelAlwaysOnTop(UGbool bLabelAlwaysOnTop = false);		

	//! \brief   ���õȼ��ֶ�ר��ͼ�ö�
	void SetGraduatedSymbolAlwaysOnTop(UGbool bGraduatedSymbolAlwaysOnTop = false);
	//! \brief   �Ƿ�ȼ��ֶ�ר��ͼ�ö�
	UGbool IsGraduatedSymbolAlwaysOnTop()const;
	
	void SetGraphAlwaysOnTop(UGbool bGraphAlwaysOnTop = false);
	//! \brief   �Ƿ�ȼ��ֶ�ר��ͼ�ö�
	UGbool IsGraphAlwaysOnTop()const;

	//! \brief ��������ڵ�һ�δ򿪿յ�ͼ�����ٴ���ӻ������ݼ����Ǹ���ȷ����ͶӰ  added by lidl 
	//void SetFirstTimeDraw(UGbool bFirstTimeDraw);
	//! \brief   �Ƿ�Ϊ��һ�λ���
	UGbool IsFirstTimeDraw() const;

	//! \brief   �õ���С�ɼ��ı���С
	UGdouble GetMinVisibleTextSize()const;
	//! \brief   ������С�ɼ��ı���С
	void SetMinVisibleTextSize(UGdouble dVisibleTextSizeMin);		
	//! \brief   �õ����ɼ��ı���С
	UGdouble GetMaxVisibleTextSize()const;							
	//! \brief   �������ɼ��ı���С
	void SetMaxVisibleTextSize(UGdouble dVisibleTextSizeMax);		

	//! \brief   �������ɼ�����
	void SetMapMaxScale(UGdouble dMaxScale);
	//! \brief   �õ����ɼ�����
	UGdouble GetMapMaxScale() const;
	//! \brief   ������С�ɼ�����
	void SetMapMinScale(UGdouble dMinScale);
	//! \brief   �õ���С�ɼ�����
	UGdouble GetMapMinScale() const;

	//! \brief   �Ƿ�̬ͶӰ
	UGbool IsProjectionOnTheFly()const;									
	//! \brief   ���ö�̬ͶӰ
	void SetProjectionOnTheFly(UGbool bProjectionOnTheFly = true);	
	
	//! \brief   �Ƿ������ѯ��Χ
	UGbool IsInflateBounds();									
	void SetInflateBounds(UGbool bIsMapInflated = true);	

	//! \brief   �ж��Ƿ���æµ�׶Σ��Ƿ������жϵȲ���
	UGbool IsBusy()const;							
	//! \brief   ���ô���æµ�׶Σ��������жϵȲ���
	void SetBusy(UGbool bBusy = true);	

	UGbool IsBusyEnable()const;							
	void SetBusyEnable(UGbool bBusyEnable = true);	

	//! \brief   �õ��������
	const UGStyle& GetBkStyle()const;								
	//! \brief   ���ñ������
	void SetBkStyle(const UGStyle& style);							
	//! \brief   �õ���ת�Ƕ�
	double GetAngle()const;											
	//! \brief   ������ת�Ƕ�
	void SetAngle(double dAngle);									

	//! \brief   �Ƿ���Ʊ���
	UGbool IsPaintBackground() const;
	//! \brief   �����Ƿ���Ʊ���
	void SetPaintBackground(UGbool bPaintBackground = true);
	
	//! \brief   ��ȡ��ͼ��XML��Ϣ
	UGbool FromXML(const UGString& strXML, UGbool bIgnoreLayerCaption = true, UGint nVersion = 0, UGbool bIgnoreLayers = false);
	//! \brief   �����ͼΪXML
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief   �򿪹����ռ���ָ���ĵ�ͼ
	UGbool Open(const UGString& strMap);
	//! \brief   ��XML��Ϣ��ָ���ĵ�ͼ
	UGbool OpenXML(const UGString& strXML, UGbool bIgnoreLayerCaption = true, UGint nVersion = 0, UGbool bIgnoreLayers = false);
	//! \brief   ���Ϊ�����ռ���ָ���ĵ�ͼ
	UGbool SaveAs(const UGString& strMap, UGbool bOverWrite = false);	
	//! \brief   �����ͼ
	UGbool Save();


	UGbool OpenDataset();


	//! \brief   �ж��Ƿ���selection��Ҫ����
	UGbool RequireHighlightSelection();
	//! \brief   ��������ͼ���m_Selection
	void HighlightSelection(UGGraphics* pGraphics);
	//! \brief   ���Ʊ���
	UGbool PaintBackground(UGGraphics* pGraphics, UGRect rcErase);
	//! \brief ���Ʊ�������
	UGbool DrawBKGrid(UGGraphics* pGraphics/*,UGMap::UGTypeOption nTypeGrid = UGMap::UGGridGrid*/);
	
	//! \brief �����������ֵ.
	//! \param nMaxGrid �������ֵ[in]��
	//! \remarks nMaxGrid Ϊ����0������ֵ��������60--100�ڣ������Ӱ��Ч�ʣ���С�в����ۡ�
	//! \attention ��
	void SetMaxGrid(UGint nMaxGrid);	
	//! \brief ��ȡ�������ֵ
	UGint GetMaxGrid();
// 	//! \brief ��������size��������
// 	void SetMpExtend(UGSize2D& sz2DExtend);
// 	UGSize2D GetMpExtend();
	//! \brief ��������size�豸����
	void SetGridExtend(const UGSize2D& szExtend);
	//UGSize GetDpExtend();
	UGSize2D GetGridExtend();
	//! \brief ���û��Ʒ�Χ
	void SetGridRect(UGRect2D& rcGrid);
	UGRect2D GetGridRect();
	//! \brief ���û�����������
	void SetGridType(UGGridType nGridType);
	UGGridType GetGridType();
	//! \brief �Ƿ�̶�����
	void SetFixedGrid(UGbool bFixed = true);
	UGbool IsFixedGrid();
	//! \brief ������ʾ����
	void SetShowGrid(UGbool bShowGrid);
	UGbool IsShowGrid();
	//! \brief   ���Ƶ�ͼ
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param rcDevBounds				������Ƶ��豸��Χ[in]
	\param rcInvalid				����ָ���ڲ��������»��Ƶ����ݣ���ͨ���޸��߼���Χ��ʵ�ֵģ���Ҫ�ⲿ���л�ԭ[in]
	\param pbBlank					�Ƿ��ǰ�ͼ[out]
	\param bIsPrinting				�Ƿ��ӡ[in]
	\param bFitToPage				�Ƿ����һҳ�Ĵ�ӡ��С��ֻ���ڴ�ӡ[in]
	\param bMapModeInitialize		�Ƿ��ʼ����ͼģʽ[in]
	\param pProgress				����������[in]
	\param bOnlyPaintBackground		�Ƿ�ֻ���Ʊ���
	\return �����Ƿ�ɹ�
	*/
	UGbool OnDraw(UGGraphics* pGraphics, UGRect rcDevBounds, UGRect rcInvalid, UGbool *pbBlank = NULL,
		UGbool bIsPrinting = false, UGbool bFitToPage = false, 
		UGbool bMapModeInitialize = true, UGProgress* pProgress = NULL,
		UGbool bOnlyPaintBackground = false);

	//! \brief   ʸ����ӡ��ͼ
	/**
	\param pGraphics				��ӡ����Graphics[in]
	\param rcDevBounds				��ӡ�����豸��Χ[in]
	\param rcMapBounds				��ͼ��Χ[in]
	\param dPrintScale				���ô�ӡ�ı���[in]
	\param bCentered				�Ƿ��յ��豸��Χ�����Ĵ�ӡ[in]
	\param bMapModeInitialize		�Ƿ��ʼ����ͼģʽ[in]
	\param bPaintBackground			�Ƿ��ӡ����[in]
	\param bLytClip					�Ƿ��ǲ��ֲ������ͼ��ӡ�ü���in��
	\return ��ӡ�Ƿ�ɹ�
	*/
	UGbool OnPrint(UGGraphics* pGraphics, UGRect rcDevBounds, const UGRect2D& rcMapBounds,
		UGdouble dPrintScale, UGbool bCentered = true, UGbool bMapModeInitialize = true, 
		UGbool bPaintBackground = false, UGbool bShowGrid = false, UGbool bLytClip = false);
	
	//! \brief   դ�񻯴�ӡ��ͼ
	/**
	\param pGraphics				��ӡ����Graphics[in]
	\param rcDevBounds				��ӡ�����豸��Χ[in]
	\param rcMapBounds				��Ҫ��ӡ�ĵ�ͼ��Χ[in]
	\param dPrintScale				���ô�ӡ�ı���[in]
	\param dDPIScale				���ǵ�ģ���DPI���ӡ����ʵ��DPI�ı�ֵ
	\param bCentered				�Ƿ����豸��Χ�����Ĵ�ӡ[in]
	\param bMapModeInitialize		�Ƿ��ʼ����ͼģʽ[in]
	\param bPaintBackground			�Ƿ��ӡ����[in]
	\return ��ӡ�Ƿ�ɹ�
	*/
	UGbool OnPrintRaster(UGGraphics* pGraphics, UGRect rcDevBounds, 
		const UGRect2D& rcMapBounds, UGdouble dPrintScale,UGdouble dDPIScale = 1, 
		UGbool bCentered = true, UGbool bMapModeInitialize = true, 
		UGbool bPaintBackground = false,UGbool bShowGrid = false);
	
	//! \brief   ���Ƽ��ζ���
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param pGeometry				���Ƶļ��ζ���[in]
	\param pStyle					���Ʒ��[in]
	\return 
	*/
	UGbool DrawGeometry(UGGraphics* pGraphics, UGGeometry* pGeometry, UGStyle* pStyle = NULL);

	//! \brief   ���Ϊ��ͼ
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param rcBounds					����ͼƬ��С[in]
	\param pbBlank					���Ƶ�ͼƬ�Ƿ��ǰ�ͼ[out]
	\param bNoBackground			�Ƿ���Ʊ���[in]
	\param bClipContent				û���õ�[in]
	\param bCopyFromCache			û���õ�[in]
	\param bEntireMap 				�Ƿ��������[in]
	\param pProgress 				���ڼ��������������Ϣ[in] add by wangna��2011-10-5
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputMap(UGGraphics* pGraphics, UGRect rcBounds, UGbool *pbBlank = NULL, UGbool bNoBackground = false, 
		UGbool bClipContent = false, UGbool bCopyFromCache = false, UGbool bEntireMap = false, UGProgress *pProgress = NULL);

	//! \brief   ���Ϊ��ͼ
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param rcBounds					����ͼƬ��С[in]
	\param bTranspencyBackGroud		�Ƿ񱳾�͸��[in]
	\param bBkgColorTranspency		�Ƿ񱳾�ɫ͸��[in]
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputMapToMemory(UGGraphics* pGraphics, UGRect rcBounds, UGbool bTranspencyBackGroud = false, UGbool bBkgColorTranspency = false);

	//! \brief   �������ͼ��
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param rcBounds					����ͼƬ��С[in]
	\param nTransparentColor		͸��ɫ������ɫ��[in]
	\param bClipContent				û���õ�[in]
	\param bEntireMap 				�Ƿ��������[in]
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputTrackingLayer(UGGraphics* pGraphics, UGRect rcBounds, 
		UGColor nTransparentColor = UGRGB(1,1,1), UGbool bClipContent = false,
		UGbool bEntireMap = false);

	//! \brief   �������ͼ��(����DPI)
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param strFileName				����ļ�����[in]
	\param rcBounds					����ͼƬ��С[in]
	\param nDPI                     �������ͼ���DPI[in]
	\param nTransparentColor		͸��ɫ������ɫ��[in]
	\param nCompress				���ͼƬ��ѹ����[in]
	\param bEntireMap 				�Ƿ��������[in]
	\return �����ͼ�Ƿ�ɹ�
	*/
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	UGbool OutputTrackingLayerEx(UGGraphics* pGraphics, const UGString& strFileName, 
		UGRect2D rcBounds, UGint nDPI = 200, UGColor nTransparentColor = UGRGB(1,1,1),
		UGint nCompress = 75, UGbool bEntireMap = false);


	//! \brief   ����豸ͼ��
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param rcBounds					����ͼƬ��С[in]
	\param nTransparentColor		͸��ɫ������ɫ��[in]
	\param bClipContent				û���õ�[in]
	\param bEntireMap 				�Ƿ��������[in]
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputUGDeviceTrackingLayer(UGGraphics* pGraphics, UGRect rcBounds, 
		UGColor nTransparentColor = UGRGB(1,1,1), UGbool bClipContent = false, 
		UGbool bEntireMap = false);

	//! \brief   ����豸ͼ��
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param strFileName				����ļ�����[in]
	\param rcBounds					����ͼƬ��С[in]
	\param nDPI                     ����豸ͼ���DPI[in]
	\param nTransparentColor		͸��ɫ������ɫ��[in]
	\param nCompress				���ͼƬ��ѹ����[in]
	\param bEntireMap				�Ƿ��������[in]
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputUGDeviceTrackingLayerEx(UGGraphics* pGraphics, 
		const UGString& strFileName, UGRect2D rcBounds, UGint nDPI = 200,
		UGColor nTransparentColor = UGRGB(1,1,1), 
		UGint nCompress = 75, UGbool bEntireMap = false);
#endif
	//! \brief   ���Ϊ��ͼ
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param szBitmap					����ͼƬ��С[in]
	\param strFileName				ͼƬ�����·��������[in]
	\param bEntireMap				�Ƿ��������[in]
	\param strDescription			�ļ�����
	\param nImageType				ͼƬ���� ,����ʱemf��wmf[in]
	\remarks EMF��WMF��ʽ��֧��Windowsƽ̨
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputMapToEMF(UGGraphics* pGraphics, UGSize szBitmap, 
		const UGString& strFileName, UGString& strDescription,
		UGbool bEntireMap = false, UGint nImageType = UGFileType::EMF);

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//! \brief   ���Ϊ��ͼ
	/**
	\param pGraphics				��Graphics�������ṩɫ��λ����Ϣ�����������ݵ�Graphcis������ΪNULL[in]
	\param szBitmap					����ͼƬ��С��DP[in]
	\param strFileName				ͼƬ�����·��������[in]
	\param nImageType				ͼƬ����[in]
	\param bEntireMap				�Ƿ��������[in]
	\param nCompress  				�Ƿ�ѹ��,Ŀǰ��֧��jpg[in]
	\param bTranspencyBackGroud		�Ƿ�͸������[in]
	\param pbigCache				��������ļ�����
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputMapToFile(UGGraphics* pGraphics, UGSize szBitmap,
		const UGString& strFileName, UGint nImageType, UGbool bEntireMap = false, 
		UGint nCompress = 100, UGbool bTranspencyBackGroud = FALSE,
		UGCacheFile* pbigCache=NULL);

	//! \brief   ���Ϊ��ͼ
	/**
	\param pGraphics				��Graphics�������ṩɫ��λ����Ϣ�����������ݵ�Graphcis������ΪNULL[in]
	\param strFileName				ͼƬ�����·��������[in]
	\param nImageType				ͼƬ����[in]
	\param rcBounds					�����ͼ�ĵ���Χ��MP[in]
	\param nDPI						�����ͼ��DPI
	\param nCompress  				�Ƿ�ѹ��[in]
	\param bShowProgress			�Ƿ���ʾ������
	\param bTranspencyBackGroud     �Ƿ񱳾�͸��
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputMapToFileEX(UGGraphics* pGraphics, const UGString& strFileName, UGint nImageType,UGRect2D& rcBounds, UGint nDPI = 200, UGint nCompress = 75, UGbool bShowProgress = true, UGbool bTranspencyBackGroud = false);
#endif
	//! \brief   ���Ϊ��ͼ
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param pDestDataSource			���Ƶ�����Դ[in]
	\param strDatasetName			���Ƶ�����Դ�����ݼ���[in]
	\param dResolution				���Ƶı���[in]
	\param rcBounds					��ʾ��Χ[in]
	\param pbBlank					���ɵ��Ƿ��ǿհ�ͼ[out]
	\param bShowProgress   			�Ƿ���ʾ������[in]
	\param nEncType [in] ���뷽ʽ��
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGDatasetRaster* OutputMapEx(UGGraphics* pGraphics, UGDataSource* pDestDataSource, 
		const UGString& strDatasetName, double dResolution, UGRect2D& rcBounds, UGbool *pbBlank = NULL,
		UGbool bShowProgress = true, UGDataCodec::CodecType nEncType = UGDataCodec::encNONE);

	//! \brief ���Ϊ��ͼΪӰ�����ݼ���
	//! \param *pGraphics [in]��
	//! \param pDestDataSource ����Դ[in]��
	//! \param strDatasetName ���ݼ�����[in]��
	//! \param dResolution ���Ƶı���[in]��
	//! \param rcBounds ��ʾ��Χ[in]��
	//! \param bShowProgress �Ƿ���ʾ������[in]��
	//! \param nEncType [in] ���뷽ʽ��
	//! \param bBlank	[out] ���ɵ��Ƿ��ǿհ�ͼ
	//! \return ��
	//! \remarks ��
	//! \attention ��
	//UGDatasetRaster* OutputMap(UGGraphics *pGraphics,UGDataSource * pDestDataSource,
	//const UGString& strDatasetName, UGdouble dResolution,
	//UGRect2D& rcBounds, UGbool bShowProgress,UGDataCodec::CodecType nEncType, UGbool &bBlank);

	//! \brief   ���Ϊ��ͼ
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param strFileName				ͼƬ���·��������[in]
	\param rcBounds					��ʾ��Χ[in]
	\param nDPI						ͼƬ����[in]
	\param bShowProgress 			�Ƿ���ʾ������[in]
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputMapToBMP(UGGraphics* pGraphics, const UGString& strFileName, 
		UGRect2D& rcBounds, UGint nDPI = 200, UGbool bShowProgress = true);
	
	//! \brief   �����ͼΪeps�ļ�
	/**	
	//! \param strFileName				ͼƬ���·��������[in]	
	//! \param bTextToVector			�Ƿ�����ʸ����[in]	
	//! \param bEntireMap				�Ƿ�ȫ�����[in]	
	//! \return �����ͼ�Ƿ�ɹ�
	//! \attion ĿǰEPS��֧�ְ�͸����������Ч����
	*/
	UGbool OutputMapToEPS(UGSize szBitmap, const UGString& strFileName, 
		UGbool bTextToVector = false, UGbool bEntireMap = false);

	//{{added by macx 2008.7 ���PDF�ӿ�
	//! \brief   �����ͼΪPDF�ļ� 
	/**	
	//! \param strFileName				ͼƬ���·��������[in]	
	//! \param bTextToVector			�Ƿ�����ʸ����[in]	
	//! \param bEntireMap				�Ƿ�ȫ�����[in]	
	//! \return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputMapToPDF(UGSize szBitmap, const UGString& strFileName, const UGchar* optlist = NULL, const UGchar* optlist_page = NULL, UGbool bDeviceTrackingLayer = FALSE, UGbool bTrackingLayer = FALSE, UGbool bEntireMap = false);
	//!brief ԭʼ״̬�����PDF��Image���
	UGbool OutputImageToPDF(UGSize szBitmap, const UGString& strFileName, const UGchar* optlist = NULL, const UGchar* optlist_page = NULL, UGbool bDeviceTrackingLayer = FALSE, UGbool bTrackingLayer = FALSE, UGbool bEntireMap = false);
	
	//! \brief ���PDF���ܽӿڽӿڡ�
	//! \param szBitmap  ��Χ[in]��
	//! \param strFileName ���·��������[in]��
	//! \param nTypeOption ������ͣ���ʸ������դ����ʽ[in]��
	//! \param nStyle ����������ã����Ƿ����߷��ţ�����nTypeOptionΪNOMALʱ����[in]��
	//! \param optlist �ĵ���������[in]��
	//! \param optlist_page ҳ������[in]��
	//! \param bEntireMap	�Ƿ�ȫ�����[in]��
	//! \return �Ƿ�ɹ�
	UGbool OutputToPDF(UGSize szBitmap, const UGString& strFileName,
		UGint nTypeOption, UGint nStyle = UG_STYLE_ALLSTYLE, 
		const UGchar* optlist = NULL, const UGchar* optlist_page = NULL, 
		UGbool bDeviceTrackingLayer = FALSE, UGbool bTrackingLayer = FALSE, 
		UGbool bEntireMap = false);	
	//}}

	//!brief ԭʼ״̬�����XPS��Image���,Add by tangzq in 2009-2-22
	//! \brief ���PDF���ܽӿڽӿڡ�
	//! \param szBitmap  ��Χ[in]��
	//! \param strFileName ���·��������[in]��
	//! \param nTypeOption ������ͣ���ʸ������դ����ʽ[in]��
	//! \param nStyle ����������ã����Ƿ����߷��ţ�����nTypeOptionΪNOMALʱ����[in]��
	//! \param optlist �ĵ���������[in]��
	//! \param optlist_page ҳ������[in]��
	//! \param bEntireMap	�Ƿ�ȫ�����[in]��
	UGbool OutputMapToXPS(UGSize szBitmap, const UGString& strFileName, 
		const UGchar* optlist = NULL, const UGchar* optlist_page = NULL,
		UGbool bEntireMap = false);

	UGbool OutputToXPS(UGSize szBitmap, const UGString& strFileName, 
		UGint nTypeOption, UGint nStyle = UG_STYLE_ALLSTYLE, 
		const UGchar* optlist = NULL, const UGchar* optlist_page = NULL,
		UGbool bEntireMap = false);

	//! \brief   �õ���ͼ������
	UGdouble GetScale()const;
	//! \brief   ���õ�ͼ������
	//! \brief   �������ñ������Ƿ�ɹ���modified by zhengyl at 2011-9-2 ��dScaleΪ0ʱ����false
	UGbool SetScale(UGdouble dScale);
	//! \brief   �õ���ͼ���ĵ�
	UGPoint2D GetCenter()const;										
	//! \brief   ���õ�ͼ���ĵ�
	void SetCenter(const UGPoint2D& pntCenter);						

	//! \brief   ƽ��
	void Pan(UGdouble dOffsetX, UGdouble dOffsetY);
	//! \brief   �Ŵ���С
	void Zoom(UGdouble dZoomRatio);
	//! \brief   ����
	UGbool ViewEntire(const UGRect rcDevice = UGRect(0,0,0,0));
	
	//! \brief   ��ȡ��ͼ��Χ
	UGRect2D GetBounds()const;
	//! \brief   �õ���ͼ��ʾ��Χ
	UGRect2D GetViewBounds()const;
	//! \brief   ���õ�ͼ��ʾ��Χ�����û�����ù̶������ߣ�������óɲ������ƶ��ģ����򣬲��Ҳ����ó��������ӽ��Ĺ̶������ߡ�
	void SetViewBounds(const UGRect2D& rcMapViewBounds,UGbool bByWidth = false);

	//! \brief   ������¼�
	UGbool HitTest(UGPoint2D pntHitTest, UGdouble dTolerance, UGbool bAppendMode = false,
		UGbool bControlMode = false, UGbool bShiftMode = false);
	//! \brief   �õ�������
	UGDrawing* GetDrawing();

	//added by xielin 2007-04-13
	//! \brief �����Ƿ������ͼ��༭ģʽ 
	void SetMultiLayerEditEnable(UGbool bMultiLayerEditEnable);
	//added by xielin 2007-04-13
	//! \brief �����Ƿ������ͼ��༭ģʽ 
	UGbool IsMultiLayerEditEnable();


	
	//added by xielin 2007-04-13
	//! \brief �����Ƿ�����༭��������ʾ 
	void SetShowTrackingTooltips(UGbool bTrackingTooltips);
	//added by xielin 2007-04-13
	//! \brief �����Ƿ�����༭��������ʾ 
	UGbool IsShowTrackingTooltips();
	
	//added by xielin 2007-04-13

	//! \brief ���õ�ǰͼ�㣬���ڶ�ͼ��༭���ڶ�ͼ��༭�У���Ϊ������ͼ��ͬʱ�༭������趨��ǰͼ�����ӵĶ���ͷŵ�
	//! ���õĵ�ǰͼ���У���������õ�ǰͼ�㣬Ĭ�Ͼ��ǿɱ༭�ĵ�һ��ͼ�� 
	void SetCurrentLayer(UGLayer* pLayer);

	//added by xielin 2007-04-13
	//! \brief ��ȡ��ǰͼ�㣬���ڶ�ͼ��༭���ڶ�ͼ��༭�У���Ϊ������ͼ��ͬʱ�༭������趨��ǰͼ�����ӵĶ���ͷŵ�
	//!���õĵ�ǰͼ���У���������õ�ǰͼ�㣬Ĭ�Ͼ��ǿɱ༭�ĵ�һ��ͼ�� 
	UGLayer* GetCurrentLayer();

	//! \brief ��ȡ��ͼ�����hashcode
	UGString GetHashCode(UGint nImageFileType) const;

	//! \brief �õ������Ƿ�ʹ����ʾ�ü�����
	UGbool IsDisplayClip() const;						
	//! \brief �õ��Ƿ�ʹ����ʾ�ü�����
	void SetDisplayClip(UGbool bIsDisplayClip);			

	//! \brief �õ���ʾ�ü�����
	void GetDisplayClipRegion(UGGeoRegion& geoClipRegion) const;
	//! \brief �õ��Ƿ�ʹ����ʾ�ü�����
	void SetDisplayClipRegion(UGGeoRegion& geoClipRegion);

	//! \brief �Ƿ���ʾ�û�ָ����Χ
	UGbool IsUserEntireBounds();
	//! \brief �趨�Ƿ���ʾ�û�ָ����Χ
	void SetIsUserEntireBounds(UGbool bIsUserEntireBounds);

	//! \brief �õ��û�ָ����ʾ��Χ
	UGRect2D GetUserEntireBounds();
	//! \brief �û�ָ����ʾ��Χ
	void SetUserEntireBounds(const UGRect2D& rc2UserEntireBounds);

	//! \brief �����û�ָ����ʾ����
	void ImportDisplayScales(UGString strXmlPath);
	//! \brief �õ��û�ָ����ʾ����
	void ExportDisplayScales(UGString strXmlPath);
	//! \brief �Ƿ�����û���ʾ����

	//! \brief �����û�ָ����ʾ����
	void SetDisplayScales(UGArray<UGdouble> arrDisplayScales);
	//! \brief �õ��û�ָ����ʾ����
	void GetDisplayScales(UGArray<UGdouble>& arrDisplayScales);
	//! \brief �Ƿ�����û���ʾ����
	void SetDisplayByScales(UGbool bDisplayByScales);
	//! \brief �����Ƿ�����û���ʾ����
	UGbool IsDisplayByScales() const;
	//! \brief ��ȡ/��������ʾ�Ķ������ڵ�������������ڵ�Ķ���Ͳ���ʾ
	UGint GetMaxVisibleVertex() const;
	void SetMaxVisibleVertex(UGint nMaxVisibleVertex);

	//added by xielin 2007-11-15 ����һ���ӿڣ��������û���ͼ����Ƿ������ͷż�¼��
	//! \brief ��ȡ/���û���ͼ����Ƿ������ͷż�¼����Ĭ��iserver��Ʒ�����ͷţ���������Ʒ�������ͷţ���Ϊ��׽��ѡ�񶼻��õ���ʾ�ļ�¼��
	void SetReleaseDisplayRecordset(UGbool bRelease = true);
	UGbool IsReleaseDisplayRecordset();

	UGbool OnSize(UGGraphics* pGraphics, const UGRect& rcNewClient);
	//modefied by macx 2008-9-27 ��ͼ��͸����
	//! \brief ����map��͸����
	//! \param nTransPercent	͸����[in]
	void SetTransPercent(UGuint nTransPercent);
	//! \brief ��ȡmap��͸����
	UGuint GetTransPercent();

	//! \brief ���õ�ͼ���ſ���Ϣ
	//! \remarks ���pResourcesΪ�գ������õ�ͼ���ſ�Ϊ��
	void SetMapResources(UGResources* pResources,UGbool bCopy = false);
	//! \brief ��ȡ��ͼ���ſ���Ϣ
	UGResources* GetMapResources();
	//! \brief �����Ƿ���õ�ͼ���ſ�
	void SetUseMapResource(UGbool bIsUseMapSources = false);
	//! \brief ��ȡ�Ƿ���õ�ͼ���ſ�
	//! \remarks �����˹����ҵ�ͼ���ſ���Ϣ��Ϊ��
	UGbool IsUseMapResource();
	
	//! \brief ���ñ�������ķ��
	//! \param style ����ķ��[in]��
	void SetGridStyle(const UGStyle& style);	
	//! \brief ��ȡ��������ķ��
	UGStyle& GetGridStyle();
	//! \brief ���ñ����������ķ��
	//! \param style �������ķ��[in]��
	void SetGridSpaceStyle(const UGStyle& style);
	//! \brief ��ȡ�����������ķ��
	UGStyle& GetGridSpaceStyle();

	//! \brief ���õ�ͼȫ����ʾ�ı߽緶Χ
	void SetMarginWidthViewEntire(UGint nMarginWidthViewEntire);
	//! \brief ��ȡ��ͼȫ����ʾ�ı߽緶Χ
	UGint GetMarginWidthViewEntire();
	
#if !defined SYMBIAN60 
	//! \brief ��ȡUGImage�����ݡ�
	//! \param nType		[in]Ҫת����ͼƬ���͡�
	//! \param pImage		[in]�����UGIamge��
	//! \param ImageData	[in]��ȡ��ͼ�����ݡ�
	//! \param bFree		[in]�Ƿ��ͷ�ImageData��
	//! \param bCopyFormCach [in]�Ƿ����Ļ����
	//! \return ��
	//! \remarks ��
	//! \attention ʹ�����Ҫdelete []imageData.pBits��
	static void ConvertImageData(UGint nType, UGImage* pImage, UGImageData& ImageData,UGbool& bFree, UGbool bCopyFormCach = false);
#endif
	//! \brief �ýӿڲ����⿪��
	void ZoomWhenFirstViewMap();
protected:	
	
	void SetMapOpenedFunc(MapOpenedProc pMapOpenedFunc, UGlong pMapWnd);
	void SendMapOpenedFunc();

	//! \brief �Ƿ���Ϳ����ڼ�����
	UGbool IsNeedLayerClip();

protected:

	//! \brief ���Ʋ�ͬ��񱳾�����
	UGbool DrawGrid(UGGraphics* pGraphics,const UGPoint2D& pntStart,const UGPoint2D& pntEnd,const UGSize2D& szExtend,UGGridType nTypeGrid = UGMap::UGGridGrid);
	UGbool DrawGridGrid(UGGraphics* pGraphics,const UGPoint2D& pntStart,const UGPoint2D& pntEnd);
	UGbool DrawGridCross(UGGraphics* pGraphics,const UGPoint2D& pntStart,const UGPoint2D& pntEnd,const UGSize2D& szExtend);
	UGbool DrawGridPoint(UGGraphics* pGraphics,const UGPoint2D& pntStart,const UGPoint2D& pntEnd,const UGSize2D& szExtend);

	UGbool CopyResource(UGResources* pResources,UGbool bCopy = true);
	void SetResource(UGResources* pResources);
	UGbool OutputTrackingLayer(UGGraphics* pGraphics,UGTrackingLayer* pTrackingLayer, UGRect rcBounds, UGColor nTransparentColor, UGbool bClipContent, UGbool bEntireMap);
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	UGbool OutputTrackingLayerEx(UGGraphics* pGraphics,UGTrackingLayer* pTrackingLayer, const UGString& strFileName, UGRect2D rcBounds, UGint nDPI, UGColor nTransparentColor, UGint nCompress, UGbool bEntireMap);
	//{{ added by lidl 2009-5-7 ��ͼʱ��UGImage�����ȡ����
	
	//! \brief ��ȡUGImage�����ݡ�
	//! \param pImage [in]�����UGIamge��
	//! \param ImageData [in]��ȡ��ͼ�����ݡ�
	//! \return ��
	//! \remarks ��
	//! \attention ʹ�����Ҫdelete []imageData.pBits��
	static void GetBmpImageData(UGImage* pImage, UGImageData& ImageData,UGbool& bFree);

	//! \brief ��ȡUGImage�����ݡ�
	//! \param pImage [in]�����UGIamge��
	//! \param ImageData [in]��ȡ��ͼ�����ݡ�
	//! \return ��
	//! \remarks ��
	//! \attention ʹ�����Ҫdelete []imageData.pBits��
	static void GetJPGImageData(UGImage* pImage, UGImageData& ImageData,UGbool& bFree);	
#endif
	//! \brief ��ȡUGImage�����ݡ�
	//! \param pImage [in]�����UGIamge��
	//! \param ImageData [in]��ȡ��ͼ�����ݡ�
	//! \param bCopyFormCach [in]�Ƿ����Ļ����
	//! \return ��
	//! \remarks ��
	//! \attention ʹ�����Ҫdelete []imageData.pBits��
	static void GetPngImageData(UGImage* pImage, UGImageData& ImageData,UGbool& bFree, UGbool bCopyFormCach = false);	

	//! \brief ��ȡUGImage�����ݡ�
	//! \param pImage [in]�����UGIamge��
	//! \param ImageData [in]��ȡ��ͼ�����ݡ�
	//! \return ��
	//! \remarks ��
	//! \attention ʹ�����Ҫdelete []imageData.pBits��
	static void GetGifImageData(UGImage* pImage, UGImageData& ImageData,UGbool& bFree);	
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//! \brief ��ȡUGImage�����ݡ�
	//! \param pImage [in]�����UGIamge��
	//! \param ImageData [in]��ȡ��ͼ�����ݡ�
	//! \param bFree [in]�Ƿ���Ҫ�ͷ��ڴ�
	//! \return ��
	//! \remarks ��
	//! \attention ʹ�����Ҫdelete []imageData.pBits��
	static void GetTiffImageData(UGImage* pImage, UGImageData& ImageData, UGbool& bFree);
	//}} added by lidl 2009-5-7 ��ͼʱ��UGImage�����ȡ����
#endif
public:
	//! \brief ͼ�㼯��
	UGLayers m_Layers;
	//! \brief ����ͼ��
	UGTrackingLayer m_TrackingLayer;

	//add by xiaoys 2012-0627
	UGTrackingLayerEx m_TrackingLayerEx;

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//! \brief ��Ƹ���ͼ��
	UGDeviceTrackingLayer m_DeviceTrackingLayer;
#endif

	//! \brief ȫ���߽�
	UGint m_nMarginWidthViewEntire;
	//deleted by xielin 2007-05-16 ��Ϊÿ��layer����һ��m_Selection,�ó�Ա����������
	//UGSelection	m_Selection;
	//added by xielin 2007-08-21 
	//! \brief �жϵ�ͼ�Ƿ�����ˢ�¡��������»��ƶ����ˡ��ڱ༭��ʱ���õ�
	UGbool m_bRefresh;
	//! \brief MapOpened�ص�
	MapOpenedProc m_MapOpenedFunc;

	//! \brief ����ͼ������
	/**
	\param pDs						�����UDB����Դ[in]
	\param strFileName				����·��[in]
	\param bOverWrite				�Ƿ�ǿ�Ƹ���[in]
	\param bUniteFile				�Ƿ�ϲ���һ���ļ���in��
	\return �����Ƿ�ɹ�
	*/
	static UGbool SaveAsUDBFile(const UGDataSource* pDs,const UGString& strFileName ,
		UGbool bOverWrite,UGbool bUniteFile = false);
	
	//! \brief 
	void SendBeforeMapDrawFunc(UGbool& bCancel,UGGraphics* pGraphics);
	//! \brief 
	void SendAfterMapDrawFunc(UGGraphics* pGraphics);

	//! \brief 
	void SetBeforeMapDrawFunc(BeforeMapDrawProc pBeforeMapDrawFunc,UGlong pWnd);
	//! \brief 
	void SetAfterMapDrawFunc(AfterMapDrawProc pAfterMapDrawFunc,UGlong pWnd);

	//!brief �����Ƿ����¼���Ĭ��Ϊtrue
	void SetNeedSendEvent(UGbool bNeedSendEvent = true);
	//!brief �����Ƿ������˷����¼�
	UGbool IsNeedSendEvent();

	//!brief �����Ƿ��ǲ��ֻ��ƣ���Ҫ���ڲ��ֳ�ͼ�ǵ��жϣ�Ĭ��Ϊtrue
	void SetIsLayoutDraw(UGbool bLayoutDraw = true);
	//!brief �����ǲ��ֻ���
	UGbool IsLayoutDraw();

	//! \brief 
	void SendSnapableChangedFunc();

	//! \brief 
	void SetSnapableChangedFunc(SnapableChangedProc pSnapableChangedFunc,UGlong pWnd);


//added by qianjn in 2009-8-26 10:05:19 ����ԭ��

	// ����ȫ����ͼ
	UGbool SetViewGlobal(UGbool bViewGlobal);
	UGbool GetViewGlobal();
	
	// �Ƿ��ڳ�ͼ��ʱ��ص���ͼ�Ķ�̬Ч�� 2010-11-11 qianjn ���������
	UGbool IsDisableDynamicEffect();
	UGbool SetDisableDynamicEffect(UGbool bDisable);

	// �Ƿ��ڱ༭��ʱ��ʵʱˢ��,Ĭ��false����ʵʱˢ�µĻ���ʾ����󣬵����ڴ����ݵ�ʱ��ȽϿ�
	UGbool IsRealTimeRefresh();
	void SetRealTimeRefresh(UGbool bRealTimeRefresh);

	UGbool IsRefreshTrackingLayer();
	void SetRefreshTrackingLayer(UGbool bRefresh);

	// �Ƿ�ƽ��ˢ��
	UGbool IsPanRefresh();
	void SetPanRefresh(UGbool bPanRefresh);

	// ���沢�ҽ��ø���ͼ��Ķ�̬Ч������ǰ���ð���������ʾ���Զ���������Ч����
	void SaveAndDisableDynamicEffectSettings();

	// �ָ���ǰ����ĸ���ͼ��Ķ�̬Ч������ǰ���ð���������ʾ���Զ���������Ч����
	void RestoreDynamicEffectSettings();

	// �˺����Ѿ��� SaveAndDisableDynamicEffectSettings() �� RestoreDynamicEffectSettings() ���档
	// �ص���ͼ�Ķ�̬Ч����bEnableΪfalseʱ�ص���̬Ч����Ϊtureʱ�ָ���һ��Ҫ��ʹ���꼰ʱ�ָ���
	// �ú����ڽ��õ���̬Ч��֮ǰ�ᱣ�����ͼ�㶯̬Ч����ԭʼ���ã�֮���ٴε��øú�������ǰ���������ȫ���ָ���
	// ��������ñ���ͻָ����ε���֮�䷢���κ�ͼ���������Ļ�˳��Ĳ��������ᵼ�����ûָ�ʱ��δ������Ϊ��
	//void EnableDynamicEffect(UGbool bEnable);

	//! \brief �жϵ�ͼ���Ƿ��������ͼͼ��
	UGbool IsWebMapFlag();
	void SetWebMapFlag(UGbool bHasWebMap);

	//! \return ���µ�ͼ����
	void UpdateMapDrawParam();
	//! \return ��ȡ��ͼ���Ʋ���
	UGbool GetMapDrawParam(UGdouble& dMapScale, UGRect2D& rcViewBounds);

	//! \brief ���ݵ�ǰ�� viewBounds �� �����ߣ����ͻ�ȡ�����ͼ����ͼƬ����
	void RequestTile(UGbool bPanMode = false, UGbool bForceUpdate = false);

	//! \brief ͼ�������ݼ�������Ƭ
	void RequestTileEx(UGdouble dScale, UGRect2D& rcBounds);

	//! \brief ���»����ImageData
	UGbool UpdateCacheTile(UGint nExtTileSize = 1, UGbool bRemoveAll = true);

	//! \brief ��ȡ��ǰ������ƬDP-->LP��ת������
	UGdouble GetTileCoordRatio();

	void SetFirstRefreshWebMapFlag(UGbool bFirstRefreshWebMap);
	UGbool GetFirstRefreshWebMapFlag();

	void SetRefreshWebMapFlag(UGbool bRefreshWebMap);
	UGbool GetRefreshWebMapFlag();

	//! \brief  �����ӳ�������Ƭ��־
	void SetDelayRequestFlag(UGbool bDelay = false);
	//! \brief  �Ƿ��ӳ�������Ƭ
	UGbool IsDelayRequest() const;

	//! \brief  ���û�ȡ�ȴ�����������Ƭ��ʱ��
	void SetWaitRequestTime(UGint nWaitTime);
	UGint GetWaitRequestTime();

	UGbool IsDrawPermissionLogo(UGImageData& imageTarget, UGbool bCacheFile = false, UGbool bOutputMapToFile = true);

	// ��DrawPermissionLogo��Ϊ��̬��������CacheBuilder��Ҳ��ʹ��
	static void DrawPermissionLogo(UGGraphics* pGraphics, UGImageData& imageTarget);
	static UGImage* DrawPermissionLogo(UGGraphics* pGraphics, UGImage* pImageTarget);
	static void DrawPermissionLogo(UGGraphics* pGraphics, const UGSize& sz);

	//! \brief ����/��ȡ��ǰ��ͼ��DPI
	void SetMapDPI(UGdouble dMapDPI);
	UGdouble GetMapDPI();

	//! \brief ����/��ȡ�Ƿ�ʹ��ȫ��ϵͳ��DPI��Ĭ��Ϊfalse��falseʱʹ�õ�ͼ���õ�DPI
	UGbool IsUseSystemDPI();
	void SetUseSystemDPI(UGbool bUseSystemDPI);

	UGbool InitNetArithmetic();
	UGFishingNetArithmetic* GetNetArithmetic();

	void AdjustHighlightStyle(UGLayer* pLayer, UGStyle& style, const UGStyle& oldStyle, UGbool bCustomStyle = true);
	
	//!\ �жϺ��������ͼͼ��ĵ�ͼ�Ƿ��ʼ���ˣ�������������ͼͼ��ĵ�ͼ�Ե�һ�������ͼ����ʼ��
	UGbool IsWebMapInited();
	//!\ ���ð��������ͼ�ĵ�ͼ��ʼ����־
	void SetWebMapInited();

	UGTrackingMap* GetTrackingMap();

	UGbool IsBackDataMap();
	void SetBackDataMap(UGbool bBackDataMap);

protected:
	static void DrawPermissionLogo(UGGraphics* pGraphics, UGbool bCacheFile = false);
	UGint GetRandNamber(UGint nMax = 0, UGint nMin = 5);

	//! \brief �ж�ͼ����߷����Ƿ���͸��������
	UGbool IsHaveLayerOpaqueRate();

	UGbool m_bDisableDynamicEffect;
	UGDict<UGint, UGbool> m_aryDynamicEffect;
	std::queue<bool> m_queueFlow;	// �������ö�̬Ч��ʱ����������ʾ����
	std::queue<bool> m_queueAutoAvoid;	// �������ö�̬Ч��ʱ�����Զ���������
	UGbool m_bRealTimeRefresh;	// �ǲ��Ǳ༭��ʱ��ʵʱˢ��,Ĭ��false����ʵʱˢ�µĻ���ʾ����󣬵����ڴ����ݵ�ʱ��ȽϿ�
	UGbool m_bPanRefresh;	// �ǲ���ƽ��ˢ��
	UGbool m_bLayoutDraw;

	//! \brief ����ͼ���Ƿ��ʼ���ˣ�������ͼ��ʱ��ֻ��ʹ��һ�������ͼͼ��Ĳ����������ô˱�������ʾ 
	UGbool m_bWebLayerInited;

//added by qianjn in 2009-8-26 10:05:19 �������

protected:	
	UGDrawing m_Drawing;

public:
	UGString m_strName;		// XXX change to be private

protected:	
	//! \brief ͼ������
	UGString m_strDescription;			
	
	//! \breif ˢ�±�־
	UGbool m_bForceToRefresh;

	//! \brief ���±�־
	UGbool m_bModified;

	UGPrjCoordSys m_PrjCoordSys;

	//! \brief �����ı�����
	UGbool m_bAllowTextOverlap;	

	UGuint m_unOnTop;
	//UGbool m_bLabelAlwaysOnTop;			//��ǩר��ͼ�ö�
	//UGbool m_bGraduatedSymbolAlwaysOnTop;	//�ȼ�����ר��ͼ�ö�
	//UGbool m_bGraphAlwaysOnTop;			//ͳ��ר��ͼ�ö�
	UGbool m_bFirstTimeDraw;	

	//! \brief ��MapModeInitialize��MapModeRestoreʹ�ñ���ͻָ�UGGraphics������ǰ��ӳ��ģʽ������ԭ��
	UGint m_nSavedMapMode;
	UGPoint m_pntSavedWndOrg;

	UGbool m_bPaintBackground;

	//added by xielin 2007-04-13  
	//! \brief ������ʾ�༭�����е���ʾ 
	UGbool m_bShowTrackingTooltips;

	UGbool m_bDisplayByScales;

	// �̶�������
	UGArray<UGdouble> m_arrDisplayScales;

	//! \brief ͸����
	UGint m_nTransPercent;
	//! \brief ����׽��size
	//UGSize2D m_szExtend;
	UGlong m_pMapWnd;


// 	//! \brief ������,��������
// 	UGSize2D m_sz2DExtend;
// 	//! \brief ���������豸����
// 	UGSize m_szExtend;
	//! \brief ����ļ����ʽ,trueʹ���豸���꣬falseʹ�õ�������
	UGbool m_bFixedGrid;
	UGSize2D m_szGridExtend;
	//! \brief ��������ķ�ʽ
	UGGridType m_nGridType;
	//! \brief �ܱ߿հ�
	UGRect2D m_rcGrid;
	//! \brief ����������
	UGint m_nMaxGrid;
	//! \brief �Ƿ��������
	UGbool m_bShowGrid;
	//! \brief �������߷��
	UGStyle m_styleGrid;
	//! \brief ���������
	UGStyle m_styleSpace;

	//��ͼ���ſ���Ϣ
	UGResources* m_pResources;
	UGbool m_bIsUseMapSources;
	UGbool m_bNameNotEmpty;

	BeforeMapDrawProc m_pBeforeMapDrawFunc;
	AfterMapDrawProc m_pAfterMapDrawFunc;
	UGlong m_pEventView;  //�����¼��ص������Ķ���ָ�룬ͳһΪһ���ɣ���ʡ�ڴ�

	SnapableChangedProc m_pSnapableChangedFunc;
	UGlong m_pSnapableChangedEvent;  


	UGbool m_bFireMapEvent;//�Ƿ���Ҫ���Ϳؼ����¼���Ϣ,added by xielin ��ͼ�༭��ʱ�����ã������ûص�������������Ϣ

	UGbool m_bViewGlobal;

	// ������ǲ������ŵ�ͼ��ת��������������ת���
	UGbool m_bIsFillAngle;

	//�����Ƿ�֧���������Ż���add by tan��2011-1-11
	UGbool m_bIsSymbolFillIgnored;

	//��¼��ǰ����ͼƬ��ţ���Ҫ���ڶ�̬��ͼʱ�Ƿ���ʾˮӡ
	UGint m_nOutputFileNumber;
	//��¼�����ͼƬ���
	UGint m_nOutputFileRandNumber;

	// �������Ʊ��������Ƹ��ٲ�ˢ��(�޸���ʱ��ˢ�µ�ͼȻ�����ˢ�¸��ٲ���ͼû��ˢ�µ�����)
	UGbool m_bRefreshTrackingLayer; 

	// �����������ͼʹ��
	//�Ƿ��ǵ�һ��ˢ�������ͼ�������һ�δ������ͼ��ˢ�µ�����
	UGbool m_bFirstRefreshWebMap;
	//! \brief ��ͼ��ǰ�ı�����(�����ͼ�Ķ��̻߳�ʹ��)
	UGdouble m_dMapScale;
	//! \brief ��ͼ��ǰ��ViewBounds(�����ͼ�Ķ��̻߳�ʹ��)
	UGRect2D m_rcMapViewBounds;
	//! \brief ����ͬ��m_dCoordRatio
	UGMutex	m_MutexCoordRatio;
	//�Ƿ�ˢ�������ͼ
	UGbool m_bRefreshWebMapFlag;
	//! \brief ���ڶ��޸�ˢ�½��м���
	UGMutex	m_MutexRefreshWebMap;
	//! \brief �����Ƿ��ӳٷ��������ͼ����
	UGbool m_bDelayRequest;

	//! \brief ��ͼ�ȴ�������Ƭ�ӳ�ʱ��
	UGint m_nWaitRequestTime;
	
	//! \brief ���ڷ�װ��������������㷨
	UGFishingNetArithmetic* m_pNetArithmetic;

	//! \brief ���ڷ�װ��ͼҵ�����ݵĻ���(Ƕ��ʽʹ��)
	UGTrackingMap* m_pTrackingMap;

	// �ж��Ƿ��Ǳ�����ͼ��Ƕ��ʽ�����Ƿ��Ǳ�����ͼ����ҵ���ͼ��
	UGbool m_bBackDataMap;

private:
#if !defined OS_ANDROID && !defined IOS
	//! \brief ��ͼ������ add by liufang
	UGChartSetting* m_pChartSetting;
#endif

};

}

#endif // !defined(AFX_UGMAP_H__37037E0D_8ABC_413E_B8BE_2B8916F0319E__INCLUDED_)

