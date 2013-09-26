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

#if !defined(AFX_UGDATASETRASTERWEB_H__7681AA6D_BDCB_4A18_A9A3_EC39CEBB7BE4__INCLUDED_)
#define AFX_UGDATASETRASTERWEB_H__7681AA6D_BDCB_4A18_A9A3_EC39CEBB7BE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDatasetRaster.h"
namespace UGC
{
	class UGMapServiceStub;
	class UGMapServiceParams;
	class UGLocalCacheManager;
	class UGMapCacheFile;
	struct UGDownloadTileInfo;
	struct UGDataChangeInfo;
	class  UGTile;
	struct UGImageData;
	typedef UGArray<UGTile*> UGTiles;

	typedef void (UGSTDCALL * DownloadResponseFunc) (UGDownloadTileInfo result, UGlong pWnd);

	typedef void (UGSTDCALL * DataChangedProc) (const UGDataChangeInfo& ChangeInfo, UGlong pWnd);

	typedef void (UGSTDCALL * RequestFinishedProc) (UGlong pWnd);

	class ENGINE_API UGDatasetRasterWeb : public UGDatasetRaster  
	{
	public:
		UGDatasetRasterWeb();
		virtual ~UGDatasetRasterWeb();

	public:

		//! \brief �����ݼ�
		virtual UGbool Open() = 0;

		//! \brief �ر����ݼ�
		virtual void Close() = 0;	

		//! \brief �ж��Ƿ�������դ�����ݼ�
		virtual UGbool IsWebRaster();

		//!	\brief	���û����ļ���λ��
		virtual UGbool SetBufferPath(const UGString& strBuffPath);

		//! \brief ��ȡ�����ļ���λ��
		virtual UGString GetBufferPath() const;

		//! \brief ������ʾͼ��
		//! \arrLayers param[in] ��ʾ��ͼ��
		//                       GoogleMaps������ʾ�ĵ�ͼ���ͣ�ֻ��������һ������
		//                       wms���ÿɼ�ͼ��
		//                       ��ͼ�Ʒ���Ԥ�������÷�������
		virtual UGbool SetVisibleLayers(const UGArray<UGString>& arrLayers);

		//! \brief ��ȡ��ǰ���õ���ʾͼ��
		virtual void GetCurrentVisibleLayers(UGArray<UGString>& arrLayers) const;

		//! \brief �������ݼ�ͶӰ��������������Դ�򿪵�ʱ�����
		virtual UGbool SetPrjCoordSys(const UGPrjCoordSys &PrjCoordSys);

		//! \brief ���ûص�����
		virtual void SetDownloadResponseFunc(DownloadResponseFunc pFunc, UGlong pWnd) = 0;

		//! \brief �����������
		//! \dScale param[in] ��ǰ��ͼ�ı�����
		//! \bound param[in] ��ǰ��ͼ��Χ
		//! \bCallBack ������Ƭ����ʱ�Ƿ�ص�
		virtual UGbool Request(const UGdouble& dScale, const UGRect2D& bound, UGbool bCallBack = TRUE) = 0;

// 		//! \brief ��ȡ������Ƭ����
// 		//! \tile param[in,out] ������Ƭ����
// 		virtual UGbool GetTileData(UGTile& tile){return FALSE;}
// 
// 		//! \brief ���ݴ����TileData�еı����ߣ���ȡTile�ĵ���Χ�����ط�Χ
// 		//! \tile param[in,out] ������Ƭ��Ϣ
// 		virtual void GetTileInfo(UGTile& tileData){return ;}

		//! \brief ͨ��������ת����Ƭ�߳���Ӧ�ĵ����С
		//! \param dMapScale ��ͼ������
		virtual UGSize2D GetTileMPSize(UGdouble dMapScale) = 0;

		//! \brief ��ȡ��Ƭ��DP��С
		virtual UGSize GetTileSize() = 0;

// 		//! \brief �ж�һ�������Ƿ��Ѿ���ɣ�Request֮�����
// 		//! \return ��ɷ���True�����򷵻�False
 		virtual UGbool IsComplete() = 0;

		//! \brief �������еı����߼���
		virtual const UGArray<UGdouble> GetScales() const = 0;	

