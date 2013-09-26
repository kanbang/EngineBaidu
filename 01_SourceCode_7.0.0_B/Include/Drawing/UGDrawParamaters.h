// UGDrawParamaters.h: interface for the UGDrawParamaters class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDrawParamaters.h
   **************************************************************************************
    \author   ���������¹���
    \brief    ��ʾ������                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGDRAWPARAMATERS_H__8A1C2D67_F27C_4242_A968_AAB8D94D4E42__INCLUDED_)
#define AFX_UGDRAWPARAMATERS_H__8A1C2D67_F27C_4242_A968_AAB8D94D4E42__INCLUDED_

#include "Graphics/UGGraphics.h"
#include "Stream/ugdefs.h"
#include "Projection/UGRefTranslator.h"

#include "Toolkit/UGStyle.h"
#include "Drawing/UGMapOverlapDisplayedOptions.h"

#define DEFAULT_COORD_RATIO 1000.0

namespace UGC {

class UGMarkerSymbol;
class UGLineSymbol;
class UGFillSymbol;
class UGMarkerSymParam;
class UGLineSymParam;
class UGFillSymParam;

class DRAWING_API UGDrawParamaters  
{
public:
	//! \brief ��ͼ��ɫģʽ
	enum UGMapColorMode
	{
		//! \brief Ĭ�ϲ�ɫģʽ
		cmDefault			= 0,
		//! \brief �ڰ�ģʽ
		cmBlackWhite		= 1,
		//! \brief �Ҷ�ģʽ
		cmGray				= 2,
		//! \brief �ڰ׷�ɫģʽ
		cmBlackWhiteReverse = 3,
		//! \brief ���ڰ׷�ɫģʽ
		cmOnlyBlackWhiteReverse = 4
	};

	//! \brief �û��������Ͷ���,��������CSmMap��ʹ��
	enum UGMapUserAction
	{
		//! \brief ʲôҲ����
		uaNull				=0,
		//! \brief ��ͼƽ��
		uaPan				=1,
		//! \brief �Ŵ�
		uaZoomIn			=2,
		//! \brief ��С
		uaZoomOut			=3,
		//! \brief ��������
		uaZoomFree			=4,
		//! \brief ��ѡ �������ס���ͳ�Ϊ��ѡ
		uaPointModeSelect	=5,
		//! \brief ����ѡ��ʽ
		uaPointModeSelectTrue = 5 + 1000,
		//! \brief ����ѡ��
		uaRectModeSelect	=6,
		//! \brief Բѡ��
		uaCircleModeSelect	=7,
		//! \brief �����ѡ��
		uaRegionModeSelect	=8,
		//! \brief �߿�ѡ��
		uaLineModeSelect	=9,

		//! \brief �༭(for������)
		uaEdit				=21,
		//! \brief 
		uaTrack				=22,
		//! \brief GeoMap�༭
		uaGeoMapEdit		=23,

		// ========================================
		// ��λ��ע�⣬21-99֮���UGMapUserActionֵ�Ѿ������
		// uaEdit��uaTrack����Action���벻Ҫ���Լ���ģ����ʹ����Щֵ
		// ========================================

		// ����UserAction���ڲ��ԣ�����ʹ��
		//! \brief �����ע
		uaMiliSymbol		=100,
		//! \brief ����λͼ����ֱ�ӻ���������Сͼ��Ч����
		uaPan2				=101,
		//! \brief ����λͼ����ֱ�ӻ���������Сͼ��Ч����
		uaZoomFree2			=102,
		//! \brief �ƶ���ǩר��ͼ��ͼ��
		uaMoveThemeLabel    =105,
		//! \brief �ƶ�ͳ��ר��ͼ��ͼ��
		uaMoveThemeGraph    =106,
		//! \brief �ƶ��ȼ�����ר��ͼ��ͼ��
		uaMoveThemeGraduatedSymbol =107,


	};// �û�������UGMapUserAction���Ͷ��壬���ʷ�ʽΪUGDrawParamaters::ua???��

	enum UGShowOption
	{
		//! \brief �Ƿ������ص��ı�
		UG_SO_ALLOW_TEXTOVERLAP			= 0x00000001,
		//! \brief �Ƿ���ʾ�����߾��
		UG_SO_LINE_SMOOTHING_MODE		= 0x00000002,
		//! \brief �Ƿ������ʾ�̶��Ƕ�
		UG_SO_MARKER_FIXEDANGLE			= 0x00000004,
		//! \brief �Ƿ����ö�̬ͶӰ
		UG_SO_PROJECTION_ONTHEFLY		= 0x00000008,
		//! \brief �Ƿ��ı��̶�����
		UG_SO_TEXT_FIXEDORIENTATION		= 0x00000010,
		//! \brief �Ƿ��ı��̶��Ƕ�
		UG_SO_TEXT_FIXEDANGLE			= 0x00000020,
		//! \brief �Ƿ����æ
		UG_SO_ACTION_BUSY				= 0x00000040,
		//! \brief �Ƿ��ܹ�ʹ��æ����
		UG_SO_ENABLE_BUSY				= 0x00000080,
		//! \brief ����ȡ��
		UG_SO_ACTION_CANCEL				= 0x00000100,
		//! \brief �Ƿ����ڴ�ӡ
		UG_SO_IS_PRINTING				= 0x00000200,
		//! \brief �Ƿ����TIN
		UG_SO_FILL_TIN					= 0x00000400,
		//! \brief �Ƿ�������ͼ��ʾ��Χ
		UG_SO_BOUNDS_LOCK				= 0x00000800,
		//! \brief �Ƿ�ȡ��Geometry��ʾ
		UG_SO_GEOMETRY_CANCEL			= 0x00001000,
		//! \brief �Ƿ��͵�ͼ�¼�
		UG_SO_MAP_EVENT					= 0x00002000,
		//! \brief �Ƿ���ʾ�����ı����
		UG_SO_TEXT_SMOOTHING_MODE		= 0x00004000,
		
	};
	//! \brief �����Ͳ����⿪��
	enum UGDrawLayerType
	{
		//! \brief ��������ͼ��
		UG_DRAWLAYER_ALL = 0,
		//! \brief �����Ʊ�ǩͼ��
		UG_DRAWLAYER_NOLABEL = 1,
		//! \brief ���Ʊ�ǩͼ��
		UG_DRAWLAYER_LABEL = 2
	};
	
public:
	//! \brief ���캯��
	UGDrawParamaters();
	//! \brief ��������
#ifdef SYMBIAN60
	~UGDrawParamaters();
#else
	virtual ~UGDrawParamaters();
#endif
	
	//! \brief =������
	//! \param drawParam Ҫ��ȡ�Ķ���
	void operator=(const UGDrawParamaters& drawParam);

public:
	//! \brief ������ 
	static UGdouble ScaleToCoordRatio(const UGPrjCoordSys& PJCoordSys, double dScale);

