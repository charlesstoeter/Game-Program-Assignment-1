#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>



class logic
{
	
public:
	logic(); //constructor

	void loadDictionary(); //load dictionary from file
	void scrambleWord(const std::string& word); //scramble a word
	void checkAnswer(const std::string& answer); //check player's answer
	void nextRound(); //proceed to the next round


private:
	std::vector<std::string> list1; //4-5 letter words
	std::vector<std::string> list2; //6-7 letter words
	std::vector<std::string> list3; //8+ letter words
	std::vector<std::string> scrambledWords; 
	std::vector<std::string> correctWords; 
	int score = 0; 
	int round = 1; 

};

logic::logic() {
	loadDictionary();
}

void logic::loadDictionary() {
	std::ifstream file("dictionary.txt");
	if (!file) {
		std::cerr << "Error opening dictionary file.\n";
		return -1;
	}
	
}

