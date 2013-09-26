#pragma once
#include "Geometry/UGFeature.h"
#include "Engine/ugeng.h"

namespace UGC{

class UGTable;

class ENGINE_API UGFieldsManager
{

public:
	//! \brief ͨ��ֵ�����ֶ�ֵ��
	//! \param strFieldName ���µ��ֶ���[in]��
	//! \param varValue �ֶ�ֵ[in]��
	//! \param strFilter �����ֶ�ʱ�������еĹ���������
	//! Ĭ�Ϲ��������ÿգ��������м�¼[in]��
	//! \return �Ƿ�����ֶ�ֵ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305000EE
	virtual ENGINE_APIF UGbool UpdateField(const UGString& strFieldName,
		const UGVariant& varValue,const UGString& strFilter = _U("")) = 0;

	//! \brief ͨ�����ʽ�����ֶ�ֵ��
	//! \param strFieldName ���µ��ֶ���[in]��
	//! \param strExpress ����������ʽ�ַ�����
	//! �ֶ�ֵ��ĳ������������ʽ��ֵ����strFieldName = Col1 + col2 * 2[in]��
	//! \param strFilter �����ֶ�ʱ�������еĹ���������
	//! Ĭ�Ϲ��������ÿգ��������м�¼[in]��
	//! \return �Ƿ�����ֶ�ֵ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305000F3
	virtual ENGINE_APIF UGbool UpdateFieldEx(const UGString& strFieldName,
		const UGString& strExpress,const UGString& strFilter = _U("")) = 0;

	//! \brief �����ֶ�ֵ,strSrcField�͡�
	//! \param strSrcFieldName Դ�ֶ�����[in]��
	//! \param strDestFieldName Ŀ���ֶ�����[in]��
	//! \return �Ƿ����ֶγɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention Ŀ���ֶ������붼������Ŀ���ֶ�Ҫ��Դ�ֶ�����ƥ�䡣
	//! strDestField���붼�������ֶ�����ƥ��
	//##ModelId=4820305000FB
	virtual ENGINE_APIF UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField) = 0;

	//! \brief ����UUID�ֶ�
	virtual ENGINE_APIF UGbool CreateUUIDField() = 0;


	//! \brief ������ͨ������
	//! \param strFieldNameList �����������ֶ��б�����ֶ��м���","����[in]��
	//! \param strIndexName ������[in]��
	//! \return ������ͨ�����Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305000FF
	virtual ENGINE_APIF UGbool CreateIndex(const UGString& strFieldNameList,
		const UGString& strIndexName) = 0;

	//! \brief ɾ��������
	//! \param strIndexName ������[in]��
	//! \return ɾ�������Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500103
	virtual ENGINE_APIF UGbool DropIndex(const UGString& strIndexName) = 0;

	//! \brief ���һ��������
	//! \param ��
	//! \return ����ֵ--���������ֶζ�ӦMAP��
	//##ModelId=482030500103
	virtual ENGINE_APIF std::map<UGString,UGString> GetIndexToMap() = 0;

	//! \brief ��������ֶΡ�
	//! \param fieldInfos �ֶ�������Ϣ��������[in]��
	//! \return ��������ֶ��Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks �������ֶ����гɹ��ģ��в��ɹ��ģ��򷵻�FALSE��
	//##ModelId=482030500106
	virtual ENGINE_APIF UGbool CreateFields(const UGFieldInfos& fieldInfos) = 0;

	//! \brief ͨ��FieldInfo����һ���ֶΡ�
	//! \param fieldInfo �ֶ�������Ϣ��������[in]��
	//! \return ����һ���ֶ��Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050010A
	virtual ENGINE_APIF UGbool CreateField(const UGFieldInfo& fieldInfo) = 0;

	//! \brief ͨ�������ֶεĸ������������һ���ֶΡ�
	//! \param strFieldName �ֶ���[in]��
	//! \param nType �ֶ�����ö��ֵ[in]��
	//! \param nSize �ֶγ��ȣ����ֽ�Ϊ��λ[in]��
	//! \param nAttributes �ֶ�����Ĭ��Ϊ0[in]��
	//! \return ����һ���ֶ��Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050010D
	virtual ENGINE_APIF UGbool CreateField(const UGString& strName,
		UGFieldInfo::FieldType nType,UGint nSize,UGint nAttributes = 0) = 0;

	//! \brief ͨ���ֶ�����ɾ���ֶΡ�
	//! \param strFieldName �ֶ���[in]��
	//! \param bSystemFieldExcluded nIndex�Ƿ����ϵͳ�ֶΣ�Ĭ�ϲ�����[in]��
	//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500113
	virtual ENGINE_APIF UGbool DeleteField(const UGString& strName) = 0;

	//! \brief ͨ�����ɾ���ֶΡ�
	//! \param nIndex �ֶ���ţ���0��ʼ[in]��
	//! \param bSystemFieldExcluded nIndex�Ƿ����ϵͳ�ֶΣ�Ĭ�ϲ�����[in]��
	//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500116
	virtual ENGINE_APIF UGbool DeleteField(UGint nIndex, UGbool bSystemFieldExcluded = FALSE) = 0;

