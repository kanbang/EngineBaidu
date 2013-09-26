/**  \file UGWindowTypes3D.h
   \brief   �����봰�������������
   \auothor malq
   \attetion ���ǿ�ƽ̨����
   Copyright(c) 2000-2010  SuperMap GIS Technolgoies, Inc<br>
   All Rights Reserved
   \version 2.0
   <b>����˵����</b>\n
	<em>1����һ��˵����\n
	<em>2���ڶ���˵����\n
*/

#ifndef UG3DWINDOWTYPES_H
#define  UG3DWINDOWTYPES_H

//! \brief ����window��������
#ifdef WIN32
#include <WINDOWS.H>

namespace UGC
{
	//! \brief ����window�豸���
	typedef HDC Display3D;                      

	//! \brief ����window���ھ��
	typedef HWND Window3D;                      
	
	//! \brief ����OpenGL�����ľ��
	typedef HGLRC GLContext;                  
	
	//! \brief ���ظ�ʽ����
	typedef PIXELFORMATDESCRIPTOR VisualInfo;  
	
	//! \brief ����
	typedef HFONT Font3D;
}
#endif

//! \brief �����window����������
#if !defined WIN32 && !defined (IOS3D)
#include <GL/glx.h>  
namespace UGC
{
	//! \brief �����豸���
	typedef ::Display* Display3D;             
	//! \brief ���崰�ھ��
	typedef ::Window   Window3D;                  
	//! \brief ����OpenGL�����ľ��
	typedef GLXContext GLContext;              
	//! \brief ����������ʽ
	typedef XVisualInfo* VisualInfo;            
}
#endif

#if defined IOS3D
namespace UGC
{
	//! \brief �����豸���
	typedef UGlong Display3D;             
	//! \brief ���崰�ھ��
	typedef UGlong   Window3D;                             
}
#endif

#endif

