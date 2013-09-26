/*! \file	 UGQueryDef.h
 *  \brief	 ��ѯ������
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGQueryDef.h,v 1.8 2009/11/05 09:22:23 siyh Exp $
 */

#include "Geometry/UGGeometry.h"
#include "Engine/UGEngDefs.h"
#include "OGDC/OgdcQueryDef.h"

#ifndef UGQUERYDEF_H
#define UGQUERYDEF_H

namespace UGC
{

//! \brief ��ѯ������
//##ModelId=482030500290
class ENGINE_API UGQueryDef : public OgdcQueryDef
{
public:
	//! \brief  ���캯��
	//##ModelId=482030500292
	UGQueryDef();
	//! \brief  ��������
	//##ModelId=48203050029F
	~UGQueryDef();
	
	//##ModelId=4820305002AF
	void operator=(const UGQueryDef &querydef);

	//##ModelId=4820305002B1
	UGbool operator==(const UGQueryDef &querydef);

	//! \brief  ����ѯ������Ϣ��ΪXML��ʽ
	//! \param nVersion �汾��
	//! \return ������XML��ʽ�ַ���
	//##ModelId=4820305002C0
	UGString ToXML(UGint nVersion) const;

	//! \brief ��XML�н�����ѯ������Ϣ(�洢�����ռ�ʱ���п��ܻ��õ��������滻��ǰ��ͼ��DisplayFilter)
	//! \param strXML XML��ʽ�ַ���
	//! \param nVersion �汾��	
	//##ModelId=4820305002CE
	UGbool FromXML(const UGString& strXML,UGint nVersion);

	//! \brief �ַ���ת��
	UGbool TransCharset(UGString::Charset eCharset);

protected:
	//##ModelId=4820305002DE
	UGString GetQueryType(QueryType nType) const;
	//##ModelId=4820305002E1
	void SetQueryType(UGString strQueryType);

public:
	//! \brief ʱ�����ݵ���ʾʱ���
	//##ModelId=4820305002E3
	UGTime				m_SequenceTime;

	//! \brief �Ƿ��ѯ�������У�Ĭ�ϲ������
	UGbool m_bVertexSeq;
};

}

#endif


