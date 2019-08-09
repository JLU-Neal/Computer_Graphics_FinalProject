// CGWORK0530View.cpp : implementation of the CCGWORK0530View class
//

#include "stdafx.h"
#include "CGWORK0530.h"

#include "CGWORK0530Doc.h"
#include "CGWORK0530View.h"
#include "math.h"
#include "Ellipse.h"
#include "Line.h"
#include "Polygon.h"
#include "PolyBezier.h"
#include "MapElement.h"
#include "MapList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CCGWORK0530View

IMPLEMENT_DYNCREATE(CCGWORK0521View, CView);

BEGIN_MESSAGE_MAP(CCGWORK0521View, CView)
	//{{AFX_MSG_MAP(CCGWORK0530View)
	ON_COMMAND(ID_MENUITEM1_1, OnMenuitem11)
	ON_COMMAND(ID_MENUITEM1_2, OnMenuitem12)
	ON_COMMAND(ID_MENUITEM1_3, OnMenuitem13)
	ON_COMMAND(ID_MENUITEM2_1, OnMenuitem21)
	ON_COMMAND(ID_MENUITEM2_2, OnMenuitem22)
	ON_COMMAND(ID_MENUITEM3_1, OnMenuitem31)
	ON_COMMAND(ID_MENUITEM3_2, OnMenuitem32)
	ON_COMMAND(ID_MENUITEM3_3, OnMenuitem33)
	ON_COMMAND(ID_MENUITEM3_4, OnMenuitem34)
	ON_COMMAND(ID_MENUITEM3_5, OnMenuitem35)
	ON_COMMAND(ID_MENUITEM3_6, OnMenuitem36)
	ON_COMMAND(ID_MENUITEM3_7, OnMenuitem37)
	ON_COMMAND(ID_MENUITEM3_8, OnMenuitem38)
	ON_COMMAND(ID_MENUITEM4_1, OnMenuitem41)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_MENUITEM5_1, OnMenuitem51)
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_MENUITEM3_9, OnMenuitem39)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0530View construction/destruction

CCGWORK0521View::CCGWORK0530View()
{
	// TODO: add construction code here
	m_DrawType = 0;//0��ʾ�߶�
	m_isDraw = true;//��ʼ״̬Ϊ��ͼ״̬
	m_LButtonDown = false;
	
	m_LineColor = RGB(0,0,0);
	m_FillStyle = -1;
	m_FillForeColor = RGB(0,255,0);
	m_FillBackColor = RGB(255,255,255);
	
	m_CubeMenuState = 0;
	m_TransMount = new int[3];
	m_RotMount = new int[3];
	RotPace = 10;
	TransPace = 1;
	m_CubePoint = new double*[8];
	int i = 0;
	for(i = 0 ; i < 8 ; i++)
		m_CubePoint[i] = new double[3];
	m_CubeType = true;
}

CCGWORK0521View::~CCGWORK0530View()
{
}

BOOL CCGWORK0521View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0530View drawing

void CCGWORK0521View::OnDraw(CDC* pDC)
{
	CCGWORK0521Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//ѭ��ͼԪ�б�
	int i;
	for (i = 0 ; i < pDoc->m_MapList.GetSize() ; i++)
	{
		//���ͼԪ�б��е�ͼԪ����ָ�벢�������ͳ�ͼԪ����ָ��
		CMapElement* pMap = (CMapElement*)pDoc->m_MapList.GetAt(i);
		//����draw��������ͼԪ
		pMap->draw(pDC);
	}
	for (i = 0 ; i < m_vecpoint.size() ; i++)
	{
		DrawPoint(pDC,m_vecpoint[i],2);
	}
	if(m_DrawType/10==3)
		DrawCube(pDC,m_CubeType);
}

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0530View printing

BOOL CCGWORK0521View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCGWORK0521View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCGWORK0521View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0530View diagnostics

#ifdef _DEBUG
void CCGWORK0521View::AssertValid() const
{
	CView::AssertValid();
}

