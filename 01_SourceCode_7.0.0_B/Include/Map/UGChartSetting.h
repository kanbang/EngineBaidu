// UGChartSetting.h: interface for the UGChartSetting class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGChartSetting.h   
   **************************************************************************************
    \author   �ܽ���
    \brief    ��ͼ��ʾ���������࣬����ͼ��ʾ�����Ĺ���                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2011 SuperMap Software Co., Ltd.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2011-04-12  �ܽ���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGCHARTSETTING_H_)
#define AFX_UGCHARTSETTING_H_

#include "ChartBase/UGChartLookupTable.h"
#include "ChartBase/UGChartColorTable.h"
#include "ChartBase/UGChartEnvironment.h"
#include "ChartToolkit/UGS57SpatialRelationshipParser.h"
#include "ChartToolkit/UGS57SpatialLineManger.h"

#include "Toolkit/UGLogFile.h"
#include "Engine/UGDatasetVector.h"
#include "FileParser/UGFileParseVector.h"
#include "Engine/UGDataSource.h"
#include "Map/UGChartSubLayer.h"

namespace UGC {
	class UGMap;

	class MAP_API UGChartSetting
	{
		friend class UGChartSubLayer;
	public:
		UGChartSetting(UGMap* pMap);
		UGChartSetting(const UGChartSetting& Map);
		~UGChartSetting();
		UGChartSetting& operator = (const UGChartSetting &Map);

	public: //! \brief ��չ����ع��ܽӿ�

		//! \brief �õ����õ���ʾ���ͣ����ƣ�
		UGString GetDisplayTypeName() const;
		//! \brief ������ʾ����
		UGbool SetDisplayTypeName(const UGString& strName);

		//! \brief ��ȡ��ʾ����,��ʾ�����������õ���ʾ�������ƾ���
		UGChartDisplayStyle::UGChartDisplayStyleType GetDisplayStyleType() const;

		//! \brief ��ȡ��ɫģʽ
		UGChartColorMode::UGS52ColorMode GetColourModeChart();
		//! \brief ������ɫģʽ
		UGbool SetColourModeChart(UGChartColorMode::UGS52ColorMode eColorMode);

		//! \brief �õ����õ���ʾ���ͣ����ƣ�S-52/IENC/INT
		UGChartDisplayCategory::UGS52DisplayCategory GetDisplayCategory();
		//! \brief ������ʾ����
		void SetDisplayCategory(UGChartDisplayCategory::UGS52DisplayCategory eDisplayCategory);

		//! \brief �õ����õ���������
		UGString GetFontName();
		//! \brief ������������
		void SetFontName(const UGString& strFontName);

		//! \brief �õ����õ������ֺ�
		UGdouble GetFontSize();
		//! \brief ���������ֺ�
		void SetFontSize(UGdouble dfFontSize);

		//! \brief �Ƿ�ʹ�÷��Ż�������߽�
		UGbool IsSymbolizedAreaBoundary() const;
		//! \brief ���÷��Ż�����߽�
		UGbool SetSymbolizedAreaBoundary(UGbool bSymbolizedBoundary = true);

		//! \brief �Ƿ�ʹ�ü򵥺�ͼ�����(��Ӧ���Ǵ�ͳֽ��ͼ���ţ�
		UGbool IsSimplifiedMarker() const;
		//! \brief �����Ƿ�ʹ���Ƿ�ʹ�ü򵥺�ͼ�����
		UGbool SetSimplifiedMarker(UGbool bSimplifiedMarker = true);

		//! \brief �Ƿ���ʾ�ı�
		UGbool IsDisplayTextMessage() const;
		//! \brief �����Ƿ���ʾ�ı�
		void SetDisplayTextMessage(UGbool bDisplayText = true);

		//! \brief �Ƿ��ı��Ա��ع���������ʾ��
		UGbool IsDisplayNational() const;
		//! \brief �����Ƿ��ı��Ա��ع���������ʾ��trueΪ�Ա��ع���������ʾ��false��Ӣ����ʾ
		void SetDisplayNation(UGbool bDisplayNation = true);

