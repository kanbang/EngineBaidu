#ifndef UGDDRRELATION_H
#define UGDDRRELATION_H

#include "Engine/UGEngDefs.h"


namespace UGC {

#define	DDR_DYNSEG_SYS_TABLE_NAME	_U("SmDDRDynSeg")

class UGDataset;
class UGRecordset;
class UGDatasetVector;

//! \brief	�������ݼ������ݼ���ϵ�Ļ��࣬���ڼ�¼���ݼ���Ĺ�ϵ
//			��DDR means Dataset to dataset relationship��
class ENGINE_API UGDDRBase
{
public:
	UGDDRBase(UGDataset *pOrgDt, UGDataset *pDestDt, \
		const UGString &strOrgPK, const UGString &strOrgFK) : m_pOrgDataset(pOrgDt), \
		m_pDestDataset(pDestDt) { m_strOrgPK = strOrgPK, m_strOrgFK = strOrgFK; }

	UGDDRBase(const UGDDRBase &ddr) : m_pOrgDataset(ddr.m_pOrgDataset), \
		m_pDestDataset(ddr.m_pDestDataset)
	{ m_strOrgPK = ddr.m_strOrgPK, m_strOrgFK = ddr.m_strOrgFK; }

	virtual ~UGDDRBase() {}

protected:
	//!	\brief	����Ĭ�Ϲ���
	UGDDRBase() {}

public:
	//!	\brief	���½ӿڻ�ȡ������Ϣ
	UGDataset* GetOrgDataset() const { return m_pOrgDataset; }
	UGDataset* GetDestDataset() const { return m_pDestDataset; }
	const UGString& GetOrgPrimaryKey() const { return m_strOrgPK; }
	const UGString& GetOrgForeignKey() const { return m_strOrgFK; }

protected:
	//!	\brief	Դ���ݼ�
	UGDataset *m_pOrgDataset;

	//!	\brief	Ŀ�����ݼ�
	UGDataset *m_pDestDataset;

	//!	\brief	Դ���ݼ��б�ʶ��ϵ�Ĺ����ֶ�
	UGString m_strOrgPK;

	//!	\brief	Ŀ�����ݼ��б�ʶ��ϵ�Ĺ����ֶ�
	UGString m_strOrgFK;
};


//!	\brief	���嶯̬�ֶε�DDR
class ENGINE_API UGDDRDynSeg : public UGDDRBase
{
public:
	//!	\brief	�������ݼ��ڶ�̬�ֶ�DDR�г䵱�Ľ�ɫ
	enum DynSegDatasetRole
	{
		dsdrNoneRole = -1,		// �޽�ɫ��������ʶδ���붯̬�ֶι�ϵ�����ݼ�
		dsdrRouteDataset = 0,	// ·�����ݼ�����LineM
		dsdrEventTable = 1,		// �¼���ͨ��ΪTabular���Ա�
		dsdrEventResult = 2		// �ֶν��������������ݼ���
	};

	enum DirectionType
	{
		dirOneSide = 0,			// �����ϵ����ϵ����ֻ���Ǵ�Դ��Ŀ�꣩
		dirBothSide = 1			// ˫���ϵ
	};

public:
	UGDDRDynSeg(UGDataset *pOrgDt, DynSegDatasetRole eOrgDtRole, \
		UGDataset *pDestDt, DynSegDatasetRole eDestDtRole, \
		const UGString &strOrgPK, const UGString &strOrgFK, \
		DirectionType eDirType) : UGDDRBase(pOrgDt, pDestDt, strOrgPK, strOrgFK), \
		m_eOrgDtRole(eOrgDtRole), m_eDestDtRole(eDestDtRole), \
		m_eDirType(eDirType) {}

	UGDDRDynSeg(const UGDDRDynSeg &ddrDynSeg) { *this = ddrDynSeg; }

