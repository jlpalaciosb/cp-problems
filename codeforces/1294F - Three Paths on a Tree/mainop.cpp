#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef vector<int> vi;
typedef vi::iterator viit;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef queue<int> qi;

int n, diam, res, a, b, c;
vvi adj; int p[200010], d[200010]; bool vis[200010]; qi q;

int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch));
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return x;
}

void fora() {
	memset(vis, false, n + 1);
	q.push(1); vis[1] = true;
	memset(d, 0, 4 * (n + 1));
	int md = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		int du = d[u]; if (md < du) { md = du; a = u; }
		viit end = adj[u].end(); for (viit it = adj[u].begin(); it != end; it++) {
			int v = *it;
			if (!vis[v]) {
				d[v] = du + 1;
				q.push(v); vis[v] = true;
			}
		}
	}
}

int forb() {
	memset(vis, false, n + 1);
	q.push(a); vis[a] = true;
	memset(p, 0, 4 * (n + 1));
	memset(d, 0, 4 * (n + 1));
	int md = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		int du = d[u]; if (md < du) { md = du; b = u; }
		viit end = adj[u].end(); for (viit it = adj[u].begin(); it != end; it++) {
			int v = *it;
			if (!vis[v]) {
				d[v] = du + 1;
				p[v] = u;
				q.push(v); vis[v] = true;
			}
		}
	}
	diam = md;
}

void forc() {
	memset(vis, false, n + 1);
	q.push(b); vis[b] = true; int u = b;
	int pu = p[u]; while (pu != 0) {
		q.push(pu); vis[pu] = true;
		pu = p[pu];
	}

	memset(d, 0, 4 * (n + 1));
	int md = 0;
	while (!q.empty()) {
		u = q.front(); q.pop();
		int du = d[u]; if (md < du) { md = du; c = u; }
		viit end = adj[u].end(); for (viit it = adj[u].begin(); it != end; it++) {
			int v = *it;
			if (!vis[v]) {
				q.push(v); vis[v] = 1;
				d[v] = du + 1;
			}
		}
	}
	res = diam + md;
}

int main() {
	n = read();
	adj = vvi(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v; u = read(); v = read();
		adj[u].push_back(v); adj[v].push_back(u);
	}

	fora();
	forb();

	if (diam == n - 1) {
		res = diam;
		for (int u = 1; u < 4; ++u) if (u != a && u != b) { c = u; break; }
	} else forc();

	printf("%d\n%d %d %d\n", res, a, b, c);
	return 0;
}
