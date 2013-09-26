// UGFileParserConfigParams.h: interface for the UGFileParserConfigParams class.
//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author ����ǿ��
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////

#ifndef __UGACADIMPORTPARAMS_H__
#define __UGACADIMPORTPARAMS_H__

#include "FileParser/UGVectorConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{
//! \brief Dxf�ĵ���������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGAcadImportParams : public UGVectorImportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGAcadImportParams();

	//! \brief ����������
	//! \remarks ��
	virtual ~UGAcadImportParams();

public:

	//! \brief ��CADģʽ����ʱ�������Ƿ���ԭʼCAD�ֲ�ṹ����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetImportByLayer(UGbool bByLayer = FALSE);

	//! \brief �ж�CAD������ȫͼ���߶�㵼�롣
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetImportByLayer() const;

	//! \brief �����Ƿ������չ���ݡ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetIgnoreExtendData(UGbool bIgnore = TRUE);

	//! \brief ��ȡ�Ƿ������չ���ݡ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetIgnoreExtendData() const;

	//! \brief �����Ƿ���Կ�����ԣ�
	//! \param [in]
	//! \return
	//! \remarks Ĭ�Ϻ���
	//! \attention
	void SetIgnoreBlockAttribute(UGbool bIgnore = TRUE);
    
	//! \brief ��ȡ�Ƿ���Կ�����ԣ�
	//! \param[in]
	//! \return true/false
	//! \attention
	UGbool GetIgnoreBlockAttribute() const;


	//! \brief �����Ƿ����Polyline��LWPline�Ŀ�ȡ�͹����Ϣ
	//! \param bResolve [in]��
	//! \return ��
	//! \remarks ����ΪTRUEʱ������ߵġ�͹�ȡ�������ȡ���Ϣ��ʧ���������������ߡ���
	//! \attention ��
	void SetIgnoreLwplineWidth(UGbool bIgnore = FALSE);

	//! \brief �õ��Ƿ����Polyline��LWPline�Ŀ�ȡ�͹����Ϣ
	//! \param bResolve [in]��
	//! \return ��
	//! \remarks 
	//! \attention ��
	UGbool GetIgnoreLwplineWidth() const;

	//! \brief �����Ƿ�blocks�������������
	//! \param bResolve [in]��
	//! \return ��
	//! \remarks ����ΪTRUEʱ�����顱���󼸺���Ϣ���ԣ����ԡ�����㡱��ʽ���ɵ����
	//! \attention ��
	void SetBlockAsInsertPoint(UGbool bAsPoint = FALSE);

	//! \brief �����Ƿ�blocks�������������
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetBlockAsInsertPoint() const;

	//! \brief �����Ƿ�����ļ��е�����ͼ�㡣
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetIgnoreHiddenLayers(UGbool bIgnore = TRUE);

	//! \brief �õ��Ƿ�����ļ��е�����ͼ�㡣
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetIgnoreHiddenLayers() const;	
	
	//! \brief �����Ƿ����ʵ����ɫ��
	//! \param bIgnoreColor [in]��
	//! \return ��
	//! \remarks ����CAD���ݼ�ʱ�����ú��Զ�����ɫ�������������ɫ���
	//! \attention ��
	void SetIgnoreEntityColor(UGbool bIgnoreColor = FALSE);
	
	//! \brief ��ȡ����ʵ����ɫ��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetIgnoreEntityColor() const;

	//! \brief ��CADģʽ����ʱ�������Ƿ�����߶�������ͷ��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetIgnoreLineStyle(UGbool bIgnore = FALSE);

	//! \brief ��ȡ�Ƿ�����߶�������ͷ��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetIgnoreLineStyle() const;

	//! \brief ��CADģʽ����ʱ�������Ƿ����hatch����������
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetIgnoreFillStyle(UGbool bIgnore = FALSE);

	//! \brief ��ȡ�Ƿ����hatch����������
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetIgnoreFillStyle() const;	


	//! \brief ��CADģʽ����ʱ�������Ƿ���Ե���ŵ��ͣ�shape���ο��ļ���
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention AutoCAD shpae�ļ���ͬ��ESRI��shape�ļ���AutoCAD��shape�洢���Ƿ��ź����嶨�塣
	void SetIgnoreShapeStyle(UGbool bIgnore = TRUE);


	//! \brief ��ȡ�Ƿ���Ե���ŵ��ͣ�shape���ο��ļ���
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention AutoCAD shpae�ļ���ͬ��ESRI��shape�ļ���AutoCAD��shape�洢���Ƿ��ź����嶨�塣	
	UGbool GetIgnoreShapeStyle() const;

	
	//! \brief ����������ݣ��������ݲ����롣
	//! \param FALSE [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetOnlyImportBlock(UGbool bOnlyBlock = FALSE);	

	
	//! \brief ����������ݣ��������ݲ����롣
	//! \param FALSE [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetOnlyImportBlock() const;

	//! \brief ���ú����߿�
	//! \param FALSE [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetIgnoreLineWidth(UGbool bLineWidth = FALSE);	

	//! \brief ���ú����߿�
	//! \param FALSE [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetIgnoreLineWidth() const;	

	//! \brief ����Բ����ϳ����ߵĶ���,Ĭ��ֵΪ73�� ��
	//! \param 73 [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetConstSegs(UGuint nConstSegs = 73);

	//! \brief  ��ȡԲ����ϳ����ߵĶ���,Ĭ��ֵΪ73����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGuint GetConstSegs() const;
	
	//! \brief ���÷����ձ��ļ�·����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetStyleMapFilePath(const UGString& strPath);

	//! \brief ��ȡ�����ձ��ļ�·��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGString GetStyleMapFilePath() const;

	//! \brief ��άʵ���Ƿ�����ά����
	//! \param FALSE [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetImportAs3D(UGbool bImportAs3D = FALSE);	

	//! \brief ��ȡ��άʵ���Ƿ�����ά����
	//! \param [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetImportAs3D();	
	//===================================================
	//! \brief  ��ȡ�Ƿ���Ϊ���в��������ֵĸ���������߶���
	//! \param 
	//! \return 
	//! \remarks 
	//! \attention 
	UGbool GetImportAsParametric();

	//===================================================
	//! \brief  �����Ƿ���Ϊ���в��������ֵĸ���������߶���
	//! \param 
	//! \return   
	//! \remarks 
	//! \attention 
	void SetImportAsParametric(UGbool bImportAsCompound = FALSE);

	//===================================================
	//! \brief  ��ȡ�Ƿ�����չ��¼��XRecord��
	//! \param 
	//! \return   
	//! \remarks 
	//! \attention
	UGbool GetImportXRecord() const;

	//===================================================
	//! \brief  �����Ƿ�����չ��¼��XRecord��
	//! \param 
	//! \return   
	//! \remarks 
	//! \attention
	void SetImportXRecord(UGbool bImportXRecord = FALSE);
