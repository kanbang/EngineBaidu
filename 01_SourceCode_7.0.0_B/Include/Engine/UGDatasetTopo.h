// UGDatasetTopo.h: interface for the UGDatasetTopo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDATASETTOPO_H__6F79F774_FF2A_4EB2_AB64_A5958D572828__INCLUDED_)
#define AFX_UGDATASETTOPO_H__6F79F774_FF2A_4EB2_AB64_A5958D572828__INCLUDED_

#include "Engine/UGDataset.h"
#include "Engine/UGDatasetVector.h"

namespace UGC{

//##ModelId=4820305302FD
	struct UGTopoDTPricision
	{
	//##ModelId=4820305302FF
		UGDatasetVector *pDataset;
	//##ModelId=48203053030D
		UGint nPricision;
	};

//##ModelId=48203053030E
	struct UGTopoRule
	{
	//##ModelId=482030530310
		UGint nID;
	//##ModelId=48203053031C
		UGDatasetVector *pDataset;
	//##ModelId=48203053031D
		UGDatasetVector *pCheckDataset;
	//##ModelId=48203053031E
		UGint nRule;
	};

	struct UGTopoRuleEx
	{
		//##ModelId=48203053031C
		UGString  strDatasetName;
		//##ModelId=48203053031D
		UGString strCheckDatasetName;
		//##ModelId=48203053031E
		UGint nRule;
	};

//##ModelId=48203053033C
class ENGINE_API UGDatasetTopo : public UGDataset
{
public: 
	//##ModelId=48203053033E
	UGDatasetTopo();
	//##ModelId=48203053034B
	virtual ~UGDatasetTopo();

public:
	//##ModelId=482030540001
	enum TopoRuleMode
	{
		                                             //������               ��������  �������
		
		RegionNoOverlap                       =  1,  //�������ص�           ��     -> ��

		RegionNoGaps                          =  2,  //�����޷�϶           ��     -> ��

		RegionNoOverlapWith                   =  3,  //���������ص�         ����� -> ��

		RegionCoveredByRegionClass            =  4,  //�汻����渲��       ����� -> ��

		RegionCoveredEach                     =  5,  //�������໥����       ����� -> ��

		RegionContainedByRegion               =  6,  //�汻�����           ����� -> ��

		RegionBoundaryCoveredByLine           =  7,  //��߽类�߸���       ����� -> ��

		RegionBoundaryCoveredByRegionBoundary =  8,  //��߽类��߽縲��   ����� -> ��

		RegionContainPoint                    =  9,  //�������             ��͵� -> ��

		LineNoIntersection                    = 10,  //�������ཻ           ��     -> ��

		LineNoOverlap                         = 11,  //�������ص�           ��     -> ��

		LineNoDangles                         = 12,  //����������           ��	   -> ��

		LineNoPseudonodes                     = 13,  //�����޼ٽ��         ��     -> ��

		LineNoOverlapWith                     = 14,  //���������ص�         �ߺ��� -> ��

		LineNoIntersectionOrInteriorTouch     = 15,  //�������ཻ���ڲ��Ӵ� ��     -> ��

		LineNoSelfOverlap                     = 16,  //�������Խ���         ��     -> ��

		LineNoSelfIntersection                = 17,  //���������ཻ         ��     -> ��

		LineCoveredByLine                     = 18,  //�߱��߸���           �ߺ��� -> ��

		LineCoveredByRegionBoundary           = 19,  //�߱���߽縲��       �ߺ��� -> ��

		LineEndpointCoveredByPoint            = 20,  //�߶˵㱻�㸲��       �ߺ͵� -> ��

		PointCoveredByLine                    = 21,  //�㱻�߸���           ����� -> ��

		PointCoveredByRegionBoundary          = 22,  //�㱻��߽縲��       ����� -> ��

		PointContainedByRegion                = 23,  //�㱻�����           ����� -> ��

		PointCoveredByLineEndpoint            = 24,  //�㱻�߶˵㸲��       ����� -> ��

		NoMultipart                           = 25,  //�޸��Ӷ���           (�ߡ���) -> (�ߡ���)

		PointNoIdentical                      = 26,  //���ظ���             ��	   -> ��

		PointNoContainedByRegion              = 27,  //�㲻�������         ����� -> ��

		LineNoIntersectionWithRegion          = 28,  //���������ཻ         �ߺ��� -> ��

		RegionNoOverlapOnBoundary             = 29,  //��߽��޽���         ����� -> ��

		RegionNoSelfIntersection              = 30,  //���������ཻ         ��     -> ��

		LineNoIntersectionWith                = 31,  //���������ཻ         �ߺ��� -> ��

		MustBeLargerThanTolerance			  = 32,  //�ڵ�������������� (�㡢�ߡ���)��(�㡢�ߡ���) -> ��

		MustExistIntersectVertex              = 33,  //�߶��ཻ��������ڽ��� (�ߡ���)��(�ߡ���) -> ��

		MustMatchWithVertex                   = 34,  //�ڵ�֮����뻥��ƥ�� (�㡢�ߡ���)��(�㡢�ߡ���) -> ��

