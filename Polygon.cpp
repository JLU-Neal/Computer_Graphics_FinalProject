// Polygon.cpp: implementation of the CPolygon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK0530.h"
#include "Polygon.h"
#include "math.h"
#include "string"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPolygon::CPolygon()
{

}

CPolygon::CPolygon(CArray<class CPoint,class CPoint> *c)
{
	int size = c->GetSize();
	int i = 0;
	for( i = 0 ; i < size ; ++i )
	{
		m_PointsList.Add(c->GetAt(i));
	}
}

CPolygon::~CPolygon()
{

}

void CPolygon::draw(CDC *pDC)
{
	/*
	//���û�ͼģʽΪʹ�û��ʶ������ɫ
	pDC->SetROP2(R2_COPYPEN);
	//��õ�ǰ���ͻ���
	CPen* pen = GetPen();
	//ѡ�񻭱ʣ�������ԭ�л���
	CPen* oldpen = pDC->SelectObject(pen);
	*/
	//�����������
//	pDC->Polygon(checkpoint, pointnumber);
	/*
	//ѡ���ԭ�л���
	pDC->SelectObject(oldpen);
	//ɾ�������Ļ���
	pen->DeleteObject();delete pen;
	*/
	if (m_PointsList.GetSize() > 2)
	{

		//ʹ�ö����ɨ��ת���㷨�������
		Polygonfill(pDC,&m_PointsList,RGB(0,255,0));
		for (int i=0;i<m_PointsList.GetSize()-1;i++)
		{
			CPoint p1 = (CPoint)m_PointsList.GetAt(i);
			CPoint p2 = (CPoint)m_PointsList.GetAt(i+1);
			//ʹ��Bresenham�����㷨����ÿ��ֱ�߶�
		//	DDALine(pDC,p1.x,p1.y,p2.x,p2.y);
		}
		CPoint p1 = (CPoint)m_PointsList.GetAt(0);
		CPoint p2 = (CPoint)m_PointsList.GetAt(
			m_PointsList.GetSize()-1);
		//ʹ��Bresenham�����㷨����ֱ�߶�
	//	DDALine(pDC,p1.x,p1.y,p2.x,p2.y);
	}
}

int CPolygon::GetType()
{
	//����ͼԪ����Ϊ�������
	return 5;
}

void CPolygon::SetPolygon(POINT *p, int num)
{
	checkpoint = p;
	pointnumber = num;
}

void CPolygon::SortET(EDGE *pEDGE)
{
	//Ҫ����ı������е�һ����
	EDGE* p1 = pEDGE;
	//��һ���ߵ���һ����
	EDGE* p2 = NULL;
	while (p1 != NULL)
	{
		p2 = p1->next;//�����һ����
		while (p2 != NULL)
		{
			//���ǰһ���ߵ�ymin���ں�һ����
			//����ymin���ʱxmin���ں�һ����
			if (p1->ymin > p2->ymin || 
				(p1->ymin == p2->ymin && p1->xmin > p2->xmin))
			{
				//��������
				int cid;double cdd;
				cid = p1->ymax;p1->ymax = p2->ymax;p2->ymax = cid;
				cid = p1->ymin;p1->ymin = p2->ymin;p2->ymin = cid;
				cdd = p1->xmin;p1->xmin = p2->xmin;p2->xmin = cdd;
				cdd = p1->fm;p1->fm = p2->fm;p2->fm = cdd;
			}
			//��һ����
			p2 = p2->next;
		}
		//��һ����
		p1 = p1->next;
	}
}

EDGE* CPolygon::GetET(CArray<CPoint,CPoint>* points)
{
	EDGE* pHead= NULL;
	EDGE* p = NULL;
	//ѭ�����б�������ı�����
	for (int i=0;i<points->GetSize();i++)
	{
		//��õ�ǰ�����һ�㣬����һ����
		CPoint point1 = (CPoint)points->GetAt(i);
		CPoint point2;
		//�����ǰ���Ѿ������һ���㣬��͵�һ�㹹��һ����
		if (i == points->GetSize() -1)
			point2 = (CPoint)points->GetAt(0);
		else
			point2 = (CPoint)points->GetAt(i+1);
		//��ƽ����x�ᣬ����
		if (point1.y == point2.y)
			continue;
		//����߽ṹ
		EDGE* edge = new EDGE();
		//����б�ʵ���
		edge->fm = (double)(point2.x - point1.x)/(point2.y - point1.y);
		//����ymin��ymax��xmin
		if (point1.y > point2.y)
		{
			edge->ymax = point1.y;edge->ymin = point2.y;
			edge->xmin = point2.x;
		}
		else
		{
			edge->ymax = point2.y;edge->ymin = point1.y;
			edge->xmin = point1.x;
		}
		edge->next = NULL;edge->last = NULL;
		//��������
		if (p == NULL)
		{
			pHead = edge;p = edge;
		}
		else
		{
			p->next = edge;
			edge->last = p;
			p = edge;
		}
	}
	//�����жϾֲ�����С��������Ӧ�ı�
	p = pHead;
	EDGE* pNext = NULL;
	while (p!=NULL)
	{
		//���û����һ�����ߣ���͵�һ���߱Ƚ�
		if (p->next == NULL)
			pNext = pHead;
		else
			pNext = p->next;
		//��������������ߵ�yminֵ��ymaxֵ����ͬ
		//��ʾ�������ߵĽڵ㲻Ϊ�ֲ������С
		if (p->ymin != pNext->ymin && p->ymax != pNext->ymax)
		{
			//����ymaxֵ�ϴ�ı�
			if (p->ymax > pNext->ymax)
			{
				p->ymin++;
				p->xmin+=p->fm;
			}
			else
			{
				pNext->ymin++;
				pNext->xmin+=pNext->fm;
			}
		}
		p = p->next;
	}
	//������������
	SortET(pHead);
	//��������������
	return pHead;
}

