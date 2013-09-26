//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief ������ͼ�ࡣ
//!  \details ���������ͼ��ķ�װ��
//!  \author ��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOGROUNDOVERLAY_H__520E3CA0_E078_4DC6_A877_410CB2EF52F6__INCLUDED_)
#define AFX_UGGEOGROUNDOVERLAY_H__520E3CA0_E078_4DC6_A877_410CB2EF52F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Geometry3D/UGGeometry3D.h"
#include "Base3D/UGVector3d.h"
#include "Toolkit/UGPalette.h"
namespace UGC
{
//! \brief ������ͼ�ࡣ
class GEOMETRY3D_API UGGeoGroundOverlay: public UGGeometry3D  
{
public:
	//! \brief ���캯����
	UGGeoGroundOverlay();
	//! \brief ����������
	virtual ~UGGeoGroundOverlay();
	//! \brief ��һ��GroundOverlay��������һ��GroundOverlay�����á���
	UGbool Make(const UGGeoGroundOverlay& GroundOverlay);

	//! \brief ��ͼƬ·����ͼƬ���ĵ�λ�á�ͼƬ�ߴ繹��GeoGroundOverlay��
	//! \param strImagePath ����ͼƬ·��[in]��
	//! \param &pntPos ͼƬ���ĵ�λ��[in]��
	//! \param szSize ͼƬ�ߴ�[in]��
	UGbool Make(const UGString& strImagePath, const UGPoint3D &pntPos, const UGSize2D& szSize);	
	//! \brief ��ͼƬ���ݡ�ͼƬ���ĵ�λ�á�ͼƬ�ߴ繹��GeoGroundOverlay��
	//! \param aryImageData ͼƬ����[in]��
	//! \param &pntPos ͼƬ���ĵ�λ��[in]��
	//! \param szSize ͼƬ�ߴ�[in]��
	//! \param bCopyData �Ƿ񿽱����ݣ���Ϊ����ֵһ������[in]��
	UGbool Make(UGArray<UGImageData*>& aryImageData, const UGPoint3D &pntPos, const UGSize2D& szSize, UGbool bCopyData);	
	
	//! \brief ��ü������ͣ��˴�����GeoGroundOverlay
	virtual UGGeometry::Type GetType() const;

	//! ����ά�������ﷵ��3
	virtual UGint GetDimension() const;
	
	//! \brief �ͷ����ݣ������ñ�����
	virtual void Clear();
	//! \brief ��ö�ά�ڵ㡣
	//! \return ��ά�㡣
	virtual UGPoint2D GetInnerPoint() const;	
	
	//! \brief �����ά�ڵ㡣
	//! \return ��ά�㡣
	virtual UGPoint3D GetInnerPoint3D()const;
	
	//! \brief ����geometry���ͣ��ٵ��ø��Ե�make����ȥʵ�֡�
	//! \param pGeometry [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ����ɹ�����true��
	virtual UGbool MakeWithGeometry(const UGGeometry* pGeometry);	

	
	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid()const;
	 
	//! \brief �õ�ͼƬ·����
	//! \return ����ͼƬ·����
	//! \remarks ��ʾ��ʱ���Ȳ鿴ͼƬ�����Ƿ���ڣ���������ڣ��ٴ�ͼƬ·���м�������
	UGString GetImagePath()const;
	//! \brief ����ͼƬ·����
	//! \param strImagePath [in] Ҫ���õ�ͼƬ·����
	void     SetImagePath(const UGString& strImagePath);
 
	//! \brief �õ��߶ȡ�
	//! \return ���ظ߶ȡ�
	//! \remarks �ø߶Ȳ��ǿ���ȥ�ĸ߶�,����û�н�����ת֮ǰ�ĸ߶ȡ�
	UGdouble GetHeight() const;	

	//! \brief ���ø߶ȡ�
	//! \param dHeight [in] Ҫ���õĸ߶ȡ�
	//! \return dHeightС�ڵ���0, ����false��
	UGbool SetHeight( UGdouble dHeight );	

	//! \brief �õ���ȡ�
	//! \return ���ؿ�ȡ�
	//! \remarks �ÿ�Ȳ��ǿ���ȥ�Ŀ��,����û�н�����ת֮ǰ�Ŀ�ȡ�
	UGdouble GetWidth() const;

	//! \brief ���ÿ�ȡ�
	//! \param dWidth [in] Ҫ���õĿ�ȡ�
	//! \return dWidthС�ڵ���0,����false��
	UGbool SetWidth( UGdouble dWidth );	

	//! \brief ����һ֡ͼƬ���ݣ��ʺ�gif֮������ݡ�
	UGint AddImageData(UGImageData* pImageData);

	//! \brief ����һ֡ͼƬ���ݣ��ʺ�gif֮������ݡ�
	void InsertAtImageData(UGint nIndex, UGImageData* pImageData);

	//! \brief �õ�ĳһ֡ͼƬ���ݣ��ʺ�gif֮������ݡ�
	UGImageData* GetImageData(UGint nIndex);

	//! \brief �Ƴ�ĳһ֡ͼƬ���ݣ��ʺ�gif֮������ݡ�
	UGImageData* RemoveImageData(UGint nIndex);

	//! \brief �ͷ�ĳ֡ͼƬ���ݣ��ʺ�gif֮������ݡ�
	UGint ReleaseImageData(UGint nIndex, UGint nCount = 1);

	//! \brief �ͷ��ڴ�ͼƬ����
	void ReleaseAllImageData();

	//! \brief �õ�֡������ͼƬ�ɶ���֡���
	UGint GetFrameCount() const;

	//! \brief �õ���ǰ֡ 
	UGint GetCurrentFrame() const;

	//! \brief ���õ�ǰ֡ 
	void SetCurrentFrame(UGint nCurFrame);

	//! \brief �洢����������
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	//! \brief ���������м���
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE ,UGbool bSDBPlus = FALSE);
	
	//! \brief ��ȡ���ݴ洢ʱ�Ĵ�С
	//! \return ���ش洢��С
	//! \remarks ��δ���Ǳ����������SaveGeoData()һ��ά��
	//! \attention �ַ����ĳ���Ҫ+4
	virtual UGint GetDataSize() const;
private:
	//! \brief ����ͼƬ����
	void SetImageData(const UGArray<UGImageData*>& aryImageData,UGbool bCopyData);
protected:
	//! \brief ��������Bounds
	//! \return ���صõ���Bounds
	virtual UGRect2D ComputeBounds() const;	

	//!\brief �õ�Boundingbox
	virtual UGBoundingBox ComputeBoundingBox() const;

private:
	//! \brief �ڴ�ͼƬ����
	//! \remarks ����ķ�ʽ����֧������GIF��ʽ��ͼƬ
	UGArray<UGImageData*> m_aryImageData;
	//! \brief ��ǰ֡
	UGint m_nCurFrame;
	//! \brief ���
	UGdouble m_dWidth;
	//! \brief �߶�
	UGdouble m_dHeight;
	//! \brief ͼƬ·��
	//! \remarks ��ͼ��ʱ���ȿ��ڴ�ͼƬ����m_aryImageData�Ƿ���ڣ�����������ڴ�ͼƬ·������
	UGString m_strImagePath;
	//! \brief ���ͼƬ����ȡ�Ƴ�ͼͼƬ����
	UGMutex m_mutex;
};
}
#endif // !defined(AFX_UGGEOGROUNDOVERLAY_H__520E3CA0_E078_4DC6_A877_410CB2EF52F6__INCLUDED_)

