#include <iostream>
#include "Game.h";
#include "Player.h";
int main()
{
	Player one = Player();
	Player two = Player();
	Game g = Game(one, two);
	g.start_game();
	return 0;
}