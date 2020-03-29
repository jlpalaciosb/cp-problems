#include <iostream>
#include <vector>
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;
typedef long long ll;
typedef vector<int> vi;

vector<vi> adj;
vector<int> vis;
int cc;
void dfs(int x, int p) {
	vis[x] = GRAY;
	for (int i = 0; i < adj[x].size(); i++) {
		int y = adj[x][i];
		if (vis[y] == GRAY && y != p) cc++;
		else if (vis[y] == WHITE) dfs(y, x);
	}
	vis[x] = BLACK;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	adj = vector<vi>(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}

	cc = 0;
	vis.assign(n + 1, WHITE);
	dfs(1, 0);

	bool allv = true;
	for (int i = 1; i <= n && allv; i++) if (vis[i] == WHITE) allv = false;

	if (cc == 1 && allv) cout << "FHTAGN!" << endl;
	else cout << "NO" << endl;

	return 0;
}
