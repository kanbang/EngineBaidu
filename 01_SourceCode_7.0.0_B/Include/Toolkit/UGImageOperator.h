// �ڴ�ͼ������,����һЩ���õ�ͼ����
// ��������з�����Ϊ��̬����
// ����:��ï
// ����:2010-12-15
// �汾:1.0.0

#ifndef  UGIMAGEOPERATOR_H
#define  UGIMAGEOPERATOR_H

#include "Stream/ugdefs.h"
#include "Toolkit/UGPalette.h"
#include "Toolkit/UGTextureInfo.h"
#include "Geometry/UGDataCodec.h"

#define DXT1_ENCODE_SIZE(w,h) (((w-1)/4 + 1)*((h-1)/4 + 1)*8)
#define DXT3_ENCODE_SIZE(w,h) (((w-1)/4 + 1)*((h-1)/4 + 1)*16)
#define DXT5_ENCODE_SIZE DXT3_ENCODE_SIZE

using namespace UGC;

#ifdef IOS
struct PVRFILEHEADER{
	UGuint	u32Version;			//Version of the file header, used to identify it.
	UGuint	u32Flags;			//Various format flags.
	UGulong	u64PixelFormat;		//The pixel format, 8cc value storing the 4 channel identifiers and their respective sizes.
	UGuint	u32ColourSpace;		//The Colour Space of the texture, currently either linear RGB or sRGB.
	UGuint	u32ChannelType;		//Variable type that the channel is stored in. Supports signed/unsigned int/short/byte or float for now.
	UGuint	u32Height;			//Height of the texture.
	UGuint	u32Width;			//Width of the texture.
	UGuint	u32Depth;			//Depth of the texture. (Z-slices)
	UGuint	u32NumSurfaces;		//Number of members in a Texture Array.
	UGuint	u32NumFaces;		//Number of faces in a Cube Map. Maybe be a value other than 6.
	UGuint	u32MIPMapCount;		//Number of MIP Maps in the texture - NB: Includes top level.
	UGuint	u32MetaDataSize;	//Size of the accompanying meta data.
};
#endif

class TOOLKIT_API UGImageOperator
{
public:
	// format ԭͼ������ظ�ʽ
	// width,height ԭͼ��Ŀ�Ⱥ͸߶�
	// in ԭͼ�������
	// comtype ͼ��ѹ������
	// out  ѹ��������,�ڲ�����ռ�
	// return ����ѹ����ͼ�����ݵĴ�С
	static UGuint Encode( const UGuint pixsize, UGuint &nWidth, UGuint &nHeight,UGbyte* pBufferIn,UGbyte **ppBufferOut,UGuint eCodecType =UGDataCodec::enrS3TCDXTN,UGbool bGeneMipmaps =FALSE);

	// ��ѹ��dxtn
	static UGuint Decode( const UGuint pixsize, UGuint nWidth, UGuint nHeight,UGbyte** ppBufferOut,const UGbyte *pBufferIn ,UGuint eCodecType,UGbool bGeneMipmaps =FALSE);

	// ����ָ���Ĵ�С����ͼƬ
	static void Scale(const UGuint components, UGuint widthin, UGuint heightin,UGbyte *pBufferIn,
					        UGuint widthout, UGuint heightout, UGbyte *pBufferOut);

	// RGB,RGBA �� BGR,BRGA֮���໥ת��,ֱ�Ӹı�ԭʼ����
	// RGBʱcomponents = 3,RGBA components = 4
	static void ImageSwapRB(const UGuint components, UGuint widthin, UGuint heightin,UGbyte *pBufferIn,UGbool bIsContainMipmap =FALSE);

 	// ��ȡmipmap������
	static UGuint GetMipMapData(UGuint nWidth,UGuint nHeight,const UGbyte* pBufferIn,UGbyte** ppBufferOut,UGArray<UGuint>& arrByteOffset);

 	//! \brief  ���ر�a��ģ���������ӽ�a��2�Ĵη�������
 	static UGuint NextP2 (UGuint a);

	//! \brief ��ImageDataת����TextureInfo
	//! \brief bMipmapCompress��mipmap����dxtѹ��
	static void ImageData2TexInfo(const UGImageData& ImageData,UGTextureInfo &Info,UGbool bMipmapCompress=TRUE);

	//! \brief ��ȡָ��ѹ����ʽ������ѹ����Ĵ�С
	//! \brief
	static UGuint GetCompressedTextureSize(const UGuint pixsize,UGuint nWidth,UGuint nHeight,UGuint eCodecType,UGbool bIsMipmaps =FALSE);

	//! \brief ���ݿ�߻�ȡmipMap�㼶
	static UGuint GetMipMapLevel(const UGuint nWidth,const UGuint nHeight);
    
#ifdef IOS
    //! \brief get the pvr file contenie
    static void GetPvrTextureData(const UGString &strFilePath,UGTextureInfo& textData);
#endif
};
#endif

