// UGTrackingLayer.h: interface for the UGTrackingLayer class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGTrackingLayer.h
   **************************************************************************************
    \author   �¹���
    \brief    ����ͼ���࣬��һ���ڴ�ͼ�㣬����������ͼ��������棬������ʱ�������ʾ��                                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTRACKINGLAYER_H__DC6194D6_CDEC_4A74_8522_AC23C8C202F5__INCLUDED_)
#define AFX_UGTRACKINGLAYER_H__DC6194D6_CDEC_4A74_8522_AC23C8C202F5__INCLUDED_

#include "Map/UGGeoEvent.h"
#include "Stream/ugdefs.h"
#include "Drawing/UGDrawing.h"

namespace UGC {

//! \brief BeforeTrackingLayerDraw �¼��ص�����
typedef void (UGSTDCALL *BeforeTrackingLayerDrawProc)(UGlong pWnd,UGbool& bCancel,UGGraphics* pGraphics);
//! \brief AfterTrackingLayerDraw �¼��ص�����
typedef void (UGSTDCALL *AfterTrackingLayerDrawProc)(UGlong pWnd,UGGraphics* pGraphics);

class MAP_API UGTrackingLayer  
{
public:
	UGTrackingLayer();

#ifdef SYMBIAN60
	~UGTrackingLayer();
#else
	virtual ~UGTrackingLayer();
#endif

public:
	//! \brief  ����¼�
	UGint HitTest(const UGPoint2D& pntHitTest, UGdouble dTolerance);

	//! \brief  �Ƿ�ɼ�
	UGbool IsVisible()const;
	//! \brief  �����Ƿ�ɼ�
	void SetVisible(UGbool bVisible = true);

	//! \brief  �Ƿ��ѡ��
	UGbool IsSelectable()const;
	//! \brief  �����Ƿ��ѡ��
	void SetSelectable(UGbool bSelectable = false);

	//! \brief  �Ƿ�ɱ༭
	UGbool IsEditable()const;
	//! \brief  �����Ƿ�ɱ༭
	void SetEditable(UGbool bEditable = false);

	//! \brief  �Ƿ�ɲ�׽
	UGbool IsSnapable()const;
	//! \brief  �����Ƿ�ɲ�׽
	void SetSnapable(UGbool bSnapable = false);

	//! \brief �Ƿ��������ͼ������Ŷ�����
	UGbool IsSymbolScalable()const;
	//! \brief ���÷����Ƿ������
	void SetSymbolScalable(UGbool bSymbolScalable = false);

	//! \brief �Ƿ������ı�����
	UGbool IsAllowTextOverlap()const;
	//! \brief �����ı�����
	void SetAllowTextOverlap(UGbool bAllowTextOverlap = true);

	//! \brief ���Ҷ�Ӧ��ǩ�ĸ��ٲ����
	/**
	\return  ��Ӧ��ǩ������
	*/
	UGint Find(const UGString &strTag, UGint nFromIndex = 0) const;
	//! \brief ���Ҷ�Ӧ���ζ���ĸ��ٲ����
	/**
	\return  ��Ӧ���ζ��������
	*/
	UGint Find(const UGGeometry* pGeometry, UGint nFromIndex = 0);

	//! \brief �Ƴ�ָ����ǩ�Ķ���
	UGbool Remove(const UGString &strTag, UGint nFromIndex = 0);
	//! \brief �Ƴ�ָ�������Ķ���
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief ���Ӽ��ζ��󵽸��ٲ�
	UGGeoEvent* Add(const UGGeometry* pGeometry, const UGString &strTag);
	//! \brief �õ�ָ�������ĸ��ٲ����
	UGGeoEvent* GetAt(UGint nIndex) const;

	//! \brief �Ƴ����ٲ����ж���
	void RemoveAll();

	//! \brief �Ƴ����ٲ����ж���
	void RemoveAllEx();

	//! \brief ��ȡ�������
	UGint GetCount()const;

	//! \brief ����ָ����������ı�ǩ
	void SetTagAt(UGint nIndex, const UGString &strTag);

