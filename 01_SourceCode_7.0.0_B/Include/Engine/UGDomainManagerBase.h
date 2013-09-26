//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class ��
//!  \details ��
//!  \author �з�һ����
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
#ifndef UGDOMAINMANAGERBASE_H
#define UGDOMAINMANAGERBASE_H

#include "Engine/UGDomain.h"

namespace UGC
{
#define	DOMAINBASE_TABLE_NAME	_U("SmDomains")
#define RANGEDOMAIN_TABLE_NAME	_U("SmRangeDomains")
#define CODEDOMAIN_TABLE_NAME	_U("SmCodeDomains")
#define DOMAINFIELD_TABLE_NAME	_U("SmDomainField")

	class UGDataSource;
	class UGDatasetVector;
	
	class ENGINE_API UGDomainManagerBase
	{
	public:
		UGDomainManagerBase();

		UGDomainManagerBase(UGDataSource *pDS);
		
		virtual ~UGDomainManagerBase();
	
		//===================================================
		//! \brief  ��ʼ��ֵ��
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		virtual UGbool InitDomain(){return FALSE;}

		//===================================================
		//! \brief  ͨ���ֶ����ƻ�ȡֵ��
		//! \param  pDatasetVector[I] ���ݼ�
		//! \param  strFieldName[I]   �ֶ�����
		//! \return   
		//! \remarks 
		//! \attention ���ñ�����֮ǰ�������ReadDomainFields����
		UGDomainBase* GetDomain(UGDatasetVector *pDatasetVector, const UGString &strFieldName);

		//===================================================
		//! \brief  ͨ��ֵ�����ͻ�ȡֵ�򼯺�
		//! \param  type[I]    ֵ������
		//! \param  domains[O] ֵ�򼯺�
		//! \return   
		//! \remarks 
		//! \attention ���ñ�����֮ǰ�������ReadDomain����
		UGArray<UGDomainBase*> GetDomains(UGDomainBase::DomainType type);

		//===================================================
		//! \brief  ͨ���ֶ����ͻ�ȡֵ�򼯺�
		//! \param  fieldtype[I] �ֶ�����
		//! \param  domains[O]   ֵ�򼯺�
		//! \return   
		//! \remarks 
		//! \attention ���ñ�����֮ǰ�������ReadDomain����
		UGArray<UGDomainBase*> GetDomains(UGFieldInfo::FieldType fieldtype);

		//===================================================
		//! \brief  ��ȡֵ�򼯺�
		//! \param  
		//! \return   
		//! \remarks 
		//! \attention
		UGArray<UGDomainBase*> GetAllDomains();

		//===================================================
		//! \brief  ��ȡֵ����Ŀ
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		UGint GetDomainCount();

		//===================================================
		//! \brief  �����ض��ֶε�ֵ��
		//! \param  pDatasetVector[I] ���ݼ�
		//! \param  strFieldName[I]   �ֶ�����
		//! \param  pDomain[I]        ֵ��
		//! \return ���óɹ�����true  
		//! \remarks 
		//! \attention
		UGbool SetDomain(UGDatasetVector *pDatasetVector, const UGString &strFieldName, UGDomainBase *pDomain);

		//===================================================
		//! \brief  ɾ���ض��ĵ�ֵ��
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		UGbool RemoveDomain(UGDatasetVector *pDatasetVector, const UGString &strFieldName);

	protected:
		//===================================================
		//! \brief  ͨ��IDɾ��ֵ��
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		virtual UGbool DeleteDomainByID(UGuint nID){return FALSE;}

		//===================================================
		//! \brief  �Ƴ�ĳ�ֶ�����Ĺ�����һ���ֶ�һ��ֻ�ܱ�����һ����
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		virtual UGbool DeleteDomainFromField(UGDatasetVector *pDataset, const UGString &fieldname){return FALSE;}

		//===================================================
		//! \brief  �����ݿ��ȡ����ص�������Ϣ
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		virtual UGbool ReadInfos(){return FALSE;}
	
		//===================================================
		//! \brief  �����ݿ��ȡ��Χ����ص���Ϣ������
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		virtual UGbool ReadRangeDomains(){return FALSE;}

		//===================================================
		//! \brief  �����ݿ��ȡ��������ص���Ϣ������
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		virtual UGbool ReadCodeDomains(){return FALSE;}

		//===================================================
		//! \brief  �����ݿ��ȡ����ֶεĹ�����Ϣ
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		virtual UGbool ReadDomainFields(){return FALSE;}

		//===================================================
		//! \brief  
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		virtual UGuint GetNextDomainID(){return 0;}

