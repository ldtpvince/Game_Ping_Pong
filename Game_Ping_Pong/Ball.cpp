#include "Ball.h"
#include "Random.h"
#include "Player.h"
#include "graphics.h"

Ball::Ball(Board board, Player1 player1, Player2 player2) {
	Random* r = Random::getInstance();
	
	// fix position in the future
	position.x = defaultWidth/2 ;
	position.y = defaultHeight/2 ;
	
	// 0 for negative vec.x, 1 for positive vec.x
	// 0 for negative vec.y, 1 for positive vec.y

	int binomRandom1 = r->getRandomVal(0, 1);
	int binomRandom2 = r->getRandomVal(0, 1);

	// random the value of vec.x
	vec.x = (r->getRandomVal(5, 9) / 10.0);
	if (binomRandom1 == 0) {
		vec.x = -vec.x;
	}

	// calculate the vec.y
	vec.y = sqrt(1 - vec.x * vec.x);
	if (binomRandom2 == 0) {
		vec.y = -vec.y;
	}

	speed = 10;

	// anchor point for the board
	Point anchorPointLeft(player1.getX(), player1.limitTop);
	Point anchorPointRight(player2.getX(), player2.limitBottom);
	int boardHeight = board.getHeight();
	int boardWidth = board.getWidth();

	// calculate limit position for the ball 
	// count from the center of the ball
	limitTop = anchorPointLeft.y + radius;
	limitBottom = anchorPointLeft.y + boardHeight - radius;
	limitLeft = anchorPointLeft.x + Player::width + radius;
	limitRight = anchorPointRight.x - radius;
}

void Ball::drawBall() {
	// set ball color
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	// draw shape
	//circle(position.x, position.y, radius);
	pieslice(position.x, position.y, 0, 360, radius);
}

void Ball::move() {
	position.x += (int)floor(vec.x * speed);
	position.y += (int)floor(vec.y * speed);
}

// input: board, player1, player2
// output: 1 if collision with player, 2 if collision with board, 0 if no collision
int Ball::hasCollision(Board board, Player1 player1, Player2 player2) {
	if ((position.x - limitLeft) <= 3) {
		int heightPlayerInterval = player1.getY() + Player::height;
		if (position.y >= player1.getY() && position.y <= heightPlayerInterval) {
			this->collisionPlayer();
			speed = speed * 1.1;
			return 1;
		}
		else {
			player2.setScore();
			this->resetState(board, player1, player2);
		}
	}

	if ((position.x - limitRight) >= -3) {
		int heightPlayerInterval = player2.getY() + Player::height;
		if (position.y >= player2.getY() && position.y <= heightPlayerInterval) {
			this->collisionPlayer();
			speed = speed * 1.1;
			return 1;
		}
		else {
			player1.setScore();
			this->resetState(board, player1, player2);
		}
	}

	if ((position.y - limitTop) <= 5) {
		this->collisionBoard();
		return 2;
	}
	if ((position.y - limitBottom) >= -5) {
		this->collisionBoard();
		return 2;
	}

	return 0;
}

void Ball::collisionBoard() {
	vec.y = -vec.y;
}

void Ball::collisionPlayer() {
	Random* r = Random::getInstance();
	
	if (vec.x > 0) {
		vec.x = -(r->getRandomVal(5, 9) / 10.0);
	}
	else if (vec.x < 0) {
		vec.x = (r->getRandomVal(5, 9) / 10.0);
	}

	if (vec.y < 0) {
		vec.y = -sqrt(1 - vec.x * vec.x);
	}
	else if (vec.y > 0) {
		vec.y = sqrt(1 - vec.x * vec.x);
	}

}

void Ball::resetState(Board board, Player1 player1, Player2 player2) {
	Random* r = Random::getInstance();
	
	// fix position in the future
	position.x = defaultWidth / 2 + 10;
	position.y = defaultHeight / 2 - 5;

	// 0 for negative vec.x, 1 for positive vec.x
	// 0 for negative vec.y, 1 for positive vec.y

	int binomRandom1 = r->getRandomVal(0, 1);
	int binomRandom2 = r->getRandomVal(0, 1);

	// random the value of vec.x
	vec.x = r->getRandomVal(5, 9) / 10.0;
	if (binomRandom1 == 0) {
		vec.x = -vec.x;
	}

	// calculate the vec.y
	vec.y = sqrt(1 - vec.x * vec.x);
	if (binomRandom2 == 0) {
		vec.y = -vec.y;
	}

	speed = 10;
	cleardevice();
}