	static UGdouble CoordRatioToScale(const UGPrjCoordSys& PJCoordSys, double dCoordRatio);
	//! \brief ת����ɫ
	//! \param color Ҫת������ɫ
	//! \param nMapColorMode ��ɫģʽ
	static void ConvertColorByColorMode(UGColor &color, UGint nMapColorMode);
    //! \brief ת�����ζ��������ɫ
	//! \param style Ҫת���ļ��ζ���
	//! \remarks ��������ɫ��ǰ��ɫ������ɫ
	//! \param nMapColorMode ��ɫģʽ
	static void ConvertStyleByColorMode(UGStyle &style, UGint nMapColorMode);
	 //! \brief ת���ı����������ɫ
	//! \param style Ҫת�����ı�����
	//! \remarks ��������ɫ��ǰ��ɫ
	//! \param nMapColorMode ��ɫģʽ
	static void ConvertTextStyleByColorMode(UGTextStyle &textStyle, UGint nMapColorMode);
	//! \brief ���õ�ǰ��ʾ����
	void Reset();
	//! \brief ��õ�ͼӳ��ģʽ
	//! \return  ��ͼ��ӳ��ģʽ
	UGint GetMapMode() const;
	//! \brief ���õ�ͼӳ��ģʽ
	//! \param nMapMode ��ͼ��ӳ��ģʽ
	void SetMapMode(UGint nMapMode);
    //! \brief ���õ�ͼӳ��ģʽ�ʹ��ڵ�ԭ������
	//! \param pGraphics ������Graphics����
	//! \return  ԭʼ�ĵ�ͼ��ӳ��ģʽ
	UGint SetGeoMapModeX(UGGraphics *pGraphics);
	//! \brief �ָ����� 
	void Restore();
	//! \brief �������
	void Preserve();
	//! \brief �ж�����ת�������Ƿ���Ч
	//! \return �Ƿ���Ч
	UGbool IsValid();
	//! \brief �жϵ�ǰ���Ƿ�ɼ�
	//! \return �Ƿ�ɼ�
	UGbool IsVisible(const UGPoint2D& point);
	//! \brief �жϵ�ǰ���Ƿ�ɼ�
	//! \return �Ƿ�ɼ�
	UGbool IsVisible(const UGRect2D& rcBounds);
	//! \brief 0.01 mm to �߼�����
	//! \param nSize Ҫת��������
	//! \return �߼�����
	UGint HIMETRICtoLP(const UGint nSize);
     //! \brief 0.01 mm to ��ͼ����
	//! \param nSize Ҫת��������
	//! \return ��ͼ����
	UGdouble HIMETRICtoMP(const UGint nSize);
	//! \brief �߼����� to 0.01 mm  
	//! \param nSize Ҫת��������
	//! \return 0.01mm ����
	UGint LPtoHIMETRIC(const UGint nSize);
	//! \brief ��ͼ���� to 0.01 mm  
	//! \param nSize Ҫת��������
	//! \return 0.01mm ����
	UGint MPtoHIMETRIC(const UGdouble dSize);
	//! \brief ��ͼ����ת�����߼�����
	//! \param dSize Ҫת��������
	//! \return �߼�����
	UGint MPtoLP(const UGdouble dSize);
    //! \brief ��ͼ����ת�����߼�����
	//! \param szSource Ҫת��������
	//! \param szTarget ת���������
	void MPtoLP(const UGSize2D& szSource, UGSize& szTarget);
    //! \brief ��ͼ����ת�����߼�����
	//! \param szSource Ҫת��������
	//! \param szTarget ת���������
	void MPtoLP(const UGPoint2D& pntSource, UGPoint& pntTarget);
	//! \brief ��ͼ����ת�����߼�����(�߾���ģʽ)
	//! \param szSource Ҫת��������
	//! \param szTarget ת���������
	void MPtoLP(const UGPoint2D& pntSource, UGPoint2D& pntTarget);
	 //! \brief ��ͼ����ת�����߼�����
	//! \param szSource Ҫת��������ľ���
	//! \param szTarget ת���������ľ���
	void MPtoLP(const UGRect2D& rcSource, UGRect& rcTarget);
	//! \brief ��ͼ����ת�����߼�����
	//! \param pPoints ��Ҫת���ĵ㴮
	//! \param nCount �㴮�ĸ���
	//! \return ת���Ƿ�ɹ�
	UGbool MPtoLPBatch(const UGPoint2D* pPoints, UGint nCount);	

	//! \brief ��ͼ����ת�����豸����
	//! \param pPoints ��Ҫת���ĵ㴮
	//! \param nCount �㴮�ĸ���
	//! \return ת���Ƿ�ɹ�
	UGbool MPtoDPBatch(const UGPoint2D* pPoints, UGint nCount);	
	//! \brief ��ͼ����ת�����߼�����
	//! \param pPoints �㴮��ָ��
	//! \param nCount �㴮�ļ��ζ���ĸ���
	//! \param arrPolycounts ÿ�����ζ���ĵ�ĸ���
	//! \return ת���Ƿ�ɹ�
	UGbool MPtoLPBatchPredigest(const UGPoint2D* pPoints, UGint nCount, UGArray<UGuint>& arrPolycounts);
	//! \brief �߼�����ת������ͼ����
	//! \param nSize ��Ҫת��������
	//! \return ת���������
	UGdouble LPtoMP(const UGint nSize);
    //! \brief �߼�����ת������ͼ����
	//! \param nSize ��Ҫת��������
	//! \return ת���������
	void LPtoMP(const UGSize& szSource, UGSize2D& szTarget);
   //! \brief �߼�����ת������ͼ����
	//! \param pntSource ��Ҫת��������
	//! \param pntTarget ת���������
	void LPtoMP(const UGPoint& pntSource, UGPoint2D& pntTarget);
    //! \brief �߼�����ת������ͼ����
	//! \param rcSource ��Ҫת��������ľ���
	//! \param rcTarget ת���������ľ���
	void LPtoMP(const UGRect& rcSource, UGRect2D& rcTarget);
	//! \brief  ȫ����ʾ
	//! \param rcLogical Ĭ���߼���Χ
	//! \param nMarginWidthViewEntire �߽緶Χ
	//! \return ��ʾ�Ƿ�ɹ�
	UGbool ViewEntire(UGRect rcLogical = UGRect(0,0,0,0), UGint nMarginWidthViewEntire = 0);
	//! \brief �趨��ͼ�µķ�Χ
	//! \param dNewScale �µķ�Χ������ת������
	//! \param rcLogicalBounds �߼���Χ
	//! \param pntCenter ��ͼ����
	// ���š�ƽ����غ���
	void SetMapScale(UGdouble dNewScale, const UGRect& rcLogicalBounds, const UGPoint2D& pntCenter);

