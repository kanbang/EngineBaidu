#ifndef UGDATASETRELATIONSHIP_H
#define UGDATASETRELATIONSHIP_H

#include "Engine/UGEngDefs.h"
#include "Engine/UGTable.h"
#include "Engine/UGGeoAction.h"
#include "Geometry/UGDataCodec.h"


namespace UGC
{
	//!	\brief	�����ϵ����
	class ENGINE_API UGRelRule
	{
	public:
		enum SpatialType
		{
			//sptlNone		= 0,		// û��ָ���ռ����
			//sptlContain		= 1,	// ����
			//sptlContainedBy = 2,		// ������
			//sptlIntersect	= 3,		// �ཻ
			//sptlDisjoint	= 4,		// ����
			//sptlTouch		= 5,		// ���
			//sptlEqual		= 6,		// ���
			//sptlCross		= 7,		// ��Խ


			sptlNone					=-1,	// û��ָ���ռ����
			sptlIdentical				=0,		// ���
			sptlDisjoint				=1,		// ����
			sptlIntersects				=2,		// �ཻ
			sptlTouches					=3,		// ���
			//UGOverlaps				=4,		
			//UGCrosses					=5,	
			sptlWithin					=6,		// ������
			sptlContains				=7,		// ����
			//UGExtentIntersect			=8,	
			//UGRelate					=9,	

			//UGCommonPoint				=10,
			//UGCommonSegment			=11,
			//UGCentroidInPolygon		=12,
			sptlCross					=13		// ��Խ
		};

	public:
		//!	\brief	���Ŀ�����ݼ���ָ��������������Դ���ݼ��еĶ����Ƿ�����Ч��Χ��
		UGbool IsInOrgRange(UGuint nCount) { return nCount >= m_nOrgMinCard && nCount <= m_nOrgMaxCard; }

		//!	\brief	���Դ���ݼ���ָ��������������Ŀ�����ݼ��еĶ����Ƿ�����Ч��Χ��
		UGbool IsInDestRange(UGuint nCount) { return nCount >= m_nDestMinCard && nCount <= m_nDestMaxCard; }

	public:
		//! \brief	����
		UGRelRule(UGuint nID, UGuint nRelClsID, UGint nOrgSubtype, UGuint nOrgMinCard, UGuint nOrgMaxCard, \
			UGint nDestSubtype, UGuint nDestMinCard, UGuint nDestMaxCard, SpatialType nSpatialType):m_nID(nID), m_nRelClsID(nRelClsID), \
			m_nOrgSubtype(nOrgSubtype), m_nOrgMinCard(nOrgMinCard), m_nOrgMaxCard(nOrgMaxCard), m_nDestSubtype(nDestSubtype), \
			m_nDestMinCard(nDestMinCard), m_nDestMaxCard(nDestMaxCard), m_nSpatialType(nSpatialType) {}

		//! \brief	��������
		UGRelRule(const UGRelRule &relRule):m_nID(relRule.m_nID), m_nRelClsID(relRule.m_nRelClsID), \
			m_nOrgSubtype(relRule.m_nOrgSubtype), m_nOrgMinCard(relRule.m_nOrgMinCard), m_nOrgMaxCard(relRule.m_nOrgMaxCard), \
			m_nDestSubtype(relRule.m_nDestSubtype), m_nDestMinCard(relRule.m_nDestMinCard), \
			m_nDestMaxCard(relRule.m_nDestMaxCard), m_nSpatialType(relRule.m_nSpatialType) {}

		UGRelRule():m_nID(0), m_nRelClsID(0), m_nOrgSubtype(0), m_nOrgMinCard(0), m_nOrgMaxCard(0), \
			m_nDestSubtype(0), m_nDestMinCard(0), m_nDestMaxCard(0), m_nSpatialType(UGRelRule::sptlNone) {}

	public:
		//!	\brief	��ϵ�����ID
		UGuint m_nID;

		//!	\brief	��ϵ����������ϵ���ID
		UGuint m_nRelClsID;

		//!	\brief	Դ���ݼ�������ID
		UGint m_nOrgSubtype;

		//!	\brief	Դ���ݼ��ж��󱻹����ķ�Χ
		UGuint m_nOrgMinCard;
		UGuint m_nOrgMaxCard;

