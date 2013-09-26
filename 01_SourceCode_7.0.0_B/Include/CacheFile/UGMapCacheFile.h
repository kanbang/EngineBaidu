#ifndef _UGMAPCACHEFILE_H_
#define _UGMAPCACHEFILE_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CacheFile/UGAbstractCacheFile.h"
#include "CacheFile/UGAbstractCacheFileV70.h"
#include "CacheFile/UGStrategyMapCacheFile.h"
#include "CacheFile/UGCacheFileCommon.h"

#include <vector>

namespace UGC
{

class CACHEFILE_API UGMapCacheFile  
{
public:
	UGMapCacheFile();
	~UGMapCacheFile();

	UGMapCacheFile& operator = (const UGMapCacheFile &CacheFile);

	bool Open(const UGString &strFileName, const UGString &strPassword = _U(""));
	bool Save(const UGString &strFileName);
	bool Close();

	void Reset();

	bool CheckTileBoundsValid(const UGRect2D &rcMPTileBounds, double dScale);
	std::vector<UGTile*> *GetTiles(const UGRect2D &rcMPBounds, double dScale, UGString strPwd, UGString strHashCode);

	// �汾�ţ�Ĭ��Ϊ���°汾��
	void SetVersion(UGMapCacheVersion nVersion);
	UGMapCacheVersion GetVersion() const;

	const UGPrjCoordSys& GetPrjCoordSys();

	bool CheckVersion(UGString strFilePath);
	UGint GetVersionFromFile(UGString strFilePath);

	bool Clear(const UGRect2D &rcBounds, const std::vector<double> &vectScales);
	UGbool Clear(const std::vector<UGdouble> &vectScales, const UGGeoRegion *pRegion);
	UGbool Clear(const UGGeoRegion *pRegion);

	// ������������
	bool SetCacheName(const UGString &strCacheName);
	UGString GetCacheName();

	// ������Դ����
	bool	 SetServiceProvider(const UGString &strServiceProvider);
	UGString GetServiceProvider();

	// ͼƬ���ԣ�������͸��Png32����͸��Png32��Png8��Jpeg�����ͼƬģʽ
	bool SetImageType(UGint nPictureFormat);
	UGint GetImageType();

	// ����ͼƬ���ش�С��Ĭ����256���ؿ��
	bool	SetTileSize(int nTileSize);
	int		GetTileSize();

	// ���ݷ�Χ���Ե�������Ϊ��λ
	bool SetBounds(const UGRect2D &rcBounds);
	UGRect2D GetBounds();

	bool SetIndexBounds(const UGRect2D &rcBounds);
	UGRect2D GetIndexBounds();

	bool SetClipRegion(UGGeoRegion *region);
	const UGGeoRegion *GetClipRegion();

	bool IsFillMargin();
	void SetFillMargin(bool bFillMargin = true);

	bool IsTransparent();
	void SetTransparent(bool bTransparent = true);

	// ÿ�����ж��ٸ����أ�Ĭ��ÿ����3�����أ�x�����y�������һ�°�
	bool SetCoordRatio(double dCoordRatio);
	double GetCoordRatio();

	double GetDPI();

	// ��������Ϣ�����Ҫ�󣬲�Ҫ������ߵĵ�����
	// ������б����߶���������Χ������Ϊ���������� true�����򷵻� false�����Ҳ��Ա��������ý����κ��޸ġ�
	bool SetOutputScales(const std::vector<double>& vectOutputScales);
	std::vector<double> GetOutputScales();

	bool SetOutputScaleCaptions(const std::map<double, UGString> &mapOutputScaleCaptions);
	void GetOutputScaleCaptions(std::map<double, UGString> &mapOutputScaleCaptions);

	// ͶӰ��Ϣ�����ʼ������ϵ��λ�ͻ���ο�ԭ��
	void SetPrjCoordSys(const UGPrjCoordSys &CoordSys);

	// �Ƿ���ջ��棬Ĭ�ϲ��ǽ���
	void SetIsCompactCache(bool bCompactCache);

	// ������λ��
	UGString GetFileDirectory();

	//! \brief ������Ƭ�����кţ��ж�ָ����Ƭ�������Ƿ����,��ʽΪ 1000/00000001x00000009/00000002x00000004.jpg
	//! \param dMapScale [in]		��ǰ��ͼ�ı�����
	//! \return						�����ڷ���false
	//! \remarks					�������£�
	bool IsTileExist(double dMapScale, int nRow, int nCol);

	//! \brief ������Ƭ�����кţ�����Ӧ���ݴ浽��Ӧ·�����߽����ļ���ʽ��,��ʽΪ 1000/00000001x00000009/00000002x00000004.jpg
	//! \param dMapScale [in]		��ǰ��ͼ�ı�����
	//! \return						��ȡ���ɵ�ͼƬ���·��
	//! \remarks					�������£�
	void SaveImageData(double dMapScale, int nRow, int nCol, const UGbyte* pData, int nSize);

	// MPPoint2PixelPos ----> PixelPos2TilePos
	//! \���ݸ����ı����߼����ĵ������Ƭλ��
	//! \param dMapScale [in] ������
	//! \param center [in] ָ�������ĵ�
	//! \param nRow [out] ������Ƭ�к�
	//! \param nCol [out] ������Ƭ�к�
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ�����Ƭ��λ��
	void ComputeTilePosition(double dMapScale, const UGPoint2D &pntCenter, int &nRow, int &nCol);

