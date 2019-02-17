#include <iostream>
#include <math.h>

using namespace std;

int suma_sucesion(int n) {
	return ((n + 1) * n) / 2;
}

int main() {
	int chips, walruses;
	cin >> walruses >> chips;

	chips = chips % suma_sucesion(walruses);

	int walruses_alim = (int)floor((-1.0 + sqrt(1.0 + 8.0 * (double)chips))/(2.0));

	cout << chips - suma_sucesion(walruses_alim) << endl;

	return 0;
}