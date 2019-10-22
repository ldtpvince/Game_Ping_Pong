#include "Ball.h"
#include "Random.h"
#include "Player.h"
#include "graphics.h"

Ball::Ball(Board board) {
	Random* r = Random::getInstance();
	
	// fix position in the future
	position.x = defaultWidth/2 + 10;
	position.y = defaultHeight/2 - 5;
	
	// 0 for negative vec.x, 1 for positive vec.x
	// 0 for negative vec.y, 1 for positive vec.y

	int binomRandom1 = r->getRandomVal(0, 1);
	int binomRandom2 = r->getRandomVal(0, 1);

	// random the value of vec.x
	vec.x = (double)r->getRandomVal(1, 9) / 10;

	// calculate the vec.y
	vec.y = sqrt(1 - vec.x * vec.x);

	speed = 10;
}

void Ball::drawBall() {
	// set ball color
	setfillstyle(SOLID_FILL, WHITE);
	// draw shape
	circle(position.x, position.y, radius);
}

void Ball::move() {
	position.x += (int)floor(vec.x * speed);
	position.y += (int)floor(vec.y * speed);

	
}

bool Ball::hasCollision(Board board) {
	Point anchorPointLeft = board.getPoint1();
	Point anchorPointRight = board.getPoint2();
	int boardHeight = board.getHeight();
	int boardWidth = board.getWidth();

	// calculate limit position for the ball 
	// count from the center of the ball
	int limitTop = anchorPointLeft.y;
	int limitBottom = anchorPointLeft.y + boardHeight - Player::height;
	int limitLeft = anchorPointLeft.y + Player::boardDistance;
	int limitRight = anchorPointRight.y - Player::boardDistance - boardWidth;


	return true;
}