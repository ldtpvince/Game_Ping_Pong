#include "Board.h"

//constructor
Board::Board(int w, int h) {
	height = h;
	width = w;
	int top = (defaultHeight - height) / 2;
	int	left = (defaultWidth - width) / 2 ;
	int right = left + width, bottom = top + height;

	/*//draw color background
	setcolor(GREEN);
	setfillstyle(1, GREEN);

	bar(left, top, right, bottom);

	//draw white lines
	setcolor(WHITE);
	setlinestyle(1, 0, 1);
	line(left + height / 2, top, left + height / 2, bottom);
	circle(left + height / 2, top + width / 2, width / 4);

	// draw walls 
	setcolor(BROWN);
	setfillstyle(1, BROWN);
	bar(left, top - thick, right, top);
	bar(left, bottom, right, bottom + thick);*/

	//2 important position support class Player
	p1 = Point(left, top);
	p2 = Point(right, top);
}

//draw ball 
//it is the same as function constructor
void Board::drawBoard() {
	setcolor(GREEN);
	setfillstyle(1, GREEN);
	int top = (defaultHeight - height) / 2 ;
	int	left = (defaultWidth - width) / 2 ;
	int right = left + width, bottom = top + height;
	bar(left, top, right, bottom);

	setcolor(WHITE);
	setlinestyle(1, 0, 1);
	line(left + width / 2, top, left + width / 2, bottom);
	circle(left + width / 2, top + height / 2, width / 4);

	setcolor(BROWN);
	setfillstyle(1, BROWN);

	bar(left, top - thick, right, top);
	bar(left, bottom, right, bottom + thick);

	// return to default mode
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	setlinestyle(SOLID_LINE, 0, 1);
}