#include "Board.h"

// construct
Board::Board(int w, int h) {
	height = h;
	width = w;
	int top = (defaultHeight - height) / 2;
	int	left = (defaultWidth - width) / 2 ;
	int right = left + width, bottom = top + height;

	//2 anchor position support class Player
	p1 = Point(left, top);
	p2 = Point(right, top);
}

// input: void
// output: void
// usage: draw Board on the screen
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