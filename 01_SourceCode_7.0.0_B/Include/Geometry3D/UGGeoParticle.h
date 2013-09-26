//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGGeoRegion3D.h
//!  \brief ��ά����ϵͳ����
//!  \author UGCTeam��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOPARTICLE_H__INCLUDED_)
#define AFX_UGGEOPARTICLE_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParticleSystem/UGParticleEffect.h"
#include "Geometry3D/UGGeometry3D.h"

namespace UGC
{

class GEOMETRY3D_API UGGeoParticle : public UGGeometry3D
{
public:
	//! \brief Ĭ�Ϲ��캯������Ҫ����ʹ��MakeWithGeometry����AddSub��ָ�����ӵĵ���λ��
	UGGeoParticle();

	//! \brief ���캯�����ⲿ���ɺõ�����Ч�����������
	//! \param pParticleEffect [in] �ⲿ���ɺõ�����Ч������
	//! \param pGeometry [in] Ҫ����������Geometry����
	//! \param bIsAutoRelease [in] ָ����Ҫ�ⲿ�ͷŻ����ڲ��ͷţ�ΪtrueΪ�ڲ��ͷš�
	UGGeoParticle(UGParticleEffect* pParticleEffect,const UGGeometry* pGeometry, UGbool bIsAutoRelease = FALSE);

	//! \brief ���캯����ͨ��·�������ڲ�������Ч������
	//! \param strParticleResFileName [in] *.par����Ч����Դ�ļ�·�����ڲ��Զ���������Ч���࣬���Զ��ͷš�
	//! \param pGeometry [in] Ҫ����������Geometry����
	UGGeoParticle(const UGString& strParticleResFileName, const UGGeometry* pGeometry);

	//! \brief ��������
	virtual ~UGGeoParticle();

public:

	//! \return ���ص�ǰ���Զ��ͷű�ǩ
	UGbool GetCurrentAutoRelease() const {return m_bIsAutoRelease;}

	//! \return ���ص�ǰ���Զ��ͷű�ǩ
	void SetCurrentAutoRelease(UGbool bVal) {m_bIsAutoRelease = bVal;}

	//! \brief ��ȡ��ǰ��������
	UGint GetCurrentParticleEffectType();

	//! \brief ��̬��������Ч������Դ�ļ�·�����ڲ����Ϊ�Զ��ͷ�
	//! \return ��������Ч����
	UGParticleEffect* SetCurrentParticleEffectResFileName(const UGString& strParticleResFileName);
	
	//! \brief ��ȡ��ǰ�����ļ�·��
	UGString GetCurrentParticleEffectResFileName();

	//! \brief ��������Ч����
	//! \param pParticleEffect [in] �ⲿ���ɺõ�����Ч������
	//! \param bIsAutoRelease [in] ָ����Ҫ�ⲿ�ͷŻ����ڲ��ͷţ�ΪtrueΪ�ڲ��ͷš�
	void SetParticleEffect(UGParticleEffect* pParticleEffect, UGbool bIsAutoRelease = FALSE);
	
	//! \brief ��������Ч���ࡣ
	//! \return ��������Ч���ࡣ
	UGParticleEffect* GetParticleEffect();

	//! \brief ��������Ч���ࡣ
	//! \return ��������Ч���ࡣ
	const UGParticleEffect* GetParticleEffect() const;

	//! \brief ͨ������Geometry�������GeoParticle��ֻ��������geometry�ڲ��ĵ㴮��
	//! \return �Ƿ���ɹ���
	virtual UGbool MakeWithGeometry( const UGGeometry* pGeometry);
	
	//! \brief ��������GeoParticle
	//! \param geoParticle [in] �������Ӷ���
	//! \return �������Ӷ���Ƿ�, ����false��
	UGbool Make(const UGGeoParticle& geoParticle);

	//! \brief �õ����ζ������͡�
	//! \return �̶�Ϊ GeoParticle��
	virtual UGGeometry::Type GetType() const;	

	//! \brief �õ��ڵ㣨��Geometry3D���Ӧ��Geometry�ڲ�����������ĵ㣩
	//! \return �����ڵ�
	virtual UGPoint2D GetInnerPoint() const;	

	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid() const;

	//! \brief ��ȡ����������ά�㡣
	//! \remarks �����ڲ���GeoModel������ڲ����õ���GeoModel��Position��
	//! \return ��ά�㡣
	virtual UGPoint3D GetInnerPoint3D() const;

	UGbool GetParticleEffectFileChanged()
	{
		return m_bParticleFileChanged;
	}

	void SetParticleEffectFileChanged( UGbool other)
	{
		m_bParticleFileChanged = other;
	}

public:
	//! \brief ��յ�������
	virtual void Clear();

