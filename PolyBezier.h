// PolyBezier.h: interface for the CPolyBezier class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYBEZIER_H__C440926D_B512_410F_BE93_BED8658BC121__INCLUDED_)
#define AFX_POLYBEZIER_H__C440926D_B512_410F_BE93_BED8658BC121__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapElement.h"

class CPolyBezier : public CMapElement  
{
public:
	void SetPoly(POINT *p, int num);
	POINT * checkpoint;//多边形端点
	int pointnumber;//端点个数
	
	int GetType();
	void draw(CDC *pDC);
	CPolyBezier();
	virtual ~CPolyBezier();

};

#endif // !defined(AFX_POLYBEZIER_H__C440926D_B512_410F_BE93_BED8658BC121__INCLUDED_)
