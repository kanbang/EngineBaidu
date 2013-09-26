// UGDataSourceOgdc.h: interface for the UGDataSourceOgdc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDATASOURCEOGDC_H__6D84965C_9B6F_4AA7_8854_7412060D5D18__INCLUDED_)
#define AFX_UGDATASOURCEOGDC_H__6D84965C_9B6F_4AA7_8854_7412060D5D18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDataSource.h"

namespace UGC {

//##ModelId=483BB70902FD1
class ENGINEOGDC_API UGDataSourceOgdc : public OgdcDataSource  
{
public:
	//##ModelId=483BB70902FF
	UGDataSourceOgdc();
	//##ModelId=483BB709030D
	virtual ~UGDataSourceOgdc();

// ���麯��
public:
	//! \brief ��������Դ,��ҪԤ�����ú�������Ϣ��
	//##ModelId=483BB709030F
	virtual OgdcBool Create();
	
	//! \brief ������Դ,��ҪԤ�����ú�������Ϣ��
	//##ModelId=483BB7090311
	virtual OgdcBool Open();

	//! \brief �ر�����Դ��
	//##ModelId=483BB7090313
	virtual void Close();

	//! \brief �ж�����Դ�Ƿ��Ѿ��򿪡�
	//! \return �򿪷���TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB709031C
	virtual OgdcBool IsOpen() const;

	//! \brief ��ȡ���ݼ�������
	//! \return ���ݼ�������
	//##ModelId=483BB709031E
	virtual OgdcInt GetDatasetCount() const;

	//! \brief ͨ����Ż�ȡ���ݼ�ָ�롣
	//! \return ���ݼ�ָ�롣
	//##ModelId=483BB7090320
	virtual OgdcDataset* GetDataset(OgdcInt nIndex) const;

	//! \brief ��ȡָ�����Ƶ����ݼ�ָ�롣
	//! \param strDatasetName ���ݼ���[in]��
	//! \return ���ݼ�ָ�롣
	//##ModelId=483BB7090323
	virtual OgdcDataset* GetDataset(const OgdcString& strDatasetName) const;
	
	//! \brief ͨ�����ݼ�����ɾ�����ݼ���
	//! \param strDatasetName ���ݼ�����[in]��
	//! \return �Ƿ�ɹ�ɾ�����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB709032E
	virtual OgdcBool DeleteDataset(const OgdcString& strDatasetName);
	
	//! \brief ͨ��ʸ�����ݼ�������Ϣ��DatasetVectorInfo�������ݡ�
	//! \param vInfo ʸ�����ݼ�������Ϣ����[in]��
	//! \return ʸ�����ݼ�ָ�롣
	//##ModelId=483BB7090331
	virtual OgdcDatasetVector* CreateDatasetVector(const OgdcDatasetVectorInfo& vInfo);	
	
	//! \brief ͨ��դ�����ݼ�������Ϣ��DatasetRasterInfo�������ݼ���
	//! \param rInfo դ�����ݼ�������Ϣ����[in]��
	//! \param bIsMBRaster �Ƿ��Զನ�η�ʽ�������ݼ�[in]��
	//! \return դ�����ݼ�ָ�롣
	//##ModelId=483BB7090334
	virtual OgdcDatasetRaster* CreateDatasetRaster(const OgdcDatasetRasterInfo& rInfo,OgdcBool bIsMBRaster = FALSE);	

	//! \brief ͨ���������ݼ�ģ�崴�����ݼ���
	//! \param &strNewName �����ݼ���[in]��
	//! \param pReferenceDataset �ο����ݼ�ָ�룬��ģ�崴�����ݼ�ָ��[in]��
	//! \return �����ݼ�ָ�롣
	//##ModelId=483BB709033C
	virtual OgdcDataset* CreateDatasetFrom(const OgdcString &strNewName, OgdcDataset* pReferenceDataset);

