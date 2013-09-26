// UGWebMapLayerStub.h: interface for the UGWebMapLayerStub class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGCACHETILEDATAS_H__66585C4A_9CBA_4EE8_98FB_AE9B0C1C2803__INCLUDED_)
#define AFX_UGCACHETILEDATAS_H__66585C4A_9CBA_4EE8_98FB_AE9B0C1C2803__INCLUDED_

#include "Toolkit/UGThread.h"
#include "Toolkit/UGPalette.h"

namespace UGC {


//////////////////////////////////////////////////////////////////////////

struct MAP_API UGTileData
{
	//! \brief ������
	UGdouble m_dScale;
	//! \brief �к�
	UGint m_nRow;
	//! \brief �к�
	UGint m_nCol;
	//! \brief  ����Χ
	UGRect2D m_rcBounds;
	//! \brief  ����Χ
	UGImageData m_ImageData;
};

//! \brief ����TileData
class MAP_API UGCacheTileDatas
{
public:
	UGCacheTileDatas();
	~UGCacheTileDatas();

	//! \brief ��ȡ�Ƿ���TileData
	UGbool IsEmpty();

	//! \brief ��ȡTileData
	const UGTileData* LookupTile(UGdouble dScale, UGint nRow, UGint nCol);

	//! \brief ��ȡTileData
	UGTileData* LookupTileEx(UGdouble dScale, UGint nRow, UGint nCol);

	//! \brief ����һ��TileData
	UGbool AddTile(UGTileData *pTileData, UGRect2D& rcBounds);

	//! \brief ɾ��һ��TileData
	UGbool RemoveTile(UGdouble dScale, UGint nRow, UGint nCol);

	//! \brief ɾ��һ��TileData
	UGbool RemoveTile(UGdouble dScale, const UGRect2D &rcBounds);

	//! \brief �������TileData
	UGint RemoveAll();

	//! \brief ��ȡTileData����
	UGint GetCount();

public:
	//! \brief TileData��󳤶ȣ�Ĭ����50
	UGint m_nMaxTilesLength;

private:
	//! \brief ����TileData
	UGDict<UGString, UGTileData> m_TileDatas;

	//! \brief �������������б�
	UGMutex m_mutexTileDatas;

};

//////////////////////////////////////////////////////////////////////////

}

#endif // !defined(AFX_UGCACHETILEDATAS_H__66585C4A_9CBA_4EE8_98FB_AE9B0C1C2803__INCLUDED_)