void CCGWORK0521View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGWORK0521Doc* CCGWORK0530View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGWORK0530Doc)));
	return (CCGWORK0530Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0530View message handlers

void CCGWORK0521View::OnMenuitem11() 
{//ͼ�λ���-���ƾ���
	// TODO: Add your command handler code here
	m_DrawType = 1;//1��ʾ����
	m_isDraw = true;//��ʼ״̬Ϊ��ͼ״̬
}

void CCGWORK0521View::OnMenuitem12() 
{//ͼ�λ���-����Բ��
	// TODO: Add your command handler code here
	m_DrawType = 2;//2��ʾԲ��
	m_isDraw = true;//��ʼ״̬Ϊ��ͼ״̬
}

void CCGWORK0521View::OnMenuitem13() 
{//ͼ�λ���-������ɫ
	// TODO: Add your command handler code here
	CSetStyleDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		//���Ի���"ȷ��"��ť�ر�ʱ�������û�ѡ������͵�����ֵ
		m_LineColor = RGB(dlg.m_rgbr,dlg.m_rgbg,dlg.m_rgbb);
	}
}

void CCGWORK0521View::OnMenuitem21() 
{//�������-���ƶ����
	// TODO: Add your command handler code here
	m_DrawType = 5;//5��ʾ�������
	//�����5�ĳ�3���ͱ����polygon�����������
	m_isDraw = true;//��ʼ״̬Ϊ��ͼ״̬
}

void CCGWORK0521View::OnMenuitem22() 
{//�������-������ɫ
	// TODO: Add your command handler code here
	CSetStyleDlg2 dlg;
	if (dlg.DoModal() == IDOK)
	{
		//���Ի���"ȷ��"��ť�ر�ʱ�������û�ѡ������͵�����ֵ
		m_FillForeColor = RGB(dlg.m_rgbr,dlg.m_rgbg,dlg.m_rgbb);
	}
}

void CCGWORK0521View::OnMenuitem31() 
{//��ά�任-����������
	// TODO: Add your command handler code here
	Invalidate();
	// TODO: Add your command handler code here
	m_DrawType=31;
	int d,x0,y0;
	CRect Rect;
	GetClientRect(&Rect);
	x0=(Rect.left+Rect.right)/2;
	y0=(Rect.top+Rect.bottom)/2;
	d=min(x0,y0)/2;
	for(int i=0;i<3;i++){
		m_TransMount[i]=0;
		m_RotMount[i]=0;
	}
	m_CubeType=true;
	m_CubePoint[0][0]=-d;
	m_CubePoint[0][1]=d;
	m_CubePoint[0][2]=d;

	m_CubePoint[1][0]=d;
	m_CubePoint[1][1]=d;
	m_CubePoint[1][2]=d;

	m_CubePoint[2][0]=d;
	m_CubePoint[2][1]=-d;
	m_CubePoint[2][2]=d;

	m_CubePoint[3][0]=-d;
	m_CubePoint[3][1]=-d;
	m_CubePoint[3][2]=d;

	m_CubePoint[4][0]=-d;
	m_CubePoint[4][1]=d;
	m_CubePoint[4][2]=-d;

	m_CubePoint[5][0]=d;
	m_CubePoint[5][1]=d;
	m_CubePoint[5][2]=-d;

	m_CubePoint[6][0]=d;
	m_CubePoint[6][1]=-d;
	m_CubePoint[6][2]=-d;

	m_CubePoint[7][0]=-d;
	m_CubePoint[7][1]=-d;
	m_CubePoint[7][2]=-d;
	CDC* pDC=this->GetDC();//�����豸��������
	DrawCube(pDC,m_CubeType);
	this->ReleaseDC(pDC);
}

void CCGWORK0521View::OnMenuitem32() 
{//��ά�任-��x�᷽��ƽ��
	// TODO: Add your command handler code here
	m_CubeMenuState=1;
}

void CCGWORK0521View::OnMenuitem33() 
{//��ά�任-��y�᷽��ƽ��
	// TODO: Add your command handler code here
	m_CubeMenuState=2;
}

void CCGWORK0521View::OnMenuitem34() 
{//��ά�任-��z�᷽��ƽ��
	// TODO: Add your command handler code here
	m_CubeMenuState=3;
}

void CCGWORK0521View::OnMenuitem35() 
{//��ά�任-��x����ת
	// TODO: Add your command handler code here
	m_CubeMenuState=4;
}

void CCGWORK0521View::OnMenuitem36() 
{//��ά�任-��y����ת
	// TODO: Add your command handler code here
	m_CubeMenuState=5;
}

