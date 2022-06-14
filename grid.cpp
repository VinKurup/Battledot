#include "grid.h"

Grid::Grid(unsigned int rows, unsigned int cols) {

	//creates a 10x10 grid and fills it with '.', indicating avaiable spot to be bombed
	grid = new char* [rows];
	for (unsigned int i = 0; i < rows; i++) {
		grid[i] = new char[cols];
		for (unsigned int j = 0; j < cols; j++) {
			grid[i][j] = '.';
			//coord->push_back(make_pair(i, j));
		}
	}
	//places a ship on the grid;
	genShip();
}

void Grid::genShip() {
	//uniformly distributes probability of selecting indices 0-9
	uniform_int_distribution<int> dist(0, 9);
	random_device rnd_seed;
	minstd_rand rnd_gen {rnd_seed()};
	//randomly chooses a row and column to place the ship indicator 's'
	grid[dist(rnd_gen)][dist(rnd_gen)] = 's';
}

bool Grid::isShip(pair<int, int> point) {

	//checks if the selected point was a ship
	if (grid[point.first][point.second] == 's') {
		isHit = true;
		return true;
	}
	grid[point.first][point.second] = 'm';
	return false;

}

void Grid::notBombed(vector<pair<int, int>>* coord) {
	//loops through the grid and creates an integer pair
	//for every point that has not been bombed
	for (unsigned int i = 0; i < rows; i++)
		for (unsigned int j = 0; j < cols; j++){

			if (grid[i][j] == '.' || grid[i][j] == 's')
				coord->push_back(make_pair(i, j));
		}
}

bool Grid::sunk() {
	return isHit;
}

Grid::~Grid() {
	//delete the battledot grid
	for (unsigned int i = 0; i < cols; i++)
		delete[] grid[i];
	delete[] grid;
}
