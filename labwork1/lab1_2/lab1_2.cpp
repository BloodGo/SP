
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <tchar.h>

const int Byte = 2048;

using namespace std;


void ANSIToUnicode(HANDLE ReadF, HANDLE WriteF);
void UnicodeToANSI(HANDLE ReadF, HANDLE WriteF);
HANDLE ReadF;
HANDLE WriteF;
void GetError();

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RUSSIAN");
    if (argc == 3) {
         if (strcmp(argv[2], "-u") == 0 || strcmp(argv[2], "-a") == 0) {
            ReadF = CreateFileA(argv[1],
                GENERIC_READ,
                FILE_SHARE_READ,
                NULL,
                OPEN_EXISTING,
                FILE_ATTRIBUTE_NORMAL,
                NULL);
            if (ReadF == INVALID_HANDLE_VALUE) {
                cout << "Error input file : "; GetError(); return 0;
            }
            WriteF = CreateFile(L"Out.txt",
                GENERIC_WRITE,
                FILE_SHARE_WRITE,
                NULL,
                CREATE_ALWAYS,
                FILE_ATTRIBUTE_NORMAL,
                NULL);
            if (WriteF == INVALID_HANDLE_VALUE) {
                cout << "Error out file: "; GetError(); return 0;
            }
            switch (argv[2][1])
            {
            case 'u':
                UnicodeToANSI(ReadF, WriteF);
                break;
            case 'a':
                ANSIToUnicode(ReadF, WriteF);
                break;
            default:
                cout << "Key is wrong:  " << argv[2];
                break;
            }
            CloseHandle(ReadF);
            CloseHandle(WriteF);
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


void ANSIToUnicode(HANDLE ReadF, HANDLE WriteF)
{
    BYTE buffer[Byte];
    DWORD dwBytes;

    while (ReadFile(ReadF, buffer, Byte, (LPDWORD)&dwBytes, NULL))
    {
        if (dwBytes == 0)
            break;

        int uLength = MultiByteToWideChar(CP_UTF8, 0, (LPCCH)buffer, dwBytes, NULL, 0);
        wchar_t* uStr = (wchar_t*)calloc(uLength, sizeof(wchar_t));

        MultiByteToWideChar(CP_UTF8, 0, (LPCCH)buffer, dwBytes, uStr, uLength);

        if (!WriteFile(WriteF, uStr, uLength * sizeof(wchar_t), (LPDWORD)&dwBytes, NULL)) {
            printf("Error of encoding");
            break;
        }
    }
    printf("completed");
}

void UnicodeToANSI(HANDLE InF, HANDLE OutF)
{
    BYTE buffer[Byte];
    DWORD dwBytes;

    while (ReadFile(InF, buffer, Byte, (LPDWORD)&dwBytes, NULL))
    {
        if (dwBytes == 0)
            break;

        int uLength = MultiByteToWideChar(CP_UTF8, 0, (LPCCH)buffer, dwBytes, NULL, 0);
        wchar_t* uStr = new wchar_t[uLength];
        MultiByteToWideChar(CP_UTF8, 0, (LPCCH)buffer, dwBytes, uStr, uLength);

        int aLength = WideCharToMultiByte(CP_ACP, 0, uStr, uLength, NULL, 0, NULL, NULL);
        char* aStr = (char*)calloc(aLength, sizeof(char));

        WideCharToMultiByte(CP_ACP, 0, uStr, uLength, aStr, aLength, NULL, NULL);

        if (!WriteFile(OutF, aStr, aLength * sizeof(char), &dwBytes, NULL)) {
            printf("Error of encoding");
            break;
        }
    }
    printf("completed");
}
