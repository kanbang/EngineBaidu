#ifndef UGDATASETRELCLASSMANAGER_H
#define UGDATASETRELCLASSMANAGER_H


#include "Engine/UGDatasetRelClass.h"


namespace UGC {

#define	RELCLASS_SYS_TABLE_NAME		_U("SmRelations")
#define RELRULE_SYS_TABLE_NAME		_U("SmRelRules")
#define EXCLUSION_SYS_TABLE_NAME	_U("SmExclusion")

class UGDataSource;

// ����Դ��ֱ�Ӳ��� ��ϵ�����ݼ������� ͨ��UGDatasetRelationMananger ������
class ENGINE_API UGDatasetRelClassManager
{
public:
	//! \brief	�� ����Դ ���죬���Դ�����Դ��ȡUGDatasetRelationMananger
	UGDatasetRelClassManager(UGDataSource *pDataSource);
	
	//! \brief	��������
	virtual ~UGDatasetRelClassManager();

public:
	//! \brief	������ϵ�����ݼ�
	UGDatasetRelClass* CreateDatasetRelClass(const UGRelClassInfo &rsInfo);
	UGDatasetRelClass* CreateDatasetRelClass(const UGRelClassInfo &rsInfo, const UGFieldInfos &fldInfos);

	//! \brief	ɾ����ϵ�����ݼ�
	virtual UGbool DeleteDatasetRelClass(const UGString &strName);

	//! \brief	ͨ������Դ ��ȡ ע������ ��ϵ�����ݼ������m_datasets 
	virtual UGbool InitDatasets() { return FALSE; }

	//!	\brief	������еĹ�ϵ��ָ��
	void RemoveAllRelClass() { m_RelClasses.RemoveAll(); }


	//!	\brief	��ϵ�Ϸ��Լ��
	//	\param	errMsgs[OUT]	���ط���ͳ�ƺ�Ĵ�����Ϣ
	//	\return	�����麯���ɹ���ִ���򷵻�TRUE�����򣬷���FALSE
	UGbool CheckValid(const UGArray<UGRelObjects> &arrRelObjects, UGArray<UGIllegalMsg> &errMsgs);
	UGbool CheckValid(UGArray<UGRecordset*> &arrRecordset, UGArray<UGIllegalMsg> &errMsgs);

	//!	\brief	��ϵ��������
	//	\return	�����麯���ɹ���ִ���򷵻�TRUE�����򣬷���FALSE
	UGbool SetException(UGint nObjectID, UGString strDtName);

	//!	\brief	��ϵɾ������
	//	\return	�����麯���ɹ���ִ���򷵻�TRUE�����򣬷���FALSE
	UGbool RemoveException(UGint nObjectID, UGString strDtName);


	//! \brief	��ȡ��ϵ��
	UGDatasetRelClass* GetDatasetRelClass(const UGString &strName);
	UGDatasetRelClass* GetDatasetRelClass(UGint nIndex);

	//! \brief	����Դ��Ŀ�����ݼ�����ȡ��ϵ��
	UGDatasetRelClass* GetDatasetRelClass(const UGString &strOrgDtName, const UGString &strDestDtName);


	//! \brief	��ȡ��ϵ������ע����Ϣ
	virtual UGbool ReadInfos() = 0;

	//! \brief	�������ϵ����ص�ϵͳ��
	virtual UGbool CreateRelSysTables() = 0;

	

	//! \brief	���ĳ�����ݼ��Ƿ��Ѽ����ϵ����
	UGbool IsJoinRelClass(const UGString &strDtName);

	//! \brief  ɾ����ĳ���ݼ�ΪԴ����Ŀ������й�ϵ�ࣻ
	//! \param strDatasetName[IN] ���ݼ����֣�
	//! \param bOrg[IN]��TRUE��strDatasetName��ӦԴ���ݼ���FALSE��strDatasetName��ӦĿ�����ݼ���
	UGbool DeleteAllDirectRelClsByDtName(UGString strDatasetName, UGbool bOrg);

	//! \brief  ��ѯ������Ŀ�����Դ���ݼ��еĹ�������
	//! \param relObjects[IN] �������ݼ�������ID���ϣ�
	//! \param aryResults[OUT] 
	//! \param bOrg[IN] TRUE���Դ��Ŀ�꣬FALSE���Ŀ����Դ��
	UGbool GetDirectRelObjectses(const UGRelObjects &relObjects, \
		UGArray<UGRelObjects> &aryResults, UGbool bOrg);
	
