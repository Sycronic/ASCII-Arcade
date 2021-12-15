#include "tictactoe.h"

Tictactoe::Tictactoe()
{
}

void Tictactoe::play()
{
	
	gLogic(board_);
}
					   
void Tictactoe::cpuLogic(std::vector<std::vector<int>>& board_)
{
	//use checksx/y/z to see which has higher number to determine where to place O
	if (maxcheckZ(board_, x, y) > maxcheckX(board_, x, y) && maxcheckZ(board_, x, y) > maxcheckY(board_, x, y) && board_[zx][zy] > 0)
	{
		x = zx;	y = zy;
		board_[zx][zy] = -4;
	}
	else if(maxcheckX(board_, x, y) > maxcheckY(board_, x, y) && board_[xx][xy] > 0)
	{
		x = xx;	y = xy;
		board_[xx][xy] = -4;
	}
	else if (maxcheckY(board_, x, y) > 0 && board_[yx][yy] > 0)
	{
		x = yx;	y = yy;
		board_[yx][yy] = -4;
	}
	else
	{
		if (maxcheckZ(board_, x, y) > maxcheckX(board_, x, y) && maxcheckZ(board_, x, y) > 0 && board_[zx][zy] > 0)
		{
			x = zx;	y = zy;
			board_[zx][zy] = -4;
		}
		else if (board_[xx][xy] > 0)
		{
			x = xx;	y = xy;
			board_[xx][xy] = -4;
		}
		else
		{
			gameOver = true;
			std::cout << "\nGame Over You Tie \n\n";
		}
	}
}

void Tictactoe::gLogic(std::vector<std::vector<int>>& board_)
{
	while (!gameOver)
	{

		drawGuide();
		playerInput(board_);

		Draw(board_);

		if (checkifWon(board_, -3, x, y))
		{
			gameOver = true;
			std::cout << "\nGame Over You Win \n\n";
		}

		cpuLogic(board_);
		Draw(board_);

		if (checkifWon(board_, -4, x, y))
		{
			gameOver = true;
			std::cout << "\nGame Over You Lose\n\n";
		}
	}
}

//returns designated X/O or space based on index value of board_ for draw
char Tictactoe::checkSpace(int x)
{
	switch (x)
	{
	case  -3: return 'O';
	case  -4: return 'X';
	default: return ' ';
	}
}

//returns results for checkX, checkY, or checkZ if any are true
bool Tictactoe::checkifWon(std::vector<std::vector<int>>& board_, int p, int x, int y)
{
	int win = p * 3;
	if (win == checkX(board_, x, y) || win == checkY(board_, x, y) || win == checkZ(board_, p, x, y))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

//draws play board
void Tictactoe::Draw(std::vector<std::vector<int>>& board_)
{

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			std::cout << checkSpace(board_[x][y]) << '|';	
			if (x == 2) {
				std::cout << '\n';
			}
		}
	}
	std::cout << '\n';
}

//returns summation for horizontal of last index for 3 in a row and returns results (also increases value of spaces needed to win)
int Tictactoe::checkX(std::vector<std::vector<int>>& board_, int x, int y)
{
	if (x == 0 || x == 2)
	{
		if (x == 0)
		{	
			addSpaceVal(board_, x + 1, y);
			addSpaceVal(board_, x + 2, y);
			return board_[x][y] + board_[x + 1][y] + board_[x + 2][y];
		}
		else
		{
			addSpaceVal(board_, x -1, y);
			addSpaceVal(board_, x - 2, y); 
			return (board_[x][y] + board_[x - 1][y] + board_[x - 2][y]);
		}
	}
	else
	{
		addSpaceVal(board_, x - 1, y);
		addSpaceVal(board_, x + 1, y);
		return board_[x][y] + board_[x - 1][y] + board_[x + 1][y];
	}
}

int Tictactoe::maxcheckX(std::vector<std::vector<int>>& board_, int x, int y)
{
	if (x == 0 || x == 2)
	{
		if (x == 0)
		{
			if (board_[x + 1][y] > board_[x + 2][y])
			{
				xx = x + 1; xy = y;
				return board_[x + 1][y];
			}
			else
			{
				xx = x + 2; xy = y;
				return board_[x + 2][y];
			}
		}
		else
		{
			if (board_[x - 1][y] > board_[x - 2][y])
			{
				xx = x - 1; xy = y;
				return board_[x - 1][y];
			}
			else
			{
				xx = x - 2; xy = y;
				return board_[x - 2][y];
			}
		}
	}
	else
	{
		if (board_[x - 1][y] > board_[x + 1][y])
		{
			xx = x - 1; xy = y;
			return board_[x - 1][y];
		}
		else
		{
			//redundant? 
			xx = x + 1; xy = y;
			return board_[x + 1][y];
		}
	}
}

//returns summation for vertical of last index for 3 in a row and returns results (also increases value of spaces needed to win)
int Tictactoe::checkY(std::vector<std::vector<int>>& board_, int x, int y)
{
	if (y == 0 || y == 2)
	{
		if (y == 0)
		{
			addSpaceVal(board_, x, y+1);
			addSpaceVal(board_, x, y+2); 
			return board_[x][y] + board_[x][y + 1] + board_[x][y + 2];
		}
		else
		{
			addSpaceVal(board_, x, y-1);
			addSpaceVal(board_, x, y-2);
			return board_[x][y] + board_[x][y - 1] + board_[x][y - 2];
		}
	}
	else
	{	
		addSpaceVal(board_, x, y+1);
		addSpaceVal(board_, x, y-1);
		return board_[x][y] + board_[x][y + 1] + board_[x][y - 1];
	}
}

