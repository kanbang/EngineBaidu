// UGWebMapLayerStub.h: interface for the UGWebMapLayerStub class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGWEBMAPLAYERSTUB_H__66585C4A_9CBA_4EE8_98FB_AE9B0C1C2803__INCLUDED_)
#define AFX_UGWEBMAPLAYERSTUB_H__66585C4A_9CBA_4EE8_98FB_AE9B0C1C2803__INCLUDED_

#include "Toolkit/UGThread.h"
#include "Toolkit/UGPalette.h"
#include "CacheFile/UGCacheFileCommon.h"
#include "Toolkit/UGTaskProcessor.h"
#include "Engine/UGDatasetRasterWeb.h"
#include "Map/UGCacheTileDatas.h"

namespace UGC {

class UGGraphics;
class UGDrawing;
class UGLayer;
class UGWebMapLayerStub;
typedef UGArray<UGTile*> UGTiles;


//////////////////////////////////////////////////////////////////////////

//! \brief ��Ƭ��������
class UGDataChangeTask : public UGTaskBase
{
public:
	UGDataChangeTask()
	{
		
	}

	UGDataChangeTask(const UGDataChangeTask* pTask)
	{
		m_ChangeInfo = pTask->m_ChangeInfo;
	}

	UGDataChangeTask(const UGDataChangeInfo& ChangeInfo)
	{
		m_ChangeInfo = ChangeInfo;
	}

	//! \brief ���� ==
	UGbool operator == (const UGDataChangeTask& Task) const
	{
		if (m_ChangeInfo == Task.m_ChangeInfo)
		{
			return true;
		}

		return false;
	}

	//! \brief ����=��
	void operator = (const UGDataChangeTask& Task)
	{
		m_ChangeInfo = Task.m_ChangeInfo;
	}

	//! \brief ��ȡ��������
	virtual UGString GetClassName()
	{
		return _U("DataChangeTask");
	}

	//! \brief ʵ��������ľ������
	virtual UGbool Execute()
	{
		return false;
	}

	//! \brief ��¡����
	virtual UGTaskBase* Clone()
	{
		return new UGDataChangeTask(*this);
	}

public:
	//! \brief ���ݱ仯��Ϣ
	UGDataChangeInfo m_ChangeInfo;

};

//! \brief ������Ⱦ��������
class UGDataChangeTaskHelper
{
public:
	static UGTaskBase* CreateTask(const UGDataChangeInfo& ChangeInfo)
	{
		return new UGDataChangeTask(ChangeInfo);
	}

	static UGDataChangeInfo& GetDataChange(UGTaskBase* pTask)
	{
		UGASSERT(pTask != NULL);
		return ((UGDataChangeTask*)pTask)->m_ChangeInfo;
	}

};

//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////

//! \brief ת��������Ƭ����
class UGUpdataCacheTask : public UGTaskBase
{
public:
	UGUpdataCacheTask(const UGUpdataCacheTask* pTask)
	{
		m_dScale = pTask->m_dScale;
		m_rcBounds = pTask->m_rcBounds;
		m_nExtTileSize = pTask->m_nExtTileSize;
		m_bRemoveAll = pTask->m_bRemoveAll;
	}

	UGUpdataCacheTask(UGdouble dScale, UGRect2D rcBounds, UGint nExtTileSize, UGbool bRemoveAll)
	{
		m_dScale = dScale;
		m_rcBounds = rcBounds;
		m_nExtTileSize = nExtTileSize;
		m_bRemoveAll = bRemoveAll;
	}

	//! \brief ���� ==
	UGbool operator == (const UGUpdataCacheTask& Task) const
	{
		if (UGEQUAL(m_dScale, Task.m_dScale) && m_rcBounds == Task.m_rcBounds && 
			m_nExtTileSize == Task.m_nExtTileSize && m_bRemoveAll == Task.m_bRemoveAll)
		{
			return true;
		}

		return false;
	}

	//! \brief ��ȡ��������
	virtual UGString GetClassName()
	{
		return _U("UpdataCacheTask");
	}

	//! \brief ʵ��������ľ������
	virtual UGbool Execute()
	{
		return false;
	}

