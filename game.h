#pragma once
#include <vector>
#include <iostream>


// TODO: make this an overall game class then put tictactoe as a child class
enum Space {UpLeft, Up, UpRight, Left, Middle, Right, DownLeft, Down, DownRight};
class Game
{
	Game::Game()
	{
	}
private:
	std::vector<int> Tboard_;
	std::vector<int> Mboard_;
	std::vector<int> Bboard_;
	int ans;
	bool Pturn = true;
	int game = 0;
public:
	void ChangeGame(int g);
	void PrintBoard(std::vector<int>board_);
	void EditBoard();
	void PlayerTurn();
	void ComTurn();
	void ChangeTurn(bool Pturn);
};