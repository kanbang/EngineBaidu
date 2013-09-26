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
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGLOCALCACHEMANAGER_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
#define AFX_UGLOCALCACHEMANAGER_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_

#include "Stream/ugdefs.h"
#include "Projection/UGPrjCoordSys.h"
#include "Toolkit/UGPalette.h"
#include "FileParser/UGExchangeFileType.h"
#include "CacheFile/UGCacheFileCommon.h"

namespace UGC 
{	
class UGMapCacheFile;
class UGTile;

//! \brief ��Ƭ����Ϣ
struct UGTileInfo
{
	//! \brief ������
	UGdouble m_dScale;

	UGint m_nRow;

	UGint m_nCol;

	//! \brief ��Χ
	UGRect2D m_rcBound;
};


//! \brief ���ػ��潻����
class MAPSERVICESTUB_API UGLocalCacheManager 
{
	enum UGCacheType
	{	
		MapCache	= 0,	
		GlobalCache = 1,
	};

public:
	//! \brief ���캯����
	UGLocalCacheManager();

	//! \brief ����������
	virtual ~UGLocalCacheManager();
	
public:
	
	//! \brief ���ض�ά���档
	//! \param UGMapCacheFile* [out]��
	UGMapCacheFile* GetAbstractCacheFile() const;

	//! \brief �������档
	//! \param strCacheFile [in]��
	//! \param nCacheType [in]��
	//! \return �ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention ͨ����׺�жϻ������͡�
	UGbool Create(const UGString& strCacheFile, UGint nCacheType = 0);

	//! \brief �򿪻��档
	//! \param strCacheFile [in]��
	//! \param nCacheType [in]��
	//! \return �ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool Open(const UGString& strCacheFile, UGint nCacheType = 0);
	
	//! \brief �ر�	
	void Close();	
	
	// ����.scihp�ļ�
	UGbool Save();

	//! \brief ��ȡ��Ƭ����
	//! \param TileData [in,out] ������Ƭ�����ݽṹ��
	UGbool GetTileData(UGTile& tileData);

	//! \brief ���ݴ����TileData�еı����ߣ���ȡTile�ĵ���Χ�����ط�Χ
	void GetTileInfo(UGTile& tileData);
	
	// ��ȡ�û���չ�ֶε����ã���ֱ���޸ġ�
	// ���map��Ԫ�ظ�����Ϊ0�������α���Ԫ�ص������ļ����
	std::map<UGString, UGString>& UserExtendField();

	//! \brief �������еı����߼���
	const UGArray<UGdouble> GetScales() const;	

	//! \brief ��ȡ��ͼ����Ŀռ�����ϵ��
	//! \param [out] ͶӰ
	//! \attention ��ȡ�����渺���ͷ�
	const UGPrjCoordSys& GetSpatialRef() const;	

	const UGbool IsCacheFileExist(UGString strCacheFile) const;

	//! \brief ��ȡ��ͼ����
	UGString GetMapName() const;

public:
	//! \brief ������������
	void SetCacheName(const UGString &strCacheName);
	void SetVersion(enum UGC::UGMapCacheVersion nVersion);

	enum UGC::UGMapCacheVersion GetVersion();

	//! \brief ͼƬ��Χ
	void SetBounds(const UGRect2D &rcBounds);

	//! \brief ͼƬ���ԣ�������͸��Png32����͸��Png32��Png8��Jpeg�����ͼƬģʽ
	void SetImageType(UGFileType::EmType nPictureFormat);

	//! \brief ͶӰ 
	void SetPrjCoordSys(const UGPrjCoordSys &CoordSys);

	//! \brief DPI���ṩ LP/DP ת�����ʣ�x�����y�������һ�°�
	void SetCoordRatio(UGdouble dCoordRatio);
	double GetCoordRatio();

	//! \brief ��������Ϣ�����Ҫ�󣬲�Ҫ������ߵĵ�����
	//! \attention ������б����߶���������Χ������Ϊ���������� true�����򷵻� false�����Ҳ��Ա��������ý����κ��޸ġ�
	UGbool SetOutputScales(const std::vector<UGdouble>& vectOutputScales);
	
	//! \brief �����ߺͱ����߱����Ķ�Ӧ��ϵ
	UGbool SetOutputScaleCaptions(const std::map<UGdouble, UGString> &mapOutputScaleCaptions);

	//! \brief ����ͼƬ���ش�С��Ĭ����256���ؿ��
	void SetTileSize(UGint nTileSize);
	
	//! \brief �Ƿ���ջ��棬Ĭ�ϲ��ǽ���
	void SetIsCompactCache(UGbool bCompactCache);

