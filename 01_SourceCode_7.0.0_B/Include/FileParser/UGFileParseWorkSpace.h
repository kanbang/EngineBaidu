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
//!  \author tangzq ��ʽת���顣
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
#if !defined(AFX_UGFileParseWorkSpace_H__9D5BD937_D091_4D5F_957C_94B8A7A74D92__INCLUDED_)
#define AFX_UGFileParseWorkSpace_H__9D5BD937_D091_4D5F_957C_94B8A7A74D92__INCLUDED_

#include "Geometry/UGFeature.h"
#include "UGFileParse.h"
#include "FileParser/UGVectorConfigParams.h"
#include "Toolkit/UGTextStyle.h"

namespace UGC {

class UGFileParseWorkSpace;
class UGDataSource;

class FILEPARSER_API UGWorkSpaceFileLayer: public UGFileLayer
{
public:
	UGWorkSpaceFileLayer(UGFileParseWorkSpace* ws){m_pWS = ws;}

	UGbool ImportConf(UGDataSource* db, const UGImportParams& importParams, UGArray<UGString>& strSucMapNames);

public:
	virtual FILELAYER_TYPE GetType(){return UGFileLayer::FL_CONFIG;}

private:
	UGFileParseWorkSpace* m_pWS;

};

//! \brief ʸ���ļ��������ࡣ
class FILEPARSER_API UGFileParseWorkSpace : public UGFileParser  
{
	friend class UGWorkSpaceFileLayer;
	friend class UGFileParseToolkit;
public:

	//! \brief ���캯����
	UGFileParseWorkSpace();
	
	//! \brief ����������
	virtual ~UGFileParseWorkSpace();	
	
	virtual UGFileType::EmGroup GetFileGroup() const;

public:
	enum DisplayType{
		Off , //����ʾ
		Graphic , //ԭͼ����ʽ
		Global , //��ʾ���ǵ���ʾ
		Value, //ר��ͼ
	};
	enum ThematicType{
		noneThemes,//û��
		ranges, //�ȼ�
		bar, //ֱ��ͼ
		pie, //��ͼ
		graduated, //�ȼ�
		density, //ɢ��ͼ
		individual, //��ֵ
	};
	enum TXT_ALIGN{
		TXT_RIGHTDOWN=0,//����,Supermap����������
		TXT_CENTERDOWN,//����,SuperMap����������
		TXT_LEFTDOWN,//���ϣ�Supermap����������
		TXT_RIGHTLINE,//�����,SuperMap�������һ���
		TXT_CENTERLINE,//����
		TXT_LEFTLINE,//�һ���,SuperMap�����������
		TXT_RIGHTUP,//����,SuperMap����������
		TXT_CENTERUP,//���£�SuperMap����������
		TXT_LEFTUP,//���£�SuperMap����������
		TXT_RIGHTCENTER,//���У�SuperMap����������
		TXT_CENTER,//��
		TXT_LEFTCENTER,//����,SuperMap����������
	};

	struct ThemeRange
	{	
		ThemeRange()
		{
			isDefault = FALSE;
			start	  = 0.0;
			end		  = 0.0;
		}
		UGbool isDefault;
		UGdouble start;
		UGdouble end;
		UGStyle style;
	};

	struct ThematicLayer
	{	
		ThematicLayer()
		{
			type    = UGFileParseWorkSpace::noneThemes;
			id      = 0;
			map     = 0;
			density = 0;
			angle	= 0.0;
			column  = _U("");
			styles.RemoveAll();
			individualRange.RemoveAll();
			
		}
		ThematicType type;
		UGint id;
		UGString column;
		UGint map;
		UGArray<ThemeRange> ranges;
		UGint density;
		UGArray<UGStyle> styles;
		UGDict<UGString, UGStyle> individualRange;
		UGdouble angle;

	};

	struct LabelConf{
		LabelConf()
		{	
			overlap    = FALSE;
			autoLabel  = FALSE;
			alongPath  = FALSE;
			visibility = FALSE;
			position   = 1;
			LabelminZoom = 0.0;
			LabelmaxZoom = 0.0;
			column		 = _U("");
			LabelzoomUnit = _U("");
			styles.RemoveAll();
			style_ids.RemoveAll();
			IsVisbilityHasZoom = FALSE;
		}
		~LabelConf()
		{
			styles.RemoveAll();
			style_ids.RemoveAll();
		}
		UGbool autoLabel; //�Ƿ��Զ���ע
		UGbool alongPath; //�Ƿ����߱�ע
		UGbool visibility; //��ע�Ƿ���ʾ
		UGbool IsVisbilityHasZoom;
		UGString column; //Ҫ��Label���ֶ�

		UGbool overlap;//�Ƿ�ѹ��
		UGTextStyle style;//������ʽ
		UGint position;//���뷽ʽ

		//{{{ [9/6/2010 zhongdz] add
		UGArray<UGint> style_ids;
		UGArray<UGTextStyle> styles; 
		//}}}
		UGdouble LabelminZoom;//��ע����С��ʾ
		UGdouble LabelmaxZoom;//��ע�������ʾ
		UGString LabelzoomUnit;//��ע�ĵ�λ
	};

	struct worStyle 
	{
		UGint styleid;
		UGint nwidth;
		UGint ncolor;
		worStyle(){
			styleid=nwidth=ncolor=-1;
		}
	};

	struct worSymbol{
		UGint styleid;
		UGint ncolor;
		UGint nsize;
		UGString strfont;// ���ŵķ���
		UGdouble dangle;
		worSymbol(){
			styleid=ncolor=nsize=-1;
			dangle = 0;
		}
	};

	struct worGlobalStyle 
	{
		worStyle globalPen; //global pen��ʽ
		worStyle globalBrush; //global brush��ʽ
		worSymbol globalSymbol; //global symblo��ʽ
		worStyle globalLine; //global line��ʽ
	};


	struct WorLayer
	{	
		WorLayer()
		{	
			map  = 0;
			name = _U("");
			tab  = _U("");	
			minZoom = 0.0;
			maxZoom = 0.0;
			crossOp = FALSE;
			dispType = UGFileParseWorkSpace::Off;
			zoomUnit = _U("");
			themes.RemoveAll();
		}
		~WorLayer()
		{
			themes.RemoveAll();
		}
		UGString name;//����(��Ӧ)
		UGString tab;//����tab
		//UGString data;//��Ӧ����(ʵ�ʴ洢�����ݿ����������)
		DisplayType dispType; //��ʾ��ʽ		
		worGlobalStyle globalstyle;// global style��ʽ
		UGArray<ThematicLayer> themes;//ר��ͼ��

		UGbool crossOp;//��Ҫ��Ҫ�����Ż�

		LabelConf label;
		UGint map; // ������ͼ

		UGdouble minZoom;//��С��ʾ
		UGdouble maxZoom;//�����ʾ
		UGString zoomUnit;//zoom��λ
	};

	struct WorMapInfo
	{	
		WorMapInfo()
		{
			name     = _U("");
			scale    = 0.0;
			centerX  = 0.0;
			centerY  = 0.0;
			winWidth = 0.0;
			layers.RemoveAll();
			winWidthUnit = _U("");
		}
		~WorMapInfo()
		{
			layers.RemoveAll();
		}

		UGString name;
		UGPrjCoordSys sr;
		UGdouble centerX;
		UGdouble centerY;
		UGdouble scale;//������
		//UGString zoomUnit;//��λ
		UGArray<WorLayer> layers;

		UGdouble winWidth; //���ڴ�С
		UGString winWidthUnit; //���ڴ�С��λ
	};

	//! \brief ������Ҫ�ǹ����ռ��ļ���ʽ�Ľ����ࡣ
	class UGWorParser
	{
	public:
		//! \brief ��ȡ�ļ������н���
		virtual UGbool Read(UGString filename,UGString::Charset charset, UGString stymapFilePath) = 0;

		//! \brief ��ȡҪ�����ж��ٸ�tab
		virtual void GetLayers(UGArray<UGString>& tabs) = 0;

		//! \brief ��ȡҪ�����ж��ٸ�ͼ��
		virtual void GetLayerNames(UGArray<UGString>& tabnames) = 0;

		//! \brief ��ȡ��ͼ��
		virtual UGint GetMapCount() = 0;

		//! \brief ��ȡһ����ͼ�����ͼ�����ݼ���
		virtual void GetLayers(UGint iMap, UGArray<WorLayer>& layers) = 0;

		//void BindLayerData(const UGString& name, UGArray<UGString> datas);

		virtual UGbool GetMapInfo(UGint iMap, WorMapInfo& info) = 0;
	};

protected:
	//////////////////////////////////////////////////////////////////////////
	// ��
	//////////////////////////////////////////////////////////////////////////
	virtual UGbool ImportConf(UGDataSource* db, const UGImportParams& importParams, UGArray<UGString>& strSucMapNames) = 0;

protected:
	//�����ļ�������
	UGWorParser* m_parser;

};

} //namespace UGC

#endif // !defined(AFX_UGFileParseWorkSpace_H__9D5BD937_D091_4D5F_957C_94B8A7A74D92__INCLUDED_)

