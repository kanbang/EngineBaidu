/*! \file	 UGDatasetRaster.h
 *  \brief	 դ�����ݼ������ļ�
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDatasetRaster.h,v 1.62 2010/05/07 08:58:18 zhouqin Exp $
 */

//////////////////////////////////////////////////////////////////////////
//!  \file UGDatasetRaster.h
//!  \brief UGDatasetRaster �Ľӿڶ��塣
//!  \details UGC����Ӱ�����ݼ��Ľӿڶ��塣
//!  \Modified Date: 2013-4-7
//!  \Modified Author:Conversion-zby
//!  \Details Comments:����UGC�ӿڲ���������ʽ�Լ��ӿ���ɣ���ҪĿ������UGC�ӿ�����Ӷನ��դ�����ݼ�����չ֧��;
//!  \Details Comments:���ε�����Ҫ��������������:(1) ����ԭ�нӿ����Ӳ�����������֧��;(2) ���Ӷನ��դ�����ݼ����нӿ�
//!  \Details Comments:�˴ε����漰����դ�����ݼ��ṹ�ĵ��������ڼ�����Աˮƽ�����Լ�ʱ��Ĳִ٣�����������������������,������
//!  \Details Comments:����Conversion-zby��ϵ!
//!  \Version 1-1-1(2013-4-7)



#ifndef UGDATASETRASTER_H
#define UGDATASETRASTER_H

#include "Engine/UGDataset.h"
#include "Element/OgdcRasterScanline.h"
#include "Element/OgdcRasterBlock.h"
#include "Engine/UGDatasetRasterInfo.h"
#include "Geometry/UGGeoRegion.h"
#include "Engine/UGRecordset.h"
#include "Toolkit/UGToolkit.h"
#include "Toolkit/UGThread.h"
#include "Toolkit/UGProgress.h"
#include "Toolkit/UGMarkup.h"
#include "Engine/UGImgBlocksManager.h"
#include "Engine/UGImgBlockRef.h"

#define PYRAMID_ONCECACHECOUNT		256			//����������ʱһ�λ���Ŀ����

namespace UGC {

//֧��դ����ʾ��ȡ�� ��UGDrawing::PaintRaster������ http://192.168.115.2:8090/browse/UGOVI-1015 
typedef UGbool (UGSTDCALL *GETVIEWBLOCKCALLBACKPROC)(UGlong pDrawingH, UGlong pWnd);

struct UGColorSpaceBand
{

	UGColorSpaceBand()
	{
		m_nColorSpaceSelected = ICS_UNKNOW;

	};
	//��ǰ���ɫ�ʵ�ģʽ
	ImgColorSpace	m_nColorSpaceSelected;

