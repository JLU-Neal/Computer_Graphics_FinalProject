// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__B86892C9_2794_4CD9_8764_64473B1A8DA0__INCLUDED_)
#define AFX_LINE_H__B86892C9_2794_4CD9_8764_64473B1A8DA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapElement.h"

class CLine : public CMapElement  
{
public:
	CLine();
	virtual ~CLine();
	void draw(CDC* pDC);//����ͼԪ
	int GetType();//����ͼԪ����


};

#endif // !defined(AFX_LINE_H__B86892C9_2794_4CD9_8764_64473B1A8DA0__INCLUDED_)
