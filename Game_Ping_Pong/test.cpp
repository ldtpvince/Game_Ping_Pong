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

int main() {
	char nameGame[] = "Game Ping Pong";
	initwindow(defaultWidth, defaultHeight, nameGame);

	gameWindow game;
	game.runGame();


	return 0;
}