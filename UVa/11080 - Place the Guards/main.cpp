#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vi::iterator vi_it;

int T, V, E;
vvi graph;

int visited[200], color[200];
int count[2], bipartite;

void dfs(int u, int c) {
	visited[u] = 1; color[u] = c; count[c]++;
	for (vi_it it = graph[u].begin(); it != graph[u].end(); it++) {
		int v = *it;
		if (!visited[v]) dfs(v, 1 - c);
		if (color[v] == c) bipartite = 0;
	}
}

int main() {
	cin >> T;
	while (T--) {
		cin >> V >> E;
		graph.clear(); graph.resize(V);
		for (int e = 0; e < E; e++) {
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		memset(visited, 0, sizeof visited);

		int ans = 0;
		for (int v = 0; v < V; v++) {
			if (!visited[v]) {
				bipartite = 1;
				count[0] = count[1] = 0;
				dfs(v, 0);
				if (!bipartite) { ans = -1; break; }
				int m = min(count[0], count[1]);
				if (m == 0) m = 1;
				ans += m;
			}
		}

		cout << ans << endl;
	}
	return 0;
}
