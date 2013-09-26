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

#ifndef _UGABSTRACTCACHEFILE_H_
#define _UGABSTRACTCACHEFILE_H_

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

class CACHEFILE_API UGAbstractCacheFile
{

	class FilterFileCell
	{
	public:
		char data[FilterFileCellSize];
		bool IsExist();
		void SetExist(bool bExist = true);

		UGColor GetColor();
		void SetColor(UGColor color);

		char *GetData();
		FilterFileCell();
	};

	friend class UGMapCacheFile;

public:
	UGAbstractCacheFile();
	~UGAbstractCacheFile();

	// �汾�ţ�Ĭ��Ϊ���°汾��
	void				SetCacheVersion(UGMapCacheVersion nVersion);
	UGMapCacheVersion	GetCacheVersion() const;

	// �ڲ��汾���
	void				SetFullCacheVersion(UGint nVersion);
	UGint				GetFullCacheVersion() const;

	// ������������
	bool			SetCacheName(const UGString &strCacheName);
	const UGString &GetCacheName();
	const UGString &GetFinalCacheName();

	// ������Դ����
	bool			SetServiceProvider(const UGString &strServiceProvider);
	const UGString &GetServiceProvider();

	// ͶӰ��Ϣ�����ʼ������ϵ��λ�ͻ���ο�ԭ��
	void				 SetPrjCoordSys(const UGPrjCoordSys &CoordSys);
	const UGPrjCoordSys &GetPrjCoordSys() const;

	// ͼƬ���ԣ�������͸��Png32����͸��Png32��Png8��Jpeg�����ͼƬģʽ
	bool		SetMixedImageType(unsigned nPictureFormat);
	unsigned	GetMixedImageType() const;

	UGint				GetIntImageType();
	bool				SetIntImageType(UGint nType);

	UGFileType::EmType	GetSingleImageType();
	bool				SetSingleImageType(UGFileType::EmType nType);

	UGint GetTileGroupSize() { return nTileGroupSize; }

	// ����ͼƬ���ش�С
	bool	SetTileSize(int nTileSize);
	int		GetTileSize() const;

	// ���ݷ�Χ���Ե�������Ϊ��λ
	void			SetBounds(const UGRect2D &rcBounds);
	const UGRect2D &GetBounds() const;
	const UGRect2D GetFinalBounds();

	TileArea GetFinalExtendedTileArea(UGdouble dScale);

	// ÿ�����ж��ٸ����أ�Ĭ��ÿ����3�����أ�x�����y�������һ�°�
	bool		SetCoordRatio(double dCoordRatio);
	double		GetCoordRatio();

	void		SetDPI(UGdouble dCoordRatio);
	UGdouble	GetDPI();

	void SetHashCodeEnabled(bool bValue = true);
	bool IsHashCodeEnabled();

	void			SetIndexBounds(const UGRect2D &rcIndexBounds);
	const UGRect2D &GetIndexBounds();
	UGRect2D		GetFinalIndexBounds();

	// ��������Ϣ�����Ҫ�󣬲�Ҫ������ߵĵ�����
	// ������б����߶���������Χ������Ϊ���������� true�����򷵻� false�����Ҳ��Ա��������ý����κ��޸ġ�//�Ƿ������˹̶�������
	bool					SetOutputScales(const std::vector<double>& vectOutputScales,UGbool bIsDisplayByScales = false);
	std::vector<double>		GetOutputScales();
	std::vector<double>		GetSortedOutputScales();		// TODO ��ȫȥ��

	bool SetOutputScaleCaptions(const std::map<double, UGString> &mapOutputScaleCaptions);
	void GetOutputScaleCaptions(std::map<double, UGString> &mapOutputScaleCaptions);
	const std::map<double, UGString> &GetOutputScaleCaptions();

	// �Ƿ���ջ��棬Ĭ�ϲ��ǽ���
	void	SetIsCompactCache(bool bCompactCache);
	bool	IsCompactCache();