		//! \brief ����ȡ�����ݲ��������������Ӿ��η��ظ��û��Ļص�����
		//! \param pFunc �ص�����[in]��
		//! \param pWnd ���[in]��
		virtual void SetDataChangedFunc(DataChangedProc pFunc, UGlong pWnd) = 0;

// 		//! \brief ���ø����û�������ɵĻص�����
// 		//! \param pFunc �ص�����[in]��
// 		//! \param pWnd ���[in]��
// 		virtual void SetRequestFinishedFunc(RequestFinishedProc pFunc,UGlong pWnd){return ;}

		//! \brief ���ݷ�Χ�ͱ����ߣ���ѯ��¼����
		//! \param rcMapBounds [in] ��Χ��
		//! \param dScale [in] �����ߡ�
		//! \return ���ط�Χ��������Ƭ����Ϣ 
		virtual UGTiles* QueryWithBounds(const UGRect2D& rcMapBounds, UGdouble dScale) const = 0;

		//##ModelId=483BB70C012C
		//! \brief ��ȡ��ʾ��Ӱ��顣
		//! \param rcView ��ȡ����ʾ��Ӱ����С[in]��
		//! \param nDeviceWidth �豸���[in]��
		//! \param nDeviceHeight �豸�߶�[in]��
		//! \return ������ʾ��Ӱ��顣
		virtual UGImgBlock* GetViewBlock(const UGRect2D& rcView, UGint nDeviceWidth, UGint nDeviceHeight, UGbool &bFinished) = 0;	

		//! \brief ���ػ���Ӱ�������
		//! \tile param ������Ƭ��Ϣ[in]
		//! \return ��Ƭ��ImageData
		virtual UGImageData* LoadTileImageData(const UGTile& tile) = 0;

		//! \brief ��ȡ��ӽ��ı�����
		//! \param dScale ���������
		//! \return ������ӽ��Ĺ̶�������
		virtual UGdouble ScaleToNearFixScale(UGdouble dScale) = 0;

		//! \brief ����һ����Χ���ż�����Ƭ֮��ķ�Χ
		//! \param dMapScale ��ͼ������
		//! \param rcMapBounds ��ͼ��Χ
		//! \param nExtTileSize ������Ƭ�ĸ���
		//! \return ����֮��ĵ�ͼ��Χ
		virtual UGRect2D ComputeTilesBounds(UGdouble dMapScale, const UGRect2D& rcMapBounds, UGint nExtTileSize = 1) = 0;

		//! \brief ��ȡ��ǰ������ƬDP-->LP��ת������
		virtual UGdouble GetCoordRatio() = 0;

		//! \brief ���ݷ�Χ�ͱ����ߣ��жϸ÷�Χ�ڵ���Ƭ�Ƿ�ȫ�����ڡ�
		//! \param rcMapBounds [in] ��Χ��
		//! \param dScale [in] �����ߡ�
		//! \return 
		virtual UGbool IsAllTilesExist(const UGRect2D& rcMapBounds, UGdouble dScale) const = 0;

		//! \brief ��ȡ���ػ���İ汾��(Ƕ��ʽʹ��)
		virtual UGint GetCacheVersion() const = 0;

		//! \brief ��ȡ��ǰ����SCI��DP-->LP��ת������(Ƕ��ʽʹ�ã���Ҫ��ʹ��GetCoordRatio�����)
		virtual UGdouble GetCacheCoordRatio() = 0;

	public:
		//! \brief �����Ƿ���Ա�͸��
		void SetCanBeTransparent(UGbool bTransparent){m_bCanBeTransparent = bTransparent;}

		//! \brief ��ȡ�Ƿ���Ա�͸��
		UGbool GetCanBeTransparent(){return m_bCanBeTransparent;}

	protected:
		//! \brief ��������Դʱȡ�Ĳ���
		virtual UGString ParamsToString() const;

		//! \brief ������Դʱ���ò���
		virtual void StringToParams(const UGString& strParams);

		//! \brief �����������ع�����
		void SetMapServiceStub(UGMapServiceStub* pMapServiceStub);

		//! \brief ��������������
		void SetMapServiceParams(UGMapServiceParams* pMapServiceParams);

		//! \brief �������ع�����
		UGMapServiceStub* m_pMapServiceStub;

		//! \brief ����������
		UGMapServiceParams* m_pMapServiceParams;

		//! \brief �����ļ���λ��
		UGString m_strBufferPath;

		//! \brief ���ػ��������
		UGLocalCacheManager* m_pLocalManager;

		UGbool m_bCanBeTransparent;
	};

}

#endif // !defined(AFX_UGDATASETRASTERWEB_H__7681AA6D_BDCB_4A18_A9A3_EC39CEBB7BE4__INCLUDED_)