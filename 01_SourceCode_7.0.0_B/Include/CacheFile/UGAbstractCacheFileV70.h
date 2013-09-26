/*
���������ļ�����ҪӦ���ڱ��滺���һЩ����������Ϣ���ϲ���л�������ɺͶ�ȡ���롣�����ͼ�ȹ��ܣ�
���������������ļ������ɷ���·������Ļ����ļ���Supermap���ϲ�������ͳһ����ʾ��
Ŀ¼����Ϊ��
��һ��Ϊ��Ŀ¼�ļ��У������������ŵ�λ�á��ļ���������ȡ���ڲ����SCI�������ļ��͸��������ߵ��ļ���
�ڶ���Ϊ�����������ļ��У��м��������߻���ͻ��м����ļ��У��ļ��е����������Ǳ����ߵ�����ֱ��ȡ��������1:5000.9���ļ�����Ϊ5000
������Ϊ����ļ��У�������ȷֳɴ�飬����16*16��ͼƬ����128*128��ͼƬ���������������к�
���ļ�Ϊ����ͼƬ�ļ�

�����ͼ���ɻ������̣�
1 ������һ��Ŀ¼�ļ���
2 �ڵ�һ��Ŀ¼�ļ�����ߵ��� ToConfigFile ����SCI�����ļ�
3 ���ݷ�Χ��������СͼƬ����ʼ��ֹ���кţ����ú��� ComputeTileRange
4 ˫��forѭ��������ÿһ��СͼƬ�����кż��� ���ȫ·���������ýӿ� ComputeTileFileName 
														��ʽΪ 1000/1x9/2x4.jpg
5 ���� ���ȫ·�������жϱ����Ƿ��Ѿ��л���СͼƬ�ˣ�û�����ж��ļ��� 1000/00000001x00000009 �Ƿ���Ҫ��
����Ȼ�����СͼƬ��Χ������Ӧ����
*/


// NOTE �����Ľ��ص�
// ��ȷ����
// ��ȫ��֤���㹫ʽ��ȷ�������ڸ��������
// �����Ƿ��Ǵ��б����߲����ĺ���ֻ�ܹ������趨�ı����ߡ������������ֻ��Ҫ�����ߵ��±꼴�ɡ����±����û����õı������±꣬���������ı������±ꣿ
// PixelArea ��Ψһ���Զ����࣬��Ƭ��š���Ƭ���š���Ƭ��Χ����Ƭ�鷶Χ�����ر�ţ������ñ�����ȥ�� DataTileArea �ȡ�
// ���ࡢ�ļ�����Ϊ UGHPMapCacheFile��

#ifndef _UGABSTRACTCACHEFILEV70_H_
#define _UGABSTRACTCACHEFILEV70_H_

#include "FileParser/UGExchangeFileType.h"
#include "Base/ogdccolordef.h"
#include "Stream/UGByteArray.h"
#include "CacheFile/UGCacheFileCommon.h"
#include "Geometry/UGGeoRegion.h"
#include "Toolkit/UGMarkup.h"
#include "Stream/UGCacheFile.h"


#define SUPERMAPSCI 0
#define ARCGISXML 1

#include <vector>

namespace UGC
{

class CACHEFILE_API UGAbstractCacheFileV70
{

	class FilterFileCell
	{
	public:
		char data[FilterFileCellSize];
		UGbool IsExist();
		void SetExist(UGbool bExist = true);

		UGColor GetColor();
		void SetColor(UGColor color);

		char *GetData();
		FilterFileCell();
	};

	friend class UGMapCacheFile;

public:
	UGAbstractCacheFileV70();
	~UGAbstractCacheFileV70();

	// �汾�ţ�Ĭ��Ϊ���°汾��
	void				SetCacheVersion(UGMapCacheVersion nVersion);
	UGMapCacheVersion	GetCacheVersion() const;

	// �ڲ��汾���
	void				SetFullCacheVersion(UGint nVersion);
	UGint				GetFullCacheVersion() const;

	// ������������
	UGbool			SetCacheName(const UGString &strCacheName);
	const UGString &GetCacheName();
	const UGString &GetFinalCacheName();

	// ������Դ����
	UGbool			SetServiceProvider(const UGString &strServiceProvider);
	const UGString &GetServiceProvider();

	// ͶӰ��Ϣ�����ʼ������ϵ��λ�ͻ���ο�ԭ��
	void				 SetPrjCoordSys(const UGPrjCoordSys &CoordSys);
	const UGPrjCoordSys &GetPrjCoordSys() const;

	// ͼƬ���ԣ�������͸��Png32����͸��Png32��Png8��Jpeg�����ͼƬģʽ
	UGbool		SetMixedImageType(unsigned nPictureFormat);
	unsigned	GetMixedImageType() const;

	UGint				GetIntImageType();
	UGbool				SetIntImageType(UGint nType);

	UGFileType::EmType	GetSingleImageType();
	UGbool				SetSingleImageType(UGFileType::EmType nType);

	UGint GetTileGroupSize() { return nTileGroupSize; }

	// ����ͼƬ���ش�С
	UGbool	SetTileSize(UGint nTileSize);
	UGint		GetTileSize() const;