	// ����ָ����ȫ·��������/����SCI�����ļ���
	bool ToConfigFile(const UGString& strCacheFile,UGbool bChangeOutputDir=true);//���bool�Ƿ��޸����·����inf�ļ����޸�·��
	bool FromConfigFile(const UGString& strCacheFile);

	//UGbool ToInfFile(const UGString &strInfPath);

	// �򿪣��رջ����ļ�
	// strCacheFile�������ļ� .sci ·����
	// strPassword�����ļ���������
	bool Open(const UGString &strCacheFile, const UGString &strPassword = _U(""));
	void Close();

	// ������λ��
	// strFileDirectory ��λ��Ϊ���涥���ļ�������·����
	// ���磬�����·������Ϊ D:\NE���򻺴�� .sci ·��Ϊ D:\NE\CacheName\CacheName.sci��
	void			SetFileDirectory(const UGString &strFileDirectory);
	const UGString &GetFileDirectory();

	const UGString &GetCacheFileName();

	// ����/�ж� margin �Ƿ��������
	// bFillMargin == true��������ݡ�bFillMargin == false������Ϊ��ɫ��͸����
	void SetFillMargin(bool bFillMargin);
	bool IsFillMargin();

	// ����/��ȡ����ͼƬѹ����
	// �������ֵ������ [0, 100] �ķ�Χ������ false�����Ҳ���ԭ�����ý����޸�
	// ���ѹ�� 0��������� 100��
	void	SetImageCompress(int nCompress);
	int		GetImageCompress();

	// ����/��ȡͼƬ����ɫ�Ƿ�͸��
	void	SetTransparentBack(UGbool bTransparentBack);
	UGbool	IsTransparentBack();
	UGbool	IsFinalTransparentBack();

	// ����/��ȡ�ü�����
	// ���û�����òü����򣬻�ȡ���Ϊ NULL��
	bool				SetClipRegion(UGGeoRegion *pClipRegion);
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
	bool PixelArea2MPBounds(double dScale, const PixelArea &rcPixelArea,	UGRect2D &rcMPBounds);

	// ��ָ���������µ���Χת��Ϊ���ط�Χ������������ת����������Ҫ����ѡ��

	// ������Χ���κ������ཻʱ����ʹֻռ�����صļ���һ���֣�Ҳ��Ϊ�����ڸ�������
	bool MPBounds2PixelAreaInclusive(double dScale, const UGRect2D &rcMPBounds,	PixelArea &pixelArea);

	// ������Χ���κ������ཻʱ����ʹֻռ�����صľ��󲿷֣�ֻҪ������û���ཻ��Ҳ��Ϊ�������ڸ�������
	bool MPBounds2PixelAreaExclusive(double dScale, const UGRect2D &rcMPBounds,	PixelArea &pixelArea);

	// ������Χ�������ཻʱ���ཻ�ı߽簴��������ķ�ʽ�����жϡ��󲿷�ʹ������Ҫʹ�õ��Ǹú�����
	// �ú����ܹ���֤ͨ��PixelArea2MPBounds�ٴ�ת������ʱ��ԭ����Χ��ӽ������Բ��ܱ�֤��ͬ��
	bool MPBounds2PixelAreaRounded(double dScale, const UGRect2D &rcMPBounds,	PixelArea &pixelArea);

	// �������ת��Ϊ��������
	bool MPPos2PixelPos(double dScale, const UGPoint2D &pntPosition, PixelArea &pixelArea);

	bool TileArea2PixelArea(const TileArea &tileArea,	PixelArea &rcPixelArea);
	bool PixelArea2TileArea(const PixelArea &rcPixelArea,	TileArea &tileArea);

	bool TileArea2TileGroupArea(const TileArea &tileArea, TileGroupArea &tileGroupArea);
	bool TileGroupArea2TileArea(const TileGroupArea &tileGroupArea, TileArea &tileArea);

	// ��ȫ�������Ƭ���кŻ���ɶ�Ӧ���ջ�������к�
	static void ConvertRowCol(int& nRow, int& nCol);
	static void CompactCellPos2TilePos(UGint nTileGroupRow, UGint nTileGroupCol, UGint nCellRow, UGint nCellCol, UGint &nTileRow, UGint &nTileCol);

