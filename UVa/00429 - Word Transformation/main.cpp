#include <iostream>
#include <queue>
#include <map>
#define INF 1000000000
using namespace std;
typedef vector<vector<int>> vvi;

int n;
string words[200];
map<string, int> index;
vvi graph;
int dist[200];

bool are_adj(int i, int j) {
	string &w1 = words[i], &w2 = words[j];
	int l = w1.length(), d = 0;
	if (w2.length() != l) return false;
	for (int i = 0; i < l; ++i) if (w1[i] != w2[i]) d++;
	return d == 1;
}

void make_graph() {
	graph.resize(n); for (int i = 0; i < n; ++i) graph[i].clear();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (are_adj(i, j)) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
}

int steps(string &w1, string &w2) {
	if (w1 == w2) return 0; // un caso especial
	int s = index[w1], t = index[w2];
	for (int i = 0; i < 200; ++i) dist[i] = INF;
	queue<int> q;
	dist[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int i = 0; i < graph[u].size(); ++i) {
			int v = graph[u][i];
			if (dist[v] == INF) {
				q.push(v);
				dist[v] = dist[u] + 1;
				if (v == t) return dist[v]; // retornar lo antes posible
			}
		}
	}
	return -1; // no deberia llegar aca
}

int main() {
	int T; cin >> T; getchar(); getchar();
	for (int t = 1; t <= T; ++t) {
		n = 0; index.clear();
		while (true) {
			string w; getline(cin, w);
			if (w == "*") break;
			index[w] = n;
			words[n++] = w;
		}
		make_graph();

		while (true) {
			string ww; getline(cin, ww); if (ww == "") break;
			int sp = ww.find(' ');
			string w1 = ww.substr(0, sp);
			string w2 = ww.substr(sp + 1);
			cout << w1 << ' ' << w2 << ' ' << steps(w1, w2) << endl;
		}
		if (t != T) cout << endl;
	}
	return 0;
}
