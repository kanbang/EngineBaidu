// UGIMGConfigParams.h: interface for the UGErdasImagineImportParams class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGIMGCONFIGPARAMS_H__3739E9A2_4CD0_41C3_BED7_B7EF1138433F__INCLUDED_)
#define AFX_UGIMGCONFIGPARAMS_H__3739E9A2_4CD0_41C3_BED7_B7EF1138433F__INCLUDED_

#include "FileParser/UGRasterConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace UGC {

//! \brief ErdasImage�ĵ���������á�
class FILEPARSER_API UGErdasImagineImportParams  : public UGRasterImportParams
{
public:

	//! \brief ���캯����
	UGErdasImagineImportParams();

	//! \brief ����������
	virtual ~UGErdasImagineImportParams();

public:
	
	//! \brief �õ��ļ����͡�
	//! \return �ļ����͡�
	virtual inline UGint GetFileType() const { return UGFileType::IMG; }
	
	

};

//! \brief ErdasImage�ĵ����������á�
class FILEPARSER_API UGErdasImagineExportParams  : public UGRasterExportParams
{
public:
	
	//! \brief ���캯����
	UGErdasImagineExportParams();

	//! \brief ����������
	virtual ~UGErdasImagineExportParams();
	
	//! \brief �õ��ļ����͡�
	//! \return �ļ����͡�
	virtual inline UGint GetFileType() const { return UGFileType::IMG; }

	//! \brief �����Ƿ񴴽�����2G��IMG���ݡ�
	//! \remarks ��������ʱ��������������2Gʱ����Ҫ���ô˽ӿڣ����ܵ�������2G��IMG��
	void SetCreateLargeImage(UGbool bCreateLarge = FALSE);	

	//! \brief �õ��Ƿ񴴽�����2G��IMG���ݡ�
	UGbool GetCreateLargeImage() const;	

protected:
	
	UGbool m_bCreateLarge;

};


typedef UGErdasImagineImportParams UGIMGImportParams;
typedef UGErdasImagineExportParams UGIMGExportParams;


} //namespace UGC
#endif // !defined(AFX_UGIMGCONFIGPARAMS_H__3739E9A2_4CD0_41C3_BED7_B7EF1138433F__INCLUDED_)

