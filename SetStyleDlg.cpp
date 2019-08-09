// SetStyleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CGWORK0530.h"
#include "SetStyleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetStyleDlg dialog


CSetStyleDlg::CSetStyleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetStyleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetStyleDlg)
	m_rgbr = 0;
	m_rgbg = 0;
	m_rgbb = 0;
	//}}AFX_DATA_INIT
}


void CSetStyleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetStyleDlg)
	DDX_Text(pDX, IDC_RGB1, m_rgbr);
	DDV_MinMaxInt(pDX, m_rgbr, 0, 255);
	DDX_Text(pDX, IDC_RGB2, m_rgbg);
	DDV_MinMaxInt(pDX, m_rgbg, 0, 255);
	DDX_Text(pDX, IDC_RGB3, m_rgbb);
	DDV_MinMaxInt(pDX, m_rgbb, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetStyleDlg, CDialog)
	//{{AFX_MSG_MAP(CSetStyleDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetStyleDlg message handlers

void CSetStyleDlg::SetStyle(COLORREF lineColor)
{
	m_LineColor = lineColor;//…Ë÷√ª≠œﬂ—’…´
}
