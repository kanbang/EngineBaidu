
#ifndef __UGDATASOURCEVECTORINFO_H_
#define __UGDATASOURCEVECTORINFO_H_

#include "Stream/ugdefs.h"
#include "Projection/UGPrjCoordSys.h"
#include "Geometry/UGFeature.h"

namespace UGC 
{

	struct CACHEFILE_API UGDatasetVectorFieldInfo
	{
		UGString						m_strFieldName;			// �ֶ���
		UGFieldInfo::FieldType			m_nFieldType;			// �ֶ�����
		UGint							m_nFieldMaxLength;		// �ֶ���󳤶�
		UGint							m_nIndex;				// �ֶ�����

		UGDatasetVectorFieldInfo()
		{
			m_strFieldName = _U("");
			m_nFieldType = UGFieldInfo::UnKnown;
			m_nFieldMaxLength = 0;
			m_nIndex = 0;
		}
		~UGDatasetVectorFieldInfo(){};
		UGDatasetVectorFieldInfo& operator=(const UGDatasetVectorFieldInfo& fieldInfo);
	};

	class CACHEFILE_API UGDatasetVectorTileInfo 
	{
	public:
		UGDatasetVectorTileInfo();
		virtual ~UGDatasetVectorTileInfo();
		UGDatasetVectorTileInfo& operator=(const UGDatasetVectorTileInfo& vectorInfo);


	public:
		//! \brief ��ȡ���ݼ���
		UGString						GetDatasetName();
		void							SetDatasetName(UGString strDatasetName);

		//! \brief ��ȡ���ݼ�����
		UGint							GetDatasetType();
		void							SetDatasetType(UGint nDatasetType);


		//! \brief ��ȡ���ݼ�������Ϣ
		UGint							GetDatasetIndex();
		void							SetDatasetIndex(UGint nIndex);

		//! \brief ��ȡ���ݼ��ֶ���Ϣ
		UGArray<UGDatasetVectorFieldInfo*>	GetDatasetFieldInfos()const;
		void								SetDatasetFieldInfos(UGArray<UGDatasetVectorFieldInfo*> arrFieldInfos);

		//! \brief ����/��ȡ���ݼ�ͶӰ��Ϣ
		UGPrjCoordSys& GetPrjCoordSys();
		void SetPrjCoordSys(const UGPrjCoordSys& PrjCoordSys);	

		// ����UGDataSourceVectorTileInfo��ToXML/FromXMLʱ�����
		void SetPrjCoordSysIndex(UGint nPrjCoordSysIndex);	
		UGint GetPrjCoordSysIndex()const;

	private:
		void clear();


	private:

		UGString							m_strDatasetName;			// ���ݼ���
		UGint								m_nDatasetType;				// ���ݼ�����
		UGint								m_nIndex;					// ���ݼ�����
		UGPrjCoordSys						m_PrjCoordSys;				// ���ݼ�ͶӰ��Ϣ
		UGint								m_nPrjCoordSysIndex;		// ͶӰ���������
		UGArray<UGDatasetVectorFieldInfo*>	m_arrDatasetFieldInfos;		// ���ݼ��ֶ���Ϣ����

	};

	class CACHEFILE_API UGDataSourceVectorTileInfo
	{
	public:
		UGDataSourceVectorTileInfo(void);
		virtual ~UGDataSourceVectorTileInfo(void);
		UGDataSourceVectorTileInfo& operator=(const UGDataSourceVectorTileInfo& dataSourceInfo);

		UGArray<UGDatasetVectorTileInfo*> GetDatasetVectorInfos()const;
		
		//! \brief ���뵼�������ļ�
		UGbool FromXML(UGString strPath);
		UGbool ToXML(UGString strPathName);

		//! \brief ���ֶβ�ֳɼ��ֶ�����
		//! \param strField [in] ������ֶα��ʽ
		//! \param arrDelimas [out] ˳������������
		//! \return ��ֺ���ֶ�����
		static UGArray<UGString> SplitToSampleField(UGString strField, UGArray<UGString> &arrDelimas);
		
	private:
		void clear();

	protected:
		UGArray<UGDatasetVectorTileInfo*>	m_arrDatasetVectorInfo;  // ���ݼ�ʸ����Ϣ����
		UGString							m_strDataSourceName;	 // ����Դ����

	};
}

#endif //__UGDATASOURCEVECTORINFO_H_
