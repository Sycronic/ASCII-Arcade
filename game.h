#pragma once
#include <vector>
#include <iostream>


enum Space {UpLeft, Up, UpRight, Left, Middle, Right, DownLeft, Down, DownRight};
class Game
{
private:
	int ans;
	int game = 0;

	void input();

public:
	void ChangeGame(int g); //redundant probably remove use source.cpp for this
};