protected:

	//! \brief ��ʶCAD������ȫͼ���뻻�Ƕ�㵼�롣
	//! \remarks m_bMLayerImport = FALSE,ȫͼ����
	UGbool m_bMLayerImport;
	
	//! \brief �Ƿ���(DWG/DXF)��չ���ݱ�־��
	UGbool m_bIgnoreXData;

	//! \brief ��ʶ���������������
	//! \remarks ��
	UGbool m_bOnlyImportBlock;

	//! \brief ����ʵ����ɫ��
	//! \remarks ��
	UGbool m_bIgnoreColor;

	//! \brief �����߿�
	//! \remarks ��
	UGbool m_bIgnoreLineWidth;

	//! \brief ���������͡�
	//! \remarks ��
	UGbool m_bIgnoreLineStyle;

	//! \brief �����η��š�
	//! \remarks ��
	UGbool m_bIgnoreShapeSymbol;

	//! \brief ����ͼԪ��䡣
	//! \remarks ��
	UGbool m_bIgnoreHatchFill;

	//! \brief �����Ż�����ߵ��߿�
	//! \remarks ��
	UGbool m_bIgnoreLwplineWidth;

	//! \brief ���ɼ�ʵ�嵼���־��
	//! \remarks ��
	UGbool m_bIgnoreHiddenLayers;

	//! \brief ��ʵ����Ϊ�㵼���־��
	//! \remarks ��
	UGbool m_bBlockAsPointImport;

	//! \brief Բ����ϳ����ߵĶ���,Ĭ��ֵΪ73��
	//! \remarks ��
	UGint m_nConstSegs;

	//! \brief �����ձ��ļ�·����
	//! \remarks ��
	UGString m_strStyleMapPath;

	//! \brief ��άʵ���Ƿ�����ά����
	//! \remarks ��
	UGbool m_bImportAs3D;

	//! \brief �Ƿ���Կ�����Զ���
	//! \remarks  Ĭ��Ϊtrue
    UGbool m_bIgnoreBlockAttribute;

	//! \brief �Ƿ���ɴ����������ֵĸ����߻������
	UGbool m_bImportAsParametric;

	//! \brief �Ƿ�����չ��¼��Ĭ��Ϊfalse
	UGbool m_bImportXRecord;
};

