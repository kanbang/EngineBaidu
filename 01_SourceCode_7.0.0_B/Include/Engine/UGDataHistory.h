// UGDataHistory.h: interface for the UGDataHistory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDATAHISTORY_H__2D9823AA_E642_44D1_980A_A3807F5DD64F__INCLUDED_)
#define AFX_UGDATAHISTORY_H__2D9823AA_E642_44D1_980A_A3807F5DD64F__INCLUDED_

#include "Stream/ugdefs.h"
#include "Engine/UGRecordset.h"
#if !defined (IOS)
#include "Engine/UGDataPool.h"
#endif
namespace UGC
{
	//�༭��ʷ��Ϣ,����������ʲôͼ��,�����Ķ���id����,����������
	//##ModelId=48203056005E
	struct EditHistoryInfo 
	{
		//##ModelId=482030560060
		UGDatasetVector* pDatasetVector;
		//##ModelId=482030560061
		UGArray<UGint> nIDs;
		//##ModelId=48203056006D
		UGint nOptType;
	};

//##ModelId=48203056008C
#if defined (IOS)
    class UGDataset;
    class UGDataPool;
#endif
class ENGINE_API UGDataHistory  
{
public:
	//##ModelId=48203056008D
	//! \brief ���캯��
	UGDataHistory();
	//##ModelId=48203056009C
	//! \brief ��������
	virtual ~UGDataHistory();
public:
	//##ModelId=482030560149
	enum OptType
	{				//�����������
		//##ModelId=48203056014B
			OPT_ADDNEW=0,		//����¶���
		//##ModelId=48203056014C
			OPT_MODIFIED=1,		//���������ı�
		//##ModelId=48203056014D
			OPT_DELETE=2,		//����ɾ��
	};

public:
	//##ModelId=4820305600AB
	//! \brief RemoveAllEvent
	UGbool RemoveAllEvent();
	//##ModelId=4820305600AC
	//! \brief Goto
	UGbool Goto(UGint nEventIndex);							  //	

	//##ModelId=4820305600AE
	//! \brief ȡ���¼���Ϣ
	UGbool GetEventInfo(                                //ȡ���¼���Ϣ
		UGint nEventIndex,                             //�¼�������
		UGint & nAction,                               //
		UGint & nLayerIndex,                           //�¼�����ͼ�㣬����¼������ڶ��ͼ�㣬��ôֻ�������һ��ͼ�������
		UGString & strNote);							  //�¼�˵��	

	//##ModelId=4820305600B3
	//! \brief ��ǰ�¼�������
	UGint GetCurrentIndex();                           //��ǰ�¼�������

	//##ModelId=4820305600BB
	//! \brief ����һ�����������������ɵļ�¼��
	UGint GetCapacity();                               //����һ�����������������ɵļ�¼��

	//##ModelId=4820305600BC
	//! \brief ȡ������¼���
	UGint GetMaxEvtCount();                            //ȡ������¼���

	//##ModelId=4820305600BD
	//! \brief ����һ�����������������ɵļ�¼��
	UGint SetCapacity(                                 //����һ�����������������ɵļ�¼��
		UGint lMaxSize);

	//##ModelId=4820305600BF
	//! \brief ��������¼���
	UGint SetMaxEvtCount(                              //��������¼���
		UGint lEvtCount);

	//##ModelId=4820305600C1
	//! \brief ��������ɾ���¼�
	UGbool RemoveEvent(	                              //��������ɾ���¼�
		int lEvtIndex);								  //�¼�������

	//##ModelId=4820305600C3
	//! \brief ��ʼһ���¼�
	UGbool BeginEvent(								  //��ʼһ���¼�	
		UGint nAction=0,								  //��ǰ��action,���Ϊ0
													  //��ʾʹ�ð󶨵�ͼ��ǰ��action			
		UGString strEvtNote=_U(""));					  //�¼���˵��	

