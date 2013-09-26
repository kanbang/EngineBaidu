#ifndef UGS57SPATIALRELATIONSHIP_H
#define UGS57SPATIALRELATIONSHIP_H

#include "Stream/ugdefs.h"

namespace UGC
{
	//! \brief �洢S57��FSPT���ֶ���Ϣ�������ݼ�ENC_FVE�ж�ȡ
	struct UGS57FSPT 
	{
		//! \brief ��Ӧ�ֶ�VE_RCIDֵ
		UGuint nRCID;
		//! \brief ��Ӧ�ֶ�ORNTֵ
		UGushort nORNT;
		//! \brief ��Ӧ�ֶ�USAGֵ
		UGushort nUSAG;
		//! \brief ��Ӧ�ֶ�MASKֵ
		UGushort nMASK;
		//! \brief RCNMֵ
		UGint nRCNM;
		UGS57FSPT()
		{
			nRCID = 0;
			nORNT = 255;
			nUSAG = 255;
			nMASK = 255;
			nRCNM = 0;
		}
	};
	//! \brief �洢S57�������Ĺ�����ϵ�������ݼ�ENC_RS�ж�ȡ
	struct UGS57RS
	{
		//! \brief Ŀ������17λ��������Ӧ�ֶ�DEST_NAME
		UGString strDESTLNAM;
		//! \brief ������ϵ���ͣ���Ӧ�ֶ�RIND
		UGshort nRIND;
		//! \brief ˵����Ϣ����Ӧ�ֶ�COMT
		UGString strCOMT;
		// Ŀ�����ı���...
		UGString strSrcAcronym;
		UGString strDestAcronym;


		UGS57RS()
		{
			strDESTLNAM.Empty();
			nRIND = 0;
			strCOMT.Empty();
			strSrcAcronym.Empty();
			strDestAcronym.Empty();
		}
	};

	struct UGS57Feature 
	{
		UGuint   unFeatureID;
		UGint    nOBJL;
		UGString strPRIM;
		UGshort  nRCNM;
		UGS57Feature()
		{
			unFeatureID = 0;
			nOBJL = 0;
			strPRIM.Empty();
			nRCNM = 0;
		}
		~UGS57Feature()
		{
			//strPRIM.Empty();
		}

		friend UGbool operator < (const UGS57Feature& lhs, const UGS57Feature& rhs)
		{
			return lhs.unFeatureID < rhs.unFeatureID;
		}

		friend UGbool operator == (const UGS57Feature& lhs, const UGS57Feature& rhs)
		{
			return lhs.unFeatureID == rhs.unFeatureID;
		}
	};
	typedef   UGArray<UGS57Feature> UGS57Features;
	typedef   UGArray<UGS57FSPT> UGS57FSPTS;
	typedef   UGArray<UGS57RS> UGS57RSS;
};

#endif
