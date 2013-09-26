/*! \file	 UGException.h
 *  \brief	 �쳣������
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
 *  All Rights Reserved
 *  \version $Id: UGException.h,v 1.4 2009/11/05 09:36:46 siyh Exp $
 */

#ifndef UGEXCEPTION_H
#define UGEXCEPTION_H

#include "Stream/ugdefs.h"
#include "UGErrorObj.h"

namespace UGC {

//! \brief �쳣���࣬UGC���Զ���������쳣�࣬Ӧ�ô�UGException�̳�
class TOOLKIT_API UGException  
{
public:

	//! \brief ���캯����
	//! \param nErrorID [in] ������Ϣ���ַ�����ԴID��
	//! \param strMessage [in] ��Ϣ�ַ�����
	//! \param strCodeFile [in] �쳣�����Ĵ����ļ���
	//! \param nCodeLine [in] �쳣�����Ĵ����С�
	UGException(UGuint nErrorID,
		const UGString& strMessage,
		const UGString& strCodeFile,
		UGint nCodeLine);
	
	//! \brief ���캯����
	//! \param strErrorID [in] ������Ϣ���ַ�����ԴID��
	//! \param strMessage [in] ��Ϣ�ַ�����
	//! \param strCodeFile [in] �쳣�����Ĵ����ļ���
	//! \param nCodeLine [in] �쳣�����Ĵ����С�
	UGException(const UGString& strErrorID,
		const UGString& strMessage,
		const UGString& strCodeFile,
		UGint nCodeLine);
	
	//! \brief ���캯����
	//! \param nErrorID [in] ������Ϣ���ַ�����ԴID��
	//! \param strCodeFile [in] �쳣�����Ĵ����ļ���
	//! \param nCodeLine [in] �쳣�����Ĵ����С�
	UGException(UGuint nErrorID,
		const UGString& strCodeFile,
		UGint nCodeLine);

	//! \brief ���캯����
	//! \param strErrorID [in] ������Ϣ���ַ�����ԴID��
	//! \param strCodeFile [in] �쳣�����Ĵ����ļ���
	//! \param nCodeLine [in] �쳣�����Ĵ����С�
	UGException(const UGString& strErrorID,
		const UGString& strCodeFile,
		UGint nCodeLine);

	//! \brief ���쳣������д�뵽��־�С�
	//! \remarks �쳣�Ĺ��캯���У�����ñ�������
	virtual void WriteToLog();	

	//! \brief �õ��ڲ�ά���Ĵ�����Ϣ�ṹ��
	//! \return �����ڲ�ά���Ĵ�����Ϣ�ṹ��
	const UGErrorObj::ErrorInfo& GetErrorInfo() const;	


private:
	//! \brief �ڲ�ά���Ĵ�����Ϣ�ṹ
	UGErrorObj::ErrorInfo m_ErrorInfo;
};

}

#endif



