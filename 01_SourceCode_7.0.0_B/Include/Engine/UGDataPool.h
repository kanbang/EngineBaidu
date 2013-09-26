// UGDataPool.h: interface for the UGDataPool class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDATAPOOL_H__C7A7F855_B011_4769_8E30_FD51EEF9A26D__INCLUDED_)
#define AFX_UGDATAPOOL_H__C7A7F855_B011_4769_8E30_FD51EEF9A26D__INCLUDED_

#include "Base/ogdcdefs.h"
#include "Base/OgdcString.h"
#include "Engine/UGDatasetVector.h"
#include "Engine/UGDataSource.h"

//=====================================================================================
#define EVTINFTB		_U("EventInfo")			//���������¼�����Ϣ�ı���
#define EVTTB			_U("EventTable")			//Ψһ���¼������
#define EVTTBNAME		_U("EventTbName")		//�¼���ı���
#define EVTTBID			_U("EvtTbID")			//�¼����id
#define CUREVTID		_U("CurrentEvt")		//��ǰ�¼���id
#define EVTCOUNT		_U("EventCount")		//�¼�����Ŀ
#define LASTEVTID		_U("LstEventID")		//���µ�EventID
#define FIRSTEVTID		_U("FrtEventID")		//�����EventID

#define OBJINFTB		_U("ObjInf")			//�������ж������Ϣ�ı���
#define OBJTBNAME		_U("ObjTbName")			//�����ı���
#define DATASETHANDLE   _U("DatasetHandle")         //���ݼ���ָ��
#define OBJTBID			_U("ObjTbID")			//������ID
#define OBJTBREF		_U("ObjTbRef")			//��������ü���
#define OBJTBISSDB      _U("objTbIsSDB")		//�Ƿ񱣴���sdb���ݼ�������	
#define OBJTBHASSTYLE   _U("objTbHasStyle")	    //�Ƿ���[smEvtGeoStyle]�ֶ�

#define	EVTID			_U("EventID")			//�¼���id
#define EVTACTION		_U("EventAction")       //�¼���Ӧ��Actionֵ
#define EVTLAYER		_U("EventLayer")		//�¼���������ͼ��
#define EVTNOTE			_U("EventNote")			//�¼���˵��
#define EVTORDERID		_U("EventOrdID")		//�¼��Ⱥ�˳��
#define SUBEVTID		_U("SubEventID")		//���¼���id��added by xielin ����һ���¼����м������¼������

#define	OBJID			_U("ObjectID")		//�����id
#define EVTOPERATOR		_U("ObjOperator")		//�¼��ж��������Ĳ���
#define EVTGEOINDEX		_U("ObjIndexPos")	    //�¼��м��ζ�����sdb�е�����

#define NOTTHISTB     0						//������
#define EVTTYPETB		1						//�¼���	
#define OBJTYPETB     2						//�����

#define TEXTFIELDSIZE   80						//�ı����͵��ֶγ���

#define HANDLETEXTSIZE  /*8*/	10 				//��Ϊudb��֧��8���ֽڵ����ͣ���ָ��ֻ����text����  //Mao_Wang�޸������������Ϊ����vc9�±߳���Ϊ9

#define SDBENGINE       1                       //�Ƿ�ʱSDB����
#define GEOHASSTYLE     2                       //���ζ����Ƿ���SYTLE
//=====================================================================================



namespace UGC
{

//##ModelId=4820305503C8
class ENGINE_API UGDataPool  
{
public:
	//##ModelId=4820305503C9
	//! \brief ���캯��
	UGDataPool();
	//##ModelId=4820305503CA
	//! \brief Ϯ������
	virtual ~UGDataPool();

public:
	//##ModelId=4820305503D8
	//! \brief ���һ���¼��� 
	UGbool ClearEvtTable(	                        //���һ���¼��� 
		UGString strEvtTbName);                  //�¼��������

	//##ModelId=4820305503DA
	//! \brief ͨ��һ�����ݼ����������
	UGbool CreateObjectTableFromDataset(          //ͨ��һ�����ݼ���������� 
		UGDatasetVector * pDtV);

	//##ModelId=4820305503DC
	//! \brief �����������ݿ�,�������Ϊ�գ�ϵͳ����һ�����������
	UGbool CreateDatabase(						//�����������ݿ�,�������Ϊ�գ�ϵͳ����һ�����������
		 UGString strDbName=_U(""));				//���ݿ���
	//##ModelId=482030560000
	//! \brief �رղ�ɾ�����ݿ�
	void DestoryDatabase();						//�رղ�ɾ�����ݿ�
	//##ModelId=482030560001
	//! \brief �����ݿ�
	UGbool OpenDatabase();						//�����ݿ�
	//##ModelId=482030560002
	//! \brief �ر����ݿ�
	UGbool CloseDatabase();						//�ر����ݿ�

	//##ModelId=48203056000F
	//! \brief ͨ�����ID����ñ���
	UGbool GetTbNameFromID(	                    //ͨ�����ID����ñ���
		UGString & strTbName,					//����
		UGint  nTbType,							//������ͣ�SMEVTTYPETB���¼�����SMOBJTYPETB�������
		const UGint & nTbID);					//���ID
												//�ɹ�����TRUE,ʧ�ܷ���FALSE