	virtual ~UGDDRDynSeg() {}

protected:
	//!	\brief	����Ĭ�Ϲ���
	UGDDRDynSeg() {}

public:
	const UGDDRDynSeg& operator =(const UGDDRDynSeg &ddrDynSeg);

	//!	\brief	��ȡԴ��Ŀ�����ݼ��ڶ�̬�ֶ�DDR�еĽ�ɫ
	DynSegDatasetRole GetOrgDatasetRole() const { return m_eOrgDtRole; }
	DynSegDatasetRole GetDestDatasetRole() const { return m_eDestDtRole; }

	//!	\brief	��ȡ��ϵ�ڴ��ݷ����ϵ�����
	DirectionType GetDirectionType() const { return m_eDirType; }

	//!	\brief	���úͻ�ȡFromMeasure��ToMeasure
	void SetFMField(const UGString &strFldName) { m_strFromM = strFldName; }
	void SetTMField(const UGString &strFldName) { m_strToM = strFldName; }

	const UGString& GetFMField() const { return m_strFromM; }
	const UGString& GetTMField() const { return m_strToM; }

	//!	\brief	���úͻ�ȡET��ER�е�RouteID�ֶ�
	void SetRouteIDField(const UGString &strFldName) { m_strRouteIDFld = strFldName; }
	const UGString& GetRouteIDField() const { return m_strRouteIDFld; }

protected:
	//!	\brief	Դ�Լ�Ŀ�����ݼ���DDR�еĽ�ɫ
	DynSegDatasetRole m_eOrgDtRole;
	DynSegDatasetRole m_eDestDtRole;

	//!	\brief	ָʾET��ER���е�FromMeasure��ToMeasure�ֶΣ�
	//			���¼�Ϊ���¼�ʱ��ToMeasure������Ч
	UGString m_strFromM;
	UGString m_strToM;

	//!	\brief	ָʾET��ER�е�RouteID�ֶ�
	UGString m_strRouteIDFld;

	//!	\brief	��ʶDDR�ǵ�����˫���ϵ
	DirectionType m_eDirType;	
};


class ENGINE_API UGRelatedObjects
{
public:
	UGRelatedObjects(UGDataset *pDt, const UGArray<UGint> &objIDs, UGDataset *pDtFrom) : \
		m_pDataset(pDt), m_pDtSearchFrom(pDtFrom)
	{
		m_arrObjIDs.Copy(objIDs);
	}

	UGRelatedObjects(const UGRelatedObjects &objects) { *this = objects; }

	UGRelatedObjects() : m_pDataset(NULL), m_pDtSearchFrom(NULL) {}

public:
	const UGRelatedObjects& operator =(const UGRelatedObjects &objects)
	{
		m_pDataset = objects.m_pDataset;
		m_arrObjIDs.Copy(objects.m_arrObjIDs);
		m_pDtSearchFrom = objects.m_pDtSearchFrom;

		return *this;
	}

public:
	//!	\brief	���������������ݼ�
	UGDataset *m_pDataset;

	//!	\brief	��������ID��
	UGArray<UGint> m_arrObjIDs;

	//!	\brief	ָ����ͨ���ĸ�ֱ�ӵ����ݼ���������
	UGDataset *m_pDtSearchFrom;
};


class UGOORMasterBase;
class UGDynSegInfo;
class UGDDRDynSeg;

//!	\brief	����DDR�ٿ��߻��࣬����DDR�Ĵ������洢���������������ع���
class ENGINE_API UGDDRMasterBase
{
	friend class UGDynSegInfo;

public:
	//!	\brief	������������������
	enum DDRType
	{
		ddrForDynSeg = 0,	// ����UGDDRMasterDynSeg����
		ddrForRelClass = 1	// ������ϵ���DDRMaster���ࣨ������չ��
	};

public:
	virtual ~UGDDRMasterBase();

protected:
	//!	\brief	���ÿ��������Ĭ�Ϲ���
	UGDDRMasterBase() {}
	UGDDRMasterBase(DDRType eClassType) : m_eClassType(eClassType) {}
	UGDDRMasterBase(const UGDDRMasterBase &ddrM) {}

public:
	//!	\brief	��ȡ��������
	DDRType GetClassType() const { return m_eClassType; }