void CCGWORK0521View::OnMenuitem37() 
{//��ά�任-��z����ת
	// TODO: Add your command handler code here
	m_CubeMenuState=6;
}

void CCGWORK0521View::OnMenuitem38() 
{//��ά�任-��������
	// TODO: Add your command handler code here
	CSetStyleDlg3 dlg;
	if (dlg.DoModal() == IDOK)
	{
		//���Ի���"ȷ��"��ť�ر�ʱ�������û�ѡ������͵�����ֵ
		RotPace = dlg.m_num2;
		TransPace = dlg.m_num1;
	}
}

void CCGWORK0521View::OnMenuitem39() 
{//��ά�任-���ı�����ʽ
	// TODO: Add your command handler code here
	m_CubeType=!m_CubeType;
	Invalidate();
}

void CCGWORK0521View::OnMenuitem41() 
{//��������-����Bezier����
	// TODO: Add your command handler code here
	m_DrawType = 4;//4��ʾBezier����
	m_isDraw = true;//��ʼ״̬Ϊ��ͼ״̬
}

void CCGWORK0521View::OnMenuitem51() 
{//����
	// TODO: Add your command handler code here
	CCGWORK0521Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int i = 0;
	for( i = 0 ; i < pDoc->m_MapList.GetSize() ; ++i )
		delete pDoc->m_MapList[i];
	pDoc->m_MapList.RemoveAll();
	m_vecpoint.clear();
	OnPaint();
	Invalidate(true);
}

void CCGWORK0521View::OnLButtonDown(UINT nFlags, CPoint point) 
{//����������
	// TODO: Add your message handler code here and/or call default
	//���ڻ�ͼ״̬ʱ��������ͼʱ���������´�����
	if (m_isDraw)
		this->DrawLButtonDown(nFlags,point);
	CView::OnLButtonDown(nFlags, point);
}

void CCGWORK0521View::OnMouseMove(UINT nFlags, CPoint point) 
{//����ƶ�
	// TODO: Add your message handler code here and/or call default
	//���ڻ�ͼ״̬ʱ��������ͼʱ����ƶ�������
	if (m_isDraw)
		this->DrawMouseMove(nFlags,point);
	CView::OnMouseMove(nFlags, point);
}

void CCGWORK0521View::OnLButtonUp(UINT nFlags, CPoint point) 
{//������̧��
	// TODO: Add your message handler code here and/or call default
	//���ڻ�ͼ״̬ʱ��������ͼʱ������̧������
	if (m_isDraw)
		this->DrawLButtonUp(nFlags,point);
	CView::OnLButtonUp(nFlags, point);
}

void CCGWORK0521View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//���ڻ�ͼ״̬ʱ��������ͼʱ����Ҽ����´�����
	if (m_isDraw)
		this->DrawRButtonDown(nFlags,point);
	CView::OnRButtonDown(nFlags, point);
}

void CCGWORK0521View::DrawLButtonDown(UINT nFlags, CPoint point)
{//����ͼʱ���������´�����
	SetCursor(m_Cursor);//����ʹ�ù����Դ
	this->SetCapture();//��׽���
	//���ÿ�ʼ�����ֹ�㣬��ʱΪͬһ��
	m_StartPoint = point;
	m_EndPoint = point;
	m_LButtonDown = true;//��������������
}

