// Window.cpp: implementation of the Window class.
//
//////////////////////////////////////////////////////////////////////
#include "Window.h"
#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include "../Core/Painter.h"
#include "../Core/Point.h"
#include "../Core/Size.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK WndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch (Message)
    {
    case WM_PAINT:
	{
	#if _MSC_VER < 1300
		Window* Win = (Window*)GetWindowLong(hWnd, GWL_USERDATA);
	#else
		Window* Win = (Window*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
	#endif

		if (Win)
			Win->OnPaint();

		return 0;
	}
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hWnd, Message, wParam, lParam);
}

Window::Window()
	: BackgroundColor(255,255,255), bHasBackgroundColor(0)
{
	bHasBackgroundColor = 0;
	//BackgroundColor = Color(255,255,255);
    Title = _T("Application");
	Width = 600;
	Height = 800;
}

Window::~Window()
{
}

bool Window::Create()
{
    WNDCLASS wc;
    ZeroMemory(&wc, sizeof(wc));

    wc.lpszClassName = Title;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpfnWndProc = WndProc;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClass(&wc))
        return false;

    Handle = CreateWindow(
        wc.lpszClassName,
        Title,
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        100, 100, // X Y monitor
        Width, Height, // SIZE
        NULL,
        NULL,
        wc.hInstance,
        NULL
    );

#if _MSC_VER < 1300
    // VC6
    SetWindowLong(Handle, GWL_USERDATA, (LONG)this);
#else
    // VS2022
    SetWindowLongPtr(Handle, GWLP_USERDATA, (LONG_PTR)this);
#endif

    return Handle != NULL;
}

void Window::exec()
{
    ShowWindow(Handle, SW_SHOW);
    UpdateWindow(Handle);
}

void Window::OnPaint()
{
    PAINTSTRUCT PS;
    HDC DC = BeginPaint(Handle, &PS);

	Painter P(DC);

	if(bHasBackgroundColor == 1)
	{
		RECT WinRect;
		GetClientRect(Handle, &WinRect);

		Rect ClientRect((int)WinRect.left, (int)WinRect.top, (int)(WinRect.right - WinRect.left), (int)(WinRect.bottom - WinRect.top));

		P.FillBackground(BackgroundColor, ClientRect);

		OutputDebugString(_T("ALISA SUKA ALISA BLYAD!!!\n"));
	}

	Construct(P);

    EndPaint(Handle, &PS);
}

void Window::Construct(Painter &P)
{
	
}
