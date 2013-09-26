/*! \file UGDBRTreeBud.h
 *  \brief R��ѿ����ඨ�塣
 *  \author ���䳬,�¿���
 *  \bug

 *	<b>����˵����</b>\n
	<em>1��2003-11-1 �״���ɴ����д.\n</em>
*/  
#ifndef _INC_UGDBRTreeBud_3E9E4B130213_INCLUDED
#define _INC_UGDBRTreeBud_3E9E4B130213_INCLUDED



#include "UGDBRTreeNode.h"

namespace UGC
{
	class UGDBRTreeLeaf;
	class UGDBRTree;

//! \brief R��ѿ����࣬����е�Ԫ����ָ��items����������
//! \remarks ����UGDBRTreeNode
class  SPATIALINDEX_API UGDBRTreeBud : public UGDBRTreeNode   
{
public:
	UGDBRTreeBud();
	virtual ~UGDBRTreeBud();

public:
	//! \brief �������㷨
	//! \param nMaxItemCount [in] �������������Ԫ������
	//! \param nMaxItemCount [in/out] �㷨���ɵĽ��ɨ���� 
	virtual UGDBRTreeNode* Split( UGint nMaxItemCount,DBScanLineInfo *pScanLines) ;
	
	//! \brief �������㷨
	//! \param nMaxItemCount [in] �������������Ԫ������
	virtual UGDBRTreeNode* Split( UGint nMaxItemCount );

	//! \brief �ж��Ƿ���Ҫ�����ָ�
	//! \param nMaxItemCount [in] �������������Ԫ������
	virtual UGbool NeedSplit( UGint nMaxEntryCount );
	
	//! \brief ��ȡChildren����
	virtual UGint GetEntryCount();

	//! \brief ��ȡ��������
	//! \return ��������
	//! \remarks ����ֵ��0
	virtual UGuchar GetType();

	//! \brief ��ȡ���ռ���ڴ���ֽ���
	//! \return ���ռ���ڴ���ֽ���
	virtual UGint GetDataSize();

public:
	//! \brief �ݱ��һ��leaf���
	//! \param pLeaf ָ���ݱ������һ��leaf������
	//! \return �ݱ�ɹ�����true�����򷵻�false
	UGbool GrowUp(UGDBRTreeLeaf* pLeaf);
	
	//! \brief ���ý�����������ָ���rtree��itemsָ��
	//! \param pIndexes ������������ָ��
	//! \param pItems rtree��itemsָ��
	//! \remarks �������ڴ棬ֻ�Ǽ򵥵�ָ�븳ֵ
	void SetItems( UGArray<UGint>* pIndexes, UGDBRTreeNodeItems* pItems );
	
	//! \brief ����������Ԫ�صķ�Χ
	void CalculateBound();

protected:

	//! \brief ѡ��һ��������и���
	//! \param nMaxItemCount �������������Ԫ������
	//! \param pScanLines ɨ��������
	//! \param nPosition �и���λ��
	//! \param bVertical �и��߷��򣬺����������
	//! \param nOldCount �����и��߻��֣��ñ����Ľ������
	//! \param nNewCount �����и��߻��֣����Ƴ��Ľ������
	//! \return ѡ��ɹ�����true�����򷵻�false
	//! \remarks �ȽϺ�����Ѻ���������и��ߣ�ѡ��Ϻõ�һ��
	UGbool ChooseCutLine( UGint nMaxItemCount,DBScanLineInfo *pScanLines,
						UGuint& nPosition, UGbool& bVertical, 
						UGint& nOldCount, UGint& nNewCount );
	
	//! \brief ѡ��һ������������и���
	//! \param nMaxItemCount �������������Ԫ������
	//! \param pScanLines ɨ��������
	//! \param nPosition �и���λ��
	//! \param nOldCount �����и��߻��֣��ñ����Ľ������
	//! \param nNewCount �����и��߻��֣����Ƴ��Ľ������
	//! \return ѡ��ɹ�����true�����򷵻�false
	//! \remarks �Թ��и��ߵ����ж�����ɵ�bound�����СΪ��׼
	UGulong ChooseVerticalCutLine( UGint nMaxItemCount,DBScanLineInfo *pScanLines,
									UGuint& nPosition,UGint& nOldCount, UGint& nNewCount );
	 
	//! \brief ѡ��һ������ĺ����и���
	//! \param nMaxItemCount �������������Ԫ������
	//! \param pScanLines ɨ��������
	//! \param nPosition �и���λ��
	//! \param nOldCount �����и��߻��֣��ñ����Ľ������
	//! \param nNewCount �����и��߻��֣����Ƴ��Ľ������
	//! \return ѡ��ɹ�����true�����򷵻�false
	//! \remarks �Թ��и��ߵ����ж�����ɵ�bound�����СΪ��׼
	UGulong ChooseHorizontalCutLine( UGint nMaxItemCount, DBScanLineInfo *pScanLines,
									UGuint& nPosition,UGint& nOldCount, UGint& nNewCount );

	//! \brief ��ȡɨ�������Ϸ�������� 
	//! \param nPosition [in] ɨ����λ��
	//! \param bVertical [in] �Ƿ��Ǵ�ֱɨ����
	UGint GetOldItemCount( UGuint nPosition, UGbool bVertical );

	//! \brief ��ȡɨ�������·�������� 
	//! \param nPosition [in] ɨ����λ��
	//! \param bVertical [in] �Ƿ��Ǵ�ֱɨ����
	UGint GetNewItemCount( UGuint nPosition, UGbool bVertical );


	//! \brief �����и��ߵ�λ�úͷ����ж�һ������Ӧ�ñ��������Ǳ����ֵ��µĽ����
	//! \param rcBound ����ķ�Χ
	//! \param nPosition �и���λ��
	//! \param bVertical �и��߷��򣬺����������
	//! \return ����Ӧ�ñ����򷵻�true�����򷵻�false
	UGbool BeSaved( const UGRectUInt& rcBound, UGuint nPosition, UGbool bVertical );
	
protected:
	//! \brief �㣬���ְַ�
	//! \return ���� TRUE ��ʾ�ֺ���
	//! ���� True ͬʱnPostion = 0 ��ʾ�˰������ڷ�
	//! \remarks pIndexes��Ϊ��ǰ����id�ĸ���Ʒ������������ڿ����޸ġ�
	UGbool DichotomyItems(UGArray<UGint>* pIndexes,UGuint &nPostion,UGuint nStartPos,UGuint nEndPos,UGbool bVertical,UGint nCount);
protected:
	//! \brief ָ������Ԫ�ص������ָ��
	UGDBRTreeNodeItems* m_pItems ;
	
	//! \brief ָ��ý�������Ԫ������������
	//! \remarks example: 
	//! 		��ȡ��nIndex��Ԫ��
	//! 		m_pItems->ElementAt(m_pIndexes->GetAt(nIndex))
	UGArray<UGint>* m_pIndexes;

};
}


#endif /* _INC_DBRTreeBud_3E9E4B130213_INCLUDED */