	//��ǰ���Ϊ���ɫ�ʣ�Ҫ��ʾ�Ĳ�������
	UGArray<UGint>	m_arrBandSelected;
};

//���ѣ�դ�����ݼ�ͳ����Ϣ
typedef struct RasterStatistics 
{
	UGbool IsDirty;
	UGdouble Max;//���ֵ
	UGdouble Min;//��Сֵ
	UGdouble Middle;//��ֵ
	UGdouble Average;//ƽ��ֵ
	UGArray<UGdouble> Most;//����
	UGArray<UGdouble> Least;//ϡ��
	UGdouble Stddev;//��׼��
	UGdouble Variance;//����

	RasterStatistics()
	{
		IsDirty = 1;
		Max = 0.0;
		Min = 0.0;
		Middle = 0.0;
		Average = 0.0;
		Stddev = 0.0;
		Variance = 0.0;
	}

} UGRasterStatisticsInfo;

#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined (IOS)
class UGRasterBand;
#endif
//! \brief դ�����ݼ�
//##ModelId=482030540119
#ifdef SYMBIAN60
class ENGINE_APIC UGDatasetRaster : public UGDataset
#else
class ENGINE_API UGDatasetRaster : public UGDataset
#endif
{
	friend class UGDataSource;
public:	
	enum UGImageAccessMode
	{
		//��������ʾģʽ 
		SingleBand	=1,
		// ���ɫ��
		CombineColor=2
	};
	
	enum MultiSpectralFile
	{
		GeoTiff =1,
		MrSID   =2,
		Image   =3,
		ArcGrid =4
	};

public:
	//! \brief ���캯��
	//##ModelId=482030540129
	ENGINE_APIF UGDatasetRaster();

	//! \brief ��������
	//##ModelId=482030540157
	virtual ENGINE_APIF ~UGDatasetRaster();

public:
	//! \brief �����ݼ�
	//##ModelId=483BB70C009C
	virtual ENGINE_APIF UGbool Open();

	//! \brief �ڶ��߳��������жϹرյ�ǰ���ݼ��Ƿ�ȫ��ʸ����Ҫ�����Ƿ��д򿪵ļ�¼����դ����Ҫ�����Ƿ�����ͷ��������ݿ�
	virtual ENGINE_APIF UGbool CanBeClose();

	//! \brief �ر����ݼ�
	//##ModelId=483BB70C009E
	virtual ENGINE_APIF void Close();

	//! \brief �������ݼ���ά��
	//##ModelId=4820305401C5
	virtual ENGINE_APIF UGint GetDimension();

	//! \brief �ж��Ƿ���ʸ�����ݼ�
	//##ModelId=4820305401C7
	virtual ENGINE_APIF UGbool IsVector();
	//! \brief �ж��Ƿ���topo���ݼ�
	//##ModelId=4820305401C9
	virtual ENGINE_APIF UGbool IsTopoDataset();

	//! \brief �ж��Ƿ���դ�����ݼ�
	//##ModelId=4820305401D4
	virtual ENGINE_APIF UGbool IsRaster();

	//! \brief �ж��Ƿ�Ϊ�ನ��դ�����ݼ�
	virtual ENGINE_APIF UGbool IsMBRaster();

	//! \brief �ж��Ƿ�������դ�����ݼ�
	//##ModelId=4820305401D4
	virtual ENGINE_APIF UGbool IsWebRaster();

	//! \brief �ж��Ƿ��ǹ�ϵ�����ݼ�
	virtual ENGINE_APIF UGbool IsRelClass();

	//! \brief �ж��Ƿ��Ǳ�
	//##ModelId=4820305401D6
	virtual ENGINE_APIF UGbool IsLinkTable();

	//! \brief ��ȡ��ɫ��		
	//! \return 	UGColorTable*
	//! \remarks 		
	//##ModelId=482030550157
	virtual ENGINE_APIF UGColorTable* GetColorTable();

	//! \brief 		���÷ֲ���ɫ��ɫ��
	//##ModelId=482030550158
	virtual ENGINE_APIF UGbool SetGridColorTable(UGColorTable* pColorTable=NULL);

	//! \brief �������ݼ��ַ����뷽ʽ
	//##ModelId=483BB70C0138
	virtual ENGINE_APIF UGString::Charset GetCharset() const;

	//! \brief �������ݼ��ַ����뷽ʽ
	//##ModelId=483BB70C013A
	virtual ENGINE_APIF UGbool SetCharset(UGString::Charset c);

	//! \brief �õ�RasterInfo��ָ��
	//##ModelId=4820305401F9
	virtual ENGINE_APIF UGDatasetRasterInfo* GetInfo();

	//##ModelId=483BB70C0119
	virtual ENGINE_APIF UGint GetBandCount() const;

	//! \brief ��ȡ��ǰ���ݼ��ı����֡�
	virtual ENGINE_APIF UGString GetTableName();	

	//! \brief �������ݼ�����
	//##ModelId=482030540177
	virtual ENGINE_APIF DatasetType GetType() const;

	//! \brief �������ݼ���(���Ժͱ�����ͬ)
	//##ModelId=482030540187
	virtual ENGINE_APIF UGString GetName() ;

	//! \brief ��ȡ���
	//##ModelId=482030540222
	ENGINE_APIF UGint GetWidth() const ;

	//! \brief ��ȡ�߶�
	//##ModelId=482030540224
	ENGINE_APIF UGint GetHeight() const;

	//! \brief �������ݼ��ķ�Χ
	//##ModelId=482030540226
	virtual ENGINE_APIF const UGRect2D& GetBounds();

	//! \brief �������ݼ��ķ�Χ
	//##ModelId=482030540232
	virtual ENGINE_APIF void SetBounds(const UGRect2D& r) ;

	//! \brief Image�����Block����
	//##ModelId=482030540235
	ENGINE_APIF UGint GetRowBlockCount() const ;

	//! \brief Image�����Block����
	//##ModelId=482030540237
	ENGINE_APIF UGint GetColBlockCount() const ;

	//! \brief ��ȡ�ü�����
	//##ModelId=4820305500DA
	virtual ENGINE_APIF UGGeoRegion* GetClipRegion();

	//! \brief ���òü�����
	//##ModelId=4820305500DC
	virtual ENGINE_APIF void SetClipRegion(UGGeoRegion* pClipRgn);

	//! \brief �ж����ݼ��Ƿ���ĳ��ѡ����Ϣ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=48203055000F
	virtual ENGINE_APIF UGbool HasFlag(UGint nOption) const;

	//! \brief �õ�Options
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305401F7
	virtual ENGINE_APIF UGint GetOptions();

	//##ModelId=482030550179
	//! \param nBandIndex[in] ��ȡ��ɫ��ֵ���ڵĲ�������ֵ��Ĭ��Ϊ0 
	//! \brief �������ݼ���ѡ����Ϣ
	virtual ENGINE_APIF void SetOptions(UGint nOptions);

	//! \brief ��ȡ���ݼ�������Ϣ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305401A8
	virtual ENGINE_APIF UGString GetDescription() const;

	//! \brief �������ݼ�������Ϣ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305401B5
	virtual ENGINE_APIF UGbool SetDescription(const UGString& strDesc);

	//! \brief ��ȡ���ݼ�������Ϣ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305401A8
	virtual ENGINE_APIF UGString GetExtInfo() const;

	//! \brief �������ݼ�������Ϣ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305401B5
	virtual ENGINE_APIF UGbool SetExtInfo(const UGString& strExtInfo);

	//! \brief ���ؿռ����ݱ��뷽ʽ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305401E6
	virtual ENGINE_APIF UGDataCodec::CodecType GetCodecType(UGint nBandIndex) ;
	virtual ENGINE_APIF UGDataCodec::CodecType GetCodecType() ;

	//! \brief ���ÿռ����ݱ��뷽ʽ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305401F4
	virtual ENGINE_APIF UGbool SetCodecType(UGDataCodec::CodecType c,UGint nBandIndex);
	virtual ENGINE_APIF UGbool SetCodecType(UGDataCodec::CodecType c);

	//! \brief ������С�߳�
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0,ȡ�����ݼ���Сֵ
	//! \��GetMinZ�е���bandIndex����Ϊ0�Ľӿ�GetMinZ;
	//##ModelId=482030540189
	virtual ENGINE_APIF UGdouble GetMinZ(UGint nBandIndex);
	virtual ENGINE_APIF UGdouble GetMinZ();
	
	//! \brief ������С�߳�
	//! \param nBandIndex[in] ��������ֵ
	//! \��SetMinZ�е���bandIndex����Ϊ0�Ľӿ�setMinZ;
	//##ModelId=482030540196
	virtual ENGINE_APIF void SetMinZ(UGdouble d,UGint nBandIndex);
	virtual ENGINE_APIF void SetMinZ(UGdouble d);
	
	//! \brief �������߳�
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \��GetMaxZ�е���bandIndex����Ϊ0�Ľӿ�GetMaxZ;
	//##ModelId=482030540199
	virtual ENGINE_APIF UGdouble GetMaxZ(UGint nBandIndex);
	virtual ENGINE_APIF UGdouble GetMaxZ();
	
	//! \brief �������߳�
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \��SetMinZ�е���bandIndex����Ϊ0�Ľӿ�setMinZ
	//##ModelId=4820305401A5
	virtual ENGINE_APIF void SetMaxZ(UGdouble d,UGint nBandIndex) ;
	virtual ENGINE_APIF void SetMaxZ(UGdouble d) ;

	//! \brief ��ȡ��Чֵ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=482030540261
	virtual ENGINE_APIF UGdouble GetNoValue(UGint nBandIndex=0);

	//! \brief brief ������ֵ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=482030540263
	virtual ENGINE_APIF UGbool SetNoValue(UGdouble dbNoValue,UGint nBandIndex=0);

	//! \brief Image�����ظ�ʽ
	//! \param nBandIndex[in]��������ֵ��Ĭ��Ϊ0
	//##ModelId=482030540265
	virtual ENGINE_APIF OGDC::PixelFormat GetPixelFormat(UGint nBandIndex=0);

	//! \brief �õ���ɫ��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305401D8
	virtual ENGINE_APIF UGColorset GetColorset(UGint nBandIndex=0);

	//! \brief ���õ�ɫ��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305401E4
	virtual ENGINE_APIF void SetColorset(const UGColorset& Colorset,UGint nBandIndex=0);

	inline UGArray<UGImgBlocksManager>* GetImgBlocksManager() { return &m_arrImgManager; }

	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	UGint GetMaxBlockSize(UGint nBandIndex=0) const;

	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	void SetMaxBlockSize(UGint nMaxBlockSize,UGint nBandIndex=0);

	//��ȡ�������ڵ�����
	//! \param nBandIndex[in] ��ȡ��ɫ��ֵ���ڵĲ�������ֵ��Ĭ��Ϊ0
	UGString GetFieldName(UGint nBandIndex = 0) const;

	//��ȡ���ε�����
	//! \param nBandIndex[in] ��ȡ��ɫ��ֵ���ڵĲ�������ֵ��Ĭ��Ϊ0
	UGString GetBandName(UGint nBandIndex = 0) const;
 
	//! \brief Block�ı߳�
	//##ModelId=482030540271
	ENGINE_APIF UGDatasetRasterInfo::IBSizeOption GetBlockSize() const ;

	//! \brief ��ȡ�������ĵ�ַ
	//##ModelId=482030540273
	virtual ENGINE_APIF UGbyte * GetBlockCache() const;

	//! \brief ��ȡBlock��Byte����
	//##ModelId=482030540275
	virtual ENGINE_APIF UGint GetBlockByteSize(UGint nBandIndex = 0);

	//! \brief ��ȡValue
	//##ModelId=4820305402AF
	//! \param bIsNeedLock �Ƿ��ڲ���Ҫ����  Ƶ�����÷��������ڼ�������ʧ̫�� 
	// �ʶ�û��Ҫ���̲߳���Ƶ�����ô˽ӿڵ��ṩbIsNeedLock������������
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	virtual ENGINE_APIF UGdouble GetValue(UGint X,UGint Y, UGint nBandIndex=0, UGbool bIsNeedLock = TRUE);

	//! \brief ����Value
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305402CE
	virtual ENGINE_APIF void SetValue(UGint X,UGint Y,UGdouble dValue,UGint nBandIndex =0);

	//! \brief �õ�ɨ����
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305402DE
	virtual ENGINE_APIF UGbool GetScanline(UGint nRowIndex,UGImgScanline& ScanLine, UGint nStartCol = 0, UGint nWidth=0,UGint nBandIndex=0);

	//! \brief ͨ��������������ɨ����
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305402EE
	virtual ENGINE_APIF UGbool SetScanline(UGint nRowIndex,UGint nColIndex,
		const UGImgScanline& ScanLine,UGint nBandIndex=0) ;

	//! \brief ͨ��Block��������
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=48203054034B
	virtual ENGINE_APIF UGbool CacheByBlock(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight,UGint nBandIndex=0) ;

	ENGINE_APIF UGbool CacheByBlock(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight, UGArray<UGImgBlockRef>& arrRefImgBlock, UGint nBandIndex=0);

	//! \brief ��ȡBlock,pImgBlock�ڴ�����������з��䣬ϵͳ�Զ��ͷ����ݿ�
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=48203054030D
	virtual ENGINE_APIF UGbool GetBlockAt( UGint nBlockRow,UGint nBlockCol, UGImgBlockRef &refImgBlock,UGint nBandIndex=0);

	//! \brief ��ȡBlock,pImgBlock�ڴ�����������з��䣬ϵͳ�Զ��ͷ����ݿ�
	//! \attention Ϊ��֧���̰߳��������˷�����ΪProtected
	//! \param nBandIndex[in] ��ȡ��ɫ��ֵ���ڵĲ�������ֵ��Ĭ��Ϊ0
	//##ModelId=48203054030D
	virtual ENGINE_APIF UGbool GetBlockAt(UGint nBlockRow,UGint nBlockCol,
		UGImgBlock*& pImgBlock,UGint nBandIndex=0);

	//! \brief ����ָ��������
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=48203055002E
 	virtual ENGINE_APIF UGImgBlock* LoadBlock(UGint nRowBlock,UGint nColBlock,UGint nBandIndex=0);

	//! \brief  ������ԴȡӰ���
	//! \param lRowBlock  Ӱ����������
	//! \param lColBlock Ӱ����������
	//! \param pImgBlock  ����Ӱ����ָ��
	//! \param nBandIndex[in] ��ȡ��ɫ��ֵ���ڵĲ�������ֵ��Ĭ��Ϊ0
	//! \return �Ƿ���ȷȡ��Ӱ��飬����ֵΪFALSEʱpImgBlockӦ��Ϊ��ָ��
	virtual ENGINE_APIF UGbool LoadBlock(UGint lRowBlock,UGint lColBlock,
		UGImgBlock* pImgBlock,UGint nBandIndex=0){ return FALSE; };

	//! \brief  һ�λ�����ж���Ӱ���
	//! \param nLeft  ��ʼ��
	//! \param nTop   ��ʼ��
	//! \param nWidth  �����п�
	//! \param nHeight �����и�
	//! \param dictImgBlock Ԥ�ȿ��ٵ�Ӱ����ڴ�
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \return �Ƿ���ȷȡ��Ӱ��飬����ֵΪFALSEʱpImgBlockӦ��Ϊ��ָ��
	virtual ENGINE_APIF UGbool LoadBlock(UGint nLeft, UGint nTop, UGint nWidth, UGint nHeight, 
		UGDict<UGint, UGImgBlock*>& dictImgBlock, UGint nBandIndex);

	//! \brief pImgBlock����
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=482030550032
	virtual ENGINE_APIF UGbool SaveBlock(UGImgBlock* pImgBlock,UGint nBandIndex=0);

	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	virtual ENGINE_APIF UGbool SaveAllBlocks(UGint nBandIndex=0);

	//! \brief ���pImgBlock����
	//##ModelId=482030550032
	virtual ENGINE_APIF UGbool SaveBlocks(UGArray<UGImgBlock*>& pAryImgBlock, UGint nBandIndex = 0);

	//! \brief ж��ָ��Block
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=482030540242
	virtual ENGINE_APIF UGbool ReleaseBlock(UGint nIndex,UGint nBandIndex=0);

	//! \brief ж�������ѷ����ڴ�Ŀ�
	//! \param nBandIndex[in]��������ֵ��Ĭ��Ϊ0
	//##ModelId=482030540251
	virtual ENGINE_APIF void ReleaseAllBlock(UGint nBandIndex=0, UGbool bPyramdLevel=TRUE);

	ENGINE_APIF void ReleaseBlockRef(UGImgBlock* pImgBlock, UGint nBandIndex);

#if PACKAGE_TYPE==PACKAGE_UGC
	//##ModelId=482030550012
	//! \brief ����Ӱ���������
	//! \param bShhowProgress �Ƿ���ʾ������[in]��
	//! \return �Ƿ����ɹ���
	virtual ENGINE_APIF UGbool BuildPyramid(UGbool bShhowProgress);	

	virtual ENGINE_APIF UGbool BuildPyramidTiersOnly(bool bShowProgress){return false;};

	//����Χ���½�����
	virtual ENGINE_APIF UGbool UpdatePyramid(const UGRect2D &rect);	
	UGbool UpdatePyramidIner(const UGRect2D& rcRect);

	//##ModelId=482030550015
	//! \brief �Ƴ���������
	//! \return �Ƿ��Ƴ��ɹ���
	virtual ENGINE_APIF UGbool RemovePyramids();	

	//##ModelId=483BB70C0102
	//! \brief �Ƿ�����Ӱ���������
	//! \return �Ƿ����ɹ���
	virtual ENGINE_APIF UGbool IsBuildPyramid() const;	

	//! \brief  ������Դȡ��������ʾ���ĸ����ڵ�Ӱ���
	//!
	//!                   			 nColIndex
	//!                  	   	+------------+------------+
	//!       		   	|    LT	|    RT           |
	//!                              	|        		|  	           |
	//!        	nRowIndex  |------------+------------|
	//!                 		|    LB       	|    RB	|
	//!                 		|          	|  	           |
	//!                  		+------------+------------+
	//!   \mark �����ȡΪ���ݼ��ı߽磬�ڲ�Ӧ�����ú�Ӱ���ĺϷ���Ⱥ͸߶ȣ�
	//!   	         ������ȡ��Ӱ�����ȫ���������ݼ��ķ�Χ���Ϸ��߿��Ϊ0����Ӱ���ָ�벻Ϊ��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	virtual ENGINE_APIF void LoadRectBlocks(UGint nRowIndex,UGint nColIndex,
		UGImgBlock*&pImgBlockLT,UGImgBlock*&pImgBlockRT,
		UGImgBlock*&pImgBlockLB,UGImgBlock*&pImgBlockRB,UGint nBandIndex=0);