	//!	\brief	����DDR
	//!	\param	pDDR[IN]	DDR������	
	virtual UGbool BuildDDR(const UGDDRBase *pDDR) = 0;

	//!	\brief	ɾ��ָ����ϵ��DDR
	virtual UGbool RemoveDDR(const UGDataset *pOrgDt, const UGDataset *pDestDt) { return FALSE; }

	//!	\brief	ɾ����ָ�����ݼ��йص�����DDR
	virtual UGbool RemoveDDR(const UGDataset *pDt) { return FALSE; }

	//!	\brief	�������DDR
	virtual UGbool RemoveAllDDRs() { return FALSE; }

	//!	\brief	��ȡָ����ϵ��DDR����
	virtual UGDDRDynSeg* GetDDR(const UGDataset *pOrgDt, const UGDataset *pDestDt) const { return NULL; }



	//!	\brief	��ȡ��ָ��Ŀ����ֱ�ӹ�ϵ�Ĺ�������
	virtual void GetDirRelatedObjects(const UGDataset *pDt, const UGArray<UGint> &arrObjIDs, \
		UGArray<UGRelatedObjects> &result) const {}

	//!	\brief	��ȡ��ָ��Ŀ����ص����й������󣨰���ֱ�ӵĺͼ�ӵģ�
	virtual void GetAllRelatedObjects(const UGDataset *pDt, const UGArray<UGint> &arrObjIDs, \
		UGArray<UGRelatedObjects> &result) const {}

	//!	\brief	��ȡ��ָ�����ݼ�ֱ����ص����ݼ�
	virtual void GetDirRelatedDataset(const UGDataset *pDt, UGArray<UGDataset*> &result) const {}

	//!	\brief	��ȡ��ָ�����ݼ���ص��������ݼ�������ֱ�ӵĺͼ�ӵģ�
	virtual void GetAllRelatedDataset(const UGDataset *pDt, UGArray<UGDataset*> &result) const {}

	//! \brief  ��ȡ���а���ָ�����ݼ��Ķ�̬�ֶ���Ϣ����
	virtual void GetDynSegInfo(const UGDataset *pDataset,UGArray<UGDynSegInfo*> &arrDynSegInfo) const {}
	//! \brief  ��ȡ���ж�̬�ֶζ�����Ϣ���󼯺ϣ���Щ���󼯺�ͨ��������ԴOpen��ʱ���ʼ��
	virtual void GetAllDynSegInfo(UGArray<UGDynSegInfo*> &arrDynSegInfo) const {}

	//! \brief  �������ݼ�pDataset��ָ����ID��ugIds�����ҳ�ĳһ�ض��Ķ�̬�ֶζ����е�Route���ݼ�����Ӧ��recordset
	virtual UGRecordset* QueryRouteDataset(UGDataset *pDataset,UGDataset *pRouteDataset,UGDataset *pETDataset,UGDataset *pRtDatset,UGArray<UGint> &ugIds) { return NULL; }
	//! \brief  �������ݼ�pDataset��ָ����ID��ugIds�����ҳ�ĳһ�ض��Ķ�̬�ֶζ����е�EventTable���ݼ�����Ӧ��recordset
	virtual UGRecordset* QueryETDataset(UGDataset *pDataset,UGDataset *pLineMDataset,UGDataset *pETDataset,UGDataset *pRtDatset,UGArray<UGint> &ugIds) { return NULL; }
	//! \brief  �������ݼ�pDataset��ָ����ID��ugIds�����ҳ�ĳһ�ض��Ķ�̬�ֶζ����е�EventResult���ݼ�����Ӧ��recordset
	virtual UGRecordset* QueryERDataset(UGDataset *pDataset,UGDataset *pLineMDataset,UGDataset *pETDataset,UGDataset *pRtDatset,UGArray<UGint> &ugIds) { return NULL; }

protected:
	//!	\brief	DDR��������������OOR������Ϣ
	UGArray<UGOORMasterBase*> m_arrOORMasters;

