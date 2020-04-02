#ifndef LIB_H
#define LIB_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <io.h>
#include <locale.h>

typedef struct {
	unsigned char** mas;
	int strok;
	int* elstr;

}book;

int Error_NOfile(char *filename);
int Error_NOpravr(char *filename);
int Error_NOpravw(char *filename);
int FileErrorInput(char* file);
int FileErrorOutput(char* file);



int strok(FILE *X);
int ElementovStr(FILE *X);
void RememberMas(FILE *X, book* text);
void InputBookFromFile(FILE *X, book* text);
void OutputBookToConsol(book* text);
void FreeMemory(book* text);
void qsort(int *elstr, int size, unsigned char** mas2);
char* ReadFNameFromConsol();
void SortText(book* text);

#endif