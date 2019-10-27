#include "Ball.h"
#include "Random.h"
#include "Player.h"
#include "graphics.h"
#include <fstream>

Ball::Ball(Board& board, Player1& player1, Player2& player2) {
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
	Point anchorPointTopLeft(player1.getX(), player1.limitTop);
	Point anchorPointBottomRight(player2.getX(), player2.limitBottom);
	int boardHeight = board.getHeight();
	int boardWidth = board.getWidth();

	// calculate limit position for the ball 
	// count from the center of the ball
	limitTop = anchorPointTopLeft.y + radius;
	limitBottom = anchorPointTopLeft.y + boardHeight- radius;
	limitLeft = anchorPointTopLeft.x + Player::width + radius;
	limitRight = anchorPointBottomRight.x - radius;
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
	if (position.x > 0) {
		position.x += (int)ceil(vec.x * speed);
	}
	else if (position.x < 0) {
		position.x += (int)floor(vec.x * speed);
	}

	if (position.y > 0) {
		position.y += (int)ceil(vec.y * speed);
	}
	else if (position.y < 0) {
		position.y += (int)floor(vec.y * speed);
	}
}

// input: board, player1, player2
// output: 1 if collision with player, 2 if collision with board, 0 if no collision
int Ball::hasCollision(const Board& board, Player1& player1, Player2& player2) {
	// heightPlayerInerval is an interval between the coordination of the top to the bottom of the player
	// if position.x of the ball to the limit edge is smaller than 3 pixel than bounce the ball back
	int compareParamForBallX = (int)floor(vec.x * speed);
	int compareParamForBallY = (int)floor(vec.y * speed);
	if ((position.x - limitLeft) <= 1) {
		int heightPlayerInterval = player1.getY() + Player::height;
		if (position.y >= player1.getY() && position.y <= heightPlayerInterval) {
			this->collisionPlayer();
			speed = speed * 1.1;
			return 1;
		}
		else {
			player2.setScore();
			this->resetState(board);
			return 1;
		}
	}

	if ((position.x - limitRight) >= -1) {
		int heightPlayerInterval = player2.getY() + Player::height;
		if (position.y >= player2.getY() && position.y <= heightPlayerInterval) {
			this->collisionPlayer();
			speed = speed * 1.1;
			return 1;
		}
		else {
			player1.setScore();
			this->resetState(board);
			return 1;
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
	if (vec.y > 0) {
		this->position.y -= 2;
	}
	else if (vec.y < 0) {
		this->position.y += 2;
	}

	vec.y = -vec.y;
}

void Ball::collisionPlayer() {
	Random* r = Random::getInstance();
	
	if (vec.x > 0) {
		vec.x = -(r->getRandomVal(5, 9) / 10.0);
		this->position.x -= 2;
	}
	else if (vec.x < 0) {
		vec.x = (r->getRandomVal(5, 9) / 10.0);
		this->position.x += 2;
	}

	if (vec.y < 0) {
		vec.y = -sqrt(1 - vec.x * vec.x);
		this->position.y += 2;
	}
	else if (vec.y > 0) {
		vec.y = sqrt(1 - vec.x * vec.x);
		this->position.y -= 2;
	}
}

void Ball::resetState(const Board& board) {
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
}