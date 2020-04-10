#pragma once
#include <Windows.h>
void create_window(HINSTANCE, INT);
void loop();


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