	// =========================================================================================

	// �ϲ���ͼ����
	// strPath���ϲ�����ǰ��ͼ������ⲿ��ͼ���棬��ָ�� SCI �ļ�
	// strPassword�����ⲿ��ͼ����Ϊ���մ洢ʱ���򿪵�ͼ���������
	bool Merge(const UGString &strPath, const UGString &strPassword = _U(""));

	bool Convert(StoreType storeType, const UGString &strDest, const UGString &strPassword);
	UGbool ConvertSingleCompactFile(const UGString &strCompactFilePath, const UGString &strDest);

	std::vector<UGTile*> *GetTiles(const UGRect2D &rcBounds, double dScale, UGString strPwd, UGString strHashCode, UGCompactFileWrapper *pCompactFile, UGint nImageType, UGbool bTransparent, UGbool bPreciseMatch);

	// MPPoint2PixelPos ----> PixelPos2TilePos
	//! \���ݸ����ı����߼����ĵ������Ƭλ��
	//! \param dScale [in] ������
	//! \param center [in] ָ�������ĵ�
	//! \param nRow [out] ������Ƭ�к�
	//! \param nCol [out] ������Ƭ�к�
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ�����Ƭ��λ��
	// NOTE ���� UGMapCacheFile ʹ�ã������ط�����ʹ�á�
	void ComputeTilePosition(double dScale, const UGPoint2D &pntCenter, int &nRow, int &nCol);

	// �Ƿ����ĳ��ͼƬ����
	bool ContainsPNGTypeP(unsigned nImageType);
	bool ContainsBMPTypeP(unsigned nImageType);
	bool ContainsJPGTypeP(unsigned nImageType);
	bool ContainsGIFTypeP(unsigned nImageType);

	// �������͵ı�����ת��Ϊ���������� .5 ת��������Ϊ 2���������������ɻ���Ŀ¼��
	unsigned	Scale2ScalePathName(double dScale);		
	double		ScalePathName2Scale(unsigned nScale);


	// ͨ��ͼƬ���ͻ�ȡ�ļ���׺��
	static UGString GetFileExtName(UGFileType::EmType nPictureFormat);

	// ������ջ�����Ƭ��
	// Ҫ����Ƭ���ⲿ�Ѿ���ȫ������ϣ�������Ƭͷ����
	UGbool OpenCompactFile(UGdouble dScale, UGint nRow, UGint nCol, UGCompactFileWrapper &compactFile, UGbool bCreateIfAbsent = false);
	UGbool CreateCompactFile(UGdouble dScale, UGint nRow, UGint nCol, UGCompactFileWrapper &compactFile);

	// ����������
	void SetOutputScales_aux(const std::vector<double>& vectOutputScales,UGbool bIsDisplayByScales = false);//�Ƿ������˹̶�������

	//! \���ݸ����ı����߼���Ƭ���кż�����Ƭ��Χ
	//! \param dScale [in]		������
	//! \param nRow [in]			ͼƬ�к�
	//! \param nCol [in]			ͼƬ�к�
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ��㵥����Ƭ�ķ�Χ
	UGRect2D ComputeTileMPBounds(double dScale, int nRow, int nCol);

	//! \���ݸ����ı����߼���Ƭ���кŷ�Χ������Ƭ��Χ
	//! \param dScale [in]		������
	//! \param TileDataArea [in]	��Ƭ���кŷ�Χ
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ�����ж�����Ƭ�ķ�Χ
	UGRect2D ComputeTileMPBounds(double dScale, const UGHPDataArea &TileDataArea);

	UGRect2D ComputeTileMPBounds(const UGString& strFileName, UGbool bGlobal = false);
	void ComputeImageFileName(const UGPoint2D &pntCenter, double dScale, UGString& vectAbsoluteFileNames);
	void ComputeImageFileName(const UGRect2D &rcMPCellImageBounds, double dScale, std::vector<UGString>& vectAbsoluteFileNames);

	// �������г�Ա
	void Reset();

	// �����ļ�����
	void ResetSCIContent();

