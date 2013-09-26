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
//!  \author ��ʽת���顣
//!  \attention �벻Ҫ����޸�����ĳ������塣
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEXCHANGEFILETYPE_H__EAB125D4_D53A_4784_A77E_5A8636BC43BD__INCLUDED_)
#define AFX_UGEXCHANGEFILETYPE_H__EAB125D4_D53A_4784_A77E_5A8636BC43BD__INCLUDED_

#include "Stream/ugdefs.h"
#include "Stream/UGByteArray.h"

namespace UGC {

#define UG_WEB_SERTYPE _U("WebMapType") // Web��������

// ��ͼ�����ʷַ�ʽ
enum  TileType
{
	Global = 0,		// ȫ���ʷַ�ʽ
	Local  = 1,		// �����ʷַ�ʽ���ñ����߷ֲ�
};

//! \brief ����ת��֧�ֵ��ļ����͡�
class FILEPARSER_API UGFileType
{
public:

	//! \brief �ļ���ʽ���顣
	enum EmGroup
	{
		//! \brief ��֪��Ӧ�÷ŵ��ĸ�����
		GroupUncertain = 0,		
		//! \brief ʸ�����͵��ļ���ʽ
		GroupVector	= 1,		
		//! \brief �û������ʸ����ʽ
		GroupUserVector	= 2,		
		//! \brief դ�����͵��ļ���ʽ
		GroupRaster = 3,	
		//! \brief �û������դ���ʽ
		GroupUserRaster = 4 ,
		//! \brief �����ռ��ļ���ʽ��������ݼ���
		GroupWorkSpace =  5,
	};


	// �ļ���ʽ����	
	// SuperMapԤ����ʸ����ʽ���� [1, 100]
	// ����ͨ��ʸ����ʽ[1, 50]	XML��ʽ[51, 60]	���ݿ��ļ�[60, 70]
	// SuperMap���Ÿ��û����п�����ʸ����ʽ����: [101, 200]
	enum EmType
	{
		// ����ʶ	
		none			= 0, 

		//!AutoCAD DWG �����ļ�
		DWG				= 2,	
		//!AutoCAD DXF �����ļ�
		DXF				= 3,	

		// ERSI File [6, 10]
		//!Arc/Info Coverage
		AIBinCov		= 6,
		//!Arc/Info E00�����ļ�
		E00				= 7,	
		
		//!ArcView Shape�ļ�
		Shape			= 8,	
		
		// MapInfo File [11, 15]
		//!MapInfo TAB
		TAB				= 11,	
		//!MapInfo MIF �����ļ�
		MIF				= 12,
		//!MapInfo �����ռ��ļ�
		WOR             = 13,
		
		// MicroStation File [16, 20]
		//!Microstation DGN�ļ�
		DGN				= 16,	

		Lidar			= 17, //! ASPRS Lidar Data Exchange Format (LAS)
		
		// other GIS/CAD software File [21, 50]
 		VCT				= 22,	//!���ұ�׼ʸ���ļ� *.VCT

		
		// other vector file 
		//!EMF�ļ�(windows metaFile:Ԫ��ǿ�ļ�)
		EMF				= 34,	
		//!WMF�ļ�(windows metaFile:Ԫ�ļ�)
		WMF				= 31,	
		//!EPS�ļ�
		EPS				= 32,	
		//!PDF�ļ�
		PDF				= 33,
		
		//!���Ӻ�ͼ��ʽ
		ENC				= 40,
		//!���Ÿ�ʽ
		TEMSVector		= 41,	//!����Vector��ʽ
		TEMSBldngVctr	= 42,	//!����Building vector��ʽ
		
		//XML document [51, 60]
		//!OpenGIS �����XML �ĵ�
		GML				= 51,	
		//!SuperMap �����XML�ĵ�
		SML				= 52,
		//google��KML�ļ���ʽ
		KML				= 53,
		//google��KML��ʽ��ѹ���ļ�
		KMZ				= 54,
		//MapGis�����ļ�wat��wal��wap
		MAPGIS			= 55,
		
