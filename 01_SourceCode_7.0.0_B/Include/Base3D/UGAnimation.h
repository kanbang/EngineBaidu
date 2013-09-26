//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief 
//!  \details 
//!  \author zhangshuai��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
#if !defined(AFX_UGANIMATION_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_)
#define AFX_UGANIMATION_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGPrerequisites3D.h"
#include "Stream/UGStream.h"
namespace UGC
{

class BASE3D_API UGAnimation
{
public:
	UGAnimation();
	//! \brief ���캯��
	//! \param strAnimName ��������[in]��
	//! \param dTimePos ��ǰ������λ��[in]��
	//! \param dTimePos ��ǰ�����ĳ���[in]��
	//! \param dTimePos �Ƿ�������������ʼΪfalse������[in]��
	UGAnimation(const UGString& strAnimName,UGdouble dTimePos, UGdouble dLength,UGbool bEnabled = false);

	//! \brief �������캯��
	UGAnimation(const UGAnimation &rhs);

	//! \brief ��������
	virtual ~UGAnimation();

	//! \brief ����==
	UGbool operator==(const UGAnimation& rhs) const;
	
	//! \brief ����!=
	UGbool operator!=(const UGAnimation& rhs) const;

	//! \brief �����ļ��м���
	void Load(UGStream& fStream);

	//! \brief �������ļ���
	void Save(UGStream& fStream);

	//! \brief ��ý��Ĵ�С
	UGint GetDataSize() const;

public:
	//! \brief ��������
	const UGString& GetAnimationName() const;

	//! \brief ��ȡ����λ��
	UGdouble GetTimePosition(void) const;

	//! \brief ���ö���λ��
	//! \param dTimePos ��ǰ������λ��[in]��
	void SetTimePosition(UGdouble dTimePos);

	//! \brief ��ȡ��������
	UGdouble GetLength() const;

	//! \brief ���ö�������
	void SetLength(UGdouble dLen);

	//! \brief ���¶���λ�ã��ڵ�ǰλ���ϼ���dOffset
	//! \param dOffset ����ʱ�����ӵ�ֵ[in]��
	void Update(UGdouble dOffset);

	//! \brief ��ǰ�����Ƿ��ѽ�������loopΪtrue������ʼ��Ϊtrue
	UGbool HasEnded(void) const;

	//! \brief ��õ�ǰ�����Ƿ���õı�ʶ
	//! \return ��
	UGbool GetEnabled(void) const;

	//! \brief ���ö����Ƿ���õı�ʶ
	//! \param bEnabled ΪtrueΪ��ǰ��������[in]��
	//! \return ��
	void SetEnabled(UGbool bEnabled);

	//! \brief �����Ƿ�ѭ������
	//! \param bLoop ΪtrueΪѭ������[in]��
	//! \return ��
	void SetLoop(UGbool bLoop) { m_bLoop = bLoop; }

	//! \brief ��ȡѭ�����ű�ʶ
	//! \return
	UGbool GetLoop(void) const { return m_bLoop; }

	//! \brief �����Ƿ��Զ�����ʱ��
	void SetAutoUpdated(UGbool autoupdate);	

	//! \brief ����Ƿ��Զ����±�ʶ
	UGbool IsAutoUpdated(void) const;

	//! \brief ��ʼʱ��
	//! \param dStartTime ���ö�����ʼ���ŵ�ʱ��[in]��
	void SetStartTime(UGdouble dStartTime);

	//! \brief �����ʼ����ʱ��
	UGdouble GetStartTime(void);

	//! \brief ��ֹʱ��
	//! \param dEndTime ���ö����������ŵ�ʱ��[in]��
	void SetEndTime(UGdouble dEndTime);

	//! \brief �����ʼ����ʱ��
	UGdouble GetEndTime(void);

private:
	//! \brief ��������
	UGString m_strAnimationName;
	
	//! \brief ����λ��
	UGdouble m_dTimePos;

	//! \brief ��������
	UGdouble m_dLength;

	//! \brief �Ƿ����
	UGbool m_bEnabled;

	//! \brief �Ƿ�ѭ������
	UGbool m_bLoop;

	//! \brief �Ƿ��Զ�Update
	UGbool m_bAutoUpdate;

	//! \brief ��ʼʱ��
	UGdouble m_dStartTime;

	//! \brief ����ʱ��
	UGdouble m_dEndTime;
};
}
#endif // !defined(AFX_UGANIMATION_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_)

	
	
