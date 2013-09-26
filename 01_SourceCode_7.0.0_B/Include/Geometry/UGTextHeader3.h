/*! \file	 UGTextHeader3.h
 *  \brief	 3.0�汾�ı�ͷ��
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
 *  All Rights Reserved
 *  \version 
 */

#ifndef UGTEXTHEADER3_H
#define UGTEXTHEADER3_H

#include "Toolkit/UGTextStyle.h"

namespace UGC {

//! \brief SuperMap SFC 3 �� GeoText���ı�ͷ�ṹ
class GEOMETRY_API UGTextHeader3		//SuperMap3.x��TextHeader�ṹ
{
public:
	//! \brief ���캯��
	UGTextHeader3();
	//! \brief ��textStyle���졣
	//! \param textStyle [in] �ı����
	void FromTextStyle(const UGTextStyle& textStyle);	

	//! \brief ת��Ϊ�ı�������
	//! \param textStyle [out] ת����õ����ı�������
	void ToTextStyle(UGTextStyle& textStyle) const;	

public:
	//! �Ӷ�����
	UGint m_nSubCount;	
	//! �ı�����ɫ
	UGColor	m_Color;		
	//! �ı��ķ��,   0x BYTE4 BYTE3 BYTE2 BYTE1 
	UGint	m_nStyle;		
	//! ����ɫ
	UGColor	m_BgColor;		
	//! ���Ӣ���ַ�������Ϊ0, ��ϵͳ�Զ�
	UGdouble	m_dFontWidth;	
	//! ���Ӣ���ַ��ߣ�����Ϊ0, �������ֿ��ܲ���ʾ
	UGdouble	m_dFontHeight;	
	//! ���ֵĶ�λ��
	UGPoint2D m_pntAnchor;	
};
//���� SmInt32 m_nStyle;//�ı��ķ��,   0x BYTE4 BYTE3 BYTE2 BYTE1 
						//�ɼ��������,	     |     |     |     |
						//��������ͼ:        |     |     |     +--Text Align
						//				     |     |     +--Text Style
						//				     |     +--Text Font Weight
						//                   +--Text Other Attribute 
						//========================================================
						//BYTE1 �ı��Ķ��뷽ʽ
						//	   ��  ��  ��
						// ��	0	1	2
						// ��	3	4	5
						// ��	6	7	8
						//--------------------------------------------------------
						//BYTE2 �ı���һ����	   ���ֽ�     ��m_lStyle��
						//����	(Bold)				0x01     ( 0x00000100 )
						//б��  (Italic)			0x02     ( 0x00000200 )
						//�»���(Underline)			0x04     ( 0x00000400 )
						//ɾ����(Stroke)			0x08     ( 0x00000800 )
						//--------------------------------------------------------
						//BYTE2 �ı��ĸ߼����	   ���ֽ�     ��m_lStyle��
						//�̶���С(FixedSize)		0x10     ( 0x00001000 )
						//�������(Opaque)			0x20     ( 0x00002000 )
						//��������(Outline)			0x40     ( 0x00004000 )    
						//��ʾ��Ӱ(Shadow)			0x80     ( 0x00008000 )    
						//--------------------------------------------------------
						//BYTE3 �ı��ıʻ���ϸ --> ��windowsһ��
						//--------------------------------------------------------
						//BYTE4�̶���С���ı��ĳߴ� ���ֽ�    ��m_lStyle��
						//�̶��Ĵ�С(FixedSize)		0xff     ( 0xff000000 )
						//========================================================

}

#endif



