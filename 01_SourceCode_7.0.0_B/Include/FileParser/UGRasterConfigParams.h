// UGRasterImportParams.h: interface for the UGRasterImportParams class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGRASTERIMPORTPARAMS_H__AFD927F6_BD78_470E_B1FA_56EF86E30E91__INCLUDED_)
#define AFX_UGRASTERIMPORTPARAMS_H__AFD927F6_BD78_470E_B1FA_56EF86E30E91__INCLUDED_


#include "Stream/ugexports.h"
#include "FileParser/UGFileParserConfigParams.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


namespace UGC 
{
	typedef UGdouble UGNoValue;
	typedef OGDC::PixelFormat UGPixelFormat;

	//! \brief ���εĻ�����Ϣ��
	class FILEPARSER_API UGRasterBandInfo
	{
	public:

		//! \brief ���캯����
		UGRasterBandInfo()
		{
			m_nBandID =-1;
			m_nIndex =-1;
			m_nDatasetID=-1;
			m_bAvail = FALSE;
			m_ePixelFormat =IPF_UNKNOWN;
			m_nWidthBytes = 0;
			m_nOptions =0;
			m_nCodecType = UGDataCodec::encNONE;
			m_dMinZ = (1.0e+21);
			m_dMaxZ = -(1.0e+21);
			m_dbNoValue = -9999;
			m_nScalar = 0;
			m_bHasExtremum = FALSE;
		}

		//! \brief ��������
		~UGRasterBandInfo()
		{
		}


		//! \brief �Ⱥſ���������
		//! \param bInfo [in]��
		void operator=(const UGRasterBandInfo& bInfo)	
		{
			m_nIndex = bInfo.m_nIndex;
			m_nBandID = bInfo.m_nBandID;
			m_ePixelFormat = bInfo.m_ePixelFormat;
			m_nCodecType = bInfo.m_nCodecType;
			m_nOptions = bInfo.m_nOptions;
			m_nWidthBytes = bInfo.m_nWidthBytes;
			m_dMaxZ = bInfo.m_dMaxZ;
			m_dMinZ = bInfo.m_dMinZ;
			m_Colorset.RemoveAll();
			m_Colorset.Copy(bInfo.m_Colorset);
			m_strName = bInfo.m_strName;	
			if(bInfo.m_strFieldName.IsEmpty())
			{
				m_strFieldName = bInfo.m_strName;
			}
			else
			{
				m_strFieldName = bInfo.m_strFieldName;
			}
			m_dbNoValue = bInfo.m_dbNoValue;
			m_nWidthBytes = bInfo.m_nWidthBytes;
			m_nDatasetID = bInfo.m_nDatasetID;
			m_bAvail = bInfo.m_bAvail;
			m_nScalar = bInfo.m_nScalar;
			m_strDescription = bInfo.m_strDescription;
			m_bHasExtremum = bInfo.m_bHasExtremum;
		}

		//! \brief �������ݿ�������
		UGint m_nBandID;
		//! \brief ��������
		UGint m_nIndex;
		//! \brief �������ڵ����ݼ�ID
		UGint m_nDatasetID;
		//! \brief ���ε�����
		UGString m_strName;
		//! \brief �������ڵ�����
		UGString m_strFieldName;
		//! \brief ��ǰ�����Ƿ���Ч
		UGbool m_bAvail;
		//! \brief ���ε�������Ϣ
		UGString m_strDescription;
		//! \brief ���ε����ظ�ʽ
		UGPixelFormat m_ePixelFormat;
		//! \brief ���ε�Ӱ�����ֽ���
		UGint m_nWidthBytes;
		//! \brief ѡ����Ϣ
		UGint m_nOptions;
		//! \brief ���ݱ�������
		UGDataCodec::CodecType m_nCodecType;
		//! \brief ��άBounds����Сֵ
		UGdouble m_dMinZ;
		//! \brief ��άBounds�����ֵ
		UGdouble m_dMaxZ;
		//! \brief ��ɫ��
		UGColorset m_Colorset;
		//! \brief ��Чֵ�����ĳһ���ֵ��m_NoValue,����Ϊ��һ��û��ֵ
		UGdouble m_dbNoValue;
		//! \brief ���blockSize
		UGint m_nMaxBlockSize;
		//! \brief ��ǰ���η��� FALSE �޷��ţ�TRUE �з���
		UGint m_nScalar;

		//! \brief �Ƿ��Ѿ������˼�ֵ
		UGbool m_bHasExtremum;
	};

	typedef UGRasterBandInfo BandInfo;

