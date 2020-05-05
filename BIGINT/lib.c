#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <io.h>

typedef struct {
	int size;
	int zn;
int* nums;

}BigInt;

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


void readBIGINt(FILE* F, BigInt* A) {
	(A->nums) = (int*)malloc(sizeof(int));
	int i = 0;
	unsigned int tmp;
	unsigned char tmp2;
	fscanf_s(F, "%c", &tmp2, 1);
	if (tmp2 == 45) {
		(A->zn) = 1;
	}
	else {
		fseek(F, 0, SEEK_SET);
		fscanf_s(F, "%1d", &tmp, 1);
		(A->zn) = 0;
		(A->nums)[i] = tmp;
		i++;
	}

	while (!feof(F)) {
		fscanf_s(F, "%1d", &tmp, 1);
		(A->nums) = (int*)realloc((A->nums), (i + 1) * sizeof(int));
		(A->nums)[i] = tmp;
		i++;
	}
	(A->size) = i - 1;

}

void PrintBigInt(BigInt* A) {
	if ((A->zn) == 1)
		printf_s("-");
	for (int i = 0; i < (A->size); i++) {
		printf_s("%d", (A->nums)[i]);
	}
	printf_s("\n");

}

void DeleteNULLS(BigInt* C) {
	while (((C->nums)[0]) == 0){

		if (((C->size) > 1)) {
			for (int i = 0; i < (C->size) - 1; i++) {
			(C->nums)[i] = (C->nums)[i + 1];
			}
			(C->size) = (C->size) - 1;
		}
		else break;
	}
}
// |A|+|B|=|C|
void BigModPlus(BigInt *A, BigInt *B, BigInt *C){
	int i, m, b, r;
	if ((A->size) < (B->size)) { m = A->size; b = B->size; }
	else { m = B->size; b = A->size;
	}
	i = 0;
	r = 0;
	(C->nums) = (int*)malloc( (b+1) * sizeof(int));
	(C->size) = b + 1;
	while (i!= m) { 
		(C->nums)[(C->size) - 1 - i] = (A->nums)[(A->size)-1-i] + (B->nums)[(B->size) - 1 - i]+r;
		if ((C->nums)[(C->size) - 1 - i] > 9) {
			r = (C->nums)[(C->size) - 1 - i]/10;
			(C->nums)[(C->size) - 1 - i] = (C->nums)[(C->size) - 1 - i] % 10;
		}
		else {
			r = 0;
		}
		i++;

	}
	
	if ((A->size) > (B->size)) {

		while (i != b) {
			(C->nums)[(C->size) - 1 - i] = (A->nums)[(A->size) - 1 - i] + r;
			if ((C->nums)[(C->size) - 1 - i] > 9) {
				r = (C->nums)[(C->size) - 1 - i] / 10;
				(C->nums)[(C->size) - 1 - i] = (C->nums)[(C->size) - 1 - i] % 10;
			}
			else {
				r = 0;
			}
			i++;

		}
	}

		else {

			while (i != b) {
			(C->nums)[(C->size) - 1 - i] = (B->nums)[(B->size) - 1 - i] + r;
				if ((C->nums)[(C->size) - 1 - i] > 9) {
					r = (C->nums)[(C->size) - 1 - i] / 10;
					(C->nums)[(C->size) - 1 - i] = (C->nums)[(C->size) - 1 - i] % 10;
				}
					else {
						r = 0;
					}
				i++;
			}
		}
	(C->nums)[(C->size) - 1 - i] = r;
}
// |A|-|B|=|C|
void BigModMinus(BigInt *A, BigInt *B, BigInt *C) {
	int i, m, b, r;
	if ((A->size) < (B->size)) { m = A->size; b = B->size; }
	else {
		m = B->size; b = A->size;
	}
	i = 0;
	r = 0;
	(C->nums) = (int*)malloc((b) * sizeof(int));
	(C->size) = b
;
	while (i != m) {
		(C->nums)[(C->size) - 1 - i] = (A->nums)[(A->size) - 1 - i] - (B->nums)[(B->size) - 1 - i] + r;
		if ((C->nums)[(C->size) - 1 - i] < 0) {
			r = -1;
			(C->nums)[(C->size) - 1 - i] = (C->nums)[(C->size) - 1 - i] + 10;
		}
		else {
			r = 0;
		}
		i++;

	}


		while (i != b) {
			(C->nums)[(C->size) - 1 - i] = (A->nums)[(A->size) - 1 - i] + r;
			if ((C->nums)[(C->size) - 1 - i] < 0) {
				r = -1;
				(C->nums)[(C->size) - 1 - i] = (C->nums)[(C->size) - 1 - i] + 10;
			}
			else {
				r = 0;
			}
			i++;

		}
	
}

int SravnMod(BigInt *A, BigInt *B){
	if ((A->size) > (B->size)) return 1;
	if ((A->size) < (B->size)) return 2;
	if((A->size)==(B->size)){
		for (int i = 0; i < A->size ; i++) {
			if ((A->nums)[i] > (B->nums)[i]) return 1;
			if ((A->nums)[i] < (B->nums)[i]) return 2;
		}
	}
	return 3;
}

