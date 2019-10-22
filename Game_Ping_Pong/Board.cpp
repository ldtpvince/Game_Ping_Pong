#include "Board.h"

//constructor
Board::Board(int h, int w) {
	height = h;
	width = w;
	//draw color background
	setcolor(GREEN);
	setfillstyle(1, GREEN);
	int left = (640 - height) / 2 - 5;
	int	top = (480 - width) / 2 + 10;
	int right = left + height, bottom = top + width;
	bar(left, top, right, bottom);

	//draw white lines
	setcolor(WHITE);
	setlinestyle(1, 0, 1);
	line(left + height / 2, top, left + height / 2, bottom);
	circle(left + height / 2, top + width / 2, width / 4);

	//draw walls 
	setcolor(BROWN);
	setfillstyle(1, BROWN);
	bar(left, top - thick, right, top);
	bar(left, bottom, right, bottom + thick);

	//2 important position support class Player
	p1 = Point(left, top);
	p2 = Point(right, top);
}

//draw ball 
//it is the same as function constructor
void Board::drawBoard() {
	setcolor(GREEN);
	setfillstyle(1, GREEN);
	int left = (640 - height) / 2 - 5;
	int	top = (480 - width) / 2 + 10;
	int right = left + height, bottom = top + width;
	bar(left, top, right, bottom);

	setcolor(WHITE);
	setlinestyle(1, 0, 1);
	line(left + height / 2, top, left + height / 2, bottom);
	circle(left + height / 2, top + width / 2, width / 4);

	setcolor(BROWN);
	setfillstyle(1, BROWN);

	bar(left, top - thick, right, top);
	bar(left, bottom, right, bottom + thick);
}