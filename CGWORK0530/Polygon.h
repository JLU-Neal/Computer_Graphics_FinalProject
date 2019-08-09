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

struct EDGE{//�߽ṹ���������Ϣͬʱ��ΪET���к�AET���еĵ�Ͱ
	int ymin;//��Сyֵ����ͬ��ET���еǼ����yֵ
	int ymax;//���yֵ����Ͱ����
	double xmin;//Сyֵ�˵��xֵ����Ͱ����
	double fm;//б�ʵ�������Ͱ����
	EDGE* next;//������һ����
	EDGE* last;//���ӵ���һ���ߣ�Ϊ������ʱʹ��
};

class CPolygon : public CMapElement  
{
public:
	void Polygonfill(CDC *pDC, CArray<CPoint,CPoint>* points, COLORREF color);
	void SortAET(EDGE *pEDGE);
	EDGE* GetET(CArray<CPoint,CPoint>* points);
	void SortET(EDGE *pEDGE);
	void SetPolygon(POINT *p, int num);
	
	CArray<CPoint,CPoint> m_PointsList;//�����洢�˵㣬���ڱ���
	POINT * checkpoint;//����ζ˵�
	int pointnumber;//�˵����

	int GetType();
	void draw(CDC *pDC);
	CPolygon();
	CPolygon(CArray<class CPoint,class CPoint>*);
	virtual ~CPolygon();

};

#endif // !defined(AFX_POLYGON_H__B93913D9_4B3A_49D2_B016_E3D8FAA9DF1F__INCLUDED_)
