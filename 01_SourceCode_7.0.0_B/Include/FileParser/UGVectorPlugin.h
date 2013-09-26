
#if !defined(AFX_UGVECTORPLUGIN_H__E1BF20D3_7163_4C55_A157_F002C0B829AF__INCLUDED_)
#define AFX_UGVECTORPLUGIN_H__E1BF20D3_7163_4C55_A157_F002C0B829AF__INCLUDED_

#include "Stream/ugdefs.h"
#include "FileParser/UGVectorCacheParamater.h"
#include "FileParser/UGExchangeFileType.h"
#include "FileParser/UGRecordsetTile.h"
#include "OGDC/OgdcQueryDef.h"
#ifndef OS_ANDROID
#include "NetToolkit/UGDownloadQueue.h"
#include "Base3D/UGTextureData.h"
#include "Geometry/UGDataCodec.h"
#include "Geometry/UGGeometry.h"
#include "Geometry/UGFeature.h"
#endif


#ifdef WIN32
#include <Windows.h>
#define VECTOREXPORT __declspec(dllexport)
#else
#define VECTOREXPORT
#endif

using namespace UGC;
namespace UGC
{	
	typedef void (UGSTDCALL * DownloadResponseFunc) (UGDownloadTileInfo result, UGlong pWnd);
}

namespace UGC
{	
	//! \breif Ӱ��������
	enum PluginVectorClass 
	{
		PV_UNKNOWN,
		PV_SCV
	};	
#ifndef OS_ANDROID
	class FILEPARSER_API UGVectorPlugin
	{
	public:
		UGVectorPlugin(){m_strPassword = _U("");}
		virtual ~UGVectorPlugin(){}
	public:
		//! \brief ���ļ���
		//! \param  strFileName,�ļ�����[in]
		//! \param  nFlags, �򿪷�ʽ����ֻ��������ȣ��ο�CFile�ı�־��[in]
		//! \param strPassword ������ [in]
		virtual UGbool Open(const UGString& strFileName, UGuint nFlags, const UGString& strPassword) = 0;

		//! \brief �ر��ļ���
		virtual void Close() = 0;

		//! \return �������
		virtual PluginVectorClass GetPluginClass() { return m_nPluginClass; }

		//! \brief  �����������ƣ����� ECW �ļ����.
		//! \param  strName,�ַ���,���������ռ�.[out]
		//! \param  nMaxLength �ַ�������[in]
		virtual UGbool GetPluginName(UGchar* strName, int nMaxLength) = 0;

		UGVectorCacheParamater& GetCacheParamater() {return m_CacheParameter;}

		// ������Ƭ��ѯ����
		virtual UGRecordsetTile* Query(OgdcQueryDef queryDef) = 0;

		//! \brief ���ûص�����
		//! \remarks ��άʹ�õİ�������
		virtual void SetDownloadResponseFunc(DownloadResponseFunc pFunc,UGlong pWnd){return; }

		//! \brief �ж�һ�������Ƿ��Ѿ���ɣ�Request֮�����
		//! \remarks ��IsFinished()��һ��  IsFinished()���ж�GetViewBlock()���ص��Ƿ���ȫ
		//! \return ��ɷ���True�����򷵻�False
		virtual UGbool IsCompleteRequest() {return TRUE;}

		//! \brief �����������
		//! \dScale param[in] ��ǰ��ͼ�ı�����
		//! \bound param[in] ��ǰ��ͼ��Χ
		virtual UGbool Request(const UGdouble& dScale, const UGRect2D& bound, UGbool bCallBack = TRUE){return FALSE;}

		//! \brief�������кŻ�ȡ��������
		//! \brief nRow[in]�����к�
		//! \brief nCol[in]�����к�
		//! \brief arrGeometry[out] ��ȡGeometry����
		//! \return ��ѯ�ɹ�����TRUE������ΪFALSE
		virtual UGbool GetBlockAt(UGint nRow, UGint nCol, UGArray<UGGeometry*>& arrGeometry) = 0;

		//! \brief�������кŻ�ȡFeatures����
		//! \brief nRow[in]�����к�
		//! \brief nCol[in]�����к�
		//! \brief arrFeatures[out] ��ȡarrFeatures����
		//! \return ��ѯ�ɹ�����TRUE������ΪFALSE
		virtual UGbool GetBlockAt(UGint nRow, UGint nCol, UGArray<UGFeature*>& arrFeatures) = 0;

