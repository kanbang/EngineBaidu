// UGDrawing.h: interface for the UGDrawing class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDrawing.h
   **************************************************************************************
    \author   ���������¹���
    \brief    ��ʾ��                                                                 
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGDRAWING_H__AAC47E2E_B5B6_476C_9462_FBF34F02DFF5__INCLUDED_)
#define AFX_UGDRAWING_H__AAC47E2E_B5B6_476C_9462_FBF34F02DFF5__INCLUDED_

#include "Drawing/UGDrawCache.h"
#include "Drawing/UGDrawParamaters.h"
#include "Drawing/UGDrawMaker.h"
#include "Engine/UGDataSource.h"
#include "Stream/ugplatform.h"
#include "Toolkit/UGProgress.h"
#include "Drawing/UGMakerCache.h"

namespace UGC {	

typedef void (UGSTDCALL *DRAWPAINTPROC)(UGGraphics* pGraphics, UGlong pPaintWnd);

// by zengzm 2007-3-26 ��__stdcall���嵽ugplatform��
typedef void (UGSTDCALL *DRAWCALLBACKPROC)(UGint nPercent, UGbool &bCancel, UGlong pWnd);
typedef void (UGSTDCALL *REFRESHCALLBACKPROC)(UGlong pWnd);

typedef void (UGSTDCALL *REPAINTCALLBACKPROC)(UGlong pWnd);
typedef void (UGSTDCALL *REFRESHMAPCALLBACKPROC)(UGdouble dMapScale, const UGRect2D &rcBounds, UGlong pWnd);
typedef void (UGSTDCALL *THREADCALLBACKPROC)(UGlong pWnd);
typedef void (UGSTDCALL *THREADCANCALECALLBACKPROC)(UGlong pWnd);
//#ifdef WIN32
//typedef void (__stdcall *DRAWCALLBACKPROC)(UGint nPercent, UGbool &bCancel, UGuint pWnd);
//#else
//typedef void (*DRAWCALLBACKPROC)(UGint nPercent, UGbool &bCancel, UGuint pWnd);
//#endif
//added by xielin 2007-04-30 
//! \brief �ص�������������չ�������
//! \param 		pGraphics		��ǰ���Ƶ�Graphics�������ڸ�Graphics�ϻ��ƶ���
//! \param 		pGeometry		��չ����
//! \param 		pWnd			ʵ�ָûص����������ָ��
typedef void (UGSTDCALL *DRAWCUSTOMGEOMETRYCALLBACKPROC)(UGGraphics* pGraphics,UGGeometry* pGeometry,UGlong pWnd);

//! \brief AfterPointInput ��ʱ�����ƻص�����
typedef void (UGSTDCALL *StartTimerProc)(UGlong pWnd, UGint nIDEvent);
typedef void (UGSTDCALL *StopTimerProc)(UGlong pWnd, UGint nIDEvent);

class UGGeoPoint;
class UGGeoLine;
class UGGeoRegion;
class UGGeoText;
class UGGeoCompound;	
class UGGeoLineM;	
class UGGeoMultiPoint;
class UGMakerCache;

// addey by macx 2008.7.31 ��
//! \brief �����PDF�ķ��ѡ�� 
//! \remarks ��ע��Ϣ��
enum UGOutputStyle
{
		UG_STYLE_NOSTYLE					=   0x00000000, //û���κη��,Ϊ0
		UG_STYLE_POINT						=	0x00000001,	//�Ƿ񺬵����1
		UG_STYLE_LINE						=	0x00000002,	//�Ƿ��߷���2
		UG_STYLE_REGON						=	0x00000004,	//�Ƿ��Ƿ������4
		UG_STYLE_ALLSTYLE					=	0x00000007,	//�������,����ȫ����� 1 + 2 + 4 = 7
};

typedef OGDC::PixelFormat UGPixelFormat;

struct DRAWING_API UGRasterStretchOption
{
	enum StretchType
	{
		none					= 0,
		StandardDeviation		= 1,
		MinimumMaximum			= 2,
		HistogramEqualization = 3,
		HistogramSpecification = 4,
		Gaussian = 5
	};

	// ���췽ʽ
	StretchType	eType;

	// ��׼���������
	UGdouble	dDevParam;

	// ֱ��ͼ�涨������
	UGArray<UGHistogram> arrStandardHistogram;

	// ��˹�������
	UGdouble	dGaussianRatio;
	UGbool		isGaussianMid;

	UGRasterStretchOption()
	{
		eType = none;
		dDevParam = 2.0;

		dGaussianRatio = 2.0;
		isGaussianMid = true;
	}

};

class DRAWING_API UGDrawing  
{
public:
	UGDrawing();

#ifdef SYMBIAN60
	~UGDrawing();
#else
	virtual ~UGDrawing();
#endif

public:
	//! \brief ���Ƽ��ζ���
	//! \param pGeometry ���ζ���
	//! \return �����Ƿ�ɹ�
	UGbool Draw(UGGeometry* pGeometry);
	//! \brief �����ı�
	//! \param UGGeoText �ı�����
	//! \param bThemeStyle �Ƿ��Ǳ�ǩ��ʽ
	//! \param bSingleTextStyle �Ƿ���ƴ�����ı������Լ��ķ��
	//! \return �����Ƿ�ɹ�
	UGbool Draw(UGGeoText* pGeoText, UGbool bThemeStyle, UGbool bSingleTextStyle = true);
    //! \brief �������ݼ�
	//! \param pDataset �ı�����
	//! \param nTransparentRate ͸����
	//! \param UGProgress ��������
	//! \return �����Ƿ�ɹ�
	UGbool Draw(UGDataset* pDataset, UGProgress* pProgress = NULL);
	  
