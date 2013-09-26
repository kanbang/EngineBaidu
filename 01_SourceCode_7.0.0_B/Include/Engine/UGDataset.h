/*! \file	 UGDataset.h
 *  \brief	 ���ݼ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDataset.h,v 1.32 2010/04/16 01:53:52 zhangshuo Exp $
 */

#ifndef UGDATASET_H
#define UGDATASET_H

#include "Geometry/UGDataCodec.h"
#include "Engine/ugeng.h"
#include "Engine/UGEngDefs.h"
#include "Engine/UGDDRRelation.h"
#include "Toolkit/UGProgress.h"
#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined (IOS)
#include "OGDC/OgdcDataset.h"
#endif
namespace UGC {

class UGDataSource;

//! \brief ���ݼ�����
//##ModelId=482030550251
#ifdef SYMBIAN60
class ENGINE_APIC UGDataset
#else
class ENGINE_API UGDataset
#endif  
{
	friend class UGDDRMasterDynSeg;
	friend class UGSpatialIndex;
	friend class UGDynSegInfo;


public:
	//! \brief ���ݼ�����,����Դ��IsSupport����������ϸ֧��˵��
	//##ModelId=4820305502EE
	enum DatasetType
	{
		//##ModelId=483BB70C0242
		UnKnown		=-1,
		//##ModelId=4820305502F0
		Tabular		=0,		//! ֻ�����Ա�û�м��ζ���
		//##ModelId=4820305502FD
		Point		=1,		//! �����ݼ�
		//##ModelId=4820305502FE
		Line		=3,		//! �����ݼ�
		//##ModelId=4820305502FF
		Network		=4,		//! �������ݼ�
		//##ModelId=48203055030D
		Region		=5,		//! ��������ݼ�
		//##ModelId=48203055030E
		Text		=7,		//! �ı����ݼ�
		//##ModelId=48203055030E
		ParametricLine = 8,   //! �����������ݼ�
		//##ModelId=48203055030E
		ParametricRegion = 9, //! �����������ݼ�
		//##ModelId=48203055030F
		LineM		=35,	//! ·�����ݼ�
		//##ModelId=482030550310
		Image		=81,	//! Ӱ��
		//##ModelId=48203055031C
		MrSID		=82,	//! MrSID
		//##ModelId=48203055031D
		Grid		=83,	//! դ��
		//##ModelId=48203055031E
		DEM			=84,	//! DEM
		//##ModelId=48203055032C
		ECW			=85,	//! ECW
		//##ModelId=48203055032D
		WMS			=86,	//! WMS	
		//##ModelId=48203055032E
		WCS			=87,	//! WCS
	    
		MBImage     =88,    //! MultiBand Image
        MBGrid      =89,    //! MultiBand Grid
		MBDEM		=90,    //! MultiBand DEM
		//##ModelId=48203055033C
		PointZ		=101,	//! ��ά��
		//##ModelId=48203055033D
		LineZ		=103,	//! ��ά��
		//##ModelId=48203055033E
		RegionZ		=105,	//! ��ά��
		//##ModelId=48203055033F
		PointGL		=137,	//! ����������Point3D
		//##ModelId=48203055034B
		TIN			=139,	//! TIN���ݼ�
		//##ModelId=48203055034C
		CAD			=149,	//! CAD���ݼ�
		
		//##ModelId=48203055034D
		WFS			=151,	//! WFS
		//##ModelId=48203055035B
		LinkTable	=153,	//! ���ݿ��,ֻ������
		//##ModelId=48203055035C
		Topo		=154,	//! Topo���ݼ�
		//##ModelId=48203055035D
		TIN2		=155,	//! �µ�Tin���ݺ���ǰ�����ֿ�
		RelClass	=156, 	//! ��ϵ�����ݼ�

		GridCollection    =199,
		ImageCollection    =200,

		VectorCollection    =201,//ʸ�����ݼ���
		RasterCollection    =202,//դ�����ݼ���
	}; 

	//##ModelId=48203055036B
	enum DatasetOption
	{
		//##ModelId=48203055036D
		Default		= 0x00000000,	//! Ĭ��ѡ�� 
		//##ModelId=48203055036E
		HasStyle	= 0x00000001,	//! ���֧�� 
		//{{2007.7.15 ri�Ժ��ֹӦ��
		//##ModelId=48203055037A
		Zip			= 0x00000002,	//! Zipѹ���洢 
		//}}
		//##ModelId=48203055037B
		Pyramid     = 0x00000004,	//! ֧��Ӱ��������洢 
		//##ModelId=48203055037C
//		Sequence	= 0x00000008,	//! ֧��ʱ��洢 
		//##ModelId=48203055037D
		MemCache	= 0x00000010,	//! ֧���ڴ滺��ģʽ 
		//##ModelId=48203055038A
//		LongTrans	= 0x00000020,	//! ֧�ֳ�������� 
		//##ModelId=48203055038B
//		UserLock	= 0x00000040,	//! ֧���û����� 
		//##ModelId=48203055038C
		CacheMode	= 0x00000080,	//! ֧�ֱ��ػ���ģʽ 
		//{{2007.7.15 ri�Ժ��ֹӦ��
		//##ModelId=48203055038D
		Library		= 0x00010000,	//! ֧�ֵ���ͼ��ģʽ 
		//}}
		//##ModelId=482030550399
		ReadOnly	= 0x00020000,	//! ֻ�� 
//		ע����SFC����
//		DataVersion = 0x00040000,	//! �汾���� 
		//##ModelId=48203055039A
//		DataVersion = 0x00100000,
		//##ModelId=48203055039B
		TopoAdscription = 0x00080000, //! topo ���� 
//		CacheIndex		= 0x00100000 //! ��̬�������� 
		//CHARSET		((nOptions & 0x0000ff00 ) >> 8)
		//! \brief �汾����
		Version		= 0x00100000,	
		//! \brief ��������
		Duplication	= 0x00200000,	

		//! \brief �����������ã��޶���������Option&0x00f00000 != 0x00400000 && Option&0x00f00000 != 0x00800000��
		VertexIndexAvailable= 0x00400000,
		//! \brief ���������ࣨ�޶���������Option&0x00f00000 != 0x00400000 && Option&0x00f00000 != 0x00800000��
		VertexIndexDirty    = 0x00800000,
	};

	enum CollectionState
	{
		//����
		normal = 1,
			
		//�Ѿ���ɾ��,
		deleted = 2,
			
		//ͶӰ����ͬ
		projectionError = 3,

		//�ֶ������ݼ����ϲ���
		fieldError = 4,
		
		//���ظ�ʽ��ͬ
		pixelError = 5,

		//ͶӰ���ֶζ���ͬ
		projectionAndField = 11,

		//ͶӰ�����ض���ͬ
		projectionAndPixel = 12,
			
	};

	typedef struct UGDatasetState
	{
		CollectionState eumState;
		UGString strName;
		UGDatasetState()
		{
			eumState = normal;
			strName = _U("");
		}

	}UGDatasetState;


public:
	//! \brief ���캯��
	//##ModelId=482030550252
	ENGINE_APIF UGDataset();
	
	//! \brief ��������
	//##ModelId=482030550253
	virtual ENGINE_APIF ~UGDataset();

public:
	//! \brief �������ݼ���ӦA�����
	//##ModelId=482030550272
	virtual ENGINE_APIF UGString GetATableName();
	
	//! \brief �������ݼ���ӦD�����
	//##ModelId=482030550272
	virtual ENGINE_APIF UGString GetDTableName();

	//! \brief �������ݼ�����
	//##ModelId=482030550265
	virtual ENGINE_APIF UGDataset::DatasetType GetType() const = 0;
	
	//! \brief �������ݼ���(���Ժͱ�����ͬ)
	//##ModelId=48203055026B
	virtual ENGINE_APIF UGString GetName() = 0;
	
	//! \brief �������ݼ���Ӧ����
	//##ModelId=482030550272
	virtual ENGINE_APIF UGString GetTableName() = 0;
	//! \brief ������С�߳�
	//##ModelId=482030550277
	virtual ENGINE_APIF UGdouble GetMinZ() = 0;

	//! \brief ������С�߳�
	//##ModelId=482030550279
	virtual ENGINE_APIF void SetMinZ(UGdouble d) = 0;

	//! \brief �������߳�
	//##ModelId=48203055027C
	virtual ENGINE_APIF UGdouble GetMaxZ() = 0;

	//! \brief �������߳�
	//##ModelId=482030550281
	virtual ENGINE_APIF void SetMaxZ(UGdouble d) = 0;

	//! \brief �������ݼ���ά��
	//##ModelId=482030550284
	virtual ENGINE_APIF UGint GetDimension() = 0;

	//! \brief �ж��Ƿ���ʸ�����ݼ�
	//##ModelId=482030550286
	virtual ENGINE_APIF UGbool IsVector() = 0;

	//! \brief �ж��Ƿ���Topo���ݼ�
	//##ModelId=482030550288
	virtual ENGINE_APIF UGbool IsTopoDataset() = 0;

	//! \brief �ж��Ƿ���դ�����ݼ�
	//##ModelId=48203055028A
	virtual ENGINE_APIF UGbool IsRaster() = 0;

	//! \brief �ж��Ƿ��ǹ�ϵ�����ݼ�
	virtual ENGINE_APIF UGbool IsRelClass() = 0;

	virtual ENGINE_APIF UGbool IsMBRaster();

	//##ModelId=48203055028C
	virtual ENGINE_APIF UGbool IsLinkTable() = 0;

	//! \brief �������ݼ��ķ�Χ
	//##ModelId=482030550291
	virtual ENGINE_APIF const UGRect2D& GetBounds() = 0;

	//! \brief �������ݼ��ķ�Χ
	//##ModelId=482030550293
	virtual ENGINE_APIF void SetBounds(const UGRect2D& r) = 0;

	//! \brief ���ؿռ����ݱ��뷽ʽ
	//##ModelId=482030550296
	virtual ENGINE_APIF UGDataCodec::CodecType GetCodecType() = 0;
	
	//! \brief ���ÿռ����ݱ��뷽ʽ
	//##ModelId=482030550298
	virtual ENGINE_APIF UGbool SetCodecType(UGDataCodec::CodecType c) = 0;

	//! \brief �������ݼ���ѡ����Ϣ(�����ֽڵ��������ݴ���һЩ����)
	//##ModelId=48203055029B
	virtual ENGINE_APIF UGint GetOptions() = 0;
#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined (IOS)
public:
	//##ModelId=483BB70C01D6
	static UGDataset* FromOgdcDataset(OgdcDataset* pOgdcDt, const UGDataSource* pDS);

	//##ModelId=483BB70C01E7
	static OgdcDataset* ToOgdcDataset(UGDataset* pDt);
#endif

public:
	//! \brief �����ݼ�
	//##ModelId=482030550261
	virtual ENGINE_APIF UGbool Open();

	//! \brief �ڶ��߳��������жϹرյ�ǰ���ݼ��Ƿ�ȫ��ʸ����Ҫ�����Ƿ��д򿪵ļ�¼����դ����Ҫ�����Ƿ�����ͷ��������ݿ�
	virtual ENGINE_APIF UGbool CanBeClose();

	//! \brief �ر����ݼ�
	//##ModelId=482030550263
	virtual ENGINE_APIF void Close();

	//! \brief ����������ʱ��
	//##ModelId=482030550267
	virtual ENGINE_APIF UGTime GetDateLastUpdated();

	//! \brief ���ش���ʱ��
	//##ModelId=482030550269
	virtual ENGINE_APIF UGTime GetDateCreated();
	
	//! \brief ���ݼ�������,ֻ�ı����ݼ���,��������
	//##ModelId=482030550274
	virtual ENGINE_APIF UGbool Rename(const UGString& strNewName);

	//! \brief �������ݼ���Ϣ
	//##ModelId=48203055029F
	virtual ENGINE_APIF UGbool SaveInfo();
	
	//! \brief ˢ�����ݼ���Ϣ
	//##ModelId=4820305502A1
	virtual ENGINE_APIF UGbool RefreshInfo();	
	
	//! \brief �������ݼ���ID
	//##ModelId=4820305502A3
	ENGINE_APIF UGint GetID() const;

	//! \brief �������ݼ���ID
	//##ModelId=4820305502A5
	ENGINE_APIF void SetID(UGint nID);

	//##ModelId=4820305502A7
	ENGINE_APIF UGString GetSchema() const;

	//! \brief ��������Դָ��
	//##ModelId=4820305502A9
	ENGINE_APIF UGDataSource* GetDataSource() const;

	//! \brief ��������Դָ��
	//##ModelId=4820305502AB
	ENGINE_APIF void SetDataSource(UGDataSource* pDs);

	//##ModelId=4820305502B0
	ENGINE_APIF UGbool IsModified() const;
	
	//##ModelId=4820305502B2
	ENGINE_APIF void SetModifiedFlag(UGbool bModified = TRUE);

	//! \brief �ж����ݼ��Ƿ��Ѿ���
	//##ModelId=4820305502B4
	virtual ENGINE_APIF UGbool IsOpen() const;

	//! \brief �������ݼ���Χ,һ�������ݼ���Ԫ�ر�ɾ�����޸ĺ�ʹ��,
	//!        ���ܺķѽ϶�ʱ��
	//##ModelId=4820305502B6
	virtual ENGINE_APIF UGbool ComputeBounds();

	//! \brief ֱ�Ӵ��ڴ��з��ض������,�ٶȱȽϿ�,
	//!        �����ܱ�֤��ȷ,ͨ��DatsetInfo��ȡ
	//##ModelId=4820305502B8
	virtual ENGINE_APIF UGint GetObjectCountDirectly();

	//! \brief �������ݼ��ж������,�ٶ���,��ֵ�Ƚ���ȷ,
	//!        ͨ��Register���ȡ
	//##ModelId=4820305502BA
	virtual ENGINE_APIF UGint GetObjectCount();

	//! \brief ��ȡ���ݼ�ռ�õ�Ӳ�̿ռ�
	//##ModelId=4820305502BC
	virtual ENGINE_APIF UGint GetStoredSpace();

	//! \brief ��ȡ���ݼ�������Ϣ
	//##ModelId=4820305502C0
	virtual ENGINE_APIF UGString GetDescription() const;

	//! \brief �������ݼ�������Ϣ
	//##ModelId=4820305502C2
	virtual ENGINE_APIF UGbool SetDescription(const UGString& /*strDesc*/);

	//! \brief ��ȡ���ݼ�������Ϣ
	//##ModelId=4820305502C0
	virtual ENGINE_APIF UGString GetExtInfo() const;

	//! \brief �������ݼ�������Ϣ
	//##ModelId=4820305502C2
	virtual ENGINE_APIF UGbool SetExtInfo(const UGString& /*strExtInfo*/);
	
	//! \brief �жϵ�ǰ���ݼ��Ƿ�ɱ༭
	//##ModelId=4820305502C5
	virtual ENGINE_APIF UGbool CanUpdate();
	
	//! \brief ע��ѡ����Ϣ
	//##ModelId=4820305502C7
	virtual ENGINE_APIF UGbool RegisterOption(UGint /*nOption*/);

	//! \brief ��ע��ѡ����Ϣ
	//##ModelId=4820305502CA
	virtual ENGINE_APIF UGbool UnRegisterOption(UGint /*nOption*/);
	
	//! \brief �ж����ݼ��Ƿ���ĳ��ѡ����Ϣ
	//##ModelId=4820305502CD
	virtual ENGINE_APIF UGbool HasFlag(UGint /*nOption*/) const;
	
	//! \brief ���ݼ��Ƿ���ĳ��ģʽ�Ĳ���������
	//##ModelId=4820305502D0
	virtual ENGINE_APIF UGbool HasAbility(UGEngAbility /*dwEngAbility*/) {return FALSE;}
	
	//! \brief �ж����ݼ��Ƿ�֧��ĳ�ֲ���
	//##ModelId=4820305502D3
	virtual ENGINE_APIF UGbool IsSupport(UGEngAction /*nAction*/) {return FALSE;}	
	
	//##ModelId=483BB70C0205
	virtual ENGINE_APIF UGbool SetPrjCoordSys(const UGPrjCoordSys &PrjCoordSys);
	
	//========================================================
	//! \brief 		��ȡ����Դ��ͶӰ��Ϣ
	//! \return 	UGPrjCoordSys ��ȡ������ͶӰ��Ϣ
	//##ModelId=483BB70C0214
	const ENGINE_APIF UGPrjCoordSys& GetPrjCoordSys();

	//! \brief ȡ�����ݼ�ͶӰ���ã���������ԴͶӰ
	virtual ENGINE_APIF void UnSetPrjCoordSys();

	//! \brief �ж����ݼ��Ƿ��������Լ���ͶӰ
	ENGINE_APIF UGbool HasSetPrjCoordSys();
#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined (IOS)
	//##ModelId=483BB70C0215
	void SetOgdcDataset(OgdcDataset* pOgdcDt);	

	//##ModelId=483BB70C0222
	const OgdcDataset* GetOgdcDataset() const;	
#endif
#if PACKAGE_TYPE==PACKAGE_UGC
	//! \brief �������ݼ�,�����������û��༭
	//##ModelId=4820305502D6
	virtual ENGINE_APIF UGbool Lock();

	//! \brief �����ݼ�����
	//##ModelId=4820305502D8
	virtual ENGINE_APIF UGbool Unlock();

	//! \brief 		�������ݼ��Ľ�����
	virtual ENGINE_APIF void SetProgress(UGProgress *pProgress) {m_pProgress = pProgress;}
	
	//! \brief 		��ȡ���ݼ��Ľ�����
	virtual ENGINE_APIF UGProgress* GetProgress() const {return m_pProgress;}


	//!	\brief	��ȡ���ݼ��ڶ�̬�ֶι�ϵά���еĽ�ɫ
	UGDDRDynSeg::DynSegDatasetRole GetDynSegRole() const { return m_eDynSegRole; }

#endif // end declare ugc sdk

protected:
	//! \brief �������ݼ���ѡ����Ϣ
	//##ModelId=4820305502DA
	virtual ENGINE_APIF void SetOptions(UGint nOptions) = 0;

public:
	//! \brief ���ݼ���ID
	//##ModelId=4820305502DE
	UGint m_nID;
protected:	
	//! \brief �Ƿ��
	//##ModelId=4820305502DF
	UGbool m_bOpened;
	//! \brief �Ƿ��Ѿ��޸�
	//##ModelId=4820305502E0
	UGbool m_bModified;	
	//! \brief ����Դָ��
	//##ModelId=4820305502E1
	UGDataSource* m_pDataSource;
#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined (IOS)
	//##ModelId=4820305502E2
	OgdcDataset* m_pOgdcDataset;
#endif	
	//##ModelId=483BB70C0224
	UGPrjCoordSys m_prjCoordSys;

	//! \brief ���ݼ��Ƿ��������Լ���ͶӰ
	UGbool m_bPrjDataset;

	//! \ brief �������
	UGMutex m_mutex;


	//!	\brief	��̬�ֶι�ϵά���У����ڱ�ʶ���ݼ��Ľ�ɫ
	UGDDRDynSeg::DynSegDatasetRole m_eDynSegRole;
	
	UGString m_strMetadataID;  //��ӦԪ����ID
	
public:
	//�汾������
	UGint m_nEditingID;		//��ǰ�򿪵����ݼ�ռ�õ�Ψһ��ʶ����SmDatasetEditing�м�¼

	UGint m_nSeriesID;		//��ǰ�򿪵����ݼ�ռ�õ�����
	
	UGint m_nLastActionID;	//��ǰ�򿪵����ݼ������ձ༭״̬
	
	UGint m_nEditState;		//���ݼ���״̬��0�����༭��Э��״̬��>0Э��״̬��-1�༭״̬

	UGReconcileInfo m_ReconcileInfo;	//Э����Ϣ

	UGint m_nComActionID;	//���ڱ�Ǳ༭ѹ���Ĳ�����
	
	UGProgress* m_pProgress; //����Compact()��ʹ�� ����������ݼ�����������ʾ  ����Ҫ�ͷ� �������ͷ�
	
};

//##ModelId=4820305503A9
typedef UGArray<UGDataset*> UGDatasets;
 
}

#endif 

