#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream input_file;
	input_file.open("input.txt");

	ofstream output_file;
	output_file.open("output.txt");

	string door;
	input_file >> door;

	int a;
	input_file >> a;

	if(door == "front")
		output_file << (a == 1 ? "L" : "R");
	else
		output_file << (a == 1 ? "R" : "L");

	return 0;
}