	//! \brief ����դ��Ļ�����Ϣ��
	class FILEPARSER_API RasterInfo
	{
	public:
		//! \brief 	Ӱ��Ŀ�
		UGint m_nWidth;
		//! \brief 	Ӱ��ĸ�
		UGint m_nHeight;
		//! \brief 	Ӱ������ظ�ʽ
		UGPixelFormat m_ePixelFormat;//UGint m_nPixelFormat;

		//! \brief 	Ӱ��Ĳ��θ���
		UGint m_nBandCount;	
		//! \brief 	�Ƿ�ನ�εı�־
		UGbool m_bIsMultiBand;	
		//! \brief 	�Ƿ���ɨ���У������ǿ�״��
		UGbool m_bIsScanline;
		//! \brief 	�Ƿ��ǰ����ط�ʽ��ȡ
		UGbool m_bIsReadPixel;

		//! \brief Ӱ���Bounds
		UGRect2D m_rc2Bounds;

		//! \brief block�ߡ�
		UGint m_nBlockHeight;
		//! \brief block��
		UGint m_nBlockWidth;

		//! \brief �Ƿ���ɨ����ƫ�ƣ�Ĭ��ΪFalse��FME����ʱΪTRUE
		UGbool m_bColOffset;

		//! \brief ������Ϣ������Ƕನ�εĻ���
		UGArray<BandInfo> m_arrBandInfos;

		//! \brief Ŀ�����ݼ�����
		UGString m_strDTName;

		//! \brief դ����������SDE��ʹ�ã�����Ĭ��Ϊ0��
		UGint m_nIndex;

	public:

		//! \brief ���캯����
		RasterInfo();

		//! \brief �������캯����
		RasterInfo(const RasterInfo& rInfo);

		//! \brief ����������
		virtual ~RasterInfo();

		//! \brief ���������Ϣ�ָ�Ĭ��ֵ��
		void Clear();

		//! \brief ���ؿ����Ⱥš�
		void operator=(const RasterInfo& rInfo);

		//! \brief Ӱ�����ɫ�ռ䡣
		ImgColorSpace GetImgColorSpace() { return m_colorSpace;};	

		//! \brief ����Ӱ�����ɫ�ռ䡣
		//! \param cs  ��Ҫ���õ���ɫ�ռ䡣[in]
		void SetImgColorSpace(ImgColorSpace cs) {m_colorSpace = cs;}	

		//! \brief ������ɫ��
		//! \param cs �µ���ɫ��[in]
		void SetColorset(const UGColorset& cs);

		//! \brief �����ɫ���ж�������ɫ��ʱ���ط񣩡�
		void ResetColorset();

		//! \brief �ж��Ƿ�����ɫ��
		UGbool HasColorset() const {return m_bHasColorset;}

		//! \brief ��ȡ��ɫ��
		//! \return ���û�У����ؿ�ָ�롣
		const UGColorset* const GetColorset() const;

		//! \brief �ж��Ƿ���NoData��
		UGbool HasNoValue() const{return m_bHasNoValue;}

		//! \brief ����Nodata��
		void SetNoValue(UGdouble noValue)	
		{
			m_bHasNoValue = TRUE;
			m_dNoValue = noValue;
		}

		//! \brief ���Nodata��ʹ�䲻���ڣ���
		void ResetNoValue()	{m_bHasNoValue = FALSE;}

		//! \brief ��ȡNodata��
		const UGNoValue* GetNoValue() const;

		//! \brief ��ȡX����ֱ��ʡ�
		UGdouble GetResoulutionX() const { return m_rc2Bounds.Width() / m_nWidth; }

		//! \brief ��ȡY����ֱ��ʡ�
		UGdouble GetResoulutionY() const { return m_rc2Bounds.Height() / m_nHeight; }

		//! \brief �ж��Ƿ��пռ�ο���
		UGbool HasPrjCoordSys() const {return m_bHasPrjCoordSys;}

		//! \brief ���ÿռ�ο���
		void SetPrjCoordSys(const UGPrjCoordSys& prj);

		//! \brief ��տռ�ο�(ʹ����)��
		void ResetPrjCoordSys()	{m_bHasPrjCoordSys = FALSE;}

		//! \brief ��ȡ�ռ�ο���
		const UGPrjCoordSys* GetPrjCoordSys() const;

		//! \brief ��ȡӰ�����ݱ�������
		UGDataCodec::CodecType GetEncodeType() const {return m_enType;}

		//! \brief ����Ӱ�����ݵı�������
		void SetEncodeType(UGDataCodec::CodecType nType){m_enType = nType;}

	protected:

		//! \brief ��ɫ�ռ䡣
		ImgColorSpace m_colorSpace;

		//! \brief 	Ӱ��ĵ�ɫ��
		UGColorset m_colorset;

		//! \brief 	�Ƿ����ɫ��
		UGbool m_bHasColorset;

		//! \brief ��Чֵ
		UGNoValue m_dNoValue;

		//! \brief �Ƿ�����Чֵ��
		UGbool m_bHasNoValue;

		//! \brief �Ƿ�������ϵͳ��
		UGbool m_bHasPrjCoordSys;

		//! \brief ͶӰ����ϵ��
		UGPrjCoordSys *m_prjSys;

		//! \brief Ӱ������ݱ�������
		UGDataCodec::CodecType m_enType;

	};

	//! \brief ����դ��Ļ�����Ϣ���ϡ�
	class FILEPARSER_API RasterInfos:public UGArray<RasterInfo>
	{
	public:
		RasterInfos();

		virtual ~RasterInfos();
	};

	typedef UGArray<BandInfo> BandInfos; 

	//! \brief դ��������ࡣ
	class FILEPARSER_API UGRasterImportParams : public UGImportParams
	{
		friend class UGWorkspaceImportParams;
	public:
        
		// !\brief ���õ���ʱ�������ɫ��ģʽ
		// 0: ��������ɫ
		// 1: ���յ�һ��ɫ����
		// 2: ����ɨ���ߵķ�ʽ����
		enum IgnoreMode
		{
			IgnoreNull =0,
			IgnoreSignal =1,
			IgnoreBorder =2,
		};

		//! \brief ���캯����
		UGRasterImportParams();

		//! \brief ����������
		virtual ~UGRasterImportParams();

	public:

		//! \brief ���ö�ȡͼ��ʱ���Ƿ���Ϊ���ǵ����εġ�
		//! \param TRUE [in]��
		//! \remarks �磺3����ÿ����8λ�����ݣ����ô˲�������ͼ�񽫱���Ϊ��һ��24��GRB�����ݡ�
		void SetReadAsOneBand(UGbool bAsOneBand = TRUE);	

		UGbool GetReadAsOneBand() const;	

		//! \brief �����Ƿ���Ϊ�ನ�����ݼ���
		//! \param bAsMultiBands [in]��
		void SetImportAsMultiBandsDataset(UGbool bAsMultiBands = TRUE);	


		//! \brief �õ��Ƿ���Ϊ�ನ�����ݼ���
		UGbool GetImportAsMultiBandsDataset() const;

		//! \brief �����Ƿ���λ��ת�����ܡ�
		//! \param pixelFormat [in]��
		//! \remarks ���SetForcePixelFormat����һ��ʹ�ã�����ΪTUREʱSetForcePixelFormat��������Ч	
		void SetForcePixelEnable(UGbool bEnable = TRUE);

		//! \brief �õ�λ��ת�������Ƿ�����
		//! \param pixelFormat [in]��
		//! \attention 	����ֵΪFalseʱ��SetForcePixelFormat������Ч
		UGbool GetForcePixelEnable() const;

		//! \brief ����ǿ�Ƶ�Ŀ�����ݼ�λ�
		//! \param pixelFormat [in]��
		//! \remarks ע�⣬�ò���ֻ�����ݵ��뵼��ʱ��Ч��ֱ�Ӵ�ʱ�ò�����Ч��
		//! \attention ����ʱ��һ�㵼������ݼ���λ���Դ����λ��һ�£�
		//!            ��Ҫ����Ŀ�����ݼ�λ��ʱ�����ô˽ӿ����á�
		void SetForcePixelFormat(UGPixelFormat pixelFormat);	

		//! \brief ��ȡ�û�ǿ�Ƶ�λ���ʽ��
		UGPixelFormat GetForcePixelFormat() const;	

		void SetImportBandInfos(const BandInfos& impBandInfos);	

		//! \brief ��ȡ������Ϣ��
		BandInfos GetBandInfos() const;	

		//! \brief �����Ƿ�����������
		//! \param TRUE [in] �Ƿ�����������
		void SetBuildPyramid(UGbool bBuild = TRUE);	

		//! \brief ��ȡ�Ƿ�����������
		UGbool GetBuildPyramid() const;	

		//! \brief ��ȡ��ɫ�ռ䡣
		ImgColorSpace GetColorSpace();	

		//! \brief ������ɫ�ռ䡣
		//! \param colorSpace [in] ��ɫ�ռ䡣
		void SetColorSpace(ImgColorSpace colorSpace);
		
