#ifndef _Grid_H_
#define _Grid_H_
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <random>

using namespace std;

class Grid
{
public:
	//creates an assigned 10x10 battledot grid
	Grid(unsigned int rows, unsigned int cols);

	//selects random point on grid for ship
	void genShip();

	//check if selected point is ship point
	bool isShip(pair<int, int>);

	//check all open points on grid
	void notBombed(vector<pair<int, int>>*);

	//check if ship is sunk
	bool sunk();

	~Grid();

private:
	const unsigned int rows = 10;

	const unsigned int cols = 10;
	
	bool isHit = false;

	char** grid;
};
#endif