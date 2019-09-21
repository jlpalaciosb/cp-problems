#include <iostream>
#include <queue>
using namespace std;
#define INF  1000000000
typedef pair<int, int> ii;

int n, e, t, dist[110];
vector<vector<ii>> graph;

void dijkstra() {
	for (int i = 0; i < 110; ++i) dist[i] = INF;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	dist[e] = 0;
	pq.push(ii(0, e));
	while (!pq.empty()) {
		int u = pq.top().second, d = pq.top().first; pq.pop();
		if (dist[u] < d) continue;
		for (int i = 0; i < graph[u].size(); ++i) {
			int v = graph[u][i].second, w = graph[u][i].first;
			if (d + w < dist[v]) {
				dist[v] = d + w;
				pq.push(ii(dist[v], v));
			}
		}
	}
}

int main() {
	int TC; cin >> TC;
	for (int tc = 1; tc <= TC; ++tc) {
		cin >> n >> e >> t;

		graph.resize(n + 1); for (int i = 1; i <= n; ++i) graph[i].clear();
		int m; cin >> m;
		for (int i = 0; i < m; ++i) {
			int u, v, w; cin >> u >> v >> w;
			graph[v].push_back(ii(w, u));
		}

		dijkstra();

		int c = 0;
		for (int i = 1; i <= n; ++i) if (dist[i] <= t) c++;
		cout << c << endl;
		if (tc < TC) cout << endl;
	}
	return 0;
}
