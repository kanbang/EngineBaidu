/*******************************************************************/
/*                                                                 */
/*         Copyright (C) 2012 SuperMap Software Co., Ltd.          */
/*                   All Rights Reserved                           */
/*                                                                 */
/*******************************************************************/
/******************************************************************************
* FILENAME  - LicenseReader.h
*   
* USAGE     - SuperMap License Core Library
*
* REVISION HISTORY - 
******************************************************************************/ 

#if !defined(LICENSEREADER_H)
#define LICENSEREADER_H

#pragma once

// ���ڵ�Ӳ������ֻ��֧��Windows
#if (defined(SOLARIS) || defined(_AIX) || defined(LINUX))
	
#else
	#define SupportPlatForm
#endif

#include <time.h>

const long MAX_CHAR				= 256;		// �ڲ�ʹ�õ���ʱ�ַ�������
const long MAX_RAW_USER			= 8;		// �û�����󳤶ȣ����ֽڼ��㣬8����ĸ��4������
const long MAX_RAW_COMPANY		= 16;		// ��˾����󳤶ȣ����ֽڼ��㣬16����ĸ��8������
const long MAX_HEARTBEAT_DAY	= 43200;	// ������ʧЧ���ʱ�䣬������㣬12Сʱ
const long CurrentReaderCount	= 3;

#define LABEL_Server			("Server")
#define LABEL_User				("User")
#define LABEL_Company			("Company")
#define LABEL_LicMode			("LicMode")
#define LABEL_LicIdentifyCode	("LicIdentifyCode")
#define LABEL_LicPath			("LicPath")
#define LABEL_LicData			("LicData")
#define LABEL_LicVersion		("LicVersion")
#define LABEL_LicMaxConnect		("LicMaxConnect")


// Ӳ�����Ĵ������100-800�������Լ��Ĵ������5000��ʼ
#define SuperMap_License_Error_Code_Base				5000
#define HASPHL_License_Error_Code_Base					6000
#define SuperPro_License_Error_Code_Base				7000

#define SuperMap_License_Error_LaterExpiredDate			(SuperMap_License_Error_Code_Base + 1)
#define SuperMap_License_Error_EarlyStartDate			(SuperMap_License_Error_Code_Base + 2)
#define SuperMap_License_Error_WrongLicenseData			(SuperMap_License_Error_Code_Base + 3)
#define SuperMap_License_Error_WrongLicenseMode			(SuperMap_License_Error_Code_Base + 4)
#define SuperMap_License_Error_OpenISVFileFailed		(SuperMap_License_Error_Code_Base + 5)
#define SuperMap_License_Error_WrongProductVersion		(SuperMap_License_Error_Code_Base + 6)
#define SuperMap_License_Error_VerifyDataFailed			(SuperMap_License_Error_Code_Base + 7)
#define SuperMap_License_Error_SecureUpdateDllNotFound	(SuperMap_License_Error_Code_Base + 8)
#define SuperMap_License_Error_ApplyUpdateCodeNotFound	(SuperMap_License_Error_Code_Base + 9)

// �Ժ�ÿ����һ����Ʒ��Ҫ�ɵĻ��У�
// 1. ��������� LABEL_XXXX
// 2. ����LibProductTypeö�٣�������
// 3. ����LicenseReader.cpp�� GetProductName����
// 3. ��LicenseRead\LicenseReadWrap.h �е� ProductWrapö�������
// 4. ��LicenseRead\LicenseReadWrap.cpp �е�GetProductDictionary���������ӣ���д��������
// ��SuperMap.License���̵�������Դ�������Դ������Program.cs�ļ�������
// 3��LibProductType��Ӧ��LicenseID����SentinelKeysLicense.h����
// 4������HASP��Ӧ��ID����HASPKeysLicense.h����

#define LABEL_CommonLicense								("CommonLicense")
#define LABEL_ObjectsCoreDevelop						("ObjectsCoreDevelop")
#define LABEL_ObjectsCoreRuntime						("ObjectsCoreRuntime")
#define LABEL_ObjectsSDXDevelop							("ObjectsSDXDevelop")
#define LABEL_ObjectsSDXRuntime							("ObjectsSDXRuntime")
#define LABEL_ObjectsSpaceDevelop						("ObjectsSpaceDevelop")
#define LABEL_ObjectsSpaceRuntime						("ObjectsSpaceRuntime")
#define LABEL_ObjectsLayoutDevelop						("ObjectsLayoutDevelop")
#define LABEL_ObjectsLayoutRuntime						("ObjectsLayoutRuntime")
#define LABEL_ObjectsSpatialDevelop						("ObjectsSpatialDevelop")
#define LABEL_ObjectsSpatialRuntime						("ObjectsSpatialRuntime")
#define LABEL_ObjectsNetworkDevelop						("ObjectsNetworkDevelop")
#define LABEL_ObjectsNetworkRuntime						("ObjectsNetworkRuntime")
#define LABEL_ObjectsTopologyDevelop					("ObjectsTopologyDevelop")
#define LABEL_ObjectsTopologyRuntime					("ObjectsTopologyRuntime")
#define LABEL_ObjectsAddressMatchingDevelop				("ObjectsAddressMatchingDevelop")
#define LABEL_ObjectsAddressMatchingRuntime				("ObjectsAddressMatchingRuntime")
#define LABEL_ObjectsCoreEmbedded						("ObjectsCoreEmbedded")
#define LABEL_ObjectsFMEVector							("ObjectsFMEVector")
#define LABEL_ObjectsFMEEsri							("ObjectsFMEEsri")
#define LABEL_ObjectsFMERaster							("ObjectsFMERaster")
#define LABEL_ObjectsFMEOther							("ObjectsFMEOther")
#define LABEL_ObjectsNauticalChartDevelop				("ObjectsNauticalChartDevelop")
#define LABEL_ObjectsNauticalChartRuntime				("ObjectsNauticalChartRuntime")
#define LABEL_ObjectsRealspaceSpatialAnalystDevelop		("ObjectsRealspaceSpatialAnalystDevelop")
#define LABEL_ObjectsRealspaceSpatialAnalystRuntime		("ObjectsRealspaceSpatialAnalystRuntime")
#define LABEL_UniversalGISCore							("UniversalGISCore")
#define LABEL_ObjectsTrafficAnalystDevelop				("ObjectsTrafficAnalystDevelop")
#define LABEL_ObjectsTrafficAnalystRuntime				("ObjectsTrafficAnalystRuntime")
#define LABEL_ObjectsRealspaceNetworkAnalystDevelop		("ObjectsRealspaceNetworkAnalystDevelop")
#define LABEL_ObjectsRealspaceNetworkAnalystRuntime		("ObjectsRealspaceNetworkAnalystRuntime")
#define LABEL_ObjectsRealspaceEffectDevelop				("ObjectsRealspaceEffectDevelop")
#define LABEL_ObjectsRealspaceEffectRuntime				("ObjectsRealspaceEffectRuntime")

#define LABEL_Deskpro_NET						("DeskproNET")
#define LABEL_Express_NET						("ExpressNET")
#define LABEL_Viewer_NET						("ViewerNET")
#define LABEL_DeskproNETTopology				("DeskproNETTopology")
#define LABEL_DeskproNETTrafficNetwork			("DeskproNETTrafficNetwork")
#define LABEL_DeskproNETFacilityNetwork			("DeskproNETFacilityNetwork")
#define LABEL_DeskproNETSpatial					("DeskproNETSpatial")
#define LABEL_DeskproNETNauticalChart			("DeskproNETNauticalChart")
#define LABEL_DeskproNETGeoProcesser			("DeskproNETGeoProcesser")
#define LABEL_DeskproNETRealspaceSpatialAnalyst	("DeskproNETRealspaceSpatialAnalyst")
#define LABEL_DeskproNETTrafficAnalyst			("DeskproNETTrafficAnalyst")
#define LABEL_DeskproNETRealspaceEffect			("DeskproNETRealspaceEffect")

#define LABEL_iServerStandard					("iServerStandard")
#define LABEL_iServerProfessional				("iServerProfessional")
#define LABEL_iServerEnterprise					("iServerEnterprise")
#define LABEL_iServerSpatial					("iServerSpatial")
#define LABEL_iServerNetwork					("iServerNetwork")
#define LABEL_iServerTrafficTransfer			("iServerTrafficTransfer")
#define LABEL_iServerSpace						("iServerSpace")
#define LABEL_iServerNauticalChart				("iServerNauticalChart")
#define LABEL_iServerExpress					("iServerExpress")

