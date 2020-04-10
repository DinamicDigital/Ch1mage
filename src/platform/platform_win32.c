#include "platform_win32.h"

// TODO: Handle Sizing, it probably should do something.
static void cb_on_size_w32(HWND hwnd, UINT flags, int width, int height);
static void cb_on_close_w32(HWND hwnd);
static void cb_on_destroy_w32();
static void cb_on_paint_w32(HWND hwnd);

void create_window(HINSTANCE hInstance, INT nCmdShow)
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

void loop()
{
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
	    TranslateMessage(&msg);
	    DispatchMessage(&msg);
	}
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
	PAINTSTRUCT paint;
	HDC hdc = BeginPaint(hwnd, &paint);
	RECT r;
	GetClientRect(hwnd, &r);
	BitBlt(hdc, 0, 0, r.right, r.bottom, hdc, 0, 0, BLACKNESS);

	TRIVERTEX vertex[2] ;
	vertex[0].x     = 0;
	vertex[0].y     = 0;
	vertex[0].Red   = 0x0000;
	vertex[0].Green = 0x8000;
	vertex[0].Blue  = 0x8000;
	vertex[0].Alpha = 0x0000;

	vertex[1].x     = r.right;
	vertex[1].y     = 20; 
	vertex[1].Red   = 0x0000;
	vertex[1].Green = 0xd000;
	vertex[1].Blue  = 0xd000;
	vertex[1].Alpha = 0x0000;

	// Create a GRADIENT_RECT structure that 
	// references the TRIVERTEX vertices. 
	GRADIENT_RECT gRect;
	gRect.UpperLeft  = 0;
	gRect.LowerRight = 1;

	// Draw a shaded rectangle. 
	GradientFill(hdc, vertex, 2, &gRect, 1, GRADIENT_FILL_RECT_H);


	
	EndPaint(hwnd, &paint);
}