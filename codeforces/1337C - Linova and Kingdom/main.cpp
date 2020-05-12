#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int n, k;
vector<vi> adj;

vi h, nc;

int dfs(int u, int hu, int pu) {
	h[u] = hu;
	nc[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != pu) {
			nc[u] += dfs(v, hu + 1, u);
		}
	}
	return nc[u];
}

void compute_nch() {
	h.assign(n, 0);
	nc.assign(n, 0);
	dfs(0, 0, -1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	adj.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}

	compute_nch();
	vi gain(n);
	for (int i = 0; i < n; i++) {
		gain[i] = -(nc[i] - 1) + h[i];
	}
	sort(gain.begin(), gain.end());

	ll ans = 0;
	for (int i = n - 1; i >= n - k; i--) {
		ans += gain[i];
	}
	cout << ans << endl;

	return 0;
}
