/* 
	\file UGSet.h
	\brief ������,��֤�������Ԫ�ض���һ��,������ͬ��stl�е�set��
	\author zengzm
	\attention
	Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/
	// UGSet.h: interface for the UGSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSET_H__61360F7F_9E23_4E6C_8B5F_BF3473B8A87F__INCLUDED_)
#define AFX_UGSET_H__61360F7F_9E23_4E6C_8B5F_BF3473B8A87F__INCLUDED_

#include "ugdefs.h"

namespace UGC {

//! \brief ������,��֤�������Ԫ�ض���һ��,������ͬ��stl�е�set
//! \remarks �ڲ�����setʵ��
//! \attention ��ʱ���ò��������, �ݲ�ʵ��, ��Ҫʱ�����㹻��Դʱ����
template<typename T>
class UGEXPORT UGSet  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGSet();

	//! \brief ������������һ��Ԫ��
	//! \return �����Ƿ�ɹ�����, �����Ԫ���Ѿ��ڼ����д���,�����ʧ��
	UGbool Add(const T& value);

	//! \brief �ڼ����в���ĳԪ���Ƿ����
	//! \return ���ڷ���true,�����ڷ���false
	UGbool Find(const T& value);

	//! \brief �õ�������Ԫ�صĸ���
	UGint GetSize();

	//! \brief �Ӽ������Ƴ�ĳԪ��
	//! \return �ɹ�����true;ʧ�ܷ���false,�����Ԫ�ز�����
	UGbool Remove(const T& value);

	//! \brief �����������
	void RemoveAll();

	// �ͼ�����صļ�����̬����

	  //!  \brief Toolkit
	static Union();
	//static 

private:
	std::set<T> m_set;
};

#endif // !defined(AFX_UGSET_H__61360F7F_9E23_4E6C_8B5F_BF3473B8A87F__INCLUDED_)

