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
	//���û�ͼģʽΪʹ�û��ʶ������ɫ
	pDC->SetROP2(R2_COPYPEN);
	//��õ�ǰ���ͻ���
	CPen* pen = GetPen();
	//ѡ�񻭱ʣ�������ԭ�л���
	CPen* oldpen = pDC->SelectObject(pen);
	//����ֱ�߶�
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
	//ѡ���ԭ�л���
	pDC->SelectObject(oldpen);
	//ɾ�������Ļ���
	pen->DeleteObject();delete pen;
}

int CLine::GetType()
{
	//����ͼԪ����Ϊֱ�߶�
	return 1;
}
