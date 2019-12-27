#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct edge {
	int w, u, v;
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

int n, m, m_;
edge E[25000], E_[25000];
bool taken[25000];

void kruskal() {
	sort(E, E + m, cmp());
	UnionFind ds = UnionFind(n);
	ds.unionSet(E[0].u, E[0].v);
	taken[0] = true;
	for (int i = 1; i < m; ++i) {
		int u = E[i].u, v = E[i].v;
		if (!ds.isSameSet(u, v)) {
			ds.unionSet(u, v);
			taken[i] = true;
		}
	}
}

int main() {
	while(cin >> n >> m, !(n == 0 && m == 0)) {
		for (int i = 0; i < m; ++i)
			cin >> E[i].u >> E[i].v >> E[i].w;
		
		memset(taken, 0, sizeof taken);
		kruskal();
		
		m_ = 0;
		for (int i = 0; i < m; ++i)
			if (!taken[i])
				E_[m_++] = E[i];
		
		if (m_ == 0) {
			cout << "forest" << endl;
			continue;
		}
		
		cout << E_[0].w;
		for (int i = 1; i < m_; ++i)
			cout << ' ' << E_[i].w;
		cout << endl;
	}
	return 0;
}
