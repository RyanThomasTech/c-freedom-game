#include <stdbool.h>
#include <stdio.h>

int whiteSum, blackSum;
extern void ScoreGame(char** board);
void ScoreCheckDiagonal(int row, int col, char** board);
void ScoreCheckVertical(int row, int col, char** board);
void ScoreCheckHorizontal(int row, int col, char** board);
int ScoreMatchNorthwest(int row, int col, char** board, bool recursive);
int ScoreMatchNortheast(int row, int col, char** board, bool recursive);
int ScoreMatchSoutheast(int row, int col, char** board, bool recursive);
int ScoreMatchSouthwest(int row, int col, char** board, bool recursive);
int ScoreCheckNorth(int row, int col, char** board, bool recursive);
int ScoreCheckSouth(int row, int col, char** board, bool recursive);
int ScoreCheckWest(int row, int col, char** board, bool recursive);
int ScoreCheckEast(int row, int col, char** board, bool recursive);
