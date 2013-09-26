//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief
//!  \details
//!  \author ��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGSIMPLESPLINE_H__07E8BCDA_D3A9_431B_A917_E7A1D7351969__INCLUDED_)
#define AFX_UGSIMPLESPLINE_H__07E8BCDA_D3A9_431B_A917_E7A1D7351969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGMatrix4d.h"

namespace UGC
{
//! \brief ������ֵ
class BASE3D_API UGSimpleSpline
{
public:
	//! \brief ���캯��
	UGSimpleSpline();

	//! \brief ��������
	~UGSimpleSpline();

	//! \brief ��ӵ�����
	//! \param vec ������[in]��
	void AddPoint(const UGVector3d& vec);

	//! \brief �����������ĳ������
	//! \param uIndex ����[in]��
	const UGVector3d& GetPoint(UGushort uIndex) const;

	//! \brief �����Ҫ������ֵ�ĵ����ݸ���
	UGushort GetNumPoints(void) const;

	//! \brief ��յ�ǰ����
	void Clear(void);

	//! \brief ����ָ��λ�õ�����
	//! \param uIndex ����[in]��
	//! \param vec ������[in]��
	void UpdatePoint(UGushort uIndex, const UGVector3d& vec);

	//! \brief ����t��������ò�ֵ����
	//! \param t ����ֵ[in]��
	UGVector3d Interpolate(UGdouble t) const;

	//! \brief ����t��������ò�ֵ����
	//! \param fromIndex ��ʼ����[in]��
	//! \param t �������ʼ�����ı���ֵ[in]��
	UGVector3d Interpolate(UGushort fromIndex, UGdouble t) const;

	//! \brief �Ƿ��Զ�����,�����µ�ʱ�������¼������в���
	void SetAutoCalculate(UGbool autoCalc);

	//! \brief ���¼������в���
	void RecalcTangents(void);

protected:

	//! \brief �Զ������ʶ
	UGbool m_bAutoCalc;

	//! \brief ������ֵ������
	UGArray<UGVector3d> m_arrPoints;

	//! \brief ���в���
	UGArray<UGVector3d> m_arrTangents;

	//! brief Hermite������ʽ
	UGMatrix4d m_matCoeffs;
};
}
#endif // !defined(AFX_UGSIMPLESPLINE_H__07E8BCDA_D3A9_431B_A917_E7A1D7351969__INCLUDED_)


