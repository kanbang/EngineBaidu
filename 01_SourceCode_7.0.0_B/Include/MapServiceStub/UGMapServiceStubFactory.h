
#if !defined(AFX_UGMAPSERVICESTUBFACTORY_H__1885519B_9074_4676_8294_31061A9FCB47__INCLUDED_)
#define AFX_UGMAPSERVICESTUBFACTORY_H__1885519B_9074_4676_8294_31061A9FCB47__INCLUDED_

#include "MapServiceStub/UGMapServiceStub.h"

namespace UGC 
{

//! \brief ����������񹤳����࣬�������Ĵ��������๤������
class MAPSERVICESTUB_API UGMapServiceStubFactory  
{
public:
	UGMapServiceStubFactory();
	virtual ~UGMapServiceStubFactory();

public:
	//! \brief �����ļ�������(�����ļ���������)
	virtual UGMapServiceStub* CreateMapServiceStub(UGint nFileType) const=0;	

	//! \brief �õ��ܹ�֧�ֵ��ļ����͡�
	virtual void GetSupportMapServiceTypes(UGArray<UGint>& arrServiceTypes) const=0;	
	
	//! \brief �õ�������ơ�
	virtual UGString GetName() const=0;	
	
public:		
	//! \brief ɾ���ļ������ࡣ
	virtual void DestroyMapServiceStub(UGMapServiceStub*& pWebStub) const;	

	//! \brief �Ƿ�֧�ֵ��ļ����͡�
	virtual UGbool IsSupportMapServiceType(UGint nServiceType) const;		
	
};

} //namespace UGC


#endif // !defined(AFX_UGMAPSERVICESTUBFACTORY_H__1885519B_9074_4676_8294_31061A9FCB47__INCLUDED_)


