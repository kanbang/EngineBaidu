// UGDrawCache.h: interface for the UGDrawCache class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDrawCache.h
   **************************************************************************************
    \author   ���������¹���
    \brief    ��ʾ�����ࡣ                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGDRAWCACHE_H__0B86E90F_8CA8_44B4_AC42_105FDCA8E9BE__INCLUDED_)
#define AFX_UGDRAWCACHE_H__0B86E90F_8CA8_44B4_AC42_105FDCA8E9BE__INCLUDED_

#include "Graphics/UGGraphics.h"

namespace UGC {

class UGDrawParamaters;

class DRAWING_API UGDrawCache  
{
public:
	//! \brief ���캯��
	UGDrawCache();
	//! \brief ��������
#ifdef SYMBIAN60
	~UGDrawCache();
#else
	virtual ~UGDrawCache();
#endif

public:
	//! \brief �ж��Ƿ��Ѿ�����
	//! \return �Ƿ��Ѿ�����
	UGbool IsUsingPreZoom() const;
	//! \brief �����Ƿ��Ѿ�����
	//! \param bUsingPreZoom �Ƿ��Ѿ�����
	void SetUsingPreZoom(UGbool bUsingPreZoom);
	//! \brief �ж��Ƿ��Ѿ��Ż�
	//! \return �Ƿ��Ѿ��Ż�
	UGbool IsOptimizedDraw() const;
	//! \brief �����Ƿ��Ѿ��Ż�
	//! \param bUsingPreZoom �Ƿ��Ѿ��Ż�
	void SetOptimizedDraw(UGbool bOptimizedDraw);
	//! \brief �ж��Ƿ���Ҫ����
	//! \return �Ƿ��Ѿ�����
	UGbool IsRefreshRequired() const;
     //! \brief �����Ƿ���Ҫ����
	//! \param bUsingPreZoom �Ƿ��и���Ҫ��
	void SetRefreshRequired(UGbool bRefreshRequired);
   //! \brief  ��ȡ��ǰͼ����ʾ����
	//! \return ��ʾ����
	UGGraphics* GetGraphics();
	//! \brief ������ʾ����
	//! \param pGraphics Ҫ���õ�ǰͼ����ʾ����
	//! \param pDrawParam Ҫ���õĻ��ʲ���
	//! \return �����Ƿ�ɹ�
	UGbool Prepare(UGGraphics *pGraphics, UGDrawParamaters *pDrawParam);
	//! \brief �ͷŵ�ǰ����
	void Release();
	//! \brief �ж��Ƿ��Ѿ�׼����
	//! \return �Ƿ��Ѿ�׼����
	UGbool IsPrepared();	
	//! \brief ʵ������ת�����߼�����
	//! \param szSize Ҫת����ʵ������,����ת������߼�����
	void DPtoLP(UGSize &szSize);
	//! \brief ʵ������ת�����߼�����
	//! \param rcRect Ҫת���ľ���,����ת������߼�����ľ���
	void DPtoLP(UGRect &rcRect);
	//! \brief �߼�����ת����ʵ������
	//! \param pPoints Ҫת����������ָ��,����ת�����ʵ������
	//! \param nCount �������
	void DPtoLP(UGPoint *pPoints, UGint nCount = 1);
	//! \brief �߼�����ת����ʵ������
	//! \param szSize Ҫת�����߼�����,����ת������߼�����
	
	void LPtoDP(UGSize &szSize);
	//! \brief �߼�����ת����ʵ������
	//! \param rcRect Ҫת���ľ���,����ת�����ʵ������ľ���
	void LPtoDP(UGRect &rcRect);
	//! \brief �߼�����ת����ʵ������
	//! \param pPoints Ҫת����������ָ��,����ת�����ʵ������
	//! \param nCount �������
	void LPtoDP(UGPoint *pPoints, UGint nCount = 1);

protected:
	UGImage* m_pImage;			//��ʾ����
	UGImage * m_pOldImage;	
	UGGraphics* m_pGraphics;
	UGint m_nHeight;
	UGint m_nWidth;

	UGbool m_bIsUsingPreZoom;
	UGbool m_bOptimizedDraw;
	UGbool m_bRefreshRequired;
	UGbool m_bPrepared;
};

}

#endif // !defined(AFX_UGDRAWCACHE_H__0B86E90F_8CA8_44B4_AC42_105FDCA8E9BE__INCLUDED_)

