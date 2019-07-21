// TRATE DE OPTIMIZAR PERO DA WRONG ANSWER

#include <iostream>
#include <set>
#include <cstring>
using namespace std;
typedef set<string>::iterator ssit;

string s1, s2;
int m, n, t;
set<string> table[81][81];

int table_len[81][81];
int solution[81][81];

void just_solution();
void backtrack(int i, int j);
void solve();

void just_solution() {
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				table_len[i][j] = 0;
			} else if (s1[i - 1] == s2[j - i]) {
				table_len[i][j] = 1 + table_len[i - 1][j - 1];
			} else {
				table_len[i][j] = max(table_len[i - 1][j], table_len[i][j - 1]);
			}
		}
	}

	memset(solution, 0, sizeof solution);
	backtrack(m, n);
}

void backtrack(int i, int j) {
	if (solution[i][j]) return;

	solution[i][j] = 1;
	if (i == 0 || j == 0) {
		return;
	} else if (s1[i - 1] == s2[j - 1]) {
		backtrack(i - 1, j - 1);
	} else if (table_len[i - 1][j] > table_len[i][j - 1]) {
		backtrack(i - 1, j);
	} else if (table_len[i - 1][j] < table_len[i][j - 1]) {
		backtrack(i, j - 1);
	} else {
		backtrack(i - 1, j);
		backtrack(i, j - 1);
	}
}

void solve() {
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			set<string> &setij = table[i][j];
			setij.clear();

			if (!solution[i][j]) continue;

			char s1i = s1[i - 1];
			char s2j = s2[j - 1];
			
			if (i == 0 || j == 0) {
				; // nothing to do
			} else if (s1i == s2j) {
				set<string> &set_copy = table[i - 1][j - 1];
				if (set_copy.empty()) {
					setij.insert(string(1, s1i));
				} else {
					for (ssit it = set_copy.begin(); it != set_copy.end(); it++) {
						string s = *it;
						s.push_back(s1i);
						setij.insert(s);
					}
				}
			} else {
				set<string> &set1 = table[i - 1][j];
				int sol1 = solution[i - 1][j];
				set<string> &set2 = table[i][j - 1];
				int sol2 = solution[i][j - 1];
				if (!sol1) {
					setij = set2;
				} else if (!sol2) {
					setij = set1;
				} else {
					int l1 = 0, l2 = 0;
					if (!set1.empty()) l1 = set1.begin()->length();
					if (!set2.empty()) l2 = set2.begin()->length();

					if (l1 >= l2) {
						for (ssit it = set1.begin(); it != set1.end(); it++) {
							setij.insert(*it);
						}
					}

					if (l2 >= l1) {
						for (ssit it = set2.begin(); it != set2.end(); it++) {
							setij.insert(*it);
						}
					}
				}
			}
		}
	}

	set<string> &the_set = table[m][n];
	for (ssit it = the_set.begin(); it != the_set.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> s1 >> s2;
		m = s1.length();
		n = s2.length();
		just_solution();
		solve();
	}
	return 0;
}
