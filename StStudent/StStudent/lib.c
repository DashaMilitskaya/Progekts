#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <malloc.h>
#include <float.h>

#include "lib.h"

StudentEntry* headl;


void NewSList(StudentEntry** head) {
	*head = (StudentEntry*)malloc(sizeof(StudentEntry));
	(*head)->nextStudent = 0;
	(headl->studentName) = NULL;
}

void NewStList() {
	NewSList(&headl);
}

char* ReadStringFromConsol() {
	char c;
	int size = 0;
	char* fname = (char*)malloc(size * sizeof(char));
	while (1) {
		c = getch();
		printf("%c", c);
		size++;
		fname = (char*)realloc(fname, size * sizeof(char));
		if (c == 13) {
			printf("\n");
			fname[size - 1] = '\0';
			break;
		}
		fname[size - 1] = (char)c;
	}
	return fname;
}

void GetStudentFromConsol() {
	StudentEntry* NewStudent;
	NewStudent = (StudentEntry*)malloc(sizeof(StudentEntry));
	if((headl->studentName)!= NULL){
	 (NewStudent->nextStudent) = headl;
	}
	else (NewStudent->nextStudent) = NULL;
	headl = NewStudent;
	printf_s("Name: \n");
	(NewStudent->studentName) = ReadStringFromConsol();
	printf_s("Surname: \n");
	(NewStudent->surname) = ReadStringFromConsol();
	printf_s("Group: \n");
	(NewStudent->group) = ReadStringFromConsol();
	printf_s("Age: \n");
	scanf_s("%d", &(NewStudent->age));
	printf_s("Number: \n");
	(NewStudent->number) = ReadStringFromConsol();
	printf_s("Marks(1-5) with space then enter: \n");
	(NewStudent->numberofmark) = 0;
		int c, sum;
		sum = 0;
		int size = 0;
		(NewStudent->marks) = (int*)malloc(size * sizeof(int));
		while (1) {
			c = getch();
			printf("%c", c);
			if (c != 32) {


				size++;
				(NewStudent->marks) = (int*)realloc((NewStudent->marks), size * sizeof(int));
				if (c == 13) {
					printf("\n");
					break;
				}
				(NewStudent->marks)[size - 1] = c - 48;
				sum = sum + (c - 48);
			}
		}
		(NewStudent->numberofmark) = size - 1;
		(NewStudent->mark) = (float) sum / (NewStudent->numberofmark);
}

void PrintStList() {
	StudentEntry* tmp = headl;
	while (1) {
		printf_s("%s %s %s %d %s %f \n", (tmp->studentName),(tmp->surname), 
			(tmp->group), (tmp->age), (tmp->number), (tmp->mark));
		tmp = (tmp->nextStudent);
		if (tmp == NULL) {
			break;
		}
	}

}

void PrintGroup(char* _group) {
	StudentEntry* tmp = headl;
	while (1) {
		if(strcmp(_group,(tmp->group))==0) 
			printf_s("%s %s %s %d %s %f \n", (tmp->studentName), (tmp->surname),
			(tmp->group), (tmp->age), (tmp->number), (tmp->mark));
		tmp = (tmp->nextStudent);
		if (tmp == NULL) {
			break;
		}
	}
}

void PrintUspev() {
	StudentEntry* tmp = headl;
	while (1) {
		if (((int)(roundf(tmp->mark))) >= 4)
			printf_s("%s %s %s %d %s %f \n", (tmp->studentName), (tmp->surname),
			(tmp->group), (tmp->age), (tmp->number), (tmp->mark));
		tmp = (tmp->nextStudent);
		if (tmp == NULL) {
			break;
		}
	}
}

void GetWordFromFile(FILE* f, char** word) {
		char tmp;
		*word = (char*)malloc(sizeof(char));
		fscanf_s(f,"%c", &tmp, 1);
		int size = 1;
		while ((tmp != 32)&&(tmp!=13)&&(!feof(f))) {
			*word = (char*)realloc(*word, size * sizeof(char));
			(*word)[size - 1] = tmp;
			size++;
			fscanf_s(f, "%c", &tmp, 1);
		}
		*word = (char*)realloc(*word, (size+1) * sizeof(char));
		(*word)[size - 1] = '\0';

}

void RememberNewStudent() {
    StudentEntry* NewStudent;
	NewStudent = (StudentEntry*)malloc(sizeof(StudentEntry));
	if ((headl->studentName) != NULL) {
		(NewStudent->nextStudent) = headl;
	}
	else (NewStudent->nextStudent) = NULL;
	headl = NewStudent;
}

