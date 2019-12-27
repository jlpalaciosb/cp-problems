#include <iostream>
#include <cstring>
#define INF 1000000000
using namespace std;

int dist[110][110], f[110];

void init_mat() {
	for (int i = 1; i <= 100; ++i)
		for (int j = 1; j <= 100; ++j)
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
}

void floyd_warshall() {
	for (int k = 1; k <= 100; ++k)	
		for (int i = 1; i <= 100; ++i)
			for (int j = 1; j <= 100; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
	int tc = 0;
	while (true) {
		int n = 0;
		memset(f, 0, sizeof f);
		init_mat();
		while (true) {
			int u, v; cin >> u >> v; if (u == 0) break;
			dist[u][v] = 1;
			if (!f[u]) n++;
			if (!f[v]) n++;
			f[u] = f[v] = true;
		}
		if (n == 0) break;
		floyd_warshall();
		int sum = 0;
		for (int i = 1; i <= 100; ++i)
			for (int j = 1; j <= 100; ++j)
				if (dist[i][j] != INF) sum += dist[i][j];
		printf("Case %d: average length between pages = %.3f clicks\n",
			++tc, (double)sum / (double)(n * (n - 1)));
	}
	return 0;
}
