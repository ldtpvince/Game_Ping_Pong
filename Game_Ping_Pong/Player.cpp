#include "Player.h"

//constructor class Player
Player::Player(int x, int y) {
	drawPlayer(x, y);
}

//draw player
void Player::drawPlayer(int x, int y) {
	//set color
	setcolor(WHITE);
	setfillstyle(1, WHITE);
	//set position
	int left = x, top = y;
	int right = left + width, bottom = top + height;
	//draw shape
	bar(left, top, right, bottom);

}

//constructor class Player1
Player1::Player1(Point p, int h_) {
	//set position
	x = p.x + boardDistance;
	y = p.y + (h_ - height) / 2;
	//set restricted range of movement
	limitTop = p.y;
	limitBottom = p.y + h_ - height;
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