	//! \brief ��ȡ�ı����
	//! \return �ı���� 
	UGTextStyle GetTextStyle() const;
    //! \brief ���ζ�����
	//! \return ���ζ����� 
	UGStyle GetStyle() const;
	//! \brief ���ü��ζ�����
	//! \return ���ؾɵļ��ζ����� 
	//! \remarks ������Ҫʹ�øú������ú���ֻ�޸ķ�����ʽ���Ƽ�ʹ��Prepare����
	void SetStyle(const UGStyle& style);
	//! \brief ���õ�ǰ��ʾ����
	//! \param style ���ü����������
	//! \param nDimesion ���϶����ά��
	//! \return ��ǰ����ʾ�ߴ�
	UGbool Prepare(const UGStyle& style, const UGint nDimesion);
	//! \brief ���õ�ǰ��ʾ����
	//! \param style ���ü����������
	//! \param nDimesion ���϶����ά��
	//! \�����Ƿ�ɹ� ��ǰ����ʾ�ߴ�
	UGbool Prepare(const UGTextStyle& style, UGbool bThemeStyle = FALSE);
	//! \brief �ͷŵ�ǰ����
	void Release();
	//! \brief ��ȡGraphics����
	//! \return ����Graphics����
	UGGraphics* GetGraphics() const;
	//! \brief ����Graphics����
	//! \param pGraphics Ҫ���õ�Graphics���� 
	//! \return ���ؾɵ�Graphics����
	UGGraphics* SetGraphics(UGGraphics* pGraphics);
	//! \brief ���㿪ʼ���Ƶ�ʱ��
	//! \param pGraphics ʹ�õ�Graphics����
	void BeginCalculateTime(UGGraphics* pGraphics);
	//! \brief ����������Ƶ�ʱ��
	void EndCalculateTime();
	//! \brief �ж��Ƿ�ʼ����
	//! \return �Ƿ�ʼ����
	UGbool IsBeginCalculateTime();
	//! \brief ˢ��ͼ��
	void OvertimeRefresh();
	//! \brief  ��ʾ�жϺ���ʾˢ����Ϣ
	UGbool DrawCallBack();
	//! \brief ��Graphicsͼ����ƶ���
	//! \param  Graphicsͼ����ƶ���
	void OnPaint(UGGraphics* pGraphics);

	UGbool RefreshCallBack();
	UGbool RePaintCallBack();
	UGbool RefreshMapCallBack(UGdouble dMapScale, const UGRect2D &rcBounds);
	void ThreadCallBack();
	void ThreadCancleCallBack();
	//! \brief ������չ������ƺ���
	//! \param pDrawCustomGeometryFunc ������չ����ĺ���ָ��
	//! \param pWnd ����ָ���Hand 
	void SetDrawCallBackFunc(DRAWCALLBACKPROC pDrawCallBackFunc, UGlong pWnd);
    //! \brief ������չ������ƺ���
	//! \param pDrawCustomGeometryFunc ������չ����ĺ���ָ��
	//! \param pWnd ����ָ���Hand 
	void SetDrawPaintFunc(DRAWPAINTPROC pDrawPaintFunc, UGlong pPaintWnd);
	//added by xielin 2007-04-30 
    //! \brief ������չ������ƺ���
	//! \param pDrawCustomGeometryFunc ������չ����ĺ���ָ��
	//! \param pWnd ����ָ���Hand 
	void SetDrawCustomGeometryFunc(DRAWCUSTOMGEOMETRYCALLBACKPROC pDrawCustomGeometryFunc,
		UGlong pWnd);

	void SetRefreshCallBackFunc(REFRESHCALLBACKPROC pRefreshCallBackFunc, UGlong pWnd);
	void SetRePaintCallBackFunc(REPAINTCALLBACKPROC pRePaintCallBackFunc, UGlong pWnd);
	void SetRefreshMapCallBackFunc(REFRESHMAPCALLBACKPROC pRefreshMapCallBackFunc, UGlong pWnd);
	void SetThreadCallBackFunc(THREADCALLBACKPROC pThreadCallBackFunc, UGlong pWnd);
	void SetThreadCancleCallBackFunc(THREADCANCALECALLBACKPROC pThreadCancaleFunc,UGlong pWnd);

	//! \brief �ϲ㶨ʱ���ص�����
	void SetStartTimerFunc(StartTimerProc pStartTimerFunc, UGlong pWnd);
	void SendStartTimer(UGint nIDEvent);
	void SetStopTimerFunc(StopTimerProc pStopTimerFunc, UGlong pWnd);
	void SendStopTimer(UGint nIDEvent);

	//added by macx 2008.8.1��
	//! \brief �������PDF�ķ�� 
	//! \param nStyle ���ѡ��[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetOutputToPDFStyle(UGint nStyle);
	
