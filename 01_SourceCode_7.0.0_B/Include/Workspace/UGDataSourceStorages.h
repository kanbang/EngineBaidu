// UGDataSourceStorages.h: interface for the UGDataSourceStorages class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDATASOURCESTORAGES_H__ED631128_7709_4035_9E99_DEBEC6BB9D03__INCLUDED_)
#define AFX_UGDATASOURCESTORAGES_H__ED631128_7709_4035_9E99_DEBEC6BB9D03__INCLUDED_

#include "Workspace/UGDataSourceStorage.h"

namespace UGC {

class WORKSPACE_API UGDataSourceStorages  
{
public:
	UGDataSourceStorages();
#ifdef SYMBIAN60
	~UGDataSourceStorages();
#else
	virtual ~UGDataSourceStorages();
#endif
	

};

}

#endif // !defined(AFX_UGDATASOURCESTORAGES_H__ED631128_7709_4035_9E99_DEBEC6BB9D03__INCLUDED_)

