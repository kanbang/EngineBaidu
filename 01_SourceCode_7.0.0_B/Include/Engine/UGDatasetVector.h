/*! \file	 UGDatasetVector.h
 *  \brief	 ʸ�����ݼ���
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDatasetVector.h,v 1.45 2010/03/22 06:00:57 wangmao Exp $
 */

#ifndef UGDATASETVECTOR_H
#define UGDATASETVECTOR_H

#include "Engine/UGDataset.h"
#include "Engine/UGRecordset.h"
#include "SpatialIndex/UGSpatialIndexInfo.h"	

#if !defined SYMBIAN60 /*&& !defined  OS_ANDROID */
//#ifndef OS_ANDROID
#include "Geometry/UGFeature.h"
//#endif
#include "SpatialIndex/UGDBRTreeNode.h"
#include "SpatialIndex/UGDBRTree.h"
#endif
#include "Engine/UGSpatialIndex.h"
#include "Toolkit/UGTextCodec.h"
#include "Engine/UGDatasetVectorInfo.h"

#if defined IOS
#include "Engine/UGDataHistory.h"
#endif

#include "Engine/UGTable.h"

namespace UGC {
	//class PATHANALYST_API	 UGEventProperty
	class ENGINE_API	 UGEventProperty  
	{
	public:
		 UGEventProperty();
		~UGEventProperty();
		UGbool operator == (const UGEventProperty& EventProperty);
		UGbool operator != (const UGEventProperty& EventProperty);
	public:		
	/*! ��̬�ֶ��¼�(Event)����
	*
	*/
		enum EventType
		{
			PointEvent = 1, /// ���¼�
			LineEvent  = 2, /// ���¼�
		};		
		
		UGString	  m_strEventRouteIDFieldName; /// �¼�����RouteID�ֶ���		
		EventType m_nEventType;			    /// �¼�����		
		UGString m_strFromMeasureFieldName; /// ���¼�����ʼMeasure�ֶ�
		UGString m_strToMeasureFieldName;   /// ���¼�����ֹMeasure�ֶ�
		UGString m_strMeasureFieldName;     /// ���¼���Measure
		
		UGlong m_nEventMeasureUnit;          /// Measure��λ
		
		UGString m_strEventTableName;
		UGDatasetVector* m_pDatasetRoute;
		UGString m_strRouteDataSourceAlias; /// Route���ݼ����ڵ�����Դ����
		UGString m_strRouteDtName;		   /// Route���ݼ�����	 
		UGString m_strRouteIDFieldName;	   /// RouteID�ֶ�	 
		UGString m_strOffsetField;		   /// ���ݶ�λƫ���ֶ�	
		UGString m_strRouteWhereClause;	   /// Route���ݼ���������

	};
#if !defined SYMBIAN60
class UGDataHistory;
#endif
class UGSpatialIndex;
//##ModelId=48203052029F
struct UG_DATA_CACHE_FILE_HEADER 
{
	//##ModelId=4820305202B0
	UGint nVersion;
	//##ModelId=4820305202B1
	UGint nRecordCount;
	//##ModelId=4820305202BF
	UGDataCodec::CodecType nCodecType;
	//##ModelId=4820305202CE
	UGint nDatasetID;
	//##ModelId=4820305202DE
	UGint nLibID;
	//##ModelId=4820305202DF
	UGint nOffBits;
	//##ModelId=4820305202EE
	UGRect2D rc2Bounds;
	//##ModelId=4820305202FD
	UGdouble dXGridSize;
	//##ModelId=4820305202FE
	UGdouble dYGridSize;
	//##ModelId=48203052030D
	UGint nReserved1;
	//##ModelId=48203052031C
	UGint nReserved2;

	//##ModelId=48203052031D
	void Save(UGStream& stream)
	{
		stream<<nVersion;
		stream<<nRecordCount;
		stream<<(UGint)nCodecType;
		stream<<(UGint)nDatasetID;
		stream<<nLibID;
		stream<<nOffBits;
		
		stream<<rc2Bounds.left;
		stream<<rc2Bounds.top;
		stream<<rc2Bounds.right;
		stream<<rc2Bounds.bottom;
		
		stream<<dXGridSize;
		stream<<dYGridSize;
		stream<<nReserved1;
		stream<<nReserved2;
	};

	//##ModelId=48203052032D
	void Load(UGStream& stream)
	{
		stream>>nVersion;
		stream>>nRecordCount;
		UGint nEnc = 0;
		stream>>nEnc;
		nCodecType = (UGDataCodec::CodecType)nEnc;
		stream>>nDatasetID;
		stream>>nLibID;
		stream>>nOffBits;
		
		stream>>rc2Bounds.left;
		stream>>rc2Bounds.top;
		stream>>rc2Bounds.right;
		stream>>rc2Bounds.bottom;
		
		stream>>dXGridSize;
		stream>>dYGridSize;
		stream>>nReserved1;
		stream>>nReserved2;
	};

	UGint GetSizeofLenth()
	{
		UGint nLenght=0;
		
		nLenght = sizeof(nVersion) + sizeof(nRecordCount) + sizeof(nCodecType) +
				  sizeof(nDatasetID) + sizeof(nLibID) + sizeof(nOffBits) +
				  4*sizeof(double) + sizeof(dXGridSize) + sizeof(dYGridSize) +
				  sizeof(nReserved1) + sizeof(nReserved2);
		return nLenght;
	}
};

//UG_SQ_MAYBEIDS
class ENGINE_API UGMaybeItem
{
public:
	UGMaybeItem()
	{
		pGeometry = NULL;
		aryIDs.RemoveAll();
	};
	
