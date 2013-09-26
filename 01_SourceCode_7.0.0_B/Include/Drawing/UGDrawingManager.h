// UGDrawSysManager.h: interface for the UGDrawSysManager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGDRAWINGMANAGER_H
#define UGDRAWINGMANAGER_H

#include "Stream/ugdefs.h"
#include "Drawing/UGDrawingGeometry.h"
#include "Drawing/UGDrawingDefine.h"
#include "Toolkit/UGThread.h"
#include "Toolkit/UGLicense.h"

namespace UGC{

class DRAWING_API UGDrawingManager  
{
public:
	UGDrawingManager();
	~UGDrawingManager();

public:
	//! \brief �õ���ʾϵͳ�������
	static UGint GetDrawingCount();
	//! \brief �õ���ʾϵͳĬ�ϲ��
	static UGDrawingGeometry* GetDefaultDrawingGeometry();
	//! \brief �����ܹ���ʾָ�����ζ������͵���ʾϵͳ
	static UGDrawingGeometry* FindDrawingGeometry(UGint nGeometryType);
	//! \brief �����ܹ���ʾָ�����ζ������͵���ʾϵͳ
	static UGbool DrawingGeometry(UGDrawing* pDrawing,UGGeometry* pGeo);

	//! \brief ����һ��ָ���ļ����Ķ�̬�⡣
	//! \param strPathName [in]��
	//! \return ���سɹ�����true��
	static UGbool LoadDrawingGeometry(const UGString& strPathName);	

	//! \brief ж�ض�̬�⡣
	//! \param hHandle [in] ��̬������
	//! \return �ɹ�ж�ط���true��
	static UGbool UnloadDrawingGeometry(void* hHandle);

	//! \brief ��ȡָ����������ʾϵͳ�������
	static UGDrawingDefine* GetDrawingDefines(UGint nIndex);

	//! \brief װ����ʾϵͳ���
	void LoadDrawingGeometry();

	// �����ʾϵͳ�����ھ�̬���� for Android by liucq
	UGbool AddDrawingProvider(void* handle);

private:
	
	//! \brief ж����ʾϵͳ���
	void UnloadDrawingGeometry();
	//! \brief ���ݶ�̬���������ʾϵͳ�������
	UGDrawingDefine* ChecktDrawingDef(void* hHandle);
	//! \brief �����ܹ���ʾָ�����ζ������͵���ʾϵͳ�������
	UGDrawingDefine* FindDrawingDef(UGint nGeometryType);
	//! \brief �����ʾϵͳ�������
	void AddDrawingDefine(UGDrawingDefine* pDrawingDef);
private:
	UGArray<UGDrawingDefine* > m_DrawingDefines;
	UGMutex m_mutex;
	UGbool m_bLoaded;
	UGLicense* m_pLicense;
};

extern DRAWING_API UGDrawingManager g_drawingManager;

}
#endif // !defined(AFX_UGDRAWSYSMANAGER_H__61326E64_8C8B_4BD7_BA7F_001FB0685232__INCLUDED_)

