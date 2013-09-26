#ifndef UGENGDEFS_H
#define UGENGDEFS_H

#include "Geometry/UGGeoRegion.h"
#include "OGDC/OgdcQueryDef.h"
#include "OGDC/OgdcDsConnection.h"
//#include "OGDC/OgdcFieldInfo.h"

#if !defined SYMBIAN60 /*&& !defined  OS_ANDROID && !defined (IOS)*/
#include "Geometry/UGFeature.h"

#else
#include  "Element/OgdcFieldInfo.h"

typedef OgdcFieldInfo UGFieldInfo;
typedef OgdcFieldInfos UGFieldInfos;

#endif

namespace UGC
{
// �����������ݼ�������
const UGString strTexture = _U("sm_Texture_Lib");
// �����������ݼ���Ӧ�Ľ��������ݼ�������
const UGString strTextureTier = _U("sm_Texture_Tier");
	
#define UGMAXONCEGEOSIZE	20971520
#define UGMAXROOTLEAFSIZE   1258496
#define UGMAXTABLENAMELENGTH 17

#define UGRTREEEDITED		5
	
#define UGSYSDATE			_U("UGSysDate")	//����ͳһ��ǰϵͳʱ���ʶ


//===================================================================================================================
//{{ͼ���ֶζ��� 
//===================================================================================================================
//		����				�ֶ���				����			˵��		���õ�ͼ������
//...................................................................................................................
#define LF_OBJ_ID		_U("SmID")			// (dbLong)			�ڲ����	(All)
#define LF_USER_ID		_U("SmUserID")		// (dbLong)			�û����	(All)
#define LF_TREE_INDEX	_U("SmKey")			// (dbLong)			�Ĳ�������	ALL Geometry Dataset.   
#define LF_LT_KEY		_U("SmLTKey")		// (dbLong)			��������	All Geometry Dataset.
#define LF_RB_KEY		_U("SmRBKey")		// (dbLong)			��������	All Geometry Dataset.
#define LF_GEO_POS		_U("SmGeoPos")		// (dbLong)			Geometry��λ��	All Geometry Dataset.
#define LF_GEOMETRY		_U("SmGeometry")	// (dbLongBinary)	��������	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_VERTEXSEQ	_U("SmVertexSeq")	// (dbLongBinary)	������������	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_GEO_TYPE		_U("SmGeoType")		// (dbSingle)		���������	ltCAD ,because geometry data can't distinguish type of itself
#define LF_SDRI_W		_U("SmSdriW")		// (dbDouble)		��С������	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_SDRI_N		_U("SmSdriN")		// (dbDouble)		��С������	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_SDRI_E		_U("SmSdriE")		// (dbDouble)		��������	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_SDRI_S		_U("SmSdriS")		// (dbDouble)		���������	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_GRANULE		_U("SmGranule")		//(dbDouble)		���������  ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_CHECKED_USER_ID	_U("SmCheckedUserID")	//(dbLong)	��¼�û�ID	(ALL)
#define LF_EDIT_STATE	_U("SmEditState")	//(dbInteger)		�༭״̬	(ALL)
#define LF_SDRI_T		_U("SmSdriT")		// (dbDouble)		��С�߳�	ltTin
#define LF_SDRI_B		_U("SmSdriB")		// (dbDouble)		���߳�	ltTin
#define LF_SDRI_I		_U("SmSdriI")		// (dbDouble)		��С����	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_NODE_ID		_U("SmNodeID")		// (dbLong)			�ڵ��ţ�	ltNetwork,��ǰĬ��ʹ��SmID,���ڵ�������һ���ֶ�
#define LF_FNODE		_U("SmFNode")		// (dbLong)			��ʼ�ڵ�	ltNetwork
#define LF_TNODE		_U("SmTNode")		// (dbLong)			��ֹ�ڵ�	ltNetwork
#define LF_RESISTANCE_A	_U("SmResistanceA")	// (dbDouble)		����������	ltNetwork
#define LF_RESISTANCE_B	_U("SmResistanceB")	// (dbDouble)		����������	ltNetwork
#define LF_X			_U("SmX")			// (dbDouble)		��������	ltPoint & ltPoint3D
#define LF_Y			_U("SmY")			// (dbDouble)		���������	ltPoint & ltPoint3D
#define LF_Z			_U("SmZ")			// (dbDouble)		��ĸ߳�	ltPoint3D
#define LF_LENGTH		_U("SmLength")		// (dbDouble)		����		ltLine& Network
#define LF_AREA			_U("SmArea")		// (dbDouble)		���		ltRegion
#define LF_PERIMETER	_U("SmPerimeter")	// (dbDouble)		�ܳ�		ltRegion 
#define LF_ASPECT		_U("SmAspect")		// (dbDouble)		����		ltTin
#define LF_SLOPE		_U("SmSlope")		// (dbDouble)		�¶�		ltTin
#define LF_TOPO_ERROR	_U("SmTopoError")	// (dbLong)			���˴���	ltNetwork, ltLine
#define LIB_SMID		_U("SmLibTileID")
#define LF_UUID			_U("SmUUID")		// (dbChar(36))		ȫ��Ψһ����	ALL Geometry Dataset

#define LF_CONJOINT_POINTS		_U("SmConjointPoints")	// (dbLongBinary)			TIN�ڵ���ٽ��㼯��	ltPointGL
#define	LF_POINT_COLOR			_U("SmPointColor")		//TIN�ڵ����ɫ����ֵ��ʾ��Ч

//{{ route���ݼ�����Section����ֶ�
#define LF_ROUTE_ID				_U("SmRouteID")
#define LF_USER_ROUTE_ID		_U("SmUserRouteID")

#define LF_SECTION_ARC			_U("SmEdgeID")
#define LF_SECTION_FROM_MEASURE _U("SmFromMeasure")	
#define LF_SECTION_TO_MEASURE	_U("SmToMeasure")	
#define LF_SECTION_FROM_POS		_U("SmFromPos")		
#define LF_SECTION_TO_POS		_U("SmToPos")		

//}}

//{{
#define LF_MATCH_ERROR _U("SmMatchError") // ʹ��CSmDataSource::UpdateFromLcaPnts()����
                                          // �ӱ�־��ƥ���������ݵ��������ݼ�ʱ���棩��
                                          // ��¼��ƥ�����Ŀ��
                                             
//}}

//{{
#define LF_TOPO_LPOLY  _U("SmTopoLPolygon")
#define LF_TOPO_RPOLY  _U("SmTopoRPolygon")

//}}
//					0	- �޴���
//					1	- ��ʼ�ڵ������ڵ�
//					2	- ��ֹ�ڵ������ڵ�
//					3	- �����ڵ㶼�����ڵ�
//					����- �����춨��...)

/*
#define LF_RASTER_LEVEL		"SmRLevel"		// (dbLong)			դ��ֱ���			ltRaster
#define LF_RASTER_INDEX_X		"SmRIndexX"		// (dbLong)			դ���X����(�к�)	ltRaster
#define LF_RASTER_INDEX_Y		"SmRIndexY"		// (dbLong)			դ���Y����(�к�)	ltRaster

#define LF_SYMBOL_STYLE			"SmSStyle"
#define LF_SYMBOL_SIZE			"SmSSize"
#define LF_SYMBOL_ROTATION		"SmSRotation"
#define LF_SYMBOL_TEXT			"SmSText"

#define LF_PEN_STYLE			"SmPStyle"
#define LF_PEN_WIDTH			"SmPWidth"
#define LF_PEN_COLOR			"SmPColor"

#define LF_BRUSH_STYLE			"SmBStyle"
#define LF_BRUSH_FRONT_COLOR	"SmBFColor"
#define LF_BRUSH_BACK_COLOR		"SmBBColor"
 */

//===================================================================================================================
//}}ͼ���ֶζ���
//===================================================================================================================

#if PACKAGE_TYPE==PACKAGE_UGC


//˵��������һЩ����������Ҫʹ�õ�ϵͳ�������

//===============================================================================
//			����					����						˵��		
//................................................................................
#define		TN_REGISTER_TABLE		_U("SmRegister")			//���ݿ���ʸ�����ݼ���ע���������ʸ�����ݼ�����Ϣ	
#define		TN_IMGREGISTER_TABLE	_U("SmImgRegister")			//���ݿ���Ӱ�����ݼ���ע���������Ӱ�����ݼ�����Ϣ	
#define     TN_DATASOURCE_INFO		_U("SmDataSourceInfo")		//����Դ��Ϣ��
#define		TN_META_ELEM_TABLE		_U("SmMetaElementTable")	//����Դ�д������Ԫ���ݵı�
#define		TN_USERS				_U("SmUsers")				//��ų������û�
#define		TN_TABLE_FIELDINFO		_U("SmFieldInfo")			//����ֶ���ص���Ϣ���������Format��



//˵��������һЩ����������Ҫʹ�õĴ洢������.

//===============================================================================
//			����					����						˵��		
//................................................................................
#define		SP_CREATE_USER			_U("smsp_CreateUser")		//�����û��Ĵ洢����
#define		SP_CREATE_DATASET		_U("smsp_CreateDataset")	//�������ݼ��Ĵ洢����
#define		SP_DELETE_DATASET		_U("smsp_DeleteDataset")	//ɾ�����ݼ��Ĵ洢����
#define		SP_SET_BOUNDS			_U("smsp_SetBounds")		//�������ݼ���Χ�洢����
#define		SP_COPY_DATASET			_U("smsp_CopyDataset")		//���ظ������ݼ��Ĵ洢����
#define		SP_CREATE_DATABASE		_U("smsp_CreateDatabase")	//�����µ�����Դ�Ĵ洢����

//SmRegister���е��ֶ�=======================================================================
//			����				�ֶ���					����			˵��	
//...........................................................................................
#define		RF_ID				_U("SmDatasetID")		//(dbLong)		//Dataset ID
#define		RF_DATASET_NAME		_U("SmDatasetName")		//(dbText)		//Dataset Name
#define		RF_TABLE_NAME		_U("SmTableName")		//(dbText)		//Geomey and Properties Table Name
#define		RF_INDEX_TABLE_NAME	_U("SmIndexTableName")	//(dbText)		//Index Table Name
#define		RF_SUB_TABLE_NAME	_U("SmSubTableName")	//(dbText)		//Sub Table name
#define		RF_IS_SUB			_U("SmIsSub")			//(dbChar)		//Is/Not sub table
#define		RF_DATASET_TYPE		_U("SmDatasetType")		//(dbInteger)	//Dataset's type
#define		RF_RECORD_COUNT		_U("SmRecordCount")		//(dbInteger)	//Object count in dataset.
#define		RF_INDEX_LEVEL		_U("SmIndexLevel")		//(dbInteger)	//Index level of the dataset.
#define		RF_LEFT				_U("SmLeft")			//(dbLong)		//Dataset Bounds' Left
#define		RF_RIGHT			_U("SmRight")			//(dbLong)		//Dataset Bounds' Right
#define		RF_TOP				_U("SmTop")				//(dbLong)		//Dataset Bounds' Top
#define		RF_BOTTOM			_U("SmBottom")			//(dbLong)		//Dataset Bounds' Bottom
#define		RF_MAXZ				_U("SmMaxZ")			//(dbDouble)	//Max Z Value of Dataset
#define		RF_MINZ				_U("SmMinZ")			//(dbDouble)	//Min Z Value fo Dataset
#define		RF_GRID_SIZE		_U("SMGRIDSIZE")		//(dbDouble)	//Grid Size fo Dataset, Used for Index.
#define		RF_USER_ID			_U("SmUserID")			//(dbInteger)	//Long transaction user id.
#define		RF_DT_VERSION		_U("SmDtVersion")		//(dbInteger)	//Data updated version.
#define		RF_OPTION			_U("SmOption")			//(dbInteger)	//Option of the dataset.
#define		RF_ENC_TYPE			_U("SmEncType")			//(dbInteger)	//Spatial data encoded type.
#define		RF_DESCRIPTION		_U("SmDescription")		//(dbText)		//Description of the dataset.
#define		RF_THUMB			_U("SmThumb")			//(dbLongBinary)//Thumb of the dataset.
#define		RF_TOLERANCE_FUZZY	_U("SmToleranceFuzzy")	//(dbDouble)	//Fuzzy tolerance of the dataset.
#define		RF_TOLERANCE_DANGLE	_U("SmToleranceDangle")	//(dbDouble)	//Dangle tolerance of the dataset.
#define		RF_TOLERANCE_NODESNAP _U("SmToleranceNodeSnap")	//(dbDouble)//NodeSnap tolerance of the dataset.
#define		RF_TOLERANCE_SMALL_POLYGON	_U("SmToleranceSmallPolygon")	//(dbDouble)	//Small polygon tolerance of the dataset
#define		RF_TOLERANCE_GRAIN	_U("SmToleranceGrain")	//(dbDouble)	//Grain tolerance of the dataset.
#define		RF_LASTUPDATE		_U("SmLastUpdate")		//(dbDate)		//The lastupdate time of the dataset.
#define		RF_MAX_GEOMETRY_SIZE	_U("SmMaxGeometrySize")	//(dbDouble)//The max geometry size of the dataset.
#define		RF_ONCE_FETCH_COUNT	_U("SmOnceFetchCount")	//(dbInteger)	//Once fetch count from server.
#define		RF_OPTIMIZE_COUNT	_U("SmOptimizeCount")	//(dbInteger)	//Optimize parameter of the dataset.
#define		RF_OPTIMIZE_RATIO	_U("SmOptimizeRatio")	//(dbFloat)		//Optimize parameter of the dataset.
//...........................................................................................

//SmImgRegister���е��ֶ�=======================================================================
//			����				�ֶ���					����			˵��	
//...........................................................................................
//#define		RF_ID					"SmDatasetID"		//(dbLong)		//Dataset ID
//#define		RF_DATASET_NAME			"SmDatasetName"		//(dbText)		//Dataset Name
//#define		RF_TABLE_NAME			"SmTableName"		//(dbText)		//Geomey and Properties Table Name
//#define		RF_DATASET_TYPE			"SmDatasetType"		//(dbInteger)	//Dataset's type
//#define		RF_OPTION				"SmOption"			//(dbInteger)	//Option of the dataset.
#define		RF_PIXEL_FORMAT				_U("SmPixelFormat")		//(dbInteger)	//Pixel format of the raster.
#define		RF_WIDTH					_U("SmWidth")			//(dbInteger)	//Width(pixels) of the raster.
#define		RF_HEIGHT					_U("SmHeight")			//(dbInteger)	//Height(pixels) of the raster.
#define		RF_E_BLOCK_SIZE				_U("SmeBlockSize")		//(dbInteger)	//e block size of the raster.
#define		RF_MAX_BLOCK_SIZE			_U("SmMaxBlockSize")	//(dbInteger)	//Max block size of the raster.
//#define		RF_MAXZ					"SmMaxZ"			//(dbDouble)	//Max Z Value of Dataset
//#define		RF_MINZ					"SmMinZ"			//(dbDouble)	//Min Z Value of Dataset
#define		RF_PYRAMID					_U("SmPyramid")			//(dbText)		//Parymid table name of the raster.
#define		RF_PYRAMID_LEVEL			_U("SmPyramidLevel")	//(dbInteger)	//Parymid level of the dataset.
#define		RF_BLOCK_SIZE				_U("SmBlockSizes")		//(dbInteger)	//Block size of the raster.
#define		RF_PALETTE					_U("SmPalette")			//(dbLongBinary)//Palette of the raster.
#define		RF_GEO_LEFT					_U("SmGeoLeft")			//(dbDouble)	//Dataset Bounds' Left
#define		RF_GEO_RIGHT				_U("SmGeoRight")		//(dbDouble)	//Dataset Bounds' Right
#define		RF_GEO_TOP					_U("SmGeoTop")			//(dbDouble)	//Dataset Bounds' Top
#define		RF_GEO_BOTTOM				_U("SmGeoBottom")		//(dbDouble)	//Dataset Bounds' Bottom
#define		RF_CLIP_REGION				_U("SmClipRegion")		//(dbLongBinary)//Clip region of raster.
#define		RF_TOLERANCE_SMALLPOLYGON	_U("SmToleranceSmallPolygon") 
//...........................................................................................


//SmDataSourceInfo���е��ֶ�=======================================================================
//			����				�ֶ���					����			˵��	
//...........................................................................................
#define		DF_VERSION			_U("SmVersion")			//dbLong		����Դ�汾��
#define		DF_FLAG				_U("SmFlag")			//dbLong		����Դ��־
#define		DF_COORDSYS			_U("SmCoordSys")		//dbLong		����ϵ
#define		DF_COORDUNIT		_U("SmCoordUnit")		//dbLong		���굥λ
#define		DF_DISTANCEUNIT		_U("SmDistanceUnit")	//dbLong		���ȵ�λ
#define		DF_PROJECTINFO		_U("SmProjectInfo")		//dbLongBinary	//ͶӰϵ����
#define		DF_DSDESCRIPTION	_U("SmDsDescription") 
#define		DF_MINORVERSION		_U("SmMinorVersion") 
#define		DF_VERSIONDATE		_U("SmVersionDate")		
//...........................................................................................

//SmFieldInfo���е��ֶ�=======================================================================
//			����				�ֶ���					����			˵��	
//...........................................................................................
#define		SMF_FIELD_ID		_U("SmID")				//dbInteger		�ֶ�ID
#define		SMF_TABLE_NAME		_U("SmTableName")		//dbText		���ݱ���
#define		SMF_DATASET_ID		_U("SmDatasetID")		//dbLong		���ݼ���ID
#define		SMF_FIELD_NAME		_U("SmFieldName")		//dbText		�ֶ���
#define		SMF_FIELD_CAPTION	_U("SmFieldCaption")	//dbText		�ֶα���
#define		SMF_FIELD_TYPE		_U("SmFieldType")		//dbLong		�ֶε�����
#define		SMF_FIELD_FORMAT	_U("SmFieldFormat")		//dbText		�ֶ���ʾ��ʽ
#define		SMF_FIELD_SIGN		_U("SmFieldSign")		//dbLong		�ֶα�ʶ����NodeID,FNode,TNode,EdgeID,RouteID��
#define		SMF_FIELD_SIZE		_U("SmFieldSize")		//dbLong		�ֶγ���
#define		SMF_FIELD_DOMAIN	_U("SmFieldDomain")		//dbText		�ֶ�ֵ��
#define		SMF_FIELD_UPDATABLE	_U("SmFieldUpdatable")	//dbBoolean		�ֶ�ֵ�Ƿ���޸�
//...........................................................................................

//ʱ�����ݿ���Ҫʹ�õ��ֶ�=======================================================================
//			����				�ֶ���					����			˵��	
//...........................................................................................
#define		SEQ_START			_U("SmSequenceStart")	//dbDate		��ʼʱ���
#define		SEQ_END				_U("SmSequenceEnd")		//dbDate		����ʱ���
#define		SEQ_STATE			_U("SmSequenceState")	//dbBoolean		ʱ��״̬
#define		SEQ_ORG_ID			_U("SmSequenceOrgID")	//dbLong		ʱ��༭����ԭʼ��SMID
//...........................................................................................

//Engine ֱ��ʹ�� OGDC����
//##ModelId=482030510177
typedef OgdcLinkItem                    UGLinkItem;
//##ModelId=482030510179
typedef OgdcJoinItem					UGJoinItem;
//##ModelId=482030510186
typedef OgdcDsConnection				UGDsConnection;

//Engine ��չ OGDC ��ö������
#define FieldTypeCurrency		5
#define FieldTypeDgnLink		129


//##ModelId=482030510198
enum DatasetState
{
	//##ModelId=4820305101A6
	dsCheckedOut	= 0x00000001,
	//##ModelId=4820305101A7
	dsLocked		= 0x00000002		
};

//##ModelId=4820305101B5
enum LongTransState
{
	//##ModelId=4820305101B7
	ltsAdded		= 0x00000001,
	//##ModelId=4820305101B8
	ltsModified		= 0x00000002,
	//##ModelId=4820305101B9
	ltsDeleted		= 0x00000004
};

//##ModelId=4820305101C5
enum SpatialQueryOption
{
	//##ModelId=4820305101C7
	SQInner			= 0x00000001,
	//##ModelId=4820305101D4
	SQMaybe			= 0x00000002,
	//##ModelId=4820305101D5
	SQOuter			= 0x00000004
};

//##ModelId=4820305101E4
struct UG_INDEX_ITEM
{
	//##ModelId=4820305101E6
	UGuint left;
	//##ModelId=4820305101E7
	UGuint top;
	//##ModelId=4820305101E8
	UGuint right;
	//##ModelId=4820305101E9
	UGuint bottom;
	//##ModelId=4820305101F4
	UGuint nID;
	//##ModelId=4820305101F5
	UGuint nPos;

