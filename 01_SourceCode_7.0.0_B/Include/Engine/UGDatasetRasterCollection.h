#ifndef UGDATASETRASTERCOLLECTION_H
#define UGDATASETRASTERCOLLECTION_H

#include "Base/ogdccolordef.h"
#include "Engine/UGDatasetRaster.h"
#include "Engine/UGDataSource.h"
// #include "Engine/UGDatasetMultiBandRaster.h"

#define OPEN_IMAGEPLUGIN_MAX_COUNT 100

namespace UGC
{

typedef struct RasterCollectionItemInfo 
{
	UGString Name;
	UGString AliasName;
	UGString Path;
	UGint Order;
	UGbool IsFileType;

} UGRasterCollectionItemInfo;
	
class ENGINE_API UGOpenedImagePlugin
{
public:

	UGOpenedImagePlugin();
	~UGOpenedImagePlugin();

	UGDataSource* m_pDataSource;
	UGint m_nRefCount;
};

class ENGINE_API UGDatasetRasterCollection :public UGDatasetRaster
{
public:

	enum CollectionOperate
	{
		CAdd	=	1,
		CDelete	=	2,
		CUpdate	=	3,
	};
	
public:
	UGDatasetRasterCollection();

	virtual ~UGDatasetRasterCollection();
	
public:

	//! \brief �رռ���
	virtual void Close();

	//! \brief ���ݱ�����ȡ�����ݼ��м����е�˳��
	virtual UGint GetSubDatasetOrder(const UGString &strAliasName);

	//! \brief ���ü��ϵ�ͶӰ��ֻ�ڼ������������ݼ�ʱ��Ч��
	virtual UGbool SetPrjCoordSys(const UGPrjCoordSys &PrjCoordSys);

	//! \brief �жϴ�դ�񼯺��Ƿ�Ϊ�ನ�μ���
	virtual UGbool IsMBRaster();

	//! \brief ���õ�ǰ�̵߳�ɫ�ʿռ�ģʽ��
	//! \param aryBand ����ѡ��[in]��
	//! \param nColorSpace ɫ�ʿռ�ģʽ[in]��
	virtual void SetBandCombineMode(const UGArray<UGint>& aryBand, ImgColorSpace nColorSpace);

	//! \brief ��ȡ��ǰ�̵߳�ɫ�ʿռ�ģʽ��
	//! \param aryBand ����ѡ��[in]��
	//! \param nColorSpace ɫ�ʿռ�ģʽ[in]��
	//! \remarks ������ǰ�����ܻ�ȡ����ǰ��ɫ�ʿռ�ģʽ��
	virtual UGbool GetBandCombineMode(UGArray<UGint>& aryBand, ImgColorSpace& nColorSpace);	

	//! \brief ����������
	virtual UGbool BuildPyramid(UGbool bShhowProgress);
	
	//! \brief ���½�����
	virtual UGbool UpdatePyramid(const UGRect2D &rect);

	//! \brief �ı伯��˳��
	//! \param strAliasName �����ݼ�����[in]��
	//! \param nPosition Ҫ�ı��λ�ã����㿪ʼ[in]
	//! \return �Ƿ�ı�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual UGbool ChangeOrder(const UGString &strAliasName,UGint nPosition);

	//! \brief ��ȡҪ��ǰҪ��ʾ�������ݼ�Ӱ��飬�ⲿ���л���
	UGArray<UGImgBlock*> GetViewBlocks(const UGRect2D& rcView, UGint nDeviceWidth, UGint nDeviceHeight);
	
	//! \brief ��ȡ��ǰ��ʾ�������ݼ�����Ӧ�Ĳü������ڻ���ʱʹ�ã�
	//! \brief �ⲿ�����ͷſռ�
	UGArray<UGGeoRegion*> GetCurViewClipRgn();

	//! \brief ��ȡ��ǰ��ʾ�������ݼ�����Ӧ�ĵ�ɫ�壬�ڻ���ʱʹ�ã�
	//! \brief �ⲿ�����ͷſռ�
	UGArray<UGColorset*> GetCurViewPalette();

