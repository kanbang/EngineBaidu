/*!
**************************************************************************************
\file    UGOpenMP.h 
**************************************************************************************
\author  ¬�� 
\brief   ��װOpenMP��һЩ���ã�����ʹ��
\attention   
----------------------------------------------------------------------------------<br>
Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                               <br>
All Rights Reserved.                                                              <br>
----------------------------------------------------------------------------------<br> 

**************************************************************************************
*/

#include "Toolkit/UGToolkit.h"

#if !defined(UGOPENMP_H)
#define UGOPENMP_H

namespace UGC {

class TOOLKIT_API UGOpenMP
{
public:
	UGOpenMP();

	//! \brief ��ȡʵ��
	static UGOpenMP& GetInstance();

	//! \brief ��ȡ�߳���Ŀ
	UGint GetNumThreads();

private:
	UGint m_nNumThreads;
};

}

#endif //#define UGOPENMP_H