#if !defined(AFX_SETSTYLEDLG_H__DB265A61_874C_4189_B92A_0BD6DE791F66__INCLUDED_)
#define AFX_SETSTYLEDLG_H__DB265A61_874C_4189_B92A_0BD6DE791F66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetStyleDlg.h : header file
//
#include "afxtempl.h"
/////////////////////////////////////////////////////////////////////////////
// CSetStyleDlg dialog

class CSetStyleDlg : public CDialog
{
// Construction
public:
	void SetStyle(COLORREF lineColor);
	CSetStyleDlg(CWnd* pParent = NULL);   // standard constructor
	
	COLORREF m_LineColor;//»­ÏßÑÕÉ«
	
// Dialog Data
	//{{AFX_DATA(CSetStyleDlg)
	enum { IDD = IDD_SETSTYLE };
	int		m_rgbr;
	int		m_rgbg;
	int		m_rgbb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetStyleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetStyleDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETSTYLEDLG_H__DB265A61_874C_4189_B92A_0BD6DE791F66__INCLUDED_)