	//##ModelId=482030560013
	//! \brief ȡ��һ����Ĵ�С  
	UGint GetTbSize(                             //ȡ��һ����Ĵ�С   
		UGString strTbName);                    //����  
	
	//##ModelId=482030560015
	//! \brief �ж�һ���������
	UGint GetTbType(								//�ж�һ���������
		UGString strTableName,                   //����
		UGint & lTableID);					    //���ID
												//�ú�������ֵ����:
	                                            //-1:�����ˣ����ݿ�û�д�
												//SMNOTTHISTB�������ڣ�
												//SMEVTTYPETB��Event��
												//SMOBJTYPETB, Object��

	//##ModelId=48203056001F
	//! \brief ����object����ȡ�����ݼ���ָ��
	UGbool GetDatasetHandleFromObjTbName(	            //����object����ȡ�����ݼ���ָ��
		const UGString & strObjTbName,           //�������
		UGlong & lDatasetHandle);                //���ݼ�ָ��

	//##ModelId=482030560022
	//! \brief �������ݼ�ָ��ȡ��obj�������
	UGbool GetObjTbNameFromDatasetHandle(             //�������ݼ�ָ��ȡ��obj�������
		const UGlong & lDatasetHandle,           //���ݼ�ָ��
		UGString & strObjTbName);                //����������
	
	//##ModelId=482030560025
	//! \brief �½�һ��EventTable
	UGbool CreateEventTable(	                    //�½�һ��EventTable
		UGString strTbName,                      //EventTable�ı���
		UGFieldInfos * pFieldInfoList);       //�ֶ��б�

	//##ModelId=482030560028
	//! \brief ɾ��һ�������ͼ�����ı�����ͼ
	UGbool DeleteEventTable(						//ɾ��һ�������ͼ�����ı�����ͼ
		                                        //�ر�ʱҪ��ס������Ŷ
		UGString strTableName);					//����
	
	
	
	//##ModelId=48203056002F
	//! \brief �������ݿ������еı�
	UGbool Purge();								//�������ݿ������еı�

	//*******************************************************************************************//
	//һ��objTable�����ݼ�һһ��Ӧ����objTable��Ӧ�����ݼ���������ͼ��ȫ���ر�ʱ����ɾ���˶���� //
	//*******************************************************************************************//	
	//##ModelId=482030560030
	//! \brief ɾ��һ�����漸�ζ��������Եı�
	UGbool DeleteObjTable(						//ɾ��һ�����漸�ζ��������Եı�
	                                        	//��һ��ͼ�㱻�ɵ�ʱ����Ҫ���ô˱�
		UGString strObjTbName); 				    //ͼ����

	//##ModelId=482030560032
	//! \brief �ͷ�һ�������,���ݼ��ͷŵ�ʱ���Ӧ�Ķ������ͷ�
	UGbool ReleaseObjTable(						//�ͷ�һ�������,���ݼ��ͷŵ�ʱ���Ӧ�Ķ������ͷ�
		UGDataset* pDt);					//����
		
	//##ModelId=482030560034
	//! \brief ��������ܱ�����ٸ��༭Event
	UGint SetMaxEventCount(						//��������ܱ�����ٸ��༭Event
		 UGint lEventCount);						//Event�ĸ���
	//##ModelId=48203056003F
	//! \brief ȡ������ܱ�����ٸ��༭Event
	UGint GetMaxEventCount();					//ȡ������ܱ�����ٸ��༭Event
	//##ModelId=482030560040
	//! \brief ��������ܱ�����ٸ��༭���󣨼�¼��
	UGint SetMaxEventSize(						//��������ܱ�����ٸ��༭���󣨼�¼��
		 UGint lEventSize);						//Event�ĸ���
	//##ModelId=482030560042
	//! \brief ȡ������ܱ�����ٸ��༭���󣨼�¼��
	UGint GetMaxEventSize();						//ȡ������ܱ�����ٸ��༭���󣨼�¼��

	//##ModelId=482030560043
	//! \brief 
	UGDatasetVector* GetEventInfoDv();
	
	//##ModelId=48203056004E
	//! \brief 
	UGDatasetVector* GetObjInfoDv();


protected: 
	//##ModelId=48203056004F
	UGString m_strDbName;						//���ݿ��ļ�������	
	//##ModelId=482030560050
	UGint m_nNextObjTbKey;						//���ɵ���һ�������Ĺؼ���
public:
	//##ModelId=482030560051
	UGint m_nMaxEventCount;						//���ı���༭�¼��ĸ���
	//##ModelId=482030560052
	UGint m_nMaxEventSize;						//һ��������󱣴�༭���󣨼�¼���ĸ���
	//##ModelId=48203056005D
	UGDataSource* m_pDatasource;

};


}
#endif // !defined(AFX_UGDATAPOOL_H__C7A7F855_B011_4769_8E30_FD51EEF9A26D__INCLUDED_)

