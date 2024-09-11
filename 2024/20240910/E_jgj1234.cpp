#include <bits/stdc++.h>
#define pii pair<int,int>
#define pi 3.14159265358979323846
#define pb push_back
#define ppii pair<int, pair<int,int>>
#define pld pair<long long,double>
#define pibb pair<int,<bool,bool>>
#define yes "YES"
#define no "NO"
#define ll long long
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define MOD2 998244353
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
void solve(){
    int k;
    string s,t;
    cin>>k;
    cin>>s>>t;
    vector<int> b(k),c(k);
    for (int i = 0; i < k; i++){
        b[k-i-1] = (int)(s[i]-'a');
        c[k-i-1] = (int)(t[i]-'a');
    }
    ll curr = b[0]+c[0];
    vector<char> res;
    for (int i = 1; i < k; i++){
        curr+=26*(b[i]+c[i]);
        res.emplace_back(static_cast<char>(curr/2%26+97));
        curr/=26;
    }
    res.emplace_back(static_cast<char>(curr/2%26+97));
    for (int i = res.size()-1; i >=0; i--){
        cout<<res[i];
    }
}
int main(){
    int t=1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //cin>>t;
    while (t--){
        solve();
    }
}
