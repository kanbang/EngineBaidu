// UGGeoEvent.h: interface for the UGGeoEvent class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGGeoEvent.h
   **************************************************************************************
    \author   �¹���
    \brief    ����ͼ���¼������ࡣ                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGGEOEVENT_H__6A5EEB50_CB05_4157_8707_8B9B17A9DE1D__INCLUDED_)
#define AFX_UGGEOEVENT_H__6A5EEB50_CB05_4157_8707_8B9B17A9DE1D__INCLUDED_

#include "Geometry/UGGeometry.h"
#include "Engine/UGDatasetVector.h"

namespace UGC {

class MAP_API UGGeoEvent  
{
public:
	UGGeoEvent(UGRecordset* pRecordset );
#ifdef SYMBIAN60
	~UGGeoEvent();
#else
	virtual ~UGGeoEvent();
#endif

public:	
	//! \brief ��ȡ�ü��ζ���
	UGGeometry* GetGeometry()const;
	//! \brief ���ö�Ӧ���ζ���
	//! \return ���ü��ζ����Ƿ�ɹ�
	UGbool SetGeometry(const UGGeometry* pGeometry);
	//! \brief ���ü��ζ����Ӧ�ķ��
	void SetStyle(const UGStyle& style);
	//! \brief �ͷż��ζ���
	void ReleaseGeometry();
	//! \brief ���ζ����ƶ���
	void MoveTo(UGdouble dx, UGdouble dy);	
	//! \brief ���ζ����ƶ�
	void Move(UGdouble dx, UGdouble dy);	

	//! \brief �õ����ζ���ı�ǩ
	UGString GetTag()const;
	//! \brief ���ü��ζ���ı�ǩ
	void SetTag(const UGString& strTag);

//	UGPoint2D GetCurPos()const;
//	void SetCurPos(const UGPoint2D& pntCurPos);

	//! \brief   ��ȡGeoEvent��XML��Ϣ
	UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief   ����GeoEventΪXML
	UGString ToXML(UGint nVersion = 0)const;

//{{ added by xiaoys at 20120628 ��չ֧������ 
	//! \brief  ����һ�������Եı�ע����
	UGbool AddFeature(UGGeometry *pGeometry, const UGArray<UGString> &aryFields, const UGArray<UGVariant *> &aryValues);

	//! \brief   ��ȡָ���ֶε�����ֵ
	UGbool GetFeature(UGVariant& var,const UGString& strField);

	//! \brief�����ֶε�ֵ��
	UGbool SetFeature(const UGString& strField,const UGVariant& var);

	//! \brief���ö���ֶε�ֵ��
	UGbool SetFeatures(const UGArray<UGString>& arFields,const UGArray<UGVariant>& var);
//}} added by xiaoys at 20120628

//{{ add by xiaoys 2012-10-29 ����m_Recordset,���ⲿRecordset�ع���ʱ����Ҫͬʱ����GeoEvent��ָ��
	UGbool UpdateRecordset(UGRecordset* pRecordset);
//}} add by xiaoys 2012-10-29 ����m_Recordset,���ⲿRecordset�ع���ʱ����Ҫͬʱ����GeoEvent��ָ��
//}} added by mahb at 20120628 
public:
	//! \brief ��¼��
	UGRecordset* m_pRecordset; 
	//! \brief ��¼��ID
	UGint m_nSmid;
	//! \brief ��ǩ
	UGString m_strTag;		
//	UGPoint2D m_pntCurPos;	//��ǰλ��

	//�Ż�ȫ����ո��ٲ�ı��
	UGbool m_bIsNeedReleaseGeometry;
private:
	UGGeoEvent(){}

};

}

#endif // !defined(AFX_UGGEOEVENT_H__6A5EEB50_CB05_4157_8707_8B9B17A9DE1D__INCLUDED_)

