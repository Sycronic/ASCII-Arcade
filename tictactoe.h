#include "game.h"
#include <algorithm>
#include <iterator>

class Tictactoe : public Game
{
public:
	Tictactoe();

	void play();
	

private:
	std::vector<std::vector<int>> board_
	{
	   {2, 1, 2},
	   {1, 3, 1},
	   {2, 1, 2}

	};
	bool gameOver = false;
	int x;
	int y;
	int xx; int xy; int yx; int yy; int zx; int zy;

	void cpuLogic(std::vector<std::vector<int>>& board_);
	void gLogic(std::vector<std::vector<int>>& board_);
	char checkSpace(int x);
	bool checkifWon(std::vector<std::vector<int>>& board_, int p, int x, int y);
	void Draw(std::vector<std::vector<int>>& board_);
	int checkX(std::vector<std::vector<int>>& board_, int x, int y);
	int maxcheckX(std::vector<std::vector<int>>& board_, int x, int y);
	int checkY(std::vector<std::vector<int>>& board_, int x, int y);
	int maxcheckY(std::vector<std::vector<int>>& board_, int x, int y);
	int checkZ(std::vector<std::vector<int>>& board_, int p, int x, int y);
	int maxcheckZ(std::vector<std::vector<int>>& board_, int x, int y);
	void playerInput(std::vector<std::vector<int>>& board_);
	void inputToV(std::vector<std::vector<int>>& board_, int p, int c);
	void convertXY(int p);
	void drawGuide();
	void addSpaceVal(std::vector<std::vector<int>>& board_, int x, int y);
};
