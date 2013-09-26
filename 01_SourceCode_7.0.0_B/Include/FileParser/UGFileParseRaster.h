//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details ���ļ�������դ���ļ���������Ҫ�ӿڡ�
//!  \author ���֡�
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFileParseRaster_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_)
#define AFX_UGFileParseRaster_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_


#include "UGFileParse.h"
#include "Geometry/UGGeometry.h"
#include "Toolkit/UGPalette.h"
#include "FileParser/UGRasterConfigParams.h"
#include "Base3D/UGTextureData.h"
#include "Base/OgdcHistogram.h"

namespace UGC {
const UGint BAND_FIRST_INDEX = 0;
class UGImage;

//! \brief դ��ͼ���ͳ����Ϣ
//! \remarks ��������Ķ���
class RasterStatisticInfo
{
public:
	UGdouble m_dMax;//���ֵ
	UGdouble m_dMin;//��Сֵ
	UGdouble m_dMiddle;//��ֵ
	UGdouble m_dAverage;//ƽ��ֵ
	UGArray<UGdouble> m_arrMost;//����
	UGArray<UGdouble> m_arrLeast;//ϡ��
	UGdouble m_dStddev;//��׼��
	UGdouble m_dVariance;//����

	RasterStatisticInfo()
	{
		m_bHasMin = FALSE;
		m_bHasMax = FALSE;
		m_bHasAverage  = FALSE;
		m_bHasLeast = FALSE;
		m_bHasMiddle = FALSE;
		m_bHasStddev = FALSE;
		m_bHasVariance = FALSE;
		m_bHasMost = FALSE;
	}
	void SetMax(UGdouble max)
	{
		m_dMax = max;
		m_bHasMax = TRUE;
	}
	void SetMin(UGdouble min)
	{
		m_dMin = min;
		m_bHasMin = TRUE;
	}
	void SetMiddle(UGdouble mid)
	{
		m_dMiddle = mid;
		m_bHasMiddle = TRUE;
	}
	void SetAverage(UGdouble average)
	{
		m_dAverage = average;
		m_bHasAverage = TRUE;
	}
	void SetMost(UGArray<UGdouble> most)
	{
		m_arrMost = most;
		m_bHasMost = TRUE;
	}
	void SetLeast(UGArray<UGdouble> least)
	{
		m_arrLeast = least;
		m_bHasLeast = TRUE;
	}
	void SetStddev(UGdouble stddev)
	{
		m_dStddev = stddev;
		m_bHasStddev = TRUE;
	}
	void SetVariance(UGdouble variance)
	{
		m_dVariance = variance;
		m_bHasVariance = TRUE;
	}
	UGbool HasMax()
	{
		return m_bHasMax;
	}
	UGbool HasMin()
	{
		return m_bHasMin;
	}
	UGbool HasMost()
	{
		return m_bHasMost;
	}
	UGbool HasLeast()
	{
		return m_bHasLeast;
	}
	UGbool HasStddev()
	{
		return m_bHasStddev;
	}
	UGbool HasVariance()
	{
		return m_bHasVariance;
	}
	UGbool HasMiddle()
	{
		return m_bHasMiddle;
	}
	UGbool HasAverage()
	{
		return m_bHasAverage;
	}

private:
	//! \brief ͳ����Ϣ��һ������ȡ���������������±�ʶ�������ж���Щ��Ա����Ϣ����Ч��
	UGbool m_bHasMin;      // ��Сֵ�Ƿ���Ч
	UGbool m_bHasMax ;     // ���ֵ�Ƿ���Ч
	UGbool m_bHasMiddle;   // ��ֵ�Ƿ���Ч
	UGbool m_bHasAverage;  // ƽ��ֵ�Ƿ���Ч
	UGbool m_bHasMost;     // �����Ƿ���Ч
	UGbool m_bHasStddev;   // ��׼���Ƿ���Ч
	UGbool m_bHasVariance; // �����Ƿ���Ч
	UGbool m_bHasLeast;    // ϡ���Ƿ���Ч


};

class RasterStatisticInfoMngr :public UGArray<RasterStatisticInfo>
{
public:
	UGbool m_bNeedMin;      // �Ƿ���Ҫ��ȡ��Сֵ
	UGbool m_bNeedMax ;     // �Ƿ���Ҫ��ȡ���ֵ
	UGbool m_bNeedMiddle;   // �Ƿ���Ҫ��ȡ��ֵ
	UGbool m_bNeedAverage;  // �Ƿ���Ҫ��ȡƽ��ֵ
	UGbool m_bNeedMost;     // �Ƿ���Ҫ��ȡ����
	UGbool m_bNeedStddev;   // �Ƿ���Ҫ��ȡ��׼��
	UGbool m_bNeedVariance; // �Ƿ���Ҫ��ȡ����
	UGbool m_bNeedLeast;    // �Ƿ���Ҫ��ȡϡ��
	