	//add by xiaoys 2012-07-10 �ýӿ���Ҫ��������jni���װ��ȡ�ֶ���Ϣ�ӿ�
	UGDataset* GetDataset();

	//! \brief ���Ƹ��ٲ�
#ifdef SYMBIAN60
	UGbool OnDraw(UGGraphics* pGraphics, UGDrawing *pDrawing);
#else
	virtual UGbool OnDraw(UGGraphics* pGraphics, UGDrawing *pDrawing);
#endif

	//! \brief ����ָ�����ַ�����
	void SetCharset(UGString::Charset nCharset);
	//! \brief �õ�ָ�����ַ�����
	UGString::Charset GetCharset()const;

	//! \brief �õ������Ŵ�С
	UGdouble GetMaxMarkerSize() const;
	//! \brief �õ���Ч����
	UGRect2D GetInvalidRect() const;
	//! \brief ������Ч����
	void SetInvalidRect(const UGRect2D& rcInvalid);

	UGdouble GetSymScaleDefinition() const;
	void SetSymScaleDefinition(UGdouble dSymScaleDefinition);

	UGdouble CalculateSymbolScale(UGdouble dScale) const;
	void SetDrawing(UGDrawing* pDrawing);
	
	//! \brief ��ȡ���ԭ���ģʽ
	UGint GetFillOrgMode() const;					
	//! \brief �������ԭ��ģʽ
	void SetFillOrgMode(UGGraphics::BrushOrgMode nFillOrgMode);		
	UGbool BuildSpatialIndex(UGSpatialIndexInfo  &spatial);

	//! \brief ��ʼ����
	UGbool BeginTrans() ;
	
	//! \brief �ύ����
	void Commit() ;
	
	//! \brief ��������
	void Rollback();
	
	//! \brief �ж������Ƿ�ʼ 
	UGbool IsTransStarted() ;

	//! \brief �����������±�־
	//! \param bIsEditBulkOperate [in] TRUEΪ��ʼ�������£�FALSEΪȡ���������±�־
	UGbool EditBulk(UGbool bIsEditBulkOperate);

	//! \brief ��������ʱ,ǿ��ˢ��,�����������༭�����ݱ���
	//! \return �Ƿ�ˢ�³ɹ�
	UGbool FlushBulkEdit();

	//! \brief ȡ�������������µ����ݣ����ϴ��ύ������ �༭��������Ч�������Լ�����ʼ���������༭
	UGbool CancleBulkOperated();
	
	//added by xielin 2007-10-17 �����Ż����ٲ����ʾ�ٶ�
	//! \brief ��ʾ��ʱ���Ƿ��ն�������������ʾ��Ĭ�ϰ��ն�������������ʾ�������Դ󲿷ֵĸ���Ӧ�ã�һ�����ٵ�һ����ע��ע�ⲻҪŪ�ɸ��϶��󣩣�����߻����ٶ�
	void SetOrderByGeometryType(UGbool bOrderByGeometryType=true);
	//! \brief �����Ƿ��ն�������������ʾ
	UGbool IsOrderByGeometryType();

	//! \brief  �Ƿ�Ϊ�߹⻬ģʽ
	UGbool IsLineSmoothingMode()const;
	//! \brief  �����߹⻬ģʽ
	void SetLineSmoothingMode(UGbool bSmoothingMode = true);			
	//! \brief  �Ƿ�Ϊ�ı��⻬ģʽ
	UGbool IsTextSmoothingMode()const;									
	//! \brief  �����ı��⻬ģʽ
	void SetTextSmoothingMode(UGbool bSmoothingMode = true);		
	//! \brief �Ƿ�Ϊ�豸ͼ��
	UGbool IsDeviceLayer();

