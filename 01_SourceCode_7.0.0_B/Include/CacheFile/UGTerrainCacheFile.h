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

#ifndef _UGTERRAINCACHEFILE_H_
#define _UGTERRAINCACHEFILE_H_

#include "FileParser/UGExchangeFileType.h"
#include "Base/ogdccolordef.h"
#include "Stream/UGByteArray.h"
#include "CacheFile/UGCacheFileCommon.h"
#include "Geometry/UGGeoRegion.h"
#include "Toolkit/UGMarkup.h"
#include "Stream/UGCacheFile.h"
#include "FileParser/UGFileParseToolkit.h"

#define SUPERMAPSCI 0
#define ARCGISXML 1

#include <vector>

namespace UGC
{

class CACHEFILE_API UGTerrainCacheFile
{
		
public:
	UGTerrainCacheFile();
	~UGTerrainCacheFile();

		// ������������
	UGbool			SetCacheName(const UGString &strCacheName);
	const UGString &GetCacheName();
	const UGString &GetFinalCacheName();

		// ͶӰ��Ϣ�����ʼ������ϵ��λ�ͻ���ο�ԭ��
	void				 SetPrjCoordSys(const UGPrjCoordSys &CoordSys);
	const UGPrjCoordSys &GetPrjCoordSys() const;

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

	
	void			SetIndexBounds(const UGRect2D &rcIndexBounds);
	const UGRect2D &GetIndexBounds();
	UGRect2D		GetFinalIndexBounds();

	// ��������Ϣ�����Ҫ�󣬲�Ҫ������ߵĵ�����
	// ������б����߶���������Χ������Ϊ���������� true�����򷵻� false�����Ҳ��Ա��������ý����κ��޸ġ�//�Ƿ������˹̶�������
	UGbool					SetOutputScales(const UGArray<UGdouble>& vectOutputScales,UGbool bIsDisplayByScales = false);
	UGArray<UGdouble>		GetOutputScales();
	UGArray<UGdouble>		GetSortedOutputScales();		// TODO ��ȫȥ��

	UGbool SetOutputScaleCaptions(const UGDict<UGdouble, UGString> mapOutputScaleCaptions);
	void GetOutputScaleCaptions(UGDict<UGdouble, UGString> &mapOutputScaleCaptions);
	const UGDict<UGdouble, UGString> &GetOutputScaleCaptions();

	// �Ƿ���ջ��棬Ĭ�ϲ��ǽ���
	void	SetIsCompactCache(UGbool bCompactCache);
	UGbool	IsCompactCache();

	UGbool ToProjection(const UGString& strProjectionFile );
	UGbool FromProjection(const UGString &strProjection);

	//! \brief �������ݼ���ɫ���ļ�
	UGbool ToColorTableFile(const UGColorTable& colorTable, const UGString& strFileName);

	//! \brief ��ȡ���ݼ���ɫ���ļ�
	UGbool FromColorTableFile(UGColorTable& colorTable, const UGString& strFileName);

	// ����ָ����ȫ·��������/����SCI�����ļ���
	UGbool ToConfigFile(const UGString& strCacheFile,UGbool bChangeOutputDir=true);//���UGbool�Ƿ��޸����·����inf�ļ����޸�·��
	UGbool FromConfigFile(const UGString& strCacheFile);

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
		
	// ����/��ȡͼƬ����ɫ�Ƿ�͸��
	void	SetTransparentBack(UGbool bTransparentBack);
	UGbool	IsTransparentBack();
	

	// ����/��ȡ�ü�����
	// ���û�����òü����򣬻�ȡ���Ϊ NULL��
	UGbool				SetClipRegion(UGGeoRegion *pClipRegion);
	const UGGeoRegion  *GetClipRegion();

	// ����/�ж��Ƿ�Ϊȫ���ʷ�
	void		SetTileType(TileType tileType);
	TileType	GetTileType();

