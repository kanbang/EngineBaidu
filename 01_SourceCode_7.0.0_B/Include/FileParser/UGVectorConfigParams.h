// UGVectorImportParams.h: interface for the UGVectorImportParams class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGVECTORIMPORTPARAMS_H__5D6357D7_FC27_48BC_8BA4_3A6788F5DD2F__INCLUDED_)
#define AFX_UGVECTORIMPORTPARAMS_H__5D6357D7_FC27_48BC_8BA4_3A6788F5DD2F__INCLUDED_

#include "Stream/ugexports.h"
#include "FileParser/UGFileParserConfigParams.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace UGC {

class  UGVectorFileLayer;
class UGSpatialIndexInfo;
	
//! \brief Դ������Ҫ����������
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGFeatureClassDefn
{
	friend class UGVectorFileLayer;

public:
	
	//! \brief ���캯����
	//! \remarks ��
	UGFeatureClassDefn();

	//! \brief �������캯����
	//! \remarks ��
	UGFeatureClassDefn(const UGFeatureClassDefn& ClassDef);

	//! \brief ����������
	//! \remarks ��
	virtual ~UGFeatureClassDefn();

	//! \brief ���ز����� =  ��
	//! \param fcdef [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGFeatureClassDefn& operator=(const UGFeatureClassDefn& fcdef);	
	
public:
	
	//! \brief ����������ݼ����͡�
	//! \remarks ö��ֵ�� UGDataset::DatasetType ��ֵһ�¡�
	enum FeatureClassType
	{
		//! ����ʶ
		UnKnown		=-1,	
		//! ֻ�����Ա�û�м��ζ���
		Tabular		=0,
		//! �����ݼ�
		Point		=1,
		//! �����ݼ�
		Line		=3,		
		//! �������ݼ�
		Network		=4,		
		//! ��������ݼ�
		Region		=5,	
		//! �ı����ݼ�
		Text		=7,	
		//!�����������ݼ�
		CompoundLine   = 8,
		//�������������ݼ�
		CompoundRegion = 9,
		//! ·�����ݼ�
		LineM		=35,	
		//! ��ά��
		PointZ		=101,
		//! ��ά��
		LineZ		=103,
		//! ��ά��
		RegionZ		=105,	
		//! ����������Point3D
		PointGL		=137,	
		//! TIN���ݼ�
		TIN			=139,	
		//! CAD���ݼ�
		CAD			=149,
		//! Topo���ݼ�
		Topo		=154,	
		//! �µ�Tin���ݺ���ǰ�����ֿ�
		TIN2		=155	
	};
	

	//! \brief �������ݼ����͡�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGint GetType() const;		
	
	//! \brief �������ݼ����͡�
	//! \param  �ֶ�����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetType(UGint nType);
	
	//! \brief ���ؽ�����ݼ����ơ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGString GetName() const;	
	
	//! \brief ����/�޸Ľ�����ݼ����ơ�
	//! \param strNewName [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetName(const UGString& strNewName);	
	
	//! \brief ��ȡ���������
	//! \param  nCount�ֶθ���[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGint GetFeatureCount() const;	
	
	//! \brief ���ö��������
	//! \param  nCount�ֶθ���[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetFeatureCount(UGint nCount);	
	
	//! \brief �������ݼ���Χ��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGRect2D GetBound() const;	

	//! \brief �������ݼ���Χ��
	//! \param  rect2D ����λ[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetBound(const UGRect2D& rect2D);

	//! \brief ��ȡ�ֶθ�����
	//! \param  [in]  
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGint GetFieldCount() const;

	//! \brief ��ȡָ������λ���ֶ���Ϣ��
	//! \param  nIndex [in]  ȡֵ:[0 and GetFieldCount()-1]. 
	//! \return ��
	//! \remarks ��
	//! \attention �û�����ɾ�����ص��ֶ�ָ�롣
	UGFieldInfo* GetFieldDefn(UGint nIndex) const;

	//! \brief ��ȡ�ֶ���Ϣ��
	//! \param  nIndex [in]  ȡֵ:[0 and GetFieldCount()-1]. 
	//! \return �����ֶ���Ϣ�Ŀ�����
	//! \remarks ��
	//! \attention ��
	UGFieldInfos GetFieldInfos() const;	

	//! \brief �����ֶ���Ϣ��
	//! \param  fieldInfos [in]  Դ�ֶ�ֵ
	//! \return 
	//! \remarks ��
	//! \attention ��
	void SetFieldInfos(const UGFieldInfos& fieldInfos);	

	//! \brief ���һ���µ��ֶΡ�
	//! \param  newFieldDefn [in] �����ڲ�copy����Ĳ������û������ͷŲ�����
	//! \return ��
	//! \remarks ��
	//! \attention 
	UGbool AddFieldDefn(UGFieldInfo* newFieldDefn);
	
	//! \brief �Ƴ�ָ������λ���ֶΡ�
	//! \param  nIndex [in]  ȡֵ:[0 and GetFieldCount()-1]. 
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void RemoveFieldDefn(UGint nfield);

	//! \brief // �ͷ��ֶ��ֵ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void RemoveAllFieldDefn();	

	//! \brief ����ָ������������λ�ý����ֶ�˳��
	//! \param  nFirst [in]  ȡֵ:[0 and GetFieldCount()-1]. 
	//! \param  nSecond [in]  ȡֵ:[0 and GetFieldCount()-1]. 
	//! \return �ɹ�����TRUE��
	//! \remarks �˽ӿ���Ҫ������á�
	//! \attention ��
	UGbool ChangeFieldDefn(UGint nFirst, UGint nSecond);

	//! \brief ����ָ������������λ�ý���CAD��չ���ݵĵ��ֶ�˳��
	//! \param  nFirst [in]  ȡֵ:[0 and m_xDataFieldInfos.GetSize()-1]. 
	//! \param  nSecond [in]  ȡֵ:[0 and m_xDataFieldInfos.GetSize()-1]. 
	//! \return �ɹ�����TRUE��
	//! \remarks �˽ӿ���Ҫ������á�
	//! \attention ��
	UGbool ShiftxDataField(UGint nFirst, UGint nSecond);

	//! \brief ����layer��ԭʼ���ơ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGString GetOriginalName() const;
	
	//! \brief ����layer��ԭʼ���ơ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetOriginalName(const UGString& strNewName);
	
	//! \brief ����CAD��չ�ֶ����ơ�
	//! \param  xDataFieldInfos[in]��
	//! \return ��
	//! \remarks ��
	//! \attention �û�Ҳ�������޸��ֶ����Ƶ�Ȩ�ޡ�
	void SetxDataFieldNames(UGDict<UGString,UGString>& DictxDataFieldNames);

	
	//! \brief ��ȡԴ�ֶ���Ϣ��
	//! \param  [out]��
	//! \return m_arrfieldNames��
	//! \remarks ��
	//! \attention ��
	UGStrArray GetSourceFieldNames() const;

	//! \brief ��ȡCAD��չ�ֶ����ơ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGDict<UGString,UGString> GetxDataFieldNames() const;

	//! \brief ��ȡԴ���ݵĿռ�����ϵ��
	//! \param  [in]��
	//! \return ��
	//! \remarks
	//! \attention ��
	UGPrjCoordSys* GetSpatialRef() const {return m_pSpatialRef;}

	//! \brief ����Դ���ݵĿռ�����ϵ��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetSpatialRef(const UGPrjCoordSys* pSpatialRef);

	//! \brief ����DWG/DXF��չ���ݵ��ֶΡ�
	//! \param xDataFieldInfos [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetxDataFieldInfos(const UGFieldInfos& xDataFieldInfos);	
	
	//! \brief ��ȡDWG/DXF��չ���ݵ��ֶΡ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGFieldInfos GetxDataFieldInfos()const;

// 	//! \brief �������ݼ��������Ա������
// 	//! \param  strRelatedTableName [in]��
// 	//! \return ��
// 	//! \remarks ��
// 	//! \attention ��
// 	void SetRelatedTableName(const UGString& strRelatedTableName);
// 
// 	//! \brief ��ȡ���ݼ��������Ա������
// 	//! \param  [in]��
// 	//! \return ��
// 	//! \remarks ��
// 	//! \attention ��
// 	UGString GetRelatedTableName()const;

// 	//! \brief s57���ݼ�����
// 	void SetS57DatasetType(UGS57ExtInfo::UGS57DatasetType eDatasetType);
// 
// 	UGS57ExtInfo::UGS57DatasetType GetS57DatasetType() const;

	void SetS57ExtInfo(const UGString& strExtInfo);

	UGString GetS57ExtInfo() const;

protected:
	
	//! \brief ��ʼ����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void Init();

	//! \brief ����layer��ԭʼ�ֶ���Ϣ��
	//! \param  FieldInfos[in]��
	//! \return ��
	//! \remarks ��
	//! \attention 
//	void SetFieldInfosOrginal(UGFieldInfos& FieldInfos);

	//! \brief // �ͷ��ֶ��ֵ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void ClearFieldDict();	

	//! \brief // ͨ�����ƻ�ȡm_arrfieldNames�е�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGint FindIndexByName(const UGString& strFieldName)const;
protected:
	
	//! \brief Ҫ�����͡�
	//! \remarks ��
	FeatureClassType m_Type;
	
	//! \brief ���������
	//! \remarks ��
	UGint m_nFeatureCount;
	
	//! \brief ���ݼ��ķ�Χ��
	//! \remarks ��
	UGRect2D m_Bound;

	//! \brief �ֶνṹ��
	//! \remarks ��
	UGDict<UGString, UGFieldInfo*> m_dictFieldInfos;

	// �ֶ��������飬ά���ֶε�˳���ϵ��ʹ֮��ԭʼ�ֶ�˳��һ��
	UGStrArray m_arrfieldNames;
	// �ֶ��������鱸�ݣ��Է�ɾ��m_arrfieldNames�е��ֶ�����
	UGStrArray m_arrCopyfieldNames;

	//! \brief ������ݼ����ơ�
	//! \remarks ��
	UGString m_strAliasName;

	//! \brief Դ����Layer���ơ�
	//! \remarks ������Layer����ʵ���ƣ������޸ġ�
	UGString m_strLayerName;

	//! \brief CAD��չ���ݵ��ֶ����ơ�
	//! \remarks ��
	UGDict<UGString,UGString> m_DictxDataFieldNames;
	
	//! \brief CAD��������չ�����ֶνṹ
	//! \remarks 
	UGFieldInfos m_xDataFieldInfos;

	//! \brief  ���ݼ�ͶӰ
	UGPrjCoordSys* m_pSpatialRef;

	//! \brief ���ݼ��������Ա����� S-57��ʹ��
	// UGString m_strRelatedTableName;

	//! \brief S57���ݼ�����
	// UGS57ExtInfo::UGS57DatasetType m_eS57DatasetType;
	// UGS57ExtInfo m_s57ExtInfo;
	UGString m_strExtInfo;


};