	~UGMaybeItem()
	{
		if(pGeometry)
		{
		}
		aryIDs.RemoveAll();
	};
	
public:
	UGGeometry *pGeometry;
	UGArray<UGint> aryIDs;
};

class ENGINE_API UGMaybeItems : public UGArray<UGMaybeItem >
{
public:
	void ReleaseAll()
	{
		for(UGint n=0; n < this->GetSize(); n++)
		{
			delete GetAt(n).pGeometry;
			//			GetAt(n).pGeometry = NULL;
		}
	};
};
typedef UGArray<UGint> UG_MayIDs;

//##ModelId=48203052033C
struct UG_INDEX_CACHE_FILE_HEADER 
{
	//##ModelId=48203052034C
	UGint nReserved1;
	//##ModelId=48203052034D
	UGint nReserved2;
	//##ModelId=48203052035B
	UGint nOffBits;

	//##ModelId=48203052036B
	void Save(UGStream& stream)
	{
		stream<<nReserved1;
		stream<<nReserved2;
		stream<<nOffBits;
	};

	//##ModelId=48203052036D
	void Load(UGStream& stream)
	{
		stream>>nReserved1;
		stream>>nReserved2;
		stream>>nOffBits;
	};

	UGint GetSizeofLenth()
	{
		UGint nLenght=0;
		
		nLenght = sizeof(nReserved1) + sizeof(nReserved2) + sizeof(nOffBits);
		return nLenght;
	}
};	


#ifdef OS_ANDROID
	class UGDataHistory;
#endif
//��¼��ʷ����ָ����Ƿ�ָ����Ч�Ľṹ
//##ModelId=48203052037A
	struct ValidDataHistory
	{
		#if !defined SYMBIAN60 /*&& !defined  OS_ANDROID && !defined (IOS)*/
		//##ModelId=48203052038B
		UGDataHistory* pDataHistory;
		#endif
		//##ModelId=48203052038C
		UGbool bValid ;
	};

//##ModelId=482030520399
class  ENGINE_API UGSubDtArray : public UGArray<UGDatasetVector *>
{
public:
	//##ModelId=4820305203B9
	UGSubDtArray()
	{
	};

