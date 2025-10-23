#include<iostream>
#include<string>
#include<Windows.h>
#include"ClipboardCopyHelper.h"

std::string removeUnwantedChars(std::string);

int main(int argc, char* argv[]) {
	if (argc <= 2) {
		std::cout << "Usage: " << argv[0] << " <dirPrefix> [branch name]" << std::endl;
		return 1;
	}
	std::string dirPrefix = argv[1];
	std::string inputNameWithoutSpaces;
	for (int i = 2; i < argc; i++) {
		std::string temp = argv[i];
		std::string filteredString = removeUnwantedChars(temp);
		if(i== argc - 1)
			inputNameWithoutSpaces += filteredString;
		else
			inputNameWithoutSpaces += filteredString + '_';
	}
	std::string finalOutput = dirPrefix + '/' + inputNameWithoutSpaces;
	std::cout << finalOutput << std::endl;
	
	ClipboardCopyHelper clipboard(finalOutput);
	clipboard.Copy();
	
	return 0;
}

std::string removeUnwantedChars(std::string word) {
	std::string correctWord = "";
	for (int i = 0; i < word.size();i++) {
		const char ch = word[i];
		switch (ch) {
		case '/':
			break;
		case '~':
			break;
		case '^':
			break;
		case ':':
			break;
		case '*':
			break;
		case '[':
			break;
		case '?':
			break;
		case '.': {
			while (i < word.size() - 1 && word[i] == '.') {
				i++;
			}
			correctWord += word[i];
			break;
		default:
			correctWord += ch;
		}
		}
	}
	return correctWord;
}