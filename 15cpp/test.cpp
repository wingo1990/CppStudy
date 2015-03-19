#include <windows.h>
#include <stdio.h>
#include <atlstr.h>
#include "resource.h"

LRESULT CALLBACK WinSunProc(
	HWND hwnd,      // handle to window
	UINT uMsg,      // message identifier
	WPARAM wParam,  // first message parameter
	LPARAM lParam   // second message parameter
	);

#define NID_UID 100
#define WM_TASKBARNOTIFY WM_USER+20
#define WM_TASKBARNOTIFY_MENUITEM_SHOW (WM_USER + 21)
#define WM_TASKBARNOTIFY_MENUITEM_HIDE (WM_USER + 22)
#define WM_TASKBARNOTIFY_MENUITEM_RELOAD (WM_USER + 23)
#define WM_TASKBARNOTIFY_MENUITEM_ABOUT (WM_USER + 24)
#define WM_TASKBARNOTIFY_MENUITEM_EXIT (WM_USER + 25)
#define WM_TASKBARNOTIFY_MENUITEM_PROXYLIST_BASE (WM_USER + 30)

HWND hWnd;
HINSTANCE HInst;
HWND hConsole;
HMENU Hmenu;
HMENU HSubMenu;
UINT g_currentproxyid;

BOOL TrayIconSet(DWORD dwMessage)
{
	NOTIFYICONDATA NotifyData	= {0};
	NotifyData.cbSize			= (DWORD)sizeof(NOTIFYICONDATA);
	NotifyData.hWnd				= hWnd;
	NotifyData.uID				= NID_UID;
	NotifyData.uFlags			= NIF_ICON|NIF_MESSAGE|NIF_INFO|NIF_TIP;
	NotifyData.dwInfoFlags		= NIIF_INFO;
	NotifyData.uCallbackMessage = WM_TASKBARNOTIFY;
	NotifyData.hIcon			= LoadIcon(HInst, (LPCTSTR)IDI_SMALL);

	strcpy(NotifyData.szInfoTitle, "InfoTitle.");
	strcpy(NotifyData.szInfo, "Info");
	strcpy(NotifyData.szTip, "Tip");

	return Shell_NotifyIcon(dwMessage, &NotifyData);
}

BOOL PopupMenuCreate()
{
	CString MenuItems[] = {"显示", "隐藏", "设置IE代理", "重新载入", "退出"};
	CString SubMenuItems[] = {"http://127.0.0.1:8086/proxy.pac", "127.0.0.1:8086"};

	Hmenu = CreatePopupMenu();
	for (int i=0; i<5;i++)
	{
		AppendMenu(Hmenu, MF_STRING, WM_TASKBARNOTIFY_MENUITEM_SHOW+i, MenuItems[i]);
	}

	HSubMenu = CreatePopupMenu();
	for(int i=0; i<2; i++)
	{
		AppendMenu(HSubMenu, MF_STRING, WM_TASKBARNOTIFY_MENUITEM_PROXYLIST_BASE+i, SubMenuItems[i]);
	}

	ModifyMenu(Hmenu, 2, MF_STRING | MF_POPUP | MF_BYPOSITION, (UINT_PTR)HSubMenu, MenuItems[2]);

	return TRUE;
}

BOOL ShowPopupMenu()
{
	POINT pt;
	GetCursorPos(&pt);
	
	ModifyMenu(HSubMenu, g_currentproxyid,			\
		MF_STRING|MF_CHECKED|MF_BYPOSITION,	\
		WM_TASKBARNOTIFY_MENUITEM_PROXYLIST_BASE + g_currentproxyid, \
		"AAAAAA");
	
	TrackPopupMenu(Hmenu, TPM_LEFTALIGN, pt.x, pt.y, 0, hWnd, NULL);
	PostMessage(hWnd, WM_NULL, 0, 0);

	return TRUE;
}

