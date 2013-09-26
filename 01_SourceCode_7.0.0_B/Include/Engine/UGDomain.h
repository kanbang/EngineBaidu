
#ifndef UGDOMAIN_H
#define UGDOMAIN_H

#include "Engine/UGEngDefs.h"

namespace UGC 
{
	class UGDataset;
	//! \brief	ֵ�����
	class ENGINE_API UGDomainBase
	{
	public:

		virtual ~UGDomainBase(){}

		//! \brief	�������ֵ��Ч��
		//	\param	val[IN]	Ҫ����ֵ	
		virtual UGbool Check(const UGVariant &val) = 0;

		//! \brief	���ָ�����ֶ����ͣ��Ƿ��Ǹ���ǰ��֧�ֹ������ֶ�����
		//	\param	fieldtype[IN] Ҫ�����ֶ�����
		virtual UGbool CheckFieldType(UGFieldInfo::FieldType fieldtype) = 0;

		//!	\brief	��ȡ����ֶ�����
		virtual UGFieldInfo::FieldType GetFieldType() { return UGFieldInfo::UnKnown; };
		virtual UGFieldInfo::FieldType GetFieldType() const { return UGFieldInfo::UnKnown; };

	public:
		//! \brief	Ŀǰ������֧�ַ�Χ�ʹ������֣�������ʽ���������Ժ���չ
		//			��չ��������RangeNot��CodeNot��������Range��Code�ļ����ȡ��
		enum DomainType { Range = 1, Code = 2, RangeNot = 3, CodeNot = 4};

	
		//! \brief	��ȡ�������
		DomainType GetDomainType() { return m_Type; }
		DomainType GetDomainType() const { return m_Type; }

		//! \brief	����
		UGDomainBase(UGuint nID, const UGString &name, DomainType type):m_nID(nID), m_strName(name), m_Type(type){}

		UGDomainBase(UGuint nID, const UGString &name, const UGString &desc, DomainType type):m_nID(nID), m_strName(name), \
			m_strDesc(desc), m_Type(type){}

		UGDomainBase():m_nID(0), m_Type(Range){}

	public:
		//! \brief	���ID
		UGuint m_nID;

		//! \brief	�������
		UGString m_strName;

		//! \brief	���������Ϣ
		UGString m_strDesc;

	protected:
		//! \brief	������ͣ������Բ��ܱ��޸ģ�����ʱ����ָ����
		DomainType m_Type;



	};


	//! \brief	��������
	class ENGINE_API UGRangeInfo
	{
	public:

		//! \brief	
		UGRangeInfo() {}

		virtual~ UGRangeInfo(){}


		//! \brief	���������������ͣ���Ӧ����ʽ�ֱ�Ϊ��[ ]��( ]��[ )������
		enum RangeType { CloseClose = 1, OpenClose = 2, CloseOpen = 3, OpenOpen = 4 };

		//! \brief	��ȡ������ֶ�����
		UGFieldInfo::FieldType GetFieldType() { return m_FieldType; }
		UGFieldInfo::FieldType GetFieldType() const { return m_FieldType; }

		void SetFieldType(UGFieldInfo::FieldType fieldType){m_FieldType = fieldType;}

		void SetType(RangeType type ){m_Type = type;}

		//! \brief	���ָ����ֵ�Ƿ��ڸ����䷶Χ��
		//	\param	val[IN]	Ҫ����ֵ
		UGbool IsIn(const UGVariant &val);

		//! \brief	��ȡ������
		const UGVariant& GetMinValue() { return m_MinValue; }
		const UGVariant& GetMinValue() const { return m_MinValue; }
		const UGVariant& GetMaxValue() { return m_MaxValue; }
		const UGVariant& GetMaxValue() const { return m_MaxValue; }

		void SetMinValue(UGVariant left){m_MinValue=left;}
		void SetMaxValue(UGVariant right){m_MaxValue=right;}

		void SetRange(UGVariant left,UGVariant right){m_MinValue = left; m_MaxValue = right;}

	public:
		//! \brief	��������
		UGRangeInfo(const UGRangeInfo &interval):m_Type(interval.m_Type), m_MinValue(interval.m_MinValue), \
			m_MaxValue(interval.m_MaxValue), m_FieldType(interval.m_FieldType) {}

		//! \brief	����������ʽ
		UGRangeInfo(UGFieldInfo::FieldType fieldType, UGVariant leftValue, UGVariant rightValue, RangeType type);

	private:

		//! \brief ���º����ǱȽ�ĳһ��ֵ��ָ��ֵ�Ĵ�С��ϵ
		//	\param compare[IN]  Ҫ�Ƚϵ�ֵ
		//		   standard[IN] ָ���ĺ�����׼ֵ
		UGbool LessThan(UGint compare, UGint standard) { return compare < standard; }
		UGbool LessThan(UGlong compare, UGlong standard) { return compare < standard; }
		UGbool LessThan(UGdouble compare, UGdouble standard) { return compare < standard; }