		//database file [61, 70]
		DBF				= 61,	//!dbf ���ݿ��ļ�

		SCV				= 63,   //!��άģ�ͻ����ļ�
		CSV				= 64,	//!�ı��ļ�

		//! Fme�����ռ�ĵ���ģʽ
		FMEWorkBench    = 65,

		//! ʸ������ʹ��fme���е���
		FMEVector       = 66, 

		//! դ������ʹ��fme���е���
		FMERaster       = 67, 
		
		// SDE��ʸ����ʽ
		SDEVector		= 68,
		
		// SDE��դ���ʽ
		SDERaster		= 69,
		
		// Esri file geodatabase vector .gdb�ļ�
		GDBFVector      = 70,
		
		// Esri file geodatabase raster .gdb�ļ�
		GDBFRaster      = 71,
		
		// Esri Personal geodatabase	.mdb�ļ�
		GDBP		    = 72,

		// SuperMapԤ����դ���ʽ���� [101, 200]
		// ����Ӱ����[101, 120] ͼƬ��[121, 140] DEM/Grid��[141-160] 
		// ����[161, 180] Ԥ����ʽ[181, 200]

		// Ӱ���� [101, 120]
		//!Erdas Image�ļ�
		IMG				= 101,	
		//!sid�ļ�
		SID				= 102,	
		//!Tiff/BigTIFF/GeoTIFF�ļ�
		GTiff			= 103,	
		//!Er-Mapper ECW�ļ�
		ECW				= 106,	
		//!Idrisi դ���ļ�
		IDR				= 107,	
		//!Landsat��7 FST�ļ�����׺��(*.fst)
		FST				= 108,	

		// ͼƬ�� [121, 140]
		//!bitmap�ļ�
		BMP				= 121,	
		//!jpg�ļ�
		JPG				= 122,	
		//!portal network graphic(PNG)		
		PNG				= 123,	
		//!gif�ļ�
		GIF				= 124,	
		//!tga�ļ�
		TGA				= 125,	

		// DEM/Grid�� [141-160]
		//!BIL��ʽ��grd�ļ�
		BIL				= 141,	
		//!Arc/Info ASCII �����ļ�
		AIASCIIGrid		= 142,	
		//!������������ļ�
		DEM				= 143,	
		//!USGS���������ļ� ������׼
		USGSGrid		= 144,	
		//!Arc/Info binary grid�ļ�
		AIBinGrid		= 145,
		//!���Ÿ�ʽ
		TEMSClutter		= 146,	//!����Raster��ʽ

		JPGPNG          = 147, //��JPG��PNGͼƬ��ϸ�ʽ 

		BIP             = 148,
		BSQ             = 149,

		// ����	[161, 180]
		//!raw�ļ�
		RAW				= 161,	

		// Ԥ����ʽ [181, 200]
	
		//!SuperMapѹ��Ӱ�� SuperMap Image Tower
		SIT				= 204,

		// ������Ԥ�� 100����� �����ܵ�ʹ�� [301, 400]
		// SuperMapΪ�û����п�������ת��Ԥ�����ļ���ʽ���� [401, 500]		
		// ʸ��: [401, 450]		
		//!�û��Զ���ʸ��1
		UserVectorBegin	= 401, 
		//!�û��Զ���ʸ��2
		UserVectorEnd	= 450, 
		
		// դ��: [451, 500]
		//!�û��Զ���դ��1
		UserRasterBegin	= 451, 
		//!�û��Զ���դ��2
		UserRasterEnd	= 500,

		//ģ���ļ�
		//3DSģ���ļ�
		Model3DS        = 501,

		//sgmģ���ļ�
		SGM				= 502,	

		//xģ���ļ�
		ModelX			= 503,

		//daeģ���ļ�
		ModelDAE        = 504,

		//osgģ���ļ�
		ModelOSG        = 505,

		//SuperMapTileEncodeType
		STET            =506,
	};

	
	//! \brief �����ļ���ʽ�����ж����ָ�ʽ������һ���顣
	//! \param eFileType [in]��
	static EmGroup GetFileGroup(EmType eFileType);	

