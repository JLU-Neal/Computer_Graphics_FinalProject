// SetStyleDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "CGWORK0530.h"
#include "SetStyleDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetStyleDlg2 dialog

CSetStyleDlg2::CSetStyleDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CSetStyleDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetStyleDlg2)
	m_rgbr = 0;
	m_rgbg = 0;
	m_rgbb = 0;
	//}}AFX_DATA_INIT
}


void CSetStyleDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetStyleDlg2)
	DDX_Text(pDX, IDC_RGB1, m_rgbr);
	DDV_MinMaxInt(pDX, m_rgbr, 0, 255);
	DDX_Text(pDX, IDC_RGB2, m_rgbg);
	DDV_MinMaxInt(pDX, m_rgbg, 0, 255);
	DDX_Text(pDX, IDC_RGB3, m_rgbb);
	DDV_MinMaxInt(pDX, m_rgbb, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetStyleDlg2, CDialog)
	//{{AFX_MSG_MAP(CSetStyleDlg2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetStyleDlg2 message handlers

void CSetStyleDlg2::SetStyle(COLORREF fillColor)
{
	m_FillColor = fillColor;//…Ë÷√ª≠œﬂ—’…´
}
