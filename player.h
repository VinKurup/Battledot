#ifndef _PLAYER_H
#define _PLAYER_H
#include <algorithm>
#include <cstdlib>
#include "grid.h"
using namespace std;


class Player {

public:
	//creates a player with an associated integer ID, battledot grid, and initial target
	Player(int id);

	//check if bomb successfully hit
	bool Bomb(pair <int, int> point);

	//select point on target grid
	pair<int, int> selectPoint(Player* target);

	//check if player's ship has been sunk
	bool isDead();

	//retrieve player ID
	int getID();

	//retrieve target player
	Player* getTarget();

	//assign player a target
	void setTarget(Player* new_target);

	~Player();

private:
	//the player's battledot grid
	Grid* grid;

	//the player's ID
	int ID;

	//the player's target
	Player* target;
};
#endif