void GetStudentsFromFiletxt(FILE* f) {
	unsigned char tmp = 0;
	int size = 1;
	int sum = 0;
	while (!feof(f)) {

			RememberNewStudent();
			(headl->marks) = (int*)malloc(sizeof(int));
			size = 1;
			GetWordFromFile(f, &(headl->studentName));
			GetWordFromFile(f, &(headl->surname));
			GetWordFromFile(f, &(headl->group));
			GetWordFromFile(f, &(headl->number));
			fscanf_s(f,"%d" ,&(headl->age));

			tmp = 0; sum = 0;
			while ((tmp != 10)&&(!feof(f))) {
				
				(headl->marks) = (int*)realloc(headl->marks, size * sizeof(int));
				fscanf_s(f, "%d", &((headl->marks)[size-1]));
				sum = sum + (headl->marks)[size - 1];
				size++;
				fscanf_s(f, "%c", &tmp, 1);
				
			}
			(headl->numberofmark) = size - 1;
			(headl->mark) = (float)sum / (headl->numberofmark);



	}
	fseek(f, 0, SEEK_SET);
}

void WriteStToTxt(FILE *f, StudentEntry* student) {
	fprintf_s(f, "%s ", student->studentName);
	fprintf_s(f, "%s ", student->surname);
	fprintf_s(f, "%s ", student->group);
	fprintf_s(f, "%s ", student->number);
	fprintf_s(f, "%d ", student->age);
	for (int i = 0; i < (student->numberofmark); i++) {
		if (((student->numberofmark) - 1) != i) {
            fprintf_s(f, "%d ", (student->marks)[i]);
		} else fprintf_s(f, "%d", (student->marks)[i]);
		
	}
	if((student->nextStudent)!=NULL)
	fprintf_s(f, "\n");
}

void WriteListToTxt(FILE *f) {
	StudentEntry* tmp = headl;
	while (tmp != NULL) {
      WriteStToTxt(f, tmp);
	  tmp = tmp->nextStudent;
	}
	fseek(f, 0, SEEK_SET);

}


void WriteStrToDat(FILE *f, char* s) {
	int size = strlen(s);
	fwrite(&size, sizeof(int), 1, f);
	for (int i = 0; i < size; i++) {
		fwrite(&(s[i]), sizeof(char), 1, f);
	}

}

void WriteStructToDat(FILE *f, StudentEntry* student) {
	WriteStrToDat(f, student->studentName);
	WriteStrToDat(f, student->surname);
	WriteStrToDat(f, student->group);
	fwrite(&(student->age), sizeof(int), 1, f);
	WriteStrToDat(f, student->number);
	fwrite(&(student->mark), sizeof(float), 1, f);
	fwrite(&(student->numberofmark), sizeof(int), 1, f);
	for (int i = 0; i < (student->numberofmark); i++) {
		fwrite(&((student->marks)[i]), sizeof(int), 1, f);
	}
}

void WriteListToDat(FILE *f) {
	int kol = 0;
	StudentEntry* tmp = headl;
	fwrite(&kol, sizeof(int), 1, f);
	while (tmp != NULL) {
		WriteStructToDat(f, tmp);
		kol++;
		tmp = tmp->nextStudent;
	}
	rewind(f);
	fwrite(&kol, sizeof(int), 1, f);
	fseek(f, 0, SEEK_SET);
}

void readStrFromDat(char** s, FILE *f) {
	int kol;
	fread(&kol, sizeof(int), 1, f);
	*s = (char*)malloc(sizeof(char)*(kol + 1));
	for (int i = 0; i < kol; i++) {

		fread(&((*s)[i]), sizeof(char), 1, f);
	}
	(*s)[kol] = '\0';
}

void readStructFromDat(StudentEntry* student, FILE *f) {
	readStrFromDat(&(student->studentName), f);
	readStrFromDat(&(student->surname), f);
	readStrFromDat(&(student->group), f);
	fread(&(student->age), sizeof(int), 1, f);
	readStrFromDat(&(student->number), f);
	fread(&(student->mark), sizeof(float), 1, f);
	fread(&(student->numberofmark), sizeof(int), 1, f);
	(student->marks) = (int*)malloc((student->numberofmark) * sizeof(int));
	for (int i = 0; i < (student->numberofmark); i++) {
		fread(&((student->marks)[i]), sizeof(int), 1, f);
	}
}

void GetStudentsFromDat(FILE *f) {
	StudentEntry student;
	int kol;
	fread(&kol, sizeof(int), 1, f);
	for (int i = 0; i < kol; i++) {
		RememberNewStudent();
		readStructFromDat(headl, f);
	}
	fseek(f, 0, SEEK_SET);
}


