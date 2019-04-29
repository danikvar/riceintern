


># Game and Player classes - Daniel Varivoda Session 2P
> This program runs a rock paper scissors game using a two classes: Game and Player.
>  The Player class serves as representation of the player storing win streak, turn count, name, and move.
>  The Game class takes two player objects as inputs and when the 'game_start()' function is called, plays the game for a user specified number of rounds
>  A player gets a point for each win and a bonus multiplier for each win streak. If a player wins 3 times in a row they only have two options consisting of their last picked move and a random choice between the remaining two.
>  Once the round limit is up the player with the most points win and the programs is ready to exit
>  ---
>  # Code:
>  
>  ## Classes:
>  The Player class serves as representation of the player storing win streak, turn count, name, and move. It has functions to update and return each of these values as needed.
>  The Game class takes in two player objects and plays a of rock paper scissors with them. It takes in a specified number of rounds and has each of the players choose a move until the the round limit is reached, comparing scores and announcing a winner at the end.
>  
>  ## Member Variables:
>  ### Player:
>  'int m_curr' - denotes the current move with 1, 2, 3 representing rock, paper, scissors respectively
>  'std::string name'  - denotes the players name
>  'int wins' - denotes the players win streak
>  'int turn' - denotes the players turn number
>  'double score' - denotes the players score
>  ### Game:
>  'Player p1' && 'Player p2' - players that will be used to play the game
>  ## Member Functions:
>  ### Player:
>  'Player::Player()' - constructor for player class, set all member values to default
>  /**
	function to set the name for the player to a chosen string
	@param string n that you want t set the name to
	*/
	void setName(std::string n);
	/**
	function to increment a score by a certain value
	@param double num that you want to increment the score by
	*/
	void incr_score(double num);
	/**
	function to increment the turn counter by one
	*/
	void incr_turn();
	/**
	function that resets the win streak counter
	*/
	void loss();
	/**
	function that fetches the current win streak count for the player
	@return int wins which is the number of the win streak counter
	*/
	int get_wins();
	/**
	function that sets the players move to an int representing rock, paper, or scissors
	@param int x which represents the players move
	*/
	void set_m(int x);
	/**
	function that gets the players current score
	@return double score
	*/
	double get_score();

	/**
	functions that gets the players name as a string
	@return string name
	*/
	std::string get_name();

	/**
	function that gets the int representing the players move
	@return int m
	*/
	int get_m();

	/**
	function that gets the players current turn number
	@return int turn
	*/
	int get_turn();
### Game:


*'Game(Player p1, Player p2)' - constructor for the game class Initializes the game object with the two passed player objects.
	
	/**
	Function that runs the game for a specified number of rounds and shows who won in the end
	*/
	void start_game();
	
	/**
	Function for p1's turn where they choose their move for the round
	*/
	void turnp1();
	
	/**
	Function for p2's turn where they choose their move for the round
	*/
	void turnp2();
	
		/**
	Function comparing which palyer won the round and updating scores and winstreaks
	*/
	void compare();
