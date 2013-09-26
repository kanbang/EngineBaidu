/*!  \file	 UGProgress.h
*  \brief	 ��������
*  \author	 caogf, zengzm
*  \attention 
*  Copyright(c) 1996-2004 SuperMap Software Co., Ltd.<br>
*  All Rights Reserved
*/
#if !defined(UGPROGRESS_H)
#define UGPROGRESS_H
#include "Toolkit/UGThread.h"
#include <stack>

namespace UGC{

//! \brief ��������Ϣ�ص�����
//! \remarks add the argument bCancel to communicate with the outside functions.caogf
typedef void (*ProgressProc)(void* pParam, const UGchar* pchTitle,const UGchar* pchMessage,
							 UGint nPercent, const UGchar* pchRemainTime,UGbool& bCancel, UGuint nRemainTime);

//! \brief �������ࡣ
/**
��������������Ϊ���ڽ��г�ʱ�������ʱ��,�ܶ��ڷ������û���չ�������Ϣ,
�����û�����Ϊ�����Ѿ���������״̬.
�ڽ��нϳ�ʱ��Ĳ���ʱ,�����ṩ��������Ϣ(�û���ѡ���Ƿ�����),
��Щ��ʱ��Ĳ�������(��������):
����ת��,
�����ݼ�/��¼���ĸ��ֿռ����, 
�����ݼ�/��¼���ĸ�ֵ,׷��,�����ռ�������, 
�򵥶���,���ǳ��˺��û����н���ʽ����(��ͼ���,����ʽ�༭)��֮��,
����ʱ�䳬��5���,�����뿼��ʹ�ý�����.<br>

����������ʽ�ɲο�����:<br>
|-------------------------------------------------|<br>
|������������Ϣ(�磺���ڵ���shape�ļ�)            |<br>
|												  |<br>
|������Ϣ(�磺���ڵ��������(10/1000))			  |<br>
|	||||||||(����λ��)							  |<br>
|_________________________________________________|<br>
<br>
UGC����У�UGProgress��һ���ʹ�÷������£�<br>
UGProgress pProgress = NULL;<br>
if(bUseProgress) //���û������Ƿ�ʹ�ý�����<br>
{<br>
	pProgress = new UGProgress();<br>
	pProgress->SetTitleMessage(UGS_IMPORT_SHAPE); // "���ڵ���shape�ļ�"<br>
	pProgress->SetProgressPos(0);<br>
}<br>
for(int i=0; i<ObjCount; i++)<br>
{<br>
	if (pProgress)<br>
	{<br>
		pProgress->SetMessage(UGC_IMPORT_REGION, i, ObjCount); // ���ڵ��������(10/1000)<br>
		int nPos = i*100/ObjCount;<br>
		pProgress->SetProgressPos(nPos);<br>
		// �Ժ�Ҫ����pProgress->IsCancel()����Ϣ<br>
	}<br>
}<br>
delete pProgress;<br>
pProgress = NULL;<br>
<br>
���ڱȽϸ��ӵ����, ��ĳ������Ҫ�ֳɼ�������,ÿ�����ֶ���Ҫ���ý�����, 
����һ������ʹ���˽�����,�������ڲ�Ҫ���õĺ���Ҳ��Ҫʹ�ý�����, 
Ϊ�˱�������û���һ���������ֶ�δ�0-100�Ľ�����ʾ,��������ʹ��:<br>
UGProgress pProgress = NULL;<br>
if(bUseProgress) //���û������Ƿ�ʹ�ý�����<br>
{<br>
	pProgress = new UGProgress();<br>
	pProgress->SetTitleMessage("�������˷���"); <br>
	pProgress->SetProgressPos(0);<br>
}<br>
//��һ�������������, ����������50%<br>
if (pProgress)<br>
{<br>
	pProgress->SetBothPosRange(0, 50); //�� 0-50<br>
}<br>
for(int i=0; i<ObjCount; i++)<br>
{<br>
	if (pProgress)<br>
	{<br>
		pProgress->SetMessage("�����������"); <br>
		int nPos = i*100/ObjCount; // ������Ȼ�� �� 0-100,�������ڲ��ᴦ��Ϊ �� 0-50<br>
		pProgress->SetProgressPos(nPos);<br>
		// �Ժ�Ҫ����pProgress->IsCancel()����Ϣ<br>
	}<br>
}<br>
<br>
//�ڶ�������Ϊ�������������ݼ�, ����������ʣ���50%<br>
if (pProgress)<br>
{<br>
	pProgress->SetBothPosRange(50, 100); //�� 50-100<br>
}<br>
for(int j=0; j<ObjCount; j++)<br>
{<br>
	if (pProgress)<br>
	{<br>
		pProgress->SetMessage("���ڴ����������ݼ�"); <br>
		int nPos = j*100/ObjCount; // ������Ȼ�� �� 0-100,�������ڲ��ᴦ��Ϊ �� 50-100<br>
		pProgress->SetProgressPos(nPos);<br>
		// �Ժ�Ҫ����pProgress->IsCancel()����Ϣ<br>
	}<br>
}<br>
delete pProgress;<br>
pProgress = NULL;<br>
<br>
���ں���Ƕ�׺���ʹ�ý����������,��Ӧ�ðѽ�������Ϊ����(���߳�Ա����).
����Pos���趨, ����ͨ��SetBothPosRange,�Լ�PushPosRange��PopPosRange������ʹ��.
�򵥶���,������Ҫ����һ������֮ǰ,����PushPosRange;����֮��,��������PopPosRange;
��ÿ��������,����Ϊ�Լ�ӵ�� [0,100]��pos ��Χ. ������ο���Ԫ���Դ���CUGProgressTest::testMultiPos�е�ʹ��<br>
ע:��ǰ�Լ�����Ĵ���Ҳ��������ʹ��,����Ҫ�޸�.<br>
<br><br>

UGC���û�(�����Ʒ)��ʹ��UGProgressʱ,Ӧ��:<br>
1)��д����õ��������ص���Ϣ�Ĵ�����<br>
void MyProgressProc(void* pParam, const UGchar* pchTitle,const UGchar* pchMessage,
							 UGint nPercent, const UGchar* pchRemainTime,UGbool& bCancel)<br>
{<br>
	// ����ѵõ��ĸ�����Ϣչ�ָ��û�<br>
	// ע��bCancel��δ������,��UGC�ϲ��Ʒ��ʱ��Ҫ�ṩ��ȥ<br>
}<br>
2)ͨ��UGCallback���ý������Ļص�����<br>
UGProgress::SetProgressProc(MyProgressProc);<br>
*/
//����ʱ��ĳ�ʼ��ֵ

class TOOLKIT_API UGProgress
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGProgress();
	//! \brief ��������
	~UGProgress();

public:
	//! \brief ���ý�������Ϣ�Ļص�����ָ��
	//! \param pProgressFun �������ص�ָ��
	//! \param pParam ���Ӳ�����Ĭ��ΪNULL
	static void SetProgressProc(ProgressProc pProgressFun, void* pParam=NULL);	