	//! \brief �ı��߼���Χ��Draw��Χ��С����ֻ��ı����Χ�Ĵ�С�������ı����ĵ㡣
	//! \param rcLogicalBounds Ҫ�ı�Ĵ�С
	void ChangeLogicalBounds(const UGRect& rcLogicalBounds);	
	//! \brief ���õ�ͼ����
	//! \param pntNewCenter ��ͼ����
	void SetCenter(const UGPoint2D& pntNewCenter);		
	//! \brief ���÷�����С����
	//! \param dZoomRatio ����1�ǷŴ�,<1ʱ��С
	void Zoom(UGdouble dZoomRatio);
	//! \brief ���÷�����С����
	//! \param dZoomRatio ����1�ǷŴ�,<1ʱ��С
	void ZoomEx(UGdouble dZoomRatio);
	//! \brief �Ŵ��ƶ��ľ���
	//! \param rcUserRect �ƶ��ľ�������
	void RectZoomOut(const UGRect& rcUserRect);		
	//! \brief ��С�ƶ��ľ���
	//! \param rcUserRect �ƶ��ľ�������
	void RectZoomIn(const UGRect& rcUserRect);		
	//! \brief ƽ�Ƶ�ͼ
	//! \param dOffsetX X�����ϵ�����
	//! \param dOffsetY Y�����ϵ�����
	void Pan(UGdouble dOffsetX, UGdouble dOffsetY);					//Ϊ�˵�ͼ��תƽ��
	//! \brief ʹ��Ĭ�ϵĵ�ͼ��ʾ��Χ
	//void MakeDefault();
	//! \brief ��õ�ͼ����ɫģʽ
	//! \return ��ͼ����ɫģʽ
	UGint GetMapColorMode() const;
	//! \brief ���õ�ͼ����ɫģʽ
	//! \param nMapColorMode ��ͼ����ɫģʽ
	void SetMapColorMode(UGint nMapColorMode);
	//! \brief ����û�����Ϊ
	//! \return �û�����Ϊ
	UGint GetUserAction() const;
	//! \brief �����û�����Ϊ
	//! \param nUserAction ���û�����Ϊ
	void SetUserAction(UGint nUserAction);	
	//! \brief ����Ѿ�������û���Ϊ
	//! \return �Ѿ�������û���Ϊ
	UGint GetUserActionSaved() const;
	//! \brief �����Ѿ�������û���Ϊ
	//! \param nUserActionSaved �Ѿ�������û���Ϊ
	void SetUserActionSaved(UGint nUserActionSaved);	
	//! \brief ���Geometry����㻺��ĳ���
	//! \return Geometry����㻺��ĳ���
	UGint GetPointCount() const;
	//! \brief ׼��Geometry����㻺��(�߾���ģʽ���������)
	UGbool PreparePointsBuf(UGint nPointCount);	
	//! \brief ���Geometry����㻺��
	//! \return ָ��Geometry����㻺���ָ��
	UGPoint* GetPointsBuffer() const;
	//! \brief ��õ�ͼ��ƫ����
	//! \return ��ͼ��ƫ����
	UGPoint GetOffset() const;
	//! \brief ���õ�ͼ��ƫ����
	//! \param nMapColorMode ��ͼ��ƫ����
	void SetOffset(const UGPoint& pntOffset);	
	//! \brief ��ô��ڵ�ԭ������
	//! \return ���ڵ�ԭ������
	UGPoint GetWindowOrg() const;
	//! \brief ���õ�ͼ�Ĵ��ڵ�ԭ������
	//! \param pntWindowOrg ��ͼ�Ĵ��ڵ�ԭ������
	void SetWindowOrg(const UGPoint& pntWindowOrg);	
	//! \brief ��õ�ͼ�ķ�Χ
	//! \return ��ͼ�ķ�Χ
	UGRect2D GetMapBounds() const;
	//! \brief ���õ�ͼ�ķ�Χ
	//! \param nMapColorMode ��ͼ�ķ�Χ
	void SetMapBounds(const UGRect2D& rcMapBounds);	
	//! \brief ��õ�ͼ����Ч��Χ
	//! \return ��ͼ����Ч��Χ
	UGRect2D GetInvalidBounds() const;
	//! \brief ���õ�ͼ����Ч��Χ
	//! \param rcInvalidBounds ��ͼ����Ч��Χ
	void SetInvalidBounds(const UGRect2D& rcInvalidBounds);	
	//! \brief ��õ�ͼ���߼���Χ
	//! \return ��ͼ���߼���Χ
	UGRect GetLogicalBounds() const;
	//! \brief ���õ�ͼ���߼���Χ
	//! \param rcLogicalBounds ��ͼ���߼���Χ
	void SetLogicalBounds(const UGRect& rcLogicalBounds);	
	//! \brief ��õ�ͼ����ʾ��Χ
	//! \return ��ͼ����ʾ��Χ
	UGRect2D GetMapDrawBounds() const;
	//! \brief ���õ�ͼ����ʾ��Χ
	//! \param rcMapDrawBounds ��ͼ����ʾ��Χ
	void SetMapDrawBounds(const UGRect2D& rcMapDrawBounds,UGbool bByWidth = false);	
	//! \brief ��õ�ͼ��������ʾ��Χ
	//! \return ��ͼ��������ʾ��Χ
	UGRect2D GetLockedDrawBounds() const;
	//! \brief ���õ�ͼ��������ʾ��Χ
	//! \param rcLockedDrawBounds ��ͼ��������ʾ��Χ
	void SetLockedDrawBounds(const UGRect2D& rcLockedDrawBounds);	
	//! \brief ��õ�ͼ�ķ�Χ
	//! \return ��ͼ�ķ�Χ
	UGdouble GetScale() const;
	//! \brief ���õ�ͼ�ķ�Χ
	//! \param dScale ��ͼ�ķ�Χ
	//! \return �����Ƿ�ɹ� modified by zhengyl at 2011-9-2
	UGbool SetScale(UGdouble dScale);	
	//! \brief ��õ�ͼ�� ����ת������(�߼�����/��������)
	//! \return ��ͼ�� ����ת������(�߼�����/��������)
	UGdouble GetCoordRatio() const;
	//! \brief ���õ�ͼ�� ����ת������(�߼�����/��������)
	//! \param dCoordRatio  ����ת������(�߼�����/��������)
	void SetCoordRatio(UGdouble dCoordRatio);	
	//! \brief ��÷������ű���ϵ��
	//! \return ��ͼ�ķ������ű���ϵ��
	UGdouble GetSymScale() const;
	//! \brief ���õ�ͼ�ķ������ű���ϵ��
	//! \param dSymScale ��ͼ�ķ������ű���ϵ��
	//! \param dSymScaleX ��ͼ�ķ���X��������ű���ϵ��
	void SetSymScale(UGdouble dSymScale,UGdouble dSymScaleX = 0);	
	//! \brief ��ȡ����X�����ϵı���ϵ�� ��õ�ͼ�ķ���X��������ű���ϵ��
	//! \return ��ͼ�ķ���X��������ű���ϵ��
	UGdouble GetSymScaleX() const{return m_dSymScaleX;};