void DeleteStByPtr(StudentEntry* st) {
	StudentEntry* tmp;
	if (st == headl) {
		headl = headl->nextStudent;
	}
	else {
		tmp = headl;
		while ((tmp->nextStudent) != NULL) {
			if ((tmp->nextStudent) == st) {
				(tmp->nextStudent) = st->nextStudent;
				break;
			}
			tmp = tmp->nextStudent;
		}
	}
	free(st->studentName);
	free(st->surname);
	free(st->group);
	free(st->number);
	free(st->marks);
}

void DeleteStWithSuName(char* suname) {
	StudentEntry* tmp = headl;
	while (tmp != NULL) {
		if (strcmp(suname, (tmp->surname)) == 0) {
			DeleteStByPtr(tmp);
		}
		tmp = tmp->nextStudent;
	}
}

void DeleteStWithNumber(int num) {
	StudentEntry* tmp = headl;
	int k = 1;
	while (k != num) {
		k++;
		tmp = tmp->nextStudent;
	}
	DeleteStByPtr(tmp);
}

void DeleteNeusp() {
	StudentEntry* tmp = headl;
	while (1) {
		if (((int)(roundf(tmp->mark))) < 4)
			DeleteStByPtr(tmp);
		tmp = (tmp->nextStudent);
		if (tmp == NULL) {
			break;
		}
	}
}

void PrintIV() {
	
		StudentEntry* tmp = headl;
		while (1) {
			if ((strlen(tmp->surname) >= 2) && ((((tmp->surname)[0]))==73) && (((tmp->surname)[1]) == 118))
				printf_s("%s %s %s %d %s %f \n", (tmp->studentName), (tmp->surname),
				(tmp->group), (tmp->age), (tmp->number), (tmp->mark));
			tmp = (tmp->nextStudent);
			if (tmp == NULL) {
				break;
			}
		}
	
}

void GenerteRandWord(char** s) {
	
	*s = (char*)malloc(sizeof(char) * 4);
	(*s)[0] = 65 + (rand() % 23);
	for (int i = 1; i < 3; i++) {
		(*s)[i]=97 + (rand() % 23);
	}
	(*s)[3] = '\0';
}

void GenerteRandNum(char** s) {

	*s = (char*)malloc(sizeof(char) * 12 );
	(*s)[0] = '7';
	for (int i = 1; i < 11; i++) {
		(*s)[i] = 48 + (rand() % 8);
	}
	(*s)[11] = '\0';
}
void AddRandom() {
	srand((unsigned int)time(0));
	RememberNewStudent();
	GenerteRandWord(&(headl->studentName));
	GenerteRandWord(&(headl->surname));
	GenerteRandWord(&(headl->group));
	(headl->age) = 20 + rand() % 10;
	GenerteRandNum(&(headl->number));
	(headl ->numberofmark)= 1+ rand() % 5;
	(headl->marks) = (int*)malloc((headl->numberofmark) * sizeof(int));
	int sum = 0;
	for (int i = 0; i < (headl->numberofmark); i++) {
		(headl->marks)[i]= 1 + rand() % 5;
		sum = sum + (headl->marks)[i];
	}
	(headl->mark) = (float) sum/ (headl->numberofmark);
}



void FreeSList(StudentEntry* head)
{
	StudentEntry* tmp;
	while (head != 0)
	{
		tmp = head;
		head = head->nextStudent;
		free(tmp);
		
	}
}

void FreeStList() {
	FreeSList(headl);

}

int Error_NOfile(char *filename) {
	if (!_access(filename, 00)) {
		printf("File Present \n");
		return 0;
	}
	else {
		printf("Error: File not Found \n");
		return 1;
	}
}

int Error_NOpravr(char *filename) {
	if (!_access(filename, 04)) {
		printf("have right to read file \n");
		return 0;
	}
	else {
		printf("Error: have not right to read file \n");
		return 1;
	}
}

int Error_NOpravw(char *filename) {
	if (!_access(filename, 02)) {
		printf("have right to write file \n");
		return 0;
	}
	else {
		printf("Error: have not right to write file \n");
		return 1;
	}
}

int FileErrorInput(char* file) {
	if (Error_NOfile(file) == 1) {
		return 1;
	}
	if (Error_NOpravr(file)) {
		return 1;
	}
	return 0;
}

int FileErrorOutput(char* file) {
	if (Error_NOfile(file) == 1) {
		return 1;
	}
	if (Error_NOpravw(file)) {
		return 1;
	}
	return 0;
}