		NoRedundantVertices					  = 35,  //�߶������߽�������ڵ�		  (�ߡ���) -> ��

		LineNoSharpAngle					  = 36,   //�����޴���          ��      ->��
	};
	
	//! \brief �������ݼ�����
	//##ModelId=48203053034D
	virtual DatasetType GetType() const
	{
		return Topo;
	};

	//! \brief �������ݼ���Ӧ����
	//##ModelId=48203053034F
	virtual UGString GetTableName();

	//! \brief ������С�߳�
	//##ModelId=482030530351
	virtual UGdouble GetMinZ();

	//! \brief ������С�߳�
	//##ModelId=48203053035C
	virtual void SetMinZ(UGdouble d);

	//! \brief �������߳�
	//##ModelId=48203053035F
	virtual UGdouble GetMaxZ();

	//! \brief �������߳�
	//##ModelId=48203053036B
	virtual void SetMaxZ(UGdouble d);

	//! \brief �������ݼ���ά��
	//##ModelId=48203053036E
	virtual UGint GetDimension();

	//! \brief �ж��Ƿ���ʸ�����ݼ�
	//##ModelId=482030530370
	virtual UGbool IsVector();

	//! \brief �ж��Ƿ���topo���ݼ�
	//##ModelId=48203053037A
	virtual UGbool IsTopoDataset();

	//! \brief �ж��Ƿ���դ�����ݼ�
	//##ModelId=48203053037C
	virtual UGbool IsRaster();

	//! \brief �ж��Ƿ��ǹ�ϵ�����ݼ�
	virtual UGbool IsRelClass();

	//##ModelId=48203053037E
	virtual UGbool IsLinkTable()
	{
		return FALSE; 
	};

	//! \brief �������ݼ��ķ�Χ
	//##ModelId=482030530380
	virtual const UGRect2D& GetBounds()
	{
		return m_rc2Bounds;
	};

	//! \brief �������ݼ��ķ�Χ
	//##ModelId=48203053038B
	virtual void SetBounds(const UGRect2D& r);

	//! \brief ���ؿռ����ݱ��뷽ʽ
	//##ModelId=48203053038E
	virtual UGDataCodec::CodecType GetCodecType();
	
	//! \brief ���ÿռ����ݱ��뷽ʽ
	//##ModelId=482030530390
	virtual UGbool SetCodecType(UGDataCodec::CodecType c);

public:
	//##ModelId=482030530399
	UGdouble GetInterval();
	//##ModelId=48203053039A
	void SetInterval(UGdouble dInterval);

	//! \brief ��������
	//! \param *pDatasetVector [in] ���ݼ�
	//! \param *pGeo [in] ����
	//! \return 
	//! \remarks ����������ݼ����������������Ϊ�գ���ѵ�ǰ�������ݼ���������Ϊ��
	//!			 ������ݼ�ָ��Ϊ�գ�������������ݼ�����		
	//! \attention 
	//##ModelId=48203053039C
	UGbool SaveDirtyRegion(UGDatasetVector *pDV = NULL, UGGeoRegion *pGeo = NULL);

	//added by luhao 2009.04.15
	//! \brief   ��������
	//! \param   pEraseRegion ���������[in] 
	//! \return  �ɹ�����TRUE��ʧ�ܷ���FALSE
	//! \remarks ���ԭ��:��UGTopoProcess::ValidateTopology()�����У������û�����һ��Ч����Σ�
	//!                   ������Ч��Ӧ�ø�������������Ч������������ཻ��������������
	UGbool EraseDirtyArea(const UGGeoRegion *pEraseRegion);
public:
	//topo���
	//! \brief ��Topo���ݼ������һ�����ݼ�
	//! \param *pDatasetVector [in] ���ݼ�
	//! \param nPricision [in] ���ݼ����ȷ�ΧΪ1-5,ֵԽ�󾫶�Խ�ͣ���nPricision����1-5��Χʱ������Сֵ1������
	//! \return ��
	//! \remarks ������ͬһ������Դ�����ݼ�
	//! \attention 
	//##ModelId=48203053039E
	virtual UGbool AddDataset(UGDatasetVector *pDatasetVector,UGint nPricision = 1);

	//! \brief ��Topo���ݼ����Ƴ�һ���������ݼ�����
	//! \param *pDatasetVector [in] ���ݼ�
	//! \attention 
	virtual UGbool RemoveDataset(UGDatasetVector *pDatasetVerctor);

	//! \brief ΪTopo���ݼ����Topo����
	//! \param pDatasetVector	Դ���ݼ�[in]	
	//! \param pdatasetCheck	Ŀ�����ݼ�[in]
	//! \param nRule			Topo����
	//! \remarks ��Ŀ�����ݼ�Ϊ��ʱ��Ϊ���ݼ����������˹�ϵ
	//##ModelId=4820305303A9
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,TopoRuleMode nRule,UGDatasetVector *pDatasetCheck = NULL);

