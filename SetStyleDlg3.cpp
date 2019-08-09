// SetStyleDlg3.cpp : implementation file
//

#include "stdafx.h"
#include "CGWORK0530.h"
#include "SetStyleDlg3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetStyleDlg3 dialog


CSetStyleDlg3::CSetStyleDlg3(CWnd* pParent /*=NULL*/)
	: CDialog(CSetStyleDlg3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetStyleDlg3)
	m_num1 = 0;
	m_num2 = 0;
	//}}AFX_DATA_INIT
}


void CSetStyleDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetStyleDlg3)
	DDX_Text(pDX, IDC_NUM1, m_num1);
	DDV_MinMaxInt(pDX, m_num1, 1, 20);
	DDX_Text(pDX, IDC_NUM2, m_num2);
	DDV_MinMaxInt(pDX, m_num2, 1, 20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetStyleDlg3, CDialog)
	//{{AFX_MSG_MAP(CSetStyleDlg3)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetStyleDlg3 message handlers
