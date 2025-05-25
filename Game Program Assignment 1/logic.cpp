#include "logic.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <allegro5/allegro.h>

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

void logic::play(int secondsPassedSoFar) {
	correctWords.clear();

	std::cout << "\nWord Unscrambler Game\n";
	std::cout << "You have 60 seconds total to guess all the words.\n\n";

	// Create a local Allegro timer to track time inside play()
	ALLEGRO_TIMER* timer = al_create_timer(1.0); // 1-second interval
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	int secondsPassed = secondsPassedSoFar;

	for (size_t i = 0; i < scrambledWords.size(); ++i) {
		if (secondsPassed >= 60) {
			std::cout << "\nTime's up!\n";
			break;
		}

		// Prompt and input
		std::cout << "Scrambled Word #" << (i + 1) << ": " << scrambledWords[i] << "\n";
		std::cout << "You have " << (60 - secondsPassed) << " seconds left.\n";
		std::cout << "Your guess: ";

		std::string guess;

		
		std::cin >> guess;

	
		ALLEGRO_EVENT event;
		while (al_get_next_event(queue, &event)) {
			if (event.type == ALLEGRO_EVENT_TIMER) {
				secondsPassed++;
			}
		}

		if (secondsPassed >= 60) {
			std::cout << "\nTime's up!\n";
			break;
		}

		
		if (guess == selectedWords[i]) {
			std::cout << "Correct!\n\n";
			correctWords.push_back(guess);
		}
		else {
			std::cout << "Incorrect. The correct word was: " << selectedWords[i] << "\n\n";
		}
	}

	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
}

void logic::showResults() {
	int score = static_cast<int>(correctWords.size());

	std::cout << "\n\n";
	std::cout << "         Game Results         \n";
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

