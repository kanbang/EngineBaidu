// UGPluginMapCache50.h: interface for the UGPluginMapCache50 class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _PLUGINMAPCACHE50_H_
#define _PLUGINMAPCACHE50_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CacheFile/UGAbstractCacheFile.h"
#include "FileParser/UGImagePlugin.h"
#include "MapServiceStub/UGMapServiceStub.h"
#include <vector>

namespace {
	// ר���������� buffer �� template
	template <typename _Ty>
	class _BufferManager : public std::auto_ptr<_Ty> {
		size_t m_nBuffSize;
	public:
		void reset(size_t nNewSize = 0, _Ty *ptr = 0) {
			std::auto_ptr<_Ty>::reset(ptr);
			if (ptr == NULL) {
				m_nBuffSize = 0;
			} else {
				m_nBuffSize = nNewSize;
			}
		}

		_Ty *release() {
			m_nBuffSize = 0;
			return std::auto_ptr<_Ty>::release();
		}

		size_t getsize() {
			return m_nBuffSize;
		}

		_BufferManager(size_t nSize = 0, _Ty *ptr = 0) : std::auto_ptr<_Ty>::auto_ptr(ptr) {
			m_nBuffSize = nSize;
		}

		~_BufferManager() {
			m_nBuffSize = 0;
		}
	};

	UGchar *pPostfix = UG_ABSCACHEFILE_EXT;
	UGchar *pArcPostfix = UG_ARCFILE_EXT;
} // anonymous namespace

namespace UGC
{
	
class PLUGINMAPCACHE50_API UGPluginMapCache50 : public UGImagePlugin {

public:
	UGPluginMapCache50();
	virtual ~UGPluginMapCache50();

public:
	virtual UGbool GetPluginName(UGchar* strName, int nMaxLength);
	virtual UGbool GetExtName(UGchar* strExtName, int nMaxLength, int nExtNameIndex = 0);
	virtual int GetExtNameCount() const { return 2; }

	virtual UGbool Open(const UGchar* strFileName, unsigned int nFlags, const UGchar *pszPassword);
	void Close();

	virtual UGbool SetViewPort(double dLeft,double dTop, double dRight, double dBottom, int nDeviceWidth, int nDeviceHeight);

	//! \brief �������ظ�ʽ
	virtual UGbool GetPixelFormat(ImagePixelFormat& nPixelformat);

	//! \brief ����ÿ�����ص�λ��
	virtual UGbool GetPixelBits(ImagePixelBits& nPixelbits);

	//! \brief ��ȡ����ͼƬ�Ĵ�С
	// NOTE ���ڸú����Ѿ��������㳬��ߴ绺��Ҫ��int ���ͻ������
	// ���ڵĽ���취�����������£����� INT_MAX
	virtual UGbool GetImageSize(int& nWidth, int& nHeight);

	virtual UGbool GetImageGeoRefrence(double& dLeft, double& dTop, double& dRight, double& dBottom, ImageUnit& nUnits);

	//! \brief ��ȡ��Ҫ��ʾ��ͼ���С
	virtual UGbool GetViewImageSize(int& nViewWidth, int& nViewHeight);

	//! \brief ��ȡ�洢���ɵ�ͼƬ��ʵ�����ص� buffer �Ĵ�С��ÿ����λ����һ���ֽ�
	virtual int GetViewImageDataSize(); 

	virtual UGbool GetViewImageData(UGbyte* pDataBuffer, int nSize);

	//! \brief ��ȡͶӰ��Ϣ
	const UGchar* GetPrjCoordSys();

	// Ϊ��ͼ���ù̶�������
	virtual void ConfigureMap(void *pMap, void (*pCallBack) (void *, std::vector<double>));

	// ����·�������úͻ�ȡ
	// ����û�ж����õĶ���·�������κμ�飬���������Ϊ
	void		SetTopPath(const UGString &strTopPath) { m_strTopPath = strTopPath; }
	UGString	GetTopPath() const { return m_strTopPath; }

	UGbool IsFinished();

	// ����������������ͼƬ�� UGMapServiceStub���� UGMapServiceStub �����ɱ�����ӵ�У����������������Ϳռ����
	void	SetMapServiceStub(UGMapServiceStub *pStub);

	// �����ⲿ CacheFile ���󡣸� UGAbstractFile �����ɱ�����ӵ�У����������Ĺرա������Ϳռ����
	void	SetCacheFile(UGAbstractCacheFile *pCacheFile);

	////! \brief �жϴ������Ƿ���ȷ
	//UGbool IsPassWordCorrect(const UGchar* strFileName, const UGchar * strPassword);//added by xuxr at 20111212

	// ��ȡ�Ƿ񱳾�͸��
	virtual UGbool IsTransparentBack();

	//! \brief ��ȡ��Ƭ��DP��С
	virtual UGSize GetTileSize();

	//! \brief �������еı����߼���
	virtual const UGArray<UGdouble> GetScales() const;

	//!  \brief �õ���ǰ������Ӱ���С
	//!  \param nWidth Ӱ����
	//!  \param nHeight Ӱ��߶�
	//!  \param dScale ���浱ǰ������
	//!  \remark �˺�����ҪӦ���ڻ�ȡ�����ʷֻ����Ӧ�����ߵ�Ӱ����
	virtual UGbool GetImageSize(UGint& nWidth,UGint& nHeight,UGdouble dScale);

