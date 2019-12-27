// WA (muy mal, ademas que me olvide que el vector ya estaba ordenado)

#include <iostream>
#include <vector>
#define INF 2000000000
using namespace std;
typedef vector<int> vi;

int A[300000], n, k;

class SegmentTree { // the segment tree is stored like a heap array
private:
	vi stmin, stmax; // recall that vi is: typedef vector<int> vi;
	int left (int p) { return p << 1; } // same as binary heap operations
	int right(int p) { return (p << 1) + 1; }
	void build(int p, int L, int R) { // O(n)
		if (L == R) { // as L == R, either one is fine
			stmin[p] = L; // store the index
			stmax[p] = L;
		} else { // recursively compute the values
			build(left(p) , L , (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R );

			int p1 = stmin[left(p)], p2 = stmin[right(p)];
			stmin[p] = (A[p1] <= A[p2]) ? p1 : p2;

			p1 = stmax[left(p)], p2 = stmax[right(p)];
			stmax[p] = (A[p1] >= A[p2]) ? p1 : p2;
		}
	}
	int rminq(int p, int L, int R, int i, int j) { // O(log n)
		if (i > R || j < L) return -1; // current segment outside query range
		if (L >= i && R <= j) return stmin[p]; // inside query range
		// compute the min position in the left and right part of the interval
		int p1 = rminq(left(p) , L , (L+R) / 2, i, j);
		int p2 = rminq(right(p), (L+R) / 2 + 1, R , i, j);
		if (p1 == -1) return p2; // if we try to access segment outside query
		if (p2 == -1) return p1; // same as above
		return (A[p1] <= A[p2]) ? p1 : p2; // as in build routine
	}
	int rmaxq(int p, int L, int R, int i, int j) { // O(log n)
		if (i > R || j < L) return -1; // current segment outside query range
		if (L >= i && R <= j) return stmax[p]; // inside query range
		// compute the max position in the left and right part of the interval
		int p1 = rmaxq(left(p) , L , (L+R) / 2, i, j);
		int p2 = rmaxq(right(p), (L+R) / 2 + 1, R , i, j);
		if (p1 == -1) return p2; // if we try to access segment outside query
		if (p2 == -1) return p1; // same as above
		return (A[p1] >= A[p2]) ? p1 : p2; // as in build routine
	}
public:
	SegmentTree() {
		stmin.assign(4 * n, 0); // create large enough vector of zeroes
		stmax.assign(4 * n, 0); // create large enough vector of zeroes
		build(1, 0, n - 1); // recursive build
	}
	int rminq(int i, int j) { return A[rminq(1, 0, n - 1, i, j)]; } // overloading
	int rmaxq(int i, int j) { return A[rmaxq(1, 0, n - 1, i, j)]; } // overloading
};

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> A[i];
	SegmentTree st = SegmentTree();

	int minc = INF;
	for (int i = 0; i < k; i++) {
		int j = i + n - k;
		int c = st.rmaxq(i, j) - st.rminq(i, j);
		if (c < minc) minc = c;
		if (minc == 0) break;
	}

	cout << minc << endl;
	return 0;
}