		//!	\brief	Ŀ�����ݼ�������ID
		UGint m_nDestSubtype;

		//!	\brief	Ŀ�����ݼ��ж��󱻹����ķ�Χ
		UGuint m_nDestMinCard;
		UGuint m_nDestMaxCard;

		//! \brief	�ռ���򣨰������ཻ�ȣ�
		UGRelRule::SpatialType m_nSpatialType;
	};


	//!	\brief	��¼ĳһ���ݼ��еĹ�������
	typedef struct ENGINE_API RelObjects
	{
		//! \brief	����
		RelObjects() {}
		RelObjects(const UGString &strName, const UGArray<UGint> &arrIDs):strDtName(strName) { objIDs.Copy(arrIDs); }


		//!	\brief	��������
		RelObjects(const RelObjects &relObjs):strDtName(relObjs.strDtName) { objIDs.Append(relObjs.objIDs); }


		//!	\brief	Դ��Ŀ�����ݼ�������
		UGString strDtName;

		//!	\brief	ָ�����ݼ��в��뵽��ϵ���е�Ŀ��
		UGArray<UGint> objIDs;

	} UGRelObjects;


	//!	\brief	�����������
	struct ENGINE_API ExclusionObjects : public RelObjects
	{
		//!	\brief	����
		ExclusionObjects():nRelClassID(0) {}
		ExclusionObjects(const UGString &strName, UGint nRelClsID, \
			const UGArray<UGint> &arrIDs):RelObjects(strName, arrIDs), nRelClassID(nRelClsID) {}

		//!	\brief	��������
		ExclusionObjects(const ExclusionObjects &exclsObjs):RelObjects(exclsObjs.strDtName, exclsObjs.objIDs), \
			nRelClassID(exclsObjs.nRelClassID) {}

		//!	\brief	��ϵ�����ƣ�ָ�����������ĸ���ϵ������Ϊ�������
		UGint nRelClassID;
	};

	typedef struct ExclusionObjects UGExclusionObjects;


	//!	\brief	���������ϵ
	typedef struct ENGINE_API ExclusionRelation
	{
		//!	\brief	����
		ExclusionRelation():nRelClassID(0), nOrgObjectID(0), nDestObjectID(0) {}
		ExclusionRelation(UGint nRelClsID, UGint nOrgObjID, UGint nDestObjID):nRelClassID(nRelClsID), \
			nOrgObjectID(nOrgObjID), nDestObjectID(nDestObjID) {}

		//!	\brief	��������
		ExclusionRelation(const ExclusionRelation &exclsRelation):nRelClassID(exclsRelation.nRelClassID), \
		nOrgObjectID(exclsRelation.nOrgObjectID), nDestObjectID(exclsRelation.nDestObjectID) {}

		//!	\brief	��ϵ���ID
		UGint nRelClassID;

		//!	\brief	Դ���ݼ��в���ù�ϵ�Ķ���ID
		UGint nOrgObjectID;

		//!	\brief	Ŀ�����ݼ��в���ù�ϵ�Ķ���ID
		UGint nDestObjectID;

	} UGExclusionRelation;


	//!	\brief	���������ϵ��
	typedef UGArray<UGExclusionRelation> UGExclusionRelations;


	//! \brief ����Ƿ���Ϣ
	class ENGINE_API UGIllegalMsg
	{
	public:
		//!	\brief	Υ�����������
		enum IllegalType
		{
			illNoRelation			= 0, // ����û�в�������κι���
			illOriginMin			= 1, // Υ���˶�Ŀ�굽Դ����СԼ��
			illOriginMax			= 2, // Υ���˶�Ŀ�굽Դ�����Լ��
			illDestinationMin		= 3, // Υ���˶�Դ��Ŀ�����СԼ��
			illDestinationMax		= 4, // Υ���˶�Դ��Ŀ������Լ��
			illSpatial				= 5  // Υ���˶Կռ�����Լ��
		};

	public:
		//! \brief	����
		UGIllegalMsg():m_IllegalType(illNoRelation) {}
		UGIllegalMsg(const UGIllegalMsg &illMsg):m_relRule(illMsg.m_relRule), m_relObjects(illMsg.m_relObjects), \
			m_strRelClassName(illMsg.m_strRelClassName), m_IllegalType(illMsg.m_IllegalType) {}

