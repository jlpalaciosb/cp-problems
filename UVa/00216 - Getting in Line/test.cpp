#include <iostream>
#include <cstring>
#define INF 999999999
using namespace std;

int main() {
	double inf = INF;
	printf("%f\n", inf);

	double cero = 6.66;
	memset(&cero, 0, sizeof cero);
	printf("%f\n%d\n", cero, cero == 0);

	return 0;
}