void CCGWORK0521View::DrawMouseMove(UINT nFlags, CPoint point)
{//����ͼʱ����ƶ�������
	SetCursor(m_Cursor);//����ʹ�ù����Դ
	CClientDC dc(this);//�����豸��������
	CDC* pDC = this->GetDC();//����豸��������
	if (m_LButtonDown && m_DrawType == 0)
	{
		dc.SetROP2(R2_NOTXORPEN);//���û�ͼģʽΪR2_NOTXORPEN
		//���»���ǰһ������ƶ���Ϣ���������Ƶ�ֱ�߶�
		//��Ϊ��ͼģʽ��ԭ�򣬽���ǲ����˸��߶�
		DDALine(&dc,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y,m_LineColor);
		//�����µ�ֱ�߶�
		DDALine(&dc,m_StartPoint.x,m_StartPoint.y,point.x,point.y,m_LineColor);
		//�����µ�ֱ�߶��յ�
		m_EndPoint = point;		
	}
	if (m_LButtonDown && m_DrawType == 1)
	{
		dc.SetROP2(R2_NOTXORPEN);//���û�ͼģʽΪR2_NOTXORPEN
		//����ǰһ�κ�������ʱ���Ƶľ��α߽���
		DDALine(&dc,m_StartPoint.x,m_StartPoint.y,m_StartPoint.x,m_EndPoint.y,m_LineColor);
		DDALine(&dc,m_StartPoint.x,m_EndPoint.y,m_EndPoint.x,m_EndPoint.y,m_LineColor);
		DDALine(&dc,m_EndPoint.x,m_EndPoint.y,m_EndPoint.x,m_StartPoint.y,m_LineColor);
		DDALine(&dc,m_EndPoint.x,m_StartPoint.y,m_StartPoint.x,m_StartPoint.y,m_LineColor);
		//�����µľ��α߽���
		DDALine(&dc,m_StartPoint.x,m_StartPoint.y,m_StartPoint.x,point.y,m_LineColor);
		DDALine(&dc,m_StartPoint.x,point.y,point.x,point.y,m_LineColor);
		DDALine(&dc,point.x,point.y,point.x,m_StartPoint.y,m_LineColor);
		DDALine(&dc,point.x,m_StartPoint.y,m_StartPoint.x,m_StartPoint.y,m_LineColor);
		//�����µ���ֹ��
		m_EndPoint = point;
	}
	if (m_LButtonDown && m_DrawType == 2)
	{
		dc.SetROP2(R2_NOTXORPEN);//���û�ͼģʽΪR2_NOTXORPEN
		//����ǰһ�κ�������ʱ���Ƶ���Բ�߽���
		MidPointCircle(&dc,m_StartPoint,m_EndPoint,m_LineColor);
		//�����µ���Բ�߽���
		MidPointCircle(&dc,m_StartPoint,point,m_LineColor);
		//�����µ���ֹ��
		m_EndPoint = point;
	}
	if (m_LButtonDown && m_DrawType == 3)
	{
		dc.SetROP2(R2_NOT);//���û�ͼģʽΪR2_NOT
		//���»���ǰһ������ƶ���Ϣ���������Ƶ�ֱ�߶�
		//��Ϊ��ͼģʽ��ԭ�򣬽���ǲ����˸��߶�
		dc.MoveTo(m_StartPoint);
		dc.LineTo(m_EndPoint);
		//�����µ�ֱ�߶�
		dc.MoveTo(m_StartPoint);
		dc.LineTo(point);
		//�����µ�ֱ�߶��յ�
		m_EndPoint = point;
	}
	if (m_LButtonDown && m_DrawType == 4)
	{
		dc.SetROP2(R2_NOTXORPEN);//���û�ͼģʽΪR2_NOTXORPEN
		//���»���ǰһ������ƶ���Ϣ���������Ƶ�ֱ�߶�
		DDALine(&dc,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y,m_LineColor);
		//�����µ�ֱ�߶�
		DDALine(&dc,m_StartPoint.x,m_StartPoint.y,point.x,point.y,m_LineColor);
		//�����µ�ֱ�߶��յ�
		m_EndPoint = point;
	}
	if (m_LButtonDown && m_DrawType == 5)
	{
		dc.SetROP2(R2_NOTXORPEN);//���û�ͼģʽΪR2_NOTXORPEN
		//���»���ǰһ������ƶ���Ϣ���������Ƶ�ֱ�߶�
		//��Ϊ��ͼģʽ��ԭ�򣬽���ǲ����˸��߶�
		DDALine(&dc,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y,m_LineColor);
		//�����µ�ֱ�߶�
		DDALine(&dc,m_StartPoint.x,m_StartPoint.y,point.x,point.y,m_LineColor);
		//�����µ�ֱ�߶��յ�
		m_EndPoint = point;
	}
}