	//! \brief ���ý�����������Ϣ
	//! \param strTitleMsg ������������Ϣ
	void SetTitleMessage(const UGString& strTitleMsg);
	//! \brief ͨ���ַ�����ԴID�͸�ʽ����Ϣ,����������Ϣ,��������Ϊ������������Ϣ
	//! \param nResID �ַ�����Դid, ��Ϊ��ʽ����Ϣ
	//! \param ... ��������,������printf("", ...)�е�...
	/*void SetTitleMessage(UGint nResID, ...);*/
	
	//! \brief ���ý�������Ϣ
	//! \param strMessage ��ǰ������Ϣ
	void SetMessage(const UGString& strMessage);

	//! \brief ͨ���ַ�����ԴID�͸�ʽ����Ϣ,����������Ϣ,��������Ϊ������Ϣ
	//! \param nResID �ַ�����Դid, ��Ϊ��ʽ����Ϣ
	//! \param ... ��������,������printf("", ...)�е�...
	/*void SetMessage(UGint nResID, ...);*/
	
	//! \brief ���ý������İٷֱ�λ��(��0��100)
	//! \param nPercent �ٷֱ�λ��
	//! \return ������һ��Pos
	UGint SetProgressPos(UGint nPercent, UGbool bForceRefresh = false);

	//! \brief ���ú���ʹ�ù����н��������õ���ʼ����ֹλ�÷�Χ
	//! \param nStartPos ��ʼλ��(�ٷֱ�ֵ)
	//! \param nEndPos ��ֹλ��(�ٷֱ�ֵ)
	//! \remarks ��Pos�����Pos,�����ϲ㺯���Ѿ�������������ķ�Χ��,�ٰ���[0,100]�����з���
	void SetBothPosRange(UGint nStartPos, UGint nEndPos);
	
	//! \brief �õ����õ���ʼ����λ��
	//! \return ���ؿ��õ���ʼ����λ��
	UGint GetStartPos() const;

	//! \brief �õ����õ���ֹ����λ��
	//! \return ���ؿ��õ���ֹ����λ��
	UGint GetEndPos() const;

	//! \brief �õ����õ�����λ�������С
	//! \return ���ؿ��õ�����λ�������С
	UGint GetPosRange() const;

