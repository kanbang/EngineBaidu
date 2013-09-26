// UGMapOverlapDisplayedOptions.h: interface for the UGMapOverlapDisplayedOptions class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGMapOverlapDisplayedOptions.h
   **************************************************************************************
    \author   ��Ƽ
    \brief    ��ͼ���������ʾѡ����                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2012-03-7  ��Ƽ    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/
#if !defined(AFX_UGMAPOVERLAPDISPLAYEDOPTIONS_H__DC6194D6_CDEC_4A74_8522_AC23C8C202F5__INCLUDED_)
#define AFX_UGMAPOVERLAPDISPLAYEDOPTIONS_H__DC6194D6_CDEC_4A74_8522_AC23C8C202F5__INCLUDED_

#include "Stream/ugexports.h"
#include "Stream/ugdefs.h"

namespace UGC {

class UGGeoText;
class UGGeoCompound;
class UGDrawing;
class UGTextStyle;
class UGGeoPoint;

class DRAWING_API UGMapOverlapDisplayedOptions  
{
public:
	enum UGOverlayType
	{
		UG_Type_Text, 
		UG_Type_GraduatedSymbol,	
		UG_Type_Graph,
		UG_Type_Point,
		UG_Type_PointWithLabel
	};

public:
	UGMapOverlapDisplayedOptions();

#ifdef SYMBIAN60
	~UGMapOverlapDisplayedOptions();
#else
	virtual ~UGMapOverlapDisplayedOptions();
#endif

	UGMapOverlapDisplayedOptions& operator = (const UGMapOverlapDisplayedOptions& mapOverlapDisplayedOptions);

public:
	//��ȡ�ı��ص�ʱ�Ƿ���ʾ����
    UGbool GetIsAllowTextOverlap() const;

	//�����ı��ص�ʱ�Ƿ���ʾ����
	void SetIsAllowTextOverlap(UGbool value);

	//��ȡ���ص�ʱ�Ƿ���ʾ����
	UGbool GetIsAllowPointOverlap() const;

	//���õ��ص�ʱ�Ƿ���ʾ����
	void SetIsAllowPointOverlap(UGbool value);

	//��ȡ��ǩ�͵��Ƿ�ѹ�ǹ�����ʾ
	UGbool GetIsAllowTextAndPointOverlap() const;

	//���ñ�ǩ�͵��Ƿ�ѹ�ǹ�����ʾ
	void SetIsAllowTextAndPointOverlap(UGbool value);

	//��ȡ��ǩ����Ӧ��ͨͼ���ϵĵ��Ƿ�һ�������ʾ
	UGbool GetIsAllowPointWithTextDisplay() const;

	//���ñ�ǩ����Ӧ��ͨͼ���ϵĵ��Ƿ�һ�������ʾ
	void SetIsAllowPointWithTextDisplay(UGbool value);

	//��ȡ�ȼ�����Ԫ���ص�ʱ�Ƿ���ʾ����
	UGbool GetIsAllowThemeGraduatedSymbolOverlap() const;

	//���õȼ�����Ԫ���ص�ʱ�Ƿ���ʾ����
	void SetIsAllowThemeGraduatedSymbolOverlap(UGbool value);

	//��ȡͳ��ר��ͼԪ���ص�ʱ�Ƿ���ʾ����
	UGbool GetIsAllowThemeGraphOverlap() const;

	//����ͳ��ר��ͼԪ���ص�ʱ�Ƿ���ʾ����
	void SetIsAllowThemeGraphOverlap(UGbool value);

	//��ȡ�ص���࣬��λΪ0.1����
	UGSize2D GetOverlappedSpaceSize() const;

	//�����ص���࣬��λΪ0.1����
	void SetOverlappedSpaceSize(UGSize2D value);

	//! \brief ������XML
	UGString ToXML() const;
	//! \brief ��ȡXML��Ϣ
	UGbool FromXML(const UGString& strXML);

