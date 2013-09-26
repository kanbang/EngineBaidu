// UGSelection.h: interface for the UGSelection class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGSelection.h
   **************************************************************************************
    \author   �¹���
    \brief    ѡ�񼯺���                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGSELECTION_H__2FBE2AA1_B3D6_469E_854F_CC6E86B762D0__INCLUDED_)
#define AFX_UGSELECTION_H__2FBE2AA1_B3D6_469E_854F_CC6E86B762D0__INCLUDED_

#include "Engine/UGDataSource.h"
#include "Drawing/UGDrawing.h"
//#include "Map/UGLayer.h"
#include "Geometry/UGGeometry.h"
#include "Map/UGChartObjectInfo.h"
namespace UGC {

	enum UGStyleOptions
	{
		FillBackColor					= 0x01,
		FillForeColor					= 0x02,
		FillBackOpaque					= 0x04,
		FillGradientAngle				= 0x08,
		FillGradientOffsetRatioX		= 0x10,
		FillGradientOffsetRatioY		= 0x20,
		FillGradientMode				= 0x40,
		FillOpaqueRate					= 0x80,
		FillSymbolID					= 0x100,

		LineColor						= 0x200,
		LineSymbolID					= 0x400,
		LineWidth						= 0x800,

		MarkerAngle						= 0x1000,
		MarkerSize						= 0x2000,
		MarkerSymbolID					= 0x4000,

		SymbolMarker					= 0x8000,
		SymbolLine						= 0x10000,
		SymbolFill						= 0x20000,    
	};


	class UGLayer;

class MAP_API UGSelection  
{
public:
	UGSelection();
#ifdef SYMBIAN60
	~UGSelection();
#else
	virtual ~UGSelection();
#endif

public:
	//! \brief ���ñ�����¼��
	void SetReserveRs(UGRecordset* pRecordset, UGbool bAutoRelease = false);   
	//! \brief ��ȡ������¼��
	UGRecordset* GetReservedRs()const;  
	//! \brief �Ӽ�¼������ѡ��
	UGbool FromRecordset(UGRecordset* pRecordset);
	//! \brief ��ѡ�����ɼ�¼��
	UGRecordset* ToRecordset(UGbool bGeometryOnly = true,UGRect2D rcBounds = UGRect2D(0.0, 0.0, 0.0, 0.0), UGbool bChartSubLayer = false)const;
	//! \brief ����ָ��ID��ѡ���е�����
	UGint FindID(UGint nID, UGint nSearchCount = 0) const;
	//! \brief ��ѡ�������ѡ�ж���ID
	UGint Add(UGuint unID,UGGeometry* pGeometry = NULL);
	//! \brief ɾ��ָ���������nCountѡ�ж���
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief ��ָ������������ѡ�ж���
	void InsertAt(UGint nIndex, UGuint unID, UGGeometry* pGeometry = NULL);//added pGeometry ����
	//! \brief �޸�ָ��λ�õĶ���
	void SetAt(UGint nIndex, UGuint unID, UGGeometry* pGeometry = NULL);
	//! \brief �õ�ָ���������Ķ���ID
	UGuint GetAt(UGint nIndex, UGGeometry** ppGeometry = NULL)const;//�����������������*&�����ǲ���ָ�գ�Ϊ�˱�����ǰ�ļ����ԣ���Ӱʱ��ָ��
	//! \brief ɾ������ѡ�ж���
	void RemoveAll();
	//! \brief ��ȡѡ��ID������ʼ��ַ
	UGuint* GetData();
	//! \brief ���ѡ�ж���ID������
	UGint Append(UGArray<UGuint>& arrIDs,UGArray<UGGeometry*>* arrGeos = NULL);
	//! \brief copyѡ���е�ID���鵽arrIDs
	void Copy(UGArray<UGuint>& arrIDs,UGArray<UGGeometry*>* arrGeos = NULL);
	//! \brief ����ѡ�м���С
	void SetSize(UGint nSize);
	//! \brief ��ȡѡ�м���С
	UGint GetSize()const;
	//! \brief ѡ���Ƿ��ж���
	UGbool IsEmpty()const;
	//! \brief ������ʾѡ��
	UGbool Highlight(UGGraphics* pGraphics, UGDrawing *pDrawing);
	//! \brief �Ƿ������Զ�����
	UGbool HasCustomStyle()const;
	//! \brief ����ʹ���Զ�����
	void SetCustomStyle(UGbool bCustomStyle = false); 
	//! \brief ����ѡ��ˮƽ
	void SetControlSelectLevel(UGint nControlSelectLevel);
	//! \brief ��ȡѡ��ˮƽ
	UGint GetControlSelectLevel()const;
	//! \brief ������ʾ���
	void SetStyle(const UGStyle& style);
	//! \brief ��ȡ��ʾ���
	const UGStyle& GetStyle()const;
	//! \brief ���ù������ݼ�
	void SetDatasetVector(UGDatasetVector* pDatasetVector);
	//! \brief ��ȡ�������ݼ�
	UGDatasetVector* GetDatasetVector()const;
	//! \brief ��������ͼ��ָ�롣
	//! \param pLayer ͼ��ָ��[in]��
 	void SetLayer(UGLayer *pLayer);	
 	//! \brief ��ȡ����ͼ��ָ�롣
 	//! \return ͼ��ָ�롣
 	UGLayer* Getlayer();
#if !defined OS_ANDROID && !defined IOS
	// Added by fansc 2011-10-8 ����ͼѡ����Ϣ
	//! \brief ��ȡ��ͼ��Ϣָ������
	UGArray<UGChartObjectInfo*> GetSelectedObjectInfo();
	//! \brief ��Ӻ�ͼ��Ϣָ��
	void AddSelectedObjectInfo(UGChartObjectInfo *pChartObjectInfo);
	//! \brief ���ѡ����Ϣ
	void ClearSelectedObjectInfo();
#endif

