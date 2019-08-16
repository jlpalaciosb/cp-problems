#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
	vi st, A;
	vi P; // guarda en que indice de st están los intervalos 0,0 1,1 2,2 ... n-1,n-1
	int n;

	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }

	void build(int p, int L, int R) {
		if(L == R) {
			st[p] = L;
			P[L] = p;
		} else {
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);

			int s1 = st[left(p)];
			int s2 = st[right(p)];
			st[p] = (A[s1] <= A[s2]) ? s1 : s2;
		}
	}

	int rmq(int p, int L, int R, int i, int j) {
		if(i > R || j < L) return -1;  // segmento actual fuera del rango solicitado
		if(L >= i && R <= j) return st[p];  // segmento actual dentro del rango solicitado
		
		// compute the min position in the left and right part of the interval
		int s1 = rmq(left(p), L, (L + R) / 2, i, j);
		int s2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

		if(s1 == -1) return s2;
		if(s2 == -1) return s1;
		return (A[s1] <= A[s2]) ? s1 : s2;
	}
public:
	SegmentTree(const vi &_A) {
		A = _A;
		n = (int)A.size();
		st.resize(4 * n);
		P.resize(n);
		build(1, 0, n - 1);
	}

	int rmq(int i, int j) {
		return rmq(1, 0, n - 1, i, j);
	}

	int update(int i, int val) {
		A[i] = val;
		int p = P[i];
		while(p > 1) {
			p = p / 2; // subimos llegando al padre
			int s1 = st[left(p)];
			int s2 = st[right(p)];
			st[p] = (A[s1] <= A[s2]) ? s1 : s2;
		}
	}
};

int main() {
	vi arr = {18, 17, 13, 19, 15, 11, 20};
	SegmentTree st(arr);
	cout << st.rmq(1, 3) << endl;
	cout << st.rmq(4, 6) << endl;
	st.update(3, 4);
	cout << st.rmq(1, 3) << endl;
	cout << st.rmq(4, 6) << endl;
	cout << st.rmq(0, 6) << endl;
	return 0;
}
