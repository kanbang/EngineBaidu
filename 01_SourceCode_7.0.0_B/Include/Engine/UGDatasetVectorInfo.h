/*! \file	 UGDatasetVectorInfo.h
 *  \brief	 ʸ�����ݼ���Ϣ����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDatasetVectorInfo.h,v 1.15 2010/05/12 06:46:34 zhouqin Exp $
 */

#ifndef UGDATASETVECTORINFO_H
#define UGDATASETVECTORINFO_H

#include "Engine/UGDataset.h"
#include "SpatialIndex/UGSpatialIndexInfo.h"

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
#include "OGDC/OgdcDatasetVectorInfo.h"
#endif

namespace UGC {

//! \brief ʸ�����ݼ���Ϣ��
//##ModelId=482030520233
class ENGINE_API UGDatasetVectorInfo  
{
public:
	//! \brief  ���캯��
	//##ModelId=482030520242
	UGDatasetVectorInfo();
	//! \brief  ��������
	//##ModelId=482030520243
	~UGDatasetVectorInfo();

	//##ModelId=482030520244
	void SetToleranceToDefault();

	//! \brief  �õ���ǰ����������
	//##ModelId=482030520245
	UGint GetIndexType()
	{
		return m_nIndexType;
	};
	//##ModelId=482030520246
	void SetIndexType(IndexType nIdxType)
	{
		m_nIndexType = nIdxType;
	};

	// �������ݼ���Ϣ�����ݼ�����
	// param nCharset[in] �ַ�������
	void SetCharset(UGString::Charset nCharset);

	// �õ����ݼ���Ϣ�����ݼ�����
	// return ���ݼ���Ϣ�ı���
	UGString::Charset GetCharset();

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
public:
	//! \brief �� OgdcDatasetVectorInfo ��ת������ UGDatasetVectorInfo ת��Ϊ OgdcDatasetVectorInfo
	//##ModelId=483BB70A0271
	OgdcDatasetVectorInfo ToOgdcDatasetVectorInfo() const;

	//! \brief �� OgdcDatasetVectorInfo ��ת������ OgdcDatasetVectorInfo �õ� UGDatasetVectorInfo
	//##ModelId=483BB70A0273
	UGbool FromOgdcDatasetVectorInfo(const OgdcDatasetVectorInfo& OgdcInfo);
#endif
public:
	//!  \brief ���ݼ�����
	//##ModelId=482030520248
	UGString m_strTableName;

	//!  \brief ���ݼ�����
	//##ModelId=482030520248
	UGString m_strName;

	//! \brief  ���ݼ�����
	//##ModelId=482030520252
	UGDataset::DatasetType m_nType;

	//!  \brief ѡ����Ϣ
	//##ModelId=482030520256
	UGint m_nOptions;
	
	//! \brief  �������
	//##ModelId=482030520257
	UGint m_nObjectCount;

	//! \brief  �������� 
	//##ModelId=482030520258
	UGint	m_nIndexType;
	
	//!  \brief ����������־
	//##ModelId=482030520259
	UGint	m_nDynamicIndex;
	
	//!  \brief ��������ר�ò���
	//##ModelId=482030520261
	UGPoint2D m_pntIdxCenter;
	//##ModelId=482030520262
	UGdouble  m_dbGridRatio;
	//##ModelId=482030520263
	UGdouble  m_dbdGrid0;
	//##ModelId=482030520264
	UGdouble  m_dbdGrid1;
	//##ModelId=482030520265
	UGdouble  m_dbdGrid2;
		
	//! \brief  �ռ���������
	//##ModelId=482030520271
	UGint m_nSpatialIndexLevel;
		
	//!  \brief ���ݼ���Bounds
	//##ModelId=482030520272
	UGRect2D m_rc2Bounds;

	//! \brief  ��άBounds����Сֵ
	//##ModelId=482030520273
	UGdouble m_dMinZ;

	//! \brief  ��άBounds�����ֵ
	//##ModelId=482030520274
	UGdouble m_dMaxZ;
	
	//!  \brief ���ݼ������������õ�Bounds
	//##ModelId=482030520275
	UGRect2D m_rc2IndexedBounds;	

	//! \brief  ���µ�����Ϊ�������˹�ϵ���༭ʱʹ��
	//UGdouble m_dToleranceFuzzy;
	//���������ޣ���ֻ�ڳ�����������ʹ�ã�Ӧ��ӦSFC�е�NodeSnap
	UGdouble m_dToleranceExtend;
	
	//����㲶׽���ޣ�������ʹ�ã�Ӧ��ӦSFC�е�Fuzzy
	UGdouble m_dToleranceNodeSnap;

	//##ModelId=482030520281
	UGdouble m_dToleranceDangle;	
	
	//##ModelId=482030520283
	UGdouble m_dToleranceSmallPolygon;
	//##ModelId=482030520284
	UGdouble m_dToleranceGrain;

	//! \brief  Tin���ݼ����������ʹ��
	//##ModelId=482030520285
	UGdouble m_dTinTolerance;

	//! \brief  ��������������״̬
	//##ModelId=482030520290
	UGint m_nCheckedUserID;
	//##ModelId=482030520291
	UGint m_nLockedUserID;
	//##ModelId=482030520292
	UGint m_nState;

	//! \brief  ���ݱ�������
	//##ModelId=482030520293
	UGint m_nCodecType;	

	//! \brief ���ݼ���������Ϣ
	//##ModelId=482030520294
	UGString m_strDescription;	

	//! \brief ���ݼ��ĸ�����Ϣ
	//##ModelId=482030520294
	UGString m_strExtInfo;	

	//! \brief �����ݼ���ID
	UGint m_nParentID;

	//! \brief ��ʶ�������ݼ��Ƿ���3D Network
	UGbool m_bIs3DNetwork;
};

}

#endif