	virtual UGbool Rename(const UGString& strNewName);

	// ͳ��դ����Ϣ
	virtual UGDict<UGint, UGRasterStatisticsInfo> BuildStatistics();

	UGDatasetRaster * GetCollectionPyramidTier(UGRect2D rcBounds,UGint nDeviceWidth);

public:

	//! \brief ��������ݼ�
	//! \param strName �����ݼ������ļ����ݼ�ʱΪӰ���ļ��ľ���·����
	//! \param strAliasName ���ݼ��ڼ����еı�����һ�������в������ظ��ı���
	//! \param bTop �Ƿ񽫴������ݼ��ӵ�����
	//! \return �Ƿ����ӳɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool AddSubDataset(const UGString &strName, const UGString &strAliasName, UGbool bTop = FALSE);
	
	//! \brief ��������ݼ�
	//! \param �����ݼ������飬�ļ����ݼ�ʱΪӰ���ļ��ľ���·����
	//! \param ���ݼ��ڼ����еı������ظ����Զ���"_1"
	//! \return ������ӳɹ��������ݼ�������
	UGint AddSubDataset(const UGArray<UGString> &arrName, const UGArray<UGString> &arrAliasName);

	//! \brief ���ָ���ļ����µ�Ӱ���ļ���������
	//! \param strPath �ļ���·��
	//! \param strExtName �����Ӱ���ļ��ĺ�׺��
	//! \return ������ӵ������ݼ�����
	UGint AddFiles(const UGString &strPath, const UGString &strExtName);

	//! \brief ׷�Ӽ��ϡ�
	//! \param Դ���� ��ֻ׷�Ӽ�����ΪӰ���ļ��������ݼ���
	//! \return �Ƿ�׷�ӳɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool Append(UGDatasetRasterCollection* pSrcCollection);

	//! \brief ���������ݼ�
	//! \param strName �����ݼ������ļ����ݼ�ʱΪӰ���ļ��ľ���·����
	//! \param strAliasName ���ݼ��ڼ����еı�����һ�������в������ظ��ı���
	//! \param nPosition �����ݼ��ڼ����е����
	//! \return �Ƿ����ӳɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool InsertSubDataset(const UGString &strName, const UGString &strAliasName, UGint nPosition);

	//! \brief ����ָ���������Ƴ������ݼ�
	UGbool RemoveSubDataset(UGint nIndex);

	//! \brief ����ָ���ı����Ƴ������ݼ�
	UGbool RemoveSubDataset(const UGString &strAliasName);
	
	//! \brief �Ƴ����������Ե������ݼ�
	UGbool RemoveAllSubDataset();

	//! \brief ��ȡ���������ݼ��ĸ���
	UGint GetSubDatasetCount();
	
	//! \brief ���������ݼ��ڼ����е��������ȡ�����
	UGString GetAliasName(UGint nOrder);

	//! \brief ʵʱ��ȡ���������ݼ��ı����������б�����˳����������ڼ������˳��һ�£�
	UGbool GetAliasNames(UGArray<UGString>& arrAliasNames);
	
	//! \brief ʵʱ��ȡ���������ݼ�����Ҫ��Ϣ
	UGbool GetItemInfo(UGArray<UGRasterCollectionItemInfo>& arrItemInfo, UGRect2D& rcBounds);

	//! \brief ����ָ����������ȡ�����ݼ�
	UGDataset* GetSubDataset(UGint nIndex);
	
	//! \brief ����ָ���ı�����ȡ�����ݼ�
	UGDataset* GetSubDataset(const UGString &strAliasName);
	
	//! \brief ��ȡ�����ݼ�
	//! \param strName �����ݼ����������ݼ�������
	//! \param strConnection �����ݼ�������Դ���Ӳ���
	//! \return ��������ȡ�����ݼ���û���򷵻�NULL
	UGDataset* GetSubDataset(const UGString& strName, const UGString& strConnection);

