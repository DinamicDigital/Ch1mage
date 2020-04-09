#include <Windows.h>
#include <stdio.h>
#include "platform_win32.h"

// TODO: Abstract the windows code completely, ie write our own platform layer for easy cross-platformness.
INT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, INT nCmdShow)
{
	create_window();

	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
	    TranslateMessage(&msg);
	    DispatchMessage(&msg);
	}
    
    return 0;
}

