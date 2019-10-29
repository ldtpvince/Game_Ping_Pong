#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <dos.h>
#include "graphics.h"
#include <time.h>
#include "Board.h"

#pragma comment(lib, "graphics.lib")
using namespace std;

class Player
{
protected:
	int x, y;//position
	static int height, width;//size of player
	int score = 0;
	static int boardDistance;//it is a distance from edge of board to player
	int speed = 15;//how fast player move
	//avoid player to move out of range
	int limitTop;//restricted top
	int limitBottom;//restricted bottom
public:
	Player(int x, int y);
	Player() {};
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getScore() {
		return score;
	}
	void setScore() {
		score = score + 1;
	}

	void drawPlayer(int x, int y);
	//decrement position
	void moveUp() {
		y -= speed;
	}
	//increment position
	void moveDown() {
		y += speed;
	}
};

//Class Player1 and Class Player 2 is inheritances from Class Player
// they are no longer differrent, maybe a little bit

class Player1 :public Player {
public:
	Player1(Board& board);
	void moveUP() {
		if (y - speed >= limitTop)
			Player::moveUp();
	}
	void moveDown() {
		if (y + speed <= limitBottom)
			Player::moveDown();
	}
	int getScore() {
		return Player::getScore();
	}
	void setScore() {
		Player::setScore();
	}
	void draw() {
		Player::drawPlayer(x, y);
	}

	friend class Ball;
};

class Player2 : public Player {
public:
	Player2(Board& board);
	void moveUP() {
		if (y - speed >= limitTop)
			Player::moveUp();
	}
	void moveDown() {
		if (y + speed <= limitBottom)
			Player::moveDown();
	}
	int getScore() {
		return Player::getScore();
	}
	void setScore() {
		Player::setScore();
	}
	void draw() {
		Player::drawPlayer(x, y);
	}

	friend class Ball;
};