	// ���ݷ�Χ���Ե�������Ϊ��λ
	void			SetBounds(const UGRect2D &rcBounds);
	const UGRect2D &GetBounds() const;
	const UGRect2D GetFinalBounds();

	TileArea GetFinalExtendedTileArea(UGdouble dScale);

	// ÿ�����ж��ٸ����أ�Ĭ��ÿ����3�����أ�x�����y�������һ�°�
	UGbool		SetCoordRatio(UGdouble dCoordRatio);
	UGdouble		GetCoordRatio();

	void		SetDPI(UGdouble dCoordRatio);
	UGdouble	GetDPI();

	void SetHashCodeEnabled(UGbool bValue = true);
	UGbool IsHashCodeEnabled();

	void			SetIndexBounds(const UGRect2D &rcIndexBounds);
	const UGRect2D &GetIndexBounds();
	UGRect2D		GetFinalIndexBounds();

	// ��������Ϣ�����Ҫ�󣬲�Ҫ������ߵĵ�����
	// ������б����߶���������Χ������Ϊ���������� true�����򷵻� false�����Ҳ��Ա��������ý����κ��޸ġ�//�Ƿ������˹̶�������
	UGbool					SetOutputScales(const std::vector<UGdouble>& vectOutputScales,UGbool bIsDisplayByScales = false);
	std::vector<UGdouble>		GetOutputScales();
	std::vector<UGdouble>		GetSortedOutputScales();		// TODO ��ȫȥ��

	UGbool SetOutputScaleCaptions(const std::map<UGdouble, UGString> &mapOutputScaleCaptions);
	void GetOutputScaleCaptions(std::map<UGdouble, UGString> &mapOutputScaleCaptions);
	const std::map<UGdouble, UGString> &GetOutputScaleCaptions();

	// �Ƿ���ջ��棬Ĭ�ϲ��ǽ���
	void	SetIsCompactCache(UGbool bCompactCache);
	UGbool	IsCompactCache();

	// ����ָ����ȫ·��������/����SCI�����ļ���
	UGbool ToConfigFile(const UGString& strCacheFile,UGbool bChangeOutputDir=true);//���UGbool�Ƿ��޸����·����inf�ļ����޸�·��
	UGbool FromConfigFile(const UGString& strCacheFile);
	UGbool ToProjection(const UGString& strProjectionFile);//ͶӰ��Ϣ��¼���ļ�
	UGbool FromProjection(const UGString& strProjection);

	//UGbool ToInfFile(const UGString &strInfPath);

	// �򿪣��رջ����ļ�
	// strCacheFile�������ļ� .sci ·����
	// strPassword�����ļ���������
	UGbool Open(const UGString &strCacheFile, const UGString &strPassword = _U(""));
	void Close();

	// ������λ��
	// strFileDirectory ��λ��Ϊ���涥���ļ�������·����
	// ���磬�����·������Ϊ D:\NE���򻺴�� .sci ·��Ϊ D:\NE\CacheName\CacheName.sci��
	void			SetFileDirectory(const UGString &strFileDirectory);
	const UGString &GetFileDirectory();

	const UGString &GetCacheFileName();

	// ����/�ж� margin �Ƿ��������
	// bFillMargin == true��������ݡ�bFillMargin == false������Ϊ��ɫ��͸����
	void SetFillMargin(UGbool bFillMargin);
	UGbool IsFillMargin();

	// ����/��ȡ����ͼƬѹ����
	// �������ֵ������ [0, 100] �ķ�Χ������ false�����Ҳ���ԭ�����ý����޸�
	// ���ѹ�� 0��������� 100��
	void	SetImageCompress(UGint nCompress);
	UGint		GetImageCompress();

	// ����/��ȡͼƬ����ɫ�Ƿ�͸��
	void	SetTransparentBack(UGbool bTransparentBack);
	UGbool	IsTransparentBack();
	UGbool	IsFinalTransparentBack();

	// ����/��ȡ�ü�����
	// ���û�����òü����򣬻�ȡ���Ϊ NULL��
	UGbool				SetClipRegion(UGGeoRegion *pClipRegion);
	const UGGeoRegion  *GetClipRegion();

	// ����/�ж��Ƿ�Ϊȫ���ʷ�
	void		SetTileType(TileType tileType);
	TileType	GetTileType();

	// ����/��ȡ��ͼ��Χ
	// ���û�����û��淶Χ����ʹ�õ�ͼ��Χ
	// ���û������������Χ����ʹ�õ�ͼ��Χ
	void			 SetMapBounds(const UGRect2D &rcMapBounds);
	const UGRect2D	&GetMapBounds();

	// ��ͼ����
	// ���û�����û��������򻺴���Ϊ��ͼ��
	void			 SetMapName(const UGString &strName);
	const UGString	&GetMapName();

	// ���ݼ�����
	// ���û�����û��������򻺴���Ϊ���ݼ���
	void			 SetDatasetName(const UGString &strName);
	const UGString& GetDatasetName();

	// ����/��ȡ hash ֵ��
	// ע�⣬�� hash ֵ���������� hash ֵ��һ���ο���
	// ���� hash ֵ�Ǹ� hash ֵ���� AdjustHashCode() ����֮��Ľ��
	// ��ȡ�� hash ֵΪ���� hash ֵ
	UGString   &GetHashCode();
	void		SetHashCode(const UGString &strHashCode);