	//! \brief �������ݼ������ļ�·��ֱ�ӻ�ȡ�����ݼ�
	//! \param strName ���ݼ�����
	//! \param bIsImagePlugins �Ƿ�ΪӰ���ļ�
	//! \param strPath Ӱ���ļ�����·��
	//! \return ��������ȡ�����ݼ���û���򷵻�NULL
	UGDataset* GetSubDataset(const UGString& strName, UGbool bIsImagePlugins, const UGString& strPath);
	
	//! \brief �жϱ����ڼ������Ƿ��ڡ�
	//! \param strAliasName �����ݼ�����[in]��
	//! \return �Ƿ���ڣ����ڷ���TRUE�����򷵻�FALSE��
	UGbool IsExitAlias(const UGString &strAliasName);
	
	//! \brief �ж����ݼ����·����������
	UGbool IsCanAdd(UGDatasetRaster* pDataset, UGbool bIsFirst);
	
	//! \brief ��������Ѵ��ڣ����һ�����õı���
	UGbool GetValidAliasName(UGString& strAliasName);
	
	//! \brief ���ݱ�����ȡ�����ݼ��Ĳü�����
	//! \param strAliasName �����ݼ�����
	//! \param pClipRegion ��ȡ�Ĳü�����
	//! \return �Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool GetSubClipRegion(const UGString &strAliasName, UGGeoRegion *&pClipRegion);

	//! \brief ���ݱ������������ݼ��Ĳü�����
	//! \param strAliasName �����ݼ�����
	//! \param pClipRegion �ü�����
	//! \return �Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool SetSubClipRegion(const UGString &strAliasName, UGGeoRegion *&pClipRegion);

	//! \brief ���ݱ�����ȡ�����ݼ��ĵ�ɫ��
	//! \param strAliasName �����ݼ�����
	//! \param colorset ��ɫ��
	//! \return �Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool GetSubPalette(const UGString &strAliasName, UGColorset &colorset);

	//! \brief ���ݱ������������ݼ��ĵ�ɫ�壨��1λ��4λ��8λӰ����Ч��
	//! \param strAliasName �����ݼ�����
	//! \param colorset ��ɫ��
	//! \return �Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool SetSubPalette(const UGString &strAliasName, UGColorset &colorset);

	//! \brief ��ȡդ�񼯺ϵ��������ݼ�
	UGDatasetVector* GetAttributeDataset();

	//! \brief ����դ�񼯺ϵ��������ݼ�
	void SetAttributeDataset(UGDatasetVector* pDataset);
	
	//! \brief ���õ�ǰ�����ݼ��Ƿ����
	UGbool SetSubEnable(UGString &strAliasName, UGbool bIsEnable);
	
	//! \brief ͬ����ǰ����
	UGbool SyncSubDatasets();

	//! \brief ����ָ�������ݼ��ı���
	UGbool RenameSubDataset(UGString& strAliasName, UGString& strNewAliasName);

	void ReduceImagePluginRefCount();

protected:

	// {{ ����Ϊ��ȫ���ڲ���ʹ�õķ���

	//! \brief ����Ӱ������Ӱ���ļ�
	//! \param strImagePath Ӱ���ļ��ľ���·��
	//! \return �������򿪵����ݼ�
	UGDataset* OpenImagePluginDataset(const UGString &strImagePath, const UGString &strName = _U(""));

	//! \brief �ر�Ӱ��������Դ
	//! \param strName Ӱ���ļ������ݼ�����
	void CloseImagePluginDataset(const UGString &strName);

	//! \brief �ر����Ե�Ӱ��������Դ
	void CloseAllImagePluginDataset();

	//! \brief ��ȡ��ǰ��Ҫ��ʾ�Ľ���������
	UGint GetPyramidLevel(UGDatasetRaster* pDatasetRaster, const UGRect2D& rcView, UGint nDeviceWidth);

	virtual UGbool UpdateCollectionTable(UGDatasetRasterCollection::CollectionOperate nType, 
		const UGint& nSubDatasetOrder, UGbool bTop = FALSE);

