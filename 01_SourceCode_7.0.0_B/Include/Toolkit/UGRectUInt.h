/*! \file	 UGRectUInt.h
 *  \brief	 4 byte unsinged int rect
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
 *  All Rights Reserved
 *  \version $Id: UGRectUInt.h,v 1.3 2009/05/15 01:34:59 chenzhao Exp $
 */
/*! ����˵��
*    2007.09.29 guohui	��ͷ�ļ�������ϸע��
*/ 

#ifndef UGRECTUINT_H
#define UGRECTUINT_H

#include "Stream/ugdefs.h"

namespace UGC {

class TOOLKIT_API UGRectUInt  
{
public:

	  //!  \brief Toolkit
	UGuint left;
	  //!  \brief Toolkit
	UGuint top ;
	  //!  \brief Toolkit
	UGuint right;
	  //!  \brief Toolkit
	UGuint bottom;
	  //!  \brief Toolkit
public:
	  //!  \brief Toolkit

	//! \brief 		ȱʡ���캯��
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGRectUInt();

	//! \brief 		��������
	//! \return 	void
	//! \param 		
	//! \remarks 	
	virtual ~UGRectUInt();

	//! \brief 		���ι��캯��
	//! \return 	void
	//! \param 		l	��
	//! \param 		t	��
	//! \param 		r	��
	//! \param 		b	��
	//! \remarks 	�ײ㲻������ݽ��й���(����ȷ��left<right,top<bottom)��ϵ
	UGRectUInt(UGuint l, UGuint t, UGuint r, UGuint b);

	//! \brief 		�������캯��
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGRectUInt(const UGRectUInt& srcRect);
	
	//! \brief 		���
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGuint Width() const;

	//! \brief 		�߶�
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGuint Height() const;
	
	//! \brief 		���� =
	UGRectUInt& operator=(const UGRectUInt& srcRect);

	//! \brief 		���� ==
	UGbool operator==(const UGRectUInt& rect) const;

	//! \brief 		���� !=
	UGbool operator!=(const UGRectUInt& rect) const;
	
	//! \brief 		�������ÿ�
	void SetRectEmpty();
	
	//! \brief 		�������ÿ�(0,0,0,0)
	void SetNULL();
	
	//! \brief 		�ϲ�����
	UGbool UnionRect(const UGRectUInt &rect1, const UGRectUInt &rect2);

	//! \brief 		�Ƿ����
	UGbool Contain(const UGRectUInt &rect) const;

	//! \brief 		�Ƿ��ཻ(�����߻�ǵ��ص�)	
	UGbool IsIntersect(const UGRectUInt &rect) const;
	
	//! \brief 		�Ƿ�Ϊ�վ���
	//! \return     TRUE if rectangle has no area
	UGbool IsRectEmpty() const;

	//! \brief 		�Ƿ�Ϊ��
	//! \return     TRUE if rectangle is (0,0,0,0)
	UGbool IsRectNull() const;

};

}

#endif

