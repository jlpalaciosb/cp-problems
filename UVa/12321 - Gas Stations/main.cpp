#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

int main() {
    int L, G;
    while (cin >> L >> G, L != 0) {
        vector<ii> v; v.resize(G);
        for (int i = 0; i < G; i++) {
            int x, rad; cin >> x >> rad;
            int l = max(0, x - rad), r = min(L, x + rad);
            v[i] = ii(l, -r);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < G; i++) v[i].second *= -1;

        int rea = 0, i = 0, c = 0;
        while (i < G && rea < L) {
            if (v[i].first > rea) break;
            int m = v[i].second;
            int j = i + 1;
            while (j < G && v[j].first <= rea) {
                m = max(m, v[j].second);
                j++;
            }
            rea = m;
            i = j;
            c++;
        }

        if (rea == L) cout << G - c << endl;
        else cout << -1 << endl;
    }
    return 0;
}