	// �����ı�ʹ��  //modified by dongfei 2007-04-11 ����������� һ����������룬һ�����Ƿ�ǿ�м�����ı���Χ
	//! \brief �ж��Ƿ�ѹ��ͼ���ı�����
	//! \param pText Ҫ�жϵ��ı��Ķ���
	//! \param bThemeStyle �Ƿ�Ϊ��ǩר��ͼ
	//! \param szBuffer ������� 
	//! \param bSingleTextStyle �Ƿ�͵�ǰ��һ�����ı���ʽ 
	//! \param bSelfOverlap �Ƿ���ѹ�� 
	//! \param bOverlapBounds �Ƿ���ͼ��߽��ཻ 
	//! \return �Ƿ�ѹ���ı����� 
	//! \remarks ���ù���1.��ǩ�ͱ�ǩ��ͳ��ͼ��ͳ��ͼ�������ı��£����б��ã����ж�ָ��������Ƿ���ѹ�����⣬�����ѹ�������Ƶı����ѻ��Ƶģ���ѡ�����ȼ��ߵı���λ�ã�������Ա������Դ�λ�ý��л��ƣ�������������޷����������ѹ�ǹ��˴���2.ͳ��ͼ��ͳ��ͼ�����ı�����£��������ͼ��֮���ѹ���������չ���1����ͳ��ͼ��ͳ��ͼ���ô��������ͼ�κ��ı���ѹ�����������ѹ�ǣ���Ȼ��ʾ��������ı����ı�֮���ѹ�ǣ����չ���1�����ı����ı����ô���3.ͳ��ͼ�ͱ�ǩ���б��ã����ͼ�κͱ�ǩ��ѹ��������ѹ������ʾ�������ͳ��ͼ�е��ı��ͱ�ǩѹ�ǣ����չ���1�����ı����ı��ı��ô���4.ͳ��ͼ֧��ͼ�α����ı��ӿڿ����£��ڴ��������£����ͳ��ͼͼ��ѹ���ı�����ͳ��ͼ���б��ô�������޷���������ʾ��������ı�ѹ��ͼ��������ѹ�ǣ���Ȼ��ʾ�����������ѭǰ3������
	UGbool	IsOverlapText(UGDrawing* pDrawing, UGGeoText* pText, UGbool bThemeStyle = false,UGSize2D szBuffer = UGSize2D(-1.0,-1.0),
		UGbool bSingleTextStyle = true, UGbool bSelfOverlap = false,UGbool bOverlapBounds = false);
	//! \brief �ж��Ƿ�ѹ��ͼ���ı�����
	//! \param UGGeoCompound Ҫ�жϵĸ��϶���
	//! \param bThemeStyle �Ƿ�Ϊ��ǩר��ͼ
	//! \param bOverlapBounds �Ƿ���ͼ��߽��ཻ 
	//! \return �Ƿ�ѹ���ı����� 
	UGbool	IsOverlapText(UGDrawing* pDrawing, UGGeoCompound* pGeoCompound, UGbool bThemeStyle = false, UGSize2D szBuffer = UGSize2D(-1.0,-1.0), UGbool bOnlyText = true, UGbool bOverlapBounds = false);
	//! \brief �жϵ�����Ƿ�ѹ������������Լ��ı�����
	//! \param pRect Ҫ�жϵĵ������߼���Χ
	//! \param szBuffer ����������
	//! \return �Ƿ�ѹ��
	UGbool IsOverlapPointAndText(UGDrawing* pDrawing,UGRect* pRect,UGSize szBuffer = UGSize(-1,-1));
	//! \brief �жϾ��ζ����Ƿ�ѹ��ͼ���ı�����
	//! \param pRect Ҫ�жϵľ��ζ���
	//! \param szBuffer ����������
	//! \return �Ƿ�ѹ���ı����� 
	UGbool	IsOverlapText(UGDrawing* pDrawing, UGRect* pRect,UGbool& bTextOverlap,UGSize szBuffer = UGSize(-1,-1));
	//! \brief �жϾ��ζ����Ƿ�ѹ��ͼ���ı�����
	//! \param pRect Ҫ�жϵľ��ζ���
	//! \param szBuffer ����������
	//! \return �Ƿ�ѹ���ı����� 
	//! \remarks ����ͳ��ͼ�ı��ã����ͳ��ͼ��ͳ��ͼѹ��,�����˺󻭣����ͳ��ͼ����ʾ���֣����ǩ��ͳ��ͼ��ʹѹ��Ҳ����ʾ�����ͳ��ͼ�е����ֲ��ֺͱ�ǩѹ��������ͳ��ͼ����
	//!          �˺�����Ҫ���ڴ���ȼ�����ר��ͼ��ѹ�����⣬���ʹ��ͳ��ר��ͼ�ģ��ͻ������Ϊ�Ȼ���ͳ��ר��ͼ���ѵȼ�����ר��ͼʡ�Բ���
	UGbool	IsOverlapGraduateText(UGDrawing* pDrawing, UGRect* pRect,UGbool& bTextOverlap,UGSize szBuffer = UGSize(-1,-1));
	//! \brief ���һ���ı�������ĸ��߽ǵ����Ƶ���Ļ���ı�����m_arrTextVertexs��
	//! \param pText Ҫ��ӵ��ı�����
	//! \param bThemeStyle �Ƿ�Ϊ��ǩר��ͼ
	//! \param szBuffer ����������
	void AddTextVertexs(UGDrawing* pDrawing, UGGeoText* pText, UGbool bThemeStyle = false,UGSize2D szBuffer = UGSize2D(-1.0,-1.0));
	//�������IsOverlapText��AddTextVertexs�����������ı����ĸ��߽ǳ������ ���ֻ�����Щ�鷳 �Ժ�����
	//UGbool  GetSubTextVertexs(UGSubText* pSubText,const UGPoint2D& pntAnchor, UGArray<UGPoint>& pnts);
	//! \brief �Ƴ���Ļ���ı����������
	void RemoveAllTextVertexs();

