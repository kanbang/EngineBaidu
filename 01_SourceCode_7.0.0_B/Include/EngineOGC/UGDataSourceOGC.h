//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file SmWebDataSource.h
//!  \brief WMSEngine ������Դ�Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGDATASOURCEOGC_H
#define UGDATASOURCEOGC_H

#include "Stream/ugexports.h"
#include "Engine/UGDataSource.h"

namespace UGC
{
class UGWebLayersInfos;
class OGCCapabilities;

class ENGINEOGC_API UGDataSourceOGC : public UGDataSource 
{
	
public:
	//! \brief  Ĭ�ϵĹ��캯��
	UGDataSourceOGC();
    //! \brief  �����βεĵĹ��캯��
	UGDataSourceOGC(UGDsConnection dsConn);
	// ����Ĵ��麯��,��OGC Web�����в�ʵ��
	virtual ~UGDataSourceOGC();

public:
	//! \brief ������Դ,��ҪԤ�����ú�������Ϣ��
	//! \return ���سɹ���ʧ�ܡ�
	virtual UGbool Open();
	
	//! \brief ��������Դ����Ҫ�趨��������Ϣ��
	//! \return �����ɹ�����TRUE,ʧ�ܷ���False��
	virtual UGbool Create();
	
	//! \brief ����Դ�Ƿ����������
	//! \return �Ƿ�����
	virtual UGbool IsConnected();
	
	//!  \brief �����������ݿ�,��ˢ�����ݼ���
	//! \return ����
	virtual UGbool Connect();
	
	//! \brief �ر�����Դ��
	//! \return ���سɹ���ʧ�ܡ�
	virtual void Close();
	
	//! \brief �ж�����Դ�Ƿ�򿪡�
	//! \return ����Դ״̬��
	virtual UGbool IsOpen();
	
	//! \brief �Ƿ���ִ��ĳЩ������������
	//! \param nAbility ����֧�ֵ�����[in]��
	//! \return �Ƿ�֧�֣��Ƿ���TRUE ���򷵻�FALSE��
	virtual UGbool HasAbility(UGEngAbility nAbility) const ;
	
	//! \brief �Ƿ�֧���ض��Ĳ�����
	//! \param nAction ����֧�Ĳ���[in]��
	//! \return �Ƿ�֧�֣��Ƿ���TRUE ���򷵻�FALSE��
	virtual UGbool IsSupport(UGEngAction nAction) const ;
	
	//! \brief ��ȡ������ʱ�䡣
	//! \return ������ʱ�䡣
	virtual UGTime GetDateLastUpdated() const ;
	
	//! \brief ��ȡ����ʱ��
	//! \return ��󴴽�ʱ�䡣
	virtual UGTime GetDateCreated() const;
	
	//! \brief �õ��������ơ�
	//! \return �������ơ�
	virtual UGString GetEngineName() const;
	
	//! \brief ����������Ϣ��
	//! \return �Ƿ񱣴�ɹ����Ƿ���TRUE ���򷵻�FALSE����
	virtual UGbool SaveInfo();
	
	//! \brief �޸����롣
	//! \param strNewPassword [in]��
	//! \return �Ƿ��޸ĳɹ����Ƿ���TRUE ���򷵻�FALSE��
	virtual UGbool ChangePassword(const UGString& strNewPassword);		
	
	//! \brief ��ʼ����
	//! \return �Ƿ�����ɹ����Ƿ���TRUE ���򷵻�FALSE��
	virtual UGbool BeginTrans();
	
	//! \brief �ύ����
	//! \return �Ƿ�����ɹ����Ƿ���TRUE ���򷵻�FALSE��
	virtual void Commit();
	
	//! \brief ��������
	//! \return �Ƿ�����ɹ����Ƿ���TRUE ���򷵻�FALSE��
	virtual void Rollback();
	
	//! \brief ����ʧ�����ݼ���
	//! \param vInfo ʧ�����ݼ���Ϣ[in]��
	//! \return ʧ�����ݼ���
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);
#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined (IOS)
	//! \brief �����������ݼ���
	//! \param strName �������ݼ���[in]��
	//! \return �������ݼ���
	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);
