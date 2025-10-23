#include "ClipboardCopyHelper.h"

ClipboardCopyHelper::ClipboardCopyHelper() {
	stringToCopy = "";
	stringSize = 0;
}

ClipboardCopyHelper::ClipboardCopyHelper(std::string d_stringToCopy) {
	stringToCopy = d_stringToCopy;
	stringSize = d_stringToCopy.size();
}

void ClipboardCopyHelper::Copy() {
	if (!OpenClipboard(NULL)) {
		std::cout << "Failed to open clipboard." << std::endl;
		return;
	}

	if (!EmptyClipboard()) {
		std::cout << "Failed to empty clipboard." << std::endl;
		CloseClipboard();
		return;
	}

	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, (this->stringSize + 1) * sizeof(char));
	if (!hg) {
		std::cerr << "Failed to allocate global memory." << std::endl;
		CloseClipboard();
		return;
	}


	char* buffer = static_cast<char*>(GlobalLock(hg));
	if (!buffer) {
		std::cerr << "Failed to lock global memory." << std::endl;
		GlobalFree(hg);
		CloseClipboard();
		return;
	}
	strcpy_s(buffer, this->stringSize + 1, this->stringToCopy.c_str()); // Use strcpy_s for security
	GlobalUnlock(hg);

	if (!SetClipboardData(CF_TEXT, hg)) {
		std::cerr << "Failed to set clipboard data." << std::endl;
		GlobalFree(hg); // Free memory if SetClipboardData fails
		CloseClipboard();
		return;
	}

	// Close the clipboard
	if (!CloseClipboard()) {
		std::cerr << "Failed to close clipboard." << std::endl;
		return;
	}

	std::cout << "Text copied to clipboard successfully!" << std::endl;
}