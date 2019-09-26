#include <iostream>
#include <vector>
#include <list>

using namespace std;

int load_piles(vector<list<int>> &piles);
int ganancia_ciel(list<int> &pile);
int ganancia_jiro(list<int> &pile);
int pop_first(list<int> &pile);
int pop_last(list<int> &pile);

int main() {
	int total_piles;
	cin >> total_piles;
	vector<list<int>> piles(total_piles);
	int total_cards = load_piles(piles);
	int ciel_score = 0, jiro_score = 0;
	string turn = "ciel";

	for(int i = 0; i < total_cards; ++i) {
		if(turn == "ciel") {
			int mp_pile_index = -1;
			int mp = 0;
			for(int j = 0; j < total_piles; ++j) {
				if(piles[j].size() > 0) {
					int p = ganancia_ciel(piles[j]);
					if(p > mp) {
						mp = p;
						mp_pile_index = j;
					}
				}
			}
			ciel_score += pop_first(piles[mp_pile_index]);
			turn = "jiro";
		} else {
			int mp_pile_index = -1;
			int mp = 0;
			for(int j = 0; j < total_piles; ++j) {
				if(piles[j].size() > 0) {
					int p = ganancia_jiro(piles[j]);
					if(p > mp) {
						mp = p;
						mp_pile_index = j;
					}
				}
			}
			jiro_score += pop_last(piles[mp_pile_index]);
			turn = "ciel";
		}
	}

	cout << ciel_score << " " << jiro_score << endl;

	return 0;
}

int load_piles(vector<list<int>> &piles) {
	int total_cards = 0;
	for (int i = 0; i < piles.size(); ++i) {
		int s;
		cin >> s;
		total_cards += s;
		for (int j = 0; j < s; ++j) {
			int e;
			cin >> e;
			piles[i].push_back(e);
		}
	}
	return total_cards;
}

int ganancia_ciel(list<int> &pile) {
	int sum = 0;
	int c = pile.size() % 2 == 0 ? pile.size() / 2 : pile.size() / 2 + 1;
	list<int>::iterator it = pile.begin();
	for(int i = 0; i < c; ++i) {
		sum += *it;
		++it;
	}
	return sum;
}

int ganancia_jiro(list<int> &pile) {
	int sum = 0;
	int c = pile.size() % 2 == 0 ? pile.size() / 2 : pile.size() / 2 + 1;
	list<int>::iterator it = pile.end();
	for(int i = 0; i < c; ++i) {
		--it;
		sum += *it;
	}
	return sum;
}

int pop_first(list<int> &pile) {
	list<int>::iterator it = pile.begin();
	int ret = *it;
	pile.erase(it);
	return ret;
}

int pop_last(list<int> &pile) {
	list<int>::iterator it = pile.end();
	--it;
	int ret = *it;
	pile.erase(it);
	return ret;
}
