// UGStyle3D.h: interface for the UGStyle3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTEXTSTYLE3D_H__7978B585_8964_4C91_99FE_FDE3F6A104BD__INCLUDED_)
#define AFX_UGTEXTSTYLE3D_H__7978B585_8964_4C91_99FE_FDE3F6A104BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGColorValue3D.h"
#include "Base3D/UGTextureData.h"
#include "Stream/UGStream.h"

//3d���ֵ�����
namespace UGC
{

class BASE3D_API UGTextStyle3D  
{
public:
	UGTextStyle3D();
	UGTextStyle3D(const UGTextStyle3D& textStyle);
	virtual ~UGTextStyle3D();
	
	void operator=(const UGTextStyle3D& textStyle);
	UGbool operator==(const UGTextStyle3D& textStyle) const;
	UGbool operator!=(const UGTextStyle3D& textStyle) const;
	
	//! \brief �洢��Stream��
	UGbool SaveToStream(UGStream& stream, UGuint nVersion = 0) const;
	
	//! \brief ��Stream������
	UGbool LoadFromStream( UGStream& stream , UGuint nVersion = 0);

	//! \brief �õ����뷽ʽ
	UGbyte GetAlign() const;				
	//! \brief ���ö��뷽ʽ
	void SetAlign(UGbyte nAlign = 0);	
	
	//! \brief �õ������ȣ�
	UGdouble GetWidth() const;
	//! \brief ���������ȣ�
	void SetWidth(UGdouble dWidth);
	
	//! \brief �õ�����߶ȣ�
	UGdouble GetHeight() const;
	//! \brief ��������߶ȣ�
	void SetHeight(UGdouble dHeight);
	//! \brief �õ���������		
	UGString GetFaceName() const;
	//! \brief ������������
	void SetFaceName(const UGString& strFaceName);

public:	
	//! \brief �������ɫ
	UGColorValue3D m_ColorFill;
	//! \brief ���ű���
	UGdouble m_dScale;

// Ŀǰû������
private:	
	UGdouble			m_dWidth;				//! �����ȣ�����λ
	UGdouble			m_dHeight;				//! ����߶ȣ�����λ
	UGint				m_nStyle;				//! ���:���壬б�壬͸��������,���е�	
	UGColorValue3D		m_ForeColor;			//! ������ɫ
	UGColorValue3D		m_BackColor;			//! ����ɫ����Ӱɫ�����ɫ
	UGString			m_strFaceName;			//! ��������


};

}

#endif // !defined(AFX_UGTEXTSTYLE3D_H__7978B585_8964_4C91_99FE_FDE3F6A104BD__INCLUDED_)

