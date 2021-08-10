#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3//修改此处可实现N子棋

void InitBoard(char board[ROW][COL], int row, int col);
void PrintBoard(char board[ROW][COL], int row, int col);
void Player(char board[ROW][COL], int row ,int col);
void Computer(char board[ROW][COL], int row, int col);

char IsWin(char board[ROW][COL], int row, int col);
