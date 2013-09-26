#ifndef UGACTIONPROCESSOR_H
#define UGACTIONPROCESSOR_H

#include "Engine/UGEngDefs.h"
#include "Geometry/UGFeature.h"
#include "Engine/UGDDRRelation.h"
#include "Geometry/UGGeoPoint.h"
#include "Geometry/UGGeoLineM.h"


namespace UGC {

//!	\brief	��Ϊ������
class ENGINE_API UGActionBase
{
public:
	//!	\brief	��Ϊ�����߶����������
	enum ActionType
	{
		actOffset = 0,			// ƽ��
		actRotate = 1,			// ��ת
		actModifyAttribute = 2,	// �޸Ķ����������Ϣ
		actModifyGeometry = 3	// �޸Ķ���ļ�����Ϣ
	};

public:
	virtual ~UGActionBase() {}

protected:
	UGActionBase(ActionType eClassType) : m_eClassType(eClassType) {}
	UGActionBase() {}
	UGActionBase(const UGActionBase &act) {}

public:
	ActionType GetClassType() const { return m_eClassType; }

protected:
	//!	\brief	��������ݵ�����
	ActionType m_eClassType;
};


class UGDDRMasterBase;
class UGDDRMasterDynSeg;

//!	\brief	��Ϊ��Ӧ��
class ENGINE_API UGActionProcessorBase
{
public:
	virtual ~UGActionProcessorBase() {}

protected:
	UGActionProcessorBase() {}
	UGActionProcessorBase(const UGActionProcessorBase &actProc) {}

public:
	//!	\brief	����Ϊ����Ӧ����
	virtual UGbool Run(const UGActionBase *pAction, const UGDDRMasterBase *pDDRMaster) = 0;
};


class UGDataset;
class UGRecordset;

//!	\brief	���������޸���Ϊ
class ENGINE_API UGActModifyAttr : public UGActionBase
{
public:
	UGActModifyAttr() : UGActionBase(UGActionBase::actModifyAttribute), \
		m_nObjID(0), m_pDt(NULL) {}

	UGActModifyAttr(UGint nObjID, UGDataset *pDt, const UGFieldInfo &fldInfo, \
		const UGVariant &oldValue, const UGVariant &newValue) : \
		UGActionBase(UGActionBase::actModifyAttribute), m_nObjID(nObjID), \
		m_pDt(pDt), m_fldInfo(fldInfo), m_OldValue(oldValue), m_NewValue(newValue) {}

	UGActModifyAttr(const UGActModifyAttr &act) { *this = act; }

	virtual ~UGActModifyAttr() {}

public:
	const UGActModifyAttr& operator =(const UGActModifyAttr &act);

public:
	//!	\brief	�޸ĵ�Ŀ��
	UGint m_nObjID;

	//!	\brief	Ŀ���������ݼ�
	UGDataset *m_pDt;

	//!	\brief	�޸ĵ��ֶ�
	UGFieldInfo m_fldInfo;

	//!	\brief	�޸�ǰ��ֵ
	UGVariant m_OldValue;

	//!	\brief	�޸ĺ��ֵ
	UGVariant m_NewValue;
};

//!	\brief	���嶯̬�ֶ��ж������޸���Ϊ�Ĵ�����
class ENGINE_API UGActModAttrProcDynSeg : public UGActionProcessorBase
{
public:
	UGActModAttrProcDynSeg() {}
	virtual ~UGActModAttrProcDynSeg() {}

protected:
	UGActModAttrProcDynSeg(const UGActModAttrProcDynSeg &actDynSeg) {}

public:
	//!	\brief	����Ϊ����Ӧ����
	virtual UGbool Run(const UGActionBase *pAction, const UGDDRMasterBase *pDDRMaster);

protected:
	void ProcActForRouteDt(const UGActModifyAttr *pAction, const UGDDRMasterDynSeg *pDDRMaster);
	void ProcActForET(const UGActModifyAttr *pAction, const UGDDRMasterDynSeg *pDDRMaster);
	void ProcActForER(const UGActModifyAttr *pAction, const UGDDRMasterDynSeg *pDDRMaster);

	void ModifyRelObjsAttr(const UGActModifyAttr *pAction, const UGRelatedObjects &objs);
	void ModifyERObjsForFMOrTM(const UGActModifyAttr *pAction, const UGDDRMasterDynSeg *pDDRMaster, \
		const UGRelatedObjects &objs, UGbool bModGeoOnly = FALSE);
	void ModifyERObjsForRID(const UGActModifyAttr *pAction, const UGDDRMasterDynSeg *pDDRMaster, \
		const UGRelatedObjects &objs, UGbool bModGeoOnly = FALSE);

	UGGeoPoint GetCorrectedGeo(const UGVariant &routeID, const UGVariant &valM, \
		UGRecordset *pRecRoute, const UGString &strRIDRoute);
	UGGeoLineM GetCorrectedGeo(const UGVariant &routeID, const UGVariant &valFM, const UGVariant &valTM, \
		UGRecordset *pRecRoute, const UGString &strRIDRoute);
};

//!	\brief	�����޸ļ�����Ϣ����Ϊ
class ENGINE_API UGActModifyGeo : public UGActionBase
{
public:
	UGActModifyGeo() : UGActionBase(UGActionBase::actModifyGeometry), \
		m_pDt(NULL), m_pOldGeo(NULL), m_pNewGeo(NULL) {}
	UGActModifyGeo(UGDataset *pDt, UGGeometry *pOldGeo, UGGeometry *pNewGeo) : \
		UGActionBase(UGActionBase::actModifyGeometry), \
		m_pDt(pDt), m_pOldGeo(pOldGeo), m_pNewGeo(pNewGeo) {}
	UGActModifyGeo(const UGActModifyGeo &act) { *this = act; }

	virtual ~UGActModifyGeo()
	{
		delete m_pOldGeo, m_pOldGeo = NULL;
		delete m_pNewGeo, m_pNewGeo = NULL;
	}

public:
	const UGActModifyGeo& operator =(const UGActModifyGeo &act)
	{
		m_eClassType = act.m_eClassType;
		m_pDt = act.m_pDt;
		m_pOldGeo = act.m_pOldGeo;
		m_pNewGeo = act.m_pNewGeo;

		return *this;
	}

public:
	//!	\brief	�����������ݼ�
	UGDataset *m_pDt;

	//!	\brief	�����޸�ǰ�ļ�����Ϣ��Ӧ�ô���ID��Ϣ��
	UGGeometry *m_pOldGeo;

	//!	\brief	�����޸ĺ�ļ�����Ϣ��Ӧ�ô���ID��Ϣ��
	UGGeometry *m_pNewGeo;
};

//!	\brief	Ϊ��̬�ֶ��������޸ļ�����Ϣ��Ϊ�Ĵ�����
class ENGINE_API UGActModGeoProcDynSeg : public UGActionProcessorBase
{
public:
	UGActModGeoProcDynSeg() {}
	virtual ~UGActModGeoProcDynSeg() {}

protected:
	UGActModGeoProcDynSeg(const UGActModGeoProcDynSeg &actDynSeg) {}

public:
	//!	\brief	����Ϊ����Ӧ����
	virtual UGbool Run(const UGActionBase *pAction, const UGDDRMasterBase *pDDRMaster);

protected:
	void ModifyERGeo(const UGActModifyGeo *pAction, const UGDDRMasterDynSeg *pDDRMaster);
};

}

#endif