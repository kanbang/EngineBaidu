//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGEditType3D.h
//!  \brief ������ά�еı༭������
//!  \author UGCTeam��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITTYPE3D_H__9969CA39_1F0D_4AD2_920F_E860971C502C__INCLUDED_)
#define AFX_UGEDITTYPE3D_H__9969CA39_1F0D_4AD2_920F_E860971C502C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGPrerequisites3D.h"

namespace UGC
{
class GEOMETRY3D_API UGEditType3D  
{
public:
	//! \brief ��ά�༭������״��
	enum EditToolShape3D
	{	
		ET3D_NULL					= 0,			// ��
        ET3D_Selection				= 1,            // ѡ��
        ET3D_Point					= 21,           // �� 
		ET3D_LineSect				= 22,           // ֱ��
		
        ET3D_EllipseArc				= 23,			// ��Բ��
        ET3D_PolyLine				= 24,			// ����,֧��subaction
        ET3D_BezierCurve			= 25,			// ��������,֧��subaction
        ET3D_Rectangle				= 26,			// ����
        ET3D_RoundRect				= 27,			// Բ�Ǿ���
        ET3D_Parallelogram			= 28,			// ƽ���ı���
        ET3D_Circle					= 29,			// Բ��Բ
        ET3D_Ellipse				= 30,			// ��Բ	
        ET3D_ObliqueEllipse			= 31,			// б��Բ
        ET3D_PolyGon				= 32,			// �����,֧��subaction
		ET3D_MulitiPoint			= 33,			// ���
		//ET_ARC3P					= 33,	        // ���㻡��Բ����
        ET3D_Text					= 34,			// ע��
        ET3D_BSpline				= 35,			// B����,֧��subaction
        //sET_SameDistline			= 36,			//��ֵ��
        ET3D_StreamText				= 37,			//����ע��	
		//ET_Mulitiline				= 38,           //�����,�ѷϳ�����ʹ��ET_PolyLineEx��ET_PolygonEx����
		ET3D_Path					= 39,           //·������֪����ô���룩
		ET3D_PolyLineEx				= 42,			// 
		ET3D_PolygonEx				= 43,			// 
		ET3D_Arc3P					= 44,           //���㻡
		ET3D_Circle3P				= 45,           //����Բ
		ET3D_Pie					= 46,           //�ɶ��� 
		ET3D_Circle2P				= 47,           //����Բ
		ET3D_Parallel				= 48,			//ƽ����,֧��subaction
		//ET_Custom					= 49,	        //��չ����
		
		ET3D_TrackPolyLine			= 55,			//���Զ�������
		ET3D_TrackBreak				= 56,			//���Զ����ٻ���
		ET3D_TrackPolyPolygon		= 57,			//������
		ET3D_FreeLine				= 58,			//���ʣ����ɻ��ߣ�֧��subaction		
        ET3D_Cardinal				= 59,			//Cardinal���ߣ�֧��subaction
		ET3D_Hatch					= 60,			//Hatch��
		ET3D_Model					= 61,			// ģ��
		ET3D_Overlay				= 62,			// OverLay
		
		ET3D_SetSnapPoint			= 70,			//����ѡ�ж���Ĳ�׽�㣬�ƶ���ʱ��������õ������׽�㲶׽�������������
		
		ET3D_Picture				= 1101,			//ͼƬ����(GeoPicture)
		
		ET3D_Map					= 2001,			//geomap���󣬲�����
		//ET_MapRegion				= 2004,			//geomapRegion���󣬲�����
		ET3D_Scale					= 2005,			//geoscale���󣬲�����
		ET3D_Direction				= 2008,			//geomap���󣬲�����
		
		ET3D_ArtText				= 2010,			//GeoArtText����, ������

		ET3D_Move                   = 3000,        // ƽ�� 
		ET3D_ScaleXYZ               = 3001,        // XYZ��������
		ET3D_ScaleXorY              = 3002,        // X��Y��������
		ET3D_RotateZ                = 3003,        // Z��Z��ת
		ET3D_ScaleZ                 = 3004,        // Z��������
		ET3D_ScaleX					= 3005,        // X��Y��������
		ET3D_ScaleY					= 3006,        // X��Y��������
		ET3D_ScaleXYZ_NWSE          = 3007,		   // XYZ��������,���������Ϸ���
		ET3D_ScaleXYZ_NESW			= 3008,		   // XYZ��������,�ض������Ϸ���

		ET3D_MoveZ                  = 3009,        // �߶�ƽ�� 
	};

	//�༭������ʽ
	enum EditAccessibilityAction
	{
		//��
		EAA_None,	
		//�༭�ڵ�
		EAA_EditPoint,			
		//��ӽڵ�
		EAA_AddPoint,
		//��
		EAA_RgnMode,			
		//��
		EAA_LineMode
	};

public:
	UGEditType3D();
	virtual ~UGEditType3D();
};

}

#endif // !defined(AFX_UGEDITTYPE3D_H__9969CA39_1F0D_4AD2_920F_E860971C502C__INCLUDED_)


