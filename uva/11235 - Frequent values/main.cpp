#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int start;
	int end;
	int freq;
} info; // info para cada uno de los numeros de -100000 a 100000

typedef vector<info> vinf;
typedef vector<int> vi;

void initInf(int n);
void start(int a, int s);
int getStart(int a);
void end(int a, int e);
int getEnd(int a);
void freqi(int a);
int getFreq(int a);
void updateFreq(int a, int f);

class SegmentTree { // segment tree para los numeros de -100000 a 100000
private:
	vi st;

	int left(int i) { return i << 1; }
	int right(int i) { return (i << 1) + 1; }

	void build(int p, int l, int r) {
		if(l == r) {
			st[p] = getFreq(l);
		} else {
			int m = (l == r - 1) ? l : (l + r) / 2;
			build(left(p), l, m);
			build(right(p), m + 1, r);
			st[p] = (st[left(p)] > st[right(p)]) ? st[left(p)] : st[right(p)];
		}
	}

	void _update(int p, int l, int r, int a) {
		if(l <= a && a <= r) {
			if(l == r) { // l y r son a
				st[p] = getFreq(l);
			} else {
				int m = (l == r - 1) ? l : (l + r) / 2;
				_update(left(p), l, m, a);
				_update(right(p), m + 1, r, a);
				st[p] = (st[left(p)] > st[right(p)]) ? st[left(p)] : st[right(p)];
			}
		}
	}

	int _rmq(int p, int l, int r, int i, int j) {
		if(j < l || r < i) {
			return -1;
		}
		if(i <= l && r <= j) {
			return st[p];
		}
		int m = (l == r - 1) ? l : (l + r) / 2;
		int ql = _rmq(left(p), l, m, i, j);
		int qr = _rmq(right(p), m + 1, r, i, j);
		if(ql == -1) return qr;
		if(qr == -1) return ql;
		return (ql > qr) ? ql : qr;
	}
public:
	SegmentTree() {
		st.resize(800010);
	}

	void construct() {
		build(1, -100000, 100000);
	}

	void update(int a) {
		_update(1, -100000, 100000, a);
	}

	int rmq(int i, int j) {
		return _rmq(1, -100000, 100000, i, j);
	}
};

vinf inf(200010);
vi v(100010);
SegmentTree st;

int main() {
	while(true) {
		int n; cin >> n; if(n == 0) break;
		int q; cin >> q;

		initInf(n);
		st.construct();

		for(int i = 1; i <= q; i++) {
			int l, r; cin >> l >> r;
			int al = v[l], ar = v[r];
			updateFreq(al, getFreq(al) - (l - getStart(al)));
			updateFreq(ar, getFreq(ar) - (getEnd(ar) - r));
			cout << st.rmq(al, ar) << endl;
			updateFreq(al, getFreq(al) + (l - getStart(al)));
			updateFreq(ar, getFreq(ar) + (getEnd(ar) - r));
		}
	}
	return 0;
}

void initInf(int n) {
	inf.assign(200010, {-1, -1, 0});
	int ab, ai;
	cin >> ai;
	v[1] = ai;
	freqi(ai);
	start(ai, 1);
	ab = ai;
	for(int i = 2; i <= n; i++) {
		cin >> ai;
		v[i] = ai;
		freqi(ai);
		if(ai != ab) {
			end(ab, i - 1);
			start(ai, i);
		}
		ab = ai;
	}
	end(ai, n);
}

void start(int a, int s) {
	inf[a + 100001].start = s;
}

int getStart(int a) {
	return inf[a + 100001].start;
}

void end(int a, int e) {
	inf[a + 100001].end = e;
}

int getEnd(int a) {
	return inf[a + 100001].end;
}

void freqi(int a) {
	inf[a + 100001].freq++;
}

int getFreq(int a) {
	return inf[a + 100001].freq;
}

void updateFreq(int a, int f) {
	inf[a + 100001].freq = f;
	st.update(a);
}
