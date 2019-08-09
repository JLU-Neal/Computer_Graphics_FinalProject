// Ellipse.cpp: implementation of the CEllipse class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK0530.h"
#include "Ellipse.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEllipse::CEllipse()
{

}

CEllipse::~CEllipse()
{

}

void CEllipse::draw(CDC *pDC)
{
	//设置绘图模式为使用画笔定义的颜色
	pDC->SetROP2(R2_COPYPEN);
	//获得当前线型画笔
	CPen* pen = GetPen();
	//选择画笔，并返回原有画笔
	CPen* oldpen = pDC->SelectObject(pen);
	//获得椭圆的控制点
	CPoint sp = GetStartPoint();
	CPoint ep = GetEndPoint();
	//绘制椭圆边界线
	CPoint p1;
	CPoint p2;
	p1 = sp;
	p2 = ep;
	int x,y,deltax,deltay,d,R,mid_x,mid_y;
	mid_x=(p1.x+p2.x)/2;
	mid_y=(p1.y+p2.y)/2;
	R=(int)sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2))/2;
	x=0;
	y=R;
	d=1-R;
	deltax=3;
	deltay=2-R-R;
	pDC->SetPixel(mid_x+x,mid_y+y,m_LineColor);
	pDC->SetPixel(mid_x+x,mid_y-y,m_LineColor);
	pDC->SetPixel(mid_x+y,mid_y+x,m_LineColor);
	pDC->SetPixel(mid_x+y,mid_y-x,m_LineColor);	
	while(x<y)
	{
		if(d<0){
			d+=deltax;
			deltax+=2;
			x++;
		}
		else{
			d+=(deltax+deltay);
			deltax+=2;
			deltay+=2;
			x++;
			y--;
		}
	pDC->SetPixel(mid_x+x,mid_y+y,m_LineColor);
	pDC->SetPixel(mid_x-x,mid_y+y,m_LineColor);
	pDC->SetPixel(mid_x-x,mid_y-y,m_LineColor);
	pDC->SetPixel(mid_x+x,mid_y-y,m_LineColor);
	pDC->SetPixel(mid_x+y,mid_y+x,m_LineColor);
	pDC->SetPixel(mid_x-y,mid_y+x,m_LineColor);
	pDC->SetPixel(mid_x-y,mid_y-x,m_LineColor);
	pDC->SetPixel(mid_x+y,mid_y-x,m_LineColor);	
	}
	//选择回原有画笔
	pDC->SelectObject(oldpen);
	//删除创建的画笔
	pen->DeleteObject();delete pen;
}

int CEllipse::GetType()
{
	//返回图元类型为椭圆
	return 2;
}