void CCGWORK0521View::DrawLButtonUp(UINT nFlags, CPoint point)
{//����ͼʱ������̧������
	SetCursor(m_Cursor);//����ʹ�ù����Դ
	ReleaseCapture();//�ͷ����
	CDC* pDC = this->GetDC();//����豸��������
	//����ĵ�ָ��
	CCGWORK0530Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//���Ƶ���ֱ�߶�
	if (m_DrawType == 0)
	{
		//����ֱ�߶�ͼԪ����ָ��
		CLine* line = new CLine();
		//���ÿ��Ƶ�
		line->SetStartPoint(m_StartPoint);
		line->SetEndPoint(m_EndPoint);
		line->m_LineColor = m_LineColor;
		//����ֱ�߶�ͼԪ
		line->draw(pDC);
		//���ֱ�߶�ͼԪ����ָ�뵽ͼԪ�б���
		pDoc->m_MapList.Add(line);
	}
	//���Ƶ��Ǿ���
	if (m_DrawType == 1)
	{
		//����ֱ�߶�ͼԪ����ָ��
		CLine* line1 = new CLine();
		CLine* line2 = new CLine();
		CLine* line3 = new CLine();
		CLine* line4 = new CLine();
		//���ÿ��Ƶ�
		CPoint cp[4];
		cp[0].x = m_StartPoint.x;cp[0].y = m_StartPoint.y;
		cp[1].x = m_StartPoint.x;cp[1].y = m_EndPoint.y;
		cp[2].x = m_EndPoint.x;cp[2].y = m_EndPoint.y;
		cp[3].x = m_EndPoint.x;cp[3].y = m_StartPoint.y;
		int i = 0;
		line1->SetStartPoint(cp[0]);
		line1->SetEndPoint(cp[1]);
		line1->m_LineColor = m_LineColor;
		line2->SetStartPoint(cp[1]);
		line2->SetEndPoint(cp[2]);
		line2->m_LineColor = m_LineColor;
		line3->SetStartPoint(cp[2]);
		line3->SetEndPoint(cp[3]);
		line3->m_LineColor = m_LineColor;
		line4->SetStartPoint(cp[3]);
		line4->SetEndPoint(cp[0]);
		line4->m_LineColor = m_LineColor;
		//���ƾ���ͼԪ
		line1->draw(pDC);
		line2->draw(pDC);
		line3->draw(pDC);
		line4->draw(pDC);
		//��Ӿ���ͼԪ����ָ�뵽ͼԪ�б���
		pDoc->m_MapList.Add(line1);
		pDoc->m_MapList.Add(line2);
		pDoc->m_MapList.Add(line3);
		pDoc->m_MapList.Add(line4);
	}
	//���Ƶ�����Բ
	if (m_DrawType == 2)
	{
		//������ԲͼԪ����ָ��
		CEllipse* ellipse = new CEllipse();
		//���ÿ��Ƶ�
		ellipse->SetStartPoint(m_StartPoint);
		ellipse->SetEndPoint(m_EndPoint);
		ellipse->m_LineColor = m_LineColor;
		//������ԲͼԪ
		ellipse->draw(pDC);
		//�����ԲͼԪ����ָ�뵽ͼԪ�б���
		pDoc->m_MapList.Add(ellipse);
	}
	//���Ƶ��Ƕ���λ���Beaizer����
	if (m_DrawType == 3 || m_DrawType == 4)
	{
		POINT cp;
		cp.x = m_StartPoint.x;
		cp.y = m_StartPoint.y;
		m_vec.push_back(cp);
	}
	//���Ƶ����������
	if(m_DrawType == 5)
	{
		m_PointsList.Add(m_StartPoint);
		POINT cp;
		cp.x = m_StartPoint.x;
		cp.y = m_StartPoint.y;
		m_vec.push_back(cp);
	}
	//�ͷ��豸��������
	this->ReleaseDC(pDC);
	m_LButtonDown = false;//����������̧��
	if (m_DrawType == 3 || m_DrawType == 4)
	{
		m_LButtonDown = true;
	}
	if (m_DrawType == 5)
	{
		m_LButtonDown = true;
	}
}