#define LABEL_SFCObjectsCoreDevelop				("SFCObjectsCoreDevelop")
#define LABEL_SFCObjectsCoreRuntime				("SFCObjectsCoreRuntime")
#define LABEL_SFCObjects3DDevelop				("SFCObjects3DDevelop")
#define LABEL_SFCObjects3DRuntime				("SFCObjects3DRuntime")
#define LABEL_SFCObjectsTopologyDevelop			("SFCObjectsTopologyDevelop")
#define LABEL_SFCObjectsTopologyRuntime			("SFCObjectsTopologyRuntime")
#define LABEL_SFCObjectsLayoutDevelop			("SFCObjectsLayoutDevelop")
#define LABEL_SFCObjectsLayoutRuntime			("SFCObjectsLayoutRuntime")
#define LABEL_SFCObjectsAnalystDevelop			("SFCObjectsAnalystDevelop")
#define LABEL_SFCObjectsAnalystRuntime			("SFCObjectsAnalystRuntime")
#define LABEL_SFCObjectsSDXDevelop				("SFCObjectsSDXDevelop")
#define LABEL_SFCObjectsSDXRuntime				("SFCObjectsSDXRuntime")
#define LABEL_SFCDeskpro						("SFCDeskpro")
#define LABEL_SFCExpress						("SFCExpress")
#define LABEL_SFCDBuilder						("SFCDBuilder")
#define LABEL_SFCDProducer						("SFCDProducer")
#define LABEL_SFCDChecker						("SFCDChecker")
#define LABEL_SFCFloor							("SFCFloor")
#define LABEL_SFCWaterGIS						("SFCWaterGIS")
#define LABEL_SFCISAdvance						("SFCISAdvance")
#define LABEL_SFCISProfessional					("SFCISProfessional")
#define LABEL_SFCISDevelop						("SFCISDevelop")

#define LABEL_SGOCoreModule						("SGOCoreModule")
#define LABEL_SGODataModule						("SGODataModule")
#define LABEL_SGODisplay2DModule				("SGODisplay2DModule")
#define LABEL_SGODisplay3DModule				("SGODisplay3DModule")
#define LABEL_SGOSequenceModule					("SGOSequenceModule")
#define LABEL_SGOCoreModuleNET					("SGOCoreModuleNET")
#define LABEL_SGOSequenceModuleNET				("SGOSequenceModuleNET")
#define LABEL_SGOCoreModuleJAVA 				("SGOCoreModuleJAVA")
#define LABEL_SGOSequenceModuleJAVA				("SGOSequenceModuleJAVA")
#define LABEL_SGOCoreModuleEMBED				("SGOCoreModuleEMBED")
#define LABEL_SGraphicServerJAVA				("SGraphicServerJAVA")
#define LABEL_SCooperationServerJAVA			("SCooperationServerJAVA")
#define LABEL_SSequenceServerJAVA				("SSequenceServerJAVA")
#define LABEL_SMilitaryUtility					("SMilitaryUtility")

#define LABEL_SGOCoreModuleRuntime				("SGOCoreModuleRuntime")
#define LABEL_SGODataModuleRuntime				("SGODataModuleRuntime")
#define LABEL_SGODisplay2DModuleRuntime			("SGODisplay2DModuleRuntime")
#define LABEL_SGODisplay3DModuleRuntime			("SGODisplay3DModuleRuntime")
#define LABEL_SGOSequenceModuleRuntime			("SGOSequenceModuleRuntime")
#define LABEL_SGOCoreModuleNETRuntime			("SGOCoreModuleNETRuntime")
#define LABEL_SGOSequenceModuleNETRuntime		("SGOSequenceModuleNETRuntime")

#define LABEL_ZXTShipmentManager				("ZXTShipmentManager")

#define LABEL_SuperMapSGSStandard				("SuperMapSGSStandard")
#define LABEL_SuperMapSGSProfessional			("SuperMapSGSProfessional")
#define LABEL_SuperMapSGSEnterprise				("SuperMapSGSEnterprise")
#define LABEL_SuperMapDManagerStandard			("SuperMapDManagerStandard")
#define LABEL_SuperMapDManagerProfessional		("SuperMapDManagerProfessional")

#define LABEL_SuperMapDCSStandard				("SuperMapDCSStandard")
#define LABEL_SuperMapDCSProfessional			("SuperMapDCSProfessional")
#define LABEL_SuperMapDCSEnterprise				("SuperMapDCSEnterprise")
#define LABEL_SuperMapDCSBusinessSMS			("SuperMapDCSBusinessSMS")
#define LABEL_SuperMapDCSVideoMonitor			("SuperMapDCSVideoMonitor")
#define LABEL_SuperMapDCSSupervisorManager		("SuperMapDCSSupervisorManager")
#define LABEL_SuperMapDCSSocialInvolvement		("SuperMapDCSSocialInvolvement")
		