	// bSingleTile���Ƿ�Ҫ���ƶ��ĵ���Χ�����ǵ�����Ƭ�ķ�Χ����Ϊfalse��������ĵ���Χ�����Ƕ�����Ƭ�ķ�Χ��
	bool CheckTileBoundsValid(const UGRect2D &rcMPTileBounds, double scale, bool bSingleTile = true);

	// ����һ����ɫͼƬ
	bool ConstructSolidImageFile(const UGString &strAbsoluteFileName, UGColor color, UGFileType::EmType fileType);

	// ���ݵ�ͼͶӰ����ͼ�����ߡ���ͼ��Χ�����ط�Χ����ÿ�����ж��ٸ����أ������ڲ�����
	static double ComputeCoordRatio(const UGPrjCoordSys& prjCoordSys, double dScale, double dMapWidth, int nPixelWidth);

	// ���ݵ�ͼͶӰ�ͳ�ʼ���ؿ�ȳ�ʼ��ͼ��ȼ��������
	static std::vector<double> ComputeMapScale(const UGPrjCoordSys& prjCoordSys, double dMapWidth, int nPixelWidth, 
												int nScaleCount = 22, double dCoordRatio = 3);

	//���ݵ�ͼͶӰ����ʼ���ؿ�Ⱥͱ����ߣ�����㼶
	static int ComputeLevelByScale(const UGPrjCoordSys& prjCoordSys, double dLevel0Width, double dScale, int nPixelWidth,
									double dCoordRatio = 3);

	// ���ݵ�ͼͶӰ�ͳ�ʼ���ؿ�ȼ���ĳһ�㼶��Ӧ������
	static UGdouble ComputeMapScaleByLevel(const UGPrjCoordSys& prjCoordSys, int nPixelWidth, int nLevel, double dCoordRatio);


	static std::vector<int> ComputeLevel(const UGPrjCoordSys& prjCoordSys, double dMapWidth, 
											int nPixelWidth, const std::vector<double>& scales, double dCoordRatio);

	UGbool Extract(const std::vector<UGdouble> &vectScales, const UGGeoRegion &region, StoreType storageType, const UGString &strOutputPath);

	UGbool Extract(const UGGeoRegion &region, const UGString &strOutputPath);

	UGbool Clear(const UGRect2D &rcBounds, UGdouble dScale, UGbool clearFolder =false);
	UGbool Clear(UGdouble dScale, const UGGeoRegion *pRegion);

	void ClearDynamicCache(const UGRect2D &rcBounds);

	// ͨ��������ת����Ƭ�߳���Ӧ�ĵ����С
	UGSize2D ComputeTileMPSize(double dScale) const;

	//Ϊ����׼ȷ�����س�����ʱ�����������������õĵط����ࡣ��û����Double���͵�����λ�õĺ�������������ô���£�
	double GetUnitsRatio();

	bool HitTest(const UGPoint2D &pntPosition, double dScale);

	bool Reload();

	// �����ļ������ͼƬ�������ͣ�������
	static UGFileType::EmType DataHeaderToImageType(const UGbyte* pData);

	// ������Ƭ�����кţ��ж�ָ����Ƭ�������Ƿ����
	// dScale		��ǰ��ͼ�ı�����
	bool IsTileExist(double dScale, int nRow, int nCol) ;

	// ���ݴ����TileData�еı����ߣ���ȡTile�ĵ���Χ�����ط�Χ
	void GetTileInfo(UGTile& TileData, UGCompactFileWrapper *pCompactFile);

	// ���ݴ����TileData�еı����ߺ����кţ���ȡTile�ĵ���Χ�����ط�Χ����Tile����������ͼ���ʽ
	bool GetTileData(UGTile& TileData, UGCompactFileWrapper *pCompactFile);

	// NOTE ���ص� UGGeoRegion �������ⲿ�ͷţ�
	UGGeoRegion *GetValidRegion(UGRect2D rcBounds, double dScale);

	bool TilePos2PixelArea(double dScale, int nRow, int nCol, PixelArea &pixelArea);

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
	UGString TilePos2RelativeOriginalFileNamePrefix(double dScale, int nRow, int nCol);