		//! \brief �Ƿ���ʾˮ���
		UGbool IsDisplaySounding() const;
		//! \brief �����Ƿ���ʾˮ���
		void SetDisplaySounding(UGbool bDisplaySounding = true);

		//! \brief ��ʾ�Ƿ�����С��ʾ���������
		UGbool IsMinVisibleScaleEnabled() const;
		//! \brief ������ʾ�Ƿ�����С��ʾ���������
		void SetMinVisibleScaleEnabled(UGbool bEnabled = true);

		//! \brief �õ���ȫˮ����
		UGfloat GetSafetyContour() const;
		//! \brief ���ð�ȫˮ��
		void SetSafetyContour(UGfloat dfSafetyDepth);

		//! \brief �õ�ǳˮ������
		UGfloat GetShallowContour() const;
		//! \brief ����ǳˮ������
		void SetShallowContour(UGfloat dfShallowDepth);

		//! \brief �õ���ˮ������
		UGfloat GetDeepContour() const;
		//! \brief ������ˮ������
		void SetDeepContour(UGfloat dfDeepDepth);

		//! \brief �õ���ȫˮ��ֵ
		UGfloat GetSafetyDepth() const;
		//! \brief ���ð�ȫˮ��ֵ
		void SetSafetyDepth(UGfloat dfSafetyDepth);

		//! \brief �Ƿ���ʾ�����ĵ����߱�ע��(��������ȫ�����߱�ע)
		UGbool IsDisplayOtherContourLabel()const;
		//! \brief ������ʾ�����ĵ����߱�ע��(��������ȫ�����߱�ע)
		void SetDisplayOherContourLabel(UGbool bDisplayLabel);

		//! \brief �Ƿ���������ɫ��ʾˮ����
		UGbool IsDisplayTwoShades() const;
		//! \brief ������������ɫ��ʾˮ����
		void SetDisplayTwoShades(UGbool bTwoShades);

		//! \brief �Ƿ���ʾ��ȫ�����߱�ǩ����ȫˮ��ֵ��
		UGbool IsDisplaySafetyContourLabel()const;
		//! \brief �����Ƿ���ʾ��ȫ�����߱�ǩ����ȫˮ��ֵ��
		void SetDisplaySafeContourLabel(UGbool bDisplayLabel);

		//! \brief �Ƿ���ʾԪ���
		UGbool IsDisplayMetaObject() const;
		//! \brief �����Ƿ���ʾԪ���
		void SetDisplayMetaObject(UGbool bDisplayMetaObject = true);

		//! \brief �Ƿ���ʾͼ�����(DSNM)
		UGbool IsDisplayCellName() const;
		//! \brief �����Ƿ���ʾͼ�����(DSNM)
		void SetDisplayCellName(UGbool bDisplayCellName = true);

		//! \brief   ��ȡ��ͼ��XML��Ϣ
		UGbool FromXML(const UGString& strXML);
		//! \brief   ���溣ͼΪXML
		UGString ToXML()const;

		//! \brief  �������ó�ʼ��״̬
		void Reset(UGMap* pMap);

		UGbool LoadColorTable(const UGString &strDisplayStyleName, UGChartColorMode::UGS52ColorMode eColorMode);
		UGbool LoadLookupTables(const UGString &strDisplayStyleName);

		UGbool IsColorTableLoaded();
		UGbool IsLookupTableLoaded();

		UGlong GetDepthUnit() const;
		void SetDepthUnit(UGlong nUnit);

		// ���õ�ͼ������Ƿ���ʾ�Ķ�Ӧ��ϵ��ʹ��ǰ�ȵ���GetDisplayFeature��ȡ��ǰ��ͼ�к��е������������
		void SetDisplayableFeature(UGDict<UGString, UGbool>& dictDisplayFeature);
		// ��ȡ��ǰ��ͼ�º��е�������������Լ��Ƿ���ʾ�Ķ�Ӧ��ϵ��Ĭ��������궼Ӧ����ʾ
		UGDict<UGString, UGbool> GetDisplayableFeature();

