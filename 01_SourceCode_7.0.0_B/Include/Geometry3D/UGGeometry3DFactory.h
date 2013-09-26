//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGGeometry3DFactory.h
//!  \brief ��������Geometry3D�Ĺ����ࡣ
//!  \author UGCTeam��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGGEOMETRY3DFACTORY_H
#define UGGEOMETRYF3DACTORY_H

#include "Geometry3D/UGGeometry3D.h"
#include "Geometry/UGGeometryFactory.h"

namespace UGC
{

//! \brief ��������Geometry3D�Ĺ�����
class GEOMETRY3D_API UGGeometry3DFactory : public UGGeometryFactory
{
public:
	//! \brief ȱʡ���캯����
	UGGeometry3DFactory();    
	
	//! \brief Ĭ������������
    virtual ~UGGeometry3DFactory();

public:

	//! \brief ȷ��pGeometry��ָ��������
	//! \param pGeometry [out] ���ζ���ָ��
	//! \param eType [in] ָ��������
	//! \remarks ��������Ҫ����: �����洫��һ�����ζ�������, ���п���ΪNULL, Ҳ�п��ܲ�����Ҫ������
	//!			 ��ʱ,����Ҫ ���·��� Geometryָ��,new ����Ҫ���͵�Geometry��; ��Ҫ����Recordeset��AddNew�ȵط�
	//! \return ����������·���ռ���,����true; ���򷵻�false
	virtual UGbool AssureGeoType(UGGeometry*& pGeometry, UGint nType);	

	//! \brief ����Geometry���ͣ�����Geometry
	//! \param nType [in] Ҫ�����ļ��ζ������ͣ����Դ���Element���ͣ�Ҳ���Դ���Geometry����
	//! \attention ���ص�Geometryָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����Geometry��ָ��; ʧ�ܷ���NULL
	virtual UGGeometry* CreateGeometry(UGint nType);

	//! \brief ��¡Geometry
	//! \param pGeometry [in] Ҫ����¡��Geometry����ָ��, ����ΪNULL
	//! \attention ���ص�Geometryָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����Geometry��ָ��; ʧ�ܷ���NULL
	virtual UGGeometry* CloneGeometry(const UGGeometry* pGeometry);
#ifndef IOS3D
	//! \brief ��¡ElementΪGeometry
	//! \param pElement [in] Ҫ����¡��Element����ָ��, ����ΪNULL
	//! \attention ���ص�Geometryָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����Geometry��ָ��; ʧ�ܷ���NULL
	virtual UGGeometry* CloneGeometry(const OgdcElement* pElement);
#endif
	//! \brief ����Geometry
	//! \param pGeometrySrc [in] ԭGeometryָ��, ����ΪNULL
	//! \param pGeometryTag [out] Ŀ��Geometryָ��, ����ΪNULL
	//! \remarks ����Geometry�������ͱ���һ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool CopyGeometry(const UGGeometry* pGeometrySrc, UGGeometry* pGeometryTag);
#ifndef IOS3D
	//! \brief ����Element
	//! \param pElement [in] ԭElementָ��, ����ΪNULL
	//! \param pGeometry [out] Ŀ��Geometryָ��, ����ΪNULL
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool CopyGeometry(const OgdcElement* pElement, UGGeometry* pGeometry);
#endif
	//! \brief �ж��Ƿ�֧�ָü�������
	//! \param nType [in] �����Geometry����
	virtual UGbool IsSupport(UGint nType) const;
	
	//! \brief ��ȡGeometry��������
	//! \return ��������
	virtual UGString GetName() const;	

	//! \brief ����������������UGGeometry::Type
	//! \param strGeometryType [in] ���ζ������͵�����
	//! \attention �ϸ����ִ�Сд, �����"GeoPoint"����ʽ
	//! \return �ɹ����ؼ��ζ�������, ʧ�ܷ���0
	virtual UGint GetGeometryType(const UGString& strGeometryType);
	
	//! \brief ����������������UGGeometry::Type
	//! \param strGeometryType [in] ���ζ������͵�����
	//! \attention �ϸ����ִ�Сд, �����"GeoPoint"����ʽ
	//! \return �ɹ����ؼ��ζ�������, ʧ�ܷ���0
	virtual UGString GetGeometryName(UGint nGeoType);

	//! \brief ��Geometry2Dת����Geometry3D��
	//! \param pGeometry [in] ����Geometry2D��ָ�롣
	//! \return �ɹ��򷵻���ά���ζ����ָ��, ʧ�ܷ���null��
	//! \attention Geometry3D���ں�����new�����ģ����渺��������ͷ�
	static UGGeometry3D* Geometry2DToGeometry3D(UGC::UGGeometry* pGeometry); 	

};

extern "C" GEOMETRY3D_API UGGeometryFactory * CreateGeometryFactory();
#if defined(_AIX) //Aix����ȫ�ֺ���������
extern "C" GEOMETRY3D_API UGGeometryFactory * CreateGeometryFactoryA();
#endif 
}

#endif // !defined(UGGEOMETRY3DFACTORY_H)



