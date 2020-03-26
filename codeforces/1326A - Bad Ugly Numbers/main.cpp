#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; scanf("%d", &n);
		if (n == 1) {
			printf("-1\n");
		} else if (n % 3 == 1) {
			for (int i = 0; i < n - 2; i++) printf("2");
			printf("33\n");
		} else {
			for (int i = 0; i < n - 1; i++) printf("2");
			printf("3\n");
		}
	}
	return 0;
}
