#include <iostream>
#include <vector>

using namespace std;

void get_dmy(const string &date, int &day, int &month, int &year);
string get_string(int day, int month, int year);
bool is_leap(int year);

vector<int> number_of_days = {-1, 31, 28, 31, 30, 31, 31, 31, 31, 30, 31, 30, 31};

int main() {
	string date;
	int day, month, year;
	
	cin >> date;
	get_dmy(date, day, month, year);
	
	if(is_leap(year)) number_of_days[2] = 29;

	day = day % number_of_days[month] + 1;
	if(day == 1) {
		month = month % 12 + 1;
		if(month == 1) year += 1;
	}

	cout << get_string(day, month, year) << endl;

	return 0;
}

void get_dmy(const string &date, int &day, int &month, int &year) {
	day = stoi(date.substr(0, 2));
	month = stoi(date.substr(3, 2));
	year = stoi(date.substr(6));
}

string get_string(int day, int month, int year) {
	string ret = "";
	if(day < 10) ret.append("0");
	ret.append(to_string(day));
	ret.append("/");
	if(month < 10) ret.append("0");
	ret.append(to_string(month));
	ret.push_back('/');
	ret.append(to_string(year));
	return ret;
}

bool is_leap(int year) {
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}