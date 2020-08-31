#ifndef PCONSOLE_H
#define PCONSOLE_H

//#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <conio.h>
using namespace std;
#pragma comment (lib, "winmm.lib")

#define DarkBlue 1
#define DarkGreen 2
#define DarkCyan 3
#define DarkRed 4
#define DarkPink 5
#define DarkYellow 6
#define DarkWhite 7
#define Grey 8
#define Blue 9
#define Green 10
#define Cyan 11
#define Red 12
#define Pink 13
#define Yellow 14
#define White 15

// MOVING
#define UP 72		
#define DOWN 80  
#define LEFT 75   
#define RIGHT 77 
//

#define SPACE 32 
#define ENTER 13

// Ingame menu
#define PAUSE 112	// P
#define SAVE 115    // S
#define LOAD 108	// L
#define SETTING 116 // T
#define ESC 27
//

//// Player control
//#define W_key 119
//#define A_key 97
//#define S_key 115
//#define D_key 100
////

#define forc(i, a, b, x) for (int i = a; i < b; i += x)
#define forv(i, a, b, x) for (int i = a; i > b; i -= x)





// stable/fix the window size
inline void fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

// Change size of cmd frame
inline void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Change colors
inline void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Move pointer to (x,y) position
inline void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { SHORT(y - 1),SHORT(x - 1) };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Clear Screen
inline void clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

// Delay
inline void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

// Disable the cursor appear
inline void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}


#endif // PCONSOLE_H