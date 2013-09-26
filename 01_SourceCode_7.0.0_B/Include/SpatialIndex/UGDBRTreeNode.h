/*! \file UGDBRTreeNode.h
 *  \brief R�����������Լ�������͵Ķ��塣
 *  \author ���䳬,�¿���
 *  \bug

 *	<b>����˵����</b>\n
	<em>1��2003-11-1 �״���ɴ����д.\n</em>
*/  
#ifndef _INC_UGDBRTREENODE_3E9E4B130201_INCLUDED
#define _INC_UGDBRTREENODE_3E9E4B130201_INCLUDED
#include "Stream/ugdefs.h"
#include "Stream/UGStream.h"
#include "Toolkit/UGRectUInt.h"
#include "Base/OgdcRect2D.h"
#include "Base/OgdcArray.h"

namespace UGC
{
#ifndef SM_DWORD_GRIDS
#define SM_DWORD_GRIDS 4294967295
#endif

//class UGLongArray;

//! \brief ����R������Ҫ������Ԫ�صĽṹ
class  SPATIALINDEX_API UGDBRTreeNodeItem
{
public:
	//! \brief �����ID
	UGint m_nID ;

	//! \brief ����ķ�Χ
	UGuint m_rcLeft;
	UGuint m_rcTop;
	UGuint m_rcRight;
	UGuint m_rcBottom;
public:
	//! \brief �õ�����ķ�Χ
	UGRectUInt GetBound(){return UGRectUInt(m_rcLeft,m_rcTop,m_rcRight,m_rcBottom);}

	//! \brief �ѽ������ݱ��浽�ڴ������С�
	//! \param arData ��������������顣
	//! \return �ɹ��򷵻�TRUE��
	virtual UGbool Store(UGStream &stream);

	//! \brief ���ڴ�����������������ݡ�
	//! \param arData �����Ž�����ݡ�
	//! \return  �ɹ��򷵻�TRUE��
	virtual UGbool Load(UGStream &stream);
};

class SPATIALINDEX_API UGDBRTreeNodeItems
{
public:
	//! \brief �õ�Ҷ�ӽ��ĸ���
	UGint GetSize();
	//! \brief �ѽ������ݱ��浽�ڴ������С�
	//! \param arData ��������������顣
	//! \return �ɹ��򷵻�TRUE��
	virtual UGbool Store(UGStream &stream);

	//! \brief ���ڴ�����������������ݡ�
	//! \param arData �����Ž�����ݡ�
	//! \return  �ɹ��򷵻�TRUE��
	virtual UGbool Load(UGStream &stream);

	//! \brief ��Ҷ�ӽ���������
	UGbool Sort();
public:
	UGArray<UGDBRTreeNodeItem> m_aryDBRTreeNodeItems;
};

//! \brief ����R������Ҫ������Ԫ�صĽṹ
class  SPATIALINDEX_API UGDBRTreeOutNodeItem
{
public:
	//! \brief �����ID
	UGint m_nID ;
	//! \brief ����ķ�Χ
	UGRect2D m_rc2Bound;
public:
	//! \brief �ѽ������ݱ��浽�ڴ������С�
	//! \param arData ��������������顣
	//! \return �ɹ��򷵻�TRUE��
	virtual UGbool Store(UGStream &stream);

	//! \brief ���ڴ�����������������ݡ�
	//! \param arData �����Ž�����ݡ�
	//! \return  �ɹ��򷵻�TRUE��
	virtual UGbool Load(UGStream &stream);


};

typedef UGArray<UGDBRTreeOutNodeItem> UGDBRTreeOutNodeItems;



//! \brief ����R���Ĺ����У��ָ��ߵ����ݽṹ
typedef struct tagDBScanLineInfo	
{
	//! \brief ����
	tagDBScanLineInfo()
	{
		ub8Area = 0;
		nNewCount = 0;
		nOldCount = 0;				
	}
	//! \brief �ָ��ߴ��������ж�������ܺ�
	UGulong ub8Area;
	
	//! \brief �ָ����ұ߻����ϱߵĶ��������
	UGint nNewCount;
	
	//! \brief �ָ�����߻����±ߵĶ��������
	UGint nOldCount;
}DBScanLineInfo;
 
//! \brief R����������
//! \remarks UGDBRTreeBranch��UGDBRTreeLeaf��UGDBRTreeBud�ĸ���
class SPATIALINDEX_API  UGDBRTreeNode 
{
public:
	//! \brief ����
	UGDBRTreeNode();
	//! \brief ����
	virtual ~UGDBRTreeNode();

public:
	//! \brief ��ȡ�����Ԫ�ص�����
	//! \return �����Ԫ�ص�����
	//! \remarks ���麯����������ʵ��
	virtual UGint GetEntryCount() = 0;

	//! \brief ��ȡ��������
	//! \return �������� 0�� bud��1�� branch��2�� leaf
	//! \remarks ���麯����������ʵ��
	virtual UGuchar GetType() = 0;
	
	//! \brief ��ȡ���ռ���ڴ���ֽ���
	//! \return ���ռ���ڴ���ֽ���
	//! \remarks ���麯����������ʵ��
	//! \remarks �����������ӽ��ռ�õ��ڴ��ֽ���
	virtual UGint GetDataSize() = 0;
	
