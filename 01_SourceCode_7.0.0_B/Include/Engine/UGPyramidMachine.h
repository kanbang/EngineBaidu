//////////////////////////////////////////////////////////////////////////
//!  \file     UGPyramidMachine.h:
//!  \brief	   �����������㷨
//!  \details  
//!  \author   zhouqin/wangmao
//!  \attention 
//!   Copyright (c) 1997-2010 SuperMap GIS Technologies,Inc.  <br>
//!   All Rights Reserved.
//!  \version 1.0
//////////////////////////////////////////////////////////////////////////
#ifndef UGPYRAMIDMACHINE_H
#define UGPYRAMIDMACHINE_H

#include "Stream/ugdefs.h"
#include "Engine/UGDataSource.h"
#include "Engine/UGDataset.h"

namespace UGC {

typedef void (*AVGFUNC)(UGImgBlock* pDes, UGImgBlock* pSrc, 
						UGint nDesStarti, UGint nDesStartj, UGdouble dbNovalue);

class ENGINE_API PyramidMachine
{
public:
	//����դ�����ݼ�����Ϣ��ʼ������������
	//��߸������ݼ������ظ�ʽ����������ֵ�ĺ�����ֵ
	//��ʼ����ÿһ�����صĸ���,ÿһ���ֽ���,�������ص��ֽڴ�С
	//dtType ���ݼ����ͣ��������ݼ����ͣ��Ա߽���ֵ�����⴦��
	PyramidMachine(PixelFormat ePixelFormat, UGDataset::DatasetType dtTyp, UGdouble dbNoValue, UGbool bHasColorset);

	//������Ŀ���ImgBlock
	void run(UGImgBlock* pDest,UGImgBlock* pLT,UGImgBlock* pRT,UGImgBlock* pLB,UGImgBlock* pRB);

	UGbool IsSupport(){return m_bCanBuild;};

private:
	void comLT();
	void comRT();
	void comLB();
	void comRB();

private:
	AVGFUNC AvgFuntion;

	//�ж����ظ�ʽ�Ƿ���Խ���������
	UGbool m_bCanBuild;

	UGdouble m_dbNoValue;

	UGImgBlock* m_pDest;
	UGImgBlock* m_pLT;
	UGImgBlock* m_pRT;
	UGImgBlock* m_pLB;
	UGImgBlock* m_pRB;
};

} //namespace UGC

#endif // !defined(UGPYRAMIDMACHINE_H)