	//! \brief ����ͼ������
	/**
	\param strFileName				����·��[in]
	\param bOverWrite				�Ƿ�ǿ�Ƹ���[in]
	\return �����Ƿ�ɹ�
	*/
	//UGbool SaveAs(const UGString& strFileName ,UGbool bOverWrite = false)const;
	//! \brief ��ͼ������
	/**
	\param strFileName				��·��[in]
	\return ���Ƿ�ɹ�
	*/
	UGbool Open(const UGString& strFileName,UGbool bAsMemoryMode = false);
	//! \brief ���ͼ��
	void Clear();

	//! \brief   ��ȡͼ���XML��Ϣ
	UGbool FromXML(const UGString& strXML,const UGString& strWorkspacePath,const UGString& strMapName,UGint nVersion = 0);
	//! \brief   ����ͼ��ΪXML
	UGString ToXML(const UGString& strWorkspacePath,const UGString& strMapName,UGint nVersion = 0)const;

	//! \brief ���ø��ٲ�ͼ���͸����
	/*
	\param nTransPercent	͸����[in]
	*/	
	void SetTransPercent(UGuint nTransPercent);
	//! \brief ��ȡͼ���͸����
	UGuint GetTransPercent();

	void SetBeforeTrackingLayerDrawFunc(BeforeTrackingLayerDrawProc pBeforeTrackingLayerDrawFunc,UGlong pWnd);
	void SetAfterTrackingLayerDrawFunc(AfterTrackingLayerDrawProc pAfterTrackingLayerDrawFunc,UGlong pWnd);

	void SendBeforeTrackingLayerDrawFunc(UGbool& bCancel,UGGraphics* pGraphics);
	void SendAfterTrackingLayerDrawFunc(UGGraphics* pGraphics);

private:
	//modified by lugw 2007-05-11 �˺�����Ϊ˽�У��ⲿ�ݲ�ʹ��
	void SetGeometryAt(UGint nIndex, const UGGeometry* pGeometry);
	//! \brief �����ڴ�����Դ,�����Ա����Դ��Ϊ�գ�����true��Ϊ�շ���false
	UGbool CreateMemoryDs();
	//! \brief ��ȡ�豸ͼ��洢·��
	UGString GetFileName(const UGString& strWorkspacePath,const UGString& strMapName)const;

	UGRecordset* GetRecordset();

//{{ add by xiaoys 2012-07-03 Ϊ����TrackingLayerEx����һЩ�麯��
public:
	UGbool IsTrackingLayerEx();

	//! \brief ͨ�����ٲ�����ǩ��ȡ���� 
	virtual UGGeoEvent* GetEvent(const UGString& strTag);

	//! \brief ͨ�����ٲ�����ֶκ�ֵ��ȡ��¼���
	virtual UGint Query(UGArray<UGint>& arIDs, const UGString& strFieldName, const UGString& strVar);

	//! \brief ���÷��ſɼ�
	virtual void SetSymbolVisible(UGbool bVisible);

	//! \brief ���÷�����˸
	virtual void SetSymbolTwinkling(UGchar cTwinkling);

	//! \brief ���÷��Ŷ��뷽ʽ
	virtual void SetSymbolAlign(UGchar cAlign);

	//! \brief ���÷���ƫ��
	virtual void SetSymbolOffset(UGshort sX, UGshort sY);


	//! \brief  ����ٲ���Ӷ�������Ա�ǩ��----------------
	virtual UGbool AddLabel(const UGString& strField, const UGTextStyle& LabelStyle,UGbool bVisible = true, UGbool bAddToTail = true);
	//! \brief  �ڸ��ٲ��Ƴ�ר��ͼ��------------------------
	virtual UGbool RemoveLabel(const UGString& strField);

	//! \brief ���ñ�ǩƫ��
	virtual UGbool SetLabelOffset(const UGString& strTag, UGshort usX, UGshort usY); 

	//! \brief ���ñ�ǩ˵��
	virtual UGbool SetLabelCaption(const UGString& strTag, const UGString& strCaption);

	//! \brief ���ñ�ǩ��������ʽ
	virtual UGbool SetLabelTextStyle(const UGString& strTag, const UGTextStyle& TextStyle);

	//! \brief  ���ñ�ǩ�Ƿ���ʾ
	virtual UGbool SetLabelVisible(const UGString& strTag,UGbool bVisible);

