#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<int> qi;

int n, res, a, b, c;
vvi g;

vi vis; int mp, fv;
void dfs1(int u, int p) {
	vis[u] = 1;
	if (p > mp) { mp = p; fv = u; }
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (!vis[v]) dfs1(v, p + 1);
	}
}

vi nxt;
int dfs2(int u) {
	vis[u] = 1;
	int r = 0; if (u == b) r = 1;
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (!vis[v]) {
			if (dfs2(v)) {
				r = 1;
				nxt[u] = v;
			}
		}
	}
	return r;
}

void bfs_for_c() {
	vis.assign(n, 0);
	qi q; q.push(a); vis[a] = 1; int u = a;
	while (nxt[u] != -1) {
		q.push(nxt[u]); vis[nxt[u]] = 1;
		u = nxt[u];
	}

	vi p; p.assign(n, 0); mp = 0;
	while (!q.empty()) {
		u = q.front(); q.pop();
		if (p[u] > mp) { mp = p[u]; c = u; }
		for (int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i];
			if (!vis[v]) {
				q.push(v); vis[v] = 1;
				p[v] = p[u] + 1;
			}
		}
	}
	res += mp;
}

int main() {
	cin >> n; g = vvi(n);
	for (int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		g[u].push_back(v); g[v].push_back(u);
	}

	mp = 0; vis.assign(n, 0); dfs1(0, 0); a = fv;
	mp = 0; vis.assign(n, 0); dfs1(a, 0); b = fv;

	res = mp;
	if (mp == n - 1) {
		for (int u = 0; u < 3; ++u) if (u != a && u != b) c = u;
	} else {
		nxt.assign(n, -1); vis.assign(n, 0); dfs2(a);
		bfs_for_c();
	}

	printf("%d\n%d %d %d\n", res, ++a, ++b, ++c);

	return 0;
}
