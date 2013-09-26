// UGDrawMaker.h: interface for the UGDrawMaker class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDrawMaker.h
   **************************************************************************************
    \author   ���������¹���
    \brief    ��ʾ����Ԥ������                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGDRAWMAKER_H__D2C06D05_68DE_4883_B417_F9CB6685D2AE__INCLUDED_)
#define AFX_UGDRAWMAKER_H__D2C06D05_68DE_4883_B417_F9CB6685D2AE__INCLUDED_

#include "Graphics/UGGraphics.h"
#include "Toolkit/UGStyle.h"

namespace UGC {

class UGMarkerSymbolLib;
class UGLineSymbolLib;
class UGFillSymbolLib;
class UGMarkerSymbol;
class UGLineSymbol;
class UGFillSymbol;
class UGMarkerSymParam;
class UGLineSymParam;
class UGFillSymParam;
class UGDrawParamaters;

class DRAWING_API UGDrawMaker  
{
public:
	UGDrawMaker();

#ifdef SYMBIAN60
	~UGDrawMaker();
#else
	virtual ~UGDrawMaker();
#endif
	
public:
	//! \brief ��ȡ���������Ϣ
	//! \return ���ص�ǰ���������Ϣ
	const UGFillSymbol* GetFillSymbol() const;
	//! \brief ��ȡ���������Ϣ
	//! \return ���ص�ǰ���������Ϣ
	const UGLineSymbol* GetLineSymbol() const;
	//! \brief ��ȡ���������Ϣ
	//! \return ���ص�ǰ���������Ϣ
	const UGMarkerSymbol* GetMarkerSymbol() const;
	//! \brief ��ȡ��ǰ����
	//! \return ��ǰ����
	const UGPen* GetPen() const;
		//! \brief ��ȡ��ǰ����
	//! \return ��ǰ����
	const UGBrush* GetBrush() const;
	//! \brief ��ȡ��ǰ������Ϣ����
	//! \return ��ǰ������Ϣ����
	const UGMarkerSymParam* GetMarkerSymParam() const;
	//! \brief ��ȡ��ǰ������Ϣ����
	//! \return ��ǰ������Ϣ����
	const UGFillSymParam* GetFillSymParam() const;
	//! \brief ��ȡ��ǰ������Ϣ����
	//! \return ��ǰ������Ϣ����
	const UGLineSymParam* GetLineSymParam() const;
	//! \brief �������Կ�
	//! \param pLineSymLib Ҫ���õ����Կ�
	void SetLineSymbolLib(UGLineSymbolLib* pLineSymLib);
	//! \brief ������Կ�
	//! \return ��ǰ�����Կ�
	UGLineSymbolLib* GetLineSymbolLib() const;
	//! \brief ���÷��ſ�
	//! \param pMarkerSymLib Ҫ���õķ��ſ�
	void SetMarkerSymbolLib(UGMarkerSymbolLib* pMarkerSymLib);
	//! \brief ��÷��ſ�
	//! \return ��ǰ�ķ��ſ�
	UGMarkerSymbolLib* GetMarkerSymbolLib() const;
	//! \brief ��������
	//! \param pMarkerSymLib Ҫ���õ�����
	void SetFillSymbolLib(UGFillSymbolLib* pFillSymLib);
    //! \brief �������
	//! \return ��ǰ������
	UGFillSymbolLib * GetFillSymbolLib() const;
	//! \brief �����Ƿ����
	//! \param bHignlight Ҫ���ø���
	void SetHignlight(UGbool bHignlight);
	//! \brief �жϷ����
	//! \return �Ƿ����
	UGbool IsHignlight() const;
	//! \brief ������ʾ����
	//! \param pGraphics Ҫ���õ�ǰͼ����ʾ����
	//! \param style Ҫ���õ�ǰ�ı����
	//! \param pDrawParam Ҫ���õĻ��ʲ���
	//! \param bThemeStyle �Ƿ�Ϊ��ǩר��ͼ
	//! \return �����Ƿ�ɹ�
	UGbool Prepare(UGGraphics *pGraphics, UGTextStyle& style, UGDrawParamaters *pDrawParam, UGbool bThemeStyle = FALSE);
	//! \brief ������ʾ����
	//! \param pGraphics Ҫ���õ�ǰͼ����ʾ����
	//! \param style Ҫ���õ�ǰ���
	//! \param pDrawParam Ҫ���õĻ��ʲ���
	//! \param bThemeStyle �Ƿ�Ϊ��ǩר��ͼ
	//! \return �����Ƿ�ɹ�
	UGbool Prepare(UGGraphics *pGraphics, UGStyle& style, UGDrawParamaters *pDrawParam = NULL, UGint nDimension = 2);
	//! \brief �ͷ���ʾ����
	//! \param pGraphics Ҫ�ͷŵ�ͼ����ʾ����
	//! \param pDrawParam Ҫ�ͷŵĻ��ʲ���
	void Release(UGGraphics *pGraphics, UGDrawParamaters *pDrawParam = NULL);
	
protected:
	UGbool m_bHignlight;
	//! \brief ���ſ�
	UGLineSymbolLib* m_pLineSymLib;
	UGMarkerSymbolLib* m_pMarkerSymLib;
	UGFillSymbolLib * m_pFillSymLib;

	UGMarkerSymbol* m_pMarkerSym;
	UGbool m_bDelMarkerSymbol;
	UGLineSymbol* m_pLineSym;
	UGbool m_bDelLineSymbol;
	UGFillSymbol* m_pFillSym;
	UGbool m_bDelFillSymbol;

	UGMarkerSymParam* m_pMarkerSymParam;
	UGFillSymParam* m_pFillSymParam;
	UGLineSymParam* m_pLineSymParam;
	
	UGint m_nDimension;
	UGPen* m_pCurPen;
	UGPen* m_pOldPen;
	UGBrush* m_pCurBrush;
	UGBrush* m_pOldBrush;
	UGFont* m_pCurFont;
	UGFont* m_pOldFont;
	UGColor m_crPrevForeColor;
	UGColor m_crPrevBackColor;
	UGint m_nPrevBkMode;
	UGint m_nPreAlign;
};

}

#endif // !defined(AFX_UGDRAWMAKER_H__D2C06D05_68DE_4883_B417_F9CB6685D2AE__INCLUDED_)

