//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief ��ά��ѧ�ࡣ
//!  \details ��ɶ���ά���õ�����ѧ�����ķ�װ��
//!  \author ��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMATHENGINE_H__90331450_3347_42D5_B0A0_41353F9437C8__INCLUDED_)
#define AFX_UGMATHENGINE_H__90331450_3347_42D5_B0A0_41353F9437C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Base3D/UGPrerequisites3D.h"
#include "Toolkit/UGPalette.h"
#include "Base3D/UGMesh.h"

//�ֶ������ĸ�����ľ���任 2011.02.22 wangxinhe,Ŀǰֻ��Ҫ3���� 2012.04.01
#define MATRIX_MULTI(VERTICES,MATRIX,ARRAYX,ARRAYY,ARRAYZ) 	\
		VERTICES[0] =MATRIX[0][0] *ARRAYX[0] + MATRIX[1][0] *ARRAYY[0] + MATRIX[2][0] *ARRAYZ[0] +MATRIX[3][0]; \
		VERTICES[3] =MATRIX[0][0] *ARRAYX[1] + MATRIX[1][0] *ARRAYY[1] + MATRIX[2][0] *ARRAYZ[1] +MATRIX[3][0]; \
		VERTICES[6] =MATRIX[0][0] *ARRAYX[2] + MATRIX[1][0] *ARRAYY[2] + MATRIX[2][0] *ARRAYZ[2] +MATRIX[3][0]; \
		VERTICES[1] =MATRIX[0][1] *ARRAYX[0] + MATRIX[1][1] *ARRAYY[0] + MATRIX[2][1] *ARRAYZ[0] +MATRIX[3][1]; \
		VERTICES[4] =MATRIX[0][1] *ARRAYX[1] + MATRIX[1][1] *ARRAYY[1] + MATRIX[2][1] *ARRAYZ[1] +MATRIX[3][1]; \
		VERTICES[7] =MATRIX[0][1] *ARRAYX[2] + MATRIX[1][1] *ARRAYY[2] + MATRIX[2][1] *ARRAYZ[2] +MATRIX[3][1]; \
		VERTICES[2] =MATRIX[0][2] *ARRAYX[0] + MATRIX[1][2] *ARRAYY[0] + MATRIX[2][2] *ARRAYZ[0] +MATRIX[3][2]; \
		VERTICES[5] =MATRIX[0][2] *ARRAYX[1] + MATRIX[1][2] *ARRAYY[1] + MATRIX[2][2] *ARRAYZ[1] +MATRIX[3][2]; \
		VERTICES[8] =MATRIX[0][2] *ARRAYX[2] + MATRIX[1][2] *ARRAYY[2] + MATRIX[2][2] *ARRAYZ[2] +MATRIX[3][2];

//�ĸ�����ֱ�Ӹ�ֵ 2010.02.22 wangxinhe
#define MATRIX_ASSIGN(VERTICES,ARRAYX,ARRAYY,ARRAYZ)	\
												VERTICES[0] =ARRAYX[0]; \
												VERTICES[1] =ARRAYY[0]; \
												VERTICES[2] =ARRAYZ[0]; \
												VERTICES[3] =ARRAYX[1]; \
												VERTICES[4] =ARRAYY[1]; \
												VERTICES[5] =ARRAYZ[1]; \
												VERTICES[6] =ARRAYX[2]; \
												VERTICES[7] =ARRAYY[2]; \
												VERTICES[8] =ARRAYZ[2];

namespace UGC 
{
#if !defined (IOS) && !defined OS_ANDROID
typedef void (*MESHSCANPROC)(UGint X, UGint Y, UGuint pData);
#endif
//! \brief ��ά��ѧ�����ࡣ
class BASE3D_API UGMathEngine  
{
public:
	//! \brief ���캯��
	UGMathEngine();
	//! \brief ��������
	virtual ~UGMathEngine();
	//! \brief ����ת��Ϊ����
	//! \param degrees �Զ�Ϊ��λ��ֵ[in]��
	//! \return �����Ի��ȱ�ʾ��ֵ��
#if !defined (IOS) && !defined OS_ANDROID
	static UGdouble DegreesToRadians(UGdouble degrees);	
	//! \brief ������ת��Ϊ��
	//! \param dRadians �Ի���Ϊ��λ��ֵ[in]��
	//! \return �����Զȱ�ʾ��ֵ��
	static UGdouble RadiansToDegrees(UGdouble dRadians);
	//! \brief ��������ת��Ϊ�ѿ�������ϵ��Ĭ�ϵ���뾶Ϊ6378137 
	//! \param dLongitude �������꾭��[in]��
	//! \param dLatitude ��������ά��[in]��
	//! \param GLOBAL_RADIUS ����6378137[in]��
	//! \return �ѿ�������ϵ�����ꡣ
	//! \attention ���ǵ���ΪԲ�����������
	static UGVector3d SphericalToCartesian(UGdouble dLongitude, UGdouble dLatitude,UGdouble dRadius = GLOBAL_RADIUS);	

