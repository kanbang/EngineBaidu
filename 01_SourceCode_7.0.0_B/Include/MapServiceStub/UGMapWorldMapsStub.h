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


#if !defined(AFX_UGMAPWORLDMAPSSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
#define AFX_UGMAPWORLDMAPSSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_

#include "MapServiceStub/UGMapServiceStub.h"

namespace UGC 
{
	//! \brief ����������ࡣ
	//! \remarks �����йط�������Ķ�Ҫ�̳д��ࡣ
	class MAPSERVICESTUB_API UGMapWorldMapsStub : public UGMapServiceStub 
	{
	public:
		//! \brief ���캯����
		UGMapWorldMapsStub();

		//! \brief ����������
		virtual ~UGMapWorldMapsStub();

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
		virtual UGint GetServiceType() const	{ return UGMapServiceType::MapWorldMaps; }

	protected:

		//! \brief ����URL����
		//! \param tileInfo[in]����URL����Ƭ
		//! \param strURL[out]�����URL
		//! \return  void
		virtual void GenerateURL(const UGTileInfo& tileInfo, UGString& strURL);

        //! brief  ���ɱ��ط�����URl    
		void GenerateURLLocal(const UGTileInfo& tileInfo, UGString& strURL);

		//! \brief ����URLʱ�Ƿ����TileInfo������
		virtual UGbool IsGenerateURLByTileInfo(){return TRUE;}
       
		//!brief     ���ݼ�����
		UGString m_strMapType;
        
		//!brief   �õ�title�������ڱ����߼���
		//!param[in]   titledata������
	    UGint GetMapWorldMapsZoom(const UGdouble dScale);


		//!\brief �õ�ʵ�ʵı����߼���
		
		UGint GetRealMapWorldMapsZoom(const UGdouble dScale);
       
		//! \brief  �õ����ݼ���Ӧ������Դ����
		//!  \param [in] dataSetName ���ݼ�����
		//!  \param [in] nZoom  �����߼���
		//!  \param [out] resDataName  ������Դ����
		//!   \return  void
		void GetResDataName(const UGString dataSetName, const UGint nZoom, UGString &resDataName);
        
	};

} //namespace UGC

#endif // !defined(AFX_UGSMCLOUDSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)

