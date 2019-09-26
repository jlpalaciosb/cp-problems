#include <iostream>
#include <map>
#define INF 1000000000
using namespace std;

int p, r, dist[50][50];
map<string,int> index;

void init_mat() {
	for (int i = 0; i < p; ++i)
		for (int j = 0; j < p; ++j)
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
}

void floyd_warshall() {
	for(int k = 0; k < p; k++)
		for (int i = 0; i < p; ++i)
			for (int j = 0; j < p; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int diameter() {
	int d = 0;
	for (int i = 0; i < p; ++i)
		for (int j = 0; j < p; ++j)
			d = max(d, dist[i][j]);
	return d;
}

int main() {
	int net = 1;
	while (cin >> p >> r, p != 0) {
		int c = 0;
		index.clear();
		init_mat();
		for (int i = 0; i < r; ++i) {
			string n1, n2; cin >> n1 >> n2;
			if (index.count(n1) == 0) index[n1] = c++;
			if (index.count(n2) == 0) index[n2] = c++;
			dist[index[n1]][index[n2]] = 1;
			dist[index[n2]][index[n1]] = 1;
		}
		floyd_warshall();
		int d = diameter();
		if (d == INF) printf("Network %d: DISCONNECTED\n\n", net++);
		else printf("Network %d: %d\n\n", net++, d);
	}
	return 0;
}