	//! \brief ����ӣ���С���ñȽϷ�Χ
	void GridTextVertexs(UGDrawing* pDrawing);
	//! \brief ��Ϊ��ʹĿ�������Դ���β��ཻ��Ŀ�������ƫ�ƵĴ�С(���Ŀ��������ı�������Ҫ���Ƕ��뷽ʽ)
	UGSize2D GetOverlapOffsetSize(const UGRect2D& sourceRect, const UGRect2D& targetRect, UGdouble dTolerance = 0.0, UGbool bTargetText = false, UGbyte nTextAlign = 0);

	void AddVertexs(UGDrawing* pDrawing, UGRect* pRect, UGMapOverlapDisplayedOptions::UGOverlayType overlapType);
	//! \brief �������ѹ��������ض���
	//! \param rectOrigin Ҫ�жϵľ��ζ���Ϊ��תˮƽ֮��ľ���
	//! \param overlapType ѹ������
	//! \param dAngle ���εĽǶ�
	//! \return �Ƿ�ѹ����ض��� 
	UGbool IsOverlap(UGDrawing* pDrawing,UGRect& rectOrigin, UGMapOverlapDisplayedOptions::UGOverlayType overlapType,
		UGSize2D szBuffer = UGSize2D(0,0), UGdouble dAngle = 0, UGPoint pntLogAnchor = UGPoint(0,0));

	//! \brief ��ȡhashcode
	UGint GetHashCode() const;

private:
	//�ı��ص�ʱ�Ƿ���ʾ����Ĭ��Ϊfalse
	UGbool m_bAllowTextOverlap; 

	//��ȡ�����õ��ص�ʱ�Ƿ���ʾ����Ĭ��Ϊtrue����������е����ݼ������е����ݼ��ĵ�ֵ���ֶΡ��Զ���ר��ͼ��
	UGbool m_bAllowPointOverlap; 

	//��ȡ�����ñ�ǩ�͵��Ƿ�ѹ�ǹ�����ʾ��Ĭ��Ϊtrue��
	UGbool m_bAllowTextAndPointOverlap; 

