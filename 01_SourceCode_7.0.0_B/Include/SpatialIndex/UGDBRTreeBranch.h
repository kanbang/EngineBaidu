 /*! \file UGDBRTreeBranch.h
 *  \brief R���ڲ������Ķ��塣
 *  \author ���䳬,�¿���
 *  \bug

 *	<b>����˵����</b>\n
	<em>1��2003-11-1 �״���ɴ����д.\n</em>
*/  
#ifndef _INC_UGDBRTreeBranch_3E9E4B130207_INCLUDED
#define _INC_UGDBRTreeBranch_3E9E4B130207_INCLUDED


#include "UGDBRTreeNode.h"

namespace UGC
{

//! \brief R���ڲ�����࣬����е�Ԫ�����������
//! \remarks ����UGDBRTreeNode
class  SPATIALINDEX_API UGDBRTreeBranch : public UGDBRTreeNode    
{	
public:
	//! \brief ����
	UGDBRTreeBranch();
	//! \brief ����
	virtual ~UGDBRTreeBranch();

public:

	//! \brief �ѽ������ݱ��浽�ڴ������С�
	//! \param arData ��������������顣
	//! \return �ɹ��򷵻�TRUE��
	virtual UGbool Store(UGStream &stream);

	//! \brief ���ڴ�����������������ݡ�
	//! \param arData �����Ž�����ݡ�
	//! \param nPos �������nPosλ�ÿ�ʼ��ȡ����
	//! \return  �ɹ��򷵻�TRUE��
	virtual UGbool Load(UGStream &stream);

	//! \brief �жϽ���Ƿ���Ҫ�ָ�
	//! \param nMaxEntryCount �������������Ԫ������
	//! \return ��Ҫ�ָ��TRUE�����򷵻�FALSE
	//! \remarks �����Ԫ�ش��������������Ҫ�ָ�
	virtual UGbool NeedSplit( UGint nMaxEntryCount );
	
	//! \brief ��ȡ�����Ԫ�ص�����
	//! \return �����Ԫ�ص�����
	virtual UGint GetEntryCount();

	//! \brief ��ȡ��������
	//! \return ��������
	//! \remarks ����ֵ��1
	virtual UGuchar GetType();

public:

	//! \brief ��ȡ�ӽ���ָ��
	//! \param nIndex �ӽ�������
	//! \return ָ���������ӽ��ָ��
	//! \remarks �ⲿ����ɾ�����ص�ָ��
	UGDBRTreeNode* GetChildAt( UGint nIndex );

	//! \brief ���һ���ӽ��
	//! \param pChildNode Ҫ��ӵ��ӽ��ָ��
	//! \return ��Ӻ��ӽ�������
	UGint AddChild( UGDBRTreeNode* pChildNode );

	//! \brief ��㷱��
	//! \param nMaxItemCount �������������Ԫ������
	//! \param pScanLines ɨ��������
	//! \return ���ܳɹ�����true�����򷵻�false
	UGbool Breed( UGint nMaxItemCount,DBScanLineInfo *pScanLines);

	//! \brief �����죬����µ�����������bud�Ľ���ݱ�Ϊleaf
	//! \return �ݱ�ɹ�����true�����򷵻�false
	UGbool GrowUp();

	//! \brief ��ȡ���ռ���ڴ���ֽ���
	//! \return ���ռ���ڴ���ֽ���
	//! \remarks �����������ӽ��ռ�õ��ڴ��ֽ���
	UGint GetDataSize();

	//! \brief �ڽ���²�ѯ, arIDs ��ѯ�Ľ��ID����
	//! \param rcBound ��ѯ�ķ�Χ
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


	//! \brief ��ȡ�ý���µ����ж����ID
	//! \param arIDs ���������ȡ����ID
	//! \return �ɹ��򷵻�TRUE��
	UGbool GetAllIDs( UGArray<UGint> &arIDs );

	//! \brief ��ȡ�ý���µ�����Ҷ�ڵ��ID
	//! \param arLeafIDs ���������ȡ����ID
	//! \return �ɹ��򷵻�TRUE��
	virtual UGbool GetAllLeafIDs( UGArray<UGint> &arLeafIDs );

	//! \brief ��ȡ�ý���µ�����Ҷ�ڵ��ID
	//! \param arLeafIDs ���������ȡ����ID
	//! \return �ɹ��򷵻�TRUE��
	virtual UGbool GetAllLeafIDs( UGArray<UGint> &arLeafIDs,
		UGArray<UGRectUInt> &aryLeafBounds,
		UGuint nGranule);

public:
	//! \brief ����ʹ�ã�ȡ��R������Ҷ�ӽڵ�ķ�Χ��
	void GetAllLeafBounds( UGArray<UGRectUInt> &arBounds );

	//! \brief ����ʹ�ã�ȡ��R������Ҷ�ӽڵ�ķ�Χ��
	UGbool GetLeafBounds( UGint nID,UGRectUInt &rcBounds);

	//! brief ��ȡ����Ҷ�ӽ���ָ��
	UGbool GetAllLeafs(UGArray<UGDBRTreeLeaf*> &aryLeafs);

protected:
	//! \brief �ӽ��ָ������
	UGArray<UGDBRTreeNode*> m_arChildren;

};

}

#endif /* _INC_UGDBRTreeBranch_3E9E4B130207_INCLUDED */