	public:
		//!	\brief	Υ����Լ������
		UGRelRule m_relRule;

		//! \brief	Υ��Լ������ĸ���������
		UGRelObjects m_relObjects;

		//! \brief	Υ�������ĸ���ϵ�ࣨ���ƣ��еĹ���
		UGString m_strRelClassName;

		//!	\brief	ָʾΥ������Լ�������е���һ���֣�����Դ��Ŀ���Լ�����֣����ǿռ�Լ�����֣�
		IllegalType m_IllegalType;
	};


	//! \brief	��¼��ϵ���һЩ������Ϣ
	typedef struct ENGINE_API RelationshipClassInfo
	{
		//! \brief	��ϵ��Ĺ������ͣ�һ��һ��һ�Զ࣬��Զ�
		enum CardinalityType 
		{ 
			ctOneToOne = 1, 
			ctOneToMany = 2, 
			ctManyToMany = 3
		};

		//! \brief	��Ϣ֪ͨ�ķ����ޣ���ǰ��Դ��Ŀ�꣩�����Ŀ�굽Դ������ǰ�����
		enum NotifyDirectory 
		{
			ndNone = 0, 
			ndForward = 1, 
			ndBackward = 2, 
			ndBoth = 3
		};


		//!	\brief	��ʼ��һЩ��Ա
		RelationshipClassInfo():cardType(ctOneToOne), notifyDir(ndNone), bComposition(FALSE), \
			bHasRelTable(FALSE) {}

		//! \breif	��������
		RelationshipClassInfo(const RelationshipClassInfo &relInfo):strName(relInfo.strName), strTableName(relInfo.strTableName), strOwner(relInfo.strOwner), \
			strOrgDtName(relInfo.strOrgDtName), strDestDtName(relInfo.strDestDtName), strForwardLable(relInfo.strForwardLable), \
			strBackwardLable(relInfo.strBackwardLable), cardType(relInfo.cardType), notifyDir(relInfo.notifyDir), \
			bComposition(relInfo.bComposition), bHasRelTable(relInfo.bHasRelTable), \
			strOrgPK(relInfo.strOrgPK), strDestPK(relInfo.strDestPK), strOrgFK(relInfo.strOrgFK), strDestFK(relInfo.strDestFK) {}


		//! \brief	��ϵ�����ݼ�������
		UGString strName;

		//! \brief	��ϵ�����ݼ�����
		UGString strTableName;

		//! \brief	��ϵ���ӵ���ߣ�ΪȨ����չ������
		UGString strOwner;

		//! \brief	Դ���ݼ����ƣ�����ʹ�����ݼ������Ƿ��������ĵ��ã������ʹ�����ݼ���ָ�룩
		UGString strOrgDtName;

		//! \brief	Ŀ�����ݼ�����
		UGString strDestDtName;

		//! \brief	Դ��Ŀ��Ĺ�ϵ˵����ǩ
		UGString strForwardLable;

		//! \brief	Ŀ�굽Դ�Ĺ�ϵ˵����ǩ
		UGString strBackwardLable;

		//! \brief	��������
		CardinalityType cardType;

		//! \brief	��Ϣ֪ͨ����
		NotifyDirectory notifyDir;

		//! \brief	�Ƿ�Ϊ���Ϲ�ϵ
		UGbool bComposition;

		//! \brief	�Ƿ�Ҫ����������
		UGbool bHasRelTable;

		//! \brief	Դ���ݼ������������������ݿ��е���������һ���£�
		UGString strOrgPK;

		//! \brief	Ŀ�����ݼ������������������ݿ��е���������һ���£�
		UGString strDestPK;

		//! \brief	�������в��յ�Դ���ݼ������
		UGString strOrgFK;

		//! \brief	�������в��յ�Ŀ�����ݼ������
		UGString strDestFK;

	} UGRelClassInfo;


	class UGDatasetRelClassManager;

	//!	\brief	�����ϵ��
	class ENGINE_API UGDatasetRelClass : public UGTable
	{