	//! \brief �ж�ĳ���Ƿ����ı�������
	//! \param pGeoText �ı�����
	//! \param pntHitTest Ҫ�жϵĵ�
	//! \return �Ƿ����ı�������
	static UGbool HitTestGeoText(UGGeoText* pGeoText, const UGPoint2D& pntHitTest, UGdouble dTolerance,UGDrawParamaters *pDrawParam);
	//! \brief �ж�ĳ���Ƿ��ڼ��ε���
	//! \param pGeoText ���ε�
	//! \param style ���ζ�����
	//! \param pntHitTest Ҫ�жϵĵ�
	//! \return �Ƿ��ڼ��ε�
	static UGbool HitTestGeoPoint(UGGeoPoint* pGeoPoint, const UGStyle& style, const UGPoint2D& pntHitTest, UGdouble dTolerance, UGDrawing *pDrawing);
	//! \brief ��õ��ı������С
	//! \param pGraphics ���Ƶ�Graphics����
	//! \param strText �ı�����
	//! \return �ı�����Ĵ�С
	static UGSize GetTextSize(UGGraphics *pGraphics, const UGString &strText);
	//! \brief ���ÿ�е��ı�����
	//! \param strText �жϵ��ı�
	//! \param strRows �ָ����ı�
	//! \return �ı��Ĵ�С��UGSize.cx �����е�����ı��� UGSize.cy �ı�����
	static UGSize GetRowStrings(const UGString &strText, UGArray<UGString> &strRows);
	//! \brief �����ı����߼��߽�
	//! \param pGraphics ���Ƶ�Graphics����
	//! \param pntAnchor �ı��Ļ���
	//! \param strText  ������ı�
	//! \param btAlign �ı��Ķ��뷽ʽ
	//! \return �ı����߼��߽�
	static UGRect CalcTextLogBounds(UGGraphics *pGraphics, const UGPoint& pntAnchor, const UGString& strText, UGbyte btAlign);
	//! \brief ����ı�������
	//! \param strText �ı�����
	//! \return �ı�����
	static UGint CalcTextRowCount(const UGString &strText);

	//! \brief ��ȡ�ı����Ͻ����� added by dongfei 2007-03-21
	UGbool GetTextLeftTop(UGPoint & pntAnchor1, const UGString & strText, const UGTextStyle & style);
	//! \brief ��ȡ�ı���������
	UGbool GetTextCenter(UGPoint & pntAnchor1, const UGString & strText, const UGTextStyle & style);
	//! \brief ��ȡ�ȼ����ŷ�Χ����Ĵ�С���������������жϵȼ������ڱ���ʱ���õĺ���

public:
	//! \brief ���ƵĻ�������
	//! \brief ���Ƶ�
	//! \param point Ҫ���Ƶĵ�
	//! \return �����Ƿ�ɹ�
	UGbool Point(const UGPoint& point);
	//! \brief ���Ƶ�
	//! \param x Ҫ���Ƶĵ�x����
    //! \param y Ҫ���Ƶĵ�y����
	//! \return �����Ƿ�ɹ�
	UGbool Point(UGint x, UGint y);

	//{{ add by xiaoys 2012-0626 ���ٲ���Ʒ�����
	//! \brief �����ŵ�
	//! \param pntPos ����߼�����
	//! \param iMarkID ����ID
	//! \����ɹ�����true��ʧ�ܷ���false
	UGbool Point(const UGPoint& pntPos, UGint iMarkID);
	//}} add by xiaoys 2012-0626 ���ٲ���Ʒ�����

	//! \brief ��������������
    //! \param pPoints ����εĵ���ָ��
	//! \param pPntCount ÿ������εĵ���
	//! \param nCount ����εĸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	UGbool PolyPolygon(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount);

	//! \brief ��һ���ı�����
	//! \param UGPoint �ı�����
	//! \param str �ı�
	//! \param style �ı����
	//! \param bThemeStyle �Ƿ��Ǳ�ǩ��ʽ
	//! \param bSingleTextStyle �Ƿ�͵�ǰͼ����ͬһ���ı���ʽ
	//! \return �����Ƿ�ɹ�
	UGbool Text(const UGPoint &pnt, const UGString &str, const UGTextStyle &style, UGbool bThemeStyle = FALSE,UGbool bSingleTextStyle = true);

	//! \brief ��һ������
    //! \param pPoints ���ߵĵ���ָ��
	//! \param nCount �ж��ٸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	UGbool Polyline(const UGPoint* pPoints, UGint nCount);
	//! \brief ���������
    //! \param pPoints �������ߵĵ���ָ��
	//! \param pPntCount ÿ�����ߵĵ���
	//! \param nCount ���ߵĸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	UGbool PolyPolyline(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount);
   //! \brief ��һ�����������
    //! \param pPoints ����εĵ���ָ��
	//! \param nCount �ж��ٸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	UGbool Polygon(const UGPoint* pPoints, UGint nCount);
	//! \brief ������
	//! \param x1 ���ε����Ͻǵ�X���� 
    //! \param y1 ���ε����Ͻǵ�Y���� 
	//! \param x2 ���ε����½ǵ�X����
	//! \param y2 ���ε����½ǵ�Y����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Rectangle(UGint x1, UGint y1, UGint x2, UGint y2);
	//! \brief ������
	//! \param rect ��Ҫ���Ƶľ��� 
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Rectangle(const UGRect& rect);
	//! \brief ����Բ
	//! \param x1 ���Ƶľ��ε����Ͻǵ�X���� 
    //! \param y1 ���Ƶľ��ε����Ͻǵ�Y���� 
	//! \param x2 ���Ƶľ��ε����½ǵ�X����
	//! \param y2 ���Ƶľ��ε����½ǵ�Y����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Ellipse(UGint x1, UGint y1, UGint x2, UGint y2);
	//! \brief ����Բ
	//! \param rect ���Ƶľ��� 
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Ellipse(const UGRect& rect);

