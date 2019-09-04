#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

int n, m;
vector<vector<int>> adj;
int pv[10000], vis[10000];
int it, num[10000], low[10000], parent[10000], rc;

void dfs1(int u) {
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!vis[v]) dfs1(v);
	}
}

class cmp {
	public: bool operator ()(const ii &ii1, const ii &ii2) {
		int pv1 = ii1.first, pv2 = ii2.first;
		int u = ii1.second, v = ii2.second;
		return (pv1 > pv2 || (pv1 == pv2 && u < v));
	}
};

void articulation(int u) {
	vis[u] = 1;
	num[u] = low[u] = it++;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!vis[v]) {
			if (parent[u] == -1) rc++;
			parent[v] = u;
			articulation(v);
			if (num[u] <= low[v]) pv[u]++;
			low[u] = min(low[u], low[v]);
		} else if (v != parent[u]) {
			low[u] = min(low[u], low[v]);
		}
	}
}

int main() {
	while (true) {
		cin >> n >> m; if (n == 0 && m == 0) break;
		adj.clear(); adj.resize(n);
		while (true) {
			int u, v; cin >> u >> v;
			if (u == -1 && v == -1) break;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int cc = 0;
		memset(vis, 0, sizeof vis);
		for (int u = 0; u < n; u++) {
			if (!vis[u]) {
				cc++;
				dfs1(u);
			}
		}
		for (int u = 0; u < n; u++) pv[u] = cc;

		memset(vis, 0, sizeof vis); it = 0; rc = 0;
		for (int u = 0; u < n; u++) {
			if (!vis[u]) {
				parent[u] = -1;
				articulation(u);
				pv[u] = cc + rc - 1;
			}
		}

		vector<ii> ord;
		ord.clear(); ord.resize(n);
		for (int u = 0; u < n; u++) ord[u] = make_pair(pv[u], u);
		sort(ord.begin(), ord.end(), cmp());
		for (int i = 0; i < m; i++)
			cout << ord[i].second << " " << ord[i].first << endl;
		cout << endl;
	}
	return 0;
}