	//! \brief ��¡����
	virtual UGTaskBase* Clone()
	{
		return new UGUpdataCacheTask(*this);
	}

	UGdouble GetScale()
	{
		return m_dScale;
	}

	UGRect2D GetBounds()
	{
		return m_rcBounds;
	}

	UGint GetExtTileSize()
	{
		return m_nExtTileSize;
	}

	UGbool IsRemoveAll()
	{
		return m_bRemoveAll;
	}

public:
	//! \brief ���»������
	UGdouble m_dScale;
	UGRect2D m_rcBounds;
	UGint m_nExtTileSize;
	UGbool m_bRemoveAll;

};

//! \brief ������Ⱦ��������
class UGUpdataCacheTaskkHelper
{
public:
	static UGTaskBase* CreateTask(UGdouble dScale, UGRect2D rcBounds, UGint nExtTileSize, UGbool bRemoveAll)
	{
		return new UGUpdataCacheTask(dScale, rcBounds, nExtTileSize, bRemoveAll);
	}

	static UGdouble GetScale(UGTaskBase* pTask)
	{
		UGASSERT(pTask != NULL);
		return ((UGUpdataCacheTask*)pTask)->GetScale();
	}

	static UGRect2D GetBounds(UGTaskBase* pTask)
	{
		UGASSERT(pTask != NULL);
		return ((UGUpdataCacheTask*)pTask)->GetBounds();
	}

	static UGint GetExtTileSize(UGTaskBase* pTask)
	{
		UGASSERT(pTask != NULL);
		return ((UGUpdataCacheTask*)pTask)->GetExtTileSize();
	}

	static UGbool IsRemoveAll(UGTaskBase* pTask)
	{
		UGASSERT(pTask != NULL);
		return ((UGUpdataCacheTask*)pTask)->IsRemoveAll();
	}

};

class UGWebMapStub;

//! \brief �������������̹߳���(����ֱ�ӵ�������RequestTile�ӿڿ��ܻ�ķ�ʱ�䣬����ĳ��̷߳���)
class UGUpdataCacheStub : public UGTaskProcessor
{
public:
	UGUpdataCacheStub();
	~UGUpdataCacheStub();

public:
	void InitUpdataCache(UGWebMapStub* pWebMapStub);
	void UnInitUpdataCache();
	void ResetUpdataCache();

	//! \brief �����������������
	UGbool AddTask(UGTaskBase* pTask, UGbool bTail = true);

	//! \brief �����������
	UGint RemoveAllTask();

protected:
	//! \brief ��������(���̴߳�����)
	virtual UGbool ProcessTask(UGTaskBase* pTask);

private:
	UGWebMapStub* m_pWebMapStub;

	//! \brief �����������
	UGTaskManager m_TaskManager;

};

//////////////////////////////////////////////////////////////////////////

class UGWebMapStub;

//! \brief ��Ƭת�������̹߳���
class UGTileDataCache : public UGTaskProcessor, public UGTaskFilter
{
public:
	UGTileDataCache();
	~UGTileDataCache();

public:
	void InitDataCache(UGWebMapStub* pWebMapStub);
	void UnInitDataCache();
	void ResetDataCache();

	//! \brief �����������������
	UGbool AddTask(UGTaskBase* pTask, UGbool bTail = true);

	//! \brief �����������
	UGint RemoveAllTask();

protected:
	//! \brief ������Ⱦ����(���̴߳�����)
	virtual UGbool ProcessTask(UGTaskBase* pTask);

	//! \brief ������Ⱦ����(���̴߳�����)
	virtual UGbool PreTranslateTask(UGTaskBase::TaskState eTaskState, UGTaskBase* pTask, UGbool& bHandle);

private:
	UGWebMapStub* m_pWebMapStub;

	//! \brief �����������
	UGTaskManager m_TaskManager;

};

//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////

//! \brief ����������Ƭ����
class UGRequestTileTask : public UGTaskBase
{
public:
	UGRequestTileTask()
	{
		m_dScale = 0.0;
		m_rcBounds.SetEmpty();
	}

	UGRequestTileTask(const UGRequestTileTask* pTask)
	{
		m_dScale = pTask->m_dScale;
		m_rcBounds = pTask->m_rcBounds;
	}

