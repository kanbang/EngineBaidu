//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGAutoRecordsetPtr.h
//!  \brief ��¼������ָ��Ľӿڶ��塣
//!  \details �����Ǽ�¼��������ָ�룬��ƴ����Ŀ����Ϊ�˽���ڽϳ�����ò�κܶ�Ĵ�������Recordset�����ͷŵ����⡣
//!  \author UGC �ռ����ݿ⿪���顣
//!  \attention ��ѯ����Recordsetָ���������㲻���ڴ����������ReleaseRecordset���ͷţ�����ᵼ��Ұָ�뼰���������
//!   Copyright (c) 1996-2008 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGAUTORECORDSETPTR_H__95A0DF3C_2075_4FDF_B09D_6EF13036A322__INCLUDED_)
#define AFX_UGAUTORECORDSETPTR_H__95A0DF3C_2075_4FDF_B09D_6EF13036A322__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Engine/UGRecordset.h"

namespace UGC
{
	
	//! \brief ��¼���������ָ�룬���������������Զ���¼������
	//! \remarks ��¼����ָ��һ���������������㲻���������ͷţ�ֻ�ܵ��ñ����Release���ͷ�
//##ModelId=483BB70C033C
	class  ENGINE_API UGAutoRecordsetPtr  
	{
	private:
		//! \brief ��ֹ�������캯��
	//##ModelId=483BB70C033D
		UGAutoRecordsetPtr(const UGAutoRecordsetPtr& autoPtr);

		//! \brief ��ֹ��ֵ����
	//##ModelId=483BB70C034C
		void operator=(const UGAutoRecordsetPtr& autoPtr);

	public:

		//! \brief ��ȡ��¼��ָ�롣
	//##ModelId=483BB70C034E
		UGRecordset * GetRecordsetPtr() const ;		

		//! \brief ���ü�¼��ָ��
	//##ModelId=483BB70C0350
		void SetRecordsetPtr(UGRecordset *pRs, UGbool bAutoDelete = TRUE);

		//! \brief �ͷż�¼�����󣬰���deleteָ�뼰��ָ�븳ΪNULL
	//##ModelId=483BB70C0353
		void Release();

		//! \brief Ĭ�Ϲ��캯��
	//##ModelId=483BB70C0354
		UGAutoRecordsetPtr();

		//! \brief Ĭ����������
	//##ModelId=483BB70C035B
		virtual ~UGAutoRecordsetPtr();

	private:
		//! \brief ��¼��ָ��
	//##ModelId=483BB70C035E
		UGRecordset * m_pRecordset;

		//! \brief ��¼��ָ���Ƿ��Զ��ͷ�
	//##ModelId=483BB70C0362
		UGbool m_bAutoDelete;
	};
}


#endif // !defined(AFX_UGAUTORECORDSETPTR_H__95A0DF3C_2075_4FDF_B09D_6EF13036A322__INCLUDED_)

