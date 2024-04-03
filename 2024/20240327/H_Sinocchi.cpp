#include <bits/stdc++.h>
using namespace std;
#define pb push_back

#define int long long
int INF = 1e18;
int mod = 1e9+7;
int inv(int a, int b){
    return 1<a ? b - inv(b%a,a)*b/a : 1;
}
int inv(int a){
    return inv(a, mod);
}
void solve(){
    int a, b; cin >> a >> b;
    int x = 1;
    x *= a; x %= mod;
    x *= b; x %= mod;
    x *= (b-1); x %= mod;
    x *= inv(2); x %= mod;
    int y = 1;
    y *= (b-1); y %= mod;
    y *= b; y %= mod;
    y *= b; y %= mod;
    y *= inv(2); y %= mod;
    y *= a; y %= mod;
    y *= a+1; y %= mod;
    y *= inv(2); y %= mod;
    cout << (x+y)%mod << "\n";


}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    // inv_init();
    int t; t=1;
    // cin >> t;
    for (int i=0; i<t; i++){
        // cout << "Case " << i+1 << ": ";
        solve();
    }
}
