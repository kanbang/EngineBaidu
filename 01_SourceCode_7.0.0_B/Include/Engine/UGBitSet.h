//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file  UGBitSet.h
//!  \brief UGBitSet
//!  \details ʹ��Bit��һ�����鲢ʵ����Ԫ�صļ�¼����Ϊ,����MoveNext,IsEof,GetRecordCount,SeekID��.
//!  \author wangmao��
//! Copyright (c) UGC, a staff of SuperMap Software Co., Ltd. 2008. All Rights Reserved. <br>
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
#ifndef UGUGBITSET_H
#define UGUGBITSET_H

#include "Stream/ugdefs.h"
namespace UGC
{
	
class ENGINE_API UGBitSet  
{
public:
	//! \brief ����
	UGBitSet(const UGint nSize, UGbool bOrdered = FALSE);
	//! \brief ����
#ifdef SYMBIAN60
	~UGBitSet();
#else
	virtual ~UGBitSet();
#endif
	
	//! \brief ��ֵ����
	const UGBitSet& operator=(const UGBitSet& cBitSet);
	//! \brief  ����ж� 
	UGbool operator==(const UGBitSet& cBitsetCmp) const;
	//! \����
	UGBitSet();

public:
	//! \brief �õ���¼��������
	//! \return ��¼����
	UGuint  GetRecordCount()const;

	//! \brief ���ü�¼��������
	//! \return ��¼����
	UGbool  SetRecordCount(UGint nRecordCount);

	//! \brief ����һ����¼��
	//! \param nID ��ӵ�ID[in]��
	//! \return ����Ƿ�ɹ���
	UGbool  AddReocrd(const UGuint nID);	

	//! \brief ɾ��һ����¼��
	//! \param nID Ҫɾ����ID[in]��
	//! \return ɾ���Ƿ�ɹ���
	UGbool  DeleteRecord(const UGint nID);	

	//! \brief �ƶ�����һ����¼��
	//! \return ��ǰ��ID����
	UGbool  MoveFirst();	

	//! \brief �ƶ�����һ����¼��
	//! \return ��ǰ��ID��
	UGbool  MoveNext(); 

	//! \brief �ƶ���ǰһ����¼��
	//! \return ��ǰ��ID��
	UGbool  MovePrev();
	
	//! \brief �ƶ������һ����¼��
	//! \return ��ǰ��ID��
	UGbool  MoveLast();

	//! \brief �ƶ�����ǰ��¼��nRowOffsetƫ��
	//! \return ��ǰ��ID��
	UGbool  Move(UGint nRowOffset);

	//! \brief �ƶ���ָ���ļ�¼λ�á�
	//! \param nRow �ڼ�����¼[in]��
	//! \remarks nRow = 0Ϊ�ƶ���First
	UGbool  MoveTo(UGint nRow);	

	//! \brief �õ���ǰID��
	//! \return ��ǰID��
	UGint  GetID() const;	

	//! \brief �ƶ���ָ��id�ļ�¼λ�á�
	//! \param nID ������ID[in]��
	//! \return �ƶ��Ƿ�ɹ���
	UGbool  SeekID(UGint nID);	

	//! \brief ����nID�Ƿ���������
	//! \param nID ��������Ҫ���Ե�ID[in]��
	//! \return ���ڷ���1�����ڷ���0
	UGuint  TestID(UGuint nID);	
	
	//! \brief �Ƿ��ǵ�һ����¼֮ǰ��
	UGbool  IsBOF() const;	
	
	//! \brief �Ƿ������һ����¼֮��
	UGbool  IsEOF() const;

	UGint GetCurrentIndex() const;

private:
	void   FindFirstBitInChar(UGuchar *pStart,UGbool bDir);
	//! \remarks �ڴ��bit����
	UGuint	m_nSize;
	
	//! \brief �ڴ濪ʼ��ָ��
        UGuchar *m_pByte;

	//! \brief ��ǰ������λ��
	UGint  m_CurrentIndex;

	//! \brief ��������λ��
	UGint  m_nMaxIndex;

	//! \brief ��С������λ��
	UGint  m_nMinIndex;

	//! \brief ��¼����
	UGuint m_nRecordCount;

	OgdcArray<UGint> m_arrOrderedIDs;

	UGbool m_bOrdered;

private:
	UGBitSet(const UGBitSet& bitset);
};

}
#endif // !defined(UGBITSET_H)

