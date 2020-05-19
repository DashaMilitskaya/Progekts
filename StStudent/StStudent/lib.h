#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <malloc.h>
#include <float.h>

typedef struct {
	char *studentName;
	char *surname;
	char *group;
	int age;
	char* number;
	float mark;
	int *marks;
	int numberofmark;
	struct StudentEntry* nextStudent;
} StudentEntry;

 

extern StudentEntry* headl;

void NewSList(StudentEntry** head);
void NewStList();
char* ReadStringFromConsol();
void GetStudentFromConsol();
void PrintStList();
void PrintGroup(char* _group);
void PrintUspev();
void GetWordFromFile(FILE* f, char** word);
void RememberNewStudent();
void GetStudentsFromFiletxt(FILE* f);
void WriteStToTxt(FILE *f, StudentEntry* student);
void WriteListToTxt(FILE *f);
void WriteListToDat(FILE *f);
void DeleteStByPtr(StudentEntry* st);
void DeleteStWithSuName(char* suname);
void DeleteStWithNumber(int num);
void DeleteNeusp();
void PrintIV();
void GenerteRandWord(char** s);
void GenerteRandNum(char** s);
void AddRandom();
void FreeSList(StudentEntry* head);
void FreeStList();
int Error_NOfile(char *filename);
int Error_NOpravr(char *filename);
int Error_NOpravw(char *filename);
int FileErrorInput(char* file);
int FileErrorOutput(char* file);
#endif