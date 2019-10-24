#include "graphics.h"
#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "Ball.h"
#include "Random.h"
#include "gameWindow.h"
#include <Windows.h>
#pragma comment(lib, "graphics.lib")
using namespace std;

// test

void test(char c) {
	cout << c << endl;
}
int main() {
	int gd = DETECT, gm;
	char nameGame[] = "Game Ping Pong";
	initwindow(900, 600, nameGame);

	gameWindow game;
	game.runGame();

	cin.ignore();
	closegraph();
	Random* r = Random::getInstance();
	delete r;
}