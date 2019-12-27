#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

int main() {
	int cases;
	cin >> cases;
	for(int i = 1; i <= cases; ++i) {
		int n_players, n_snakes, n_rolls;
		VI pos_players(1000000), snakes_tails(101);
		bool game_over;

		cin >> n_players >> n_snakes >> n_rolls;
		pos_players.assign(n_players, 1);
		snakes_tails.assign(101, -1);
		game_over = false;

		for(int j = 1; j <= n_snakes; ++j) {
			int mouth, tail;
			cin >> mouth >> tail;
			snakes_tails[mouth] = tail;
		}

		int turn = 0;
		for(int j = 1; j <= n_rolls; ++j) {
			int rolled;
			cin >> rolled;
			if(!game_over) {
				pos_players[turn] += rolled;
				if(pos_players[turn] >= 100) {
					pos_players[turn] = 100;
				} else if(snakes_tails[pos_players[turn]] != -1) {
					pos_players[turn] = snakes_tails[pos_players[turn]];
				}
				if(pos_players[turn] == 100) {
					game_over = true;
				}
			}
			turn = (turn + 1) % n_players;
		}

		for(int j = 0; j < n_players; j++) {
			cout << "Position of player " << (j + 1) << " is " << pos_players[j] << "." << endl;
		}
	}

	return 0;
}
