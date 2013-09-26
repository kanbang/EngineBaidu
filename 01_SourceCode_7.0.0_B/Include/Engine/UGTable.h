/*! \file	 UGTable.h
 *  \brief	 ���ݼ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGTable.h,v 1.12 2009/08/10 07:58:01 cuiwz Exp $
 */

#if !defined(AFX_UGTABLE_H__93882047_ECE5_4A73_9B3F_FD8D539F8C69__INCLUDED_)
#define AFX_UGTABLE_H__93882047_ECE5_4A73_9B3F_FD8D539F8C69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDataset.h"
#include "Engine/UGRecordset.h"
#include "Engine/UGFieldsManager.h"

namespace UGC{

//�޸� UGTable  : public UGDataset���� UGDatasetVector : public UGTable
//�޸�ԭ��ʹ��UGTable UGDataset�� UGDatasetVector �ܹ�����һ�� OgdcDataset* m_pOgdcDataset

//##ModelId=4820305000EA
#ifdef SYMBIAN60
class ENGINE_APIC UGTable  : public UGDataset
#else
class ENGINE_API UGTable  : public UGDataset
#endif
{
	friend class UGFieldsManager;
public:
	//##ModelId=4820305000EB
	ENGINE_APIF UGTable();
	//##ModelId=4820305000EC
	virtual ENGINE_APIF ~UGTable();

public:
	//! \brief ͨ��ֵ�����ֶ�ֵ��
	//! \param strFieldName ���µ��ֶ���[in]��
	//! \param varValue �ֶ�ֵ[in]��
	//! \param strFilter �����ֶ�ʱ�������еĹ���������
	//! Ĭ�Ϲ��������ÿգ��������м�¼[in]��
	//! \return �Ƿ�����ֶ�ֵ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305000EE
	virtual ENGINE_APIF UGbool UpdateField(const UGString& strFieldName,
		const UGVariant& varValue,const UGString& strFilter = _U(""));

	//! \brief ͨ�����ʽ�����ֶ�ֵ��
	//! \param strFieldName ���µ��ֶ���[in]��
	//! \param strExpress ����������ʽ�ַ�����
	//! �ֶ�ֵ��ĳ������������ʽ��ֵ����strFieldName = Col1 + col2 * 2[in]��
	//! \param strFilter �����ֶ�ʱ�������еĹ���������
	//! Ĭ�Ϲ��������ÿգ��������м�¼[in]��
	//! \return �Ƿ�����ֶ�ֵ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305000F3
	virtual ENGINE_APIF UGbool UpdateFieldEx(const UGString& strFieldName,
		const UGString& strExpress,const UGString& strFilter = _U(""));

	//! \brief �����ֶ�ֵ,strSrcField�͡�
	//! \param strSrcFieldName Դ�ֶ�����[in]��
	//! \param strDestFieldName Ŀ���ֶ�����[in]��
	//! \return �Ƿ����ֶγɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention Ŀ���ֶ������붼������Ŀ���ֶ�Ҫ��Դ�ֶ�����ƥ�䡣
	//! strDestField���붼�������ֶ�����ƥ��
	//##ModelId=4820305000FB
	virtual ENGINE_APIF UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);

	//! \brief ����UUID�ֶ�
	virtual ENGINE_APIF UGbool CreateUUIDField();

	//! \brief �ж��Ƿ�����UUID�ֶ�
	virtual ENGINE_APIF UGbool HasUUIDField();

	//! \brief ������ͨ������
	//! \param strFieldNameList �����������ֶ��б�����ֶ��м���","����[in]��
	//! \param strIndexName ������[in]��
	//! \return ������ͨ�����Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305000FF
	virtual ENGINE_APIF UGbool CreateIndex(const UGString& strFieldNameList,
		const UGString& strIndexName);

	//! \brief ɾ��������
	//! \param strIndexName ������[in]��
	//! \return ɾ�������Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500103
	virtual ENGINE_APIF UGbool DropIndex(const UGString& strIndexName);

	//! \brief ���һ��������
	//! \param ��
	//! \return ����ֵ�����������ֶζ�ӦMap
	//##ModelId=482030500103
	virtual ENGINE_APIF std::map<UGString,UGString> GetIndexToMap();