	RasterStatisticInfoMngr()
	{
		m_bNeedMin = FALSE;
		m_bNeedMax = FALSE;
		m_bNeedMiddle = FALSE;
		m_bNeedAverage = FALSE;
		m_bNeedMost  = FALSE;
		m_bNeedStddev = FALSE;
		m_bNeedVariance = FALSE;
		m_bNeedLeast = FALSE;		
	}
};

//! \brief ʵ��դ������Ա�
class UGRasterAttributeTable//: public OgdcRecordset
{
public:
	//! \brief ����ɫ���ʼ�����Ա�
	//! \param colorset  ��ɫ��[in]
	UGbool InitFromColorset(const UGColorset& colorset)	;

	//! \brief ��ֵ���ָ���ɫ��Χ�����������Ա��С�
	//! \param values  ��ֵ���ָ���ɫ��Χ��[in]
	UGbool SplitRows(UGdouble* values);	

	//! \brief �����Ա��Ƴ���ɫ��
	//! \param colorset  ��ɫ��[out]
	void ToColorset(UGColorset& colorset);	

	//! \brief ��ȡֵ����Ӧ����ɫ��
	//! \param dfValue  ֵ��[in]
	//! \param color  ֵ��Ӧ����ɫ��[out]
	UGbool GetColorOfValue(UGdouble dfValue, UGColor& color);

	//! \brief ��ȡֵ���ڵ��С�
	//! \param dfValue  ֵ��[in]
	//! \param iRow  �����С�[out]
	UGbool GetRowOfValue(UGdouble dfValue, UGint& iRow)	;

	//! \brief ��ȡһ����ɫ��Χ�������ޡ�
	//! \param iRow [in] �ڼ�����ɫ��Χ��
	UGbool GetRowRange(UGint iRow, UGdouble& rowMin, UGdouble& rowMax);

};

class UGFileParseRaster;
class FILEPARSER_API UGRasterFileLayer: public UGFileLayer
{
public:
	UGRasterFileLayer(UGFileParseRaster* pFP){m_pFP = pFP;}

	UGFileParseRaster* GetRasterFileParser(){return m_pFP;}

public:
	virtual FILELAYER_TYPE GetType(){return UGFileLayer::FL_RASTER;}

private:
	UGFileParseRaster* m_pFP;

};

typedef UGbool (UGSTDCALL * BandGetTileFunc) (UGByteArray*, UGlong);

// ������Ҳ��һ��ͼƬ��ͬ���ǰ���洢�ġ�
struct PyramidInfo
{	
	PyramidInfo()
	{	
		m_nWidth  = 0;
		m_nHeight = 0;
		m_nIndex  = 0;
		m_nBlockWidth   = 0;
		m_nBlockHeight  = 0;
		m_nBlocksPerRow = 0;
		m_nBlocksPerColumn = 0;
		m_nGDALDataType = 8;
		m_ePixelFormat  = IPF_UBYTE;
	}
	UGint m_nWidth;           //ͼƬ�� ����ĵ�λҪ�������ظ�ʽ��ȷ��
	UGint m_nHeight;          //ͼƬ��
	UGint m_nIndex;           //������������
	UGint m_nBlockWidth;      //��Ŀ�
	UGint m_nBlockHeight;     //��ĸ�
	UGint m_nBlocksPerColumn; //ÿ�еĿ��� 
	UGint m_nBlocksPerRow;    //ÿ�еĿ���
	UGint m_nGDALDataType;    //GDAL�е��������ͣ������Ǻ�������ǲ���ָ�����ظ�ʽ
	UGPixelFormat m_ePixelFormat; // ���ظ�ʽ
};



//! \brief ������Ҫ�Ƕ���դ���ļ���ʽ�Ľ������ࡣ
//! \remarks �����й�դ���ļ����������ʽ���඼����̳д��ࡣ
class FILEPARSER_API UGFileParseRaster : public UGFileParser  
{
	//������ʽ 
	enum EmSamplingPattern
	{
		NONE             = 0, 
		NEAREST          = 1,  
		AVERAGE          = 2,
		GAUSS            = 3,
		AVERAGE_MAGPHASE = 4
	};

public:

	//! \brief ���캯����
	UGFileParseRaster();	

	//! \brief ����������
	virtual ~UGFileParseRaster();
	
public:	

	virtual UGFileType::EmGroup GetFileGroup() const;
	
