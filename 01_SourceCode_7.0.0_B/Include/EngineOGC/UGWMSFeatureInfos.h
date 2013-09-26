// UGWMSFeatureInfos.h: doubleerface for the UGWMSFeatureInfos class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGWMSFEATUREINFOS_H)
#define UGWMSFEATUREINFOS_H

#include "Stream/ugexports.h"
#include "Stream/ugdefs.h"
#include "Toolkit/UGMarkup.h"
namespace UGC
{
class ENGINEOGC_API UGWMSFeatureInfos  
{
public:
	UGWMSFeatureInfos();
	virtual ~UGWMSFeatureInfos();
	
public:
	//! \brief ��
	//! \param UGDict<UGString dictQueryPairs>[out] ������Ϣ�ԡ�
	//! \return ��
	UGbool GetWMSFeatureInfos(UGDict<UGString,UGString>& dictQueryPairs);
private:
	//! \brief �ж�QueryLayers��layer���������ռ�Ĳ�ͬ�ֳ���Ӧ�Ľ�ֵ�ԡ�
	//! \param strValue [in]������layer��
	//! \param strKeys [out]��������ռ�ġ�
 	//! \param UGDict<UGString dictQueryPairs) [out] ����������ռ�Ϊ��������layersΪֵ�Ľ�ֵ�ԡ�
	//! \remarks ��
	void StorageQueryLayers(UGString strValue,UGStrings& strKeys,UGDict<UGString,UGString>& dictQueryPairs);
    
	//! \brief ��ȡ�ӷ�������������XML�ļ���
 	//! \param mk [in]  ������markup��
	//! \param UGDict<UGString dictQueryPairs>[out] ������Ϣ�ԡ�
	//! \return  
  	UGbool  ReadXMLInfo(UGMarkup& mk,UGDict<UGString,UGString>& dictQueryPairs);

	//! \brief ��ȡ�ӷ��������������ı��ļ���
	//! \param strFile [in] �ı��ļ��ĵ�ַ��
	//! \param UGDict<UGString dictQueryPairs>[out] ������Ϣ�ԡ�
	//! \return  
	UGbool  ReadTextInfo(UGString strFile,UGDict<UGString,UGString>& dictQueryPairs);

	//! \brief ����һ������GetFeatureInfo��URL��
	//! \param strLayers [in]������querylayers��
	//! \return ����URL��
 	UGString  GetFeatureInfoURL(UGString strLayers);

public: //��˽�����ԵĶ�д���� 
	UGString GetMainURL() const { return m_strURL; }
	void SetMainURL(UGString val) { m_strURL = val; }

	UGString GetBox() const { return m_strBox; }
	void SetBox(UGString val) { m_strBox = val; }

	UGString GetStyle() const { return m_strStyle; }
	void SetStyle(UGString val) { m_strStyle = val; }

	UGString GetFormat() const { return m_strFormat; }
	void SetFormat(UGString val) { m_strFormat = val; }

	UGString GetInfoFormat() const { return m_strInfoFormat; }
	void SetInfoFormat(UGString val) { m_strInfoFormat = val; }

	UGString GetRequest() const { return m_strRequest; }
	void SetRequest(UGString val) { m_strRequest = val; }

	UGString GetLayers() const { return m_strLayers; }
	void SetLayers(UGString val) { m_strLayers = val; }

	UGString GetQueryLayers() const { return m_strQueryLayers; }
	void SetQueryLayers(UGString val) { m_strQueryLayers = val; }

	UGlong GetWidth() const {	return m_nWidth; }
	void SetWidth(UGlong val) { m_nWidth = val;}

	UGlong GetHeight() const { return m_nHeight; }
	void SetHeight(UGlong val) { 	m_nHeight = val; }

	UGlong GetPx() const { return m_nPx; }
	void SetPx(UGlong val) { m_nPx = val; }
 	
	UGlong GetPy() const {return m_nPy;}
	void SetPy(UGlong val) { m_nPy = val; }
    
	UGString GetCRSName() const { return m_strCRSName; }
	void SetCRSName(UGString val) { m_strCRSName = val; }
public:
   UGDict<UGString,UGString> m_dictOrgPairs;
private:
	//! \brief ���ʷ���������������URL
	//! \remarks ��ע��Ϣ��
	UGString m_strURL;
	//! \brief ��������ͼ�߽�,��minx,miny,maxx,maxy���� 
	//! \remarks x,y�ֱ�����ȣ�γ�ȡ�
	UGString m_strBox;
	//! \brief ����ͼ��ķ��
	//! \remarks ��ע��Ϣ��
    UGString m_strStyle;
	//! \brief ���������ͼ�ĸ�ʽ
	//! \remarks ��ע��Ϣ��
	UGString m_strFormat;
	//! \brief ��������������ʾ��ʽ
	//! \remarks Ŀǰ��text/html,text/plain,application/vnd.ogc.gml��
	UGString m_strInfoFormat;
	//! \brief �����������
	//! \remarks request=GetFeatureInfo��
	UGString m_strRequest;
	//! \brief ͼ������
	//! \remarks ��ע��Ϣ��
	UGString m_strLayers;
	//! \brief ͼ������
	UGString m_strQueryLayers;
	//! \brief ����������ͼ������Ŀ�ȡ�
	//! \remarks ��λ�����ء�
	UGlong     m_nWidth;
	//! \brief ����������ͼ������ĸ߶ȡ�
	//! \remarks ��λ������
	UGlong     m_nHeight;	
	//! \brief ������ͼ�������ĳ��x���ꡣ	
	UGlong     m_nPx; 	
	//! \brief ������ͼ�������ĳ��y���ꡣ	
	UGlong     m_nPy;	
	//! \brief ͼ�������ο�ϵ��
	UGString m_strCRSName;
	
};
}
#endif // !defined(UGWMSFEATUREINFOS_H)


