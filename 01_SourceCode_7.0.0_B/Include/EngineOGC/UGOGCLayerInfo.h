//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGOGCLayerInfo.h
//!  \brief OGC�������ݵ�ͼ��Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef SMWEBLAYERINFO_H
#define SMWEBLAYERINFO_H

#include "Stream/ugexports.h"
#include "Stream/ugdefs.h"
#include "Geometry/UGCRSBound.h"

namespace UGC
{
///////////////////// OGC Online Request Structs //////////////////////////
typedef struct WMSRequest
{
	
	WMSRequest()
	{
		urlGetCapbilities = _U("");
		arrFormatCapbilities.RemoveAll();
		urlGetMap = _U("");
		arrFormatMap.RemoveAll();
		urlGetFeatureInfo = _U("");
		arrFormatFeatureInfo.RemoveAll();
		urlDescribeLayer = _U("");
		arrFormatLayerDescribe.RemoveAll();
		urlGetLegendGraphic = _U("");
		arrFormatLegendGraphic.RemoveAll();
	}
	//! \brief wms���������������ַ��
 	UGString urlGetCapbilities;
	//! \brief wms��Request��������������
	UGArray<UGString> arrFormatCapbilities;
	//! \brief wms�������ͼ�����ַ��
	UGString urlGetMap;
	//! \brief wms������ĵ�ͼ�ĸ�ʽ��
	UGArray<UGString> arrFormatMap;
	//! \brief wms������������Ϣ�����ַ
	UGString urlGetFeatureInfo;
	//! \brief wms������������Ϣ�ĸ�ʽ
	UGArray<UGString> arrFormatFeatureInfo;
	//! \brief wms������ͼ��ĵ�ַ 
	UGString	urlDescribeLayer;
	//! \brief wms������ͼ������xml�ĵ�ַ
	UGArray<UGString> arrFormatLayerDescribe;
	UGString	urlGetLegendGraphic;
	UGArray<UGString> arrFormatLegendGraphic;

} WMSOLRequest;

typedef struct WFSRequest
{
	WFSRequest()
	{
		urlGetCapabilitiesGet = _U("");
		urlGetCapabilitiesPost = _U("");
		arrFormatCapbilities.RemoveAll();
		urlDescribeFeatureTypeGet = _U("");
		urlDescribeFeatureTypePost = _U("");
		arrFormatFeatureTypeDescribe.RemoveAll();
		urlGetFeatureGet = _U("");
		urlGetFeaturePost = _U("");
		arrFormatFeature.RemoveAll();
		urlGetFeatureWithLockGet = _U("");
		urlGetFeatureWithLockPost = _U("");
		arrFormatFeatureWithLock.RemoveAll();
		urlGetGMLObjectGet = _U("");
		urlGetGMLObjectPost = _U("");
		arrFormatGMLObject.RemoveAll();
		urlLockFeatureGet = _U("");
		urlLockFeaturePost = _U("");
		arrFormatLockFeature.RemoveAll();
		urlTransactionGet = _U("");
		urlTransactionPost = _U("");
		arrFormatTransaction.RemoveAll();
	}
	//! \brief WFS�����������ַ��
	UGString	urlGetCapabilitiesGet;
	//! \brief WFS�����������ַ��
	UGString	urlGetCapabilitiesPost;
	//! \brief WFS��������Ӧ������Ϣ 
	UGArray<UGString> arrFormatCapbilities;
	//! \brief WFS�����������ַ��
	UGString	urlDescribeFeatureTypeGet;
	//! \brief WFS�����������ַ��
	UGString	urlDescribeFeatureTypePost;
	//! \brief WFS��������Ӧ������Ϣ
	UGArray<UGString> arrFormatFeatureTypeDescribe;
	//! \brief WFS�����������ַ��
	UGString	urlGetFeatureGet;
	//! \brief WFS�����������ַ��
	UGString	urlGetFeaturePost;
	//! \brief WFS��������Ӧ������Ϣ
	UGArray<UGString> arrFormatFeature;
	//! \brief WFS�����������ַ��
	UGString	urlGetFeatureWithLockGet;
	//! \brief WFS�����������ַ��
	UGString	urlGetFeatureWithLockPost;
	//! \brief WFS��������Ӧ������Ϣ
	UGArray<UGString> arrFormatFeatureWithLock;
	//! \brief WFS�����������ַ��
	UGString	urlGetGMLObjectGet;
	//! \brief WFS�����������ַ��
	UGString	urlGetGMLObjectPost;
	//! \brief WFS��������Ӧ������Ϣ
	UGArray<UGString> arrFormatGMLObject;
	//! \brief WFS�����������ַ��
	UGString	urlLockFeatureGet;
	//! \brief WFS�����������ַ��
	UGString	urlLockFeaturePost;
	//! \brief WFS��������Ӧ������Ϣ
	UGArray<UGString> arrFormatLockFeature;
	//! \brief WFS�����������ַ��
	UGString	urlTransactionGet;
	//! \brief WFS�����������ַ��
	UGString	urlTransactionPost;
	//! \brief WFS��������Ӧ������Ϣ
	UGArray<UGString> arrFormatTransaction;
} WFSOLRequest;

typedef struct WCSRequest
{
	WCSRequest()
	{
		urlGetCapbilitiesGet = _U("");
		urlGetCapbilitiesPost = _U("");
		arrFormatCapbilities.RemoveAll();
		urlDescribeCoverageGet = _U("");
		urlDescribeCoveragePost = _U("");
		arrFormatCoverageDescribe.RemoveAll();
		urlGetCoverageGet = _U("");
		urlGetCoveragePost = _U("");
		arrFormatCoverage.RemoveAll();
	}
	//! \brief WCS�����������ַ��
	UGString urlGetCapbilitiesGet;
	//! \brief WCS�����������ַ��
	UGString urlGetCapbilitiesPost;
	//! \brief WCS��������Ӧ������Ϣ
	UGArray<UGString> arrFormatCapbilities;
	//! \brief WCS�����������ַ��
	UGString urlDescribeCoverageGet;
	//! \brief WCS�����������ַ��
	UGString urlDescribeCoveragePost;
	//! \brief WCS��������Ӧ������Ϣ
	UGArray<UGString> arrFormatCoverageDescribe;
	//! \brief WCS�����������ַ��
	UGString urlGetCoverageGet;
	//! \brief WCS�����������ַ��
	UGString urlGetCoveragePost;
	//! \brief WCS��������Ӧ������Ϣ
	UGArray<UGString> arrFormatCoverage;
} WCSOLRequest;

/////////////////////// OGCLayer //////////////////////////////////////////
class ENGINEOGC_API OGCLayer
{
public:	
	//! \brief  Ĭ�ϵĹ��캯��
	OGCLayer();
	//! \brief  Ĭ�ϵ���������
	virtual ~OGCLayer();
public:
	// elements
	//! \brief ͼ������ơ�
	UGString m_strName;
	//! \brief ͼ��ı��⡣	 
	UGString m_strTitle;
	//! \brief ͼ���ժҪ��
	UGString m_strAbstract;
	//! \brief ͼ���ͶӰ��
	UGArray<UGString> m_arrCRS;
	//! \brief ͼ��Ĺؽ����б�
	UGStrings m_arrKeywords;
	//! \brief ͼ��֧�ֵĹ���ͶӰ
	//! \brief ͼ��ķ�Χ��	
	UGRect2D m_rcLatLongBoundingBox;
	//! \brief ͼ���style�� 	
	UGDict<UGString,UGString> m_arrStyle;
	//! \brief WCSͼ��֧�ֵĿռ������
	UGStrings m_arrInterpolations;
	//! \brief WCSͼ��Ĭ��֧�ֵĿռ������
	UGString m_DefaultInterpolation;
};
//////////////////// WMSLayer  //////////////////////////////////////////
class ENGINEOGC_API WMSLayer :public OGCLayer
{
public:	
	//! \brief  Ĭ�ϵĹ��캯��
	WMSLayer();
	//! \brief  Ĭ�ϵ���������
	virtual ~WMSLayer();

public:
	//! \brief ��ȡ��ͼ������ָ�롣
	WMSLayer* GetParentalLayer();	
	
