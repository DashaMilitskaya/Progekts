#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int main(){

	int n = 15000;

	int* mas = (int*)malloc(n * sizeof(int));
	int* mas1 = (int*)malloc(n * sizeof(int));
	int* mas2 = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++){
	mas[i] = i;
	}

	mas[1] = 0;

	for (int t = 2; t < n; t++){
	if (mas[t] != 0){
		for (int j = t * 2; j < n; j += t){
			mas[j] = 0;
		}
	}
	}
	int z = 0;

	for (int i = 0; i < n; i++){
	if (mas[i] != 0){
		mas1[z] = mas[i];
		z++;
	}
	}

	int k;
	scanf_s("%d", &k);

	for (int i = 0; i < k; i++){
	scanf_s("%d", &mas2[i]);
	}

	for (int i = 0; i < k; i++){
	printf("%d\n", mas1[mas2[i] - 1]);
	}
	system("pause");
	return 0;

}