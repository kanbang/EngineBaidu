#if !defined UGCHARTOBJECTINFO_H
#define UGCHARTOBJECTINFO_H

#include "Stream/ugdefs.h"
#include "Stream/ugexports.h"
#include "Engine/UGRecordset.h"
#include "ChartBase/UGS57Dictionary.h"
#include "Engine/UGDatasetGroup.h"
#include "ChartToolkit/UGS57DatasetGroupExt.h"
#include "ChartBase/UGS57ExtInfo.h"

namespace UGC{

	class UGChartSetting;

typedef void (UGSTDCALL *AfterChartLayerEditAttributeProc)(UGlong pWnd, UGbool& bEditAttribute);


	struct UGS57EdgeStyle{
		UGuint m_nFeatureId;
		UGuint m_nEdgeId;
		UGStyle m_style;
		UGbool m_bValid;
		UGS57EdgeStyle()
		{
			m_nFeatureId = 0;
			m_nEdgeId = 0;
			m_bValid = false;
		}
	};

	typedef void (UGSTDCALL *AfterModifiedEdgeStyleProc)(UGlong pWnd, UGArray<UGS57EdgeStyle>& s57EdgeStyles);


	class MAP_API UGChartObjectInfo
	{
	public:
		UGChartObjectInfo();
		~UGChartObjectInfo();

		const UGChartObjectInfo& operator =(const UGChartObjectInfo& chartAttiInfo);

		void SetRecordset(UGRecordset* pRecordset, UGDatasetGroup *pDatasetGroup);
		UGRecordset* GetRecordset();

		UGDatasetGroup* GetDatasetGroup();

		// ���á���ȡ�����17���ַ�����������ȫ��Ψһ��ʶ��
		void SetLNAM(const UGString& strLNAM);
		UGString GetLNAM()const;

		// ���á���ȡ�����RCID��������һ����ͼ�ڵ�Ψһ��ʶ
		void SetFeatureID(UGuint nFeatureID);
		UGuint GetFeatureID()const;

		// ���á���ȡ�����Ӧ�ļ�¼��ID
		void SetRecordsetID(UGint nRecordsetID);
		UGint GetRecordsetID()const;

		// ���á���ȡ��������ַ����
		void SetAcronym(const UGString& strAcronym);
		UGString GetAcronym()const;

		// ���á���ȡ�������
		void SetName(const UGString& strName);
		UGString GetName()const;

		// ���á���ȡ��걾�ػ�����
		void SetLocalName(const UGString& strLocalName);
		UGString GetLocalName()const;

		// ���á���ȡ���ı��룬OBJL�ֶ�ֵ
		void SetFeatureCode(UGint nFeatureCode);
		UGint GetFeatureCode()const;

		// ���á���ȡ�������
		void SetAgencyToken(const UGString& strToken);
		UGString GetAgencyToken()const;

		// ���á���ȡ���ζ�������
		void SetGeometryType(const UGGeometry::Type eType);
		UGGeometry::Type GetGeometryType()const;

		// ���á���ȡˮ��ֵ, ��ЧֵΪDouble��Сֵ 2.2250738585072014e-308
		UGbool SetDepth(UGdouble dDepth);
		UGdouble GetDepth()const;

		// ���á���ȡ��������
		void SetS57FeatureTypeName(const UGString& strTypeName);
		UGString GetS57FeatureTypeName()const;

		// ���á���ȡ����Master��17���ַ�����
		void SetMasterLNAM(const UGString& strLNAM);
		UGString GetMasterLNAM()const;

		// ���á���ȡ���ļ�������17���ַ�����
		void SetCollectionLNAM(const UGString& strLNAM);
		UGString GetCollectionLNAM()const;

		// ���á���ȡS57��׼�ж��������ֵ�������������Ի�����Ϣ��
		void SetS57Attribute(UGArray<UGS57AttiInfo>& s57Attributes);
		UGArray<UGS57AttiInfo> GetS57Attribute();

		// �ύ����ֵ
		UGbool UpdateS57Attribute(const UGString& strAcronym, UGVariant& valValue);

		void SetChartLayerEditAttributeFunc(AfterChartLayerEditAttributeProc pChartLayerEditAttiProc, UGlong pWnd);
		void SendChartLayerEditAttributeFunc(UGbool& bEditAttribute);

		void SetPointStyles(UGArray<UGStyle>& pointStyle);
		UGArray<UGStyle>& GetPointStyles();

		void SetEdgesStyle(UGArray<UGS57EdgeStyle>& aryEdgeStyle);
		UGArray<UGS57EdgeStyle> GetEdgesStyle();

		void SetModifiedLineStyle(UGArray<UGS57EdgeStyle>& aryEdgeStyle);

		void SetModifiedS57EdgeStyleFunc(AfterModifiedEdgeStyleProc pModifiedEdgeStyleProc, UGlong pWnd);
		void SendModifiedS57EdgeStyleFunc(UGArray<UGS57EdgeStyle>& s57EdgeStyles);

		void SetChartSetting(UGChartSetting *pChartSetting);
	private:
		//  ��ʼ��ֵ
		void Init();

		// ��DEST_LNAMֵ��ȡ��Ӧ��ϵ��SRC_LNAM.
		// nRIND ��ϵ����
		UGString GetRelationSrcLNAM(const UGint nRIND);
		
		// ��ȡS57��׼�ж��������
		UGbool ReadS57Attribute(UGS57SpecsObject& s57SpecsObj);

		UGbool WriteS57Attribute(UGS57AttiInfo& s57AttiInof);

		UGbool WriteS57Attribute(const UGString& strAcronym, UGVariant& valValue);
	private:
		UGRecordset *m_pRecordset;
		UGDatasetGroup *m_pDatasetGroup;
		// ��Ҫ�ṩ����Ϣ
		UGString m_strLNAM;
		UGuint  m_nFeatureID;
		UGString m_strAcronym;
		UGString m_strName;
		UGString m_strLocalName;
		UGint m_nFeatureCode;
		UGString m_strAgencyToken;
		UGGeometry::Type m_eGeoType;
		UGdouble m_dDepth;
		UGString m_strFeatureTypeName;
		UGString m_strMasterLNAM;
		UGString m_strCollectionLNAM;
		UGint m_nRecordsetID;
		UGArray<UGS57AttiInfo> m_AttiInfos;
		
		UGArray<UGStyle> m_pointStyle;
		//! \brief �����¼��ص������Ķ���ָ��
		UGlong m_pEventView;  

		UGChartSetting *m_pChartSetting;

		UGArray<UGS57EdgeStyle> m_s57EdgeStyles;
		UGArray<UGS57EdgeStyle> m_modifiedS57EdgeStyles;
		AfterChartLayerEditAttributeProc m_pAfterChartLayerEditAttributeFunc;
		AfterModifiedEdgeStyleProc m_pAfterModifiedEdgeStyleFunc;
	};
}

#endif
