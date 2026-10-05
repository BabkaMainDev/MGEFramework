// Application.cpp: implementation of the Application class.
//
//////////////////////////////////////////////////////////////////////

// modified Sep 28,2026 22:19 GMT +3

#include "Application.h"
#include <windows.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Application::Application()
{

}

Application::~Application()
{

}

int Application::Run(int argc, char* argv[])
{
    MSG Message = {0};

    while (GetMessage(&Message, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }

    return (int)Message.wParam;
}
