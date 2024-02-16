#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        vector<string> v(3);
        cin >> v[0] >> v[1] >> v[2];
        vector<int> f(3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (v[i][j] != '?') {
                    f[(int)v[i][j]-65]++;
                }
            }
        }
        if (f[0] == 2) {
            cout << 'A' << endl;
        } else if (f[1] == 2) {
            cout << 'B' << endl;
        } else {
            cout << 'C' << endl;
        }
    }
}
