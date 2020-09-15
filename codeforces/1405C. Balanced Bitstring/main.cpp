#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        bool err = false;

        for (int i = 0; i < n - k; i++) {
            if (s[i] == '?' && s[i + k] != '?') {
                s[i] = s[i + k];
            } else if (s[i] != '?' && s[i + k] == '?') {
                s[i + k] = s[i];
            } else if (s[i] != '?' && s[i + k] != '?' && s[i] != s[i + k]) {
                err = true;
                break;
            }
        }

        if (err) {
            cout << "NO" << endl;
            continue;
        }

        int c0 = 0, c1 = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == '0') {
                c0++;
            } else if (s[i] == '1') {
                c1++;
            }
        }
        if (c0 > k / 2 || c1 > k / 2) {
            err = true;
        }

        if (err) {
            cout << "NO" << endl;
            continue;
        }
        
        for (int i = k; i < n && !err; i++) {
            if (s[i - k] == '0') {
                c0--;
            } else if (s[i - k] == '1') {
                c1--;
            }
            if (s[i] == '0') {
                c0++;
            } else if (s[i] == '1') {
                c1++;
            }
            if (c0 > k / 2 || c1 > k / 2) {
                err = true;
                break;
            }
        }
        
        cout << (err ? "NO" : "YES") << endl;
    }
    
    return 0;
}
