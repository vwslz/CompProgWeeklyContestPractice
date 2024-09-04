#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, m, x; cin >> n >> m >> x; x--;
        vector<int> a(n);
        a[x] = 1;
        for (int i = 2; i <= m+1; i++) {
            vector<int> b(n);
            int ri; cin >> ri;
            char ci; cin >> ci;
            for (int j = 0; j <= n-1; j++) {
                int x = a[j];
                if (ci == '0') {
                    if (x == i-1) {
                        b[(j + ri) % n] = i;
                    }
                } else if (ci == '1') {
                    if (x == i-1) {
                        b[(((j - ri) % n) + n) % n] = i;
                    }
                } else if (ci == '?') {
                    if (x == i-1) {
                        b[(j + ri) % n] = i;
                        b[(((j - ri) % n) + n) % n] = i;
                    }
                }
            }
            a = b;
        }
        vector<int> v;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == m+1) {
                v.push_back(i+1);
                ans++;
            }
        }
        cout << ans << endl;
        for (int e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
}
