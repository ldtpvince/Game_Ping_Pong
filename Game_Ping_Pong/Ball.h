#pragma once
#include "Point.h"
#include "Vector.h"
#include "Board.h"
#include "Player.h"

class Ball
{
private:
	Vector vec; // a vector with length 1 that guide the direction of the Ball
	int speed; // the moving speed of the Ball
	const int radius = 15; // the radius of the Ball
	int limitTop; // the top edge of the Board that the Ball cant pass
	int limitBottom; // the bottom edge of the Board that the Ball cant pass
	int limitLeft; // the left edge of the Board that the Ball cant pass
	int limitRight; // the right edge of the BOard that the Ball cant pass
public:
	Point position; // position of the Ball on the screen

	Ball(Board& board, Player1& player1, Player2& player2);

	void drawBall();
	void move();

	int hasCollision(const Board& board, Player1& player1, Player2& player2);
	void collisionBoard();
	void collisionPlayer();
	void resetState(const Board& board);
};

