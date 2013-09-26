//////////////////////////////////////////////////////////////////////////
//!  \file     UGTextureLib.h:
//!  \brief	   ��ά�����
//!  \details  ʵ������������ά����������ɾ���Ͷ�ȡ����
//!  \author   wangmao/yaoyh��
//!  \attention 
//!   Copyright (c) 1997-2010 SuperMap GIS Technologies,Inc.  <br>
//!   All Rights Reserved.
//!  \version 1.0
//////////////////////////////////////////////////////////////////////////
#ifndef UGTEXTURELIB_H
#define UGTEXTURELIB_H

#include "Stream/ugdefs.h"
#include "Engine/UGDataset.h"
#include "Toolkit/UGTextureInfo.h"

#define TEXTURE_CACHE_COUNT (10)

namespace UGC {

	class UGDataSource;
	
	class ENGINE_API UGTextureLib
	{
	public:
			typedef struct  
			{
				UGString strKey;
				UGuint   nRefCount;
				UGTextureInfo data;
			}NodeCache;

			// �������������
			// ���������Դ����ǿղ����Ǵ򿪵�,���򹹽�������⽫�޷�����ʹ��
			UGTextureLib(UGDataSource* pDs);
			UGTextureLib();
			~UGTextureLib();

			// ������Դ��Ա��ֵ
			void SetDataSource(UGDataSource* pDs);

			// ����һ�����������
			// ��������ɹ�����TRUE,���򷵻�FALSE
			// note:����Ѿ�����������Ѿ����ڷ��ش����ɹ�
			// ����ֵ�� Ϊ-1 ��ʾ����ʧ��  Ϊ0��ʾ�Ѿ����ڣ� Ϊ1��ʾ�����ɹ�
			UGbool  CreateTextureLib();

			// ɾ�����������
			// �ɹ�����TRUE,���򷵻�FALSE
			UGbool  DeleteTextureLib();

			// �洢����,���������ID�Ѿ�����,�����ü���+1
			// ��������ʱ�Զ��������
			// �洢���� UGTextureData��װ����������
			// �ɹ�����TRUE,���򷵻�FALSE
			UGbool	AddTexture(const UGTextureInfo& textureData);

			//Ϊ�����������ü���,ʧ�ܷ���FALSE,���򷵻�TRUE
			//������ܿ����ʵ����������������
			UGbool AddReference(const UGString& argstrkey);

			// ���������ID�͵ȼ���ȡnLevel������������
			// nLevelΪ����ȼ�,0Ϊ�ϸ����,�������ߴ���������߼���ʱȡ��ֲ�����
			// ��ȡ�������� UGTextureData
			// �ɹ�����TRUE,���򷵻�FALSE
			UGbool GetTexture(UGTextureInfo& textureData,UGbool bLoadCompress=TRUE);

			//! \brief ��ȡѹ�����������ݣ������ݲ����н�ѹ
			//! \param textureInfo �����ȡ��������Ϣ		
			//! \return �ɹ�����TRUE, ���򷵻�FALSE
			UGbool GetCompressTexture(UGTextureInfo& textureInfo);

			// ���������IDж������,���������ID�Ѿ�����,�����ü���-1
			// ���ü���Ϊ0ʱ�Զ�ɾ������
			// �ɹ�����TRUE,���򷵻�FALSE
			UGbool  DeleteTexture(const UGString& strkey);

			// ������������ͼƬ��С,ģ�����ݼ�Ĭ��ֵΪ512,��Ч���Ͽ����ֵ�Ѿ��㹻
			// �������ͼƬ���������ֵ�����һ���ʵ�������
			UGbool SetMaxTexureSize(const UGuint size);;
	private:
			// ����������Ϣ��
			UGbool CreateTextureTable();
			
			// ��������������ϢUGTextureData�� ����������������Ա�
			// nTextureID �Ǳ�ʾ�������������Ա��е�SmID
			// textureData ��ʾ�����������Ϣ
			// ���ع������˶��ٲ������
			UGbool UpdateTextureTier(const UGTextureInfo& textureData,UGVariant& varImageData);
			
			// �����ⲿ�����Ĺؼ��ּ���Ψһ������ID
			UGuint  GetMapCode(const UGString& strkey);	

			// UDB����
			void UDBBeginTrans();
			// UDB����
			void UDBEndTrans();

			// �Ƿ��ڻ�����
			UGuint IsCacheTexture(UGString& strKey);

			// ��ӵ�������ȥ
			void   AddToCache(UGString& strKey,UGuint nRefCount,const UGTextureInfo& textureData);

			// �����������ĳ��ȵ������ʼ
			void  SaveDataSize(UGuchar* pBuffer,UGuint size);

			// �õ��������ĳ���
			UGuint LoadDataSize(UGuchar* pBuffer);

			// ��������������Դ
			UGDataSource* m_pDataSource;
			
			NodeCache     m_TextureCache[TEXTURE_CACHE_COUNT];

			// �Ƿ���Ҫ������С��
			UGbool m_bBigEndian;

			// �������Ĵ�С
			UGuint m_nMaxTexSize;

			// ��ʹ�õ����������ӿ�
			const UGTextureLib& operator=(const UGTextureLib&);
			UGTextureLib(const UGTextureLib&);

			// �ҵ�һ�������2�ı���������
			UGuint NearP2(UGuint val);

			// ����������
			void  LimitMaxTexture(UGuint &width,UGuint &height);
	};
}

#endif // !defined(UGTEXTURELIB_H)