		//===================================================
		//! \brief �ж�DomainID�Ƿ�����Ч��ID
		//! \param nDomainID[in]
		//! \return  ��Ч����TRUE,��Ч����FALSE
		//! \remarks 
		//! \attention
		virtual UGbool IsValidDomainID(UGint nDomainID){return TRUE;}

	
		//===================================================
		//! \brief  �����ݿⴴ��������DOMAINBASE_TABLE_NAME��RANGEDOMAIN_TABLE_NAME��
		//!			CODEDOMAIN_TABLE_NAME��DOMAINFIELD_TABLE_NAME
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		virtual UGbool CreateDomainTables(){return FALSE;}

		//===================================================
		//! \brief  �������Ϣд�����ݿ�
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		virtual UGbool InsertDomainToDB(const UGDomainBase *pDomain){return FALSE;}

		//===================================================
		//! \brief  ���������Ϣ�����ݿ�
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		virtual UGbool UpdateDomainToDB(const UGDomainBase *pDomain){return FALSE;}

		//===================================================
		//! \brief  ������ֶεĹ�����Ϣд�����ݿ�
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		virtual UGbool InsertDomainFieldToDB(const UGDomainField &dmfld){return FALSE;}

		//===================================================
		//! \brief  ͨ��ID��ȡֵ��
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		UGDomainBase* GetDomainByID(UGint nDomainID);

		//===================================================
		//! \brief  ����Ƿ���ɾ��ָ��ID�������Ѿ���������ĳ���ֶ�ʱ�ǲ��ܱ�ɾ���ģ�
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		UGbool CanDeleteDomain(UGuint nID);

		//===================================================
		//! \brief  ������Χ��
		//! \param  nSize[I] pIntervals��ָ�ڴ�Ĵ�С 
		//! \return   
		//! \remarks 
		//! \attention
		UGDomainBase* MakeRangeDomain(
			UGuint nDomainID, 
			const UGString &strDomainName, 
			const UGString &strDomainDesc, 
			UGint nDomainType, 
			UGint nFieldType, 
			const void *pIntervals, 
			UGint nSize);
	
		//===================================================
		//! \brief  ����������
		//! \param  nSize[I] pCodeInfos��ָ�ڴ�Ĵ�С 
		//! \return   
		//! \remarks 
		//! \attention
		UGDomainBase* MakeCodeDomain(
			UGuint nDomainID, 
			const UGString &strDomainName, 
			const UGString &strDomainDesc,
			UGint nDomainType,
			UGint nFieldType, 
			const void *pCodeInfos, 
			UGint nSize);

	public:
		//===================================================
		//! \brief  �������ID��ȡ���������ֶ���
		//! \param  nDomainID[IN]
		//! \return ���������ֶ���
		//! \remarks 
		//! \attention
		UGString GetFieldName(UGint nDomainID);

		//===================================================
		//! \brief  �������ID��ȡ�����ڵ����ݼ�ID
		//! \param  nDomainID[IN]
		//! \return �����ڵ����ݼ�ID 
		//! \remarks 
		//! \attention
		UGint GetDataSetID(UGint nDomainID);

		//===================================================
		//! \brief  �ֶ��Ƿ��Ѿ���������������������ٹ���
		//! \param  pDataset[I]
		//! \param  strFieldName[I]
		//! \return   
		//! \remarks 
		//! \attention
		UGbool IsSetDomain(UGDatasetVector *pDataset, const UGString &strFieldName);

		//===================================================
		//! \brief  ���ָ�����ֶκ�����ֶ������Ƿ�һ��
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		UGbool IsFieldTypeConsistent(UGDatasetVector *pDataset, const UGString &strFieldName, UGint nDomainID);


		//===================================================
		//! \brief  ����Ƿ�������Υ��ֵ�����
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		UGbool HasInvalidFieldValue(){return m_bHasInvalidFieldValue;}

		//===================================================
		//! \brief  �����Ƿ�������Υ�������־
		//! \param 
		//! \return   
		//! \remarks 
		//! \attention
		void SetHasInvalidFieldValue(UGbool hasInvalidValue){m_bHasInvalidFieldValue = hasInvalidValue;}

	protected:
		//!	\brief	��¼���е���
		UGArray<UGDomainBase*> m_Domains;

		//! \brief	��¼�����ֶ�֮��Ķ�Ӧ���
		UGArray<UGDomainField> m_DomainFields;

		//!	\brief	��Ӧ������Դ
		UGDataSource *m_pDataSource;

		//! \brief �Ƿ�������Υ�������־
		UGbool m_bHasInvalidFieldValue;
	};
}

#endif
