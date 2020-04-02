#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Rus");
	
	int todo;
	printf_s("¬ведите 1 чтобы считать им€ фаила из параметров main \n");
	printf_s("¬ведите 2 чтобы считать им€ фаила из консоли \n");
	printf_s("¬ведите 3 чтобы считать им€ фаилов из файла \n");
	scanf_s("%d", &todo);

	if (todo == 1) {
		if (FileErrorInput(argv[1]) == 1) {
			system("pause");
			exit(1);
		}
    book text;
	FILE *f;
    fopen_s(&f, argv[1], "r");
    InputBookFromFile(f, &text);
	SortText(&text);
	OutputBookToConsol(&text);
	FreeMemory(&text);
	fclose(f);
    } else
		if (todo == 2) {
			book text;
			FILE *f;
			char tmp;
			scanf_s("%c", &tmp, 1);
			char* fname = ReadFNameFromConsol();
			if (FileErrorInput(fname) == 1) {
				system("pause");
				exit(1);
			}
			fopen_s(&f, fname, "r");
			InputBookFromFile(f, &text);
			SortText(&text);
			OutputBookToConsol(&text);
			FreeMemory(&text);
			fclose(f);
			free(fname);

		}else
			if (todo == 3) {
				book text;
				book* text2;
				FILE *f, *names;
				char tmp;
				scanf_s("%c", &tmp, 1);
				char* fname = ReadFNameFromConsol();


				if (FileErrorInput(fname) == 1) {
					system("pause");
					exit(1);
				}
				fopen_s(&names, fname, "r");
				InputBookFromFile(names, &text);
				OutputBookToConsol(&text);
				text2 = (book*)malloc(sizeof(book)*(text.strok));
				for (int i = 0; i < (text.strok); i++) {
					((text.mas)[i]) =  (char*)realloc(((text.mas)[i]), (((text.elstr)[i])+1) * sizeof(char));
					((text.mas)[i][((text.elstr)[i])])= '\0';
					if (FileErrorInput(((text.mas)[i])) == 1) {
						system("pause");
						exit(1);
					}
					fopen_s(&f, ((text.mas)[i]), "r");
					InputBookFromFile(f, &(text2[i]));
					SortText(&(text2[i]));
					OutputBookToConsol(&(text2[i]));
					FreeMemory(&(text2[i]));
					fclose(f);
				}

				FreeMemory(&text);
				free(fname);
				fclose(names);
			}
			else
				printf_s("error number input");
	


	
    system("pause");
	return 0;
}