	//! \brief ���ݺ�׺���õ��ļ����͡�
	//! \param strExtName [in] ��.�ĺ�׺�� ��
	static EmType ExtNameToFileType(const UGString& strExtName);	
	
	//! \brief �����ļ����͵õ���׺����
	//! \param strExtName [in]��
	static UGString FileTypeToExtName(EmType eFileType);

	static UGString DetailByFileType(EmType etype);

	//! \brief �Ƿ���ʸ�����͡�
	//! \param eFileType [in]��
	static UGbool IsVector(EmType eFileType);	

	static UGbool IsModelFile(EmType eFileType);
	
	//! \brief �Ƿ���Ե����CAD���͡�
	//! \param eFileType [in]��
	//! \attention ĿǰֻFME��ʹ�á�
	static UGbool IsCanBeCAD(EmType eFileType);

	//! \brief ��������ݼ������Ƿ�Ҫ�Ӻ�׺��
	//! \param eFileType [in]��
	//! \attention ĿǰֻFME��ʹ�á�
	static UGbool IsNeedAddEx(EmType eFileType);

	//! \brief ����������Ƿ���Engine���� ��SDE��
	//! \param eFileType [in]��
	//! \attention ĿǰֻFME��ʹ�á�
	static UGbool IsNoEngineType(EmType eFileType);
};

//! \brief �ص�����������������Ƭ����Ϣ��
struct UGDownloadTileInfo
{
	//! \brief ������
	UGdouble m_dScale;

	//! \brief  ����Χ
	UGRect2D m_rcBounds;

	//! \brief �к�
	UGint m_nRow;

	//! \brief �к�
	UGint m_nCol;

	//! \brief ���سɹ�ʱ��Ϊ0����0Ϊ�д���
	UGint m_eErrorType;

	//! \brief ���� ==
	//! \param const UGMapDownloadRequest& request
	//! \return	 ��������������򷵻�true
	UGbool operator==(const UGDownloadTileInfo& TileInfo) const
	{
		if (m_dScale == TileInfo.m_dScale && m_nRow == TileInfo.m_nRow && m_nCol == TileInfo.m_nCol)
		{
			return TRUE;
		}

		return FALSE;
	}

	//! \brief ����=��
	//! \param &request [in]��
	void operator = (const UGDownloadTileInfo &TileInfo)
	{
		m_eErrorType = TileInfo.m_eErrorType;
		m_rcBounds = TileInfo.m_rcBounds;
		m_nRow = TileInfo.m_nRow;
		m_nCol = TileInfo.m_nCol;
		m_dScale = TileInfo.m_dScale;
	}
};

class UGTile
{
public:
	UGTile()
	{
		m_nRow = 0;
		m_nCol = 0;
	}
	~UGTile()
	{
	}

	void SetScale(UGdouble dScale) 
	{
		m_dScale = dScale;
	}

	UGdouble GetScale() const 
	{
		return m_dScale;
	}

	void SetTileRow(UGint nRow)
	{
		m_nRow = nRow;
	}
	UGint GetTileRow()
	{
		return m_nRow;
	}

	void SetTileCol(UGint nCol)
	{
		m_nCol = nCol;
	}
	UGint GetTileCol()
	{
		return m_nCol;
	}

	void SetFileType(UGint nFileType)
	{
		m_nFileType = nFileType;
	}

	UGint GetFileType()
	{
		return m_nFileType; 
	}

	void SetByteArray(const UGByteArray &ByteArray)
	{
		m_ByteArray = ByteArray;
	}

	UGByteArray &GetByteArray()
	{
		return m_ByteArray;
	}

	void SetTilePos(int nRow, int nCol) 
	{
		m_nRow = nRow;
		m_nCol = nCol;
	}
	void GetTilePos(int &nRow, int &nCol) const 
	{
		nRow = m_nRow;
		nCol = m_nCol;
	}

