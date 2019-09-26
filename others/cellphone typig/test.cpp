#include <iostream>
#include <unordered_map>

using namespace std;

typedef unordered_map<char, int*> MCI;
typedef MCI::iterator MCIit;

int main() {
	MCI my_map = {};
	int a = 9, b = 8;
	char str[] = "hola";
	my_map[str[0]] = &a;
	my_map[str[1]] = &b;

	for(MCIit it = my_map.begin(); it != my_map.end(); ++it) {
		cout << *(it->second) << endl;
	}

	cout << (my_map.find(str[0]) != my_map.end()) << endl;

	return 0;
}
