#include <iostream>
#include <vector>
#define INF 100

using namespace std;

typedef vector<int> VI;

VI princess_cards(3);
VI princess_played;
VI prince_cards(2);
VI prince_played;

int get_prince_play();
int get_princess_play(int prince_play);
int get_prince_last_play(bool already_winning);
bool card_played(int card);

int main() {
	while(true) {
		cin >> princess_cards[0] >> princess_cards[1] >> princess_cards[2];
		cin >> prince_cards[0] >> prince_cards[1];
		if(princess_cards[0] == 0) {
			break;
		}

		int prince_score = 0;
		prince_played.clear();
		princess_played.clear();

		for (int i = 1; i <= 3; ++i) {
			if(i < 3) {
				int prince_play = get_prince_play();
				int princess_play = get_princess_play(prince_play);
				if(prince_play > princess_play) {
					prince_score += 1;
				} else {
					prince_score -= 1;
				}
			} else {
				if(prince_score == -2) {
					cout << -1 << endl;
				} else if(prince_score == 0) {
					cout << get_prince_last_play(false) << endl;
				} else if(prince_score == 2) {
					cout << get_prince_last_play(true) << endl;
				} else {
					cout << "Impossible llegar aquí!" << endl;
				}
			}
		}
	}

	return 0;
}

// Retorna la mayor carta aún no jugada
int get_prince_play() {
	int max = -1;
	for(int i = 0; i < prince_cards.size(); ++i) {
		bool played = false;
		for(int j = 0; j < prince_played.size(); ++j) {
			if(prince_cards[i] == prince_played[j]) {
				played = true;
				break;
			}
		}
		if(!played && prince_cards[i] > max) {
			max = prince_cards[i];
		}
	}
	prince_played.push_back(max);
	return max;
}

// Si es que tiene cartas con que puede superar retorna el menor con el que puede ganar si no
// retorna su menor carta no jugada
int get_princess_play(int prince_play) {
	int min1 = INF, min2 = INF;
	for(int i = 0; i < princess_cards.size(); ++i) {
		bool played = false;
		for(int j = 0; j < princess_played.size(); ++j) {
			if(princess_cards[i] == princess_played[j]) {
				played = true;
				break;
			}
		}
		if(!played && princess_cards[i] < min1 && princess_cards[i] > prince_play) {
			min1 = princess_cards[i];
		}
		if(!played && princess_cards[i] < min2) {
			min2 = princess_cards[i];
		}
	}
	if(min1 != INF) {
		princess_played.push_back(min1);
		return min1;
	} else {
		princess_played.push_back(min2);
		return min2;
	}
}

int get_prince_last_play(bool already_winning) {
	int princess_last_move;
	for(int i = 0; i < princess_cards.size(); ++i) {
		bool played = false;
		for(int j = 0; j < princess_played.size(); ++j) {
			if(princess_cards[i] == princess_played[j]) {
				played = true;
				break;
			}
		}
		if(!played) {
			princess_last_move = princess_cards[i];
			break;
		}
	}

	if(already_winning) { // Retorna la menor carta que no se jugo y que no sea igual a la ultima jugada de la princesa
		for(int i = 1; i <= 52; ++i) {
			if(!card_played(i) && i != princess_last_move) {
				return i;
			}
		}
		cout << "Impossible llegar aquí!" << endl;
	} else { // Retorna la menor carta que es mayor a la carta que le queda a la princesa
		for(int i = princess_last_move + 1; i <= 52; ++i) {
			if(!card_played(i)) {
				return i;
			}
		}
		return -1;
	}	
}

// retorna true si algun jugador jugo esta carta
bool card_played(int card) {
	for(int j = 0; j < prince_played.size(); ++j) {
		if(prince_played[j] == card) {
			return true;
		}
	}
	for(int j = 0; j < princess_played.size(); ++j) {
		if(princess_played[j] == card) {
			return true;
		}
	}
	return false;
}