	// 530000/3/5/7x12.3f2d0c
	UGString TilePos2RelativeSolidPicFileNamePrefix(UGdouble dScale, UGint nRow, UGint nCol, UGColor color);

	UGbool SaveCompactCellData(double dScale, int nRow, int nCol, const UGbyte *pData, size_t nSize, UGCompactFileWrapper &compactFile);

	UGbool SaveCompactImageData(UGdouble dScale, UGint nRow, UGint nCol, const UGbyte *pData, size_t nSize, UGbool bSolidColor, UGColor color, UGCompactFileWrapper &compactFile);

	//! \brief ������Ƭ�����кţ�����Ӧ���ݴ浽��Ӧ·����
	//! \param dScale [in]		��ǰ��ͼ�ı�����
	// ��� nSize Ϊ sizeof(UGColor)�����ʾΪ��ɫͼƬ��
	void SaveOriginalImageData(double dScale, int nRow, int nCol, const UGbyte* pData, size_t nSize, UGbool bSolid = false);

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
	bool LoadImageData(double dScale, int nRow, int nCol, UGByteArray &ByteArray, UGbool &bSolidColor, UGCompactFileWrapper *pCompactFile, UGColor &color);
	bool LoadImageData(double dScale, int nRow, int nCol, UGByteArray &ByteArray, UGbool &bSolidColor, UGCompactFileWrapper *pCompactFile, UGColor &color, UGint nRequiredImageType, UGbool bTransparent, UGbool bPreciseMatch);


private:

	UGAbstractCacheFile &operator=(const UGAbstractCacheFile &rhs);
	UGAbstractCacheFile(const UGAbstractCacheFile &rhs);

	// ��Դ�����е����д�ɫͼƬ���Ƶ�Ŀ�껺���С�
	// �ϸ���˵�Ⲣ����һ���õķ�ʽ����ȷ�ķ�ʽӦ��������Ƭ���С���ѭ���в��Ҵ�ɫͼƬ�����и��ƣ�������һ���Ը��ƹ�ȥ��
	// һ���Ը��ƹ�ȥ�ᵼ��ԭ�������ڻ���ģ����� sci �н���˵���� caption �µĴ�ɫͼƬҲ�����ơ�
	void CopySolidFiles(UGAbstractCacheFile *pDest, UGAbstractCacheFile *pSrc);
	UGbool IsSolidPic(const UGString &strFileName);

	// ============================ �洢����ȡ��Ƭ��غ��� ============================

	// NOTE
	// SaveOriginalImageData() �� LoadImageData() ֮�����һ�ֲ��Գ��ԣ�
	// SaveOriginalImageData() ֻ����������ԭʼ����
	// LoadImageData() �ȿ��Զ�ȡԭʼ���棬Ҳ���Զ�ȡ���ջ���
	void SaveSolidOriginalImageData(double dScale, int nRow, int nCol, UGColor color);


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
	UGbool LoadCompactCellData(UGdouble dScale, int nRow, int nCol, UGByteArray &ByteArray, UGCompactFileWrapper &compactFile);

	// ��ȡ���ļ������е���ͼƬ��ͼƬ���ݡ�nRow �� nCol ����Ƭ���к�
	UGbool LoadCompactImageData(UGdouble dScale, UGint nRow, UGint nCol, UGByteArray &ByteArray, UGbool &bSolidColor, UGColor &solidColor, UGCompactFileWrapper &compactFile, UGint nRequiredImageType, UGbool bTransparent, UGbool bPreciseMatch);

	// ================================================================================

	// ��ͼ����ϲ������Լ��
	bool Merge_Feasibility_Check(UGAbstractCacheFile *pExtCacheFile);

	// �ϲ� SCI �ļ�
	bool Merge_SCI_File(UGAbstractCacheFile *pExtCacheFile);

	// ��ȡ SuperMap SCI �ļ�
	// strConfigFile��SCI �ļ�·��
	bool FromSuperMapSCIConfigFile(const UGString &strConfigFile);

