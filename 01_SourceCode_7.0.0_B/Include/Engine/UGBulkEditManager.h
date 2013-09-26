#ifndef SUPERMAP_ENGINE_UGBuldEditManager_H
#define SUPERMAP_ENGINE_UGBuldEditManager_H

#include "Engine/UGRecordset.h"
#include "Geometry/UGFeature.h"

namespace UGC
{
class UGRecordset;

struct UGBinaryFieldInfo
{
public:
	UGBinaryFieldInfo()
	{
		pData = NULL;
		nSize = 0;
	};

	~UGBinaryFieldInfo()
	{
		if (pData!= NULL)
		{
			delete[] pData;
			pData = NULL;
		}

		nSize =0;
	};

public:

	UGbyte *pData;
	UGuint nSize;
};

struct UGBulkAddInfo

{
	UGbool bHasStyle;
	UGbool bBigGeo;		
	UGint  nSMID;		
	UGint  nGeoSize;

	//����ǵȳ��洢����ֵΪ0��
	//���ȳ�ʱ����ֵΪgeometry��m_pBulkGeoBuffer��ƫ������
	//����Ǵ�����ֵΪ��m_arrBigGeoData��������
	UGint  nGeoOffset;
	UGint  nGeoType;

	//����ǵȳ��洢����ֵΪ0��
	//���ȳ�ʱ����ֵΪ������¼������ֵ��m_pBulkAttrBuffer��ƫ������
	UGint  nAttrOffset;
	UGint  nAttrSize;

};

struct UGModifyFieldInfo
{
public:
	UGString m_strFieldName;
	UGVariant m_newValue;
};

struct UGModifyGeoInfo
{
public:
	UGModifyGeoInfo()
	{
		m_pNewGeometry = NULL;
		m_nOldIndex = 0;
	};
	virtual ~UGModifyGeoInfo() 
	{
		if (m_pNewGeometry!= NULL)
		{
			delete m_pNewGeometry;
			m_pNewGeometry = NULL;	
		}				
	};

public:
	UGGeometry* m_pNewGeometry;
	UGRect2D m_oldBounds;
	UGint m_nOldIndex;
};

struct UGModifyInfo
{
public:
	UGModifyInfo()
	{
		m_SMID = -1;
		m_pModifyGeoInfo = NULL;
		m_arrModifyFieldInfos.SetSize(0);
	};
	~UGModifyInfo()
	{		
		if (m_pModifyGeoInfo != NULL)
		{
			delete m_pModifyGeoInfo;
			m_pModifyGeoInfo = NULL;
		}			

		for (UGint i = 0; i < m_arrModifyFieldInfos.GetSize(); ++i)
		{
			delete m_arrModifyFieldInfos[i];				
			m_arrModifyFieldInfos[i] = NULL;
		}

		m_arrModifyFieldInfos.RemoveAll();
	};

public:
	UGint m_SMID;			
	UGModifyGeoInfo * m_pModifyGeoInfo;
	UGArray<UGModifyFieldInfo*> m_arrModifyFieldInfos;
};

class ENGINE_API UGBulkEditManager
{
	friend class UGRecordset;

public:
	UGBulkEditManager(UGRecordset * pRecordset);
	virtual ~UGBulkEditManager();


	virtual UGbool Init();		 
	//���ָ����pFeature
	virtual UGint AddOneFeature(UGFeature * pFeature);

	//���һ��Ĭ�ϵ�pFeature
	virtual UGFeature* AddOneFeature();

	virtual UGbool Delete();

	virtual UGbool SetFieldValue(const UGString &strFieldName,const UGVariant &varValue);

	virtual UGbool SetGeometry(UGGeometry *pGeometry);


	virtual UGbool GetFieldValue(const UGString &strFieldName,UGVariant &varValue);

	virtual UGbool GetGeometry(UGGeometry *&pGeometry);

	virtual UGint GetID();

	virtual UGbool Update(void);

	virtual UGbool CancelUpdate(void);

	virtual void SetBulkEditMaxCount(UGuint nMaxCount){m_nBulkEditMaxCount = nMaxCount;};

	virtual UGuint GetBulkEditMaxCount(void){return m_nBulkEditMaxCount;};

	virtual void SetSmIDBegin(UGuint nSmIDBegin){m_nSmIDBegin = nSmIDBegin;};

	virtual UGint SetOneFeature(UGGeometry *pGeometry, UGbool bModifyGeometry, const UGArray<UGString> &aryFields, const UGArray<UGVariant> &aryValues);

	virtual UGuint GetSmIDBegin(){return m_nSmIDBegin;};

	//����ӵ�Features�в����ƶ���nSMID��¼
	//����CurrentIndex����ǰnSmID���ڵļ�¼��
	virtual UGbool SeekID(UGint nSMID);

	virtual void Clear(UGbool bFree);

	virtual UGint GetCurrentIndex();

	virtual UGbool SetCurrentIndex(UGint nCurrentIndx);	

