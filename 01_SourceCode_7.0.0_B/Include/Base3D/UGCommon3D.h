//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief ��άʹ�õ�ö�ٺͳ����Ķ����ļ���
//!  \details ��װ����άʹ�õ�ö�ٺͳ����Ķ����ļ���
//!  \author ��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//! \brief//

#ifndef UG3DCOMMON_H
#define UG3DCOMMON_H

#include "Base3D/UGPrerequisites3D.h"

namespace UGC
{

static UGString g_stStringBlank = _U("");

#define MAX_GRID_VERTICE_NUM  16

#define BLOCK_BORDER_WIDTH 8
//! \brief ����뾶��
#define GLOBAL_RADIUS  6378137
//! \brief ����������������
#define SMSCN_MAX_TEXTURE_COORD_SETS 8
//! \brief ��Чֵ���塣
#define VALUE_NAN                    UG_FLTMAX
//! \brief  ��������ֵ    
#define FLOAT_EPSILON                1.401298e-45
//! \brief ���������ŵ�������
#define MAX_TEXTURE_NUM              10000
//! \brief ��ά�������ƹ���Ŀ��
#define MAX_LIGHTS                   8        // �����Դ������
//! \brief ÿ�����ο����󶥵���Ŀ��
#define MAX_VERTEX_COUNT             4096  
//! \brief ����ܽ�����С�߶�  
#define MIN_ALTITUDE                 50000

//! \brief ƽ��0��tile�Ĵ�С pow(2.0,25)  
#define LOD0_TILE_SIZE 33554432

//#define LEVEL_WIDTH 2
//#define MAX_LEVEL_NUM 6
//! \brief ÿ���� LEVEL_WIDTH��LEVEL_WIDTH�����ο鹹��
#define LEVEL_WIDTH 4
//! \brief �����ڿɼ�����
#define MAX_LEVEL_NUM 6

//!\brief ȫ������ʷֵ�������
#define GLOBAL_GRID_MAX_LEVEL 22

#define MORPH_FRAME_NUM 5
#define EAST_DIRECTION 1
#define SOUTH_DIRECTION 2
#define WEST_DIRECTION 4
#define NORTH_DIRECTION 8
#define NORTH_EAST_DIRECTION (NORTH_DIRECTION|EAST_DIRECTION)
#define SOUTH_EAST_DIRECTION (SOUTH_DIRECTION|EAST_DIRECTION)
#define NORTH_WEST_DIRECTION (NORTH_DIRECTION|WEST_DIRECTION)
#define SOUTH_WEST_DIRECTION (SOUTH_DIRECTION|WEST_DIRECTION)

//! \brief ��ɫ��ֵӰ�������������׶���
#define MAX_COLOR_INTERPOLATOR_STAGES 6

//! \brief ��ͼģʽ����
#define SKETCHMATERIAL _U("Ogre/SketchModel")

//! \brief ��Ⱦ���ȼ����
#define RENDER_PRIORITY_INTERVAL 5
    
//! \brief Enumerates the wave types usable with the Ogre engine. 
enum WaveformType
{
    //! \brief Standard sine wave which smoothly changes from low to high and back again.
    WFT_SINE,
    //! \brief An angular wave with a constant increase / decrease speed with pointed peaks.
    WFT_TRIANGLE,
    //! \brief Half of the time is spent at the min, half at the max with instant transition between.
    WFT_SQUARE,
    //! \brief Gradual steady increase from min to max over the period with an instant return to min at the end.
    WFT_SAWTOOTH,
    //! \brief Gradual steady decrease from max to min over the period, with an instant return to max at the end.
    WFT_INVERSE_SAWTOOTH,
	//! \brief Pulse Width Modulation. Works like WFT_SQUARE, except the high to low transition is controlled by duty cycle. 
	//! \brief With a duty cycle of 50% (0.5) will give the same output as WFT_SQUARE.
	WFT_PWM
};

//! \brief Filtering options for textures / mipmaps. 
enum FilterOptions
{
    //! \brief No filtering, used for FILT_MIP to turn off mipmapping
    FO_NONE,
    //! \brief Use the closest pixel
    FO_POINT,
    //! \brief Average of a 2x2 pixel area, denotes bilinear for MIN and MAG, trilinear for MIP
    FO_LINEAR,
	/// Equal to: min=FO_LINEAR, mag=FO_LINEAR, mip=FO_LINEAR
	FO_TRILINEAR,
    //! \brief Similar to FO_LINEAR, but compensates for the angle of the texture plane
    FO_ANISOTROPIC
};

//! \brief
enum UGFilterType
{
    //! \brief The filter used when shrinking a texture
    FT_MIN,
    //! \brief The filter used when magnifiying a texture
    FT_MAG,
    //! \brief The filter used when determining the mipmap
    FT_MIP
};
//! \brief
enum UG3DPixelFormat
{
	//! \brief δ֪���ظ�ʽ.
	PF_UNKNOWN = 0,
	//! \brief 8λ���أ���������.
	PF_L8 = 1,
	PF_BYTE_L = PF_L8,
	//! \brief 16λ���أ���������.
	PF_L16 = 2,
	PF_SHORT_L = PF_L16,
	//! \brief 8λ���أ�����alphaֵ.
	PF_A8 = 3,
	PF_BYTE_A = PF_A8,
	//! \brief 8λ����, 4λalphaֵ, 4λ����.
	PF_A4L4 = 4,
	//! \brief ���ֽ�����, һ������alphaֵ��һ����������
	//! \brief 8λ����, 4λ����, 4λalpha.
	PF_L4A4 = 35,
	//! \brief 16λ����, ÿ4λ����BGRA.
	PF_B4G4R4A4 = 36,
	//! \brief 24λ����, ÿ8λ����BRG.
	PF_B8R8G8 = 37,
	//! \brief 32λ����, ÿ10λ����BGR, 2λ����alpha.
	PF_B10G10R10A2 = 38,
	PF_BYTE_LA = 5,
	//! \brief 16λ���ظ�ʽ, R,G,BΪ5��6��5.
	PF_R5G6B5 = 6,
	//! \brief 16λ���ظ�ʽ, B,G,RΪ5��6��5.
	PF_B5G6R5 = 7,
	//! \brief 8λ����, B,G,RΪ2��3��3.
	PF_R3G3B2 = 31,
	//! \brief 16λ����, alpha��R,G,BΪ4,4,4,4.
	PF_A4R4G4B4 = 8,
	//! \brief 16λ����, alpha��R,G,BΪ1,5,5,5.
	PF_A1R5G5B5 = 9,
	//! \brief 24λ����, R,G,BΪ8,8,8.
	PF_R8G8B8 = 10,
	//! \brief 24λ����, B,G,RΪ8,8,8.
	PF_B8G8R8 = 11,
	//! \brief 32λ����, alpha,R,G,BΪ8,8,8,8.
	PF_A8R8G8B8 = 12,
	//! \brief 32λ����, B, G, R,alphaΪ8,8,8,8.
	PF_A8B8G8R8 = 13,
	//! \brief 32λ����, B, G, R,alphaΪ8,8,8,8.
	PF_B8G8R8A8 = 14,
	//! \brief 32λ����, R, G, B,alphaΪ8,8,8,8.
	PF_R8G8B8A8 = 28,
	// 128λ����, ÿ��Ԫ��ռ32λ
	PF_FLOAT32_RGBA = 25,
	//! \brief 32λ����, R, G, BΪ8��8,8��alpha��Ч
	PF_X8R8G8B8 = 26,
	//! \brief 32λ����, B G, RΪ8��8,8��alpha��Ч
	PF_X8B8G8R8 = 27,
	//! \brief 3�ֽ�����, ÿ����ɫռһ���ֽ�
	PF_BYTE_RGB = PF_B8G8R8,
	//! \brief 3�ֽ�����, ÿ����ɫռһ���ֽ�
	PF_BYTE_BGR = PF_R8G8B8,
	//! \brief 4�ֽ�����, ÿ����ɫ��alpha��ռһ���ֽ�
	PF_BYTE_BGRA = PF_A8R8G8B8,
	//! \brief 4�ֽ�����, ÿ����ɫ��alpha��ռһ���ֽ�
	PF_BYTE_RGBA = PF_A8B8G8R8,
	//! \brief 32λ���� ��λ����alpha��ÿ����ɫռ10λ
	PF_A2R10G10B10 = 15,
	//! \brief 32λ����, ��λ����alpha��ÿ����ɫռ10λ
	PF_A2B10G10R10 = 16,
	//! \brief DirectDraw Surface (DDS) DXT1 format
	PF_DXT1 = 17,
	//! \brief DirectDraw Surface (DDS) DXT2 format
	PF_DXT2 = 18,
	//! \brief DirectDraw Surface (DDS) DXT3 format
	PF_DXT3 = 19,
	//! \brief DirectDraw Surface (DDS) DXT4 format
	PF_DXT4 = 20,
	//! \brief DirectDraw Surface (DDS)) DXT5 format
	PF_DXT5 = 21,
	// 16λ����, ����R
	PF_FLOAT16_R = 32,
	// 48λ����, ÿ16λfloat����RGB
	PF_FLOAT16_RGB = 22,
	// 64λ����,ÿ16λfloat����RGBA
	PF_FLOAT16_RGBA = 23,
	// 16λ���أ�float����R
	PF_FLOAT32_R = 33,
	// 96λ����, ÿ32λfloat����RGB
	PF_FLOAT32_RGB = 24,
	// 128λ����, ÿ32λfloat����RGBA
	// �����������
	PF_DEPTH = 29,
	// 64λ����, ÿ16λfloat����RGBA
	PF_SHORT_RGBA = 30,
	// ��ǰ�������ظ�ʽ����Ŀ
	PF_COUNT = 34						
};

/** Enum identifying special mipmap numbers
*/
enum TextureMipmap
{
	/// Generate mipmaps up to 1x1
	MIP_UNLIMITED = 0x7FFFFFFF,
	/// Use TextureManager default
	MIP_DEFAULT = -1
};

//! \brief Defines the frame buffer types. 
enum FrameBufferType {
    FBT_COLOUR  = 0x1,
    FBT_DEPTH   = 0x2,
    FBT_STENCIL = 0x4
};
//! \brief ��Ӱģʽ
enum ShadeOptions
{
    SO_FLAT,
    SO_GOURAUD,
    SO_PHONG
};
//! \brief �ȽϷ�ʽ
enum CompareFunction
{
    CMPF_ALWAYS_FAIL,
    CMPF_ALWAYS_PASS,
    CMPF_LESS,
    CMPF_LESS_EQUAL,
    CMPF_EQUAL,
    CMPF_NOT_EQUAL,
    CMPF_GREATER_EQUAL,
    CMPF_GREATER
};
//! \brief ��Ⱦ�����õĻ��ģʽ
enum SceneBlendFactor
{
    SBF_ONE,
    SBF_ZERO,
    SBF_DEST_COLOUR,
    SBF_SOURCE_COLOUR,
    SBF_ONE_MINUS_DEST_COLOUR,
    SBF_ONE_MINUS_SOURCE_COLOUR,
    SBF_DEST_ALPHA,
    SBF_SOURCE_ALPHA,
    SBF_ONE_MINUS_DEST_ALPHA,
    SBF_ONE_MINUS_SOURCE_ALPHA

};

/** Types of blending that you can specify between an object and the existing contents of the scene.*/
enum SceneBlendType
{
	/// Make the object transparent based on the final alpha values in the texture
	SBT_TRANSPARENT_ALPHA,
	/// Make the object transparent based on the colour values in the texture (brighter = more opaque)
	SBT_TRANSPARENT_COLOUR,
	/// Add the texture values to the existing scene content
	SBT_ADD,
	/// Multiply the 2 colours together
	SBT_MODULATE,
	/// The default blend mode where source replaces destination
	SBT_REPLACE
	// TODO : more
};

/** Blending operations controls how objects are blended into the scene. The default operation
is add (+) but by changing this you can change how drawn objects are blended into the
existing scene.
*/
enum SceneBlendOperation
{
	SBO_ADD,
	SBO_SUBTRACT,
	SBO_REVERSE_SUBTRACT,
	SBO_MIN,
	SBO_MAX
};

/** List of valid texture blending operations, for use with TextureUnitState::setColourOperation.
@remarks
This list is a more limited list than LayerBlendOperationEx because it only
includes operations that are supportable in both multipass and multitexture
rendering and thus provides automatic fallback if multitexture hardware
is lacking or insufficient.
*/
enum LayerBlendOperation {
	/// Replace all colour with texture with no adjustment
	LBO_REPLACE,
	/// Add colour components together.
	LBO_ADD,
	/// Multiply colour components together.
	LBO_MODULATE,
	/// Blend based on texture alpha
	LBO_ALPHA_BLEND

};

//! \brief ��Ⱦ�����õĵĲü�ģʽ
enum CullingMode
{
    //! \brief Hardware never culls triangles and renders everything it receives.
    CULL_NONE = 1,
    //! \brief Hardware culls triangles whose vertices are listed clockwise in the view (default).
    CULL_CLOCKWISE = 2,
    //! \brief Hardware culls triangles whose vertices are listed anticlockwise in the view.
    CULL_ANTICLOCKWISE = 3
};

/** Manual culling modes based on vertex normals.
This setting applies to how the software culls triangles before sending them to the 
hardware API. This culling mode is used by scene managers which choose to implement it -
normally those which deal with large amounts of fixed world geometry which is often 
planar (software culling movable variable geometry is expensive). */
enum ManualCullingMode
{
	/// No culling so everything is sent to the hardware.
	MANUAL_CULL_NONE = 1,
	/// Cull triangles whose normal is pointing away from the camera (default).
	MANUAL_CULL_BACK = 2,
	/// Cull triangles whose normal is pointing towards the camera.
	MANUAL_CULL_FRONT = 3
};

//! \brief ��Ⱦ�����õĶ������ʾģʽ
enum PolygonMode
{
	//! \brief Only points are rendered.
    PM_POINTS = 1,
	//! \brief Wireframe models are rendered.
    PM_WIREFRAME = 2,
	//! \brief Solid polygons are rendered.
    PM_SOLID = 3
};

//! \brief ͼ����Ƶķ�����ģʽ
enum SmoothHintMode
{
	//��ʹ�ÿ����
	SHM_NONE,
	//�ɾ���OpenGL��ʵ���������������ַ�ʽ�ﵽ�㣬�ߵ�ƽ��Ч��
	SHM_DONT_CARE,
	//�����ٶ����
	SHM_FASTEST,
	//��ʾЧ�����
	SHM_NICEST
};

//! \brief ��Ⱦ�����õ���ļ���ģʽ
enum FogMode
{
    //! \brief No fog. Duh.
    FOG_NONE,
    //! \brief Fog density increases  exponentially from the camera (fog = 1/e^(distance * density))
    FOG_EXP,
    //! \brief Fog density increases at the square of FOG_EXP, i.e. even quicker (fog = 1/e^(distance * density)^2)
    FOG_EXP2,
    //! \brief Fog density increases linearly between the start and end distances
    FOG_LINEAR
};
//! \brief ��Ⱦ�����õĵ������ļ���ģʽ
enum SceneNormalMode
{
	//! \brief 
	SNM_NONE = 1,
	//! \brief ƽ��
    SNM_FLAT = 2,
	//! \brief ƽ��ģʽ
    SNM_SMOOTH = 3
};
//! \brief ��Ⱦ�����õĵ�������滷�Ʒ���
enum PolygonFrontFace
{
	//! \brief ���涼��
	PFF_NONE = 1,
	//! \brief ˳ʱ��
    PFF_CW = 2,
	//! \brief ��ʱ��.
    PFF_CCW = 3
};

// Categorisation of passes for the purpose of additive lighting
enum IlluminationStage
{
	/// Part of the rendering which occurs without any kind of direct lighting
	IS_AMBIENT,
	/// Part of the rendering which occurs per light
	IS_PER_LIGHT,
	/// Post-lighting rendering
	IS_DECAL, 
	/// Not determined
	IS_UNKNOWN
};

enum LightTypes
{
	//! \brief ���Դ
	LT_POINT,
	//! \brief �����Դ
	LT_DIRECTIONAL,
	//! \brief �۹��Դ
	LT_SPOTLIGHT,
};

//! \brief ��Ⱦ�����õ������ʹ��ģʽ
enum TextureType
{
	//! \brief 1D texture, used in combination with 1D texture coordinates
	TEX_TYPE_1D = 1,
	//! \brief 2D texture, used in combination with 2D texture coordinates (default)
	TEX_TYPE_2D = 2,
	//! \brief 3D texture, used in combination with 3D texture coordinates
	TEX_TYPE_3D = 3,
	//! \brief 3D cube map, used in combination with 3D texture coordinates
	TEX_TYPE_CUBE_MAP = 4,
};

//! \brief ���ݻ��Ƶķ�ʽ
enum OperationType
{
	/// A list of points, 1 vertex per point
	OT_POINT_LIST = 1,
	/// A list of lines, 2 vertices per line
	OT_LINE_LIST = 2,
	/// A strip of connected lines, 1 vertex per line plus 1 start vertex
	OT_LINE_STRIP = 3,
	/// A list of triangles, 3 vertices per triangle
	OT_TRIANGLE_LIST = 4,
	/// A strip of triangles, 3 vertices for the first triangle, and 1 per triangle after that 
	OT_TRIANGLE_STRIP = 5,
	/// A fan of triangles, 3 vertices for the first triangle, and 1 per triangle after that
	OT_TRIANGLE_FAN = 6,

