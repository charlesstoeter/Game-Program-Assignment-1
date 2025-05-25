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
	

	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	if (!queue) {
		std::cerr << "Failed to create event queue." << std::endl;
		al_destroy_timer(timer);
		return -1;
	}

}