	//##ModelId=4820305203BA
	~UGSubDtArray()
	{
	};
public:
	//##ModelId=4820305203C8
	UGDatasetVector * operator [](UGint nIndex) const;
	//##ModelId=4820305203CB
	UGDatasetVector * operator [](UGString strName) const;
};

//! \brief �޸�ͼ���ʶ
enum UGModifyDatasetFlag	
{
	//! \brief ��Ӷ���
	mdAddGeometry,			
	//! \brief ɾ��ɾ��
	mdDeleteGeometry,				
	//! \brief �޸Ķ���
	mdEditGeometry,		

};
//! \brief ModifyDatasetProc �ص�����
//!param[in] pLayerDataset ���ݼ�ͼ��ָ��
//!param[in] nID �޸Ķ����ID
//!param[in] pnt2D �޸Ķ�����ڵ�
//!param[in] flag�޸ı�ʶ
typedef  void (UGSTDCALL *AffterDatasetModifiedProc)(void* pLayerDataset,UGint nID,UGPoint2D pnt2D,UGModifyDatasetFlag flg);

//##ModelId=48203053006D
#ifdef SYMBIAN60
class ENGINE_APIC UGDatasetVector : public UGTable
#else
class ENGINE_API UGDatasetVector : public UGTable
#endif
{
friend class UGSpatialIndex;

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
friend class UGDBRTreeBranch;
friend class UGDBRTreeLeaf;
#endif

public:
	//! \brief ���캯��
	//##ModelId=48203053007D
	ENGINE_APIF UGDatasetVector();
	//! \brief ��������
	//##ModelId=48203053007E
	virtual ENGINE_APIF ~UGDatasetVector();

	//! \brief ����UGDataset����Ĵ��麯��
public:

	//! \brief ׷�Ӽ�¼,�����ֶ��ж�Ӧ��ϵ,�ռ��ֶβ�����
	//##ModelId=48203053017F
	virtual ENGINE_APIF UGbool Append(UGRecordset* pSrcRecordset,
		UGArray<UGString> &strSrcFieldNames,
		UGArray<UGString> &strDesFieldNames,
		UGbool bShowProgress = TRUE,
		UGString strTileName = _U(""));

	//! \brief �����ݼ�׷�Ӽ�¼��
	//! \param pSrcRecordset Դ��¼��ָ��[in]��
	//! \return ׷�ӳɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203053017A
	virtual ENGINE_APIF UGbool Append(UGRecordset* pSrcRecordset, 
		UGbool bShowProgress = TRUE,UGString strTileName = _U(""),
		UGArray<UGString> arrSrcFieldNames = UGArray<UGString>(), 
		UGArray<UGString> arrDesFieldNames = UGArray<UGString>());

	//CHENZhao 2009.03.19 ����ʵ�ֵ�Append�壬�ٶ��������ɿ�������
	//! \brief �����ݼ�׷�Ӽ�¼��
	virtual ENGINE_APIF UGbool AppendGeoOnly(UGRecordset* pSrcRcdset);
	//! \brief �����ݼ�׷�Ӽ�¼��
	virtual ENGINE_APIF UGbool AppendNormal(UGRecordset* pSrcRcdset);
	//! \brief �����ݼ�׷�Ӽ�¼������SmID�����ͻ��ɾ��֮ǰ�ġ�
	virtual ENGINE_APIF UGbool AppendWithSmID(UGRecordset* pSrcRcdset);
	//! \brief �����ݼ�׷�Ӽ�¼����ѡ��ͬ�ж�Ӧ��ϵ��
	virtual ENGINE_APIF UGbool AppendFields(UGRecordset* pSrcRcdset, UGStrings& dstFields, UGStrings& srcFields);
	//! \brief �����ݼ�׷�Ӽ�¼,���С��ѷ�����
	virtual ENGINE_APIF UGbool AppendByColumn(UGRecordset* pSrcRcdset, UGStrings& dstFields, UGStrings& srcFields);

	//! \brief �����ݼ���׷����
	//! \param pSrcDataset		Դ���ݼ�
	//! \param strSrcLinkField	Դ���ݼ���Ŀ�����ݼ����������ֶ�
	//! \param strDestLinkField 
	//! \param arrSrcFields		Դ���ݼ�Ҫ׷�ӵ�Ŀ�����ݼ���������
	//! \param arrDestFields	��׷������Ŀ�����ݼ��е�����
	//! \return ׷�ӳɹ�����TRUE��ʧ�ܷ���FALSE
	virtual ENGINE_APIF UGbool AppendFields(UGDatasetVector* pSrcDataset, UGString strSrcLinkField,
		UGString strDestLinkField, UGArray<UGString>& arrSrcFields, 
		UGArray<UGString>& arrDestFields, UGbool bShowProgress = FALSE);
	
	//! \brief ��������ݼ�׷����ʱָ����Դ��Ŀ���ֶ��������Ƿ�Ϸ�
	//! \param pSrcDataset			Դ���ݼ�
	//! \param arrSrcFieldNames		Դ���ݼ�Ҫ׷�ӵ�Ŀ�����ݼ���������
	//! \param arrDesFieldNames		��׷������Ŀ�����ݼ��е�����
	//! \param srcCopyFieldInfos	�õ�Դ���ݼ��кϷ��ֶ���Ϣ
	//! \param desCopyFieldInfos	�õ�Ŀ�����ݼ��кϷ��ֶ���Ϣ
	//! \param arrBinaryFieldIndex	�Ϸ��ֶ��ж������ֶε�����
	//! \return	ָ����Դ��Ŀ���������ϺϷ�����TRUE�����򷵻�FALSE
	virtual ENGINE_APIF UGbool FieldsAppendAble(UGRecordset* pSrcRecordset,
		UGArray<UGString>& arrSrcFieldNames, UGArray<UGString>& arrDesFieldNames, 
		UGFieldInfos& srcCopyFieldInfos, UGFieldInfos& desCopyFieldInfos,	
		UGArray<UGint>& arrBinaryFieldIndex);

	//! \brief ���Դ�ֶ������Ƿ���Ŀ���ֶ���ƥ�䣬��ʸ�����ݼ�׷��ʱʹ��
	//! \brief srcField Դ�ֶ�����
	//! \brief desField Ŀ���ֶ�����
	//! \return ���ؼ����
	virtual ENGINE_APIF UGbool CheckFieldTypeIsMatch(UGFieldInfo::FieldType srcFieldType, 
		UGFieldInfo::FieldType desFieldType);
	
	ENGINE_APIF UGint  GetEventType();
	const ENGINE_APIF UGEventProperty& GetEventProperty();
	ENGINE_APIF void SetEventProperty(const UGEventProperty& EventProperty);


	//! \brief ���ؼ�¼��������
	//! \return ��¼��������
	//##ModelId=482030530199
	virtual ENGINE_APIF UGint GetRecordsetCount();

	//! \brief ͨ����¼������ͷż�¼���ڴ�ռ䡣
	//! \param nIndex ��¼�����[in]��
	//! \return �Ƿ��ͷųɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305301A8
	virtual ENGINE_APIF UGbool ReleaseRecordset(UGint nIndex);
	
	//! \brief ͨ����¼��ָ���ͷż�¼���ڴ�ռ䡣s
	//! \param *pRecordset ��¼��ָ��[in]��
	//! \return �Ƿ��ͷųɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305301AB
	virtual ENGINE_APIF UGbool ReleaseRecordset(UGRecordset *pRecordset);
#if !defined SYMBIAN60 /*&& !defined  OS_ANDROID && !defined (IOS)*/
	//! \brief ȡ�����ݼ���ĳ������Ҫ�ء�
	//! \param nID ���ݼ���¼ID��[in]��
	//! \param pFeature ����Ҫ��ָ��[in|out]�ں����ڷ����ڴ�,���渺��ɾ������������ڴ�й©��
	//! \return �ɹ�����Ture��ʧ�ܷ��� False��
	//##ModelId=48203053012A
	virtual ENGINE_APIF UGbool GetFeature(UGint nID, UGFeature*& pFeature);	

	//! \brief ������Ҫ�ظ��µ����ݼ��С�
	//! \param pFeature ����Ҫ��ָ��[in]��
	//! \return �Ƿ񱣴�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203053012D
	virtual ENGINE_APIF UGbool UpdateFeature(const UGFeature* pFeature);
	
	//! \brief ������Ҫ��׷�ӵ����ݼ�δβ��
	//! \param pFeature ����Ҫ��ָ��[in]��
	//! \return �Ƿ�׷�ӳɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ׷��ʱ����Ҫ�ع��������ݼ���¼ID���������á�
	//##ModelId=482030530139
	virtual ENGINE_APIF UGbool AddFeature(const UGFeature* pFeature);
	
	//! \brief ������Ҫ�ش����ݼ���ɾ����
	//! \param nID ���ݼ���¼ID��[in]��
	//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203053013C
	virtual ENGINE_APIF UGbool DeleteFeature(UGint nID);

	//! \brief ʸ�����ݼ�����������Provider�����Ƿ�֧����ز�ѯ
	virtual UGbool IsSupportQueryType(UGQueryDef::QueryType queryType) const;


#endif

public:

	//! \brief �����ռ�����
	//! \remarks �˷���ֻ�����������Ĳ���������R������,ͼ�������������ĺ���,�����IDXNone
	//!          ��ôĬ���ؽ��Ĳ���������R������
	//##ModelId=482030530261
	virtual ENGINE_APIF UGbool BuildSpatialIndex(UGSpatialIndexInfo  &spatial);
	
	//! \brief ����ռ�����,Ϊû��������״̬
	//##ModelId=482030530268
	virtual ENGINE_APIF UGbool DropSpatialIndex();

	//! \brief ���ݵ�ǰ����״̬�ؽ�����
	//! \param *pDataset [in]��
	//! \return
	//! \remarks
	//! \attention 
	//##ModelId=482030530264
	virtual ENGINE_APIF UGbool ReBuildSpatialIndex();
	
	//! \brief �����ݵĿռ���������
	//! \param *pDataset [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	//##ModelId=482030530266
	virtual ENGINE_APIF UGbool UpdateSpatialIndex();
	
	//! \brief �Ƿ���Ҫ�ؽ��ռ�����
	//! \remarks �涨:���û����������FALSE,�����������������
	//##ModelId=482030530280
	virtual ENGINE_APIF UGbool IsSpatialIndexDirty();

	//! \brief �������ݼ������е�Geometry������㶥�����У����洢Ϊ�������ֶΣ�ϵͳ�ֶΣ������������ݼ��Ķ����������Ϊ"����"
	//! \remarks ��֧�ֶ�ά�桢��ά�����ݼ�
	virtual UGbool ReBuildVertexSeq();

	//! \brief �������ݼ��ж�������ֵΪ�յ�Geometry������㶥�����У����洢�����������ݼ��Ķ����������Ϊ"����"
	//! \remarks ��֧�ֶ�ά�桢��ά�����ݼ�
	virtual UGbool BuildVertexSeq();

	//! \brief ɾ���������к����ݼ�ɾ���洢���������Ķ������ֶΣ����������ݼ��Ķ����������Ϊ"��"
	//! \remarks ��֧�ֶ�ά�桢��ά�����ݼ�
	virtual UGbool DropVertexSeq();

public:

	virtual ENGINE_APIF UGbool CanBeClose();
	//! \brief �������ݼ�����
	//##ModelId=483BB70B00BB
	virtual ENGINE_APIF UGDataset::DatasetType GetType() const;

	//! \brief �������ݼ���ά��
	//##ModelId=48203053008C
	virtual ENGINE_APIF UGint GetDimension();

	//! \brief �������ݼ���(���Ժͱ�����ͬ)
	//##ModelId=48203053009C
	virtual ENGINE_APIF UGString GetName();

	//! \brief �������ݼ���Ӧ����
	//##ModelId=48203053009E
	virtual ENGINE_APIF UGString GetTableName();

	//! \brief �������ݼ���Ӧ�����ݱ������
	//##ModelId=4820305300AB
	ENGINE_APIF void SetTableName(const UGString& strTableName);
	
	//! \brief ��ȡ���ݼ�������Ϣ
	//##ModelId=4820305300AD
	virtual ENGINE_APIF UGString GetDescription() const;

	//! \brief �������ݼ�������Ϣ
	//##ModelId=4820305300BB
	virtual ENGINE_APIF UGbool SetDescription(const UGString& /*strDesc*/);

	//! \brief ��ȡ���ݼ�������Ϣ
	//##ModelId=4820305300AD
	virtual ENGINE_APIF UGString GetExtInfo() const;

	//! \brief �������ݼ�������Ϣ
	//##ModelId=4820305300BB
	virtual ENGINE_APIF UGbool SetExtInfo(const UGString& /*strExtInfo*/);


	//! \brief ������С�߳�
	//##ModelId=4820305300BE
	virtual ENGINE_APIF UGdouble GetMinZ();
	
	//! \brief ������С�߳�
	//##ModelId=4820305300CB
	virtual ENGINE_APIF void SetMinZ(UGdouble d);
	
	//! \brief �������߳�
	//##ModelId=4820305300CE
	virtual ENGINE_APIF UGdouble GetMaxZ();
	
	//! \brief �������߳�
	//##ModelId=4820305300DA
	virtual ENGINE_APIF void SetMaxZ(UGdouble d);
	
	//! \brief �ж��Ƿ���ʸ�����ݼ�
	//##ModelId=4820305300DD
	virtual ENGINE_APIF UGbool IsVector();

	//##ModelId=4820305300EA
	virtual ENGINE_APIF UGbool IsLinkTable();

	//ͨ��ĳЩ�ؼ����ж��Ƿ��Ǿ�̬��ѯ
	//##ModelId=483BB70802FC
	ENGINE_APIF UGbool IsStatisticalQuery(const UGQueryDef& querydef);

	//! \brief �ж��Ƿ���topo���ݼ�
	//##ModelId=4820305300EC
	virtual ENGINE_APIF UGbool IsTopoDataset();

	//! \brief �ж��Ƿ���դ�����ݼ�
	//##ModelId=4820305300EE
	virtual ENGINE_APIF UGbool IsRaster();

	//! \brief �ж��Ƿ�������ʸ�����ݼ�
	//##ModelId=4820305401D4
	virtual ENGINE_APIF UGbool IsWebVector();

	//! \brief �ж��Ƿ��ǹ�ϵ�����ݼ�
	virtual ENGINE_APIF UGbool IsRelClass();

	//! \brief �������ݼ��ķ�Χ
	//##ModelId=4820305300FA
	virtual ENGINE_APIF const UGRect2D& GetBounds();
	
	//! \brief �������ݼ��ķ�Χ
	//##ModelId=4820305300FC
	virtual ENGINE_APIF void SetBounds(const UGRect2D& r);

	//! \brief ֱ�Ӵ��ڴ��з��ض������,�ٶȱȽϿ�,
	//!        �����ܱ�֤��ȷ,ͨ��DatsetInfo��ȡ
	//##ModelId=48203053010E
	virtual ENGINE_APIF UGint GetObjectCountDirectly();
	
	//! \brief �������ݼ��ж������,�ٶ���,��ֵ�Ƚ���ȷ,
	//!        ͨ��Register���ȡ
	//##ModelId=48203053011A
	virtual ENGINE_APIF UGint GetObjectCount();

	//! \brief �������ݼ��ж������,�ٶ���,��ֵ�Ƚ���ȷ,
	//!        ͨ��Register���ȡ
	//##ModelId=48203053011C
	virtual ENGINE_APIF void SetObjectCount(UGint nCount);

	//! \brief ����¼����Register���е��Ƿ�һ�£������һ�»��Զ��޸���
	virtual ENGINE_APIF UGbool CheckObjectCount();

	enum TileIndexStatus{INDEX_TYPE_NOT_MATCH, INDEX_TABLE_NOT_EXIST, INDEX_DATASET_NOT_EXIST};
	//! \brief ���ͼ���������������״̬�����飬Ϊ��˵��û�����⡣
	virtual ENGINE_APIF UGArray<TileIndexStatus> CheckTileIndex();

	//! \brief �õ�δ��ռ�õ��ֶ���
	//##ModelId=4820305301C6
	virtual ENGINE_APIF UGString GetUnoccupiedFieldName(const UGString& strFieldName);

	//! \brief ��ȡʸ�����ݼ���Ϣ
	//! \return UGDatasetVectorInfo *
	//##ModelId=482030530148
	ENGINE_APIF UGDatasetVectorInfo * GetInfo();

	//! \brief �ͷ����м�¼��
	//##ModelId=4820305301B5
	ENGINE_APIF void ReleaseAllRecordsets();

	//! \brief ���ݸ�����ID����ɾ����¼��
	//! \param pIDs ������ID[in]��
	//! \param nCount Ҫɾ����ID�ĸ���[in]��
	//! \return �Ƿ�ɹ�ɾ����
	virtual UGbool DeleteRecords(const UGint* pIDs,UGint nCount);	
	
	//! \brief ������SQL��ѯ��¼����,����Register��
	//##ModelId=4820305301F5
	virtual ENGINE_APIF UGbool ComputeRecCount();

	//CHENZhao ��VAT���õ�������һ�����ݼ�Ϊ�����ݼ�
	//! \brief ����һ�����ݼ�Ϊ�����ݼ�
	virtual ENGINE_APIF UGbool SetIsSub(UGbool isSub);
	//! \brief ���������ݼ���ParentID
	virtual ENGINE_APIF UGbool SetParentID(UGint id);

	//! \brief ɾ�������������ݡ�
	//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��ձ����е��ֶ���Ȼ������
	//##ModelId=482030500131
	virtual ENGINE_APIF UGbool Truncate();


	//! \brief ��ȷ���㾭γ���µ����
	//! \param ������������ֶ�,�����������ᴴ��,����Ѵ���,����Ҫ�ֶ�����ΪDouble,�������ʧ��
	//! \remark �������������ݼ�,��Ϊ��γ������ϵ������,���򷵻�ʧ��
	virtual UGbool CalcGeographicArea(const UGString &strFieldName);

	//! \brief ��ȷ���㾭γ���µĳ���(�����ݼ�Ϊ�ܳ�)
	//! \param ������������ֶ�,�����������ᴴ��,����Ѵ���,����Ҫ�ֶ�����ΪDouble,�������ʧ��
	//! \remark ���������ߺ������ݼ�,��Ϊ��γ������ϵ������,���򷵻�ʧ��
	virtual UGbool CalcGeographicLength(const UGString &strFieldName);


//////////////////////////////////////////////////////////////////////////
//		�������� OGDC �Ļ��������ӵķ���
//////////////////////////////////////////////////////////////////////////
public:
	
	//! \brief  ���ؿռ����ݱ��뷽ʽ
	//##ModelId=482030530109
	virtual ENGINE_APIF UGDataCodec::CodecType GetCodecType();
	
	//! \brief  ���ÿռ����ݱ��뷽ʽ,�������ݼ���ʱ������,��������ݲ��������޸�
	//##ModelId=48203053010B
	virtual ENGINE_APIF UGbool SetCodecType(UGDataCodec::CodecType c);

	//! \brief  �������ݼ���ѡ����Ϣ(�����ֽڵ��������ݴ���һЩ����)
	//##ModelId=482030530128
	virtual ENGINE_APIF UGint GetOptions();

	//! \brief  �ж����ݼ��Ƿ���ĳ��ѡ����Ϣ
	//##ModelId=482030530149
	virtual ENGINE_APIF UGbool HasFlag(UGint nOption) const;

	//! \brief  �������ݼ�������,һ�㲻����ֱ���޸�
	//##ModelId=482030530157
	virtual ENGINE_APIF void SetFlag(UGint nOption,UGbool bHas);

	//! \brief  �Զ���汾��ѯ add by jinagzb
	//! \remarks ֻ֧�־�̬��ѯ
	virtual ENGINE_APIF UGRecordset* CustomVersionQuery(UGint nSeriesID, UGint nLastActionID, const UGQueryDef& querydef);

	//! \brief  ��ѯͨ�����
	//##ModelId=482030530167
	virtual ENGINE_APIF UGRecordset* Query(const UGQueryDef& querydef);

	//! \brief  ������Ա��ѯ
	//##ModelId=48203053016A
	virtual ENGINE_APIF UGRecordset* Query2(UGLinkItem &linkitem);

	//! \brief  ��ȡ���ռ������ֽڴ�С
	//##ModelId=48203053016D
	virtual ENGINE_APIF UGint GetMaxGeoSize();

	//! \brief  �������ռ������ֽڴ�С
	//##ModelId=482030530177
	virtual ENGINE_APIF UGbool SetMaxGeoSize(UGint nMaxGeoSize);


	//! \brief ��ȡ��ǰ���ݼ��е����SMID��Ϣ
	virtual ENGINE_APIF UGint GetMaxID(){return GetObjectCount();};

	//! \breif ��ȡһ���µ�SMID��Դ
	virtual ENGINE_APIF UGint GetNewID(){return GetMaxID() + 1;};

	//! \brief  ��ȡ�����ݼ�ָ��
	//##ModelId=48203053018C
	ENGINE_APIF UGDataset* GetParentDataset() const;

	//! \brief  ��ȡ�����ݼ�ָ��
	//##ModelId=48203053018E
	ENGINE_APIF UGDatasetVector * GetChildDataset() const;

	//! \brief  ���ø����ݼ�ָ��
	//##ModelId=482030530197
	ENGINE_APIF void SetParentDataset(UGDatasetVector* pDatasetVector);

	//! \brief  ����ָ�����������ݼ�ָ��
	//##ModelId=4820305301A5
	virtual ENGINE_APIF UGRecordset* GetRecordsetAt(UGint nIndex);

	//UGSpatialQuery�У�ͨ��OGDC�������Recordset��Ҫ���ݼ�ͳһ����
	UGbool AddRecordset(UGRecordset *pRecordset);

	//! \brief  �õ����ݼ��пռ�������BOUNDS
	//##ModelId=4820305301B6
	ENGINE_APIF UGRect2D GetIndexBounds() const;

	//! \brief  �������ݼ���������BOUNDS
	//##ModelId=4820305301B8
	ENGINE_APIF void SetIndexBounds(const UGRect2D& rc2Bounds);

	//! \brief  �õ�ͼ������ͼ������	
	//##ModelId=4820305301C9
	virtual ENGINE_APIF UGString GetMiniatureDtName();

	//! \brief  �������ݼ��ַ����뷽ʽ
	//##ModelId=4820305301DA
	virtual ENGINE_APIF UGbool SetCharset(UGString::Charset c);
	
	//##ModelId=4820305301E4
	ENGINE_APIF UGbool PJConvert( UGRefTranslator *pRefTranslator );		//ͶӰת��
	//##ModelId=4820305301E6
	ENGINE_APIF UGbool PJForward( UGPrjCoordSys *pPrjCoordSys );			//�������굽ͶӰ����,�ٶ�Datum��ͬ.
	//##ModelId=4820305301E8
	ENGINE_APIF UGbool PJInverse( UGPrjCoordSys *pPrjCoordSys );			//ͶӰ���굽��������,�ٶ�Datum��ͬ.

	//! \brief  ��ȡ�����ļ�����ʱ·��
	//##ModelId=4820305301FB
	ENGINE_APIF UGString GetCacheTempPath() const;

	//! \brief  ���û����ļ�����ʱ·��
	//##ModelId=482030530203
	ENGINE_APIF void SetCacheTempPath(const UGString& strTempPath);

	//! \brief  ���������������
	//##ModelId=482030530205
	virtual ENGINE_APIF UGString GetIndexTableName();

	//! \brief  ���������������
	//##ModelId=482030530207
	ENGINE_APIF void SetIndexTableName(const UGString& strIndexTable);
	
	//! \brief  �����Ƿ��(0.0) 
	//##ModelId=482030530209
	ENGINE_APIF UGbool IsToleranceEmpty() const ;

	//! \brief  ʹ��Ĭ������
	//##ModelId=482030530213
	//CHENZhao 08.12.01 �������������޵ĺ�������ֵ����ΪUGbool
	virtual ENGINE_APIF UGbool SetToleranceToDefault();

	//! \brief  ��������Ϊ��
	//##ModelId=482030530215
	ENGINE_APIF void EmptyTolerance();

	//! \brief  ������С���������ķ�Χ
	//##ModelId=482030530216
	ENGINE_APIF UGbool SetToleranceSmallPolygon(UGdouble dNewValue);

	//! \brief  �õ���С���������ķ�Χ
	//##ModelId=482030530218
	ENGINE_APIF UGdouble GetToleranceSmallPolygon() const ;

	//! \brief  ���ö���������
	//##ModelId=482030530222
	ENGINE_APIF UGbool SetToleranceDangle(UGdouble dNewValue);

	//! \brief  �õ�����������
	//##ModelId=482030530224
	ENGINE_APIF UGdouble GetToleranceDangle() const;

	//! \brief  ���ýڵ�����
	//##ModelId=482030530226
	ENGINE_APIF UGbool SetToleranceNodeSnap(UGdouble dNewValue);

	//! \brief  �õ��ڵ�����
	//##ModelId=482030530228
	ENGINE_APIF UGdouble GetToleranceNodeSnap() const;

	//! \brief  ������������
	//##ModelId=48203053022A
	ENGINE_APIF UGbool SetToleranceGrain(UGdouble dNewValue);

	//! \brief  �õ���������
	//##ModelId=482030530232
	ENGINE_APIF UGdouble GetToleranceGrain() const;

	//! \brief  ���úϲ��ٽڵ�����
	//##ModelId=482030530234
	ENGINE_APIF UGbool SetToleranceExtend(UGdouble dNewValue);

	//! \brief  �õ��ϲ��ٽڵ�����
	//##ModelId=482030530236
	ENGINE_APIF UGdouble GetToleranceExtend() const;
	
	//! \brief  �������ݼ���ѡ����Ϣ
	//##ModelId=482030530238
	ENGINE_APIF void SetOptions(UGint nOptions);
#if !defined SYMBIAN60 /*&& !defined  OS_ANDROID && !defined (IOS)*/
	//added by xielin 2007-05-23 
	//##ModelId=48203053023A
	//! \brief  �������ݼ���ѡ����Ϣ
	void RegisterToDataset(UGDataHistory* pDataHistory);
	//##ModelId=482030530242
	//! \brief  �������ݼ���ѡ����Ϣ
	void UnRegisterFromDataset(UGDataHistory* pDataHistory);
#endif

	//! \brief  ���������topo ���Ի��topo���ݼ�ָ��
	//##ModelId=482030530244
	virtual ENGINE_APIF UGDataset * GetTopoAdscriptionDT();

	//! \brief  For Tin ���ݼ�
	//##ModelId=482030530246
	virtual ENGINE_APIF UGbool CreateSubDataset(UGDatasetVectorInfo & vInfo);

	//! \brief ͨ�������ݼ�����ɾ�������ݼ�
	//##ModelId=482030530249
	virtual ENGINE_APIF UGbool DeleteSubDataset(UGString &strName);

	//! \brief ͨ����ʵ��ȣ����豸��ȣ���������ʾTin����������һ������
	//##ModelId=48203053024C
	ENGINE_APIF UGDatasetVector * GetTinLayer(UGint nWidth,UGint nDeviceWidth);
#if !defined SYMBIAN60 /*&& !defined  OS_ANDROID */
	//! \brief ��ȡR��
	//##ModelId=483BB70B0157
	UGDBRTree* GetDBRTree();
#endif
	//! \brief ��ѯ���ͼ����һ��ͼ��������
	//! \param nLibTileID [in]��
	//! \param arFields [in]��
	//! \param dGranule [in]��
	//! \return UGRecordset
	//! \remarks ���dGraunle<=0����ô�Ͳ����ù��˷�ʽ,��֮����
	//! \attention ��
	//##ModelId=48203053026A
	virtual ENGINE_APIF UGRecordset* QueryWithLibTileID(UGint nLibTileID,
		UGArray<UGString> & arFields,UGdouble dGranule);

	//! \brief ͨ�����η�Χ��ѯͼ�����
	//! \param rc2Bounds [in]��
	//! \param arLibTileIDs [out]��
	//! \return UGbool
	//! \remarks ��
	//! \attention ��
	//##ModelId=482030530274
	virtual ENGINE_APIF UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
		UGArray<UGint>& arLibTileIDs);
	
