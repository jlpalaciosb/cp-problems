#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vi::iterator viIt;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, k;
	vi a;
	string s;

	cin >> n >> k;
	a.reserve(n + 100);
	s.reserve(n + 100);

	for(int i = 0; i < n; i++) {
		int ai; cin >> ai;
		a.push_back(ai);
	}

	cin >> s;

	viIt first = a.begin(), last = a.begin();
	for(int i = 1; i < n; i++) {
		last++;
		if(s[i] != s[i - 1]) {
			sort(first, last, cmp);
			first = last;
		}
	}
	sort(first, a.end(), cmp);

	long long max = a[0];
	int c = 1;
	for(int i = 1; i < n; i++) {
		if(s[i] == s[i - 1]) {
			if(c < k) max += a[i];
			c++;
		} else {
			c = 1;
			max += a[i];
		}
	}

	cout << max << endl;

	return 0;
}