void BigModMultiply(BigInt *A, BigInt *B, BigInt *C) {
	
	(C->nums) = (int*)calloc(1, sizeof(int));
	(C->size) = 1;

	BigInt tmp;
	BigInt tmp2;
	int r = 0;
	int t = 0;
	tmp.size = (A->size) + 1;
	tmp.nums = (int*)calloc(((A->size) + 1), sizeof(int));
	for (int i = (B->size) - 1; i >= 0; i--) {
		tmp.nums = (int*)calloc(((A->size) + 1), sizeof(int));
		r = 0;
		for (int j = (A->size) - 1; j >= 0; j--) {
			(tmp.nums)[j+1] = (A->nums)[j] * (B->nums)[i] + r;
			if ((tmp.nums)[j+1] > 10) {
				r = (tmp.nums)[j+1] / 10;
				(tmp.nums)[j+1] = (tmp.nums)[j+1] % 10;
			}
			else {
				r = 0;
			}
		}
		(tmp.nums)[0] = (tmp.nums)[0] + r;
		
		if (t > 0) {
			tmp.nums = (int*)realloc(tmp.nums, (tmp.size + 1)*(sizeof(int)));
			tmp.size = tmp.size + 1;
			for(int k = 1; k <=t; k++ )
			(tmp.nums)[tmp.size - k] = 0;
		}
		tmp2 = *C;
		BigModPlus(&tmp2, &tmp, C);
		DeleteNULLS(C);
		t++;
		//PrintBigInt(&tmp);
		//PrintBigInt(C);


	}
     
}

void BigModDiv(BigInt *A, BigInt *B, BigInt *C) { //|c|=|a|/|b|
	BigInt ost;
	BigInt tmp;
	BigInt tmp2;
	int razr = 0;
	int r = 0;
	(C->nums) = (int*)calloc((A->size), sizeof(int));
	(C->size) = A->size;
	tmp.nums = (int*)calloc(1, sizeof(int));
	tmp.size = 1;
	(tmp.nums)[0] = (A->nums)[0];
	for (int i = 0; i < (A->size); i++) {
		razr = 0;
		tmp2.nums = (int*)calloc(1, sizeof(int));
		tmp2.size = 1;

		while (SravnMod(&tmp, &tmp2)!= 2) {
			BigModMinus(&tmp, &tmp2, &ost);
			DeleteNULLS(&ost);
			tmp2.nums = (int*)calloc(((B->size) + 1), sizeof(int));
			tmp2.size = (B->size) + 1;
			razr++;
			   
			   if (razr != 10) {

                     r = 0;
				   for (int j = (B->size) - 1; j >= 0; j--) {
					   (tmp2.nums)[j + 1] = razr * (B->nums)[j] + r;
					   if ((tmp2.nums)[j + 1] > 10) {
						   r = (tmp2.nums)[j + 1] / 10;
						   (tmp2.nums)[j + 1] = (tmp2.nums)[j + 1] % 10;
					   }
					   else {
						   r = 0;
					   }
				   }
				   (tmp2.nums)[0] = (tmp2.nums)[0] + r;
			   }
			   else {
				   tmp2.nums = (int*)malloc( ((B->size) + 1)* sizeof(int));
				   for (int f = 0; f < (B->size); f++) {
					   (tmp2.nums)[f] = (B->nums)[f];
				   }
				   tmp2.size = (B->size) + 1;
				   (tmp2.nums)[tmp2.size - 1] = 0;
				   r = 0;
			   }
				DeleteNULLS(&tmp2);
				
		}
		//PrintBigInt(&tmp2);
		(C->nums)[i] = razr - 1;
		tmp = ost;
		tmp.nums = (int*)realloc(tmp.nums,((tmp.size)+1)* sizeof(int));
		tmp.size = tmp.size+ 1;
		
		(tmp.nums)[tmp.size - 1] = (A->nums)[i+1];
		//PrintBigInt(&tmp);
		DeleteNULLS(&tmp);
		

	}

}

void BigPlus(BigInt *A, BigInt *B, BigInt *C) {
	if ((A->zn) == (B->zn)) {
		BigModPlus(A, B, C);
		(C->zn) = (A->zn);
	}
	else {
		int bol = SravnMod(A, B);
		if (bol == 3) { 
			(C->zn) = 0; 
			(C->nums) = (int*)calloc(1, sizeof(int));
			(C->size) = 1;
		} else 
		    if (bol == 2){//B>A
			(C->zn) = (B->zn);
			BigModMinus(B, A, C);
		    } else
		          if (bol == 1) {//A>B
					(C->zn) = (A->zn);
					BigModMinus(A, B, C);
				  }
	}
	DeleteNULLS(C);

}

void BigMinus(BigInt *A, BigInt *B, BigInt *C) {
	if ((B->zn) == 0) {
		(B->zn) = 1;
	}
	else B->zn = 0;
	BigPlus(A, B, C);
	if ((B->zn) == 0) {
		(B->zn) = 1;
	}
	else B->zn = 0;

}

void BigMultiply(BigInt *A, BigInt *B, BigInt *C) {
	if ((A->zn) == (B->zn)) {
		C->zn = 0;
	}
	else C->zn = 1;
	BigModMultiply(A, B, C);
	DeleteNULLS(C);
}

void BigDiv(BigInt *A, BigInt *B, BigInt *C) {
	if (((B->size) == 1) && ((B->nums)[0] == 0)) {
		printf_s("ERROR: div 0!");
		exit(1);

	}
	if ((A->zn) == (B->zn)) {
		C->zn = 0;

	}
	else C->zn = 1;
	BigModDiv(A, B, C);
	DeleteNULLS(C);
}
void FreeInt(BigInt* A) {
	free(A->nums);
}