	// ���������ʱ��������ָ�������ƺͱ�����������Feature�������������
	UGbool GetFeature(const UGString &strName, const UGString &strAliasName, UGFeature*& pFeature, UGbool bIsFirst);

	void UpdateInfo(UGFeature* pAddFeature, UGbool bIsFirst);

	void SetQueryFields(UGArray<UGString>& fields);

	void SetCreateFields(UGFieldInfos& fieldInfos);

	UGbool ReleasePyramidDatasets();
	
	//! \brief ���û���������Ĵ�С
	void SetBasePyramidSize(UGDatasetRasterInfo& info);

	//! \brief ���µ�һ�������
	UGbool UpdateBasePyramidTier(UGDatasetRaster*& pBasePyramidTier, UGRect2D rcUpdateBounds, UGint nBandIndex = 0);

	UGbool UpdateBasePyramidTier(UGDatasetRaster* pBasePyramidTier, UGRect2D rcSubBounds, 
		UGDatasetRaster* pSubRasterDataset,UGProgress &Progress, UGint nBandIndex = 0);

	UGImgBlock* GetImagePluginsViewBlock(UGDatasetRaster* pSubRasterDataset, 
		const UGRect2D& rcBounds, UGint nBandIndex);

	//! \brief �������Ӱ��飬���ڽ��������£�����ɾ��һ�������ݼ���
	UGbool EraseBasePyramidTier(UGDatasetRaster* pBasePyramidTier, UGRect2D& rcRect, UGint nBandIndex = 0);

	void ConvertPixel(UGDatasetRaster* pSrcRaster, UGdouble& dValue);

	void ConvertBlock(UGImgBlock*&pImgBlock, UGDatasetRaster*& pDatasetRaster);

	// ���µ�����Ӱ�������
	UGbool UpdatePyramidSB(const UGRect2D &rect);
	
	// ���¶ನ��Ӱ�������
	UGbool UpdatePyramidMB(const UGRect2D &rect);

	// �Ե�ǰ�����еĶನ�����ݼ��ĵ�ǰ�������еĹ���
	void SetIndex(UGint nIndex);
	
	UGint GetIndex() const;

	// �õ������������ݵĲ������ݣ��������ݼ��Ĳ���������һ����
	UGint GetColBandCount();
	// }}

protected:
	
	//! \brief �����������ݼ�
	UGDatasetVector* m_pAttributeDataset;

	// Ӱ��������Դ��ÿһ��Ӱ���ļ���Ӧһ������Դ
	UGArray<UGOpenedImagePlugin*> m_arrImgDataSource;

	UGDict<UGint, UGOpenedImagePlugin*> m_dicCurOpenedImagePlugin;

	//! \brief ��ʾʱ����Ӱ���Ĳü�����͵�ɫ��
	UGDict<UGint,UGArray<UGGeoRegion*> > m_dicCurViewClipRgn;
	UGDict<UGint,UGArray<UGColorset*> > m_dicCurViewPalette;

	// �ڸ���Ӱ���ʱ�����õ�ǰ��ĵ�ɫ��Ͳü�����
	UGColorset m_SubColorset;
	UGGeoRegion* m_pSubClipRegion;

	// ��ǰ����
	UGDict<UGint, UGint> m_dicIndex;

	// �ನ����ʾɫ�����
	UGDict<UGint,UGColorSpaceBand> m_dicColorSpace;

	// �ನ�ο����
// 	UGArray<UGImgBlocksManager> m_arrImgManager;

	// ���Ͻ�����������
	UGint m_nPyramidTierCount;

	// �������漯���������ݼ�����������Ҫ��Ϊ��ǰ��汾����
	// 0��ʾSP3�汾�ĵ����μ��ϣ�7C�汾����С��Ϊ1
	// ��Ϊ7C�汾����դ��Ӱ�����ݵĲ�������Ϊ1
	UGint m_nCollectionBandCount;
};
}
#endif