#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

string lpp(string &str) {
	if (str.length() == 0) return "";
	int lens = str.length(), lenpp = 0;
	int p = 31, m = 1e9 + 9; ll ppow = 1;
	int p_ = 193, m_ = 1e9 + 9; ll ppow_ = 1;
	ll hash1 = 0, hash2 = 0;
	ll hash1_ = 0, hash2_ = 0;
	for (int i = 0; i < lens; i++) {
		int cv = str[i] - 'a' + 1;
		hash1 = (hash1 + cv * ppow) % m; ppow = (ppow * p) % m;
		hash2 = (hash2 * p % m + cv) % m;
		hash1_ = (hash1_ + cv * ppow_) % m_; ppow_ = (ppow_ * p_) % m_;
		hash2_ = (hash2_ * p_ % m_ + cv) % m_;
		if (hash1 == hash2 && hash1_ == hash2_) lenpp = i + 1;
	}
	return str.substr(0, lenpp);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		string s; cin >> s; int n = s.length();

		int k = 0;
		while (k < n / 2 && s[k] == s[n - k - 1]) k++;

		string ss = s.substr(k, n - k * 2);
		string lpp1 = lpp(ss);
		reverse(ss.begin(), ss.end());
		string lpp2 = lpp(ss);

		if (lpp1.length() > lpp2.length())
			cout << s.substr(0, k) << lpp1 << s.substr(n - k) << endl;
		else
			cout << s.substr(0, k) << lpp2 << s.substr(n - k) << endl;
	}

	return 0;
}
