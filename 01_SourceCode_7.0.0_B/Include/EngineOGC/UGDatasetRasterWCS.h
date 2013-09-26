//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file SmWCSRaster.h
//!  \brief WCSդ�����ݼ��Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef SMWCSRASTER_H
#define SMWCSRASTER_H

#include "Stream/ugexports.h"
#include "Engine/UGWebDatasetRaster.h"
#include "EngineOGC/UGWCSCapabilities.h"

namespace UGC
{

//! \brief Coverage�ķ�Χֵ��
//! \remarks ͨ��������ʾ����ֵ��
struct AxisDescription
{
	//! \brief ����������
	UGString m_strAxisName;
	
	//! \brief ��������Сֵ��
	int m_nMin;
	
	//! \brief ���������ֵ��
	int m_nMax;
	
	//! \brief ��Чֵ
	int m_nNullVal;
};

//! \brief Coverage�ķ�Χֵ���顣
typedef UGArray<AxisDescription> AxisDescriptions;

class ENGINEOGC_API UGDatasetRasterWCS : public UGWebDatasetRaster  
{
	friend class CSmWCSParse;
public:
	//! \brief  Ĭ�ϵĹ��캯��
	UGDatasetRasterWCS();
    //! \brief  �����βεĵĹ��캯��
	UGDatasetRasterWCS(UGDatasetRasterInfo& rInfo);
	//! \brief  Ĭ�ϵ���������
	virtual ~UGDatasetRasterWCS();

public:
	//! \brief �õ������ڴ��դ�����ݼ���
	//! \param strGetCoverageURL ��Web����Դ����ͼƬ��URL[in]��
	//! \return դ�����ݼ�ָ�롣
	//! \remarks �������غ������ɴ˺�����װ��
	UGDatasetRaster* GetDatasetRaster(UGString strGetCoverageURL);
	
	//! \brief �õ������ڴ��դ�����ݼ�,���ڷŴ���Сƽ�Ʋ���������
	//! \param rcBound ����Ӱ���������Χ[in]��
	//! \param dWidth ����Ӱ��Ŀ��,��λ����[in]��
	//! \param dHeight ����Ӱ��ĸ߶�,��λ����[in]��
	//! \param strFormat ����Ӱ��ĵĸ�ʽ[in]��
	//! \return դ�����ݼ�ָ�롣
	UGDatasetRaster* GetDatasetRaster(UGRect2D rcQueryBound,
		UGint dWidth,UGint dHeight,UGString strFormat =_U(""));	

	//! \brief �õ�����Դ������ͼ�������顣
	//! \param aryLayerNames ͼ��������[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool GetAllLayerNames(UGArray<UGString>& aryLayerNames);
	
	//! \brief �õ�����Դ������ͼ��������顣
	//! \param aryLayerTitles ͼ���������[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetAllLayerTitles(UGArray<UGString>& aryLayerTitles);
	
	//! \brief �õ�����Դ������ͼ�������顣
	//! \param aryLayerIndexes ͼ��������[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetAllLayerIndexes(UGArray<UGint>& aryLayerIndexes);	
	
	//! \brief �õ����пɼ�ͼ�������顣
	//! \param aryLayerNames �ɼ�ͼ��������[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetVisibleLayerNames(UGArray<UGString>& aryLayerNames);
	
	//! \brief �õ����пɼ�ͼ��������顣
	//! \param aryLayerTitles �ɼ�ͼ��ͼ���������[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetVisibleLayerTitles(UGArray<UGString>& aryLayerTitles);
	
	//! \brief �õ����ݼ����пɼ���ͼ���ż��ϡ�
	//! \param aryLayerIndexes �ɼ�ͼ��������[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetVisibleLayerIndexes(UGArray<UGint>& aryLayerIndexes);
	
	//! \brief ���õ�ǰ���ݼ��Ŀɼ�ͼ�㡣
	//! \param aryLayerIndexes Դͼ��������[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	virtual UGbool SetVisibleLayers(const UGArray<UGint>& aryLayerIndexes);	
	