int WINAPI WinMain(
	HINSTANCE hInstance,      // handle to current instance
	HINSTANCE hPrevInstance,  // handle to previous instance
	LPSTR lpCmdLine,          // command line
	int nCmdShow              // show state
	)
{
	HInst = hInstance;

	WNDCLASS wndcls;
	wndcls.cbClsExtra=0;
	wndcls.cbWndExtra=0;
	wndcls.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	wndcls.hCursor=LoadCursor(NULL,IDC_CROSS);
	wndcls.hIcon=LoadIcon(NULL,IDI_ERROR);
	wndcls.hInstance=hInstance;
	wndcls.lpfnWndProc=WinSunProc;
	wndcls.lpszClassName="Weixin2003";
	wndcls.lpszMenuName=NULL;
	wndcls.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);

	hWnd=CreateWindow("Weixin2003","北京维新科学技术培训中心",WS_OVERLAPPED|WS_SYSMENU,
		0,0,600,400,NULL,NULL,hInstance,NULL);

	ShowWindow(hWnd, SW_HIDE /*SW_SHOWNORMAL*/);
	UpdateWindow(hWnd);

	WCHAR szVisible[BUFSIZ] = L"";

	AllocConsole();
	_wfreopen(L"CONIN$",  L"r+t", stdin);
	_wfreopen(L"CONOUT$", L"w+t", stdout);

	hConsole = GetConsoleWindow();

	SetForegroundWindow(hConsole);
	printf("Start......\n");

	SetWindowText(hConsole, "Hello Baby!");

	TrayIconSet(NIM_ADD);

	PopupMenuCreate();

	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WinSunProc(
	HWND hwnd,      // handle to window
	UINT uMsg,      // message identifier
	WPARAM wParam,  // first message parameter
	LPARAM lParam   // second message parameter
	)
{
	UINT nID = -1;

	switch(uMsg)
	{
	case WM_CHAR:
		char szChar[20];
		sprintf(szChar,"char is %d",wParam);
		printf("%s\n", szChar);
		MessageBox(hwnd,szChar,"weixin",0);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd,"mouse clicked","weixin",0);
		printf("%s\n", "mouse clicked");
		HDC hdc;
		hdc=GetDC(hwnd);
		TextOut(hdc,0,50,"计算机编程语言培训",strlen("计算机编程语言培训"));
		ReleaseDC(hwnd,hdc);
		break;
	case WM_PAINT:
		HDC hDC;
		PAINTSTRUCT ps;
		hDC=BeginPaint(hwnd,&ps);
		TextOut(hDC,0,0,"维新培训",strlen("维新培训"));
		EndPaint(hwnd,&ps);
		break;
	case WM_CLOSE:
		if(IDYES==MessageBox(hwnd,"是否真的结束？","weixin",MB_YESNO))
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_TASKBARNOTIFY:
		if (lParam == WM_LBUTTONUP)
		{
			ShowWindow(hConsole, !IsWindowVisible(hConsole));
			SetForegroundWindow(hConsole);
		}
		else if (lParam == WM_RBUTTONUP)
		{
			SetForegroundWindow(hWnd);
			
			ShowPopupMenu();
		}
		break;
	case WM_COMMAND:
		nID = LOWORD(wParam);
		if (WM_TASKBARNOTIFY_MENUITEM_PROXYLIST_BASE <= nID && nID <= WM_TASKBARNOTIFY_MENUITEM_PROXYLIST_BASE+1)
		{
			//WCHAR *szProxy = lpProxyList[nID-WM_TASKBARNOTIFY_MENUITEM_PROXYLIST_BASE];
			//SetWindowsProxy(szProxy);
			//SetWindowsProxyForAllRasConnections(szProxy);
			//TrayIconSet(szProxy, NIM_MODIFY);
			g_currentproxyid = nID - WM_TASKBARNOTIFY_MENUITEM_PROXYLIST_BASE;
			//notify....
			//ShowPopupMenu();
		}
		break;
	default:
		return DefWindowProc(hwnd,uMsg,wParam,lParam);
	}
	return 0;
}