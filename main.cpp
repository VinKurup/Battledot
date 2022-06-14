#include "battledotnet.h"

using namespace std;

int main(int argc, char* argv[]) {

	//checks if valid argument provided
	if (argc != 2) {
		printf("The number arguments supplied is %d. Please supply a single integer argument as ./battledotnet <num_players>.\n", (argc - 1));
		return -1;
	}

	unsigned int num_players;
	try {
		num_players = (unsigned int) stoi(argv[1]);
	}
	catch (...) {
		printf("Please enter a valid postive integer.\n");
		return -1;
	}

	//checks for at least 2 players
	if (num_players < 2) {
		printf("Please enter an integer value of 2 or more.\n");
		return -1;
	}

	BattleDot battledot(num_players);
	battledot.Play();

	return 0;
}