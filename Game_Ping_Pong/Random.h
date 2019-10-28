#pragma once
#include "time.h"
#include <iostream>

class Random
{
private:
	static Random* instance;
	Random();
public:
	~Random();

	static Random* getInstance();
	int getRandomVal(int min, int max);
};

