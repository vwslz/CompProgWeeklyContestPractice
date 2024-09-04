#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int INF = 1e18;
const int MZ = 50;
template<class T, int N> struct Matrix {
	typedef Matrix M;
	array<array<T, N>, N> d{};
	M operator*(const M& m) const {
		M a;
		rep(i,0,N) rep(j,0,N)
			rep(k,0,N){
                a.d[i][j] += d[i][k]*m.d[k][j];
            }
		return a;
	}
	vector<T> operator*(const vector<T>& vec) const {
		vector<T> ret(N);
		rep(i,0,N) rep(j,0,N){
            ret[i] += d[i][j] * vec[j];
        }
		return ret;
	}
	M operator^(ll p) const {
		assert(p >= 0);
		M a, b(*this);
		rep(i,0,N) a.d[i][i] = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};
string pref(string s, int x){
    string ns = "";
    for (int i=x; i>=1; i--){
        ns += s[s.size()-i];
    }
    return ns;
}
string suf(string s, int x){
    return s.substr(0, x);
}
void solve(){
    int N; cin >> N;
    string chs; cin >> chs;
    int m = chs.size();
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            string ns = s.substr(0, i);
            ns += chs[j];
            int ni = 0;
            // find max prefix of ns which is a suffix
            for (int a=1; a<=min((int)ns.size(), n); a++){
                if (suf(s, a) == pref(ns, a)) ni = a;
            }
            if (ni < n) v[ni][i] += 1;
        }
    }
    Matrix<uint32_t, MZ> M;
    for (int i=0; i<MZ; i++){
        for (int j=0; j<MZ; j++){
            if (i<n && j<n) M.d[i][j] = v[i][j];
            else M.d[i][j] = 0;
        }
    }
    Matrix <uint32_t, MZ> M2 = M^N;
    // for (int i=0; i<2; i++){
    //     for (int j=0; j<2; j++){
    //         cout << M2.d[i][j] << ' ';
    //     }cout << "\n";
    // }
    vector<uint32_t> vec(MZ, 0); vec[0] = 1;
    vector<uint32_t> MP = M2*vec;
    uint32_t total = 0;
    for (int i=0; i<MZ; i++){
        total += MP[i];
    }
    cout << total << "\n";
    // vector<uint32_t
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<n; j++){
    //         cout << v[i][j] <<' ';
    //     }cout << "\n";
    // }

}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    // inv_init();
    int t; t=1;
    cin >> t;
    for (int i=0; i<t; i++){
        cout << "Case " << i+1 << ": ";
        solve();
    }
}
