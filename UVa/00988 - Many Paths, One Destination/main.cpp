#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj;

vi memo;
int nump(int u) {
	int &r = memo[u];
	if (r > 0) return r;

	int e = adj[u].size();
	if (e == 0) {
		r = 1;
	} else {
		for (int i = 0; i < e; ++i) {
			r += nump(adj[u][i]);
		}
	}
	return r;
}

int main() {
	int V, tc = 0;
	while (scanf("%d", &V) == 1) {
		if (++tc > 1) cout << endl;

		adj.clear(); adj.resize(V);
		for (int u = 0; u < V; ++u) {
			int e; scanf("%d", &e);
			for (int j = 0; j < e; ++j) {
				int v; scanf("%d", &v);
				adj[u].push_back(v);
			}
		}

		memo.assign(V, 0);
		cout << nump(0) << endl;
	}
	return 0;
}