		UGbool MoreThan(UGint compare, UGint standard) { return compare > standard; }
		UGbool MoreThan(UGlong compare, UGlong standard) { return compare > standard; }
		UGbool MoreThan(UGdouble compare, UGdouble standard) { return compare > standard; }

		UGbool Equal(UGdouble compare, UGdouble standard) { return UGEQUAL(compare, standard); }

		UGbool LessEqual(UGint compare, UGint standard) { return !MoreThan(compare, standard); }
		UGbool LessEqual(UGlong compare, UGlong standard) { return !MoreThan(compare, standard); }
		UGbool LessEqual(UGdouble compare, UGdouble standard) { return Equal(compare, standard) || LessThan(compare, standard); }

		UGbool MoreEqual(UGint compare, UGint standard) { return !LessThan(compare, standard); }
		UGbool MoreEqual(UGlong compare, UGlong standard) { return !LessThan(compare, standard); }
		UGbool MoreEqual(UGdouble compare, UGdouble standard) { return Equal(compare, standard) || MoreThan(compare, standard); }

	public:
		//! \brief	��������
		RangeType m_Type;

	private:
		//! \brief	����
		UGVariant m_MinValue;

		//! \brief	����
		UGVariant m_MaxValue;

		//! \brief	������ֶ����ͣ�������ͳһ��TimeStamp���ʹ�����Ϊ�����ʵ��ֻ��datetime����
		UGFieldInfo::FieldType m_FieldType;
	};


	//! \brief	��Χ������
	class ENGINE_API UGRangeDomain:public UGDomainBase
	{
	public:
		UGRangeDomain() {m_Type = Range;m_FieldType = UGFieldInfo::UnKnown;}
		
		virtual ~UGRangeDomain(){}

		//! \brief	�������ֵ��Ч��
		//	\param	val[IN]	Ҫ����ֵ
		virtual UGbool Check(const UGVariant &val);

		//! \brief	���ָ�����ֶ����ͣ��Ƿ��Ǹ���ǰ��֧�ֹ������ֶ�����
		//	\param	fieldtype[IN] Ҫ�����ֶ�����
		virtual UGbool CheckFieldType(UGFieldInfo::FieldType fieldtype);

		//! \brief	��ȡ����ֶ�����
		virtual UGFieldInfo::FieldType GetFieldType() { return m_FieldType; }
		virtual UGFieldInfo::FieldType GetFieldType() const { return m_FieldType; }

	public:
		//!	\brief	����
		UGRangeDomain(UGuint nID, const UGString& name, UGFieldInfo::FieldType fieldtype, const UGArray<UGRangeInfo> &rangeinfos):\
			UGDomainBase(nID, name, Range), m_FieldType(fieldtype)
		{
			Append(rangeinfos);
		}

		UGRangeDomain(UGuint nID, const UGString &name, const UGString &desc,\
			UGFieldInfo::FieldType fieldtype, const UGArray<UGRangeInfo> &rangeinfos):\
			UGDomainBase(nID, name, desc, Range), m_FieldType(fieldtype)
		{
			Append(rangeinfos);
		}

		//! \brief	��������
		UGRangeDomain(const UGRangeDomain &RDomain);

	public:
		//!	\brief	�����е���������ת���ɶ����ƣ��Ա��ڴ洢
		//			��ʽΪ��[ �������|����1������|����1������|����1������|...|����n������|����n������|����n������ ]
		//	\param	pResult[OUT]  ���ش洢���������ݵĶѵ�ָ�루���渺���ͷţ�
		//			nSize[OUT]	���ض��������ݵĴ�С
		UGbool ToBinary(void* &pResult, UGint &nSize);

		//! \brief	��ȡ��������
		const UGArray<UGRangeInfo>& GetRangeInfos() { return m_RangeInfos; }
		const UGArray<UGRangeInfo>& GetRangeInfos() const { return m_RangeInfos; }

		//! \brief	��ȡָ��λ�õ�����
		//	\param	nIndex[IN]	ָ����λ��
		const UGRangeInfo& Get(UGint nIndex);
		const UGRangeInfo& Get(UGint nIndex) const;

		//! \brief	���û�ı�ָ��λ�õ����䣨�ýӿ������Ҫ�ǿ������������ֶ������Ƿ���ƥ�䣩
		//	\return	����ƥ�������óɹ��򷵻�TRUE����֮FALSE
		UGbool Set(UGint nIndex, const UGRangeInfo &rangeinfo);

		//!	\brief	����һ������
		UGbool Add(const UGRangeInfo &rangeinfo);