void CPolygon::SortAET(EDGE *pEDGE)
{
	//Ҫ����ı������е�һ����
	EDGE* p1 = pEDGE;
	//��һ���ߵ���һ����
	EDGE* p2 = NULL;
	while (p1 != NULL)
	{
		p2 = p1->next;//�����һ����
		while (p2 != NULL)
		{
			//���ǰһ���ߵ�xmin���ں�һ����
			if (p1->xmin > p2->xmin)
			{
				//��������
				int cid;double cdd;
				cid = p1->ymax;p1->ymax = p2->ymax;p2->ymax = cid;
				cid = p1->ymin;p1->ymin = p2->ymin;p2->ymin = cid;
				cdd = p1->xmin;p1->xmin = p2->xmin;p2->xmin = cdd;
				cdd = p1->fm;p1->fm = p2->fm;p2->fm = cdd;
			}
			//��һ����
			p2 = p2->next;
		}
		//��һ����
		p1 = p1->next;
	}
}

void CPolygon::Polygonfill(CDC *pDC, CArray<CPoint,CPoint>* points, COLORREF color)
{
	//���ET��
	EDGE* pET = GetET(points);
	//AET��
	EDGE* pAET = NULL;
	//��Сyֵ
	int y = pET->ymin;
	//���yֵ
	int ymax = pET->ymax;
	//����Ҫ�����ɨ����
	while (y <= ymax)
	{
		//ET��Ϊ�գ����ҵ�ǰ�ıߵ�ymin�͵�ǰɨ�������
		while (pET != NULL && pET->ymin == y)
		{
			//����ǰ���ƶ���AET����
			EDGE* p = pET;//��õ�ǰ��
			pET = pET->next;//ETָ���ƶ���ET���е���һ����
			p->next = NULL;//�����ӵ���һ���ߣ������������ᵽET��
			if (pAET == NULL)//��ǰAETΪ�գ�ֱ�Ӽ��뵽AET��
				pAET = p;
			else
			{//��ǰAET��Ϊ�գ����ӵ�AET���
				pAET->next = p;
				//���ӵ�ǰ�ıߵ���һ����ΪAET����ԭ�е����һ����
				p->last = pAET;
				//AETָ���ƶ����������һ����
				pAET = p;
			}
			//�����ƶ������ıߣ��޸�ymaxֵ
			if (ymax < pAET->ymax)
				ymax = pAET->ymax;
		}
		//�ҵ�AET��ĵ�һ����
		while (pAET->last != NULL)
			pAET = pAET->last;
		//����
		SortAET(pAET);
		EDGE* pFill = pAET;
		//���AET���е�����
		//����ͼ��
	int pic[16][39]={
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,
				0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,
				0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,
				0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,
				0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,0,0,0,
				0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,0,0,0,
				0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,
				0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,
				0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,
				0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

		while (pFill != NULL)
		{
			//��䵱ǰ�ߺ���һ����֮�������
			for (int i=(int)pFill->xmin;i<=(int)pFill->next->xmin;i++)
				//PatternFill(pDC,i,y,&dl,200,100);
				if(pic[y%16][i%39]==0)
					pDC->SetPixel(i,y,m_FillForeColor/*RGB(0,255,0)*/);
			//AET���еı�Ӧ�ɶԳ���
			pFill = pFill->next->next;
		}
		//��AET����ymaxΪ��ǰɨ���ߵı��������
		pFill = pAET;
		while (pFill != NULL)
		{
			//��ǰ��ymax����ɨ����
			if (pFill->ymax == y)
			{
				//��ǰ����AET������һ����
				if (pFill->last != NULL)
					pFill->last->next = pFill->next;
				//��ǰ����AET��û����һ����
				else
					pAET = pFill->next;
				//��ǰ����AET������һ����
				if (pFill->next != NULL)
					pFill->next->last = pFill->last;
				//�����Ѿ����������ı߶���
				EDGE* pdelete = pFill;
				//�ƶ�����һ����
				pFill = pFill->next;
				delete pdelete;
			}
			else
				//�ƶ�����һ����
				pFill = pFill->next;
		}
		//AET������Ȼ�б�
		if (pAET != NULL)
		{
			//���¼���AET�и��ߵ�xminֵ
			pFill = pAET;
			while (pFill != NULL)
			{
				pFill->xmin+=pFill->fm;
				pFill = pFill->next;
			}
			//��������
			SortAET(pAET);
			//�ҵ�AET���е����һ���ߣ��Ա㽫ET�еı��ƶ�����
			while(pAET->next != NULL)
				pAET = pAET->next;
		}
		//������һ��ɨ����
		y++;
	}
}