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


#if !defined(AFX_UGOPENSTREETMAPSSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
#define AFX_UGOPENSTREETMAPSSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_

#include "MapServiceStub/UGMapServiceStub.h"

namespace UGC 
{
	//! \brief ����������ࡣ
	//! \remarks �����йط�������Ķ�Ҫ�̳д��ࡣ
	class MAPSERVICESTUB_API UGOpenStreetMapsStub : public UGMapServiceStub 
	{
	public:
		//! \brief ���캯����
		UGOpenStreetMapsStub();

		//! \brief ����������
		virtual ~UGOpenStreetMapsStub();

	public:
		//! \brief �򿪷���
		//! \param impParams [in]��
		//! \return �ɹ�����TRUE��ʧ�ܷ���FALSE��
		//! \attention ���ط���ǰ���á�
		virtual UGbool Open(const UGMapServiceParams* impParams, UGbool bReSave = TRUE);

		//! \brief ���ػ�ȡ�������͵ĺ���
		//! \param  [in]
		//! \return 
		//! \remarks 
		//! \attention 
		virtual UGint GetServiceType() const	{ return UGMapServiceType::OpenStreetMaps; }

	protected:
        

		// Function list

		//! \brief ����URL����
		//! \param tileInfo[in]����URL����Ƭ
		//! \param strURL[out]�����URL
		//! \return  void
		virtual void GenerateURL(const UGTileInfo& tileInfo, UGString& strURL);

		//! \brief ����URLʱ�Ƿ����TileInfo������
		virtual UGbool IsGenerateURLByTileInfo(){return TRUE;}
        
		//!brief   �õ�title�������ڱ����߼���
		//!param[in]   titledata������
	    UGint GetOpenStreetMapsZoom(const UGdouble dScale);
      




		//Attribute List

		//!brief     ���ݼ�����
		UGString m_strMapType;


	private:
        
		//! \brief ��������ֲ����������������
		//! \param[in] �����������������
		//! \param �Ƿ���Questlayerͼ�㣬Ĭ�ϲ���
		void GeneRandServerName(UGint nServerNumber,UGString &strServerName,UGbool bQuestlayer);
        
	};

} //namespace UGC

#endif // !defined(AFX_UGSMCLOUDSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)

