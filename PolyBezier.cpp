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
	//���û�ͼģʽΪʹ�û��ʶ������ɫ
	pDC->SetROP2(R2_COPYPEN);
	//��õ�ǰ���ͻ���
	CPen* pen = GetPen();
	//ѡ�񻭱ʣ�������ԭ�л���
	CPen* oldpen = pDC->SelectObject(pen);
	*/
	//����Bezier����
	pDC->PolyBezier(checkpoint, pointnumber);
	/*
	//ѡ���ԭ�л���
	pDC->SelectObject(oldpen);
	//ɾ�������Ļ���
	pen->DeleteObject();delete pen;
	*/
}

int CPolyBezier::GetType()
{
	//����ͼԪ����ΪBezier����
	return 4;
}

void CPolyBezier::SetPoly(POINT *p, int num)
{
	checkpoint = p;
	pointnumber = num;
}