	//! \brief ����ת��Ϊ����
	//! \param fDegree �Զ�Ϊ��λ��ֵ[in]��
	//! \return �����Ի��ȱ�ʾ��ֵ��
	static UGdouble Degree2Radian(UGdouble fDegree);
	//! \brief �ѿ�������ת��Ϊ�������꣨�������꣩��
	//! \param x �ѿ�������x[in]��
	//! \param y �ѿ�������y[in]��
	//! \param z �ѿ�������z[in]��
	//! \return ��������ϵ���ꡣ
	static UGVector3d CartesianToSphericalD(UGdouble x, UGdouble y, UGdouble z);	
	//! \brief ��Ԫ��ת��Ϊŷ���ǡ�
	//! \param q ��Ԫ��[in]��
	//! \return ŷ���ǡ�
	static UGVector3d QuaternionToEuler(UGQuaternion4d q);	
	//! \brief ŷ����ת��Ϊ��Ԫ����
	//! \param yaw ��y����ת�ĽǶ�[in]��
	//! \param pitch ��x����ת�Ƕ�[in]��
	//! \param roll ��z����ת�ĽǶ�[in]��
	//! \return ������Ԫ����
	static UGQuaternion4d EulerToQuaternion(UGdouble yaw, UGdouble pitch, UGdouble roll);	
#endif
	//! \brief ��γ�Ⱥ���Ƭ�ĳߴ�����Ƭ��������
	//! \param latitude ά�ȣ���λ����[in]��
	//! \param tileSize ��Ƭ�ߴ磬��ά����[in]��
	//! \return ��Ƭ������������
	static UGint GetRowFromLatitude(UGdouble latitude, UGdouble tileSize, UGbool bStartLT = FALSE);
	//! \brief �ɾ��Ⱥ���Ƭ�ĳߴ�����Ƭ��������
	//! \param longitude ���ȣ���λ����[in]��
	//! \param tileSize ��Ƭ�ߴ磬��ά����[in]��
	//! \return ��Ƭ������������
	static UGint GetColFromLongitude(UGdouble longitude, UGdouble tileSize);


	//! \brief �����������Ƭ�ĳߴ�����Ƭ��������
	//! \param Coord �����꣬��λ��[in]��
	//! \param tileSize ��Ƭ�ߴ磬��[in]��
	//! \param dL0TileSize 0�����Ƭ�ߴ磬��[in]��
	//! \return ��Ƭ������������
	static UGint GetRowFromCoord(UGdouble Coord, UGdouble tileSize, UGdouble dL0TileSize);