	//! \brief   ����Ӱ��������Ĳ㼶�����ݼ�
	//! \param rInfo    ���������ݼ��������Ϣ
	//! \param nLevel   Ϊ���ݼ������ڼ���Ľ����������ݼ�����Ϊ0�㣬���ε���
	//! \return  ���ش����������ݼ�ָ��
	virtual ENGINE_APIF UGDatasetRaster* Tier1(UGDatasetRasterInfo &rInfo,UGint nLevel){ return NULL; };

	//! \brief   ����Ӱ��������Ĳ㼶�����ݼ�
	//! \param nLevel   Ϊ���ݼ������ڼ���Ľ����������ݼ�����Ϊ0�㣬���ε���
	//! \param lWidth   ���������ݼ���Ӱ�����
	//! \param lHeight    ���������ݼ���Ӱ���߶�
	//! \param eBlockSize    ���������ݼ���Ӱ����С
	//! \param nOptions    ���������ݼ���ѡ����Ϣ
	//! \return	 ���ش����������ݼ�ָ��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	virtual ENGINE_APIF UGDatasetRaster* Tier(UGint nLevel, UGint lWidth, UGint lHeight, 
		UGDatasetRasterInfo::IBSizeOption eBlockSize, UGint nOptions){ return NULL; };

	//!	\brief	�������������ȫ�Ľ�����
	virtual ENGINE_APIF void ClearIncompletePyramid(){};

	//##ModelId=482030550001
	//! \brief	�õ�ĳ����������ݼ�
	//! \remarks �������ԭ����˽�к�����publicֻ������̬ͶӰʱ���ã���������ʹ����ѯ������
	ENGINE_APIF  virtual UGDatasetRaster * GetPyramidTier(UGint nImgWidth,UGint nDeviceWidth);

	//##ModelId=482030550000
	//! \brief ��ǰ���ݼ���Ӱ��������ĸ���ָ������
	//! \remarks �������ԭ����˽�к�����publicֻ������̬ͶӰʱ���ã���������ʹ����ѯ������
	ENGINE_APIF UGDatasets& GetPyramidDatasets();