	OT_QUAD_STRIP = 8,

	OT_QUAD_LIST = 9,

	OT_POLYGON = 10,

	OT_PICTURE = 12,

};

//! \brief ����������
enum VertexIndexType
{
	IT_16BIT,
	IT_32BIT
};

//! \brief ���ݻ��Ƶ�����
enum VertexOptions
{
	VO_NORMALS = 1,                  // GL_NORMAL_ARRAY + glNormalPointer()
	VO_TEXTURE_COORDS = 2,           // GL_TEXTURE_COORD_ARRAY + glTexCoordPointer()
	VO_DIFFUSE_COLOURS = 4,          // GL_COLOR_ARRAY + glColorPointer()
	VO_SPECULAR_COLOURS = 8,         // Secondary Color
	VO_BLEND_WEIGHTS = 16,      
	VO_USE_SINGLE_COLOR = 32,        // use only one kind of color
	VO_USE_POINT_SMOOTHING = 64,     // �����㷴����
	VO_MATERIAL = 128,               // ʹ�ò���
	VO_TEXTURE_COLOR = 256,          // ʹ�ò���
};

//! \brief �������
enum BlendFactor
{
	BF_ZERO						= 1,
	BF_ONE						= 2,
	BF_SRC_COLOR				= 3,
	BF_ONE_MINUS_SRC_COLOR		= 4,
	BF_DST_COLOR				= 5,
	BF_ONE_MINUS_DST_COLOR		= 6,
	BF_SRC_ALPHA				= 7,
	BF_ONE_MINUS_SRC_ALPHA		= 8,
	BF_DST_ALPHA				= 9,
	BF_ONE_MINUS_DST_ALPHA		= 10,
	BF_CONSTANT_COLOR			= 11,
	BF_ONE_MINUS_CONSTANT_COLOR	= 12,
	BF_CONSTANT_ALPHA			= 13,
	BF_ONE_MINUS_CONSTANT_ALPHA	= 14,
	BF_SRC_ALPHA_SATURATE		= 15,
};

//����ϵͳ����ʸ�����ٶ�ʸ�������÷�ʽ
enum ForceApplication
{
	ADD,		//�ۼ�
	AVERAGE     //ƽ��
};

/** The type of billboard to use. */
enum UGBillboardType
{
	/// Standard point billboard (default), always faces the camera completely and is always upright
	UGC_BBT_POINT,
	/// Billboards are oriented around a shared direction vector (used as Y axis) and only rotate around this to face the camera
	UGC_BBT_ORIENTED_COMMON,
	/// Billboards are oriented around their own direction vector (their own Y axis) and only rotate around this to face the camera
	UGC_BBT_ORIENTED_SELF,
	/// Billboards are perpendicular to a shared direction vector (used as Z axis, the facing direction) and X, Y axis are determined by a shared up-vertor
	UGC_BBT_PERPENDICULAR_COMMON,
	/// Billboards are perpendicular to their own direction vector (their own Z axis, the facing direction) and X, Y axis are determined by a shared up-vertor
	UGC_BBT_PERPENDICULAR_SELF
};
    
enum HashFunction
{
	/** Try to minimise the number of texture changes. */
	MIN_TEXTURE_CHANGE,
	/** Try to minimise the number of GPU program changes.
	@note Only really useful if you use GPU programs for all of your
	materials. 
	*/
	MIN_GPU_PROGRAM_CHANGE,

