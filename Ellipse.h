// Ellipse.h: interface for the CEllipse class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELLIPSE_H__6008D4A7_C748_470F_B061_E02CA05D42FD__INCLUDED_)
#define AFX_ELLIPSE_H__6008D4A7_C748_470F_B061_E02CA05D42FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapElement.h"

class CEllipse : public CMapElement  
{
public:
	CEllipse();
	virtual ~CEllipse();
	void draw(CDC* pDC);//绘制图元
	int GetType();//返回图元类型


};

#endif // !defined(AFX_ELLIPSE_H__6008D4A7_C748_470F_B061_E02CA05D42FD__INCLUDED_)
