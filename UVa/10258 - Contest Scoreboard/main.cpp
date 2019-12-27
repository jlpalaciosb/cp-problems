#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int number;
	int solved;
	int penalty;
	bool problems_solved[10];
	int problems_penalty[10];
	bool submitted;
} contestant;

vector<contestant> constestants(101);

void init_contestants();
bool compare(contestant c1, contestant c2);

int main() {
	int n;
	cin >> n;
	getchar();
	getchar();

	for(int i = 1; i <= n; ++i) {
		init_contestants();

		while(true) {
			int C, P, T;
			char L;
			string submission;
			getline(cin, submission);
			if(submission == "") {
				break;
			}
			stringstream stream(submission);
			stream >> C >> P >> T >> L;
			if(L == 'C') {
				if(constestants[C].problems_solved[P] == false) {
					constestants[C].problems_solved[P] = true;
					constestants[C].penalty += T;
					constestants[C].penalty += constestants[C].problems_penalty[P];
					constestants[C].solved += 1;
				}
			} else if(L == 'I') {
				if(constestants[C].problems_solved[P] == false) {
					constestants[C].problems_penalty[P] += 20;
				}
			}
			constestants[C].submitted = true;
		}

		sort(constestants.begin() + 1, constestants.end(), &compare);

		for(int j = 1; j <= 100; ++j) {
			if(constestants[j].submitted == false) {
				continue;
			} else {
				cout << constestants[j].number << " ";
				cout << constestants[j].solved << " ";
				cout << constestants[j].penalty << endl;
			}
		}
		if(i != n) {
			cout << endl;
		}
	}
	return 0;
}

void init_contestants() {
	for(int i = 1; i <= 100; ++i) {
		constestants[i].number = i;
		constestants[i].solved = 0;
		constestants[i].penalty = 0;
		for(int j = 1; j <= 9; j++) {
			constestants[i].problems_solved[j] = false;
			constestants[i].problems_penalty[j] = 0;
		}
		constestants[i].submitted = false;
	}
}

bool compare(contestant c1, contestant c2) {
	if(c1.solved > c2.solved) {
		return true;
	} else if(c1.solved == c2.solved && c1.penalty < c2.penalty) {
		return true;
	} else if(c1.solved == c2.solved && c1.penalty == c2.penalty && c1.number < c2.number) {
		return true;
	} else {
		return false;
	}
}