	//! \brief �õ�һ��ͼ������Ϣ
	//! \param nTileID [in]��
	//! \param rc2TileBounds [out]��
	//! \param nRecCount [out]��
	//! \param nVersion [out]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	//##ModelId=482030530278
	virtual ENGINE_APIF UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
		UGint& nRecCount,UGint& nVersion);

	//SpatialIndex��Ҫ�õ��ķ���
	//! \brief �����ݿ��ж�ȡ��ǰ���ݼ���Bounds��Ϣ
	//! \remarks �˺�����CDatasetVector::GetBounds�������𣬴˺����Ǵ����ݿ��ж�ȡ���õ��������µ�Bounds����������ֱ�Ӵ��ڴ��ж�ȡm_DatasetInfo�д洢��Bounds��Ϣ���ٶ�Ҫ��ö�
	//! \sa	CDatasetVector::GetBounds
	//##ModelId=483BB70B015E
 	virtual ENGINE_APIF UGRect2D GetBoundsDirectly();

	//! \brief ���ſռ���������
	//! \param nOption	   ��ѯѡ��[in]
	//! \param dbTolerance ����[in]
	//! \param pGeo        ��ѯ��Χ����[in]
	//! \param aryInnerIDs �����ڲ�ѯ��Χ�ڵĶ���ID[out]
	//! \param aryOuterIDs �����ڲ�ѯ��Χ��Ķ���ID[out]
	//! \param aryMaybeIDs �������ѯ��Χ�ཻ�Ķ���ID[out]
	//! \return
	//! \remarks
	//! \attention
	ENGINE_APIF UGbool IndexbagQuery(SpatialQueryOption nOption,UGdouble dbTolerance,UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,UGArray<UGint> &aryOuterIDs,UGMaybeItems &aryMaybeItems);
	//! \brief �ж�׷��ʱ�ǲ������Ա�����
	//! \param Ŀ�����ݼ�
	//! \param Դ��¼��
	virtual ENGINE_APIF UGbool TabularAppendMatch(UGDatasetVector* dst, UGRecordset* src);

	UGSpatialIndex* GetSpaitalIndexObect(){return m_pSpatialIndex;};

	//! \brief ���㼫ֵ
	//! \param strExpression		��ѯ���ֶα��ʽ[in]
	//! \param JoinItems			��ѯ���ⲿ��������[in]
	//! \param bIsSupportNegative	�Ƿ�֧�ָ�ֵ[in]
	//! \param dMinSum				��ѯ����Сֵ[in/out]
	//! \param dMaxSum				��ѯ�����ֵ[in/out]
	//! \remarks ����ά�м����ֶμ�ֵ�����ýӿڣ��ŵ�Engine�������
	UGbool CalculateExtremum(const UGArray<UGString>& strExpression,const UGArray<UGJoinItem>& JoinItems,UGbool bIsSupportNegative,UGdouble& dMinSum,UGdouble& dMaxSum);

	//! \brief �����޸����ݼ���Ļص�������ַ
	void SetAffterDatasetModifiedFunction(AffterDatasetModifiedProc pffterDatasetModifiedProc,void* pLayerDataset);

	//! \brief ��ȡ�޸����ݼ���Ļص�������ַ
    AffterDatasetModifiedProc GetAffterDatasetModifiedFunction();

	//\brief ��ȡ�ص��������õ����ݼ�ͼ��ĵ�ַ
	void* GetLayerDatasetPointer();
	//! \brief ͨ���������дֲ�ѯ
	//! \param *pBounds ��ѯbounds[in]
	//! \param aryInnerIDs ����bounds��Χ�ڵĶ���id����[out]
	//! \param aryMaybeItems ��bounds�ཻ�Ķ����id����[out]
	//! \param aryOuterIDs ����bounds��Ķ����id���� [out]
	//! \param bNeedOuterIDs �Ƿ񷵻�����bounds��Ķ����id����[in]
	//! \param dbTolerance ����[in]
	virtual ENGINE_APIF UGbool QueryBySpatialIndex(UGGeoRegion& geoRegion,
		UGArray<UGint>& aryInnerIDs,UGArray<UGint>& aryMaybeIDs,
		UGArray<UGint>& aryOuterIDs,UGbool bNeedOuterIDs);
