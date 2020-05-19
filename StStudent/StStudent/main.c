#include "lib.h"
#include <stdio.h>


int main(int argc, const char * argv[]) {

	if (FileErrorInput(argv[1]) == 1) {
		system("pause");
		exit(1);
	}

	if (FileErrorOutput(argv[2]) == 1) {
		system("pause");
		exit(1);
	}

	
	NewStList();//задаЄт новый список
	

	//GetStudentFromConsol(); // ввод с консоли
	
	FILE *f, *w, *d;
	fopen_s(&f, argv[1], "r");
	fopen_s(&w, argv[2], "w");
	fopen_s(&d, argv[3], "rb+");

	//GetStudentsFromDat(d);
	GetStudentsFromFiletxt(f); //добавлет студентов из TXT к существующему списку;

	PrintStList();//вывод в консоль

	printf_s("\n");
	printf_s("Input Some Group:");
	printf_s("\n");
	char* mygroup = ReadStringFromConsol();

	PrintGroup(mygroup); //выводит группу

	printf_s("\n");
	printf_s("Print Uspev.:");
	printf_s("\n");

	PrintUspev();//выводит успевающих


	WriteListToTxt(w);

	WriteListToDat(d);//сохран€ет список в бинарный файл


	NewStList();//задаЄт новый список
	GetStudentsFromDat(d);//добавл€ет студентов из бинарника(к существующему списку)
    printf_s("\n Print Dat: \n");
	PrintStList();

	printf_s("\n Input Familiy to delete: \n");
	char* Famil = ReadStringFromConsol();
    DeleteStWithSuName(Famil); //удаление по фамилии

	printf_s("\n Print after delete: \n");
	PrintStList();

	int num;
	printf_s("\n Input num to delete: \n");
	scanf_s("%d", &num);
	DeleteStWithNumber(num); //удаление по номеру
	printf_s("\n Print after delete: \n");
	PrintStList();

	DeleteNeusp();//удаление неуспевающих
	printf_s("\n Print after delete: \n");
	PrintStList();

	printf_s("\n Print Iv: \n");
	PrintIV();//¬ывод студентов с фамлией на Iv

	printf_s("\n ADD Random: \n");
	AddRandom();
	PrintStList();

	fclose(f);
	fclose(w);
	fclose(d);
	FreeStList();
	system("pause");
	return 0;
}