	UGdouble GetDPIScale() const;
	
	void SetDPIScale(UGdouble dDPIScale);

	//! \brief Ŀǰ���ڻ�ȡLayout��GeoMap�����ű���(�����жϵ�ͼ��ͼ���Ƿ��ڿɼ�������֮��)
	UGdouble GetScaleRatio() const;
	//! \brief Ŀǰ��������Layout��GeoMap�����ű���(�����жϵ�ͼ��ͼ���Ƿ��ڿɼ�������֮��)
	void SetScaleRatio(UGdouble dScaleRatio);
	//! \brief ��õ�ͼ����ת�Ƕ�
	//! \return ��ͼ����ת�Ƕ�
	UGdouble GetAngle() const;
	//! \brief ���õ�ͼ����ת�Ƕ�
	//! \param dAngle ��ͼ����ת�Ƕ�
	void SetAngle(UGdouble dAngle);	
	//! \brief ��õ�ͼ����С��ʾ��Χ
	//! \return ��ͼ����С��ʾ��Χ
	UGdouble GetMinScale() const;
	//! \brief ���õ�ͼ�������ʾ��Χ
	//! \param dMinScale ��ͼ�������ʾ��Χ
	void SetMinScale(UGdouble dMinScale);	
	//! \brief ��õ�ͼ�������ʾ��Χ
	//! \return ��ͼ�������ʾ��Χ
	UGdouble GetMaxScale() const;
	//! \brief ���õ�ͼ�������ʾ��Χ
	//! \param dMaxScale ��ͼ�������ʾ��Χ
	void SetMaxScale(UGdouble dMaxScale);
	//! \brief ��õ�ͼ�ı���ģʽ
	//! \return ��ͼ�ı���ģʽ
	const UGStyle& GetBackgroundStyle() const;
	//! \brief ���õ�ͼ�ı���ģʽ
	//! \param style ��ͼ�ı���ģʽ
	void SetBackgroundStyle(const UGStyle& style);
	//! \brief ��õ�ͼ���ַ���
	//! \return ��ͼ���ַ���
	UGString::Charset GetCurCharset() const;
	//! \brief ���õ�ͼ���ַ���
	//! \param nCurCharset ��ͼ���ַ���
	void SetCurCharset(UGString::Charset nCurCharset);
	//! \brief ��õ�ͼ�ļ���ͼ����ʽ
	//! \return ��ͼ�ļ���ͼ����ʽ
	UGStyle* GetGeometryStyle() const;
	//! \brief ���õ�ͼ�ļ���ͼ����ʽ
	//! \param pStyle ��ͼ�ļ���ͼ����ʽ
	void SetGeometryStyle(UGStyle* pStyle);
	//! \brief ��õ�ͼ���ı���ʽ
	//! \return ��ͼ���ı���ʽ
	UGTextStyle* GetTextStyle() const;
	//! \brief ���õ�ͼ���ı���ʽ
	//! \param pStyle ��ͼ���ı���ʽ
	void SetTextStyle(UGTextStyle* pStyle);
	//! \brief ��õ�ͼ�Ļ���
	//! \return ��ͼ�Ļ���
	UGPen* GetPen() const;
	//! \brief ���õ�ͼ�Ļ���
	//! \param pPen ��ͼ�Ļ���
	void SetPen(UGPen* pPen);
	//! \brief ��õ�ͼ�Ļ�ˢ
	//! \return ��ͼ�Ļ�ˢ
	UGBrush* GetBrush() const;
	//! \brief ���õ�ͼ�Ļ�ˢ
	//! \param pBrush ��ͼ�Ļ�ˢ
	void SetBrush(UGBrush* pBrush);
	//! \brief ��õ�ͼ������
	//! \return ��ͼ������
	UGFont* GetFont() const;
	//! \brief ���õ�ͼ������
	//! \param pFont ��ͼ������
	void SetFont(UGFont* pFont);
	//! \brief ��õ�ͼ�ĵ����
	//! \return ��ͼ�ĵ����
	UGMarkerSymbol* GetMarkerSymbol() const;
	//! \brief ���õ�ͼ�ĵ����
	//! \param pMarkerSym ��ͼ�ĵ����
	void SetMarkerSymbol(UGMarkerSymbol* pMarkerSym);
	//! \brief ��õ�ͼ��������
	//! \return ��ͼ��������
	UGFillSymbol* GetFillSymbol() const;
	//! \brief ���õ�ͼ��������
	//! \param pFillSym ��ͼ��������
	void SetFillSymbol(UGFillSymbol* pFillSym);
	//! \brief ��õ�ͼ�����η���
	//! \return ��ͼ�����η���	
	UGLineSymbol* GetLineSymbol() const;
	//! \brief ���õ�ͼ�����η���
	//! \param pLineSym ��ͼ�����η���
	void SetLineSymbol(UGLineSymbol* pLineSym);
	//! \brief ��õ�ͼ�ĵ���Ų���
	//! \return ��ͼ�ĵ���Ų���
	UGMarkerSymParam* GetMarkerSymParam() const;
	//! \brief ���õ�ͼ�ĵ���Ų���
	//! \param pMarkerSymParam ��ͼ�ĵ���Ų���
	void SetMarkerSymParam(UGMarkerSymParam* pMarkerSymParam);
	//! \brief ��õ�ͼ�������Ų���
	//! \return ��ͼ�������Ų���
	UGFillSymParam* GetFillSymParam() const;
	//! \brief ���õ�ͼ�������Ų���
	//! \param pFillSymParam ��ͼ�������Ų���
	void SetFillSymParam(UGFillSymParam* pFillSymParam);
	//! \brief ��õ�ͼ�����η��Ų���
	//! \return ��ͼ�����η��Ų���
	UGLineSymParam* GetLineSymParam() const;
	//! \brief ���õ�ͼ�����η��Ų���
	//! \param pLineSymParam ��ͼ�����η��Ų���
	void SetLineSymParam(UGLineSymParam* pLineSymParam);
	//! \brief ��õ�ͼ����С�ɼ��ı���
	//! \return ��ͼ����С�ɼ��ı���
	UGdouble GetMinVisibleTextSize() const;
	//! \brief ���õ�ͼ����С�ɼ��ı���
	//! \param dMinVisibleTextSize ��ͼ����С�ɼ��ı���
	void SetMinVisibleTextSize(UGdouble dMinVisibleTextSize);
	//! \brief ��õ�ͼ�����ɼ��ı���
	//! \return ��ͼ�����ɼ��ı���
	UGdouble GetMaxVisibleTextSize() const;
	//! \brief ���õ�ͼ�����ɼ��ı���
	//! \param dMaxVisibleTextSize ��ͼ�����ɼ��ı���
	void SetMaxVisibleTextSize(UGdouble dMaxVisibleTextSize);
	//! \brief ��õ�ͼ�Ķ�̬ͶӰת��
	//! \return ��ͼ�Ķ�̬ͶӰת��
	UGRefTranslator* GetRefTranslator();
	//! \brief ��õ�ͼ�Ķ�̬ͶӰת��
	//! \return ��ͼ�Ķ�̬ͶӰת��
	UGRefTranslator* GetRefTranslator() const;
	//! \brief �ж��Ƿ������ı�ѹ��
	//! \return �ı��Ƿ�����ѹ��
	UGbool IsAllowTextOverlap() const;
	//! \brief �����ı� �Ƿ������ı�ѹ��
	//! \param bFlag �Ƿ������ı�ѹ��
	void SetAllowTextOverlap(UGbool bFlag);
	//��ȡѹ�ǹ���ѡ��
	UGMapOverlapDisplayedOptions& GetOverlapDisplayedOptions();
	//��ȡѹ�ǹ���ѡ��
	const UGMapOverlapDisplayedOptions& GetOverlapDisplayedOptions() const;
	//����ѹ�ǹ���ѡ��
	void SetOverlapDisplayedOptions(const UGMapOverlapDisplayedOptions& options);
	//! \brief �ж������Ƿ�⻬ģʽ
	//! \return �����Ƿ�⻬ģʽ
	//���ߺ��ı����ֿ�����SFC����һ��
	UGbool IsLineSmoothingMode() const;
	//! \brief ���������Ƿ�⻬ģʽ
	//! \param bFlag �����Ƿ�⻬ģʽ
	void SetLineSmoothingMode(UGbool bFlag);
	//! \brief �ж��ı��Ƿ�⻬ģʽ
	//! \return �ı��Ƿ�⻬ģʽ
	UGbool IsTextSmoothingMode() const;
	//! \brief �����ı��Ƿ�⻬ģʽ
	//! \param bFlag �ı��Ƿ�⻬ģʽ
	void SetTextSmoothingMode(UGbool bFlag);
	//UGbool IsSmoothingMode() const;
	//void SetSmoothingMode(UGbool bFlag);
	//! \brief �жϵ�����Ƿ������Ƕ�
	//! \return ������Ƿ������Ƕ�
	UGbool IsMarkerFixedAngle() const;
	//! \brief ���õ�����Ƿ������Ƕ�
	//! \param bFlag ������Ƿ������Ƕ�
	void SetMarkerFixedAngle(UGbool bFlag);
	//! \brief �ж��Ƿ����ö�̬ͶӰ
	//! \return �Ƿ����ö�̬ͶӰ
	UGbool IsProjectionOnTheFly() const;
	//! \brief ���õ�ͼ�Ƿ����ö�̬ͶӰ
	//! \param bFlag ��ͼ�Ƿ����ö�̬ͶӰ
	void SetProjectionOnTheFly(UGbool bFlag);
	//! \brief �ж��Ƿ��ı��̶�����
	//! \return �Ƿ��ı��̶�����
	UGbool IsTextFixedOrientation() const;
	//! \brief ���õ�ͼ�Ƿ��ı��̶�����
	//! \param bFlag ��ͼ�Ƿ��ı��̶�����
	void SetTextFixedOrientation(UGbool bFlag);
	//! \brief �ж��Ƿ��ı��̶��Ƕ�
	//! \return �Ƿ��ı��̶��Ƕ�
	UGbool IsTextFixedAngle() const;
	//! \brief ���õ�ͼ�Ƿ��ı��̶��Ƕ�
	//! \param bFlag ��ͼ�Ƿ��ı��̶��Ƕ�
	void SetTextFixedAngle(UGbool bFlag);
	//! \brief �ж��Ƿ����ȡ��
	//! \return �Ƿ����ȡ��
	UGbool IsCancel() const;
	//! \brief ���õ�ͼ�Ĳ���ȡ��
	//! \param bFlag ��ͼ�Ĳ���ȡ��
	void SetCancel(UGbool bFlag);
	