protected:
	//! brief ��ʼ���ռ���������
	//##ModelId=483BB70B0160
	virtual ENGINE_APIF UGbool InitSpatialIndex();

	//!brief ˢ�����ݼ���ѡ����Ϣ
	virtual ENGINE_APIF UGbool RefreshOption();

	//! \brief ͼ�������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeItems	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
    virtual ENGINE_APIF UGbool LibTileSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeItems,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption, 
		UGdouble dbTolerance);
	
	//! \brief R�������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeItems	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	virtual ENGINE_APIF UGbool RTreeSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeItems,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption,
		UGdouble dbTolerance);
	
	//! \brief �༶���������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeItems	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	//! \remarks pGeoΪ��ά����ʱ��aryInnerIDs�Ǳ�pGeo��ȫ�����Ķ���ID��aryMaybeIDs����pGeo�ཻ��ID����ϵ��Ҫ��һ���жϣ�aryOuterIDs��һ����pGe�ⲿ�Ķ���ID
	//!          pGeoΪһά����ʱ��aryInnerIDsΪ�գ�aryMaybeIDs����pGeo�ཻ��ID����ϵ��Ҫ��һ���жϣ�aryOuterIDs����pGeoû�н������ID
	//!          pGeoΪ��ά����ʱ��aryInnerIDsΪ�գ�aryMaybeIDs�ǵ����ڶ���Χ�ڵĶ���ID��aryOuterIDs�ǵ����ڶ���Χ��Ķ���ID
	virtual ENGINE_APIF UGbool DynamicSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeItems,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption, 
		UGdouble dbTolerance);
