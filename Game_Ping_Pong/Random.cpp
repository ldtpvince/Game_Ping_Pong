#include "Random.h"
#include <time.h>

Random* Random::instance = NULL;

Random::Random() {
	srand(time(NULL));
}

Random::~Random() {
	delete instance;
}

// input: void
// output: Random*
// usage: to get the singleton object of Random class
Random* Random::getInstance() {
	if (instance == NULL) {
		instance = new Random();
	}
	return instance;
}

// input: int min, int max
// output: int
// usage: get a random value in the interval [min, max]
int Random::getRandomVal(int min, int max) {
	return rand() % (max - min + 1) + min;
}