#include "logic.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

logic::logic() {}

void logic::loadWordsFromFile(const std::string& filename) {
	std::ifstream file(filename);
	std::string word;

	while (file >> word) {
		if (word.length() >= 4 && word.length() <= 5) {
			list1.push_back(word);
		}
		else if (word.length() >= 6 && word.length() <= 7) {
			list2.push_back(word);
		}
		else if (word.length() >= 8) {
			list3.push_back(word);
		}
	}
	
	file.close();
}