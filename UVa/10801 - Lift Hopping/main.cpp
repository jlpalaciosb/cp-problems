#include <queue>
#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;
typedef pair<int, int> ii;

int n, k, t[5];
vector<int> pisos[5];
vector<ii> graph[100];
int dist[100];

void construct_graph() {
	for (int i = 0; i < 100; ++i) graph[i].clear();
	for (int e = 0; e < n; ++e) {
		int np = pisos[e].size();
		for (int i = 0; i < np; ++i) {
			int u = pisos[e][i];
			for (int j = 0; j < np; ++j) {
				int v = pisos[e][j];
				if (u == v) continue;
				int w = abs(u - v) * t[e] + 60;
				if (v == k) w -= 60;
				graph[u].push_back(ii(v, w));
			}
		}
	}
}

void dijkstra() {
	for (int i = 0; i < 100; ++i) dist[i] = INF;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	dist[0] = 0;
	pq.push(ii(0, 0));
	while (!pq.empty()) {
		int u = pq.top().second, d = pq.top().first; pq.pop();
		if (u == k) break;
		if (dist[u] < d) continue;
		for (int i = 0; i < graph[u].size(); ++i) {
			int v = graph[u][i].first, w = graph[u][i].second;
			if (d + w < dist[v]) {
				dist[v] = d + w;
				pq.push(ii(dist[v], v));
			}
		}
	}
}

int main() {
	while (scanf("%d%d", &n, &k) == 2) {
		for (int i = 0; i < n; ++i) cin >> t[i];
		int e = 0;
		while (e < n) {
			pisos[e].clear();
			while (true) {
				int p; cin >> p; pisos[e].push_back(p);
				char c; c = getchar();
				if (c == '\n' || c == EOF) break;
			}
			e++;
		}

		construct_graph();
		dijkstra();
		if (dist[k] != INF) cout << dist[k] << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