		//! \brief ׷�����ݼ�ʱ�����ú��Եı߽�ֵ
// 		void SetBorderValue(UGdouble dValue) {m_dBorderValue = dValue;}
// 		UGdouble GetBorderValue() const { return m_dBorderValue; }
		
		//! \brief ׷�����ݼ�ʱ�������Ƿ���Ա߽�ֵ
// 				void SetIsIgnoreBorderValue(UGbool bIgnoreBorderColor) {m_bIgnoreBorderColor=bIgnoreBorderColor;}
// 				UGbool GetIsIgnoreBorderValue() const { return m_bIgnoreBorderColor; }
//       

        //! \brief ׷�����ݼ�ʱ�����ú�����ɫֵ���ۺϺ�����ɫ��ֵ�ͺͱ߽�ֵ�Ĺ���
		void SetIgnoreValues( UGArray<UGdouble>dValues);
		//! \brief ��ȡ������ɫ������ֵ
		void GetIgnoreValues(UGArray<UGdouble>&dValues)const;


		void SetIgnoreMode(IgnoreMode eIgnoreMode);
        //! \brief ��ȡ����ģʽ
		IgnoreMode GetIgnoreMode()const;
      
		//! \brief ���SDE�����õ�ǰ��դ�����ݼ�����
		void SetRasterIndex(UGint nIndex){m_nRasterIndex = nIndex;}

		//! \brief ���SDE,��ȡ��ǰ��դ�����ݼ�����
		UGint GetRasterIndex(){return m_nRasterIndex;}

		//! \brief �������ɵĵ��������ļ���·����
		virtual void SetWorldFilePath(const UGString& strWorldFile) { m_strWorldFile = strWorldFile; }

		//! \brief �õ����������ļ�·��
		virtual UGString GetWorldFilePath() const { return m_strWorldFile; }
		//! \brief ���õ�������ݼ������Ϣ��
		//! \param impDatasetInfos [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		void SetImportDatasetInfos(const RasterInfos& impDatasetInfos);	

		//! \brief �õ���������ݼ������Ϣ��
		//! \param  [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		RasterInfos& GetImportDatasetInfos();

	protected:

		//! \brief  Ŀ�����ݼ����ظ�ʽ
		UGPixelFormat m_nPixelFormat;


		//! \brief ѡ����Ĳ���������
		UGArray <UGint> m_arrBandsRaster;
        //! \brief ��ɫ�ռ�
		ImgColorSpace m_nImgColorSpace; 
        
		//!\brief ������Ϣ
		BandInfos m_impBandInfos;	
        
		//!brief Ŀ�����ݼ�����
		UGString m_strDestDTRName;
        
		//!\brief ��������ֵ
		UGint m_nRasterIndex;
        
		//!brief Ӱ������ο��ļ�
		UGString m_strWorldFile;
        
		//!\brief դ�����ݼ���Ϣ
		RasterInfos m_dtInfos;
        
// 		//!brief �Ƿ���Ա�����ɫ
		//UGbool m_bIgnoreBorderColor;
        
		//!\brief ������ɫ��ֵ
		UGArray<UGdouble>m_dIgnoreValues;
         
	    //!\brief ������ɫģʽ
		IgnoreMode m_eIgnoreMode;
	};

	//////////////////////////////////////////////////////////////////////////
	// raster export params
	//////////////////////////////////////////////////////////////////////////

	//! \brief դ�񵼳��������ࡣ
	class FILEPARSER_API UGRasterExportParams : public UGExportParams
	{
	public:

		//! \brief ���캯����
		UGRasterExportParams();

		//! \brief ����������
		virtual ~UGRasterExportParams();

	public:

		//! \brief �����Ƿ���λ��ת�����ܡ�
		//! \param pixelFormat [in]��
		//! \remarks ���SetForcePixelFormat����һ��ʹ�ã�����ΪTUREʱSetForcePixelFormat��������Ч	
		void SetForcePixelEnable(UGbool bEnable = TRUE);

		//! \brief �õ�λ��ת�������Ƿ�����
		//! \param pixelFormat [in]��
		//! \attention 	����ֵΪFalseʱ��SetForcePixelFormat������Ч
		UGbool GetForcePixelEnable() const;

		//! \brief ǿ�����õ�����Ӱ���λ�
		//! \param pixFormat [in]��
		//! \remarks ע�⣬�ò���ֻ�����ݵ��뵼��ʱ��Ч��ֱ�Ӵ�ʱ�ò�����Ч����
		void SetForcePixelFormat(UGPixelFormat pixFormat);	

		//! \brief ��ȡ����Ӱ���λ�
		//! \return ���ص���Ӱ���λ�
		UGPixelFormat GetForcePixelFormat() const;		