	//! \brief ���õ�ͼ�Ƿ��������ΪImage���ݼ�
	//! \param bFlag ��ͼ�Ƿ����ΪImage���ݼ�
	void SetOutputImage(UGbool bFlag);
	//! \brief ��ȡ��ͼ�Ƿ��������ΪImage���ݼ�
	UGbool  IsOutputImage();

	//! \brief �����Ƿ񳬳���ͼ��ΧҲ��������
	//! \param bFlag �Ƿ񳬳���ͼ��ΧҲ��������
	void SetDrawOutsideMapBounds(UGbool bFlag);
	//! \brief ��ȡ�Ƿ񳬳���ͼ��ΧҲ��������
	UGbool IsDrawOutsideMapBounds();

	//! \brief �ж��Ƿ����æ
	//! \return �Ƿ����æ
	UGbool IsBusy() const;
	//! \brief ���õ�ͼ�Ĳ���æ
	//! \param bFlag ��ͼ�Ĳ���æ
	void SetBusy(UGbool bFlag);
	//! \brief �ж��Ƿ��ܹ�ʹ��æ����
	//! \return �Ƿ��ܹ�ʹ��æ����
	UGbool IsBusyEnable()const;	
	//! \brief ���õ�ͼ�Ƿ��ܹ�ʹ��æ����
	//! \param bFlag ��ͼ�Ƿ��ܹ�ʹ��æ����
	void SetBusyEnable(UGbool bFlag);
	//! \brief �ж��Ƿ�ȡ��Geometry��ʾ
	//! \return �Ƿ�ȡ��Geometry��ʾ
	UGbool IsGeometryCancel() const;
	//! \brief ���õ�ͼ�Ƿ�ȡ��Geometry��ʾ
	//! \param bFlag ��ͼ�Ƿ�ȡ��Geometry��ʾ
	void SetGeometryCancel(UGbool bFlag);
	//! \brief �ж��Ƿ����ڴ�ӡ
	//! \return �Ƿ����ڴ�ӡ
	UGbool IsPrinting() const;
	//! \brief ���õ�ͼ�Ƿ����ڴ�ӡ
	//! \param bFlag ��ͼ�Ƿ����ڴ�ӡ
	void SetPrinting(UGbool bFlag);
	//! \brief �ж��Ƿ����TIN
	//! \return �Ƿ����TIN
	UGbool IsFillTIN() const;
	//! \brief ���õ�ͼ�Ƿ����TIN
	//! \param bFlag ��ͼ�Ƿ����TIN
	void SetFillTIN(UGbool bFlag);
	//! \brief �ж��Ƿ�������ͼ��ʾ��Χ
	//! \return �Ƿ�������ͼ��ʾ��Χ
	UGbool IsDrawBoundsLocked() const;
	//! \brief �����Ƿ�������ͼ��ʾ��Χ
	//! \param bFlag ��ͼ�Ƿ�������ͼ��ʾ��Χ
	void SetDrawBoundsLocked(UGbool bFlag);
	//! \brief �ж��Ƿ��͵�ͼ�¼�
	//! \return �Ƿ��͵�ͼ�¼�
	UGbool IsSendMapEvent() const;
	//! \brief �����Ƿ��͵�ͼ�¼�
	//! \param nMapColorMode ��ͼ�Ƿ��͵�ͼ�¼�
	void SetSendMapEvent(UGbool bFlag);
	//! \brief ������ɼ�����
	//! \return ���ɼ�����
	UGint GetMaxVisibleVertex() const;
	//! \brief ���õ�ͼ����ɫģʽ
	//! \param nMapColorMode ��ͼ����ɫģʽ
	void SetMaxVisibleVertex(UGint nMaxVisibleVertex);
	//! \brief �����ʾͼ��ѡ��
	//! \return ��ʾͼ��ѡ��
	UGint GetDrawLayerType() const;
	//! \brief ���õ�ͼ��ʾͼ��ѡ��
	//! \param nDrawLayerType ��ͼ��ʾͼ��ѡ��
	void SetDrawLayerType(UGint nDrawLayerType);
	//! \brief ��õ�ǰ��ʾͼ������  ��ǰ��ʾͼ�������Լ���ͼ������Ϊ�˼�����ʾ�ٷֱ�
	//! \return ��ǰ��ʾͼ������
	UGint GetDrawLayerIndex() const;
	//! \brief ���õ�ͼ��ǰ��ʾͼ������
	//! \param nDrawLayerIndex ��ͼ��ǰ��ʾͼ������
	void SetDrawLayerIndex(UGint nDrawLayerIndex);
	//! \brief ��õ�ǰ��ʾ��ͼ����
	//! \return ��ǰ��ʾ��ͼ����
	UGint GetDrawLayerCount() const;
	//! \brief ���õ�ͼ��ǰ��ʾ��ͼ����
	//! \param nMapColorMode ��ͼ��ǰ��ʾ��ͼ����
	void SetDrawLayerCount(UGint nDrawLayerCount);
	//! \brief ���ͻ���ʱ�Ƿ�������ʾ��ʵ����
	//! \return �Ƿ�������ʾ��ʵ����1�����ǣ�0�����Ĭ��Ϊ1��
	UGbool IsLineAdjust() const;
	//! \brief ���ͻ���ʱ����������ʾ��ʵ����
	//! \param bLineAdjust  �Ƿ�������ʾ��ʵ��[in]
	//! \remarks Ĭ���»������ͻ���ô˷������趨�Ƿ�������ʾ��ʵ�����ڷŴ���Сʱ����������ʾ���͡�
	void SetLineAdjust(UGbool bLineAdjust = true);
	//addby dongfei 2007-03-26
	//! \brief ���õ�ͼƽ����ʾ������¼�� 	
	//! \brief ���õ�ͼƽ����ʾ������¼��
	//! \param nRecorcCount ��ͼƽ����ʾ������¼��
	void SetSmoothingMaxRecord(UGint nRecorcCount);
	//! \brief ��ȡ��ͼƽ����ʾ������¼�� dongfei 2007-03-26
	//! \brief ��õ�ͼƽ����ʾ������¼��
	//! \return ��ͼƽ����ʾ������¼��
	UGint GetSmoothingMaxRecord()const;
	//! \brief �����Ƿ�ǿ�Ƽӵ��ı��߽�
	//! \param bForceAdd �Ƿ�ǿ�Ƽӵ��ı��߽�
	void  SetForceAddTextBounds(UGbool bForceAdd = false){m_bForceAdd = bForceAdd;};
	//! \brief �ж��Ƿ�ǿ�Ƽӵ��ı��߽�
	//! \return �Ƿ�ǿ�Ƽӵ��ı��߽�
	UGbool IsForceAddTextBounds(){return m_bForceAdd;};
	//! \brief ����ü���Χ
	void ComputeClipBounds();

