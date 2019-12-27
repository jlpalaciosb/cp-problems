#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef vector<int> vi;

int T, R, C, M, N, W, x, y;
bool water[100][100];
int ndir; vi dr, dc;
int even, odd;
bool visited[100][100];

void dfs(int a, int b) {
	visited[a][b] = true;
	int k = 0;
	for(int dir = 0; dir < ndir; dir++) {
		int c = a + dr[dir];
		int d = b + dc[dir];
		if (c < 0 || c >= R || d < 0 || d >= C) continue;
		if (!water[c][d]) {
			k++;
			if (!visited[c][d]) dfs(c, d);
		}
	}
	if (k % 2 == 0) even++;
	else odd++;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> R >> C >> M >> N;

		memset(water, false, sizeof water);
		cin >> W;
		for (int w = 1; w <= W; w++) {
			cin >> x >> y;
			water[x][y] = true;
		}

		if (M == 0) {
			dr = {-N, +N, +0, +0};
			dc = {+0, +0, -N, +N};
		} else if (N == 0) {
			dr = {-M, M, 0, 0};
			dc = {0, 0, -M, M};
		} else if (M == N) {
			dr = {-M, -M, +M, +M};
			dc = {-M, +M, -M, +M};
		} else {
			dr = {-M, -M, +M, +M, -N, -N, +N, +N};
			dc = {-N, +N, -N, +N, -M, +M, -M, +M};
		}
		ndir = dr.size();

		even = odd = 0;
		memset(visited, false, sizeof visited);
		dfs(0, 0);
		printf("Case %d: %d %d\n", t, even, odd);
	}
	return 0;
}
