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
	//����LOGBRUSH�ṹ
	LOGBRUSH lb;
	lb.lbColor = m_LineColor;
	lb.lbStyle = BS_SOLID;
	//���ع���Ļ���ָ��
	return new CPen(PS_GEOMETRIC,1,&lb,0,NULL);
}

CBrush* CMapElement::GetBrush()
{
	if (m_FillStyle == -1)
		//��䷽ʽֵΪ-1������ʵ�Ļ�ˢָ��
		return new CBrush(m_FillForeColor);
	else
		//���򷵻���Ӱ�߻�ˢָ��
		return new CBrush(m_FillStyle,m_FillForeColor);
}
