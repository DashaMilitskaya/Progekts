#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
void setconsolesize(int x, int y)
{
	HANDLE hCons;
	COORD crd;
	SMALL_RECT rct;
	crd.X = (short)x + 1;
	crd.Y = (short)y + 1;
	rct.Left = 0;
	rct.Top = 0;
	rct.Right = x;
	rct.Bottom = y;
	hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hCons, crd);
	SetConsoleWindowInfo(hCons, 1, &rct);
}
void hidecursor()
{
	HANDLE hCons;
	CONSOLE_CURSOR_INFO cci;
	hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	cci.dwSize = 1;
	cci.bVisible = 0;
	SetConsoleCursorInfo(hCons, &cci);
}

void clrscr()
{
	HANDLE hCons;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD crd;
	int len;
	DWORD bRet;
	short x, y;
	char space = 0x20;
	hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hCons, &csbi);
	x = csbi.dwSize.X;
	y = csbi.dwSize.Y;
	len = (int)x*y;
	crd.X = 0;
	crd.Y = 0;
	FillConsoleOutputCharacter(hCons, space, len, crd, &bRet);
}

void gotoxy(int column, int row)
{
	HANDLE hCons;
	COORD crd;
	hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	//#ifdef MY_DEBUG 
	// if (hCons == INVALID_HANDLE_VALUE || hCons == 0) printf("\nERROR!!!\n"); 
	//#endif 
	crd.X = (short)column;
	crd.Y = (short)row;
	//#ifedf MY_DEBUG 
	// if (SetConsoleCursorPosition(hCons,crd) == 0) printf("\nERROR2\n"); 
	//#else 
	SetConsoleCursorPosition(hCons, crd);
	//#endif 
}
int GetFontSize(HANDLE windowHandle, COORD *size)
{
	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

	if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
	{
		return 0;
	}

	*size = font.dwFontSize;

	return 1;
}

int SetFontSize(HANDLE windowHandle, COORD size)
{
	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

	if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
	{
		return 0;
	}

	font.dwFontSize = size;

	if (!SetCurrentConsoleFontEx(windowHandle, 0, &font))
	{
		return 0;
	}

	return 1;
}


int GoX(int x)
{
	int i;
	i = -1 + rand() % 3;
	x = x + i;
	return x;
}
int GoY(int y)
{
	int j;
	j = -1 + rand() % 3;
	y = y + j;
	return y;
}
void print_sneg(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	SetConsoleTextAttribute(h, 2);
	gotoxy(x1, y1);
	printf("*");
	gotoxy(x1 + 2, y1);
	printf("*");
	gotoxy(x1 - 2, y1);
	printf("*");
	gotoxy(x1, y1 + 2);
	printf("*");
	gotoxy(x1, y1 - 2);
	printf("*");

	SetConsoleTextAttribute(h, 12);
	gotoxy(x2, y2);
	printf("*");
	gotoxy(x2 + 2, y2);
	printf("*");
	gotoxy(x2 - 2, y2);
	printf("*");
	gotoxy(x2, y2 + 2);
	printf("*");
	gotoxy(x2, y2 - 2);
	printf("*");

	SetConsoleTextAttribute(h, 11);
	gotoxy(x3, y3);
	printf("*");
	gotoxy(x3 + 2, y3);
	printf("*");
	gotoxy(x3 - 2, y3);
	printf("*");
	gotoxy(x3, y3 + 2);
	printf("*");
	gotoxy(x3, y3 -2);
	printf("*");

	SetConsoleTextAttribute(h, 8);
	gotoxy(x4, y4);
	printf("*");
	gotoxy(x4 + 2, y4);
	printf("*");
	gotoxy(x4 - 2, y4);
	printf("*");
	gotoxy(x4, y4 + 2);
	printf("*");
	gotoxy(x4, y4 - 2);
	printf("*");

	SetConsoleTextAttribute(h, 14);
	gotoxy(x5, y5);
	printf("*");
	gotoxy(x5 + 2, y5);
	printf("*");
	gotoxy(x5 - 2, y5);
	printf("*");
	gotoxy(x5, y5 + 2);
	printf("*");
	gotoxy(x5, y5 - 2);
	printf("*");
}

int main()
{
	srand((unsigned int)time(0));
	setconsolesize(60, 20);
	int x1 = 34, y1 = 8, x2 = 25, y2 = 15;
	int x3 = 15, y3 = 7, x4 = 55, y4 = 5, x5 = 50, y5 = 10;
	while (1)
	{
		x1 = GoX(x1);
		y1 = GoY(y1);

		x2 = GoX(x2);
		y2 = GoY(y2);

		x3 = GoX(x3);
		y3 = GoY(y3);

		x4 = GoX(x4);
		y4 = GoY(y4);

		x5 = GoX(x5);
		y5 = GoY(y5);
		Sleep(200);
		print_sneg(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5);
	}
	system("pause");
	return 0;
}