	//! \���ݸ����ı����߼���Ƭ���кż�����Ƭ��Χ
	//! \param dMapScale [in]		������
	//! \param nRow [in]			ͼƬ�к�
	//! \param nCol [in]			ͼƬ�к�
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ��㵥����Ƭ�ķ�Χ
	UGRect2D ComputeTileMPBounds(double dMapScale, int nRow, int nCol);

	// MPBounds2PixelArea ----> PixelArea2TileArea
	//! \���ݵ�ͼ��Χ����ͼƬ���кŷ�Χ
	//! \param dMapScale [in]		������
	//! \param rcMapBounds [in]		��ͼ��Χ
	//! \param nStartRow [out]		ͼƬ��ʼ�к�
	//! \param nEndRow [out]		ͼƬ�����к�
	//! \param nStartCol [out]		ͼƬ��ʼ�к�
	//! \param nEndCol [out]		ͼƬ�����к�
	//! \param bBigTileImage [in]	�Ƿ��Ǵ��ͼƬ
	//! remarks ��ͼ����ʹ�á���Ҫ�ǳ�ͼʱʹ��
	void ComputeTileRange(double dMapScale, const UGRect2D& rcMapBounds, UGHPDataArea &TileDataArea);

	// ��ȡ���������
	double ScaleToNearFixScale(double dScale);

	// �������͵ı�����ת��Ϊ���������� .5 ת��������Ϊ 2���������������ɻ���Ŀ¼��
	unsigned		Scale2ScalePathName(double dScale);		
	double	ScalePathName2Scale(unsigned nScale);

	// ���ݴ����TileData�еı����ߺ����кţ���ȡTile�ĵ���Χ�����ط�Χ����Tile����������ͼ���ʽ
	bool GetTileData(UGTile& TileData);

	// ���ݴ����TileData�еı����ߣ���ȡTile�ĵ���Χ�����ط�Χ
	void GetTileInfo(UGTile& TileData);

	//! \brief ��ȡ�������ɵ���Ƭ���SCI�ļ���·������ʽΪ 1000/00000001/00000009/00000002x00000004.jpg
	//! \param dMapScale [in]		��ǰ��ͼ�ı�����
	//! \return						��ȡ���ɵ���Ƭ���·��
	UGString ComputeTileFileName(double dMapScale, int nRow, int nCol);

	// ���ݴ򿪵�sci����
	bool SaveAsSCI3D();

	//! \brief ����һ����Χ���ż�����Ƭ֮��ķ�Χ
	//! \param dMapScale ��ͼ������
	//! \param rcMapBounds ��ͼ��Χ
	//! \param nExtTileSize ������Ƭ�ĸ���
	//! \return ����֮��ĵ�ͼ��Χ
	UGRect2D ComputeTilesMPBounds(double dMapScale, const UGRect2D& rcMapBounds, int nExtTileSize = 1);

	//! \brief ͨ��������ת����Ƭ�߳���Ӧ�ĵ����С
	//! \param dMapScale ��ͼ������
	UGSize2D GetTileMPSize(double dMapScale);

	// �ϲ���ͼ����
	// strPath �ϲ�������ͼ������ⲿ����
	// strPassword �ⲿ���������
	bool Merge(const UGString &strPath, const UGString &strPassword = _U(""));
	
	//UGString GetClipRegion();
	TileType GetTileType();
	StoreType GetStorageType();
	int GetImageCompress() ;
	//UGdouble GetCoordRatio();
	UGColor GetDefaultColor();

	// ���ص� UGGeoRegion �������ⲿ�ͷţ�
	UGGeoRegion *GetValidRegion(const UGRect2D &rcBounds, double dScale);

	bool HitTest(const UGPoint2D &pntPosition, double dScale);

	bool Convert(StoreType sotreType, const UGString &strDest, const UGString &strPassword );

	UGbool ConvertSingleCompactFile(const UGString &strCompactFilePath, const UGString &strOutputPath);

	bool Reload();

	UGString GetHashCode();

	UGbool Extract(std::vector<UGdouble> vectScales, const UGGeoRegion &region, StoreType type, const UGString &strPath);

	UGbool Extract(const UGGeoRegion &region, const UGString &strPath);

	// �ʷַ�ʽ
	//TileType GetTileType();

	// ��ȡ�û���չ�ֶε����ã���ֱ���޸ġ�
	// ���map��Ԫ�ظ�����Ϊ0�������α���Ԫ�ص������ļ����
	std::map<UGString, UGString>& UserExtendField();

	//! \brief ɾ���ض��������ɵ��û��Զ���汾
	void DeleteRevisionNumber(UGint value);

private:
	//! \brief ƥ������ߣ��ҵ���ӽ�������
	double AdjustScale(double dScale);

	//! \brief �������ά���õĶ�ʮ�������ߣ�����������������У�������ߵ�ʱ����
	void ComputeLevelsScale();

private:
	UGString m_strFileName;							// sci �ļ����ơ���ִ���� Open() ֮�󣬸����ƾͻᱻ���¡�
	UGMapCacheVersion m_nVersion;					// ��ǰ����İ汾�š��� ToConfigFile() �иð汾��ָʾ��Ҫ�������ļ���ʽ
	UGString m_strTopLevelDirName;					// ����SCI���Ŀ¼λ��

	UGAbstractCacheFileV70 m_HPMapCacheFileV70;
	UGAbstractCacheFile m_HPMapCacheFile;
	UGStrategyMapCacheFile m_StrategyMapCacheFile;

	std::vector<double> m_vect3DLevelsScales;		// ��ά�㼶��Ӧ�ı������б�
	UGCompactFileWrapper *m_pCompactFile;
};

}

#endif // _UGMAPCACHEFILE_H_
