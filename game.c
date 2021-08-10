#include"game.h";
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//在其中输入空格字符
		}
	}
}
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}//打印竖着的 “ | ”
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("___");
				if (j < col - 1)
					printf("|");
			}//打印 "__"
			printf("\n");
		}
	}
	printf("\n");
}
void Player(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走\n\n");
	while (1)
	{
		printf("请输入要走的坐标： ");
		scanf("%d %d", &x, &y);
		if (x <= ROW && y <= COL && x >= 1 && y >= 1)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';//减去一是为了符合逻辑（大部分朋友会认为坐标是从1开始的，实际数组中是从零开始的）
				break;
			}
			else
			{
				printf("坐标被占用！\n");
			}
		}//需判断坐标是否存在或被占用
		else
			printf("坐标非法！\n\n");
	}
}
void Computer(char board[ROW][COL], int row, int col)
{
	printf("电脑走： \n\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int Player = 0;
	int Computer = 0;
	int win = 0;
	while (i <= row)//判断行
	{
		Player = 0;
		Computer = 0;
		j = 0;
		while (j < (col - 1))
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] == '*')
				Player++;
			if (board[i][j] == board[i][j + 1] && board[i][j] == '#')
				Computer++;
			if (Player == (row - 1))
				return '*';
			else if (Computer == (row - 1))
				return '#';
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	Player = 0;
	Computer = 0;
	while (j <= row)//判断列
	{
		Player = 0;
		Computer = 0;
		i = 0;
		while (i < (col - 1))
		{
			if (board[i][j] == board[i + 1][j] && board[i][j] == '*')
				Player++;
			if (board[i][j] == board[i + 1][j] && board[i][j] == '#')
				Computer++;
			if (Player == (row - 1))
				return '*';
			else if (Computer == (row - 1))
				return '#';
			i++;
		}
		j++;
	}
	Player = 0;
	Computer = 0;
	/*i = 0;
	j = 0;*/
	for (i = 0; i < row; i++)//斜左上至右下
	{
		if (board[i][i] == board[i + 1][i + 1] && board[i][i] == '*')
			Player++;
		if (board[i][i] == board[i + 1][i + 1] && board[i][i] == '#')
			Computer++;
		if (Player == (row - 1))
			return '*';
		else if (Computer == (row - 1))
			return '#';
	}
	Player = 0;
	Computer = 0;
	for (i = 0, j = (col - 1); i < row, j > 0 ; i++ , j--)//斜右上至左下
	{
			if (board[i][j] == board[i + 1][j - 1] && board[i][j] == '*')
				Player++;
			if (board[i][j] == board[i + 1][j - 1] && board[i][j] == '#')
				Computer++;
			if (Player == (row - 1))
				return '*';
			else if (Computer == (row - 1))
				return '#';
	}


	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				win++;
		}
	}
	if (win == 0)
		return 'Q';
	    return 'C';
}