	public:
		//! \brief	����
		UGDatasetRelClass();
		UGDatasetRelClass(UGDataSource *pDs);

		//!	\brief	����
		virtual ~UGDatasetRelClass();

	public:
		//! \brief	���ݹ�ϵ����Ϣ������ϵ��
		UGbool Create(const UGRelClassInfo &rclsInfo);

		//!	\brief	�����й������Ա�Ĺ�ϵ��
		//	\param	fldInfos[IN]	��ϵ��������ֶ�
		UGbool Create(const UGRelClassInfo &rclsInfo, const UGFieldInfos &fldInfos);

		//!	\brief	�����й������Ա�Ĺ�ϵ��
		//	\param	DtvTable[IN]	�������Ӧ���������ݼ�
		UGbool Create(const UGRelClassInfo &rclsInfo, UGDatasetVector* pDtvTable);
		
		//! \brief  ׷�Ӽ�¼
		//  \param  pSrcRecordset �������¼��ָ��[in]
		virtual UGbool Append(UGRecordset* pSrcRecordset);

		//!	\brief	�����й������Ա�Ĺ�ϵ��
		UGbool SetRelClassInfo(const UGRelClassInfo &relInfo);

		//!	\brief	��ȡ��ϵ�����ݼ�������
		virtual UGDataset::DatasetType GetType() const { return RelClass; }

		//!	\brief	��ȡ��ϵ�����ݼ�������
		virtual UGString GetName() { return m_RelClassInfo.strName; }

		//!	\brief	��ȡ��ϵ�����Ա������
		virtual UGString GetTableName() { return m_strTableName; }

		//! \brief	��ȡ��ϵ�������Ϣ
		void GetRelClassInfo(UGRelClassInfo &result) const;


		//!	\brief	��ȡ�����������Ŀ
		UGint GetRelRuleCount() const { return (UGint)m_RelRules.GetSize(); }

		//! \brief	����һ����������
		UGbool CreateRelRule(UGint nOrgSubtype, UGuint nOrgMinCard, UGuint nOrgMaxCard, \
			UGint nDestSubtype, UGuint nDestMinCard, UGuint nDestMaxCard, UGRelRule::SpatialType nSpatialType);

		//!	\brief	��ȡ���еĹ�������
		const UGArray<UGRelRule>& GetAllRelRules() const { return m_RelRules; }

		//!	\brief	��ȡָ���Ĺ�������
		UGbool GetRelRuleByID(UGuint nID, UGRelRule &result) const;
		UGbool GetRelRuleByIndex(UGint nIndex, UGRelRule &result) const;

		//!	\brief	����Դ��Ŀ�����ݼ�����������ȡ��������
		UGbool GetRelRuleBySubtype(UGint nOrgSubType, UGint nDestSubType, UGRelRule &result) const;

		//!	\brief	ɾ��ָ���Ĺ�������
		virtual UGbool DeleteRelRuleByID(UGuint nID) = 0;
		UGbool DeleteRelRuleByIndex(UGint nIndex);

		//!	\brief	ָ��Դ��Ŀ�����ݼ���������ɾ����������
		UGbool DeleteRelRuleBySubtype(UGint nOrgSubType, UGint nDestSubType);

		//!	\brief	ɾ�����еĹ�������
		virtual UGbool DeleteAllRelRules() = 0;

		//!	\brief	�޸�ָ���Ĺ�������
		UGbool ModifyRelRuleByID(UGuint nID, UGuint nOrgMinCard, UGuint nOrgMaxCard, UGuint nDestMinCard, \
			UGuint nDestMaxCard, UGRelRule::SpatialType nSpatialRule);
		UGbool ModifyRelRuleByIndex(UGint nIndex, UGuint nOrgMinCard, UGuint nOrgMaxCard, UGuint nDestMinCard, \
			UGuint nDestMaxCard, UGRelRule::SpatialType nSpatialRule);

		//!	\brief	�޸���Դ��Ŀ�����ݼ�������Ψһȷ���Ĺ�������
		UGbool ModifyRelRuleBySubtype(UGint nOrgSubType, UGint nDestSubType, UGuint nOrgMinCard, UGuint nOrgMaxCard, \
			UGuint nDestMinCard, UGuint nDestMaxCard, UGRelRule::SpatialType nSpatialRule);


