/*! \file	 UGRecordset.h
 *  \brief	 ��¼���ඨ���ļ�
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRecordset.h,v 1.33 2010/03/24 01:20:47 wangmao Exp $
 */

#ifndef UGRECORDSET_H
#define UGRECORDSET_H

#include "Engine/UGQueryDef.h"
#include "Engine/ugeng.h"
#if !defined SYMBIAN60 /*&& !defined  OS_ANDROID && !defined (IOS)*/
#include "Geometry/UGFeature.h"
#endif
#include "Geometry/UGGeometry.h"
#include "Toolkit/UGRectUInt.h"
#include "Geometry/UGGeoCompound.h"
#include "Engine/UGTableRecordset.h"
#include "Toolkit/UGStringW.h"
#include "Engine/UGBulkEditManager.h"
#include "Toolkit/UGLogFile.h"

namespace UGC {

class UGTable;
class UGDatasetVector;
class UGRecordset;
class UGDatasetRelClass;
class UGBulkEditManager;

#define UGBULKEDITGEOSIZE 65536
#define MAXBINARYFIELDSIZE	1024 * 5

//! \brief �Ӽ�¼���������������ϼ�¼��
struct SubRecordset 
{
	//! \brief ���ݼ�����
	UGString  strDtName;
	//! \brief ��¼��
	UGint nRecordCount;
	//! \brief ��¼��
	UGRecordset *pRecordset;

	SubRecordset()
	{
		nRecordCount = -1;
		pRecordset = NULL;
	}

};
//! \brief ��¼����
//##ModelId=4820305001A5
#ifdef SYMBIAN60
class ENGINE_APIC UGRecordset :public UGTableRecordset
#else
class ENGINE_API UGRecordset :public UGTableRecordset
#endif
{	
public:
	//! \brief �༭ģʽ
	//##ModelId=482030500235
	enum EditMode 
	{
		//##ModelId=482030500243
		EditNone			= 0x00000000, //! δ���κα༭
		//##ModelId=482030500244
		EditAdd				= 0x00000001, //! ��ִ�й�AddNew����
		//##ModelId=482030500245
		EditInProgress		= 0x00000002, //! ���ڱ༭
		//##ModelId=482030500261
		EditSetFieldValue	= 0x00000004, //! �Ѹ����������� 
		//##ModelId=482030500262
		EditSetGeometry		= 0x00000008, //! ��ִ�й�SetGeometry����
		//##ModelId=482030500263
		EditDeleted			= 0x00000010, //! ��ɾ����¼
		EditBulkOperate		= 0x00000100  //! �������±�־
	};
	
public:
	//! \brief ���캯��
	//##ModelId=4820305001B5
	ENGINE_APIF UGRecordset();

	//##ModelId=483BB70802BF
	ENGINE_APIF UGRecordset(UGDatasetVector* pDatasetVector);
	//! \brief ��������
	//##ModelId=4820305001B6
	virtual ENGINE_APIF ~UGRecordset();
public:
	//! \brief ��ȡ��¼����Ӧ�����ݼ���
	//! \return ʸ�����ݼ�ָ�롣
	//##ModelId=4820305001B8
	ENGINE_APIF UGDatasetVector* GetDataset() const;

	//! \brief ��ȡ��¼����Ӧ�����ݼ���
	//! \return ��ϵ�����ݼ�ָ�롣
	ENGINE_APIF UGDatasetRelClass* GetDatasetRel() const;
	
	//! \brief �жϼ�¼���Ƿ����������ݡ�
	//! \return ���������ݷ���TRUE��û�з���FALSE��
	//##ModelId=4820305001BA
	ENGINE_APIF UGbool HasDBInfo();

	//! \brief �жϼ�¼���Ƿ��м������ݡ�
	//! \return �м������ݷ���TRUE��û�з���FALSE����
	//##ModelId=4820305001BB
	ENGINE_APIF UGbool HasGeometry();

	//! \brief �ж�ָ���ֶε��ֶ�ֵ�ڶ�̬�ֶι�ϵ���Ƿ�����޸�
	//! \param strName ָ�����ֶ�����
	//! \param varVal  ָ���ֶε�ָ��ֵ
	//! \param ID	   ��Ӧ�ļ�¼ID
	//! \return ���سɹ�˵�����ֶ�ֵ�������ã�����ʧ����˵���ڶ�Ӧ�Ķ�̬�ֶι�ϵ�и�ֵ�ǷǷ���
	ENGINE_APIF UGbool IsAvailableForDyn(const UGString &strName, const UGVariant &varVal, const UGint ID);

	//! \brief ɾ�����ݼ�ʱɾ����Ӧ�Ķ�̬�ֶμ�¼
	ENGINE_APIF void RemoveDynRecord();

	//! \brief ɾ�����м�¼
	//##ModelId=4820305001BC
	virtual ENGINE_APIF UGbool DeleteAll();

	//! \brief ��ĳ��ͳ�Ʒ���ͳ��ĳ���ֶ�
	//! \param &strField ��ͳ���ֶ�
	//! \param nMode ͳ��ģʽ,������"MAX","MIN","AVG","SUM","STDDEV","VARIANCE"
	//! \attention ������ͳ�ƹؼ������в�ͬ,���"�����ݿ��ͳ�ƺ���.doc"
	//##ModelId=4820305001C5
	virtual ENGINE_APIF UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);