	UGRequestTileTask(UGdouble dScale, UGRect2D rcBounds)
	{
		m_dScale = dScale;
		m_rcBounds = rcBounds;
	}

	//! \brief ���� ==
	UGbool operator == (const UGRequestTileTask& Task) const
	{
		if (UGEQUAL(m_dScale, Task.m_dScale) && m_rcBounds == Task.m_rcBounds)
		{
			return true;
		}

		return false;
	}

	//! \brief ��ȡ��������
	virtual UGString GetClassName()
	{
		return _U("RequestTileTask");
	}

	//! \brief ʵ��������ľ������
	virtual UGbool Execute()
	{
		return false;
	}

	//! \brief ��¡����
	virtual UGTaskBase* Clone()
	{
		return new UGRequestTileTask(*this);
	}

	UGdouble GetScale()
	{
		return m_dScale;
	}

	UGRect2D GetBounds()
	{
		return m_rcBounds;
	}

private:
	//! \brief �������
	UGdouble m_dScale;
	UGRect2D m_rcBounds;

};

//! \brief ������Ⱦ��������
class UGRequestTileTaskHelper
{
public:
	static UGTaskBase* CreateTask(UGdouble dScale, UGRect2D rcBounds)
	{
		return new UGRequestTileTask(dScale, rcBounds);
	}

	static UGdouble GetScale(UGTaskBase* pTask)
	{
		UGASSERT(pTask != NULL);
		return ((UGRequestTileTask*)pTask)->GetScale();
	}

	static UGRect2D GetBounds(UGTaskBase* pTask)
	{
		UGASSERT(pTask != NULL);
		return ((UGRequestTileTask*)pTask)->GetBounds();
	}

};


class UGWebMapStub;

//! \brief �������������̹߳���(����ֱ�ӵ�������RequestTile�ӿڿ��ܻ�ķ�ʱ�䣬����ĳ��̷߳���)
class UGRequestTileStub : public UGTaskProcessor
{
public:
	UGRequestTileStub();
	~UGRequestTileStub();

public:
	void InitRequestStub(UGWebMapStub* pWebMapStub);
	void UnInitRequestStub();
	void ResetRequestStub();

	//! \brief �����������������
	UGbool AddTask(UGTaskBase* pTask, UGbool bTail = true);

	//! \brief �����������
	UGint RemoveAllTask();

protected:
	//! \brief ��������(���̴߳�����)
	virtual UGbool ProcessTask(UGTaskBase* pTask);

private:
	UGWebMapStub* m_pWebMapStub;

	//! \brief �����������
	UGTaskManager m_TaskManager;

};

//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////

class UGWebMapStub
{
	friend class UGUpdataCacheStub;
	friend class UGTileDataCache;
	friend class UGRequestTileStub;
public:
	UGWebMapStub();
	virtual ~UGWebMapStub();

public:
	//! \brief ��ʼ�������ͼ�����Ϣ
	virtual void InitWebMapInfo(UGLayer *pLayer);

	//! \brief ����ʼ�������ͼ�����Ϣ
	virtual void UnInitWebMapInfo();

	//! \brief �������������ͼ�����Ϣ
	virtual void ResetWebMapInfo();

	//! \brief ͼ�������ݼ�������Ƭ
	virtual void RequestTile(UGdouble dScale, UGRect2D& rcViewBounds, UGbool bPanMode = false, UGbool bForceUpdate = false);

	//! \brief ���ݵ�ǰ����ͼ��Χ��m_pDrawTileImage���Ƶ�pGraphics��
	virtual UGbool OnDrawTileImage(UGDrawing* pDrawing, UGbool bIsPrinting);

public:
	//! \brief �Ƿ����첽ģʽ���Ƶ�ͼ
	UGbool IsAsyncMode() const;

	//! \brief �ж��Ƿ��ͼ
	UGbool IsPrintToFile();

	//! \brief ���»����ImageData
	UGbool UpdateCacheTile(UGint nExtTileSize = 1, UGbool bRemoveAll = true);

	//! \brief ���ݵ�ǰ����ͼ��Χ�ѱ��ص���Ƭƴ���������Ƶ�pGraphics��
	UGbool OnDrawLocaleTileImage(UGDrawing* pDrawing);