#endif 

	//! \brief �õ�դ�����ݵļ�ֵ��
	//ע�⣺���դ�����ݵ�ֵ�����仯���˺����������¼��㼫ֵ��
	//�����ȵ���CalculateExtremum�����¼��㼫ֵ�ſ��ԡ�
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=4820305401B8
	virtual ENGINE_APIF void GetExtremum(UGdouble& dMax, UGdouble& dMin,UGint nBandIndex=0);

	//##ModelId=482030550148
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \�������в��εļ�ֵ
	virtual ENGINE_APIF UGbool CalculateExtremum(
		UGDatasetRaster * pDtGrid, 
		UGdouble &dMax, 
		UGdouble& dMin, 
		UGPoint * pMaxPt = NULL, 
		UGPoint * pMinPt = NULL,
		UGProgress* pProgress = NULL,UGint nBandIndex=0);

	//##ModelId=48203055014E
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \�������в��εļ�ֵ
	virtual ENGINE_APIF UGbool CalculateExtremum(
		UGdouble &dMax,
		UGdouble& dMin, 
		UGRecordset * pRsRegion = NULL,
		UGPoint * pMaxPt = NULL, 
		UGPoint * pMinPt = NULL,
		UGProgress* pProgress = NULL,UGint nBandIndex=0);

	//!	\brief	դ�����ݼ���׷��
	//##ModelId=482030550138
	virtual ENGINE_APIF UGbool Append(UGDatasetRaster *pSrcRaster);

	//դ�����ݿ��ٸ���
	virtual ENGINE_APIF UGbool CopyFromFile(UGDatasetRaster *pSrcDataset);

	//! \brief �����Ƿ���SaveBlockʱ���㼫ֵ,����ΪTRUEʱ��SaveBlockʱ���Զ����㼫ֵ���������û��Լ�ά�����ݼ��ļ�ֵ
	virtual ENGINE_APIF void SetAutoCalculateExtremum(UGbool bAutoComputeExtremum){m_bAutoComputeExtremum = bAutoComputeExtremum; };

	//! \brief 		��ȡӰ��ĵ�����������
	//! \return 	UGRect2D
	//! \remarks 		
	//##ModelId=482030550109
	ENGINE_APIF UGRect2D GetGeoReference();	

	//! \brief 		����Ӱ��ĵ�����������
	//! \return 	void
	//! \param 		&rc2GeoReference
	//! \remarks 		
	//##ModelId=4820305500EC
	virtual ENGINE_APIF void SetGeoReference(const UGRect2D &rc2GeoReference);

	//�ӿڱ任.===========================================================
	//##ModelId=482030550035
	ENGINE_APIF void PrepareGeoRefrence();		//��ʼ��GeoRefernce

	//! \brief ��������תΪ��������
	//##ModelId=48203055004E
	ENGINE_APIF void ImgToXY(const UGPoint& pntImg,UGPoint2D& pntXY);

	//! \brief ��������תΪ��������
	//##ModelId=48203055007D
	ENGINE_APIF void ImgToXY(const UGRect& rectImg,UGRect2D& rectXY);

	//! \brief ��������תΪ��������
	//##ModelId=48203055009C
	ENGINE_APIF void XYToImg(const UGPoint2D& pntXY,UGPoint& pntImg);

	//! \brief ��������תΪ��������
	//##ModelId=4820305500BB
	ENGINE_APIF void XYToImg(const UGRect2D& rectXY,UGRect& rectImg);

	//դ����Ӱ�������Ƶ��ǲ�ͬ��
	//##ModelId=482030550196
	ENGINE_APIF void GridToXY(const UGPoint& pntImg,UGPoint2D& pntXY);

	//##ModelId=4820305501B5
	ENGINE_APIF void XYToGrid(const UGPoint2D& pntXY,UGPoint& pntImg);

	//##ModelId=4820305500EA
	ENGINE_APIF UGDatasetRaster* GetParentDataset() const;

	//##ModelId=482030550167
	ENGINE_APIF void SetParentDataset(UGDatasetRaster* pParent) ;

	//! �������ر߳�����λ����λ��
	ENGINE_APIF UGbool ComDivAndMod();

	//! \brief դ�����ݼ�ͶӰת��
	//pSrcDatasetRaster Input  դ������ 
	//pDesDataSource Output դ������Դ 	
	//pClipRegion �ü�����
	//strDesRasterName Output դ������ 	
	ENGINE_APIF UGDatasetRaster* PJConvert(UGRefTranslator *pRefTranslator,
		const UGString& strDesRasterName, UGdouble dResolution = 0.0, 
		UGGeoRegion* pClipRegion=NULL, UGDataSource* pDesDataSource = NULL,
		UGbool bShowProgress = TRUE);

	ENGINE_APIF UGDatasetRaster* PJForward(UGPrjCoordSys* pPJCoordsys,
		const UGString& strDesRasterName, UGdouble dResolution = 0.0, 
		UGGeoRegion* pClipRegion=NULL, UGDataSource* pDesDataSource = NULL,
		UGbool bShowProgress = TRUE);

	ENGINE_APIF UGDatasetRaster* PJInverse(UGPrjCoordSys* pPJCoordsys,
		const UGString& strDesRasterName, UGdouble dResolution = 0.0, 
		UGGeoRegion* pClipRegion=NULL, UGDataSource* pDesDataSource = NULL,
		UGbool bShowProgress = TRUE);

	//����դ�����ݼ���ValueTable
	ENGINE_APIF UGDatasetVector* BuildValueTable(UGDataSource* pOutputDs,UGString& strName);

