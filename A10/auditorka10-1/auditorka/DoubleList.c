#include <windows.h>
#include <tlhelp32.h>

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
		WriteConsole(hStdOut, szBuff, lstrlen(szBuff), &dwTemp, NULL);
		PrintModuleList(hStdOut, peProcessEntry.th32ProcessID);
	} while (Process32Next(hSnapshot, &peProcessEntry));

	CloseHandle(hSnapshot);
}

int main(int argc, char* argv[]) {
	
	HANDLE CONST hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	PrintProcessList(hStdOut);
	system("pause");
	ExitProcess(0);
	
}