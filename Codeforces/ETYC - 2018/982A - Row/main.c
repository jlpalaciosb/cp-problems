#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, i;
	scanf("%d", &n); getchar();
	char row[n];

	for (i = 0; i < n; ++i) {
		row[i] = getchar();
	}

	if (n==1 && row[0]=='0')
	{
		printf("No\n");
		return 0;
	}


	for (i = 1; i < n; ++i) {
		if (row[i] == '1' && row[i-1] == '1') {
			printf("No\n");
			return 0;
		}
	}

	int cantCero = 0;
	if (row[0] == '0') {
		cantCero++;
	}
	for (i = 1; i < n; ++i) {
		if (row[i] == '0') {
			if(row[i-1] == '0') {
				cantCero++;
			} else {
				cantCero = 1;
			}
			if (cantCero == 2 && (i == 1 || i == n-1)) {
				printf("No\n");
				return 0;
			}
			if (cantCero == 3) {
				printf("No\n");
				return 0;
			}
		} else {
			cantCero = 0;
		}
	}

	printf("Yes\n");
	return 0;
}