	//! \brief �ɺ��������Ƭ�ĳߴ�����Ƭ��������
	//! \param Coord �����꣬��λ��[in]��
	//! \param tileSize ��Ƭ�ߴ磬��[in]��
	//! \param dL0TileSize 0�����Ƭ�ߴ磬��[in]��
	//! \return ��Ƭ�����ĺ�����
	static UGint GetColFromCoord(UGdouble Coord, UGdouble tileSize, UGdouble dL0TileSize);
    
#if !defined (IOS) && !defined OS_ANDROID
	//! \brief �������������ǶȾ��롣
	//! \param lonA A��ľ��ȣ���λ����[in]��
	//! \param latA A���γ�ȣ���λ����[in]��
	//! \param lonB B��ľ��ȣ���λ����[in]��
	//! \param latB B���γ�ȣ���λ����[in]��
	//! \return A��B���������ǶȾ��롣
	static UGdouble SphericalDistance( UGdouble lonA, UGdouble latA,UGdouble lonB,UGdouble latB);	
	//! \brief �������������ǶȾ��롣
	//! \param lonA A��ľ��ȣ���λ����[in]��
	//! \param latA A���γ�ȣ���λ����[in]��
	//! \param lonB B��ľ��ȣ���λ����[in]��
	//! \param latB B���γ�ȣ���λ����[in]��
	//! \return A��B���������ǶȾ��롣
	static UGdouble SphericalDistanceCos( UGdouble lonA, UGdouble latA,UGdouble lonB,UGdouble latB);	
	//! \brief ��һ�����������������������������б��������
	//! \param pVertex ��������[in]��
	//! \param pIndice ���������δ�����������[in]��
	//! \param nVertexCount ��������Ĵ�С[in]��
	//! \param nIndiceCount ��������Ĵ�С[in]��
	//! \return ���������������
	//! \attention ÿ���������������ǹ⻬������������Χ���еĵ�������õ��������
	static UGdouble* ComputeVertexNormals(UGdouble* pVertex,UGushort* pIndice,UGint nVertexCount,UGint nIndiceCount);
	//! \brief ��һ���������������������������ʹ���������
	//! \param pVertex ��������[in]��
	//! \param pIndice ���������δ�����������[in]��
	//! \param nVertexCount ��������Ĵ�С[in]��
	//! \param nIndiceCount ��������Ĵ�С[in]��
	//! \return ���������������
	//! \attention ÿ���������������ǹ⻬������������Χ���еĵ�������õ��������
	static UGfloat* ComputeVertexNormals(UGfloat* pVertex,UGushort* pIndice,UGint nVertexCount,UGint nIndiceCount);
	static UGfloat* ComputeVertexNormals(UGfloat* pVertex,UGuint* pIndice,UGint nVertexCount,UGint nIndiceCount);
	//! \brief ��һ����������������������ʹ���������
	//! \param pVertex ���������δ���������,ÿ�����㹹��һ�������Σ�������[in]��
	//! \param nVertexCount ��������Ĵ�С[in]��
	//! \return ���������������
	//! \attention ÿ���������������ǹ⻬������������Χ���еĵ�������õ��������
	static UGdouble* ComputeVertexNormals(UGdouble* pVertex,UGint nVertexCount);
	//! \brief ��һ����������������������ʹ���������
	//! \param pVertex ���������δ���������,ÿ�����㹹��һ�������Σ�������[in]��
	//! \param nVertexCount ��������Ĵ�С[in]��
	//! \return ���������������
	//! \attention ÿ���������������ǹ⻬������������Χ���еĵ�������õ��������
	static UGfloat* ComputeVertexNormals(const UGfloat* pVertex,const UGuint nVertexCount);

	//! \brief ��һ����������������������ʹ������������ϵĽӿڣ����������⡣
	//! \param pVertex ���������δ���������,ÿ�����㹹��һ�������Σ�������[in]��
	//! \param nVertexCount ��������Ĵ�С[in]��
	//! \param pNormal �������������[out]��
	//! \param bQuad [in]��
	static void ComputeFaceNormals(UGfloat* pVertex,UGint nVertexCount, UGfloat* pNormal, UGbool bQuad = FALSE);	
	//! \brief �ɲ����ߵ���������������ά�����ķ����ˡ�
	//! \param vec1 ����1[in]��
	//! \param vec2 ����2[in]��
	//! \param vec3 ����3[in]��
	//! \return ��ķ�������
	static UGVector3d ComputeFaceNormals(const UGVector3d& vec1,const UGVector3d& vec2,const UGVector3d& vec3);	
	
	//! \brief ����������vec1������vec2��ŷ���ǡ�
	//! \param vec1 ����1[in]��
	//! \param vec2 ����2[in]��
	//! \return ����1������2��ŷ���ǡ�
	static UGVector3d GetVec1RotToVec2(const UGVector3d& vec1,const UGVector3d& vec2);	
	//! \brief ������ĳ��������תһ���Ƕ������ɵ�ŷ���ǡ�
	//! \param fAngle ��ת�Ƕ�[in]��
	//! \param vecAxies ��ת��[in]��
	//! \return ŷ���ǡ�
	static UGVector3d GetRotFormAngleAxies(UGdouble fAngle,UGVector3d& vecAxies);	
	//! \brief �жϸ����͵�������
	//! \param fValue ����ĸ�����ֵ[in]��
	//! \return ��������1����������-1��0����0.0��
	static UGdouble Sign (UGdouble fValue);	

	//! \brief ��бʽֱ������ο�Ľ���
	//! \param pnt1 ��ά��[in]��
	//! \param pnt1 ֱ��б��[in]��
	//! \param pnt1 ���ο�[in]��
	//! \return ���㡣
	static UGPoint2Ds IntersectionOfRectByPointslopeline(UGPoint2D& point, UGdouble dSlope, UGRect2D& rect);

