//#pragma once

#ifndef _UGVECTORCACHEPARAMATER_H_
#define _UGVECTORCACHEPARAMATER_H_

#include "Stream/ugdefs.h"
#include "Geometry/UGDataCodec.h"
#include "Projection/UGPrjCoordSys.h"

namespace UGC
{

// ���������Χ
struct UGGridArea
{
	// ��Ƭ�����������ڵ�λ��
	UGint nLevel;		// �����߲㼶
	UGint nStartRow;	// ��ʼ�кţ���������
	UGint nEndRow;		// ��ֹ�кţ���������
	UGint nStartCol;	// ��ʼ�кţ���������
	UGint nEndCol;		// ��ֹ�кţ���������
};

class FILEPARSER_API UGVectorCacheParamater
{
public:
	UGVectorCacheParamater(void);
	virtual ~UGVectorCacheParamater(void);

public:
	enum VectorCacheType
	{
		SCV		= 0,			// ��ά����
		SCM		= 1,			// ��������
	};
	enum TileSplitType
	{
		GLOBAL		= 0,		// ȫ���ʷ�
		LOCAL		= 1,		// �����ʷ�
	};
	enum TileStorageType
	{
		Original		= 0,	// ԭʼ�ļ�
		Compact	= 1,	// �����ļ�
		Single	        = 2, //
	};

public:
	// ���뵼�������ļ�
	UGbool ToConfigFile(UGString strPath);
	UGbool FromConfigFile(UGString strPath);

	// ������Ƭ�����кţ��ж�ָ����Ƭ�������Ƿ����
	UGbool IsTileExist(UGdouble dScale, UGint nRow, UGint nCol);

	//! \���ݵ�ͼ��Χ����ͼƬ���кŷ�Χ
	//! \param dMapScale [in]		������
	//! \param rcMapBounds [in]		��ͼ��Χ
	//! \param nStartRow [out]		ͼƬ��ʼ�к�
	//! \param nEndRow [out]		ͼƬ�����к�
	//! \param nStartCol [out]		ͼƬ��ʼ�к�
	//! \param nEndCol [out]		ͼƬ�����к�
	//! \param bBigTileImage [in]	�Ƿ��Ǵ��ͼƬ
	//! remarks ��ͼ����ʹ�á���Ҫ�ǳ�ͼʱʹ��
	void ComputeTileRange(UGdouble dMapScale, const UGRect2D& rcMapBounds, UGGridArea &GridArea);

	//! \���ݸ����ı����߼���Ƭ���кż�����Ƭ��Χ
	//! \param dMapScale [in]		������
	//! \param nRow [in]			ͼƬ�к�
	//! \param nCol [in]			ͼƬ�к�
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ��㵥����Ƭ�ķ�Χ
	UGRect2D ComputeTileMPBounds(UGdouble dMapScale, UGint nRow, UGint nCol);

	//! \���ݸ����ı����߼����ĵ������Ƭλ��
	//! \param dMapScale [in] ������
	//! \param center [in] ָ�������ĵ�
	//! \param nRow [out] ������Ƭ�к�
	//! \param nCol [out] ������Ƭ�к�
	//! remarks ��ͼ����ʹ�á���Ҫ�Ǽ�����Ƭ��λ��
	void ComputeTilePosition(UGdouble dMapScale, const UGPoint2D &pntCenter, UGint &nRow, UGint &nCol);

	// ����Tile��ȫ·����
	UGString ComputeTileFullName(UGdouble dMapScale, UGint nRow, UGint nCol, UGbool bBuild = true);

	UGdouble ComputeScale(UGdouble dMP = 180, UGint nDP = 256);
	UGdouble ComputeMPSize(UGdouble dScale, UGint nDP = 256);


	// ��ȫ�������Ƭ���кŻ���ɶ�Ӧ���ջ�������к�
	static void ConvertRowCol(UGint& nRow, UGint& nCol);

	// ͨ����Ƭ��λ�ü�����Ƭ��λ��
	static void CompactCellPos2TilePos(UGint nTileGroupRow, UGint nTileGroupCol, UGint nCellRow, UGint nCellCol, UGint &nTileRow, UGint &nTileCol);

	// ͨ����Ƭλ�ü�����Ƭ���λ��
	static void TilePos2TileGroupPos(UGint nTileRow, UGint nTileCol, UGint &nGroupTileRow, UGint &nGroupTileCol);


	// ͶӰ��Ϣ�����ʼ������ϵ��λ�ͻ���ο�ԭ��
	void				 SetPrjCoordSys(const UGPrjCoordSys &CoordSys);
	const UGPrjCoordSys &GetPrjCoordSys() const;

	//! \brief ��ȡ����İ汾��
	UGfloat GetVersion() const;
	
	void SetVersion(UGfloat fVersion); 

	void		SetCacheName(const UGString &strCacheName);
	UGString	GetCacheName() const;

	void		SetCachePath(const UGString &strCachePath);
	UGString	GetCachePath() const;

	UGString	GetCacheFolderName() const;
	void			SetCacheFolderName(const UGString& floderName);

	void		SetLevel0MPSize(UGdouble dLevel0MPSize);
	UGdouble	GetLevel0MPSize() const;

	void		SetLevel0DPSize(UGint nLevel0DPSize);
	UGint		GetLevel0DPSize() const;

	void		SetOrigin(UGPoint2D pntOrigin);
	UGPoint2D	GetOrigin() const;


	void		SetDPI(UGdouble dDPI);
	UGdouble	GetDPI() const;


	void		SetVectorCacheType(UGVectorCacheParamater::VectorCacheType nCacheType);
	UGVectorCacheParamater::VectorCacheType 	GetVectorCacheType() const;

