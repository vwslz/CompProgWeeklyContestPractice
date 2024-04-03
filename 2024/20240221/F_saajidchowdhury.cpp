#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; getline(cin, s);
    while ((int)s.size() >= 1 and (60 <= (int)s[0] or (int)s[0] <= 71)) {
        int n, m;
        istringstream is(s);
        is >> n >> m;
        vector<int> a(n);
        vector<vector<int>> f(1000001);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            f[a[i]].push_back(i); //stores zero indecex
        }
        for (int i = 0; i < m; i++) {
            int k, v; cin >> k >> v;
            k--;
            if (k < (int)f[v].size()) {
                cout << f[v][k]+1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
        getline(cin, s);
        getline(cin, s);
    }
}