	// ��ȡ�����Ƿ񱳾�͸��
	UGbool IsTransparentBack();
	void SetTransparent(const UGbool &bTransparent);

	//! \brief �������кŵ�ԭ�㣬�����ϲ�Ѿ�γ�ȵģ�-180��90��ת������ǰ��ͼͶӰ����ϵ����Ĭ��ֵ
	//! \attention �����趨��ԭ�㣬��������ȡ���ݣ���ԭ����ߺ��ϱߵĲ���ͼƬ
	void SetOrigin(const UGPoint2D &pntOrigin);

	//! \brief ��ȡ�����߼���
	const std::vector<UGdouble> GetOutputScales();
	
	//! \brief ��ȡ�����߱���
	void GetOutputScaleCaptions(std::map<UGdouble, UGString> &mapOutputScaleCaptions);

	//! \brief ��ȡ��Ƭȫ·��
	UGString GetTileFilePath(const UGdouble& dScale, const UGint& nRow, const UGint& nCol);

	//! \brief ���÷����ṩ��
	void SetServiceProvider(const UGString& strProvider);

	//! \brief ��ȡ�����ṩ��
	UGString GetServiceProvider() const;
    
	
	UGint GetImageWidth() const;

	UGint GetImageHeight() const;

	UGint GetScaleCount() const;

	UGint GetTileSize() const;

	PixelFormat GetPixelFormat() const;

	UGdouble ScaleToNearFixScale(UGdouble dScale) const;

	UGRect2D ComputeTilesBounds(UGdouble dMapScale, const UGRect2D& rcMapBounds, UGint nExtTileSize = 1) const;

	UGSize2D GetTileMPSize(UGdouble dMapScale) const;

	UGRect2D GetBounds()const;
	
public:
	//! \brief �����Ƿ�򿪡�
	//! \param  [in]��
	UGbool IsOpened(){return m_bOpen;}
    
	void BoundToRowAndCol(UGdouble& dScale, const UGRect2D& bound, UGint& nRow, UGint& nCol);

protected:	
	//! \brief ����򿪱�־��
	UGbool m_bOpen;

	UGString m_strCacheFile;

	UGString m_strCacheDir;

	UGString m_strFileExtName;
	
	//! \brief Map������ 
	//! \attention ��Ҫ������UGMapServiceStub�жϴ�ʱ�Ļ����Ƿ��Ѿ��ǿյ�
	UGString m_strMapName;
	
	//! \brief �����ͶӰ��
	UGPrjCoordSys m_prjCoordSys;
	
	//�� biref ��ά����Ļ���
	//! \attention �ڹ��캯����ʱ�򱻳�ʼ��
	UGMapCacheFile *m_pMapCacheFile;

////////////����ʵ��GetViewBlock�ӿ�//////////////{
public:
	//! \brief ���õ�ǰ��ʾ��Χ
	//! \param  nLeft, nTop,��ʾ��Χ����ߺ��ϱߡ�nLeft < nRight��nTop < nBottom.[in]
	//! \param  nRight, nBottom ��ʾ��Χ���ұߺ��±ߡ����Ǹ�ֵ�������������ꡣ[in]
	//! \param  nDeviceWidth, nDeviceHeight,��ʵ��ʾ���ڵĴ�С����Ļ���ص�λ��[in]
	//! \remarks ���ڶ�ֱ��ʵ�ͼ�󣬿��԰��մ��ڴ�С����ʾ��Χ��С��ȷ��ͼ��ķֱ���,�Ӷ���������һ��ȡ��Ӱ������
	bool SetViewPort(int nLeft,int nTop, int nRight, int nBottom, int nDeviceWidth, int nDeviceHeight);

	//! \brief ���õ�ǰ��ʾ��Χ
	//! \param  dLeft, dTop,��ʾ��Χ����ߺ��ϱߡ�dLeft < dRight��dTop < dBottom.[in]
	//! \param  dRight, dBottom ��ʾ��Χ���ұߺ��±ߡ����Ǹ�ֵ�����ǵ�������.[in]
	//! \param  nDeviceWidth, nDeviceHeight,��ʵ��ʾ���ڵĴ�С����Ļ���ص�λ��[in]
	//! \remarks ���ڶ�ֱ��ʵ�ͼ�󣬿��԰��մ��ڴ�С����ʾ��Χ��С��ȷ��ͼ��ķֱ���,�Ӷ���������һ��ȡ��Ӱ������
	bool SetViewPort(double dLeft,double dTop, double dRight, double dBottom, int nDeviceWidth, int nDeviceHeight);

