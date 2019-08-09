// MapElement.cpp: implementation of the CMapElement class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK0530.h"
#include "MapElement.h"
#include "SetStyleDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMapElement::CMapElement()
{

}

CMapElement::~CMapElement()
{

}

void CMapElement::SetStartPoint(CPoint point)
{
	m_StartPoint = point;
}

void CMapElement::SetEndPoint(CPoint point)
{
	m_EndPoint = point;
}

CPoint CMapElement::GetStartPoint()
{
	return m_StartPoint;
}

CPoint CMapElement::GetEndPoint()
{
	return m_EndPoint;
}

void CMapElement::draw(CDC *pDC)
{

}

int CMapElement::GetType()
{
	return 0;
}

CPen* CMapElement::GetPen()
{
	//构造LOGBRUSH结构
	LOGBRUSH lb;
	lb.lbColor = m_LineColor;
	lb.lbStyle = BS_SOLID;
	//返回构造的画笔指针
	return new CPen(PS_GEOMETRIC,1,&lb,0,NULL);
}

CBrush* CMapElement::GetBrush()
{
	if (m_FillStyle == -1)
		//填充方式值为-1，返回实心画刷指针
		return new CBrush(m_FillForeColor);
	else
		//否则返回阴影线画刷指针
		return new CBrush(m_FillStyle,m_FillForeColor);
}
