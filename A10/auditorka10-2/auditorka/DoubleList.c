#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <string.h>


char* name;
int bul=0;

VOID PrintModuleList(HANDLE CONST hStdOut, DWORD CONST dwProcessId) {
	MODULEENTRY32 meModuleEntry;
	TCHAR szBuff[1024];
	DWORD dwTemp;
	HANDLE CONST hSnapshot = CreateToolhelp32Snapshot(
		TH32CS_SNAPMODULE, dwProcessId);
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return;
	}

	meModuleEntry.dwSize = sizeof(MODULEENTRY32);
	Module32First(hSnapshot, &meModuleEntry);
	do {
	wsprintf(szBuff, "  ba: %08X, bs: %08X, %s\r\n",
			meModuleEntry.modBaseAddr, meModuleEntry.modBaseSize,
			meModuleEntry.szModule);
		
	} while (Module32Next(hSnapshot, &meModuleEntry));

	CloseHandle(hSnapshot);
}

VOID PrintProcessList(HANDLE CONST hStdOut) {
	PROCESSENTRY32 peProcessEntry;
	TCHAR szBuff[1024];
	DWORD dwTemp;
	HANDLE CONST hSnapshot = CreateToolhelp32Snapshot(
		TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return;
	}

	peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &peProcessEntry);
	do {
		wsprintf(szBuff, "=== %08X %s ===\r\n",
			peProcessEntry.th32ProcessID, peProcessEntry.szExeFile);
		if (strcmp((peProcessEntry.szExeFile), name) == 0) {
			bul++;
			}
		//WriteConsole(hStdOut, szBuff, lstrlen(szBuff), &dwTemp, NULL);
		PrintModuleList(hStdOut, peProcessEntry.th32ProcessID);
	} while (Process32Next(hSnapshot, &peProcessEntry));
	if (bul > 1) {
			printf_s("Error: program is working");
			system("pause");
			exit(1);
	}
	CloseHandle(hSnapshot);
}

int main(int argc, char* argv[]) {
	int c = (strlen(argv[0]))+1;
    name = (char*)malloc(sizeof(char));
	int len = 0;
		for (int i = 0; i < c; i++) {
			if (((argv[0])[i]) != 92) {
				len++;
				name = (char*)realloc(name, len*sizeof(char));
				name[len - 1] = (argv[0])[i];

			}
			else len = 0;
        }

	
	HANDLE CONST hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	

	PrintProcessList(hStdOut);
	printf_s("ok");
	system("pause");
	ExitProcess(0);
	
}