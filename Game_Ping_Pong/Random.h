#pragma once
#include "time.h"
#include <iostream>

class Random
{
private:
	static Random* instance;
	
	Random();
	~Random();
public:
	static Random* getInstance();
	int getRandomVal(int min, int max);
};

