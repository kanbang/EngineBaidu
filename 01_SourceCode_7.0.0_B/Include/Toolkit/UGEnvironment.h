#if !defined(UGENVIRONMENT_H)
#define UGENVIRONMENT_H

#include "Stream/ugdefs.h"

namespace UGC {

//! \brief ����������
// ��һЩ��Ҫ��������ʱ�����õ�ֵ�ŵ�����
// �Ժ����ͳһ���ŵ�����
// add by gouyu 2011-8-22
class TOOLKIT_API UGEnvironment
{
public:
	UGEnvironment();
	void init(); // added by liucq 20130610 �Ӻ��ʼ�������ƶ�ƽ̨�ֶ����ó�ʼ��
	//! \brief ��ȡ�Ƿ���Ƶ��������ʻ���ʱ������ʹ�ñ��ߺ����������ɫ���ƣ�Ĭ��ֻ��ʹ������ɫ
	static UGbool GetSymbolDrawWithLineBrushColor();

	static void SetSymbolDrawWithLineBrushColor(UGbool value);

private:

	void ReadIsSymbolDrawWithLineBrushColor();

	static UGbool g_bSymbolDrawWithLineBrushColor;
};
#ifdef OS_ANDROID
extern TOOLKIT_API UGEnvironment g_UGEnvironment;
#endif
}
#endif