void CCGWORK0521View::DrawRButtonDown(UINT nFlags, CPoint point)
{
	if (m_DrawType == 3)
	{
		CDC* pDC = this->GetDC();//����豸��������
		//����ĵ�ָ��
		CCGWORK0530Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		POINT *cp = new POINT[m_vec.size()];
		int i = 0;
		for( i = 0 ; i < m_vec.size() ; ++i )
		{
			cp[i].x = m_vec[i].x;
			cp[i].y = m_vec[i].y;
		}
		//�����������ͼԪ����ָ��
		CPolygon* poly = new CPolygon();
		//���ÿ��Ƶ�
		poly->SetPolygon(cp, m_vec.size());
		poly->m_LineColor = m_LineColor;
		//�����������ͼԪ
		poly->draw(pDC);
		//����������ͼԪ����ָ�뵽ͼԪ�б���
	 	pDoc->m_MapList.Add(poly);
		//��ջ�����
		m_vec.clear();
		this->ReleaseDC(pDC);
		m_LButtonDown = false;//����������̧��
		OnPaint();
		Invalidate(true);
	}
	if (m_DrawType == 4)
	{
		CDC* pDC = this->GetDC();//����豸��������
		//����ĵ�ָ��
		CCGWORK0530Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		POINT *cp = new POINT[m_vec.size()];
		int i = 0;
		for( i = 0 ; i < m_vec.size() ; ++i )
		{
			cp[i].x = m_vec[i].x;
			cp[i].y = m_vec[i].y;
			if(m_vec.size() % 3 == 1)//����������������Ƿ������ƶ����
			{
				int i = 0;
				for( i = 0 ; i < m_vec.size() ; ++i )
				{
					//����ֱ�߶�ͼԪ����ָ��
					CLine* line = new CLine();
					//���ÿ��Ƶ�
					line->SetStartPoint(m_vec[i]);
					line->SetEndPoint(m_vec[(i+1)%(m_vec.size())]);
					line->m_LineColor = m_LineColor;
					//����ֱ�߶�ͼԪ
					line->draw(pDC);
					//���ֱ�߶�ͼԪ����ָ�뵽ͼԪ�б���
					pDoc->m_MapList.Add(line);
					m_vecpoint.push_back(m_vec[i]);
				}
			}
		}
		//�����������ͼԪ����ָ��
		CPolyBezier* poly = new CPolyBezier();
		//���ÿ��Ƶ�
		poly->SetPoly(cp, m_vec.size());
		poly->m_LineColor = m_LineColor;
		//�����������ͼԪ
		poly->draw(pDC);
		//����������ͼԪ����ָ�뵽ͼԪ�б���
	 	pDoc->m_MapList.Add(poly);
		//��ջ�����
		m_vec.clear();
		this->ReleaseDC(pDC);
		m_LButtonDown = false;//����������̧��
		OnPaint();
		Invalidate(true);
	}
	if (m_DrawType == 5)
	{
		CDC* pDC = this->GetDC();//����豸��������
		//����ĵ�ָ��
		CCGWORK0530Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		//�����������ͼԪ����ָ��
		CPolygon* poly = new CPolygon(&m_PointsList);
		poly->m_FillForeColor = m_FillForeColor;
		//�����������ͼԪ
		poly->draw(pDC);
		//����������ͼԪ����ָ�뵽ͼԪ�б���
		pDoc->m_MapList.Add(poly);
		//���������α�ͼԪ����ָ�뵽ͼԪ�б���
		//������εı�����CLineֱ�߶�ͼԪ������
		//��ô���Ļ����൱�ڰѳ��������е�ֱ�߶ζ���CLine
		//������Ӧ���������
		int i = 0;
		for( i = 0 ; i < m_vec.size() ; ++i )
		{
			//����ֱ�߶�ͼԪ����ָ��
			CLine* line = new CLine();
			//���ÿ��Ƶ�
			line->SetStartPoint(m_vec[i]);
			line->SetEndPoint(m_vec[(i+1)%(m_vec.size())]);
			line->m_LineColor = m_LineColor;
			//����ֱ�߶�ͼԪ
			line->draw(pDC);
			//���ֱ�߶�ͼԪ����ָ�뵽ͼԪ�б���
			pDoc->m_MapList.Add(line);
		}
		//��ջ�����
		m_vec.clear();
		m_PointsList.RemoveAll();
		this->ReleaseDC(pDC);
		m_LButtonDown = false;//����������̧��
		OnPaint();
		Invalidate(true);
	}
}

