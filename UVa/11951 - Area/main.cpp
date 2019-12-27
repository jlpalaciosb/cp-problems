#include <iostream>

using namespace std;

int T, N, M, K;
long long A[100][100];

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		int S = 0;
		long long P = 20000000000;
		
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> A[i][j];
				if (j > 0) A[i][j] += A[i][j - 1];
				if (i > 0) A[i][j] += A[i - 1][j];
				if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				for (int k = i; k < N; ++k) {
					for (int l = 0; l < M; ++l) {
						long long p = A[k][l];
						if (i > 0) p -= A[i - 1][l];
						if (j > 0) p -= A[k][j - 1];
						if (i > 0 && j > 0) p += A[i - 1][j - 1];

						if (p > K) break;

						int s = (k - i + 1) * (l - j + 1);

						if (s > S) {
							S = s;
							P = p;
						} else if (s == S && p < P) {
							P = p;
						}
					}
				}
			}
		}

		if (S == 0) P = 0;

		printf("Case #%d: %d %d\n", t, S, (int)P);
	}

	return 0;
}