		//!	\brief	�������䣨����intervals�����Ͳ�ƥ������佫�ᱻ��������
		void Append(const UGArray<UGRangeInfo> &rangeinfos);

		//!	\brief	�Ƴ�ָ��λ�õ�����
		//	\param	nIndex[IN]	ָ����λ��
		//			nCount[IN]	��ָ��λ�������Ƴ����ٸ�
		void Remove(UGint nIndex, UGint nCount = 1);

		//!	\brief	�Ƴ����е�����
		void RemoveAll() { m_RangeInfos.RemoveAll(); }

	protected:
		//!	\brief	��¼���е����䣬����涨���е�����������߼������ʽ�����һ��
		//			��Ϊ˽�г�Ա��Ϊ�˱�֤���������ֶ����ͱ���һ�£�ͨ��ǰ��Ľӿ���������
		UGArray<UGRangeInfo> m_RangeInfos;

		//!	\brief	����ֶ����ͣ������Դ���ʱ���뱻ָ���������������޸ģ�
		UGFieldInfo::FieldType m_FieldType;
	};


	//! \brief	UGRangeNotDomain��UGRangeDomain��ȡ��
	class ENGINE_API UGRangeNotDomain:public UGRangeDomain
	{
	public:
		//! \brief	�������ֵ��Ч��
		//	\param	val[IN]	Ҫ����ֵ
		virtual UGbool Check(const UGVariant &val) { return !UGRangeDomain::Check(val); }

		virtual ~UGRangeNotDomain(){}

	public:
		//!	\brief	����
		UGRangeNotDomain(UGuint nID, const UGString &name, UGFieldInfo::FieldType fieldtype, const UGArray<UGRangeInfo> &intervals);

		UGRangeNotDomain(UGuint nID, const UGString &name, const UGString &desc,\
			UGFieldInfo::FieldType fieldtype, const UGArray<UGRangeInfo> &intervals);

		//! \brief	����UGRangeDomain������
		UGRangeNotDomain(const UGRangeDomain &RDomain);

		//! \brief	��������
		UGRangeNotDomain(const UGRangeNotDomain &RNotDomain);

	private:
		//! \brief	�������ˣ�Ĭ�Ϲ����ǲ�������Σ�
		UGRangeNotDomain() {}
	};


	//! \brief	���������Ϣ
	class ENGINE_API UGCodeInfo
	{
	public:
		UGCodeInfo(){;}

		virtual ~UGCodeInfo(){}

		//! \brief	��ȡ�ֶ�����
		UGFieldInfo::FieldType GetFieldType() { return m_FieldType; }
		UGFieldInfo::FieldType GetFieldType() const { return m_FieldType; }

		void SetFieldType(UGFieldInfo::FieldType type){m_FieldType = type;}

		void SetDescription(UGString description){m_strDesc = description;}


		//!	\brief	��ȡ����ֵ
		const UGVariant& GetValue() { return m_Value; }
		const UGVariant& GetValue() const { return m_Value; }

		void SetValue(UGVariant value){m_Value = value;}

	public:
		//!	\brief	����
		UGCodeInfo(UGFieldInfo::FieldType fieldType,UGVariant value,const UGString &desc);

		//!	\brief	��������
		UGCodeInfo(const UGCodeInfo &codeinfo):m_Value(codeinfo.m_Value), m_strDesc(codeinfo.m_strDesc), \
			m_FieldType(codeinfo.m_FieldType) {}

	public:
		//! \brief	����ĺ�������
		UGString m_strDesc;

	private:
		//! \brief	ʵ�ʴ���ֵ
		UGVariant m_Value;

		//! \brief	������ֶ�����
		UGFieldInfo::FieldType m_FieldType;
	};


	//! \brief	����������
	class ENGINE_API UGCodeDomain:public UGDomainBase
	{
	public:
		UGCodeDomain() {m_Type = Code;m_FieldType = UGFieldInfo::UnKnown;}

		virtual ~UGCodeDomain(){}

		//! \brief	�������ֵ��Ч��
		//	\param	val[IN]	Ҫ����ֵ	
		virtual UGbool Check(const UGVariant &val);

		//! \brief	���ָ�����ֶ����ͣ��Ƿ��Ǹ���ǰ��֧�ֹ������ֶ�����
		//	\param	fieldtype[IN] Ҫ�����ֶ�����
		virtual UGbool CheckFieldType(UGFieldInfo::FieldType fieldtype);

		//! \brief	��ȡ����ֶ�����
		virtual UGFieldInfo::FieldType GetFieldType() { return m_FieldType; }
		virtual UGFieldInfo::FieldType GetFieldType() const { return m_FieldType; }

	public:
		//! \brief	����
		UGCodeDomain(UGuint nID,  const UGString &name, \
			UGFieldInfo::FieldType fieldtype, UGArray<UGCodeInfo> &codeinfos):\
			UGDomainBase(nID, name, Code), m_FieldType(fieldtype)
		{
			Append(codeinfos);
		}

