#include <iostream>
#include <memory>
#include <string>
#include <format>

#include "force_delete.h"

#include <Windows.h>
#include <winternl.h>


int wmain(int argc, wchar_t* argv[]) {
	/* ensure user isnt silly */
	if (argc <= 1) {
		return 0;
	}

	auto Driver = CForceDelete();

	/* delete all filepaths passed :D */
	for (auto i = 1; i < argc; ++i) {
		std::wstring wsFilePath{ std::format(L"\\DosDevices\\{}", argv[i]) };
	
		/* delete file :D  */
		if (!Driver.DoThingy(wsFilePath.c_str(), wsFilePath.size() * 2)) {
			
		}
	}

	return 0;
}