	//##ModelId=4820305600CD
	//! \brief ����һ���¼�
	void EndEvent(									  //����һ���¼�
		UGbool bRecord=TRUE);							  //�Ƿ�Ըղŷ������¼����м�¼	
	

	//******************************************************************************//
   //*			�˺���������beginevent��EndEvent֮�����,���Խ��ж�֮���á�		  *//
  //******************************************************************************//
	//##ModelId=4820305600DA
	//! \brief �����¼�������	
	UGbool SetEvtInfo(								  //�����¼�������	
		OptType etype,								  //����Ĳ�������
		UGRecordset* pRecordset,//�������ڼ�¼��������ΪNULL
		UGbool bOne = false);	//�Ƿ������һ����¼��Ĭ��Ϊ����ѭ��������¼��		  

	//##ModelId=4820305600EA
	//! \brief ���ˣ�������ǰ���¼���
	UGbool GoBack();									  //���ˣ�������ǰ���¼���
													  //�ص���һ�¼����ɹ�����true	

	//##ModelId=4820305600FA
	//! \brief ǰ�����ָ���һ�¼�
	UGbool GoForward();                                 //ǰ�����ָ���һ�¼�

	//##ModelId=4820305600FB
	//! \brief �Ƿ����ǰ��
	UGbool CanGoForward();							  //�Ƿ����ǰ��	

	//##ModelId=4820305600FC
	//! \brief �Ƿ���Ի���
	UGbool CanGoBack();								  //�Ƿ���Ի���		

	
	//##ModelId=482030560109
	//! \brief ȡ���¼�����
	UGint GetEvtCount();								  //ȡ���¼�����	
	
	//added by xielin 2007-05-23 
	//! \brief ���ݼ��ͷŵ�ʱ����øýӿ�
	//##ModelId=48203056010A
	UGbool OnDatasetDestory(UGDataset* pDt);
	
	//! \brief �õ��༭����ʷ��Ϣ����
	//##ModelId=48203056010C
	UGArray<EditHistoryInfo> GetEditHistoryInfo();

protected:
	//##ModelId=48203056010D
    
    UGDataPool * m_pDataPool;
	//##ModelId=482030560119
	UGString m_strEvtTbName;							  //�¼��������
	//##ModelId=48203056011A
	UGbool m_bEvtBegin;								  //�¼��Ƿ��Ѿ���ʼ	
	//##ModelId=48203056011B
	UGint m_nAction;									  //�¼���action	
	//##ModelId=48203056011C
	UGString m_strEvtNote;							  //�¼���˵��
	//##ModelId=482030560128
	UGArray<UGint> m_arEvtIndex;				  //�¼�������	
	//##ModelId=482030560129
	UGint m_nCurEvtIndex;							  //��ǰ�¼�������	
	//{{qiuli 03.5.6
	//##ModelId=48203056012A
	UGbool m_bGoback;
	//}}qiuli 03.5.6

	//##ModelId=48203056012B
	UGArray<EditHistoryInfo> m_aryEditHistoryInfo;   //����edit��������ʷ��¼��Ϣ,�ڲ�ʹ��,������

private://��Ǹ���������ڲ�ʹ�ã� 
	
	//�����ݼ����޸ļ�¼���а����Ķ���
	//##ModelId=482030560138
	void ModifyGeometry(UGRecordset *pRs,				//��¼��
						UGDatasetVector *pDtV);			//���ݼ�

	//�����ݼ�����Ӽ�¼���а����Ķ���   
	//##ModelId=48203056013B
	void AddNewGeometry(UGRecordset *pRs,				//��¼��
						UGDatasetVector *pDtV); 			//���ݼ�
 
	//�����ݼ���ɾ����¼���а����Ķ��� 
	//##ModelId=48203056013E
	void DeleteGeometry(UGRecordset *pRs,				//��¼��
						UGDatasetVector * pDtV);			//���ݼ�

};

}
#endif // !defined(AFX_UGDATAHISTORY_H__2D9823AA_E642_44D1_980A_A3807F5DD64F__INCLUDED_)