		//! \brief	Ϊָ����Դ���ݼ��е�Ŀ�꽨����ϵ
		UGbool BuildRelation(UGint orgID, const UGArray<UGint> &destIDs);
		UGbool BuildRelation(UGint orgID, UGRecordset &destRecordset);

		//! \brief	Ϊָ����Ŀ�����ݼ��е�Ŀ�꽨����ϵ
		UGbool BuildRelation(const UGArray<UGint> &orgIDs, UGint destID);
		UGbool BuildRelation(UGRecordset &orgRecordset, UGint destID);

		//!	\brief	���ݿռ�����Զ�������ϵ
		//	\remark	�ýӿ����Ϊ�����ѽ����ľ������Ϊ���ݣ�����
		//			���еĿռ�����Զ�������Ӧ�����Ķ����ϵ
		UGbool BuildRelationBySptlRule();

		//!	\brief	ɾ��Ϊָ��Ŀ���ѽ�����Ĺ�ϵ
		UGbool DeleteRelation(const UGRelObjects &relObjects);
		UGbool DeleteRelation(UGRecordset &recordset);

		//!	\brief	ָ��Դ���ݺ�Ŀ�����ݼ��е�Ŀ����ɾ����ϵ
		UGbool DeleteRelation(UGint nOrgID, UGint nDestID);


		//!	\brief	��ȡָ��Ŀ��Ĺ���Ŀ��
		virtual UGbool GetRelationObjects(const UGRelObjects &relObjects, UGRelObjects &result) = 0;
		UGbool GetRelationObjects(UGRecordset &recordset, UGRelObjects &result);


		//!	\brief	��Ч�Լ��
		//	\param	errMsgs[OUT]	���ط���ͳ�ƺ�Ĵ�����Ϣ
		//	\return	�����麯���ɹ���ִ���򷵻�TRUE�����򣬷���FALSE
		UGbool CheckValid(const UGRelObjects &relObjs, UGArray<UGIllegalMsg> &errMsgs);
		UGbool CheckValid(UGRecordset &recordset, UGArray<UGIllegalMsg> &errMsgs);

		
		//!	\brief	�򿪹�ϵ�����ݼ�
		virtual UGbool Open();

		//!	\brief	�رչ�ϵ�����ݼ�
		virtual void Close();

		//!	\brief	��ѯ�����������
		virtual UGRecordset* Query(const UGQueryDef &querydef);


		//!	\brief	ִ�в������˽ӿڸ�����Դ��Ŀ�����ݼ��еĶ���
		//	\param	impactObjects[OUT]	������Ӱ��Ķ���Դ��Ŀ�����ݼ�����Ӱ��Ķ���
		UGbool ExcuteOprt(const UGRelObjects &relObjects, const UGGeoAction &msg, UGArray<UGRelObjects> &arrImpactObjs);
		UGbool ExcuteOprt(UGRecordset *pRecordset, const UGGeoAction &msg, UGArray<UGRelObjects> &arrImpactObjs);

		//!	\brief	ִ�в������˽ӿ�ֻ����������ݼ��еĶ����������ݼ��е�Ŀ�겻��ᣩ
		//	\param	impactObjects[OUT]	������Ӱ��Ķ���(������ݼ�����Ӱ��Ķ���
		UGbool DealRelObjects(const UGRelObjects &relObjects, const UGGeoAction &msg, UGRelObjects &impactObjs);
		UGbool DealRelObjects(UGRecordset &recordset, const UGGeoAction &msg, UGRelObjects &impactObjs);
		
		//! \brief  ֱ�Ӵ�����Ķ���
		UGbool DealRelObjectsJustInput(const UGRelObjects &relObjects, \
			const UGGeoAction &msg, UGRelObjects &impactObjs);

		//! \brief	�ж��Ƿ��й��������
		UGbool HasRelTable();


		//! \brief ͨ����¼������ͷż�¼���ڴ�ռ䡣
		//! \param nIndex ��¼�����[in]��
		//! \return �Ƿ��ͷųɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		virtual UGbool ReleaseRecordset(UGint nIndex);

