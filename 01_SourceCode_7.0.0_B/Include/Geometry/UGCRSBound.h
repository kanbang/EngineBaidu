// UGCRSBound.h: interface for the UGCRSBound class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGCRSBOUND__INCLUDED_)
#define AFX_UGCRSBOUND__INCLUDED_

#include "Stream/ugexports.h"
#include "Stream/ugdefs.h"

namespace UGC
{

//! \brief �ο�ϵ�����ṹ��
//! \remarks Webͼ�������ο�ϵ����������Χ��Ϣ
class  GEOMETRY_API UGCRSBound  
{
public:
	//! \brief ���캯��
	UGCRSBound();
	//! \brief ���캯��
	UGCRSBound(UGString strCRSName, UGRect2D rcBound);
	UGRect2D Transform(UGString strEPSGdst);
public:
	//! \brief ͼ�������ο�ϵ��
	UGString m_strCRSName;
	
	//! \brief ͼ���������Χ��
	UGRect2D m_rcBound;
	
	UGdouble m_Resx;
	UGdouble m_Resy;
};

//! \brief �ο�ϵ�������ϡ�
//! \remarks ���ڴ��һ��Webͼ���ж������ο�ϵ����������Χ��Ϣ�������
class GEOMETRY_API UGCRSBounds :public UGArray<UGCRSBound>
{
public:
	//! \brief ���캯��
	UGCRSBounds();
	//! \brief ���캯��
	UGCRSBounds(const UGCRSBounds& crsBounds);
	//! \brief ��������
#ifdef SYMBIAN60
	~UGCRSBounds();
#else
	virtual ~UGCRSBounds();
#endif

	
	
public:
	//! \brief operator=
	const UGCRSBounds& operator=(const UGCRSBounds& crsBounds);
	
	//! \brief GetIndexByName
	UGint GetIndexByName(const UGString& strCRSName);
	
	//! \brief GetIndexByName
	UGCRSBound* GetObjByName(const UGString& strCRSName);
};

}
#endif // !defined(AFX_UGCRSBOUND__INCLUDED_)