	void		SetDynamicCache(UGbool bDynamic);
	UGbool		IsDynamicCache();

	// ���ݻ���ͼƬ�Ƿ�͸���Լ�����ͼƬ��ʽ�Ƿ�֧��͸�������� hash ֵΪ���� hash ֵ
	// TODO ������Ϊ private��ʹ���Զ������ķ�ʽ��ʵ��
	void		AdjustHashCode(UGString &strHashCode);

	// Ĭ�Ϲ���ɫ�Ļ�ȡ������
	void	SetDefaultColor(UGColor color);
	UGColor	GetDefaultColor();

	// =================== ���ط�Χ������Χ�������ߡ����кš�·����ת�� ===================
	UGbool PixelArea2MPBounds(UGdouble dScale, const PixelArea &rcPixelArea,	UGRect2D &rcMPBounds);

	// ��ָ���������µ���Χת��Ϊ���ط�Χ������������ת����������Ҫ����ѡ��

	// ������Χ���κ������ཻʱ����ʹֻռ�����صļ���һ���֣�Ҳ��Ϊ�����ڸ�������
	UGbool MPBounds2PixelAreaInclusive(UGdouble dScale, const UGRect2D &rcMPBounds,	PixelArea &pixelArea);

	// ������Χ���κ������ཻʱ����ʹֻռ�����صľ��󲿷֣�ֻҪ������û���ཻ��Ҳ��Ϊ�������ڸ�������
	UGbool MPBounds2PixelAreaExclusive(UGdouble dScale, const UGRect2D &rcMPBounds,	PixelArea &pixelArea);

	// ������Χ�������ཻʱ���ཻ�ı߽簴��������ķ�ʽ�����жϡ��󲿷�ʹ������Ҫʹ�õ��Ǹú�����
	// �ú����ܹ���֤ͨ��PixelArea2MPBounds�ٴ�ת������ʱ��ԭ����Χ��ӽ������Բ��ܱ�֤��ͬ��
	UGbool MPBounds2PixelAreaRounded(UGdouble dScale, const UGRect2D &rcMPBounds,	PixelArea &pixelArea);

	// �������ת��Ϊ��������
	UGbool MPPos2PixelPos(UGdouble dScale, const UGPoint2D &pntPosition, PixelArea &pixelArea);

	UGbool TileArea2PixelArea(const TileArea &tileArea,	PixelArea &rcPixelArea);
	UGbool PixelArea2TileArea(const PixelArea &rcPixelArea,	TileArea &tileArea);

	UGbool TileArea2TileGroupArea(const TileArea &tileArea, TileGroupArea &tileGroupArea);
	UGbool TileGroupArea2TileArea(const TileGroupArea &tileGroupArea, TileArea &tileArea);

	// ��ȫ�������Ƭ���кŻ���ɶ�Ӧ���ջ�������к�
	static void ConvertRowCol(UGint& nRow, UGint& nCol);
	static void CompactCellPos2TilePos(UGint nTileGroupRow, UGint nTileGroupCol, UGint nCellRow, UGint nCellCol, UGint &nTileRow, UGint &nTileCol);

	// =========================================================================================

	// �ϲ���ͼ����
	// strPath���ϲ�����ǰ��ͼ������ⲿ��ͼ���棬��ָ�� SCI �ļ�
	// strPassword�����ⲿ��ͼ����Ϊ���մ洢ʱ���򿪵�ͼ���������
	UGbool Merge(const UGString &strPath, const UGString &strPassword = _U(""));

	UGbool Convert(StoreType storeType, const UGString &strDest, const UGString &strPassword);
	UGbool ConvertSingleCompactFile(const UGString &strCompactFilePath, const UGString &strDest);

	std::vector<UGTile*> *GetTiles(const UGRect2D &rcBounds, UGdouble dScale, UGString strPwd, UGString strHashCode, UGCompactFileWrapper *pCompactFile, UGint nImageType, UGbool bTransparent, UGbool bPreciseMatch);

	// MPPoint2PixelPos ----> PixelPos2TilePos
	//! \���ݸ����ı����߼����ĵ������Ƭλ��
	//! \param dScale [in] ������
	//! \param center [in] ָ�������ĵ�
	//! \param nRow [out] ������Ƭ�к�
	//! \param nCol [out] ������Ƭ�к�
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ�����Ƭ��λ��
	// NOTE ���� UGMapCacheFile ʹ�ã������ط�����ʹ�á�
	void ComputeTilePosition(UGdouble dScale, const UGPoint2D &pntCenter, UGint &nRow, UGint &nCol);

	// �Ƿ����ĳ��ͼƬ����
	UGbool ContainsPNGTypeP(unsigned nImageType);
	UGbool ContainsBMPTypeP(unsigned nImageType);
	UGbool ContainsJPGTypeP(unsigned nImageType);
	UGbool ContainsGIFTypeP(unsigned nImageType);

	// �������͵ı�����ת��Ϊ���������� .5 ת��������Ϊ 2���������������ɻ���Ŀ¼��
	unsigned	Scale2ScalePathName(UGdouble dScale);		
	UGdouble		ScalePathName2Scale(unsigned nScale);


