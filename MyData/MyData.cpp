// MyData.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "MyData.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CMyDataApp

BEGIN_MESSAGE_MAP(CMyDataApp, CWinApp)
END_MESSAGE_MAP()


// CMyDataApp construction

CMyDataApp::CMyDataApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CMyDataApp object

CMyDataApp theApp;


// CMyDataApp initialization

BOOL CMyDataApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}


MY_POINT* MY_DATA::allocTab(MY_POINT* ptab, int n)
{
    try
    {
        if (!ptab)
        {
            ptab = new MY_POINT[n];
            capacity = n;
        }
    }
    catch (std::bad_alloc)
    {
        //CExcept1App* pExp = (CExcept1App*)pExcept;
        //pExcept->PutMessage(1003);
    }

    return ptab;
}

MY_DATA::MY_DATA(int no_it)
{
    //pExcept = GetExceptPtr();
    pTab = NULL;
    Init(no_it);
}

MY_DATA::MY_DATA(const MY_DATA& ob)
{
    capacity = ob.capacity;
    last = ob.last;
    pTab = NULL;
    pTab = allocTab(pTab, capacity);
    if (pTab)
        std::copy(ob.pTab, ob.pTab + last, pTab);
}

void MY_DATA::Init(int no_it)
{
    capacity = no_it;
    last = 0;
    pTab = allocTab(pTab, capacity);
}

void MY_DATA::Push(const MY_POINT& tmp)
{
    if (last >= capacity)
    {
        int delta = last - capacity;
        int new_capacity = (delta > capacity) ? (capacity + delta) : (2 * capacity);
        int old_capacity(capacity);
        MY_POINT* newTab(NULL);
        newTab = allocTab(newTab, new_capacity);
        std::copy(pTab, pTab + old_capacity, newTab);
        delete[] pTab;
        pTab = newTab;
        //capacity = new_capacity;
    }

    pTab[last++] = tmp;
}

void MY_DATA::GetMaxMinCoords(double& max_x, double& min_x, double& max_y, double& min_y)
{
    max_x = min_x = max_y = min_y = 0;
    if (pTab && last)
    {
        max_x = min_x = pTab[0].x;
        max_y = min_y = pTab[0].y;

        for (int i = 1; i < last; ++i)
        {
            if (pTab[i].x > max_x)
                max_x = pTab[i].x;
            if (pTab[i].y > max_y)
                max_y = pTab[i].y;
            if (pTab[i].x < min_x)
                min_x = pTab[i].x;
            if (pTab[i].y < min_y)
                min_y = pTab[i].y;
        }
    }
}


