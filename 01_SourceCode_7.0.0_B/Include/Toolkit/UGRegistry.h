#ifndef UGREGISTRY_H
#define UGREGISTRY_H

#include "Toolkit/UGMarkup.h"
#include "Toolkit/UGHash.h"
#include "Toolkit/UGToolkit.h"

namespace UGC{

#ifdef SYMBIAN60
class TOOLKIT_APIC UGRegistry : public UGHash<UGString>
#else
class TOOLKIT_API UGRegistry : public UGHash<UGString>
#endif
{
private:
	  //!  \brief Toolkit
	enum ElemType 
	{ 
	  //!  \brief Toolkit
		Value = 0, 
	  //!  \brief Toolkit
		Object = 1, 
	  //!  \brief Toolkit
		Sequence = 2, 
	  //!  \brief Toolkit
		ObjectSequence = 3, 
	  //!  \brief Toolkit
		SubRegistry = 4, 
	  //!  \brief Toolkit
		ExternalFile = 5 
	};
	  //!  \brief Toolkit
	static TOOLKIT_APIF ElemType Convert(const UGString &strType);
	
public:
	//! \brief
	  //!  \brief Toolkit
	typedef UGHash<UGString> ObjType;
	  //!  \brief Toolkit
	//! \brief
	  //!  \brief Toolkit
	typedef UGArray<UGString> SeqType;
	//! \brief
	  //!  \brief Toolkit
	typedef UGArray<ObjType> ObjSeqType;
	//! \brief
	  //!  \brief Toolkit
	typedef UGHash<void*> VHash;
	//! \brief
	  //!  \brief Toolkit
	typedef VHash::POSITION VHash_Pos;

protected:
	TOOLKIT_APIF UGRegistry();
	TOOLKIT_APIF UGRegistry(const UGString& file);
	virtual TOOLKIT_APIF void LoadDoc(const UGString& content);
	virtual TOOLKIT_APIF void LoadFromMarkup(const UGMarkup& content);

	TOOLKIT_APIF void SaveDoc(UGMarkup& markup);
#ifdef OS_ANDROID
public: //��android �Ͽ��Ŵ˽ӿڣ���Ϊ�ϲ��û���ı�SuperMap.xml��·�������û��ı��ʱ����ô˽ӿ�
#endif
	TOOLKIT_APIF void LoadFile(const UGString& filename);
	
public:
	//! \brief
	  //!  \brief Toolkit
	static TOOLKIT_APIF UGString XmlPath();
	
	//! \brief
	  //!  \brief Toolkit
	static TOOLKIT_APIF UGRegistry& Root();
	
	//! \brief
	  //!  \brief Toolkit
	virtual TOOLKIT_APIF ~UGRegistry();
	
//	static ObjType ObjNull;
//	static SeqType SeqNull;
//	static ObjSeqType ObjSeqNull;
//	static UGRegistry RegNull;
	
	//! \brief
	  //!  \brief Toolkit
	TOOLKIT_APIF UGString Encoding() const;
	//! \brief
	  //!  \brief Toolkit
	TOOLKIT_APIF ObjType& Obj(const UGString& s) const;
	//! \brief
	  //!  \brief Toolkit
	TOOLKIT_APIF SeqType& Seq(const UGString& s) const;
	//! \brief
	  //!  \brief Toolkit
	TOOLKIT_APIF ObjSeqType& ObjSeq(const UGString& s) const;	
	//! \brief
	  //!  \brief Toolkit
	TOOLKIT_APIF UGRegistry& SubReg(const UGString& s) const;
	//! \brief
	  //!  \brief Toolkit
	TOOLKIT_APIF UGRegistry& SubFile(const UGString& s) const;	
	//! \brief
	  //!  \brief Toolkit
	TOOLKIT_APIF UGString Name() const;

	//! \brief ���޸����ڴ��еĶ����洢��ugc.xml�ļ���
	TOOLKIT_APIF UGbool Save();

	//! \brief �õ�SubFile�е��ļ���
	//! \param strTag ugc.xml�ļ��м�¼subfile�ı�ǩ������"PrjConfig"
	//! \return ������ugc.xml�ļ��м�¼���ⲿ�ļ���,��"PrjConfig.xml"
	//! \remarks �����ı�ǩΪ:<PrjConfig type="external">PrjConfig.xml</PrjConfig>
	TOOLKIT_APIF UGString GetSubFileName(const UGString& strTag) const;

private: 
	VHash m_Objs;
	VHash m_Seqs;
	VHash m_ObjSeqs;
	VHash m_SubRegs;
	VHash m_SubExts;
	ObjType m_SubFiles;

	UGString m_strFileName;
	UGString m_strRootName;
};


//! \brief ��resource.xml�ж�ȡ�ַ�����Դ����
//! \author zengzm
//! \remarks resource.xml�����ݽ�����һЩ����, ��Ҫ�ǲ�����id��Ϊtag name,����id �Զ�����
//! �ʶ�ԭ��Registry�಻������. �����Registry������ר�Ŵ���resource.xml����
class TOOLKIT_API UGRegistryResource : public UGRegistry
{
public:
	  //!  \brief Toolkit
	virtual void LoadDoc(const UGString& content);
	virtual TOOLKIT_APIF void LoadFromMarkup(const UGMarkup& content);
};

//! \brief ��epsfont.xml�ж�ȡ�ַ�����Դ����
class TOOLKIT_API UGRegistryEpsFont: public UGRegistry
{
public:
	  //!  \brief Toolkit
	virtual void LoadDoc(const UGString& content);
	virtual TOOLKIT_APIF void LoadFromMarkup(const UGMarkup& content);
};

}
#endif

