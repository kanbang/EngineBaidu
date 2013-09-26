/* 
	\file UGSpatialIndex.h
	\brief	�������������һ��
			���������Ĵ������ؽ���ɾ��
			������������֮ǰ�����ݵķ������������������������Լ���������Ӧ��
			���������Ƿ�֧��ĳ�������Ŀ���

	\author zhouqin
	\attention
	Copyright(c) 2008 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
*/
//////////////////////////////////////////////////////////////////////
#ifndef UGENGTOOLKIT_H
#define UGENGTOOLKIT_H

#include "Stream/ugdefs.h"
#include "Engine/UGEngDefs.h"
#include "Engine/UGDatasetVectorInfo.h"
#include "Engine/UGDataset.h"
#include "Engine/UGDatasetRasterInfo.h"
#include "Engine/UGDatasetRaster.h"
#include "Base/ogdccolordef.h"

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
// #include "Engine/UGDatasetMultiBandRaster.h"
#endif
//#include "Workspace/UGWorkspace.h"
namespace UGC {

//##ModelId=48203051014A
class ENGINE_API UGEngineToolkit
{
private:
	//##ModelId=482030510157
	UGEngineToolkit();
	//##ModelId=482030510158
#ifdef SYMBIAN60
	~UGEngineToolkit();
#else
	virtual ~UGEngineToolkit();
#endif
	

public:
	//modified by macx 2008.8.4 �����ռ����
	//! \brief DsConnect ToXML
	//##ModelId=48203051015A
	static UGString DSConnectToXML(const UGDsConnection& dsc, UGint nVersion, UGString strRefPath=_U(""), const UGString& strPWD = (_U("")));
	
	//modified by macx 2008.8.4 �����ռ����
	//! \brief DsConnect FromXML
	//##ModelId=482030510168
	static UGbool DSConnectFromXML(UGDsConnection& dsc, const UGString& strXML,UGint nVersion, UGString strRefPath=_U(""), const UGString& strPWD = (_U("")));

	//##ModelId=483BB7090157
	static UGbool AppendBlock(UGImgBlock* pResBlock, UGImgBlock* pSrcBlock); 

	/////////////////////////////	FieldInfo ��ط���	////////////////////////////////////////////
	//! \brief �Ƿ��Ǽ����ֶ�
	//##ModelId=483BB709015B
	static UGbool IsGeoField(UGString strName);

	//! \brief �Ƿ���ϵͳ�ֶ�
	//##ModelId=483BB7090167
	static UGbool IsSystemField(UGString strName);

	//! \brief �Ƿ���SmID�ֶ�
	//##ModelId=483BB709016A
	static UGbool IsSmID( UGString strName);

	//! \brief �Ƿ���ϵͳUUID�ֶ�
	static UGbool IsUUID(UGString strName);

	//##ModelId=483BB709016D
	static void SetFieldSign(UGFieldInfo& fieldInfo);
	/////////////////////////////	FieldInfo ��ط���	////////////////////////////////////////////

	//! \brief ���㷶Χ�߽�����
	//! \param &rcBounds [in]��
	//! \param &aryGrids [out]��
	//! \return T
	//! \remarks �м���ͼ��㼸�㣬aryGrids�������£����ϼ�¼
	//! \attention ��
	//##ModelId=483BB7090170
	static UGbool FindQueryGrids(UGDatasetVectorInfo* sInfo, UGRect2D &rcBounds,UGArray<UGPoint> &aryGrids);

	//! \brief	Colorset�Ĵ�ȡ
    //! \brief �ͼ�����
	//##ModelId=483BB709017B
	static UGbool ColorsetLoad(UGColorset& clrSet, UGStream& stream);
	
	//! \brief	Colorset�Ĵ�ȡ
	//##ModelId=483BB709017F
	static UGbool ColorsetSave(UGColorset& clrSet, UGStream& stream);

    //ͨ�����ػ�ȡʵ���ֽڿ��
	static UGint  GetWidthBytes(OGDC::PixelFormat ePixelFormat, UGint nWidth);
	//�������صı��뷽ʽ
	static UGbool ModifyEncType(OGDC::PixelFormat ePixelFormat,UGDataset::DatasetType nType,UGColorset &Colorset,UGDataCodec::CodecType& nEncType);


	//{{��SFC����ֲ����	add by shuxl	08.12.11
	//�����ֶΣ�����Ϸ��ʹ���
	static UGbool CreateValidField( UGDatasetVector * pDataSetV,  const UGFieldInfo & fieldinfo);
	//�����ֶΣ�����Ϸ��ʹ���
	static UGbool CreateValidField( UGDatasetVector * pDataSetV,  const UGString &strName, UGint nType, UGint lSize, UGint lAttributes = 0);
	//�����ֶΣ�ֻ�����Ϸ��ֶ�
	static UGbool CreateValidFields( UGDatasetVector * pDataSetV,  const UGFieldInfos & fieldinfos);
	//}}��SFC����ֲ����	add by shuxl	08.12.11

