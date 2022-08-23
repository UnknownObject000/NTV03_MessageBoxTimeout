# NTV03_MessageBoxTimeout
NTAPI自动消失的消息框视频源代码，用于演示未公开的API
 - MessageBoxTimeoutA
 - MessageBoxTimeoutW

## 关于MessageBoxTimeoutA

### 函数原型
```c++
int MessageBoxTimeoutA(IN HWND hWnd, IN LPCSTR lpText, IN LPCSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
```

### 函数指针类型
```c++
typedef int(__stdcall* typeMSGBOXAAPI)(IN HWND hWnd, IN LPCSTR lpText, IN LPCSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
```

### 所在DLL
 - user32.dll

## 关于MessageBoxTimeoutW

### 函数原型
```c++
int MessageBoxTimeoutW(IN HWND hWnd, IN LPCWSTR lpText, IN LPCWSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
```

### 函数指针类型
```c++
typedef int(__stdcall* typeMSGBOXWAPI)(IN HWND hWnd, IN LPCWSTR lpText, IN LPCWSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
```

### 所在DLL
 - user32.dll
 
 ## 兼容不同字符集所使用的宏定义
 ```
#ifdef _UNICODE
#define MessageBoxTimeout MessageBoxTimeoutW
#else
#define MessageBoxTimeout MessageBoxTimeoutA
#endif
 ```
