#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct edge {
	int w, u, v;
};
struct neigh {
	int w, v;
};
class cmp {
	public: bool operator()(const edge &e1, const edge &e2) {
		return e1.w < e2.w;
	}
};
class UnionFind { // OOP style
private: vector<int> p, rank; // remember: vi is vector<int>
public:
UnionFind(int N) { rank.assign(N, 0);
p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
if (!isSameSet(i, j)) { // if from different set
int x = findSet(i), y = findSet(j);
if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
else { p[x] = y;
if (rank[x] == rank[y]) rank[y]++; }
} } };

int n, m, q;
edge E[1000];
vector<vector<neigh>> mst;

void kruskal() {
	sort(E, E + m, cmp());
	UnionFind ds = UnionFind(n + 1);
	for (int i = 0; i < m; ++i) {
		int u = E[i].u, v = E[i].v, w = E[i].w;
		if (!ds.isSameSet(u, v)) {
			ds.unionSet(u, v);
			mst[u].push_back((neigh){w, v});
			mst[v].push_back((neigh){w, u});
		}
	}
}

bool dfs(int u, int parent);

int target, mxans;
int mx(int u, int v) {
	if (u == v) return 0;
	mxans = -1;
	target = v;
	dfs(u, -1);
	return mxans;
}

bool dfs(int u, int parent) {
	if (u == target) return true;
	bool flag = false;
	for (int i = 0; i < mst[u].size(); i++) {
		int v = mst[u][i].v, w = mst[u][i].w;
		if (v != parent) {
			bool dfs_ = dfs(v, u);
			flag = flag || dfs_;
			if (dfs_) mxans = max(mxans, w);
		}
	}
	return flag;
}

int main() {
	int tc = 0;
	while(cin >> n >> m >> q, tc++, !(n == 0 && m == 0 && q == 0)) {
		if (tc > 1) cout << endl;

		for (int i = 0; i < m; ++i)
			cin >> E[i].u >> E[i].v >> E[i].w;
		
		mst.resize(n + 1); for (int i = 0; i <= n; ++i) mst[i].clear();
		kruskal();
		
		cout << "Case #" << tc << endl;
		for (int i = 0; i < q; ++i) {
			int u, v; cin >> u >> v;
			int mx_ = mx(u, v);
			if (mx_ != -1) cout << mx_ << endl;
			else cout << "no path" << endl;
		}
	}
	return 0;
}
