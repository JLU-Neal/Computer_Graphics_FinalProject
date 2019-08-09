// Polygon.h: interface for the CPolygon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYGON_H__B93913D9_4B3A_49D2_B016_E3D8FAA9DF1F__INCLUDED_)
#define AFX_POLYGON_H__B93913D9_4B3A_49D2_B016_E3D8FAA9DF1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Afxtempl.h"
#include "MapElement.h"

struct EDGE{//边结构，保存边信息同时作为ET表中和AET表中的吊桶
	int ymin;//最小y值，等同于ET表中登记项的y值
	int ymax;//最大y值，吊桶数据
	double xmin;//小y值端点的x值，吊桶数据
	double fm;//斜率倒数，吊桶数据
	EDGE* next;//连接下一个边
	EDGE* last;//连接到上一个边，为了排序时使用
};

class CPolygon : public CMapElement  
{
public:
	void Polygonfill(CDC *pDC, CArray<CPoint,CPoint>* points, COLORREF color);
	void SortAET(EDGE *pEDGE);
	EDGE* GetET(CArray<CPoint,CPoint>* points);
	void SortET(EDGE *pEDGE);
	void SetPolygon(POINT *p, int num);
	
	CArray<CPoint,CPoint> m_PointsList;//用来存储端点，用于保存
	POINT * checkpoint;//多边形端点
	int pointnumber;//端点个数

	int GetType();
	void draw(CDC *pDC);
	CPolygon();
	CPolygon(CArray<class CPoint,class CPoint>*);
	virtual ~CPolygon();

};

#endif // !defined(AFX_POLYGON_H__B93913D9_4B3A_49D2_B016_E3D8FAA9DF1F__INCLUDED_)
