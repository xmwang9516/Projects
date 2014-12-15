// CMyDataBase.h: interface for the CCMyDataBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMYDATABASE_H__1A116005_0F1F_47E2_A544_15E3C43E43AF__INCLUDED_)
#define AFX_CMYDATABASE_H__1A116005_0F1F_47E2_A544_15E3C43E43AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCMyDataBase  
{
public:
	int InsertDataBase(CString strEntryTime, CString strName, CString strIDNumber, CString strSex, CString strNation, CString strBirthDay, CString strAddress, char *pPhotoData, int nFileLen);
	void ReleaseBuffer();
	int dbExecute(char *pchSQL, char **ppchReturn);
	CCMyDataBase();
	virtual ~CCMyDataBase();


	//定义ado连接变量指针;
	_ConnectionPtr  m_pCon; 
	
	char*       m_pchOut;
	DWORD		m_nFileLen;//BMP文件长度
	char*		m_pBMPBuffer;

};

#endif // !defined(AFX_CMYDATABASE_H__1A116005_0F1F_47E2_A544_15E3C43E43AF__INCLUDED_)
