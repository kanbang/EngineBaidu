// UGDatasetRasterWMS.h: interface for the UGDatasetRasterWMS class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGDATASETRASTERWMS_H
#define UGDATASETRASTERWMS_H

#include "Stream/ugexports.h"
#include "Engine/UGWebDatasetRaster.h"
#include "EngineOGC/UGOGCLayerInfo.h"

namespace UGC
{
#define DEFAULT_SRS_NAME _U("EPSG:4326")
#define DEFAULT_NONE _U("NONE")

class ENGINEOGC_API UGDatasetRasterWMS  :public UGWebDatasetRaster
{
public:
	//! \brief  Ĭ�ϵĹ��캯��
	UGDatasetRasterWMS();
    //! \brief  �����βεĵĹ��캯��
	UGDatasetRasterWMS(UGDatasetRasterInfo& rInfo);
	//! \brief  Ĭ�ϵ���������
	virtual ~UGDatasetRasterWMS();
public:
	//! \brief �õ������ڴ��դ�����ݼ���
	//! \param strURL ��Web����Դ�����URL[in]��
	//! \return դ�����ݼ�ָ�롣
	//! \remarks �������غ������ɴ˺�����װ��
	virtual UGDatasetRaster* GetDatasetRaster(UGString strURL);
	
	//! \brief �õ������ڴ��դ�����ݼ�,���ڷŴ���Сƽ�Ʋ���������
	//! \param rcBound ����Ӱ���������Χ[in]��
	//! \param dWidth ����Ӱ��Ŀ��,��λ����[in]��
	//! \param dHeight ����Ӱ��ĸ߶�,��λ����[in]��
	//! \param strFormat ����Ӱ��ĸ�ʽ[in]��
	//! \return դ�����ݼ�ָ�롣
	virtual UGDatasetRaster* GetDatasetRaster(UGRect2D rcBound,
		UGint dWidth,UGint dHeight,UGString strFormat =_U("image/png"));
	
	//! \brief �õ�����Դ������ͼ�������顣
	//! \param aryNames ͼ��������[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetAllLayerNames(UGArray<UGString>& aryLayerNames);
	
	//! \brief �õ�����Դ������ͼ��������顣
	//! \param aryNames ͼ���������[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetAllLayerTitles(UGArray<UGString>& aryLayerTitles);
	
	//! \brief �õ�����Դ������ͼ�������顣
	//! \param aryNames ͼ��������[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetAllLayerIndexes(UGArray<UGint>& aryLayerIndexes);
	
	//! \brief �õ����пɼ�ͼ�������顣
	//! \param aryNames �ɼ�ͼ��������[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetVisibleLayerNames(UGArray<UGString>& aryLayerNames);
	
	//! \brief �õ����пɼ�ͼ��������顣
	//! \param aryNames �ɼ�ͼ��ͼ���������[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetVisibleLayerTitles(UGArray<UGString>& aryLayerTitles);
	
	//! \brief �õ����ݼ����пɼ���ͼ���ż��ϡ�
	//! \param aryNames �ɼ�ͼ��������[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetVisibleLayerIndexes(UGArray<UGint>& aryLayerIndexes);
	
	//! \brief ���õ�ǰ���ݼ��Ŀɼ�ͼ�㡣
	//! \param arySrc Դͼ��������[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	virtual UGbool SetVisibleLayers(const UGArray<UGint>& aryLayerIndexes);	
	
	//! \brief ���õ�ǰ���ݼ��Ŀɼ�ͼ�㡣
	//! \param arySrc Դͼ����Ϣ����[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	virtual UGbool SetVisibleLayers(const UGArray<UGString>& aryLayerNames);

	//! \brief �����Ƿ񱳾�͸����
	virtual void SetTransparent(UGbool bTransparent);

	//! \brief �õ��Ƿ񱳾�͸����
	virtual UGbool GetTransparent();
	
public:

	//! \brief �õ����ζ����������Ϣ��
 	//! \param posX [in] ��ָ����dWidth,dHeight��ѡ�����ѡ��x���ص㡣
	//! \param posY [in] ��ָ����dWidth,dHeight��ѡ�����ѡ��y���ص㡣��	
	//! \param dictQueryPairs [out] �õ���������ֵ�ԡ�
	//! \return ��	
	//! \attention ��
	UGbool GetWMSFeatureInfos(UGlong posX,UGlong posY,
							UGDict<UGString,UGString>& dictQueryPairs); 
	//! \brief ���õ�ǰ���ݼ�������ͼ�㡣
	//! \param arySrc Դͼ����Ϣ����[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool SetAllLayers(const UGWebLayersInfos& arySrc);
	
	//! \brief �õ���ǰ���ݼ�������ͼ�㡣
	//! \param aryDest Ŀ��ͼ����Ϣ����[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool GetAllLayers(UGWebLayersInfos& aryDest) const;	
	
