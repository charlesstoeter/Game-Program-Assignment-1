#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>


int main()
{
    std::cout << "Hello Welcome to the Scrambling Game!\n";


    

	std::string word;
	std::vector<std::string> list1;
	std::vector<std::string> list2;
	std::vector<std::string> list3;


	while (file >> word) {
		if (word.length() >= 4 && word.length() <= 5) {
			list1.push_back(word);
		} else if (word.length() >= 6 && word.length() <= 7) {
			list2.push_back(word);
		} else if (word.length() >= 8) {
			list3.push_back(word);
		}
	}

	file.close();

	bool round = 1;




}