	// ͨ��ͼƬ���ͻ�ȡ�ļ���׺��
	static UGString GetFileExtName(UGFileType::EmType nPictureFormat);

	// ������ջ�����Ƭ��
	// Ҫ����Ƭ���ⲿ�Ѿ���ȫ������ϣ�������Ƭͷ����
	UGbool OpenCompactFile(UGdouble dScale, UGint nRow, UGint nCol, UGCompactFileWrapper &compactFile, UGbool bCreateIfAbsent = false);
	UGbool CreateCompactFile(UGdouble dScale, UGint nRow, UGint nCol, UGCompactFileWrapper &compactFile);
	UGbool CreateOrgSolidCompactFile(UGdouble dScale, UGint nRow, UGint nCol, UGCompactFileWrapper &compactFile, UGbool bCreateIfAbsent = false);
	// ����������
	void SetOutputScales_aux(const std::vector<UGdouble>& vectOutputScales,UGbool bIsDisplayByScales = false);//�Ƿ������˹̶�������

	//! \���ݸ����ı����߼���Ƭ���кż�����Ƭ��Χ
	//! \param dScale [in]		������
	//! \param nRow [in]			ͼƬ�к�
	//! \param nCol [in]			ͼƬ�к�
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ��㵥����Ƭ�ķ�Χ
	UGRect2D ComputeTileMPBounds(UGdouble dScale, UGint nRow, UGint nCol);

	//! \���ݸ����ı����߼���Ƭ���кŷ�Χ������Ƭ��Χ
	//! \param dScale [in]		������
	//! \param TileDataArea [in]	��Ƭ���кŷ�Χ
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ�����ж�����Ƭ�ķ�Χ
	UGRect2D ComputeTileMPBounds(UGdouble dScale, const UGHPDataArea &TileDataArea);

	UGRect2D ComputeTileMPBounds(const UGString& strFileName, UGbool bGlobal = false);
	void ComputeImageFileName(const UGPoint2D &pntCenter, UGdouble dScale, UGString& vectAbsoluteFileNames);
	void ComputeImageFileName(const UGRect2D &rcMPCellImageBounds, UGdouble dScale, std::vector<UGString>& vectAbsoluteFileNames);

	// �������г�Ա
	void Reset();

	// �����ļ�����
	void ResetSCIContent();

	// bSingleTile���Ƿ�Ҫ���ƶ��ĵ���Χ�����ǵ�����Ƭ�ķ�Χ����Ϊfalse��������ĵ���Χ�����Ƕ�����Ƭ�ķ�Χ��
	UGbool CheckTileBoundsValid(const UGRect2D &rcMPTileBounds, UGdouble scale, UGbool bSingleTile = true);

	// ����һ����ɫͼƬ
	UGbool ConstructSolidImageFile(const UGString &strAbsoluteFileName, UGColor color, UGFileType::EmType fileType);

	// ���ݵ�ͼͶӰ����ͼ�����ߡ���ͼ��Χ�����ط�Χ����ÿ�����ж��ٸ����أ������ڲ�����
	static UGdouble ComputeCoordRatio(const UGPrjCoordSys& prjCoordSys, UGdouble dScale, UGdouble dMapWidth, UGint nPixelWidth);

	// ���ݵ�ͼͶӰ�ͳ�ʼ���ؿ�ȳ�ʼ��ͼ��ȼ��������
	static std::vector<UGdouble> ComputeMapScale(const UGPrjCoordSys& prjCoordSys, UGdouble dMapWidth, UGint nPixelWidth, 
												UGint nScaleCount = 22, UGdouble dCoordRatio = 3);

	//���ݵ�ͼͶӰ����ʼ���ؿ�Ⱥͱ����ߣ�����㼶
	static UGint ComputeLevelByScale(const UGPrjCoordSys& prjCoordSys, UGdouble dLevel0Width, UGdouble dScale, UGint nPixelWidth,
									UGdouble dCoordRatio = 3);

	// ���ݵ�ͼͶӰ�ͳ�ʼ���ؿ�ȼ���ĳһ�㼶��Ӧ������
	static UGdouble ComputeMapScaleByLevel(const UGPrjCoordSys& prjCoordSys, UGint nPixelWidth, UGint nLevel, UGdouble dCoordRatio);


	static std::vector<UGint> ComputeLevel(const UGPrjCoordSys& prjCoordSys, UGdouble dMapWidth, 
											UGint nPixelWidth, const std::vector<UGdouble>& scales, UGdouble dCoordRatio);

	UGbool Extract(const std::vector<UGdouble> &vectScales, const UGGeoRegion &region, StoreType storageType, const UGString &strOutputPath);

	UGbool Extract(const UGGeoRegion &region, const UGString &strOutputPath);

	UGbool Clear(const UGRect2D &rcBounds, UGdouble dScale, UGbool clearFolder =false);
	UGbool Clear(UGdouble dScale, const UGGeoRegion *pRegion);

	void ClearDynamicCache(const UGRect2D &rcBounds);

	// ͨ��������ת����Ƭ�߳���Ӧ�ĵ����С
	UGSize2D ComputeTileMPSize(UGdouble dScale) const;

