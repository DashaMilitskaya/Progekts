#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <io.h>


typedef struct {
	unsigned char** mas;
	int strok;
	int* elstr;

}book;

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

int strok(FILE *X) {
	int m = 1;
	unsigned char tmp;
	while (!feof(X)) {
		if (fscanf_s(X, "%c", &tmp, 1) == 1) {

			if (tmp == 10) {
				m++;
			}

		}

		else
			break;
	}
	fseek(X, 0, SEEK_SET);
	return m;
}


int ElementovStr(FILE *X) {
	int n = 0;
	char tmp = 0;
	

		while ((tmp != 10) && (!feof(X))) {
			
			
			fscanf_s(X, "%c", &tmp, 1);
			if ((tmp != 10) && (!feof(X) && (tmp != 13)))
			{
	          n++;
			}

		}
	

	
	return n;
}	
 
void RememberMas(FILE *X, book* text) {
	(text->strok) = strok(X);
	(text->mas) = (char**)malloc(sizeof(char*)*(text->strok));
	(text->elstr) = (int*)malloc(sizeof(int)*(text->strok));
	for (int i = 0; i < (text->strok); i++) {
		((text->elstr)[i]) = ElementovStr(X);
		((text->mas)[i]) = (char*)malloc(sizeof(char)*((text->elstr)[i]));
	}
fseek(X, 0, SEEK_SET);
}

void InputBookFromFile(FILE *X, book* text) {
	RememberMas(X, text);
	unsigned char tmp;
	for (int i = 0; i < (text->strok); i++) {
		for (int j = 0; j < ((text->elstr)[i]); j++) {
			fscanf_s(X, "%c", &tmp, 1);
	        ((text->mas)[i][j]) = tmp;
		}
		fscanf_s(X, "%c", &tmp, 1);

	}
}

void OutputBookToConsol(book* text) {
	for (int i = 0; i < (text->strok); i++) {
		for (int j = 0; j < ((text->elstr)[i]); j++) {
			printf_s("%c", ((text->mas)[i][j]));

		}
		printf_s("\n");
	}
}


void qsort(int *elstr, int size, unsigned char** mas2) {
	
	int i = 0;
	int j = size - 1;

	
	int mid = elstr[size / 2];
	

	
	do {
		
		
		while (elstr[i] < mid) {
			i++;
		}
		
		while (elstr[j] > mid) {
			j--;
		}

		
		if (i <= j) {
			int tmp = elstr[i];
			elstr[i] = elstr[j];
			elstr[j] = tmp;
			
			char* uk = mas2[i];
			mas2[i] = mas2[j];
			mas2[j] = uk;
			
			i++;
			j--;
			
		}
	} while (i <= j);


	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		qsort(elstr, j + 1, mas2);
	}
	if (i < size) {
		//"Првый кусок"
		qsort(&elstr[i], size - i, &mas2[i]);
	}
	
	
}

void SortText(book* text) {
	qsort((text->elstr),(text->strok),(text->mas));
}

char* ReadFNameFromConsol() {
	int c;
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

void FreeMemory(book* text) {
	   for (int i = 0; i < (text->strok); i++) {
		   free((text->mas)[i]);


	   }

	   free(text->mas);
	   free(text->elstr);
}

 
	