	// ��ȡ ArcGIS XML �ļ�
	// strConfigFile��XML �ļ�·��
	bool FromArcGISXMLConfigFile(const UGString &strConfigFile);

	// �����մ洢�������Ƿ���ȷ
	bool IsPassWordCorrect(const UGchar* strSCIFileName, const UGchar * strPassword);

	// ��ǰ 5.0 �����Ѿ������� filter �ļ����洢��ɫ��Ϣ�����ǣ����ַ�ʽ�ڽ���������Ȼ��ʹ�ü�ֵ���ʱ��� filter �ļ���ش���
	// ��ͨ�洢�� filter �ļ�����
	bool SaveFilterFileContent(double dScale, int nRow, int nCol, FilterFileCell cell);
	bool SaveFilterFileContent(FILE *fd, int nRow, int nCol, FilterFileCell cell);
	FILE *CreateFilterFile(const UGString &strPath);
	bool LoadFilterFileContent(double dScale, int nRow, int nCol, FilterFileCell &cell);
	FILE *OpenFilterFile(double dScale, int nRow, int nCol, bool bCreateIfNotExist);
	UGString TilePos2RelativeFilterFileName(double dScale, int nRow, int nCol);

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
	bool TilePos2RelativeFileName(double dScale, int nRow, int nCol, UGString &strFileName);

	// _alllayers/L02/R000049e7/C0000687e
	UGString TilePos2RelativeArcGISOriginalFileNamePrefix(double dScale, int nRow, int nCol);

	// ���ԭʼ��Ƭ���ļ������ FileDirectory ��·������ɫ���Ǵ�ɫ�����á���ɫ��Ƭ���� 530000/ 3/5/7x12.ffee33.solid ����ʽ��
	// NOTE �ú�����Ҫ��ȡ���̣��ٶ���
	UGString GetSolidOriginalTileFileName(UGdouble dScale, UGint nRow, UGint nCol, UGColor &color);

	// 530000/3/5
	bool TilePos2RelativeSuperMapFileName_aux(double dScale, int nRow, int nCol, UGString &strPath);


	//! \brief ��ȡ�������ɵ���Ƭ���SCI�ļ���·������ʽΪ 1000/1/9.cf
	//! \param dScale [in]		��ǰ��ͼ�ı�����
	//! \return						��ȡ���ɵ���Ƭ���·��
	//! \remarks					�������£�
	UGString TilePos2RelativeCompactFileName(double dScale, int nRow, int nCol);

	UGColor SolidString2Color(const UGString &strColor);
	static UGString Color2SolidString(UGColor color);

	UGbool IsRequiredImageTypeSatisfied(UGFileType::EmType emRealFileType, UGint nRequiredImageType, UGbool bTransparent, UGbool bPreciseMatch);
	// =========================================================================================

	// ��ȡ���������
	double ScaleToNearFixScale(double dScale);

	// NOTE ���� GetValidRegion ʹ�ã�û�д�����
	void _MergeTileArea2GeoRegion(double dScale, const UGRect2D &rcBounds, const TileArea &tileArea, UGGeoRegion *region);

	// �������������ı������е��±ꡣ
	// ���� Scale ����Ŀ���٣�ʹ�� int ֵ��ȫ���ԡ�����Ҫʹ�������� size_type��
	// 0 �𡣷��� -1 ��ʾ����
	// NOTE һ��Ҫ���ú����ķ���ֵ
	double Round2NearestScale(double dScale);

	void DebugValidateScale(double dScale);

	bool IsPathSet();


	// ���� m_dUnitsRatio ��Ա��
	void AdjustUnitsRatio();

	// DPI �� CoordRatio �໥ת��
	double		DPI2CoordRatio(double nDPI) const;
	double		CoordRatio2DPI(double dCoordRatio) const;