	MIN_PASS_INDEX
};

//! \brief ������ɫ���ٵĲ�������
enum TrackVertexColourType
{
	TVC_NONE        = 0x0,
	TVC_AMBIENT     = 0x1,        
	TVC_DIFFUSE     = 0x2,
	TVC_SPECULAR    = 0x4,
	TVC_EMISSIVE    = 0x8
};

//! \brief ����OverlayԪ�ص�λ��/�ߴ���Ϣ��ʲô��λ��¼
enum GuiMetricsMode
{
	GMM_RELATIVE,				//_U('left'), _U('top'), _U('height') and _U('width')�Ȳ���ת����0.0��1.0�У���ʾ�ڸ�����/�����е����λ��
	GMM_PIXELS					//λ�úͳߴ��Ծ����������귽ʽ��ʾ
};

//! \brief GPU �Ͽ������еĳ�������
enum GpuProgramType
{
	GPT_VERTEX_PROGRAM,
	GPT_FRAGMENT_PROGRAM,
	GPT_GEOMETRY_PROGRAM
};

//! \brief �����ε�����ģʽ����
/*
enum AltitudeMode
{
	//! \brief  ������
	ClampToGround = 0,
	//! \brief  ��Ե���
	RelativeToGround = 1,
	//! \brief  ���Ը߶�
	Absolute = 2,				// ����ı������������������߶ȣ�Ҳ�������óɴ�ģʽ
};*/


//! \brief ����ģʽ����
enum DrawMode
{
	//! \brief  ����ά����
	DRAW3D = 0,
	//! \brief  ʵʱդ��
	REAL_TIME_RASTER = 1,	
	//! \brief  ���Ƶ���Ļ
	DRAW_SCREEN = 2,
	//! \brief  ����ʵʱ�߳�
	REAL_TIME_ELEVATION = 3,
	//! \brief  �����޸ĸ̵߳���
	REAL_TIME_MODIFY_ELEVATION = 4,
};

/*
//! \brief 2ά3άһ�廯ʱ������ģʽ
enum UGFill3DMode
{
	//! \brief ��ʾ���
	FILL_FACE = 1, 
	//! \brief ��ʾ������
	FILL_LINE = 2, 
	//! \brief ��ʾ��������
	FILL_FACEANDLINE = 3, 
};

//! \brief �����ģʽ
enum UGBillBoardMode
{
	SCREEN_ALIGNED,//��������Ļ�ģ�ʼ������۲��
	AUTO_Z_AXIAL,//����벼���,Χ��ĳ���̶�����ת
	FIXED_ANGLE//�̶��Ƕȵģ�Ŀǰ�����أ�����Ƕ��Ժ���ٿ��ӿڣ�
};*/


//! ͼ������ķ���
enum UGImageSamplerType
{
	IMAGE3D_RESAMPLER_NONE             = 0, // ��������      �����κβ���
	IMAGE3D_RESAMPLER_NEAREST_NEIGHBOR = 1, // ���ٽ�����    ʵ��
	IMAGE3D_RESAMPLER_BILINEAR         = 2, // ˫���Բ���    ʵ��
	IMAGE3D_RESAMPLER_BICUBIC          = 3, // �����������  δ��ʵ��
};

//! \brief ������Ⱦ����ö�ٳ���
typedef enum _Graphics3DType
{
	//! \brief ��Ч����
	RST_NONE = 0, 
		//! \brief OpenGL��Ⱦ����
		RST_OGL = 1, 
		//! \brief D3D��Ⱦ����
		RST_D3D = 2,
		//! \brief OGRE��Ⱦ����
		RST_OGRE = 3,
}Graphics3DType;

enum SceneType
{
	ST_EARTH_SPHERICAL   = 0,       //�򳡾�
	ST_EARTH_PROJECTION = 1,	//ƽ���ͶӰ����
	ST_NONEARTH  = 2,           //ƽ��ľֲ����곡��
};
/*
enum UGLineStyle3D
{
	//! \brief ��ͨ��
	LINE_SIMPLE = 0, 
	//! \brief ��ά����
	LINE_PIPELINE = 1, 
};*/



//! ֧��������ʾģʽ
enum StereoMode
{
	ANAGLYPHIC,//����ɫ��ʽ
	QUAD_BUFFER,//�Ļ��淽ʽ
	HORIZONTAL_SPLIT,//ˮƽ�ָ�
	VERTICAL_SPLIT,//��ֱ�ָ�
	LEFT_EYE,//������
	RIGHT_EYE,//������
	HORIZONTAL_INTERLACE,//ˮƽ����
	VERTICAL_INTERLACE,//��ֱ����
	CHECKERBOARD//����ʽ��������DLP��ʾ��
};

//! ֧�ֵ������Ӳ�ģʽ
enum ParallaxMode
{
	NEGATIVE_PARALLAX, //���Ӳ����������Ļǰ
	POSITIVE_PARALLAX  //���Ӳ����������Ļ��
};

//! ֧�ֵķ���վ����Ϊ
enum UGStopMode
{
	FLY_STOP_WAIT,		//���е�վ���ȴ�
	FLY_STOP_ROTATION	//���е�վ�����վ�����
};

//! ֧�ֵķ��������
enum UGCameraType
{
	CAMERA,			//��վ����ת��·������ʱ����Camera��ʽ
	LOOKAT,			//��վ����ת��·������ʱ����LookAt��ʽ
	CAMERA_LOOKAT,	//��վ����תCamera��ʽ��·������ʱLookAt��ʽ
	LOOKAT_CAMERA	//��վ����תLookAt��ʽ��·������ʱCamera��ʽ
};

//! ����״̬
enum UGFlyStatus
{
	STOP,
	PAUSE,
	PLAY
};

/** Enumeration of the types of constant we may encounter in programs. 
@note Low-level programs, by definition, will always use either
float4 or int4 constant types since that is the fundamental underlying
type in assembler.
*/
enum GpuConstantType
{
	GCT_FLOAT1 = 1,
	GCT_FLOAT2 = 2,
	GCT_FLOAT3 = 3,
	GCT_FLOAT4 = 4,
	GCT_SAMPLER1D = 5,
	GCT_SAMPLER2D = 6,
	GCT_SAMPLER3D = 7,
	GCT_SAMPLERCUBE = 8,
	GCT_SAMPLER1DSHADOW = 9,
	GCT_SAMPLER2DSHADOW = 10,
	GCT_MATRIX_2X2 = 11,
	GCT_MATRIX_2X3 = 12,
	GCT_MATRIX_2X4 = 13,
	GCT_MATRIX_3X2 = 14,
	GCT_MATRIX_3X3 = 15,
	GCT_MATRIX_3X4 = 16,
	GCT_MATRIX_4X2 = 17,
	GCT_MATRIX_4X3 = 18,
	GCT_MATRIX_4X4 = 19,
	GCT_INT1 = 20,
	GCT_INT2 = 21,
	GCT_INT3 = 22,
	GCT_INT4 = 23,
	GCT_VECTOR3D = 24,
	GCT_VECTOR4D = 25,
	GCT_DOUBLE = 26,
	GCT_COLOR =27,
	GCT_UNKNOWN = 99
};

/** Enumeration of GPU vendors. */
enum GPUVendor
{
	GPU_UNKNOWN = 0,
	GPU_NVIDIA = 1,
	GPU_ATI = 2, 
	GPU_INTEL = 3,
	GPU_S3 = 4,
	GPU_MATROX = 5,
	GPU_3DLABS = 6,
	GPU_SIS = 7,
	GPU_IMAGINATION_TECHNOLOGIES = 8,
	GPU_APPLE = 9,  // Apple Software Renderer
	GPU_NOKIA = 10,
	/// placeholder
	GPU_VENDOR_COUNT = 11
};

/// Enum describing the various actions which can be taken onthe stencil buffer

//! \brief ģ�建�����ö�ٳ�����
enum StencilOperation
{
	/// Leave the stencil buffer unchanged
	// ����ģ�建��ֵ����
	SOP_KEEP,