	//Ϊ����׼ȷ�����س�����ʱ�����������������õĵط����ࡣ��û����UGdouble���͵�����λ�õĺ�������������ô���£�
	UGdouble GetUnitsRatio();

	UGbool HitTest(const UGPoint2D &pntPosition, UGdouble dScale);

	UGbool Reload();

	// �����ļ������ͼƬ�������ͣ�������
	static UGFileType::EmType DataHeaderToImageType(const UGbyte* pData);

	// ������Ƭ�����кţ��ж�ָ����Ƭ�������Ƿ����
	// dScale		��ǰ��ͼ�ı�����
	UGbool IsTileExist(UGdouble dScale, UGint nRow, UGint nCol) ;

	// ���ݴ����TileData�еı����ߣ���ȡTile�ĵ���Χ�����ط�Χ
	void GetTileInfo(UGTile& TileData, UGCompactFileWrapper *pCompactFile);

	// ���ݴ����TileData�еı����ߺ����кţ���ȡTile�ĵ���Χ�����ط�Χ����Tile����������ͼ���ʽ
	UGbool GetTileData(UGTile& TileData, UGCompactFileWrapper *pCompactFile);

	// NOTE ���ص� UGGeoRegion �������ⲿ�ͷţ�
	UGGeoRegion *GetValidRegion(UGRect2D rcBounds, UGdouble dScale);

	UGbool TilePos2PixelArea(UGdouble dScale, UGint nRow, UGint nCol, PixelArea &pixelArea);

	//! \brief  ����/��ȡ��������,��m_nstroeTypeΪMIXED_FILES��SINGLE_FILEʱ������Ż������á�
	void SetPassword(const UGString& strPwd);
	const UGString &GetPassword();

	UGbool SetPropertiesByPreCaption(const UGString &strPreCaption);
	UGString GeneratePreCaption();

	UGint GetSourceType();

	// ��ȡ�û���չ�ֶε����ã���ֱ���޸ġ�
	// ���map��Ԫ�ظ�����Ϊ0�������α���Ԫ�ص������ļ����
	std::map<UGString, UGString>& UserExtendField();

	// =================== ��Ƭ���͡�ͼƬ����ת����� ===================

	// ��UGFileTypeת��ΪUGint
	static UGbool ConvertImageTypeToInt( const UGFileType::EmType & eFileType, UGint &nFileType);
	static UGbool ConvertIntToImageType( const UGint &nFileType, UGFileType::EmType & eFileType);

	// ��UGint��Mixedʵ�ֻ�ת
	static void ConvertMixedToInt( const unsigned & unFileType, UGint &nFileType);
	static UGbool ConvertIntToMixed( const UGint &nFileType, unsigned & unFileType);
	
	// ��Mixed��UGStringʵ�ֻ�ת
	static UGbool ConvertMixedToString( const unsigned & unFileType, UGString &strFileType);
	static UGbool ConvertStringToMixed( const UGString &strFileType, unsigned & unFileType);

	// ===================================================================


	//! \brief ��ȡ�������ɵ���Ƭ���·������ʽΪ 1000/1/9/2x4
	//! \param dScale [in]		��ǰ��ͼ�ı�����
	//! \return						��ȡ���ɵ���Ƭ���·��
	//! \remarks					�������£�
	UGString TilePos2RelativeOriginalFileNamePrefix(UGdouble dScale, UGint nRow, UGint nCol, UGbool bIsCreat = false);

	// 530000/3/5/7x12.3f2d0c
	UGString TilePos2RelativeSolidPicFileNamePrefix(UGdouble dScale, UGint nRow, UGint nCol, UGColor color);

	UGbool SaveCompactCellData(UGdouble dScale, UGint nRow, UGint nCol, const UGbyte *pData, size_t nSize, UGCompactFileWrapper &compactFile);

	UGbool SaveCompactImageData(UGdouble dScale, UGint nRow, UGint nCol, const UGbyte *pData, size_t nSize, UGbool bSolidColor, UGColor color, UGCompactFileWrapper &compactFile);

	//! \brief ������Ƭ�����кţ�����Ӧ���ݴ浽��Ӧ·����
	//! \param dScale [in]		��ǰ��ͼ�ı�����
	// ��� nSize Ϊ sizeof(UGColor)�����ʾΪ��ɫͼƬ��
	void SaveOriginalImageData(UGdouble dScale, UGint nRow, UGint nCol, const UGbyte* pData, size_t nSize, UGbool bSolid = false);

	//! \brief ������Ƭ�����кţ�����Ӧ����ȡ����
	//! \param dScale [in]		������
	//! \param nRow [in]			ͼƬ�к�
	//! \param nCol [in]			ͼƬ�к�
	//! \param pData [out]			ͼƬ���ݣ����bSolidColorΪtrue���ݾ�����ɫֵ�������������ͼƬ����ɫ
	//! \param nSize [out]			ͼƬ���ݴ�С
	//! \param bSolidColor [out]	�Ƿ��Ǵ�ɫͼƬ��ֻ�ڽ����ͻ�����������
	//! \return						�Ƿ�ɹ���ȡ������
	//! \remarks					�������£�
	// NOTE �� bSolidColor Ϊ false ʱ��ByteArray ���������Ѿ�ѹ���˵�ͼƬ���ݣ����� PNG��JPG �ļ�����
	// �� bSolidColor Ϊ true ʱ��ByteArray ������ֻ��һ�� UGColor ��С��ָʾ���Ǵ�ɫͼƬ����ɫֵ
	UGbool LoadImageData(UGdouble dScale, UGint nRow, UGint nCol, UGByteArray &ByteArray, UGbool &bSolidColor, UGCompactFileWrapper *pCompactFile, UGColor &color);
	UGbool LoadImageData(UGdouble dScale, UGint nRow, UGint nCol, UGByteArray &ByteArray, UGbool &bSolidColor, UGCompactFileWrapper *pCompactFile, UGColor &color, UGint nRequiredImageType, UGbool bTransparent, UGbool bPreciseMatch);

