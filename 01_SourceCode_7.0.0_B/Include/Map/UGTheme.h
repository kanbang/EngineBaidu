// UGTheme.h: interface for the UGTheme class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGTheme.h 
   **************************************************************************************
    \author   �¹���
    \brief    ר��ͼ���࣬����ר��ͼ������������                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEME_H__AEAB0616_AD6A_4049_9C12_07AE84BC1270__INCLUDED_)
#define AFX_UGTHEME_H__AEAB0616_AD6A_4049_9C12_07AE84BC1270__INCLUDED_

#include "Engine/UGDataSource.h"
#include "Stream/ugdefs.h"
#include "Toolkit/UGHashCode.h"
#include "Drawing/UGDrawing.h"
#include "Map/UGSelection.h"
#include "Engine/UGQueryDef.h"

namespace UGC {

#define UG_THEME_MAX_VALUE_COUNT	256

#define THEME_DIVISION _U("[#]")

//�Ѿ���UGSelection�������ˣ�����ע�͵�
//class UGLayer;

//! \brief ��չר��ͼͼ���¼��ص�����
typedef UGbool (UGSTDCALL *ExtendThemeDrawGeometryProc)(UGLayer* pTheme,UGbool& bCancel,UGGeometry* pGeometry,UGArray<UGString> arrFieldValues,UGGeometry* pYieldGeometry,UGlong pData);
typedef UGbool  (UGSTDCALL *ExtendThemeRecordsetDrawProc)(UGLayer* pTheme,UGRecordset* pDisplayRecordset,UGDrawing* pDrawing,UGArray<UGString> strFieldsNameArray,UGbool& bEnd,UGlong pData);

#ifdef SYMBIAN60
class MAP_APIC UGTheme 
#else
class MAP_API UGTheme 
#endif
{
public:
	enum UGClassType
	{
		//! \brief �Ⱦ෽ʽ
		ctEqualDistance,
		//! \brief ƽ������ʽ
		ctExtraction,
		//! \brief ��׼�ʽ
		ctStdev,
		//! \brief ������ʽ
		ctLogarithm,
		//! \brief �ȼ�����ʽ
		ctQuantile,
		//! \brief �Զ��巽ʽ
		ctCustomInterval,
		null_type
	};
	//! \brief ר��ͼ����
	enum UGThemeType 
	{
		ttNone =			0,
			//! \brief UNIQUEר��ͼ
			ttUnique = 			1,
			//! \brief RANGEר��ͼ
			ttRange	 = 			2,
			//! \brief GRAPHר��ͼ
			ttGraph	 = 			3,
			//! \brief GRADUATED_SYMBOLר��ͼ
			ttGraduatedSymbol = 4,
			//! \brief DENSITYר��ͼ
			ttDotDensity =		5,
			//		ttSymbolShade =		6,			//SYMBOL_SHADEר��ͼ
			//! \brief LABELר��ͼ
			ttLabel	=			7,
			//! \brief CUSTOMר��ͼ
			ttCustom =			8,
			//! \brief GRIDUNIQUEר��ͼ
			ttGridUnique = 		11,	
			//! \brief GRIDRANGEר��ͼ
			ttGridRange	 = 		12,	
			//! \brief ��չר��ͼ
			ttPlugin =          13   
	};
	enum UGThemeGraduatedMode
	{
		gmConstant,
		gmSquareRoot,
		gmLogarithm
	};
	enum UGThemeDataType
	{
		tvRecordset,
		tvExternal,
		tvMixed
	};

	enum UGActionType
	{
		UGDrawTheme = 0,
		UGHitTest = 1,
		UGTheme2Dataset = 2,
		UGThemeSymolToGeometry = 3,
		UGGeometry2Dataset = 4
	};

	//! \brief ר��ͼ��Ϊ��0���ơ�1�����2תΪ���ݼ�
	/**
	\param nType                   ��Ϊ����[in]
	\param pHitTestPoint2D         ��������ĵ�[in]
	\param dTolerance              ������ĵ�����[in]
	\param geoTextHitTestArray     ���صĵ��е�ı�ǩ��Ϣ���������ڱ�ǩר��ͼ��[in/out]
	\param strHitTestExpression    �����ǩר��ͼ����Ҫ����Ϣ���ֶα��ʽ���������ڱ�ǩר��ͼ��[in]
	\param Selection               ����¼�ѡ�е�ѡ�񼯣������ڵ�ֵ�ͷ�Χר��ͼ��[in]
	\param pDefaultStyle           ����¼�Ĭ�ϵķ�񣨽����ڵ�ֵ�ͷ�Χר��ͼ��[in]
	\param arrIDs				   ����¼�ѡ�еļ��ζ����ID�������ڵ�ֵ�ͷ�Χר��ͼ[in]
	\param pRecordsetCAD           ר��ͼת���ݼ�ʱ��������Geometry��CAD��¼��[in]
	\param geometryArray     ��ר��ͼ����ת��ΪGeometry���������ڵ��Զ���ר��ͼ��[in/out]
	\return ��Ӧ��intֵ
	*/
	struct UGActionData 
	{
		UGActionType nType;
		UGPoint2D pntHitTestPoint2D;
		UGdouble dTolerance;
		UGArray<UGGeometry*> geoTextHitTestArray;
		UGString strHitTestExpression;
		UGRecordset* pRecordsetCAD;
		UGStyle defaultStyle;
		UGArray<UGint> arrIDs;
		UGSelection* pSelection;
		UGbool bLableCompound ;
		UGArray<UGGeometry*> geometryArray;
		
		UGActionData()
		{
			nType = UGTheme::UGDrawTheme;
			pRecordsetCAD = NULL;
			geoTextHitTestArray.RemoveAll();
			strHitTestExpression.Empty();
			pSelection = NULL;
			bLableCompound = false;
			geometryArray.RemoveAll();
		}
	};

public:
	MAP_APIF UGTheme();
	virtual MAP_APIF ~UGTheme();

public:
	//! \brief ר��ͼ�Ƿ���Ч
	virtual MAP_APIF UGbool IsValid()const = 0;
	//! \brief �ýӿڶ��ⲻ����
	virtual MAP_APIF UGbool IsVisibleItem(UGRecordset *pRecordset, UGStyle &Style){return TRUE;};
	//! \brief ��ȡר��ͼ�ֶ�
	virtual MAP_APIF UGString GetFieldName(UGbool bAddExpression = true)const = 0;
	//! \brief ��ȡר��ͼ�ֶ�����
	virtual MAP_APIF UGbool GetFieldNames(UGArray<UGString>& arrExpressions,UGbool bAddExpression = true)const{return false;};
	//! \brief ר��ͼ�Ļ���
	virtual MAP_APIF UGbool OnDrawTheme(UGDrawing* pDrawing,UGLayer* pLayer,UGProgress* pProgress = NULL){return false;};
	//! \brief ����ר��ͼԪ��
	virtual MAP_APIF UGbool OnDrawThemeElement(UGDrawing* pDrawing,UGLayer* pLayer,UGGeometry *pGeometry, UGRecordset* pDisplayRecordset, UGActionData* pActionData = NULL){return false;};
	//! \brief �˺���Ŀǰ���ڻ�ȡ���ζ��󣬷��Ϊ����ϻ��ƣ����������һЩ�ص�
	virtual MAP_APIF UGGeometry* GetThemeElement(UGDrawing* pDrawing,UGLayer* pLayer,UGRecordset *pDisplayRecordset, UGActionData* pActionData = NULL){return NULL;};

	//! \brief ��չר��ͼ�Ļ���
	//UGbool OnDrawThemeEx(UGDrawing* pDrawing,UGLayer* pLayer,UGProgress* pProgress = NULL);
	//! \brief ��ȡר��ͼ�Ĳ�ѯ����
	//! \remarks �����Զ���ר��ͼ�������ݼ���أ�������Ҫ���룬��������ר��ͼ����Ҫ��
	virtual MAP_APIF UGbool GetThemeQueryDef(UGQueryDef* querfdef,UGDataset* pDv = NULL){return false;};
	//! \brief ר��ͼ����¼���ֻ��UGThemeStyleר��ͼ��Ч
	virtual MAP_APIF UGbool HitTest(const UGPoint2D& pntHitTest, UGdouble dTolerance,UGLayer* pLayer, UGint& nSelectedID, UGSelection &Selection, UGRecordset* pRs, UGDrawing *pDrawing,const UGStyle& defaultStyle,UGArray<UGint>& arrIDs)
	{
		return false;
	}
	//! \brief ר��ͼ����¼���ֻ��UGThemeLabelר��ͼ��Ч
	virtual MAP_APIF UGbool HitTestThemeLable(const UGPoint2D& pntHitTest,UGdouble dTolerance,UGLayer* pLayer,UGGraphics* pGraphics, UGDrawing *pDrawing,UGArray<UGGeoText>& geoTextArray,UGString strFieldExpression)
	{
		return false;
	}
	virtual MAP_APIF UGbool HitTestThemeLable(const UGPoint2D& pntHitTest,UGdouble dTolerance,UGLayer* pLayer,UGGraphics* pGraphics, UGDrawing *pDrawing,UGArray<UGGeoCompound>& geoCompoundArray,UGString strFieldExpression)
	{
		return false;
	}
	virtual MAP_APIF UGbool HitTestThemeGraph(const UGPoint2D& pntHitTest,UGdouble dTolerance,UGDrawing *pDrawing,UGLayer* pLayer,UGArray<UGGeoText>& geoTextArray)
	{
		return false;
	}

	//! \brief  ��pRecordset�е�ר��ͼ����ת��ΪGeometry��Ŀǰֻ֧�ֵ㵥ֵ���ֶΡ��Զ���ר��ͼ�� add by wangna 2011-05-31
	//! \param pLayer         ר��ͼͼ��[in]
	//! \param pRecordset         ��Ҫ��ר��ͼ����ת��ΪGeometry�Ķ����¼��[in]
	//! \param pDrawing         ��ʾ��ָ��[in]
	//! \param geometryArray         ��¼���ж����Ӧ��ר��ͼ����ת��ΪGeometry����[in/out]
	//! \return �Ƿ�ת���ɹ�
	MAP_APIF UGbool ConvertThemeObjectsToGeometrys(UGLayer* pLayer, UGRecordset *pRecordset, UGDrawing* pDrawing, UGArray<UGGeometry *> &geometryArray);

	//! \brief ר��ͼ�Ƿ��ö���ֻ�Ա�ǩ��ͳ�ƣ��ȼ�������Ч
	virtual MAP_APIF UGbool IsThemeOnTop()const
	{
		return false;
	}

	//! \brief ͳ��ר��ͼ�ֶ���ʾ���ø�������
	virtual MAP_APIF MAP_APIF void SetItemThemeRangeName(){};
	//! \brief ������ʾѡ��
	virtual MAP_APIF MAP_APIF void HighlightSelection(UGLayer* pLayer,UGDrawing* pDrawing){};
	//! \brief դ��ר��ͼ����Ƶ�Drawing�У�����դ��ר��ͼ��Ч
	virtual MAP_APIF MAP_APIF void CopyThemeGridToDrawing(UGDrawing* pDrawing);
	virtual MAP_APIF UGbool IsAutoAvoid()const{return false;};
	//////////////////////////////////////////////////////////////////////////
	//! \brief �鿴ѡ���ֶ��Ƿ�Ϸ�
	virtual MAP_APIF UGbool CheckFieldType(UGint nType);
	//! \brief ר��ͼ����ΪXML��Ϣ
	virtual MAP_APIF UGString ToXML(UGint nVersion = 0)const;
	//! \brief ר��ͼ��ȡXML��Ϣ
	virtual MAP_APIF UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief ��ȡר��ͼ�����hashcode
	virtual MAP_APIF UGint GetHashCode() const = 0;

	//! \brief ��ȡר��ͼ���Ƿ��в���ʾ������,
	// ��ֶ�ר��ͼ��ĳ������Ϊ����ʾ,�򷵻�TRUE
	virtual MAP_APIF UGbool HasUnVisibleItem() const { return FALSE;}

	//! \brief ��ȡר��ͼ���Ƿ��а�͸��������
	// �絥ֵר��ͼ������͸��������򷵻�TRUE
	virtual MAP_APIF UGbool HasTransparentItem() const { return FALSE; }

	//! \brief �����ⲿֵ
	MAP_APIF void SetExternalValue(const UGString& strKey, const UGString& strExternalValue);
	//! \brief �õ��ⲿֵ
	MAP_APIF UGbool GetExternalValue(const UGString& strKey, UGString& strExternalValue)const;
	//! \brief ����ⲿֵ
	MAP_APIF void ClearExternalData();
	
	//! \brief �õ����ɼ�����	
	MAP_APIF UGdouble GetVisibleScaleMax()const;							
	//! \brief �õ���С�ɼ�����	
	MAP_APIF UGdouble GetVisibleScaleMin()const;						
	//! \brief �������ɼ�����
	MAP_APIF void SetVisibleScaleMax(UGdouble dVisibleScaleMax);		
	//! \brief ȡ�����ɼ�����
	MAP_APIF void CancelVisibleScaleMax();							
	//! \brief ������С�ɼ�����
	MAP_APIF void SetVisibleScaleMin(UGdouble dVisibleScaleMin);		
	//! \brief ȡ����С�ɼ�����
	MAP_APIF void CancelVisibleScaleMin();							

	//! \brief �Ƿ�ɼ���Χ��
	MAP_APIF UGbool IsVisibleScale(UGdouble dScale,UGDrawParamaters* pDrawParam = NULL)const;
	//! \brief �Ƿ�ɼ�
	MAP_APIF UGbool IsVisible()const;
	//! \brief �����Ƿ�ɼ�
	MAP_APIF void SetVisible(UGbool bVisible = true);

	//! \brief �õ�ר��ͼ����
	MAP_APIF UGString GetCaption()const;
	//! \brief ����ר��ͼ����
	MAP_APIF void SetCaption(const UGString& strCaption );

	//! \brief �õ�ר��ͼ���˱��ʽ
	MAP_APIF UGString GetFilter()const;

	//! \brief �õ�ר��ͼ����
	MAP_APIF UGTheme::UGThemeType GetType()const;

	//! \brief �õ�ר��ͼ��������
	MAP_APIF UGint GetDataType()const;
	//! \brief ����ר��ͼ��������
	MAP_APIF void SetDataType(UGint nDataType);

	//! \brief ר��ͼ�Ƿ��޸�
	MAP_APIF UGbool IsModified()const;
	//! \brief ����ר��ͼ�Ƿ��޸�
	MAP_APIF void SetModifiedFlag(UGbool bModified = true);

	//! \brief ����ת��double��
	static MAP_APIF UGbool Variant2Double(const UGVariant& var, double& dKey);
	//! \brief ����ת���ַ���
	static MAP_APIF UGString Variant2String(const UGVariant& var); //�������ַ���
	//! \brief ת��ר��ͼ��������
	/**
	\param nThemeType				���Ͷ�Ӧ��intֵ[in]
	\return ��Ӧ���ַ�������
	*/
	static MAP_APIF UGString ConvertThemeType(UGTheme::UGThemeType nThemeType);
	//! \brief ת��ר��ͼ��������
	/**
	\param strThemeType		���Ͷ�Ӧ���ַ�������[in]
	\return ��Ӧ��intֵ
	*/
	static MAP_APIF UGTheme::UGThemeType ConvertThemeType(const UGString& strThemeType);

	//! \brief ����ר��ͼ�������ƣ��ڲ�ʹ�ã������޸ģ������ṩ����caption
	MAP_APIF void SetName(UGString strLayerName) {m_strName = strLayerName;};

	//! \brief �õ�ר��ͼ��������
	MAP_APIF UGString GetName() {return m_strName;};

	//! \brief ����ר��ͼ��չͼ��Ļص�����
	MAP_APIF void SetExtendThemeDrawGeometryFun(ExtendThemeDrawGeometryProc pExtendThemeDrawGeometryFun,UGlong pData);
	
	//! \brief ִ����չר��ͼ�Ļص�����
	MAP_APIF UGbool SendExtendThemeDrawGeometryFun(UGLayer* pLayer,UGbool& bCancel,UGGeometry*& pGeometry,UGArray<UGString> arrFieldValues,UGGeometry* pYieldGeometry = NULL);

	//! \brief ����ר��ͼ��չͼ��Ļص�����
	MAP_APIF void SetExtendThemeDrawRecordsetFun(ExtendThemeRecordsetDrawProc pExtendThemeDrawRecordsetFun,UGlong pData);
	
	//! \brief ִ����չר��ͼ�Ļص�����
	MAP_APIF UGbool SendExtendThemeDrawRecordsetFun(UGLayer* pLayer,UGRecordset* pDisplayRecordset,UGDrawing* pDrawing,UGArray<UGString> strFieldsNameArray,UGbool& bEnd);

	//UGbool m_bIsExtendTheme;
	//added by macx 2008.8.4 
	//! \brief PDF�������͡�
	//! \remarks �Ƿ���PDFGraphics���棬�ڻ��Ʊ�ǩר��ͼ������PDFʱʹ�ã�����ʹ��PDF������ת�����ء�
	UGbool m_bPDFType;

	//! \brief �����ֶα��ʽ���飬ֻ��������չר��ͼ 2008-7-4 lugw
	virtual MAP_APIF void SetExtendExpression(const UGArray<UGString>& strExpressionArray);
	UGArray<UGString> GetExtendExpression();

	//added by macx 200-8-26 
	//! \brief ������ͼ�ֶ�����
	//! \param strRepreFiledName [in]��
	MAP_APIF void SetMakeRepresentationFieldName(const UGString &strRepreFiledName);	
	//! \brief ��ȡ��ͼ�ֶ�����
	//! \return ��ͼ�ֶ�����
	const MAP_APIF UGString& GetMakeRepresentationFieldName();	
	//added by macx 200-8-26 
	//! \brief ������ͼ�ֶ�����
	//! \param strRepreFiledName [in]��
	//! \remarks �ڱ�ǩ��ͳ�ƣ��ȼ�ר��ͼʹ�ã������Զ��塢��ֵ���ֶ�ʱʹ��SetRepresentationFieldName
	MAP_APIF void SetSaveRepresentationFieldName(const UGString &strSaveRepreFiledName);	
	
	//! \brief ��ȡ��ͼ�ֶ�����
	//! \return ��ͼ�ֶ�����
	const MAP_APIF UGString& GetSaveRepresentationFieldName();
	//added by macx 2008-8-26 
	//! \brief ������ͼ����־ true��ʹ����ͼ��false����ʹ��
	MAP_APIF void SetUseRepresentation(UGbool bRepresentation);	
	//! \brief ������ͼ����־ true��ʹ����ͼ��false����ʹ��
	MAP_APIF UGbool IsUseRepresentation();

	//! \brief  �ֶ�(���ʽ)ֵ���ⲿ�������ݵĶ�Ӧ
	UGDict<UGString,UGString> m_ExternalData; 

	//! \brief �����¼��ص������Ķ���ָ�룬ͳһΪһ���ɣ���ʡ�ڴ�
	UGlong m_pEventData;  

//added by qianjn in 2009-8-26 10:02:55 ����ԭ����ʱ��Ա�� �����ط�����

	//! \brief  �Ƿ�������ʾ
	virtual THEMEBASE_APIF UGbool IsEnableFlow()const;
	//! \brief  �����Ƿ�������ʾ
	virtual THEMEBASE_APIF void SetEnableFlow(UGbool bEnableFlow = true);

	//! \brief �����Զ����ã��˹��ܶ��ڲ��߱��Զ����õ�ר��ͼ�㲻���ã���������û���κ�Ч�����߱��Զ����õ�ר��ͼ��������ش˷�����
	virtual THEMEBASE_APIF void SetAutoAvoid(UGbool bAutoAvoid = true) { }
	virtual MAP_APIF UGbool ThemeToDataset(UGLayer* pLayer,UGRecordset *pRecordset, UGDrawing *pDrawing, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL){return false;}

	UGbool m_bViewGlobal;

	UGbool m_bFields;

//added by qianjn in 2009-8-26 10:02:55 �������
	//! \brief SFC�зֶ�ר��ͼ�ֶη�ʽ��UGC�в���Ӧ��ͨ��SFC�ֶη�ʽ�õ�UGC�ֶη�ʽ��
	//! \param nSFCClassType [in]UGint nSFCClassType --- SFC�зֶ�ר��ͼ�ķֶη�ʽ��
	//! \return UGC�еķֶη�ʽ��
    static MAP_APIF UGTheme::UGClassType GetClassTypeFromSFC( UGint nSFCClassType ); 	
	//! \brief SFC�зֶ�ר��ͼ�ֶη�ʽ��UGC�в���Ӧ��ͨ��UGC�ֶη�ʽ�õ�SFC�ֶη�ʽ��
	//! \param nUGCClassType [in]UGTheme::UGClassType nUGCClassType --- UGC�еķֶη�ʽ.��
	//! \return SFC�еķֶη�ʽ��
	static MAP_APIF UGint GetClassTypeToSFC( UGTheme::UGClassType nUGCClassType );	
protected:  
	MAP_APIF void Swap(const UGTheme& theme);
	//! \brief  ��pRecordset�е�ר��ͼ����ת��ΪGeometry��Ŀǰֻ֧�ֵ㵥ֵ���ֶΡ��Զ���ר��ͼ�� add by wangna 2011-06-02
	//! \param pLayer         ר��ͼͼ��[in]
	//! \param pRecordset         ��Ҫ��ר��ͼ����ת��ΪGeometry�Ķ����¼��[in]
	//! \param pDrawing         ��ʾ��ָ��[in]
	//! \param geometryArray         ��¼���ж����Ӧ��ר��ͼ����ת��ΪGeometry����[in/out]
	//! \return �Ƿ�ת���ɹ�
	virtual MAP_APIF UGbool ThemeObjectsToGeometrys(UGLayer* pLayer, UGRecordset *pRecordset, UGDrawing* pDrawing, UGArray<UGGeometry *> &geometryArray){return false;}
    
protected:  
	UGbool m_bModified;
	//! \brief  ר��ͼ����
	UGTheme::UGThemeType m_nType;	
	//! \brief  1,���Ա�2���ⲿ�û���������,����Ϊ�Ժ�Ԥ��
	UGint m_nDataType; 
		
	//! \brief caption for this thematic map
	UGString m_strCaption;
	UGbool m_bVisible;
	//! \brief ����ͼ�����ߴ��ڸ�ֵ��ʱ�򣬱�ͼ�㲻��ʾ������ֵС�ڵ���0�����������Ч��Ĭ��Ϊ0
	UGdouble m_dVisibleScaleMax;
	//! \brief ����ͼ������С�ڸ�ֵ��ʱ�򣬱�ͼ�㲻��ʾ������ֵС�ڵ���0�����������Ч��Ĭ��Ϊ0
	UGdouble m_dVisibleScaleMin;

	//! \brief SFC��ר��ͼ�Ĺ��˱��ʽ������Ϊ��SFC�汾�ĵ�ͼʱ�����ֶβ��ᱻ����
	UGString m_strFilter;

	UGArray<UGString> m_arrExtendExpArray;

	UGString m_strName;
	
	ExtendThemeDrawGeometryProc m_pExtendThemeDrawGeometryFun;
	ExtendThemeRecordsetDrawProc m_pExtendThemeDrawRecordsetFun;

	//! \brief ������ͼ�ֶ�,��������ר��ͼ��geometry�ֶ�
	UGString m_strRepreFiledName;
	//! \brief ����ר��ͼ�޸ĵ��ֶ�
	UGString m_strSaveRepreFiledName;
	//! \brief �Ƿ�ʹ����ͼ����
	//! \remarks true ʹ�ã�false ��ʹ�á�
	UGbool m_bRepresentation;
};

}

#endif // !defined(AFX_UGTHEME_H__AEAB0616_AD6A_4049_9C12_07AE84BC1270__INCLUDED_)