public:

	// �õ�դ����Ϣ
	virtual ENGINE_APIF UGDict<UGint, UGRasterStatisticsInfo> GetStatisticsInfo();

	//! ͳ��դ����Ϣ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \Ĭ��ͳ�����м�ֵ
	virtual ENGINE_APIF UGDict<UGint, UGRasterStatisticsInfo> BuildStatistics();

	//�����ݿ��ѯ������
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	virtual ENGINE_APIF UGbool GetDistinctValue(UGArray<UGdouble> &valueArray, UGArray<UGint> &countArray,UGint nBandIndex=0);
	//ɾ�����ݿ��е���ؼ�¼
// 	virtual ENGINE_APIF UGbool ClearDistinctValueCount();

	// դ����Ϣ��ʽ����XML
	ENGINE_APIF UGString StatisticsInfoToXML();

	ENGINE_APIF void StatisticsInfoFromXML(const UGString& strXML);

protected:

	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	void GetCurBandStatInfo(UGRasterStatisticsInfo& rsi,UGint nBandIndex=0);

	//! \��ȡ��ǰ����������ͳ����Ϣ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \param info դ��ͳ����Ϣ
	ENGINE_APIF void GetBaseStatisticsInfo(UGRasterStatisticsInfo& info,UGint nBandIndex=0);

// 	StaticsticsStatus m_staticsticsStatus;
	UGDict<UGint, UGRasterStatisticsInfo> m_dictRasterStatInfo;

	void ParserStatInfoXML(UGMarkup& strXML, UGRasterStatisticsInfo& statInfo, UGbool isToXML);

// 	virtual ENGINE_APIF UGbool CreateStatistics();
// 	virtual ENGINE_APIF UGRecordset *GetArrtibuteTable();
// 	virtual ENGINE_APIF UGRecordset *GetStatistics();

	UGdouble CalcAvgValue(UGdouble a, UGdouble b, UGdouble c, UGdouble d);

protected:

	//##ModelId=482030550169
	//! \brief ��ָ����Ӱ��������ص����ػ��档
	//! \param pImgBlock ָ����Ӱ���[in]��
	//! \return ���ر��ػ���Ĵ�С��
	ENGINE_APIF UGint EncodeBlock(UGImgBlock * pImgBlock,UGint nBandIndex=0);

	//##ModelId=48203055016B
	//! \brief ��ָ�����ֽ�������������ص�Ӱ��鵱�С�
	//! \param pImgBlock ��ȡ��Ӱ���[in]��
	//! \param pByte �ֽ���ָ��[in]��
	//! \param nRawSize �ֽ�����С[in]��
	ENGINE_APIF UGbool DecodeBlock(UGImgBlock * pImgBlock, const UGbyte * pByte,UGint nRawSize,UGint nBandIndex=0);	

	//! \brief ��ʼ��һ���տ�
	ENGINE_APIF UGbool InitBlock(UGint nRow,UGint nCol,UGint nBandIndex = 0);

	//! \brief 
	ENGINE_APIF UGbool InitBlock(UGint nRow,UGint nCol, UGImgBlock* pImgBlock,UGint nBandIndex = 0);

	//! \brief ��ȡBlockManager�����еı��޸Ĺ���δ����Ŀ�ֳ��Ѵ��ں�δ���ڵ�����
	UGbool StatisticsBlocks(UGArray<UGImgBlock*> & updateBlocks ,
		UGArray<UGImgBlock*> & insertBlocks, UGint nBandIndex = 0);

