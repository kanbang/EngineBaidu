//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details ���ļ�������ģ���ļ�����Ҫ�ӿڡ�
//!  \author zhangshuai,sunye
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEPARSERMODE_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_)
#define AFX_UGFILEPARSERMODE_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_

#include "FileParser/UGFileParse.h"
#include "Base3D/UGBoundingBox.h"
#include "Base3D/UGMatrix4d.h"
#include "Base3D/UGNode.h"
#include "Base3D/UGAnimationCurve.h"
#include "Base3D/UGAnimation.h"
#include "Base3D/UGMaterial3D.h"

namespace UGC 
{
	class UGMaterial;
	class UGMesh;
	class UGAnimation;
	class UGMaterial3D;
//! \brief ģ�͵Ļ�����Ϣ��
class FILEPARSER_API ModelDataInfo
{
public:
	//! \brief ���캯����
	ModelDataInfo();

	//! \brief �������캯����
	ModelDataInfo(const ModelDataInfo& mInfo);

	//! \brief ���ؿ��Ⱥš�
	void operator=(const ModelDataInfo& mInfo);

	//! \brief ����������
	virtual ~ModelDataInfo();
 
 	//! \brief ���������Ϣ�ָ�Ĭ��ֵ��
 	void Clear();
 
	//! \brief ����ģ�͵�����
	void SetName(const UGString& strName);

	//! \brief ��ȡģ�͵�����
	const UGString& GetName() const; 

	//! \brief �õ�ģ�͵ļ������ݡ�
	UGArray<UGMesh*>& GetMesh();

	//! \brief ��ȡģ�͵Ĳ������ݡ�
	UGArray<UGMaterial*>& GetMaterial();

	//! \brief ��ȡģ�͵Ĳ������ݡ�
	UGArray<UGMaterial3D*>& GetMaterial3D();

	//! \brief ���ð�Χ��
	void SetBoundingBox(const UGBoundingBox& box){m_BoundingBox = box;}

	//! \brief ��ȡģ�͵İ�Χ��
	UGBoundingBox& GetBoundingBox(){return m_BoundingBox;}

	//! \brief ��ȡģ�͵İ�Χ��
	void ComputeBoundingBox();

	//! \brief ģ�͵��ھֲ��������
	UGMatrix4d GetLocalMatrix();

	//! \brief ģ�͵��ھֲ��������
	//! \param matLocalMatrix �ֲ��������
	void SetLocalMatrix(const UGMatrix4d matLocalMatrix);

	//! \brief ���������
	UGNode& GetRootNode(void);

	const UGAnimationCurve* FindAnimationCurve(const UGString& strNodeName)const;

	//! \brief ��ȡ������Ϣ
	UGbool IsAnimated();
	
	//! \brief �����ʼʱ��
	UGdouble GetStartTime();

	//! \brief��ý���ʱ��
	UGdouble GetEndTime();

	//! \brief �����ļ��м���
	void Load(UGStream& fStream,const UGString& strFileName);

	//! \brief �������ļ���
	void Save(UGStream& fStream,const UGString& strFileName);

	//! \brief ��ý��Ĵ�С
	UGint GetDataSize() const;

	//! \brief �����Ƿ��ж���
	void SetAnimated(UGbool bAnimated);
	
	//! \brief ������ʼʱ��
	void SetStartTime(UGdouble dStartTime);
	
	//! \brief ���ý���ʱ��
	void SetEndTime(UGdouble dEndTime);

	//! \brief ��ȡ������Ϣ
	UGAnimation* GetAnimationState(void);

	//! \brief ���ÿ��ƶ�����Ϣ
	void SetAnimationState(UGAnimation* pAnimation);

	//! \brief �õ��������������ű���
	//! \return �������������ű��ʡ�
	UGPoint3D GetScale() const;	

	//! \brief �õ�������������ת�Ƕ�
	//! \return ������������ת�Ƕȡ�
	UGPoint3D GetRotation() const;

	//! \brief ���ö�������Ŵ�С
	//! \param fScaleX [in] X�������ű��ʡ�
	//! \param fScaleY [in] Y�������ű��ʡ�
	//! \param fScaleZ [in] Z�������ű��ʡ�
	void SetScale(UGdouble fScaleX,UGdouble fScaleY,UGdouble fScaleZ);

	//! \brief ���ö������ת�� 
	//! \param fRotateX [in] X�������ת�Ƕȡ�
	//! \param fRotateY [in] Y�������ת�Ƕȡ�
	//! \param fRotateZ [in] Z�������ת�Ƕȡ�
	void SetRotation(UGdouble fRotateX,UGdouble fRotateY,UGdouble fRotateZ);


    //!  \brief ������άģ�Ͷ���Ķ�λ�� 
    void SetPosition(const UGPoint3D pntPosition);

    //!  \brief ������άģ�Ͷ�λ��
	UGPoint3D GetPosition()const;

protected:
	
	//! \brief ģ�����ݵ�����
	UGString m_strName;

	//! \brief �����������е�λ�������ƵĶ�Ӧ��ϵ,
	//! \brief ģ�͵Ĳ������ݡ�
	UGArray<UGMaterial*> m_arryMaterial;

	//! \brief �����������е�λ�������ƵĶ�Ӧ��ϵ,
	//! \brief ģ�͵Ĳ������ݡ�
	UGArray<UGMaterial3D*> m_arryMaterial3D;

	//! \brief ģ�͵ļ������ݡ�
	UGArray<UGMesh*> m_arryMesh;

	//! \brief ģ�͵İ�Χ��
	UGBoundingBox m_BoundingBox;

	//! \brief ģ�͵ľֲ�����
	UGMatrix4d m_matLocalMatrix;

	//! \brief �����
	UGNode m_rootNode;

	//! \brief ������Ϣ
	UGbool m_bIsAnimated;

	//! \brief ������ʼʱ��
	UGdouble m_dStartTime;

	//! \brief ��������ʱ��
	UGdouble m_dEndTime;

	//! \brief ���ʶ�Ӧ�б�,�������������е�λ�ö�
	UGDict<UGString,UGint> m_MaterialMap;

	//! \brief Mesh��Ӧ�б�,�������������е�λ�ö�
	UGDict<UGString,UGint> m_MeshMap;

	//! \brief �汾��
	UGdouble m_dVersion;

	//! \brief ������Ϣ
	UGAnimation* m_pAnimation;

	//! \brief ��ά���������ϵ��
	UGPoint3D m_pntScale;

	//! \brief ��ά�������ת��
	UGPoint3D m_pntRotate;

    //! \brief ��άģ�Ͳ����
	UGPoint3D m_pntPosition;

public:
	//! \brief ��Ӧ��ģ����Ϣ�еĶ���UGString���ڲ��Ҷ���
	UGDict<UGString,UGAnimationCurve*> m_AnimationList;
};


class FILEPARSER_API UGFileParseModel : public UGFileParser  
{
public:

	//! \brief ���캯����
	UGFileParseModel();	

	//! \brief ����������
	virtual ~UGFileParseModel();
	
public:	
	ModelDataInfo* GetModelDataInfo()const;
	////////////////////////////////////////////////////////////////////////
	//
	// ���û�������
	//
	////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////
	// д�뺯��
	//////////////////////////////////////////////////////////////////////////
	virtual UGbool Save(const UGExportParams& expParams,const ModelDataInfo* pModelInfo);
protected:
	ModelDataInfo* m_pModelInfo;

};

} //namespace UGC

#endif // !defined(AFX_UGFILEPARSERMODE_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_)

