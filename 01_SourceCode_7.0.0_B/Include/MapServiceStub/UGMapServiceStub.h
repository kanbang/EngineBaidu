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
/*
�����������������Ļ��࣬�ڲ��������ض���ʵ�ֶ��߳��첽���أ�����֮ǰ�û���Ҫ
���ûص������ͱ��ػ�����������û�����Request����µ������ٴε���Request�Ὣ��
����ӵ����ض���ͷ�����������أ�ԭ�е��������ȼ����͡�����Stopֹͣ���е����ز����
���ض��С�
*/
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGMAPSERVICESTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
#define AFX_UGMAPSERVICESTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_

#include "MapServiceStub/UGMapServiceParams.h"
#include "MapServiceStub/UGLocalCacheManager.h"
#include "Stream/ugplatform.h"
#include "NetToolkit/UGDownloadQueue.h"
#include "MapServiceStub/UGMapDownloadQueue.h"
#include "CacheFile/UGAbstractCacheFile.h"

namespace UGC 
{

// typedef void (UGSTDCALL * DownloadResponseFunc) (UGDownloadTileInfo result, UGlong pWnd);

// typedef void (UGSTDCALL * DataChangedProc) (const UGDataChangeInfo& ChangeInfo, UGlong pWnd);

//! \brief ����������ࡣ
//! \remarks �����йط�������Ķ�Ҫ�̳д��ࡣ
class MAPSERVICESTUB_API UGMapServiceStub 
{
public:
	//! \brief ���캯����
	UGMapServiceStub();

	//! \brief ����������
	virtual ~UGMapServiceStub();
	
public:

	//! \brief ���ñ��ػ����������
	//! \param pLocalCacheManager [in]��
	//! \attention �򿪷���֮ǰ�������ñ��ػ��������
	UGbool SetLocalCacheManager(UGLocalCacheManager *pLocalCacheManager);

	//! \brief ��ȡ���ػ����������
	//! \param pLocalCacheManager [in]��
	//! \attention �򿪷���֮ǰ�������ñ��ػ��������
	UGLocalCacheManager* GetLocalCacheManager();

	//! \brief �򿪷���
	//! \param impParams [in]��
	//! \return �ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention ���ط���ǰ���á�
	virtual UGbool Open(const UGMapServiceParams* pMapServiceParams, UGbool bReSave = TRUE) = 0;

	//! \brief ��������
	//! \param dScale [in] �����ߡ�
	//! \param bound [in] ��Χ��
	//! \param nSec [in] ���س�ʱʱ�䣬Ĭ��30��
	//! \attention ͨ��bound���󣬲��ṩ�ص���ֻʹ�ö��̣߳�ֻ��ȫ�������ʱ�ŷ������߳�
	virtual UGbool Request(const UGdouble& dScale, const UGRect2D& bound, UGbool bCallBack = TRUE, const UGint& nSec = 0);
	
	//! \brief �رշ���	
	virtual void Close();

	//! \brief ����ClientID����ʱֻ��GoogleMapsʹ��
	virtual void SetUser(const UGString& strUser){}

	//! \brief ����ǩ������ʱֻ��GoogleMapsʹ��
	virtual void SetPassword(const UGString& strPassword){}

	//! \brief ��ʱ����������Ļ���ض��У������������Ļ�߳��ͷŵ������ٽ������ء�
	void Stop();

	//! \brief ����������ɵĻص�����
	//! \param pFunc �ص�����[in]��
	//! \param pWnd ���[in]��
	void SetDownloadResponseFunc(DownloadResponseFunc pFunc,UGlong pWnd);

	//! \brief �Ƿ��������
	//! \return ��������ȫ��������ɣ��򷵻�true�����򷵻�false��
	UGbool IsComplete(){return (m_bLastTileRequest && m_DownloadQueue.IsComplete());}

	//! \brief ��������ʱ���õ�����̸߳���������ܳ���10
	void SetThreadCount(UGint nThreadCount){m_DownloadQueue.SetMaxThreadCount(nThreadCount);}

	//! \brief �������󣨳�ͼ�Ʒ��񣩡�
	//! \param dScale [in] �����ߡ�
	//! \param bound [in] ��Χ��
	//! \attention ���ú�����̨�߳����أ��Իص��ķ�ʽ��Χ������Ϣ��
	virtual UGbool Request(const UGuint& nScalePath, const TileArea& tileArea);