	//! \brief ��������ֶΡ�
	//! \param fieldInfos �ֶ�������Ϣ��������[in]��
	//! \return ��������ֶ��Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks �������ֶ����гɹ��ģ��в��ɹ��ģ��򷵻�FALSE��
	//##ModelId=482030500106
	virtual ENGINE_APIF UGbool CreateFields(const UGFieldInfos& fieldInfos);
	
	//! \brief ͨ��FieldInfo����һ���ֶΡ�
	//! \param fieldInfo �ֶ�������Ϣ��������[in]��
	//! \return ����һ���ֶ��Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050010A
	virtual ENGINE_APIF UGbool CreateField(const UGFieldInfo& fieldInfo);

	//! \brief ͨ�������ֶεĸ������������һ���ֶΡ�
	//! \param strFieldName �ֶ���[in]��
	//! \param nType �ֶ�����ö��ֵ[in]��
	//! \param nSize �ֶγ��ȣ����ֽ�Ϊ��λ[in]��
	//! \param nAttributes �ֶ�����Ĭ��Ϊ0[in]��
	//! \return ����һ���ֶ��Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050010D
	virtual ENGINE_APIF UGbool CreateField(const UGString& strName,
		UGFieldInfo::FieldType nType,UGint nSize,UGint nAttributes = 0);

	//! \brief ͨ���ֶ�����ɾ���ֶΡ�
	//! \param strFieldName �ֶ���[in]��
	//! \param bSystemFieldExcluded nIndex�Ƿ����ϵͳ�ֶΣ�Ĭ�ϲ�����[in]��
	//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500113
	virtual ENGINE_APIF UGbool DeleteField(const UGString& strName);

	//! \brief ͨ�����ɾ���ֶΡ�
	//! \param nIndex �ֶ���ţ���0��ʼ[in]��
	//! \param bSystemFieldExcluded nIndex�Ƿ����ϵͳ�ֶΣ�Ĭ�ϲ�����[in]��
	//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500116
	virtual ENGINE_APIF UGbool DeleteField(UGint nIndex, UGbool bSystemFieldExcluded = FALSE);

	//! \brief ��ȡ���ݱ��������ֶε�������Ϣ��
	//! \param fieldInfos ���ݱ��������ֶε�������Ϣ����[out]��
	//! \param bSystemFieldExcluded �Ƿ��ȡϵͳ�ֶΣ�Ĭ�ϲ�ȡ[in]��
	//! \return �Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050011B
	virtual ENGINE_APIF UGbool GetFieldInfos(UGFieldInfos& fieldInfos,UGbool bSystemFieldExcluded = FALSE);

	//! \brief ͨ���ֶ�����ȡ�ֶ�������Ϣ��
	//! \param strFieldName �ֶ���[in]��
	//! \param fieldInfo �ֶ�������Ϣ[out]��
	//! \return �Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050011F
	virtual ENGINE_APIF UGbool GetFieldInfo(const UGString& strName,UGFieldInfo& fieldInfo);
	
	//! \brief ͨ���ֶ���Ż�ȡ�ֶ���Ϣ��
	//! \param nIndex �ֶ���ţ���0��ʼ[in]��
	//! \param fieldInfo �ֶ�������Ϣ[in]��
	//! \param bSystemFieldExcluded nIndex�Ƿ����ϵͳ�ֶΣ�Ĭ�ϲ�����[in]��
	//! \return �Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500123
	virtual ENGINE_APIF UGbool GetFieldInfo(UGint nIndex,UGFieldInfo& fieldInfo, UGbool bSystemFieldExcluded = FALSE);

	//! \brief ͨ���ֶ��������ֶ���Ϣ��
	//! \param strFieldName �ֶ���[in]��
	//! \param fieldInfo �ֶ�������Ϣ��������[in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500127
	virtual ENGINE_APIF UGbool SetFieldInfo(const UGString& strName,const UGFieldInfo& fieldInfo);

	//! \brief ͨ����������ֶ���Ϣ��
	//! \param nIndex �ֶ���ţ���0��ʼ[in]��
	//! \param fieldInfo �ֶ�������Ϣ��������[in]��
	//! \param bSystemFieldExcluded nIndex�Ƿ����ϵͳ�ֶΣ�Ĭ�ϲ�����[in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050012B
	virtual ENGINE_APIF UGbool SetFieldInfo(UGint nIndex,const UGFieldInfo& fieldInfo, UGbool bSystemFieldExcluded = FALSE);
	
