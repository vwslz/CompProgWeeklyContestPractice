#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int pwr = 4194304; //2^22
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(pwr, -1);
    //dp[j] := some a[i] if there is an a[i] compatible with j, otherwise -1.
    for (int i = 0; i < n; i++) {
        dp[pwr-1-a[i]] = a[i]; //a[i] is compatible with its complement
    }
    for (int j = pwr-2; j >= 0; j--) {
        int x = 1;
        while (x < pwr) {
            dp[j] = max(dp[j|x],dp[j]); //a[i] is compatible with j
                                        //iff 
                                        //j is one of the original complements of some a[I], or 
                                        //a[i] is also compatible with at least one
                                        //[j, but with an extra zero flipped to one]
            x *= 2;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dp[a[i]] << " ";
    }
    cout << endl;
}
