/*! \file UGDBRTree.h
 *  \brief R����Ķ���.
 *  \author ���䳬,�¿���
 *  \bug

 *	<b>����˵����</b>\n
	<em>1��2003-11-1 �״���ɴ����д.\n</em>
*/   

#ifndef _INC_UGDBRTREE_3E9E4B130220_INCLUDED
#define _INC_UGDBRTREE_3E9E4B130220_INCLUDED

#include "Stream/ugdefs.h"
#include "UGDBRTreeNode.h"
//#include "Engine/UGDatasetVector.h"

#define SM_QUAD_KEY_START		0
#define SM_QUAD_KEY_END			255
#define SM_GRID_KEY_START		256
#define SM_GRID_KEY_END			267
#define SM_RTREE_KEY_START		512
#define SM_INVALID_KEY			-1
#define SM_DEFAULT_KEY			-2


struct UGRTreeQuery{

};


namespace UGC{

class UGDBRTreeBranch;
class UGDBRTreeLeaf;
	
//!	\brief	UGDBRTree���ṩR���Ĵ���,��ѯ,����,��ȡ�ȹ��ܡ�
//! \remarks	R����ʵ�ַ����봫ͳ��R���кܴ�ͬ,�ڵ�Ļ��ָ��Ӻ���
class SPATIALINDEX_API UGDBRTree 
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGDBRTree();
	//! \brief Ĭ����������
	virtual ~UGDBRTree();

public: 
	//! \brief �õ���һ��Ҷ�ӽ���id
	UGint GetNextLeafID();
//	UGDatasetVector * GetVector();
//	void SetVector(UGDatasetVector * pVector);
	
	//! \brief ����һ��R��
	//! \param pItems ��������R�������ж����Bound��ID�����顣
	//! \param rc2Bounds ���ж���Χ��
	//! \param nQuality R����������ȡֵ��Χ[1,10],ֵԽС��R������Խ�ߣ�����ʱ��ҲԽ����
	//! \return �����ɹ�����TRUE,���򷵻�FALSE.
	//! \remarks ������������Ժ������µ�R��ǰ����ɾ��ԭ����R��
	UGbool Create( UGDBRTreeNodeItems* pItems,const UGRect2D& rc2Bounds, UGuint nQuality = 5, UGbool bPointDataset = false );

	//! \brief ����һ��R��
	//! \param pItems ��������R�������ж����Bound��ID������
	//! \param rc2Bounds ���ж���Χ
	//! \param bPointDataset  
	//! \return 
	//! \remarks �˷���Ŀ���Ǵ���һ��������������R ��������ٶȡ���������
	//! \attention 
	UGbool Create2( UGDBRTreeNodeItems* pItems,const UGRect2D& rc2Bounds,
		UGbool bIsPntDT, UGuint nQuality = 5 );	

	//! \brief ɾ��R���е�һ������
	//! \param UGRectUInt ����ķ�Χ
	//! \param nID �����ID
	UGbool Delete(const UGRectUInt& rcBounds,UGint nID);

	//! \brief ����R�����ͷ�ռ�õ��ڴ档
	void Destroy();
	