	//��ȡ�����ñ�ǩ����Ӧ��ͨͼ���ϵĵ��Ƿ�һ�������ʾ��Ĭ��Ϊfalse��
	//���������ʾ��ֻ��ͼ�㼯���ж�Ӧ���ݼ���������С��ͼ��ĵ��������Ƶ�
	UGbool m_bAllowPointWithTextDisplay; 

	//��ȡ�����õȼ�����Ԫ���ص�ʱ�Ƿ���ʾ����Ĭ��Ϊtrue
	UGbool m_bAllowThemeGraduatedSymbolOverlap;

	//��ȡ������ͳ��ר��ͼԪ���ص�ʱ�Ƿ���ʾ����Ĭ��Ϊtrue
	UGbool m_bAllowThemeGraphOverlap; 

	//��ȡ�������ص���࣬��λΪ0.1���ס�
	//Ϊ����ʱ��ʾ��������֮��ľ��룬�����������ʾ��С�ڵ��ڸþ���Ĳ���ʾ��
	//Ϊ����ʱ��ʾ����������ص����룬С�ڸþ���ľ���ֵʱ��ʾ�����ڵ��ڸþ���ľ���ֵʱ����ʾ
	UGSize2D m_szOverlappedSpace; 

	//��ʾ����Ļ�ϵ����ֵ���Ļ��������
	//! \brief �洢��ǩר��ͼ����
	//UGArray<UGPoint> m_arrTextVertexs;
	//����ʾ����Ļ�ϵ����ֵ���Ļ��������ֳɸ���
	UGArray<UGPoint>** m_arrGridTextVertexs;
	UGint m_nGridRowCount;
	UGint m_nGridColCount;
	//! \brief ������С
	UGint m_nGridWidth;
	//! \brief �洢ͳ��ר��ͼ����
	UGArray<UGPoint>** m_arrGridGrphVertexs;
	//! \brief �洢�ȼ�����ר��ͼ����
	UGArray<UGPoint>** m_arrGridGraduatetexts;
	//! \brief ����ȼ����ŵĻ��巶Χ,����ʾ�ȼ����ź�,�������ͳ�Ʒ���ʱ,��Ҫ��ԭ������巶Χ,��Ϊ�������Ի��Ƶ�ͳ�ƾͲ�����ʾ��
	UGArray<UGSize>  m_arrBufferSize;
	//! \brief �洢���ѹ�ǹ���ʱ�ĵ�����
	UGArray<UGPoint>** m_arrGridPointVertexs;
	//! \brief �洢��ͱ�ǩһ��ѹ�ǹ���ʱ�ĵ�����(���ֶ��еĵ㲻��m_arrPointVertexs�е������ظ�)
	UGArray<UGPoint>** m_arrGridPointVertexsWithLabel;

	void ComputerRegionRowCol(UGDrawing* pDrawing, UGPoint2D pPntPolygon[], UGint nCount, UGint& nMinCol,UGint& nMaxCol,UGint& nMinRow,UGint& nMaxRow);

	// Ϊ�˹����ı�ʹ��
	UGbool IsOverlapRects(const UGPoint* pPntObliqueRect, const UGRect& rect)const;
	UGint IsPointInRect(const UGPoint& Pnt, const UGRect& rect)const;
	UGint IsPointInObliqueRect(const UGPoint& pnt, const UGPoint* pPntObliqueRect)const;
	void GetPntPolygonOfText(UGDrawing* pDrawing,UGGeoText* pGeoText, UGint nSubIndex, UGTextStyle& textStyle, 
							UGSize2D& szBuffer, UGPoint2D* pPntPolygon, UGint nLength, UGRect* pNotRotatedRect = NULL);
	void AddVertexs(UGDrawing* pDrawing, UGPoint2D* pPntPolygon, UGMapOverlapDisplayedOptions::UGOverlayType overlapType);
};

}

#endif // !defined(AFX_UGTRACKINGLAYER_H__DC6194D6_CDEC_4A74_8522_AC23C8C202F5__INCLUDED_)