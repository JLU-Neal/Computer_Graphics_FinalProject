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
	CPoint m_StartPoint;//ͼԪ��ʼ���Ƶ�
	CPoint m_EndPoint;//ͼԪ��ֹ���Ƶ�

public:
	CBrush* GetBrush();
	CPen* GetPen();
	COLORREF m_LineColor;//������ɫ
	int m_FillStyle;//������䷽ʽ
	COLORREF m_FillForeColor;//�������ǰ��ɫ
	COLORREF m_FillBackColor;//������䱳��ɫ
	
	CMapElement();
	virtual ~CMapElement();//����ͼԪ��ʼ���Ƶ�
	void SetStartPoint(CPoint point);
	void SetEndPoint(CPoint point);//����ͼԪ��ֹ���Ƶ�
	CPoint GetStartPoint();//���ͼԪ��ʼ���Ƶ�
	CPoint GetEndPoint();//���ͼԪ��ֹ���Ƶ�
	virtual void draw(CDC* pDC);//����ͼԪ���ɾ����ͼԪ���า��ʵ��
	virtual int GetType();//���ͼԪ���ͣ��ɾ����ͼԪ���า��ʵ��
};

#endif // !defined(AFX_MAPELEMENT_H__495A2BD4_E392_40D8_B4FD_027D85F67834__INCLUDED_)