	//! \brief  ��ָ����ǩ����һ�㣻
	virtual UGbool LabelMoveUp(const UGString &strTag);
	//! \brief  ��ָ����ǩ����һ�㣻
	virtual UGbool LabelMoveDown(const UGString &strTag);
	//! \brief  ��ָ����ǩ��Ϊ��㣻
	virtual UGbool LabelMoveTop(const UGString &strTag);
	//! \brief  ��ָ����ǩ��Ϊ��ײ㣻
	virtual UGbool LabelMoveBottom(const UGString &strTag);
	//! \brief  ������б�ǩ��
	virtual void ClearLabel();

	//! \brief  �½��ֶ�
	virtual UGbool CreateUserField(const UGString& strName,UGFieldInfo::FieldType nType,UGint nSize,UGint nAttributes = 0);
	virtual UGbool CreateUserFields(const UGFieldInfos& fieldInfos);

	//{{ add by xiaoys 2012-07-06
	virtual UGbool GetFieldInfos(UGFieldInfos& infos);
	
	virtual UGbool GetFieldInfo(UGFieldInfo& info, const UGString& strFieldName);

	virtual UGbool DeleteUserField(const UGString& strFieldName);
	//}} add by xiaoys 2012-07-06

	//! \brief  ���õ�ǰ�ֶ�ֵ
	virtual UGbool SetFieldValue(const UGString& strFieldName,const UGVariant& var);

	//! \brief  �޸ĵ�iIndex������ָ���ֶε�ֵ��
	virtual UGbool SetFieldValue(const UGString& strFieldName,const UGVariant& var,const UGint& iIndex); 

	//! \brief ��ȡ�����iIndex�������ֶ�����
	virtual UGString GetFieldName(UGint iIndex);

	//! \brief  ����һ�������Եı�ע����
	virtual UGint AddFeature(UGGeometry *pGeometry, const UGArray<UGString> &aryFields, const UGArray<UGVariant *> &aryValues,const UGString& strTag);

	//! \brief  ������ٲ����ж��󣬵�������ṹ��------------------------
	void DeleteAllFeatures();
//}} add by xiaoys 2012-07-03 Ϊ����TrackingLayerEx����һЩ�麯��

	//add by xiaoys 2012-07-16
	virtual UGbool GetFieldValue(UGVariant& var, UGint iIndex, const UGString& strField);


protected:
	UGDrawing* m_pDrawing;
	UGRect2D m_rcInvalid;
	//! \brief ���ķ��ŵĴ�С�����ǱƲ����ѵģ�������ʱά��
	UGdouble m_dMaxMarkerSize;
	UGuint m_unOptions;
	UGList<UGGeoEvent*> m_Events;

	UGDataSource* m_pDs;
	UGDatasetVector* m_pDv;
	UGRecordset* m_pRecordset; 

	UGString::Charset m_nCharset;
	//! \brief �������ű�����
	UGdouble m_dSymScaleDefinition;	
	UGGraphics::BrushOrgMode m_nFillOrgMode;
	UGbool m_bOrderByGeometryType;
	UGbool m_bLineSmoothingMode;
	UGbool m_bTextSmoothingMode;

	UGbool m_bDeviceTrackingLayer;
	UGbool m_bTrackingLayerEx;

	UGMutex m_mutex;

	UGuint m_nTransPercent;

	UGGraphics* m_pTransPercentGraphics;
	UGImage* m_pTransPercentImage;
	UGBrush* m_pTransPercentBrush;
	UGPen* m_pTransPercentPen;

	BeforeTrackingLayerDrawProc m_pBeforeTrackingLayerDrawFunc;
	AfterTrackingLayerDrawProc m_pAfterTrackingLayerDrawFunc;
	UGlong m_pEventView;  //�����¼��ص������Ķ���ָ��
};

}

#endif // !defined(AFX_UGTRACKINGLAYER_H__DC6194D6_CDEC_4A74_8522_AC23C8C202F5__INCLUDED_)

