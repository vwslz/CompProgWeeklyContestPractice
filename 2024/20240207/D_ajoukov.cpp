#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define pb(x) push_back(x)

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



int solve() {
    int n;
    cin >> n;
    if (n == 0)
        return 0;

    vector<int> L(n);
    vector<int> W(n);
    vector<int> H(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> W[i] >> H[i];
    }
    int index = -1;
    int h = -1;
    int v = -1;
    for (int i = 0; i < n; i++) {
        if (H[i] > h) {
            h = H[i];
            v = L[i] * W[i] * H[i];
            index = i;
        } else if (H[i] == h) {
            if (L[i] * W[i] * H[i] > v) {
                h = H[i];
                v = L[i] * W[i] * H[i];
                index = i;
            }
        }
    }
    cout << L[index] * W[index] * H[index] << endl;
    return -1;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    // int tc = 1;
    // cin >> tc;
    // for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
    while (true) {
        int ret = solve();
        if (ret == 0) {
            return 0;
        }
    }
}