// ƽ̨�����ҵ��
#define LABEL_SuperMapEUD						("SuperMapEUD")                // �����ռ����ݴ�������
#define LABEL_SuperMapESSData					("SuperMapESSData")			   // �������ȵ�����Ϣ�������ݷ���ģ��
#define LABEL_SuperMapESSMapping				("SuperMapESSMapping")		   // �������ȵ�����Ϣ�����ͼ����ģ��
#define LABEL_SuperMapESSSpatialAnalyst			("SuperMapESSSpatialAnalyst")  // �������ȵ�����Ϣ����ռ��������ģ��
#define LABEL_SuperMapESSCatalog				("SuperMapESSCatalog")		   // �������ȵ�����Ϣ����Ŀ¼����ģ��

// TODO ��Ҫ���ģ��ĵط�


enum LibProductType
{	
	CommonLicense							= 0,	// ���õ�һЩ�����Ϣ���ڲ�ʹ��
	ObjectsCoreDevelop						= 1,	// �������������
	ObjectsCoreRuntime						= 2,	// ����������а�
	ObjectsSDXDevelop						= 3,	// �ռ����ݿ����������
	ObjectsSDXRuntime						= 4,	// �ռ����ݿ�������а�
	ObjectsSpaceDevelop						= 5,	// ��ά���������
	ObjectsSpaceRuntime						= 6,	// ��ά������а�
	ObjectsLayoutDevelop					= 7,	// �Ű��ӡ���������
	ObjectsLayoutRuntime					= 8,	// �Ű��ӡ������а�
	ObjectsSpatialDevelop					= 9,	// �ռ�������������
	ObjectsSpatialRuntime					= 10,	// �ռ����������а�
	ObjectsNetworkDevelop					= 11,	// ����������������
	ObjectsNetworkRuntime					= 12,	// �������������а�
	ObjectsTopologyDevelop					= 13,	// �������������
	ObjectsTopologyRuntime					= 14,	// ����������а�
	ObjectsAddressMatchingDevelop			= 15,	// ��ַƥ�����������
	ObjectsAddressMatchingRuntime			= 16,	// ��ַƥ��������а�
	ObjectsCoreEmbedded						= 17,   // SuperMapǶ��ʽ����ƽ̨		FILE
	ObjectsFMEVector						= 18,	// SuperMap ����ת��ʸ����ʽ	FILE
	ObjectsFMEEsri							= 19,	// SuperMap ����ת��ESRI��ʽ	FILE	
	ObjectsFMERaster						= 20,	// SuperMap ����ת��դ���ʽ 	FILE
	ObjectsFMEOther							= 21,	// SuperMap ����ת��������ʽ	FILE
	ObjectsNauticalChartDevelop				= 22,	// SuperMap ��ͼ������	
	ObjectsNauticalChartRuntime				= 23,   // SuperMap ��ͼ���а�	
	ObjectsRealspaceSpatialAnalystDevelop	= 24,	// ��ά�ռ�������������
	ObjectsRealspaceSpatialAnalystRuntime	= 25,	// ��ά�ռ����������а�
	UniversalGISCore						= 26,	// UniversalGISCore ���
	ObjectsTrafficAnalystDevelop			= 27,	// �����������������
	ObjectsTrafficAnalystRuntime			= 28,	// ��������������а�
	ObjectsRealspaceNetworkAnalystDevelop	= 29,	// ��ά����������������
	ObjectsRealspaceNetworkAnalystRuntime	= 30,	// ��ά�������������а�
	ObjectsRealspaceEffectDevelop			= 31,	// ��ά��Ч���������
	ObjectsRealspaceEffectRuntime			= 32,	// ��ά��Ч������а�

	
	DeskproNET							= 501,	// ����ɿ�����
	ExpressNET							= 502,	// ����
	ViewerNET							= 503,	// ������Ѱ�
	DeskproNETTopology					= 504,	// �������˴�����չģ��
	DeskproNETTrafficNetwork			= 505,  // ���潻ͨ���������չģ�� 
	DeskproNETFacilityNetwork			= 506,  // ������ʩ���������չģ�� 
	DeskproNETSpatial					= 507,  // ����ռ������չģ��
	DeskproNETNauticalChart				= 508,	// ���溣ͼ��չģ��
	DeskproNETGeoProcesser				= 509,	// ����ռ䴦����չģ��
	DeskproNETRealspaceSpatialAnalyst	= 510,	// ������ά������չģ��
	DeskproNETTrafficAnalyst			= 511,	// ���湫��������չģ��
	DeskproNETRealspaceEffect			= 512,	// ������ά��Ч��չģ��

