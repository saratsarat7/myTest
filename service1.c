#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

#define BUF_SIZE 256
TCHAR szName[]=TEXT("Global\\MyFileMappingObject");
// TCHAR szMsg[]=TEXT("Message from first process."); // Not needed as we are assigning the data from file here.

static char statFilename[]	= "stat_serv_file.dsg";

int _tmain()
{
   HANDLE hMapFile;
   LPCTSTR pBuf;
   
   // begenning of our static file read.
	FILE * staticFp;
	staticFp = fopen (statFilename, "rb");
	fseek(staticFp, 0, SEEK_END);
	int lengthOfFile = ftell(staticFp);
	fseek(staticFp, 0, SEEK_SET);
	char *ptr;
	ptr = (char*) calloc(1,lengthOfFile*sizeof(char));
	fread(ptr,lengthOfFile,1,staticFp);
	fclose(staticFp);
   // ending of our static file read.

   hMapFile = CreateFileMapping(
                 INVALID_HANDLE_VALUE,    // use paging file
                 NULL,                    // default security
                 PAGE_READWRITE,          // read/write access
                 0,                       // maximum object size (high-order DWORD)
                 BUF_SIZE,                // maximum object size (low-order DWORD)
                 szName);                 // name of mapping object

   if (hMapFile == NULL)
   {
      _tprintf(TEXT("Could not create file mapping object (%d).\n"),
             GetLastError());
      return 1;
   }
   pBuf = (LPTSTR) MapViewOfFile(hMapFile,   // handle to map object
                        FILE_MAP_ALL_ACCESS, // read/write permission
                        0,
                        0,
                        BUF_SIZE);

   if (pBuf == NULL)
   {
      _tprintf(TEXT("Could not map view of file (%d).\n"),
             GetLastError());

       CloseHandle(hMapFile);

      return 1;
   }


   // CopyMemory((PVOID)pBuf, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));
   // We are using the file data here.
   CopyMemory((PVOID)pBuf, ptr, (lengthOfFile * sizeof(char)));
    _getch();

   UnmapViewOfFile(pBuf);

   CloseHandle(hMapFile);

   return 0;
}