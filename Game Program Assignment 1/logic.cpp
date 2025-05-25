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

		scrambledWords.push_back(scrambled);
	}

}

void logic::play() {
	std::cout << "Welcome to the Scrambling Game!\n";
	std::cout << "Unscramble the word. you have 60 seconds. you have one try per word. \n \n";

	correctWords.clear(); //clean slate

	for (size_t i = 0; i < scrambledWords.size(); i++) {
		std::cout << "Scrambled Word #" << (i + 1) << ": " << scrambledWords[i] << std::endl;
		std::cout << "Your guess: ";

		std::string guess;
		std::cin >> guess;


		if (guess == selectedWords[i]) {
			std::cout << "Correct! \n\n";
			correctWords.push_back(guess);
		}
		else {
			std::cout << "Incorrect. The correct word was " << selectedWords[i] << "\n\n";
		}
	}
}

void logic::showResults() {
	int score = static_cast<int>(correctWords.size());

	std::cout << "\n==============================\n";
	std::cout << "         Game Results         \n";
	std::cout << "==============================\n";
	std::cout << "Correct Answers: " << score << " out of 5\n";


	std::string level;
	
	if (score == 5) {
		level = "Genius!";
	}
	else if (score == 4) {
		level = "Smart!";
	}
	else if (score == 3) {
		level = "Average.";
	}
	else if (score == 2) {
		level = "Below Average.";
	}
	else {
		level = "Try Again!";
	}

	std::cout << "Your Intellect Level: " << level << "\n";


}