		//! \brief	����
		UGCodeDomain(UGuint nID, const UGString &name, const UGString &desc,\
			UGFieldInfo::FieldType fieldtype, UGArray<UGCodeInfo> &codeinfos):\
			UGDomainBase(nID, name, desc, Code), m_FieldType(fieldtype)
		{
			Append(codeinfos);
		}

		//!	\brief	��������
		UGCodeDomain(const UGCodeDomain &CDomain);

	public:
		//!	\brief	�����еĴ�����Ϣת���ɶ����ƣ��Ա��ڴ洢
		//			��ʽΪ��[ �������|����1��ֵ|����1�ĺ�������|...|����n��ֵ|����n�ĺ������� ]
		//	\param	pResult[OUT]  ���ش洢���������ݵĶѵ�ָ�루���渺���ͷţ�
		//			nSize[OUT]	���ض��������ݵĴ�С
		UGbool ToBinary(void* &pResult, UGint &nSize);

		//! \brief	��ȡ���а��������д�����Ϣ
		const UGArray<UGCodeInfo>& GetCodeInfos() { return m_CodeInfos; }
		const UGArray<UGCodeInfo>& GetCodeInfos() const { return m_CodeInfos; }

		//!	\brief	��ȡָ��λ�õĴ�����Ϣ
		const UGCodeInfo& Get(UGint nIndex);
		const UGCodeInfo& Get(UGint nIndex) const;

		//! \brief	���û�ı�ָ��λ�õĴ�����Ϣ���ýӿ������Ҫ�ǿ��Ǵ�����Ϣ������ֶ������Ƿ���ƥ�䣩
		//	\return	����ƥ�������óɹ��򷵻�TRUE����֮FALSE
		UGbool Set(UGint nIndex, const UGCodeInfo &codeinfo);

		//!	\brief	����һ��������Ϣ
		UGbool Add(const UGCodeInfo &codeinfo);

		//!	\brief	���Ӵ�����Ϣ������codeinfos�����Ͳ�ƥ��Ĵ��뽫�ᱻ��������
		void Append(const UGArray<UGCodeInfo> &codeinfos);

		//!	\brief	�Ƴ�ָ��λ�õĴ�����Ϣ
		//	\param	nIndex[IN]	ָ����λ��
		//			nCount[IN]	��ָ��λ�������Ƴ����ٸ�
		void Remove(UGint nIndex, UGint nCount = 1);

		//!	\brief	�Ƴ����еĴ�����Ϣ
		void RemoveAll() { m_CodeInfos.RemoveAll(); }

	protected:
		//!	\brief	����ֶ����ͣ������Դ���ʱ���뱻ָ���������������޸ģ�
		UGFieldInfo::FieldType m_FieldType;

		//!	\brief	��¼���еĴ�����Ϣ
		UGArray<UGCodeInfo> m_CodeInfos;
	};


	//! \brief	UGCodeNotDomain��UGCodeDomain��ȡ��
	class ENGINE_API UGCodeNotDomain:public UGCodeDomain
	{
	public:
		//! \brief	�������ֵ��Ч��
		//	\param	val[IN]	Ҫ����ֵ	
		virtual UGbool Check(const UGVariant &val) { return !UGCodeDomain::Check(val); }

		virtual ~UGCodeNotDomain(){}

	public:
		//! \brief	����
		UGCodeNotDomain(UGuint nID, const UGString &name, UGFieldInfo::FieldType fieldtype, const UGArray<UGCodeInfo> &codeinfos);

		UGCodeNotDomain(UGuint nID, const UGString &name, const UGString &desc, \
			 UGFieldInfo::FieldType fieldtype, const UGArray<UGCodeInfo> &codeinfos);

		//!	\brief	����UGCodeDomain������
		UGCodeNotDomain(const UGCodeDomain &CDomain);

		//!	\brief	��������
		UGCodeNotDomain(const UGCodeNotDomain &CNotDomain);

	private:
		//! \brief	����Ĭ�Ϲ���
		UGCodeNotDomain() {}
	};


	//!	\brief	�������ֶεĹ���
	struct ENGINE_API UGDomainField
	{
		//!	\brief	����
		UGDomainField(UGuint nDatasetID, const UGString &strFieldName, UGuint nDomainID):m_nDatasetID(nDatasetID), \
			m_strFieldName(strFieldName), m_nDomainID(nDomainID) {}

		UGDomainField():m_nDatasetID(0), m_nDomainID(0) {}

		//!	\brief	���ݼ���ID
		UGuint m_nDatasetID;

		//!	\brief	�ֶε�����
		UGString m_strFieldName;

		//!	\brief	���ID
		UGuint m_nDomainID;
	};

};

#endif