//! \brief Դ�����е����ݼ�������Ϣ��
//! \remarks���ݼ�����Ϊ�ؼ���	
//typedef UGArray<UGFeatureClassDefn*> UGFeatureClassInfos;
class FILEPARSER_API UGFeatureClassInfos : public UGArray<UGFeatureClassDefn> 
{ 
public:
	//! \brief ���캯����
	//! \remarks ��
	UGFeatureClassInfos();
	
	//! \brief ����������
	//! \remarks ��
	virtual ~UGFeatureClassInfos();

public:

	//! \brief ͨ�����Ƶõ�������һ����Ҫ�ض��塣
	//! \param strName [in] �����ơ�
	//! \return ��
	//! \remarks ��
	//! \attention ��
	const UGFeatureClassDefn* GetFeatureDefnByName(const UGString& strName) const;		

};


//! \brief ʸ���������	
class FILEPARSER_API UGVectorImportParams  : public UGImportParams
{
	friend class UGWorkspaceImportParams;
public:
	//! \brief ���캯����
	//! \remarks ��
	UGVectorImportParams();
	
	//! \brief ����������
	//! \remarks ��
	virtual ~UGVectorImportParams();
	
	//! \brief ���캯����
	//! \remarks ��
	UGVectorImportParams(const UGVectorImportParams& tmp);