	//! \brief �������ݼ���
	//! \param pSrcDataset Դ���ݼ�ָ��[in]��
	//! \param strDestDatasetName Ŀ�����ݼ���[in]��
	//! \param bBuildIndexOrPyramid �Ƿ��դ�����ݼ�������������Ĭ�ϲ���[in]��
	//! \return Ŀ�����ݼ�ָ�롣
	//##ModelId=483BB7090340
	virtual OgdcDataset* CopyDataset(OgdcDataset* pSrcDataset, 
		const OgdcString& strDestDatasetName, OgdcBool bBuildIndexOrPyramid = FALSE);

	//! \brief ����������Ϣ��
	//##ModelId=483BB7090345
	virtual OgdcBool SaveInfo();

public:	
	//! \brief ����ͶӰ����ϵ��
	//! \param coordSys [in]��
	//##ModelId=483BB709034B
	virtual OgdcBool SetCoordSys(const OgdcCoordSys& coordSys);	

	//! \brief �õ�ͶӰ����ϵ��
	//##ModelId=483BB709034E
	virtual OgdcBool GetCoordSys(OgdcCoordSys& coordSys);	

	//! \brief ִ��SQL��䡣
	//! \param strSQL SQL���[in]��
	//! \return �Ƿ�ɹ�ִ�У��ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��Ҫ���������ݿ⼶ִ�е����ݲ�����
	//##ModelId=483BB7090351
	virtual OgdcBool Execute(const OgdcString& strSQL);	
	
	//! \brief ����Դ�Ƿ���������ӡ�
	//##ModelId=483BB7090354
	virtual OgdcBool IsConnected();
	
	//! \brief �����������ݿ�,��ˢ�����ݼ��ȡ�
	//##ModelId=483BB7090356
	virtual OgdcBool Connect();	
	
	//! \brief ��ȡ������ʱ�䡣
	//##ModelId=483BB709035C
	virtual OgdcTime GetDateLastUpdated();
	
	//! \brief ��ȡ����ʱ�䡣
	//##ModelId=483BB709035E
	virtual OgdcTime GetDateCreated();	
	
	//! \brief �޸����롣
	//! \param strNewPassword ������[in]��
	//! \return �޸ĳɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7090360
	virtual OgdcBool ChangePassword(const OgdcString& strNewPassword);
	
	//! \brief ��ȡ�������ơ�
	//! \return �������ơ�
	//##ModelId=483BB7090363
	virtual OgdcString GetEngineName() const ;
	
	//! \brief ����һ������Դ��Ŀǰû�е����ݼ����֡�
	//! \param strDatasetName ָ��һ�����ݼ���[in]��
	//! \return ����ָ�������ɵļ���Ψһʶ������ݼ�����
	//##ModelId=483BB7090365
	virtual OgdcString GetUnoccupiedDatasetName(const OgdcString& strDatasetName);	
	
	//! \brief �ж����ݼ������Ƿ�Ϸ���
	//! \param strDatasetName ���ݼ���[in]��
	//! \param nState ���ݼ����ֶ�������������[out]��
	//! \return �����Ƿ�Ϸ����Ƿ���TRUE�����򷵻�FALSE��
	//##ModelId=483BB709036B
	virtual OgdcBool IsAvailableDatasetName(const OgdcString& strDatasetName);

	//! \brief ��ȡ����Դ�汾�š�
	//! \return ����Դ�汾�š�
	//##ModelId=483BB709036E
	virtual OgdcInt GetVersion();		
	
	//! \brief ��ʼ����
	//! \return �Ƿ�ɹ���ʼ���񣬳ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7090370
	virtual OgdcBool BeginTrans();
	
	//! \brief �ύ����
	//! \return �Ƿ�ɹ��ύ���񣬳ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7090372
	virtual void Commit();
	
	//! \brief ��������
	//! \return �Ƿ�ɹ��������񣬳ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB7090374
	virtual void Rollback();
	
	//! \brief �ж������Ƿ�ʼ 
	//##ModelId=483BB7090376
	virtual OgdcBool IsTransStarted() const ;

	//! \brief �ж�����Դ�Ƿ�֧�ֶ��������
	//! \return ֧�ַ���TRUE����֧�ַ���FALSE��
	//##ModelId=483BB709037A
	virtual OgdcBool IsTransacted() const;
	
