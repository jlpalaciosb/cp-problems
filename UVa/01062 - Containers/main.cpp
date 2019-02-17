/* This greedy solution is accepted */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int case_num = 1;
	string arrival;
	vector<stack<char>> stacks;

	while(getline(cin, arrival), arrival != "end") {
		stacks.clear();

		for(int i = 0; i < arrival.length(); ++i) {
			char to_stack = arrival[i];
			bool insertado = false;
			for(int j = 0; j < stacks.size(); ++j) {
				if(to_stack <= stacks[j].top()) {
					stacks[j].push(to_stack);
					insertado = true;
					break;
				}
			}
			if(!insertado) {
				stack<char> new_stack = stack<char>();
				new_stack.push(to_stack);
				stacks.push_back(new_stack);
			}
		}

		cout << "Case " << case_num << ": " << stacks.size() << endl;
		case_num++;
	}
	return 0;
}