	//!	\brief	�������������
	DDRType m_eClassType;
};


class UGOORMasterDynSeg;
class UGDynSegInfo;

//!	\brief	���嶯̬�ֶε�DDR�ٿ��ߣ���Ҫ��Զ�̬�ֶε��ض�ʵ��
class ENGINE_API UGDDRMasterDynSeg : public UGDDRMasterBase
{
public:
	UGDDRMasterDynSeg() : UGDDRMasterBase(UGDDRMasterBase::ddrForDynSeg) {}
	virtual ~UGDDRMasterDynSeg();

protected:
	//!	\brief	���ÿ�������
	UGDDRMasterDynSeg(const UGDDRMasterDynSeg &ddrMDynSeg) {}

public:
	//!	\brief	����DDR
	//!	\param	pDDR[IN]	DDR������	
	virtual UGbool BuildDDR(const UGDDRBase *pDDR);

	//!	\brief	ɾ��ָ����ϵ��DDR
	virtual UGbool RemoveDDR(const UGDataset *pOrgDt, const UGDataset *pDestDt);

	//!	\brief	ɾ����ָ�����ݼ��йص�����DDR
	virtual UGbool RemoveDDR(const UGDataset *pDt);

	//!	\brief	�������DDR
	virtual UGbool RemoveAllDDRs();

	//!	\brief	��ȡָ����ϵ��DDR����
	virtual UGDDRDynSeg* GetDDR(const UGDataset *pOrgDt, const UGDataset *pDestDt) const;


	//!	\brief	��ȡ��ָ��Ŀ����ֱ�ӹ�ϵ�Ĺ������󣬻���˵����ϵ
	virtual void GetDirRelatedObjects(const UGDataset *pDt, const UGArray<UGint> &arrObjIDs, \
		UGArray<UGRelatedObjects> &result) const;

	//!	\brief	��ȡ��ָ��Ŀ����ص����й������󣨰���ֱ�ӵĺͼ�ӵģ�������˵����ϵ
	virtual void GetAllRelatedObjects(const UGDataset *pDt, const UGArray<UGint> &arrObjIDs, \
		UGArray<UGRelatedObjects> &result) const;

	//!	\brief	��ȡ��ָ�����ݼ�ֱ����ص����ݼ�������˵����ϵ
	virtual void GetDirRelatedDataset(const UGDataset *pDt, UGArray<UGDataset*> &result) const;

	//!	\brief	��ȡ��ָ�����ݼ���ص��������ݼ�������ֱ�ӵĺͼ�ӵģ�������˵����ϵ
	virtual void GetAllRelatedDataset(const UGDataset *pDt, UGArray<UGDataset*> &result) const;

	//!	\brief	��ȡ��Ҫ���д���Ĺ���������Ҫ����Ķ���ο�����ĵ��й���������ʽ��������
	void GetRelObjsToProc(const UGDataset *pDt, const UGArray<UGint> &arrObjIDs, \
		UGArray<UGRelatedObjects> &result) const;

	//!	\brief	ΪER�е�Ŀ��������Ӧ��LineM�е�·�߶��󣬴������һ��Ϊ��������
	void GetRouteForERObj(const UGDataset *pDt, const UGArray<UGint> &arrObjIDs, \
		UGRelatedObjects &result) const;

	//! \brief  ��ȡ���а���ָ�����ݼ��Ķ�̬�ֶ���Ϣ����
	virtual void GetDynSegInfo(const UGDataset *pDataset,UGArray<UGDynSegInfo*> &arrDynSegInfo) const;
	//! \brief  ��ȡ���ж�̬�ֶζ�����Ϣ���󼯺ϣ���Щ���󼯺�ͨ��������ԴOpen��ʱ���ʼ��
	virtual void GetAllDynSegInfo(UGArray<UGDynSegInfo*> &arrDynSegInfo) const;