	////////////////////////////////////////////////////////////////////////
	//
	// ���û�������
	//
	////////////////////////////////////////////////////////////////////////
	//! \brief ����Ӱ�������  ֧�������ʽ    ע:�˷���������Ӱ������
	//! \return �����Ƿ񴴽��������Ƿ�ɹ���
	//! \remarks �����ERDAS��IMG�ļ�����ϣ����ArcMapһ��������ҵ�rrd�ļ�
	//! �������ڵ�������ò��GDAL 1.6����֧�֣�����ͨ���ı�����������޸ģ�
	//! ���Ƿ��������ã�Ѱ���µĽ��֮����
	virtual UGbool BuildPyramid(UGbool bShhowProgress = FALSE);

	//! \brief ����Ӱ���ȡ�
	//! \return ͼ��Ŀ�
	virtual UGint GetWidth() const;	

	//! \brief ����Ӱ��߶ȡ�
	virtual UGint GetHeight() const;	


	//! \brief �Ƿ���ɨ���д�����
	//! \return �ж��Ƿ���ɨ���С�
	virtual UGbool IsScanline() const;	
	
	//! \brief �Ƿ��ǰ����صķ�ʽ��ȡ
	//! \return �ж��Ƿ������ض�ȡ��ʽ��
	virtual UGbool IsReadPixel() const;


	//! \brief ��ȡ�洢Ӱ��ֿ�Ŀ����ص�λ����
	//! \return �������ص�λ��Ӱ��ֿ�Ŀ�
	virtual UGint GetBlockWidth() const;	

	//! \brief ��ȡ�洢Ӱ��ֿ�ĸߣ����ص�λ����
	//! \return �������ص�λ��Ӱ��ֿ�ĸߡ�
	virtual UGint GetBlockHeight() const;
	

	//! \brief ��ȡ�����block������
	//! \return ���غ���block����
	virtual UGint GetColBlocks() const;	

	//! \brief ��ȡ�����block������
	//! \return ��������block������
	virtual UGint GetRowBlocks() const;	
	
	//! \brief �õ�Ŀ��Ӱ�����ݵĻ�����Ϣ��
	RasterInfo GetRasterInfo() const {return m_tarInfo;}	
	
	//! \brief �õ�ԭʼӰ�����ݵĻ�����Ϣ
	RasterInfo GetSrcRasterInfo() const {return m_srcInfo;}	
	
	//! \brief �õ�Ŀ��Ӱ�����ݵĻ�����Ϣ�����á�
	RasterInfo& GetRasterInfoRef() {return m_tarInfo;}	

	//! \brief �õ��Ƿ���Ե���ɺϳɲ��Ρ�
	UGbool GetForceAsOneBand() {return m_bForceAsOneBand;}	

	void SetDTName(const UGString strDTName){m_tarInfo.m_strDTName = strDTName;}
	
	//! \brief �õ�Ŀ��Ӱ�����ݵĻ�����Ϣ���ϡ�
	virtual RasterInfos GetRasterInfos();

	//! \brief �õ�ԭʼӰ�����ݵĻ�����Ϣ���ϡ�
	virtual RasterInfos GetSrcRasterInfos();

	//##ModelId=482030540261
	//! \brief �Ƿ���Ҫ���·���
	//! \return �����Ƿ���Ҫ���·���
	//! \remarks ���ǵ�ͼƬ��ԭ�������Ͻ� �����ֵ�Tga���ݵ�ԭ�����������µġ�
	virtual UGbool IsReverseReadOrWrite() const {return FALSE;}

	//////////////////////////////////////////////////////////////////////////
	// �������
	//////////////////////////////////////////////////////////////////////////

	//! \brief �Ƿ�ನ��
	virtual UGbool IsMultiBand() const;

	//! \brief �õ����εĸ�����
	//! \return ���ز��εĸ�����
	virtual UGint GetBandCount() const;	

	//! \brief ��ȡ������Ϣ�б�
	//! \param bandInfos  Ҫ����Ĳ�����Ϣ�б�[out]
	//! \attention ����ನ��ʱ�á�
	virtual UGbool GetBandInfos(UGArray<BandInfo>& bandInfos);

	//! \brief ���ò�����Ϣ��ȥ������ȡ������Ϣ
    //UGbool  SetBandInfos(UGArray<BandInfo>& bandInfos);

	//===================================================
	//! \brief  ��ȡ���������ݼ���Ϣ�б�
	//! \param  rasterInfos[out]Ҫ����Ľ�������Ϣ�����б�
	//! \return   
	//! \remarks 
	//! \attention ����ನ��ʱ�á�
	virtual UGbool GetPyramidInfos(UGArray<PyramidInfo>& pyramidInfos);

	///////////////////////////////////////////////////
	// ����������
	///////////////////////////////////////////////////

	//! \brief �������ص���ȡ�
	//! \param  [in]��
	//! \return ����ͼ�����ȡ�
	//! \remarks ͼ����ȱ�ʾ��������λ����
	virtual UGPixelFormat GetPixelFormat() const;	

