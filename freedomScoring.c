#include "freedomScoring.h"


void ScoreGame(char** board){
	whiteSum = 0;
	blackSum = 0;
	for (int row = 0; row<10; row++){
		for (int col = 0; col<10; col++){
			ScoreCheckDiagonal(row, col, board);
			ScoreCheckHorizontal(row, col, board);
			ScoreCheckVertical(row, col, board);
		}
	}
	printf("\nBlack Score: %d\tWhite Score: %d\n",blackSum, whiteSum);
	if (blackSum == whiteSum){
		printf("\nIt's a tie!\n");
	} else if (blackSum > whiteSum){
		printf("\nBlack wins!\n");
	} else {
		printf("\nWhite wins!\n");
	}
}

void ScoreCheckHorizontal(int row, int col, char** board){
	if (	ScoreCheckWest(row, col, board, false)!=1  &&
		ScoreCheckEast(row, col, board, true)==4 ){
		if (board[row][col]=='W'){
			whiteSum++;
		} else {
			blackSum++;
		}
	}
}

int ScoreCheckWest(int row, int col, char** board, bool recursive){
	char originalStoneColor = board[row][col];
	int sum = 0;
	if (recursive){
		if (col-1>=0 && board[row][col-1] == originalStoneColor){
			sum= 1+ScoreCheckWest(row, col-1, board, true);
			return sum;
		}
		return 1;
	} else {
		if (col-1>=0 && board[row][col-1] == originalStoneColor){
			return 1;
		}
		return 0;
	}
}

int ScoreCheckEast(int row, int col, char** board, bool recursive){
	char originalStoneColor = board[row][col];
	int sum = 0;
	if (recursive){
		if (col+1<=9 && board[row][col+1] == originalStoneColor){
			sum= 1+ScoreCheckEast(row, col+1, board, true);
			return sum;
		}
		return 1;
	} else {
		if (col+1<=9 && board[row][col+1] == originalStoneColor){
			return 1;
		}
		return 0;
	}
}

void ScoreCheckVertical(int row, int col, char** board){
	if (	ScoreCheckNorth(row,col,board,false)!=1 &&
		ScoreCheckSouth(row, col, board, true)==4 ){
		if (board[row][col]=='W'){
			whiteSum++;
		} else {
			blackSum++;
		}
	}
}

int ScoreCheckNorth(int row, int col, char** board, bool recursive){
	char originalStoneColor = board[row][col];
	int sum = 0;
	if (recursive){
		if (row-1>=0 && board[row-1][col] == originalStoneColor){
			sum= 1+ScoreCheckNorth(row-1, col, board, true);
			return sum;
		}
		return 1;
	} else {
		if (row-1>=0 && board[row-1][col] == originalStoneColor){
			return 1;
		}
		return 0;
	}
}

int ScoreCheckSouth(int row, int col, char** board, bool recursive){
	char originalStoneColor = board[row][col];
	int sum = 0;
	if (recursive){
		if (row+1<=9 && board[row+1][col] == originalStoneColor){
			sum= 1+ScoreCheckSouth(row+1, col, board, true);
			return sum;
		}
		return 1;
	} else {
		if (row+1<=9 && board[row+1][col] == originalStoneColor){
			return 1;
		}
		return 0;
	}
}

void ScoreCheckDiagonal(int row, int col, char** board){
	if (	ScoreMatchNortheast(row, col, board, false)!=1 && 
		ScoreMatchSouthwest(row, col, board, true)==4 ){
		if (board[row][col]=='W'){
			whiteSum++;
		} else {
			blackSum++;
		}
	}
	if (	ScoreMatchSoutheast(row, col, board, false)!=1 &&
		ScoreMatchNorthwest(row, col, board, true)==4 ){
		if (board[row][col]=='W'){
			whiteSum++;
		} else {
			blackSum++;
		}
	}
}

int ScoreMatchNorthwest(int row, int col, char** board, bool recursive){
	char originalStoneColor = board[row][col];
	int sum = 0;
	if (recursive){
		if (row-1>=0 && col-1>=0 && board[row-1][col-1] == originalStoneColor){
			sum= 1+ScoreMatchNorthwest(row-1, col-1, board, true);
			return sum;
		}
		return 1;
	} else {
		if (row-1>=0 && col-1>=0 && board[row-1][col-1] == originalStoneColor){
			return 1;
		}
		return 0;
	}
}

int ScoreMatchNortheast(int row, int col, char** board, bool recursive){
	char originalStoneColor = board[row][col];
	int sum = 0;
	if (recursive){
		if (row-1>=0 && col+1<=9 && board[row-1][col+1] == originalStoneColor){
			sum= 1+ScoreMatchNortheast(row-1, col+1, board, true);
			return sum;
		}
		return 1;
	} else {
		if (row-1>=0 && col+1<=9 && board[row-1][col+1] == originalStoneColor){
			return 1;
		}
		return 0;
	}
}

int ScoreMatchSoutheast(int row, int col, char** board, bool recursive){
	char originalStoneColor = board[row][col];
	int sum = 0;
	if (recursive){
		if (row+1<=9 && col+1<=9 && board[row+1][col+1] == originalStoneColor){
			sum= 1+ScoreMatchSoutheast(row+1, col+1, board, true);
			return sum;
		}
		return 1;
	} else {
		if (row+1<=9 && col+1<=9 && board[row+1][col+1] == originalStoneColor){
			return 1;
		}
		return 0;
	}
}

int ScoreMatchSouthwest(int row, int col, char** board, bool recursive){
	char originalStoneColor = board[row][col];
	int sum = 0;
	if (recursive){
		if (row+1<=9 && col-1>=0 && board[row+1][col-1] == originalStoneColor){
			sum= 1+ScoreMatchSouthwest(row+1, col-1, board, true);
			return sum;
		}
		return 1;
	} else {
		if (row+1<=9 && col-1<=0 && board[row+1][col-1] == originalStoneColor){
			return 1;
		}
		return 0;
	}
}
