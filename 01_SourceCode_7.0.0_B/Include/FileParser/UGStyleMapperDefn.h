#ifndef _UGSTYLEMAPERDEFN_INCLUDE_H
#define _UGSTYLEMAPERDEFN_INCLUDE_H

#include "Stream/ugdefs.h"
#include "Toolkit/UGThread.h"

namespace UGC {



//! \brief ���Ŷ��ղ���
//! \remarks ��ע��Ϣ��
class UGSymbolParam
{
public:
	
	UGSymbolParam(){dAngle = 0.0; dScale=0.0;}	
	UGSymbolParam(const UGSymbolParam& param);
	UGSymbolParam& operator=(const UGSymbolParam& param);
	UGbool operator==(const UGSymbolParam& param);

	UGString strId; // ���ŵ����ƻ��,����
	UGString strGroup; // �������ڵķ��飬��ѡ
	UGdouble dAngle; // ��ת�ǣ���ѡ
	UGString strColor; // ������ɫ������16���Ʊ��(#RRGGBB),��ѡ
	UGdouble dScale; // �������ű���
};


//! \brief ���Ͷ��ղ���
//! \remarks ��ע��Ϣ��
class UGLineStyleParam
{
public:

	UGLineStyleParam(){dWidth=0.0;}
	UGLineStyleParam(const UGLineStyleParam& param);
	UGLineStyleParam& operator=(const UGLineStyleParam& param);
	UGbool operator==(const UGLineStyleParam& param);

	UGString strId; // �������ƻ��,����
	UGString strColor; // ������ɫ,����16���Ʊ��(#RRGGBB),��ѡ
	UGdouble dWidth; // ���ʿ�ȣ���ѡ
};


//! \brief �������ղ���
//! \remarks ��ע��Ϣ��
class UGFillStyleParam
{
public:

	UGFillStyleParam(){nAngle=0;}
	UGFillStyleParam(const UGFillStyleParam& param);
	UGFillStyleParam& operator=(const UGFillStyleParam& param);
	UGbool operator==(const UGFillStyleParam& param);

	UGString strId; // ��������ƻ��
	UGshort nAngle; // ��ת��,��λ0.1��
	UGString strFcolor; // ���ǰ��ɫ
	UGString strBcolor; // ��䱳��ɫ
};

//! \brief ������ղ���
//! \remarks ��ע��Ϣ��
class UGFontParam
{
public:

	UGFontParam(){strAngle=_U("");dxFactor=0.0;dyFactor=0.0;}
	UGFontParam(const UGFontParam& param);
	UGFontParam& operator=(const UGFontParam& param);
	UGbool operator==(const UGFontParam& param);

	UGString strId; // ��������
	UGString strAngle; // ������ת��
	UGdouble dxFactor; // x�������ű���
	UGdouble dyFactor;// y�������ű���
	UGString strFcolor; // ����ǰ��ɫ
	UGString strBcolor; // ���屳��ɫ
};



class FILEPARSER_API UGStyleTable
{
public:
	
	UGStyleTable(){}
	UGStyleTable(const UGStyleTable& tmp);
	void operator=(const UGStyleTable& tmp);
	~UGStyleTable();

	UGbool Save(const UGString& strfilePath);

	void AddSymbol(UGSymbolParam* extend, UGSymbolParam* our);
	UGSymbolParam* FindSymbol(const UGSymbolParam& symbol, UGbool bExtend=TRUE);

	void AddLineStyle(UGLineStyleParam* extend, UGLineStyleParam* our);
	UGLineStyleParam* FindLineStyle(const UGLineStyleParam& lineStyle, UGbool bExtend=TRUE);

	void AddFillStyle(UGFillStyleParam* extend, UGFillStyleParam* our);
	UGFillStyleParam* FindFillStyle(const UGFillStyleParam& fillStyle, UGbool bExtend=TRUE);

	void AddFontStyle(UGFontParam* extend, UGFontParam* our);
	UGFontParam* FindFontStyle(const UGFontParam& fontStyle, UGbool bExtend=TRUE);

	void Clear();

protected:

	// ���Ŷ��ղ���
	UGArray<UGSymbolParam*> m_arrSymbolExtend;
	UGArray<UGSymbolParam*> m_arrSymbolOur;

	// ���Ͷ��ղ���
	UGArray<UGLineStyleParam*> m_arrLineStyleExtend;
	UGArray<UGLineStyleParam*> m_arrLineStyleOur;

	// �������ղ���
	UGArray<UGFillStyleParam*> m_arrFillStyleExtend;
	UGArray<UGFillStyleParam*> m_arrFillStyleOur;