	static UGdouble Compute2DAngleFromY(UGPoint2D pnt1);	
	//! \brief �ж��Ƿ��ǺϷ�ʵ����
	//! \param dValue ʵ��[in]��
	//! \return trueΪ�Ϸ���falseΪ�Ƿ���
	static UGbool IsRealNaN(UGdouble dValue);
	//! \brief ���㶥��İ�Χ�С�
	//! \param pVertex ��������[in]��
	//! \param nVertexCount ������Ŀ[in]��
	//! \param boundingBox ��Χ��[out]��
	static void  ComputeBoundingBox(UGfloat* pVertex,UGint nVertexCount,UGBoundingBox& boundingBox);	
	//! \brief ����������ǻ���
	//! \param pPoint ������Ķ�������[in]��
	//! \param nPoint ������Ŀ[in]��
	//! \param nTri �����ε���Ŀ[out]��
	//! \return �����εĶ������顣
	static void PartTriangulation(const UGArray<UGPoint3D>& arrPoint, UGArray<UGushort>& arrTriIndex, UGint& nTri);	
	//! \brief �������������ཻ��
	//! \param &rayOrg �������[in]��
	//! \param rayDelta ���߷��򣨵�λ����[in]��
	//! \param p0 �����ε�һ����[in]��
	//! \param p1 �����εڶ�����[in]��
	//! \param p2 �����ε�������[in]��
	//! \return �����ཻ����t��
	//! \remarks rayIntersect = rayOrg + rayDelta * t��
	static UGbool RayTriangleIntersect(UGVector3d &rayOrg, UGVector3d& rayDelta, 
									   UGVector3d& p0, UGVector3d& p1, UGVector3d& p2, 
									   UGdouble& t);

	//! \brief  ������ռ��е�һ�ξ���ת����γ�ȿ�ȡ�
	//! \param CartesianDist [in]��
	//! \param SphericalDist [in]��
	//! \return ��
	//! \remarks  �뾶���õ���뾶��
	//! \attention ��
	static void CartesianDist2SphericalDist(const UGdouble& CartesianDist, UGdouble& SphericalDist);
	//! \brief ���������������ˡ�
	//! \param pDest Ŀ�Ķ�������[in]��
	//! \param pSrc Դ��������[in]��
	//! \param nCount �������[in]��
	//! \param matView ����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static void VerticesMulitplyViewMatrix(UGfloat* pDest, UGfloat* pSrc,
										   UGint nCount, UGMatrix4d& matView);
	//! \brief �����������ļнǡ�
	//! \param v1 ����1[in]��
	//! \param v2 ����2[in]��
	//! \return ���������нǡ�
	static UGdouble AngleOfV1V2(UGVector3d& v1, UGVector3d& v2);	
	
	//static UGVector3d VerticalVectorOfV3(UGVector3d& v1, UGVector3d& v2, UGVector3d& v3);
	//! \brief  ���ر�a��ģ���������ӽ�a��2�Ĵη�������
	static UGuint NextP2 (UGuint a);

	//! \brief  ����2�Ķ��ٴη��պô��ڻ����a��
	static UGuint NextLog2(UGuint a);

	//! \brief �õ���������С�
	//! \param nLevel �ļ����ڵĲ�[in]��
	//! \param nRow �ļ����ڵ���[in]��
	//! \param nCol �ļ����ڵ���[in]��
	//! \param nCacheRow �ļ��ڻ���Ŀ¼����[out]��
	//! \param nCacheCol �ļ��ڻ���Ŀ¼����[out]��
	static void GetCacheRowCol(UGint nLevel, UGint nRow, UGint nCol, UGint& nCacheRow, UGint& nCacheCol);

	//! \brief �õ��ļ��Ļ�������·����
	//! \param nLevel �ļ����ڵĲ�[in]��
	//! \param nRow �ļ����ڵ���[in]��
	//! \param nCol �ļ����ڵ���[in]��
	//! \param nVersion �ļ��汾��[in]��
	//! \return �ļ������·����û��ͼƬ����չ������
	static UGString GetCacheLocalPath(UGint nLevel, UGint nRow, UGint nCol, UGint nVersion);

	//! \brief �ж϶����Ƿ���ʱ������
	//! \param pPoint ��������[in]��
	//! \param nPoint ���������С[in]��
	//! \return �Ƿ���ʱ������
	static UGint IsCounterClockwise(const UGPoint3D* pPoint, UGint nPoint);	
	//! \brief �߶������ཻ��
	//! \param vecSphereCenter ����[in]��
	//! \param dSphereRadius ��뾶[in]��
	//! \param vecStart �߶���ʼ��[in]��
	//! \param vecEnd �߶ν�����[in]��
	//! \param t1 ����1[in]��
	//! \param t2 ����2[in]��
	//! \return ���������
	//! \remarks ���㷶ΧΪ0-1��Χ����Ч��
	//! \attention ��
	static UGint LineSphereIntersection(UGVector3d vecSphereCenter,
							UGdouble dSphereRadius,
							UGVector3d vecStart,
							UGVector3d vecEnd, 
							UGfloat& t1, UGfloat& t2);