	//! \brief ������ʾ��Χ
	//! \param arrDisplayScales ��Ҫ���õĵ���
	void SetDisplayScales(const UGArray<UGdouble>& arrDisplayScales);
	//! \brief �����ʾ��Χ
	//! \param arrDisplayScales ��ʾ��Χ�ĵ���
	void GetDisplayScales(UGArray<UGdouble>& arrDisplayScales);
	//! \brief �����Ƿ���ݷ�Χ��ʾ��ͼ
	//! \param bDisplayByScales �Ƿ���ݷ�Χ��ʾ��ͼ
	void SetDisplayByScales(UGbool bDisplayByScales);
	//! \brief �ж��Ƿ���ݷ�Χ��ʾ��ͼ
	//! \return ���ݷ�Χ��ʾ��ͼ
	UGbool IsDisplayByScales() const;
	//! \brief �Ƿ�Ϊ�豸ͼ����ƣ����ṩ���豸ͼ����
	UGbool IsDeviceDraw()const;
	//! \brief ����Ϊ�豸ͼ����ƣ����ṩ���豸ͼ����
	void SetDeviceDraw(UGbool bIsDeviceDraw = false);
	

	//! \brief ��ȡ�豸�����᷽��
	//! \return �����᷽��
	//! \param �����᷽��,trueΪ���ϣ�falseΪ����
	//! \attention ��
	UGbool IsOrientation()const;	
	//! \brief �����豸�����᷽��
	//! \param �����᷽��,trueΪ���ϣ�falseΪ����[in].
	void SetOrientation(UGbool bOrientation);

	//! \brief ������ǲ������ŵ�ͼ��ת��������������ת���
	UGbool GetIsFillAngle()const;
	void SetIsFillAngle(UGbool bIsFillAngle = false);
	
	//! \brief ���õ�ǰ��ͼ�Ƿ���Է������,add by tanzw,2011-1-13
	//! \param bIsSymbolFillIgnored �Ƿ���Է�����䣬Ĭ��false������
	//! \remarks ���Է������ʱ��ֻ�����������ı���ɫ�������з��ŵĻ���
	UGbool IsSymbolFillIgnored()const;
	void SetSymbolFillIgnored(UGbool bIsSymbolFillIgnored = false);

	//! \brief ��ͼˢ���ǲ����м�ȡ��������
	UGbool GetIsDrawComplete()const;
	void SetIsDrawComplete(UGbool bIsDrawComplete);

