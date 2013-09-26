/*! \file	 UGGeometryDefine.h
 *  \brief	 ��������Geometry�Ĺ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
 *  All Rights Reserved
 *  \version $Id: UGGeometryDefine.h,v 1.4 2009/05/14 03:00:24 zhouqin Exp $
 */

#ifndef UGGEOMETRYDEFINE_H
#define UGGEOMETRYDEFINE_H

#include "Geometry/UGGeometryFactory.h"
#if defined OS_ANDROID || defined IOS
#include "GeometryCAD/UGGeometryCADFactory.h"
#endif
namespace UGC{

//! \brief ��������Geometry�Ĺ�����
class GEOMETRY_API UGGeometryDefine
{
public:
	//! \brief ���캯����
	UGGeometryDefine();    
	//! \brief ����������
#ifdef SYMBIAN60
    ~UGGeometryDefine();
#else
	virtual ~UGGeometryDefine();
#endif

public:
	//! \brief ����
	UGString m_strName;

	void* m_hHandle;
	UGGeometryFactory *m_pGeoFactory;
};



}

#endif // UGGEOMETRYDEFINE_H