	/// Set the stencil value to zero
	// ����ģ�建��ֵ���Ϊ��
	SOP_ZERO,

	/// Set the stencil value to the reference value
	// �滻ԭ����ģ�建��
	SOP_REPLACE,

	/// Increase the stencil value by 1, clamping at the maximum value
	// ģ�建��ֵ����һ
	SOP_INCREMENT,

	/// Decrease the stencil value by 1, clamping at 0
	// ģ�建��ֵ����һ
	SOP_DECREMENT,

	/// Increase the stencil value by 1, wrapping back to 0 when incrementing the maximum value
	// ģ�建��ֵ����һ�����������ֵ��ֵΪ��
	SOP_INCREMENT_WRAP,

	/// Decrease the stencil value by 1, wrapping when decrementing 0
	// ģ�建��ֵ����һ�����ﵽ��Сֵ���ټ���
	SOP_DECREMENT_WRAP,

	/// Invert the bits of the stencil buffer
	// ģ�建��ֵλȡ��
	SOP_INVERT

};



//! \brief ��ά��ͨ��
class BASE3D_API UGCommon3D
{
public:
	//! \brief ��Defualt�ַ������ַ���ת��ΪUTF8���ַ�����
	//! \param str Defualt�ַ������ַ���[in]��
	//! \return ����UTF8���ַ�����
	static UGMBString UGToKmlString(UGString str);
	//! \brief ��UTF8�ַ������ַ���ת��ΪDefualt���ַ�����
	//! \param str UTF8�ַ������ַ���[in]��
	//! \return ����Defualt���ַ�����
	static UGString KmlToUGString(UGMBString str);
	//! \brief TTF���·������
// 	static UGString ms_strTTFLibPath;
// 	//! \brief TTF����߶�
 	static UGushort ms_uTTFHeight;
	//! \brief ������Դ�ļ�������Ŀ¼��Ĭ��Ϊ�ա�������ͻ�����UAC���ƺ󣬿ͻ����޷����������Լ�������ļ���Դ������
	// �ೡ����Ӧ��Ҳ���ܹ�ͨ�õģ��Ͼ�û�ж���Դ�����޸Ĳ�����Ĺ��ܡ�
	static UGString ms_strSceneResFoloderPath;

	//��ά��Ч����Ƿ����
	static UGbool ms_bIsSpace3DEffectVailed;

};

}

#endif

