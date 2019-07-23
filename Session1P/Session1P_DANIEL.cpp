#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	cout << "Right Road, Wrong Road" << "\n";
	cout << "A demon is loose in the kingdom and devours everything in its path " << "\n";
	cout << "A hero sets out to hunt down this demon before it destroys his village," << endl;
	cout <<"but he must take care to follow the correct path" << "\n";
	cout << "What is your name hero?:" << "\n";
	string name;
	getline(cin, name);
	bool alive = true;
	int turn = 1;
	size_t lives = 5;
	int demon;
	while (alive)
	{
		cout << "It is turn: " << turn << endl;
		cout << "You have " << lives << " lives left."<< endl;
		cout << "Choose the path you want to take to follow the demon:" << "\n";
		cout << "Press L to go down the left path and R to go down the right path" << "\n";
		char letter;
		cin >> letter;
		int player;
		switch (letter) {
		case 'r':
			cout << "You attempt to take the right path" << endl;
			player = 0;
			break;
		case 'l':
			cout << "You attempt to take the left path" << endl;
			player = 1;
			break;
		default:
			--turn;
			cout << "Invalid direction" << endl;
		}
		demon = rand() % 2;
		if (demon == player)
		{
			cout << "You have followed down the correct path" << endl;
		}
		else if (demon != player)
		{
			cout << "You travelled down the wrong path and lost valuable time. You lose a life" << endl;
			--lives;
		}
		if (lives == 0)
		{
			cout << "You have ran out of lives and your journey is finished " << name << endl;
			cout << "You had survived for " << turn << " turns." << endl;
			if (turn >= 20)
			{
				cout << "Amazing! The amount of turns you have survived grants you a S score on your journey" << endl;
			}
			else if (15 <= turn && turn <= 20)
			{
				cout << "Good job. The amount of turns you have survived grants you an A score on your journey" << endl;
			}
			else if (12 <= turn && turn <= 14)
			{
				cout << "Not Bad. The amount of turns you have survived grants you a B score on your journey" << endl;
			}
			else if (10<= turn && turn <= 11)
			{
				cout << "The amount of turns you have survived grants you a C score on your journey" << endl;
			}
			else if (6<= turn && turn <= 9)
			{
				cout << "The amount of turns you have survived grants you a D score on your journey" << endl;
			}
			else if (turn == 5)
			{
				cout << "You did not survive long and earned an F score for your journey" << endl;
			}
			cout << "THE END";
			alive = false;
		}
		++turn;
	}
	string str;
	getline(cin, str);
	string str1;
	getline(cin, str1);
	return 0;
}