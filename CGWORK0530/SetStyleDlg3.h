#if !defined(AFX_SETSTYLEDLG3_H__1AF434E0_7EAC_4AB1_B6BA_9063FADF904D__INCLUDED_)
#define AFX_SETSTYLEDLG3_H__1AF434E0_7EAC_4AB1_B6BA_9063FADF904D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetStyleDlg3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetStyleDlg3 dialog

class CSetStyleDlg3 : public CDialog
{
// Construction
public:
	CSetStyleDlg3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetStyleDlg3)
	enum { IDD = IDD_SETSTYLE3 };
	int		m_num1;
	int		m_num2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetStyleDlg3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetStyleDlg3)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETSTYLEDLG3_H__1AF434E0_7EAC_4AB1_B6BA_9063FADF904D__INCLUDED_)