int Tictactoe::maxcheckY(std::vector<std::vector<int>>& board_, int x, int y)
{
	if (y == 0 || y == 2)
	{
		if (y == 0)
		{
			if (board_[x][y + 1] > board_[x][y + 2])
			{
				yx = x; yy = y + 1;
				return board_[x][y + 1];
			}
			else
			{
				yx = x; yy = y + 2;
				return board_[x][y + 2];
			}
			
		}
		else
		{
			if (board_[x][y - 1] > board_[x][y - 2])
			{
				yx = x; yy = y - 1;
				return board_[x][y - 1];
			}
			else
			{
				yx = x; yy = y - 2;
				return board_[x][y - 2];
			}
		}
	}
	else
	{
		if (board_[x][y + 1] > board_[x][y - 1])
		{
			yx = x; yy = y - 1;
			return board_[x][y + 1];
		}
		else
		{
			yx = x; yy = y - 1;
			return board_[x][y - 1];
		}
	}
}

//returns summation for diagnal of last index for 3 in a row and returns results
int Tictactoe::checkZ(std::vector<std::vector<int>>& board_, int p, int x, int y)
{	//TODO:: check this for issue with cpu win
	if (board_[1][1] == p)
	{
		if (x == 1 && y == 1)
		{
			//needs to check both ways maybe switch others to this format?
			if ((p == board_[0][0] && p == board_[2][2]) || (p == board_[0][2] && p == board_[2][0]))
				return p * 3;
		}
		if (x < 1) {
			if (y < 1)
			{
				addSpaceVal(board_, 2, 2);
				return board_[x][y] + board_[2][2] + p;
			}
			if (y > 1)
			{
				addSpaceVal(board_, 2, 0);
				return board_[x][y] + board_[2][0] + p;
			}
			else
			{
				return 0;
			}
		}
		if (x > 1)
		{
			if (y < 1)
			{
				addSpaceVal(board_, 0, 2);
				return board_[x][y] + board_[0][2] + p;
			}
			if (y > 1)
			{
				addSpaceVal(board_, 0, 0);
				return board_[x][y] + board_[0][0] + p;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int Tictactoe::maxcheckZ(std::vector<std::vector<int>>& board_, int x, int y)
{
	if (x == 1 && y == 1)
	{
		//needs to check both ways maybe switch others to this format?
		if ((board_[0][0] + board_[2][2]) > (board_[0][2] + board_[2][0]))
		{
			if (board_[0][0] > board_[2][2])
			{
				zx = 0; zy = 0;
				return board_[0][0];
			}
			else
			{
				zx = 2; zy = 2;
				return board_[2][2];
			}
		}
		else
		{
			if (board_[0][2] > board_[2][0])
			{
				zx = 0; zy = 2;
				return board_[0][2];
			}
			else
			{
				zx = 2; zy = 0;
				return board_[2][0];
			}
		}
	}
	if (x < 1) {
		if (y < 1)
		{
			if (board_[2][2] > board_[1][1])
			{
				zx = 2; zy = 2;
				return board_[2][2];
			}
			else
			{
				zx = 1; zy = 1;
				return board_[1][1];
			}

		}
		if (y > 1)
		{
			if (board_[2][0] > board_[1][1])
			{
				zx = 2; zy = 0;
				return board_[2][0];
			}
			else
			{
				zx = 1; zy = 1;
				return board_[1][1];
			}
		}
		else
		{
			return 0;
		}
	}
	if (x > 1)
	{
		if (y < 1)
		{
			if (board_[0][2] > board_[1][1])
			{
				zx = 0; zy = 2;
				return board_[0][2];
			}
			else
			{
				zx = 1; zy = 1;
				return board_[1][1];
			}
		}
		if (y > 1)
		{
			if (board_[0][0] > board_[1][1])
			{
				zx = 0; zy = 0;
				return board_[0][0];
			}
			else
			{
				zx = 1; zy = 1;
				return board_[1][1];
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

}

//takes player input converts it to xy, and places on board_
void Tictactoe::playerInput(std::vector<std::vector<int>>& board_)
{
	std::cout << "enter your placement\n";
	int c;
	std::cin >> c;
	inputToV(board_, -3, c);
	convertXY(c);
}

//sets player input onto the board;
void Tictactoe::inputToV(std::vector<std::vector<int>>& board_, int p, int c)
{
	switch (c)
	{
	case 0: board_[0][0] = p; break;
	case 1: board_[1][0] = p; break;
	case 2: board_[2][0] = p; break;
	case 3: board_[0][1] = p; break;
	case 4: board_[1][1] = p; break;
	case 5: board_[2][1] = p; break;
	case 6: board_[0][2] = p; break;
	case 7: board_[1][2] = p; break;
	case 8: board_[2][2] = p; break;
	}
}

//converts the player input to x, y cordinates for board_
void Tictactoe::convertXY(int p) 
{
	switch (p)
	{
	case 0: x = 0; y = 0; break;
	case 1: x = 1; y = 0; break;
	case 2: x = 2; y = 0; break;
	case 3: x = 0; y = 1; break;
	case 4: x = 1; y = 1; break;
	case 5: x = 2; y = 1; break;
	case 6: x = 0; y = 2; break;
	case 7: x = 1; y = 2; break;
	case 8: x = 2; y = 2; break;
	}
}

//draws the placement guide
void Tictactoe::drawGuide() 
{
	std::cout << "0|1|2" << '\n' << "3|4|5" << '\n' << "6|7|8" << '\n' << '\n';
}

void Tictactoe::addSpaceVal(std::vector<std::vector<int>>& board_, int x, int y)
{
	if (board_[x][y] > 0)
	{
		board_[x][y]++;
	}
}