    //�ڵ������ݼ���ʱ�� ����������Ƿ���Լ���
	static UGbool CheckRasterInfo(const UGArray<UGDatasetRasterInfo*>& rasterInfos);
	//�ж�strName�Ƿ�Ϸ���Ҳ������RasterInfo���Ƿ���ڣ�������ڣ�����TRUE,����strName��ɺϷ���
	//����������򲻱�
	static UGbool GetAvailFieldName(const UGDatasetRasterInfo& RasterInfo,UGString& strName);
    
	//! \brief ȥ��srcAry�к�exceptAry��һ����ֵ
	//! \param &srcAry Դ����[in][out]��
	//! \param &exceptAry ��������[in]��
	//! \return void
	static void Except(UGArray<UGint>& srcAry,UGArray<UGint>& exceptAry);

	//! \param nBandIndexSrc[in] ԭ���ݲ�������ֵ��Ĭ��Ϊ0
	//! \param nBandIndexDes[in] ��������ֵ��Ĭ��Ϊ0
	static UGbool CopyDatasetRaster(UGDatasetRaster* RasterTarget, UGDatasetRaster* RasterSrc, UGint nBandIndexDes=0, UGint nBandIndexSrc = 0, UGint nProgresStartPos=0, UGint nProgresEndPos=100, UGProgress *pProgressSrc = NULL);
	//ͨ�� RasterSrc �ĵ�n���ι���һ��RasterTarget 
	static UGbool GetRasterInfo(UGDatasetRasterInfo& RasterTarget, const UGDatasetRasterInfo& RasterSrc, UGint nBand);
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//ͨ�� RasterSrc ����Ϣ��ȡ��һ��BandInfo
	static UGBandInfo GetBandInfo(const UGDatasetRasterInfo& RasterSrc);
#endif
	//! \brief �Ժ��б������ַ������б����滻,��Ҫ���ڴ���SQL��䡣
	//! \param &strIn ����Ĵ�[in]��
	//! \param &strTableSrc Դ����[in]��
	//! \param &strTableDest Ŀ�����[in]��
	//! \return ���ؽ������
	//! \remarks ��Ҫ���ڴ���SQL��䡣
	static UGString ReplaceTableName(const UGString &strIn, const UGString &strTableSrc, const UGString &strTableDest);	

	//! \brief �ж��ֶε�Ĭ��ֵ�Ƿ�Ϸ���ֻ������������Ч�� 
	//! \param fieldInfo �ֶ���Ϣ��[in] 
	static UGbool IsDefaultValueAviable(UGFieldInfo fieldInfo);
    //! \brief ����ʵ���˲�ͬ��դ�����ݼ�֧�ֵ����ظ�ʽ
	// ͬʱ�����˵�ǰ�����դ��֧���Ǽ������͵����ݼ�
	static UGbool GetSupportRaster(UGEngineType engType,UGDataset::DatasetType dataType,OGDC::PixelFormat ePixelFormat,UGbool IsMBRaster = FALSE);
	static UGbool GetSupportVector(UGEngineType engType,UGDataset::DatasetType dataType);
	static UGbool IsSupportPixelFormat(OGDC::PixelFormat ePixelFormat);
	//! \brief ����ʵ���˲�ͬ�����ظ�ʽ�ڴ������ݼ���ʱ��ĳ�ʼ����ֵ
	static UGdouble GetDefaultNoValue(OGDC::PixelFormat ePixelFormat);
    //! \brief ��IDs���ظ��ģ�С�ں͵���0��Id���й���

	//! \brief ��ú���ı�����
	static UGbool ExtractTableName(UGDataSource *pDS, UGString strName, 
		UGString strTableName, UGString& strResTabName);

	//! \brief ����ַ�����ǰnCount���ַ�	
	static UGString GetSubText(const UGString strString, UGint nCount);

    static UGbool FilterIDs(UGArray<UGint>& arrIDs);
	//! \brief �ж����arrByte �ǲ��������Ϸ����ַ������
	static UGbool IsValid(UGByteArray& arrByte);
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//! \brief ���ضನ�ε����в���
	static UGArray<UGint> GetArrayIndex(UGDatasetRaster* pRaster);
#endif
    //! \brief ��ò�ͬ��ֵ������256λ֮��ı���
	static UGdouble GetRatioPixel(UGdouble dMaxZ,UGdouble dMinZ,OGDC::PixelFormat ePixelFormat);
    //! \brief ͨ��nColor����ȡʵ�ʵ�RGBֵ
	static UGColor GetColor(UGint nColor,ImgColorSpace nColorSpace);
 
	//! \brief ���������㷨 Ӱ�������
	//	BilinearInterpolation	CubicConvolution NearestNeighbor
	static UGbool BilinearInterpolation(UGImgBlock *pResBlock, UGArray<UGImgBlock*>& arrImgBlock
		, ImgColorSpace nColorSpace,UGArray<UGdouble>&dMinZs,

		UGArray<UGdouble>&dMaxZs,UGint nBandCount , UGbool bMaxMinStretch=true);

