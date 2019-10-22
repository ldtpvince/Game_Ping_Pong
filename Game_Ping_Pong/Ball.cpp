#include "Ball.h"
#include "Random.h"
#include "Player.h"
#include "graphics.h"

Ball::Ball(Board board) {
	Random* r = Random::getInstance();
	
	position.x = board.getWidth() / 2;
	position.y = board.getHeight() / 2;

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
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	// draw shape
	circle(position.x, position.y, radius);
}