	virtual UGint GetFieldDataSize(const UGFieldInfo &fieldInfo);

	virtual UGint GetFieldDataSize(const UGFieldDefine &fieldInfo);
	
	virtual UGbool FillFieldData(UGint nIndex, UGint nFieldIndex, UGbool bFind,const UGVariant &varVal);

	//��pGeometry�����ݴ�����ƶ���λ��pPos,������ݳ��ȴ���m_nGeoSize��ֱ�ӷ���false
	virtual UGbool FillGeoData(UGint nIndex,const UGGeometry* pGeometry, UGBulkAddInfo *pBulkAddInfo);

	//�÷�����ȡ����ӵ�geometry��geoBuffer�д洢����ʼλ��
	//����ǵȳ��ģ����ΪnIndex * m_nGeoSize
	//����ǲ��ȳ��ģ��㷨�ɸ������Լ�����������udb����m_nBulkGeoBufferSize - m_nBulkGeoLeft
	virtual UGint GetGeoOffset(UGint nIndex);	

protected:		
	void Check();
	virtual UGint  GetActualRecordCount();
	virtual UGbool PreSysFieldInfos();
	virtual UGbool FillSystemFieldData(UGint nIndex,UGGeometry *pGeometry,UGint nSMID);	

	virtual UGbool AddBounds(UGint nIndex,const UGGeometry *pGeometry);

	//nIndex����m_arrBulkAddInfos�е�������
	//nFieldIndex : ��m_FieldInfos�е�������
	//varValue:�µ��ֶ�ֵ
	virtual UGbool SetFieldValue(UGint nIndex,UGint nFieldIndex,const UGVariant &varValue);
	virtual UGbool GetFieldValue(UGint nIndex,UGint nFieldIndex,UGVariant &varValue);
	virtual UGbool GetFieldValue(UGVariant &varValue,UGbyte *pData,const UGFieldInfo &fieldInfo);

	virtual UGbool GetDefaultValue(UGFieldInfo &fieldInfo, UGVariant &varValue);
	
	virtual UGbool SetGeometry(UGint nIndex,UGGeometry *pGeometry);
	virtual UGbool GetGeometry(UGGeometry *&pGeometry,UGint nIndex);

	virtual UGbool InitBulkBuffer();

	UGint GetFieldIndex(const UGString &strFieldName);
	virtual UGbool AddFieldInfo(const UGString & strFieldName);
	virtual UGbool AddFieldInfo(const UGFieldInfo &fieldInfo);	

protected:
	UGArray<UGFeature *> m_arrFeatures;

	UGRecordset *m_pRecordset;

	UGuint m_nBulkEditMaxCount;

	UGuint m_nSmIDBegin;

	UGArray<UGint> m_arrDeleteIDs;

	UGArray<UGModifyInfo*> m_arrModifyInfos;

	UGint m_nCurrentEditCount;

	UGint m_nMaxGeoSize;

	UGbyte* m_pBulkGeoBuffer;
	UGbyte* m_pBulkAttrBuffer;
	UGuint m_nBulkGeoBufferSize;
	UGuint m_nBulkAttrBufferSize;
	UGshort * m_pBulkIndicators;
	UGuint m_nBulkIndsSize;
		 

	//��¼ÿ���ֶε�ƫ�ƣ�˳Ѱ�ͼ�¼�����ֶε�˳��һ��
	UGArray<UGint> m_arrFieldOffset;

	//ÿ����¼���Եĳ���
	UGint m_nAttributeSize;

	//Ϊÿ��Geometry����Ŀռ�
	UGint m_nGeoSize;

	//������Ӷ�Ӧ���ֶ���Ϣ
	UGFieldInfos m_FieldInfos;

	UGDict<UGString,UGint> m_dictFieldIndexes;

	//������ӹ���������ӵĶ���ķ�Χ
	UGRect2D m_newBulkBounds;

	//����Ƿ�ʹ����ҪGeometry
	UGbool m_bHasGeometry;

	//�洢�����
	UGArray<UGbyte *> m_arrBigGeoData;

	UGArray<UGBulkAddInfo*> m_arrBulkAddInfos;

	UGint m_nBulkAddIndex;

	//���bulkAddInfos�и����ζ���ķ�Χ��Ϊά���ռ�����ʱʹ��
	UGArray<UGRect2D> m_arrBulkAddBounds;

	//����Ƕ�̬��������������ÿ��geometry��
	UGArray<UGArray<UGPoint> *> m_arrBulkAddGrids;

	UGuint m_nHasSetFieldCount;


	UGArray<UGint> m_arrBulkAddFieldIndex;
	

	//��һ��UGint ΪSMID,�ڶ���UGintΪFieldIndex
	UGDict<UGint,UGDict<UGint,UGBinaryFieldInfo* >* > m_dictBinaryFields;

	
public:
	UGFeature * m_pTemplateFeature;

};



}

#endif