#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
char* sett(struct tm* u)
{
	char s[40];
	char* tmp;
	for (int i = 0; i < 40; i++) s[i] = 0;
	int length = strftime(s, 40, "%d.%m.%Y", u);
	tmp = (char*)malloc(sizeof(s));
	strcpy(tmp, s);
	return(tmp);
}
int main() {
	setlocale(LC_ALL, "Rus");
	char buffer[267];
	DWORD size;
	size = sizeof(buffer);
	GetUserName(&buffer, &size);
	printf("Username : ");
	
	printf("%s", buffer);
	
	printf("\n");
	char buffer1[267];
	DWORD size1;
	size1 = sizeof(buffer1);
	GetComputerName(&buffer1, &size1);
	printf("Computername : ");
	
	printf("%s", buffer1);
		
	printf("\n");
	long ttime;
	ttime = time(NULL);
	ttime = ttime - (ttime / 365 / 24 / 3600) * 365 * 24 * 3600;
	ttime = ttime - (ttime / 24 / 3600) * 24 * 3600;
	printf("Time : %d:%d\n", ttime / 3600 + 5, (ttime - ttime / 3600 * 3600) / 60);
	const time_t timer = time(NULL);
	struct tm* u;
	char* f;
	u = localtime(&timer);
	f = sett(u);
	printf("Date : %s", f);
	system("pause");
	return 0;

}