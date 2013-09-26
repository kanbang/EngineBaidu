/**  \file UGLayersRecordsetsManager.h
   \brief ʵ��Layers�м�¼���Ĺ���
   \author lugw
   \attention 
   Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
   All Rights Reserved.
 */ 

#if !defined(AFX_UGLAYERSRECORDSETSMANAGER_H__EE094C5F_85C5_441B_9AB8_CCA855D24FEE__INCLUDED_)
#define AFX_UGLAYERSRECORDSETSMANAGER_H__EE094C5F_85C5_441B_9AB8_CCA855D24FEE__INCLUDED_

#include "Stream/ugdefs.h"
#include "Map/UGLayer.h"


namespace UGC
{
	//{{zhouping 2010/12/27 bNullRecordsetΪtrueʱ��ʾpLayer�õ��ļ�¼��Ϊ��
	struct UGLayerIsNullRecordset
	{
		UGLayer* pLayer;
		UGbool bNullRecordset;
		UGLayerIsNullRecordset()
		{
			pLayer = NULL;
			bNullRecordset = false;
		};
	};
	//zhouping 2010/12/27}}

	struct UGRecordsetWithLayer 
	{
		UGRecordset* pRecordset;
		//{{zhouping 2010/12/22  layerArray�е�ÿ��Ԫ�ر�ʾͼ���Ӧ�ļ�¼���Ƿ�Ϊ�գ��ֶα��ʽ������ɣ�
		//pLastNotNullRecordsetLayer ��ʾlayerIsNullRecordsetArray�����һ����Ӧ��¼����Ϊ�յ�ͼ��
		//�޸�֮��pRecordset��ʾ�õ��ļ�¼�������Ϊ�յ�ͼ�㣨����Ӧһ�����ݼ������еĽ����¼��
		//bNullRecordsetWithCurLayer��ʾ��ǰͼ���Ӧ�ļ�¼���Ƿ�Ϊ��
		//pCurNotNullRecordsetLayer��ʾ��ǰ���Ʋ�ѯ��ͼ�㣬��¼������Ҫ��Ϊ�˽�����ͼ�㹲�����ݼ�ʱ��˭
		//�ͷŵ����⣬ԭ����pLastNotNullRecordsetLayer���㲻��Ҫ���ˣ�������ƵĹ���ȡ����ʱ�����ͼ��û��
		//�ͷ�
		UGArray<UGLayerIsNullRecordset> pLayerArray;
		UGLayer* pLastNotNullRecordsetLayer;
		UGLayer* pCurNotNullRecordsetLayer;
		UGbool bNullRecordsetWithCurLayer;
		//zhouping 2010/12/22}}
		UGRecordsetWithLayer()
		{
			pRecordset = NULL;
			pLayerArray.RemoveAll();
			pLastNotNullRecordsetLayer = NULL;
			pCurNotNullRecordsetLayer = NULL;
			bNullRecordsetWithCurLayer = false;
		};
	};

	struct UGDatasetWithRecordset
	{
		UGDatasetVector* pDv;
		UGArray<UGRecordsetWithLayer> pRecordsetArray;
		UGDatasetWithRecordset()
		{
			pDv = NULL;
			pRecordsetArray.RemoveAll();
		};
	};

class MAP_API UGLayersRecordsetsManager  
{
public:
	UGLayersRecordsetsManager();
#ifdef SYMBIAN60
	~UGLayersRecordsetsManager();
#else
	virtual ~UGLayersRecordsetsManager();
#endif
	//! \brief �õ���Ӧͼ���Recordset���ڲ��������Recordset
	/**
	����������ϸ����
	\param Layers       ��Layers�µ�����ͼ��[in] 
	\param pos          ��ǰ���Ʋ�λ��[in]
	\param pLayer       ��ǰ���Ʋ�[in]
	\param pGraphics    ��ǰ��ʾ����[in]
	\param pDrawing     ��ǰ���Ʋ���[in]
	\param bTemp        �ü�¼���Ƿ�Ϊ��ʱ[in/out]
	\return �ò��¼��
	*/
	UGRecordset* FindRecordsetWithLayer(UGList<UGLayer*> Layers, UGLayer* pLayer, UGGraphics* pGraphics, UGDrawing *pDrawing, UGbool& bTemp);

	//! \brief ��ȡ��ǰ��ͼ����ļ�¼����С
	UGuint GetSize()const;
	//! \brief ��յ�ͼ���еļ�¼��
	void RemoveAll();

	UGbool AppendQueryDefFields(UGQueryDef& qfTo,UGQueryDef& qfFrom);

	UGbool m_bIsflateBounds;

protected:

	UGbool GetQueryDef(UGList<UGLayer*> Layers, UGLayer* pLayer, UGGraphics* pGraphics, UGDrawing *pDrawing, UGRecordsetWithLayer& RecordsetWithLayerTemp);
	UGbool AddRecordsetWithLayer(UGRecordsetWithLayer& RecordsetWithLayerTemp,UGbool bFindDv);

private:
	UGArray<UGDatasetWithRecordset> m_pDatasetWithRecordset;
	UGArray<UGDatasetVector*> m_pDifDatasetsVector;
	UGuint m_nSize;
};

}

#endif // !defined(AFX_UGLAYERSRECORDSETSMANAGER_H__EE094C5F_85C5_441B_9AB8_CCA855D24FEE__INCLUDED_)