	//////////////////////////////////////////////////
	// ��ɫ��/��ɫ�ռ��ʽ���
	//////////////////////////////////////////////////	

	//! \brief ��ȡդ���ɫ�ʿռ��ʽ��
	//! \param  [in]��
	//! \return ����դ���ɫ�ʿռ��ʽ��
	//! \remarks �ֳ�RGB,RGBA,CMY,CMYK,YIQ,YUV,YCC��
	virtual ImgColorSpace GetImgColorSpace();	

	//! \brief ת��դ���ɫ�ʿռ��ʽ��
	//! \param nImgColorSpace Ҫ���õ�ɫ�ʿռ�[in]��
	//! \remarks �ֳ�RGB,RGBA,CMY,CMYK,YIQ,YUV,YCC��ͨ��ת����ʽ�����е���ɫģʽת���ɶ�Ӧ����ɫģʽ
	virtual void ConvertColorSpace(ImgColorSpace nImgColorSpace);

	//! \brief ���õ�ɫ�塣
	//! \param Palette  Ҫ���õ���ɫ��[in]
	//! \return ������ɫ��
	virtual void SetColorset(const UGColorset& Palette);	

	//! \brief �õ���ɫ�塣
	//! \return ������ɫ��
	virtual UGbool GetColorset(UGColorset& Palette) const;	

	////////////////////////////////////////////////////////
	// �������
	////////////////////////////////////////////////////////

	//! \brief �õ�Ӱ���Bounds(�пռ䷶Χ�����ؿռ䷶Χ��û�пռ䷶Χ������ͼ�񳤿�Χ)��
	//! \return ����Ӱ���Ľǵ����귶Χ��
	virtual UGRect2D GetBounds() const;	

	//! \brief ��ȡ�ռ�ο���
	virtual const UGPrjCoordSys* GetSpatialRef() const;

	////////////////////////////////////////////////////////
	// ��Чֵ���
	////////////////////////////////////////////////////////
	
	//##ModelId=482030540261
	//! \brief ��ȡ��Чֵ��
	//! \param  [in]��
	//! \return ������Чֵ��
	//! \remarks ���û����Чֵ����ô���صġ�
	virtual UGbool GetNoValue(UGNoValue& nodata) const;

	/////////////////////////////////////////////////////////
	// ���Ա����
	/////////////////////////////////////////////////////////
	//! \brief ��ȡ���Ա�
	//! \param table  Ҫ���ص�դ�����Ա�[out]
	//! \param iBand  �鿴�ڼ���������û�����Ա���Ϣ��[in]
	virtual UGbool GetAttributeTable(UGRasterAttributeTable& table, UGint iBand=BAND_FIRST_INDEX);	

	//! \brief �������Ա�
	//! \param table  դ������Ա�[in]
	//! \param iBand  �鿴�ڼ���������û�����Ա���Ϣ��[in]
	//! \remarks ���Ա�Ӧ�����ⲿ�������á�
	virtual void SetAttributeTable(const UGRasterAttributeTable& table, UGint iBand=BAND_FIRST_INDEX);	
	
	/////////////////////////////////////////////////////////
	// �洢���
	/////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//////////////////////////////////////////////////////////////////////////
	//! \brief ׼����ʼ��ȡդ������,�ڵ���ReadData֮ǰ�������
	//! \param 1 [in] �ӵڼ��п�ʼ��
	virtual UGbool BeginRead(UGint nIndex = 1)	;

	//! \brief ׼��һ��ɨ���е�����
	//! \param imgScanline ɨ�������ݡ�[out]
	//! \return �Ƿ�ɹ���
	virtual UGbool PrepareScanLine(UGImgScanline& imgScanline);

	//! \brief ׼��һ����Ƭ������
	//! \param imgScanline ��Ƭ���ݡ�[out]
	//! \return �Ƿ�ɹ���
	virtual UGbool PrepareBlock(UGImgBlock& imgBlock);

	//! \brief ��ȡDEM��GRID���ݵĸ߳�ֵ
	//! \param nRowPixIndex �̵߳ĵڼ����С�[in]
	//! \param nColPixIndex �̵߳ĵڼ����С�[in]
	//! \param dValue	�߳�ֵ��[out]
	//! \param nBand=0  �ڼ������� [in]��
	//! \attention ע�⣺Ŀǰֻ��DEM��GRID�������ǰ��д洢ʱʹ�á�
	virtual UGbool ReadGridValue(UGint nRowPixIndex, UGint nColPixIndex, UGdouble& dValue, UGint nBand=0) {return FALSE;}
	
