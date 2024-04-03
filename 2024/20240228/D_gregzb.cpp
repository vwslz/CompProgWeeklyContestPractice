#include <bits/stdc++.h>
using namespace std;

template <class T>
using limits = numeric_limits<T>;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<
// long long,
// null_type,
// less<long long>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

// using uint128 = __uint128_t;
// using int128 = __int128_t;

using ull = unsigned long long;
using ll = long long;

// #define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL_COMPPROG_ENV
#define debug(...)
#else
#include "../templates/debug.hpp"
#endif

struct chash {
    template <class T>
    static void hash_combine(std::size_t& seed, const T& v)
    {
        std::hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }

    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template <class U, class V>
    size_t operator()(std::pair<U,V> p) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        size_t hash = std::hash<U>()(p.first);
        chash::hash_combine(hash, p.second);
        return splitmix64(hash + FIXED_RANDOM);
    }

    template <class A, class B>
    size_t operator()(std::tuple<A, B> p) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        size_t hash = std::hash<A>()(std::get<0>(p));
        chash::hash_combine(hash, std::get<1>(p));
        return splitmix64(hash + FIXED_RANDOM);
    }

    template <class A, class B, class C>
    size_t operator()(std::tuple<A, B, C> p) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        size_t hash = std::hash<A>()(std::get<0>(p));
        chash::hash_combine(hash, std::get<1>(p));
        chash::hash_combine(hash, std::get<2>(p));
        return splitmix64(hash + FIXED_RANDOM);
    }

    template <class A, class B, class C, class D>
    size_t operator()(std::tuple<A, B, C, D> p) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        size_t hash = std::hash<A>()(std::get<0>(p));
        chash::hash_combine(hash, std::get<1>(p));
        chash::hash_combine(hash, std::get<2>(p));
        chash::hash_combine(hash, std::get<3>(p));
        return splitmix64(hash + FIXED_RANDOM);
    }

    template <class T>
    size_t operator()(T x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(std::hash<T>()(x) + FIXED_RANDOM);
    }
};

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

const ll mod = 1000000009; // change to something else
template<class T, int N> struct Matrix {
	typedef Matrix M;
	array<array<T, N>, N> d{};
	M operator*(const M& m) const {
		M a;
		rep(i,0,N) rep(j,0,N)
			rep(k,0,N) {
                a.d[i][j] += d[i][k]*m.d[k][j];
                a.d[i][j] %= mod;
            }
		return a;
	}
	vector<T> operator*(const vector<T>& vec) const {
		vector<T> ret(N);
		rep(i,0,N) rep(j,0,N) {
            ret[i] += d[i][j] * vec[j];
            ret[i] %= mod;
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

void solve() {
    ll N, M, C;
    cin >> N >> M >> C;
    vector<ll> start(20);
    // vector<ll> end;
    Matrix<ll, 20> mat;
    // for (int i = 0; i < N; i++) {
    //     ll a;
    //     cin >> a;
    //     start[20-i-1] = a;
    //     // cin >> start[20-i-1];
    // }
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        start[N-i-1] = a;
        // cin >> start[20-i-1];
    }
    for (int i = 0; i < C; i++) {
        int v;
        cin >> v;
        mat.d[0][v-1] = 1;
    }
    if (M <= N) {
        cout << start[N-M] << "\n";
        return;
    }
    for (int i = 1; i < 20; i++) {
        mat.d[i][i-1] = 1;
    }
    // for (auto el : start) {
    //     std::cout << el << " ";
    // } std::cout << "\n";
    auto x = (mat^(M - N)) * start;
    cout << x[0] << "\n";
}

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
