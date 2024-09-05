#include <bits/stdc++.h>
    
using namespace std;
#define pb push_back
#define int long long
const int INF = 1e18;
int mod = 998244353;
string solve(string s, int k){
    int n = s.size();
    if (n == 1) return s;
    char maxdigit = s[0];
    int maxidx = 0;
    for (int i=0; i<min(n, k+1); i++) {
        char c = s[i];
        if (c > maxdigit){
            maxdigit = c;
            maxidx = i;
        }
    }
    if (s[0] == maxdigit){
        string s0 = "";
        for (int i=1; i<n; i++) s0 += s[i];
        return s[0] + solve(s0, k);
    }
    k -= maxidx;
    for (int i=maxidx; i>=1; i--) s[i] = s[i-1];
    s[0] = maxdigit;
    // cout << s << '\n';exit(0);
    string s0 = "";
    for (int i=1; i<n; i++) s0 += s[i];
    return s[0] + solve(s0, k);

}
void solve(){  
    string s; cin >> s;
    int k; cin >> k;
    cout << solve(s, k) << "\n";

}
int32_t main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(nullptr);
    // inv_init();ож
    int t; t=1;
    // cin >> t;
    for (int i=0; i<t; i++){
        // cout << "Case " << i+1 << ": ";
        solve();
    }
}
