#ifndef UGDUMPGENERATOR_H
#define UGDUMPGENERATOR_H

// �ù���Ŀǰ��֧��Windowsƽ̨
/**
���ܣ�ʹ���쳣�����ܲ�׽Win32�쳣��C�ṹ���쳣�������ACCESS_VIOLATION��ARRAY_BOUNDS_EXCEEDED��DIVIDE_BY_ZERO�ȣ�
	������Dump�ļ���������к�������������Ͷ�λ

	Ŀǰ�������������Win32�쳣����.Net�����Java�������׽���쳣�������̫һ�¡�
	.Net�����ṩ��System::SystemException������Win32�쳣���ܹ�ֱ��ʹ�ø��쳣���Ͳ�׽����
	�������ʹ�ñ����еķ�װ������CLI������ֱ��ʹ��System::SystemException�������
	Java�����Ҫ��Wrapj��ʹ�ñ����ܽ���Win32�쳣�Ĵ�����ֹ���������ͬʱ��Wrapj��Toolkit��
	�ṩ��DumpExceptionCallBack(msg)�Ļص�����C++�쳣���ݵ�Java�㡣

�÷���
1��ȷ��Supermap.xml�������DumpEnabled��ֵΪ��true������������ȷ�ġ�DumpPath��
2���ڿ��ܲ��������Ĵ������Ӳ����쳣�Ĵ����磺����Ҫ��try֮ǰ����UGDumpGenerator::InitInstance();
	UGDumpGenerator::InitInstance();
	try
	{
		UGWorkspace ws = new UGWorkspace();
	}
	catch(UGExceptionEx &e)
	{
		UGDumpGenerator::WriteDumpFile(e);
		// �����������
		...
	}
3���޸Ĺ������ԣ�C/C++/Code Generation/Enable C++ Exceptions: Yes With SEH Exceptions (/EHa)��
	����ȷ��������Ϊ��EHA�����������������������Win32�쳣
4����Windbg��UGDumpGenerator::WriteDumpFile(e)���ɵ�Dump�ļ����е��Բ��������⡣


*/
#include "Stream/ugdefs.h"
namespace UGC{

	// ����C++�쳣�࣬��¼�쳣��Ϣ
	class UGExceptionEx
	{
		friend class UGDumpGenerator;
	public:
		UGExceptionEx(unsigned int _code, void* _ptr) : code(_code), ptrException(_ptr) 
		{

		}

		~UGExceptionEx() {}

	private:
		unsigned int code;
		void* ptrException;
	};


	// Dump�ļ�������
	class TOOLKIT_API UGDumpGenerator
	{
	private:
		UGDumpGenerator();
	public:
		~UGDumpGenerator();

		// ʵ����DumpGenerator������ģʽ
		// _set_se_translator����Ҫ��ÿ���߳��е�������_set_se_translator������ڶ��̻߳�����ʹ�ã�������Ҫ��׽�쳣�ķ���Ӧ���ȵ���InitInstance()
		static UGDumpGenerator& InitInstance();

		//! \brief �����쳣��Ϣ����Dump�ļ����쳣��Ϣ���Դ�UGExceptionEx.ptrException�л�ȡ
		//! \param *pException ΪNULLʱ���ѽ��̵ĵ�ǰ״̬����Dump�ļ�����Ϊ��ʱ�����ø��쳣��Ϣ����Dump�ļ�
		static void WriteDumpFile(UGExceptionEx* pException);
		static void WriteDumpFile( int errorno, void* exception_pointers );

	private:
		static void* m_pDumpHandler;
		static UGbool m_bDumpEnabled;
	};
}
#endif

