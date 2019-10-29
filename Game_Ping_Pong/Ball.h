#pragma once
#include "Point.h"
#include "Vector.h"
#include "Board.h"
#include "Player.h"

class Ball
{
private:
	// vec length == 1
	Vector vec;
	int speed;
	const int radius = 15;
	int limitTop;
	int limitBottom;
	int limitLeft;
	int limitRight;
public:
	Point position;

	Ball(Board& board, Player1& player1, Player2& player2);

	void drawBall();
	void move();

	int hasCollision(const Board& board, Player1& player1, Player2& player2);
	void collisionBoard();
	void collisionPlayer();
	void resetState(const Board& board);
};

