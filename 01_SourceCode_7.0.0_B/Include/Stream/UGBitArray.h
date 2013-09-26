/* 
	\file UGBitArray.h
	\brief λ���顣
	\author jifang
	\attention
	Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����UGbool��Ϊbool by zengzm��ȷ��һ��sizeֻռ��һ��bit,std::vector<bool>�ڲ��ᴦ���</em>
	<em>2���ڶ���˵����</em>
*/
	
#if !defined(UGBITARRAY_H_)
#define UGBITARRAY_H_

#include <vector>
#include "Stream/ugdefs.h"

namespace UGC {

//! \brief λ������,�÷���UGArray�ǳ����ơ�
//! \remarks �ڲ�����std::vector<bool>ʵ��,ÿ��boolԪ�ؽ�ռ��һ��λ,�Լ����ڴ�ռ�õĿռ䡣
class STREAM_API UGBitArray 
{
public:
	//! \brief ���캯����
	//! \param n Ԫ�ظ���[in]��
	//! \param b ÿ��Ԫ�صĳ�ʼֵ[in]��
	UGBitArray(UGint n = 0, bool b = FALSE);	
	
	//! \brief �������캯����
	//! \param bitArray ���������¶����bitArray[in]��
	UGBitArray(const UGBitArray & bitArray);	
	
	//! \brief ����������
	~UGBitArray();	
	
	//! \brief ������ֵ������
	//! \param bitArray ������������и�ֵ��bitArray[in]��
	//! \return ��ֵ��ö��������,��֧�����㡣
	UGBitArray &operator=(const UGBitArray &bitArray);	

	//! \brief ������������Ԫ������.
	//! \return Ԫ�ظ���
	UGint GetSize() const;
	
	//! \brief ����Ԫ�ظ���, ��ԭ����Ĳ����ò���b���, �����ԭ��С, �Զ��ض�.
	//! \param n Ԫ�ظ���[in]��
	//! \param b ���������չ,���Ӳ���Ԫ�ص�ֵ [in]��
	void SetSize(UGint n, bool b = FALSE);	

	//! \brief �õ�ָ��������Ԫ��ֵ
	//! \param i ָ��������[in]��
	//! \return ����ָ��Ԫ�ص�boolֵ��
	//! \remarks ����ֵ���Խ��, �׳�out_of_range�쳣��
	bool GetAt(UGint i) const;	
	
	//! \brief ����ָ��������Ԫ�ص�boolֵ��
	//! \param i ָ��������[in]��
	//! \param b ָ����boolֵ[in]��
	//! \remarks ����ֵ���Խ��, �׳�out_of_range�쳣.��
	void SetAt(UGint i, bool b);	
	
	//! \brief �õ�ָ������Ԫ�ص�boolֵ
	//! \param i ָ��������[in]��
	//! \return ����ָ������Ԫ�ص�boolֵ��
	//! \remarks ������ֵû�б߽���, �ɵ����߱�֤.��
	bool operator[](UGint i);	
	
	//! \brief ���������һ��Ԫ�ء�
	//! \param b ���ӵ�Ԫ�ص�ֵ[in]��
	//! \return �������Ԫ�ص�����(��0��)��
	UGint Add(bool b);	
	
	//! \brief ���������������һ�����顣
	//! \param bitArray Ҫ���ӵ�����[in]��
	//! \return ���������Ԫ�ص���ʼλ�á�
	UGint Append(const UGBitArray &bitArray);	
	
	//! \brief ��ָ��������ǰ��һ��Ԫ�ء�
	//! \param nIndex ָ��������[in]��
	//! \param b Ҫ�����Ԫ��[in]��
	void InsertAt(UGint nIndex, bool b);	
	
	//! \brief ��ָ��������ǰ��UGBitArray����
	//! \param nIndex ָ��������[in]��
	//! \param bitArray Ҫ���������[in]��
	void InsertAt(UGint nIndex, const UGBitArray &bitArray);	
	
	//! \brief �õ�����洢�ռ��С
	//! \return ��������洢�ռ��С
	//! \remarks ����洢�ռ��С=����Ԫ�ش�С+Ԥ���ռ��С
	UGint GetCapacity() const;
	
	//! \brief ��������洢�ռ��С
	//! \param nCapacity Ҫ���õĴ�С[in]��
	//! \remarks �������õ�ֵΪ����,�����ᵼ�����еĿռ䱻��С;�����ᵼ��С������Ԫ�صĴ�С��
	void SetCapacity(UGint nCapacity);	
	
	//! \brief �Ƴ�����Ԫ��, �ͷ�����.
	void RemoveAll();
	
	//! \brief �ͷŶ���洢�ռ�.
	//! \remarks �ڲ�ͨ���·���һ������,Ȼ����н���ʵ��
	void FreeExtra();
private:
	//! \brief �ڲ�ʵ���õ�stl��vector<bool>
	std::vector<bool> m_bitvect;
};

}

#endif // UGBITARRAY_H_


