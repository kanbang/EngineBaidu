
#ifndef __UGGRIDCONFIGPARAMS_H__
#define __UGGRIDCONFIGPARAMS_H__

#include "FileParser/UGRasterConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC
{
	class FILEPARSER_API UGGridImportParams : public UGRasterImportParams
	{
	public:
		//! \brief ���캯����
		UGGridImportParams();
		
		//! \brief ����������
		virtual ~UGGridImportParams();
	public:
		
		//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
		virtual UGint GetFileType() const	{ return UGFileType::AIASCIIGrid; }
		
	private:
	};

	
	class FILEPARSER_API UGGridExportParams : public UGRasterExportParams
	{
	public:
		//! \brief ���캯����
		UGGridExportParams();

		//! \brief ����������
		virtual ~UGGridExportParams();
	public:
		//! \brief ���ػ�ȡ�ļ���ʽ���͵ĺ�����
		virtual UGint GetFileType() const	{ return UGFileType::AIASCIIGrid; }
	private:
	};
}

#endif
