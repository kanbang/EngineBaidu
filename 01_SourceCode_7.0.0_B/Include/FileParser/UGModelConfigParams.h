// UGVectorImportParams.h: interface for the UGVectorImportParams class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMODELIMPORTPARAMS_H__5D6357D7_FC27_48BC_8BA4_3A6788F5DD2F__INCLUDED_)
#define AFX_UGMODELIMPORTPARAMS_H__5D6357D7_FC27_48BC_8BA4_3A6788F5DD2F__INCLUDED_

#include "Stream/ugexports.h"
#include "FileParser/UGFileParserConfigParams.h"
#include "FileParser/UGVectorConfigParams.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace UGC {

class  UGVectorFileLayer;
class UGSpatialIndexInfo;


//! \brief ʸ���������	
class FILEPARSER_API UGModelImportParams  : public UGVectorImportParams
{
	friend class UGWorkspaceImportParams;
public:
	//! \brief ���캯����
	//! \remarks ��
	UGModelImportParams();
	
	//! \brief ����������
	//! \remarks ��
	virtual ~UGModelImportParams();
	
	//! \brief ���캯����
	//! \remarks ��
	UGModelImportParams(const UGModelImportParams& tmp);

	//! \brief ���ظ�ֵ���ź�����
	//! \remarks ��
	UGModelImportParams& operator=(const UGModelImportParams& tmp);

public:
	
	

protected:
	
// 	! \brief ��
// 		//! \remarks ��
// 		UGFeatureClassInfos m_dtInfos;
// 		
// 	
// 		UGSpatialIndexInfo* m_pSpatialIndex;

};


//////////////////////////////////////////////////////////////////////////

//! \brief ʸ������������
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGModelExportParams : public UGExportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGModelExportParams(){
		m_strDatasetName = _U("");
	}//��ʼֵ=0����ʾû�а汾

	//! \brief ����������
	//! \remarks ��
	virtual ~UGModelExportParams(){}
public:
	//! \brief ��ȡҪ������ʸ�����ݼ����ơ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGString GetDtNameToBeExported() const;	

	//! \brief ����Ҫ������ʸ�����ݼ����ơ�
	//! \param  name [in] ���õ����ơ�
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetDtNameToBeExported(const UGString& name);


	//! \brief ��ȡҪ������ʸ�����ݼ��������顣
	//! \param  [in]��
	//! \return ��
	//! \remarks ���ݼ��������顣
	//! \attention Ϊ�˶�����ݼ�����ʹ�á�
	//! ע��˽ӿ����麯��, ֧�ֶ����ݼ��������ܵĸ�ʽ��Ҫ����
	virtual UGbool GetDtNamesBeExported(UGStrings& arrNames) const {return FALSE;}

	//! \brief ����Ҫ������ʸ�����ݼ��������顣
	//! \param  name [in] ���õ����ơ�
	//! \return ��
	//! \remarks ��
	//! \attention Ϊ�˶�����ݼ�����ʹ�á�
	//! ע��˽ӿ����麯��, ֧�ֶ����ݼ��������ܵĸ�ʽ��Ҫ����
	virtual void SetDtNamesBeExported(const UGStrings& arrNames){ ;};

protected:
	
	//! \brief ��
	//! \remarks ��
	/*UGDict <UGint, UGFeatureClassDefn> m_ExportDatasetInfos;*/
	
private:	
	// \brief Ҫ���������ݼ����ơ�
	// \remarks ��
	UGString m_strDatasetName;
};

} //namespace UGC

#endif // !defined(AFX_UGVECTORIMPORTPARAMS_H__5D6357D7_FC27_48BC_8BA4_3A6788F5DD2F__INCLUDED_)

