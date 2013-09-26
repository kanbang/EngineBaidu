#ifndef UGRELATIONMASTER_H
#define UGRELATIONMASTER_H

#include "Engine/UGEngDefs.h"


namespace UGC {

class UGDDRBase;
class UGDDRMasterBase;
class UGDataset;
class UGRecordset;

//!	\brief	�����ϵ�Ĺ����߻��࣬��Ҫ�Ƕ����ṩ�ӿڲ�
class ENGINE_API UGRelationMasterBase
{
public:
	virtual ~UGRelationMasterBase();

protected:
	UGRelationMasterBase() : m_pDDRMaster(NULL) {}
	UGRelationMasterBase(UGDDRMasterBase *pDDRMaster) : m_pDDRMaster(pDDRMaster) {}
	UGRelationMasterBase(const UGRelationMasterBase &relMaster) {}

public:
	UGDDRMasterBase* SetDDRMaster(UGDDRMasterBase *pDDRMaster)
	{
		UGDDRMasterBase *pOldDDRMaster = m_pDDRMaster;
		m_pDDRMaster = pDDRMaster;

		return pOldDDRMaster;
	}

protected:
	UGDDRMasterBase *m_pDDRMaster;
};


class UGActionBase;
class UGDynSegInfo;
class UGDDRDynSeg;

//!	\brief	��ϵ����������Ҫ���ڶ������ʹ�õĽӿ�
class ENGINE_API UGRelationManager : public UGRelationMasterBase
{

	friend class UGDDRMasterDynSeg;
	friend class UGDynSegInfo;
public:
	//!	\brief	˵�����׽ӿ�Ϊ��Щ���ܷ���
	enum ManagerType
	{
		mtDynamicSegment = 0, // ��̬�ֶ�
		mtRelationClass	 = 1  // ��ϵ��
	};

public:
	UGRelationManager() {}
	UGRelationManager(UGDDRMasterBase *pDDRMaster) : UGRelationMasterBase(pDDRMaster) {}
	virtual ~UGRelationManager();

protected:
	UGRelationManager(const UGRelationManager &relManager) {}

public:
	//!	\brief	�������ݼ����ϵ��������Ϊ���ݼ������ݼ��佨����ϵ
	UGbool BuildRelationDt2Dt(const UGDDRBase *pDDR);

	//!	\brief	��ȡָ�����ݼ�����Ӧ�Ķ�̬�ֶι�ϵ
	UGDDRDynSeg* GetDDR(const UGDataset *pOrgDt, const UGDataset *pDestDt);

	//!	\brief	ɾ���������ݼ���Ĺ�ϵ
	UGbool RemoveRelationDt2Dt(const UGDataset *pOrgDt, const UGDataset *pDestDt);

	//!	\brief	ɾ����ָ�����ݼ��йص����й�ϵ
	UGbool RemoveRelationForDt(const UGDataset *pDt);

	//! \brief ɾ�����еĹ�ϵ
	UGbool RemoveAllRelation();

	//!	\brief	����Ϊ������Ӧ
	UGbool ProcessAction(const UGActionBase *pAction);

	//! \brief  ��ȡ���а���ָ�����ݼ��Ķ�̬�ֶ���Ϣ����
	void GetDynSegInfo(UGDataset *pDataset,UGArray<UGDynSegInfo*> &arrDynSegInfo);
	//! \brief  ��ȡ���ж�̬�ֶζ�����Ϣ���󼯺ϣ���Щ���󼯺�ͨ��������ԴOpen��ʱ���ʼ��
	void GetAllDynSegInfo(UGArray<UGDynSegInfo*> &arrDynSegInfo);

	//! \brief  �������ݼ�pDataset��ָ����ID��ugIds�����ҳ�ĳһ�ض��Ķ�̬�ֶζ����е�Route���ݼ�����Ӧ��recordset
	UGRecordset* QueryRouteDataset(UGDataset *pDataset,UGDataset *pRouteDataset,UGDataset *pETDataset,UGDataset *pRtDatset,UGArray<UGint> &ugIds);
	//! \brief  �������ݼ�pDataset��ָ����ID��ugIds�����ҳ�ĳһ�ض��Ķ�̬�ֶζ����е�EventTable���ݼ�����Ӧ��recordset
	UGRecordset* QueryETDataset(UGDataset *pDataset,UGDataset *pRouteDataset,UGDataset *pETDataset,UGDataset *pRtDatset,UGArray<UGint> &ugIds);
	//! \brief  �������ݼ�pDataset��ָ����ID��ugIds�����ҳ�ĳһ�ض��Ķ�̬�ֶζ����е�EventResult���ݼ�����Ӧ��recordset
	UGRecordset* QueryERDataset(UGDataset *pDataset,UGDataset *pRouteDataset,UGDataset *pETDataset,UGDataset *pRtDatset,UGArray<UGint> &ugIds);
};

}

#endif