	iServerStandard					= 1000,	// iServer��׼��
	iServerProfessional				= 1001,	// iServerרҵ��
	iServerEnterprise				= 1002,	// iServer�߼���
	iServerSpatial					= 1003,	// iServer�ռ������չ
	iServerNetwork					= 1004,	// iServer���������չ
	iServerTrafficTransfer			= 1005,	// iServer��ͨ������չ
	iServerSpace					= 1006,	// iServer��ά��չ
	iServerNauticalChart			= 1007, // iServer��ͼ��չ
	iServerExpress					= 1008, // iServer������

	SFCObjectsCoreDevelop			= 5000,	// SFC�������������
	SFCObjectsCoreRuntime			= 5001,	// SFC����������а�
	SFCObjects3DDevelop				= 5002,	// SFC��ά���������
	SFCObjects3DRuntime				= 5003,	// SFC��ά������а�
	SFCObjectsTopologyDevelop		= 5004,	// SFC�������������
	SFCObjectsTopologyRuntime		= 5005,	// SFC����������а�
	SFCObjectsLayoutDevelop			= 5006,	// SFC�Ű��ӡ���������
	SFCObjectsLayoutRuntime			= 5007,	// SFC�Ű��ӡ������а�
	SFCObjectsAnalystDevelop		= 5008,	// SFC�������������
	SFCObjectsAnalystRuntime		= 5009,	// SFC����������а�
	SFCObjectsSDXDevelop			= 5010,	// SFC�ռ����ݿ����������
	SFCObjectsSDXRuntime			= 5011,	// SFC�ռ����ݿ�������а�
	SFCDeskpro						= 5012,	// SFC Deskpro
	SFCExpress						= 5013,	// SFC Express
	SFCDBuilder						= 5014,	// SFC D-Builder
	SFCDProducer					= 5015,	// SFC D-Producer
	SFCDChecker						= 5016,	// SFC D-Checker
	SFCFloor						= 5017,	// SFC Floor
	SFCWaterGIS						= 5018,	// SFC WaterGIS
	SFCISAdvance					= 5019,	// IS .NET�߼���
	SFCISDevelop					= 5021,	// IS .NET������

	SGOCoreModule					= 6001,	//	SuperMap DGO ����ģ��
	SGODataModule					= 6002,	//	SuperMap DGO ���ݹ���ģ��
	SGODisplay2DModule				= 6003,	//	SuperMap DGO ���ñ��ģ��
	SGODisplay3DModule				= 6004,	//	SuperMap DGO ��άģ��		
	SGOSequenceModule				= 6005,	//	SuperMap DGO Эͬģ��
	SGOCoreModuleNET				= 6006,	//	SuperMap DGO ��άģ��
	SGOSequenceModuleNET			= 6007,	//	SuperMap DGO ʱ������ģ��

	SGOCoreModuleJAVA				= 6008,	//	SuperMap EGS ������
	SGOSequenceModuleJAVA			= 6009,	//	SuperMap EGS ���ݹ������
	SGOCoreModuleEMBED				= 6010,	//	SuperMap EGS Эͬ����
	SGraphicServerJAVA				= 6011,	//	SuperMap EGS ��ͼ��������
	SCooperationServerJAVA			= 6012,	//	SuperMap EGS ��ͼ��ӡ����
	SSequenceServerJAVA				= 6013,	//	SuperMap EGS ���ݷ���
	SMilitaryUtility				= 6014,	//													FILE

	SGOCoreModuleRuntime			= 6015,	//	SuperMap DGO ����ģ�����а�
	SGODataModuleRuntime			= 6016,	//	SuperMap DGO ���ݹ���ģ�����а�
	SGODisplay2DModuleRuntime		= 6017,	//	SuperMap DGO ���ñ��ģ�����а�
	SGODisplay3DModuleRuntime		= 6018,	//	SuperMap DGO ��άģ�����а�		
	SGOSequenceModuleRuntime		= 6019,	//	SuperMap DGO Эͬģ�����а�
	SGOCoreModuleNETRuntime			= 6020,	//	SuperMap DGO ��άģ�����а�
	SGOSequenceModuleNETRuntime		= 6021,	//	SuperMap DGO ʱ������ģ�����а�

	ZXTShipmentManager				= 6100, // ����ͨ��������Ӧ�ó���							FILE
	
	//���ֳ���
	SuperMapSGSStandard				= 6200,	// �������ĵ�����Ϣ����ƽ̨ ��׼�� 60/20	FILE
	SuperMapSGSProfessional			= 6201,	// �������ĵ�����Ϣ����ƽ̨ רҵ�� 60/20	FILE
	SuperMapSGSEnterprise			= 6202,	// �������ĵ�����Ϣ����ƽ̨ �߼��� 60/20	FILE
	SuperMapDManagerStandard		= 6203,	// �ռ����ݹ���ƽ̨��� ��׼��	60			FILE
	SuperMapDManagerProfessional	= 6204,	// �ռ����ݹ���ƽ̨��� רҵ��	60			FILE

	SuperMapDCSStandard				= 6205, // SuperMap DCS ��׼�� 
	SuperMapDCSProfessional			= 6206, // SuperMap DCS רҵ��
	SuperMapDCSEnterprise			= 6207, // SuperMap DCS �߼��� 
	SuperMapDCSBusinessSMS			= 6208,	// SuperMap DCS ҵ�������ϵͳ
	SuperMapDCSVideoMonitor			= 6209, // SuperMap DCS ��Ƶ�����ϵͳ
	SuperMapDCSSupervisorManager	= 6210, // SuperMap DCS �ලԱ������ϵͳ
	SuperMapDCSSocialInvolvement	= 6211, // SuperMap DCS ��ǰ������ϵͳ

	// ƽ̨�����ҵ��
	SuperMapEUD						= 6300, // �����ռ����ݴ�������
	SuperMapESSData					= 6301, // �������ȵ�����Ϣ�������ݷ���ģ��
	SuperMapESSMapping				= 6302, // �������ȵ�����Ϣ�����ͼ����ģ��
	SuperMapESSSpatialAnalyst		= 6303, // �������ȵ�����Ϣ����ռ��������ģ��
	SuperMapESSCatalog				= 6304, // �������ȵ�����Ϣ����Ŀ¼����ģ��

	// TODO ��Ҫ���ģ��ĵط�
};


enum LibLicenseMode
{
	NoLicense		= 0,	// �����
	HardwareKey		= 1,	// Ӳ����
	TrialVersion	= 2,	// ԭ���ļ����������Ϊ���ð棬�����ϵĳ��򶼿���ʹ��
	NetworkCard		= 3,	// ����
	ComputerName    = 4,	// ����������ܣ���ʽ�汾
};

enum LibProductVersion
{
	V200 = 200,
	V600 = 600,
};

enum LibHardwareKeyType
{
	InvalidType		= 0,
	Standalone		= 1,
	StandaloneTime	= 2,
	Network			= 3,
	NetworkTime		= 4,
};

struct LicenseData
{	
	LibProductType product;	
	LibProductVersion version;
};

enum LibHardwareType
{
	UnknownHW	= 0,
	SuperPro	= 1,
	Sentinel	= 2,
	Aladdin		= 3,
};


class LicenseReader
{
	friend class LicenseReaderSentinel;
	friend class LicenseReaderAladdin;
	friend class LicenseReaderSuperPro;

public:
	LicenseReader();
	~LicenseReader();
	
	// ���³�Ա������Ӧ���������
public:
	// �õ���ǰ������ʶ����
	char* GetIdentifyCode();

	// �õ����ʹ���û���
	char* GetUser();

	// �õ����ʹ�ù�˾����
	char* GetCompany();

	// ���������û���
	int GetMaxConnection();

	// ��ǰ���������û���
	int GetCurrentConnection();	

	// ���ģʽ
	LibLicenseMode GetLicenseMode();

	// ��ɷ�����
	char* GetLicenseServer();

	// ��Ʒ��������
	int GetExpiredDate(int &year,int &month,int &day);

	// ��Ʒ����
	LibProductVersion GetProductVersion();

	// ��Ʒ����
	LibProductType GetProductType();

	// ���õ�ǰʹ�õ�Ӳ����
	void SetCurrentHardwareType(LibHardwareType hardwareType);