	//! \brief ˢ�¼�¼��,һ��������²�ѯһ��
	//##ModelId=4820305001C9
	virtual ENGINE_APIF UGbool Refresh();

	//! \brief �����ֶ�ֵ,strSrcField��
	//!        strDestField���붼�������ֶ�����ƥ��
	//##ModelId=4820305001CB
	virtual ENGINE_APIF UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);
	
	//! \brief ��ȡ��ǰ��¼��ID
	//##ModelId=4820305001CF
	virtual ENGINE_APIF UGint GetID();

	//! \brief ֱ�Ӷ������ζ����ָ��,���ڰ��������ݶ������ڴ��е�����(��dgn)��˵��
	//!        ����Ҫ�������ζ�������Ҳ��Ҫȥɾ����,�������Լӿ�����ٶ�
	//##ModelId=4820305001D4
	virtual ENGINE_APIF UGbool GetGeometryDirect(UGGeometry*& pGeometry);

	//! \brief ȡ�ü��ζ��󣬷��صļ��ζ���ָ���ں����ڷ����ڴ棬
	//!        ���渺��ɾ������������ڴ�й©
	//##ModelId=4820305001D7
	virtual ENGINE_APIF UGbool GetGeometry(UGGeometry*& pGeometry);

	//! \brief ���õ�ǰ��¼�ļ��ζ���
	//##ModelId=4820305001DE
	virtual ENGINE_APIF UGbool SetGeometry(UGGeometry &geometry);

	//! \brief ȡ�ü��ζ������άBounds
	//##ModelId=4820305001DA
	ENGINE_APIF UGbool GetGeometryBounds(UGRect2D &rc2Bounds,double& dMinZ,double& dMaxZ);

	//! \brief ����ʾ���õĽӿ�
	virtual ENGINE_APIF UGbool GetWordRectBounds(UGRectUInt & /*rcWdRectBounds*/){return FALSE;};

	//! \brief �жϼ�¼���Ƿ�Ϊ��
	//##ModelId=4820305001E4
	ENGINE_APIF UGbool IsEmpty();

	//! \brief ͨ��ID��λ��¼ָ��
	//##ModelId=4820305001E5
	virtual ENGINE_APIF UGbool SeekID(UGint nID);

	//! \brief ���£��ύ�޸�
	//! \return UGint �ɹ��򷵻ظ��¶����ID,���򷵻�-1
	//! \remark ��AddNew��Edit֮����Ҫ����Update����ɱ༭
	//##ModelId=4820305001E8
	virtual ENGINE_APIF UGint Update();

	//! \brief ȡ���޸�
	//##ModelId=4820305001EA
	virtual ENGINE_APIF UGbool CancelUpdate();
	
	//! \brief ��ʼ�޸�����
	//##ModelId=4820305001EC
	virtual ENGINE_APIF UGbool Edit();

	//! \brief �����������±�־
	//! \param bIsEditBulkOperate [in] TRUEΪ��ʼ�������£�FALSEΪȡ���������±�־
	virtual ENGINE_APIF UGbool EditBulk(UGbool bIsEditBulkOperate);

	//! \brief ��װ��UDB�༭�������񣬸ýӿڶ�����������Ч
	//! \mark ����������عر� 
	virtual ENGINE_APIF UGbool StartQuickEdit();

	//! \brief ��װ��UDB�༭�ر����񣬸ýӿڶ�����������Ч
	//! \mark ����������عر� 
	virtual ENGINE_APIF UGbool EndQuickEdit();

	//! \brief �����������µ����ޣ�ʹ�õ��ڴ��С������ nCacheSize ���ֽڣ����ﵽ����ʱ�Զ��ύ��Ĭ��ֵΪ0
	//! \param nCacheSize ��������ʹ�õ��ڴ�����
	//! \return  �Ƿ����óɹ�����Ҫ����������״̬������
	//! \remarks ���ͬʱ�������ڴ����޺�Ҫ���������ޣ�����������֮һ���Զ��ύ
	//! \remarks �����û�������ڴ����ޣ�Ҳû������Ҫ�������ޣ���Ҫ��������1024����
	virtual ENGINE_APIF UGbool SetBulkMaxCache(UGuint nCacheSize);

	//! \brief �����������µ����ޣ����µļ�¼�ﵽ nCount ��ʱ���Զ��ύ��Ĭ��ֵΪ0
	//! \param nCount ��������Ҫ����������
	//! \return  �Ƿ����óɹ�����Ҫ����������״̬������
	//! \remarks ���ͬʱ�������ڴ����޺�Ҫ���������ޣ�����������֮һ���Զ��ύ
	//! \remarks �����û�������ڴ����ޣ�Ҳû������Ҫ�������ޣ���Ҫ��������1024����
 	virtual ENGINE_APIF UGint SetBulkMaxFeature(UGuint nCount);
