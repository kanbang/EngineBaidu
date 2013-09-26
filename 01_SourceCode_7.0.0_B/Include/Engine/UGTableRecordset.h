// UGTableRecordset.h: interface for the UGTableRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTABLERECORDSET_H__7C95DC17_F28F_441D_A6C8_4AEB7AC45601__INCLUDED_)
#define AFX_UGTABLERECORDSET_H__7C95DC17_F28F_441D_A6C8_4AEB7AC45601__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugdefs.h"
#include "Engine/UGEngDefs.h"

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
#include "OGDC/OgdcRecordset.h"
#include "Element/OgdcFieldInfo.h"
#endif

namespace UGC{

//##ModelId=4820304F030F
#ifdef SYMBIAN60
class ENGINE_APIC UGTableRecordset
#else
class ENGINE_API UGTableRecordset
#endif
 {
public:
	//##ModelId=4820304F031C
	ENGINE_APIF UGTableRecordset();
	//##ModelId=4820304F031D
	virtual ENGINE_APIF ~UGTableRecordset();

public:
	//! \brief �Ƿ��¼��Ϊ��(û�м�¼)
	//##ModelId=4820304F032C
	virtual ENGINE_APIF UGbool IsEmpty(); 

	//! \brief �жϵ�ǰ��¼ָ���Ƿ�ָ��ͷ
	//##ModelId=4820304F032E
	virtual ENGINE_APIF UGbool IsBOF();

	//! \brief �жϵ�ǰ��¼ָ���Ƿ�ָ��β
	//##ModelId=4820304F033C
	virtual ENGINE_APIF UGbool IsEOF();
	
	//! \brief �رռ�¼��
	//##ModelId=4820304F033E
	virtual ENGINE_APIF void Close();

	//! \brief ͨ���ֶ�����ȡ�ֶ�ֵ
	//##ModelId=4820304F0340
	virtual ENGINE_APIF UGbool GetFieldValue(const UGString& strName,UGVariant& varVal);

	//! \brief ͨ��������Ż�ȡ�ֶ�ֵ
	//##ModelId=4820304F034C
	virtual ENGINE_APIF UGbool GetFieldValue(UGint nIndex,UGVariant& varVal);

	//! \brief ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	//##ModelId=4820304F0350
	virtual ENGINE_APIF UGbool SetFieldValue(const UGString& strName,const UGVariant& varVal);
	
	//! \brief ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	//##ModelId=4820304F035D
	virtual ENGINE_APIF UGbool SetFieldValue(const UGString& strName,const UGString& strVal);
	
	//! \brief ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	//##ModelId=4820304F0361
	virtual ENGINE_APIF UGbool SetFieldValue(UGint nIndex,const UGVariant& varVal);

	//! \brief ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	//##ModelId=4820304F036E
	virtual ENGINE_APIF UGbool SetFieldValue(UGint nIndex,	const UGString& strVal);

	//! \brief ͨ���ֶ��������ֶ�ֵΪ��
	//##ModelId=4820304F0372
	virtual ENGINE_APIF UGbool SetFieldValueNull(const UGString& strName);

	//! \brief ͨ�����������ֶ�ֵΪ��
	//##ModelId=4820304F037C
	virtual ENGINE_APIF UGbool SetFieldValueNull(UGint nIndex);

	//! \brief ��֪�ֶ�Ϊbool���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param bValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820304F037F
	virtual ENGINE_APIF UGbool SetBool(UGint nFieldIndex, UGbool bValue = FALSE);
	
	//! \brief ��֪�ֶ�Ϊbool���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param bValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820304F038B
	virtual ENGINE_APIF UGbool SetBool(const UGString& strFieldName, UGbool bValue = FALSE);

	//! \brief ��֪�ֶ�Ϊbool����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820304F038F
	virtual ENGINE_APIF UGbool GetBool(UGint nFieldIndex);

	//! \brief ��֪�ֶ�Ϊbool����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820304F039B
	virtual ENGINE_APIF UGbool GetBool(const UGString& strFieldName);

	//! \brief ��֪�ֶ�Ϊbyte���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param bValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820304F039E
	virtual ENGINE_APIF UGbool SetByte(UGint nFieldIndex, UGbyte bValue = 0); 

	//! \brief ��֪�ֶ�Ϊbyte���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param bValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820304F03AC
	virtual ENGINE_APIF UGbool SetByte(const UGString& strFieldName, UGbyte bValue = 0);
	
	//! \brief ��֪�ֶ�Ϊbyte����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��	
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820304F03B0
	virtual ENGINE_APIF UGbyte GetByte(UGint nFieldIndex);
	
	//! \brief ��֪�ֶ�Ϊbyte����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820304F03BB
	virtual ENGINE_APIF UGbyte GetByte(const UGString& strFieldName);

	//! \brief ��֪�ֶ�ΪShort���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param nValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820304F03BE
	virtual ENGINE_APIF UGbool SetINT16(UGint nFieldIndex, UGshort nValue=0);

	//! \brief ��֪�ֶ�ΪShort���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param nValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820304F03C9
	virtual ENGINE_APIF UGbool SetINT16(const UGString& strFieldName, UGshort nValue=0);

	//! \brief ��֪�ֶ�ΪShort����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820304F03CD
	virtual ENGINE_APIF UGshort GetINT16(UGint nFieldIndex);

	//! \brief ��֪�ֶ�ΪShort����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820304F03D8
	virtual ENGINE_APIF UGshort GetINT16(const UGString& strFieldName);
	
	//! \brief ��֪�ֶ�Ϊint���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param nValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820304F03DB
	virtual ENGINE_APIF UGbool SetINT32(UGint nFieldIndex, UGint nValue=0);
	
	//! \brief ��֪�ֶ�Ϊint���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param nValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500000
	virtual ENGINE_APIF UGbool SetINT32(const UGString& strFieldName, UGint nValue=0);

	//! \brief ��֪�ֶ�ΪInt����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030500004
	virtual ENGINE_APIF UGint GetINT32(UGint nFieldIndex);
	
	//! \brief ��֪�ֶ�ΪInt����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030500007
	virtual ENGINE_APIF UGint GetINT32(const UGString& strFieldName);

	//! \brief ��֪�ֶ�ΪLong���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param lValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050000F
	virtual ENGINE_APIF UGbool SetINT64(UGint nFieldIndex, UGlong lValue=0);
	
	//! \brief ��֪�ֶ�ΪLong���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param lValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500013
	virtual ENGINE_APIF UGbool SetINT64(const UGString& strFieldName, UGlong lValue=0);

	//! \brief ��֪�ֶ�ΪLong����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=48203050001F
	virtual ENGINE_APIF UGlong GetINT64(UGint nFieldIndex);
	
	//! \brief ��֪�ֶ�ΪLong����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030500022
	virtual ENGINE_APIF UGlong GetINT64(const UGString& strFieldName);

	//! \brief ��֪�ֶ�ΪFloat���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param dbalue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500025
	virtual ENGINE_APIF UGbool SetFloat(UGint nFieldIndex, UGfloat dbalue=0);
	
	//! \brief ��֪�ֶ�ΪFloat���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param dbValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050002E
	virtual ENGINE_APIF UGbool SetFloat(const UGString& strFieldName, UGfloat dbValue=0);

	//! \brief ��֪�ֶ�ΪFloat����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030500032
	virtual ENGINE_APIF UGfloat GetFloat(UGint nFieldIndex);
	
	//! \brief ��֪�ֶ�ΪFloat����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030500035
	virtual ENGINE_APIF UGfloat GetFloat(const UGString& strFieldName);

	//! \brief ��֪�ֶ�ΪDouble���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param dbValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050003E
	virtual ENGINE_APIF UGbool SetDouble(UGint nFieldIndex, UGdouble dbValue=0);
	
	//! \brief ��֪�ֶ�ΪDouble���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param dbValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500042
	virtual ENGINE_APIF UGbool SetDouble(const UGString& strFieldName, UGdouble dbValue=0);

	//! \brief ��֪�ֶ�ΪDouble����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030500046
	virtual ENGINE_APIF UGdouble GetDouble(UGint nFieldIndex);
	
	//! \brief ��֪�ֶ�ΪDouble����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=48203050004E
	virtual ENGINE_APIF UGdouble GetDouble(const UGString& strFieldName);

	//! \brief ��֪�ֶ�ΪTime���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param tmValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500051
	virtual ENGINE_APIF UGbool SetTime(UGint nFieldIndex, UGTime tmValue);
	
	//! \brief ��֪�ֶ�ΪTime���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param tmValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500055
	virtual ENGINE_APIF UGbool SetTime(const UGString& strFieldName, UGTime tmValue);

	//! \brief ��֪�ֶ�ΪTime����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=48203050005D
	virtual ENGINE_APIF UGTime GetTime(UGint nFieldIndex);
	
	//! \brief ��֪�ֶ�ΪTime����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030500060
	virtual ENGINE_APIF UGTime GetTime(const UGString& strFieldName);

	//! \brief ��֪�ֶ�ΪDate���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param tmValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500063
	virtual ENGINE_APIF UGbool SetDate(UGint nFieldIndex, UGTime tmValue);
	
	//! \brief ��֪�ֶ�ΪDate���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param tmValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500067
	virtual ENGINE_APIF UGbool SetDate(const UGString& strFieldName, UGTime tmValue);

	//! \brief ��֪�ֶ�ΪDate����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=48203050006F
	virtual ENGINE_APIF UGTime GetDate(UGint nFieldIndex);
	
	//! \brief ��֪�ֶ�ΪDate����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030500072
	virtual ENGINE_APIF UGTime GetDate(const UGString& strFieldName);

	//! \brief ��֪�ֶ�ΪTimeStamp���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param tmValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500075
	virtual ENGINE_APIF UGbool SetTimeStamp(UGint nFieldIndex, UGTime tmValue);
	
	//! \brief ��֪�ֶ�ΪTimeStamp���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param tmValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050007D
	virtual ENGINE_APIF UGbool SetTimeStamp(const UGString& strFieldName, UGTime tmValue);

	//! \brief ��֪�ֶ�ΪTimeStamp����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030500081
	virtual ENGINE_APIF UGTime GetTimeStamp(UGint nFieldIndex);
	
	//! \brief ��֪�ֶ�ΪTimeStamp����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030500084
	virtual ENGINE_APIF UGTime GetTimeStamp(const UGString& strFieldName);

	//! \brief ��֪�ֶ�ΪBinary���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param pValue �ֶ�ֵ [in]��
	//! \param nLength pValue�ĳ��� [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030500087
	virtual ENGINE_APIF UGbool SetBinary(UGint nFieldIndex, UGbyte *pValue, UGint nLength);
	
	//! \brief ��֪�ֶ�ΪBinary���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param pValue �ֶ�ֵ [in]��
	//! \param nLength pValue�ĳ��� [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050008E
	virtual ENGINE_APIF UGbool SetBinary(const UGString& strFieldName, UGbyte *pValue, UGint nLength);

	//! \brief ��֪�ֶ�ΪBinary����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \param nLength �������ֶεĳ���[out]��
	//! \return ��ȡ�Ķ������ֶ�ָ�롣
	//##ModelId=482030500093
	virtual ENGINE_APIF UGbyte* GetBinary(UGint nFieldIndex, UGint& nLength);
	
	//! \brief ��֪�ֶ�ΪShort����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \param nLength �������ֶεĳ���[out]��
	//! \return ��ȡ�Ķ������ֶ�ָ�롣
	//##ModelId=482030500097
	virtual ENGINE_APIF UGbyte* GetBinary(const UGString& strFieldName, UGint& nLength);

	//! \brief ��֪�ֶ�ΪString���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param strValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203050009D
	virtual ENGINE_APIF UGbool SetString(UGint nFieldIndex, UGString strValue);
	
	//! \brief ��֪�ֶ�ΪString���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param strValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305000A1
	virtual ENGINE_APIF UGbool SetString(const UGString& strFieldName, UGString strValue);

	//! \brief ��֪�ֶ�ΪString����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820305000A5
	virtual ENGINE_APIF UGString GetString(UGint nFieldIndex);
	
	//! \brief ��֪�ֶ�ΪString����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820305000A8
	virtual ENGINE_APIF UGString GetString(const UGString& strFieldName);

	//! \brief �ڼ�¼�����ٴβ�ѯ,���ҷ��������ĵ�һ����¼
	//##ModelId=4820305000AC
	virtual ENGINE_APIF UGbool FindFirst(const UGString& strFilter);
	
	//! \brief �ڼ�¼�����ٴβ�ѯ,���ҷ������������һ����¼
	//##ModelId=4820305000AF
	virtual ENGINE_APIF UGbool FindLast(const UGString& strFilter);

	//! \brief �ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	//##ModelId=4820305000B2
	virtual ENGINE_APIF UGbool FindNext(const UGString& strFilter);

	//! \brief �ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	//##ModelId=4820305000B5
	virtual ENGINE_APIF UGbool FindPrev(const UGString& strFilter);

	//! \brief ������Ӧ����,��ǰ������ƶ���¼ָ��
	//##ModelId=4820305000B8
	virtual ENGINE_APIF UGbool Move(UGint nRows);

	//! \brief �ƶ���¼ָ�뵽��ǰ
	//##ModelId=4820305000BC
	virtual ENGINE_APIF UGbool MoveFirst();

	//! \brief �ƶ���¼ָ�뵽���
	//##ModelId=4820305000BE
	virtual ENGINE_APIF UGbool MoveLast();

	//! \brief �����ƶ�һλ��¼ָ��
	//##ModelId=4820305000C0
	virtual ENGINE_APIF UGbool MoveNext();

	//! \brief �����ƶ�һλ��¼ָ��
	//##ModelId=4820305000C2
	virtual ENGINE_APIF UGbool MovePrev();

	//! \brief �ƶ���¼ָ�뵽ָ��λ��
	//##ModelId=4820305000C4
	virtual ENGINE_APIF UGbool MoveTo(UGint nRow);

	//! \brief ��ȡ��¼����
	//##ModelId=4820305000C7
	virtual ENGINE_APIF UGint GetRecordCount();

	//! \brief �ռ������ֶε���Ϣ
	//##ModelId=4820305000C9
	virtual ENGINE_APIF UGbool GetFieldInfos(UGFieldInfos& fieldInfos);
	
	//! \brief ͨ���ֶ�����ȡ�ֶ���Ϣ
	//##ModelId=4820305000CD
	virtual ENGINE_APIF UGbool GetFieldInfo(const UGString& strName,UGFieldInfo& fieldInfo);
	
	//! \brief ͨ������ȡ�ֶ���Ϣ
	//##ModelId=4820305000D1
	virtual ENGINE_APIF UGbool GetFieldInfo(UGint nIndex,UGFieldInfo& fieldInfo);
	
	//! \brief ��ȡ�ֶθ���
	//##ModelId=4820305000D5
	virtual ENGINE_APIF UGint GetFieldCount();

public:

	//! \brief ����������ѯ
	//##ModelId=4820305000D7
	virtual ENGINE_APIF UGbool GetForeignKeysVal(UGArray<UGString> &aryForeignKeys,UGArray<UGVariant> &aryVal);
	//##ModelId=4820305000DB
	//nIndex ��Ҫ���ڱ��浱ǰ����������λ��
	virtual ENGINE_APIF UGbool FetchForeignKeysVal(UGArray<UGVariant> &aryVal,UGint nIndex);

	static ENGINE_APIF UGbool IsFieldValueValid(const UGString& v, UGFieldInfo::FieldType t);
	static ENGINE_APIF UGbool IsFieldValueValid(const UGVariant& v, UGFieldInfo::FieldType t);
	static ENGINE_APIF UGbool StringIsInteger( const UGString& str );

	UGFieldInfos m_FieldInfos;

#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
public:
	//##ModelId=483BB7070265
	OgdcRecordset* GetOgdcRecordset() const;

	//##ModelId=483BB7070271
	UGbool SetOgdcRecordset(OgdcRecordset* pORecordset);
protected:
	//##ModelId=483BB7070273
	OgdcRecordset* m_pOgdcRecordset;
#endif
};

}

#endif // !defined(AFX_UGTABLERECORDSET_H__7C95DC17_F28F_441D_A6C8_4AEB7AC45601__INCLUDED_)


