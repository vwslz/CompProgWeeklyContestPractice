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

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#ifndef LOCAL_COMPPROG_ENV
#define debug(...)
#else
#include "../templates/debug.hpp"
#endif

struct chash
{
    template <class T>
    static void hash_combine(std::size_t &seed, const T &v)
    {
        std::hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template <class U, class V>
    size_t operator()(std::pair<U, V> p) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        size_t hash = std::hash<U>()(p.first);
        chash::hash_combine(hash, p.second);
        return splitmix64(hash + FIXED_RANDOM);
    }

    template <class A, class B>
    size_t operator()(std::tuple<A, B> p) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        size_t hash = std::hash<A>()(std::get<0>(p));
        chash::hash_combine(hash, std::get<1>(p));
        return splitmix64(hash + FIXED_RANDOM);
    }

    template <class A, class B, class C>
    size_t operator()(std::tuple<A, B, C> p) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        size_t hash = std::hash<A>()(std::get<0>(p));
        chash::hash_combine(hash, std::get<1>(p));
        chash::hash_combine(hash, std::get<2>(p));
        return splitmix64(hash + FIXED_RANDOM);
    }

    template <class A, class B, class C, class D>
    size_t operator()(std::tuple<A, B, C, D> p) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        size_t hash = std::hash<A>()(std::get<0>(p));
        chash::hash_combine(hash, std::get<1>(p));
        chash::hash_combine(hash, std::get<2>(p));
        chash::hash_combine(hash, std::get<3>(p));
        return splitmix64(hash + FIXED_RANDOM);
    }

    template <class T>
    size_t operator()(T x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(std::hash<T>()(x) + FIXED_RANDOM);
    }
};

struct RatPop
{
    int x, y, pop;
};

template <class T>
struct SubMatrix
{
    vector<vector<T>> p;
    SubMatrix(vector<vector<T>> &v)
    {
        int R = sz(v), C = sz(v[0]);
        p.assign(R + 1, vector<T>(C + 1));
        rep(r, 0, R) rep(c, 0, C)
            p[r + 1][c + 1] = v[r][c] + p[r][c + 1] + p[r + 1][c] - p[r][c];
    }
    T sum(int u, int l, int d, int r)
    {
        return p[d][r] - p[d][l] - p[u][r] + p[u][l];
    }
};

void solve()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int d, n;
        cin >> d >> n;

        vector<vector<int>> pop_grid(1025, vector<int>(1025));

        // vector<RatPop> pops(n);
        for (int i = 0; i < n; i++)
        {
            int x, y, pop;
            cin >> x >> y >> pop;
            pop_grid[x][y] = pop;
            // cin >> pops[i].x >> pops[i].y >> pops[i].pop;
        }

        SubMatrix<int> pop_sums(pop_grid);

        int mx = 0;
        int mxx = 0;
        int mxy = 0;

        for (int x = 0; x < 1025; x++)
        {
            for (int y = 0; y < 1025; y++)
            {
                int v = pop_sums.sum(max(0, x - d), max(0, y - d), min(1025, x + d + 1), min(1025, y + d + 1));
                if (v > mx) {
                    mx = v;
                    mxx = x;
                    mxy = y;
                }
            }
        }

        cout << mxx << " " << mxy << " " << mx << "\n";
    }
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
