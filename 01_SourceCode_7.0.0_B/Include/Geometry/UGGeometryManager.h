/*! \file	 UGGeometryManager.h
 *  \brief	 ��������Geometry�Ĺ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
 *  All Rights Reserved
 *  \version $Id: UGGeometryManager.h,v 1.8 2009/05/14 03:00:24 zhouqin Exp $
 */
#ifndef UGGEOMETRYMANAGER_H
#define UGGEOMETRYMANAGER_H

#include "Geometry/UGGeometryDefine.h"

namespace UGC{

//! \brief ��������Geometry�Ĺ�����
class GEOMETRY_API UGGeometryManager
{
public: 
	//! \brief ���캯��
	UGGeometryManager();
	
	//! \brief ��������
#ifdef SYMBIAN60
	~UGGeometryManager();
#else
	virtual ~UGGeometryManager();
#endif

public:	
	//! \brief �õ����ι�������Ŀ��
	static UGint GetGeoFactoryCount();	

	//! \brief ����Geometry���ͣ���ȡָ������Geometry������
	//! \param nType �����Geometry������
	static UGString GetGeoFactoryName(UGGeometry::Type nType);	

	//! \brief ȷ��pGeometry��ָ��������
	//! \param pGeometry ���ζ���ָ��
	//! \param eType ָ��������
	//! \remarks ��������Ҫ����: �����洫��һ�����ζ�������, ���п���ΪNULL, Ҳ�п��ܲ�����Ҫ������
	//!			 ��ʱ,����Ҫ ���·��� Geometryָ��,new ����Ҫ���͵�Geometry��; ��Ҫ����Recordeset��AddNew�ȵط�
	//! \return ����������·���ռ���,����true; ���򷵻�false
	static UGbool AssureGeoType(UGGeometry*& pGeometry, UGint nType);	

	//! \brief ����Geometry���ͣ�����Geometry
	//! \param nType Ҫ�����ļ��ζ������ͣ����Դ���Element���ͣ�Ҳ���Դ���Geometry����
	//! \attention ���ص�Geometryָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����Geometry��ָ��; ʧ�ܷ���NULL
	static UGGeometry* CreateGeometry(UGint nType);

	//! \brief ��¡Geometry
	//! \param pGeometry Ҫ����¡��Geometry����ָ��, ����ΪNULL
	//! \attention ���ص�Geometryָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����Geometry��ָ��; ʧ�ܷ���NULL
	static UGGeometry* CloneGeometry(const UGGeometry* pGeometry);
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS) 
	//! \brief ��¡ElementΪGeometry
	//! \param pElement Ҫ����¡��Element����ָ��, ����ΪNULL
	//! \attention ���ص�Geometryָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����Geometry��ָ��; ʧ�ܷ���NULL
	static UGGeometry* CloneGeometry(const OgdcElement* pElement);
#endif	
	//! \brief ����Geometry
	//! \param pGeometrySrc ԭGeometryָ��, ����ΪNULL
	//! \param pGeometryTag Ŀ��Geometryָ��, ����ΪNULL
	//! \remarks ����Geometry�������ͱ���һ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	static UGbool CopyGeometry(const UGGeometry* pGeometrySrc, UGGeometry* pGeometryTag);
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS) 
	//! \brief ����Element
	//! \param pElement ԭElementָ��, ����ΪNULL
	//! \param pGeometry Ŀ��Geometryָ��, ����ΪNULL
	//! \return �ɹ�����true,ʧ�ܷ���false
	static UGbool CopyGeometry(const OgdcElement* pElement, UGGeometry* pGeometry);
#endif
	//! \brief �ж��Ƿ�֧�ָü�������
	//! \param nType�������Geometry����
	static UGbool IsSupport(UGint nGeoType);

	//! \brief ����������������UGGeometry::Type
	//! \param strGeometryType ���ζ������͵�����
	//! \attention �ϸ����ִ�Сд, �����"GeoPoint"����ʽ
	//! \return �ɹ����ؼ��ζ�������, ʧ�ܷ���0
	static UGint GetGeometryType(const UGString& strGeometryType);
	
	//! \brief ����������������UGGeometry::Type
	//! \param strGeometryType ���ζ������͵�����
	//! \attention �ϸ����ִ�Сд, �����"GeoPoint"����ʽ
	//! \return �ɹ����ؼ��ζ�������, ʧ�ܷ���0
	static UGString GetGeometryName(UGint nGeoType);

	//! \brief ����һ��ָ���ļ����Ķ�̬�⡣
	//! \param strPathName [in]��
	//! \return ���سɹ�����true��
	static UGbool LoadGeometryFactory(const UGString& strPathName);	

	//! \brief ж�ض�̬�⡣
	//! \param hHandle [in] ��̬������
	//! \return �ɹ�ж�ط���true��
	static UGbool UnloadGeometryFactory(void* hHandle);	

	//! \brief �õ����ι������塣
	//! \param nIndex [in] ������
	//! \return ��
	static UGGeometryDefine* GetAt(UGint nIndex);

	// ��� ���ζ����� ���ھ�̬���� for Android by liucq
	UGbool AddGeometryProvider(void* handle);

private:
	//! \brief ��鶯̬���Ƿ�Ϸ�������Ϸ����ʼ������
	//! \param hHandle [in] ��̬������
	UGGeometryDefine* Check(void* hHandle);

	//! \brief �������ü������͵Ķ�̬���Ƿ��Ѿ�����
	//! \param nGeoType [in] ���ζ�������
	UGGeometryDefine* Find(UGint nGeoType);

	//! \brief ���ص�ǰ·��������GeometryFactory
	void LoadGeometryFactory();

	//! \brief ж���Ѿ����ص�GeometryFactory
	void UnloadGeometryFactory();

private:
	UGArray<UGGeometryDefine*> m_geometryDefines;
	UGMutex m_mutex;
};

extern GEOMETRY_API UGGeometryManager g_geometryManager;

}
#endif // !defined(AFX_UGGEOFACTORY_H__78297849_2C23_469A_A6B2_24C8E982EE63__INCLUDED_)

