/************************************************************************/
/* ����Ƕ��ʽƽ̨����ɿ����࣬���ฺ���������ļ�����֤��ɣ���֤ģ��    */
/* ���ߣ�������                                                         */
/* ʱ�䣺2012��9��25��                                                  */
/************************************************************************/

#ifndef UGPERMISSION_HEADER_FOR_OBJECTS_EMBEDED
#define UGPERMISSION_HEADER_FOR_OBJECTS_EMBEDED


#include "Stream/UGFile.h"
#include "Stream/ugdefs.h"



#include <string>
#include <iostream>


// a small class for calculating MD5 hashes of strings or byte arrays
// it is not meant to be fast or secure
//
// usage: 1) feed it blocks of uchars with update()
//      2) finalize()
//      3) get hexdigest() string
//      or
//      MD5(std::string).hexdigest()
//
// assumes that char is 8 bit and int is 32 bit
namespace UGC
{


class TOOLKIT_API MD5
{
	
public:
	typedef unsigned int size_type;

	MD5();
	MD5(const  unsigned char *text);
	void update(const unsigned char *buf, size_type length);
	void update(const char *buf, size_type length);
	MD5& finalize();
	char* hexdigest() const;
	UGString hex16byte() const;
	friend std::ostream& operator<<(std::ostream&, MD5 md5);

private:
	typedef unsigned char uint1; 
	typedef unsigned int uint4;
	void init();
	
	enum {blocksize = 64}; // VC6 won't eat a const static int here

	void transform(const uint1 block[blocksize]);
	static void decode(uint4 output[], const uint1 input[], size_type len);
	static void encode(uint1 output[], const uint4 input[], size_type len);

	bool finalized;
	uint1 buffer[blocksize]; // bytes that didn't fit in last 64 byte chunk
	uint4 count[2];   // 64bit counter for number of bits (lo, hi)
	uint4 state[4];   // digest so far
	uint1 digest[16]; // the result

	// low level logic operations
	static inline uint4 F(uint4 x, uint4 y, uint4 z);
	static inline uint4 G(uint4 x, uint4 y, uint4 z);
	static inline uint4 H(uint4 x, uint4 y, uint4 z);
	static inline uint4 I(uint4 x, uint4 y, uint4 z);
	static inline uint4 rotate_left(uint4 x, int n);
	static inline void FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
	static inline void GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
	static inline void HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
	static inline void II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
};

UGString md5(const UGchar *str);

//���ܳ�16λ���ַ���
UGString md5to16byte(const UGchar *str);


//������Ŀ���ģ��
#define MOBILE_MODULE_CORE_Dev 0x01
//�����������ģ��
#define MOBILE_MODULE_CORE_Runtime 0x02
//���嵼������ģ��
#define MOBILE_MODULE_GUIDE_Dev 0x04
//���嵼������ģ��
#define MOBILE_MODULE_GUIDE_Runtime 0x08
//������ά����ģ��
#define MOBILE_MODULE_3D_Dev 0x10
//������ά����ģ��
#define MOBILE_MODULE_3D_Runtime 0x20


const UGString UserSerialID = _U("UserSerialID");
const UGString Modules = _U("Modules");
const UGString Version = _U("Version");
const UGString StartDate = _U("StartDate");
const UGString ExpiredDate = _U("ExpiredDate");
const UGString TrialLicense = _U("Trial License");
const UGString DeviceID = _U("DeviceID");
const UGString DeviceIDType = _U("DeviceIDType");
const UGString LicCode = _U("LicCode");

//�������ͷ
#define LICENSE_HEADER _U("SuperMapiMoble2012") // ���ܵĻ����ַ������ʹ���д���

//��������ļ�����׺
#define SINGLE_LICENSE_EX _U(".slm")
#define GROUP_LICENSE_EX _U(".sglm")

#define LICENSE_LINE_END _U("\r\n")

//�豸�ų���
#define DEVICEID_LENGTH 16
//��Կ����
#define KEY_LENGHT 32

class TOOLKIT_API UGPermission  
{
public:
	UGPermission();
	virtual ~UGPermission();

public:
	 static UGString GetDeviceID();

	 static UGbool SetDeviceMacAddress(UGString macAddress);

	 static UGString GetLicensePath();

	 static UGbool SetLicensePath(UGString strAppPath);

private:
	static UGString mDeviceID;

	//���·��
	static UGString mLicensePath;

	//��ǰ������ԭʼ���豸�ţ���ֱ�Ӵ�Ӳ����ȡ�����豸��
	static UGString mOrginalDeviceID;
};

class TOOLKIT_API UGLicenseManager
{
public :
	UGLicenseManager();
	~UGLicenseManager();

public:
	//��֤����Ƿ����
	 UGbool isRegister();
	
	//��֤ģ���Ƿ����
	 UGbool isModuleValid(UGulong module);

	//�Ƿ���������ɿ���
	 UGbool isTrailValid();

	 //�Ƿ���ʹ�����
	 UGbool isTrail();

	 //����Ƿ����
	 UGbool isLicenseExsit();

	 //��ȡ�汾
	 UGlong GetVersion();

	 //��ȡ��ɿ�ʼʱ��
	 UGTime GetStartDate();

	 //��ȡ�����ֹʱ��
	 UGTime GetExpireDate();

	 //ͨ��ע������֤���
	 //! \brief ����֤�ɹ���������·����ֱ�����ɵ�������ļ�
	 UGbool VerifyLicenceCode(UGString licCode,UGString& errMsg);

	
private:
	//�Ƿ��Ǽ������
	UGbool isGroupLicense();

	//��֤ʱ���Ƿ���ȷ
	UGbool isTimeValid();

	//��֤�汾
	UGbool isVersionValid();

	//��ȡ���
	UGbool ReadLicenseData();

	//�Ӽ�������гɵ������
	UGbool CreateSingleLicense();

	//�����·�����ҵ�����ļ�,û���ҵ���Ϊfalse,�ҵ�Ϊtrue
	UGbool FindLincenseFile();

private:
	//�������
	UGbool mIsTrailValid;

	UGbool mIsRegister;

	UGbool mIsTimeValid;

	UGbool mIsVersionValid;

	//ģ����Ϣ����
	UGulong mModulesCode;

	//��ȡ��ģ����Ϣ����
	UGString mStrModulesCode;;

	//�汾����
	UGString mStrVersionCode;

	//��ʼʱ��
	UGString mStrStartDate;

	//����ʱ��
	UGString mStrEndDate;

	//�û����к�
	UGString mUserSerialID;

	//Ӳ����
	UGString mStrDeviceID;

	//��ȡ�������
	UGString mStrLicenseCode;

	//�Ƿ����������
	UGbool mIsTrailLicense;

	//ֻ��һ���ļ�
    static UGbool mHasReadLicense;

	//����ļ�
	UGString mLicenseFile;
};

extern TOOLKIT_API UGLicenseManager g_LicenseManager;

}//namespace UGC

#endif //#ifndef UGPERMISSION_HEADER_FOR_OBJECTS_EMBEDED