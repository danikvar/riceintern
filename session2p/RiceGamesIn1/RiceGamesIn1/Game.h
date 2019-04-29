#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Player.h"

class Game
{
private:
	Player p1;
	Player p2;
public:
	Game(Player one, Player two);
	void start_game();
	void turnp1();
	void turnp2();
	void compare();

};


#endif // !GAME_H
