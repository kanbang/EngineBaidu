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


#if !defined(AFX_UGBAIDUMAPSSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
#define AFX_UGBAIDUMAPSSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_

#include "MapServiceStub/UGMapServiceStub.h"

namespace UGC 
{
	class UGHMACSHA1;
//! \brief ����������ࡣ
//! \remarks �����йط�������Ķ�Ҫ�̳д��ࡣ
class MAPSERVICESTUB_API UGBaiDuMapsStub : public UGMapServiceStub 
{
public:
	//! \brief ���캯����
	UGBaiDuMapsStub();

	//! \brief ����������
	virtual ~UGBaiDuMapsStub();
	
public:
	//! \brief �򿪷���
	//! \param impParams [in]��
	//! \return �ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention ���ط���ǰ���á�
	virtual UGbool Open(const UGMapServiceParams* impParams, UGbool bReSave = TRUE);

protected:

	//! \brief ����URL����
	//! \param tileInfo[in]����URL����Ƭ
	//! \param strURL[out]�����URL
	virtual void GenerateURL(const UGTileInfo& tileInfo, UGString& strURL);
    
	//! \brief ����URLʱ�Ƿ����TileInfo������
	virtual UGbool IsGenerateURLByTileInfo(){return TRUE;}
    
    //! \brief ��ǰ�����ͼ����
	UGString m_strMapType;
    
    //! \brief ��õ�ͼ�����߼���
	 UGint GetBaiDuMapsZoom( UGdouble dScale);
    
	//! \brief ��ȡ���ݼ�����
    //! \param strResName ��ȡ�����ݼ�����
    //! \param nMapType ��ͼ����
    //! \param nDataVersion ���ݰ汾 
	void GetResDataName(UGString strMapType, UGString &strResName, UGint &nMapType,UGint& nDataVersion);
private:
	//! \brief  ����3dlayer URl
	//! \Param tileInfo[in] ����URL����Ƭ��Ϣ
	//! \ Param strURL[out] ���ɵ�URL
	void GenerateURL3D(const UGTileInfo& tileInfo,UGString & strURL);
	//! \brief �Ƿ�����ά���е�ͼ
	//!\ \return �������ά��ͼ����Ϊtrue,���򷵻�Ϊfalse

	UGbool Is3DCityMap(const UGString& strMapType);

private: 

	//! \brief �������Ʊ�ʶ
	UGString m_strCityMark;
	//! \brief ���б��
    UGint m_nNumber;

};

} //namespace UGC

#endif // !defined(AFX_UGBAIDUSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)

