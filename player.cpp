#include "player.h"

Player::Player(int id) {
	ID = id;
	grid = new Grid(10, 10);
}

bool Player::Bomb(pair<int, int> point) {
	//return true if the target shit has been hit
	return (target->grid) -> isShip(point);
}

pair<int, int> Player::selectPoint(Player* target) {
	//return the coordinate selected on the target grid
	vector<pair<int, int>> coord;
	(target->grid)->notBombed(&coord);

	//randomly selects a point from the available grid points on target
	int point = rand() %(int)coord.size();
	return coord[point];
}

bool Player::isDead() {
	//return true if own ship is sunk/dead
	return grid->sunk();
}

int Player::getID() {
	return ID;
}

Player* Player::getTarget() {
	return target;
}

void Player::setTarget(Player* new_target) {
	target = new_target;
}

Player::~Player(){
	delete grid;
}