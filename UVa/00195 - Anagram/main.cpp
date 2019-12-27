#include <iostream>
#include <algorithm>

using namespace std;

short values[256];
void init_values();

bool compare(char c1, char c2);

int main() {
	init_values();
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		string word;
		cin >> word;
		sort(word.begin(), word.end(), &compare);
		do {
			cout << word << endl;
		} while(next_permutation(word.begin(), word.end(), &compare));
	}
	return 0;
}

void init_values() {
	int v = 1;
	for(char c = 'A'; c <= 'Z'; ++c) {
		values[c] = v;
		v = v + 2;
	}
	v = 2;
	for(char c = 'a'; c <= 'z'; ++c) {
		values[c] = v;
		v = v + 2;
	}
}

bool compare(char c1, char c2) {
	return values[c1] < values[c2];
}