	//! \brief ��ȡ�û��Զ������°汾
	UGint GetRevisionNumber();

	//! \brief �����û��Զ������°汾
	void SetRevisionNumber(UGint number);

	//! \brief ��ȡ�û����õ��Զ���汾�����İ汾��
	UGint GetMaxRevisionNumber();

	// ��ӵ�ǰ�û��Զ���汾���汾����б�
	void AddRevisionNumberToList();

	//! \brief ɾ���ض��������ɵ��û��Զ���汾
	void DeleteRevisionNumber(UGint value);

private:

	UGAbstractCacheFileV70 &operator=(const UGAbstractCacheFileV70 &rhs);
	UGAbstractCacheFileV70(const UGAbstractCacheFileV70 &rhs);

	// ��Դ�����е����д�ɫͼƬ���Ƶ�Ŀ�껺���С�
	// �ϸ���˵�Ⲣ����һ���õķ�ʽ����ȷ�ķ�ʽӦ��������Ƭ���С���ѭ���в��Ҵ�ɫͼƬ�����и��ƣ�������һ���Ը��ƹ�ȥ��
	// һ���Ը��ƹ�ȥ�ᵼ��ԭ�������ڻ���ģ����� sci �н���˵���� caption �µĴ�ɫͼƬҲ�����ơ�
	void CopySolidFiles(UGAbstractCacheFileV70 *pDest, UGAbstractCacheFileV70 *pSrc);
	UGbool IsSolidPic(const UGString &strFileName);

	// ============================ �洢����ȡ��Ƭ��غ��� ============================

	// NOTE
	// SaveOriginalImageData() �� LoadImageData() ֮�����һ�ֲ��Գ��ԣ�
	// SaveOriginalImageData() ֻ����������ԭʼ����
	// LoadImageData() �ȿ��Զ�ȡԭʼ���棬Ҳ���Զ�ȡ���ջ���
	void SaveSolidOriginalImageData(UGdouble dScale, UGint nRow, UGint nCol, const UGbyte* pData, size_t nSize);


	// ���ԭʼ��ƬͼƬ���ݣ������Ƿ�Ϊ��ɫ��ʧ�ܷ��� false��byteArray ���ᱻ��ա�
	UGbool LoadOriginalImageData(UGdouble dScale, UGint nRow, UGint nCol, UGByteArray &ByteArray, UGbool &bSolidColor, UGColor &color, UGint nRequiredImageType, UGbool bTransparent, UGbool bPreciseMatch);

	// ��÷Ǵ�ɫ��ԭʼ��Ƭ���ݡ����Ϊû���ҵ������� false��byteArray ���ᱻ��ա�û���ҵ�ͨ����ζ���Ǵ�ɫͼƬ������Ҫͨ��
	// LoadSolidOriginalImageData() ����ȡ����
	// ���� LoadOriginalImageData() ʹ��
	UGbool LoadNonSolidOriginalImageData(UGdouble dScale, UGint nRow, UGint nCol, UGByteArray &ByteArray, UGint nRequiredImageType, UGbool bTransparent, UGbool bPreciseMatch);

	// ��ȡ��ɫ��Ƭ���ݡ����û���ҵ������� false��byteArray ���ᱻ���
	// ���� LoadOriginalImageData() ʹ��
	UGbool LoadSolidOriginalImageData(UGdouble dScale, UGint nRow, UGint nCol, UGByteArray &ByteArray, UGColor &color, UGint nRequiredImageType, UGbool bTrnasparent, UGbool bPreciseMatch);

	// ��ȡ���ļ������е���ͼƬλ���д洢�����ݣ������洢��ͼƬ֮ǰ��ͷ��
	UGbool LoadCompactCellData(UGdouble dScale, UGint nRow, UGint nCol, UGByteArray &ByteArray, UGCompactFileWrapper &compactFile);

	// ��ȡ���ļ������е���ͼƬ��ͼƬ���ݡ�nRow �� nCol ����Ƭ���к�
	UGbool LoadCompactImageData(UGdouble dScale, UGint nRow, UGint nCol, UGByteArray &ByteArray, UGbool &bSolidColor, UGColor &solidColor, UGCompactFileWrapper &compactFile, UGint nRequiredImageType, UGbool bTransparent, UGbool bPreciseMatch);

	// ================================================================================

	// ��ͼ����ϲ������Լ��
	UGbool Merge_Feasibility_Check(UGAbstractCacheFileV70 *pExtCacheFile);