	//! \brief ����ѡ�����ݼ����й��������ݼ���ȷ��ɾ��Rule
	//!      ��Ҫע��һ�����������ݼ��ж��Rule�������С��ɾ������
	//##ModelId=4820305303B2
	virtual UGbool DeleteRule(UGDatasetVector *pDatasetVector,TopoRuleMode nRule,UGDatasetVector *pDatasetCheck = NULL);

	//! \brief ���Topo�����ݼ�,����ʵ��
	//##ModelId=4820305303BB
	virtual UGbool GetAllRelation(UGArray<UGTopoDTPricision> &aryTopoRelations);

	//##ModelId=4820305303BE
	virtual UGbool GetAllRules(UGArray<UGTopoRule> &aryRules);

	//! \brief ���Topo�������ݼ�,����ʵ��
	//##ModelId=4820305303C1
	virtual UGDatasetVector * GetPointErrorDataset();
	//##ModelId=4820305303C3
	virtual UGDatasetVector * GetLineErrorDataset();
	//##ModelId=4820305303C5
	virtual UGDatasetVector * GetRegionErrorDataset();
	//##ModelId=4820305303C9
	virtual UGDatasetVector * GetDirtyAreaDataset();

	//! \brief ��ȡ����
	//! \param *pDatasetVector [in] ���ݼ�
	//! \return ��������
	//! \remarks �����ݼ�ָ��ǿ�ʱ��ȡ�������ݼ��������������ȡ�������ݼ�������
	//! \attention 
	//##ModelId=4820305303CB
	UGGeoRegion * GetDirtyArea(UGDatasetVector *pDV = NULL);

	//! \brief ���˹��򵼳���XML�ļ�
	virtual UGbool ToopRuleToXML(const UGString &strXMLFile);
	//! \brief ֱ�Ӵ�XML�������˹���
	virtual UGbool ToopRuleFromXML(const UGString &strXMLFile);

	//! \brief ����XML��ʽ�����˹���
	//! \param &strXML ���˹����XML�ļ�[in]
	//! \param &aryTopoRuleInfos ���˹�����Ϣ����[out]
	//! \return ����ʧ���򷵻�FALSE
	virtual UGbool ParseXML(const UGString &strXMLFile, UGArray<UGTopoRuleEx> &aryTopoRuleInfos);

	//! \brief �����˹�����Ϣ���鵼�����˹���
	//! \param &aryTopoRuleInfos ���˹�����Ϣ����[in]
	virtual void ImportTopoRule(const UGArray<UGTopoRuleEx> &aryTopoRuleInfos);

	//! \brief ��ȡ�������ݼ�
	virtual UGbool GetRelateDatasets(UGArray<UGDatasetVector *> &aryRelateDataset);

	//! \brief ��ȡ�������ݼ���
	virtual UGint GetRelationDtCount();

	//! \brief �����������ع������ݼ�
 	virtual UGDatasetVector* GetRelationDtTAt(UGint nIndex, UGint &nPricision);

	//!	\brief ���ù������ݼ�����
	virtual UGbool SetRelationDtPrecision(UGDatasetVector *pDatasetVector, UGint nPricision);

	//! \brief �Ƴ����й������ݼ�
	virtual void RemoveAllDataset();

	//! \brief ��ȡ���˹�����
	virtual UGint GetTopoRuleCount();

	//! \brief �����������˹���
	virtual UGTopoRule GetTopoRuleAt(UGint nIndex);

	//! \brief ���������޸����˹���
	virtual	UGbool SetTopoRuleAt(UGint nIndex, UGDatasetVector *pDataset, UGint nRule, UGDatasetVector *pCheckDataset = NULL);

	//! \brief ɾ���������˹���
	virtual void DeleteAllTopoRule();

	//! \brief �ж����ݼ��Ƿ���ĳ��ѡ����Ϣ
	virtual UGbool HasFlag(UGint nOption) const;

	//! \brief ע��ѡ����Ϣ
	virtual UGbool RegisterOption(UGint nOption);

	//! \brief ��ע��ѡ����Ϣ
	virtual UGbool UnRegisterOption(UGint nOption);

protected:
	//##ModelId=4820305303CC
	virtual UGbool AddSubDataset(UGTopoDTPricision structTopo);
	
public:
	//! \brief ���ݼ��������ݼ�ָ��
	//##ModelId=4820305303CF
	UGSubDtArray m_arySubDataset;
	//##ModelId=4820305303D0
	UGArray<UGTopoDTPricision> m_aryTopoRelationDts;
	//##ModelId=4820305303D8
	UGArray<UGTopoRule> m_aryTopoRules;
	//##ModelId=4820305303D9
	UGString m_strName;
	//##ModelId=4820305303DA
	UGint m_nOptions;
	//##ModelId=4820305303DB
	UGRect2D m_rc2Bounds;
	//##ModelId=482030540000
	UGdouble m_dInterval;
};

}

#endif // !defined(AFX_UGDatasetTopo_H__6F79F774_FF2A_4EB2_AB64_A5958D572828__INCLUDED_)

