#include "gameWindow.h"
#include <thread>

gameWindow::gameWindow() :board(600, 400), ball(board, player1, player2), player1(board), player2(board), exitFlag(false) {}

void gameWindow::runGame() {
	drawTitle();//draw title
	drawInstruction();//draw instruction
	while (1) {

		board.drawBoard();//draw ball

		drawScorePlayer1();//draw player1
		drawScorePlayer2();//draw player2

		ball.move();
		ball.drawBall();//draw ball

		if (GetAsyncKeyState(0x57)) player1.moveUP();//if discover key 'w' pressed , player1 will move up
		if (GetAsyncKeyState(0x53)) player1.moveDown();//if discover key 's' pressed , player1 will move down
		player1.draw();

		if (GetAsyncKeyState(VK_UP)) player2.moveUP();//if discover key UP pressed , player2 will move up
		if (GetAsyncKeyState(VK_DOWN)) player2.moveDown();//if discover key DOWN pressed , player2 will move down
		player2.draw();

		ball.hasCollision(board, player1, player2);

		if (GetAsyncKeyState(0x50)) {//Pess key 'p' to pause game
			pauseGame();
			while (1) {
				if (GetAsyncKeyState(0x52))//press key 'r' to resume game
					break;
			}
		}

		int Winner = winner();//find whether there is winner
		if (Winner) {// Find winner
			drawResult(Winner);//draw result
			delay(2000);

			return; //exit game
		}

		delay(50);

		if (GetAsyncKeyState(VK_ESCAPE)) {
			// press key "Esc' to exit game
			return;
		}
	}
}

void gameWindow::drawScorePlayer1() {
	//Draw Player text

	//set color
	setcolor(YELLOW);
	settextstyle(1, 0, 1);
	char nameplayer[] = "Player 1";
	//set position text
	int xName = (board.getPoint1().x - textwidth(nameplayer)) / 2;
	int yName = board.getPoint1().y + board.getHeight() / 2;
	outtextxy(xName, yName, nameplayer);//draw text

	//Draw score

	char* score = new char;
	_itoa(player1.getScore(), score, 10);//transform interger into character
	char Score[10] = "Score: ";
	strcat(Score, score);//Combine sequence of characters
	//set position text
	int xScore = (board.getPoint1().x - textwidth(Score)) / 2;
	int yScore = yName + 2 * textheight(nameplayer);
	//set color
	setcolor(YELLOW);
	settextstyle(1, 0, 1);
	outtextxy(xScore, yScore, Score);//draw text
}

//the same as drawScorePlayer1
void gameWindow::drawScorePlayer2() {
	//Draw Player text
	setcolor(YELLOW);
	settextstyle(1, 0, 1);
	char nameplayer[] = "Player 2";
	int xName = (defaultWidth - board.getPoint2().x - textwidth(nameplayer)) / 2 + board.getPoint2().x;
	int yName = board.getPoint2().y + board.getHeight() / 2;
	setcolor(YELLOW);
	settextstyle(1, 0, 1);
	outtextxy(xName, yName, nameplayer);

	//draw score text
	char* score = new char;
	_itoa(player2.getScore(), score, 10);
	char Score[10] = "Score: ";
	strcat(Score, score);
	int xScore = (defaultWidth - board.getPoint2().x - textwidth(Score)) / 2 + board.getPoint2().x;
	int yScore = yName + 2 * textheight(nameplayer);
	setcolor(YELLOW);
	settextstyle(1, 0, 1);
	outtextxy(xScore, yScore, Score);
}

//draw instructrion
void gameWindow::drawInstruction() {
	//set color text
	setcolor(5);
	settextstyle(1, 0, 1);
	//text
	char InPlayer1[] = "Player 1: W - S";
	char InPlayer2[] = "Player 2: UP - DOWN";
	char InPlay[] = "Press P to Pause - Press R to Resume";
	char InPlay2[] = "Press Escape to exit the game";
	//set position of text
	int x = (defaultWidth - textwidth(InPlay)) / 2;
	int height_text = textheight(InPlayer1);
	int y = board.getPoint1().y + board.getHeight() + height_text;
	//draw text
	outtextxy(x, y, InPlayer1);
	outtextxy(x, y + height_text, InPlayer2);
	outtextxy(x, y + 2 * height_text, InPlay);
	outtextxy(x, y + 3 * height_text, InPlay2);
}
//draw title of game
void gameWindow::drawTitle() {
	setcolor(BLUE);
	settextstyle(3, 0, 7);
	//title
	char title[] = "PING PONG";
	//set position of text
	int x = (defaultWidth - textwidth(title)) / 2;
	int y = (board.getPoint1().y - textheight(title)) / 2;
	//draw text
	outtextxy(x, y, title);

}
//Pause Game
void gameWindow::pauseGame() {
	//set size of retangle
	int width = 200;
	int height = 100;
	//set position of retangle
	int top = (defaultHeight - height) / 2;
	int left = (defaultWidth - width) / 2;
	int bottom = top + height;
	int right = left + width;
	//draw retangle
	setcolor(3);
	setfillstyle(1, 3);
	bar(left, top, right, bottom);
	//draw text
	setcolor(WHITE);
	settextstyle(1, 0, 3);
	char pause[] = "PAUSE";
	//set position of text based on coordinate of retangle
	int x = left + (width - textwidth(pause)) / 2;
	int y = top + (height - textheight(pause)) / 2;
	//draw text
	outtextxy(x, y, pause);

}
//find winner
int gameWindow::winner() {
	if (player1.getScore() == scoreWiner) return 1;//player 1 is winner
	if (player2.getScore() == scoreWiner) return 2;//player 2 is winner
	//non of them
	return 0;
}
//draw result
void gameWindow::drawResult(int idx) {
	char* player = new char;
	_itoa(idx, player, 10);//transform interger into character 

	char result[20] = "WINNER: PLAYER ";
	strcat(result, player);//conbine both

	cleardevice();//clear screen
	//set color
	setcolor(6);
	settextstyle(1, 0, 5);
	//set position of text
	int x = (defaultWidth - textwidth(result)) / 2;
	int y = (defaultHeight - textheight(result)) / 2;
	outtextxy(x, y, result);//draw text
}