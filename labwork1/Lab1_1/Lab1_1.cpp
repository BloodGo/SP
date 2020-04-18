#include <iostream>
#include <fstream>
#include <Windows.h>
#include <tchar.h>
#include <locale.h>

    
using namespace std;

void GetError();


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "russian");
    if (argc == 2) {
        if (strcmp(argv[1], "-s") == 0) {
            SYSTEM_INFO si;
            GetSystemInfo(&si);
            printf("My system info :\n");
            printf("  Number of processors: %u\n", si.dwNumberOfProcessors);
            printf("  Page size: %u\n", si.dwPageSize);
            printf("  Processor type: %u\n", si.dwProcessorType);
            printf("  Minimum application address: %lx\n", si.lpMinimumApplicationAddress);
            printf("  Maximum application address: %lx\n", si.lpMaximumApplicationAddress);
            printf("  Active processor mask: %u\n", si.dwActiveProcessorMask);
            printf("  Active processor mask: %u\n", si.wProcessorLevel);
            printf("Memory info :\n");
            MEMORYSTATUS ms;
            GlobalMemoryStatus(&ms);
            printf("  RAM amount : %u\n", ms.dwTotalPhys);
            printf("  Available RAM : %u\n", ms.dwAvailPhys);
            printf("  The percentage of memory used : %u\n", ms.dwMemoryLoad);
            printf("  The total number of bytes of virtual memory used in the calling process : %u\n", ms.dwTotalVirtual);
            printf("  The amount of this memory still available to the calling process : %u\n", ms.dwAvailVirtual);
        }
        else if (strcmp(argv[1], "-e") == 0) {
            HLOCAL result = LocalAlloc(LHND, 5000000000000);
            if (result == NULL) {
                GetError();
            }
        }
        else {
            printf("Error key");
        }
       
    } 
    else {
        printf("Error argument");
    }
    return 0;
}

void GetError()
{
    HLOCAL lpMsg;
    DWORD errcode;
    errcode = GetLastError();
    FormatMessage(
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        errcode,
        MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
        ((LPTSTR)&lpMsg),
        0,
        NULL);
    wprintf((L"%s\n"), (LPTSTR)lpMsg);
    LocalFree(lpMsg);
}



