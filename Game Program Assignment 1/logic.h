#pragma once
#include <vector>
#include <string>




class logic
{
	
public:
	logic(); //constructor

	void loadWordsFromFile(const std::string& filename);
	void selectRandomWords();
	void scrambleWords();
	void play();
	void showResults();


private:
	std::vector<std::string> list1; //4-5 letter words
	std::vector<std::string> list2; //6-7 letter words
	std::vector<std::string> list3; //8+ letter words
	std::vector<std::string> selectedWords;
	std::vector<std::string> scrambledWords; 
	std::vector<std::string> correctWords; 


};



