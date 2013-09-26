//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class ��
//!  \details ��
//!  \author ����ת���顣
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGSMCLOUDSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
#define AFX_UGSMCLOUDSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_

#include "MapServiceStub/UGMapServiceStub.h"

namespace UGC 
{
//! \brief ����������ࡣ
//! \remarks �����йط�������Ķ�Ҫ�̳д��ࡣ
class MAPSERVICESTUB_API UGSMCloudStub : public UGMapServiceStub 
{
public:
	//! \brief ���캯����
	UGSMCloudStub();

	//! \brief ����������
	virtual ~UGSMCloudStub();
	
public:
	//! \brief �򿪷���
	//! \param impParams [in]��
	//! \return �ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention ���ط���ǰ���á�
	virtual UGbool Open(const UGMapServiceParams* pMapServiceParams, UGbool bReSave = TRUE);

	//! \brief ���ػ�ȡ�������͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual UGint GetServiceType() const	{ return UGMapServiceType::SuperMapCloud; }

protected:

	//! \brief ����URL����ͼ���Ʒ�������URL�ķ�ʽ��
	//! \param nScalePath[in]����URL�ı�����
	//! \param nRow[in]����URL����
	//! \param nCol[in]����URL����
	//! \param strURL[out]�����URL
	//! \attention �Լ��ķ����ֱ�������к��������
	virtual void GenerateURL(const UGuint& nScalePath, const UGint& nRow, const UGint& nCol, UGString& strURL);

	//! \brief ����URLʱ�Ƿ����TileInfo������
	virtual UGbool IsGenerateURLByTileInfo(){return FALSE;}

private:
	//! \brief �������������Ӧ�ĵ�ͼ����
	//! \return ���ص�ͼ���ڵļ���
	UGint GetMapWorldMapsZoom(const UGdouble dScale);
	//! \brief �Ƿ���˽���Ʒ���
	//! �ǹ̶�IP�Ķ���˽�е��Ƶ�ͼ����
	inline UGbool IsPrivateCloud()const
	{return !m_strBaseURL.CompareNoCase(_U("http://supermapcloud.com"))==0;}
	//! \brief �޸ĳ�ͼ�Ʒ���Ļ���ַ
    void GenerateBaseURL(UGString &strBaseURL);
    //! \brief ��ͼ����
	UGString m_strMapName;
	
};

} //namespace UGC

#endif // !defined(AFX_UGSMCLOUDSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)