	//! \brief    ������
	//! \param x1 ���Ƶľ��ε����Ͻǵ�X���� 
    //! \param y1 ���Ƶľ��ε����Ͻǵ�Y���� 
	//! \param x2 ���Ƶľ��ε����½ǵ�X����
	//! \param y2 ���Ƶľ��ε����½ǵ�Y����
	//! \param x3 ������ʼ���ߵ� 
	//! \param y3 ���߽������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Arc(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4);
	//! \brief    ������
	//! \param pntStart ������ʼ���ߵ� 
	//! \param pntEnd ���߽������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Arc(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd);
	//! \brief    ������
	//! \param x1 ���Ƶľ��ε����Ͻǵ�X���� 
    //! \param y1 ���Ƶľ��ε����Ͻǵ�Y���� 
	//! \param x2 ���Ƶľ��ε����½ǵ�X����
	//! \param y2 ���Ƶľ��ε����½ǵ�Y����
	//! \param x3 ������ʼ���ߵ� 
	//! \param y3 ���ν������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Chord(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4);
//! \brief    ������
	//! \param pntStart ������ʼ���ߵ� 
	//! \param pntEnd ���ν������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Chord(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd);
	//! \brief    ������
	//! \param x1 ���Ƶľ��ε����Ͻǵ�X���� 
    //! \param y1 ���Ƶľ��ε����Ͻǵ�Y���� 
	//! \param x2 ���Ƶľ��ε����½ǵ�X����
	//! \param y2 ���Ƶľ��ε����½ǵ�Y����
	//! \param x3 ������ʼ�� 
	//! \param y3 ���ν�����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Pie(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4);
  //! \brief    ������
	//! \param pntStart ������ʼ���ߵ� 
	//! \param pntEnd ���ν������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Pie(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd);
	//! \brief ��Բ�Ǿ���
	//! \param x1 ���Ƶľ��ε����Ͻǵ�X���� 
    //! \param y1 ���Ƶľ��ε����Ͻǵ�Y���� 
	//! \param x2 ���Ƶľ��ε����½ǵ�X����
	//! \param y2 ���Ƶľ��ε����½ǵ�Y����
	//! \param x3 Բ�Ǿ���X����
	//! \param y3 Բ�Ǿ���Y����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool RoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3);
	//! \brief    ��Բ�Ǿ���
	//! \param rect ���Ƶľ��� 
	//! \param point Բ�Ǿ���XY����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool RoundRect(const UGRect& rect, UGPoint point);

	UGbool GetArcPoints(UGRect &rect, UGdouble dAngleStart, UGdouble dAngleEnd, UGArray<UGPoint> &arr);

	static UGbool CalMarkerSymbolBounds(UGPoint2D pntCentroid,UGDrawing* pDrawing,UGStyle& style,UGRect& rcRect);

	//! \brief ��ͼ�ڴ�ӡ��ͼģʽ�������Ƿ����ˢ��
	void SetOverTimeRefresh(UGbool bOverTimeRefresh);

	//! \brief �жϵ�ͼ�ڴ�ӡ��ͼģʽ���Ƿ����ˢ��
	UGbool IsOverTimeRefresh(UGbool bOverTimeRefresh);

	//! \brief �������ŵ�ͼʱ�Ƿ�ˢ�µ�ͼ
	void SetZoomRefreshFlag(UGbool bRefreshFlag);
	UGbool GetZoomRefreshFlag();

	//! \brief ����ƽ�ƻ���Ч��(Ŀǰ�����ͼʹ��)
	void StartBufferPan();
	void StopBufferPan();
	UGbool IsBufferPanning();

	//! \brief ���Ʋ�����ͼ���Ļ���(���ƹ�������Ҫ���⴦�����ֺ͵����)
	void SetDrawingGeoLegend(UGbool bDrawingGeoLegend);
	UGbool IsDrawingGeoLegend();

	//! \brief �����Ƿ��첽ˢ�µ�ͼģʽ
	void SetAsyncMode(UGbool bAsync);
	UGbool IsAsyncMode() const;

	//! \brief ���ͼģʽ(�첽ģʽ�°�����͵����ֳַ�������ͼ����)
	void SetMultiMapMode(UGbool bMultiMap);
	UGbool IsMultiMapMode() const;

	//! \brief ��ȡ��ͼ���Ʋ���(�첽��ͬ��ģʽ�ǲ�һ����)
	UGDrawParamaters* GetDrawParamaters();
	UGGraphics* GetDrawGraphics();

	//! \brief �����Ƿ�ȡ����ͼ����(�̰߳�ȫ��)
	void SetCancleDrawFlag(UGbool bCancle);
	UGbool IsCancleDrawFlag();