public:
	//! \brief  �Ż�����¼���Ż�����
	//##ModelId=482030530285
	UGint m_nOptimizeCount;
	//! \brief  �Ż�������Ż�����
	//##ModelId=482030530286
	UGdouble m_dOptimizeRatio;
	//! \brief  ���ռ������ֽڴ�С
	//##ModelId=482030530290
	UGint m_nMaxGeometrySize;
	//! \brief  �����ŵ��ֽڴ�С
	//##ModelId=482030530291
	UGint m_nMaxSymbolSize;
	//! \brief  ���ݼ��������ݼ�ָ��
	//##ModelId=482030530292
	UGSubDtArray m_arySubDataset;
	//! \brief  ʸ�����ݼ���Ϣ
	//##ModelId=482030530293
	UGDatasetVectorInfo m_DatasetInfo;
	//! \brief  TIN���ݼ������ݼ�ָ��

	//! \brief  ���ݼ�������ѯ���ⲿ����Դ
	//##ModelId=482030530294
	UGArray<UGDataSource *> m_aryLinkDatasource;

	UGEventProperty* m_pEventProperty; 
protected:
	//! \brief ��¼��ָ��ļ��ϣ��򿪵����м�¼������������
	//!        ����֪����ô�ͷ�
	//##ModelId=482030530295
	UGArray<UGRecordset*> m_Recordsets;
	//! \brief �����ļ�����ʱ·��
	//##ModelId=48203053029F
	UGString m_strCacheTempPath;

	//! \brief �����ݼ���ָ��
	//##ModelId=4820305302A1
	UGDataset * m_pParentDataset;

	//! \brief �����������
	//##ModelId=4820305302AF
	UGString m_strIndexTable;

	//added by xielin 2007-05-22
	//##ModelId=4820305302B0
	UGArray<ValidDataHistory> m_aryValidDataHistory;

	//##ModelId=4820305302B2
	UGSpatialIndex* m_pSpatialIndex;

	AffterDatasetModifiedProc ms_pAffterDatasetModifiedProc;

	void* m_pLayerDataset;
};

}

#endif

