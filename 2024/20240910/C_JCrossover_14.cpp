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
 int n;
 cin>>n;
 vector<int> nums(n);
 forn(i,n) cin>>nums[i];
 set<int> useda;
 set<int> usedb;
 vector<int> a;
 vector<int> b;
 bool yes = true;
 forn(i,n)
 {
    if(useda.find(nums[i])!=useda.end()&&usedb.find(nums[i])!=usedb.end())
    {
        yes = false;
        break;
    }
    if(useda.find(nums[i])==useda.end())
    {
        a.pb(nums[i]);
        useda.insert(nums[i]);
    }
    else
    {
        b.pb(nums[i]);
        usedb.insert(nums[i]);
    }
 }
 sort(a.begin(),a.end());
 sort(b.begin(),b.end(),greater<int>());
 if(yes)
 {
    cout<<"YES"<<ln;
    cout<<a.size()<<ln;
    for(int x:a) cout<<x<<" ";
    cout<<ln;
    cout<<b.size()<<ln;
    for(int x:b) cout<<x<<" ";
    cout<<ln;
 }
 else
 {
    cout<<"NO"<<ln;
 }
 return 0;
}
