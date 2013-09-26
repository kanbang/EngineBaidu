//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author  ��ʽת���顣
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
#if !defined(AFX_UGFileParseVector_H__9D5BD937_D091_4D5F_957C_94B8A7A74D92__INCLUDED_)
#define AFX_UGFileParseVector_H__9D5BD937_D091_4D5F_957C_94B8A7A74D92__INCLUDED_

#include "Geometry/UGFeature.h"
#include "UGFileParse.h"
#include "FileParser/UGVectorConfigParams.h"

#include "UGS57SpatialRelationship.h"

namespace UGC {

//! \brief Դ�����е�һ��Ҫ�ز㡣	
class FILEPARSER_API UGVectorFileLayer: public UGFileLayer
{

public:

	//! \brief ���캯����
	UGVectorFileLayer();
	//! \brief ����������
	virtual ~UGVectorFileLayer();

public:
	//ʶ������
	virtual FILELAYER_TYPE GetType(){return UGFileLayer::FL_VECTOR;}

public:

	//////////////////////////////////////////////////////////////////////////
	// ��
	//////////////////////////////////////////////////////////////////////////
	
	//! \brief ���¿�ʼ���ļ���
	virtual void ResetReading() = 0;

	//	����������ܲ�,����Ҫ�ϵ�,�������ʵ�ִ���
	//! \brief ȡ����
	//! \param arrFeature [in]��ȡ��Geometry�������顣
	//! \param nCount [in]ÿ�λ�ȡGeometry�ĸ�����
	//! \return �ɹ����ػ�ȡ���������
	//! \remask �û�����arrFeature����ռ�,�������ͷ�
	virtual UGint ReadFeatures(UGArray<UGFeature*>& arrFeature, UGint nCount = 1) {return -1;}

	//////////////////////////////////////////////////////////////////////////
	//  [3/4/2011 ������] �ش����,feature�ṹ���ܿ���,���ṩ�˺���
	//! \brief ��ȡ1������
	//! \param oneFeature [in]��ȡ��feature����
	//! \return �ɹ�����1��
	virtual UGint ReadOneFeature(UGFeature*& pFeature) {return -1;}

	
	//! \brief ��ȡlayer�ж������
	//! \return ����layer�ж������, ��ȡʧ�ܷ��� -1 
	//! \remarks Returns the number of features in the layer
	UGint GetFeatureCount() const {return m_FcDefn.GetFeatureCount();}	
	

	//! \brief ��ȡ�ļ���ǰ��¼��š�
	UGint GetFeatureReaded(){ return m_nReadWrited; }

	//! \brief ��ȡԴ���ݵĿռ�����ϵ��
	virtual UGPrjCoordSys* GetSpatialRef() const { return m_FcDefn.m_pSpatialRef;}

	//////////////////////////////////////////////////////////////////////////
	// д
	//////////////////////////////////////////////////////////////////////////

	
	//! \brief ����layer���ֶνṹ��
	virtual UGint CreateFields(UGFieldInfos& fields) {return 0;}

		

	//! \brief ��layer�д�����дһ���µĶ���
	//! \return ���سɹ�д��layer�Ķ��������
	virtual UGint CreateFeature(const UGArray<UGFeature*>& arrFeature){ return 0;}

	//virtual UGint CreateFeature(const UGArray<UGFeature*>& arrFeature){return 0;}	

	//! \brief ��ȡlayer�еĻ�����Ϣ��
	UGFeatureClassDefn * GetLayerDefn(){ return &m_FcDefn;}
	
	//! \brief �ж��Ƿ�����ͬ��Ҫ�ء�
	UGbool HasSameLayer(UGVectorFileLayer* pFileLayer);	

	void SetLayerDefn(const UGFeatureClassDefn* pClssDefn);

	//! \brief ��������ͶӰ,���ڵ���ʱ����
	void SetSpatialRef(const UGPrjCoordSys& srs);

	void SetImportOrExportCharset(UGString::Charset);

	UGString::Charset GetImportOrExportCharset();

	virtual UGulong GetCurFilePosition()const {return 0;}
	virtual UGulong GetFileLength()const {return 0;}

