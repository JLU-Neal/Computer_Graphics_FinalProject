// CGWORK0521.h : main header file for the CGWORK0521 application
//

#if !defined(AFX_CGWORK0530_H__F47970EB_BCF5_458C_8026_9C041810A134__INCLUDED_)
#define AFX_CGWORK0530_H__F47970EB_BCF5_458C_8026_9C041810A134__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0521App:
// See CGWORK0521.cpp for the implementation of this class
//

class CCGWORK0530App : public CWinApp
{
public:
	CCGWORK0530App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGWORK0521App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCGWORK0521App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGWORK0521_H__F47970EB_BCF5_458C_8026_9C041810A134__INCLUDED_)
