#include "tictactoe.h"

Tictactoe::Tictactoe()
{
		board_ = { 0 };
}

void Tictactoe::play()
{
	//TODO:: fix this
	gLogic(board_);
}

void Tictactoe::gLogic(std::vector<std::vector<int>>& board_)
{
	while (!gameOver)
	{
		playerInput(board_);
		Draw(board_);

		if (checkifWon(board_, -3, x, y))
		{
			gameOver = true;
			std::cout << "\nGame Over \n";
		}

		if (checkifWon(board_, -4, x, y))
		{
			gameOver = true;
			std::cout << "\nGame Over \n";
		}
	}
}

char Tictactoe::checkSpace(int x)
{
	switch (x)
	{
	case  -3: return 'O';
	case  -4: return 'X';
	default: return ' ';
	}
}

bool Tictactoe::checkifWon(std::vector<std::vector<int>>& board_, int p, int x, int y)
{
	int win = p * 3;
	if (win == checkX(board_, x, y) || checkY(board_, x, y) || checkZ(board_, p, x, y))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void Tictactoe::Draw(std::vector<std::vector<int>>& board_)
{
	std::cout << "0|1|2" << '\n' << "3|4|5|" << '\n' << "6|7|8";

	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			std::cout << checkSpace(board_[x][y]) << '|';
			if (y == 2) {
				std::cout << '\n';
			}
		}
	}
}

int Tictactoe::checkX(std::vector<std::vector<int>>& board_, int x, int y)
{
	if (x == 0 || 2) 
	{
		if (x == 0)
		{
			return board_[x][y] + board_[x + 1][y] + board_[x + 2][y];
		}
		else
		{
			return board_[x][y] + board_[x - 1][y] + board_[x - 2][y];
		}
	}
	else
	{
		return board_[x][y] + board_[x - 1][y] + board_[x + 1][y];
	}
}

int Tictactoe::checkY(std::vector<std::vector<int>>& board_, int x, int y)
{
	if (y == 0 || 2)
	{
		if (y == 0)
		{
			return board_[x][y] + board_[x][y + 1] + board_[x][y + 2];
		}
		else
		{
			return board_[x][y] + board_[x][y - 1] + board_[x][y - 2];
		}
	}
	else
	{
		return board_[x][y] + board_[x][y + 1] + board_[x][y - 1];
	}
}

int Tictactoe::checkZ(std::vector<std::vector<int>>& board_, int p, int x, int y)
{
	if (board_[1][1] == p)
	{
		if (x < 1) {
			if (y < 1)
			{
				return board_[x][y] + board_[2][2] + p;
			}
			if (y > 1)
			{
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
				return board_[x][y] + board_[0][2] + p;
			}
			if (y > 1)
			{
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

void Tictactoe::playerInput(std::vector<std::vector<int>>& board_)
{
	std::cout << "enter your placement\n";
	int c;
	std::cin >> c;
	inputToV(board_, c);
	convertXY(c);
}

void Tictactoe::inputToV(std::vector<std::vector<int>>& board_, int p)
{
	switch (p)
	{
	case 0: board_[0][0] = p;
	case 1: board_[1][0] = p;
	case 2: board_[2][0] = p;
	case 3: board_[0][1] = p;
	case 4: board_[1][1] = p;
	case 5: board_[2][1] = p;
	case 6: board_[0][2] = p;
	case 7: board_[1][2] = p;
	case 8: board_[2][2] = p;
	}
}

void Tictactoe::convertXY(int p)
{
	switch (p)
	{
	case 0: x = 0; y = 0;
	case 1: x = 1; y = 0;
	case 2: x = 2; y = 0;
	case 3: x = 0; y = 1;
	case 4: x = 1; y = 1;
	case 5: x = 2; y = 1;
	case 6: x = 0; y = 2;
	case 7: x = 1; y = 2;
	case 8: x = 2; y = 2;
	}
}