#if !defined SYMBIAN60 /*&& !defined  OS_ANDROID && !defined (IOS)*/
	//! \brief ��������ʱ ���һ��Ҫ��
	//! \return ���� pFeature �� SmID��С�� 1 �����ʧ��
	virtual ENGINE_APIF UGint AddOneFeature(UGFeature *pFeature);
	virtual ENGINE_APIF UGint AddOneFeature(UGGeometry *pGeometry, const UGArray<UGString> &aryFields, const UGArray<UGVariant *> &aryValues) {return -1;}

	// ����ָ����Ӧ�ֶΣ��ֶεĺϷ������ⲿ�ж�
	virtual UDBENGINE_APIF UGint AddOneFeature(UGFeature *pFeature,UGFieldInfos srcFields, UGFieldInfos desFields){return -1;};

	//! \brief ��������ʱ �޸�һ��Ҫ�أ���ʱ֧��UDB http://192.168.115.2:8090/browse/UGOSPII-2227��
	//! \param bModifyGeometry �Ƿ��޸ĵ�ǰ��Geometry. bModifyGeometry=TRUE�� pGeometry����Ϊ�գ�pGeometry=FALSE����pGeometryû���ã����Դ����
	virtual ENGINE_APIF UGint SetOneFeature(UGGeometry *pGeometry, UGbool bModifyGeometry, const UGArray<UGString> &aryFields, const UGArray<UGVariant> &aryValues);
