#include "graphics.h"
#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "Ball.h"
#include "Random.h"
#include <Windows.h>
#pragma comment(lib, "graphics.lib")
using namespace std;

void test(char c) {
	cout << c << endl;
}
int main() {
	int gd = DETECT, gm;
	char c[] = "Game Ping Pong";
	initwindow(900, 600);
	int w = getwindowwidth();
	int h = getwindowheight();

	Board board(380, 540);

	Player1 p1(board.getPoint1(), board.getHeight());
	Player2 p2(board.getPoint2(), board.getHeight());

	Ball ball(board, p1, p2);

	while (1) {
		board.drawBoard();
		ball.drawBall();
		ball.move();

		if (GetAsyncKeyState(0x57)) p1.moveUP();
		if (GetAsyncKeyState(0x53)) p1.moveDown();
		p1.draw();

		if (GetAsyncKeyState(VK_UP)) p2.moveUP();
		if (GetAsyncKeyState(VK_DOWN)) p2.moveDown();
		p2.draw();

		ball.hasCollision(board, p1, p2);

		delay(50);

		if (GetAsyncKeyState(VK_ESCAPE)) break;
	}
	cin.ignore();
	closegraph();
	Random* r = Random::getInstance();
	delete r;
}