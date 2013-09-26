#pragma once

#include "Stream/ugdefs.h"
#include "Engine/UGDatasetGroupItem.h"
#include "Engine/UGDataSource.h"

namespace UGC {

//! \brief CreateDatasetGroup �ص�����
typedef  void (UGSTDCALL *CreateDatasetGroupProc)(void* pData, const UGString& strGroupName);

//! \brief AfterDeleteDatasetGroup �ص�����
typedef  void (UGSTDCALL *AfterDeleteDatasetGroupProc)(void* pData, const UGString& strGroupName);

//! \brief BeforeDeleteDatasetGroup �ص�����
typedef  void (UGSTDCALL *BeforeDeleteDatasetGroupProc)(void* pData, const UGString& strGroupName, UGbool& bCancel);

//! \brief AddDatasetGroupItem �ص�����
typedef  void (UGSTDCALL *AddDatasetGroupItemProc)(void* pData, UGString& strDatasetTableName);


class ENGINE_API UGDatasetGroup
{
public:
	UGDatasetGroup(void);
	UGDatasetGroup(UGDataSource *pDataSource);
	~UGDatasetGroup(void);

	//{{----------�������صĲ���------------------------------------
	UGDatasetGroup* GetParentGroup() const;
	void SetParentGroup(UGDatasetGroup* pParentGroup);
	UGDatasetGroup* GetChildGroup(UGint nIndex) const;
	UGDatasetGroup* GetChildGroup(const UGString& strName) const;
	UGint GetChildGroupCount() const;
	UGDatasetGroup* CreateChildGroup(const UGString& strName);
	UGbool AppendGroup(UGDatasetGroup *pDatasetGroup);
	UGbool IsChildGroupExisted(const UGString& strName);
	UGString GetGroupName() const;
	void SetGroupName(const UGString& strName);
	UGbool RemoveGroup(const UGString& strName);
	void SetDescription(const UGString& strDescription);
	UGString GetDescription();
	UGint IndexOfChildGroup(const UGString& strChildGroupName);
	//}}--------------------------------------------------------------

	//{{----------��Item����ز���------------------------------------
	UGint GetGroupItemCount() const;
	UGDatasetGroupItem GetGroupItem(UGint nIndex) const;
	UGbool SetGroupItem(UGint nIndex, UGDatasetGroupItem GroupItem);
	UGint FindGroupItem(UGString TableName) const;
	UGbool IsExist(UGString TableName) const;
	UGbool AddGroupItem(UGDatasetGroupItem GroupItem);
	UGbool RemoveGroupItem(UGString TableName);
	//}}--------------------------------------------------------------

	UGbool IsModified();

	UGbool FromXML(UGString xml);
	UGString ToXML();

	UGbool SetDataSource(UGDataSource *pDataSource);
	UGDataSource *GetDataSource();

	UGbool SetExtData(UGString &strExtData);
	UGString GetExtData();

	void SetCreateDatasetGroupFunction(CreateDatasetGroupProc pCreateDatasetGroupProc, void* pData);
	void SetAfterDeleteDatasetGroupFunction(AfterDeleteDatasetGroupProc pAfterDeleteDatasetGroupProc, void* pData);
	void SetBeforeDeleteDatasetGroupFunction(BeforeDeleteDatasetGroupProc pBeforeDeleteDatasetGroupProc, void* pData);
	void SetAddDatasetGroupItemFunction(AddDatasetGroupItemProc pAddDatasetGroupItemProc, void* pData);

protected:
	void SetModifiedFlag(UGbool bModified);

private:
	//! ���������
	UGString m_strName;
	UGString m_strDescription;
	UGString m_strExtData;

	UGbool m_bModified;

	//! ����ĸ��飬���m_pParentGroupΪNULL����ʾ��Ϊ����
	UGDatasetGroup*          m_pParentGroup;             

	//! �����µ���������
	UGArray<UGDatasetGroup*> m_ChildGroups;

	//! ��Group��֯�ķ���(Item)����¼��ID��
	//! ע:һ��Group�в���������ͬID��Item����,ͬʱ�������е�Item����Ӧ�ķ���ID����Ψһ��
	UGArray<UGDatasetGroupItem> m_Items;

	UGDataSource * m_pDataSource;

	CreateDatasetGroupProc ms_pCreateDatasetGroupProc;
	AfterDeleteDatasetGroupProc ms_pAfterDeleteDatasetGroupProc;
	BeforeDeleteDatasetGroupProc ms_pBeforeDeleteDatasetGroupProc;
	AddDatasetGroupItemProc ms_pAddDatasetGroupItemProc;
	void* m_pCallBackData;
};

}

