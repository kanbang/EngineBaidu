#ifndef _UGSCMFEATURE_H_
#define _UGSCMFEATURE_H_

#include "Stream/ugdefs.h"

namespace UGC{

#define SCM_INVALIDTYPE 0xFFFF

//!< ��ʱ������д���궨��
#define SCM_TILE_FLAG 500

typedef UGuint UGScmGeoID ;

//!< ����ͼ�������ͷ,�������ı�����ͨ��("/"ǰ��ֱ��Ӧ��������ı��е�ע��)
struct UGScmInnerHead 
{
	UGint m_iFileSize;		//!< ���ݿ�(��ʱ�ļ�)�ܴ�С
	UGint m_iGeoCount;		//!< ���ζ�������
	UGint m_iIndexOffset;	//!< ������ƫ��,����ǵ����ݣ���Ϊ0 / ���ı���Ϣ��ƫ�� 
	UGint m_iDataOffset;	//!< ���ݿ�ƫ�� / ���ı���Ϣ��ƫ��
	UGint m_iFeatureOffset;	//!< �������ݿ�ƫ��,û����Ϊ0 / �ı�ƫ��
	UGScmInnerHead()
	{
		m_iFileSize = 0;
		m_iGeoCount = 0;
		m_iIndexOffset = 0;
		m_iDataOffset = 0;
		m_iFeatureOffset = 0;
	};
};

//!< ���滯��Χ
struct UGScmNormalBound 
{
	UGushort m_usLeft;		//!< ��								
	UGushort m_usRight;		//!< ��
	UGushort m_usTop;		//!< ��
	UGushort m_usBottom;	//!< ��
	UGScmNormalBound()
	{
		m_usLeft = 0;
		m_usRight = 0;
		m_usTop = 0;
		m_usBottom = 0;
	};
};

//!< ����λ��
struct  UGScmPosInfo
{
	UGint m_iCount;			//!< �����
	UGint m_iOffset;		//!< ���ƫ��
	UGScmPosInfo()
	{
		m_iCount = 0;
		m_iOffset = -1;
	}
};

//!< ����������Ϣ
struct UGScmGeoIndex
{
	UGint m_iSubOffset;
	UGScmNormalBound m_NormalBound;
	UGScmGeoIndex()
	{
		m_iSubOffset = -1;
	}
};

//!< ������������Ϣ
struct UGScmGeoSubIndex 
{
	UGint m_iSubCount;					//!< �Ӷ������
	UGArray<UGScmPosInfo> m_arPosInfo ; //!< �Ӷ���λ����Ϣ 
};

//!< �����������ݿ�
struct UGScmGeoIndexInfo
{
	UGArray<UGScmGeoIndex> arGeoIndex;		//!< ����������
	UGArray<UGScmGeoSubIndex> arSubIndex;	//!< ����������
};

//!< �ı�
struct UGScmGeoText
{
	UGushort m_usStyleIndex;	//!< �������
	UGushort m_usSubCount;		//!< �Ӷ������
	UGint m_iSubOffset;			//!< �Ӷ������ƫ��
	UGScmGeoText()
	{
		m_usStyleIndex = 0;
		m_usSubCount = 0;
		m_iSubOffset = -1;
	}
};

//!< ���ı�
struct UGScmSubText
{
	UGushort m_usX;		//!< �Ӷ������滯x����
	UGushort m_usY;		//!< �Ӷ������滯y����
	UGint m_iAngle;		//!< �Ӷ���Ƕ�,ʵ�ʽǶ�=m_iAngle*0.1
	UGint m_iNameInfo;	//!< ���Ƴ��Ⱥ�ƫ�ƺϳ�
	UGScmSubText()
	{
		m_usX = 0;
		m_usY = 0;
		m_iAngle = 0;
		m_iNameInfo = 0;
	};

};

//!< �ı��������ݿ�
struct UGScmTextIndexInfo
{

};


//!< �ı���POI������Ϣ
struct UGScmAnnotateIndexInfo 
{
	UGushort m_usX;		    //!< ���滯X���ꡣ
	UGushort m_usY;		    //!< ���滯y���ꡣ
	UGint m_iTXTOffset;   //!< �ı�ƫ�ơ�
	UGint m_iSubKind;      //! ���ſ�ID,�ı����͸ñ���Ϊ-1
	UGScmAnnotateIndexInfo()
	{
		m_usX = 0;
		m_usY = 0;
		m_iTXTOffset = 0;
		m_iSubKind = -1;
	};
};

struct UGScmNormalPoint 
{
	UGushort m_usX;
	UGushort m_usY;
	UGScmNormalPoint() 
	{
		m_usX = 0;
		m_usY = 0;
	};
};

typedef UGint UGScmFeatrueIndex;

//��Ƭ������ͷ
struct UGScmTileHead
{
	UGushort usNDTSign;		 	 //NDT���ݱ�ʶ
	UGushort m_usLayerCount;	 //������ͼ�������	
	UGint m_iDataOffset;		 //���ݼ�����ƫ��
	UGint m_iSize;               //��Ƭ��С
	UGScmTileHead()
	{
		usNDTSign = 500;
		m_usLayerCount = 0;
		m_iDataOffset = 0;
		m_iSize = 0;
	}
};

struct UGScmTileIndex
{
//	UGushort usLayerID;
	UGushort usType;			//!< ��������
	UGint iOffset;				//!< ���ƫ��
	UGint iSize;				//!< ��С

	UGScmTileIndex()
	{
		usType = SCM_INVALIDTYPE;
		iOffset = -1;
		iSize = -1;
	}
};

enum ScmDstType
{
	//! \brief ��
	Point = 1,
	//! \brief ��
	Line = 3,
	//! \brief ��
	Region = 5,
	//! \brief �ı�
	Text = 7
	//***ע���Ժ��ټ�***//
	//Annotate
};

struct UGScmFeatureInfo 
{
	UGString m_strField;		//!< �����ֶ�����
	UGVariant::VarType m_Type;	//!< �����ֶ�����
};

struct UGTilePosition
{
	UGint m_iRow;				//!< ��
	UGint m_iColumn;			//!< ��
	UGdouble m_dScale;			//!< ������

	UGTilePosition()
	{
		m_iRow = 0;
		m_iColumn = 0;
		m_dScale = 0.0;
	}
};

//!< ���ı����Ⱥ��ı�ƫ�ƺϳ�
#define CombineScmTxtIndex(ScmLen,ScmOffset) ( (ScmLen<<24) | ScmOffset)

//!< �����ı�����
#define ParseScmTxtLength(x) ( x>>24 )

//!< �����ı�ƫ��
#define ParseScmTxtOffset(x) ( x & 0x00FFFFFF )

}

#endif