//! \brief Dxf�ĵ����������á�
//! \remarks ��ע��Ϣ��
class FILEPARSER_API UGAcadExportParams : public UGVectorExportParams
{
public:
	//! \brief ���캯����
	//! \remarks ��
	UGAcadExportParams();

	//! \brief ����������
	//! \remarks ��
	~UGAcadExportParams();
public:
	enum EmVersion
	{
//		ACAD09	= 9,//->OdDb::vAC09	R9
//		ACAD10	= 10,//->OdDb::vAC10	R10
		ACAD12	= 12,//->OdDb::vAC12	R11-12
		ACAD13	= 13,//->OdDb::vAC13	R13
		ACAD14	= 14,//->OdDb::vAC14	R14
		ACAD2000= 2000,//->OdDb::vAC15	2000-2002
		ACAD2004= 2004,//->OdDb::vAC18	2004-2006
		ACAD2007= 2007,//->OdDb::vAC21	2007
	};

public:


	//! \brief ��ȡҪ������ʸ�����ݼ��������顣
	//! \param  [in]��
	//! \return ��
	//! \remarks ���ݼ��������顣
	//! \attention Ϊ�˶�����ݼ�����ʹ�á�
	virtual UGbool GetDtNamesBeExported(UGStrings& arrNames) const ;

	//! \brief ����Ҫ������ʸ�����ݼ��������顣
	//! \param  name [in] ���õ����ơ�
	//! \return ��
	//! \remarks ��
	//! \attention Ϊ�˶�����ݼ�����ʹ�á�
	virtual void SetDtNamesBeExported(const UGStrings& arrNames);
	
	//! \brief ��ȡҪ������ʸ�����ݰ汾�š�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGint GetVersion() const;	

	//! \brief ����Ҫ������ʸ�����ݰ汾�š�
	//! \param  nVer [in] ���õİ汾�š�
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetVersion(UGint nVer = ACAD2004);

	//! \brief ���õ�������չ���ݵ��ֶ���Ϣ��
	//! \param fieldInfos [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetExtendDataFieldInfos(const UGFieldInfos& fieldInfos);
	
	//! \brief ��ȡ��������չ���ݵ��ֶ���Ϣ.
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGFieldInfos GetExtendDataFieldInfos() const;

	//! \brief �����Ƿ񵼳���չ���ݣ�Ĭ�ϲ�������
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetExportExtendData(UGbool bIgnore = FALSE);

	//! \brief ��ȡ�Ƿ񵼳���չ���ݡ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetExportExtendData() const;

	//! \brief �����Ƿ񵼳���չ��¼��Ĭ�ϲ�������
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention �������ΪTRUE����CAD�ֶν�����չ��¼����ʽ������
	void SetExportXRecord(UGbool bExportXRecord = FALSE);

	//! \brief ��ȡ�Ƿ񵼳���չ��¼��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetExportXRecord() const;

	//! \brief ���÷����ձ��ļ�·����
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetStyleMapFilePath(const UGString& strPath);

	//! \brief ��ȡ�����ձ��ļ�·��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGString GetStyleMapFilePath() const;



	//! \brief �����Ƿ񵼳������ȵı߽���
	//! \param [in]
	//! \return
	//1 \remarks
	//! \attention
	void SetExportBorder(const UGbool bExpBorder);

	//! \brief ��ȡ�Ƿ񵼳������ȵı߽���
	//! \param
	//! \return ��������߽��߷���true ���򷵻�false
	//! \attention
	UGbool GetExportBorder()const;
protected:
	//! \brief ʸ������Ҫ�������ļ��汾�š�
	//! \remarks ��	
	UGint m_nFileVersion;

	//! \brief ������չ���ݵ��ֶΡ�
	//! \remarks ��
	UGFieldInfos m_xDataFieldInfos;
	//! \brief �����ձ��ļ�·����
	//! \remarks ��
	UGString m_strStyleMapPath;

	//Ҫ���������ݼ���������
	UGStrings m_arrNames;

	//! \brief �Ƿ񵼳�(DWG/DXF)��չ���ݱ�־��
	UGbool m_bExportXData;

	//! \brief �Ƿ񵼳�(DWG/DXF)��չ���ݼ�¼,Ĭ�ϲ�������
	UGbool m_bExportXRecord;

	//! \brief �Ƿ񵼳��߽���
	UGbool m_bExportBorder;
};
} //namespace UGC
#endif // !defined(AFX_UG_PNG_FILEPARSERCONFIGPARAMS_H__INCLUDED_)

