// PolyBezier.cpp: implementation of the CPolyBezier class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK0530.h"
#include "PolyBezier.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPolyBezier::CPolyBezier()
{

}

CPolyBezier::~CPolyBezier()
{

}

void CPolyBezier::draw(CDC *pDC)
{
	/*
	//设置绘图模式为使用画笔定义的颜色
	pDC->SetROP2(R2_COPYPEN);
	//获得当前线型画笔
	CPen* pen = GetPen();
	//选择画笔，并返回原有画笔
	CPen* oldpen = pDC->SelectObject(pen);
	*/
	//绘制Bezier曲线
	pDC->PolyBezier(checkpoint, pointnumber);
	/*
	//选择回原有画笔
	pDC->SelectObject(oldpen);
	//删除创建的画笔
	pen->DeleteObject();delete pen;
	*/
}

int CPolyBezier::GetType()
{
	//返回图元类型为Bezier曲线
	return 4;
}

void CPolyBezier::SetPoly(POINT *p, int num)
{
	checkpoint = p;
	pointnumber = num;
}