	//! \brief ��ȡһ��ɨ���е����ݣ��ڸú����У�imgScanline�������ʹ�С�����з��䣬׼������ȫ����PrepareScanLine��������
	//! \param imgScanline ɨ�������ݡ�[out]
	//! \param nRowIndex  �ڼ���ɨ���С�[in]
	//! \param nBand=0 [in]�ڼ������ε�ɨ���С�
	//! \param nColIndex[in]�ӵڼ��п�ʼɨ��
	virtual UGbool ReadScanLine(UGImgScanline& imgScanline, UGint nRowIndex, UGint nBand=0, UGint nColIndex=0)	{return FALSE;}


	//! \brief ��ȡһ��������ָ����2��֮������ݣ�imgScanline�������ʹ�С���ں����ڲ����·��䣬����ʱ����Ҫ���κι�����
	//! param  imgScanline [out] nColEnd-nColStartֱ�ӵ�����
	//! param  nRowIndex   [in]  �ڼ���
	//! param  lColStart   [in]  ��ʼ��
	//! param  lColEnd     [in]  ��ֹ��
	//! param  nBand       [in]  �ڼ�������
	virtual UGbool ReadScanLine(UGImgScanline& imgScanline, UGint nRowIndex, UGlong nColStart, UGlong nColEnd, UGint nBand)	{return FALSE;}
	
	//! \brief ��ȡһ��Block����
	//! \param pImgBlock ���ض�ȡ��block���ݡ�[out]
	//! \param nRowBlockIndex Ҫ��ȡ��block���ڵڼ��С�[in]
	//! \param nColBlockIndex Ҫ��ȡ��block���ڵڼ��С�[in]
	//! \param nBand=0 Ҫ��ȡ�ڼ������ε�block��[in]
	//! \return ��ȡ�Ƿ�ɹ���
	virtual UGbool ReadBlock(UGImgBlock& pImgBlock, UGint nRowBlockIndex, UGint nColBlockIndex, UGint nBand=0)	{return FALSE;}
	
	// ��ȡ��֡Ӱ������ [6/10/2011 ������]
	//! \brief ��ȡӰ�����ݸ�֡���ݣ���̬������
	//! \param strGifFile [in] �ļ�·����
	//! \param arrPicture [out] ����Ӱ�����ݡ�
	//! \param ͼ�������Ƿ�ת��
	//! \return �Ƿ��ȡ�ɹ���
	virtual UGbool GetDynamicIMGData(const UGString& strFile, UGArray<UGGeoPicture*>& arrPicture,UGbool bReverse){return FALSE;}


	// �����֡Ӱ������
	//! \brief ����Ӱ�����ݸ�֡���ݣ���̬������
	//! \param strGifFile [in] �ļ�·����
	//! \param arrPicture [in] ������Ϣ��
	//! \return �Ƿ񱣴�ɹ���
	virtual UGbool SetDynamicIMGData(const UGString& strFile,UGTextureDataAnimation *pTextureDataAnimation){return FALSE;}


	//! \brief ������ȡդ������,�ڵ���ReadData֮��������(�ͷŶ���)
	virtual void EndRead();

	//////////////////////////////////////////////////////////////////////////
	// ���������صĺ��� 
	//////////////////////////////////////////////////////////////////////////
	//! \brief �Ƿ���ڽ������ļ�
	virtual UGbool IsExistPyramid();

	//! \brief ��ȡ�������ĸ���
	//! \�õ��ڼ����εĽ������ĸ���
	virtual UGint GetPyramidCount(UGint nBand);

	//! \brief �õ��ض����ε��ض����������ض��������
	//! \param pDataBuffer Ҫ��ŵ�����
	//! \param nSize ���ݵĴ�С ��GetPyramidBlockSizeȷ��
	//! \param nBandĳ������
	//! \param nTierIndex����������
	//! \param nXBlock���Xλ��
	//! \param nYBlock���Yλ��
	virtual UGbool GetPyramidBlockData(unsigned char* pDataBuffer, UGint nSize, UGint nBand, UGint nTierIndex, UGint nXBlock, UGint nYBlock);

    
	//! \brief �õ��ض����ε��ض�λ�õ�����
	//! \param pDataBuffer Ҫ��ŵ�����
	//! \param nSize ���ݵĴ�С
    //! \parma nBand ��������
	//! \param xBlock ���к�
	//! \param YBlock ���к�
	virtual UGbool GetRawRasterData(void * pDataBuffer,UGRect rectView,UGint nBandIndex);
	
	//! brief �õ���ʾ�ý�����ʱ����������Ҫ���ڴ��С(�ֽ�)
	//! param nBand ����
	//! param nTierIndex ����������
	virtual UGint GetPyramidBlockSize(UGint nBand, UGint nTierIndex){return 0;}
	
	//! brief �õ�һ���������д洢����ܸ���
	//! param nBand ����
	//! param nTierIndex ����������
	virtual UGint GetPyramidBlockCount(UGint nBand, UGint nTierIndex){return 0;}

