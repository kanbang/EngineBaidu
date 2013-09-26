#pragma once

#if !defined(AFX_UGLAYERSCM_H__A4B470F7_6A63_4275_BB1D_EF15BAD2DDAD__INCLFUDED_)
#define AFX_UGLAYERSCM_H__A4B470F7_6A63_4275_BB1D_EF15BAD2DDAD__INCLFUDED_

#include "Map/UGLayer.h"
#include "Workspace/UGWorkspace.h"
#include "Map/UGMap.h"

namespace UGC {

class MAP_API UGLayerSCM : public UGLayer
{
public:
	UGLayerSCM(void);
	virtual ~UGLayerSCM(void);

public:
	UGbool OnDraw(UGGraphics* pGraphics, UGDrawing* pDrawing);
	// �ڲ���ʵ�֣������� UGLayer::UG_Layer_SCM ���ͣ��������޸�
	virtual void SetType(UGLayer::UGLayerType nType);
	// �Ѳ�������ʼ������
	virtual void SetDataset(UGDataset *pDataset, UGbool bInit = true, UGbool bClearRecordsets = true);

private:
	UGWorkspace m_Workspace;
	UGMap m_Map;
};

}

#endif