	//! \brief �����Ƿ����ʹ��һ��һ�е��ı���ȡ��ʽ���롣
	//! \param bImportUseReadLine [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	/* ����˵����
	ʸ����ʽ���ļ��򿪵�ʱ����Ҫȷ��Feature�������
	��CSV��Lidar��ASCII�ļ���ͷ��Ϣ,ʹ��ReadLineȷ��Feature������ܺ�ʱ
	���ṩ����������,���ļ��򿪵�ʱ����Ҫȷ��Feature�ĸ���
	����ʱʹ��DataImport.importByBatch2()�������е��빤����
	ʡʱ��������
	*/
	void SetImportUseReadLine(const UGbool bImportUseReadLine = TRUE);	

	//! \brief ��ȡ�Ƿ����ʹ��һ��һ�е��ı���ȡ��ʽ���롣
	//! \param  [out]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetIsImportUseReadLine() const;

protected:

	//! \brief ��������ļ���д������Ϣ��
	//! ����0Ϊʧ�ܣ�����1Ϊ�ɹ�������
	virtual UGint Create() { return 0;}	

	//! \brief ��ȡlayer�Ļ�����Ϣ��
	virtual UGFeatureClassDefn* ReadLayerDefn(const UGImportParams& importParams){return 0;};

	//! \brief ����Ϊ�û��޸ĺ�����ݼ����ơ�
	void SetLayerName(const UGString& strName);

	//! \brief �������ݼ���Χ��
	//! \param  rect2D ����λ[in]��
	void SetBound(UGRect2D& rect2D);	
	
	//! \brief �������ݼ����͡�
	//! \param  �ֶ�����[in]��
	void SetType(UGint nType);	

	//! \brief ���ö��������
	//! \param  nCount�ֶθ���[in]��
	void SetFeatureCount(UGint nCount);	

	//! \brief ����layer��ԭʼ�ֶ���Ϣ��
	//! \param  FieldInfos[in]��

	//! \return ��
	//! \remarks ��
	//! \attention 
//	void SetFieldInfosOrginal(UGFieldInfos& FieldInfos);

	
	//! \brief ����layer��ԭʼ�ֶ���Ϣ��
	//! \param  FieldInfos[in]��
	void SetxDataFieldInfosOrginal(UGFieldInfos& FieldInfos);


protected:

// 	UGFieldInfos& GetFieldInfosOrginal()
// 	{
// 		return m_FcDefn.m_FieldInfosOriginal;
// 	}
	const UGStrArray GetSourceFieldName() const;

	const UGDict<UGString, UGFieldInfo*>& GetFiledInfos() const;

protected:

	UGFeatureClassDefn m_FcDefn;
	// �ļ����룬�����ʱ��Ϊ��Դ�ļ��ı��룬����ΪĿ���ļ�����
	UGString::Charset m_eImportOrExportCharset;

//	//! \brief ���������
//	//! \remarks ��
//	UGint m_nfeatureCount;
	
	//! \brief ��ǵ�ǰ�Ѷ�д������Ŀ��
	UGint m_nReadWrited;

// 	//! \brief S57���ݼ�����չ��Ϣ���洢������OBJLֵ�����������Ա�����
// 	UGString m_strS57DatasetExtInfo;

	//! \brief �ڵ���ʱ�Ƿ��ǰ�һ��һ�еĶ�ȡ��
	//! \remarks Ŀǰ������CSV��Lidar��ASCII�ļ���ʽ����
	/* ��Ӵ˱�����˵����
	ʸ����ʽ���ļ��򿪵�ʱ����Ҫȷ��Feature�������
	��CSV��Lidar��ASCII�ļ�����ReadLine�ķ�����ܺ�ʱ
	���ṩ����������,���ļ��򿪵�ʱ����Ҫȷ��Feature�ĸ���
	����ʱʹ��DataImport.importByBatch2()�������е��빤����
	ʡʱ��������
	*/
	UGbool m_bImportUseReadLine;


};

typedef UGArray<UGVectorFileLayer*> UGArrVectFileLayer;

//! \brief ʸ���ļ��������ࡣ
class FILEPARSER_API UGFileParseVector : public UGFileParser  
{
public:

	//! \brief ���캯����
	UGFileParseVector();
	
	//! \brief ����������
	virtual ~UGFileParseVector();	

public:
	
