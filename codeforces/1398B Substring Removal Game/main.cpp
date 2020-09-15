#include <algorithm>
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
        string s; cin >> s;
        vi v; v.resize(0);
        int i = 0, len = s.length();
        while (i < len) {
            if (s[i] == '0') {
                i++;
            } else {
                int c = 0;
                while (i < len && s[i] == '1') {
                    c++;
                    i++;
                }
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end());
        int ans = 0, n = v.size();
        for (int i = n - 1; i >= 0; i -= 2) {
            ans += v[i];
        }
        cout << ans << endl;
    }
    
    return 0;
}
