// Dll1.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

int __stdcall add(int a, int b)
{
	return a + b;
}



int __stdcall sub(int a, int b)
{
	return a - b;
}