	//! \brief �ѵ�ǰPos Rangeѹջ
	//! \remarks �ں���������ʱʹ��
	void PushPosRange();

	//! \brief ��Pos Rangeջ�е������ϲ�
	//! \remarks �ں���������ʱʹ��
	void PopPosRange();

	//! \brief �õ�����������λ��
	//! \remarks Ϊ��֧�ֶ��Ƕ�׽������ͷ���ʹ��, SetBothPosRange�Ⱥ�Pos��صĺ���,�����õ������λ��;
	//! �������ӵõ�����λ�õķ���,�Ա��ڲ���ʱ���к˶�. һ��û�б�Ҫʹ��
	UGint GetAbsolutePos(int nPercent) const;

	//! \brief ��ս������ĸ�����Ϣ
	void Clear(); 

	//! \brief �õ��û��Ƿ�ȡ������Ϣ,�Ա�������ܽ����жϳ���; Ŀǰ��δʹ��
	UGbool IsCanceled();

	//! \brief �Ƿ���ʾ������
	//! \remarks ���Ի���Ƿ���ʾ������; ���ý������Ƿ���ʾͨ��UGRegistry::Root().SetAt("ShowProgress", "true")������,
	//!			���ú���Ѿ����ڵĽ���������������
	UGbool IsShow() const;

private:
	UGString m_strTitle; // ����������Progress Title
	UGString m_strMessage; // ����������Progress Msg
	// ������������һ�ε�Percent; Ĭ��Ϊ-1, ������һ��Ҳ����ˢ����
	UGint m_nLastPercent; 
	
	// �ڵ���SetProgressPosʱ,�������1%,һ���ǲ�ˢ�µ�; 
	// ����,���ʱ����������ms_nRefreshInterval(Ĭ��Ϊ5��),Ҳˢ��һ��,��ֹ��ʱ�䲻ˢ��
#ifndef SYMBIAN60
	static const UGint ms_nRefreshInterval; // ʱ�䵥λ: ��
#else
	static const UGint ms_nRefreshInterval =5; // ʱ�䵥λ: ��
#endif	
	UGTime m_tmStart; // ��ǰ��������ʼʱ��¼������ʱ���,
	UGTime m_tmLast; // ��һ�ν���������ʱ��¼������ʱ���
	UGString m_strRemainTime; // ʣ��ʱ�����ʾ�ַ���
	UGuint m_nRemainTime; //ʣ��ľ��������
	UGbool m_bCancel;//����ȡ��
	//! �Ƿ���ʾ������,�ڹ��캯���ж�ȡugc.xml����
	UGbool m_bShowProgress;

	//UGint m_nStartPos; //��ʼλ��,Ĭ��Ϊ0
	//UGint m_nEndPos; // ��ֹλ��,Ĭ��Ϊ100

	  //!  \brief Toolkit
	struct PosRange
	{
	  //!  \brief Toolkit
		UGint m_nStartPos;
	  //!  \brief Toolkit
		UGint m_nEndPos;
	  //!  \brief Toolkit
		PosRange(){
	  //!  \brief Toolkit
	  //!  \brief Toolkit
			m_nStartPos = 0;
	  //!  \brief Toolkit
			m_nEndPos = 100;
		}
	};
	//! \brief ��ǰ��Pos Range(����λ��)
	PosRange m_curPosRange;

	//! \brief  Pos Range�Ķ�ջ(����λ��), �������ƶ��Ƕ�׵Ľ���������
	std::stack<PosRange> m_PosRanges;
	
//�����������ص���ش�������������������������������������������
	struct UGProgProc 
	{
		UGProgProc(){
			m_pProgressFun = NULL;
			m_pParam = NULL;
		}
		ProgressProc m_pProgressFun;
		void* m_pParam;
	};
	static UGDict<UGuint, UGProgProc> ms_ProgProc;

//	! \brief �������ص�����ָ��
//		static ProgressProc	ms_pProgressFun;
//		static void* ms_pParam;

	//! \brief ���̱߳���
	static UGMutex ms_mutex;

private:
	//! \brief ����ʣ��ʱ��
	UGString GetRemainTimeInfo(UGint nPercent, UGbool &bRefresh,UGuint& nRemainTime); 

	//! \brief ���ûص�����
	void ProgCallback(const UGchar* pchTitle,const UGchar* pchMessage,
				UGint nPercent, const UGchar* pchRemainTime,UGuint nRemainTime = 0);

	//! \brief ����percent��pos range�ľ��Է�Χ, �õ�����Pos
	UGint GetAbsolutePos(UGint nPercent, PosRange posRangeTotal) const;
};

}

#endif // !defined(UGPROGRESS_H)