		//! \brief ����Ӱ���(Tile)�Ĵ�С(����)��
		//! \param blockWidth [in] Tile�Ŀ�
		//! \param blockHeight [in] Tile�ĸߡ�
		void SetBlockSize(UGint blockWidth, UGint blockHeight);	

		//! \brief ��ȡӰ���(Tile)�Ĵ�С(����)��
		//! \param blockWidth [in] Tile�Ŀ�
		//! \param blockHeight [in] Tile�ĸߡ�
		void GetBlockSize(UGint& blockWidth, UGint& blockHeight) const;	

		//! \brief ��ȡҪ������դ�����ݼ����ơ�
		UGString GetDtNameToBeExported()const;

		//! \brief ����Ҫ������դ�����ݼ����ơ�
		//! \param  name [in] ���õ����ơ�
		void SetDtNameToBeExported(UGString name);

		//! \brief ����͸��
		void SetTransparent(UGbool bTrans = TRUE);

		//! \brief ��ȡ�Ƿ�֧��͸��
		UGbool GetTransparent()const;

		//! \brief ����͸��ɫ
		void SetTransColor(UGColor cRGB);

		//! \brief ��ȡ͸��ɫ
		UGColor GetTransColor() const;

		//! \brief �����ļ���ѹ���ʡ�
		//! \param  nQuality [in] 
		//! \remarks ����ÿ����ʽ��֧������ѹ���� ��
		//! \attention ��֪����֧�̶ֳȣ���������ʽ�����ò�������JPEG
		virtual void SetQuality(UGint nQuality) {}

		//! \brief �õ�ѹ���ʡ�	
		virtual UGint GetQuality() const {return 0;}

		//		void TransImageDataPreprocess(UGbyte *ImageData, UGlong nSize, UGbool bTrans);
		//! \brief  ImageDataԤ��������32bit�����е�Alpha����
		//! \param UGbyte *ImageData
		//! \param UGlong nSize ImageData��С
		//! \param UGbool bTrans  �Ƿ�͸��
		//! \return UGbool �û�����͸��֮�󣬷����Ƿ������ر�͸��
		UGbool TransImageDataPreprocess(UGbyte *ImageData, UGlong nSize, UGbool bTrans);

		//! \brief ������ϲ��ε���
		//! \param bnds [in] ������ϡ�
		void SetCombineBands(const UGArray<UGint>& bnds);

		//! \brief ��ȡ��ϲ��ε���
		//! \param obnds [out] ������ϡ�
		void GetCombineBands(UGArray<UGint>& obnds) const ;

		//! \brief ����ͼ��ķֱ���/DPI.
		//! \param ndpi [in] ͼ���DPI��
		//! \remarks �˽ӿ����ڵ�ͼ��ͼ��
		//! \attention Ŀǰ֧��JPG��PNG��TIF��
		virtual void SetResolution(UGint ndpi) {};

		////! \brief ����ͼ��ķֱ���/DPI.
		//! \param ��
		//! \remarks ��
		//! \attention ����ĸ�ʽ���ò�����Ҫ��д�˺�����
		virtual UGint GetResolution() {return 0;};

	protected:

		//! \brief Ŀ���ļ����ظ�ʽ��
		UGPixelFormat m_nPixelFormat;

		//! \brief Ӱ���Ŀ�
		UGint m_nBlockWidth;

		//! \brief Ӱ���ĸߡ�
		UGint m_nBlockHeight;

		//! \brief Ҫ���������ݼ����ơ�
		UGString m_strDatasetName;

		//{{�޸�ԭ�� ���GIF��PNG��͸��֧�� �޸���:��˷ 2009-6-18 12:58:09
		//! \brief ��ʶ�Ƿ�͸��
		//! \remarks ��gif��png���õ�
		UGbool m_bTransparent;

		//! \brief �洢͸��ɫ������ʾʹ��SetTransColor��ֵ
		UGColor m_cTransColor;

		//! \brief �����ж��Ƿ����ù�͸��ɫ
		UGbool m_bHaveTransColorSet;
		//}}  2009-6-18 12:58:09

		//{{�޸�ԭ�� ��Ӳ�����Ϲ��� �޸���:���� 2009-11-9 12:41:09
		//! \brief ������ϵ�������
		UGArray<UGint> m_arrCombineBands;
		//}}  2009-11-9 12:41:09

	};

} //namespace UGC

#endif // !defined(AFX_UGRASTERIMPORTPARAMS_H__AFD927F6_BD78_470E_B1FA_56EF86E30E91__INCLUDED_)