	//! \brief �������Ӷ���ĸ���Geometry.
	//! \param pPoints [in] �㴮ָ�롣
	//! \param pPolyCount [in] �Ӷ����е��������顣
	//! \param nSubCount [in] �Ӷ�����Ŀ��
	//! \return �����Ӷ���ĵ�����С��2��,����false��
	virtual UGbool Make( const UGPoint2D* pPoints, const UGint* pPolyCount, UGint nSubCount );

	//! \brief �������������
	//! \param pPoints [in] �㴮ָ�롣
	//! \param pPolyCount [in] �Ӷ����е��������顣
	//! \param nSubCount [in] �Ӷ�����Ŀ��
	//! \return �����Ӷ���ĵ�����С��3��,����false��
	UGbool Make(const UGPoint3D* pPoints, const UGint* pPolyCount, UGint nSubCount);

	//! \brief �õ�ָ���Ӷ���ĵ㴮��ָ�롣
	//! \param nSubIndex [in] �Ӷ���������
	//! \return �����Ӷ���ĵ㴮��ָ�롣
	const UGPoint3D* GetPoints(UGint nSubIndex=0) const;	

	//! \brief �õ�ָ���Ӷ���ĵ㴮��ָ�롣
	//! \param nSubIndex [in] �Ӷ���������
	//! \return �����Ӷ���ĵ㴮��ָ�롣
	UGPoint3D* GetPoints(UGint nSubIndex=0);	

	//! \brief �����Ӷ���
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮������
	//! \return ��ĸ�������3��,����false��
	UGbool AddSub(const UGPoint3D* pPoints, UGint nPntCount);	

	//! \brief �����Ӷ���
	//! \param nIndex [in] Ҫ�����λ��������
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�е�ĸ�����
	//! \return �����С��3��������λ�÷Ƿ�,����false��
	UGbool InsertSub(UGint nIndex, const UGPoint3D* pPoints, UGint nPntCount);	

	//! \brief ɾ���Ӷ���
	//! \param nIndex [in] Ҫɾ�����Ӷ����λ��������
	//! \return �����Ƿ�, ����false��
	UGbool DelSub(UGint nIndex);

	//! \brief �õ��Ӷ�����Ŀ������ָ�롣
	//! \return �����Ӷ�����Ŀ������ָ�롣
	const UGint* GetPolyCounts() const;

	//! \brief �õ������Ӷ���ĵ�ĸ����ܺ͡�
	//! \return ���ظ�����
	UGint GetPointCount() const;	

	//! \brief �õ��Ӷ���ĸ���
	//! \return ���ظ���
	virtual UGint GetSubCount() const;

	//! \brief �õ�ĳ���Ӷ���ĵ�ĸ�����
	//! \param nSubIndex [in] �Ӷ���������
	//! \return ���ظ�����
	UGint GetSubPntCount(UGint nSubIndex) const;

public:
	//! \brief ��ά��������
	//! \param dRatioX [in] X�������ű���
	//! \param dRatioY [in] Y�������ű���
	//! \param dRatioZ [in] Z�������ű���
	virtual void Inflate3D( UGdouble dRatioX, UGdouble dRatioY, UGdouble dRatioZ);

	//! \brief ��ά��������
	//! \param dRatio [in] ���ű���(X,Y,Z������ͬ)	
	virtual void Inflate3D( UGdouble dRatio);

	//! \brief ��ά����ƽ��
	//! \param dX [in] ƽ�Ƶ�Xƫ����
	//! \param dY [in] ƽ�Ƶ�Yƫ����	
	//! \param dZ [in] ƽ�Ƶ�Zƫ����	
	virtual void Offset3D( UGdouble dX, UGdouble dY, UGdouble dZ);

	//! \brief ��ά����ƽ��
	//! \param dOffset [in] ƫ����(X,Y,Z������ͬ)	
	virtual void Offset3D( UGdouble dOffset);

	//! \brief ��ά����ƽ��
	//! \param vecOffset [in] ƽ�Ƶ�ƫ����(�ֱ���UGVector3d�е�x,y,z����X,Y,Z�����ƫ����)��
	virtual void Offset3D( const UGVector3d &vecOffset);	
	
	//! \brief ��ά������ת
	//! \param vecAxis [in] ��ת�� ��ԭ��
	//! \param dAngle [in] ��ת�Ƕ�
	virtual void Rotate3D(const UGVector3d& vecAxis, UGdouble dAngle);

	virtual void SetPosition(const UGPoint3D& value);

public:
	//! \brief �õ�ά��, ��Ϊ0ά, ��/���ߵ�Ϊ1ά, ��/�����Ϊ2ά, GeoCompound/GeoText��Ϊ-1
	virtual UGint GetDimension() const;