	// ά��һ�Ű汾�ź���Ϳɴ�ĳ�汾�Ķ��ձ�������ʱ�򣬸���m_nVersion������Ӧ��ʹ򿪰汾�浽�����ļ���
	// ����1��2��3����ʹ򿪰汾Ϊ1;4�汾�д�Ķ���Ҫ��4�汾����ʹ򿪰汾ֻ��Ϊ4���û���4�汾�������»��沢
	// ���������������������汾Ϊ4����һ���û���3�汾����򿪡�����ʱ֪���洢���������汾��4������3��
	// �������nMyVersion,���ʱ��3����汾�ʹ�ʧ�ܡ�������Ϊ�˱���Ͱ汾�򿪸Ķ��ϴ��°汾�ļ������⡣
	unsigned	Version2RequiredVersion();

	// ͨ����Ƭλ�ü�����Ƭ���λ��
	void TilePos2TileGroupPos(int nTileRow, int nTileCol, int &nGroupTileRow, int &nGroupTileCol);


	// ============================== ���ݳ�Ա ==============================
	// ����ĳ�Ա�ڻ��������ļ��г���
	//UGMapCacheVersion m_nCacheVersion;			// ��ǰ����İ汾�š��� ToConfigFile() �иð汾��ָʾ��Ҫ�������ļ���ʽ
	UGint	m_nFullCacheVersion;				// ��ǰ����������汾��
	UGString m_strServiceProvider;				// Service Provider
	UGString m_strCacheName;					// �������ơ�����������������Ϊ����Դ��ʽ���м���ʱ������Դ����
	UGPrjCoordSys *m_pPrjCoordSys;				// ͶӰ��Ϣ������ͼ������ص���ά�����еı�����Ϣ��
	unsigned m_nImageType;						// ͼƬ��ʽ
	int m_nTileSize;							// ��Ƭ���ر߳���
	int m_nTileWidth;							// ��Ƭ���ؿ�
	int m_nTileHeight;							// ��Ƭ���ظ�
	UGRect2D m_rcBounds;						// ����ĵ���Χ��������Ϊ����Դ��ʽ���м���ʱ������Դ��Χ
	double m_dCoordRatio;						// LP/DP ת�����ʣ���λΪ(����/����)��
	UGRect2D m_rcIndexBounds;					// ������Χ
	bool m_bCompactCache;						// �Ƿ���ջ���
	bool m_bEnableHashCode;						// ���ɵ�ͼƬ�Ƿ���� hashcode ���ļ�����
	UGColor m_DefaultColor;						// �洢�����˵���Ĭ����ɫ
	UGbool m_bTransparentBack;					// �洢ͼƬ�Ƿ�͸��
	bool m_bFillMargin;							// �Ƿ�ʹ��������� margin
	int m_nImageCompress;						// ����ͼƬѹ����
	UGGeoRegion* m_pClipRegion;					// �ü�����
	TileType m_TileType;						// ȫ���ʷֻ��߱����ʷ�
	UGRect2D m_rcMapBounds;						// ��ͼ���ݷ�Χ
	UGString m_strHashCode;						// ���ɻ����ɢ��ֵ
	std::map<double, UGString> m_mapOutputScaleCaptions;	// �����ߡ�����
	UGint m_nExtendedTiles;						// ������Ƭ������������������һ��
	UGString m_strMapName;						// ���ɻ���ĵ�ͼ��
	double m_dUnitsRatio;						// ͶӰ����ϵ�ĵ�λ��LP/MP��ת��������ʹ�á�

	// ����ĳ�Ա���ڻ��������ļ��г���
	UGString m_strPassword;						// ���ļ���������
	UGString m_strFileDirectory;				// ����SCI���Ŀ¼λ��
	UGString m_strCacheFileName;				// �� sci �ļ�Ϊ�򿪵��ⲿ�ļ����߾����˱������������һ���ⲿ�ļ���Ӧ��
	int m_nSourceType;							// Դ�ļ�����
	UGMutex m_mutexFilterFile;					// д��ͬһ�� Filter �ļ�ʱ���л���
	UGbool m_bDynamicCache;						// ��ǰ���ɵ��Ƕ�̬����

	std::map<UGString, UGString> m_mapUserExtendField;	// �û���չ�ֶ�

};

} // UGC

#endif // _UGABSTRACTCACHEFILE_H_
