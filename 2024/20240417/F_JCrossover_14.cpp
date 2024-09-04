#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace__gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define otree tree<ll,ll,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

void solve(){
}
int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++)
 {
    int n,m,k;
    cin>>n>>m>>k;
    vector<ll> prepared(n);
    forn(i,n) cin>>prepared[i];
    vector<ll> models(m);
    forn(i,m) cin>>models[i];
    vector<ll> complexities(k);
    forn(i,k) cin>>complexities[i];
    sort(models.begin(),models.end());
    sort(complexities.begin(),complexities.end());
    vector<pair<ll,pair<ll,ll>>> diffs;
    for(int i=1;i<n;i++)
    {
        diffs.pb(mp(prepared[i]-prepared[i-1],mp(prepared[i],prepared[i-1])));
    }
    sort(diffs.begin(),diffs.end());
    ll bigger =diffs[diffs.size()-1].second.first;
    ll smaller = diffs[diffs.size()-1].second.second;
    ll target = (bigger+smaller)/2;
    ll ans = bigger-smaller;

    for(int i=0;i<m;i++)
    {
        int ind = lower_bound(complexities.begin(),complexities.end(),target-models[i])-complexities.begin();
        ll newdiff;
        newdiff = max(abs(models[i]+complexities[ind]-bigger),abs(models[i]+complexities[ind]-smaller));
        if(diffs.size()>=2)
        {
            newdiff=max(newdiff,diffs[diffs.size()-2].first);
        }
        ans = min(ans,newdiff);
        if(ind>0)
        {
            ind--;
                newdiff = max(abs(models[i]+complexities[ind]-bigger),abs(models[i]+complexities[ind]-smaller));
                if(diffs.size()>=2)
                {
                    newdiff=max(newdiff,diffs[diffs.size()-2].first);
                }
                ans = min(ans,newdiff);

            ind++;
        }
        if(ind<k-1)
        {
            ind++;
                newdiff = max(abs(models[i]+complexities[ind]-bigger),abs(models[i]+complexities[ind]-smaller));
                if(diffs.size()>=2)
                {
                    newdiff=max(newdiff,diffs[diffs.size()-2].first);
                }
            ans = min(ans,newdiff);
        }
    }
    cout<<ans<<ln;

 }
 return 0;
}
