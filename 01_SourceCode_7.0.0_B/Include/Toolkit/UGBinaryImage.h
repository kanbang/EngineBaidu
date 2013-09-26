#ifndef _UGBINARYIMAGE_H
#define _UGBINARYIMAGE_H
#include "Stream/ugdefs.h"

namespace UGC
{
// ��ֵλͼ��,�Ǻ�(0)����(1)
// ���������ϱȽϴ��������,���������쳣��ֵ
class TOOLKIT_API UGBinaryImage
{
public:
	// ����y��x�е�λͼ,��ʼ��Ϊ0
	UGBinaryImage(UGint x, UGint y);
	~UGBinaryImage();

	// ��ָ����Ԫ�޸�Ϊ1
	void Set(UGint x, UGint y);
	// ��ָ����Ԫ�޸�Ϊ0
	void Remove(UGint x, UGint y);
	// ����ָ����Ԫ�Ƿ�Ϊ1
	UGbool HitTest(UGint x, UGint y);
	// ����λͼ
	void Reset();
	// ��(x,y)Ϊ���(����������),�������²�����һ��ֵΪ1����Ԫ.
	// ���x,y��ֵΪ��,��ӵ�һ����Ԫ��ʼ������
	UGbool FindNext(UGint &x, UGint &y);

	// ��(x,y)Ϊ���(����������),�������²�����һ��ֵΪ0����Ԫ.
	// ���x,y��ֵΪ��,��ӵ�һ����Ԫ��ʼ������
	UGbool FindXORNext(UGint &x, UGint &y);

// 	UGbyte* TakeBuffer()
// 	{
// 		UGbyte *pTmp = m_pBuffer;
// 		m_pBuffer = NULL;
// 		return pTmp;
// 	}
// 	void GiveBuffer(UGbyte *pBuffer, UGint nWidth, UGint nHeight)
// 	{
// 		if(m_pBuffer != NULL)
// 		{
// 			delete []m_pBuffer;
// 		}
// 		m_pBuffer = pBuffer;
// 		m_nWidth = nWidth;
// 		m_nHeight = nHeight;
// 	}

private:
	UGint m_nWidth;
	UGint m_nHeight;
	UGbyte *m_pBuffer;
	UGint m_nByteSpace;
};

}
#endif
