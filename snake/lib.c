#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define DIR_RIGHT 1
#define DIR_LEFT -1
#define DIR_UP 2
#define DIR_DOWN -2

int direct = 0;
int prev_dir = 0;
COORD snake[2048];
int len = 3;
int sx = 10;
int sy = 10;
int running = 1;
int ax;
int ay;
int points = 0;

void gotoxy(int x, int y)
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

void game_over()
{
	Sleep(200);
	system("cls");
	gotoxy(40, 12);
	printf("game over\n");
	_getch();
	running = 0;
}

void apples()
{
	srand(time(NULL));
	ax = rand() % 80;
	ay = rand() % 25;
}

void eat_himself()
{
	int i;
	for (i = 1; i < len; i++)
		if (snake[i].X == snake[0].X && snake[i].Y == snake[0].Y)
			game_over();
}



void handle()
{
	while (_kbhit())
		switch (_getch())
		{
		case 'a':
			prev_dir = direct;
			direct = DIR_LEFT;
			break;
		case 'd':
			prev_dir = direct;
			direct = DIR_RIGHT;
			break;
		case 's':
			prev_dir = direct;
			direct = DIR_DOWN;
			break;
		case 'w':
			prev_dir = direct;
			direct = DIR_UP;
			break;
		case 'x':
			running = 0;
			break;
		default:
			return;
			break;
		}
}

void draw()
{
	int i, j;
	system("cls");
	gotoxy(ax, ay);
	putchar('*');
	if (prev_dir == -direct && prev_dir)
		game_over();
	switch (direct)
	{
	case DIR_RIGHT:
		if (snake[0].X + 1 < 80)
		{
			for (i = len - 1; i > 0; i--)
				snake[i] = snake[i - 1];
			snake[0].X++;
			eat_himself();
		}
		else
			game_over();
		break;
	case DIR_LEFT:
		if (snake[0].X - 1 > 0)
		{
			for (i = len - 1; i > 0; i--)
				snake[i] = snake[i - 1];
			snake[0].X--;
			eat_himself();
		}
		else
			game_over();
		break;
	case DIR_UP:
		if (snake[0].Y - 1 >= 0)
		{
			for (i = len - 1; i > 0; i--)
				snake[i] = snake[i - 1];
			snake[0].Y--;
			eat_himself();
		}
		else
			game_over();
		break;
	case DIR_DOWN:
		if (snake[0].Y + 1 < 25)
		{
			for (i = len - 1; i > 0; i--)
				snake[i] = snake[i - 1];
			snake[0].Y++;
			eat_himself();
		}
		else
			game_over();
		break;
	}
	if (ax == snake[0].X && ay == snake[0].Y)
	{
		++len;
		++points;
		apples();
	}
	char buf[32];
	int k = 32;
	sprintf_s(buf, 32, "points - %d", points);
	SetConsoleTitle(buf);
	gotoxy(snake[0].X, snake[0].Y);
	putchar('@');
	for (i = 1; i < len; i++)
	{
		gotoxy(snake[i].X, snake[i].Y);
		putchar('o');
	}
	gotoxy(0, 0);
}


