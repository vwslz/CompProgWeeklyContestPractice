#include <bits/stdc++.h>
using namespace std;
#define pb push_back

#define int long long
// int INF = 1e18;
// int mod = 1e9+7;
// int mod2 = 100001357;
double EPS = 1e-8;
// #define ll long long int
// vector<vector<int>> adj;
void solve(){
    int n, k; cin >> n >> k; n--;
    vector<int> B(n+1);
    for (int i=0; i<n+1; i++) cin >> B[i];
    vector<int> v(n);
    for (int i=0; i<n; i++) v[i] = B[i+1] - B[i];
    vector<int> cur(n);
    for (int i=0; i<n; i++) cur[i] = v[i];
    vector<int> l(n);
    vector<int> r(n);
    for (int i=0; i<n; i++){
        l[i] = i-1;
        r[i] = i+1;
    }
    multiset<array<int, 2>> s;
    for (int i=0; i<n; i++) s.insert({v[i], i});
    int res = 0;
    for (int _=0; _<k; _++){
        auto [__, i] = *s.begin();
        s.erase(s.begin());
        res += cur[i];
        // cout << i << "\n";
        if (l[i] == -1 && r[i] == n){
        }
        else if (l[i] == -1){
            s.erase({cur[r[i]], r[i]});
            if (r[r[i]] != n){
                l[r[r[i]]] = -1;
            }
        }
        else if (r[i] == n){
            s.erase({cur[l[i]], l[i]});
            if (l[l[i]] != -1){
                r[l[l[i]]] = n;
            }
        }
        else{
            int L = l[i];
            int R = r[i];

            s.erase({cur[L], L});
            s.erase({cur[R], R});
            s.erase({cur[i], i});
            cur[i] = cur[L]+cur[R] - cur[i];
            s.insert({cur[i], i});
            l[i] = l[L]; r[i] = r[R];
            if (r[i] != n) l[r[i]] = i;
            if (l[i] != -1) r[l[i]] = i;
        }
    }
    cout << res << "\n";

}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    // inv_init();
    int t; t=1;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
}  