	UGMakerCache* GetMakerCache();

public:
	//! \brief ��ͼ����ת�����߼�����(�߾���ģʽ)
	//! \param szSource Ҫת��������
	//! \param szTarget ת���������
	void MPtoLP(const UGPoint2D& pntSource, UGPoint& pntTarget);
	//! \brief ��ͼ����ת�����߼�����(�߾���ģʽת��)
	//! \param pPoints ��Ҫת���ĵ㴮
	//! \param nCount �㴮�ĸ���
	//! \return ת���Ƿ�ɹ�
	UGbool MPtoLPBatch(const UGPoint2D* pPoints, UGint nCount);	
	//! \brief ��ͼ����ת�����߼�����(�߾���ģʽת��)
	//! \param pPoints �㴮��ָ��
	//! \param nCount �㴮�ļ��ζ���ĸ���
	//! \param arrPolycounts ÿ�����ζ���ĵ�ĸ���
	//! \return ת���Ƿ�ɹ�
	UGbool MPtoLPBatchPredigest(const UGPoint2D* pPoints, UGint nCount, UGArray<UGuint>& arrPolycounts);

protected:
	UGbool DrawDataset(UGDatasetVector* pDatasetV,UGProgress* pProgress = NULL);
	UGbool DrawDataset(UGDatasetRaster* pDatasetR,UGProgress* pProgress = NULL);
	///////////////////////////////////////////////////////
	// ��һ���Ա�ǻ���դ�����ݼ�ʱ��Ҫ��
	UGbool PaintRaster(UGint nTransparentRate = 0,UGProgress* pProgress = NULL);
	void PaintImgBegin();
	UGbool PaintImgBlock(UGImgBlock* pIBlock, UGint nTransparentRate);
	UGColor ImageIndexToColor(UGint nColor, const UGPixelFormat& pixelFormat);
	UGbool PaintViewBlock(UGImgBlock* pIBlock);
	///////////////////////////////////////////////////////	

	//////////////////////////////////////////////////////////////////////////
	UGbool PaintDatasetRaster(UGint nTransparentRate, UGProgress* pProgress /*= NULL*/);
	UGbool PaintImgRaster(UGint nTransparentRate, UGProgress* pProgress /*= NULL*/);

	//! \brief ��ȡ��ʾ��Ӱ��顣
	//! \param rcView ��ȡ����ʾ��Ӱ����С[in]��
	//! \param nDeviceWidth �豸���[in]��
	//! \param nDeviceHeight �豸�߶�[in]��
	//! \return ������ʾ��Ӱ��顣
	UGArray<UGImgBlock*> GetViewBlock(const UGRect2D& rcView, UGint nDeviceWidth, UGint nDeviceHeight, UGbool &bFinished);

	UGbool PrintViewRaster(const UGRect2D& rcDraw, const UGRect& rcBMP, UGProgress* pProgress);
	UGbool PaintViewRaster(const UGRect2D& rcDraw, const UGRect& rcBMP, UGProgress* pProgress);
	UGbool PaintViewOnePixelRaster(UGbool bPixDrawMode, const UGRect2D& rcDraw, const UGRect& rcImage, UGProgress* pProgress);

	//! \return �����ü�����
	UGRgn* CreateClipRgn(UGGraphics* pGraphics, UGGeoRegion *pClipRegion);

	//! \return ���Ʋ�ѯ������ImageBlocks
	UGbool PaintViewImageBlocks(UGArray<UGImgBlock*>& arrImgBlocks);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	//! \return ��ȡդ�����ݼ���ͳ��ֵ
	UGbool GetRasterStatisticsInfo(UGArray<UGint>& arrBandSelect, UGArray<UGdouble>& arrMaxVal, UGArray<UGdouble>& arrMinVal, UGArray<UGdouble>& arrMeanVal, UGArray<UGdouble>& arrStandardDVal);
	UGbool GetPluginRasterStatisticsInfo(UGArray<UGint>& arrBandSelect, UGArray<UGdouble>& arrMaxVal, UGArray<UGdouble>& arrMinVal, UGArray<UGdouble>& arrMeanVal, UGArray<UGdouble>& arrStandardDVal);

	//! \return ֱ��ͼͳ��
	// ���ݼ�ֱ��ͼͳ�ƣ�Ϊ�˱�ֻ֤ͳ��һ�Σ��Ժ�������洢
	UGArray<UGHistogram> CalculateHistogramInfo(UGArray<UGint> arrBandSelect);
	// Ӱ����ֱ��ͼͳ��
	UGArray<UGHistogram> CalculateImagePluginHistogramInfo(UGArray<UGint> arrBandSelect);

	// λ����ؼ���
	UGbool IsSupport(UGPixelFormat ePixelFormat);
	UGint ValueExtent(UGPixelFormat ePixelFormat);

	//! \brief ���ΪRGB
	UGbool CompoundColor(UGImgBlock *pDestImgBlock, UGImgBlock *pSrcImgBlock);
	UGbool CompoundColor(UGImgBlock *pResBlock,UGArray<UGImgBlock*>& arrImgBlock,ImgColorSpace nColorSpace);

	//! \brief ����ԭʼ���������ϵ��
	UGdouble CalcInterpolationScale(UGImgBlock *pImgBlock, UGdouble &dMaxVal, UGdouble &dMinVal, UGdouble &dMeanVal, UGdouble &dStdVal);
	UGdouble CalcStretchScale(UGImgBlock *pImgBlock, UGdouble &dMaxVal, UGdouble &dMinVal, UGdouble &dMeanVal, UGdouble &dStdVal);
	
	//! \brief ������
	UGbool NonaStretchImageBlock(UGImgBlock* pImgBlock, UGdouble dMaxVal, UGdouble dMinVal, UGdouble dMeanVal, UGdouble dStdVal);
	UGbool NonaStretchImageBlock(UGImgBlock *pImgBlock, UGArray<UGImgBlock*>& arrImgBlock,ImgColorSpace nColorSpace, UGArray<UGdouble> arrMaxVal, UGArray<UGdouble> arrMinVal, UGArray<UGdouble> arrMeanVal, UGArray<UGdouble> arrStdVal);