	//! \brief ���õ�ǰ���ݼ��Ŀɼ�ͼ�㡣
	//! \param arySrc Դͼ����Ϣ����[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool SetVisibleLayers(const UGWebLayersInfos& arySrc);	
	
	//! \brief �õ���ǰ���ݼ��Ŀɼ�ͼ�㡣
	//! \param aryDest Ŀ��ͼ����Ϣ����[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool GetVisibleLayers(UGWebLayersInfos& aryDest) const;
 
	//! \brief �ڿɼ�ͼ���л�ȡ�ɲ�ѯ��ͼ�㡣
	//! \return �����Զ��ŷָ���ͼ���ַ�����
	UGString GetQueryableLayers();
	//! \brief ��ͼ������ʼ������ƽ���С�
	//! \param aryDest Ŀ��ͼ����Ϣ����[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool initLayers(WMSLayer* pWMSlayer);
	//! \brief ��WMSĳ��ͼ������m_arrWMSStyle�е�ĳһ���
	//! \param strLayName ��Ҫ���õ�ͼ������֡�
	//! \param strStyle �����õķ��
	//! \attention ��
	UGbool SetStyle(UGString &strLayName,UGString &strStyle);
	//! \brief �õ�����ͼ���֧�ֵ�style ��
	//! \attention ��
	//! \return ����style�ļ���
	UGArray<UGString> GetAllStyles();
	//! \brief ���ص�ͼʱָ���ĵ�ͼ��	 ��
	UGint GetMapWidth() 	const { return m_dWidth; }
	//! \brief ���ص�ͼʱָ���ĵ�ͼ��	 ��
    UGint GetMapHeight() const { return m_dHeight; }
private:
	//! \brief �õ�ͼ����Ϣ�ı߽�����ϡ�
	//! \param layersInfo ͼ����Ϣ����[in]��
	//! \return �߽���Ρ�
	//! \remarks ����ͼ����Ϣ�ж���߿���ЩҲ���ϲ������շ��ؽ���
	UGRect2D GetLatLonBoxUnion() const;

	//! \brief �õ�ͼ����Ϣ�ı߽�����ϡ�
	//! \param layersInfo ͼ����Ϣ����[in]��
	//! \return �߽���Ρ�
	//! \remarks ����ͼ����Ϣ�ж���߿���ЩҲ���ϲ������շ��ؽ���
	UGRect2D GetBoundingBoxUnion(UGString& strCrsName) const;

	//! \brief �õ�ʹ�õĲο�ϵ������
	//! \return �Ƿ�õ���
	UGbool GetUsedCRSBounds();	

	//! \brief �õ��ɼ�ͼ���URL��ѯѡ��,��ʽΪLayers = Layer1,Layer2,Layer3&amp;��
	//! \param layersSrc ͼ����Ϣ����[in]��
	//! \return Layers URL��ѯѡ�
	//! \remarks ��ʽΪLAYERS = Layer1,Layer2,Layer3&amp;��
	//! \attention ��
	UGString GetLayersURLValue() const;

	//! \brief �õ��ɼ�ͼ���URL��ѯѡ��,��ʽΪStyles = style1,style2...		
	//! \attention ��
 	UGString GetStylesURLValue() const;
	
	//! \brief �õ�ͼ������Χ��URL��ѯѡ�
	//! \param rcSrc ���ο����[in]��
	//! \return BBOX URL��ѯѡ�
	//! \remarks ��ʽΪ BBOX=-165.270004272461,-54.7538909912109,177.130187988281,83.1083221435547&amp��
	//! \attention ��
	UGString GetBBoxURLValue(const UGRect2D& rcSrc) const;



public:
	//! \brief �����ͼʱ��bounds	
	UGRect2D m_RcBound;
protected:
	//! \brief ��ƽ�������е�WMSͼ���б�
	UGWebLayersInfos m_arrAllLayers;

	//! \brief �ɼ���WMSͼ���б�
	UGWebLayersInfos m_arrVisibleLayers;

	UGbool m_bTransparent;

 
private:
	//! \brief WMSͼ������
	WMSLayer* m_pWMSlayer;
	//! \brief �洢ͼ����֧�ֵ���ʽ
	//! \remarks ��ע��Ϣ��
	UGArray<UGString> m_arrWMSStyle;
    //! \brief ����ͼ���style
	UGDict<UGString,UGString> m_arrRequestWMSStyle;
	//! \brief �����ͼʱָ���ĵ�ͼ��	
	UGint m_dWidth;
	//! \brief �����ͼʱָ���ĵ�ͼ��
	UGint m_dHeight ;

	
	
};

}
#endif // !defined(UGDATASETRASTERWMS_H)