		//! \brief ͨ����¼��ָ���ͷż�¼���ڴ�ռ䡣
		//! \param *pRecordset ��¼��ָ��[in]��
		//! \return �Ƿ��ͷųɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		virtual UGbool ReleaseRecordset(UGRecordset *pRecordset);


		//! \brief	��ȡ��ϵ�������
		UGDatasetRelClassManager* GetDatasetRelClassManager();


		//!	\brief	��ĳһ����Ķ�������Ϊ����ϵ����������
		//	\param	bOrg[IN]	ָʾ������Դ����Ŀ�����ݼ��е�
		UGbool SetExclusionObject(UGint nObjectID, UGbool bOrg);

		//! \brief	��ĳһ����Ĺ�ϵ����Ϊ����ϵ��������ϵ
		//	\remark	nOrgObjectID��nDestObjectID֮��ȷ��һ������Ĺ�ϵ
		UGbool SetExclusionRelation(UGint nOrgObjectID, UGint nDestObjectID);

		//!	\brief	��ȡ����ϵ���е������������
		//	\param	arrExclsObjects[OUT]	����Դ��Ŀ�����ݼ��е������������
		virtual UGbool GetAllExclusionObjects(UGArray<UGExclusionObjects> &arrExclsObjects) = 0;

		//!	\brief	��ȡ����ϵ���е����������ϵ
		virtual UGbool GetAllExclusionRelations(UGExclusionRelations &exclsRelations) = 0;

		//! \brief	�ӱ���ϵ�����Ƴ�ָ�����������
		virtual UGbool RemoveExclusionObject(UGint nObjectID, UGbool bOrg) = 0;

		//!	\brief	�ӱ���ϵ�����Ƴ�ָ���������ϵ
		virtual UGbool RemoveExclusionRelation(UGint nOrgObjectID, UGint nDestObjectID) = 0;

		//!	\brief	�ӱ���ϵ�����Ƴ�ָ�������������������ϵ
		virtual UGbool RemoveExclusionRelation(UGint nObjectID, UGbool bOrg) = 0;

		//! \brief	�ӱ���ϵ�����Ƴ����е����⣨�����������������ϵ��
		virtual UGbool RemoveAllExclusion() = 0;

	public:
		//! \brief	������С�߳�
		virtual UGdouble GetMinZ() { return 0; }

		//! \brief	������С�߳�
		virtual void SetMinZ(UGdouble d) {}

		//! \brief	�������߳�
		virtual UGdouble GetMaxZ() { return 0; }

		//! \brief	�������߳�
		virtual void SetMaxZ(UGdouble d) {}

		//! \brief	�������ݼ���ά��
		virtual UGint GetDimension() { return 0; }

		//! \brief	�ж��Ƿ���ʸ�����ݼ�
		virtual UGbool IsVector() { return FALSE; }

		//! \brief	�ж��Ƿ���topo���ݼ�
		virtual UGbool IsTopoDataset() { return FALSE; }

		//! \brief	�ж��Ƿ���դ�����ݼ�
		virtual UGbool IsRaster() { return FALSE; }
		
		//! \brief �ж��Ƿ��ǹ�ϵ�����ݼ�
		virtual UGbool IsRelClass(){ return TRUE; }

		virtual UGbool IsLinkTable() { return FALSE; }

		//! \brief	�������ݼ��ķ�Χ
		virtual const UGRect2D& GetBounds() { return m_rc2Bounds; }

		//! \brief	�������ݼ��ķ�Χ
		virtual void SetBounds(const UGRect2D& r) {}

		//! \brief	���ؿռ����ݱ��뷽ʽ
		virtual UGDataCodec::CodecType GetCodecType() { return UGDataCodec::encNONE; }

		//! \brief	���ÿռ����ݱ��뷽ʽ
		virtual UGbool SetCodecType(UGDataCodec::CodecType c) { return TRUE; }

		//! \brief	�������ݼ���ѡ����Ϣ(�����ֽڵ��������ݴ���һЩ����)
		virtual UGint GetOptions() { return 0; }

		//! \brief	�������ݼ���ѡ����Ϣ
		virtual void SetOptions(UGint nOptions) {}

