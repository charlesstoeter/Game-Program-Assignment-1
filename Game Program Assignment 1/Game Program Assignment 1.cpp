#include "logic.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>



//main 
int main() {
	if (!al_init()) { // Initialize Allegro
		std::cerr << "Failed to initialize Allegro." << std::endl;
		return -1; 
	}

	ALLEGRO_TIMER* timer = al_create_timer(1.0); // Create a timer with 1 second intervals
	if (!timer) {
		std::cerr << "Failed to create timer." << std::endl;
		return -1;
	}
	

	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue(); // Creating an event queue
	if (!event_queue) {
		std::cerr << "Failed to create event queue." << std::endl;
		al_destroy_timer(timer);
		return -1;
	}


	al_register_event_source(event_queue, al_get_timer_event_source(timer)); //registering the timer event source

	logic game;
	game.loadWordsFromFile("dictionary.txt"); // Load words from the file
	game.selectRandomWords(); // Select random words from the loaded lists
	game.scrambleWords(); // Scramble the selected words

	//starts the timer
	al_start_timer(timer);

	

	game.play(0);


	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	game.showResults();

	return 0;
}


