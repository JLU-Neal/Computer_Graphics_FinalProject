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
	//销毁列表中所有指针所指向的对象
	for (int i=0;i<GetSize();i++)
	{
		delete GetAt(i);
	}
}
