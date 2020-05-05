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
	int size;
	int zn;
	int* nums;

}BigInt;

int Error_NOfile(char *filename);
int Error_NOpravr(char *filename);
int Error_NOpravw(char *filename);
int FileErrorInput(char* file);
int FileErrorOutput(char* file);

void readBIGINt(FILE* F, BigInt* A);
void PrintBigInt(BigInt* A);
void BigModPlus(BigInt *A, BigInt *B, BigInt *C);
void BigModMinus(BigInt *A, BigInt *B, BigInt *C);
int SravnMod(BigInt *A, BigInt *B);
void DeleteNULLS(BigInt* C);
void BigModMultiply(BigInt *A, BigInt *B, BigInt *C);
void FreeInt(BigInt* A);
void BigModDiv(BigInt *A, BigInt *B, BigInt *C);
void BigPlus(BigInt *A, BigInt *B, BigInt *C);
void BigMinus(BigInt *A, BigInt *B, BigInt *C);
void BigMultiply(BigInt *A, BigInt *B, BigInt *C);
void BigDiv(BigInt *A, BigInt *B, BigInt *C);

#endif