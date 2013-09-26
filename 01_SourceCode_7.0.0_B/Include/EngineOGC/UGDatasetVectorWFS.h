// SmWFSVector.h: interface for the UGDatasetVectorWFS class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SMWFSVECTOR_H__BD617A57_529C_414D_ABED_99EF4BC23929__INCLUDED_)
#define AFX_SMWFSVECTOR_H__BD617A57_529C_414D_ABED_99EF4BC23929__INCLUDED_

#include "Stream/ugexports.h"
#include "Engine/UGWebDatasetVector.h"
#include "EngineOGC/UGOGCLayerInfo.h"
#include "EngineOGC/UGWFSCapabilities.h"

namespace UGC
{

class ENGINEOGC_API UGDatasetVectorWFS : public UGWebDatasetVector  
{
public:
	//! \brief  Ĭ�ϵĹ��캯��
	UGDatasetVectorWFS();
	//! \brief  �����βεĵĹ��캯��
	UGDatasetVectorWFS(UGDataSource *pDataSource);
	//! \brief  �����βεĵĹ��캯��
	UGDatasetVectorWFS(UGDatasetVectorInfo& vInfo);
	//! \brief  Ĭ�ϵ���������
	virtual ~UGDatasetVectorWFS();

public:
	//! \brief ���ݲ�ѯ����õ��ڴ��¼����
	//! \param querydef ��ѯ����[in]��
	//! \return �ڴ��¼����
	UGRecordset* Query(const UGQueryDef& querydef);

	//! \brief ����WFS��GetFeature��URL����õ��ڴ��¼��,Ĭ�ϵȵ�EditRecordset��
	//! \param strURL WFS��GetFeature�����URL[in]��
	//! \return �ڴ��¼����
	UGRecordset* Query(const UGString &strURL);

	//! \brief ���ô����ݼ���Ӧ��FeatureTypeInfo��WFSͼ����Ϣ��
	//! \param arySrc ��������Դͼ����Ϣ[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool SetFeatureTypeInfo(const WFSFeatureType& layerSrc);	

	//! \brief �õ����ݼ���Ӧ��FeatureTypeInfo����Ϣ��
	//! \param aryDest ��������Դͼ����Ϣ[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool GetFeatureTypeInfo(WFSFeatureType& layerDest) const;	

	//! \brief �����õ����ݼ������Ͳ�д�뵽���ݼ���m_DatasetInfo��֧��
	//! \return �Ƿ�ɹ�����,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool ParseDatasetType();
	//! \brief �������ݼ��ж������,�ٶ���,��ֵ�Ƚ���ȷ,
	//! \brief ͨ��Register���ȡ
	//##ModelId=48203053011A
	virtual UGint GetObjectCount();

	//! \brief �жϵ�ǰ���ݼ��Ƿ�ɱ༭
	virtual UGbool CanUpdate();
private:


	//! \brief ����������Ϣ��ѯ�õ���¼����
	//! \param &rcQueryBound ��ѯ������󣬰���������Ϣ[in]��
	//! \return �ڴ��¼����
	//! \param bIsCached �Ƿ񻺳���������Դ[in]��
	UGRecordset* GetRecordsetVectorBounds(const UGQueryDef& queryBound, UGbool bIsCached);
	
	//! \brief ����IDs��ѯ�Ĳ�ѯ����õ���¼����
	//! \param queryIDs ��ѯ������󣬰�����ѯ��IDs[in]��
	//! \param bIsCached �Ƿ񻺳���������Դ[in]��
	//! \return �ڴ��¼����
	UGRecordset* GetRecordsetVectorIDs(const UGQueryDef& queryIDs, UGbool bIsCached);
	
	//! \brief ����General��ѯ�Ĳ�ѯ����õ���¼����
	//! \param queryGeneral ��ѯ������󣬰���General��ѯ�Ĳ���[in]��
	//! \param bIsCached �Ƿ񻺳���������Դ[in]��
	//! \return �ڴ��¼����	
	UGRecordset* GetRecordsetVectorGeneral(const UGQueryDef& queryGeneral, UGbool bIsCached);

	//! \brief ����GetFeauture�����URL�õ��ڴ����ݼ����ٲ�ѯ�õ��ڴ��¼����
	//! \param strURL GetFeauture�����URL[in]��
	//! \param queryDef ��ѯ�������[in]��
	//! \return �ڴ��¼����
	UGRecordset* GetRecordsetVector(UGString strGetFeatureURL,const UGQueryDef& queryDef);

	//! \brief �õ�ͼ����Ϣ�ı߽�����ϡ�
	//! \param layersInfo ͼ����Ϣ����[in]��
	//! \return �߽���Ρ�
	//! \remarks ����ͼ����Ϣ�ж���߿���ЩҲ���ϲ������շ��ؽ���
	UGRect2D GetLayersBoundUnion(const UGWebLayersInfos& layersInfo);

	//! \brief �õ��ɼ�ͼ���URL��ѯѡ�
	//! \param layersSrc ͼ����Ϣ����[in]��
	//! \return Layers URL��ѯѡ���ʽΪLayers = Layer1,Layer2,Layer3&amp;
	//! \remarks ��ʽΪLAYERS = Layer1,Layer2,Layer3&amp;��
	UGString GetLayersURLValue(UGWebLayersInfos layersSrc) const;

