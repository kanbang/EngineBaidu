#ifndef UGDATASETVECTORCOLLECTION_H
#define UGDATASETVECTORCOLLECTION_H

#include "Engine/UGDataset.h"
#include "Engine/UGDatasetVector.h"

namespace UGC
{
	class UGRecordset;
	class ENGINE_API UGDatasetVectorCollection : public UGDatasetVector
	{

	public:
		
		UGDatasetVectorCollection();

		UGDatasetVectorCollection(UGDataSource *pDataSource);

		virtual ~UGDatasetVectorCollection();

	public:

		//! \brief ������ݼ���
		//! \param strName ���ݼ�����[in]��
		//! \param nState ״̬��Ĭ��Ϊ����[in]
		//! \return �Ƿ���ӳɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool AddSubDataset(const UGString &strName,CollectionState nState = normal);

		//! \brief �Ƴ����ݼ���
		//! \param strName ���ݼ�����[in]��
		//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool RemoveDataSet(const UGString &strName);

		//! \brief �ı伯��˳��
		//! \param strName ���ݼ�����[in]��
		//! \param position Ҫ�ı��λ��[in]
		//! \return �Ƿ�ı�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool ChangeOrder(const UGString &name,UGint position);

		//! \brief �ϲ����ݼ���
		//! \param strName ���ݼ�����[in]��
		//! \param bkill �Ƿ�Ҫɾ��ԭ����[in]
		//! \return �Ƿ�ϲ��ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool CombineCollection(const UGString &strName,UGbool bKill);

		//! \brief �õ����ݼ�������
		//! \return ���ظ�����
		//##ModelId=4820305301AB
		UGint GetDatasetCount();

		//! \brief ���ؼ������顣
		//! \return ��������
		//##ModelId=4820305301AB
		UGArray<UGDatasetState> GetStates();

	public:
		//! \brief Ϊ���ϴ����ֶΡ�
		//! \param info �ֶ���Ϣ[in]��
		//! \return �Ƿ񴴽��ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool CreateField(const UGFieldInfo &info);

		//! \brief �޸��ֶΡ�
		//! \param strName �ֶ���[in]��
		//! \param info �ֶ���Ϣ[in]��
		//! \return �Ƿ��޸ĳɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool SetFieldInfo(const UGString &strName,const UGFieldInfo &info);

		//! \brief ɾ���ֶΡ�
		//! \param name �ֶ���[in]��
		//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool DeleteField(const UGString &name);

		//! \brief �õ����ݼ�ָ�롣
		//! \param name ���ݼ�����[in]��
		//! \return ���ݼ�ָ��
		//##ModelId=4820305301AB
		virtual UGDataset* GetDataset(const UGString &name);

		//! \brief ˢ�����ݼ�״̬��
		//! \param strDatasetName ���ݼ�����[in]��
		//! \return �Ƿ�ˢ�³ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool RefreshDatasetState(const UGString & strDatasetName);

		//! \brief ˢ���������ݼ���
		//! \return �Ƿ�ˢ�³ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool RefreshDatasetStates();
		
		//! \brief ��ѯ��
		//! \param def ��ѯ����[in]��
		//! \return ��¼��ָ��
		//##ModelId=4820305301AB
		virtual UGRecordset* Query(const UGQueryDef &def);

		//! \brief ���������ݼ�ͶӰ��
		//! \param PrjCoordSys ͶӰ����[in]��
		//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool UpdateSubProjection(const UGPrjCoordSys &PrjCoordSys);
		
		//! \brief �õ�״̬��
		//! \param name ���ݼ�����[in]��
		//! \return ���ݼ�״̬
		//##ModelId=4820305301AB
		virtual CollectionState GetDatasetState(const UGString& name);

		//! \brief �ж����ݼ��Ƿ��ܹ���ӽ����ϡ�
		//! \param strName ���ݼ�����[in]��
		//! \return �Ƿ��ܹ���ӣ��ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool CanAdd(const UGString &strName);

		//! \brief �õ����ݼ�ָ�롣
		//! \param index ����[in]��
		//! \return ���ݼ�ָ��
		//##ModelId=4820305301AB
		virtual UGDataset* GetDataset(UGint index);//�ڲ�ʹ��

		//! \brief �Ƿ��ܹ���ӡ�
		//! \param strName ���ݼ�����[in]��
		//! \return ���ݼ�ָ��
		//##ModelId=4820305301AB
		virtual UGbool IsMatch(const UGString &strName);

		//! \brief �õ��洢�����͡�
		//! \param nType ����[in]��
		//! \return �����Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE
		//##ModelId=4820305301AB
		virtual UGbool GetStoredType(DatasetType &nType);

		//! \brief �õ�������
		//! \return ����
		//##ModelId=4820305301AB
		virtual UGString GetTableName();

		//! \brief ������ݼ������ڸ��ơ�
		//! \param strName ���ݼ�����[in]��
		//! \param nState ���ݼ�״̬[in]��
		//! \param nSrcID ���Ƶ����ݼ�ID[in]��
		//! \return �Ƿ���ӳɹ����ɹ�����TRUE��ʧ�ܷ���FALSE
		//##ModelId=4820305301AB
		virtual UGbool AddForCopy(const UGString &strName,CollectionState nState,UGint nSrcID);

		//##ModelId=4820305301B5
		void ReleaseAllRecordsets();

		//! \brief ͨ����¼������ͷż�¼���ڴ�ռ䡣
		//! \param nIndex ��¼�����[in]��
		//! \return �Ƿ��ͷųɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool ReleaseRecordset(UGint nIndex);

		//! \brief ͨ����¼��ָ���ͷż�¼���ڴ�ռ䡣
		//! \param *pRecordset ��¼��ָ��[in]��
		//! \return �Ƿ��ͷųɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
		//##ModelId=4820305301AB
		virtual UGbool ReleaseRecordset(UGRecordset *pRecordset);

	protected:

		void GetSubDatasetNames(UGStrings &dts);

	protected:
		//�洢���ݼ���״̬
		UGArray<UGDatasetState> m_arrDatasetState;

	};

}
#endif