	// �õ�������Ϣ
	static bool GetNetWordCardInfo(int nPos,char* CardSN,char* CardName);

	// ���³�Ա������Ӧ����ķ������������û�в�����������Ҫʹ���ߴ�����
public:
	// 0�ǳɹ��ģ������������Ϣ����ͨ��GetErrorDetail���õ�ȷ�к���
	int Connect(const LicenseData &data);

	// 0�ǳɹ��ģ������������Ϣ����ͨ��GetErrorDetail���õ�ȷ�к���
	int Verify();

	// �Ͽ�����������
	void Disconnect();

	// �õ��������������Ϣ
	static char* GetErrorDetail(int code);

	// �õ���������
	int GetKeyType(LibHardwareKeyType &keyType);

	// ����Ϊ�������ܺ�����������������ļ��������ļ�ʹ��
public:
	// �����ļ���ɵ�LicData
	static char* GenerateLicData(	const LibProductType product,
									const char* user,
									const char* company,
									const char* version,
									const char* identifyCode,
									unsigned int expiredDate,
									unsigned int startDate,
									int LicenseMode,
									unsigned int licFileMaxConnect = 0);
	
	// �õ���Ʒ��Ӧ���ַ������֣���������������ļ��ȵط�ʹ��
	static char* GetProductName(LibProductType product);

	// ����Ini�ļ�����Ľ�
	static char* GenerateFileIniSegment(const LibProductType product,
									const char* user,
									const char* company,
									const char* identifyCode,
									const char* licPath,
									unsigned int licFileMaxConnect = 0);

	// ����lic����Ľ�
	static char* GenerateLicSegment(const LibProductType product,const char* licData,const char* version, unsigned int licFileMaxConnect = 0);

	// ����Ini������Ľ�
	static char* GenerateKeyIniSegment(const LibProductType product,const char* server);

	// �õ��ļ���������ļ�·��
	static char* GetIniFileName();
	
	// �õ����������
	static char* GetMachineName();

	
	// �ڲ�ר�ú���
	static void GetLicenseInfo(const char* productName,char* user,char* company,char* server,char* licData,char* identifyCode,LibProductVersion nVersion = V200);
	// �ļ�����Ҫ��ȡд����ɸ�������������ӿ� add by gouyu 2012-11-6
	static void GetLicenseInfo(const char* productName,char* user,char* company,char* server,char* licData,char* identifyCode, unsigned int &licMaxConnect ,LibProductVersion nVersion = V200);
	
	static void GetStartExpiredDate(const char* licData,unsigned int *startDate,unsigned int *expiredDate);	
	static LibLicenseMode ReadProductLicMode(char* productName);

	static int CollectKeyInfo(char* &keyInfo,int *&count);
	static int UpdateKeyInfo(const char* updateInfo,const int count);

	// ��ȡ�����÷��������ӵ�ʱ��Ƶ��
	// add by gouyu 2011-11-7
	static long GetConnectionHeartbeat();
	static void SetConnectionHeartbeat(long value);

	// ��ȡ�����ⲿ�����֤�ļ���λ�ã��255���ַ�
	// add by gouyu 2011-11-28
	static char* GetExtraIniKeyPath();
	static void SetExtraIniKeyPath(const char* path);

public:
	static int VerifyMachine();
	static char* CreateKeys();
	
	// ����Ϊ�ڲ�ʹ��
private:	
	void InitilizeReader();
	void ReleaseReader();

	int ConnectComputerName(const LicenseData &data);
	int ConnectHardwareKey(const LicenseData &data);
	int ConnectNetworkCard(const LicenseData &data);
	int VerifyHardwareKey();
	static char* GetDir(char* pFileName);

	unsigned char* Encrypt(unsigned char* inValue);
	unsigned char* Decrypt(unsigned char* inValue);

private:
	void* m_readerArray[CurrentReaderCount];
	int m_currentIndex;

	LicenseData m_data;
	LibLicenseMode m_licMode;
	LibHardwareType m_hardwareType;
	char m_productName[MAX_CHAR];
	char m_user[MAX_CHAR];
	char m_company[MAX_CHAR];
	char m_server[MAX_CHAR];	
	char m_licData[MAX_CHAR];
	char m_identifyCode[MAX_CHAR];
	unsigned int m_licFileMaxConnect;

	static char* sm_pExtraIniPath;
};

#endif
