// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

int __stdcall add(int a, int b);
int __stdcall sub(int a, int b);

//#ifdef __cplusplus
//extern "C"
//{
//	int __stdcall mux(int a, int  b);
//}
//#endif

// reference additional headers your program requires here