	void SetMPBounds(const UGRect2D &rcBounds) 
	{
		m_rcBounds = rcBounds;
	}
	const UGRect2D &GetMPBounds() const 
	{
		return m_rcBounds;
	}

	void SetTileSize(UGint nTileSize) 
	{
		m_nTileSize = nTileSize;
	}

	UGint GetTileSize() const 
	{
		return m_nTileSize;
	}

private:
	// ������
	UGdouble m_dScale;

	// ��Ƭλ��
	int m_nRow;
	int m_nCol;

	//! \brief  ����Χ
	UGRect2D m_rcBounds;

	//! \brief  Tile ��ͼ���ʽ
	UGint m_nFileType;

	//! \brief  Tile ���ļ���
	UGByteArray m_ByteArray;

	//! \brief  Tile �����ؿ��
	UGint m_nTileSize;

};

//! \brief ���ݱ仯�ص������������ýṹ�ڶ��߳���ʹ��
struct UGDataChangeInfo
{
	enum ChangeType
	{
		DownLoad = 0,	// ������������ı仯
		Zoom = 1,		// ��������ı仯
		Pan = 2			// �ƶ�����ı仯
	};

	//! \brief �������ݱ仯������
	ChangeType m_eChangeType;
	//! \brief ��ͼ������
	UGdouble m_dMapScale;
	//! \brief ��ͼ��Ӧ��Ƭ�����������
	UGdouble m_dTileScale;
	//! \brief ��ͼMP->LP��ת������
	UGdouble m_dCoordRatio;
	//! \brief  ���ݱ仯����(����Χ)
	UGRect2D m_rcChangeBounds;
	//! \brief  ���ݲ��������(����Χ)
	UGRect2D m_rcClipBounds;
	//! \brief �������سɹ�ʱ��Ϊ0����0Ϊ�д���
	UGint m_eErrorType;
	//! \brief ���ݱ仯����(�豸��Χ)
	UGint m_nChangeWidth;
	//! \brief ���ݱ仯����(�豸��Χ)
	UGint m_nChangeHeight;
	//! \brief �к�(���ڵ���)
	UGint m_nRow;
	//! \brief �к�(���ڵ���)
	UGint m_nCol;

	UGDataChangeInfo()
	{
		m_eChangeType = DownLoad;
		m_dMapScale = 0.0;
		m_dTileScale = 0.0;
		m_dCoordRatio = 0.0;
		m_rcChangeBounds.SetEmpty();
		m_rcClipBounds.SetEmpty();
		m_eErrorType = 0;
		m_nChangeWidth = 0;
		m_nChangeHeight = 0;
		m_nRow = 0;
		m_nCol = 0;
	}

	//! \brief ���� ==
	UGbool operator==(const UGDataChangeInfo& ChangeInfo) const
	{
		if (m_dMapScale == ChangeInfo.m_dMapScale && m_rcChangeBounds == ChangeInfo.m_rcChangeBounds)
		{
			return TRUE;
		}

		return FALSE;
	}

	//! \brief ����=��
	void operator = (const UGDataChangeInfo& ChangeInfo)
	{
		m_eChangeType = ChangeInfo.m_eChangeType;
		m_dMapScale = ChangeInfo.m_dMapScale;
		m_dTileScale = ChangeInfo.m_dTileScale;
		m_dCoordRatio = ChangeInfo.m_dCoordRatio;
		m_rcChangeBounds = ChangeInfo.m_rcChangeBounds;
		m_rcClipBounds = ChangeInfo.m_rcClipBounds;
		m_eErrorType = ChangeInfo.m_eErrorType;
		m_nChangeWidth = ChangeInfo.m_nChangeWidth;
		m_nChangeHeight = ChangeInfo.m_nChangeHeight;
		m_nRow = ChangeInfo.m_nRow;
		m_nCol = ChangeInfo.m_nCol;
	}

};

typedef UGArray<UGTile*> UGTiles;


} //namespace UGC


#endif // !defined(AFX_UGEXCHANGEFILETYPE_H__EAB125D4_D53A_4784_A77E_5A8636BC43BD__INCLUDED_)


