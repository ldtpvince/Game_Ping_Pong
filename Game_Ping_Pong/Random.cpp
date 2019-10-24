#include "Random.h"
#include <time.h>

Random* Random::instance = NULL;

Random::Random() {
	srand(time(NULL));
}

Random::~Random() {
	delete instance;
}

Random* Random::getInstance() {
	if (instance == NULL) {
		instance = new Random();
	}
	return instance;
}

int Random::getRandomVal(int min, int max) {
	return rand() % (max - min + 1) + min;
}