	//! brief �õ��������ĳ���
	//! nBand ����
	//! nTierIndex ����������
	//! nWidth �������Ŀ�
	//! nHeight �������ĸ�
	virtual void GetPyramidSize(UGint nBand, UGint nTierIndex, UGint &nWidth, UGint &nHeight);

	//! brief �õ���������ÿ�д洢�Ŀ�ĸ���
	//! param nBand ����
	//! param nTierIndex ����������
	virtual UGint GetPyramidBlocksPerRow(UGint nBand, UGint nTierIndex);

	//! brief �õ���������ÿ�д洢�Ŀ�ĸ���
	//! param nBand ����
	//! param nTierIndex ����������
	virtual UGint GetPyramidBlocksPerColumn(UGint nBand, UGint nTierIndex);

	//! brief �õ��������п�ĳ���(�ֽ�)
	//! param nBand ����
	//! param nTierIndex ����������
	virtual UGint GetPyramidBlockXSize(UGint nBand, UGint nTierIndex);

	//! brief �õ��������п�ĸ߶�(�ֽ�)
	//! param nBand ����
	//! param nTierIndex ����������
	virtual UGint GetPyramidBlockYSize(UGint nBand, UGint nTierIndex);

	//! brief  �õ���������һ���м�������
	//! return ����������
	virtual UGint GetPyramidBandCount();

	//! brief�õ�Img�ļ��ĵ���Χ
	//! param ImgBounds ���ܵĵ���Χ
	virtual UGbool GetImgBounds(UGRect2D &ImgBounds){return FALSE;}

	//! brief �õ��������ļ������ظ�ʽ
	//! remarks ������HFA����һ��3�����ں�Ϊһ�����εĹ��̣�������
	//! ������֧������ںϵĹ�������Ҫ�õ�ԭʼͼ������ظ�ʽ
	virtual UGPixelFormat GetPyramidPixelFormat();

	//! brief �õ����������ظ�ʽ�õ�λ��
	//! remark ��HFA��õ�����һƬ���ݣ��ڴ�HFA�еõ�һƬ����ʱҪ�õ�
	virtual UGint GetDataTypeBits();

	//! brief ��ʼ����������Ϣ
	//! param nBand ����
	//! param nTierIndex ����������
	virtual UGbool InitPyramidInfo();

	virtual UGint GetSamplingPattern() const;

	virtual void SetSamplingPattern(const UGint nSampling);
	//////////////////////////////////////////////////////////////////////////
	// д�뺯��
	//////////////////////////////////////////////////////////////////////////
	
	virtual void SetBandGetTileFunc(BandGetTileFunc pFunc, UGlong pWnd){return ;}
	
	//! \brief ����һ���ⲿ�����ļ��Ա㵼����
	//! \param info  Ҫ������դ��Ļ������ԡ�[in]
	//! \param exchangeParams  ����������[in]
	//! \return �Ƿ�ɹ���
	//! \remarks �������ǰ�󶼲��ܵ���Open��
	virtual UGbool Create(const RasterInfo& info, const UGExportParams& exchangeParams) = 0;
	
	//! \brief ׼����ʼд����,�ڵ���WriteData֮ǰ�������
	//! \return �Ƿ�ɹ���
	virtual UGbool BeginWrite();
	
	//! \brief д��һ��ɨ���е�����
	//! \param imgScanline  Ҫд������ݡ�[in]
	//! \param nRowIndex  �ڼ���ɨ���С�[in]
	//! \param 0  ��ɨ����д��ڼ������Ρ�[in]
	//! \return �Ƿ�ɹ���
	virtual UGbool WriteScanLine(const UGImgScanline& imgScanline, UGint nRowIndex, UGint nBandIndex = 0)	{return FALSE;};
	
	//! \brief д��һ����Ƭ���ݡ�
	//! \param pImgBlock  д�����Ƭ���ݡ�[in]
	//! \param nRowBlockIndex  �ڼ��е���Ƭ��[in]
	//! \param nColBlockIndex  �ڼ��е���Ƭ��[in]
	//! \param nBandIndex  �ڼ����ε���Ƭ��[in]
	//! \return �Ƿ�ɹ���
	virtual UGbool WriteBlock(const UGImgBlock& pImgBlock, UGint nRowBlockIndex, UGint nColBlockIndex, UGint nBandIndex = 0) 	{return FALSE;};
	
	//! \brief ����д����,�ڵ���WriteData֮��������
	virtual void EndWrite();
	
	
	//! \brief �ر����ݡ�
	virtual void Close();


	//! \brief ��ȡӰ�����ݵ�һЩͳ����Ϣ
	//! \param statiInfoMngr [in] ��Ҫ��ȡ��ͳ����Ϣ
	//! \param statiInfoMngr [out] ͼ���ͳ����Ϣ
	//! \remarks �ڵ����������֮ǰ��RasterStaticsticInfoMngr��Ҫ���úó�ԱbNeedXXX,������Ҫ��ȡ��Щͳ����Ϣ
	virtual UGbool GetStatisticInfos(RasterStatisticInfoMngr &statiInfoMngr);