	UGint GetSizeofLenth()
	{
		UGint nLenght=0;
		nLenght = 6*sizeof(left);
		return nLenght;
	}
};

//##ModelId=482030510203
struct UG_CAD_INDEX_ITEM
{
	//##ModelId=482030510205
	UGuint left;
	//##ModelId=482030510206
	UGuint top;
	//##ModelId=482030510207
	UGuint right;
	//##ModelId=482030510213
	UGuint bottom;
	//##ModelId=482030510214
	UGuint nID;
	//##ModelId=482030510215
	UGuint nPos;
	//##ModelId=482030510216
	UGuint nType;

	UGint GetSizeofLenth()
	{
		UGint nLenght=0;
		nLenght = 7*sizeof(left);
		return nLenght;
	}
};

//##ModelId=482030510222
struct UG_SUPER_INDEX_ITEM
{
	//##ModelId=482030510232
	UGuint left;
	//##ModelId=482030510233
	UGuint top;
	//##ModelId=482030510234
	UGuint right;
	//##ModelId=482030510235
	UGuint bottom;
	//##ModelId=482030510236
	UGuint nID;
	//##ModelId=482030510237
	UGuint nPos;
	//##ModelId=482030510242
	UGuint nType;
	//##ModelId=482030510243
	UGuint dwX;
	//##ModelId=482030510244
	UGuint dwY;
	//##ModelId=482030510245
	UGdouble dZ;
};

//##ModelId=482030510251
struct UG_DATASET_TIER_NAME
{
	//##ModelId=482030510253
	UGString strDataset;
	//##ModelId=482030510254
	int nTileID;
	//##ModelId=482030510255
	UG_DATASET_TIER_NAME()
	{
		strDataset = _U("");
		nTileID    = -1;
	}
};


#define UUIDLENGTH			36
#define ROOTVERSIONNAME		_U("RootVersion")	//���汾Ĭ������

//! \brief �����ύö��
enum UGPostOption
{
	POConflictDest			= 1, //������ͻ��Ŀ��汾Ϊ׼
	POConflictCur			= 2, //������ͻ�Ե�ǰ�汾Ϊ׼
	POConflictCommon		= 3, //������ͻ�Ա�����֮ǰ��Ŀ��汾Ϊ׼
	POConflictUnion			= 4, //������ͻ��Union�ռ����
};

typedef struct UGVersionInfo
{
	UGint nVersionID;				//�汾��
	UGString strVersionName;		//�汾����
	UGString strCreator;			//�汾������
	UGString strDescription;		//�汾������Ϣ
	UGint nParentVersionID;			//���汾��
	UGTime CreationTime;			//�汾����ʱ��
	UGVersionInfo()
	{
		nVersionID = 0;
		strVersionName = _U("");
		strCreator = _U("");
		strDescription = _U("");
		nParentVersionID = 0;
		CreationTime = UGTime::GetCurTime();
	}
}VERSIONINFO;

//Э�������Ϣ
typedef struct UGReconcileInfo
{
	UGString strDestVersionName;
	UGint nCurSeriesID, nCurLastActionID;	//Э��ǰ��ǰ�汾��SeriesID��LastActionID
	UGint nDestSeriesID, nDestLastActionID;	//Э��ǰĿ��汾��SeriesID��LastActionID
	UGint nMaxCommonActionID;				//�������ActionID
	UGint nSeriesID, nLastActionID;			//Э�����SeriesID��LastActionID
	UGArray<UGint> aryConflictIDs;			//ʸ������:��ͻ����IDs,դ������:��ͻ������к�ÿ2�����ݱ�ʾһ�����к�,������ʾ�к�,ż����ʾ�к�
	UGReconcileInfo()
	{
		strDestVersionName = _U("");
		nCurSeriesID = 0;
		nCurLastActionID = 0;
		nDestSeriesID = 0;
		nDestLastActionID = 0;
		nMaxCommonActionID = 0;
		nSeriesID = 0;
		nLastActionID = 0;
		aryConflictIDs.SetSize(0);
	}
	~UGReconcileInfo()
	{
		aryConflictIDs.RemoveAll();

	}
}RECONCILEINFO;

enum UGDuplicateType
{
	CheckOut	=	0,		//���߸���
	OneWay		=	1,		//������¸���
	TwoWay		=	2		//˫��ͬ������
};

typedef struct UGDuplicateInfo
{
	UGString	strID;				//����ID
	UGString	strName;			//��������
	UGString	strDes;				//��������
	UGString	strCreator;			//����������
	UGString	strIDFieldName;		//����Ψһ��ʶ�ֶ�
	UGint		nDatasetID;			//�������ݼ�ID
	UGint		nRole;				//0����������1���Ӹ���
	UGint		nType;				//�������ͣ�0�����߸�����1�����򸴱���2��˫�򸴱�
	UGint		nExchangeState;		//0��Data Sender��1��Data Receiver
	UGint		nUpdateSequence;	//���Զ�Ӧ����������������
	UGint		nSynchroSequence;	//���Ϊ��Ӧ����ͬ��������

	UGDuplicateInfo()
	{
		strID = _U("");
		strName = _U("");
		strDes = _U("");
		strCreator = _U("");
		nRole = 0;
		nType = 0;
		nExchangeState = 0;
		nUpdateSequence = 0;
		nSynchroSequence = 0;
	}
}DUPLICATEINFO;

typedef struct UGDiffMsgInfo
{
	UGString	strID;
	UGString	strName;
	UGint		nObjCount;
	UGint		nMaxSequence;
	UGint		nRole;
	UGDiffMsgInfo()
	{
		strID = _U("");
		strName = _U("");
		nObjCount = 0;
		nMaxSequence = 0;
		nRole = 0;
	}
}DIFFMSGINFO;

#endif // end declare ugc sdk
}
#endif

