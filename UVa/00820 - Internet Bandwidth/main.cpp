#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
typedef vector<int> vi;

int n, s, t, res[101][101], f;
vi p;

void augment(int v, int min_edge) {
	if (v == s) {
		f = min_edge;
	} else {
		int u = p[v];
		if (u != -1) {
			augment(u, min(min_edge, res[u][v]));
			res[u][v] -= f;
			res[v][u] += f;
		}
	}
}

int max_flow() {
	int mf = 0;
	do {
		vi dist(n + 1, INF); dist[s] = 0;
		queue<int> q; q.push(s);
		p.assign(n + 1, -1);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == t) break;
			for (int v = 1; v <= n; ++v) {
				if (res[u][v] > 0 && dist[v] == INF) {
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		f = 0; augment(t, INF);
		mf += f;
	} while (f > 0);
	return mf;
}

int main() {
	int net = 0;
	while (cin >> n, n != 0) {
		scanf("%d%d", &s, &t);
		memset(res, 0, sizeof res);
		int c; scanf("%d", &c); for (int i = 0; i < c; ++i) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			res[u][v] += w; res[v][u] += w;
		}
		printf("Network %d\n", ++net);
		printf("The bandwidth is %d.\n\n", max_flow());
	}
	return 0;
}