	// �ϲ� SCI �ļ�
	UGbool Merge_SCI_File(UGAbstractCacheFileV70 *pExtCacheFile);

	// ��ȡ SuperMap SCI �ļ�
	// strConfigFile��SCI �ļ�·��
	UGbool FromSuperMapSCIConfigFile(const UGString &strConfigFile);

	// ��ȡ ArcGIS XML �ļ�
	// strConfigFile��XML �ļ�·��
	UGbool FromArcGISXMLConfigFile(const UGString &strConfigFile);

	// �����մ洢�������Ƿ���ȷ
	UGbool IsPassWordCorrect(const UGchar* strSCIFileName, const UGchar * strPassword);

	// ��ǰ 5.0 �����Ѿ������� filter �ļ����洢��ɫ��Ϣ�����ǣ����ַ�ʽ�ڽ���������Ȼ��ʹ�ü�ֵ���ʱ��� filter �ļ���ش���
	// ��ͨ�洢�� filter �ļ�����
	UGbool SaveFilterFileContent(UGdouble dScale, UGint nRow, UGint nCol, FilterFileCell cell);
	UGbool SaveFilterFileContent(FILE *fd, UGint nRow, UGint nCol, FilterFileCell cell);
	FILE *CreateFilterFile(const UGString &strPath);
	UGbool LoadFilterFileContent(UGdouble dScale, UGint nRow, UGint nCol, FilterFileCell &cell);
	FILE *OpenFilterFile(UGdouble dScale, UGint nRow, UGint nCol, UGbool bCreateIfNotExist);
	UGString TilePos2RelativeFilterFileName(UGdouble dScale, UGint nRow, UGint nCol);

	// ============================== ��Ƭλ�õ��ļ�����ת������ ==============================

	// ��ö����ļ���·������ '/' ��β
	UGString GetTopLevelPath();

	// ��� Precaption ·������ '/' ��β
	UGString GetPrecaptionPath();

	// �ӱ����߻�� Caption ·������ '/' ��β
	// �����߱��������ʹ��
	UGString GetCaptionPath(UGdouble dScale);

	// �ӱ����ߡ���Ƭ�����кŻ����Ƭ����·������ '/' ��β
	// �����߱��������ʹ��
	UGString GetTileGroupRowPath(UGdouble dScale, UGint nRow, UGint nCol);

	// �ӱ����ߡ���Ƭ�����кŻ����Ƭ����·������ '/' ��β
	// �����߱��������ʹ��
	UGString GetTileGroupColPath(UGdouble dScale, UGint nRow, UGint nCol);

	// TODO �ú�����������ȫ�� TilePos2FileName �滻��
	// NOTE ��ǰ���� ComputeImageFileName() ʹ��
	UGbool TilePos2RelativeFileName(UGdouble dScale, UGint nRow, UGint nCol, UGString &strFileName);

	// _alllayers/L02/R000049e7/C0000687e
	UGString TilePos2RelativeArcGISOriginalFileNamePrefix(UGdouble dScale, UGint nRow, UGint nCol);

	// ���ԭʼ��Ƭ���ļ������ FileDirectory ��·������ɫ���Ǵ�ɫ�����á���ɫ��Ƭ���� 530000/ 3/5/7x12.ffee33.solid ����ʽ��
	// NOTE �ú�����Ҫ��ȡ���̣��ٶ���
	UGString GetSolidOriginalTileFileName(UGdouble dScale, UGint nRow, UGint nCol, UGColor &color);

	// 530000/3/5
	UGbool TilePos2RelativeSuperMapFileName_aux(UGdouble dScale, UGint nRow, UGint nCol, UGString &strPath);


	//! \brief ��ȡ�������ɵ���Ƭ���SCI�ļ���·������ʽΪ 1000/1/9.cf
	//! \param dScale [in]		��ǰ��ͼ�ı�����
	//! \return						��ȡ���ɵ���Ƭ���·��
	//! \remarks					�������£�
	UGString TilePos2RelativeCompactFileName(UGdouble dScale, UGint nRow, UGint nCol, UGbool bIsCreat = false);

	UGColor SolidString2Color(const UGString &strColor);
	static UGString Color2SolidString(UGColor color);

	UGbool IsRequiredImageTypeSatisfied(UGFileType::EmType emRealFileType, UGint nRequiredImageType, UGbool bTransparent, UGbool bPreciseMatch);
	// =========================================================================================

	// ��ȡ���������
	UGdouble ScaleToNearFixScale(UGdouble dScale);

	// NOTE ���� GetValidRegion ʹ�ã�û�д�����
	void _MergeTileArea2GeoRegion(UGdouble dScale, const UGRect2D &rcBounds, const TileArea &tileArea, UGGeoRegion *region);

	// �������������ı������е��±ꡣ
	// ���� Scale ����Ŀ���٣�ʹ�� UGint ֵ��ȫ���ԡ�����Ҫʹ�������� size_type��
	// 0 �𡣷��� -1 ��ʾ����
	// NOTE һ��Ҫ���ú����ķ���ֵ
	UGdouble Round2NearestScale(UGdouble dScale);

	void DebugValidateScale(UGdouble dScale);

	UGbool IsPathSet();