	//! \return ��׼������Ӱ���
	UGbool StandardDevStretchImageBlock(UGImgBlock* pImgBlock, UGdouble dMaxVal, UGdouble dMinVal, UGdouble dMeanVal, UGdouble dStandardDVal, UGdouble dDevParam);
	UGbool StandardDevStretchImageBlock(UGImgBlock *pImgBlock, UGArray<UGImgBlock*>& arrImgBlock,ImgColorSpace nColorSpace, UGArray<UGdouble> arrMaxVal, UGArray<UGdouble> arrMinVal, UGArray<UGdouble> arrMeanVal, UGArray<UGdouble> arrStdVal, UGdouble dDevParam);

	//! \brief ��ֵ����
	UGbool MaxMinStretchImageBlock(UGImgBlock *pImgBlock, UGdouble dMaxVal, UGdouble dMinVal, UGdouble dMeanVal, UGdouble dStdVal);
	UGbool MaxMinStretchImageBlock(UGImgBlock *pImgBlock, UGArray<UGImgBlock*>& arrImgBlock,ImgColorSpace nColorSpace, UGArray<UGdouble> arrMaxVal, UGArray<UGdouble> arrMinVal, UGArray<UGdouble> arrMeanVal, UGArray<UGdouble> arrStdVal);

	//! \return ��˹����Ӱ���
	UGbool GaussianStretchImageBlock(UGImgBlock *pImgBlock, UGdouble dMaxVal, UGdouble dMinVal, UGdouble dMeanVal, UGdouble dStandardDVal, UGdouble dRatio, UGbool isMid);
	UGbool GaussianStretchImageBlock(UGImgBlock *pImgBlock, UGArray<UGImgBlock*>& arrImgBlock,ImgColorSpace nColorSpace, UGArray<UGdouble> arrMaxVal, UGArray<UGdouble> arrMinVal, UGArray<UGdouble> arrMeanVal, UGArray<UGdouble> arrStdVal, UGdouble dRatio, UGbool isMid);

	//! \return ֱ��ͼ��������Ӱ���
	UGbool HistogramEquStretchImageBlock(UGImgBlock* pImgBlock, UGdouble dMaxVal, UGdouble dMinVal, UGdouble dMeanVal, UGdouble dStandardDVal, UGHistogram histogram);
	UGbool HistogramEquStretchImageBlock(UGImgBlock *pImgBlock, UGArray<UGImgBlock*>& arrImgBlock,ImgColorSpace nColorSpace, UGArray<UGdouble> arrMaxVal, UGArray<UGdouble> arrMinVal, UGArray<UGdouble> arrMeanVal, UGArray<UGdouble> arrStdVal, UGArray<UGHistogram> arrHistogram);

	//! \return ֱ��ͼ�涨������Ӱ���
	UGbool HistogramSpcStretchImageBlock(UGImgBlock* pImgBlock, UGdouble dMaxVal, UGdouble dMinVal, UGdouble dMeanVal, UGdouble dStandardDVal, UGHistogram histogram, UGHistogram histogramStandard);
	UGbool HistogramSpcStretchImageBlock(UGImgBlock *pImgBlock, UGArray<UGImgBlock*>& arrImgBlock,ImgColorSpace nColorSpace, UGArray<UGdouble> arrMaxVal, UGArray<UGdouble> arrMinVal, UGArray<UGdouble> arrMeanVal, UGArray<UGdouble> arrStdVal, UGArray<UGHistogram> arrHistogram, UGArray<UGHistogram> arrHistogramStandard);
	//////////////////////////////////////////////////////////////////////////

//{{{added by qianjn in 2009-7-20 16:37:07 ����ԭ��դ��̬ͶӰ

	UGImgBlock* GetFlyPrjImgBlock(UGbool bPrint = FALSE);

//}}added by qianjn in 2009-7-20 16:37:07 ����ԭ��

	//! \��PaintViewBlock����ȡһ���ֹ��õĴ��뵽һ�������У���PaintRaster�л���õ�,��������û��̫�����壬����Ϊ����ȡ�������룬����ά��
	//! \����դ��ֵ��ȡ��Ҫ�������ص���ɫֵ,������DEM��GRID�����ظ�ʽ��ΪIPF_MONO��դ�����ݼ�
	UGColor GetPixelColor(UGdouble dValue, UGColorTable *pColorTable, UGint nNoValue, UGint nStylesSize);
	UGColor GetPixelColor( UGdouble dValue, UGColorDictTable *pClrDictTable, UGint nNoValue );

