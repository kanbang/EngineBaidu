// UGImgToolkit.h: interface for the UGImgToolkit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGIMGTOOLKIT_H__21224E42_7983_49CB_99BC_9792CA94305F__INCLUDED_)
#define AFX_UGIMGTOOLKIT_H__21224E42_7983_49CB_99BC_9792CA94305F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Toolkit/UGPalette.h"

namespace UGC
{
	  //!  \brief Toolkit
	struct UGCMYK 
	{
	  //!  \brief Toolkit
		UGuint CValue;
	  //!  \brief Toolkit
		UGuint MValue;
	  //!  \brief Toolkit
		UGuint YellowVal;
	  //!  \brief Toolkit
		UGuint KValue;
	};
class TOOLKIT_API UGImgToolkit  
{
public:
	  //!  \brief Toolkit
	enum ReflectType
	{
	  //!  \brief Toolkit
		XAXES,	//ˮƽ���߶Գ�
	  //!  \brief Toolkit
		YAXES,	//��ֱ���߶Գ�
	  //!  \brief Toolkit
		ORIGIN	//�е�Գ�
	};
public:
	  //!  \brief Toolkit
	UGImgToolkit();
	  //!  \brief Toolkit
	virtual ~UGImgToolkit();

public:
	//==============================================================
	//�������ظ�ʽ�����ؿ�ȼ���DWORD����İ���BYTE�Ƶ�ʵ����Ҫ���.
	//! \brief
	  //!  \brief Toolkit
	static UGint AlignWidth(OGDC::PixelFormat PixelFormat,UGint lPixelWidth);
	//! \brief
	  //!  \brief Toolkit
	static UGint AlignWidthByte(OGDC::PixelFormat PixelFormat,UGint lPixelWidth);
	//! \brief
	  //!  \brief Toolkit
	static UGint AlignWidthWord(OGDC::PixelFormat PixelFormat,UGint lPixelWidth);
	
	//! \brief
	  //!  \brief Toolkit
	static UGushort BitCount(OGDC::PixelFormat PixelFormat);		//���ݸ�ʽ����λ��.
	//! \brief
	  //!  \brief Toolkit
	static UGushort PaletteSize(OGDC::PixelFormat PixelFormat);	//�õ���Ҫ�ĵ�ɫ���С.
	//! \brief
	  //!  \brief Toolkit
	static OGDC::PixelFormat Bit2Format(UGushort wBitCount);		//����λ�����ظ�ʽ.
	
	//! \brief
	//!  \brief ��GIF�ļ�������RGBA��ʽ
	static UGbool ImageGIFToRGBA(UGImageData& imageData, UGbyte nAlpha = 255); 
	//! \brief
	  //!  \brief Toolkit
	static UGbool ImageDataToRGBA(UGImageData& imageData, UGbyte nAlpha = 255);  // �ȸ���ά�ð��Ժ������ơ�
	//! \brief 32λColors��ɫת��ΪImageData��ʽ�������ʹ��
	//! \param imageData	 Ҫת�ɵ�ImageData��ʽ[in/out]
	//! \param nWidth		 Ҫת�ɵ�ImageData�Ŀ��[in]
	//! \param nHeight		 Ҫת�ɵ�ImageData�ĸ߶�[in]
	//! \param pData		 �����32λ��ɫ��[in]
	//! \return ת���Ƿ�ɹ�
	//! \remarks �����Ϊ32λ�ַ���������ΪnWidth*32/4*nHeight,ת�����ImagedataҲΪ232λ��ʽ
	//! \brief
	static UGbool ColorsToImageData(UGImageData& imageData, UGint nWidth,UGint nHeight,UGColor* pData);  // �ȸ���ά�ð��Ժ������ơ�
	  //!  \brief Toolkit
	//! \brief
	static UGuint GetValue(const UGbyte* pByte, UGint nWidthBytes, OGDC::PixelFormat pixelFormat, UGuint x, UGuint y);
	//! \brief
	  //!  \brief Toolkit
	static void SetValue(UGbyte* pByte, UGint nWidthBytes, OGDC::PixelFormat pixelFormat, UGuint x, UGuint y, UGuint nValue);
	//! \brief ����ImageData��
	//! \param arySrcImgData [in]��
	//! \param nReflectType ��������[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static UGArray<UGImageData*> ReflectImageData(UGArray<UGImageData*>& arySrcImgData,ReflectType nReflectType);	
	
	#if PACKAGE_TYPE==PACKAGE_UGC
	//ɫ�ʿռ�ת��------------------------------------------------------------
	//! \brief
	  //!  \brief Toolkit
	static UGint RGB2CMY(UGint color);
	//! \brief
	  //!  \brief Toolkit
	static UGint CMY2RGB(UGint color);
	//! \brief
	  //!  \brief Toolkit
	static UGint RGB2YIQ(UGint color);
	//! \brief
	  //!  \brief Toolkit
	static UGint YIQ2RGB(UGint color);
	//! \brief
	  //!  \brief Toolkit
	static UGint RGB2YUV(UGint color);
	//! \brief
	  //!  \brief Toolkit
	static UGint YUV2RGB(UGint color);
	//! \brief
	  //!  \brief Toolkit
	static UGint RGB2YCC(UGint color);
	//! \brief
	  //!  \brief Toolkit
	static UGint YCC2RGB(UGint color);
	//! \brief CMYK��RGBת�� ��SFC���ּ���
	static UGint CMYK2RGB(UGCMYK& cmyk);
	  //!  \brief Toolkit
	static UGCMYK RGB2CMYK(UGColor color);
	//! \brief
	static void RGBtoHSL(UGColor rgb, UGdouble& H, UGdouble& S, UGdouble& L);
	//! \brief
	static UGColor HLStoRGB(const UGdouble& H, const UGdouble& L, const UGdouble& S);
	//! \brief
	static UGdouble HuetoRGB(UGdouble m1, UGdouble m2, UGdouble h);
	#endif // end declare ugc API

	//! \brief �ж���ɫ���Ƿ�8λ�Ҷ�
	static UGbool IsGrayColorset(const UGColorset &colorset);


	//! \brief ͼƬ�����2��N�η��������Ա�����ά�а�����ص����⡣
	//! \param imageData ͼƬ���� [out]��
	//! \param nRealWidth ��Ч���ݵĿ�� [out]��
	//! \param nRealHeight ��Ч���ݵĸ߶� [out]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static void ImageDataToPowerOfTwo(UGImageData& imageData, UGint& nRealWidth, UGint& nRealHeight, UGbyte chA = 255);
};
}

#endif // !defined(AFX_UGIMGTOOLKIT_H__21224E42_7983_49CB_99BC_9792CA94305F__INCLUDED_)


