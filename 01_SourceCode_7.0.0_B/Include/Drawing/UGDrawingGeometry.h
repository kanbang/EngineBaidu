// UGDrawingGeometry.h: interface for the UGDrawingGeometry class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGDRAWINGGEOMETRY_H
#define UGDRAWINGGEOMETRY_H

#include "Stream/ugdefs.h"
#include "Drawing/UGDrawing.h"
namespace UGC{
#ifdef SYMBIAN60
class DRAWING_APIC UGDrawingGeometry
#else
class DRAWING_API UGDrawingGeometry
#endif
{
public:
	DRAWING_APIF UGDrawingGeometry();
	virtual DRAWING_APIF ~UGDrawingGeometry();

public:
	//! \brief �Ƿ�֧�ּ��ζ�������
	virtual DRAWING_APIF UGbool IsSupportGeometry(UGint nGeometryType);
	//! \brief �õ�����֧�ֵļ��ζ�������
	virtual DRAWING_APIF UGint GetSupportGeoType(UGArray<UGint>& nTypeArray);
	//! \brief ��ȡ��������
	virtual DRAWING_APIF UGString GetName();
	//! \brief ��ʾ���ζ���
	virtual DRAWING_APIF UGbool DrawingGeometry(UGDrawing* pDrawing,UGGeometry* pGeo);

	//added by xielin 2007-04-30 
    //! \brief ������չ������ƺ���
	//! \param pDrawCustomGeometryFunc ������չ����ĺ���ָ��
	//! \param pWnd ����ָ���Hand
	//! \remarks �û��Զ����geometryֻ�ڻ�����֧�ֻ��ƣ��������̳����У�����DrawingGeometryCAD�У����ô˻ص�����Ҳ����Ч�ģ�������л��ơ�
	DRAWING_APIF void SetDrawCustomGeometryFunc(DRAWCUSTOMGEOMETRYCALLBACKPROC pDrawCustomGeometryFunc,
		UGlong pWnd);
protected:

//{{modified by qianjn in 2010-6-24 13:44:05 �޸�ԭ�򣺶��̳߳�ͼ����

// 	UGbool DrawGeometry(UGGeoPoint* pGeo);
// 	UGbool DrawGeometry(UGGeoLine* pGeo);
// 	UGbool DrawGeometry(UGGeoRegion* pGeo);
// 	UGbool DrawGeometry(UGGeoText* pGeo, UGbool bThemeStyle = false, UGbool bSingleTextStyle = true);	
// 	UGbool DrawGeometry(UGGeoCompound* pGeo
	DRAWING_APIF UGbool DrawGeometry(UGDrawing* pDrawing, UGGeoPoint* pGeo);
	DRAWING_APIF UGbool DrawGeometry(UGDrawing* pDrawing, UGGeoLine* pGeo);
	DRAWING_APIF UGbool DrawGeometry(UGDrawing* pDrawing, UGGeoRegion* pGeo);
	DRAWING_APIF UGbool DrawGeometry(UGDrawing* pDrawing, UGGeoText* pGeo, UGbool bThemeStyle = false, UGbool bSingleTextStyle = true);	
	DRAWING_APIF UGbool DrawGeometry(UGDrawing* pDrawing, UGGeoCompound* pGeo);

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)

// 	UGbool DrawGeometry(UGGeoLineM* pGeo);
// 	UGbool DrawGeometry(UGGeoMultiPoint* pGeo);
// 	UGbool DrawGeometry(UGGeoPicture* pGeo);
	UGbool DrawGeometry(UGDrawing* pDrawing, UGGeoLineM* pGeo);
	UGbool DrawGeometry(UGDrawing* pDrawing, UGGeoMultiPoint* pGeo);
#endif	
	UGbool DrawGeometry(UGDrawing* pDrawing, UGGeoPicture* pGeo);
//}}modified by qianjn in 2010-6-24 13:44:05 �޸����

	//! \return ���㸴�϶����������ƺ�ĵ���bounds(Ŀǰ��ͼ�����õ�������ֻ�������ı���bounds)
	UGbool CalcGeoCompoundBounds(UGDrawing* pDrawing, UGArray<UGGeometry*>& arrGeometry, UGRect2D& rcBounds);

	//! \return ���ݷ�Χ�����ü�����
	UGRgn* CreateClipRgn(UGDrawing* pDrawing, UGRect2D rcBounds);


	DRAWING_APIF void AttachDrawing(UGDrawing* pDrawing);
	friend class UGDrawing;
protected:
	UGDrawing* m_pDrawing;

private:
	//added by xielin 2007-04-30��չ������ƻص�����
	DRAWCUSTOMGEOMETRYCALLBACKPROC m_pDrawCustomGeometryFunc;
	UGlong m_pDrawCustomGeometryWnd;
	

};

}

#endif // !defined(AFX_UGDRAWINGGEOMETRY_H__19C27E20_03AE_45A6_8592_9EB5EF5584FE__INCLUDED_)

