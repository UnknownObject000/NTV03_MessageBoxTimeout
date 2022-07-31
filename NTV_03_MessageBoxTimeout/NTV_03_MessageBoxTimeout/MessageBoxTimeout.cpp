#include "pch.h"
#include "MessageBoxTimeout.h"

int MessageBoxTimeoutA(IN HWND hWnd, IN LPCSTR lpText, IN LPCSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds)
{
	MSGBOXAAPI func_MessageBoxTimeoutA = nullptr;
	HMODULE hUser32 = GetModuleHandle(L"user32.dll");
	if (!hUser32)
		return -1;
	func_MessageBoxTimeoutA = (MSGBOXAAPI)GetProcAddress(hUser32, "MessageBoxTimeoutA");
	if (func_MessageBoxTimeoutA)
		return func_MessageBoxTimeoutA(hWnd, lpText, lpCaption, uType, wLanguageId, dwMilliseconds);
	else
		return -2;
}

int MessageBoxTimeoutW(IN HWND hWnd, IN LPCWSTR lpText, IN LPCWSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds)
{
	MSGBOXWAPI func_MessageBoxTimeoutW = nullptr;
	HMODULE hUser32 = GetModuleHandle(L"user32.dll");
	if (!hUser32)
		return -1;
	func_MessageBoxTimeoutW = (MSGBOXWAPI)GetProcAddress(hUser32, "MessageBoxTimeoutW");
	if (func_MessageBoxTimeoutW)
		return func_MessageBoxTimeoutW(hWnd, lpText, lpCaption, uType, wLanguageId, dwMilliseconds);
	else
		return -2;
}
