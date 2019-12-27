#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int left_buddy;
	int right_buddy;
} soldier;

void print_buddy(int b, char c);

int main() {
	vector<soldier> soldiers(100001);

	int s, b;
	while(true) {
		cin >> s >> b;
		if(s == 0) {
			break;
		}
		for(int i = 1; i <= s; ++i) {
			soldiers[i].left_buddy = i == 1 ? -1 : i - 1;
			soldiers[i].right_buddy = i == s ? -1 : i + 1;
		}
		for(int i = 1; i <= b; ++i) {
			int L, R;
			cin >> L >> R;
			int l = soldiers[L].left_buddy;
			int r = soldiers[R].right_buddy;
			if(l != -1) {
				soldiers[l].right_buddy = r;
			}
			if(r != -1) {
				soldiers[r].left_buddy = l;
			}
			print_buddy(l, ' ');
			print_buddy(r, '\n');
		}
		cout << '-' << endl;
	}
	
	return 0;
}

void print_buddy(int b, char c) {
	if(b == -1) {
		cout << "*";
	} else {
		cout << b;
	}
	cout << c;
}