	//! \brief ����rectRes�Ƿ��rectObj�ཻ��
	//! \param rectRes һ���ǽϴ�ľ��ο�[in]��
	//! \param rectObj �����Եľ��ο�[in]��
	//! \return ��Χ�Ƿ��ཻ��
	//! \remarks �����Ƿ����ߡ�
	//! \attention ��
	static UGbool IsIntersect3D(const UGRect2D& rectRes,const UGRect2D& rectObj);

	//! \brief ����rectRes�Ƿ��pnt�ཻ��
	//! \param rectRes [in]��
	//! \param pnt [in]��
	//! \return ��Χ�Ƿ��ཻ��
	//! \remarks �����Ƿ����ߡ�
	//! \attention ��
	static UGbool IsIntersect3D(const UGRect2D& rectRes, const UGPoint2D& pnt);

	//! \brief ���ڴ��ڼ�������������Ƕȵ����Ǻ���ֵ
	//! \param dAngle [in]�Ƕ�
	//! \param dCosVal[out]�Ƕȶ�Ӧ������
	//! \param dSinVal[out]�Ƕȶ�Ӧ������
	//! \remarks ��
	static void AdjSpecialTriFunValue(const UGdouble dAngle,UGdouble &dCosVal,UGdouble &dSinVal);
	
	//! \brief ����õ��µĲ���㣬����������۾������������һ���ı�����
	//! \param ViewMatrix ��ͼ����[in]��
	//! \param vecInsertPos �����ԭʼ��[in]��
	//! \param nScale �۾���Ŀ���ľ��룬�µ�Ŀ��㵽ԭʼĿ���ľ��룬���ߵı�ֵ[in]��
	//! \return �µ�Ŀ��㡣
	//! \remarks ��
	//! \attention ��Ҫ�����ڵ�����ı�����Ϊ�˷�ֹ�ر������������ʱ�ݵ��������⡣
	static UGVector3d GetCloserInsertPnt(const UGMatrix4d& ViewMatrix, const UGVector3d& vecInsertPos, UGint nScale);

	//! \brief ���������潻�㡣
	//! \param vecStart ��ʼ����[in]��
	//! \param vecEnd �յ�����[in]��
	//! \param dRadius ��İ뾶[in]
	//! \param vecIntersect ����[out]��
	//! \return ��
	//! \remarks ��
	//! \attention ��������Ϊ(0,0,0)��
	static UGbool RayIntersectionWithSphere(UGVector3d& vecStart, UGVector3d& vecEnd,UGdouble dRadius, UGVector3d& vecIntersect);	
	
	//! \brief ͼ�����ݲ�����һ���ǴӴ�С�Ĳ���
	//! \param pSRC Դ���� �������ռ�
	//! \param pDEST Ŀ������ �������ռ�
	//! \param nSrcWidth Դ���ݿ�
	//! \param nSrcHeight Դ���ݸ�
	//! \param nDestWidth Ŀ�����ݿ�
	//! \param nDestHeight Ŀ�����ݸ�
	static void  ScaleImage(UGuchar* pSRC, UGuchar* pDEST, UGint nSrcWidth, UGint nSrcHeight, 
		                    UGint nDestWidth, UGint nDestHeight, UGImageSamplerType nType = IMAGE3D_RESAMPLER_BILINEAR);

	//! \brief �Ե�������������ţ������༶����
	//! \param srcImageData Դ����
	//! \param desImageData Ŀ������ 
	//! \param nNewWidth Ŀ�����ݿ�
	//! \param nNewHeight Ŀ�����ݸ�
	static void ScaleImage(const UGImageData& srcImageData,UGImageData& desImageData,UGint nNewWidth,UGint nNewHeight);
#endif   
	//! \brief ���������Ͻǿ�ʼ��Tile�ľ�γ��Bounds.
	//! \param nRow Tile����[in].
	//! \param nCol Tile����[in].
	//! \param level Tile�Ĳ�[in].
	//! \param dL0TileSizeDeg ���ľ�γ�ȿ�ȣ�Ĭ��Ϊ180[in].
	//! \param UGRect2D ���ؾ�γ��Bounds[out].
	static UGRect2D CalcTileBounds(UGint nRow, UGint nCol, UGint level, UGdouble dL0TileSizeDeg = 180);
#if !defined (IOS) && !defined OS_ANDROID
	//! \brief ���������½ǿ�ʼ��Tile�ľ�γ��Bounds.
	//! \param nRow Tile����[in].
	//! \param nCol Tile����[in].
	//! \param level Tile�Ĳ�[in].
	//! \param dL0TileSizeDeg ���ľ�γ�ȿ�ȣ�Ĭ��Ϊ180[in].
	//! \param UGRect2D ���ؾ�γ��Bounds[out].
	static UGRect2D CalcLeftBottomTileBounds(UGint nRow, UGint nCol, UGint level, UGdouble dL0TileSizeDeg = 180);