	//! \brief ��R���в�ѯ
	//! \param rcBound ��ѯ�ķ�Χ
	//! \param arIDs ��ѯ�Ľ��ID����
	//! \return  ��ѯ���Ķ��������
	UGint Query(const UGRect2D& rcBound, 
			   UGRectUInt & rcDWBound,
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
	UGint Query(const UGRect2D& rcBound, 
			   UGRectUInt & rcDWBound,
			   UGArray<UGint> &arCertainLeafIDs,
			   UGArray<UGRectUInt> &aryCertainBounds,
			   UGArray<UGint> &arMaybeLeafIDs,
			   UGArray<UGRectUInt> &aryMaybeBounds,
			   UGdouble dGranule);

	//! \brief ��ѯ�ý�㡣��
	//! \param rcBound ��ѯ�ķ�Χ[in]��
	//! \param rcReferenceBound ��ѯ�Ĳο���Χ[in]��
	//! \param bFuzzy �Ƿ�ʱģ����ѯ[in]��
	//! \param nGranule ����[in]��
	//! \param &aryItemIDs [in]��
	//! \param &arCertainLeafIDs [in]��
	//! \param &arMaybeLeafIDs [in]��
	//! \return ��ѯ�Ƿ�ɹ���
	UGint Query(const UGRect2D& SearchBounds,
				const UGRect2D& rcReferenceBounds,
				UGbool bFuzzy,
				UGdouble dGranule,
				UGArray<UGint> &aryItemIDs);

	//! \brief ��ѯ������rcBound,������aryLeafIDs�е�ID��
	//! \param rcBound �����ķ�Χ[in]��
	//! \param aryLeafIDs ������ID����[in]��
	//! \return ��ѯ�Ƿ�ɹ���
	UGint QueryContainedByLeafID(const UGRect2D& rc2Bounds,UGArray<UGint> & aryLeafIDs);

	//! \brief �õ�R���ķ�Χ
	//! \return  R�������ķ�Χ
	UGRect2D GetBound();

	//! \brief �õ�R��ռ���ڴ�Ĵ�С
	//! \return  R��ռ���ڴ�����������ֽ�Ϊ��λ��
	UGint GetDataSize();

	//! \brief ���ڴ�����������R�����ݲ�����R����
	//! \param arData R�����ݡ�
	//! \return  �ɹ��򷵻�TRUE��
	UGbool Load(UGStream &stream);

	//! \brief ��R�����ݱ��浽�ڴ������С�
	//! \param arData ��������R�������顣
	//! \return  �ɹ��򷵻�TRUE��
	UGbool Store(UGStream &stream);

	//! \brief ����ʹ�ã�ȡ��R������Ҷ�ӽڵ�ķ�Χ��
	void GetAllLeafBounds( UGArray<UGRectUInt> &arBounds );
	
	//! \brief ����ʹ�ã�ȡ��R������Ҷ�ӽڵ�ķ�Χ��
	void GetAllLeafBounds2( UGArray<UGRectUInt> &arBounds );

	//! \brief �õ�Ҷ�ӽ��ķ�Χ
	UGbool GetLeafBounds( UGint nID,UGRectUInt &rcBounds);

	//! \brief �õ����е�Ҷ�ӽ��
	UGbool GetAllLeafs(UGArray<UGDBRTreeLeaf*> &aryLeafs);

public:
	//! \brief R��ָ��
	static UGDBRTree * m_pTree;

protected:
	//! \brief ƽ��R��
	//! \param pItems [in]��
	//! \param rc2Bounds [in]��
	//! \param false [in]��
	//! \return ��
	//! \remarks �����������ṹ���ع�R��
	//! \attention ��
	UGbool BalanceRTree(UGDBRTreeNodeItems* pItems,const UGRect2D& rc2Bounds,UGbool bPointDataset = false);	

	//! \brief	R���ĸ���㣬������ͨ�Ķ���
	UGDBRTreeBranch* m_pRootNormal;
	//! \brief	R���ĸ���㣬����ϴ�Ķ���
	UGDBRTreeBranch* m_pRootBig;

	//! \brief	Ҷ�ӽڵ�ID
	UGint m_nLeafID;
//	UGDatasetVector * m_pVector;
public:

	//! \brief R��������Χ
	UGRect2D m_rc2Bounds;

	//! \brief ��ʹ�õ��ڴ�
	UGuint m_nMemoryUsed;

	//! \brief �������������
	UGuint m_nMaxItemCount;

	//! \brief �������� 
	UGuint m_nBigItemCount;

};

}

#endif /* _INC_UGDBRTREE_3E9E4B130220_INCLUDED */