	// ���ݼ�����
	// ���û�����û��������򻺴���Ϊ���ݼ���
	void			 SetDatasetName(const UGString &strName);
	const UGString& GetDatasetName();


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

	UGbool TileArea2PixelArea(const TileArea &tileArea,	PixelArea &rcPixelArea);
	UGbool PixelArea2TileArea(const PixelArea &rcPixelArea,	TileArea &tileArea);

	UGbool TileArea2TileGroupArea(const TileArea &tileArea, TileGroupArea &tileGroupArea);
	UGbool TileGroupArea2TileArea(const TileGroupArea &tileGroupArea, TileArea &tileArea);

	// ��ȫ�������Ƭ���кŻ���ɶ�Ӧ���ջ�������к�
	static void ConvertRowCol(UGint& nRow, UGint& nCol);
	static void CompactCellPos2TilePos(UGint nTileGroupRow, UGint nTileGroupCol, UGint nCellRow, UGint nCellCol, UGint &nTileRow, UGint &nTileCol);

	// �������͵ı�����ת��Ϊ���������� .5 ת��������Ϊ 2���������������ɻ���Ŀ¼��
	unsigned	Scale2ScalePathName(UGdouble dScale);		
	UGdouble		ScalePathName2Scale(unsigned nScale);

	// ������ջ�����Ƭ��
	// Ҫ����Ƭ���ⲿ�Ѿ���ȫ������ϣ�������Ƭͷ����
	UGbool OpenCompactFile(UGdouble dScale, UGint nRow, UGint nCol, UGCompactFileWrapper &compactFile, UGbool bCreateIfAbsent = false);
	UGbool CreateCompactFile(UGdouble dScale, UGint nRow, UGint nCol, UGCompactFileWrapper &compactFile);
	
	// ����������
	void SetOutputScales_aux(const UGArray<UGdouble>& vectOutputScales,UGbool bIsDisplayByScales = false);//�Ƿ������˹̶�������

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
	// �������г�Ա
	void Reset();

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
	// ͨ��������ת����Ƭ�߳���Ӧ�ĵ����С
	UGSize2D ComputeTileMPSize(UGdouble dScale) const;

	//Ϊ����׼ȷ�����س�����ʱ�����������������õĵط����ࡣ��û����UGdouble���͵�����λ�õĺ�������������ô���£�
	UGdouble GetUnitsRatio();

	UGbool TilePos2PixelArea(UGdouble dScale, UGint nRow, UGint nCol, PixelArea &pixelArea);

	//! \brief  ����/��ȡ��������,��m_nstroeTypeΪMIXED_FILES��SINGLE_FILEʱ������Ż������á�
	void SetPassword(const UGString& strPwd);
	const UGString &GetPassword();

	// ===================================================================

	// 530000/3/5/7x12.3f2d0c
	//UGString TilePos2RelativeSolidPicFileNamePrefix(UGdouble dScale, UGint nRow, UGint nCol, UGColor color);

	UGbool SaveCompactCellData(UGdouble dScale, UGint nRow, UGint nCol, const UGbyte *pData, size_t nSize, UGCompactFileWrapper &compactFile);

	//! \brief ��ȡ�û��Զ������°汾
	UGint GetRevisionNumber();

	//! \brief �����û��Զ������°汾
	void SetRevisionNumber(UGint number);

	//! \brief ��ȡ�û����õ��Զ���汾�����İ汾��
	UGint GetMaxRevisionNumber();

	// ��ӵ�ǰ�û��Զ���汾���汾����б�
	void AddRevisionNumberToList();

	// ��ȡ�û��Զ����б�
	const UGArray<UGint> GetRevisionNumberList() const;

	// ͨ����Ƭλ�ü�����Ƭ���λ��
	void TilePos2TileGroupPos(UGint nTileRow, UGint nTileCol, UGint &nGroupTileRow, UGint &nGroupTileCol);

	//! \brief ����ѹ����ʽ
	UGint GetCompressType() const;
	void SetCompressType(UGint eCodecType);