	//! \brief����������Bounds�ķ�Χ
	//! \param rcBounds ��Ҫ�����ķ�Χ[in].
	//! \param nLevel �����Ĳο���[in].
	static UGRect2D CeilBounds(UGRect2D rcBounds,UGint nLevel,UGdouble dL0TileSizeDeg = 180);

	//! \brief ͨ�����Բ�ֵ����������š�from gluScaleImage
	//! \param components ��ɫ�ɷ�������RGBA��4
	//! \param widthin ����ͼ��Ŀ��
	//! \param heightin ����ͼ��ĸ߶�
	//! \param datain ����ͼ���ָ��
	//! \param widthout ���ͼ��Ŀ��
	//! \param heightout ���ͼ��ĸ߶�
	//! \param dataout ���ͼ���ָ��
	static void ScaleImageInternal(UGint components, UGint widthin, UGint heightin,
		const UGuchar *datain,
		UGint widthout, UGint heightout,
		UGuchar* dataout);

	//! \brief ��ͼ����������Mipmapͼ������
	//! \param components [in] ԭʼͼ��λ�Ŀǰ��֧��32λ
	//! \param widthin	  [in] ԭʼͼ����
	//! \param heightin   [in] ԭʼͼ��߶�
	//! \param datain     [in] ԭʼͼ������
	//! \param widthout   [in/out] ����ͼ��Ŀ��
	//! \param heightout  [in/out] ����ͼ��ĸ߶�
	//! \param arrTextureSize [in/out] ԭʼMipMapͼ������ÿ���ƫ��
	//! \return MipMap���ɽ��
	static UGuchar* GenerateMipMap(UGint components, UGuint& widthin, UGuint& heightin,
		UGuchar *datain, UGuint& widthout, UGuint& heightout,UGArray<UGuint>& arrTextureOffset);

	//! \brief ��ͼ����������Mipmapͼ������
	//! \param pImageData [in] ԭʼͼ������
	//! \param pTotalImageData [out] ���ɺ��ͼ������ 
	static UGuchar* GenerateMipMap(UGint components, UGint& widthin, UGint& heightin,
		UGuchar *datain, UGint& widthout, UGint& heightout);

	//! \brief ͨ��һ����Mipmapͼ�����ݵõ�Mipmapͼ������
	//! \param pMipMapImageData [in] һ����Mipmapͼ������
	//! \param arrMipMapImageData [out] Mipmapͼ������ 
	static UGuchar* ParseMipMap(UGint components, UGint widthin, UGint heightin,
		const UGuchar *datain,
		UGArray<UGuint>& arrTextureSize);

	//! \brief ����8�������BoundingBox���浽�����������ԭ�㣩�ľ��� by wangxinhe 2010.12.14
	//! \param vecBoundBox BoundBox��8������
	//! \param BoundingBox ���ڵĵ������꣨��γ�ȣ�����߶ȣ�
	//! \param viewMatrix ��ǰ����ͼ����
	//! \param BoundingBox ��Z�����ת�Ƕ�
	//! \param altitude ��ǰ������ĸ߶�
	//! \param tilt �������Tilt�Ƕ�
	//! \return �õ��ľ���
	static double GetBoundingBoxDistanceToCamera(const UGVector3d *vecBoundBox,	const UGPoint3D &pntBoundBox,
												const UGMatrix4d &viewMatrix,UGdouble rotation,UGdouble altitude,
												UGdouble tilt);

	//! \brief ����ֱ����ƽ��Ľ���
	//! \param planeVector [IN] ƽ�淨����
	//! \param planePoint [IN] ƽ����һ��
	//! \param lineVector [IN] ֱ�ߵ�����
	//! \param linePoint [IN] ֱ����һ��
	//! \return ���ؽ���
	static UGbool GetPlaneLineIntersectPoint(UGVector3d &planeVector,UGVector3d &planePoint,
		UGVector3d &lineVector,UGVector3d &linePoint,UGVector3d& vecIntersect);