#endif

	//! \brief ��������ʱ,ǿ��ˢ��,�����������༭������д�����ݿ�
	//! \return �Ƿ�ˢ�³ɹ�
	virtual ENGINE_APIF UGbool FlushBulkEdit();

	//! \brief ȡ�������������µ����ݣ����ϴ��ύ������ �༭��������Ч�������Լ�����ʼ���������༭
	virtual ENGINE_APIF UGbool CancleBulkOperated();

	//! \brief ��ȡ��ǰ�༭ģʽ
	//##ModelId=4820305001EE
	ENGINE_APIF EditMode GetEditMode() const ;
	
	//! \brief �����¼�¼,�ɹ�������TRUEֵ��ʧ�ܷ���FALSEֵ��
	//! \param *pGeometry [in] ��ӵ�Geometryָ��
	//! \param bReturnID=FALSE [in] �˲����Ѿ��������á�
	//! \return True �� False ��ֵ
	//! \remarks �����õ��¶����ID����ô���ϵ���GetId����
	//##ModelId=4820305001F4
	virtual ENGINE_APIF UGint AddNew(UGGeometry *pGeometry,
		UGbool bReturnID=FALSE);

	//! \brief ɾ����ǰ��¼
	//##ModelId=4820305001F8
	virtual ENGINE_APIF UGbool Delete();

	//! \brief ˢ�¼�¼
	//##ModelId=4820305001FA
	virtual ENGINE_APIF UGbool FlushCurrentRecord();
	
	//! \brief �Ƿ�֧������
	//##ModelId=4820305001FC
	virtual ENGINE_APIF UGbool CanTransact() const;

	//! \brief �Ƿ�ɸ���
	//##ModelId=4820305001FE
	virtual ENGINE_APIF UGbool CanUpdate();	

	//! \brief �Ƿ�����
	//##ModelId=482030500200
	virtual ENGINE_APIF UGbool CanAppend();

	//! \brief �����¼���ķ�Χ
	//##ModelId=482030500207
	virtual ENGINE_APIF UGbool ComputeBounds(UGRect2D &rc2Bounds,
		UGdouble &dMinZ,UGdouble &dMaxZ);

	//! \brief ���ò�ѯ����
	//##ModelId=48203050020F
	ENGINE_APIF void SetQueryDef(const UGQueryDef& querydef);

	//! \brief ��ȡ��ѯ����
	//##ModelId=482030500213
	ENGINE_APIF void GetQueryDef(UGQueryDef & querydef) const;

	//##ModelId=482030500216
	ENGINE_APIF UGQueryDef::QueryOption GetOptions() const;

	//! \brief ���Ҫ�ӽ��������������Ƿ�Ϸ�
	//##ModelId=482030500218
	ENGINE_APIF UGbool IsGeometryTypeValid(UGGeometry::Type& geoType);

	//! \brief ����XML��ʽ����Ϣ
	//##ModelId=48203050021A
	ENGINE_APIF UGString ToXML(UGGeometry::GMLVersionType versionType, UGint nPace = 0);
	
	//! \brief ��XML�ַ���������Geometry
	//##ModelId=48203050021D
	ENGINE_APIF UGbool FromXML(const UGString& strXML,UGGeometry::GMLVersionType versionType);
#if !defined SYMBIAN60 /*&& !defined  OS_ANDROID && !defined IOS*/
	//! \brief ȡ�����ݼ���ĳ������Ҫ�ء�
	//! \param nID ���ݼ���¼ID��[in]��
	//! \return ����Ҫ��ָ�롣
	//##ModelId=482030500223
	virtual ENGINE_APIF UGFeature* GetFeature();	
	
	virtual ENGINE_APIF UGbool GetFeature(UGFeature *&pFeature);

	//! \brief ������Ҫ�ظ��µ����ݼ��С�
	//! \param pFeature ����Ҫ��ָ��[in]��
	//! \return �Ƿ񱣴�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500226
	virtual ENGINE_APIF UGint UpdateFeature(const UGFeature* pFeature);
	
	//! \brief ������Ҫ��׷�ӵ����ݼ�δβ��
	//! \param pFeature ����Ҫ��ָ��[in]��
	//! \return �Ƿ�׷�ӳɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ׷��ʱ����Ҫ�ع��������ݼ���¼ID���������á�
	//##ModelId=482030500229
	virtual ENGINE_APIF UGint AddFeature(const UGFeature* pFeature);	
#endif
	//! \brief �Ƿ�֧��ָ���Ĳ���
	//##ModelId=482030500204
	virtual ENGINE_APIF UGbool IsSupport(UGEngAction nAction){return FALSE;}

	//! \brief �Ƿ��ڶ�ά��ͼ��ʾ��ʹ�øü�¼��
//	virtual ENGINE_APIF void IsUseIn2DMap(UGbool bIn2Dmap){m_bIn2Dmap = bIn2Dmap;}
	
	virtual ENGINE_APIF UGint GetLinkTableCurrentIndex()
	{
		return m_nCurrentLinkTableIndex;
		
	}

	virtual ENGINE_APIF UGint GetLinkRecourdCount()
	{
		return m_nLinkRecourdCount;
	}

public:
	//!	\brief	�޸��ֶ�������Ϣ�ͼ�����Ϣ�������ǽ�ԭ����SetFieldValue��SetGeometry��Update��ʵ��Ǩ�ƹ����ˣ�
	//			��Ҫԭ����Ҫ��ԭ���Ľӿ�����������Ϊ�Ĵ�������Ӧ�Զ�̬�ֶλ��ϵ�����������
	virtual ENGINE_APIF UGbool ModifyFieldValue(const UGString &strName, const UGVariant &varVal) { return FALSE; }
	virtual ENGINE_APIF UGbool ModifyGeometry(UGGeometry &geometry) { return FALSE; }
	virtual ENGINE_APIF	UGint CommitModify() { return FALSE; }

	virtual ENGINE_APIF UGFeature * GetTemplateFeature();

