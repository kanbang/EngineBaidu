//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class ��
//!  \details ��
//!  \author ��˷��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGVECTORTILEFILE_H__D46B88EA_7586_4BB1_90C1_DEB12E333766__INCLUDED_)
#define AFX_UGVECTORTILEFILE_H__D46B88EA_7586_4BB1_90C1_DEB12E333766__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry/UGFeature.h"
#include "Geometry/UGGeometry.h"

namespace UGC
{	

#define UGVectorTileFileGeoExt _U(".scvb")
#define UGVectorTileFileAttExt _U(".scvd")

	class UGVCGeoRecordHeader
	{
	public:
		UGint m_nRecordSize;
		UGint m_ID;
		UGint m_nType;
	public:
		UGVCGeoRecordHeader(void)
		{
			m_nRecordSize = 0;
			m_ID = -1;
			m_nType = 0;
		};
		~UGVCGeoRecordHeader(void)
		{
		};
	public:
		void operator = (const UGVCGeoRecordHeader &value)
		{
			m_nRecordSize = value.m_nRecordSize;
			m_ID = value.m_ID;
			m_nType = value.m_nType;
		};
		void GetFromGeometry(const UGGeometry* pGeometry);
		
		void Save(UGStream& stream)
		{
			stream.Save((UGint*)&m_nRecordSize,1);
			stream.Save((UGint*)&m_ID,1);
			stream.Save((UGint*)&m_nType,1);
		}
		void Load(UGStream& stream)
		{
			stream.Load((UGint*)&m_nRecordSize,1);
			stream.Load((UGint*)&m_ID,1);
			stream.Load((UGint*)&m_nType,1);
		}
		UGint GetSize()
		{
			return 3*sizeof(UGint);
		}
	};

	class UGVCGeoFileHeader
	{
	public:
		char m_pFlag[4];
		int m_nVersion;
		int m_nSizeofFileHeader;
		int m_nHasAtt;

	public:
		UGVCGeoFileHeader(void)
		{
			strcpy(m_pFlag, "smV");
			UGTime time = UGTime::GetCurTime();			
			m_nVersion = time.GetYear() * 10000 + time.GetMonth() * 100 + time.GetDay();
			m_nSizeofFileHeader = sizeof(UGVCGeoFileHeader);
			m_nHasAtt = 1;
		};
		~UGVCGeoFileHeader(void)
		{
		};

	public:
		void operator = (const UGVCGeoFileHeader &value)
		{
			strcpy(m_pFlag, value.m_pFlag);
			m_nVersion = value.m_nVersion;
			m_nSizeofFileHeader = value.m_nSizeofFileHeader;
			m_nHasAtt = value.m_nHasAtt;
		};

		void Save(UGStream& stream)
		{
			stream.Save((UGachar*)m_pFlag,4);
			stream.Save((UGint*)&m_nVersion,1);
			stream.Save((UGint*)&m_nSizeofFileHeader,1);
			stream.Save((UGint*)&m_nHasAtt,1);
		}
		 void Load(UGStream& stream)
		 {
			 stream.Load((UGachar*)m_pFlag,4);
			 stream.Load((UGint*)&m_nVersion,1);
			 stream.Load((UGint*)&m_nSizeofFileHeader,1);
			 stream.Load((UGint*)&m_nHasAtt,1);
		 }

		 UGint GetSize()
		 {
			 return 4*sizeof(UGachar) + 3*sizeof(UGint);
		 }
			
	};


	class GEOMETRY3D_API UGVectorTileFile
	{
	private:
		UGVectorTileFile(void);

		void Triangulate(UGGeoRegion* pGeoRegion, UGArray<UGushort>& arrIndex);
		void Triangulate(UGGeoRegion* pGeoRegion, UGArray<UGArray<UGushort> >& arrIndexes, UGArray<UGuint>& arrSubCounts);
		void Triangulate(UGGeoRegion* pGeoRegion, UGArray<UGArray<UGuint> >& arrIndexes, UGArray<UGuint>& arrSubCounts);
		UGbool TriangulateSub(UGGeoRegion* pGeoRegion, UGArray<UGushort>& arrIndex);
		UGbool TriangulateSub(UGGeoRegion* pGeoRegion, UGArray<UGuint>& arrIndex);

	public:
		//! \brief ���������ļ�������
		//! \param fCacheVersion �����ļ��İ汾��
		//! \param cacheCodeType �����ļ��ı��뷽ʽ
		UGVectorTileFile(UGfloat fCacheVersion,UGDataCodec::CodecType cacheCodeType);
		~UGVectorTileFile(void);

