// MapList.cpp: implementation of the CMapList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK0530.h"
#include "MapList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMapList::CMapList()
{

}

CMapList::~CMapList()
{
	//�����б�������ָ����ָ��Ķ���
	for (int i=0;i<GetSize();i++)
	{
		delete GetAt(i);
	}
}
