#include "Game.h"
#include <iostream>
#include <string>
#include <list>

Game::Game(Player one, Player two)
{
	p1 = one;
	p2 = two;
}

void Game::start_game()
{
	int rounds;
	std::cout << "Please enter the number of rounds to play: \n";
	std::cin >> rounds;
	std::string p1n;
	std::cout << "Please, enter your name Player 1: ";
	std::getline(std::cin, p1n);
	std::getline(std::cin, p1n);
	std::string p2n;
	std::cout << "Please, enter your name Player 2: ";
	std::getline(std::cin, p2n);
	std::cout << "\n";
	p1.setName(p1n);
	p2.setName(p2n);
	turnp1();
	//makes p1 start first so the game can differentiate turns
	while (p1.get_turn() < rounds || p2.get_turn() < rounds) //while under the round limit for either players
	{
		if (p1.get_turn() > p2.get_turn()) //if p1 haas taken a turn it is p2's turn
		{
			turnp2();
		}
		else //if both have taken their turns compare their moves, output their updated scores, and start the next round
		{
			compare();
			std::cout << "The score for " << p1.get_name() << " is: " << p1.get_score() << "\n";
			std::cout << "The score for " << p2.get_name() << " is: " << p2.get_score() << "\n";
			std::cout << "*************  ROUND " << p1.get_turn() + 1 << "  ************* \n";
			turnp1();
		}
	}
	if (p1.get_score() > p2.get_score()) //if p1 has a higher ending score they win
	{
		std::cout << p1.get_name() << " wins! \n";
		std::cout << "The score for " << p1.get_name() << " is: " << p1.get_score() << "\n";
		std::cout << "The score for " << p2.get_name() << " is: " << p2.get_score() << "\n";
	}
	if (p2.get_score() > p1.get_score()) //if p2 has a higher ending score they win
	{
		std::cout << p2.get_name() << " wins! \n";
		std::cout << "The score for " << p1.get_name() << " is: " << p1.get_score() << "\n";
		std::cout << "The score for " << p2.get_name() << " is: " << p2.get_score() << "\n";
	}
	if (p1.get_score() == p2.get_score()) //if ending scores are equal it is a tie
	{
		std::cout << "It's a tie \n";
		std::cout << "The score for " << p1.get_name() << " is: " << p1.get_score() << "\n";
		std::cout << "The score for " << p2.get_name() << " is: " << p2.get_score() << "\n";
	}
	char c;
	std::cin >> c; // press enter to end game
}

void Game::turnp1()
{
	p1.incr_turn(); //increase p1's turn counter
	std::cout << p1.get_name() << " please use keys 1, 2, or 3 to pick rock, paper, or scissors respectively \n";
	if (p1.get_wins() % 3 == 0 && p1.get_wins() > 0) //if won 3 in a row only have two options
	{
		std::list<int> l = {1, 2, 3};
		int one = p1.get_m();
		l.remove(p1.get_m());
		int pick = rand() % 2 + 1;
		int two = 0;
		if (pick == 1) //randomly either remove the front or back option to leave only one option other than the last picked move
		{
			l.pop_back();
			two = l.front();
		}
		else
		{
			l.pop_front();
			two = l.front();
		}
		std::cout << "You have won 3 times in a row you may only choose keys " << one << " and " << two << "\n";
		int m;
		std::cin >> m;
		while (m != one && m != two)
		{
			std::cout << "please enter a valid key \n";
			std::cin >> m;
		}
		p1.set_m(m);
	}
	else //if player hasnt won 3 times in a row get any of the 3 choices
	{
		int n;
		std::cin >> n;
		p1.set_m(n);
	}
}

void Game::turnp2()
{
	p2.incr_turn();
	std::cout << p2.get_name() << " please use keys 1, 2, or 3 to pick rock, paper, or scissors respectively \n";
	if (p2.get_wins() % 3 == 0 && p2.get_wins() > 0)
	{
		std::list<int> l = { 1, 2, 3 };
		int one = p2.get_m();
		l.remove(p2.get_m());
		int pick = rand() % 2 + 1;
		int two = 0;
		if (pick == 1)
		{
			l.pop_back();
			two = l.front();
		}
		else
		{
			l.pop_front();
			two = l.front();
		}
		std::cout << "You have won 3 times in a row you may only choose keys " << one << " and " << two << "\n";
		int m;
		std::cin >> m;
		while (m != one && m != two)
		{
			std::cout << "please enter a valid key \n";
			std::cin >> m;
		}
		p2.set_m(m);
	}
	else
	{
		int n;
		std::cin >> n;
		p2.set_m(n);
	}
}

void Game::compare()
{
	double p1m;
	double p2m;
	if (p1.get_wins() > 0) //if p1 has a winstreak started calculate the bonus mutiplier for winning
	{
		p1m = ((p1.get_wins() - 1) * .3) + 1.2;
	}
	else //else no multiplier
	{
		p1m = 1.0;
	}
	if (p2.get_wins() > 0) //same for if p2 wins
	{
		p2m = ((p2.get_wins() - 1) * .3) + 1.2;
	}
	else
	{
		p2m = 1.0;
	}
	if (p1.get_m() == p2.get_m()) //if same move, its a tie, neither score and both lose thier streak
	{
		std::cout << "It's a tie! \n";
		p1.loss();
		p2.loss();
	}
	//else check moves against each other and update winstreak and score for both players
	else if (p1.get_m() == 1 && p2.get_m() == 2)
	{
		p2.incr_score(1*p2m);
		p1.loss();
		std::cout << p2.get_name() << " wins this round with paper \n";
	}
	else if (p1.get_m() == 1 && p2.get_m() == 3)
	{
		p1.incr_score(1*p1m);
		p2.loss();
		std::cout << p1.get_name() << " wins this round with rock \n";
	}

	else if (p1.get_m() == 2 && p2.get_m() == 3)
	{
		p2.incr_score(1 * p2m);
		p1.loss();
		std::cout << p2.get_name() << " wins this round with scissors \n";
	}
	else if (p1.get_m() == 2 && p2.get_m() == 1)
	{
		p1.incr_score(1 * p1m);
		p2.loss();
		std::cout << p1.get_name() << " wins this round with paper \n";
	}
	else if (p1.get_m() == 3 && p2.get_m() == 1)
	{
		p2.incr_score(1 * p2m);
		p1.loss();
		std::cout << p2.get_name() << " wins this round with rock \n";
	}
	else if (p1.get_m() == 3 && p2.get_m() == 2)
	{
		p1.incr_score(1 * p1m);
		p2.loss();
		std::cout << p1.get_name() << " wins this round with scissors \n";
	}
}