	//! \brief ���������㷨 ��������
	static UGbool BilinearInterpolation(UGColor& nColor ,UGArray<UGdouble>& arrValue
		, ImgColorSpace nColorSpace,UGArray<UGdouble>&dMinZs,
		UGArray<UGdouble>&dMaxZs,UGint nBandCount );
	
	//!\brief ��������ķ��㷨
	static UGbool BilinearInterpolationR(UGArray<UGdouble>& arrValue,UGColor nColor, 
		ImgColorSpace nColorSpace,UGArray<UGdouble>&dMinZs,
		UGArray<UGdouble>&dMaxZs,UGint nBandCount );

	//! \brief ����rcRsBounds������ӽ���rcDtBounds����Ŵ�һЩ��
	static void InflateBounds(const UGRect2D& rcDtBounds,UGRect2D& rcRsBounds,UGdouble dTolerance = 0);
    
	//! \brief ��鵱ǰ�ֶ��Ƿ�����ɾ��������ɾ��������TRUE;
	static UGbool CheckField(const UGFieldInfo&filedInfo);

	//! \brief ����ƽ��ֵ
	static UGdouble CalcAvgValue(UGdouble a, UGdouble b, UGdouble c, UGdouble d,UGdouble dNoValue);
	static UGuint GetImgPyramidValue(OGDC::PixelFormat ipf, UGbool bIndexedColor, UGuint a,
		UGuint b, UGuint c, UGuint d);

	//! \brief �ж�Ŀ���ֶ��Ƿ����Դ�ֶ�
	//! \param &srcInfo Դ�ֶ�
	//! \param &destInfo Ŀ���ֶ�
	//! \return ���ؼ����жϽ��
	static UGbool IsFiledTypeCompatible(const UGFieldInfo &srcInfo, const UGFieldInfo &destInfo);

	//! \brief �õ����Դ�Դ��¼����׷�ӵ�Ŀ�����ݼ����ֶ�
	//! \param *pSrcRcd	Դ��¼��
	//! \param *pDataset Ŀ�����ݼ�
	//! \param &fieldsAppendable ��Ҫ��׷�ӵ�Ŀ�����ݼ����ֶ�����
	//! \return 
	static void FieldsAppendable(UGRecordset *pSrcRcd, UGDatasetVector *pDataset, UGFieldInfos &fieldsAppendable);

	//! \brief �õ�֧�ֵı�������
	//!\ param nType ���ݼ�����
	//!\ param ePixelFormat ���ظ�ʽ
	//!\ param &colorset ��ɫ��
	static UGArray<UGDataCodec::CodecType> GetSupportEncType(UGDataset::DatasetType nType, OGDC::PixelFormat ePixelFormat, const UGColorset &colorset);

	//! \brief ͳ�ƺ��������ֵ����Сֵ��ƽ��ֵ���ܺ͡���׼����
	//! \param *pData ����
	//! \param nCount ���ݸ���
	//! \parma emode ͳ������
	static UGdouble Statistic(UGint *pData, UGint nCount, UGStatisticMode eMode);
	static UGdouble Statistic(UGdouble *pData, UGint nCount, UGStatisticMode eMode);

	//! \brief ����Ƿ������ݿ�Ĺؼ���
	//! \brief ���е����ݿ�ؼ��ֺϼ�
	//! \return ������֤���
	static UGbool CheckIsKeyword(UGString strWord);

	static UGString GetDatasetCachePath();

	//! \brief ��������ַ�������������������ŵ��Ӵ�����Ϊ�����N
	//! \brief ���ʹ��SQL�������ݿ�ʱ��SQL������ж�����Ե��ַ�������Ҫ���N���
	//! \Sample "Name in 'China', 'American'", �����Ϊ "Name in N'China', N'American'"
	static void SQLWideCharSupport(UGString &strContent);

	//! \brief������ݼ����͵��ַ���
	static UGString GetStrType(const UGDataset::DatasetType type);

	//! \�ж��Ƿ����׷��Ҫ�󣬲���ͨ������������ȷ���ֶ�ƥ���ϵ
	static UGbool IsMatchingAppend(UGDatasetVector *pVector, UGRecordset *pRcd, UGArray<UGString> &strSrcFieldNames, UGArray<UGString> &strDesFieldNames);

	static UGbool IsMatchingJoint( UGDatasetVector *pVector, UGRecordset *pRcd, UGArray<UGString> &strSrcFieldNames, UGArray<UGString> &strDesFieldNames, UGFieldInfos &outSrcInfos, UGFieldInfos &outDestInfos);

	static UGbool IsFieldSignExist(UGDatasetVector *pVector, UGFieldInfo::FieldSign fieldSign);

	static UGString ConvertDateTimeToString( UGTime timeValue,UGEngineType engineType );
};
}

#endif // !defined(UGENGTOOLKIT_H)