	void SetPixelFormat(UGPixelFormat nPixelFormat);
	UGPixelFormat GetPixelFormat();
	//! \brief ���û����ļ�����
	//! \param bounds [in] ���淶Χ
	//! \return ��
	//! \remarks ��
	//! \attention
	void SetStorageType(UGuint type);
	//! \brief ��û����ļ�����
	UGuint GetStorageType();

	void SetCacheVersion(UGint nVersion);//
	void SetFileExtName(UGString strFileExtName);//str
	UGint GetCacheVersion();//
	UGString GetFileExtName();//str

	//! \brief ��ȡ�������ɵ���Ƭ���SCI�ļ���·������ʽΪ 1000/1/9.cf
	//! \param dScale [in]		��ǰ��ͼ�ı�����
	//! \return						��ȡ���ɵ���Ƭ���·��
	//! \remarks					�������£�
	UGString TilePos2RelativeCompactFileName(UGdouble dScale, UGint nRow, UGint nCol, UGbool bIsCreat = false);
	// 530000/3/5
	UGbool TilePos2RelativeSuperMapFileName_aux(UGdouble dScale, UGint nRow, UGint nCol, UGString &strPath);
	void ResetSCTContent();
	UGColorTable* GetColorTable();

	UGString GetNetCatchPath();

private:

	UGTerrainCacheFile &operator=(const UGTerrainCacheFile &rhs);
	UGTerrainCacheFile(const UGTerrainCacheFile &rhs);

	// ============================ �洢����ȡ��Ƭ��غ��� ============================

	
		// ��ȡ���ļ������е���ͼƬλ���д洢�����ݣ������洢��ͼƬ֮ǰ��ͷ��
	UGbool LoadCompactCellData(UGdouble dScale, UGint nRow, UGint nCol, UGByteArray &ByteArray, UGCompactFileWrapper &compactFile);

	// ��ȡ���ļ������е���ͼƬ��ͼƬ���ݡ�nRow �� nCol ����Ƭ���к�
	UGbool LoadCompactImageData(UGdouble dScale, UGint nRow, UGint nCol, UGByteArray &ByteArray, UGbool &bSolidColor, UGColor &solidColor, UGCompactFileWrapper &compactFile, UGint nRequiredImageType, UGbool bTransparent, UGbool bPreciseMatch);

	// ================================================================================
	// �����մ洢�������Ƿ���ȷ
	UGbool IsPassWordCorrect(const UGchar* strSCIFileName, const UGchar * strPassword);

	// ============================== ��Ƭλ�õ��ļ�����ת������ ==============================

	// ��ö����ļ���·������ '/' ��β
	UGString GetTopLevelPath();

		// TODO �ú�����������ȫ�� TilePos2FileName �滻��
	// NOTE ��ǰ���� ComputeImageFileName() ʹ��
	UGbool TilePos2RelativeFileName(UGdouble dScale, UGint nRow, UGint nCol, UGString &strFileName);




	// =========================================================================================

	// ��ȡ���������
	UGdouble ScaleToNearFixScale(UGdouble dScale);

	// �������������ı������е��±ꡣ
	// ���� Scale ����Ŀ���٣�ʹ�� UGint ֵ��ȫ���ԡ�����Ҫʹ�������� size_type��
	// 0 �𡣷��� -1 ��ʾ����
	// NOTE һ��Ҫ���ú����ķ���ֵ
	UGdouble Round2NearestScale(UGdouble dScale);

	void DebugValidateScale(UGdouble dScale);

	// ���� m_dUnitsRatio ��Ա��
	void AdjustUnitsRatio();

	// DPI �� CoordRatio �໥ת��
	UGdouble		DPI2CoordRatio(UGdouble nDPI) const;
	UGdouble		CoordRatio2DPI(UGdouble dCoordRatio) const;

	UGint GetBytesPerPixel(const PixelFormat& strDataFormat);