	void SetStyleOptions(UGint styleOptions);
	UGint GetStyleOptions();

	UGbool IsFillForeColorEnable();
	UGbool IsFillBackColorEnable();
	UGbool IsFillBackOpaqueEnable();
	UGbool IsFillGradientAngleEnable();
	UGbool IsFillGradientOffsetRatioXEnable();
	UGbool IsFillGradientOffsetRatioYEnable();
	UGbool IsFillGradientModeEnable();
	UGbool IsFillOpaqueRateEnable();
	UGbool IsFillSymbolIDEnable();
	UGbool IsLineColorEnable();
	UGbool IsLineSymbolIDEnable();
	UGbool IsLineWidthEnable();

	UGbool IsMarkerAngleEnable();
	UGbool IsMarkerSizeEnable();
	UGbool IsMarkerSymbolIDEnable();

	UGbool IsSymbolMarkerEnable();
	UGbool IsSymbolLineEnable();
	UGbool IsSymbolFillEnable();

protected:
	//! \brief ����ʸ�����ݼ�
	UGDatasetVector* m_pDatasetVector;
	//! \brief ���ڽ�ȡ�õļ�¼������
	UGRecordset *m_pReserveRs;   

	//! \brief Ĭ��ΪFalse, ���û�û������ѡ�񼯷��,
	UGbool m_bCustomStyle;	
	//! \brief �Ƿ��Զ��ͷ����ݼ�����������ݼ������洫�������Ҫ�Զ�
	UGbool m_bAutoReleaseRs;         
	UGint m_nControlSelectLevel;

	UGStyle m_Style;
	//! \brief ѡ�ж����ID
	UGArray<UGuint> m_arrIDs;
	//! brief ������¼��ͼ���ʱ��ר��ͼѡ�е�Geometry����ѡ��ʱ���ص���Geometry
	UGArray<UGGeometry*> m_arrGeo;
	//! brief ������¼ר��ͼ��Geometry����ѡ��ʱ���ص���Geometry
//	UGArray<UGGeometry*>m_arrGeo;
	//! \brief ������ͼ��
	UGLayer* m_pLayer;
#if !defined OS_ANDROID && !defined IOS
	UGArray<UGChartObjectInfo*> m_arrSelectedObjectInfo;
#endif

	UGint m_nStyleOptions;            // ���ѡ������Զ������Ƿ�������
};

}

#endif // !defined(AFX_UGSELECTION_H__2FBE2AA1_B3D6_469E_854F_CC6E86B762D0__INCLUDED_)

