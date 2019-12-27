#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int H, W, tc = 0;
bool image[200][200], analyzer[202][202];
vvb hexa;
string row;
vector<char> found;
vector<int> di, dj;
char geo[6];

void init() {
	hexa.resize(256);
	hexa['0'] = {0,0,0,0};
	hexa['1'] = {0,0,0,1};
	hexa['2'] = {0,0,1,0};
	hexa['3'] = {0,0,1,1};
	hexa['4'] = {0,1,0,0};
	hexa['5'] = {0,1,0,1};
	hexa['6'] = {0,1,1,0};
	hexa['7'] = {0,1,1,1};
	hexa['8'] = {1,0,0,0};
	hexa['9'] = {1,0,0,1};
	hexa['a'] = {1,0,1,0};
	hexa['b'] = {1,0,1,1};
	hexa['c'] = {1,1,0,0};
	hexa['d'] = {1,1,0,1};
	hexa['e'] = {1,1,1,0};
	hexa['f'] = {1,1,1,1};

	di = {0, 0, 1, -1};
	dj = {1, -1, 0, 0};

	geo[0] = 'W';
	geo[1] = 'A';
	geo[2] = 'K';
	geo[3] = 'J';
	geo[4] = 'S';
	geo[5] = 'D';
}

void read_image() {
	for (int r = 0; r < H && (cin >> row); r++)
		for (int h = 0; h < W; h++)
			for (int b = 0; b < 4; b++)
				image[r][4 * h + b] = hexa[row[h]][b];
}

void show_image() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < 4 * W; j++)
			cout << image[i][j];
		cout << endl;
	}
	cout << endl;
}

void dfs1(int i, int j);
void dfs2(int i, int j);

void analyze(int row, int col) {
	int count = 0;

	memset(analyzer, false, sizeof analyzer);
	dfs1(row, col);

	dfs2(0, 0);
	for (int i = 0; i < 202; i++) {
		for (int j = 0; j < 202; j++) {
			if (!analyzer[i][j]) {
				count++;
				dfs2(i, j);
			}
		}
	}

	found.push_back(geo[count]);
}

void dfs1(int i, int j) {
	analyzer[i + 1][j + 1] = 1;
	image[i][j] = 0;
	for (int d = 0; d < 4; d++) {
		int ni = i + di[d], nj = j + dj[d];
		if (ni < 0 || ni >= H || nj < 0 || nj >= 4 * W) continue;
		if (image[ni][nj]) dfs1(ni, nj);
	}
}

void dfs2(int i, int j) {
	analyzer[i][j] = 1;
	for (int d = 0; d < 4; d++) {
		int ni = i + di[d], nj = j + dj[d];
		if (ni < 0 || ni >= 202 || nj < 0 || nj >= 202) continue;
		if (!analyzer[ni][nj]) dfs2(ni, nj);
	}
}

int main() {
	init();
	while (cin >> H >> W) {
		if (H == 0) break;
		read_image();
		found.clear();
		for (int i = 0; i < H; i++)
			for (int j = 0; j < 4 * W; j++)
				if (image[i][j]) analyze(i, j);
		sort(found.begin(), found.end());
		printf("Case %d: ", ++tc);
		for (int i = 0; i < found.size(); i++) cout << found[i];
		cout << endl;
	}
	return 0;
}