void CCGWORK0521View::DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF curColor)
{
	double dx,dy,e,x,y;
	dx=x2-x1;  dy=y2-y1;
	e=(fabs(dx)>fabs(dy))? fabs(dx):fabs(dy);
	dx/=e;
	dy/=e;
	x=x1;
	y=y1;
	for(int i=1; i<=e; i++)
	{
		pDC->SetPixel((int)(x+0.5),(int)(y+0.5),curColor);
		x+=dx;
		y+=dy;
	}
}

void CCGWORK0521View::MidPointCircle(CDC *pDC, CPoint p1, CPoint p2, COLORREF color)
{
	int x,y,deltax,deltay,d,R,mid_x,mid_y;
	mid_x=(p1.x+p2.x)/2;
	mid_y=(p1.y+p2.y)/2;
	R=(int)sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2))/2;
	x=0;
	y=R;
	d=1-R;
	deltax=3;
	deltay=2-R-R;
	pDC->SetPixel(mid_x+x,mid_y+y,color);
	pDC->SetPixel(mid_x+x,mid_y-y,color);
	pDC->SetPixel(mid_x+y,mid_y+x,color);
	pDC->SetPixel(mid_x+y,mid_y-x,color);	
	while(x<y)
	{
		if(d<0){
			d+=deltax;
			deltax+=2;
			x++;
		}
		else{
			d+=(deltax+deltay);
			deltax+=2;
			deltay+=2;
			x++;
			y--;
		}
	pDC->SetPixel(mid_x+x,mid_y+y,color);
	pDC->SetPixel(mid_x-x,mid_y+y,color);
	pDC->SetPixel(mid_x-x,mid_y-y,color);
	pDC->SetPixel(mid_x+x,mid_y-y,color);
	pDC->SetPixel(mid_x+y,mid_y+x,color);
	pDC->SetPixel(mid_x-y,mid_y+x,color);
	pDC->SetPixel(mid_x-y,mid_y-x,color);
	pDC->SetPixel(mid_x+y,mid_y-x,color);	
	}
}

void CCGWORK0521View::DrawCube(CDC *pDC, int type)
{
	COLORREF m_CubeColors[6]={RGB(20,20,20),RGB(40,40,40),
		RGB(60,60,60),RGB(80,80,80),
		RGB(100,100,100),RGB(120,120,120)};
	int m_CubeFaces[6][4]={
		{0,1,2,3},
		{7,6,5,4},
		{1,5,6,2},
		{0,3,7,4},
		{0,4,5,1},
		{3,2,6,7},
	};
	CPoint projPoints[8];
	int isVisible[6]={1,1,1,1,1,1};
	CPoint* P=new CPoint[5];
/////////////////////////////////////
	int i,j,D,x0,y0,x1,x2,y1,y2;
		CRect Rect;
	GetClientRect(&Rect);
	x0=(Rect.left+Rect.right)/2;
	y0=(Rect.top+Rect.bottom)/2;
	D=min(x0,y0)/2;
///////////////////////////////////
	double** target=new double*[8];
	for(i=0;i<8;i++)
		target[i]=new double[3];
	for(i=0;i<8;i++)
		for(j=0;j<3;j++)
			target[i][j]=m_CubePoint[i][j];
	target=doRotate(target);
	target=doTranslate(target);
	for(i=0;i<8;i++)
		target[i][2]=target[i][2]+2*D;
///////////////////////////////////
	for(i=0;i<8;i++){
		projPoints[i].x=2*D*(target[i][0])/(target[i][2]+D)+x0;
		projPoints[i].y=2*D*(target[i][1])/(target[i][2]+D)+y0;
	}
///////////////////////////////////
	for(i=0;i<6;i++){
		x1=projPoints[m_CubeFaces[i][0]].x-projPoints[m_CubeFaces[i][1]].x;
		y1=projPoints[m_CubeFaces[i][0]].y-projPoints[m_CubeFaces[i][1]].y;
		x2=projPoints[m_CubeFaces[i][2]].x-projPoints[m_CubeFaces[i][1]].x;
		y2=projPoints[m_CubeFaces[i][2]].y-projPoints[m_CubeFaces[i][1]].y;	
		if(x1*y2-x2*y1>=0&&type)
			isVisible[i]=0;
	}	
///////////////////////////////////
	for(i=0;i<6;i++){
		if(isVisible[i]){
			for(j=0;j<4;j++)
				P[j]=projPoints[m_CubeFaces[i][j]];
			P[4]=P[0];
				FillFace(P,pDC,m_CubeColors[i],type);
		}
	}
}