	//! \brief �ص�ˢ�µ�ͼ
	void RefreshMapCallBack(UGdouble dMapScale, const UGRect2D &rcBounds);

	//! \brief ���ת������
	UGbool AddDataCacheTask(UGTaskBase* pTask, UGbool bTail = true);

	//! \brief �������ת������
	UGint RemoveAllDataCacheTask();
	
protected:
	//! \brief �߳�ת�����ػ������Ƭ�����ؾ���
	UGbool ProcessUpdateCacheTask(UGdouble dMapScale, const UGRect2D rcBounds, UGint nExtTileSize = 1, UGbool bRemoveAll = true);

	UGImageData* ConvertTileImageData(UGDatasetRasterWeb* pDatasetWeb, UGTile* pTile, UGColorTable* pColorTable);

	void PaintImageDataByColorTable( UGImageData* pImageDataDest,UGImageData* pImageDataSrc, UGColorTable *pColorTable);

	//! \brief �߳�ת�����ػ������Ƭ�����ؾ���
	UGbool ProcessTileCacheTask(UGTaskBase* pTask);

	UGImageData* CreateTileImageData(UGint nWidth, UGint nHeight);
	UGbool DeleteTileImageData(UGImageData* pTileImageData);
	UGbool FillTileImageData(UGImageData* pTileImageData, UGColor color = UGRGBA(255, 255, 255, 0));
	UGbool DrawTileImageData(UGImageData* pImageDataDest, UGint x, UGint y, UGint nWidth, UGint nHeight, UGImageData* pImageDataSrc, UGint xSrc, UGint ySrc);
	UGbool StretchTileImageData(UGImageData* pImageDataDest, UGint x, UGint y, UGint nWidth, UGint nHeight, UGImageData* pImageDataSrc, UGint xSrc, UGint ySrc, UGint nSrcWidth, UGint nSrcHeight);

	//! \brief ���ݵ�ǰ����ͼ��Χ�ѻ����CacheTileImage���Ƶ�pGraphics��
	UGbool OnDrawCacheTileImage(UGDrawing* pDrawing, UGRect2D& rcTileImageBounds, UGImageData* pTileImageData);

protected:
	//! \brief ͼ�������ݼ�������Ƭ
	UGbool Request(UGdouble dScale, UGRect2D rcBounds);

private:
	static UGbool GetViewDPSize(UGDrawing* pDrawing, UGint& nViewWidth, UGint& nViewHeight);

	static UGbool TransparentBitbltDraw(UGDrawing* pDrawing, UGint x, UGint y, UGint nWidth, UGint nHeight, 
		UGImageData* pImageData, UGint xSrc, UGint ySrc, UGbool bAlphaMask);

	static UGbool TransparentOrRotateDraw(UGDrawing* pDrawing, UGint x, UGint y, UGint nWidth, UGint nHeight, 
		UGImageData* pImageData, UGRect2D& rcImageBounds, UGbool bAlphaMask);

	// ����ÿ�����ص�͸�������ȺͶԱȶȵ�
	static void ProcessPixelModify(const UGbyte& btBitsPixelSrc, UGbyte* pPixelBitsSrc,
		const UGbyte& btBitsPixelDest, UGbyte* pPixelBitsDest,
		const UGbool& bBackTransparent, const UGColor& clrTransparent, const UGbyte& btColorTolerance, 
		const UGchar& btBrightness, const UGchar& btContrast, 
		const UGdouble& dTransPercentRate, const UGdouble& dTransPercentRateRemain, 
		const UGbool& bAlphaMask);

	static void GetPixel(const UGbyte& btBitsPixel, const UGbyte* pPixelBits, UGbyte& r, UGbyte& g, UGbyte& b, UGbyte& a);
	static void SetPixel(const UGbyte& btBitsPixel, UGbyte* pPixelBits, const UGbyte& r, const UGbyte& g, const UGbyte& b, const UGbyte& a);

	static void Brightness(UGbyte& r, UGbyte& g, UGbyte& b, UGint nPercentage);
	static void Contrast(UGbyte& r, UGbyte& g, UGbyte& b, UGint nPercentage);

protected:
	UGLayer* m_pLayer;

