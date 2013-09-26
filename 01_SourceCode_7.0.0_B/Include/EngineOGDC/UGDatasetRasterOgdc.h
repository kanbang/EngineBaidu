// UGDatasetRasterOgdc.h: interface for the UGDatasetRasterOgdc class.
//
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//!  \file UGDatasetRasterOgdc.h
//!  \brief UGDatasetRasterOgdc �Ľӿڶ��塣
//!  \details UGDatasetRasterOgdc����Ӱ�����ݼ��Ľӿڶ��塣
//!  \Modified Date: 2013-4-7
//!  \Modified Author:Conversion-zby
//!  \Details Comments:����UGC�ӿڲ��������Լ��ӿ����,��ҪĿ������UGCEngineOGDC�ӿ�����Ӷನ��դ�����ݼ�����չ֧��;
//!  \Details Comments:���ε�����Ҫ��������������:(1) ����ԭ�нӿ����Ӳ�����������֧��;(2) ���Ӷನ��դ�����ݼ����нӿ�
//!  \Details Comments:�˴ε����漰����դ�����ݼ��ṹ�ĵ��������ڼ�����Աˮƽ�����Լ�ʱ��Ĳִ٣�����������������������,������
//!  \Details Comments:����Conversion-zby��ϵ!
//!  \Version OGDC-1-1(2013-4-7)


#if !defined(AFX_UGDATASETRASTEROGDC_H__B310E3AF_CDAF_4FA8_9470_D1D414D5FBD5__INCLUDED_)
#define AFX_UGDATASETRASTEROGDC_H__B310E3AF_CDAF_4FA8_9470_D1D414D5FBD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OGDC/OgdcDatasetRaster.h"
#include "Engine/UGDatasetRaster.h"

namespace UGC {

class UGDataSourceOgdc;

//##ModelId=483BB70B0232
class ENGINEOGDC_API UGDatasetRasterOgdc : public OgdcDatasetRaster  
{
public:
	//##ModelId=483BB70B0243
	UGDatasetRasterOgdc();
	//##ModelId=483BB70B0244
	virtual ~UGDatasetRasterOgdc();

public:
	//! \brief �����ݼ���
	//! \return �Ƿ�ɹ������ݼ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70B0246
	virtual OgdcBool Open();	
	
	//! \brief �ر����ݼ���
	//! \return �Ƿ�ɹ��ر����ݼ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70B0248
	virtual void Close();	

	//! \brief �ж����ݼ��Ƿ��Ѿ��򿪡�
	//! \return �򿪷���TRUE�����򷵻�FALSE��
	//##ModelId=483BB70B024A
	virtual OgdcBool IsOpen() const;
	
	//! \brief ���������ݼ���
	//! \param strNewName �µ����ݼ���[in]��
	//! \return �Ƿ�ɹ����������ݼ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ֻ�ı����ݼ���,�������䡣
	//##ModelId=483BB70B0252
	virtual OgdcBool Rename(const OgdcString& strNewName);		

	//! \brief �жϵ�ǰ���ݼ��Ƿ�ɱ༭��
	//! \return �ɱ༭����TRUE�����ɷ���FALSE��
	//##ModelId=483BB70B0255
	virtual OgdcBool CanUpdate();
	
	//! \brief �ж����ݼ��Ƿ���դ�����ݼ�
	//! \return ���ݼ���դ�����ݼ�����TRUE�����򷵻�FALSE��
	//##ModelId=483BB70B0257
	virtual OgdcBool IsRaster();	
	
	//! \brief �����ݼ�������Ϣ���浽���ݿ��С�
	//! \return �Ƿ�ɹ����棬�ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=483BB70B0259
	virtual OgdcBool SaveInfo();	
	
	//! \brief ˢ�����ݼ���Ϣ��
	//! \return �Ƿ�ɹ�ˢ�£��ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks �����ݿ��ж�ȡ���ݼ��ĸ������ԣ�ˢ�µ�ǰ���ݼ�����Ϣ��
	//##ModelId=483BB70B0262
	virtual OgdcBool RefreshInfo();	

	//! \brief ��������Դָ��
	virtual OgdcDataSource* GetDataSource() const;
	
	//! \brief ��������Դָ��
	virtual void SetDataSource(UGDataSourceOgdc* pDataSource);

public:	
	//! \brief �������ݼ���Ӧ����
	//##ModelId=483BB70B0264
	virtual OgdcString GetTableName();	
	
	//! \brief ��ȡ���������ݼ���ʱ�̡�
	//! \return ���������ݼ���ʱ�̡�
	//##ModelId=483BB70B0266
	virtual OgdcTime GetDateLastUpdated();	
	
	//! \brief ��ȡ�������ݼ���ʱ�̡�
	//! \return �������ݼ���ʱ�̡�
	//##ModelId=483BB70B0268
	virtual OgdcTime GetDateCreated();	
	