double** CCGWORK0521View::doTranslate(double **target)
{
	for(int i=0;i<8;i++){
		for(int j=0;j<3;j++)
			target[i][j]+=m_TransMount[j];
	}
	return target;
}

double** CCGWORK0521View::doRotate(double **target)
{
	double Trigono[3][2];
	double tmp[3];
	double arc;
	int i,j;
	for(i=0;i<3;i++){
		arc=(m_RotMount[i]*3.1415926)/180;
		Trigono[i][0]=sin(arc);
		Trigono[i][1]=cos(arc);
	}
	for(i=0;i<8;i++){
		for(j=0;j<3;j++)//X��
			tmp[j]=target[i][j];
		target[i][1]=tmp[1]*Trigono[0][1]-tmp[2]*Trigono[0][0];
		target[i][2]=tmp[1]*Trigono[0][0]+tmp[2]*Trigono[0][1];

		for(j=0;j<3;j++)//Y��
			tmp[j]=target[i][j];
		target[i][2]=tmp[2]*Trigono[1][1]-tmp[0]*Trigono[1][0];
		target[i][0]=tmp[0]*Trigono[1][1]+tmp[2]*Trigono[1][0];

		for(j=0;j<3;j++)//Z��
			tmp[j]=target[i][j];
		target[i][0]=tmp[0]*Trigono[2][1]-tmp[1]*Trigono[2][0];
		target[i][1]=tmp[0]*Trigono[2][0]+tmp[1]*Trigono[2][1];
	}
	return target;
}

void CCGWORK0521View::FillFace(CPoint *P, CDC *pDC, COLORREF curFill, int type)
{
	int xl,xr,yt,yd;
	bool flag;
	int i,j,k;
	///*
	for(i=0;i<4;i++){
		DDALine(pDC,P[i].x,P[i].y,
		P[i+1].x,P[i+1].y,0);		
	}
	//*/
	if(!type)
		return;
	xl=P[0].x;
	xr=P[0].x;
	yt=P[0].y;
	yd=P[0].y;
	
	for(i=0;i<4;i++){
		if(P[i].x<xl)
			xl=P[i].x;
		if(P[i].x>xr)
			xr=P[i].x;
		if(P[i].y<yt)
			yt=P[i].y;
		if(P[i].y>yd)
			yd=P[i].y;			
	}
	CPoint Vect[4];
	int Consts[4];
	for(i=0;i<4;i++){
		Vect[i].x=P[i+1].x-P[i].x;
		Vect[i].y=P[i+1].y-P[i].y;
		Consts[i]=P[i].y*Vect[i].x-P[i].x*Vect[i].y;
	}
	for(i=yt;i<=yd;i++)
		for(j=xl;j<=xr;j++){
			flag=true;
			for(k=0;k<4;k++)
				if(Vect[k].y*j-Vect[k].x*i+Consts[k]>0){
					flag=false;
					break;
				}
			if(flag)
				pDC->SetPixel(j,i,curFill);
		}
}

void CCGWORK0521View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_DrawType==31){
		if(!m_CubeMenuState){
			CView::OnKeyDown(nChar, nRepCnt, nFlags);
			return;
		}
		switch(nChar){
		case 'A'://VK_A:
			if(m_CubeMenuState>3)
				m_RotMount[m_CubeMenuState-4]+=RotPace;
			else
				m_TransMount[m_CubeMenuState-1]+=TransPace;
			break;
		case 'L'://VK_L:
			if(m_CubeMenuState>3)
				m_RotMount[m_CubeMenuState-4]-=RotPace;
			else
				m_TransMount[m_CubeMenuState-1]-=TransPace;
			break;
		}
		Invalidate();
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CCGWORK0521View::ChangeCubeType()
{
	m_CubeType=!m_CubeType;
	Invalidate();
}



void CCGWORK0521View::DrawPoint(CDC *pDC, CPoint p, int siz)
{
	int x=p.x-siz;
	int y=p.y-siz;
	int i,j;
	for(i=x;i<x+2*siz;i++)
		for(j=y;j<y+2*siz;j++)
			pDC->SetPixel(i,j,0);
}
