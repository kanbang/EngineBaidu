// UGSpatialIndexInfo.h: interface for the UGSpatialIndexInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSPATIALINDEXINFO_H__DFDA261E_05C0_46C7_A3E6_08A2A6CAA872__INCLUDED_)
#define AFX_UGSPATIALINDEXINFO_H__DFDA261E_05C0_46C7_A3E6_08A2A6CAA872__INCLUDED_

#include "Stream/ugdefs.h"

namespace UGC {

//! \brief �ռ���������ö��
enum IndexType
{       //! \brief û������
	    IdxNone		= 1,
		//! \brief Rtree����
		IdxRTree	= 2,
		//! \brief �Ĳ�������
		IdxQTree	= 3,	
		//! \brief ͼ������ UGC�ﲻ֧�ֱ༭	
		IdxTile		= 4,		
		//! \brief multi-level Grid
		IdxDynamic  = 5,		
};

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
class SPATIALINDEX_API UGSpatialIndexInfo 
#else
class ENGINE_API UGSpatialIndexInfo 
#endif
{
public:
	//! \brief �������͹���
	UGSpatialIndexInfo();

	//! \brief �������͹���
	UGSpatialIndexInfo(IndexType nIndexType);

	//! \brief �༶�����������캯��
	UGSpatialIndexInfo(UGPoint2D	pntCenter,
						UGdouble	dGrid0,
						UGdouble	dGrid1,
						UGdouble	dGrid2,
						UGdouble	dGridRatio);

	//! \brief R���������캯��
	UGSpatialIndexInfo(UGint nQuality,UGString strSort);

	//! \brief ͼ������
	UGSpatialIndexInfo(UGString	strTileFieldName);

	//! \brief ͼ������
	UGSpatialIndexInfo(UGdouble	dWidth,UGdouble	dHeight);

	//! \brief �Ĳ�������
	UGSpatialIndexInfo(UGint nLevel);

	//! \brief
	UGSpatialIndexInfo& operator=(const UGSpatialIndexInfo& info);

	//! \brief ��������
#ifdef SYMBIAN60
	~UGSpatialIndexInfo();
#else
	virtual ~UGSpatialIndexInfo();
#endif

public:
	//! \brief �ռ���������
	IndexType	nIndexType; 

	//! \brief R�������ֵ * 50��ΪҶ�Ӱ��Ķ������
	UGint		nQuality;	

	//! \brief ��չ��R������Ȩ���ֶΣ����Ϊ����ʾ������QueryMode ΪFuzzyQuery��ʱ��ʹ��
	UGString	strSort;

	//! \brief ͼ�����������������������ֶ�
	UGString	strTileFieldName;

	//! \brief ͼ�������������������ӵĿ��
	UGdouble	dWidth;
	//! \brief ͼ�������������������ӵĸ߶�
	UGdouble	dHeight;

	//! \brief �༶�������������ĵ��λ��
	UGPoint2D	pntCenter;	
	//! \brief �༶����������0���ĸ��ӵĿ��
	UGdouble	dGrid0;
	//! \brief �༶����������1���ĸ��ӵĿ��
	UGdouble	dGrid1;	
	//! \brief �༶����������2���ĸ��ӵĿ��
	UGdouble	dGrid2;
	//! \brief �༶���������и��ӵĴ�С
	UGdouble	dGridRatio;
};

}

#endif // !defined(AFX_UGSPATIALINDEXINFO_H__DFDA261E_05C0_46C7_A3E6_08A2A6CAA872__INCLUDED_)