	//! \brief �ж����ݼ��Ƿ��ڴ򿪺��й��޸ġ�
	//! \return �й��޸ķ���TRUE��û�з���FALSE��
	//##ModelId=483BB70B0271
	virtual OgdcBool IsModified() const;
	
	//! \brief �������ݼ��Ƿ��й��޸ġ�
	//! \param bModified ���ݼ��Ƿ��й��޸ģ�Ĭ�����޸�[in]��
	//##ModelId=483BB70B0273
	virtual void SetModifiedFlag(OgdcBool bModified = TRUE);
	
	//! \brief �������ݼ��ַ����뷽ʽ
	//! \param textCodec ���ݼ��ַ����뷽ʽ[in]��
	//##ModelId=483BB70B0276
	virtual void SetCharset(OgdcString::Charset nCharset);

	//! \brief ��ȡ���ݼ��ַ����뷽ʽ��
	//! \return ���ݼ��ַ���ö�١�
	//##ModelId=483BB70B0279
	virtual OgdcString::Charset GetCharset() const;

	//! \brief ����ͶӰ����ϵ��
	//! \param coordSys [in]��
	//##ModelId=483BB70B027B
	virtual OgdcBool SetCoordSys(const OgdcCoordSys& coordSys);	

	//! \brief �õ�ͶӰ����ϵ��
	//##ModelId=483BB70B0282
	virtual OgdcBool GetCoordSys(OgdcCoordSys& coordSys) const;	

public:
	//##ModelId=483BB70B0285
	virtual OgdcBool BuildPyramid();	

	//! \brief �Ƴ�Ӱ���������
	//! \param  [in]��
	//! \return �Ƿ��Ƴ��ɹ����Ƿ���TRUE�����򷵻�FALSE��
	//! \remarks 
	//! \attention 
	//##ModelId=483BB70B0287
	virtual OgdcBool DropPyramid();	

	//##ModelId=483BB70B0289
	virtual OgdcBool IsBuildPyramid() const;
	
	//! \brief ��ȡӰ�����ݼ�ָ������ĳһ���ص����ɫֵ��
	//! \param nCol ���ص��к�[in]��
	//! \param nRow ���ص��к�[in]��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \return ��ɫֵ��
	//! \remarks ��ɫֵ����ֵ�����ݼ������ظ�ʽ��ͬ����ͬ��
	//! \attention 
	//##ModelId=483BB70B0296
	virtual OgdcColor GetPixel(OgdcInt nCol, OgdcInt nRow,UGint nBandIndex=0);	
	
	//! \brief  ����Ӱ�����ݼ�ָ������ĳһ���ص����ɫֵ��
	//! \param nCol ���ص��к�[in]��
	//! \param nRow ���ص��к�[in]��
	//! \param nColor ��ɫֵ[in]��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \remarks Ҫ�������ݼ������ظ�ʽ��ȷ�������ص����ɫֵ��
	//! \attention 
	//##ModelId=483BB70B029A
	virtual void SetPixel(OgdcInt nCol, OgdcInt nRow, OgdcColor nColor,UGint nBandIndex=0);	
	
	//! \brief ��ȡGrid���ݼ�ָ������ĳһ�������ֵ��
	//! \param nCol �����к�[in]��
	//! \param nRow �����к�[in]��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \return ����ֵ��
	//! \remarks 
	//! \attention 
	//##ModelId=483BB70B02A1
	virtual OgdcDouble GetValue(OgdcInt nCol, OgdcInt nRow,UGint nBandIndex=0);
	
	//! \brief ����Grid���ݼ�ָ������ĳһ�������ֵ��
	//! \param nCol �����к�[in]��
	//! \param nRow �����к�[in]��
	//! \param dValue ����ֵ[in]��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \remarks Ҫ�������ݼ��İ׻�ֵ��ȷ��������������ֵ��
	//! \attention 
	//##ModelId=483BB70B02A5
	virtual void SetValue(OgdcInt nCol, OgdcInt nRow, OgdcDouble dValue,UGint nBandIndex=0);

	//##ModelId=483BB70B02AA
	virtual OgdcRasterBlock* GetViewBlock(const OgdcRect2D& rcView, 
		OgdcInt nDeviceWidth, OgdcInt nDeviceHeight);

public:
	//! \brief ��ȡ���ݼ����͡�
	//! \remarks 
	//##ModelId=483BB70B02B1
	virtual OgdcInt GetType() const;

	//! \brief ��ȡ���ݼ�����
	//! \return ���ݼ����ַ�����
	//! \remarks 
	//! \attention 
	//##ModelId=483BB70B02B3
	virtual OgdcString GetName();

	//! \brief ��ȡ���ݼ�������Ϣ��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ-1
	//! \return ���ݼ���������Ϣ�ַ�����
	//! \remarks 
	//! \attention 
	//##ModelId=483BB70B02B5
	virtual OgdcString GetDescription(OgdcInt nBandIndex=0) const;