	//! \brief ��ȡ���ݱ����ֶθ�����
	//! \param bSystemFieldExcluded nIndex�Ƿ����ϵͳ�ֶΣ�Ĭ�ϲ�����[in]��
	//! \return �ֶθ�����
	//##ModelId=48203050012F
	virtual ENGINE_APIF UGint GetFieldCount(UGbool bSystemFieldExcluded = FALSE);

	//! \brief ͳ���ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \param nMode ͳ��ģʽ[in]��
	//! \return ͳ��ֵ��
	//##ModelId=482030500133
	virtual ENGINE_APIF UGVariant Statistic(const UGString& strField,UGStatisticMode nMode);

	//! \brief �����ֶε�ֵ������
	//! \param &strFieldName �ֶ���[in]��
	//! \param varKeys ��ֵ����[in]��
	//! \return ��ֵ������
	//##ModelId=482030500138
	virtual ENGINE_APIF UGint CalculateUniqueValues(const UGString &strFieldName,UGArray<UGVariant>& varKeys);

	//! \brief �����ֶε����
	//! \param strFieldName �ֶ���[in]��
	//! \param nSign ϵͳ�ֶα�ʶ[in]��
	//! \return ���óɹ�����TRUE��ʧ�ܷ���FALSE��	
	//##ModelId=4820305301D4
	virtual ENGINE_APIF UGbool SetFieldSign(const UGString& strFieldName,UGFieldInfo::FieldSign nSign);

	//! \brief ͨ������ȡ�ֶ���
	//! \param nSign ϵͳ�ֶα�ʶ[in]��
	//! \return �ֶ�����
	//##ModelId=4820305301CB
	virtual ENGINE_APIF UGString GetFieldNameBySign(UGFieldInfo::FieldSign nSign);

	//! \brief �ж��ֶ����Ƿ���Ч��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��Ч����TRUE����Ч����FALSE��
	//##ModelId=4820305301BA
	virtual ENGINE_APIF UGbool IsAvailableFieldName(const UGString& strFieldName);

	//! \brief  �Ƿ��м������ݣ�����Tablur���ݼ������м�������
	//##ModelId=48203053015B
	virtual ENGINE_APIF UGbool HasGeometry() const;

	//! \brief �ж��Ƿ�����ݼ�
	virtual ENGINE_APIF UGbool IsPointDT();	


	//! \brief �����ֶ���Ϣ
	ENGINE_APIF UGbool SetFieldInfo(const UGString & strName,
							 const UGString & strForeignName,
							 UGFieldInfo::FieldType nType,
							 const UGString & strFormat,	
							 const UGString & strDomain, 
							 UGbool bUpdatable = TRUE,
							 UGbool bRequired = FALSE,
							 const UGString & strDefault = _U("")
							 );

	//! \brief ��ȡ���ݱ��������ֶ���Ϣ�� ���á���UGFieldsManager�á�
	UGFieldInfos& GetFieldInfosRef(){return m_FieldInfos;};

	UGFieldsManager *GetFieldsManager(); 

	//! \brief  �������ݼ��ַ����뷽ʽ
	//##ModelId=4820305301D8
	ENGINE_APIF UGMBString::Charset GetCharset() const;

	//! \brief  �������ݼ��ַ����뷽ʽ
	//##ModelId=4820305301DA
	virtual ENGINE_APIF UGbool SetCharset(UGMBString::Charset c);

	//! \brief  �ж����ݼ��Ƿ���ĳ��ѡ����Ϣ
	//##ModelId=482030530149
	ENGINE_APIF UGbool HasFlag(UGint nOption) const;

public:
	//����һ�º���� 
	//##ModelId=48203050013C
	UGFieldInfos m_FieldInfos;

	//##ModelId=4820305302A0
	UGMBString::Charset m_nCharset;

	//! \brief  һ�λ�ȡ�ļ�¼��
	//##ModelId=482030530284
	UGint m_nOnceFetchCount;

protected:
	UGFieldsManager *m_pFieldsManager;

};

}

#endif // !defined(AFX_UGTABLE_H__93882047_ECE5_4A73_9B3F_FD8D539F8C69__INCLUDED_)

