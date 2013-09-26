/*!
**************************************************************************************
\file     UGTrackingLayerEx.h
**************************************************************************************
\author   mahb,xiaoys
\brief    �ƶ��˸��ٲ㣬֧�ֶ�����źͶ��ǩ��ʾ��                                                           
\attention   
----------------------------------------------------------------------------------<br>
Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                               <br>
All Rights Reserved.                                                             <br>
----------------------------------------------------------------------------------<br> 

**************************************************************************************
\version 2012-06-21      ��ʼ���汾.                                              <br>
**************************************************************************************
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTrackingLayerEx_H__E301D009_A2C1_4803_A434_C18A87419F38__INCLUDED_)
#define AFX_UGTrackingLayerEx_H__E301D009_A2C1_4803_A434_C18A87419F38__INCLUDED_

#include "Map/UGTrackingLayer.h"
//#include "ThemeBase/UGThemeLabel.h"

namespace UGC
{

typedef struct UG_SYMBOLSTYLE
{
	//! \brief �Ƿ�ɼ�
	UGbool m_bVisible;		
	//! \brief ��˸���� 0-����˸
	UGchar m_ctwinkling;
	//! \brief ���Ŷ��뷽ʽ
	UGchar m_cAlign;
	//! \brief ����ƫ������X
	UGshort m_sX;
	//! \brief ����ƫ������Y
	UGshort m_sY;
	//! \brief ����
//	UGString m_strCaption;			
//	//! \brief ���
//	UGStyle m_Style;
	UG_SYMBOLSTYLE()
	{
		m_bVisible = true;
		m_sX = 0;
		m_sY = 0;
	}
}UGSymbolLayout;

typedef struct UG_LablelStyle
{
	//! \brief �ɼ�
	UGbool m_bVisible;		
	//! \brief �ı�ƫ������X
	UGshort m_sX;
	//! \brief �ı�ƫ������Y
	UGshort m_sY;
	//! \brief ����
	UGString m_strCaption;			
	//! \brief ���
	UGTextStyle m_TextStyle;	
	UG_LablelStyle()
	{
		m_bVisible = true;
		m_sX = 0;
		m_sY = 0;
	}
}UGLabelStyle;

typedef struct UG_ITEM_ATTR
{
	UGString strField;
	UGVariant varValue;
}UGItemAttr;

class MAP_API UGTrackingLayerEx : public UGTrackingLayer 
{

public:
	UGTrackingLayerEx();
	virtual ~UGTrackingLayerEx();

 public:
 	//virtual UGbool OnDraw(UGGraphics* pGraphics, UGDrawing *pDrawing);
	virtual UGbool OnDraw(UGGraphics* pGraphics, UGDrawing *pDrawing);

 	//! \brief ͨ�����ٲ�����ǩ��ȡ����
 	virtual UGGeoEvent* GetEvent(const UGString& strTag);
 
 	////! \brief ͨ�����ٲ�����Ż�ȡ����
 	//virtual UGGeoEvent* GetEvent(const UGint& iTrackID);

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


//============================================================================================================
//=======================��ǩ������ؽӿ�=====================================================================

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

	virtual void ClearLabel();
//===============================================================================================================
//=======================�ֶ�����������ؽӿ�==================================================================
	//! \brief  �½��ֶ�----------------------------------
	virtual UGbool CreateUserField(const UGString& strName,UGFieldInfo::FieldType nType,UGint nSize,UGint nAttributes = 0);
	virtual UGbool CreateUserFields(const UGFieldInfos& fieldInfos);
	//{{ add by xiaoys 2012-07-06
	virtual UGbool GetFieldInfos(UGFieldInfos& infos);

	virtual UGbool GetFieldInfo(UGFieldInfo& info, const UGString& strFieldName);

	virtual UGbool DeleteUserField(const UGString& strFieldName);

	//}} add by xiaoys 2012-07-06
	//! \brief  �����ֶ�ֵ-------------------------
	virtual UGbool SetFieldValue(const UGString& strFieldName,const UGVariant& var);

	virtual UGbool SetFieldValue(const UGString& strFieldName,const UGVariant& var,const UGint& iIndex); 
	
	//! /brief ��ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(UGVariant& var, UGint iIndex, const UGString& strField);

	//ɾ���ֶ�
//	UGbool DeleteUserField(const UGString& strName);

	//! \brief ��ȡ�����iIndex�������ֶ�����--------------------------
	virtual UGString GetFieldName(UGint iIndex);

	//! \brief  ����һ�������Եı�ע����------------------------------
	virtual UGint AddFeature(UGGeometry *pGeometry, const UGArray<UGString> &aryFields, const UGArray<UGVariant *> &aryValues,const UGString& strTag);

	//! \brief ɾ���ƶ��ı�ע����
//	virtual UGbool DeleteFeature(const UGint& iIndex);
private:
	//! \brief  ��ȡ��ǩ���Ƶ�˳��
	UGint GetLabelIndex(const UGString& strTag);

	//! \brief  �����ڴ����ݼ�
	UGbool CreateMemDataset();

	//add by xiaoys 2012-06-29  ���һ������ִ��Ľӿ�����ģ����ѯ
	UGint GetMaxSub(const UGString& strSrc, const UGString& strDes);

	//add by xiaoys 2012-07-07 ���һ������m_pRecordset�Ľӿ�
	UGbool CreateRecordset();
 private:
    //! \brief  ���Ż��Ʒ��
	UGSymbolLayout m_SymbolStyle;

	//! \brief  ��ǩר��ͼ������ 
	UGArray<UGLabelStyle> m_arLabelStyle;

};
}


#endif // !defined(AFX_UGTrackingLayerEx_H__E301D009_A2C1_4803_A434_C18A87419F38__INCLUDED_)
