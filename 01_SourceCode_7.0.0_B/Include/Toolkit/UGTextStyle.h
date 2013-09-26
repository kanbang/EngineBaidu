
/*!
   **************************************************************************************
    \file     UGTextStyle.h
   **************************************************************************************
    \author   �¹���
    \brief    �ı������                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-07-06  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#ifndef UGTEXTSTYLE_H
#define UGTEXTSTYLE_H

#include "Stream/ugdefs.h"

namespace UGC {

//! \brief �ı������
class TOOLKIT_API UGTextStyle  
{
public:
	//! \brief
	UGTextStyle();
	//! \brief
	UGTextStyle(const UGTextStyle& textStyle);
	//! \brief
	~UGTextStyle();

	//! \brief
	UGTextStyle& operator=(const UGTextStyle& textStyle);
	//! \brief
	UGbool operator==(const UGTextStyle& textStyle) const;
	//! \brief
	UGbool operator!=(const UGTextStyle& textStyle) const;

public:
	//! \brief
	UGbool FromOgdcTextStyle(const OgdcTextStyle& ogdcTextStyle);
	//! \brief
	UGbool ToOgdcTextStyle(OgdcTextStyle& ogdcTextStyle) const;
	
	  //!  \brief Toolkit
	//! \brief  �õ�������ɫ
	UGColor GetForeColor() const;	
	  //!  \brief Toolkit
	//! \brief  ����������ɫ
	void SetForeColor(UGColor foreColor);	
	  //!  \brief Toolkit
	//! \brief  ����ɫ����Ӱɫ�����ɫ
	UGColor	GetBackColor() const;
	
	  //!  \brief Toolkit
	//! \brief  ���ñ���ɫ,ͬʱҲ����Ӱɫ�����ɫ
	void SetBackColor(UGColor backColor);	
	  //!  \brief Toolkit
	//! \brief  �õ���ת�Ƕȣ��Զ�Ϊ��λ����ʱ�뷽��
	UGdouble GetAngle() const;	
	  //!  \brief Toolkit
		//! \brief  ������ת�Ƕȣ��Զ�Ϊ��λ����ʱ�뷽��
	void SetAngle(UGdouble dAngle);
	  //!  \brief Toolkit
		//! \brief  �õ������ȣ�����λ
	UGdouble GetWidth() const;
	  //!  \brief Toolkit
	//! \brief  ���������ȣ�����λ
	void SetWidth(UGdouble dWidth);
  //! \brief Toolkit
  //! \brief  �õ�����߶ȣ�����λ
	UGdouble GetHeight() const;	
	  //!  \brief Toolkit
	//! \brief  ��������߶ȣ�����λ
	void SetHeight(UGdouble dHeight);
	// added by lidl 2008-9-10 16:43:20
	  //!  \brief Toolkit
	//! \brief  �õ��ֺ�,��λ���� 
	UGdouble GetSize() const;
	  //!  \brief Toolkit
	//! \brief  �����ֺţ���λ����
	void SetSize(UGdouble dSize);	
	//!  \brief Toolkit
	//! \brief �õ���������	
	UGString GetFaceName() const;
	 //!  \brief Toolkit
     //! \brief  ������������
	void SetFaceName(const UGString& strFaceName);
	//!  \brief Toolkit
	//! \brief  �õ����з����Ϣ:���壬б�壬͸��������,���е�
	UGint GetStyle() const;			
	//!  \brief Toolkit
	//! \brief �������еķ�񣬸߼��û�ʹ��!
	void SetStyle(UGint nStyle);	
	//! \brief Toolkit
	//! \brief  �Ƿ����
	UGbool IsBold() const;	
	//!  \brief Toolkit
	//! \brief  �����Ƿ����
	void SetBold(UGbool bBold = true);				
	//!  \brief Toolkit
	//! \brief  �Ƿ��»���
	UGbool IsUnderline() const;
	//!  \brief Toolkit
	//! \brief  �����Ƿ��»���
	void SetUnderline(UGbool bUnderline = true);		
	  //!  \brief Toolkit
	//! \brief  �Ƿ�б��
	UGbool IsItalic() const;	
	//!  \brief Toolkit
	//! \brief  �����Ƿ�б��
	void SetItalic(UGbool bItalic = true);			
	//!  \brief Toolkit
	//! \brief  �Ƿ�ɾ����
	UGbool IsStrikeOut() const;		
	//! \brief Toolkit
	//! \brief �����Ƿ�ɾ����
	void SetStrikeOut(UGbool bStrikeOut = true);
	//!  \brief Toolkit
	//! \brief  �õ����뷽ʽ
	UGbyte GetAlign() const;				
	//!  \brief Toolkit
	//! \brief  ���ö��뷽ʽ
	void SetAlign(UGbyte nAlign = 0);				
	  //!  \brief Toolkit
	//! \brief  �õ��ı��ıʻ����
	UGint GetWeight() const;					
	  //!  \brief Toolkit
	//! \brief  �����ı��ıʻ����
	void SetWeight(UGint nWeight);	
	  //!  \brief Toolkit
	//! \brief  �Ƿ�̶���С
	UGbool IsFixedSize() const;			
	//!  \brief Toolkit
	//! \brief �̶���С�����岻���ͼ�����Ŷ�����
	void SetFixedSize(UGbool bFixedSize=true);			
	//!  \brief Toolkit
	//! \brief  �̶���С�ĳߴ磬mm��λ
	UGdouble GetSizeForFixed() const;			
	  //!  \brief Toolkit
	//! \brief ���ù̶���С�ĳߴ磬mm��λ
	void SetSizeForFixed(UGdouble dSize);		

	  //!  \brief Toolkit
	//!  \brief �Ƿ񱳾���͸��, ע����,true��ʾ��͸��!!
	UGbool IsBackOpaque() const;				
	  //!  \brief Toolkit
	//! \brief  �����Ƿ񱳾���͸��
	void SetBackOpaque(UGbool bBackOpaque = false);				
	  //!  \brief Toolkit
	//! \brief �Ƿ���ʾ���
	UGbool IsHalo() const;			
	  //!  \brief Toolkit
	//! \brief  �����Ƿ���ʾ���
	void SetHalo(UGbool bHalo = true);		
	

	//{{added by mahb at 20120716
	//! \brief  ���ñ�����͸����
	//! \params ucTransparency ͸���ȣ�0~255��0Ϊ͸����255Ϊ��͸��
	void SetBackTransparency(UGuchar ucTransparency);

	//! \brief  ��ȡ������͸����
	UGuchar GetBackTransparency() const;
	//}}
	
	  //!  \brief Toolkit
	//! \brief  �Ƿ���ʾ��Ӱ
	UGbool IsShadow() const;	
	
	  //!  \brief Toolkit
	//! \brief  �����Ƿ���ʾ��Ӱ
	void SetShadow(UGbool bShadow = true);			
	
	//! \brief
	  //!  \brief Toolkit
	  //!  \brief Toolkit
	UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief
	  //!  \brief Toolkit
	UGString ToXML(UGint nVersion = 0) const;

	
	  //!  \brief Toolkit
	//! \brief ��ȡ�ı��������hashcode
	UGint GetHashCode() const;

	//! \brief ��ȡ/�����ʼ�Ч��,����60��֮�䣬Ŀǰֻ�Ա�ǩר��ͼ��Ч��������Ƕ�Ϊ��λ
	UGdouble GetItalicAngle() const;
	  //!  \brief Toolkit
	void SetItalicAngle(UGdouble nItalicAngle);
	  //!  \brief Toolkit

	//! \brief  �õ�3D�ı���͸����
	//! \remarks �ò���������ά��ʹ�ã�֧�ֱ���ΪXMLUGC��Ϣ,SFC�汾�����棬���ݿ��в��������Ϣ��Ĭ��Ϊ100,��͸��,OGDC�в�����˷��
	UGint GetText3DOpaque() const;		
	//! \brief ����3D�ı��Ĳ�͸����
	void SetText3DOpaque(UGint nOpaque);
	
	//! \brief �õ�3D�ı������ű���
	//! \remarks �ò���������ά����ʱʹ�ã������棬OGDC�в�����˷��
	UGdouble  GetText3DScale() const;		
	//! \brief �����ı������ű���
	void SetText3DScale(UGdouble dScale);	
	
private:
	UGColor		m_ForeColor;			//! ������ɫ
	UGColor		m_BackColor;			//! ����ɫ����Ӱɫ�����ɫ
	UGint		m_nAngle;				//! ��ת�Ƕȣ���0.1��Ϊ��λ,x����������Ϊ��ʼ����ʱ�뷽��
	UGint		m_nItalicAngle;			//! ��ת�Ƕȣ���0.1��Ϊ��λ,x����������Ϊ��ʼ����ʱ�뷽��
	UGdouble	m_dWidth;				//! �����ȣ�����λ
	UGdouble	m_dHeight;				//! ����߶ȣ�����λ
	UGString	m_strFaceName;			//! ��������
	UGint		m_nStyle;				//! ���:���壬б�壬͸��������,���е�	
	UGbyte      m_nText3DOpaque;
	UGdouble    m_dText3DScale;
	//UGdouble    m_dSize;				//! �����ֺ�

	//{{ added by mahb at 20120716
	UGuchar     m_ucBackTransparency;   //! ����͸����
};

}

#endif

