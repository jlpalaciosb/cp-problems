#include <queue>
#include <bitset>
#include <iostream>
#include <cstring>
#define INF 1000000000
#include <vector>
#define SOURCE 50001
#define MONK_OFFSET 50002
#define MAX_V 50110
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

int n, m, v[100], a[100], b[100];
bool comp[50001];
vector<vector<ii>> graph;
int TARGET, NV;

void construct() {
	NV = 50001 + 1 + n + 1, TARGET = NV - 1;
	graph.clear(); graph.resize(NV);

	int sa = 0;
	while (true) {
		int sb = sa + 1;
		while (comp[sb]) sb++;
		graph[sa].push_back(ii(sb, (sb - sa) * m));
		sa = sb;
		if (sb == 50000) break;
	}

	for (int i = 0; i < n; ++i) {
		int f = a[i];
		while (true) {
			int l = f + 1;
			while (comp[l]) l++;
			graph[SOURCE].push_back(ii(f, l - f));
			graph[l].push_back(ii(MONK_OFFSET + i, l - f));
			f = l;
			if (f == b[i]) break;
		}
		graph[MONK_OFFSET + i].push_back(ii(TARGET, v[i]));
	}
}

vi p, pj; // p stores the BFS spanning tree from s
int f;
vector<vector<ii>> res;
void augment(int v, int min_edge) { // traverse BFS spanning tree from s->t
	if (v == SOURCE) {
		f = min_edge;
	} else {
		augment(p[v], min(min_edge, res[p[v]][pj[v]].second));
		res[p[v]][pj[v]].second -= f; //res[v][p[v]] += f;
	}
}
int max_flow() {
	res = graph;
	int mf = 0;
	while (1) { // now a true O(VE^2) Edmonds Karp’s algorithm
		int f = 0;
		bitset<MAX_V> vis; vis[SOURCE] = true; // we change vi dist to bitset!
		queue<int> q; q.push(SOURCE);
		p.assign(NV, -1); pj.assign(NV, -1);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == TARGET) break;
			for (int j = 0; j < (int)graph[u].size(); j++) {
				int v = graph[u][j].first;
				if (res[u][j].second > 0 && !vis[v]) {
					vis[v] = true;
					q.push(v);
					p[v] = u; pj[v] = j;
				}
			}
		}

		f = 0;
		augment(TARGET, INF);
		if (f == 0) break;
		mf += f;
	}
	return mf;
}

int main() {
	int cn = 0;
	while (true) {
		cin >> n; if (n == 0) break; cin >> m;
		memset(comp, 0, 50001);
		int total = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i] >> a[i] >> b[i];
			total += v[i];
			comp[a[i]] = comp[b[i]] = false;
		}
		construct();
		if (max_flow() == total) {
			printf("Case %d: Yes\n", ++cn);
		} else {
			printf("Case %d: No\n", ++cn);
		}
	}
	return 0;
}
