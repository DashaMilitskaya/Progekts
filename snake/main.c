#include "lib.h"

int main()
{
	int i;
	for (i = 0; i < len; i++)
	{
		snake[i].X = sx - i;
		snake[i].Y = sy;
	}
	apples();
	while (running)
	{
		handle();
		draw();
		Sleep(100);
	}
	return 0;
}
