// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK0530.h"
#include "Line.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{

}

CLine::~CLine()
{

}

void CLine::draw(CDC *pDC)
{
	//设置绘图模式为使用画笔定义的颜色
	pDC->SetROP2(R2_COPYPEN);
	//获得当前线型画笔
	CPen* pen = GetPen();
	//选择画笔，并返回原有画笔
	CPen* oldpen = pDC->SelectObject(pen);
	//绘制直线段
	int x1 = GetStartPoint().x;
	int x2 = GetEndPoint().x;
	int y1 = GetStartPoint().y;
	int y2 = GetEndPoint().y;
	double dx,dy,e,x,y;
	dx=x2-x1;  dy=y2-y1;
	e=(fabs(dx)>fabs(dy))? fabs(dx):fabs(dy);
	dx/=e;
	dy/=e;
	x=x1;
	y=y1;
	for(int i=1; i<=e; i++)
	{
		pDC->SetPixel((int)(x+0.5),(int)(y+0.5),m_LineColor);
		x+=dx;
		y+=dy;
	}
	//选择回原有画笔
	pDC->SelectObject(oldpen);
	//删除创建的画笔
	pen->DeleteObject();delete pen;
}

int CLine::GetType()
{
	//返回图元类型为直线段
	return 1;
}
