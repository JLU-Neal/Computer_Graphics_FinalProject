#if !defined(AFX_SETSTYLEDLG2_H__652F5FCD_2422_4768_BBB2_1DB8C84BA493__INCLUDED_)
#define AFX_SETSTYLEDLG2_H__652F5FCD_2422_4768_BBB2_1DB8C84BA493__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetStyleDlg2.h : header file
//
#include "afxtempl.h"
/////////////////////////////////////////////////////////////////////////////
// CSetStyleDlg2 dialog

class CSetStyleDlg2 : public CDialog
{
// Construction
public:
	void SetStyle(COLORREF filleColor);
	CSetStyleDlg2(CWnd* pParent = NULL);   // standard constructor
	
	COLORREF m_FillColor;//Ìî³äÑÕÉ«

// Dialog Data
	//{{AFX_DATA(CSetStyleDlg2)
	enum { IDD = IDD_SETSTYLE2 };
	int		m_rgbr;
	int		m_rgbg;
	int		m_rgbb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetStyleDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetStyleDlg2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETSTYLEDLG2_H__652F5FCD_2422_4768_BBB2_1DB8C84BA493__INCLUDED_)