	//! \brief ��ȡ�Ƿ���Ҫ���б�����ת��ת����
	UGbool GetCoordRatioToScale() const;	
	//! \brief ���ñ�����ת����
	//! \param �Ƿ���Ҫת��
	void SetCoordRatioToScale(UGbool bCoordRatioToScale);

	//! \brief ���õ�ǰ�������ɻ��棬��ʱ����CacheBuilderʹ��
	UGbool SetIsOutputCache(UGbool bIsOutputCache = true);

	//! \brief ��õ�ǰ�Ƿ��������ɻ��棬��ʱ����CacheBuilderʹ��
	UGbool GetIsOutputCache() const;

	//! \brief �����Ƿ�������ͼ��תΪ���ݼ�����ʱΪ����Ԥ����׼��
	UGbool SetIsBanchLayersToDataset(UGbool bBanchLayersToDataset = true);

	//! \brief ��ȡ�Ƿ�������ͼ��תΪ���ݼ�����ʱΪ����Ԥ����׼��
	UGbool GetIsBanchLayersToDataset() const;

	//! \brief �����Ƿ�ʹ�÷��ŵ�Ĭ����ɫ��ʾ
	void SetIsSymbolDefaultColor(UGbool bIsSymbolDefaultColor);
	
	//! \brief ����Ƿ�ʹ�÷��ŵ�Ĭ����ɫ��ʾ
	UGbool GetIsSymbolDefaultColor() const;

	//! \brief �жϵ�ͼ���Ƿ��������ͼͼ��
	UGbool IsWebMapFlag();
	void SetWebMapFlag(UGbool bHasWebMap);

	// �Զ��������ͼDP-->LPת������
	void SetWebMapCoordRatio(UGdouble dRatioX, UGdouble dRatioY);
	void GetWebMapCoordRatio(UGdouble& dRatioX, UGdouble& dRatioY);

	//! \brief ���õ�ͼDP-->LPת������
	//! \param pGraphics ������Graphics����
	void SetWebMapModeCoordRatio(UGGraphics *pGraphics);

	//! \brief �жϵ�ǰ�Ƿ�Ҫ��ӡ���ļ���
	//! \return ���ص�ǰ�Ƿ���Դ�ӡ���ļ���
	UGbool IsPrintToFile() const;
	//! \brief �����Ƿ��ӡ���ļ�����
	//! \param UGbool �Ƿ��ӡ���ļ���
	void SetPrintToFile(UGbool bPrintToFile = TRUE);

	//! \brief �ж��Ƿ�ֻˢ�������ͼͼ��
	UGbool IsOnlyRefreshWebMapFlag();
	void SetOnlyRefreshWebMapFlag(UGbool bRefreshWebMap);

	//! \brief ����/��ȡ��ǰ��ͼ��DPI
	void SetMapDPI(UGdouble dMapDPI);
	UGdouble GetMapDPI() const;

	//! \brief ����/��ȡ�Ƿ�ʹ��ȫ��ϵͳ��DPI��Ĭ��Ϊfalse��falseʱʹ�õ�ͼ���õ�DPI
	UGbool IsUseSystemDPI();
	void SetUseSystemDPI(UGbool bUseSystemDPI);

	//! \brief ����/��ȡ�߾�������ת��ģʽ
	UGbool IsHighPrecisionMode();
	void SetHighPrecisionMode(UGbool bHighPrecision);

	//! \brief ����/��ȡ������ͼ����ģʽ(Ƕ��ʽʹ��)
	UGbool IsDrawBackMapMode();
	void SetDrawBackMapMode(UGbool bDrawBackMap);

	//! \brief �ж��Ƿ�ֻˢ�µײ�����(Ƕ��ʽʹ��)
	UGbool IsOnlyRefreshBackMapFlag();
	void SetOnlyRefreshBackMapFlag(UGbool bRefreshBackMap);

protected:
	//! \brief ����ǰ�����ߵ�������ӽ��Ĺ̶�������
	void AdjustToNearestFixedScale();
	void PanEx(UGdouble dOffsetX, UGdouble dOffsetY);			
	void LockMapDrawBounds();	
	//���ڸ�������豸�ķ�Χm_rcDrawBounds������ǰ��ͼ��ʾ��Χ�ĳ������,
	//ʹ�õ�ͼ��ʾ���м���������Ͻǡ����bByMax == false����ô��ͼ��ʾ��Χ
	//�����ᳬ��Ŀǰ�ķ�Χ.
	void AdjustWidthHeightRatio(UGbool bByMax = true,UGbool bByWidth = false);	
	void SetOption(UGbool bFalg, UGint nValue);
	void ChangeLogicalDrawBounds(const UGRect& rcLogicalBounds);
	//! \brief �豸ͼ���������ת�߼�����
	void MPtoLPDevice(const UGPoint2D& pntSource, UGPoint& pntTarget);
	//! \brief �豸ͼ���������ת�߼�����(�߾���ģʽ)
	void MPtoLPDevice(const UGPoint2D& pntSource, UGPoint2D& pntTarget);

	UGSize LPtoDPSize(const UGSize &szLP);

	// �����߼�����ת����double�͵��߼����꣬��߾��ȡ�
	// �����������߼�����ʱ�Ѿ�ʹ���˸߾��ȣ�����������Ҫʹ���߼���ߵĵط�����Ҫ�������������ɸ߾��ȵ��߼����
	UGSize2D LPtoHLP(const UGSize &szLP);

public:
	UGbool m_bIsDisplayClip;	// �ñ�����������;��1. ��ʾ�Ƿ�ʹ�òü�����2. ��Drawingʹ�ñ�ʾ��ǰ���ƵĶ����Ƿ��Ѿ������˲ü���
								// ��������;������ͻ�������û�ֻ��Ҫ�������һ����;��

	UGRect2D m_rc2ClipBounds;

	// �û����õ�ȫ����Χ
	UGbool m_bIsUserEntireBounds;
	UGRect2D m_rc2UserEntireBounds;

	UGbool m_bCoordRatioChange;
	
	//! \brief UGGeoPicture�����֡��ʾ�ĵ�ǰ֡����
	UGint m_nPictureCurFrame;

	//! \brief ��������ʾ��ʱ����ô�Bounds�ü����ڲ������������⿪��
	UGbool m_bUseMapDrawBoundsToPrint;
	UGRect2D m_rcMapDrawBoundsToPrint;

	//! \brief ��¼Bounds�仯����������⿪�ţ�
	UGRect2D m_rcPreMapDrawBounds;