	void		SetBounds(UGRect2D rcBounds);
	UGRect2D	GetBounds() const;

	void		SetOutputScaleCaptions(const std::map<UGdouble, UGString> &mapScaleCaptions);
	void		GetOutputScaleCaptions(std::map<UGdouble, UGString> &mapScaleCaptions) const;

	//! \brief ����ָ���������µ���ƬMPSize
	UGSize2D ComputeTileMPSize(UGdouble dMapScale);

	// ��ȡ�������ڱ������������������Ҳ�������-1��
	UGint GetScaleIndex(UGdouble dScale);

	// ����Level0��MP��DP����ָ�����������ڵڼ��㣬��ƥ��ı����ߺ�������-1
	UGbyte GetLevel(UGdouble dScale);
	// ����Level0��MP��DP����ָ���㼶�ı�����
	UGdouble GetScale(UGbyte nLevel);

	//! \brief��ȡʸ��������
	UGint GetDataType() const;
	void SetDataType(UGint nDataType);

	//! \brief ��Ƭ�ʷ�����
	void SetTileSplitType(UGVectorCacheParamater::TileSplitType nTileType);
	UGVectorCacheParamater::TileSplitType GetTileSplitType() const;

	//! \brief ��Ƭ�ļ��洢����
	void SetTileStorageType(UGVectorCacheParamater::TileStorageType nStoreType);
	UGVectorCacheParamater::TileStorageType GetTileStorageType() const;

	//! \brief��Ƭ�ļ���ѹ������
	//! \remarks ��ֻ֧��ZIP,Ĭ�ϲ�ѹ��
	void SetTileCompressionType(UGDataCodec::CodecType nCompressType);
	UGDataCodec::CodecType GetTileCompressionType() const;

	//! \brief ���ѹ�����������
	//! \remarks ��ֻ֧��dds��pvrtc��Ĭ�ϲ���dds
	UGDataCodec::CodecType GetTextureCompressionType() const;
	//! \brief ����ѹ�����������
	//! \remarks ��ֻ֧��dds��pvrtc��Ĭ�ϲ���dds
	void SetTextureCompressionType(UGDataCodec::CodecType nTexCompressionType);

	//! \brief ���ݸ����������ҵ����ƥ�������
	UGdouble Round2NearestScale(double dScale);

	//! \brief ���á���ȡ�Զ���汾��
	UGint	GetRevisionNumber();
	void	SetRevisionNumber(UGint number);

	//! \brief ����Զ���汾�ŵ��汾�б���
	void AddRevisionNumberToSortedArray(UGint nRevisionNumber);

private:
	//! \brief ��ȡ�������ɵ���Ƭ���·������ʽΪ 1000/1/9/2x4
	//! \param dScale [in]		��ǰ��ͼ�ı�����
	//! \return						��ȡ���ɵ���Ƭ���·��
	//! \remarks					�������£�
	UGString TilePos2RelativeOriginalFileNamePrefix(double dScale, int nRow, int nCol);

	UGString ConvertVectorCacheTypeToString(UGVectorCacheParamater::VectorCacheType nCacheType);
	UGVectorCacheParamater::VectorCacheType ConvertStringToVectorCacheType(UGString strCacheType);


private:
	UGfloat			m_fVersion;					// ����汾��
	UGArray<UGint>	m_nRevisionNumberList;		// �û��Զ������ݰ汾����
	UGString		m_strCacheName;				// �������ơ�����������������Ϊ����Դ��ʽ���м���ʱ������Դ���ƣ����ļ�����
	UGdouble		m_dLevel0MPSize;					// ��0����Ƭ����߳���
	UGint			m_nLevel0DPSize;					// ��0����Ƭ���ر߳���
	std::map<UGdouble, UGString> m_mapOutputScaleCaptions;	// �����ߡ�����

	UGPoint2D		m_pntOrigin;					// �ο�ԭ��
	UGdouble		m_dDPI;							// ÿӢ���ж��ٸ����أ�Ĭ��ֵ96�������ʱ�����û����š�

	VectorCacheType		m_nCacheType;					// �ļ���ʽ������ʸ����Ƭ������ʸ����Ƭ
	UGPrjCoordSys 		m_PrjCoordSys;					// ͶӰ��Ϣ������ͼ������ص���ά�����еı�����Ϣ��
	UGRect2D			m_rcBounds;						// ����ĵ���Χ��������Ϊ����Դ��ʽ���м���ʱ������Դ��Χ�������û��޸�

	
	UGint					m_nDataType;				//! \briefʸ�����������ͣ��㡢�ߡ��棬������ʸ����Ƭ���ݼ�����ΪCAD
	TileSplitType			m_nTileSplitType;			//��Ƭ�ʷ����ͣ�����/ȫ���ʷ�
	TileStorageType			m_nTileStorageType;			//��Ƭ�ļ��洢����
	UGDataCodec::CodecType	m_nTileCompressionType;		//��Ƭ�ļ�ѹ������
	UGDataCodec::CodecType	m_nTexCompressionType;		//! \brief ����ѹ����ʽ


	// ���±���ֻ������Ƭ������ʱ�򣬲���Ҫ�����scv�����ļ���
	UGString		m_strCachePath;					// ������λ�ã���Ŀ¼�¼�Ŀ¼�ǻ������ļ��еĻ����Ŀ�ļ���¼
	UGString		m_strCacheFolderName;			// �����Ŀ�ļ���¼������Ŀ¼�·���SCV�����ļ���ͶӰ�ļ��������߲㼶���������ñ���ļ���Ĭ��Ϊ"",���Ϊ""�����ݸ���������ͬ
	UGint			m_nRevisionNumber;				// �û���ǰ���õ��Զ������ݰ汾��

};
}
#endif //_UGVECTORCACHEPARAMATER_H_