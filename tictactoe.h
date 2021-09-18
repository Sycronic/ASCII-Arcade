#pragma once
#include <vector>

enum Space {UpLeft, Up, UpRight, Left, Middle, Right, DownLeft, Down, DownRight};
class Tictactoe
{
	Tictactoe::Tictactoe()
	{
	}
private:
	std::vector<int> board_ = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
public:
	void PrintBoard(std::vector<int>board_);
	void EditBoard();
	void PlayerTurn();
	void ComTurn();
};