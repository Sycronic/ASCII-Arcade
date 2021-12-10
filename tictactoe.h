#include "game.h"

class Tictactoe : public Game
{
public:
	Tictactoe();

	void play();
	

private:
	std::vector<std::vector<int>> board_
	{
	   {1, 1, 1},
	   {1, 1, 1},
	   {1, 1, 1}

	};
	bool gameOver = false;
	int x;
	int y;

	void gLogic(std::vector<std::vector<int>>& board_);
	char checkSpace(int x);
	bool checkifWon(std::vector<std::vector<int>>& board_, int p, int x, int y);
	void Draw(std::vector<std::vector<int>>& board_);
	int checkX(std::vector<std::vector<int>>& board_, int x, int y);
	int checkY(std::vector<std::vector<int>>& board_, int x, int y);
	int checkZ(std::vector<std::vector<int>>& board_, int p, int x, int y);
	void playerInput(std::vector<std::vector<int>>& board_);
	void inputToV(std::vector<std::vector<int>>& board_, int p, int c);
	void convertXY(int p);
};
