//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author ����ת���顣
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGMAPSERVICEPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_)
#define AFX_UGMAPSERVICEPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_

#include "MapServiceStub/UGMapServiceType.h"
#include "FileParser/UGExchangeFileType.h"
#include "Projection/UGPrjCoordSys.h"

namespace UGC {

//! \brief ת���������ࡣ
class MAPSERVICESTUB_API UGMapServiceParams  
{

public:
	
	//! \brief ���캯����
	UGMapServiceParams();
	
	//! \brief ����������
	virtual ~UGMapServiceParams();

public:
	//! \brief �õ��������͡�
	//! \param  [in]��
	//! \return �������͡�
	//! \remarks ���������Լ�ʵ�֡�
	virtual UGint GetServiceType() const {return 0;}
	
public:
	UGString m_strBaseURL;						// �������ַ,��:http://maps.googlemap.com	
	UGString m_strMapName;					    // ��ͼ���ơ�����������������Ϊ����Դ��ʽ���м���ʱ������Դ����
	UGPrjCoordSys m_prjCoordSys;				// ͶӰ��Ϣ������ͼ������ص���ά�����еı�����Ϣ��
	UGFileType::EmType m_nImageType;			// ͼƬ��ʽ
	UGint m_nTileSize;							// ��Ƭ���ر߳���Ĭ�� 256 ����
	UGPoint2D m_pntCenter;						// Ĭ����ʾ�����ĵ㣬Ĭ��ֵ��0��0��
	UGdouble m_dCoordRatio;						// LP/DP��ӳ���ϵ��
	UGPoint2D m_pntOrigin;						// ��������������ԭ������棬Ĭ��ֵ��0��0��
	std::vector<UGdouble> m_vectOutputScales;		// ����������
	UGbool m_bCompactCache;						// �Ƿ��ǽ��ջ���
	UGRect2D m_rcBounds;
	UGint m_nLevel;								//������ܲ���

};

} //namespace UGC
#endif // !defined(AFX_UGMAPSERVICEPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_)