	// ��������ղ���
	UGArray<UGFontParam*> m_arrFontExtend;
	UGArray<UGFontParam*> m_arrFontOur;

};

class FILEPARSER_API UGStyleMapMgr
{
public:

	UGStyleMapMgr(UGStyleTable* pStyleTable = NULL){m_pStyleTable = pStyleTable;}
	UGStyleMapMgr(const UGStyleMapMgr& tmp)
	{
		if( m_pStyleTable == NULL )
		{
			m_pStyleTable = new UGStyleTable;
		}
		if( m_pStyleTable )
		{
			*m_pStyleTable = *tmp.m_pStyleTable;
		}
	}
	void operator=(const UGStyleMapMgr& tmp)
	{
		if( m_pStyleTable == NULL )
		{
			m_pStyleTable = new UGStyleTable;
		}
		if( m_pStyleTable )
		{
			*m_pStyleTable = *tmp.m_pStyleTable;
		}
	}
	~UGStyleMapMgr(){Close();}

	//! \brief �򿪷������ļ�	
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGint Open(const UGString& strStylePath);	

	//! \brief �ر��ļ�	
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void Close();


	//! \brief ���ݲ��յĶ��ղ����õ�һ�����Ŷ���	
	//! \param  symbolParam [in] �ɲ��յĶ��ղ���
	//! \param  bExtend [in] ����Ķ��ղ����Ƿ����ⲿ�ġ�
	//! \return ������ⲿ�Ķ��ղ���������SuperMap���Ŷ��ա�
	//! \remarks ��
	//! \attention ��
	UGSymbolParam* GetSymbolStyle(const UGSymbolParam& symbolParam, UGbool bExtend = TRUE) const;

	//! \brief ���ݲ��յĶ��ղ����õ�һ�����Ͷ���	
	//! \param  symbolParam [in] �ɲ��յĶ��ղ���
	//! \param  bExtend [in] ����Ķ��ղ����Ƿ����ⲿ�ġ�
	//! \return ������ⲿ�Ķ��ղ���������SuperMap���Ͷ��ա�
	//! \remarks ��
	//! \attention ��
	UGLineStyleParam* GetLineStyle(const UGLineStyleParam& symbolParam, UGbool bExtend = TRUE) const;


	//! \brief ���ݲ��յĶ��ղ����õ�һ��������	
	//! \param  symbolParam [in] �ɲ��յĶ��ղ���
	//! \param  bExtend [in] ����Ķ��ղ����Ƿ����ⲿ�ġ�
	//! \return ������ⲿ�Ķ��ղ���������SuperMap�����ա�
	//! \remarks ��
	//! \attention ��
	UGFillStyleParam* GetFillStyle(const UGFillStyleParam& symbolParam, UGbool bExtend = TRUE) const;


	//! \brief ���ݲ��յĶ��ղ����õ�һ���������	
	//! \param  symbolParam [in] �ɲ��յĶ��ղ���
	//! \param  bExtend [in] ����Ķ��ղ����Ƿ����ⲿ�ġ�
	//! \return ������ⲿ�Ķ��ղ���������SuperMap������ա�
	//! \remarks ��
	//! \attention ��
	UGFontParam* GetFontStyle(const UGFontParam& symbolParam, UGbool bExtend = TRUE) const;
	
protected:

	UGint ParserSymbol(const UGStrings& arrSymbol);
	void ParserSymbolItem(const UGStrings& arrItem, UGSymbolParam* symbolParam);

	UGint ParserLineStyle(const UGStrings& arrLineStyle);
	void ParserLineStyleItem(const UGStrings& arrItem, UGLineStyleParam* lineParam);

	UGint ParserFillStyle(const UGStrings& arrFillStyle);
	void ParserFillStyleItem(const UGStrings& arrItem, UGFillStyleParam* fillParam);

	UGint ParserFont(const UGStrings& arrFont);
	void ParserFontItem(const UGStrings& arrItem, UGFontParam* fontParam);

private:

	//! \brief  ������ķ��Ŷ��ձ������ֽ���Զ��Ÿ�����������	
	//! \param  strIn [in] 
	//! \param  bExtend [out] 
    //! \param  arrOur [out] 
	//! \return 
	//! \remarks ��
	//! \attention ��
	UGbool AnalyseStyleItem(const UGString& strItemIn, UGStrings &arrExtend, UGStrings &arrOur);

	UGStyleTable * m_pStyleTable;
};


	
}
#endif //_UGSTYLEMAPERDEFN_INCLUDE_H