	//! \brief ���ظ�ֵ���ź�����
	//! \remarks ��
	UGVectorImportParams& operator=(const UGVectorImportParams& tmp);

public:
	
	//! \brief ���õ�������ݼ������Ϣ��
	//! \param impDatasetInfos [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetImportDatasetInfos(const UGFeatureClassInfos& impDatasetInfos);	
	
	//! \brief �õ���������ݼ������Ϣ��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGFeatureClassInfos& GetImportDatasetInfos();

	//! \brief �����Ƿ���Կ����ݼ���û�м�¼�����ݼ�Ϊ�����ݼ�
	//! \param bHoldNoGeometryDT [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetIgnoreNoGeometryDataset(UGbool bHoldNoGeometryDT = TRUE);	
	
	//! \brief �õ��Ƿ���Կ����ݼ���û�м�¼�����ݼ�Ϊ�����ݼ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetIgnoreNoGeometryDataset() const;
	

	//! \brief ���õ�������Ŀռ��������͡�
	//! \param spatialIndx [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetBuildSpatialIndex(const UGSpatialIndexInfo* spatialIndx);


	//! \brief �õ������Ŀռ��������͡���
	//! \param  [in]��
	//! \return ��
	//! \remarks �ڲ�����ĳ�Ա�����治���ͷ�
	//! \attention ��
	UGSpatialIndexInfo* GetBuildSpatialIndex() const;
	
	//! \brief ��
	//! \param strDtName [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetDestDTVectorName(const UGString& strDtName);

protected:
	
	//! \brief ��
	//! \remarks ��
	UGFeatureClassInfos m_dtInfos;
	

	UGSpatialIndexInfo* m_pSpatialIndex;

};


//////////////////////////////////////////////////////////////////////////

//! \brief ʸ������������
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGVectorExportParams : public UGExportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGVectorExportParams(){
		m_strDatasetName = _U("");
	}//��ʼֵ=0����ʾû�а汾

	//! \brief ����������
	//! \remarks ��
	virtual ~UGVectorExportParams(){}
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
	UGDict <UGint, UGFeatureClassDefn> m_ExportDatasetInfos;
	
private:	
	// \brief Ҫ���������ݼ����ơ�
	// \remarks ��
	UGString m_strDatasetName;
};

} //namespace UGC

#endif // !defined(AFX_UGVECTORIMPORTPARAMS_H__5D6357D7_FC27_48BC_8BA4_3A6788F5DD2F__INCLUDED_)