	virtual UGFileType::EmGroup GetFileGroup() const;
	//////////////////////////////////////////////////////////////////////////
	// ��
	//////////////////////////////////////////////////////////////////////////
	
	//! \brief ��ȡԴ�����е����ݼ���Ŀ��
	virtual UGint GetLayerCount(){ return m_ArrVectFileLayer.GetSize(); }

	//! \brief ͨ�������õ�Դ�����е�һ�����ݼ���
	virtual UGFileLayer* GetLayer(UGint nlayer);	

	//! \brief ͨ�����Ƶõ�Դ�����е�һ�����ݼ�����
	virtual UGVectorFileLayer* GetLayerByName(const UGString& strLayer);

	//! \brief ����Դ�����е����ݼ���Ϣ��
	UGFeatureClassDefn* GetFetureClassDefn(UGint index) const;// {return m_ArrVectFileLayer;}	

	//  [10/13/2009 ������] �˽ӿڼ�����������ͨ��layer��ȡͶӰ
	//! \brief ��ȡԴ���ݵĿռ�����ϵ��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
//	virtual const UGPrjCoordSys*  GetSpatialRef () {return NULL;}

	//////////////////////////////////////////////////////////////////////////
	// д
	//////////////////////////////////////////////////////////////////////////


	//! \brief ����ʸ���ļ���
	//! \param fcDefn [in]��
	virtual UGint Create(const UGVectorExportParams* exprams, const UGPrjCoordSys* spatialRef=NULL) {return 0;}

	//! \brief ����ʱ����һ��Ҫ�ز㡣
	//! \param fcDefn [in]��
	virtual UGVectorFileLayer* CreateLayer(const UGFeatureClassDefn* pfcDefn){return NULL;}	

	virtual UGVectorFileLayer* CreateLayer(const UGFeatureClassDefn* pfcDefn, UGString::Charset){return NULL;}	

	//! \brief ׼����ʼд����,��layerд����֮ǰ�������
	//! \return �Ƿ�ɹ� ,1����ɹ���-1�����ɹ�
	virtual UGint BeginWrite(){ return 1;}

	//! \brief ����д����,��layerд������֮��������
	//! \return �Ƿ�ɹ� ,1����ɹ���-1�����ɹ�
	virtual UGint EndWrite(){return 1;}

	//! \brief ��S57����ʹ�ã�����DSNM_CODEֵ
	// virtual void SetDSNMCode(const UGushort nDSNMCode){return;}

	//! \brief ���ù�����ϵ���飬��S57ʹ��
	virtual void SetRSDict(UGDict<UGString,UGS57RSS>& dictRs) {return;}

	//! \brief �������ߺ����ߵ����˹�ϵ���飬��S57ʹ��
	virtual void SetFVEDict(UGDict<UGuint, UGS57FSPTS>& dictFspt) {return;}

	//! \brief ���õ����͵�ؼ���������˹�ϵ���飬��S57ʹ��
	virtual void SetFVPDict(UGDict<UGuint, UGS57FSPTS>& dictFspt) {return;}

	//! \brief ����ˮ�����ݼ������ƣ���S57ʹ��
	//virtual void SetSoundgLayerName(const UGString& strLayerName) {return; }

	//! \brief ����S57���Ե��ַ����ȼ��� ��S57ʹ��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual void SetAALL(UGint nAALL) { return; }

	//! \brief ����S57�����������Ե��ַ����ȼ��� ��S57ʹ��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual void SetNALL(UGint nNALL) { return; }

	virtual UGString GetDatasetGroupExtData()const {return _U("");}

protected:
	//! \brief ���Ҫ����������
	//! \param pClassDefn [in]��
	UGbool AddVectorFileLayer(UGVectorFileLayer* pFileLayer);	
protected:

	//! \brief �˸�ʽ�е����ݼ���Ϣ��
	//! \remarks ��
	//UGFeatureClassInfos m_ArrFcInfos;
	UGArrVectFileLayer m_ArrVectFileLayer;
};

} //namespace UGC

#endif // !defined(AFX_UGFileParseVector_H__9D5BD937_D091_4D5F_957C_94B8A7A74D92__INCLUDED_)

