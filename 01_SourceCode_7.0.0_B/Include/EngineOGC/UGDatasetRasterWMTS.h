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
//!  \author ����ת���顣
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0

#if !defined(AFX_UGDATASETRASTERWMTS_H__7681AA6D_BDCB_4A18_A9A3_EC39CEBB7BE4__INCLUDED_)
#define AFX_UGDATASETRASTERWMTS_H__7681AA6D_BDCB_4A18_A9A3_EC39CEBB7BE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDatasetRasterWeb.h"
#include "MapServiceStub/UGMapServiceStub.h"
#include "MapServiceStub/UGLocalCacheManager.h"

namespace UGC
{
	
	class ENGINEOGC_API UGDatasetRasterWMTS : public UGDatasetRasterWeb 
	{
		friend class UGDataSourceOGC;
	public:
		UGDatasetRasterWMTS();
		virtual ~UGDatasetRasterWMTS();

	public:

		//! \brief �����ݼ�
		virtual UGbool Open();

		//! \brief �ر����ݼ�
		virtual void Close();	

		//! \brief ��ȡ��ǰ���õ���ʾͼ��
		virtual void GetCurrentVisibleLayers(UGArray<UGString>& arrLayers) const;

		//! \brief ���ûص�����
		virtual void SetDownloadResponseFunc(DownloadResponseFunc pFunc,UGlong pWnd);

		//! \brief �����������
		//! \dScale param[in] ��ǰ��ͼ�ı�����
		//! \bound param[in] ��ǰ��ͼ��Χ
		virtual UGbool Request(const UGdouble& dScale, const UGRect2D& bound, UGbool bCallBack = TRUE);

		//! \brief ͨ��������ת����Ƭ�߳���Ӧ�ĵ����С
		//! \param dMapScale ��ͼ������
		virtual UGSize2D GetTileMPSize(UGdouble dMapScale);

		//! \brief ��ȡ��Ƭ��DP��С
		virtual UGSize GetTileSize();

		//! \brief �������еı����߼���
		virtual const UGArray<UGdouble> GetScales() const;

		//! \brief �ж�һ�������Ƿ��Ѿ���ɣ�Request֮�����
		//! \return ��ɷ���True�����򷵻�False
		virtual UGbool IsComplete();

		//! \brief ����ȡ�����ݲ��������������Ӿ��η��ظ��û��Ļص�����
		//! \param pFunc �ص�����[in]��
		//! \param pWnd ���[in]��
		virtual void SetDataChangedFunc(DataChangedProc pFunc,UGlong pWnd);

		//! \brief ���ݷ�Χ�ͱ����ߣ���ѯ��¼����
		//! \param rcMapBounds [in] ��Χ��
		//! \param dScale [in] �����ߡ�
		//! \return ���ط�Χ��������Ƭ����Ϣ
		virtual UGTiles* QueryWithBounds(const UGRect2D& rcMapBounds, UGdouble dScale) const;

		//##ModelId=483BB70C012C
		//! \brief ��ȡ��ʾ��Ӱ��顣
		//! \param rcView ��ȡ����ʾ��Ӱ����С[in]��
		//! \param nDeviceWidth �豸���[in]��
		//! \param nDeviceHeight �豸�߶�[in]��
		//! \return ������ʾ��Ӱ��顣
		virtual UGImgBlock* GetViewBlock(const UGRect2D& rcView, UGint nDeviceWidth, UGint nDeviceHeight, UGbool &bFinished);

		//! \brief ���ػ���Ӱ�������
		//! \tile param ������Ƭ��Ϣ[in]
		//! \return ��Ƭ��ImageData
		virtual UGImageData* LoadTileImageData(const UGTile& tile);

		//! \brief ��ȡ��ӽ��ı�����
		//! \param dScale ���������
		//! \return ������ӽ��Ĺ̶�������
		virtual UGdouble ScaleToNearFixScale(UGdouble dScale);

		//! \brief ����һ����Χ���ż�����Ƭ֮��ķ�Χ
		//! \param dMapScale ��ͼ������
		//! \param rcMapBounds ��ͼ��Χ
		//! \param nExtTileSize ������Ƭ�ĸ���
		//! \return ����֮��ĵ�ͼ��Χ
		virtual UGRect2D ComputeTilesBounds(UGdouble dMapScale, const UGRect2D& rcMapBounds, UGint nExtTileSize = 1);

		//! \brief ��ȡ��ǰ������ƬDP-->LP��ת������
		virtual UGdouble GetCoordRatio();

		//! \brief ���ݷ�Χ�ͱ����ߣ��жϸ÷�Χ�ڵ���Ƭ�Ƿ�ȫ�����ڡ�
		//! \param rcMapBounds [in] ��Χ��
		//! \param dScale [in] �����ߡ�
		//! \return 
		virtual UGbool IsAllTilesExist(const UGRect2D& rcMapBounds, UGdouble dScale) const;

		//! \brief ��ȡ���ػ���İ汾��(Ƕ��ʽʹ��)
		virtual UGint GetCacheVersion() const;

		//! \brief ��ȡ��ǰ����SCI��DP-->LP��ת������(Ƕ��ʽʹ�ã���Ҫ��ʹ��GetCoordRatio�����)
		virtual UGdouble GetCacheCoordRatio();

	private:
		//! \brief ���GetViewBlock��������
		UGMutex m_mutex;

		UGImagePlugin* m_pImagePlugin;
	};

}

#endif // !defined(AFX_UGDATASETRASTERREST_H__7681AA6D_BDCB_4A18_A9A3_EC39CEBB7BE4__INCLUDED_)