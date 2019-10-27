#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Board.h"
#include "Player.h"
#include "Ball.h"
#include <stdlib.h>


class gameWindow
{
	Board board;
	Player1 player1;
	Player2 player2;
	Ball ball;
	const int scoreWiner = 5;//Score of Winner
	bool exitFlag;
public:
	gameWindow();
	void runGame();
	void drawScorePlayer1();
	void drawScorePlayer2();
	void drawInstruction();
	void drawTitle();
	void pauseGame();
	int winner();
	void drawResult(int);

	// test using thread
	/*void testPlayer1();
	void testPlayer2();*/
};


