#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int color[N];
vector<int> e[N];
string ans;

struct Edge {
    int u, v, id;

    void read(int i) {
        id = i;
        cin >> u >> v;
        e[u].push_back(i);
        e[v].push_back(i);
    }

    int another(int x) {
        return u ^ v ^ x;
    }

    int side(int x) {
        return x == u;
    }

}ed[N];


bool dfs(int u, int p) {
    for (int i: e[u]) {
        int v = ed[i].another(u);
        if (v == p) continue;
        if (color[v] == -1) {
            color[v] = color[u] ^ 1;
            if (!dfs(v, u)) return false;
        } else if (color[v] == color[u]) {
            return false;
        }
        ans[i] = '0' + (color[u] ? ed[i].side(u) : ed[i].side(v));
    }
    return true;
}

void Solve() {
    int n, m;
    cin >> n >> m;
    ans.resize(m);
    for (int i = 0; i < m; ++i) {
        ed[i].read(i);
    }
    memset(color, -1, sizeof(color));
    color[1] = 0;
    if (dfs(1, -1)) {
        cout << "YES\n" << ans << '\n';
    } else {
        color[1] = 1;
        if (dfs(1, -1)) {
            cout << "YES\n" << ans << '\n';
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    // cin >> test;
    while (test--) Solve();
}
