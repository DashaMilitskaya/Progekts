#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

char* ReadFromConsol() {
	int i = 1;
	int number = 0;
	int symbol = 0;

	char* mass = (char*)malloc(i * sizeof(char));
	while (1) {
		mass[i-1] = getch();
		if ((mass[i-1] == 8) && (i > 0)) { //8 is the code of backspace
			i--;
			printf("\b \b");
			mass = (char*)realloc(mass, i * sizeof(char));
		}
		else {
			if ((mass[i-1] != 8)) {
				if ((mass[i - 1] < 58) && (mass[i - 1] > 47)) {
					number++;
				}
				if ((mass[i - 1] < 39) && (mass[i - 1] > 32)) {
					symbol++;
				}
				if (mass[i - 1] != 13){
				printf("*");
				}
				else {
					printf("\n");
			      mass[i-1] = '\0';
				  if ((i > 6) && (number>0)&&(number<4)&&(symbol>0)) {
					  printf_s("safe");
				  }
				  else
				  {
					  printf_s("not safe");
				  }
			         break;

				}
				i++;
				mass = (char*)realloc(mass, i * sizeof(char));
			}
		}

	}
	return mass;
}

int main() {
	printf("\n \n password must have one or more special-symbol:! * # $ % &  and 1-3 of numbers(1 2 3 4 5 6 7 8 9 0) and  6 or more symbols \n \n ");
	char* pas= ReadFromConsol();

	printf("\n \n \n \n password: ");

		printf_s("%s", pas);

	
	free(pas);
	system("pause");
	return 0;

}