// UGFishingNetArithmetic.h: interface for the UGFishingNetArithmetic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFINISHINGNETARITHMETIC_H__37037E0D_8ABC_413E_B8BE_2B8916F0319E__INCLUDED_)
#define AFX_UGFINISHINGNETARITHMETIC_H__37037E0D_8ABC_413E_B8BE_2B8916F0319E__INCLUDED_

#include "Stream/ugdefs.h"
#include "CacheFile/UGCacheFileCommon.h"
#include "FileParser/UGVectorCacheParamater.h"

namespace UGC {

enum UGFishingNetGirdSize
{
	SIZE_256B		= 256,
	SIZE_512B		= 512,
	SIZE_1K			= 1024,
	SIZE_2K			= 2048,		// 2*1024
	SIZE_4K			= 4096,		// 4*1024
	SIZE_8K			= 8192,		// 8*1024
	SIZE_16K		= 16384,	// 16*1024
	SIZE_32K		= 32768,	// 32*1024
	SIZE_64K		= 65536,	// 64*1024
};

struct UGGridIndex
{
	UGint row : 32;
	UGint col : 32;
};

class UGPrjCoordSys;
class UGMapCacheFile;

class MAP_API UGFishingNetArithmetic  
{
public:
	UGFishingNetArithmetic();
	virtual ~UGFishingNetArithmetic();

	// �汾�ţ�Ĭ��Ϊ���°汾��
	void SetVersion(UGMapCacheVersion nVersion);
	UGMapCacheVersion GetVersion() const;

	// ͨ����ͼͶӰ��������ϵ��λ
	void SetPrjCoordSysRatio(const UGPrjCoordSys &CoordSys);

	// ���ü��������DPI
	void SetDPI(UGdouble dDPI);
	UGdouble GetDPI();

	// ������������Ĵ�С
	void SetGirdSize(UGFishingNetGirdSize nGirdSize);
	UGFishingNetGirdSize GetGridSize();

	// ���������ݷ�Χ���Ե�������Ϊ��λ
	void SetBounds(const UGRect2D &rcBounds);
	UGRect2D GetBounds();

	//! \���ݵ�ͼ��Χ����ͼƬ���кŷ�Χ
	//! \param dMapScale [in]		������
	//! \param rcMapBounds [in]		��ͼ��Χ
	//! \param nStartRow [out]		ͼƬ��ʼ�к�
	//! \param nEndRow [out]		ͼƬ�����к�
	//! \param nStartCol [out]		ͼƬ��ʼ�к�
	//! \param nEndCol [out]		ͼƬ�����к�
	//! \param bBigTileImage [in]	�Ƿ��Ǵ��ͼƬ
	//! remarks ��ͼ����ʹ�á���Ҫ�ǳ�ͼʱʹ��
	void ComputeGridRange(UGdouble dMapScale, const UGRect2D& rcMapBounds, UGGridArea &GridArea);

	//! \���ݸ����ı����߼���Ƭ���кŷ�Χ������Ƭ��Χ
	//! \param dMapScale [in]		������
	//! \param TileDataArea [in]	��Ƭ���кŷ�Χ
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ�����ж�����Ƭ�ķ�Χ
	UGRect2D ComputeGridMPBounds(UGdouble dMapScale, const UGGridArea &GridArea) const;

	//! \���ݸ����ı����߼���Ƭ���кż�����Ƭ��Χ
	//! \param dMapScale [in]		������
	//! \param nRow [in]			ͼƬ�к�
	//! \param nCol [in]			ͼƬ�к�
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ��㵥����Ƭ�ķ�Χ
	UGRect2D ComputeGridMPBounds(UGdouble dMapScale, UGint nRow, UGint nCol);

	//! \���ݸ����ı����߼����ĵ������Ƭλ��
	//! \param dMapScale [in] ������
	//! \param center [in] ָ�������ĵ�
	//! \param nRow [out] ������Ƭ�к�
	//! \param nCol [out] ������Ƭ�к�
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ�����Ƭ��λ��
	void ComputeGridPosition(UGdouble dMapScale, const UGPoint2D &pntCenter, UGint &nRow, UGint &nCol);

	//! \brief ����һ����Χ���ż�����Ƭ֮��ķ�Χ
	//! \param dMapScale ��ͼ������
	//! \param rcMapBounds ��ͼ��Χ
	//! \param nExtTileSize ������Ƭ�ĸ���
	//! \return ����֮��ĵ�ͼ��Χ
	UGRect2D ComputeGridsMPBounds(UGdouble dMapScale, const UGRect2D& rcMapBounds, const UGRect& rcExtend = UGRect(0, 0, 0, 0));

	UGSize2D ComputeGridMPSize(UGdouble dMapScale) const;

protected:
	UGMapCacheVersion m_nMapCacheVersion;	//! ����汾��
	UGdouble m_dCoordRatio;					// LP/DP ת�����ʣ���λΪ(����/����)
	UGdouble m_dUnitsRatio;					//! ͶӰ����ϵ�ĵ�λ��LP/MP��ת��������ʹ�ã�Ĭ���� ��=10000

	// ������Ƭ��Ҫ�Ĳ���
	UGFishingNetGirdSize m_nGirdSize;		//! ������������ر߳���Ĭ�� 256 ����
	UGRect2D m_rcMapBounds;					//! ��������ķ�Χ��ʵ��ֻʹ���˵�ͼ�����Ͻ�

};

}

#endif // !defined(AFX_UGFINISHINGNETARITHMETIC_H__37037E0D_8ABC_413E_B8BE_2B8916F0319E__INCLUDED_)