//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details ���������ϸ��Ϣ��
//!  \author ����ת���顣
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGWMTSPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_)
#define AFX_UGWMTSPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_

#include "MapServiceStub/UGMapServiceParams.h"
#include "MapServiceStub/UGMapServiceType.h"

namespace UGC {

	//! \brief ��ͼ�Ʒ���������á�
	class MAPSERVICESTUB_API UGWMTSParams : public UGMapServiceParams
	{
	public:
		//! \brief ���캯����
		//! \remarks ��
		UGWMTSParams();

		//! \brief ���캯����
		//! \remarks ��
		UGWMTSParams(const UGWMTSParams& ugWMTSParams);

		//! \brief ����������
		//! \remarks ��
		virtual ~UGWMTSParams();

	public:

		//! \brief ���ػ�ȡ�������͵ĺ�����
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGint GetServiceType() const	{ return UGMapServiceType::WMTS; }

		//! \brief ͨ��URL��ʼ����ͼ����
		virtual UGbool InitParams();

		virtual void GetAllLayers(UGArray<UGString>& arrLayers) const;

		//! \brief ͨ������sci�ļ���ʼ����ͼ����
		virtual UGbool FromLocalCache(const UGString& strCacheFile);

		//! \brief ��ȡxml����ڻ����Ŀ¼����webcache֮���Ŀ¼
		//! \brief ��Ҫ������������ʱҲ����ͨ��xml�����е�LayerͼƬ
		//! \biref ��: /WMTS/map-china400/wmts100/wmts100.xml 
		virtual UGString GetXMLRelativePath();

		//! \brief ��ȡ.sci����ڻ����Ŀ¼����webcache֮���Ŀ¼
		//! \brief ��Ҫ������������ʱҲ����ͨ��xml�����е�LayerͼƬ
		//! \biref ��Chin��m_strMapType�Ļ�  �򷵻� /WMTS/map-china400/wmts100/China/China.sci 
		virtual UGString GetLayerRelativePath();
		
		//! ���û�����ļ��е�Ŀ¼
		//! ����D:\Buffer
		void SetBufferPath(const UGString& strBufferPath);
		
		//! ��ȡ�����������ƵĶ�Ӧ��ϵ
		std::map<UGdouble, UGString> GetOutputScaleCaptions();
		
		//! ��ȡͼ��Ĳ���
		UGWMTSParams* GetLayerParams(const UGString& strLayer);

		//! \brief ��ȡͼ���Ӧ��TileMatrix���ϵ�����
		UGString GetTileMatrixSet() const;

		//! \brief ��ȡWMTSͼ�����ơ�
		UGString GetLayerName() const;
		
		//! \brief ��ȡWMTSͼ�����ơ�
		UGString GetLayerAlias() const;

		UGbool LoadAllLayerParams(const UGString& strPathXML);

		// !---------------- ͼ�����Ϣ -----------------
		// !   ����ͼ��Ӧ�ú��е�WMTS������Ϣ ����ͼ������Tileʱʹ��		

		//! \brief WMTSͼ���������ơ�
		UGString m_strLayerName;

		//! \brief WMTSͼ�����ͱ�����
		UGString m_strLayerAlias;

		//! \brief ͼ��������
		UGString m_strStyle;

		//! \brief ͼ������ظ�ʽ
		UGString m_strFormat;

		//! \brief ͼ��鼯������
		UGString m_strTileMatrixSet;

		//! \brie ͼ������ߺͱ��������Ƶ�ӳ���ϵ
		std::map<UGdouble, UGString> m_mapOutputScaleCaptions;


		// !---------------- ����ʱʹ�õ���ʱ��¼ --------------

		//! \brief ͼ�����ƺͶ�Ӧ��ͼ�������ӳ���ϵ 
		//! \brief ÿ��һ��Layer�ͻ�����1
		UGDict<UGString, UGWMTSParams*> m_dictWMTSParams;

		//! \brief �Ƿ�͸��
		UGbool m_bTransparent;

		//! \brief ����wmts�����Ƿ������ͼ����
		//! \���������ͼ��iserver������wmts����Ĺ��һ�����߾������Ǳ�׼wmts��������ֻ�ܼ�һ����������һ�¿���������һ�ַ���
		UGbool m_bIsTianDiTu;

	private:
		UGbool ParseURL();
		
		//! \brief ��ȡͶӰ
		//! \param Prj ͶӰ
		//! \param strCRS ��EPSG:4326
		UGbool GetProjectionByName(UGPrjCoordSys& Prj, const UGString& strCRS );
        
		//! \brief ����ͼ���ʶ��ȡ��Ӧͼ��Ĳ�����ָ��
		UGWMTSParams* GetParamsByLayerIdentifier(UGString strLayerIdentifier)const;

		// !---------------- WMTS�������Ϣ-----------------
		//! \brief ����Ļ�����ַ
		UGString m_strHost;

		//! \brief ����Ļ����ַ
		UGString m_strServerPath;

		//! \brief ����İ汾��
		UGString m_strVersion;

		//! \brief �����·�� ��D:\Buffer
		UGString m_strBufferPath;

	

	};

} //namespace UGC
#endif // !defined(AFX_UGSMICLOUDPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_)