	//! \brief ��ȡ���롣
	//! \remarks ͨ����ȡ������ϢҲ���Եõ����롣
	//##ModelId=483BB709037C
	virtual OgdcString GetPassword() const;

	//! \brief ��ȡ����Դ���ơ�
	//##ModelId=483BB709037E
	virtual OgdcString GetName() const ;

	//! \brief ��ȡ��������
	//##ModelId=483BB7090380
	virtual OgdcInt GetEngineType() const;

	//! \brief ��ȡ�������
	//##ModelId=482030520128
	virtual  UGint GetEngineClass() const;

	//! \brief ��ȡ�ļ�������ĺ�׺��
	//##ModelId=48203052012A
	virtual UGString GetEnginePostfix() const ;

	//! \brief �ж�����Դ�Ƿ��޸ġ�
	//! \return ���޸ķ���TRUE�����򷵻�FALSE��
	//##ModelId=483BB7090382
	virtual OgdcBool IsModified();

	//! \brief ��������Դ�Ƿ��޸ġ�
	//! \param bModified ����Դ�Ƿ��޸Ĳ���ֵ��Ĭ��Ϊ�޸�[in]��
	//##ModelId=483BB7090384
	virtual void SetModifiedFlag(OgdcBool bModified = TRUE);
	
	//! \brief ��ȡ����Դ�ı�����
	//! \return ����Դ�ı�����
	//##ModelId=483BB709038A
	virtual OgdcString GetAlias() const;

	//! \brief ��������Դ�ı���
	//! \param strAlias ����Դ�ı���[in]��
	//##ModelId=483BB709038C
	virtual void SetAlias(const OgdcString& strAlias);
	
	//! \brief �жϴ�����ֶ���������Ƿ���á�
	//! \param �ֶ���������Ƿ���á�
	//! \param nState ���ݼ��������ֶ������������͡�
	//! \return	���÷���TRUE�������÷���FALSE��
	//##ModelId=483BB709038F
	virtual OgdcBool IsValidFieldOrTableName(const OgdcString& strFieldOrTableName);
	
	//! \brief ��������Դ������Ϣ��
	//! \param strDescription ����Դ������Ϣ[in]��
	//##ModelId=483BB7090392
	virtual void SetDescription(OgdcString strDescription);
	
	//! \brief ��ȡ����Դ������Ϣ��
	//! \return ����Դ������Ϣ��
	//##ModelId=483BB7090395
	virtual OgdcString GetDescription();

	//! \brief ��ʼ��Ԫ���ݿ���
	//! \return Ԫ���ݿ����ָ��
	//##ModelId=483BB7090397
	virtual OgdcMetaDatabase * InitMetaDatabase();

	//! \brief ��ȡԪ���ݿ���
	//! \return Ԫ���ݿ����ָ��
	//! \remarks ���ڵ��ô˺���֮ǰû�е���InitMetaDatabase���򷵻�ΪNULL
	//##ModelId=483BB709039A
	virtual OgdcMetaDatabase * GetMetaDatabase();
	
	//##ModelId=483BB709039C
	UGDataSource* GetDataSource() const;
	//##ModelId=483BB709039E
	void SetDataSource(UGDataSource* pDataSource);

	//! \brief ɾ����ǰ������Դ(���Զ�ɾ���������ݼ������ɾ������ϵͳ���ϵͳ����)
	//! \remark ���ô˷����󣬿����ٴδ���ͬ����������Դ
	//! \attention �����ݿ����͵�����Դ��Ҫʵ�ִ˷������ļ�������Դ������
	virtual OgdcBool DropDataSource();


protected:	
	//##ModelId=483BB70903A0
	UGDataSource* m_pDataSource;
	//##ModelId=483BB70903AA
	UGArray<OgdcDataset*> m_Datasets;

};

}

#endif // !defined(AFX_UGDATASOURCEOGDC_H__6D84965C_9B6F_4AA7_8854_7412060D5D18__INCLUDED_)