	bool UnZip(UGbyte* &pImageData,UGint & nSize);

	// ============================== ���ݳ�Ա ==============================
	// ����ĳ�Ա�ڻ��������ļ��г���
	//UGMapCacheVersion m_nCacheVersion;		// ��ǰ����İ汾�š��� ToConfigFile() �иð汾��ָʾ��Ҫ�������ļ���ʽ
	UGint	m_nFullCacheVersion;				// ��ǰ����������汾��
	//UGString m_strServiceProvider;				// Service Provider
	UGString m_strCacheName;					// �������ơ�����������������Ϊ����Դ��ʽ���м���ʱ������Դ����
	UGPrjCoordSys *m_pPrjCoordSys;				// ͶӰ��Ϣ������ͼ������ص���ά�����еı�����Ϣ��
	UGint m_nTileSize;							// ��Ƭ���ر߳���
	UGint m_nTileWidth;							// ��Ƭ���ؿ�
	UGint m_nTileHeight;						// ��Ƭ���ظ�
	UGRect2D m_rcBounds;						// ����ĵ���Χ��������Ϊ����Դ��ʽ���м���ʱ������Դ��Χ
	UGdouble m_dCoordRatio;						// LP/DP ת�����ʣ���λΪ(����/����)��
	UGRect2D m_rcIndexBounds;					// ������Χ
	UGbool m_bCompactCache;						// �Ƿ���ջ���
	UGString m_strNetCatchPath;					// ����·�������ַ
	//UGint m_nImageCompress;						// ����ͼƬѹ����
	UGGeoRegion* m_pClipRegion;					// �ü�����
	TileType m_TileType;						// ȫ���ʷֻ��߱����ʷ�
	UGDict<UGdouble, UGString> m_mapOutputScaleCaptions;	// �����ߡ�����
	//UGint m_nExtendedTiles;						// ������Ƭ������������������һ��

	UGString m_strDatasetName;					// ���ɻ�������ݼ���
	UGdouble m_dUnitsRatio;						// ͶӰ����ϵ�ĵ�λ��LP/MP��ת��������ʹ�á�
	UGArray<UGint> m_nRevisionNumberList;		// �û��Զ���汾����

	// ����ĳ�Ա���ڻ��������ļ��г���
	UGString m_strPassword;						// ���ļ���������
	UGString m_strFileDirectory;				// ����SCI���Ŀ¼λ��
	UGString m_strCacheFileName;				// �� sci �ļ�Ϊ�򿪵��ⲿ�ļ����߾����˱������������һ���ⲿ�ļ���Ӧ��

	UGint m_nRevisionNumber;					// �û���ǰ���õ��Զ���汾��
	UGbool m_bUseDataset;						//Ĭ��false�Ƿ�ʹ��Dataset���ݼ�
	//! \brief ѹ����ʽ
	//! \Ŀǰֻ���ڵ���ѹ���Ƿ�Ϊzipѹ��
	//add by fxj 101207
	UGint m_eCodecType;

	//! \brief ���ظ�ʽ
	//! \Ŀǰֻ���ڵ��λ����б���float/double���͵ĸ߾���DEM
	//add by shansg 2013-04-23
	UGPixelFormat m_nPixelFormat;

	//! \brief �����ļ�����
	//! \remarks ��ע��Ϣ��
	UGuint m_storeType;//0://PURE_FILES 1://MIXED_FILES 2 singlefile

	//! \brief ����汾��,���ڱ�ʶ�����ļ��İ汾
	//! \remarks ��ע��Ϣ��
	UGint m_nVersion;

	//! \brief �ļ���׺��
	UGString m_strFileExtName;

	//! \brief ÿ����������λ��
	UGint m_nBytesPerPixel;

	//! \brief �������ɫ���л�ȡ����ɫ��
	UGColorTable* m_pColorTable;
};

} // UGC

#endif // _UGABSTRACTCACHEFILE_H_