	public:
		UGbool SaveFeatureToVcFile(const UGArray<UGFeature*> arrFeature, UGString strFileName, UGbool bIgnoreAtt = TRUE/*FALSE*/);
		UGbool LoadFeatureFromVcFile(UGArray<UGFeature*> &arrFeature, UGString strFileName);

		UGbool SaveGeometryArrayToVcFile(const UGArray<UGGeometry*> arrGeometry, UGString strFileName);
		UGbool LoadGeometryArrayFromVcFile(UGArray<UGGeometry*> &arrGeo, UGString strFileName, UGbool &bIgnoreAtt);
		
		UGbool AppendGeometryArrayToVcFile(const UGArray<UGGeometry*> arrGeometry, UGString strFileName);
		UGint LoadGeoFromVcFileByRange(UGArray<UGGeometry*> &arrGeo, UGString strFileName, UGint nStartIndex, UGint nRange, UGbool &bIgnoreAtt);

		//  [7/8/2010 zhangshuo]
		// ���ļ������д�ӿ�
		UGbool SaveFeatureToByteArray(const UGArray<UGFeature*> arrFeature, UGByteArray &arGeoOutput, UGByteArray &arAttOutput, UGbool bIgnoreAtt = TRUE/*FALSE*/);
		UGbool LoadFeatureFromByteArray(UGArray<UGFeature*> &arrFeature,UGByteArray &arGeoInput, const UGByteArray &arAttInput);

		UGbool SaveGeometryArrayToByteArray(const UGArray<UGGeometry*> arrGeometry, UGByteArray &arOutput, UGbool bIgnoreAtt);
		UGbool LoadGeometryArrayFromByteArray(UGArray<UGGeometry*> &arrGeo,UGByteArray &arInput, UGbool &bIgnoreAtt);


		//! \brief ��������ѹ����ʽ
		//! \remarks ��ֻ֧��ZIPѹ��
		virtual UGDataCodec::CodecType GetCompressType() const;

		//! \brief ��������ѹ����ʽ
		//! \remarks ��ֻ֧��ZIPѹ��
		virtual void SetCompressType(UGDataCodec::CodecType eCodecType);
		//! \brief ���û�����ļ��İ汾�ţ�����汾���������ļ��еİ汾��
		void SetCacheVersion(UGfloat fVersion);
		//! \brief ֻ�����������
		UGbool LoadAttributeFromVcFile(UGArray<UGFeature*> &arrFeature, UGString strFileName, const UGString& strPWD = UGString(_U("")));

		//! \brief ֻ�����������
		UGbool LoadAttributeFromByteArray(UGArray<UGFeature*> &arrFeature, const UGByteArray &arrInput, const UGString& strPWD = UGString(_U("")));

	protected:
		UGbool SaveAttributeToVcFile(const UGArray<UGFeature*> arrFeature, UGString strFileName, const UGString& strPWD = (_U("")));
		UGbool LoadAttributeFromVcFile(UGArray<UGFeature*> &arrFeature, UGString strFileName, UGArray<UGGeometry *> arrGeo, const UGString& strPWD = (_U("")));

		UGbool SaveAttributeToByteArray(const UGArray<UGFeature*> arrFeature, UGByteArray &arOutput, const UGString& strPWD = (_U("")));
		UGbool LoadAttributeFromByteArray(UGArray<UGFeature*> &arrFeature, const UGByteArray &arInput, UGArray<UGGeometry *> arrGeo, const UGString& strPWD = (_U("")));
		
		//��ת��С���ֽ�
		void SwapBitDirection(UGbyte *s,int size);

	private:
		FILE *m_pFileGeo;
		FILE *m_pFileAtt;
		//! \�����ļ��İ汾��(scv�а汾�ţ�����Tileѹ����Ϊ�˼�����ǰδ��Tile����ѹ���Ļ�������
		UGfloat m_fCacheVersion;
		//! \brief ��ʾ��ǰϵͳ�Ƿ��Ǵ���ڴ�
		UGbool m_bIsBigEndian;

		//! \brief ��ֻ֧��ZIPѹ��
		UGDataCodec::CodecType m_eCodecType;
	};

}

#endif // !defined(AFX_UGVECTORTILEFILE_H__D46B88EA_7586_4BB1_90C1_DEB12E333766__INCLUDED_)