		//! \brief ��ȡĳһ�����Bounds
		//! \brief nRow[in] ����к�
		//! \brief nCol[in] �ĵ��к�
		//! \brief recBounds [out] ���bounds
		//! \return ��ȡ�ɹ�����TRUE�����򷵻�FALSE
		virtual UGbool GetBlockBounds(UGint nRow, UGint nCol, UGRect2D& recBounds) = 0;

		//! \brief ��ȡĳһ����İ�Χ��
		//! \brief nRow[in] ����к�
		//! \brief nCol[in] �ĵ��к�
		//! \brief boundingBox [out] ��İ�Χ��
		//! \return ��ȡ�ɹ�����TRUE�����򷵻�FALSE
		virtual UGbool GetBlockBoundingBox(UGint nRow, UGint nCol, UGBoundingBox& boundingBox) = 0;

		//! \brief��ȡ�ֶ���Ϣ
		virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos) = 0;

		//! \brief ��ȡ����
		//! \param res[out] ����״̬
		//! \param strPath[in] ����·����Ҳ������������		
		//! \param nLodLevel[in] �������
		//! \param bNeedUnCompress[in] ��ȡ�������Ƿ���Ҫ��ѹ��
		//! \param nTileRow �������ڵ���
		//! \param nTileCol �������ڵ���
		//! return �ɹ��Ļ�����һ��UGTextureData���͵�ָ�룬���򷵻ؿ�
		//! remarks ��άʹ��
		virtual UGTextureData* GetTextureData(UGint& res, UGString strTexPath, UGint nLodLevel, UGbool bNeedUnCompress = TRUE, UGint nTileRow = 0, UGint nTileCol = 0) = 0;

		//! brief ��ȡ�������ʱ·��������GIF����,�ǽ�ͼƬд����ʱĿ¼��Ȼ��ӱ�����ʱĿ¼��ȡ��������
		virtual UGString GetTextureTempPath(const UGString& strTexture, UGint nTileRow = 0, UGint nTileCol = 0) = 0;	

		//! \brief ��������
		virtual  void DownloadQueueBeginDownLoad() = 0;

		//! \brief ��ȡʸ���ļ����ض���
		virtual UGDownloadQueue& GetVectorDataDownloadQueue() = 0;
		virtual UGDownloadQueue& GetVectorAtrriDownloadQueue() = 0;
		//! \brief ��ȡͼ���������ؽ���
		virtual	UGfloat GetDataStreamingProgress() = 0;

	protected:
		//! \brief ����
		UGString m_strPassword;

		//! \brief ��ǰʸ���������
		PluginVectorClass m_nPluginClass;	

		UGVectorCacheParamater m_CacheParameter;
	};
#else
class FILEPARSER_API UGVectorPlugin
{
public:
	UGVectorPlugin(){m_strPassword = _U("");}
	virtual ~UGVectorPlugin(){}
public:
	//! \brief ���ļ���
	//! \param  strFileName,�ļ�����[in]
	//! \param  nFlags, �򿪷�ʽ����ֻ��������ȣ��ο�CFile�ı�־��[in]
	//! \param strPassword ������ [in]
	virtual UGbool Open(const UGString& strFileName, UGuint nFlags, const UGString& strPassword) = 0;

	//! \brief �ر��ļ���
	virtual void Close() = 0;

	//! \return �������
	virtual PluginVectorClass GetPluginClass() { return m_nPluginClass; }

	//! \brief  �����������ƣ����� ECW �ļ����.
	//! \param  strName,�ַ���,���������ռ�.[out]
	//! \param  nMaxLength �ַ�������[in]
	virtual UGbool GetPluginName(UGchar* strName, int nMaxLength) = 0;

	//! \brief��ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos) = 0;

	UGVectorCacheParamater& GetCacheParamater() {return m_CacheParameter;}

	// ������Ƭ��ѯ����
	virtual UGRecordsetTile* Query(OgdcQueryDef queryDef) = 0;
protected:
	//! \brief ����
	UGString m_strPassword;

	//! \brief ��ǰʸ���������
	PluginVectorClass m_nPluginClass;	

	UGVectorCacheParamater m_CacheParameter;
};

#endif


	// �����Ҫʵ��һ��������ȫ�ֺ����������� UGVectorPlugin �������ࡣ
	// ����һ������࣬��new һ���� UGImagePlugin �������ࡣ
	extern "C" VECTOREXPORT UGVectorPlugin* CreateVectorPlugin();
}

#endif //AFX_UGVECTORPLUGIN_H__E1BF20D3_7163_4C55_A157_F002C0B829AF__INCLUDED_

