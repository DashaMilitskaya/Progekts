#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <io.h>

int main()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hf = FindFirstFile("***.txt", &FindFileData);
	if (hf != INVALID_HANDLE_VALUE)
	{
		do
		{
			FILE* fp;
			fopen_s(&fp, (FindFileData.cFileName), "r+");
			unsigned long long int size = ((FindFileData.nFileSizeHigh) * (MAXDWORD + 1)) + (FindFileData.nFileSizeLow);
			if (size > 20) {
				printf_s("%s\n", FindFileData.cFileName);
			}
			fclose(fp);
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
	system("pause");
	return 0;
	
}