	//! \brief ˫���Բ���
	//! \param pSRC [IN] ��Ҫ���в�����ԭʼ��
	//! \param pDEST [IN] �����Ĳ������
	//! \param nOldWidth [IN] ԭʼ���ݵĿ��
	//! \param nOldHeight [IN] ԭʼ���ݵĸ߶�
	//! \param nWidth [IN] ��������������ݵĿ��
	//! \param nHeight [IN] ��������������ݵĸ߶�
	static void  TerrainSamplerBiLinear(const UGfloat* pSRC, UGfloat* pDEST, UGint nOldWidth, UGint nOldHeight, 
		UGint nWidth, UGint nHeight);

	//! \brief ��ͼ���������ݽ��ж��봦����ʱֻ��24λͼ����
	//! \param components ��ɫ�ɷ�������RGBA��4
	//! \param width ����ͼ��Ŀ��
	//! \param height ����ͼ��ĸ߶�
	//! \param datain ����ͼ���ָ��
	//! \param dataout ���ͼ���ָ��
	static UGbool ClipImageData(UGint components, UGint width, UGint height, const UGuchar *datain, UGuchar *dataout);

	//! \brief ������ƽ����
	//! \param planeNormalVector ƽ�淨����
	//!	\param PlanePoint ƽ���ϵ�һ����
	//! \param triangleP1 �����ζ���1
	//! \param triangleP2 �����ζ���2
	//! \param triangleP3 �����ζ���3
	//! \return ���Ǳ�����ƽ��Ľ���(���ཻ���淵��0���㣬���ڵ������㷵��1���㣩
	static UGArray<UGVector3d> GetPlaneTriangleIntersectLine(UGVector3d& planeNormalVector, UGVector3d& planePoint, 
		UGVector3d& triangleP1, UGVector3d& triangleP2, UGVector3d& triangleP3);

	//! \brief ����ά����ƽ��ķ������
	//! \param planeNormalVector ƽ�淨����
	//!	\param PlanePoint ƽ���ϵ�һ����
	//! \param point ָ���Ĵ������
	//! \return ��ά����ƽ��ķ�����룬����ֵ�Ǿ��룬������ʾ�뷨���������ͬһ��
	static UGdouble GetPointDirectionDistanceToPlane(UGVector3d& planeNormalVector, UGVector3d& PlanePoint,
		UGVector3d& point);

	//! \brief ƽ����ƽ������
	//! \param planeVector1 ƽ��1�ķ�������[in]
	//! \param planePoint1	ƽ��1�е�����[in]
	//! \param planeVector2 ƽ��2�ķ�������[in]
	//! \param planePoint2	ƽ��2�е�����[in]
	//! \param lineVector		���ߵķ�������[out]
	//! \param linePoint			�����ϵĵ�����[out]
	//! \return ��ý��߷���TRUE�����򷵻�FALSE
	static UGbool GetPlanePlaneIntersectLine(UGVector3d &planeVector1,UGVector3d &planePoint1,
		UGVector3d &planeVector2,UGVector3d &planePoint2,UGVector3d& lineVector, UGVector3d& linePoint);

	//! \brief ������������������
	//! \param triangleA1��triangleA2��triangleA3	������A�������˵�����[in]
	//! \param triangleB1��triangleB2��triangleB3	������B�������˵�����[in]
	//! \return ���ؽ��ߵ������˵�����
	static UGArray<UGVector3d> GetTriangleTriangleIntersectPoints(UGVector3d &triangleA1, UGVector3d &triangleA2,
		UGVector3d &triangleA3, UGVector3d &triangleB1, UGVector3d &triangleB2, UGVector3d &triangleB3);

	//! \brief �жϵ��Ƿ���Mesh�ڲ�
	//! \param point	���жϵĵ�[in]
	//! \param mesh	�����жϵ�mesh[in]
	//! \return ��mesh�ڲ�����TRUE������ΪFALSE
	static UGbool IsPointInMesh(UGVector3d &point, UGMesh &mesh);

	//! \brief �ж��������Ƿ��BOX�ཻ
	//! \param p1 p2 p3		��������������[in]
	//! \param pMax pMin	BOX�����ֵ����Сֵ[in]
	//! \return �ཻ����TRUE������ΪFALSE
	static UGbool IsTrangleBoxIntersect(UGVector3d &p1, UGVector3d &p2, UGVector3d &p3,
		UGVector3d &pMax, UGVector3d &pMin);