	//! \brief �ѽ������ݱ��浽�ڴ������С�
	//! \param arData ��������������顣
	//! \return �ɹ��򷵻�TRUE��
	virtual UGbool Store(UGStream &stream);

	//! \brief ���ڴ�����������������ݡ�
	//! \param arData �����Ž�����ݡ�
	//! \return  �ɹ��򷵻�TRUE��
	virtual UGbool Load(UGStream &stream);

	//! \brief ��ȡ�ý���µ����ж����ID
	//! \param arIDs ���������ȡ����ID
	//! \return �ɹ��򷵻�TRUE��
	virtual UGbool GetAllIDs( UGArray<UGint> &arIDs );

	//! \brief ��ȡ�ý���µ�����Ҷ�ڵ��ID
	//! \return �ɹ��򷵻�TRUE��
	virtual UGbool GetAllLeafIDs( UGArray<UGint> &/*arLeafIDs*/ ){return FALSE;};



	//! \brief ��ѯ�ý��
	//! \param rcBound ��ѯ�ķ�Χ
	//! \param arIDs ��ѯ�Ľ��ID����
	//! \return  ��ѯ���Ķ��������
	virtual UGbool Query(const UGRectUInt& rcBound, 
					   UGArray<UGint> &arCertainLeafIDs,
					   UGArray<UGint> &arMaybeLeafIDs);
	//! \brief ��ѯ�ý�㡣
	//! \param rcBound ��ѯ�ķ�Χ[in]��
	//! \param &arCertainLeafIDs ��ѯ�ľ�ȷ���ID����[in]��
	//! \param &aryCertainBounds ��ѯ�ľ�ȷ���ID����ķ�Χ[in]��
	//! \param &arMaybeLeafIDs ��ѯ�Ŀ��ܽ��ID����[in]��
	//! \param &aryMaybeBounds ��ѯ�Ŀ��ܽ��ID����ķ�Χ[in]��
	//! \param nGranule ����[in]��
	//! \return ��ѯ�Ƿ�ɹ���
	virtual UGbool Query(const UGRectUInt& rcBound, 
						UGArray<UGint> &arCertainLeafIDs,
						UGArray<UGRectUInt> &aryCertainBounds,
						UGArray<UGint> &arMaybeLeafIDs,
						UGArray<UGRectUInt> &aryMaybeBounds,
						UGuint nGranule);

	//! \brief ��ѯ�ý�㡣��
	//! \param rcBound ��ѯ�ķ�Χ[in]��
	//! \param rcReferenceBound ��ѯ�Ĳο���Χ[in]��
	//! \param bFuzzy �Ƿ�ʱģ����ѯ[in]��
	//! \param nGranule ����[in]��
	//! \param &aryItemIDs [in]��
	//! \param &arCertainLeafIDs [in]��
	//! \param &arMaybeLeafIDs [in]��
	//! \return ��ѯ�Ƿ�ɹ���
		virtual UGbool Query(const UGRectUInt& rcBound,
						const UGRectUInt& rcReferenceBound,
						UGbool bFuzzy,
						UGuint nGranule,
						UGArray<UGint> &aryItemIDs,
						UGArray<UGint> &arCertainLeafIDs,
						UGArray<UGint> &arMaybeLeafIDs);

	//! \brief ��ѯ������rcBound,������aryLeafIDs�е�ID��
	//! \param rcBound �����ķ�Χ[in]��
	//! \param aryLeafIDs ������ID����[in]��
	//! \return ��ѯ�Ƿ�ɹ���
	virtual UGbool QueryContainedByLeafID(const UGRectUInt& rcBound,UGArray<UGint> & aryLeafIDs);


	//! \brief �жϽ���Ƿ���Ҫ�ָ�
	//! \param nMaxEntryCount �������������Ԫ������
	//! \return ��Ҫ�ָ��TRUE�����򷵻�FALSE
	//! \remarks �����Ԫ�ش��������������Ҫ�ָ�
	virtual UGbool NeedSplit( UGint nMaxEntryCount );

	//! \brief �ָ���
	//! \param nMaxItemCount �������������Ԫ������
	//! \param pScanLines ɨ��������
	//! \return �ָ�������µĽ��
	virtual UGDBRTreeNode* Split( UGint nMaxItemCount,DBScanLineInfo *pScanLines);
		
	//! \brief �ָ���
	//! \param nMaxItemCount �������������Ԫ������
	//! \return �ָ�������µĽ��
	virtual UGDBRTreeNode* Split( UGint nMaxItemCount );
public:
	//! \brief ��ȡ���ķ�Χ
	//! \return ���ķ�Χ
	UGRectUInt GetBound() const
	{
		return m_rcBound;
	}

	//! \brief ���ý��ķ�Χ
	//! \param ���ķ�Χ
	void SetBound(const UGRectUInt& rcBound)
	{
		m_rcBound = rcBound;
	}

protected:
	//! \brief ���ķ�Χ
	UGRectUInt m_rcBound;
};

}

#endif /* _INC_UGDBRTREENODE_3E9E4B130201_INCLUDED */

