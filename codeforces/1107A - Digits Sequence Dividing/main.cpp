#include <iostream>

using namespace std;

int main() {
	int q, n;
	scanf("%d\n", &q);
	while(q--) {
		scanf("%d\n", &n);
		int c1 = getchar() - '0';
		int c2 = getchar() - '0';
		if(n == 2 && c2 <= c1) {
			printf("NO");
		} else {
			printf("YES\n2\n%d %d", c1, c2);
		}
		for(int i = 3; i <= n; i++)
			printf("%c", getchar());
		printf("\n");
		getchar();
	}
	return 0;
}