	UGbool DrawString(UGint x, UGint y, const UGString& strText, UGTextStyle textStyle);
	UGbool DrawPointAndCache(const UGPoint& point, UGMarkerSymbol *pMarkerSymbol);
	UGbool DrawImageData(UGImageData* pImageDataDest, UGint x, UGint y, UGint nWidth, UGint nHeight, UGImageData* pImageDataSrc, UGint xSrc, UGint ySrc);

private:
	//! \brief ��ȡ��ʾ��Ӱ��顣
	//! \param rcView ��ȡ����ʾ��Ӱ����С[in]��
	//! \param nDeviceWidth �豸���[in]��
	//! \param nDeviceHeight �豸�߶�[in]��
	//! \return ������ʾ��Ӱ��顣
	UGImgBlock* GetRasterBlock(UGDatasetRaster* pDatasetR, const UGRect2D& rcBounds, const UGRect& rcImage);
	//! \brief ��ȡ��ʾ��Ӱ��顣
	//! \param rcView ��ȡ����ʾ��Ӱ����С[in]��
	//! \param nDeviceWidth �豸���[in]��
	//! \param nDeviceHeight �豸�߶�[in]��
	//! \return ������ʾ��Ӱ��顣
	UGImgBlock* GetMultiBandRasterBlock(UGDatasetRaster* pDatasetR, const UGRect2D& rcBounds, const UGRect& rcImage);
	UGImgBlock* GetPluginRasterBlock(UGDatasetRaster* pDatasetR, const UGRect2D& rcBounds, const UGRect& rcImage);

private:
	void PaintBlockDataByColorTable( UGImgBlock* pIBlock, UGColorTable *pColorTable, UGint nNoValue, UGint nStylesSize );
	void PaintBlockDataByColorDictTable( UGImgBlock* pIBlock, UGColorDictTable *pColorTable, UGint nNoValue );

private:
	//! \brief ����imageBlock����ɫ�ı䣬�������ȡ��Աȶ��Լ�͸��
	void ProcessColorModify(UGImgBlock *pBlock);
	void ProcessColorModify24(UGImgBlock *pBlock);
	void ProcessColorModify32(UGImgBlock *pBlock);
	void ProcessColorModifyOthers(UGImgBlock *pBlock);

	//! \brief ��ȡ�������ؼ�������ɫ���ԣ��������ȡ��Աȶ��Լ�͸��
	UGColor GetPixelAndProcessColorModify(UGint x, UGint y);

	//! \brief ��ȡ����������ɫ
	UGColor GetPixel(UGImageData& imageData, UGint x, UGint y);

public:
	//! \brief ������ʾ����
	UGDrawParamaters m_DrawParam;
	//! \brief ������ʾ����(����Ƕ��̵߳Ļ����������߳�ʹ�õ�)
	UGDrawParamaters m_MainDrawParam;
	//! \brief ������ʾ����(����Ƕ��̵߳Ļ����������߳�ʹ�õ�)
	UGGraphics* m_pMainGraphics;
	//! \brief ��ʾ����
	UGDrawCache m_DrawCache;
	//! \brief ��ʾ����Ԥ����
	UGDrawMaker m_DrawMaker;
	//modefied by macx 2008-9-26 
	//! \brief ���ƽ��Ȼص�����
	DRAWCALLBACKPROC m_pDrawCallBackFunc;
	//! \brief ��ʾ����
	UGlong m_pWnd;

	REFRESHCALLBACKPROC m_pRefreshCallBackFunc;
	UGlong m_pRefreshWnd;

	REPAINTCALLBACKPROC m_pRePaintCallBackFunc;
	UGlong m_pRePaintWnd;

	REFRESHMAPCALLBACKPROC m_pRefreshMapCallBackFunc;
	UGlong m_pRefreshMapPaintWnd;

	//! \brief ������̻߳ص�
	THREADCALLBACKPROC m_pThreadFunc;
	UGlong m_pThreadWnd;

	//������߳�����ȡ���Ļص�
	THREADCANCALECALLBACKPROC m_pThreadCancleFunc;
	UGlong m_pThreadCancleWnd;
protected:
// 	DRAWCALLBACKPROC m_pDrawCallBackFunc;
// 	UGlong m_pWnd;
	UGbool m_bOverTimeRefresh;

	// ��ͼ��ʱ������Ĭ�ϻ�����1000�����ǿ����������ļ���߶�ȡ�ɡ�
	UGint m_nTimeSlot;

	// �����Ƿ�ˢ�±�ʶ
	UGbool m_bZoomRefreshFlag;
	// ƽ�ƻ����ʶ
	UGbool m_bBufferPanning;
	// �첽ˢ�µ�ͼģʽ
	UGbool m_bAsyncMode;
	// ���ͼģʽ���첽ģʽ�°�����͵����ֲ�ֳ�������ͼ���ƣ�
	UGbool m_bMultiMapMode;

	// �첽ģʽ��ȡ����ͼ����
	UGbool m_bCancleDrawFlag;
	//! \brief ����ǰ����ͼ����
	UGMutex m_CancleDrawMutex;

	UGMakerCache* m_pMakerCache;

public:
	UGlong m_pPaintWnd;
	DRAWPAINTPROC m_pDrawPaintFunc;

	//! \brief ��ʱ�����ƺ���
	UGlong m_pEventView;  //�����¼��ص������Ķ���ָ��
	StartTimerProc m_pStartTimerFunc;
	StopTimerProc m_pStopTimerFunc;

protected:
	UGStyle m_Style;
	UGTextStyle m_TextStyle;
	UGGraphics* m_pGraphics;

	UGGraphics* m_pRefreshGraphics;
	UGbool m_bBeginCalculateTime;
	UGbool m_bBeginDrawImg;
	clock_t m_clockBegin;
	UGint m_nCalculateNum;

	///////////////////////////////////////////////////////
	//��һ���Ա�ǻ���դ�����ݼ�ʱ��Ҫ��
	UGRect m_rcImgPaint;
	UGSize2D m_szImgViewOffset;
	UGSize2D m_szImgViewRatio;
	UGImageData m_ImgInfo;

public:
	UGDatasetRaster *m_pDTRaster;

protected:
	UGImgBlock *m_pDemBlock;
	///////////////////////////////////////////////////////

