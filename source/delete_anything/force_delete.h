#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#undef WIN32_LEAN_AND_MEAN


// sorry, this project was originally c but i figured i quickly make it cpp 
// i dont feel like cleaning up this code and making it look nice, :(
// 
class CForceDelete {
public:
	CForceDelete() {
		HANDLE hFile = CreateFileW(
			L"\\\\.\\IUForceDelete123",
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL
		);

		if (hFile == INVALID_HANDLE_VALUE) {
			MessageBoxW(NULL, L"CreateFileW Failed", L"DeleteAnything", MB_OK | MB_ICONERROR);
			ExitProcess(EXIT_FAILURE);
		}

		m_hFile = hFile;
	}

	~CForceDelete() {
		if(m_hFile)
		CloseHandle(m_hFile);
	}

	bool DoThingy(PCWSTR wcFileName, DWORD dwNameLen) {
		DWORD dwOutputBuffer = 0; // char[4]
		DWORD dwReturned = 0;
		if (!DeviceIoControl(m_hFile,
			0x8016E000ul,
			(LPVOID)wcFileName,
			dwNameLen,
			&dwOutputBuffer,
			sizeof(dwOutputBuffer),
			&dwReturned,
			NULL
		)) {
			return false;
		}

		return true;
	}

private:
	HANDLE m_hFile{};
};