	//! \brief �õ���ǰͼ����ͼ�����еĲ������
	//! \return ͼ��Ĳ������
	//! \remarks 0��Ϊ���ĸ������´ε�����
	//! \attention ��ƽ��������
	UGint GetCurrentLevel();

	//! \brief ���ĸ߶ȡ�
	//! \return ���ĸ߶ȡ�
	UGint GetTotalLevel();	
	
	//! \brief ��ͼ����������һ����ͼ�㡣
	//! \return �Ƿ�ɹ���
	void Growleaf(WMSLayer* pSubLayer);

	//! \brief �Ƿ���Ҷ�ӽ�㡣 
	UGbool IsLeaf();
	
	//! \brief ƽ�л�ͼ�� ��
	//! \param arrParallelLayer [in] ͼ������ 
	//! \attention ֻ�и�ͼ��ſ���ƽ�л�
	UGbool Parallelize(UGArray<WMSLayer*>& arrParallelLayer);

	//! \brief ��ȡ��ͼ�����Ϣ��
	//! \param pParentLayer ��ͼ�㡣[in] 
	void InheriFrom(WMSLayer* pParentLayer);
private:
	//! \brief ��ȡͼ��Ĳ��� ��
	//! \param pCurrentLayer ������ͼ�㡣[in] 
	UGint TotalLevel(WMSLayer* pCurrentLayer);

