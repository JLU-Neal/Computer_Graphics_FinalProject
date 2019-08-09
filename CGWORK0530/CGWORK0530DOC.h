// CGWORK0521Doc.h : interface of the CCGWORK0521Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGWORK0521DOC_H__F26D068F_6339_427F_8367_84A33244F468__INCLUDED_)
#define AFX_CGWORK0521DOC_H__F26D068F_6339_427F_8367_84A33244F468__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MapList.h"

class CCGWORK0521Doc : public CDocument
{
protected: // create from serialization only
	CCGWORK0521Doc();
	DECLARE_DYNCREATE(CCGWORK0521Doc)

// Attributes
public:
	CMapList m_MapList;//当前绘制的图元的列表
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGWORK0521Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCGWORK0521Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCGWORK0521Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGWORK0521DOC_H__F26D068F_6339_427F_8367_84A33244F468__INCLUDED_)