	//!  \brief  �Ƿ���ȫ�򻺴�
	virtual UGbool IsGlobalCache();

private:
	void Reset();
	static void UGSTDCALL OnDownload(UGDownloadTileInfo result, UGlong pWnd);

	// ���ﴫ������ط�Χ�����ϡ��ҡ��£���ָ�����������µ����ط�Χ��
	UGbool SetViewPort(int64_t nLeft, int64_t nTop, int64_t nRight, int64_t nBottom, int nDeviceWidth, int nDeviceHeight);
	UGbool SetViewPort(int nLeft,int nTop, int nRight, int nBottom, int nDeviceWidth, int nDeviceHeight);
	UGbool SetViewPort_aux();

	// ������ӽ��ı�����
	// nImageWidth Ϊ��������������Ҫȡ���������ؿ��
	// nDeviceWidth Ϊ��ǰ��ȡ�õ����ݽ�Ҫ���Ƶ����豸�����ؿ��
	double FindNearestScale(int64_t nImageWidth, int nDeviceWidth);

	// ��ȡͼƬ�ļ�����
	// TODO ȥ����һ�� GetImageFileDataToInternalBuffer()
	UGbool GetImageFileDataToInternalBuffer(const UGString &strFullImageFileName, UGdouble dScale, int nRow, int nCol, UGbool bCompactCache = false);
	UGbool GetImageFileDataToInternalBuffer(int nRow, int nCol, UGByteArray &ByteArray, UGbool bSolidColor, UGColor color);
	UGbool GetDownloadTileInfoToInternalBuffer(UGDownloadTileInfo info);
	void PaintSolidColor(UGdouble dScale, int nRow, int nCol, UGColor color);

	// ========================== ��Ա���� ==========================
	// ָʾ�����Ƿ��Ѿ�˳����
	UGbool m_bOpened;

	// �������ڵ�Ŀ¼·������·���ָ�����β��
	// ����Ǵ����绺�棬��Ϊ���绺�� URL ·�����������涥��Ŀ¼����
	// ������ RelativePathName �ϲ���һ����ɻ���ͼƬԴ·��
	// �� '/' ��β
	// ���磺
	// ������� sci �� http://localhost:8080/China400_100x100/China400.sci������ַ���Ϊ��
	// "http://localhost:8080/"
	// ������� sci �� D:/MapCache/China400_100x100/China400.sci������ַ���Ϊ��
	// "D:/MapCache/"
	//UGString m_strCachePath;	

	// �������ݵ�·������·����һ�������ļ�ϵͳ·����
	// ���� "D:/SuperMap/Cache/China400_100x100"
	UGString m_strTopPath;

	// �洢���ɵ�ͼƬ��ʵ�����ص� buffer
	_BufferManager<UGbyte> m_buffManager;

	// �������룬���ļ�������ʹ��
	UGString m_strPassword;
	UGString m_strProjectionXML;

	UGString m_strFileName;	// ���� Open() �����ж��Ƿ���Ҫ�رյ�ǰ���ݣ���һ��������

	// ���ݴ�С��GetViewImageSize() ��Ҫʹ��
	int64_t m_nViewImageHeight;
	int64_t m_nViewImageWidth;

	UGMapServiceStub *m_pStub;

	// ���ı�����
	UGdouble m_dMaxScale;

	// ��С�ı�����
	UGdouble m_dMinScale;

	// ��������ķ�Χ��������չ�˵���Ƭ
	UGRect2D m_rcExtendedBounds;

	UGbool m_bExternalCacheFile;
	UGAbstractCacheFile *m_pCacheFile;
	std::auto_ptr<UGbyte> m_pDefaultColorLine;

	// ��δ�ҵ����ݵĿ���Ŀ
	size_t m_nLostBlocks;

	// ���һ����ʾʱ�����ط�Χ�������ط�Χ��ָ�����һ����ʾ�ı������µ����ط�Χ��
	PixelArea m_ViewPixelArea;

	// ���һ����ʾ�ı�����
	UGdouble m_dScale;

	// ��������ʾ�ĵ���Χ�ı��ʱ�򱣻� buffer
	UGMutex m_Mutex;

	// ��һ�� SetViewPort() ����ʱ�Ĳ���
	// ���ﱣ����Щ������Ϊ�˷�ֹ�ظ����㣬�ӿ��ٶȡ�
	UGdouble m_dSavedScale;
	int64_t m_nSavedPixelAreaLeft;
	int64_t m_nSavedPixelAreaRight;
	int64_t m_nSavedPixelAreaTop;
	int64_t m_nSavedPixelAreaBottom;

	UGCompactFileWrapper m_compactFile;

};

#if !defined OS_ANDROID && !defined IOS
extern "C" PLUGINMAPCACHE50_API UGImagePlugin* CreateImagePlugin();
#else
extern "C" PLUGINMAPCACHE50_API UGImagePlugin* CreateHPImagePlugin();
#endif
}

#endif // _PLUGINMAPCACHE50_H_
