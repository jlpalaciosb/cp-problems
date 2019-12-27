#include <stdio.h>

int main() {
	unsigned long long n;
	scanf("%llu", &n);
	n++;
	if(n % 2 == 0) {
		printf("%llu\n", n/2);
	} else {
		if(n == 1) {
			printf("0\n");
		} else {
			printf("%llu\n", n);
		}
	}
	return 0;
}