#endif
	//! \brief ����դ�����ݼ���
	//! \param rInfo դ�����ݼ���Ϣ[in]��
	//! \return դ�����ݼ���
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);
	
	//! \brief ɾ�����ݼ���
	//! \param strName ���ݼ�����[in]��
	//! \return �Ƿ�����ɹ����Ƿ���TRUE ���򷵻�FALSE��
	virtual UGbool DeleteDataset(const UGString& strName);
	
	//! \brief �Ƿ�֧�ִ������ݼ����͡�
	//! \param nDtType ���ݼ�����[in]��
	//! \return �Ƿ�֧�֡�
	virtual UGbool IsSupport(UGDataset::DatasetType nDtType) const;	
public:
	
	// �õ������õ���ʱ�ļ������ú�������ɾ��
	void AutoPatchURL();

	//! \brief ͨ�� GetCapabilities ��URL���˷�����������������λ���ְ汾�š�
	//! \param strGetCapbilityURL GetCapabilities�����URL��ַ[in]��
	//! \return ��λ���ְ汾�š�
	int CheckGetCapbility(UGString strGetCapbilityURL);	
	
	//! \brief �õ�������������
	//! \return �Ƿ�ɹ���ȡ��
	UGbool GetCapabilities();	

	//! \brief �汾Э�̡�
	//! \return �Ƿ�ɹ�Э�̵õ����ð汾��
	UGbool VersionNegotiate();	

	//! \brief ͨ��EPSG����ο�ϵͳ�ַ����õ�SuperMap����ο�ϵͳ��
	//! \param Prj SuperMap����ο�ϵͳ[out]��
	//! \param strSRS EPSG����ο�ϵͳ�ַ���[in]��
	//! \return �Ƿ�ɹ�����ƥ��ת����
	UGbool GetProjectionByName(UGPrjCoordSys& Prj, const UGString& strCRS);	

	//! \brief �������ݼ��Ƿ�򿪻�����ơ�
	//! \param bIsCached �Ƿ�򿪻������[in]��
	//! \return TRUEΪ�򿪻��塣
	void SetCached(const UGbool& bIsCached){m_bIsCached = bIsCached;}

	//! \brief ���ݼ��Ƿ�򿪻�����ơ�
	//! \return TRUEΪ�򿪻��塣
	UGbool IsCached(){return m_bIsCached;}
protected:
	//! \brief ������ؼ����ֵ������ڴ档
	void LoadOGCDict();	

	//! \brief ȥ��URL�е�OGC�ؼ��֡�
	//! \param strURL URL�ַ���[in]��
	UGString TrimKeyWord(const UGString& strURL);	

#if (defined(_MSC_VER) && _MSC_VER > 1200) || OS_ANDROID
	//! \brief  ��WMTS����Դ
	UGbool OpenDataSourceWMTS();
#endif

public:
	// ���ڰ汾Э�̵ı���
	//! \brief GetCapabilities�����URL��ַ��
	//! \remarks URL:http://maps.supermap.com:7070/ogc3/smwms?REQUEST=GetCapabilities&SERVICE=WMS&VERSION=1.3.0
	UGString m_strURL;
	
	//! \brief WMS��WCS��WFS�淶�İ汾�š�
	//! \remarks �ص�2007��6��18�գ�WMS�淶�����°汾��1.3.0 , WFS�����°汾�汾�� 1.1.1 ��
	//! \brief VERSION=1.3.0&
	UGString m_strVersion;

	//! \brief ����Դ������
	//! \remarks ��WMS, WCS ,WFS ���ַ�����������
	OGCCapabilities* m_pCapabilities;
	
	//! \brief �Ƿ񻺳��������ݡ�
	//! \remarks ��ע��Ϣ��
	UGbool m_bIsCached;

	//! \breif �û�ָ������
	UGString m_strCoordinate;
protected:
	// ����һ��OGC URL ����Ĺؼ����ֵ�
	UGDict<UGString,UGint>  m_dictOGCKeyWords;
};

#if !defined OS_ANDROID && !defined (IOS)
extern "C" ENGINEOGC_API UGDataSource* CreateDataSource();
extern "C" ENGINEOGC_API OgdcDataSource* CreateOgdcDataSource();
extern "C" ENGINEOGC_API OgdcFeature* CreateOgdcFeature();
#else
extern "C" ENGINEOGC_API UGDataSource* CreateOGCDataSource();
#endif

}
#endif // !defined(UGDATASOURCEOGC_H)

