#include <iostream>
#include <vector>
#define UNDEF -1
using namespace std;

class eflist {
private:
	int n, m;
	vector<int> next, prev;
	vector<bool> is;
public:
	eflist(int n_) {
		n = n_;
		if (n_ < 1 || n_ > 1000000) n = 10; // XD
		m = 0;
		next.assign(n, 0);
		prev.assign(n, 0);
		is.assign(n, true);
		for (int i = 0; i < n; i++) {
			next[i] = i + 1;
			prev[i] = i - 1;
		}
		prev[0] = next[n - 1] = UNDEF;
	}
	void rem(int i) {
		if (i >= 0 && i < n && is[i]) {
			if (i == m) m = next[i];
			if (prev[i] != UNDEF) next[prev[i]] = next[i];
			if (next[i] != UNDEF) prev[next[i]] = prev[i];
			is[i] = false;
		}
	}
	int getm() { return m; }
};

int main(int argc, char const *argv[]) {
	int q, x; cin >> q >> x;
	vector<int> s(x); for (int i = 0; i < x; i++) s[i] = i;
	eflist el(1000000);

	while (q--) {
		int y; scanf("%d", &y);
		int mod = y % x;
		el.rem(s[mod]);
		s[mod] += x;
		printf("%d\n", el.getm());
	}
	return 0;
}
