#include <iostream>

using namespace std;

int main() {
	cout << "sizeof(unsigned) = " << sizeof(unsigned) << endl;
	const unsigned uno = 1;
	unsigned max = (uno << 31) - 1;
	max = (uno << 31) | max;
	cout << "max = " << max << endl;
	return 0;
}
