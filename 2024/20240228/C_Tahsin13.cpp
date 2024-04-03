#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll choose(int n, int k)
{
    long long res = 1;
    for(int i = n-k+1; i <= n; ++i)
        res *= i;
    for(int i = 2; i <= k; ++i)
        res /= i;
    return res;
}

pair<ll, ll> add(pair<ll, ll> x, pair<ll, ll> y)
{
    ll a = x.first*y.second + y.first*x.second;
    ll b = x.second*y.second;
    ll g = __gcd(a, b);
    return make_pair(a/g, b/g);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    for(int t = 1; t <= tt; ++t)
    {
        int m; cin >> m;
        pair<ll, ll> ans = make_pair(0, 1);
        for(int i = 0; i < m; ++i)
        {
            int n, k; cin >> n >> k;
            ans = add(ans, make_pair(choose(n-1, k-1), choose(n, k)));
        }
        printf("Case %d: %lld/%lld\n", t, ans.first, ans.second);
    }
}
