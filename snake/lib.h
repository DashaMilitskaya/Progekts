#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>

extern int direct;
extern int prev_dir;
extern COORD snake[2048];
extern int len;
extern int sx;
extern int sy;
extern int running;
extern int ax;
extern int ay;
extern int points;


void gotoxy(int x, int y);
void handle();
void draw();
void apples();
void eat_himself();
void game_over();


#endif