#include <iostream>
#define UNDEF -1
using namespace std;

string str1, str2;
int M, N;

int memo[81][81];
char op[81][81];

int distance(int m, int n) {
	int &ans = memo[m][n];
	if (ans != UNDEF) {
		;
	} else if (m == 0) {
		ans = n;
		op[m][n] = 'I';
	} else if (n == 0) {
		ans = m;
		op[m][n] = 'D';
	} else if (str1[m - 1] == str2[n - 1]) {
		ans = distance(m - 1, n - 1);
		op[m][n] = '-';
	} else {
		int di = distance(m, n - 1); // insert
		int dd = distance(m - 1, n); // delete
		int dr = distance(m - 1, n - 1); // replace
		ans = 1 + min(min(di, dd), dr);
		if (ans - 1 == di) {
			op[m][n] = 'i';
		} else if (ans - 1 == dd) {
			op[m][n] = 'd';
		} else {
			op[m][n] = 'r';
		}
	}
	return ans;
}

void clear_memo() {
	for (int i = 0; i < 81; ++i)
		for (int j = 0; j < 81; ++j)
			memo[i][j] = UNDEF;
}

void show_solution(int m, int n, int pos, int c) {
	if (op[m][n] == 'I') {
		for (int i = 0; i < n; i++)
			printf("%d Insert %d,%c\n", ++c, i + 1, str2[i]);
	} else if (op[m][n] == 'D') {
		for (int i = 0; i < m; i++)
			printf("%d Delete 1\n", ++c);
	} else if (op[m][n] == '-') {
		show_solution(m - 1, n - 1, pos - 1, c);
	} else if (op[m][n] == 'i') {
		printf("%d Insert %d,%c\n", ++c, pos + 1, str2[n - 1]);
		show_solution(m, n - 1, pos, c);
	} else if (op[m][n] == 'd') {
		printf("%d Delete %d\n", ++c, pos);
		show_solution(m - 1, n, pos - 1, c);
	} else if (op[m][n] == 'r') {
		printf("%d Replace %d,%c\n", ++c, pos, str2[n - 1]);
		show_solution(m - 1, n - 1, pos - 1, c);
	} else {
		printf("Impossible\n");
	}
}

int main() {
	int tc = 0;
	while (getline(cin, str1) && getline(cin, str2)) {
		tc++; if(tc > 1) cout << endl;
		M = str1.length();
		N = str2.length();
		clear_memo();
		cout << distance(M, N) << endl;
		show_solution(M, N, M, 0);
	}
	return 0;
}