	//! \brief  �������ݼ�pDataset��ָ����ID��ugIds�����ҳ�ĳһ�ض��Ķ�̬�ֶζ����е�LineM���ݼ�����Ӧ��recordset
	virtual UGRecordset* QueryRouteDataset(UGDataset *pDataset,UGDataset *pRouteDataset,UGDataset* pETDataset,UGDataset *pRtDatset,UGArray<UGint> &ugIds);
	//! \brief  �������ݼ�pDataset��ָ����ID��ugIds�����ҳ�ĳһ�ض��Ķ�̬�ֶζ����е�EventTable���ݼ�����Ӧ��recordset
	virtual UGRecordset* QueryETDataset(UGDataset *pDataset,UGDataset *pRouteDataset,UGDataset* pETDataset,UGDataset *pRtDatset,UGArray<UGint> &ugIds);
	//! \brief  �������ݼ�pDataset��ָ����ID��ugIds�����ҳ�ĳһ�ض��Ķ�̬�ֶζ����е�EventResult���ݼ�����Ӧ��recordset
	virtual UGRecordset* QueryERDataset(UGDataset *pDataset,UGDataset *pRouteDataset,UGDataset* pETDataset,UGDataset *pRtDatset,UGArray<UGint> &ugIds);

protected:
	//!	\brief	���DDR����Ч��
	UGbool CheckDDR(const UGDDRDynSeg &ddrDynSeg);

	//! \brief	DDR��Ϣ���
	virtual UGbool RecordDDRToDB(const UGDDRDynSeg &ddrDynSeg) { return TRUE; }

	//!	\brief	����OORMaster����
	virtual UGOORMasterDynSeg* MakeOORMaster(const UGDDRDynSeg &ddrDynSeg);

	//!	\brief	�����ݿ���ɾ��DDR��¼
	virtual UGbool DeleteDDRFromDB(const UGDataset *pOrgDt, const UGDataset *pDestDt) { return TRUE; }
	virtual UGbool DeleteDDRFromDB(const UGDataset *pDt) { return TRUE; }
	virtual UGbool DeleteAllDDRsFromDB() { return TRUE; }

	//!	\brief	�ڸ�����������������ӹ�ϵ���У��ݹ�������������
	//!	\param	pDt[IN]					�������ݼ�����������ʼ���ݼ�
	//			arrDtSearched[IN, OUT]	�������������ݼ������ڷ�ֹ�ظ������ͻػ�
	void SearchRelObjects(const UGDataset *pDt, const UGArray<UGint> &arrObjIDs, \
		UGArray<const UGDataset*> &arrDtSearched, UGArray<UGRelatedObjects> &result) const;

	void SearchRelDt(const UGDataset *pDt, UGArray<const UGDataset*> &arrDtSearched, \
		UGArray<UGDataset*> &result) const;

	//!	\brief	���ݸ�DDR���������ú����ݼ��Ľ�ɫ
	void InitDatasetRole();

	//!	\brief	���ָ�����ݼ��Ƿ��ڲ��붯̬�ֶΣ����û�У���������ݼ��Ķ�̬�ֶν�ɫ
	void CheckAndCleanDtRole(const UGDataset *pDt);

private:
	//��̬�ֶζ�����Ϣ���󼯺�
	UGArray<UGDynSegInfo *>   m_arrDynSegInfoPtr;
};


//!	\brief	����OOR�ٿ��߻��࣬����OOR�Ľ������洢���������������ع���
//			��OOR means Object to object relationship����DDR������������
//			������OOR�����ÿһ��DDR��������Ӧ��һ��OOR���ϣ���UGOORMaster����
class ENGINE_API UGOORMasterBase
{
	friend class UGDDRMasterDynSeg;

protected:
	//!	\brief	���ÿ��������Ĭ�Ϲ���
	UGOORMasterBase() {}
	UGOORMasterBase(const UGOORMasterBase &oorM) {}

public:
	virtual ~UGOORMasterBase();

public:
	//!	\brief	����OOR
	virtual UGbool BuildOOR(UGint nOrgObjID, UGint nDestObjID) { return TRUE; }

