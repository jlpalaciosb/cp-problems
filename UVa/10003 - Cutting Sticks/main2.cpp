#include <iostream>
#include <vector>
#define INF 1000000000
#define UNDEF -1
#define MAXL 1000

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VI cuts;
VVI costs;

int cost(int i, int f, int cl, int cr);

int main() {
	cuts.resize(MAXL);
	costs.resize(MAXL);
	for(int i = 0; i < MAXL; ++i) {
		costs[i].resize(MAXL);
	}

	while(true) {
		int l;
		cin >> l;
		if(l == 0) {
			break;
		}

		int n;
		cin >> n;		

		for(int i = 0; i < n; ++i) {
			cin >> cuts[i];
		}

		/* Inicializa todos los costos posibles a UNDEF */
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				costs[cuts[i]][cuts[j]] = UNDEF;
			}
			costs[0][cuts[i]] = UNDEF;
			costs[cuts[i]][l] = UNDEF;
		}
		costs[0][l] = UNDEF;

		cout << "The minimum cutting is " << cost(0, l, 0, n-1) << "." << endl;
	}

	return 0;
}

int cost(int xi, int xf, int cl, int cr) {
	if(costs[xi][xf] != UNDEF) {
		return costs[xi][xf];
	} else {
		if(cl > cr) { //no hay cortes
			costs[xi][xf] = 0;
			return 0;
		}
		if(cl == cr) { //uno solo corte
			costs[xi][xf] = xf - xi;
			return xf - xi;
		} else {
			int min = INF;
			for(int i = cl; i <= cr; ++i) {
				int costi;
				costi = cost(xi, cuts[i], cl, i - 1) + cost(cuts[i], xf, i + 1, cr);
				if(costi < min) {
					min = costi;
				}
			}
			int cost = (xf - xi) + min;
			costs[xi][xf] = cost;
			return cost;
		}
	}
}