	//! \brief �������ݼ�������Ϣ��
	//! \param strtDescription ���ݼ�������Ϣ�ַ���[in]��
	//! \remarks 
	//! \attention 
	//##ModelId=483BB70B02B7
	virtual void SetDescription(const OgdcString& strtDescription,OgdcInt nBandIndex =0);

	//! \brief �������ݼ���ά����
	//! \return ���ݼ��Ŀռ�ά��, դ��Ϊ-1ά��
	//! \attention 
	//##ModelId=483BB70B02BA
	virtual OgdcInt GetStyleDimension();		
	
	//! \brief �������ݼ��ĵ���Χ��
	//! \return ���ݼ�����Χ���Ρ�
	//! \remarks 
	//! \attention 
	//##ModelId=483BB70B02BF
	virtual OgdcRect2D GetBounds();	
	
	//! \brief �������ݼ��ĵ���Χ��
	//! \param rcBunds ���ݼ�����Χ����[in]��
	//! \remarks 
	//! \attention 
	//##ModelId=483BB70B02C1
	virtual void SetBounds(const OgdcRect2D& rcBounds);	

	//##ModelId=483BB70B02C4
	virtual OgdcInt GetBandCount() const;

	//##ModelId=483BB70B02CB
// 	virtual void SetBandCombineMode(const OgdcArray<OgdcInt>& aryBand, ImgColorSpace nColorSpace);
// 	//##ModelId=483BB70B02CF
// 	virtual OgdcBool GetBandCombineMode(OgdcArray<OgdcInt>& aryBand, ImgColorSpace& nColorSpace) const;
	
	//! \brief ��ȡդ�����ݼ���ȡ�
	//! \return դ�����ݼ���ȣ�������ֵΪ��λ��
	//! \remarks 
	//! \attention 
	//##ModelId=483BB70B02D3
	virtual OgdcInt GetWidth() const;	
	
	//! \brief ��ȡդ�����ݼ��߶ȣ�������ֵΪ��λ��
	//! \return դ�����ݼ��߶ȣ�������ֵΪ��λ��
	//! \remarks 
	//! \attention ��
	//##ModelId=483BB70B02D5
	virtual OgdcInt GetHeight() const;	

	//! \brief ��ȡդ�����ݼ��������Чֵ
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ-1
	//! \return ��Чֵ��
	//! \remarks Grid���ݼ��İ׻�ֵ��Ҳ�ɴ˽ӿڻ�ȡ��
	//! \attention ��
	//##ModelId=483BB70B02D7
	virtual OgdcDouble GetNoValue(OgdcInt nBandIndex=0) const;	
	
	//! \brief ����դ�����ݼ�����Чֵ��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ-1
	//! \param dbNoValue [in]��
	//! \remarks Grid���ݼ��İ׻�ֵ��Ҳ�ɴ˽ӿ����á�
	//! \attention ��
	//##ModelId=483BB70B02D9
	virtual void SetNoValue(OgdcDouble dbNoValue,OgdcInt nBandIndex=0);
	
	//! \brief ��ȡӰ������ظ�ʽ��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ-1
	//! \return ���ظ�ʽö��ֵ��
	//! \remarks 
	//! \attention 
	//##ModelId=483BB70B02DC
    virtual PixelFormat GetPixelFormat(OgdcInt nBandIndex =0) const;	

	//! \brief ����ָ�������ݡ�
	//! \param nRowBlock Ӱ����к�[in]��
	//! \param nColBlock Ӱ����к�[in]��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \return Ӱ���ָ�롣
	//! \remarks 
	//! \attention 
	//##ModelId=483BB70B028B
	virtual OgdcRasterBlock* LoadBlock(OgdcInt nRowBlock, OgdcInt nColBlock,OgdcInt nBandIndex=0);	
    
	//! \brief ��һ�ڴ��е�Ӱ��������̡�
	//! \param pImgBlock Ӱ���ָ��[in]��
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ0
	//! \return �Ƿ�ɹ����棬�ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks 
	//! \attention 
	//##ModelId=483BB70B0293
	virtual OgdcBool SaveBlock(OgdcRasterBlock* pImgBlock,OgdcInt nBandIndex=0);	
	
	//! \param nBandIndex[in] ��������ֵ��Ĭ��Ϊ-1
	virtual void ReleaseAllBlocks(OgdcInt nBandIndex=-1);

	
	//##ModelId=483BB70B02DF
	UGDatasetRaster* GetDatasetRaster() const;	
	
	//##ModelId=483BB70B02E1
	void SetDatasetRaster(UGDatasetRaster* pDatasetRaster);
    
	//�Ƿ��Ƕನ�����ݼ�
	virtual OgdcBool IsMBRaster();

protected:	
	//##ModelId=483BB70B02E3
	UGDatasetRaster* m_pDatasetRaster;
	UGDataSourceOgdc* m_pDsOgdc;
};

}

#endif // !defined(AFX_UGDATASETRASTEROGDC_H__B310E3AF_CDAF_4FA8_9470_D1D414D5FBD5__INCLUDED_)