		// �Ƿ���ʾ������ΪnCode�������, ���ڲ�ʹ��
		UGbool IsDisplayableFeature(UGint nCode);

		// ���õ�ͼ������Ƿ��ѡ���������࣬ʹ��ǰ�ȵ���GetSelectableFeature��ȡ��ǰ��ͼ�к��е������������
		void SetSelectableFeature(UGDict<UGString, UGbool>& dictSelectedFeature);
		// ��ȡ��ǰ��ͼ�º��е�������������Լ��Ƿ�ɱ�ѡ��Ķ�Ӧ��ϵ��Ĭ��������궼Ӧ�ÿ��Ա�ѡ��
		UGDict<UGString, UGbool> GetSelectableFeature();

		// �ж�������ΪnCode������Ƿ���Ա�ѡ�񣬹��ڲ�ʹ��
		UGbool IsSelectableFeature(UGint nCode);

		// ���ӵ�ͼ�е��������
		void AddFeature(UGint nCode);
		void ClearFeature();

		// ��ȡ���еĿ���ʾ��������������java �����װʱ��Ҫʹ�á�
		UGint GetDisplayableFeatureCount() const;
		// ��ȡ���еĿ�ѡ����������������java �����װʱ��Ҫʹ�á�
		UGint GetSelectableFeatureCount() const;

		const UGStyle& GetSelectionStyle() const;
		void SetSelectionStyle(const UGStyle& selectionStyle);

		//! \brief �Ƿ������ı��ü���
		UGbool IsTextClipRegionEnabled() const;
		//! \brief �����Ƿ������ı��ü���
		void SetTextClipRegionEnabled(UGbool bEnabled = true);

		UGbool IsDisplayLowAccurateMarker() const;
		void SetDisplayLowAccurateMarker(UGbool bEnabled = true);
	protected:
		// !brief ����ڲ�����ʹ�õ�ֵ��������Ϊ��λ��
		// !brief ����ֵ��ʱ����ת������Ϊ��λ����ֵ
		UGfloat UnitConverteToMeter(UGfloat dfValue);
		// !brief ֵ��ȡ��ʱ���ȴ���ת��Ϊ��ǰ��λ����ֵ
		UGfloat UnitConverteFromMeter(UGfloat dfValue) const;

		//! \brief  ���õ�ͼ�ĸ��±�־
		void SetModifiedFlag(UGbool bModified = true);

	protected:
		UGChartLookupTable m_lookupTable;
		UGbool m_bLookupTableLoaded;

		UGChartColorTable m_ColorTable;
		UGbool m_bColorTableLoaded;

		UGString m_strDisplayStyleName;
		UGString m_strFontName;
		UGfloat m_dfFontSize;
		UGChartColorMode::UGS52ColorMode m_eColorMode;
		UGChartDisplayCategory::UGS52DisplayCategory m_eDisplayCategory;
		UGbool m_bSymbolizedBoundary;
		UGbool m_bSimplifiedMarker;
		UGbool m_bDisplayText;
		UGbool m_bDisplaySounding;
		UGbool m_bMinVisibleScaleEnabled;
		UGfloat m_dfSafetyContour;
		UGfloat m_dfShallowContour;
		UGfloat m_dfDeepContour;
		UGbool m_bDisplayTextNational;
		UGbool m_bDisplaySafetyContourLabel;
		UGbool m_bDisplayMetaObject;
		UGbool m_bDisplayCellName;
		UGbool m_bDisplayOtherContourLabel;
		UGfloat m_dfSafetyDepth;
		UGbool m_bTwoShades;
		UGlong m_nDepthUnit;
		UGbool m_bTextClipRegionEnabled;

		UGStyle m_selectionStyle;
		UGMap *m_pMap;
		UGDict<UGint, UGbool> m_dictDisplayFeature;
		UGDict<UGint, UGbool> m_dictSelectableFeature;

		UGChartDisplayStyle::UGChartDisplayStyleType m_eDisplayStyleType;

		UGbool m_bDisplayLowAccurateMarker;
	};
}
#endif //!defined(AFX_UGCHARTSETTING_H_)
