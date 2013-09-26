//=====================================================================================
// ��Ŀ����			SuperMap Foundation Class (SFC) Library 2.0
// ��  �ߣ�			���ܿ�
// ��  λ��			������ͼ����ɷ����޹�˾
// ����޸�ʱ�䣺	2004-4-7
//-------------------------------------------------------------------------------------
// ��Ҫ������		1. ���ʹ�÷�ΧΪSuperMap GIS����������Ա��δ����ɲ������Դ�����
//					2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
//					
//-------------------------------------------------------------------------------------
// �ļ�����			TLQuadTree.h
// ��  ����			UGTLQuadTree (Three Level Quad Tree)
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		 �����й��Ĳ����������ࡣ
// ����˵����		
//					
//					
//------------------------------------------------------------------------------------------------
//! �޸�˵��: by zengzm 2007-4-10 ���ע��, ��������, �����BigEndian�ϵ�����

#if !defined(AFX_UGTLQUADTREE_H__8AE407D7_0CC9_40A3_B2D8_21C73CEA7276__INCLUDED_)
#define AFX_UGTLQUADTREE_H__8AE407D7_0CC9_40A3_B2D8_21C73CEA7276__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugdefs.h"
#include "Base/OgdcRect2D.h"
#include "Base/OgdcString.h"

namespace UGC
{

// �ú�ŵ�cpp��,ֻ��cpp�вŻ��õ�
// #define MacroForGetXEveryBit(x,y)


//! \brief �Ĳ����ࡣ
class SPATIALINDEX_API UGTLQuadTree  
{
	union unPosition
	{
		UGushort s;
		struct
		{
			unsigned a1:1;
			unsigned a2:1;
			unsigned a3:1;
			unsigned a4:1;
			unsigned a5:1;
			unsigned a6:1;
			unsigned a7:1;
			unsigned a8:1;
			unsigned a9:1;
			unsigned a10:1;
			unsigned a11:1;
			unsigned a12:1;
			unsigned a13:1;
			unsigned a14:1;
			unsigned a15:1;
			unsigned a16:1;
		} a;
	};

public:
	//! \brief Ĭ�Ϲ��캯��
	UGTLQuadTree();
	//! \brief ��������
	virtual ~UGTLQuadTree();
	
	//! \brief ������Ҫ���ӵĲ���
	void SetLevel(UGshort nLevel);
	//! \brief ������Ҫ����ӵ�Bounds
	void SetEntireBounds(UGRect2D rc2EntireBounds);
	//! \brief ͬʱ���ø��ӵĲ�����Bounds
	void SetEntireBounds(UGRect2D rc2EntireBounds,UGshort nLevel);

	//! \brief ͨ����Ҫ��ѯ��bounds���õ� sql���
	UGString BuildQdTreeSQL(UGRect2D rc2QueryBounds);

	//! \brief �õ����� ��װ(envelop) ĳ������Χ �� ��С����(��β���) �ı���
	UGint GetKeyByBounds(UGRect2D &rc2ObjBounds);
	//! \brief �õ����� ��װ(envelop) ĳ������Χ �� ��С����(��β���) �ı���
	UGint GetKeyByBounds(UGRect2D *prc2ObjBounds);

	//! \brief 
	UGint GetKeyByWNES(UGdouble dLeft,UGdouble dTop,UGdouble dRight,UGdouble dBottom);
	//! \brief �õ�ָ�����,ָ�� ���еĸ��� �ı���(����level��6λ)
	UGint GetPointKeyByPosition(UGint nX,UGint nY,UGshort nLevel);
	//! \brief �õ� ���Է�װ(envelop) ����ĸ��ӣ�X1 Y1��X2 Y2���� ��С�ĸ��ӣ���β������ı���
	UGint GetKeyByPosition(UGint nX1,UGint nY1,UGint nX2,UGint nY2);
	//! \brief ���ݱ���õ���Ӧ��Bounds
	UGbool GetBoundsByKey(UGint nKey,UGRect2D & rc2Bounds);
	//! \brief �ж���������(key)����Ӧ��Bounds�Ƿ��н���
	UGbool Intersect(UGint nKey1,UGint nKey2);

private:
	//! \brief ��Ҫ����������bounds
	UGRect2D m_rc2EntireBounds;
	//! \brief bounds��left
	UGdouble m_dLeft;
	//! \brief bounds ��bottom
	UGdouble m_dBottom;
	//! \brief bounds��width
	UGdouble m_dWidth;
	//! \brief bounds��height
	UGdouble m_dHeight;
	//! \brief һ���ֵĲ����Ŀ
	UGshort m_nTotalLevel;
	//! \brief ��ǰ���ڴ���Ĳ��
	UGshort m_nCurLevel;
	//! \brief ��ǰ��Σ�һ�������������ˮƽ�������
	UGdouble m_dHOffset;
	//! \brief ��ǰ��Σ�һ������������Ĵ�ֱ�������
	UGdouble m_dVOffset;
	//! \brief �õ�ĳһ��� ���ӣ�X��Y�� �� ����(����level��6λ)
	UGint GetPointKeyByPosition(unPosition X,unPosition Y,UGshort nLevel);
	//! \brief �õ� ���Է�װ(envelop) ����ĸ��ӣ�X1 Y1��X2 Y2���� ��С�ĸ��ӣ���β������ı���
	UGint GetKeyByPosition(unPosition X1,unPosition Y1,unPosition X2,unPosition Y2);
	//! \brief �ڲ��ȽϺ���
	static UGint S_compare_ids (const void  *id_ptr_1,const void  *id_ptr_2);

};

}
#endif // !defined(AFX_QUADTREE_H__8AE407D7_0CC9_40A3_B2D8_21C73CEA7276__INCLUDED_)