	//===================================================
	//! \brief  ��ȡ�������ֵ
	//! \param  nBandIndex ����������ֵ
	//! \return ���ض�Ӧ���ε������ֵ
	virtual UGdouble GetMax(UGint nBandIndex);

	//===================================================
	//! \brief  ��ȡ������Сֵ
	//! \param  nBandIndex ����������ֵ
	//! \return ���ض�Ӧ���ε���С��ֵ
	virtual UGdouble GetMin(UGint nBandIndex);

	//===================================================
	//! \brief  ��ȡ��Ӧ���ε������Сֵ
	//! \param  nBandIndex[I] ��������ֵ
	//! \param  dMin[O]       ��Сֵ 
	//! \param  dMax[O]       ���ֵ
	//! \return   
	//! \remarks �˽ӿڷ��ؾ��岨�εļ�ֵ
	//! \attention
	virtual UGbool GetMaxMin(UGint nBandIndex,UGdouble &dMin,UGdouble &dMax);

	//===================================================
	//! \brief  �õ�դ����Ϣ
	//! \param 
	//! \return   
	//! \remarks 
	//! \attention
	virtual RasterStatisticInfo* GetStatisticsInfo(UGint nBandIndex);

	//===================================================
	//! \brief  ͳ��դ����Ϣ
	//! \param 
	//! \return   
	//! \remarks 
	//! \attention
	virtual RasterStatisticInfo* BuildStatistic(UGint nBandIndex);

	//===================================================
	//! \brief  ��ȡͳ��ֱ��ͼ
	//! \param  dMin[I]       ��Сֵ
	//! \param  dMax[I]       ���ֵ
	//! \param  nBandIndex[I] ��������
	//! \param  nBuckets[I]   ��������ͼ�ֵ��ͬ��������
	//! \return   
	//! \remarks ����ֱ��ͼ��Ϣ
	//! \attention
	virtual UGHistogram* GetHistogram(
		UGdouble dMin, 
		UGdouble dMax,
		UGint nBandIndex = 0,
		UGint nBuckets = 256);

	//! \brief �������ͺ��ļ�����ȡImageData����������Сʱʹ�ã�����������Ƭ����
	//! \param strFilePath[in] �ļ�·��
	//! \return ���ݵ�ImageData
	virtual UGImageData* LoadImageData(const UGString& strFilePath){return NULL;}

	//! \brief �����ڴ�����ȡImageData����������Сʱʹ�ã�����������Ƭ����
	//! \param ImageBytes[in] �ļ��ڴ���
	//! \return ���ݵ�ImageData
	virtual UGImageData* LoadImageData(const UGByteArray& ImageBytes){return NULL;}

	//! \brief ���UGImageData���ݵ��ڴ�(���׽ӿڣ���������С��ʱ��ʹ�ã������������Ƭʹ��)��
	//! \param ImageBytes [inout] ͼƬ������ڴ�����
	//! \param nfileType [in] Ҫ�����Image���͡�
	//! \param imageData [in] Ҫ�����Image���ݡ�
	//! \param bIsSavaAs8Bit [in] �Ƿ���8λͼƬ(��ʱֻ֧��png)��
	//! \return ����ת�����ͼ������
	//! \attention imageData.pBits ����Ϊ�ա�
	virtual UGbool SaveImageDataToMemory(UGByteArray& ImageBytes, UGint nfileType, const UGImageData* pImageData, UGbool bTransparentBack = FALSE, UGColor cTransColor = UGRGB(1, 2, 3), UGint nQuality = 75, UGbool bIsSavaAs8Bit = false, UGint ndpi = 96){return false;}

protected:

	UGint RePrepareBlock(UGImgBlock& imgBlock, UGint nRowBlockIndex, UGint nColBlockIndex, UGint nBand);

	void ModifyTargetInfo(UGbool bIsImportAsOneBand);
	
protected:
	
	/*! brief  ע��դ��ṹ�ϵ��ش����  modified by jiangrs 2012/10/11
	**************************************************
	���������ڴ�դ������ʱ���ߵ���Ϣ�ı���ԭʼ��դ����Ϣ
	(��3����8λ�����1����24λ)
	���û���Ҫ֪��ԭʼ��դ����Ϣ & ��ֱ�Ӵ�Ӱ��ʱ���������ʱҲ��Ҫ֪��ԭʼ��դ����Ϣ
	�ʵ���Ϊ��
	�޸� m_info ----> m_tarInfo   
	���� m_srcInfo
	���� m_bForceAsOneBand 
	�޸� GetRasterInfo()��GetRasterInfoRef() ����ֵm_info ----> m_tarInfo
	���� GetSrcRasterInfo() ����ֵ m_srcInfo
	*/

