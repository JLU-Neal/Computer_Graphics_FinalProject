// MapElement.h: interface for the CMapElement class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPELEMENT_H__495A2BD4_E392_40D8_B4FD_027D85F67834__INCLUDED_)
#define AFX_MAPELEMENT_H__495A2BD4_E392_40D8_B4FD_027D85F67834__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "afxtempl.h"
class CMapElement : public CObject  
{
private:
	CPoint m_StartPoint;//图元起始控制点
	CPoint m_EndPoint;//图元终止控制点

public:
	CBrush* GetBrush();
	CPen* GetPen();
	COLORREF m_LineColor;//画线颜色
	int m_FillStyle;//区域填充方式
	COLORREF m_FillForeColor;//区域填充前景色
	COLORREF m_FillBackColor;//区域填充背景色
	
	CMapElement();
	virtual ~CMapElement();//设置图元起始控制点
	void SetStartPoint(CPoint point);
	void SetEndPoint(CPoint point);//设置图元终止控制点
	CPoint GetStartPoint();//获得图元起始控制点
	CPoint GetEndPoint();//获得图元终止控制点
	virtual void draw(CDC* pDC);//绘制图元，由具体的图元子类覆盖实现
	virtual int GetType();//获得图元类型，由具体的图元子类覆盖实现
};

#endif // !defined(AFX_MAPELEMENT_H__495A2BD4_E392_40D8_B4FD_027D85F67834__INCLUDED_)
