#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;
int pre[N][2][26], suf[N][2][26];

void Solve() {
    string s; int n;
    cin >> n >> s;
    for (int i = 0; i <= n; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 26; ++k) pre[i][j][k] = suf[i][j][k] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            pre[i][j][s[i] - 'a'] = (i % 2 == j) ? 1 : 0;
            if (i) {
                for (int k = 0; k < 26; ++k) 
                    pre[i][j][k] += pre[i - 1][j][k];
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 2; ++j) {
            suf[i][j][s[i] - 'a'] = (i % 2 == j) ? 1 : 0;
            if (i + 1 < n) {
                for (int k = 0; k < 26; ++k) 
                    suf[i][j][k] += suf[i + 1][j][k];
            }
        }
    }

    if (n % 2 == 0) {
        cout << n - *max_element(suf[0][0], suf[0][0] + 26) - *max_element(suf[0][1], suf[0][1] + 26) << '\n'; 
    } else {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // Del this i 
            for (int even = 0; even < 26; ++even) {
                for (int odd = 0; odd < 26; ++odd) {
                    int cur = 0;
                    if (i) cur += pre[i - 1][0][even] + pre[i - 1][1][odd];
                    if (i + 1 < n) cur += suf[i + 1][0][odd] + suf[i + 1][1][even];
                    ans = max(ans, cur);
                }
            }
        }
        cout << n - ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int test;
    cin >> test;
    while (test--) Solve();
}
