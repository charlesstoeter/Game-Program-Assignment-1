#include "logic.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>




int main() {
	if (!al_init()) {
		std::cerr << "Failed to initialize Allegro." << std::endl;
		return -1;
	}

	ALLEGRO_TIMER* timer = al_create_timer(1.0);
	if (!timer) {
		std::cerr << "Failed to create timer." << std::endl;
		return -1;
	}
	

	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	if (!event_queue) {
		std::cerr << "Failed to create event queue." << std::endl;
		al_destroy_timer(timer);
		return -1;
	}


	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	logic game;
	game.loadWordsFromFile("dictionary.txt");
	game.selectRandomWords();
	game.scrambleWords();

	//starts the timer
	al_start_timer(timer);

	int secondsPassed = 0;

	while (true) {
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		//if type statements
		if (event.type == ALLEGRO_EVENT_TIMER) {
			secondsPassed++;


			game.play(secondsPassed);
			break;
		}
	}


	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	game.showResults();

	return 0;
}