	//! \brief ���õ�ǰ���ݼ��Ŀɼ�ͼ�㡣
	//! \param aryLayerNames Դͼ����Ϣ����[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	virtual UGbool SetVisibleLayers(const UGArray<UGString>& aryLayerNames);	

public:
	//! \brief ��ʼ����ǰͼ����Ϣ��
	//! \param pWCCoverage WCS��Coverageͼ����Ϣ[in]��
	//! \return  �Ƿ�ɹ���ʼ����
	UGbool initCoverage(WCSCoverage* pWCCoverage)	;

	//! \brief �����õ���ǰCoverage�õ�ͼ�����ϸ��Ϣ��
	//! \param strDescribeXMLPath DescribeCoverage�����XML�ļ����ڵ�·��[in]��
	//! \return �Ƿ�ɹ�����,�ɹ�����TRUE,ʧ�ܷ���FALSE����
	UGbool ParseCoverage(WCSCapabilities* pwcsCapabilities);	

	//! \brief �����õ���ǰCoverage�õ�ͼ�����ϸ��Ϣ��
	//! \param strDescribeXMLPath DescribeCoverage�����XML�ļ����ڵ�·��[in]��
	//! remark WCS 1.1.1��1.1.2 �汾ʹ��
	//! \return �Ƿ�ɹ�����,�ɹ�����TRUE,ʧ�ܷ���FALSE����
	UGbool ParseDescribeCoverage(WCSCapabilities* pwcsCapabilities);	

	//! \brief �õ�ͼ������Χ��URL��ѯѡ�
	//! \return BBOX URL��ѯѡ�
	//! \remarks ��ʽΪ BBOX=-165.270004272461,-54.7538909912109,177.130187988281,83.1083221435547&amp��
	UGString GetBBoxURLValue(UGRect2D rcSrc) const;

	//! \brief �ָ��ַ�����
	//! \param strSrc Դ�ַ���[in]��
	//! \param arrStrDst Ŀ���ַ�������[in]��
	//! \param strseparator �ָ��[in]��
	void Split(UGString strSrc, UGArray<UGString>& arrStrDst, UGString strseparator);	
private:
	UGDatasetRaster* GetDatasetRaster(UGString strGetCoverageURL,
		 UGRect2D rcGeoref);

	//! \brief ͨ��GetCoverage�����XML�ļ������ڴ�����Դ��
	//! \param strGetCoverageXMLPath GetCoverage�����XML�ļ���ַ[in]��
	//! \param strImageFormat �����Ӱ���ʽ[in]��
	//! \return �ڴ�����Դָ�롣
	UGDataSource* CreatDataSource(const UGString& strGetCoverageXMLPath, 
		UGRect2D rcGeoRef = UGRect2D(0,0,0,0) ,UGString strImageFormat =_U(""));

public:
	//! \brief ���ظ�ʽ��
	UGString m_strNativeFormat;

	//! \brief ������֧�ֵ�Ӱ���ʽ�ַ������顣
	UGArray<UGString> m_SupportFormats;

	//! \brief WCS��Coverageͼ����Ϣ��
	WCSCoverage* m_pCoverageInfo;

	//! \brief WCSͼ��֧�ֵ����ꡣ
	AxisDescriptions m_aryAxis;
	
	//! \brief WCSͼ��֧�ֵĲο�ϵ������Ϣ���顣
	UGCRSBounds m_arySuportCRSBound;
	
	//! \brief spatialDomain�Ĳο�ϵ������Ϣ
	UGCRSBound m_spatialDomainEVlp;
	
	//! \brief Ӱ��ԭ��ȡ�
	int m_ImageWith;
	
	//! \brief Ӱ��ԭ�߶ȡ�
	int m_ImageHight;
	
	//! \brief WCSͼ��֧�ֵĿռ������
	UGArray<UGString> m_aryInterpolations;

	//! \brief WCSͼ��Ĭ��֧�ֵĿռ������
	UGString m_DefaultInterpolation;
};

}
#endif // !defined(SMWCSRASTER_H)