	//!	\brief	��ȡָ������Ĺ�������
	virtual void GetRelatedObjects(const UGArray<UGint> &arrObjIDs, \
		UGbool bOrgOrDest, UGArray<UGint> &result) const = 0;

protected:
	//!	\brief	��Ӧ��DDR����
	UGDDRBase *m_pDDR;
};


//!	\brief	���嶯̬�ֶε�OOR�ٿ��ߣ���Ҫ��Զ�̬�ֶε��ض�ʵ��
class ENGINE_API UGOORMasterDynSeg : public UGOORMasterBase
{
public:
	UGOORMasterDynSeg(const UGDDRDynSeg &ddrDynSeg, const UGDDRMasterDynSeg *pDDRMaster);
	virtual ~UGOORMasterDynSeg();

protected:
	//!	\brief	���ÿ��������Ĭ�Ϲ���
	UGOORMasterDynSeg() {}
	UGOORMasterDynSeg(const UGOORMasterDynSeg &oorM) {}

public:
	//!	\brief	��ȡָ������Ĺ�������
	virtual void GetRelatedObjects(const UGArray<UGint> &arrObjIDs, \
		UGbool bOrgOrDest, UGArray<UGint> &result) const;
	
protected:
	//!	\brief	��ʶOOR������DDRMaster
	const UGDDRMasterDynSeg *m_pDDRMaster;
};

//!	\brief ���嶯̬�ֶ���Ϣ�࣬��ÿһ�鶯̬�ֶ���Ϣ���ж�Ӧ�ð���Route��EventTable��EventResult�������ݼ�
//! \brief ����������֮��������ݿ��SmDDRDynSeg�м�¼�Ĺ�ϵ�����
class ENGINE_API UGDynSegInfo
{
public:
	UGDynSegInfo();
	~UGDynSegInfo();
	//! \brief ��ȡRoute���ݼ�
	UGDataset* GetRouteDataset(){return m_pRouteDataset;}
	//! \brief ��ȡEventTable���ݼ�
	UGDataset* GetEventDataset(){return m_pEventDataset;}
	//! \brief ��ȡEventResult���ݼ�
	UGDataset* GetResultDataset(){return m_pResultDataset;}
	//! \brief ��ָ�����ݼ�����ΪRoute���ݼ�
	UGbool SetRouteDataset(UGDataset *pDataset);	
	//! \brief ��ָ�����ݼ�����ΪEventTable���ݼ�
	UGbool SetEventDataset(UGDataset *pDataset);
	//! \brief ��ȡEventResult���ݼ�
	UGbool SetResultDataset(UGDataset *pDataset);
	//�� \brief ����ָ���Ľ�ɫָ�������ݼ��������ݼ��洢��Route��EventTable����EventResult���ݼ�
	UGbool SetRoleDataset(UGDDRDynSeg::DynSegDatasetRole role,UGDataset * pDataset);
	//!  \brief �ж�ָ�������ݼ��Ƿ��ڴ˶�̬�ֶ���Ϣ���У���������򷵻����Ľ�ɫ
	UGDDRDynSeg::DynSegDatasetRole GetDatasetRole(const UGDataset * pDatatset);

private:
	//�� \brief Route���ݼ�
	UGDataset* m_pRouteDataset;
	//�� \brief EventTable���ݼ�
	UGDataset* m_pEventDataset;
	//�� \brief EventResult���ݼ�
	UGDataset* m_pResultDataset;
};

}

#endif