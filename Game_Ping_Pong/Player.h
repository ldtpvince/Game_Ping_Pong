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
	int height = 60, width = 20;//size of player
	int score = 0;
	int boardDistance = 10;//it is a distance from edge of board to player
	int speed = 10;//how fast player move
	//avoid player to move out of range
	int limitTop;//restricted top
	int limitBottom;//restricted bottom
public:
	Player(int x, int y);
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
		score++;
	}

	Player() {
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
	Player1(Point p, int h_);
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
};

class Player2 : public Player {
public:
	Player2(Point p, int h_);
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
		return Player::setScore();
	}
	void draw() {
		Player::drawPlayer(x, y);
	}
};