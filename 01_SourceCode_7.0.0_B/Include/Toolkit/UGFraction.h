/**  \file UGFraction.h
   \brief 实现一个分数类的管理
   \author lugw
   \attention 
   Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
   All Rights Reserved.
 */ 

#if !defined(AFX_UGFRACTION_H__E201903D_6704_44FE_B8C2_BFBCF64C37B2__INCLUDED_)
#define AFX_UGFRACTION_H__E201903D_6704_44FE_B8C2_BFBCF64C37B2__INCLUDED_

#include "Stream/ugdefs.h"
#include <math.h>

namespace UGC
{
	
	  //!  \brief Toolkit
class TOOLKIT_API UGFraction  
{
public:
	  //!  \brief Toolkit
	UGFraction();
	  //!  \brief Toolkit
	UGFraction(UGdouble& decimal,UGint nMaxNumber = 999);
	  //!  \brief Toolkit
	UGFraction(UGint nDenominator,UGint nNumerator,UGint nNegative);
	  //!  \brief Toolkit
	void operator = (const UGFraction &fraction);
	  //!  \brief Toolkit
	virtual ~UGFraction();

	//! \brief 得到分数的分子
	
	//! \param nNegative  分数的分子
	
	UGint GetDenominator();
	//! \brief 设置分数的正负
	
	//! \param nNegative  分数的分子

	void SetDenominator(UGint &nDenominator);

	//! \brief 得到分数的分母
	//! \param nNegative  分数的正负
	UGint GetNumerator();
	//! \brief 设置分数的分母
	//! \param nNumerator  分数的分母
	void SetNumerator(UGint &nNumerator);

	//! \brief 得到分数的正负
	//! \return 分数正负
	UGbool GetNegative();
	//! \brief 设置分数的正负
	//! \param nNegative  分数的正负
	void SetNegative(UGbool &nNegative);

private:
	//! \brief 分子
	UGint m_nDenominator;
	//! \brief 分母
	UGint m_nNumerator;
	//! \brief 正负
	UGbool m_nNegative;

};


}

#endif // !defined(AFX_UGFRACTION_H__E201903D_6704_44FE_B8C2_BFBCF64C37B2__INCLUDED_)

