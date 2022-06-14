#include "battledotnet.h"

BattleDot::BattleDot(unsigned int num_player) {

	num = num_player;
	//creates a player for the number of players that entered
	for (unsigned int i = 0; i < num; i++)
		alive.push_back(new Player(i));
	//sets the target of each player to the next, and the final added player to the first player
	//so as each player can only attack the next person
	for (unsigned int i = 0; i < num; i++) {
		if (i == num - 1)
			(alive[i])->setTarget(alive[0]);
		else
			(alive[i])->setTarget(alive[i + 1]);
	}
}

void BattleDot::Battle(Player* player) {

	//simulates battle rounds until only one player remains
	do {
		if (player->isDead()) {
			//no further actions once dead
			this_thread::sleep_for(chrono::milliseconds(1));
			break;
		}

		//selects a point in target grid to bomb
		pair <int, int> bomb = player -> selectPoint(player->getTarget());
		bool kill = player->Bomb(bomb);
		
		cout << "Player " << player->getID() << " has bombed Player " << (player->getTarget())->getID() 
			<< " at (" << bomb.first << "," << bomb.second << ").";
		//if target's ship hit by player, retreives target's target and assigns that to the player's 
		if (kill) {
			m.lock();
			dead++;
			cout << " Hit!" << endl;
			cout << "Player " << (player->getTarget())->getID() << " has been eliminated!" << endl;

			//reassigns the killed target as long as there are other targets remaining
			if (dead < alive.size() - 1) {
				unsigned int i = player->getID();
				for (unsigned int j = 0; j < alive.size(); j ++) {
					++i;
					if (i == alive.size()) {
						i = 0;
					}
					//finds a target thats not self or dead
					if(! alive[i]->isDead() && alive[i]->getID() != player->getID()) {
						player -> setTarget(alive[i]);
						break;
					}
				}
			}
			m.unlock();
		} 
		else
			cout << " Miss!" << endl;

		//no further actions until all players have finished their round
		this_thread::sleep_for(chrono::milliseconds(1));
	} while (dead != alive.size() - 1);

}

void BattleDot::Play() {

	//creates a new thread for each player
	for (unsigned int i = 0; i < num; i++) {
		threads->push_back(new thread(&BattleDot::Battle, this, alive[i]));
	}

	//thread process executes
	for (unsigned int i = 0; i < num; i++) {
		threads->operator[](i)->join();
	}

	int winner;
	//finds the last player alive
	for (int i = 0; i < alive.size(); i++) {
		if(!alive[i] ->isDead())
			winner = alive[i] -> getID();
	}
	cout << "Player " << winner << " is the winner!" << endl;
}

BattleDot::~BattleDot() {
	//deletes all the user threads
	for (int i = 0; i < (int)threads->size(); i++)
		delete threads->operator[](i);
	delete threads;
}