public:

	//! \brief ��ǰ�Ķನ��դ�����ݼ����Ӳ��Ρ�
	//! \param arrRaster Ҫ���ӵ�դ�����ݼ�ָ������[in]��
	//! \return ��
	//! \remarks ���ӵ����ݼ�ָ������ָ�����UGCԭ����դ�����ݼ���
	//! \attention arrRaster�͵�ǰ���ݼ������ڿ�ȣ��߶ȣ����ݼ����ͣ�Ӱ��ֿ�䳤��Ӱ��������Ӱ�������ϸ�Ҫ��һ�¡�
	ENGINE_APIF UGbool AppendRaster(const UGArray<UGDatasetRaster *>& arrRaster);	

	//! \brief ��ನ��դ�����ݼ�׷�Ӷ�����Ρ�
	//! \param &BandRaster [in] Ҫ׷�ӵĲ������ڵĶನ��դ�����ݼ���
	//! \param nBandIndex [in] Ҫ׷�ӵĲ���������
	//! \attention pBandRaster�͵�ǰ���ݼ������ڿ�ȣ��߶ȣ����ݼ����ͣ�Ӱ��ֿ�߳���Ӱ��������Ӱ�����������ݼ���Χ�ϸ�Ҫ��һ�¡���
	virtual ENGINE_APIF UGbool AppendBand(UGDatasetRaster* pBandRaster,const UGArray<UGint>& arrBandIndex);

	//! \brief ɾ��ĳ�����Ρ�
	//! \param nBandIndex [in] ����������
	//! \remarks ���ɾ�����ǵ�ǰ�ƶ����Σ��Զ��ƶ�����һ�����Ρ�
	virtual ENGINE_APIF UGbool DeleteBand(UGint nBandIndex);  	

	//! \brief �������դ�����ݼ���
	//! \param arrBandIndex �����Ĳ�������[in]��
	//! \param arrRaster ������դ�����ݼ��б�[in]��
	//! \param arrName ������դ�����ݼ���������б�[in]��
	//! \remarks ��������ݼ���ָUGCԭ����դ�����ݼ�����
	//! \attention arrName���������С��arrBandIndex�������Ĭ�ϵ����֡�
	//!            ��� arrBandIndex���û�����ã��򵼳���ǰ���ݼ������в��Ρ�
	virtual ENGINE_APIF UGbool ExportRaster(const UGArray<UGint>& arrBandIndex, UGArray<UGDatasetRaster *>& arrRaster,
		UGArray<UGString>& arrName, UGDataSource* pOutputDatasource = NULL);

public:

	//! \brief ����MrSID���ⲿ����,
	//! \brief bFileMode��ָ���ļ�����ķ�ʽ���Ǵ洢�����ݿ��еķ�ʽ
	//##ModelId=48203055001F
	ENGINE_APIF UGbool CreateMrSIDLink(const UGString& strImgPathName,
		UGbool bFileMode = TRUE);

	//! \brief ����ECW���ⲿ����
	//##ModelId=482030550022
	ENGINE_APIF UGbool CreateECWLink(const UGString& strImgPathName,
		UGbool bFileMode = TRUE);

	//! \brief �Ϸ������ļ����
	//##ModelId=482030550025
	ENGINE_APIF UGbool IsValidExternalFileLink() ;

	//! \brief ȡ�ù����ļ���
	//##ModelId=482030550026
	ENGINE_APIF UGString GetLinkFileName() const;


public:

	//! \brief ��ȡPixel
	//! \remarks ���ڶನ�Σ������ǰ����С��0������ݵ�ǰBandCombineMode��ȡ��ǰ��������ɫ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=482030540277
	virtual ENGINE_APIF UGColor GetPixel(UGint X,UGint Y ,UGint nBandIndex=0);

	//! \brief ��ȡPixel
	virtual ENGINE_APIF UGColor GetPixel(UGint X,UGint Y,UGArray<UGint>& nIndex, ImgColorSpace nColorSpace = ICS_RGB);
	
	//! \brief ����Pixel
	//! \remarks ���ڶನ�Σ������ǰ����С��0������ݵ�ǰBandCombineMode
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//����
	//##ModelId=482030540290
	virtual ENGINE_APIF void SetPixel(UGint X,UGint Y,UGColor nColor,UGint nBandIndex=0);
		
	//! \brief ͨ������Χ��������
	//##ModelId=48203054032C
	virtual ENGINE_APIF UGbool CacheByGeoRef(const UGRect2D& rc2FocusedArea);

	//! \brief ͨ��Pixel��������
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//##ModelId=48203054035C
	virtual ENGINE_APIF UGbool CacheByPixel(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight,UGint nBandIndex=0);

	//! \brief ���ݲ�ͬ�����ظ�ʽ�������������ֵ
	ENGINE_APIF void GetImgPyramidValue(OGDC::PixelFormat ipf, UGbool bIndexedColor, UGuint a,
		UGuint b, UGuint c, UGuint d, UGuint& e);

	//! \brief ͨ������Χ���ƻ������ݵĴ�С
	//##ModelId=48203054037A
	ENGINE_APIF UGint EstimateCachSizeByGeoRef(const UGRect2D& rc2FocusedArea);

	//! \brief ͨ��Block���ƻ������ݵĴ�С
	//##ModelId=482030540399
	virtual ENGINE_APIF UGint EstimateCachSizeByBlock(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight);

	//! \brief ͨ��Pixel���ƻ������ݵĴ�С
	//##ModelId=4820305403B9
	virtual ENGINE_APIF UGint EstimateCachSizeByPixel(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight) ;

	//##ModelId=483BB70C012C
	//! \brief ��ȡ��ʾ��Ӱ��顣
	//! \param rcView ��ȡ����ʾ��Ӱ����С[in]��
	//! \param nDeviceWidth �豸���[in]��
	//! \param nDeviceHeight �豸�߶�[in]��
	//! \return ������ʾ��Ӱ��顣
	virtual ENGINE_APIF UGImgBlock* GetViewBlock(const UGRect2D& rcView, UGint nDeviceWidth, UGint nDeviceHeight);	

	//! \brief �������ز����Ƿ��Ǳ�����
	virtual ENGINE_APIF void SetSamClosedInterfal(UGbool bValue);

	//! \brief ��ȡ��ʾ��Ӱ��顣
	//! \param rcView ��ȡ����ʾ��Ӱ����С[in]��
	//! \param nDeviceWidth �豸���[in]��
	//! \param nDeviceHeight �豸�߶�[in]��
	//! \param bFinished ��ǰ�˴λ�ȡӰ����Ƿ��Ѿ��õ�ȫ������[out]��
	//! \return ������ʾ��Ӱ��顣
	virtual ENGINE_APIF UGImgBlock* GetViewBlock(const UGRect2D& rcView, UGint nDeviceWidth, UGint nDeviceHeight, UGbool &bFinished) { bFinished = TRUE; return GetViewBlock(rcView, nDeviceWidth, nDeviceHeight); }

	//! \brief ��ȡ��ʾ��Ӱ��顣
	//! \param rcView ��ȡ����ʾ��Ӱ����С[in]��
	//! \param nDeviceWidth �豸���[in]��
	//! \param nDeviceHeight �豸�߶�[in]��
	//! \param nDeviceHeight ָ�����������ţ���SetBandIndexָ���������Զನ��������[in]��
	//! \return ������ʾ��Ӱ��顣
	virtual ENGINE_APIF UGImgBlock* GetViewBlock(const UGRect2D& rcView, UGint nDeviceWidth, UGint nDeviceHeight, UGint nBandIndex);

	//! \brief ���ص�ǰӰ���ɫ�ʿռ�
	virtual ENGINE_APIF ImgColorSpace GetColorSpace() const;
	
	//! \brief ���õ�ǰӰ���ɫ�ʿռ�
	virtual ENGINE_APIF void SetColorSpace(ImgColorSpace nColorSpace);