	//! \brief ��ȡ���ݱ��������ֶε�������Ϣ��
	//! \param fieldInfos ���ݱ��������ֶε�������Ϣ����[out]��
	//! \param bSystemFieldExcluded �Ƿ��ȡϵͳ�ֶΣ�Ĭ�ϲ�ȡ[in]��
	//! \return �Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050011B
	virtual ENGINE_APIF UGbool GetFieldInfos(UGFieldInfos& fieldInfos,UGbool bSystemFieldExcluded = FALSE) = 0;

	//! \brief ͨ���ֶ�����ȡ�ֶ�������Ϣ��
	//! \param strFieldName �ֶ���[in]��
	//! \param fieldInfo �ֶ�������Ϣ[out]��
	//! \return �Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050011F
	virtual ENGINE_APIF UGbool GetFieldInfo(const UGString& strName,UGFieldInfo& fieldInfo) = 0;

	//! \brief ͨ���ֶ���Ż�ȡ�ֶ���Ϣ��
	//! \param nIndex �ֶ���ţ���0��ʼ[in]��
	//! \param fieldInfo �ֶ�������Ϣ[in]��
	//! \param bSystemFieldExcluded nIndex�Ƿ����ϵͳ�ֶΣ�Ĭ�ϲ�����[in]��
	//! \return �Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500123
	virtual ENGINE_APIF UGbool GetFieldInfo(UGint nIndex,UGFieldInfo& fieldInfo, UGbool bSystemFieldExcluded = FALSE) = 0;

	//! \brief ͨ���ֶ��������ֶ���Ϣ��
	//! \param strFieldName �ֶ���[in]��
	//! \param fieldInfo �ֶ�������Ϣ��������[in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500127
	virtual ENGINE_APIF UGbool SetFieldInfo(const UGString& strName,const UGFieldInfo& fieldInfo) = 0;

	//! \brief ͨ����������ֶ���Ϣ��
	//! \param nIndex �ֶ���ţ���0��ʼ[in]��
	//! \param fieldInfo �ֶ�������Ϣ��������[in]��
	//! \param bSystemFieldExcluded nIndex�Ƿ����ϵͳ�ֶΣ�Ĭ�ϲ�����[in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050012B
	virtual ENGINE_APIF UGbool SetFieldInfo(UGint nIndex,const UGFieldInfo& fieldInfo, UGbool bSystemFieldExcluded = FALSE) = 0;

	//! \brief ��ȡ���ݱ����ֶθ�����
	//! \param bSystemFieldExcluded nIndex�Ƿ����ϵͳ�ֶΣ�Ĭ�ϲ�����[in]��
	//! \return �ֶθ�����
	//##ModelId=48203050012F
	virtual ENGINE_APIF UGint GetFieldCount(UGbool bSystemFieldExcluded = FALSE) = 0;

	//! \brief ͳ���ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \param nMode ͳ��ģʽ[in]��
	//! \return ͳ��ֵ��
	//##ModelId=482030500133
	virtual ENGINE_APIF UGVariant Statistic(const UGString& strField,UGStatisticMode nMode) = 0;

	//! \brief �����ֶε�ֵ������
	//! \param &strFieldName �ֶ���[in]��
	//! \param varKeys ��ֵ����[in]��
	//! \return ��ֵ������
	//##ModelId=482030500138
	virtual ENGINE_APIF UGint CalculateUniqueValues(const UGString &strFieldName,UGArray<UGVariant>& varKeys) = 0;

	//! \brief �����ֶ���Ϣ
	//! \brief �����ֶε����
	//! \param strFieldName �ֶ���[in]��
	//! \param nSign ϵͳ�ֶα�ʶ[in]��
	//! \return ���óɹ�����TRUE��ʧ�ܷ���FALSE��	
	//##ModelId=4820305301D4
	virtual UGbool SetFieldSign(const UGString& strFieldName,UGFieldInfo::FieldSign nSign) = 0;

	//! \brief ͨ������ȡ�ֶ���
	//! \param nSign ϵͳ�ֶα�ʶ[in]��
	//! \return �ֶ�����
	//##ModelId=4820305301CB
	virtual UGString GetFieldNameBySign(UGFieldInfo::FieldSign nSign) = 0;

	//! \brief ��ѯ�ֶ���Ϣ
	virtual UGbool QueryFieldInfos() = 0;

	//! \brief �ж��ֶ����Ƿ���Ч��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��Ч����TRUE����Ч����FALSE��
	//##ModelId=4820305301BA
	virtual UGbool IsAvailableFieldName(const UGString& strFieldName) = 0;

	//! \brief ���ö������ֶεĴ�С
	//! \param nNewSize �ֶε�Size
	//! \param strFieldName Ҫ���õ��ֶ�����
	//! \return �ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual UGbool SetMaxBinaryFieldSize(UGint nNewSize, UGString strFieldName){ return FALSE; };

protected:
	//! \brief ���ݼ�ָ�룬��ʼ��ʱ��ֵ
	UGTable *m_pDataset;
};


}
