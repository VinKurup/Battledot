#ifndef _BATTLEDOTNET_H_
#define _BATTLEDOTNET_H_
#include "player.h"
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

class BattleDot{
/*
	Builds the playerbase and runs a game of BattleDot
*/
public:
	//create a game of battledot with the given number of players
	BattleDot(unsigned int num_player);

	//actions of players per round
	void Battle(Player* player);

	//plays through a whole game of BattleDot
	void Play();

	~BattleDot();

private:
	//the number of players at the start of the game
	unsigned int num;

	mutex m;

	//tracks the threads
	vector<thread*> *threads = new vector <thread*>;

	//tracks the players still alive
	vector <Player*> alive;

	unsigned int dead = 0;
};
#endif
