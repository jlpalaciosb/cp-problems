#include <iostream>
#include <set>
using namespace std;
typedef set<string> ss;
typedef ss::iterator ssit;

int main() {
	string str1, str2;
	int m, n, t;
	ss table[81][81];

	cin >> t;
	while (t--) {
		cin >> str1 >> str2;
		m = str1.length();
		n = str2.length();

		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				ss &setij = table[i][j];
				char ci = str1[i - 1];
				char cj = str2[j - 1];
				setij.clear();
				if (i == 0 || j == 0) {
					; // let the setij empty
				} else if (ci == cj) {
					ss &set_copy = table[i - 1][j - 1];
					if (set_copy.empty()) {
						setij.insert(string(1, ci));
					} else {
						for (ssit it = set_copy.begin(); it != set_copy.end(); it++) {
							string s = *it;
							s.push_back(ci);
							setij.insert(s);
						}
					}
				} else {
					ss &set1 = table[i - 1][j];
					ss &set2 = table[i][j - 1];
					if (set1.empty()) {
						setij = set2;
					} else if (set2.empty()) {
						setij = set1;
					} else if (set1.begin()->length() > set2.begin()->length()) {
						setij = set1;
					} else if (set1.begin()->length() < set2.begin()->length()) {
						setij = set2;
					} else {
						for (ssit it = set1.begin(); it != set1.end(); it++)
							setij.insert(*it);
						for (ssit it = set2.begin(); it != set2.end(); it++)
							setij.insert(*it);
					}
				}
			}
		}

		ss &the_set = table[m][n];
		for (ssit it = the_set.begin(); it != the_set.end(); it++)
			cout << *it << endl;
		if (t > 0) cout << endl;
	}

	return 0;
}
