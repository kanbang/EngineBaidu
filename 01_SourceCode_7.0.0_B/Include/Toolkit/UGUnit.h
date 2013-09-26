// SmUnit.h: interface for the UGUnit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGC_SMUNIT_H__6F3A3977_6B26_4FA5_8847_357F48923186__INCLUDED_)
#define UGC_SMUNIT_H__6F3A3977_6B26_4FA5_8847_357F48923186__INCLUDED_

#include "Stream/ugdefs.h"

namespace UGC{

	  //!  \brief Toolkit
class TOOLKIT_API UGUnit  
{
	
public:
	//! \brief
	UGUnit();
	
	//! \brief
	~UGUnit();

	
	//! \brief
static UGString GetUnitName(UGlong nUnit) ;

// ����nUnit�ǳ��Ȼ��ǽǶ�
// ���ȷ��� UNIT_DISTANCE 
// �Ƕȷ��� UNIT_ANGLE
// �޷�ʶ��ĵ�λ���� 0 
static UGlong   GetUnitType(UGlong nUnit) ; 
		
	//! \brief
static UGString UnitConvert(UGlong lUnits);
	//! \brief
static UGint UnitConvert(UGString strUnits);

	//! \brief
static UGString GetUnitsNameExt(UGlong lUnits);
	//! \brief
static UGString GetUnitsName(UGlong lUnits);	
};


}//namespace UGC


#endif // !defined(UGC_SMUNIT_H__6F3A3977_6B26_4FA5_8847_357F48923186__INCLUDED_)

