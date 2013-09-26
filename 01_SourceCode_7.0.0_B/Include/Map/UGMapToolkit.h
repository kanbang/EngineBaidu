#if !defined(_UGMAPTOOLKIT_H_)
#define _UGMAPTOOLKIT_H_

#include "Map/UGMap.h"
#include "Engine/UGDatasetVector.h"
#include "Engine/UGDataSource.h"

namespace UGC {
	class MAP_API UGMapToolkit
	{
public:	
		//! \brief �ѵ�ͼ�е��ı�ͼ��תΪһ��CAD���ݼ�ʱ��ģʽ
		enum UGConvertOption
		{
			//! \brief  ֻת��ǩר��ͼͼ��
			UGThemeLabelOnly = 0,				
			//! \brief  ֻת�ı�ͼ��
			UGTextLayerOnly = 1,				
			//! \brief  ��ǩר��ͼ���ı�ͼ�㶼ת
			UGAll = 2					
		};
public:		
		//!brief �ѵ�ͼ�е������ı�ͼ��תΪһ��CAD���ݼ�,��Ҫ���ڳ�����
		/**
		\param pMap						��ͼ
		\param pDataSource				���������Դ
		\param strDatasetName			���ݼ�����
		\param convertOption			ת��ѡ��
		\return �������ɵ����ݼ�
		*/
		static UGDatasetVector* MapLabelToDataset(UGMap* pMap, UGDataSource* pDataSource, UGString strDatasetName,UGConvertOption convertOption);

		//!brief ��ĳ����ͼ�еĲ����ı�ͼ�㣨������ǩ��תΪһ��CAD���ݼ�,��Ҫ���ڳ�����
		/**
		\param pMap						��ͼ
		\param arrLayers				�ı�ͼ�㼯��
		\param pDataSource				���������Դ
		\param strDatasetName			���ݼ�����
		\param bVisibleLayerOnly		Ϊfalseʱ�ῼ�ǵ�ǰ�������²��ɼ���ͼ��
		\return �������ɵ����ݼ�
		*/
		static UGDatasetVector* ThemeOrTextLayersToDataset(UGMap* pMap, UGArray<UGLayer*>* arrLayers, UGDataSource* pDataSource, UGString strDatasetName, UGbool bVisibleLayerOnly);

		//!brief ��ĳ����ͼ�е��ı�ͼ�㣨������ǩ����ȡ����
		/**
		\param pMap						��ͼ
		\param convertOption			ת��ѡ��
		\return �����ı�ͼ�㼯��
		*/
		static UGArray<UGLayer*>* GetLabelLayers(UGMap* pMap, UGConvertOption convertOption);

		//!brief ��ĳ����ͼ�еĵ�ͼ���ȡ����
		/**
		\param pMap						��ͼ
		\param convertOption			ת��ѡ��
		\return �����ı�ͼ�㼯��
		*/
		static UGArray<UGLayer*>* GetPointLayers(UGMap* pMap);
	};
}

#endif // _UGMAPTOOLKIT_H_