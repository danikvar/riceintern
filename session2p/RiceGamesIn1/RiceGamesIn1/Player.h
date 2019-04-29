#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class Player
{
private:
	int m_curr;
	std::string name;
	int wins;
	int turn;
	double score;
public:
	Player();
	void setName(std::string n);
	void incr_score(double num);
	void incr_turn();
	void loss();
	int get_wins();
	void set_m(int x);
	double get_score();
	std::string get_name();
	int get_m();
	int get_turn();
};
#endif // !PLAYER_H

