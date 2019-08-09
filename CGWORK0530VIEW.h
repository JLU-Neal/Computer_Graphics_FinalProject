// CGWORK0521View.h : interface of the CCGWORK0521View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGWORK0530VIEW_H__4BA75F47_B2D5_4EBA_A30C_7EF3AA6E2437__INCLUDED_)
#define AFX_CGWORK0530VIEW_H__4BA75F47_B2D5_4EBA_A30C_7EF3AA6E2437__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "vector"
#include "SetStyleDlg.h"
#include "SetStyleDlg2.h"
#include "SetStyleDlg3.h"
class CCGWORK0530View : public CView
{
protected: // create from serialization only
	CCGWORK0530View();
	DECLARE_DYNCREATE(CCGWORK0530View)

// Attributes
public:
	CCGWORK0530Doc* GetDocument();
	
	int m_DrawType;//��ͼ����
	BOOL m_isDraw;//�Ƿ����ڻ�ͼ
	CPoint m_EndPoint;//����ͼ��ֹ������
	CPoint m_StartPoint;//����ͼ��ʼ������
	BOOL m_LButtonDown;//�������Ƿ���
	HCURSOR m_Cursor;//�����Դ���
	
	COLORREF m_LineColor;//������ɫ
//	COLORREF m_FillColor;//�����ɫ
	int m_FillStyle;//������䷽ʽ
	COLORREF m_FillForeColor;//�������ǰ��ɫ
	COLORREF m_FillBackColor;//������䱳��ɫ
	
	std::vector<POINT> m_vec;//��ʱ�����洢�˵㣬���ڱ���������Ρ�����������ͼԪ
	std::vector<POINT> m_vecpoint;//�����洢���������߶���С����
	CArray<CPoint,CPoint> m_PointsList;//�����洢�˵㣬���ڱ���
	
	int m_CubeMenuState;//�����嵱ǰӦ�����Ķ���
	int RotPace;//��ת�Ƕ�
	int TransPace;//ƽ�ƽǶ�
	int* m_RotMount;
	int* m_TransMount;
	double** m_CubePoint;
	bool m_CubeType;//������ʽ

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGWORK0521View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawPoint(CDC *pDC, CPoint p,int siz);
	void ChangeCubeType();
	void FillFace(CPoint *P, CDC *pDC, COLORREF curFill, int type);
	double** doRotate(double** target);
	double** doTranslate(double** target);
	void DrawCube(CDC *pDC,int type);
	void MidPointCircle(CDC *pDC, CPoint p1, CPoint p2, COLORREF color);
	void DDALine(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF curColor);
	void DrawRButtonDown(UINT nFlags, CPoint point);
	void DrawLButtonUp(UINT nFlags, CPoint point);
	void DrawMouseMove(UINT nFlags, CPoint point);
	void DrawLButtonDown(UINT nFlags, CPoint point);
	virtual ~CCGWORK0530View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCGWORK0521View)
	afx_msg void OnMenuitem11();
	afx_msg void OnMenuitem12();
	afx_msg void OnMenuitem13();
	afx_msg void OnMenuitem21();
	afx_msg void OnMenuitem22();
	afx_msg void OnMenuitem31();
	afx_msg void OnMenuitem32();
	afx_msg void OnMenuitem33();
	afx_msg void OnMenuitem34();
	afx_msg void OnMenuitem35();
	afx_msg void OnMenuitem36();
	afx_msg void OnMenuitem37();
	afx_msg void OnMenuitem38();
	afx_msg void OnMenuitem39();
	afx_msg void OnMenuitem41();
	afx_msg void OnMenuitem51();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CGWORK0521View.cpp
inline CCGWORK0530Doc* CCGWORK0530View::GetDocument()
   { return (CCGWORK0530Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGWORK0521VIEW_H__4BA75F47_B2D5_4EBA_A30C_7EF3AA6E2437__INCLUDED_)
