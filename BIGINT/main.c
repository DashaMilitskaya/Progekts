#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Rus");

	if (FileErrorInput(argv[1]) == 1) {
		system("pause");
		exit(1);
	}
	if (FileErrorInput(argv[2]) == 1) {
		system("pause");
		exit(1);
	}

	BigInt A, B;
	FILE *fA, *fB;
	fopen_s(&fA, argv[1], "r");
	fopen_s(&fB, argv[2], "r");
	readBIGINt(fA, &A);
	PrintBigInt(&A);
	readBIGINt(fB, &B);
	PrintBigInt(&B);

	BigInt C;
	//BigModPlus(&A,&B,&C);
	//PrintBigInt(&C);
	//DeleteNULLS(&C);
	//PrintBigInt(&C);
	//BigModMinus(&A, &B, &C);
	//PrintBigInt(&C);
	/* DeleteNULLS(&C);
	PrintBigInt(&C);
	printf_s("%d\n", SravnMod(&A, &B));

	BigModMultiply(&A, &B, &C);
	PrintBigInt(&C);
	BigModDiv(&A, &B, &C);*/
	BigPlus(&A, &B, &C);
	printf("\n C=A+B= \n");
	PrintBigInt(&C);

	BigMinus(&A, &B, &C);
	printf("\n C=A-B= \n");
	PrintBigInt(&C);

	BigMultiply(&A, &B, &C);
	printf("\n C=A*B= \n");
	PrintBigInt(&C);

	BigDiv(&A, &B, &C);
	printf("\n C=A/B= \n");
	PrintBigInt(&C);

	FreeInt(&A);
	FreeInt(&B);
	FreeInt(&C);
	system("pause");
	return 0;
}