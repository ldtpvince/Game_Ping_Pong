#include "Board.h"

//constructor
Board::Board(int w, int h) {
	height = h;
	width = w;
	//set up for p1,p2
	int top = (defaultHeight - height) / 2;
	int	left = (defaultWidth - width) / 2 ;
	int right = left + width, bottom = top + height;

	//2 anchor position support class Player
	p1 = Point(left, top);
	p2 = Point(right, top);
}

//draw ball 
void Board::drawBoard() {
	//set color
	setcolor(GREEN);
	setfillstyle(1, GREEN);
	//set position
	int top = (defaultHeight - height) / 2 ;
	int	left = (defaultWidth - width) / 2 ;
	int right = left + width, bottom = top + height;
	//draw rectangle
	bar(left, top, right, bottom);

	setcolor(WHITE);
	setlinestyle(1, 0, 1);
	//draw the circle and the straight line in center of board
	line(left + width / 2, top, left + width / 2, bottom);
	circle(left + width / 2, top + height / 2, width / 4);

	setcolor(BROWN);
	setfillstyle(1, BROWN);

	//decorate the board
	bar(left, top - thick, right, top);//edge of top
	bar(left, bottom, right, bottom + thick);//edge of bottom

	// return to default mode
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	setlinestyle(SOLID_LINE, 0, 1);
}