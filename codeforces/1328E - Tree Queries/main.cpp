#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vi::iterator viit;

/* library code */
struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};
/* end library code */

vector<vi> adj(200000);
int n, m;

vi p(2000000), d(200000);
void dfs(int u, int pu, int du) {
	p[u] = pu; d[u] = du;
	for (viit it = adj[u].begin(); it != adj[u].end(); it++) {
		int v = *it;
		if (v != pu) dfs(v, u, du + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	dfs(0, -1, 0);
	LCA lca_cal(adj, 0);

	vi vec(n);
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		int md = -1, mdv;
		for (int j = 0; j < k; j++) {
			int u; cin >> u; u--;
			vec[j] = u;
			if (d[u] > md) {
				md = d[u];
				mdv = u;
			}
		}

		bool ans = true;
		for (int j = 0; j < k && ans; j++) {
			int u = vec[j];
			if (d[u] - d[lca_cal.lca(u, mdv)] > 1) ans = false;
		}

		cout << (ans ? "YES" : "NO") << endl;
	}

	return 0;
}
