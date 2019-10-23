#include "Player.h"

int Player::height = 60;
int Player::width = 20;
int Player::boardDistance = 10;

//constructor class Player
Player::Player(int x, int y) {
	drawPlayer(x, y);
}

//draw player
void Player::drawPlayer(int x, int y) {
	//set color
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	//set position
	int left = x, top = y;
	int right = left + width, bottom = top + height;
	//draw shape
	bar(left, top, right, bottom);
}

//constructor class Player1
Player1::Player1(Point p, int h) {
	//set position
	x = p.x + boardDistance;
	y = p.y + (h - height) / 2;
	//set restricted range of movement
	limitTop = p.y;
	limitBottom = p.y + h - height;
	//draw player
	Player(x, y);
}

//constructor class Player2
//it is the same as constructor Player1
Player2::Player2(Point p, int h) {
	x = p.x - boardDistance - width;
	y = p.y + (h - height) / 2;
	limitTop = p.y;
	limitBottom = p.y + h - height;
	Player(x, y);
}

