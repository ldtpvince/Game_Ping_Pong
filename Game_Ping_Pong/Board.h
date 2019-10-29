#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "graphics.h"
#include "Point.h"
#include <time.h>

#pragma comment(lib, "graphics.lib")
using namespace std;

const int defaultHeight = 600;
const int defaultWidth = 900;

class Board
{
	int height;
	int width;
	Point p1;//anchor left
	Point p2;//anchor right

	const int thick = 10;//thick of board to decorate
public:
	Board(int w, int h);
	Board();
	int getHeight() {
		return height;
	}
	int getWidth() {
		return width;
	}
	Point getPoint1() {
		return p1;
	}
	Point getPoint2() {
		return p2;
	}
	void drawBoard();
};