	//! \brief �����TileImage��Ӧ�ĵ���Χ
	UGRect2D m_rcCacheTileSetBounds;
	//! \brief ��¼��ǰ����ı�����
	UGdouble m_dCacheTileScale;
	//! \brief ����ͬ��m_pCacheTileImage
	UGMutex	m_MutexCacheTileImage;

	//! \brief �����TileImageData
	UGImageData* m_pCacheTileImageData;

	//! \brief �����Ѿ����ʹ��������ͼ��Ƭ����
	UGCacheTileDatas m_CacheTileDatas;
	//! \brief ת����Ƭ���̹߳�����
	UGTileDataCache m_DataCache;

	//! \brief ������Ƭ����������
	UGRequestTileStub m_RequestStub;

	//! \brief ����ת����ǰ��������
	UGUpdataCacheStub m_UpdataCacheStub;

};

//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////

class UGWebMapLayerStub;

//! \brief �������ݱ仯������̹߳���
class UGDrawDataChange : public UGTaskProcessor, public UGTaskFilter
{
public:
	UGDrawDataChange();
	virtual ~UGDrawDataChange();

	void InitDataChange(UGWebMapLayerStub* pWebMapStub);
	void UnInitDataChange();
	void ResetDataChange();

	//! \brief �����������������
	UGbool AddTask(UGTaskBase* pTask, UGbool bTail = true);

	//! \brief �����������
	UGint RemoveAllTask();

protected:
	//! \brief ������Ⱦ����(���̴߳�����)
	virtual UGbool ProcessTask(UGTaskBase* pTask);

	//! \brief ������Ⱦ����(���̴߳�����)
	virtual UGbool PreTranslateTask(UGTaskBase::TaskState eTaskState, UGTaskBase* pTask, UGbool& bHandle);

private:
	UGWebMapLayerStub* m_pWebMapStub;

	//! \brief �����������
	UGTaskManager m_TaskManager;

};

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

class UGWebMapLayerStub : public UGWebMapStub 
{
	friend class UGDrawDataChange;
public:
	UGWebMapLayerStub();
	virtual ~UGWebMapLayerStub();

public:
	//! \brief ��ʼ�������ͼ�����Ϣ
	virtual void InitWebMapInfo(UGLayer *pLayer);

	//! \brief ����ʼ�������ͼ�����Ϣ
	virtual void UnInitWebMapInfo();

	//! \brief �������������ͼ�����Ϣ
	virtual void ResetWebMapInfo();

	//! \brief ͼ�������ݼ�������Ƭ
	virtual void RequestTile(UGdouble dScale, UGRect2D& rcViewBounds, UGbool bPanMode = false, UGbool bForceUpdate = false);

	//! \brief ���ݵ�ǰ����ͼ��Χ��m_pDrawTileImage���Ƶ�pGraphics��
	virtual UGbool OnDrawTileImage(UGDrawing* pDrawing, UGbool bIsPrinting);

public:
	//! \brief ��ӻ�������
	UGbool AddDataChangeTask(UGTaskBase* pTask, UGbool bTail = true);

	//! \brief ������л�������
	UGint RemoveAllDataCacheTask();

protected:
	//! \brief �̰߳ѱ仯�����ڵ�Tile���Ƶ�m_pCacheTileImageData��
	UGbool ProcessDataChangeTask(UGTaskBase* pTask);

	UGbool CreatePanCacheTileImage(const UGDataChangeInfo& ChangeInfo, UGRect2D& rcTileIntersect);
	UGbool CreateZoomCacheTileImage(const UGDataChangeInfo& ChangeInfo);
	UGbool DrawTiles(UGTiles* pTiles, int nTileSize, const UGDataChangeInfo& ChangeInfo, const UGRect2D* pTilesIntersect = NULL);

protected:
	//! \brief ������Ƭ���̹߳�����
	UGDrawDataChange m_DataChange;

};

//////////////////////////////////////////////////////////////////////////

}

#endif // !defined(AFX_UGWEBMAPLAYERSTUB_H__66585C4A_9CBA_4EE8_98FB_AE9B0C1C2803__INCLUDED_)
