#include <iostream>
#include <list>

using namespace std;

typedef list<char> LI;
typedef list<char>::iterator LIit;

int main() {
	string input;
	input.reserve(100009);
	while(getline(cin, input)) {
		LI beiju = LI();
		LIit pointer = beiju.end();
		for(int i = 0; i < input.length(); ++i) {
			char c = input[i];
			switch(c) {
				case '[':
					pointer = beiju.begin();
					break;
				case ']':
					pointer = beiju.end();
					break;
				default:
					beiju.insert(pointer, c);
					break;
			}
		}
		for(LIit it = beiju.begin(); it != beiju.end(); ++it) {
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}
