/*! \file UGDBRTreeLeaf.h
 *  \brief R��Ҷ����ඨ�塣
 *  \author ���䳬,�¿���
 *  \bug

 *	<b>����˵����</b>\n
	<em>1��2003-11-1 �״���ɴ����д.\n</em>
*/  

#if !defined(AFX_UGDBRTREELEAF_H__60DCDD23_A57A_406F_B2A3_B9160FF5B5A1__INCLUDED_)
#define AFX_UGDBRTREELEAF_H__60DCDD23_A57A_406F_B2A3_B9160FF5B5A1__INCLUDED_

#include "UGDBRTreeNode.h"
#include "UGDBRTree.h"
namespace UGC
{
//! \brief R��Ҷ����࣬����е�Ԫ����ID����
//! \remarks ����UGDBRTreeNode
class  SPATIALINDEX_API UGDBRTreeLeaf : public UGDBRTreeNode  
{
public:
	//! \brief ���캯��
	UGDBRTreeLeaf();

	//! \brief ��������
	virtual ~UGDBRTreeLeaf();

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

	//! \brief ���ڴ�����������������ݡ�
	//! \param pData �����Ž�����ݡ�
	//! \return  �ɹ��򷵻�TRUE��	
	UGbool LoadMyself(UGStream &stream);

	//! \brief �ѽ������ݱ��浽�ڴ������С�
	//! \param pData ��������������顣
	//! \return �ɹ��򷵻�TRUE��
	UGbool StoreMyself(UGStream &stream);

	//! \brief ��ȡ�����Ԫ�ص�����
	//! \return �����Ԫ�ص�����
	virtual UGint GetEntryCount();

	//! \brief ��ȡ���ռ���ڴ���ֽ���
	//! \return ���ռ���ڴ���ֽ���
	virtual UGint GetDataSize();
	
	//! \brief ��ȡ�ý���µ����ж����ID
	//! \param arIDs ���������ȡ����ID
	//! \return �ɹ��򷵻�TRUE��
// 	virtual UGbool GetAllIDs( UGArray<UGint> &arIDs );

//	//! \brief �ڽ���²�ѯ
//	//! \param rcBound ��ѯ�ķ�Χ
//	//! \param arIDs ��ѯ�Ľ��ID����
//	//! \return  ��ѯ���Ķ��������
//	virtual UGbool Query(const UGRectUInt& rcBound, 
//					   UGArray<UGint> &arItemIDs, 
//					   UGArray<UGint> &arCertainLeafIDs,
//					   UGArray<UGint> &arMaybeLeafIDs);
// 	virtual UGbool Query(const UGRectUInt& rcBound,
// 						const UGRectUInt& rcReferenceBound,
// 						UGbool bFuzzy,
// 						UGuint nGranule,
// 						UGArray<UGint> &aryItemIDs,
// 						UGArray<UGint> &arCertainLeafIDs,
// 						UGArray<UGint> &arMaybeLeafIDs);

	//! \brief ��ȡ��������
	//! \return ��������
	//! \remarks ����ֵ��2
	virtual UGuchar GetType();

public:
	//! \brief ��ȡID�����ָ��
	//! \return ID�����ָ��
	UGDBRTreeNodeItems* GetIDArray() ;
	
	//! \brief Ҷ�ӽڵ�ID
	UGint m_nID;

protected:
	//! \brief ID�����ָ��
	UGDBRTreeNodeItems *m_pNodeItems;
private:
	//! \brief �Ƿ��Ѿ�������
	UGbool m_bLoad;

};

}
#endif // !defined(AFX_UGDBRTREELEAF_H__60DCDD23_A57A_406F_B2A3_B9160FF5B5A1__INCLUDED_)