	//! \brief �õ��ɼ�ͼ���URL��ѯѡ�
	//! \param layersSrc ͼ��������[in]��
	//! \return Layers URL��ѯѡ�
	//! \remarks ��ʽΪLAYERS = Layer1,Layer2,Layer3&amp;��
	UGString GetLayersURLValue(UGArray<UGString> layersSrc) const;

	//! \brief �õ�ͼ������Χ��URL��ѯѡ�
	//! \return BBOX URL��ѯѡ�
	//! \remarks ��ʽΪ BBOX=-165.270004272461,-54.7538909912109,177.130187988281,83.1083221435547&amp��
	UGString GetBBoxURLValue(UGRect2D rcSrc) const;

	//! \brief �õ�IDs��ѯ��FeatureID URL��ѯѡ�
	//! \param *pIDs IDs����ָ��[in]��
	//! \param nCount IDs����[in]��
	//! \return FeatureID URL��ѯѡ���ʽΪFeatureID=state.1,state.2&amp;��
	//! \remarks ���磺FeatureID=state.1,state.2&��
	UGString GetFeatureIDURLValue(UGint *pIDs, UGint nCount) const;	

	//! \brief ͨ��GetFeature�����XML�ļ������ڴ�����Դ��
	//! \param strGetFeatureXMLPath GetFeature����õ���XML�ļ���ַ[in]��
	//! \param strDescribeXMLPath DescribeFeatureType����õ���XML�ļ���ַ[in]��
	//! \param versionGML ���������ʹ�õ���GML���ԺͰ汾[in]��
	//! \return �ڴ�����Դָ�롣
	UGDataSource* CreatDataSource(UGString strGetFeatureXMLPath, 
		UGString strDescribeXMLPath, UGGeometry::GMLVersionType versionGML);

	//! \brief �����õ���ǰFeatureType����Ӧ���ֶ���Ϣ���顣
	//! \param fieldInfos �����õ����ֶ���Ϣ����[in]��
	//! \param strTypeName �����õ���WFS���ݼ���[in]��
	//! \param edatasetType �����õ���WFS���ݼ�����[in]��
	//! \param strDiscribeXMLPath DescribeFeatureType����õ���XML�ļ���[in]��
	//! \return �Ƿ�ɹ�����,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	UGbool ParseFeatureType(UGFieldInfos& fieldInfos, UGString& strTypeName, 
		UGDataset::DatasetType& edatasetType, UGString strDescribeXMLPath);

	//! \brief ͨ��GetFeature�����XML�ļ��õ��ڴ�����Դ�ı߽��ͶӰ��
	//! \param CRSBound �ο�ϵ������Ϣ[in]��
	//! \param strDiscribeXMLPath GetFeature�����XML�ļ���ַ[in]��
	//! \return �Ƿ�ɹ�����,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	UGbool ParseFeatureBound(UGCRSBound& CRSBound, UGString strGetFeatureXMLPath);
	
	UGbool JudgeGeoLabel(UGString strLabelName);

	
	//! \brief ����mk�ҵ�һ���¶������õ���¼���
	//! \param *pRecordset [in] ��
	//! \param &mk [in] CMarkup����
	//! \param pGeoAdd [in] Ҫ��ӵļ��ζ���
	//! \param trans [in] ͶӰת�������������ü��ζ����ͶӰ��
	//! \param bTrans [in] �Ƿ����ͶӰ��ת����
	//! \param VersionGML [in] ��ȡ���ζ����gml�汾��	 	
	//! \attention ��
	UGString AddGeometry(UGRecordset *pRecordset,UGMarkup &mk,UGGeometry* pGeoAdd,	
		UGRefTranslator& trans,UGbool bTrans,UGGeometry::GMLVersionType VersionGML);

	//! \brief �����ֶ���Ϣ�õ�fieldinfo
	UGFieldInfo GetSysFieldInfo(const UGString & strName,
		const UGString & strForeignName,
		UGFieldInfo::FieldType nType,
		const UGString & strFormat,	
		const UGString & strDomain, 
		UGbool bUpdatable = TRUE,
		UGbool bRequired = FALSE,
		const UGString & strDefault = _U("")
		);
	void GetSysFieldInfos(UGDataset::DatasetType eDatasetType, UGFieldInfos &sysFieldInfos);

protected:
	
	//! \brief WFS����Դ��ͼ����Ϣ��
	//! \remarks ��ע��Ϣ��
	WFSFeatureType m_featureTypeInfo;

	//! \brief ��ѯ��Ԫ��ǰ׺
	//! \remarks ���� FeatureID=state.1,state.2 ��ǰ׺����state��
	UGString m_strElementName;

	//! \brief ���ݼ��Ƿ񾭹�ת����
	//! \remarks ��ע��Ϣ��
	UGbool m_bHasTrans;

	//! \brief ���ݼ��Ƿ���¹��ֶ���Ϣ��
	UGbool m_bFieldsUpdated;
 
	//! \brief  �ڻ�ȡ���ݶ�����Ŀʱ��
	//! \attention �Ե�һ�β�ѯΪ׼��	
	UGint m_nWFSObjectCount;
};

}
#endif // !defined(AFX_SMWFSVECTOR_H__BD617A57_529C_414D_ABED_99EF4BC23929__INCLUDED_)