	//! \brief �ж�ƽ���Ƿ��BOX�ཻ
	//! \param planeVector	ƽ�淨����[in]
	//! \param planePoint		ƽ����һ��[in]
	//! \param pMax pMin	BOX�����ֵ����Сֵ[in]
	//! \return �ཻ0�������ǰ��1������ĺ���-1
	static UGint IsPlaneBoxIntersect(UGVector3d &planeVector,UGVector3d &planePoint,
		UGVector3d &pMax, UGVector3d &pMin);
private:
	//! \brief ��ά��Ĳ�ˡ�
	//! \param U ��1[in]��
	//! \param V ��2[in]��
	//! \return ��1�͵�2�Ĳ�ˡ�
	static UGfloat Kross (const UGPoint2D& U, const UGPoint2D& V);	
	//! \brief �ж��߶��Ƿ���Բ׶֮�ڡ�
	//! \param V0 �߶ε���ʼ�˵�[in]��
	//! \param V1 �߶ε���ֹ�˵�[in]��
	//! \param VM �߶�V0-VM����ֹ�˵�[in]��
	//! \param VP �߶�V0-VP����ֹ�˵�[in]��
	//! \param bClockwise ������Ƿ�˳ʱ��[in]��
	//! \return �߶�v0-v1�Ƿ������VM-V0-VP��Բ׶�ڡ�
	static UGbool SegmentInCone(UGPoint2D& V0, UGPoint2D& V1, UGPoint2D& VM, UGPoint2D& VP, UGbool bClockwise);	
	//! \brief �ж�������е����������Ƿ��ǶԽ��ߡ�
	//! \param pPoint ����εĶ�������[in]��
	//! \param nPoint �������[in]��
	//! \param i0 ����1������[in]��
	//! \param i2 ����2������[in]��
	//! \param bClockwise ������Ƿ�˳ʱ��[in]��
	//! \return ����1�Ͷ���2�Ƿ񹹳ɶ���εĶԽ��ߡ�
	static UGbool IsDiagonal(const UGPoint3D* pPoint, UGushort* pPointIndex, UGint nPoint,UGint i0, UGint i2, UGbool bClockwise);	

	//! \brief �ж�������Ĳ��������
	//! \param x1 ����1��x����[in]��
	//! \param y1 ����1��y����[in]��
	//! \param x2 ����2��x����[in]��
	//! \param y2 ����2��y����[in]��
	//! \param x3 ����3��x����[in]��
	//! \param y3 ����3��y����[in]��
	//! \return ����1ʱΪ��ʱ�룬��1ʱΪ˳ʱ�룬0Ϊ���ߡ�
	static UGint counterclockwise(UGdouble x1, UGdouble y1, UGdouble x2, UGdouble y2, UGdouble x3, UGdouble y3);	
	
	//! \brief ���ڽ�����
	static void  ImageSamplerNearestNeighbor(UGuchar* pSRC, UGuchar* pDEST, UGint nSrcWidth, UGint nSrcHeight, 
		                    UGint nDestWidth, UGint nDestHeight);
	//! \brief ˫���Բ���
	static void  ImageSamplerBiLinear(UGuchar* pSRC, UGuchar* pDEST, UGint nSrcWidth, UGint nSrcHeight, 
		                    UGint nDestWidth, UGint nDestHeight);
	
	//! \brief �����������
	static void  ImageSamplerCubic(UGuchar* pSRC, UGuchar* pDEST, UGint nSrcWidth, UGint nSrcHeight, 
		                    UGint nDestWidth, UGint nDestHeight);

	//! \brief ͨ�����Բ�ֵ����������š�from gluScaleImage
	//! \param components ��ɫ�ɷ�������RGBA��4
	//! \param widthin ����ͼ��Ŀ��
	//! \param heightin ����ͼ��ĸ߶�
	//! \param datain ����ͼ���ָ��
	//! \param dataout ���ͼ���ָ��
	static void HalveImage(UGint components, UGuint width, UGuint height,
		const UGuchar *datain, UGuchar *dataout);

public:
	static SceneType m_msSceneType;
	//ƽ��ͶӰ����
	static UGPoint2D m_msPntProCenter;
	//ƽ��ͶӰ����
	static UGRect2D m_msSceneViewRect;
#endif
};
}
#endif // !defined(AFX_UGMATHENGINE_H__90331450_3347_42D5_B0A0_41353F9437C8__INCLUDED_)

