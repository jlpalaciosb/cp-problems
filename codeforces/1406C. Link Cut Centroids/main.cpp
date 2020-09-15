#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vi::iterator viit;

int n;;
vector<vi> adj(100001);
vi p(100001), d(100001), s(100001), c(100001), x(100001);

void dfs1(int u, int p_, int d_) {
    p[u] = p_;
    d[u] = d_;
    s[u] = c[u] = 1;

    viit end = adj[u].end();
    for (viit it = adj[u].begin(); it < end; it++) {
        int v = *it;
        if (v != p[u]) {
            dfs1(v, u, d_ + 1);
            s[u] += s[v];
            c[u] = max(c[u], s[v]);
        }
    }

    c[u] = max(c[u], n - s[u]);
}

void dfs2(int u) {
    x[u] = 1;

    viit end = adj[u].end();
    for (viit it = adj[u].begin(); it < end; it++) {
        int v = *it;
        if (v != p[u]) {
            dfs2(v);
        }
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int u = 1; u <= n; u++) adj[u].clear();
        for (int i = 0; i < n - 1; i++) {
            int u, v; scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs1(1, 0, 0);

        int minc = c[1];
        for (int u = 2; u <= n; u++) if (c[u] < minc) minc = c[u];
        int nc = 0;
        for (int u = 1; u <= n; u++) if (c[u] == minc) nc++;

        int ansa = adj[1][0], ansb = 1, ansc = adj[1][0];
        if (nc > 1) {
            int maxd = 0, maxdu;
            for (int u = 1; u <= n; u++) {
                if (c[u] == minc && d[u] > maxd) {
                    maxd = d[u];
                    maxdu = u;
                }
            }

            x.assign(n + 1, 0);
            dfs2(maxdu);

            ansa = maxdu, ansb = 1, ansc = adj[1][0];
            for (int u = 1; u <= n; u++) {
                if (s[u] == 1 && x[u] == 0) {
                    ansb = u;
                    ansc = p[u];
                    break;
                }
            }
        }
        printf("%d %d\n%d %d\n", ansb, ansc, ansa, ansb);
    }
    
    return 0;
}
