// UGPlane.h: interface for the UGPlane class.
//
//////////////////////////////////////////////////////////////////////
/* 
	\file UGPlane.h
	\brief UGC��άƽ����ͷ�ļ���
	\author ������
	\attention
	Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGPLANE_H__FB442292_3E4D_49F8_A98D_245EE80AE3B2__INCLUDED_)
#define AFX_UGPLANE_H__FB442292_3E4D_49F8_A98D_245EE80AE3B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGVector3d.h"

namespace UGC 
{
//! \brief ��άƽ���࣬���Ӿ�����ʹ�á�
//! \remarks 	
class BASE3D_API UGPlane  
{

public:

	//! \brief Ĭ�Ϲ��캯����
	UGPlane();	
	//! \brief ���캯�����ɷ����������ԭ��ľ��빹���档
	//! \param vec ��ķ�����[in]��
	//! \param fDistance �����ԭ��ľ���[in]��
	UGPlane(const UGVector3d& vec,UGdouble fDistance);	
	//! \brief ����������ʲôҲû�ɡ�
	virtual ~UGPlane();
	//! \brief ������б�׼����
	void Normalize();

	//! \brief ��ȡָ���ĵ㵽��ƽ��ľ���ֵ��
	//! \param vPoint ָ������ά�ռ��еĵ�λ��[in]��
	//! \return ���ؼ�������ľ��롣
	UGdouble GetDistance(const UGVector3d& vPoint)const;

	//! \brief ��ȡ��ķ�������
	UGVector3d GetNormal();

	//! \brief ������ķ�������
	void SetNormal(UGVector3d val);

	//! \brief ��ȡ�����ԭ��ľ��롣
	UGdouble GetPlaneDistance();

	//! \brief ���������ԭ��ľ��롣
	void SetPlaneDistance(UGdouble dist);

protected:

	//! \brief ��Ա��ķ�����
	UGVector3d m_vNormal;

	//! \brief ��Ա�����ԭ��ľ���
	UGdouble m_fDistance;
};
}
#endif // !defined(AFX_UGPLANE_H__FB442292_3E4D_49F8_A98D_245EE80AE3B2__INCLUDED_)

