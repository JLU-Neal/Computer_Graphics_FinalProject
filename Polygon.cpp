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
	//设置绘图模式为使用画笔定义的颜色
	pDC->SetROP2(R2_COPYPEN);
	//获得当前线型画笔
	CPen* pen = GetPen();
	//选择画笔，并返回原有画笔
	CPen* oldpen = pDC->SelectObject(pen);
	*/
	//绘制填充多边形
//	pDC->Polygon(checkpoint, pointnumber);
	/*
	//选择回原有画笔
	pDC->SelectObject(oldpen);
	//删除创建的画笔
	pen->DeleteObject();delete pen;
	*/
	if (m_PointsList.GetSize() > 2)
	{

		//使用多边形扫描转换算法填充多边形
		Polygonfill(pDC,&m_PointsList,RGB(0,255,0));
		for (int i=0;i<m_PointsList.GetSize()-1;i++)
		{
			CPoint p1 = (CPoint)m_PointsList.GetAt(i);
			CPoint p2 = (CPoint)m_PointsList.GetAt(i+1);
			//使用Bresenham画线算法绘制每条直线段
		//	DDALine(pDC,p1.x,p1.y,p2.x,p2.y);
		}
		CPoint p1 = (CPoint)m_PointsList.GetAt(0);
		CPoint p2 = (CPoint)m_PointsList.GetAt(
			m_PointsList.GetSize()-1);
		//使用Bresenham画线算法绘制直线段
	//	DDALine(pDC,p1.x,p1.y,p2.x,p2.y);
	}
}

int CPolygon::GetType()
{
	//返回图元类型为填充多边形
	return 5;
}

void CPolygon::SetPolygon(POINT *p, int num)
{
	checkpoint = p;
	pointnumber = num;
}

void CPolygon::SortET(EDGE *pEDGE)
{
	//要排序的边链表中第一个边
	EDGE* p1 = pEDGE;
	//第一个边的下一个边
	EDGE* p2 = NULL;
	while (p1 != NULL)
	{
		p2 = p1->next;//获得下一条边
		while (p2 != NULL)
		{
			//如果前一条边的ymin大于后一条边
			//或者ymin相等时xmin大于后一条边
			if (p1->ymin > p2->ymin || 
				(p1->ymin == p2->ymin && p1->xmin > p2->xmin))
			{
				//交换数据
				int cid;double cdd;
				cid = p1->ymax;p1->ymax = p2->ymax;p2->ymax = cid;
				cid = p1->ymin;p1->ymin = p2->ymin;p2->ymin = cid;
				cdd = p1->xmin;p1->xmin = p2->xmin;p2->xmin = cdd;
				cdd = p1->fm;p1->fm = p2->fm;p2->fm = cdd;
			}
			//下一条边
			p2 = p2->next;
		}
		//下一条边
		p1 = p1->next;
	}
}

