#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int angle;

	while(scanf("%d", &angle) != EOF) {
		cout << (angle % 6 == 0 ? 'Y' : 'N') << endl;
	}

	return 0;
}
