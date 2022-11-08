// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// $Log:$
//
// DESCRIPTION:
//	Main program, simply calls D_DoomMain high level loop.
//
//-----------------------------------------------------------------------------

static const char
rcsid[] = "$Id: i_main.c,v 1.4 1997/02/03 22:45:10 b1 Exp $";

#include "doomdef.h"

#include "m_argv.h"
#include "d_main.h"

#ifdef WIN32
#include <Windows.h>

LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

INT WINAPI wWinMain
(
    HINSTANCE   hInst,
    HINSTANCE   hInstPrev,
    PSTR        cmdline, 
    int         cmdshow
)
{
    myargc = 0;
    myargv = CommandLineToArgW(GetCommandLine());

    const wchar_t CLASS_NAME[] = L"Doom Window Class";
    WNDCLASS dwc;

    dwc.lpfnWndProc = WindowProc;
    dwc.hInstance = hInst;
    dwc.lpszClassName = CLASS_NAME;

    RegisterClass(&dwc);

    // Create new window
    HWND hwnd = CreateWindowEx
    (
        0,
        CLASS_NAME,
        L"Doom",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL,
        NULL,
        hInst,
        NULL
    );
    if (hwnd == NULL) return -1;
    ShowWindow(hwnd, cmdshow);

    D_DoomMain();

    return 0;
}
#endif

#ifdef LINUX
int main 
(
    int     argc, 
    char**  argv
)
{ 
    myargc = argc;
    myargv = argv; 
 
    D_DoomMain (); 

    return 0;
} 
#endif