	protected:
		//!	\brief	����ϵ����Ϣ�Ƿ�Ϸ����Ϸ����򷵻�Դ��Ŀ�����ݼ��Ĺ����ֶ���Ϣ
		//	\param	infoOrgFld[OUT]		����Դ���ݼ������ֶ���Ϣ
		//			infoDestFld[OUT]	����Ŀ�����ݼ������ֶ���Ϣ
		UGbool CheckRelClassInfo(const UGRelClassInfo &rclsInfo, UGFieldInfo &infoOrgFld, UGFieldInfo &infoDestFld);

		//!	\brief	��ʼ����ϵ�����Ϣ
		//	\param	fldInfos[IN]	��ϵ��������ֶ���Ϣ
		UGbool InitRelClass(const UGRelClassInfo &rclsInfo, const UGFieldInfos &fldInfos);

		//!	\brief	��ʼ����ϵ�����Ϣ
		//	\param	pDtvTabl[IN]	������������������ݼ�
		UGbool InitRelClass(const UGRelClassInfo &rclsInfo, UGDatasetVector *pDtvTabl);

		//! \brief	��ȡ��һ�����õĹ���ID
		virtual UGuint GetNextRelRuleID() = 0;

		//!	\brief	�����µĹ����������ݿ���
		virtual UGbool InsertRelRuleToTable(const UGRelRule &relRule) = 0;

		//!	\brief	�������ݿ��еĹ�������
		virtual UGbool UpdateRelRuleToTable(const UGRelRule &relRule) = 0;

		//!	\brief	����ϵ���뵽��������
		//	\param	bOrg[IN]	��ʶָ������Դ����Ŀ�����ݼ��й����ֶε�ֵ
		UGbool InsertRelationToTable(const UGVariant &val, UGbool bOrg, const UGArray<UGVariant> &values);

		//!	\brief	����ָ���Ĵ��пռ����Ĺ����Զ���������Ĺ�ϵ
		UGbool BuildRelationByRelRule(const UGRelRule &relRule);

		//!	\brief	��Ϊ������չԤ���Ľӿڣ���Դ��Ŀ�����ݼ��У���ȡ����ָ������ļ�¼��������ͬ�飩
		//			ע�⣺�ⲿʹ��ʱ��Ӧ��ǰ�����ݼ�
		UGRecordset* GetRecordsetBySubtype(UGint nSubtype, UGbool bOrg);

		//! \brief	����ϵ�ӹ�������ɾ��
		//	\param	bOrg[IN]	��ʶָ������Դ����Ŀ�����ݼ��й����ֶε�ֵ
		UGbool DeleteRelationFromTable(const UGArray<UGVariant> &values, UGbool bOrg);

		//! \brief	����ϵ�ӹ�������ɾ��������ָ����ֵ������ֻɾ��һ����¼��
		UGbool DeleteRelationFromTable(const UGVariant &valOrg, const UGVariant &valDest);

		//!	\brief	�Ӽ�¼���л�ø������SmID
		UGbool GetIDsFromRecordset(UGRecordset &recordset, UGArray<UGint> &ids);
	

		//!	\brief	�����ݿ��в�ѯ��������
		//			ע�⣺��������������潫��һ��Ӧ�����ݼ���
		//	\param	bDynamic[IN]	ָʾ�Ƿ񷵻ض�̬�ļ�¼��
		//			bQueryGeometry[IN]	ָʾ��ѯ�Ƿ�ͬʱ��ѯ��������Ϣ
		UGRecordset* SearchRelObjects(const UGRelObjects &rObjects, UGbool bDynamic = FALSE, UGbool bQueryGeometry = FALSE);


		//!	\brief	����Ƿ���ͬ�������ݼ���ͬ���ı����
		virtual UGbool CheckNameAvailable(const UGString &strDtName, const UGString &strTableName) = 0;

		//!	\brief	����������
		//	\param	fldInfos[IN]	��ϵ��������ֶ���Ϣ
		virtual UGbool CreateRelTable(const UGFieldInfos &fldInfos) = 0;

		//! \brief �����������ݼ����������������������ݼ��ı�
		//	\param	pdtTable[IN]	�������ݼ�
		virtual UGbool CreateRelTableFromDt(UGDatasetVector* pdtTable){return FALSE;}

