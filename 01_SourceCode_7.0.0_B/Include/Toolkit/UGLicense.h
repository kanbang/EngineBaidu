// UGLicense.h: interface for the UGLicense class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGLICENSE
#define UGLICENSE

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugdefs.h"
#include "Stream/ugplatform.h"

#include "License/LicenseReader.h"

typedef LibHardwareKeyType UGHardwareKeyType;
typedef LibLicenseMode UGLicenseMode;
typedef LibProductVersion UGProductVersion;
typedef LibProductType UGProductType;

namespace UGC
{			
	//! \brief LicenseErrorProc �¼��ص�����
	typedef void (UGSTDCALL *LicenseErrorProc)(UGString errorMsg);

	class TOOLKIT_API UGLicense
	{

	public:
	enum ChartLicenseState
	{
		UnEnable			= -1,	// ������
		iServerEnable		= 0,	// iServer��ɿ���
		DeskproEnable		= 1,	// ������ɿ���
		ObjectEnable		= 2,	// �����ɿ���
	};									

	public:

		~UGLicense();

		UGLicense();

		UGProductVersion GetVersion();

		UGProductType GetProduct();

		UGLicenseMode GetLicenseMode();

		UGHardwareKeyType GetKeyType();

		UGString GetIdentifyCode();

		UGString GetUser();

		UGString GetCompany();

		UGString GetLicenseServer();

		UGTime GetExpiredDate();

		UGint GetMaxConnection();

		UGint Connect(UGProductType product);

		UGint Verify();

		void Disconnect();

		static UGString GetErrorMessage(UGint code);	

		UGbool GetLicenseVaild();

		static UGbool VerifyUGCLicense();

		//{{added by qianjn 2011-4-12 
	public:

		// �����Ƿ��������, 0����ʽ��ɣ�1Ϊ��ͼ������ɣ�2Ϊ����������ɣ�3Ϊ��ά�������
		static void SetIsUnregistered(UGint nType, UGbool bUnregistered);
		static UGbool GetIsUnregistered(UGint nType);

		// ���û��ȡ��ǰ��ͼ����Ƿ���� [8/31/2011 zhoujt]
		static void SetChartLicenseState(UGint nCode);
		static UGLicense::ChartLicenseState GetChartLicenseState();

		//// ���õ�ǰ���еĲ�Ʒ����
		//static void SetCurrentProduction(UGint nType);
		//static UGint GetCurrentProduction();

		// ��ȡ�����õ�ǰ��Ʒ�Ƿ�������ƺ�ͼͼ�� [9/2/2011 zhoujt]
		static void SetDrawChartLayer(UGbool bEnable = false);
		static UGbool GetDrawChartLayer();

		static UGbool GetLicCheckMode();
		static void SetLicCheckMode(UGString mode);

		static void SetLicenseErrorFunc(LicenseErrorProc pLicenseErrorFunc);

	private:

		static LicenseErrorProc g_pLicenseErrorFunc;
		static void SendLicenseErrorFunc(UGString errorMsg);

	private:

		// �Ƿ�������ɣ�Ĭ��false
		static UGbool m_bUnregisteredMap;
		static UGbool m_bUnregisteredLayout;
		static UGbool m_bUnregisteredSpace;
		//}}added by qianjn 2011-4-12 

		// ��ǰ��ͼ��ɵ�״̬ [8/31/2011 zhoujt]
		// iServer��ɿ��� --- 0; ������ɿ��� --- 1; �����ɿ��� -- 2; û����� --- -1;
		static UGLicense::ChartLicenseState m_eChartLicenseState;

		//  [9/2/2011 zhoujt]
		static UGbool m_bDrawCharLayer;

		LicenseReader* m_pLicenseReader;	

		static UGbool g_licenseVaild;
		static UGbool g_Checked;
		static UGString g_checkMode;
	};	
}
#endif //UGLICENSE
