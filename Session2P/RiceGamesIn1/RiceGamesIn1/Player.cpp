#include "Player.h"

Player::Player()
{
	m_curr = 0;
	name = "";
	wins = 0;
	turn = 0;
	score = 0;
}

void Player::setName(std::string n)
{
	name = n;
}

void Player::incr_score(double num)
{
	score += num;
	++wins;
}

void Player::incr_turn()
{
	turn++;
}

void Player::loss()
{
	wins = 0;
}

int Player::get_wins()
{
	return wins;
}

void Player::set_m(int x)
{
	m_curr = x;
}

double Player::get_score()
{
	return score;
}

std::string Player::get_name()
{
	return name;
}

int Player::get_m()
{
	return m_curr;
}

int Player::get_turn()
{
	return turn;
}
