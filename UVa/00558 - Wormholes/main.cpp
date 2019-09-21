#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;

int n, m, dist[1000];
vector<ii> adj[1000];

void bellman_ford() {
	for (int i = 0; i < n; ++i) dist[i] = INF;
	for (int i = 0; i < n; ++i) {
		for (int u = 0; u < n; ++u) {
			for (int j = 0; j < adj[u].size(); ++j) {
				int v = adj[u][j].first, w = adj[u][j].second;
				dist[v] = min(dist[v], dist[u] + w);
			}
		}
	}
}

bool has_neg_cycle() {
	for (int u = 0; u < n; ++u) {
		for (int j = 0; j < adj[u].size(); ++j) {
			int v = adj[u][j].first, w = adj[u][j].second;
			if (dist[u] + w < dist[v]) return true;
		}
	}
	return false;
}

int main() {
	int c; cin >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) adj[i].clear();
		for (int i = 0; i < m; ++i) {
			int u, v, w; cin >> u >> v >> w;
			adj[u].push_back(ii(v, w));
		}
		bellman_ford();
		if (has_neg_cycle()) cout << "possible" << endl;
		else cout << "not possible" << endl;
	}
	return 0;
}