//{{modified by qianjn in 2008-11-24 18:59:19 �޸�ԭ��

	//  [added by zhangshuo at 6/8/2010]
	virtual ENGINE_APIF UGDatasetRaster* GetMemDataset(){return NULL;};

	//�����½�����ʹ�ã����ݱ��Ƿ�Ϊ��
	virtual ENGINE_APIF UGbool IsBlockTableEmpty();
	//�����½�����ʹ�ã�������ݱ��
	virtual ENGINE_APIF UGbool Truncate();

// 	//##ModelId=482030550001
// 	//! \brief	�õ�ĳ����������ݼ�
// 	//! \remarks �������ԭ����˽�к�����publicֻ������̬ͶӰʱ���ã���������ʹ����ѯ������
// 	ENGINE_APIF UGDatasetRaster * GetPyramidTier(UGRect2D rectView,UGint nDeviceWidth,UGint nDeviceHeigth){return NULL;}
//     
	//դ������֧����ʾȡ��
	void SetGetViewBlockCallBackProc(GETVIEWBLOCKCALLBACKPROC pFun, UGlong pDrawing, UGlong pWndH);

protected:

//}}{modified by qianjn in 2008-11-24 18:59:19 �޸�ԭ��
	
	//##ModelId=48203055017C
	//! \brief ��ȡָ��λ�õĵ�Ӱ���
	//! \param nIndex [in]��
    //UGImgBlock * GetBlockByPos(UGint nIndex);	

	//##ModelId=482030550186
	//! \brief ����ĳ��λ��Ӱ���顣
	//! \param nIndex Ӱ����λ�ã���Ҫָ��blockmanager[in]��
	//! \param *pImgBlock Ӱ���ָ��[in]��
	ENGINE_APIF UGbool	SetBlockByPos(UGint nIndex,UGImgBlock *pImgBlock, UGint nBandIndex = 0);	
	//! \brief ��ȡӰ�������
	//##ModelId=483BB70C0148
	ENGINE_APIF UGint GetColBlocks();	
	//! \brief ��ȡӰ�������
	//##ModelId=483BB70C0149
	ENGINE_APIF UGint GetRowBlocks();	

	// �õ�ȱʡ�ı任���դ���С
	ENGINE_APIF double GetPJConvertCellSize(UGRefTranslator* pPJTranslator);

	ENGINE_APIF UGGeoRegion* GetPJConvertRegion(UGRefTranslator* pPJTranslator,
		UGGeoRegion* pClipRegion);

public:
	//CHENZhao UGC.USR.104.017 դ�����ݼ����Ա�ͳ����Ϣ����
// 	virtual ENGINE_APIF StaticsticsStatus GetStatisticsStatus();
// 	virtual ENGINE_APIF void SetStatisticsStatus(StaticsticsStatus ss);
// 	virtual ENGINE_APIF StaticsticsStatus RefreshStatisticsStatus();

// 	enum StaticsticsStatus{STATISTICS_OK= 1,STATISTICS_NO= 0,STATISTICS_DIRTY= 2};
// 
// 	//����դ��ֵͳ��,��ɾ��֮ǰ��ֵ��д�����ݿ���
// 	virtual ENGINE_APIF UGbool RefreshDistinctValueCount();
// 	//����ʵ��������㲢����
// 	virtual ENGINE_APIF UGbool CountDistinctValue(UGArray<UGdouble> &valueArray, UGArray<UGint> &countArray);
// 

public:	

	//! \brief �޸ĵ�ǰ���ε�����
	//! \param nBandIndex nBandIndexΪ�޸ĺ�����
	//! \remarks ע�⣬����ӿ��ڵ��û������ã������ڶ��û�������¶�ͬһ�����ݼ����������ܻ��д���
	//!          �����ǰ�������Ϸ���������������ظ������޸�ʧ��
	virtual ENGINE_APIF UGbool ModifyBandIndex(UGint nBandIndex);
	
	//##ModelId=483BB70C0120
	//! \brief ���õ�ǰ�̵߳�ɫ�ʿռ�ģʽ��
	//! \param aryBand ɫ�ʿռ�ģʽ�Ĳ���ѡ��[in]��
	//! \param nColorSpace ɫ�ʿռ�ģʽ[in]��
// 	virtual ENGINE_APIF void SetBandCombineMode(const UGArray<UGint>& aryBand, ImgColorSpace nColorSpace);
	
	//##ModelId=483BB70C0128
	//! \brief ��ȡ��ǰ�̵߳�ɫ�ʿռ�ģʽ��
	//! \param aryBand ����ѡ��[in]��
	//! \param nColorSpace ɫ�ʿռ�ģʽ[in]��
	//! \remarks ������ǰ�����ܻ�ȡ����ǰ��ɫ�ʿռ�ģʽ��
// 	virtual ENGINE_APIF UGbool GetBandCombineMode(UGArray<UGint>& aryBand, ImgColorSpace& nColorSpace);	

	//! \brief ���ɫ����ʾģʽ��
// 	ENGINE_APIF UGImageAccessMode GetReadMode() const;	
	//! \brief ����ɫ����ʾģʽ��
	//! \param ReadMode [in]��
	//! \remarks �����ǵ�������ʾģʽ��ʱ��������� ��ǰ��������m_nIndexBand��
	//           ֻ��ʾ��ǰ������Ϣ��
	//           �����ǻ��ɫ����ʾģʽ��ʱ��������ݵ�ǰ��ɫ�ʸ�ʽ����ʾ��
	//            ���ν�����ʾ
	//! \attention
// 	ENGINE_APIF void SetReadMode(UGImageAccessMode ReadMode);

	//! \brief ����bit1,bit4,bit8�ڴ���ʱ��Ҫ����Ĭ�ϵĵ�ɫ�塣
	//! \param &srcInfo [in]UGDatasetRasterInfo ����
	//! \param &destInfo [in]UGDatasetRasterInfo ����
	//! \attention ����srcInfo���������Ͳ�ͬ,���destInfo��ɫֵ��
	ENGINE_APIF void FillColorset(const UGDatasetRasterInfo &srcInfo,UGDatasetRasterInfo &destInfo);
	

private:
	//##ModelId=482030550189
	//! \param nBandIndex[in] ��ȡ��ɫ��ֵ���ڵĲ�������ֵ��Ĭ��Ϊ0
	ENGINE_APIF UGbool CalculateExtremumByRegion(UGdouble &dMax,
		UGdouble& dMin,
		UGGeoRegion * pRegion = NULL, 
		UGPoint * pMaxPt = NULL, 
		UGPoint * pMinPt = NULL,
		UGProgress* pProgress = NULL,UGint nBandIndex=0) ;
public:	

public:
	//! \brief ��ǰ�������굽Ӱ�������ӳ�����.
	//##ModelId=4820305501D4
	UGSize2D m_imgRatio;

 #if PACKAGE_TYPE==PACKAGE_UGC

	//##ModelId=482030550216
	UGColor m_NoDataStyle;

	//##ModelId=482030550224
	UGbyte m_btBackColorTolerance;

	//##ModelId=482030550225
	UGColor m_BackColor;

	// ��ȡ�Ƿ��ʼ����͸��
	virtual bool IsTransparentBack() { return false; }

#endif // end declare ugc sdk

	//!\brief ��ʶդ�����ݼ�֮��ĸ����Ƿ�Ϊͬһ���룬���������ͬ����ֱ�Ӷ���
	UGbool m_bCopyWithSameCodecType;
	
	//! \brief �Ƿ������ͷ��ڴ�ķ�ʽ�޸Ļ����С
	UGbool m_bChangeCacheByDel;

	//! \brief ����blockmanager����block��С��Ĭ����100��
	UGint m_nCacheSize;

protected:

	UGArray<UGImgBlocksManager> m_arrImgManager;

 	//! \brief դ��ֲ���ɫ��ɫ��
	//##ModelId=4820305501D5
 	UGColorTable m_ColorTable;

	//! \brief Raster��Ϣ
	//##ModelId=4820305501D6
	UGDatasetRasterInfo m_RasterInfo;
	
	//! \brief �����ڴ��л����Block����
	//##ModelId=4820305501D7
// 	UGImgBlocksManager m_ImgManager; 
	
	//! \brief �ü�����
	//##ModelId=4820305501E4
	UGGeoRegion* m_pClipRgn;
	
	//##ModelId=4820305501E5
	UGRect2D m_rcViewGeoRef;	//��ʾ�ο�����

	//##ModelId=4820305501E6
	UGbool m_bGeoReferencePrepared;	//����ο������Ƿ���

	//##ModelId=4820305501E7
// 	UGMutex m_mutexBlock;

	//! \brief ���������Ӱ��⣬����������Ӱ�����ݼ�
	//##ModelId=4820305501F4
	UGDatasets m_PyramidDatasets;

	//! \brief ����Ǳ����ݼ��ǽ�������һ�㣬�������ͼ���ָ��
	//##ModelId=4820305501F5
	UGDatasetRaster* m_pParentDataset;

	//! \brief �ļ������·��,�����ⲿ�ļ�ʹ��
	//##ModelId=4820305501F6
	UGString m_strLinkFileName;
	
	//! \brief ��ŵ�ǰBlock��ָ��
	//##ModelId=4820305501F7
	UGImgBlock *m_pBlock; 
	
	//! \brief ����ѹ���Ļ�����
	//##ModelId=482030550203
	UGbyte * m_pBlockCache;

	//! \brief �������Ĵ�С
	//##ModelId=482030550204
	UGuint m_nBlockCacheSize;

	//##ModelId=483BB70C0167
	UGString::Charset m_nCharset;

	//##ModelId=483BB70C0157
// 	UGint m_nBandIndex;

	//! \brief ���ڶ�ȡӰ��ʱ�Ķ�ȡģʽ��ѡȡ�Ĳ���
//	UGImageAccessMode m_nReadMode;

	//! \brief ��ǰӰ���Ĭ��ɫ�ʿռ�
	ImgColorSpace  m_nColorSpace;

	//! GetValue��ȥ���˳�����ȡ������λ��������
	UGuint m_nDiv;
	//! GetValue��ȥ���˳�����ȡ������λ��������
	UGuint m_nMod;
	//! ��¼��m_nDiv,m_nMod�Ƿ�׼����
	UGbool m_bInitImg;

	//դ�����ݼ���ʾ֧��ȡ�� �ص�
	GETVIEWBLOCKCALLBACKPROC m_pGetViewBlockCallBackFunc;
	//դ�����ݼ���ʾ֧��ȡ�� �ص�����
	UGlong m_pWndH;
	//դ�����ݼ���ʾ֧��ȡ�� �ص�����
	UGlong m_pDrawingH;
	//! \brief դ�����Ա����ݼ�
// 	UGDatasetVector *m_pVATDataset;

	//!\brief GetViewBlockʱ�Ƿ�ʹ�ñ����䣬Ŀǰ���ػ�ȡʹ������ҿ����䣬���ʺ���άӦ��
	UGbool m_bSampleClosedInterval;

	//! \brief �����Կ�����SaveBlock�Ƿ���㼫ֵ,����դ������޸�ʱ��֪�����ݼ��ļ�ֵ����ֱ�����ã�����Ҫ�ڱ������ټ���һ�飬�ṩ�����Ч��	
	UGbool m_bAutoComputeExtremum;

};

}

#endif

