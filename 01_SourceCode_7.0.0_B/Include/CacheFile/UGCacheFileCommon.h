#ifndef _UGCACHEFILECOMMON_H_
#define _UGCACHEFILECOMMON_H_

#include "FileParser/UGExchangeFileType.h"
#include "Stream/UGByteArray.h"
#include "CompactFile/UGCompactFile.h"
#include <limits>

#if defined(_MSC_VER)

typedef unsigned int uint32_t;
typedef __int64 int64_t;
typedef int int32_t;
typedef unsigned int uint32_t;

#else

#include <stdint.h>

#endif

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

#define UG_ABSCACHEFILE_EXT _U(".sci")
#define UG_ARCFILE_EXT _U(".xml")
#define UG_SOLID_FILENAME _U("solid.dat")
#define HASHCODE_LENGTH 8


namespace UGC 
{

const int nMaxTileSize = 2048;
const int nMinTileSize = 64;

//struct CompactCacheFilePosition
//{
//	UGdouble dScale;
//	UGint nRow;
//	UGint nCol;
//
//	CompactCacheFilePosition()
//	{
//		dScale = 0;
//		nRow = 0;
//		nCol = 0;
//	}
//};

enum UGMapCacheVersion 
{
	Version_UNKNOWN = 0,
	Version_10 = 10,
	Version_20 = 20,
	Version_21 = 21,
	Version_30 = 30,
	Version_31 = 31,
	Version_40 = 40,
	Version_41 = 41,
	Version_50 = 50,
	Version_70 = 70,
};

class UGCompactFileWrapper
{
public:
	UGCompactFile compactFile;
	UGint nTileGroupRow;
	UGint nTileGroupCol;
	UGdouble dScale;
	
	UGCompactFileWrapper()
	{
		// ���ջ��� 25 ����ƣ�������к�Ϊ�Ƿ�ֵ
		nTileGroupCol = std::numeric_limits<UGint>::min();
		nTileGroupRow = std::numeric_limits<UGint>::min();

		dScale = 0;
	}
};

enum UGMapCacheStrategy
{
	UNKNOWN = -1,

	Cache_ISDOTNET = 0,		// IS.Net��SFC�Ļ������

	Cache_UGC = 1,			// UGC �Ļ������

	Cache_iServer20 = 2,	// ��ӦiServer20���ԣ���ISJava���׻��淽ʽ

	Cache_iServer6R3D = 6	// ��ά����
};

// ������������Ľṹ�塣��С�ɶ��������Ϊ����
struct UGHPDataArea
{

	// ��Ƭ�������������ڵ�λ��
	int32_t nStartGroupRow;		// ��ʼ��Ƭ���кţ���������
	int32_t nEndGroupRow;		// ��ֹ��Ƭ���кţ���������
	int32_t nStartGroupCol;		// ��ʼ��Ƭ���кţ���������
	int32_t nEndGroupCol;		// ��ֹ��Ƭ���кţ���������

	// ��Ƭ�����������ڵ�λ��
	int32_t nStartTileRow;		// ��ʼ��Ƭ�кţ���������
	int32_t nEndTileRow;		// ��ֹ��Ƭ�кţ���������
	int32_t nStartTileCol;		// ��ʼ��Ƭ�кţ���������
	int32_t nEndTileCol;		// ��ֹ��Ƭ�кţ���������

	// ���������������е�λ��
	int64_t nStartPixelRow;		// ��ʼ�����кţ���������
	int64_t nEndPixelRow;		// ��ֹ�����кţ���������
	int64_t nStartPixelCol;		// ��ʼ�����кţ���������
	int64_t nEndPixelCol;		// ��ֹ�����кţ���������
};

struct TileGroupArea
{
	int32_t left;		// ��ʼ��Ƭ���кţ���������
	int32_t top;		// ��ʼ��Ƭ���кţ���������
	int32_t right;		// ��ֹ��Ƭ���кţ���������
	int32_t bottom;		// ��ֹ��Ƭ���кţ���������

	TileGroupArea()
	{
		Reset();
	}

	void Reset()
	{
		left = 0;
		right = -1;
		top = 0;
		bottom = -1;
	}

	void SetValues(int32_t left, int32_t top, int32_t right, int32_t bottom)
	{
		this->left = left;
		this->top = top;
		this->right = right;
		this->bottom = bottom;
	}
};


// ���������������е�λ��
// ��ʵ���Ͼ���һ�� UGRect������ UGRect �ĳ�Ա���� int �ͣ��� 32 λ�����ϲ��ܴﵽ��Χ��ʾ��Ҫ��
struct PixelArea
{
	int64_t left;		// ��ʼ�����кţ���������
	int64_t top;		// ��ʼ�����кţ���������
	int64_t right;		// ��ֹ�����кţ���������
	int64_t bottom;		// ��ֹ�����кţ���������

	PixelArea()
	{
		Reset();
	}

	int64_t Width() const
	{
		return right - left + 1;
	}

	int64_t Height() const
	{
		return bottom - top + 1;
	}

	void Reset()
	{
		left = 0;
		right = -1;
		top = 0;
		bottom = -1;
	}

	void SetValues(int64_t left, int64_t top, int64_t right, int64_t bottom)
	{
		this->left = left;
		this->top = top;
		this->right = right;
		this->bottom = bottom;
	}
};

//enum TileGroupSize
//{
//	SIZE_16		= 16,
//	SIZE_32		= 32,
//	SIZE_64		= 64,
//	SIZE_128	= 128
//};

// ����������Ƭ����Ƭ����
struct TileArea
{
	int32_t left;		// ��ʼ��Ƭ�кţ���������
	int32_t top;		// ��ʼ��Ƭ�кţ���������
	int32_t right;		// ��ֹ��Ƭ�кţ���������
	int32_t bottom;		// ��ֹ��Ƭ�кţ���������

	TileArea()
	{
		Reset();
	}

	void Reset()
	{
		left = 0;
		right = -1;
		top = 0;
		bottom  = -1;
	}

	void SetValues(int32_t left, int32_t top, int32_t right, int32_t bottom)
	{
		this->left = left;
		this->top = top;
		this->right = right;
		this->bottom = bottom;
	}

	UGulong GetSize()
	{
		return (UGulong(right) - left + 1) * (bottom - top + 1);
	}
};


const unsigned FilterFileCellSize = 5;
const unsigned nMaxDPI = 2000;
const unsigned nMinDPI = 10;
const unsigned nCompactTileHeadSize = 12;	// Ŀǰ������Ƭͷ��С12���ֽ�

// Filter File ר��
const unsigned char Filter_Exist_Bit = 0;
const UGint nTileGroupSize = 128;
const UGint PNG8 = 8888;

}

#endif // _UGCACHEFILECOMMON_H_