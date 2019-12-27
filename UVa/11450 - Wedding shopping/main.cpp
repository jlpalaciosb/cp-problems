// Solución del ejercicio 3.5.1.3 de CP3 de Halim

#include <iostream>
#include <cstring>

using namespace std;

int N, M, C, K;
int price[20][20];
int qom[20];
bool reachable[2][201];

int main(int argc, char const *argv[]) {
	cin >> N;
	while (N--) {
		cin >> M >> C;
		for (int g = 0; g < C; ++g) {
			cin >> K; qom[g] = K;
			for (int model = 0; model < qom[g]; ++model) {
				cin >> price[g][model];
			}
		}
		memset(reachable, false, sizeof reachable);

		for (int model = 0; model < qom[0]; ++model) {
			int money = M - price[0][model];
			if (money >= 0) reachable[0][money] = true;
		}

		int cur = 1, prev = 0;
		for (int g = 1; g < C; ++g) {
			for (int money = 0; money <= 200; ++money) {
				if (reachable[prev][money]) {
					for (int model = 0; model < qom[g]; model++) {
						int nmoney = money - price[g][model];
						if (nmoney >= 0) reachable[cur][nmoney] = true;
					}
				}
			}
			memset(reachable[prev], false, sizeof reachable[prev]);
			int tmp = cur; cur = prev; prev = tmp;
		}

		bool solution = false;
		for (int money = 0; money <= 200; money++) {
			if (reachable[prev][money]) {
				cout << M - money << endl;
				solution = true;
				break;
			}
		}
		if (!solution) cout << "no solution" << endl;
	}
	return 0;
}
