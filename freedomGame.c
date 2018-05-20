#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "freedomScoring.h"

#define BOARDCHARMAX 4
#define BOARDDEFAULT 10

int GetBoardSizeInput();
void CreateBoard(char*** board, int boardSize);
bool BoardHasEmptySpaces(char** board, int boardSize);
void PrintBoard(char** board, int boardSize);
void PlayTurn(int turnCount, char*** board);
int PlacePiece(bool player1, int x, int y, char*** board);
bool AdjacentToPrevMove(int x, int y, char*** board);
int GetLetterVal(char xPosChar);
bool PrevMoveIsSurroundedOrFirstTurn(char*** board);
char** GenFakeBoard();

static int prevXMove = -1;
static int prevYMove = -1;

int main(){
	int turnCount = 0;
	char** board;
	int boardSize = BOARDDEFAULT;
	CreateBoard(&board, boardSize);
	//board = GenFakeBoard();	//******UNCOMMENT ME FOR FAKE BOARD
	PrintBoard(board, boardSize);
	while ( BoardHasEmptySpaces(board, boardSize) ){
		PlayTurn(turnCount, &board);
		turnCount++;
		PrintBoard(board, boardSize);
	}
	ScoreGame(board);
	return 0;
}

int GetBoardSizeInput(){
	char usrInput[BOARDCHARMAX];
	char* ptr;
	printf("Input length of one side of board (board is square): ");
	fgets(usrInput, BOARDCHARMAX, stdin);
	return strtol(usrInput, &ptr, 10);
}

void CreateBoard(char*** board, int boardSize){
	*board = (char **)malloc(boardSize * sizeof(char *));
	for (int i = 0; i<boardSize; i++){
		(*board)[i] = (char*)malloc(boardSize * sizeof(char));
	}
	for (int row=0; row<boardSize; row++){
		for (int col = 0; col<boardSize; col++){
			(*board)[row][col] = ' ';
		}
	}
}

void PlayTurn(int turnCount, char*** board){
	bool player1 = turnCount%2;
	char usrInput[4], xPosChar;
	int xPos, yPos;
	do {
		printf("Input the position you would like to place your piece: ");
		memset(usrInput, '\0', sizeof(usrInput));
		fgets(usrInput, 4, stdin);
		xPosChar = usrInput[0];
		xPos = GetLetterVal(xPosChar);
		yPos = usrInput[1] - '0';
	} while ( PlacePiece(player1, xPos, yPos, board) != 0 );
}

int PlacePiece(bool player1, int x, int y, char*** board){
	char stoneColor;
	if (player1) stoneColor = 'W';
	else stoneColor = 'B';

	if ((*board)[x][y] == ' ' && AdjacentToPrevMove(x, y, board)){
		(*board)[x][y] = stoneColor;
		return 0;
	} else {
		printf("\nIllegal move.\n");
		return 1;
	}
}

bool AdjacentToPrevMove(int x, int y, char*** board){
	if (PrevMoveIsSurroundedOrFirstTurn(board)){
		prevXMove = x;
		prevYMove = y;
		return true;
	} else if (	(x == prevXMove+1 || x == prevXMove || x == prevXMove-1) &&
			(y == prevYMove+1 || y == prevYMove || y == prevYMove-1)){
		prevXMove = x;
		prevYMove = y;
		return true;
	}
	return false;
}

bool PrevMoveIsSurroundedOrFirstTurn(char*** board){
	if (prevXMove == -1){
		return true;
	}

	if (	(prevXMove-1 < 0 || (*board)[prevXMove-1][prevYMove]!=' ') &&
		(prevXMove+1 > 9 || (*board)[prevXMove+1][prevYMove]!=' ') &&
		(prevYMove-1 < 0 || (*board)[prevXMove][prevYMove-1]!=' ') &&
		(prevYMove+1 > 9 || (*board)[prevXMove][prevYMove+1]!=' ') &&
		((prevXMove+1 > 9 && prevYMove+1 >9) || (*board)[prevXMove+1][prevYMove+1]!=' ') &&
		((prevXMove+1 > 9 && prevYMove-1 <0) || (*board)[prevXMove+1][prevYMove-1]!=' ') &&
		((prevXMove-1 < 0 && prevYMove+1 >9) || (*board)[prevXMove-1][prevYMove+1]!=' ') &&
		((prevXMove-1 < 0 && prevYMove-1 <0) || (*board)[prevXMove-1][prevYMove-1]!=' ') 
		) return true;
	return false;
}

int GetLetterVal(char xPosChar){
	if (xPosChar == 97 || xPosChar == 65 ) return 0;
	if (xPosChar == 98 || xPosChar == 66 ) return 1;
	if (xPosChar == 99 || xPosChar == 67 ) return 2;
	if (xPosChar == 100 || xPosChar == 68 ) return 3;
	if (xPosChar == 101 || xPosChar == 69 ) return 4;
	if (xPosChar == 102 || xPosChar == 70 ) return 5;
	if (xPosChar == 103 || xPosChar == 71 ) return 6;
	if (xPosChar == 104 || xPosChar == 72 ) return 7;
	if (xPosChar == 105 || xPosChar == 73 ) return 8;
	if (xPosChar == 106 || xPosChar == 74 ) return 9;
	printf("\n erroneous value received\n");
	return -1;
}

bool BoardHasEmptySpaces(char** board, int boardSize){
	for (int row=0; row<boardSize; row++){
		for (int col=0; col<boardSize; col++){
			if (board[row][col] == ' '){
				return true;
			}
		}
	}
	return false;
}

char** GenFakeBoard(){
	char** board = (char **)malloc(10*sizeof(char *));
	char* row0 = "BWBWBBWWBW";
	char* row1 = "BWBBWWBBBW";
	char* row2= "WWBWBWBWBB";
	char* row3= "BBWBBWBWWW";
	char* row4= "WWBWWWBBWB";
	char* row5= "BBWBBWWBBW";
	char* row6= "WWBWWBBWBB";
	char* row7= "WWBWWBWWWW";
	char* row8= "BBBBWWBBBB";
	char* row9= "WBWWBBWWWB";

	board[0] = row0;
	board[1] = row1;
	board[2] = row2;
	board[3] = row3;
	board[4] = row4;
	board[5] = row5;
	board[6] = row6;
	board[7] = row7;
	board[8] = row8;
	board[9] = row9;

	return board;
}

void PrintBoard(char** board, int boardSize){
	int asciiNum=0;
	printf("\n  0 1 2 3 4 5 6 7 8 9\n");
	for (int row=0; row<boardSize; row++){
		asciiNum = row + 65;
		printf("%c|", asciiNum);
		for (int col = 0; col<boardSize; col++){
			printf("%c|", board[row][col]);
		}
		printf("\n");
		printf(" |");
		for (int col = 0; col<boardSize; col++){
			printf("-+");
		}
		printf("\n");
	}
}
