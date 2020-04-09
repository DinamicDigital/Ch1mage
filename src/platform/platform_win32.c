#include "platform_win32.h"

void create_window()
{
	const wchar_t NAME[] = L"window";

	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = NAME;

	RegisterClass(&wc);


	HWND window = CreateWindowEx(
		0, NAME,
		"Ch1mage",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		0, 0, hInstance, 0
	);

	if (window == 0)
	{
		return -1;
	}
	
	ShowWindow(window, nCmdShow);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_SIZE: {
			int width = LOWORD(lParam);
			int height = HIWORD(lParam);

			cb_on_size_w32(hwnd, (UINT) wParam, width, height);
		} break;
		case WM_CLOSE:
		{
			cb_on_close_w32(hwnd);
		} break;
		case WM_DESTROY:
		{
			cb_on_destroy_w32();
		} break;
		case WM_PAINT:
		{
			

			cb_on_paint_w32(hwnd);
		} break;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam); 
}

// TODO: Handle Sizing, it probably should do something.
static void cb_on_size_w32(HWND hwnd, UINT flags, int width, int height)
{

}

static void cb_on_close_w32(HWND hwnd)
{
	DestroyWindow(hwnd);
}

static void cb_on_destroy_w32()
{
	PostQuitMessage(0);
}

static void cb_on_paint_w32(HWND hwnd)
{
	HDC hdc = GetWindowDC(hwnd);
	RECT client;
	GetClientRect(hwnd, &client);
	BitBlt(hdc, 
}