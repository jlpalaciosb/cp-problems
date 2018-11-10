#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

long long n, nx = 0, ny = 0;	//OJO, tengo que poner long long para que ande en codeforces
								//pero solo con long ya me anda en mi notebook
int x, y, xy;
VVI tree;
vector<bool> visited;

bool dfs1(int u);
void dfs2(int u);
void dfs(int u, bool hijodey);

int main() {
	cin >> n >> x >> y;
	tree.resize(n+1);
	visited.resize(n+1);
	
	tree.assign(n+1, {});
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	visited.assign(n+1, false);
	visited[x] = true;
	xy = 0;
	for(int i = 0; i < tree[x].size(); ++i) {
		if(dfs1(tree[x][i])) {
			xy = i;
			break;
		}
	}
	//cout << "xy = " << xy << endl;

	visited.assign(n+1, false);
	visited[x] = true;
	nx += 1;
	for(int i = 0; i < tree[x].size(); ++i) {
		if(i != xy) {
			dfs2(tree[x][i]);
		}
	}
	//cout << "nx = " << nx << endl;

	visited.assign(n+1, false);
	visited[x] = true;
	for(int i = 0; i < tree[x].size(); ++i) {
		dfs(tree[x][i], false);
	}
	//cout << "ny = " << ny << endl;

	cout << n * (n - 1) - nx * ny << endl;

	return 0;
}

bool dfs1(int u) {
	visited[u] = true;
	if(u == y) {
		return true;
	}
	for(int i = 0; i < tree[u].size(); ++i) {
		if(!visited[tree[u][i]] && dfs1(tree[u][i])) {
			return true;
		}
	}
	return false;
}

void dfs2(int u) {
	visited[u] = true;
	nx += 1;
	for(int i = 0; i < tree[u].size(); ++i) {
		if(!visited[tree[u][i]]) {
			dfs2(tree[u][i]);
		}
	}
}

void dfs(int u, bool hijodey) {
	visited[u] = true;
	if(hijodey) {
		ny += 1;
	} else if(u == y) {
		ny += 1;
		hijodey = true;
	}
	for(int i = 0; i < tree[u].size(); ++i) {
		if(!visited[tree[u][i]]) {
			dfs(tree[u][i], hijodey);
		}
	}
}
