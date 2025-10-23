#pragma once
#include<string>
#include<iostream>
#include<Windows.h>


class ClipboardCopyHelper {
private:
	std::string stringToCopy;
	size_t stringSize;

public:
	ClipboardCopyHelper();

	ClipboardCopyHelper(std::string d_stringToCopy);

	void Copy();
	
};