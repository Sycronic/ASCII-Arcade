#include "game.h"

void Game::PrintBoard(std::vector<int> board_)
{
	for (int i = 0; i < board_.size(); i++)
		std::cout << board_.at(i) << ' ';
}

void Game::EditBoard()
{
}

void Game::PlayerTurn()
{
}

void Game::ComTurn()
{
}