	//! \brief ��¼Graphics�������꣬�����⿪�ţ�
	UGPoint m_pntGraphicsWindowOrg;
	UGdouble m_dCoorRatioX;
	UGdouble m_dCoorRatioY;

protected:
	//! \brief ��ʾ��ǰ�������ɻ���
	UGbool m_bIsOutputCache;
	//! \brief �Ƿ�������ͼ��תΪ���ݼ�����ʱΪ����Ԥ����׼��
	UGbool m_bBanchLayersToDataset;
	//! \brief ��ͼ��LP��DP��ӳ��ģʽ����ֵ��ö��UGGraphics::MapMode �����塣
	UGint m_nMapMode;
	//! \brief ��ͼ��ɫģʽ����ֵ��ö�� UGMapColorMode �����塣
	UGint m_nMapColorMode;	
	//! \brief �û���������ֵ��ö�� UGEditType::EditToolShape �����塣
	UGint m_nUserAction;
	UGint m_nUserActionSaved;		

	//! \brief ��ʾGeometry�����괮����
	UGint m_nPointCount;	
	UGPoint *m_pPointsBuf;	

	//! \brief ����ƫ����
	UGPoint m_pntOffset;
	//! \brief ����ԭ�������λ�ã�LP��
	UGPoint m_pntWindowOrg;
	//! \brief ������ͼ��Χ
	UGRect2D m_rcMapBounds;
	UGRect2D m_rcMapBoundsSaved;
	//! \brief ��ͼˢ�·�Χ(MP)
	UGRect2D m_rcInvalidBounds;	

	//! \brief ��ͼ�߼���Χ(LP)
	UGRect m_rcLogicalBounds;
	UGRect m_rcLogicalBoundsSaved;
	//! \brief ��ǰ��ͼ��ʾ��Χ
	UGRect2D m_rcMapDrawBounds;
	UGRect2D m_rcMapDrawBoundsSaved;
	UGRect2D m_rcRotateMapDrawBounds;
	
	//! \brief ��ͼ������ʾ��Χ
	UGRect2D m_rcLockedDrawBounds;

	//! \brief ����ת������LP/MP��
	UGdouble m_dCoordRatio;
	UGdouble m_dCoordRatioSaved;	

	//! \brief ��ͼ��ת�Ƕ�
	UGdouble m_dAngle;	

	//! \brief ��ͼ�����С���ű���
	double m_dMinScale;
	double m_dMaxScale;

	//! \brief ��ͼ�������
	UGStyle m_BackgroundStyle;
	//! \brief ��ǰ��ʾ�ı��ַ���
	UGString::Charset m_nCurCharset;

	//! \brief ��ʾGeometry��ʱ���
	UGStyle* m_pGeometryStyle;
	UGTextStyle* m_pTextStyle;

	UGPen* m_pCurPen;
	UGBrush* m_pCurBrush;
	UGFont* m_pCurFont;

	//! \brief ��ʾGeometry��ʱ����
	UGMarkerSymbol *m_pMarkerSym;
	UGLineSymbol *m_pLineSym;
	UGFillSymbol *m_pFillSym;

	//! \brief ��ʱ���Ų���
	UGMarkerSymParam* m_pMarkerSymParam;
	UGFillSymParam* m_pFillSymParam;
	UGLineSymParam* m_pLineSymParam;
	
	//! \brief �����С�ɼ��ı���С���߼���λ��
	UGint m_nVisibleTextSizeMin;
	UGint m_nVisibleTextSizeMax;
	
	UGdouble m_dScaleRatio;
	UGdouble m_dDPIScale;
	UGdouble m_dSymScale;						//�������ű���
	UGdouble m_dSymScaleX;						//����X�����ϵ����ű���ϵ�� added by dongfei
	UGRefTranslator* m_pRefTranslator;			//��̬ͶӰת��

	UGuint m_nOption;
	UGint m_nMaxVisibleVertex;

	// ��ͼ�Ƿ��������ΪImage���ݼ�
	UGbool m_bOutputImage;

	// �Ƿ񳬳���ͼ��ΧҲ��������
	UGbool m_bDrawOutsideMapBounds;

	//! \brief ��ʾͼ��ѡ��
	UGint m_nDrawLayerType;
	//! \brief ��ǰ��ʾͼ�������Լ���ͼ������Ϊ�˼�����ʾ�ٷֱ�
	UGint m_nDrawLayerIndex;
	UGint m_nDrawLayerCount;
		
	//! \brief �Ƿ�������Ϳ�ȣ�������ʾ
	/**
	*/	
	UGbool m_bLineAdjust;

	//! \brief ��ƽ����ʾ������¼�� -1��ʾ���޴� dongfei 2007-03-26
	UGint m_nSmoothingMaxRecord;
	UGbool m_bForceAdd;			//�Ƿ�ǿ�Ƽ��뵽�����ı�������

	UGbool m_bFixedScales;		// �Ƿ��ǹ̶�������
	UGArray<UGdouble> m_arrFixedScales;	// �̶������߹���������ı�����

	UGbool m_bIsDeviceDraw;
	//! \brief �豸������Y�ķ���true��Ϊ���£�falseΪ����
	UGbool m_bOrientation;

	// ������ǲ������ŵ�ͼ��ת��������������ת���
	UGbool m_bIsFillAngle;
	//! \brief ���ھֲ�ˢ�����ι��ܣ���¼�ǲ����м�ȡ��������
	UGbool m_bIsDrawComplete;

	UGbool m_bIsSymbolFillIgnored;

	UGbool m_bCoordRatioToScale;
	UGbool m_bIsSymbolDefaultColor;

	UGdouble m_dMapDPI;
	UGbool m_bUseSystemDPI;

	//! \brief ���ڱ�ǵ�һ�δ򿪵�ͼ��ʱ�򣬵�ͼ������λ����Ϣ�ǲ��Ƿ����仯��   added by zhengyl 2011-6-16
	UGbool m_bIsFirstMapCenterChange;

	//�Ƿ��������ͼͼ��
	UGbool m_bHasWebMapFlag;
	UGdouble m_dWebMapCoorRatioX;
	UGdouble m_dWebMapCoorRatioY;

	UGMapOverlapDisplayedOptions m_overlapDisplayedOptions;

	//! \brief �Ƿ�������ļ���
	UGbool m_bPrintToFile;
	// �Ƿ�ֻˢ�������ͼ
	UGbool m_bOnlyRefreshWebMapFlag;

	// �Ƿ��Ǹ߾�������ת��ģʽ
	UGbool m_bHighPrecisionFlag;

	// �Ƿ��ǻ��Ʊ�����ͼ����ģʽ
	UGbool m_bDrawBackMapMode;

	// �Ƿ�ֻˢ�������ͼ
	UGbool m_bOnlyRefreshBackMapFlag;
};

}

#endif // !defined(AFX_UGDRAWPARAMATERS_H__8A1C2D67_F27C_4242_A968_AAB8D94D4E42__INCLUDED_)