EDGE* CPolygon::GetET(CArray<CPoint,CPoint>* points)
{
	EDGE* pHead= NULL;
	EDGE* p = NULL;
	//循环点列表构造最初的边链表
	for (int i=0;i<points->GetSize();i++)
	{
		//获得当前点和下一点，构成一条边
		CPoint point1 = (CPoint)points->GetAt(i);
		CPoint point2;
		//如果当前点已经是最后一个点，则和第一点构成一条边
		if (i == points->GetSize() -1)
			point2 = (CPoint)points->GetAt(0);
		else
			point2 = (CPoint)points->GetAt(i+1);
		//边平行于x轴，舍弃
		if (point1.y == point2.y)
			continue;
		//构造边结构
		EDGE* edge = new EDGE();
		//计算斜率倒数
		edge->fm = (double)(point2.x - point1.x)/(point2.y - point1.y);
		//设置ymin，ymax和xmin
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
		//构造链表
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
	//下面判断局部极大极小并缩短相应的边
	p = pHead;
	EDGE* pNext = NULL;
	while (p!=NULL)
	{
		//如果没有下一个条边，则和第一条边比较
		if (p->next == NULL)
			pNext = pHead;
		else
			pNext = p->next;
		//如果连续的两条边的ymin值和ymax值都不同
		//表示连接两边的节点不为局部极大或极小
		if (p->ymin != pNext->ymin && p->ymax != pNext->ymax)
		{
			//缩短ymax值较大的边
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
	//将边链表排序
	SortET(pHead);
	//返回排序后的链表
	return pHead;
}

void CPolygon::SortAET(EDGE *pEDGE)
{
	//要排序的边链表中第一个边
	EDGE* p1 = pEDGE;
	//第一个边的下一个边
	EDGE* p2 = NULL;
	while (p1 != NULL)
	{
		p2 = p1->next;//获得下一条边
		while (p2 != NULL)
		{
			//如果前一条边的xmin大于后一条边
			if (p1->xmin > p2->xmin)
			{
				//交换数据
				int cid;double cdd;
				cid = p1->ymax;p1->ymax = p2->ymax;p2->ymax = cid;
				cid = p1->ymin;p1->ymin = p2->ymin;p2->ymin = cid;
				cdd = p1->xmin;p1->xmin = p2->xmin;p2->xmin = cdd;
				cdd = p1->fm;p1->fm = p2->fm;p2->fm = cdd;
			}
			//下一条边
			p2 = p2->next;
		}
		//下一条边
		p1 = p1->next;
	}
}

void CPolygon::Polygonfill(CDC *pDC, CArray<CPoint,CPoint>* points, COLORREF color)
{
	//获得ET表
	EDGE* pET = GetET(points);
	//AET表
	EDGE* pAET = NULL;
	//最小y值
	int y = pET->ymin;
	//最大y值
	int ymax = pET->ymax;
	//有需要处理的扫描线
	while (y <= ymax)
	{
		//ET表不为空，并且当前的边的ymin和当前扫描线相等
		while (pET != NULL && pET->ymin == y)
		{
			//将当前边移动到AET表中
			EDGE* p = pET;//获得当前边
			pET = pET->next;//ET指针移动到ET表中的下一条边
			p->next = NULL;//不连接到下一条边，以免重新连会到ET表
			if (pAET == NULL)//当前AET为空，直接加入到AET中
				pAET = p;
			else
			{//当前AET不为空，连接到AET表后
				pAET->next = p;
				//连接当前的边的上一条边为AET表中原有的最后一条边
				p->last = pAET;
				//AET指针移动到表中最后一条边
				pAET = p;
			}
			//根据移动过来的边，修改ymax值
			if (ymax < pAET->ymax)
				ymax = pAET->ymax;
		}
		//找到AET表的第一条边
		while (pAET->last != NULL)
			pAET = pAET->last;
		//排序
		SortAET(pAET);
		EDGE* pFill = pAET;
		//填充AET表中的区间
		//读入图案
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
			//填充当前边和下一条边之间的区间
			for (int i=(int)pFill->xmin;i<=(int)pFill->next->xmin;i++)
				//PatternFill(pDC,i,y,&dl,200,100);
				if(pic[y%16][i%39]==0)
					pDC->SetPixel(i,y,m_FillForeColor/*RGB(0,255,0)*/);
			//AET表中的边应成对出现
			pFill = pFill->next->next;
		}
		//将AET表中ymax为当前扫描线的边清除出表
		pFill = pAET;
		while (pFill != NULL)
		{
			//当前边ymax等于扫描线
			if (pFill->ymax == y)
			{
				//当前边在AET中有上一条边
				if (pFill->last != NULL)
					pFill->last->next = pFill->next;
				//当前边在AET中没有上一条边
				else
					pAET = pFill->next;
				//当前边在AET中有下一条边
				if (pFill->next != NULL)
					pFill->next->last = pFill->last;
				//销毁已经清除出链表的边对象
				EDGE* pdelete = pFill;
				//移动到下一条边
				pFill = pFill->next;
				delete pdelete;
			}
			else
				//移动到下一条边
				pFill = pFill->next;
		}
		//AET表中仍然有边
		if (pAET != NULL)
		{
			//重新计算AET中各边的xmin值
			pFill = pAET;
			while (pFill != NULL)
			{
				pFill->xmin+=pFill->fm;
				pFill = pFill->next;
			}
			//重新排序
			SortAET(pAET);
			//找到AET表中的最后一条边，以便将ET中的边移动过来
			while(pAET->next != NULL)
				pAET = pAET->next;
		}
		//处理下一条扫描线
		y++;
	}
}