	UGString m_strFilePath;
	//! \brief �Ƿ��н����� 
	UGbool m_bHasPyramid;
	//! \brief դ��Ļ�����Ϣ(ͨ���û������Ĳ���(ImportParms)���ɵ�)
	RasterInfo m_tarInfo;
	//! \brief դ��Ļ�����Ϣ(ԭʼ��)
	RasterInfo m_srcInfo;
	//! brief ��������Ϣ
	UGArray<PyramidInfo> m_PyramidInfos;
	//! \brief ����Ϊ3���Σ�ÿ����8λʱ�����԰���24λ�����ε��루RGB��
	//         ����Ϊ4���Σ�ÿ����8λʱ�����԰���32Ϊ�����ε��루RGBA��
	//         jpgʱ���ڲ����뵥����
	//! \brief �Ƿ��ܹ��ϳ�Ϊһ������
	//! \remarks ��ÿ���������Openʱά���� 
	//! \remarks �ڵ���ʱ���ж�����û��Ǻϳɲ��� ���˲���ΪFALSE �򲻻���е���
	UGbool m_bForceAsOneBand;
	

	//! brief ������ʽ
	UGString m_strSampling;

public:

	//! \brief ͨ�������õ�Դ�����е�һ�����ݼ���
	//! \param nlayer [in]��
	virtual UGFileLayer* GetLayer(UGint nlayer);

	//! \brief �����ļ����ơ�
	virtual void SetFilePath(const UGString& strFilePath);	

private:

	//===================================================
	//! \brief  ��դ��ͳ����Ϣ���浽XML
	//! \param 
	//! \return   
	//! \remarks 
	//! \attention
	UGString StatisticsInfosToXML(const RasterStatisticInfo &statisticInfo, UGint nBandIndex);

	//===================================================
	//! \brief  ��XML�ж���դ��ͳ����Ϣ
	//! \param  strXML[in]
	//! \return   
	//! \remarks 
	//! \attention
	RasterStatisticInfo* StatisticsInfosFromXML(const UGString &strXML, UGint nBandIndex);

	//===================================================
	//! \brief  ���漫ֵ��XML�ļ�
	//! \param  nBandIndex[I] ��������
	//! \param  dMin[O]       ��Сֵ
	//! \param  dMax[O]       ���ֵ
	//! \return   
	//! \remarks 
	//! \attention
	UGString ExtremumToXML(UGint nBandIndex,UGdouble &dMin, UGdouble &dMax);

	//===================================================
	//! \brief  ��XML�л�ȡ��ֵ
	//! \param  strXML[I] XML·��
	//! \param  dMin[I]   ��Сֵ
	//! \param  dMax[I]   ���ֵ
	//! \return ��ȡ�ɹ�����true 
	//! \remarks 
	//! \attention
	UGbool ExtremumFromXML(UGint nBandIndex, const UGString &strXML, UGdouble &dMin, UGdouble &dMax);

	//===================================================
	//! \brief  ���㼫ֵ
	//! \param 
	//! \return   
	//! \remarks 
	//! \attention
    UGbool ComputeExtremum(UGint nBandIndex, UGdouble &dMin, UGdouble &dMax);

	//===================================================
	//! \brief  ����ֱ��ͼ��Ϣ��XML
	//! \param  nBandIndex[I] ��������
	//! \param  histogram[I]  ֱ��ͼ��Ϣ
	//! \return   
	//! \remarks 
	//! \attention
	UGString HistogramToXML(UGdouble dMin, UGdouble dMax, UGint nBuckets, UGint nBandIndex, OgdcHistogram &histogram);

	//===================================================
	//! \brief  ��XML�л�ȡֱ��ͼ��Ϣ
	//! \param  strXML[I]    XML·��
	//! \param  histogram[O] ֱ��ͼ��Ϣ
	//! \return ��ȡ�ɹ�����true  
	//! \remarks 
	//! \attention
	UGbool HistogramFromXML(UGdouble dMin, UGdouble dMax, UGint nBuckets,UGint nBandIndex, const UGString &strXML, OgdcHistogram &histogram);

	//===================================================
	//! \brief  ����ͳ��ֱ��ͼ
	//! \param 
	//! \return   
	//! \remarks 
	//! \attention
	virtual UGbool ComputeHistogram(
		UGHistogram &histogram, 
		UGdouble dMin, 
		UGdouble dMax,
		UGint nBandIndex = 0,
		UGint nBuckets = 256);

private:

	UGRasterFileLayer* m_layer;

	UGMutex m_mutex;

	void*  m_hDataset;
};

} //namespace UGC

#endif // !defined(AFX_UGFileParseRaster_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_)

