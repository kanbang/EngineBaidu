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


#if !defined(AFX_UGWMTSSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
#define AFX_UGWMTSSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_

#include "MapServiceStub/UGMapServiceStub.h"

namespace UGC 
{
//! \brief ����������ࡣ
//! \remarks �����йط�������Ķ�Ҫ�̳д��ࡣ
class MAPSERVICESTUB_API UGWMTSStub : public UGMapServiceStub 
{
public:
	//! \brief ���캯����
	UGWMTSStub();

	//! \brief ����������
	virtual ~UGWMTSStub();
	
public:
	//! \brief �򿪷���
	//! \param impParams [in]��
	//! \return �ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention ���ط���ǰ���á�
	virtual UGbool Open(const UGMapServiceParams* impParams, UGbool bReSave = TRUE);

	//! \brief ���ػ�ȡ�������͵ĺ�����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual UGint GetServiceType() const	{ return UGMapServiceType::WMTS; }

protected:

	//! \brief ����URL
	//! \param tileInfo[in]����URL����Ƭ
	//! \param strURL[out]�����URL
	virtual void GenerateURL(const UGTileInfo& tileInfo, UGString& strURL);

	//! \brief ����URLʱ�Ƿ����TileInfo������
	virtual UGbool IsGenerateURLByTileInfo(){return TRUE;}
	
// 	//! \brief ����ͼ��MapServiceStub��������ͼ���� Ŀǰ����WMTS����Ҫʹ��
// 	//! \param strLayer [in] ͼ�����ơ���
// 	//! \return 
// 	virtual void SetLayer(const UGString& strLayer);

// 	//! \brief ����ͼ��SetTileMatrixSet Ŀǰ����WMTS����Ҫʹ��
// 	//! \param strLayer [in] ͼ�����ơ���
// 	//! \return 
// 	virtual void SetTileMatrixSet(const UGString& strTileMatrixSet);
	
private:

	UGString m_strLayerName;

	map<double, UGString> m_mapOutputScaleCaptions;
	
	//! \brief �Ƿ������ͼ����Ĭ����false
	UGbool m_bisTianDitu;

	//! \brief ��Ƭ������ʽ
	UGString m_strFormat;
};

} //namespace UGC

#endif // !defined(AFX_UGWMTSSTUB_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)

