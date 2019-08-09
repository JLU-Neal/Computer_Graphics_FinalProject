// CGWORK0530Doc.cpp : implementation of the CCGWORK0530Doc class
//

#include "stdafx.h"
#include "CGWORK0530.h"

#include "CGWORK0530Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0530Doc

IMPLEMENT_DYNCREATE(CCGWORK0530Doc, CDocument)

BEGIN_MESSAGE_MAP(CCGWORK0530Doc, CDocument)
	//{{AFX_MSG_MAP(CCGWORK0530Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0530Doc construction/destruction

CCGWORK0530Doc::CCGWORK0530Doc()
{
	// TODO: add one-time construction code here

}

CCGWORK0530Doc::~CCGWORK0530Doc()
{
}

BOOL CCGWORK0530Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCGWORK0530Doc serialization

void CCGWORK0530Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0530Doc diagnostics

#ifdef _DEBUG
void CCGWORK0530Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCGWORK0530Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0530Doc commands