		//!	\brief	ɾ��������
		virtual void DropRelTable() = 0;

		//!	\brief	�ֱ���Դ��Ŀ�����ݼ���Ϊ�����ֶδ�������
		virtual UGbool BuildIndexForPKAndFK() = 0;

		//!	\brief	��SmRegister��SmRelations���в��������Ϣ
		virtual UGbool InsertRClsInfoToTable() = 0;

		//!	\brief	Ԥ���ӿڣ�Ϊ����������չ׼������ȡĳһָ�������Ӧ������
		UGint GetRelObjectSubtype(UGint nID, UGRecordset &recordset) { return 0; }

		//! \brief	���Դ��Ŀ�����Ŀռ�����Ƿ����ָ���ռ�����Ҫ��
		UGbool CheckRelObjectSpatial(const UGGeometry *pGeoOrg, const UGGeometry *pGeoDest, UGRelRule::SpatialType nSpatialType);

		//! \brief	�������ʱ�ӽӿ�CheckValid��������ĺ�������Ҫ����������ɷǷ���Ϣ��ͳ�ƺͷ���
		//	\param	nObjIDCurr[IN]		��ǰҪ����ͳ�ƺͼ��Ķ���ID
		//			arrValCompare[IN]	��nObjIDCurrָʾ������ص�ӳ�����ֵ
		//			pRcdsetObj[IN]		nObjIDCurrָʾ���������ļ�¼��
		//			relIDs[IN]			���ܵĹ�������ID����
		//			relVals[IN]			���ܵĹ���������Ӧ�Ĺ���ֵ
		//			pRcdsetRel[IN]		���ܵĹ������������ļ�¼��
		//			exclsRelations[IN]	�����ϵ
		//			errMsgs[OUT]		����ͳ�Ʒ����Ĵ�����Ϣ
		void StatisticIllegalMsg(UGint nObjIDCurr, const UGArray<UGVariant> &arrValCompare, UGRecordset *pRcdsetObj, \
			const UGArray<UGint> &relIDs, const UGArray<UGVariant> &relVals, UGRecordset *pRcdsetRel, \
			const UGExclusionRelations &exclsRelations, UGArray<UGIllegalMsg> &errMsgs);


		//!	\brief	������Ϣ�����޸ļ��ζ���
		void ModifyGeometryByAction(UGRecordset *pRecordset, const UGGeoAction &actMsg, UGArray<UGint> &idsDeal);

		//! \brief	ִ�ж�����ʱ�򣬹��������Ƿ���Ҫ��Ӧ
		//	\param	strDtName[in]	�ǵ�ǰִ�ж����Ķ��� ���ڵ����ݼ����֣�ͨ����ϵ�����Ϣ�����жϹ��������Ƿ���Ҫ��Ӧ
		//			actMsg[IN]		Ҫ���͵���Ϣ
		UGbool NeedSendMessage(const UGString &strDtName, const UGGeoAction &actMsg);


		//!	\brief	��SmRelRulesϵͳ���ж�ȡ����
		virtual UGbool QueryRules() = 0;


		//!	\brief	�����ݿ���д��������Ϣ
		virtual UGbool InsertExclusionToTable(UGExclusionRelation &exclsRelation) = 0;


		//!	\brief	�Դ����Ķ�����й��ˣ������޳����������
		UGbool FilterExclsObjects(const UGRelObjects &relObjs, UGRelObjects &result);

	protected:
		//! \brief	����������
		UGArray<UGRelRule> m_RelRules;

		//! \brief	Դ���ݼ�ָ��
		UGDataset *m_pOrgDt;

		//! \brief	Ŀ�����ݼ�ָ��
		UGDataset *m_pDestDt;

		//! \brief	��ϵ��Ļ�����Ϣ
		UGRelClassInfo m_RelClassInfo;

		//! \brief	��ϵ�����Ա������
		UGString m_strTableName;

		//!	\brief	�����������׸����ù���
		UGRect2D m_rc2Bounds;

		//! \brief ��¼��ָ��ļ��ϣ��򿪵����м�¼����������������֪����ô�ͷ�
		UGArray<UGRecordset*> m_Recordsets;
	};
}

#endif

