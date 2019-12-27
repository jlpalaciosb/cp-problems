#include <iostream>
#include <queue>
#define INF 1000000000
using namespace std;

int s, t, r, rv[10], dist[10000];

void bfs() {
	for (int i = 0; i < 10000; ++i) dist[i] = INF;
	dist[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) return;
		for (int i = 0; i < r; ++i) {
			int v = (u + rv[i]) % 10000;
			if (dist[v] == INF) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
	int tc = 0;
	while (cin >> s >> t >> r, r != 0) {
		for (int i = 0; i < r; ++i) cin >> rv[i];
		bfs();
		if (dist[t] == INF)
			printf("Case %d: Permanently Locked\n", ++tc);
		else
			printf("Case %d: %d\n", ++tc, dist[t]);
	}
	return 0;
}
