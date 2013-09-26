/*! \file	 UGGeometryFactory.h
 *  \brief	 ��������Geometry�Ĺ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
 *  All Rights Reserved
 *  \version $Id: UGGeometryFactory.h,v 1.7 2008/08/05 06:39:31 gaoff Exp $
 */
#ifndef UGGEOMETRYFACTORY_H
#define UGGEOMETRYFACTORY_H

#include "Geometry/UGGeometry.h"

namespace UGC{

//! \brief �ص�������������չ�������
//! \param 		pElement	�ⲿҪ��������չ����
//! \param 		nType		��չ���������
//! \param 		pVoid		ʵ�ָûص����������ָ��
typedef void (UGSTDCALL *CREATEGEOMETRYEXTENDCALLBACKPROC)
(UGGeometry** pGeometry, UGint nType, void* pVoid);

//! \brief ��������Geometry�Ĺ�����
#ifdef SYMBIAN60
class GEOMETRY_APIC UGGeometryFactory
#else
class GEOMETRY_API UGGeometryFactory
#endif
{
public:
	//! \brief ���캯����
	GEOMETRY_APIF UGGeometryFactory();    
	//! \brief ����������
    virtual GEOMETRY_APIF ~UGGeometryFactory();

public:

	//! \brief ȷ��pGeometry��ָ��������
	//! \param pGeometry ���ζ���ָ��
	//! \param eType ָ��������
	//! \remarks ��������Ҫ����: �����洫��һ�����ζ�������, ���п���ΪNULL, Ҳ�п��ܲ�����Ҫ������
	//!			 ��ʱ,����Ҫ ���·��� Geometryָ��,new ����Ҫ���͵�Geometry��; ��Ҫ����Recordeset��AddNew�ȵط�
	//! \return ����������·���ռ���,����true; ���򷵻�false
	virtual GEOMETRY_APIF UGbool AssureGeoType(UGGeometry*& pGeometry, UGint nType);	

	//! \brief ����Geometry���ͣ�����Geometry
	//! \param nType Ҫ�����ļ��ζ������ͣ����Դ���Element���ͣ�Ҳ���Դ���Geometry����
	//! \attention ���ص�Geometryָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����Geometry��ָ��; ʧ�ܷ���NULL
	virtual GEOMETRY_APIF UGGeometry* CreateGeometry(UGint nType);

	//! \brief ��¡Geometry
	//! \param pGeometry Ҫ����¡��Geometry����ָ��, ����ΪNULL
	//! \attention ���ص�Geometryָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����Geometry��ָ��; ʧ�ܷ���NULL
	virtual GEOMETRY_APIF UGGeometry* CloneGeometry(const UGGeometry* pGeometry);
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//! \brief ��¡ElementΪGeometry
	//! \param pElement Ҫ����¡��Element����ָ��, ����ΪNULL
	//! \attention ���ص�Geometryָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����Geometry��ָ��; ʧ�ܷ���NULL
	virtual GEOMETRY_APIF UGGeometry* CloneGeometry(const OgdcElement* pElement);
#endif
	//! \brief ����Geometry
	//! \param pGeometrySrc ԭGeometryָ��, ����ΪNULL
	//! \param pGeometryTag Ŀ��Geometryָ��, ����ΪNULL
	//! \remarks ����Geometry�������ͱ���һ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool CopyGeometry(const UGGeometry* pGeometrySrc, UGGeometry* pGeometryTag);
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//! \brief ����Element
	//! \param pElement ԭElementָ��, ����ΪNULL
	//! \param pGeometry Ŀ��Geometryָ��, ����ΪNULL
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool CopyGeometry(const OgdcElement* pElement, UGGeometry* pGeometry);
#endif
	//! \brief �ж��Ƿ�֧�ָü�������
	//! \param nType�������Geometry����
	virtual GEOMETRY_APIF UGbool IsSupport(UGint nType) const;
	
	//! \brief ��ȡGeometry��������
	virtual GEOMETRY_APIF  UGString GetName() const;	

	//! \brief ����������������UGGeometry::Type
	//! \param strGeometryType ���ζ������͵�����
	//! \attention �ϸ����ִ�Сд, �����"GeoPoint"����ʽ
	//! \return �ɹ����ؼ��ζ�������, ʧ�ܷ���0
	virtual GEOMETRY_APIF UGint GetGeometryType(const UGString& strGeometryType);
	
	//! \brief ����������������UGGeometry::Type
	//! \param strGeometryType ���ζ������͵�����
	//! \attention �ϸ����ִ�Сд, �����"GeoPoint"����ʽ
	//! \return �ɹ����ؼ��ζ�������, ʧ�ܷ���0
	virtual GEOMETRY_APIF UGString GetGeometryName(UGint nGeoType);
};



}

#endif // !defined(AFX_UGGEOFACTORY_H__78297849_2C23_469A_A6B2_24C8E982EE63__INCLUDED_)

