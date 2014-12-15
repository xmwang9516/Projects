// CTest.h : main header file for the CTEST application
//

#if !defined(AFX_CTEST_H__1AAA4956_98C0_435F_9F08_24505577516B__INCLUDED_)
#define AFX_CTEST_H__1AAA4956_98C0_435F_9F08_24505577516B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCTestApp:
// See CTest.cpp for the implementation of this class
//

class CCTestApp : public CWinApp
{
public:
	CCTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTEST_H__1AAA4956_98C0_435F_9F08_24505577516B__INCLUDED_)
