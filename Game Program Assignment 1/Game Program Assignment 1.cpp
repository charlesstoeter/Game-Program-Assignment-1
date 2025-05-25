#include "logic.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

void * input(ALLEGRO_THREAD* ptr, void* arg);
void * timer(ALLEGRO_THREAD* ptr, void* arg);

logic game;

int main() {
    game.loadWordsFromFile("dictionary.txt");
    game.selectRandomWords();
    game.scrambleWords();
    game.play();
    game.showResults();

    return 0;
}

void* input(ALLEGRO_THREAD* ptr, void* arg) {
    bool finished = false;
}