	// ���� m_dUnitsRatio ��Ա��
	void AdjustUnitsRatio();

	// DPI �� CoordRatio �໥ת��
	UGdouble		DPI2CoordRatio(UGdouble nDPI) const;
	UGdouble		CoordRatio2DPI(UGdouble dCoordRatio) const;

	// ά��һ�Ű汾�ź���Ϳɴ�ĳ�汾�Ķ��ձ�������ʱ�򣬸���m_nVersion������Ӧ��ʹ򿪰汾�浽�����ļ���
	// ����1��2��3����ʹ򿪰汾Ϊ1;4�汾�д�Ķ���Ҫ��4�汾����ʹ򿪰汾ֻ��Ϊ4���û���4�汾�������»��沢
	// ���������������������汾Ϊ4����һ���û���3�汾����򿪡�����ʱ֪���洢���������汾��4������3��
	// �������nMyVersion,���ʱ��3����汾�ʹ�ʧ�ܡ�������Ϊ�˱���Ͱ汾�򿪸Ķ��ϴ��°汾�ļ������⡣
	unsigned	Version2RequiredVersion();

	// ͨ����Ƭλ�ü�����Ƭ���λ��
	void TilePos2TileGroupPos(UGint nTileRow, UGint nTileCol, UGint &nGroupTileRow, UGint &nGroupTileCol);

	// �ݹ����Ŀ¼ɾ���Զ���汾�����ļ�
	void DeleteRevisionNumber(UGString strPath, UGString strPattern);

	// ============================== ���ݳ�Ա ==============================
	// ����ĳ�Ա�ڻ��������ļ��г���
	//UGMapCacheVersion m_nCacheVersion;		// ��ǰ����İ汾�š��� ToConfigFile() �иð汾��ָʾ��Ҫ�������ļ���ʽ
	UGint	m_nFullCacheVersion;				// ��ǰ����������汾��
	UGString m_strServiceProvider;				// Service Provider
	UGString m_strCacheName;					// �������ơ�����������������Ϊ����Դ��ʽ���м���ʱ������Դ����
	UGPrjCoordSys *m_pPrjCoordSys;				// ͶӰ��Ϣ������ͼ������ص���ά�����еı�����Ϣ��
	unsigned m_nImageType;						// ͼƬ��ʽ
	UGint m_nTileSize;							// ��Ƭ���ر߳���
	UGint m_nTileWidth;							// ��Ƭ���ؿ�
	UGint m_nTileHeight;						// ��Ƭ���ظ�
	UGRect2D m_rcBounds;						// ����ĵ���Χ��������Ϊ����Դ��ʽ���м���ʱ������Դ��Χ
	UGdouble m_dCoordRatio;						// LP/DP ת�����ʣ���λΪ(����/����)��
	UGRect2D m_rcIndexBounds;					// ������Χ
	UGbool m_bCompactCache;						// �Ƿ���ջ���
	UGbool m_bEnableHashCode;					// ���ɵ�ͼƬ�Ƿ���� hashcode ���ļ�����
	UGColor m_DefaultColor;						// �洢�����˵���Ĭ����ɫ
	UGbool m_bTransparentBack;					// �洢ͼƬ�Ƿ�͸��
	UGbool m_bFillMargin;						// �Ƿ�ʹ��������� margin
	UGint m_nImageCompress;						// ����ͼƬѹ����
	UGGeoRegion* m_pClipRegion;					// �ü�����
	TileType m_TileType;						// ȫ���ʷֻ��߱����ʷ�
	UGRect2D m_rcMapBounds;						// ��ͼ���ݷ�Χ
	UGString m_strHashCode;						// ���ɻ����ɢ��ֵ
	std::map<UGdouble, UGString> m_mapOutputScaleCaptions;	// �����ߡ�����
	UGint m_nExtendedTiles;						// ������Ƭ������������������һ��
	UGString m_strMapName;						// ���ɻ���ĵ�ͼ��
	UGString m_strDatasetName;					// ���ɻ�������ݼ���
	UGdouble m_dUnitsRatio;						// ͶӰ����ϵ�ĵ�λ��LP/MP��ת��������ʹ�á�
	UGArray<UGint> m_nRevisionNumberList;		// �û��Զ���汾����

	// ����ĳ�Ա���ڻ��������ļ��г���
	UGString m_strPassword;						// ���ļ���������
	UGString m_strFileDirectory;				// ����SCI���Ŀ¼λ��
	UGString m_strCacheFileName;				// �� sci �ļ�Ϊ�򿪵��ⲿ�ļ����߾����˱������������һ���ⲿ�ļ���Ӧ��
	UGint m_nSourceType;						// Դ�ļ�����
	UGMutex m_mutexFilterFile;					// д��ͬһ�� Filter �ļ�ʱ���л���
	UGbool m_bDynamicCache;						// ��ǰ���ɵ��Ƕ�̬����

	std::map<UGString, UGString> m_mapUserExtendField;	// �û���չ�ֶ�

	UGint m_nRevisionNumber;					// �û���ǰ���õ��Զ���汾��
	UGbool m_bUseDataset;						//Ĭ��false�Ƿ�ʹ��Dataset���ݼ�
};

} // UGC

#endif // _UGABSTRACTCACHEFILE_H_