	//! \brief ���õ�ǰ��ʾ��Χ��,������ʾ��Χ��Ӱ�����ݵĿ�ȡ�
	//! \remarks ���ڶ�ֱ���ͼ�󣬿��ܴ�����һ���ȡ���ݣ���������Ŀ�ȿ��ܺ���ʾ��Χ�Ŀ�Ȳ�һ��
	//! \param  nViewWidth ��ʾ����Ӱ���ȡ�[out]
	//! \param  nViewHeight ��ʾ����Ӱ��߶ȡ�[out]
	bool GetViewImageSize(int& nViewWidth, int& nViewHeight);

	//! \brief ���õ�ǰ��ʾ��Χ��,������ʾ��Χ�����ݵĴ�С��
	int GetViewImageDataSize(); 

	//! \brief ���õ�ǰ��ʾ��Χ��,��ȡ��ʾ��Χ�ڵ�Ӱ������,�ⲿȡ�������Ժ󣬿���������ʾ
	//! \param  pDataBuffer,Ӱ�����ݣ����������ռ䡣[in]
	//! \param  nSize�����ݴ�С(�ֽ�������һ�����GetViewImageDataSize��������ֵ.[in]
	bool GetViewImageData(unsigned char* pDataBuffer, int nSize);

	//! \brief ָʾ���������Ƿ�ȫ������
	UGbool IsFinished(){return m_bFinished;}

	//! \brief �õ���ǰ���ӷ�Χ
	virtual UGRect2D GetViewRect();

	//! \brief ���ػ���Ӱ�������
	//! \param  dScale. ��Ƭ������.[in]
	//! \param  nRow. ��Ƭ�к�.[in]
	//! \param  nCol. ��Ƭ�к�.[in]
	//! \param  bRGBA �Ƿ�ת����RGBA[in]
	//! \return ��Ƭ��ImageData
	UGImageData* LoadTileImageData(UGdouble dScale, UGint nRow, UGint nCol, UGbool bRGBA = FALSE);

private:
	UGbool UnZip(UGbyte* &pImageData,UGint &nSize);

	//! \brief �������ݻ�����
	bool CreateDataBuffer();

	//! \brief �ͷŻ�������
	void ReleaseBufferData();

	void Release();

	//! \brief �õ�Ӱ���İ�Χ��
	//! \param  nRow. ����к�.[in]
	//! \param  nCol. ����к�.[in]
	//! \param  nDataLevel. ��Ĳ��.[in]
	UGRect2D GetCellBound(UGint nRow, UGint nCol, UGint nDataLevel);

	UGRect GetCellDataRowCol(UGRect2D InsectBound, UGRect2D CellBound);

	//! \brief ���ػ���Ӱ������
	//! \param  nBeginRow. ��ȡ����Ӱ�����ݵ���ʼ�к�.[in]
	//! \param  nEndRow. ��ȡ����Ӱ�����ݵĽ����к�.[in]
	//! \param  nBeginCol. ��ȡ����Ӱ�����ݵ���ʼ�к�.[in]
	//! \param  strFilePath. ��ȡ��Ӱ������ݵĽ����к�.[in]
	//! \param  strFilePath. ��ȡ����Ӱ�����ݵĲ��.[in]
	bool LoadImageData(UGint nBeginRow, UGint nEndRow, UGint nBeginCol, UGint nEndCol, UGint nDataLevel, UGRect2D ViewRect);

	//! \brief ���õ�ǰ���ӷ�Χ
	void SetViewRect(const UGdouble &dLeft, const UGdouble &dTop, const UGdouble &dRight, const UGdouble &dBottom);

private:

	//! \brief ����ͼƬ���ظ�ʽ
	//! \remarks ��Ϊ��ЩͼƬ��λ���Ƕ�ȡ��������  ����Ҫ����¼һ�»���ĸ�ʽ
	//! \remarks ����λ����ļ�BilĿǰ��λ����IPF_TBYTE
	PixelFormat m_nPixelFormat;

	//! \brief ���ݻ����С
	UGint m_nBuffSize;

	//! \brief ���ݻ���
	UGbyte* m_pBuffer;

	//! \brief �ӷ�Χ�ڵĿ��
	UGint m_nViewWidth;

	//! \brief �ӷ�Χ�ڵĸ߶�
	UGint m_nViewHeight;

	UGDict<UGlong, UGImageData*> m_imageDatas;

	UGbool m_bFinished;

	//! \brief ��ǰ��������
	UGRect2D m_ViewRect;

	UGint  m_nCacheType;

//////////////////////����ʵ��GetViewBlock�ӿ�///////////////////}

};

} //namespace UGC

#endif // !defined(AFX_UGLOCALCACHEMANAGER_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)

