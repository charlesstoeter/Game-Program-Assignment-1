#include "logic.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>

logic::logic() {}

void logic::loadWordsFromFile(const std::string& filename) {
	std::ifstream file(filename);
	std::string word;

	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filename << std::endl;
		return;
	}

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

void logic::selectRandomWords() {
	srand(static_cast<unsigned int>(time(0))); // Seed 
	for (int i = 0; i < 2 && list1.size() >= 2; i++) {
		int index = rand() % list1.size();
		selectedWords.push_back(list1[index]);
		list1.erase(list1.begin() + index); //this prevents any duplications
	}

	for (int i = 0; i < 2 && list2.size() >= 2; i++) {
		int index = rand() % list2.size();
		selectedWords.push_back(list2[index]);
		list2.erase(list2.begin() + index); // dupliccates
	}

	if (!list3.empty()) {
		int index = rand() % list3.size();
		selectedWords.push_back(list3[index]);
		list3.erase(list3.begin() + index); //this prevents any duplications
	}
}

void logic::scrambleWords() {
	std::random_device rd;
	std::mt19937 g(rd());

	scrambledWords.clear(); // this allows to start fresh

	for (const std::string& word : selectedWords) {
		std::string scrambled = word;

		std::shuffle(scrambled.begin(), scrambled.end(), g);
		while (scrambled == word && word.length() > 1) {
			std::shuffle(scrambled.begin(), scrambled.end(), g);
		}
	}
}