	//! \brief  ��ȡ�ܹ���Ӧ�˶���Ĺ��������Ĺ�������ļ��ϣ�������ӵģ�
	//! \param relObjectsOrg[IN]  ��ΪԴ�Ĺ������󼯺ϣ�
	//! \param aryRelObjects[OUT]  ��֮ΪԴ�Ĺ������󼯺ϵļ��ϣ�����ֱ�ӹ������ӹ�����
	//! \attention *****************aryRelObjects[0]ΪrelObjectsOrg��һ��������******************8
	UGbool GetRelObjectsesForAction(const UGRelObjects &relObjectsOrg, \
		UGArray<UGRelObjects> &aryRelObjects);

	//! \brief  �����ܹ���Ӧ���������������ж��󣬰�����ӹ�ϵ�ģ�
	//  \param  relObjects[IN]			��ΪԴ�Ĺ������󼯺ϣ�
	//  \param  msg[IN]					��Ҫ���Ķ�����
	//	\param	aryImpactObjects[OUT]	������Ӱ��Ķ���(������ݼ�����Ӱ��Ķ���
	//  \param  isModified[in]          Դ�����Ƿ��Ѿ����޸Ĺ������û�б��޸Ĺ����ڲ������޸ģ�
	UGbool DealRelObjectsesRecursion(const UGRelObjects &relObjects, \
		const UGGeoAction &msg, UGArray<UGRelObjects> &aryImpactObjs, UGbool isModified);

	//! \brief  ȡ�������ݼ����������ֱ�ӹ�ϵ�ࣻ
	//! \param strName [IN] ���ݼ�����
	//! \param aryRelClass[OUT] ��ϵ�����飻
	UGbool GetAllDirectRelClasses(const UGString &strName, \
	UGArray<UGDatasetRelClass*> &aryRelClassP);


private:
	//! \brief  ��ѯ�Դ������ֶ�Ӧ�����ݼ���ΪԴ����Ŀ�����ݼ��Ĺ�ϵ��ָ������(��Ƕ�״���)��
	//! \param strName [IN] ���ݼ�����
	//! \param aryRelClass[OUT] ��ϵ�����飻
	//! \param bOrg[IN] ���������Ƿ��Ƕ�Ӧ��ϵ���е�Դ���ݼ���TRUE��strNameΪԴ���ݼ����֣�FALSE��strNameΪĿ�����ݼ����֣���
	UGbool GetDirectRelClasses(const UGString &strName, \
		UGArray<UGDatasetRelClass*> &aryRelClassP, UGbool bOrg = TRUE);

	//! \brief  ��ȡ�������ֶ�Ӧ�����ݼ�ֱ����ΪԴ��Ŀ�꣬������һ�˵����ݼ��ܹ���Ӧ�����ݼ���Ϣ�����й�ϵ�࣬ע�⣺��ֱ�ӹ�ϵ�࣬��������ӵģ�
	//! \param strName [IN] ���ݼ�����
	//! \param aryRelClass[OUT] ��ϵ�����飻
	UGbool GetAllDirectRelClassesForAction(const UGString &strName, \
		UGArray<UGDatasetRelClass*> &aryRelClassP);

	//! \brief  ��ȡ����Ӧ�����ݼ����������й�ϵ�࣬������ӵģ�û�����ϻ�������������ĳ�Ա��Ψһ�����ظ���
	//! \param  strSrcDtName[IN] ���ݼ����֣�
	//! \param  aryRelClassP[OUT] ��ϵ�����飻
	UGbool GetRelClassesForAction(UGString strSrcDtName, UGArray<UGDatasetRelClass*> &aryRelClassP);


protected:
	//! \brief	��������newһ����ϵ�����ݼ�����
	virtual UGDatasetRelClass* GetNewRelClass() = 0;

	//!	\brief	ɾ����ϵ�������ݿ��е���Ϣ
	virtual UGbool DeleteDtRelClassFromTable(UGDatasetRelClass *pRelClass) = 0;

protected:
	//! \brief	����������Դָ��
	UGDataSource *m_pDataSource;

	//! \brief	��ϵ�����ݼ�ָ������
	UGArray<UGDatasetRelClass*> m_RelClasses;
};

}

#endif