	//! \brief �������������Ϣ
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SendDownloadResponseFunc(const UGDownloadTileInfo& tileDownloadInfo);

	//! \brief ����ȡ�����ݲ��������������Ӿ��η��ظ��û��Ļص�����
	//! \param pFunc �ص�����[in]��
	//! \param pWnd ���[in]��
	void SetDataChangedFunc(DataChangedProc pFunc,UGlong pWnd);

	//! \brief ���ø����û�������ɵĻص�����
	//! \param pFunc �ص�����[in]��
	//! \param pWnd ���[in]��
	void SetRequestFinishedFunc(RequestFinishedProc pFunc,UGlong pWnd){m_DownloadQueue.SetRequestFinishedFunc(pFunc, pWnd);}

	//! \brief �������������Ϣ
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SendDataChangedFunc(const UGDataChangeInfo& ChangeInfo);

	//! \brief ���ݷ�Χ�ͱ����ߣ���ѯ��¼����
	//! \param rcMapBounds [in] ��Χ��
	//! \param dScale [in] �����ߡ�
	//! \return 
	UGTiles* QueryWithBounds(const UGRect2D& rcMapBounds, UGdouble dScale) const;

	//! \brief ���ݷ�Χ�ͱ����ߣ��жϸ÷�Χ�ڵ���Ƭ�Ƿ�ȫ�����ڡ�
	//! \param rcMapBounds [in] ��Χ��
	//! \param dScale [in] �����ߡ�
	//! \return 
	UGbool IsAllTilesExist(const UGRect2D& rcMapBounds, UGdouble dScale) const;


	//! \brief �õ��������͡�
	//! \param  [in]��
	//! \return �������͡�
	//! \remarks ���������Լ�ʵ�֡�
	virtual UGint GetServiceType() const {return 0;}


	//! brief �õ������
	//! param [in]  �������������
	//! param [out] �������������
	void GeneRandNumber(const UGint nSeedNumber, UGint & nServerNumber);

protected:

	//! \brief ����URLʱ�Ƿ����TileInfo������
	virtual UGbool IsGenerateURLByTileInfo() = 0;

	//! \brief ����URL
	//! \param tileInfo[in]����URL����Ƭ
	//! \param strURL[out]�����URL
	virtual void GenerateURL(const UGTileInfo& tileInfo, UGString& strURL){}

	//! \brief ����URL����ͼ��Web��������URL�ķ�ʽ��
	//! \param nScalePath[in]����URL�ı�����
	//! \param nRow[in]����URL����
	//! \param nCol[in]����URL����
	//! \param strURL[out]�����URL
	//! \attention �Լ��ķ����ֱ�������к��������
	virtual void GenerateURL(const UGuint& nScalePath, const UGint& nRow, const UGint& nCol, UGString& strURL){}

	//! \brief �������������к�̨���߳����ء�
	//! \remarks ��������в�Ϊ�գ����������Ѿ������������������е�����������������ж��߳����ء�
	void BackgroundDownloadFile();

	//! \brief ����һ����Ƭ
	void RequestTile(UGMapCacheFile* pCacheFile, UGuint nScalePath, UGdouble dScale, UGint nRow, UGint nCol, UGbool bCallBack);
	


public:
	//! \brief �����Ƿ�򿪡�
	//! \param  [in]��
	UGbool IsOpen() const;	
	
protected:
	//! \brief ����Ļ���ַ��־��
	UGString m_strBaseURL;

	//! \brief ����򿪱�־��
	UGbool m_bOpen;

	//! \brief ���ض��У��ڹ��캯������ɳ�ʼ��
	UGMapDownloadQueue m_DownloadQueue;

	//! \brief �����뻺��IO����
	UGLocalCacheManager* m_pLocalCacheManager;

	//! \brief �ص��������
	UGDict<UGlong, DownloadResponseFunc> m_dictDownloadRF;

	//! \brief �Ƿ��Ѿ��Ǵ������һ����Ƭ
	UGbool m_bLastTileRequest;

	//! \brief �ص��������
	UGDict<UGlong, DataChangedProc> m_dictDataCF;

};

} //namespace UGC

#endif // !defined(AFX_UGMAPSERVICESTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)

