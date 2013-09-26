#ifndef UGGEOACTION_H
#define UGGEOACTION_H

#include "Engine/UGEngDefs.h"

namespace UGC {
class ENGINE_API UGGeoAction
{
public:
	UGGeoAction();
	~UGGeoAction();

	enum UGActionType
	{
		atNone,		//�޶���
		atOffset,		//ƽ��
		atInflate,	//����
		atRotate,		//��ת
		atDelete,		//ɾ��

	};//��������

public:
	//! \brief��ȡ��������
	UGActionType GetType() const {return m_eType;}

protected:
	UGActionType m_eType;
};

class ENGINE_API UGOffsetAction : public UGGeoAction
{
public:
	UGOffsetAction();
	//�� \brief��ά�ƶ�
	UGOffsetAction(UGdouble dX, UGdouble dY);
	//�� \brief��ά�ƶ�
	UGOffsetAction(UGdouble dX, UGdouble dY, UGdouble dZ);
	~UGOffsetAction();
public:
	//! \brief X����ƫ��ֵ
	UGdouble m_dOffsetX;
	//! \brief Y����ƫ��ֵ
	UGdouble m_dOffsetY;
	//! \brief Z����ƫ��ֵ
	UGdouble m_dOffsetZ;
};

class ENGINE_API UGRotateAction : public UGGeoAction
{
public:
	UGRotateAction();
	//�� \brief��ά��ת
	UGRotateAction(UGPoint2D pnt, UGdouble dAngle);
	//�� \brief��ά��ת
	UGRotateAction(UGPoint3D pnt, UGdouble dAngle);
	~UGRotateAction();
public:
	//! \brief ��׼��X����
	UGdouble m_dCenterX;
	//! \brief ��׼��X����
	UGdouble m_dCenterY;
	//! \brief ��׼��X����
	UGdouble m_dCenterZ;
	//! \brief ��ת�Ƕ�
	UGdouble m_dAngle;
};

class ENGINE_API UGInflateAction : public UGGeoAction
{
public:
	UGInflateAction();
	//�� \brief��ά����
	UGInflateAction(UGdouble dXRatio, UGdouble dYRatio);
	//�� \brief��ά����
	UGInflateAction(UGdouble dXRatio, UGdouble dYRatio, UGdouble dZRatio);
	~UGInflateAction();
public:
	//! \brief X�������ű���
	UGdouble m_dRatioX;
	//! \brief Y�������ű���
	UGdouble m_dRatioY;
	//! \brief Z�������ű���
	UGdouble m_dRatioZ;
};

class ENGINE_API UGDeleteAction : public UGGeoAction
{
public:
	UGDeleteAction();
	~UGDeleteAction();
};

}
#endif