	//! \brief ��ȡ��ͼ�㡣
	//! \param pLayer ������ͼ�㡣[in] 
	//! \return ���ظ�ͼ���ָ�롣
 	WMSLayer* ParentalLayer(WMSLayer* pLayer);

	//! \brief ƽ�л�ͼ�㡣
	//! \param pLayer Ҫƽ�л���ͼ�㡣[in]
	//! \param arrParallelLayer �洢ƽ�л�ͼ���ͼ�����顣[in]
	UGbool ParallelizeLayer(WMSLayer* pLayer, UGArray<WMSLayer*>& arrParallelLayer);

public:
    //! \brief ��ʾͼ��ɼ���	 
	UGbool m_bVisible;
	//! \brief ͼ��ķ�Χ��
 	UGCRSBounds m_arrBoundingBox;
 	//! \brief �Ƿ�ɲ�ѯ 
 	UGbool m_bQueryable;
	//! \brief ͼ��ļ���     
	UGint m_nCascaded;
	//! \brief ͼ���͸��
	UGbool m_bOpaque;
	//! \brief �Ƿ����Ӽ�����
	UGbool m_bNoSubsets;
	//! \brief ���صĿ��
	UGint m_nFixedWidth;
	//! \brief ���صĸ߶�
	UGint m_nFixedHeight;	
	//! \brief ��ͼ��ָ�� 
	WMSLayer* m_pParentalLayer;
	//! \brief ͼ�����顣
 	UGArray<WMSLayer*> m_arrSubLayer;
};

class ENGINEOGC_API UGWebLayersInfos : public UGArray<WMSLayer*>
{
public:
	//! \brief  Ĭ�ϵĹ��캯��
	UGWebLayersInfos();
	//! \brief  Ĭ�ϵ���������
	~UGWebLayersInfos();
};

//////////////////// WMSLayer  //////////////////////////////////////////
class ENGINEOGC_API WFSFeatureType :public OGCLayer
{
public:	
	//! \brief  Ĭ�ϵĹ��캯��
	WFSFeatureType();
	//! \brief  Ĭ�ϵ���������
	virtual ~WFSFeatureType();

	const WFSFeatureType& operator =(const WFSFeatureType& featureType);
	
public:    
	//! \brief ����ͶӰ
	//! \remarks ��ע��Ϣ��
	UGString m_mainCRS;
    //! \brief �洢WFS�Ĳ������顣
 	UGArray<UGString> m_arrOperations;
	//! \brief �洢����ĸ�ʽ ��
 	UGArray<UGString> m_OutputFormats;
};

//////////////////// WMSLayer  //////////////////////////////////////////
class ENGINEOGC_API WCSCoverage :public OGCLayer
{
public:	
	//! \brief  Ĭ�ϵĹ��캯��
	WCSCoverage();
	//! \brief  Ĭ�ϵ���������
	virtual ~WCSCoverage();
	
public: 

	//! \brief ����ͶӰ
	//! \remarks ��ע��Ϣ��
	UGString m_mainCRS;
};

}
//////////////////////// End WMSLayer //////////////////////////////////
#endif // !defined(SMWEBLAYERINFO_H)

