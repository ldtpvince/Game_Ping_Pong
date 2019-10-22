#pragma once
#include "Point.h"
#include "Vector.h"
#include "Board.h"

class Ball
{
private:
	// vec length == 1
	Vector vec;
	int speed;
	const int radius = 15;
public:
	Point position;

	Ball(Board board);

	void drawBall();
	void move();

	bool isCollideBoard();
	bool isCollidePlayer();
	void collisionBoard();
	void collisionPlayer();
};