protected:

	//! \brief ��ʼ����ѯ�ֶ�
	virtual ENGINE_APIF UGbool InitFields(UGArray<UGString> &fields);

	//! \brief  ����QueryDefine���ж��Ƿ���Ҫ�����ѯ�ֶ�
	//##ModelId=483BB70802FC
	ENGINE_APIF UGbool IsStatisticalQuery(UGbool bCheckGroupby=TRUE);

	//�����ѯ�����ļ�������
	//! \brief �������ݼ�������Ĳ�ѯ����ת��Ϊ�Ա�������Ĳ�ѯ
	//! \param &querydefIn [in]
	//! \param &querfdefOut [out] 
	//! \remarks  
	//! \sa CheckOut, CheckIn, UndoCheckOut, UnLock
	virtual ENGINE_APIF void TransactQuerydef(const UGQueryDef &querydefIn, UGQueryDef &querydefOut);
	//! \brief ��������ڴ�strIn�е���'.'Ϊ�������Ӵ�Ϊ���ݼ�������Ҫ�����滻Ϊ��Ӧ�ı���
	//! \return ����""�������滻ʧ�ܣ����򷵻��滻��Ľ��
	virtual ENGINE_APIF UGString ReplaceString(const UGString &strIn);
	//! \brief �Ӵ�strIn��ȡ�����һ���ַ���ʼ��ǰ����Ĳ������Ƿ��ַ����Ӵ�����A-Z,a-z,0-9��'_'֮����ַ���Ϊ�Ƿ�
	virtual ENGINE_APIF UGString GetLegalString(const UGString &strIn);

	
protected:	
	//! \brief ��¼����Ӧ�����ݼ�
	//##ModelId=48203050022F
	//UGDatasetVector* m_pDataset;
	UGTable* m_pDataset;


	//��������
	//! \brief ����ڴ棨��λ���ֽڣ�
	UGuint m_nBulkMaxCache;

	//! \brief ����¼����,Ĭ��1024
	UGuint m_nBulkMaxFeature;
	UGint m_nCurrentLinkTableIndex;
	//linkTableʵ�ʵļ�¼������Ŀ
	UGint m_nLinkRecourdCount;

	//{{������Ϊ���ϼ�¼�����ӵı���
	//! \brief �Ƿ�ʹ�ø��ϼ�¼��
	UGbool m_bUsingComplex;

	UGint m_nCurSubRecordIndex;

	//! \brief ���ϼ�¼����ÿ����¼����λ��ƫ��
	UGArray<UGint> m_arySubOffset;

	//! \brief ���ϼ�¼�����Ӽ�¼������
	UGArray<SubRecordset> m_arySubRecordset;

	//! \brief ���ϼ�¼���������ڴ��С
	UGint m_nTotalMemSize;

	UGMutex m_Mutex;

//	UGbool m_bIn2Dmap;
public:
	//! \brief ��ѯ����
	//##ModelId=482030500234
	UGQueryDef m_QueryDef;

	UGArray<UGint> m_arrIDs;

	UGint m_nCurrentIndex;

	UGint m_nRecordCount;

	//! ��ǰ�༭ģʽ
	//! \brief ��ǰ�༭״̬
	/// @li	0 -- EditNone			δ���κα༭
	/// @li	1 -- EditInProgress		���ڱ༭
	/// @li	2 -- EditAdd			��ִ�й�AddNew����
	/// @li	3 -- EditOfGeometry		��ִ�й�SetGeometry����
	//##ModelId=482030500232
	UGint m_nEditMode;

	//!  \brief �����洢�������ֶ����ݵĴ�С
	UGDict<UGString, UGint> m_dictBinarySize;

protected:
	UGint m_nIDIndex;


//#if !defined OS_ANDROID && !defined (IOS)
	// ���ӵ�ǰ��¼����Featureģ��,���������GetFeature������.
	UGFeature *m_pFeatureTemplate;

	UGBulkEditManager *m_pBulkEditManager;
//#endif

	//!  \brief �����洢�������ֶ����ݵĻ���
	UGArray<UGuchar*> m_arrBinaryBuffer;
	
private:
	UGuint m_nFeatureUsedMemory;
};


}

#endif



