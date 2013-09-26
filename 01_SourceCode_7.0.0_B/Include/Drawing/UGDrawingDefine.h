// UGDrawSysDefine.h: interface for the UGDrawSysDefine class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGDRAWSYSTDEFINE_H
#define UGDRAWSYSTDEFINE_H

#include "Stream/ugdefs.h"
#include "Drawing/UGDrawingGeometry.h"

namespace UGC{

class DRAWING_API UGDrawingDefine  
{
public:
	UGDrawingDefine();

#ifdef SYMBIAN60
	~UGDrawingDefine();
#else
	virtual ~UGDrawingDefine();
#endif

public:
	//! \brief Drawing�������
	UGString m_strName;
	//! \brief Drawing������
	void* m_hHandle;
	//! \brief ���Ƽ��ζ���
	UGDrawingGeometry* m_pDrawingGeometry;

};

}

#endif // !defined(AFX_UGDRAWSYSDEFINE_H__387A69C7_04C4_4516_80FE_316ABB36ABFC__INCLUDED_)

