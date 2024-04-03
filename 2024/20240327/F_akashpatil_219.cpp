#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ms memset
#define MOD 1000000007
#define MOD2 998244353
#define sp fixed<<setprecision
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
ll fpow(ll x,ll y,ll p=MOD){x=x%p;ll sum=1;while(y){if(y&1)sum=sum*x;sum%=p;y=y>>1;x=x*x;x%=p;}return sum;}
ll inv(ll a,ll m=MOD){ll c=m;ll y=0,x=1;if(m==1)return 0;while(a>1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=c;return x;}
ll add(ll a, ll b) {if(a<0)a+=MOD; if(b<0)b+=MOD; return (a%MOD + b%MOD + MOD)%MOD;}
ll sub(ll a, ll b) {if(a<0)a+=MOD; if(b<0)b+=MOD; return (a%MOD - b%MOD + MOD)%MOD;}
ll mul(ll a, ll b) {if(a<0)a+=MOD; if(b<0)b+=MOD; return ((a%MOD)*(b%MOD) + MOD)%MOD;}
void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
ll solve(vector<ll> &v, ll i, ll j){
    ll include = 0;
    ll exclude = 0;
    ll res = 0;
    for(ll k=i;k<j;k++){
        ll include_t = v[k] + exclude;
        ll exclude_t = max(include,exclude);
        //res = max(res,(max(include_t,exclude_t)));
        include = include_t;
        exclude = exclude_t;
        res = max(res,(max(include,exclude)));
    }
    return res;
}
int main(){
    setIO();
    ll t,n;
    t = 1;
    for(ll tc = 1; tc <=t ; tc++){
       cin >> n;
       vector<pair<ll,ll> >v(n);
       for(int i=0;i<n;i++){
            cin >> v[i].f >> v[i].se;
       }
       sort(v.begin(),v.end());
       ll cur_day = 0;
       for(int i=0;i<n;i++){
        if(v[i].se >= cur_day){
            cur_day = v[i].se;
        }
        else{
            cur_day = v[i].f;
        }
       }
       cout<<cur_day<<"\n";
    }
}
