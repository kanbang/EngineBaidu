// UGMapCacheState.h: interface for the UGMapCacheState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMAPCACHESTATE_H__658CE52F_FD8E_430D_B5E0_DAC4EAF29F51__INCLUDED_)
#define AFX_UGMAPCACHESTATE_H__658CE52F_FD8E_430D_B5E0_DAC4EAF29F51__INCLUDED_

#include "Stream/ugdefs.h"

namespace UGC
{

class CACHEFILE_API UGMapCacheState  
{
public:
	UGMapCacheState();
	~UGMapCacheState();
	
	//! \brief �����ִ�ͼƬ����
	void UpdateExistImageCount();

	//! \brief ��ȡ��ǰ����״̬��ʼʱ��
	void StartTime();

	//! \brief ��ȡ��ǰ����״̬����ʱ��
	void EndTime();

	//! \brief ��ǰ�����ͼ�ı�����
	UGdouble m_dScale;

	//! \brief caption
	UGString m_strCaption;

	//! \brief ǰ�����ߵĻ���ͼƬ����������Ǹ��ݵ�ͼ���������Χ�͵���ͼƬ����Χ������ġ�
	UGint m_nImageCount;

	//! \brief ��ǰ�����ߵĻ���ʵ�ʴ��ڵĻ���ͼƬ�����������������Ҫ���ɵĻ���ͼƬ��ȥ�����ݵ�ͼƬ������Щ�뵱ǰ��ͼ��Χ���ü���Χû�н�����ͼƬ����Ŀ��
	UGint m_nExistImageCount;

	//! \brief ��ǰ����״̬��HashCode
	UGString m_strHashCode;

	//! \brief ���濪ʼʱ��
	UGTime m_startTime;

	//! \brief �������ʱ��
	UGTime m_endTime;

	////! \brief ��δ����ͼƬ����
	//UGint m_nNotImageCount;


	// UGC �������ר��
	//int m_nXLevel;
	//int m_nYLevel;


};

}

#endif // !defined(AFX_UGMAPCACHESTATE_H__658CE52F_FD8E_430D_B5E0_DAC4EAF29F51__INCLUDED_)