	//! \brief ֻ���漸�����ݲ��֡�
	//! \param stream [in] �洢��, ����֮ǰӦ����Open��
	//! \param eCodecType [in] �洢�ı��뷽ʽ��
	//! \param FALSE [in] �Ƿ�洢ΪSDBPlus�ĸ�ʽ��
	//! \return �ɹ�����true,ʧ�ܷ���false��
	//! \remarks ����SDBPlus��������ݿ�����Ĵ洢�ϲ��ϴ�,���Ա���ֱ�ӵ��øú���,�����ӱ������зֱ���
	//! \attention ��SDBPlus����,���ò�public֮��
	virtual UGbool SaveGeoData(UGStream& stream, 
		UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	//! \brief ֻת�ؼ������ݲ���
	//! \param stream [in] �� 
	//! \param eCodecType [in] ���뷽ʽ
	//! \attention ����Ҫ���� UGbool bSDBPlus = FALSE �Ĳ���
	//! \return �ɹ�����true,ʧ�ܷ���false	
	virtual UGbool LoadGeoData( UGStream& stream , 
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );

	//! \brief �洢����ĸ�������,����Geometry�洢��һ�������
	//! \brief ������ߴ洢ʹ�õ���������Ӳ����ֿ�
	//! \return �ɹ�����TRUE,ʧ�ܷ���FLASE
	virtual UGbool SaveExtData(UGArray<UGTextureInfo>& arryTextureInfo);

	//! \brief ���ض����������ݵ����ζ�����
	//! \return �ɹ�����TRUE,ʧ�ܷ���FLASE
	virtual UGbool LoadExtData(const UGArray<UGTextureInfo>& arrayTextureInfos);

	//! \brief ͨ�����ζ����б��������·����ʼ��������Ϣ
	//! \return �ɹ�����TRUE,ʧ�ܷ���FLASE
	virtual UGbool InitialTextureInfo(UGArray<UGTextureInfo>& arrayTextureInfos);


	//! \brief ��Geometry����XML�ַ���
	//! \param versionType [in] GML�İ汾
	//! \param nPace [in] �����Ŀո���Ŀ,ʹ��xml�ַ������������˹��Ķ�; 
	//! ��Ҫ����������ص�xml�ַ�����һ�����ǩ�е�һ����, ͨ��ָ���ո���Ŀ,����ʹ�������
	//! \return ����ָ��GML�汾��xml�ַ���
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGString ToXML(GMLVersionType versionType, UGint nPace = 0)  const;

	//! \brief ��XML�ַ���������Geometry
	//! \param strXML [in] xml��ʽ�ַ���
	//! \param versionType [in] xml�ַ�����GML�汾
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual UGbool FromXML(const UGString& strXML, GMLVersionType versionType);

protected:
	//! \brief ��������BoundingBox
	//! \remarks ���ڻ�ȡ����Model���ڲ���Ϣ������������õ��ǵĲ�����GeoPoint��һ�¡�
	//! \return ���صõ���BoundingBox
	virtual UGBoundingBox ComputeBoundingBox() const;

	//! \brief ��������Bounds
	//! \return ���صõ���Bounds
	//! \remarks ת��2ά��Geometry�󣬵������ķ���ʵ��
	virtual UGRect2D ComputeBounds() const;	

private:

	UGPoint2D ComputeGeoLineInnerPoint() const;

	UGPoint2D ComputeGeoRegionInnerPoint() const;

	UGPoint3D ComputeGeoRegionInnerPoint3D() const;

	UGPoint3D ComputeGeoLineInnerPoint3D() const;

	//! \brief ���ڲ�����ά������ת�ɶ�ά��
	//! \return ���ض�ά��ָ�룬����ע��ʹ�ú��ͷš�	
	UGPoint2D* GetPoint2Ds() const;

	void ComputePosition();

private:

	//! \brief ����Ч��
	UGParticleEffect* m_pParticleEffect;

	//! \brief �Ƿ��Զ��ͷ�UGParticleEffect��Ĭ����TRUE
	UGbool m_bIsAutoRelease;

	//! \brief �����㴮
	// ���ⲿ�ı�����������ص�Geometry��λ�ã��������ڲ��ļ��ε���ϢҲ��Ҫ����
	UGArray<UGPoint3D> m_Point3Ds;

	//! \brief ������� �����Ӷ���ĵ�ĸ��� ��Ϣ����������
	// ���ⲿ�ı�����������ص�Geometry��λ�ã��������ڲ��ļ��ε���ϢҲ��Ҫ����
	UGArray<UGint> m_PolyCounts;

	//! \brief ��¼���ӵ��ⲿGeometry��Դ��Ĭ����null
	UGint m_nGeometryTypeSrc;

	UGbool m_bParticleFileChanged;

};

}

#endif