	//! \brief ���PDFʱҪ�صķ��ѡ��
	//{{�޸�ԭ����������PDF�ķ������ѡ�� �޸���:macx 2008-7-31 9:53:19
	UGint m_nOutputStyle;
	//}}�޸�ԭ����������PDF�ķ������ѡ�� �޸���:macx  2008-7-31 9:53:19
	
	// �Ƿ����ڻ��Ʋ����е�ͼ��(����ͼ����Ҫ���⴦��������Ҫʹ�ñ�־�����ƹ����п�������)
	UGbool m_bDrawingGeoLegend;

public:

#if PACKAGE_TYPE==PACKAGE_UGC
	//! \brief ר��ͼ��ʾģʽ
	//! \remarks 0, theme none; 1, theme unique; 2, theme range;
	UGint m_nDrawMode;
	
	//! \brief �ֶ�ר��ͼ��KEYS
	UGArray <UGdouble> *m_pAryDoubleKeys;
	
	//! \brief ��ֵר��ͼ��KEYS,Ҳ��ugdouble���洢�ɡ�
	UGArray <UGdouble> *m_pAryIntKeys;
	
	//! \brief ר��ͼ���
	UGColorset *m_pStyles;
	
	//! \brief ר��ͼĬ�Ϸ��
	UGColor m_DefaultStyle;
#endif // end declare ugc sdk

	UGint m_nTransparentRate;

	//������Ҫ���̳߳�ͼ��դ�����ݼ��Ĳ��ֱ�����Ϣ���浽Drawing����
	UGColor m_NoDataStyle;
	UGColor m_BackColor;
	UGbyte m_btBackColorTolerance;
	UGchar m_btBrightness;
	UGchar m_btContrast;
	UGColorTable m_ColorsetTable;
	UGColorDictTable m_clrDictTable;
	UGint m_nGridNoData;

	//! \brief ʵ��դ��Χר��ͼ�Ƿ�ɼ����ܣ��ڲ�ʹ�ã������⿪��
	UGArray<UGbool>* m_pVisibles;		//Visibles

	UGColorTable* GetColorsetTable();
	UGColorDictTable* GetColorDictTable();
	//! \brief �ض�ֵ��͸������,����ͼ����ָ����͸��ɫ
	UGbool m_bSpecialValueTransparent;
	//! \brief ��Ҫ͸�����ض�ֵ,���Ƿ���Ҫ���m_nGridNoData.��ʱȥ����
	//UGdouble m_dSpecialValue;

public:
	//! \brief ���������Ҫ�����ڸ��϶���
	UGStyle m_styleHignlight;
	//! \brief �Ƿ�������ƶ�����Ҫ�����ڸ��϶���
	UGbool m_bHignlight;

	UGbool m_bPan2;
	clock_t m_panBeginTime;
	UGbool m_bViewGlobal;

	//added by xielin 2008-6-13 UGGeoMap��Ҫ�õ���Ӧ��UGWorkspace�����ﱣ��һ����
	void* m_pWorkspace;

	//added by xielin 2008-8-7 ����һ���������洢�Ƿ񱳾�͸��������ֵ͸����
	//��ǰ��������ֵ���Ϊ-1������ģ�������linux�ϣ�Ĭ�ϰ�ɫ����-1�����½�������޸�֮
	UGbool m_bRasterBackTransparent;

	//! \brief �ನ����ʾ����
	UGArray<UGint> m_arrMultiBandVisible;
	//! \brief �ನ����ʾ��ɫ�ռ�ģʽ
	ImgColorSpace m_nImgCS;

	//! \brief �ನ���������
	UGRasterStretchOption m_RasterStretch;
	
	public:
		UGbool IsImagePaintTiled();
		void SetImagePaintTiled(UGbool bTiled = true);

	private:
		// �����Ƿ�ֿ���ʾӰ��
		UGbool m_bImagePaintTiled;

		// ͳ��ֵ
		UGArray<UGdouble>			m_arrMaxVal;
		UGArray<UGdouble>			m_arrMinVal;
		UGArray<UGdouble>			m_arrMeanVal;
		UGArray<UGdouble>			m_arrStandardDVal;
		UGArray<UGdouble>			m_arrNoValue;
		UGArray<UGHistogram>	m_arrHistogram;

		// ��ʶ�Ƿ���Ӱ�����ݼ�����
		UGbool	m_bDatasetRasterCollection;

		// �ֿ���ʾ
		UGbool PaintViewImage_Tile(const UGRect2D& rcDraw, const UGRect& rcBMP, UGProgress* pProgress);

		UGbool PaintViewGrid_Tile(UGDatasetRaster* pDatasetRaster, const UGRect2D& rcDraw, const UGRect& rcImg, UGProgress* pProgress);
		UGbool PaintViewMBImage_Tile(UGDatasetRaster* pDatasetRaster, const UGRect2D& rcDraw, const UGRect& rcImg, UGProgress* pProgress);
		UGbool PaintViewSBImage_Tile(UGDatasetRaster* pDatasetRaster, const UGRect2D& rcDraw, const UGRect& rcImg, UGProgress* pProgress);
};

}

#endif // !defined(AFX_UGDRAWING_H__AAC47E2E_B5B6_476C_9462_FBF34F02DFF5__INCLUDED_)

