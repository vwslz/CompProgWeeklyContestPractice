// add me on genshin impact! 607984574
// Problem: H - Two Merged Sequences
// Attempted: 2024-09-10 19:47:45 EST

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#ifdef UwU
#include "C:\genshin_impact\keqing.cpp"
#else
#define debug(...) 0
#endif
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFLL = 1e18;
 
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)
#define sz(x) (int)x.size()
#define make_unique(v) sort(all(v)); v.erase(unique(all(v)), v.end())

template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {
	int n; cin >> n;
	vector<int> a(n); cin >> a;
	vector<int> inc = {-INF}, dec = {INF};
	vector<int> status(n);
	FOR(i,0,n){
		if(a[i] > inc.back() && a[i] < dec.back()){
			if(i+1 < n && a[i+1] > a[i]){
				// leave room for next to be in dec because it cant be inc anyways
				inc.pb(a[i]);
			}
			else{
				status[i] = 1;
				dec.pb(a[i]);
			}
		}
		else if(a[i] > inc.back()){
			inc.pb(a[i]);
		}
		else if(a[i] < dec.back()){
			status[i] = 1;
			dec.pb(a[i]);
		}
		else{
			debug(inc);
			debug(dec);
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	cout << status << endl;
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/
