#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int board[9][9];
		for (int i = 0; i < 9; i++) {
			string s; cin >> s;
			for (int j = 0; j < 9; j++) {
				board[i][j] = s[j] - '0';
			}
		}
		int j = 0;
		for (int i = 0; i < 9; i++) {
			board[i][j]--;
			if (board[i][j] == 0) {
				board[i][j] = 9;
			}
			if (i == 2) j = 1;
			else if (i == 5) j = 2;
			else j += 3;
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}