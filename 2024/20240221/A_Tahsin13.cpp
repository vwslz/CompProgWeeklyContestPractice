#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a (k);
    for(int &x : a) cin >> x;
    vector<vector<pair<int, int>>> adj (n+1, vector<pair<int, int>>());
    for(int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }
    vector<long long> dist (n+1, LLONG_MAX);
    vector<int> orig (n+1);
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    for(int x : a) pq.push(make_tuple(0LL, x, x));
    while(!pq.empty())
    {
        long long d, u, p;
        tie(d, u, p) = pq.top();
        pq.pop();
        if(orig[u]) continue;
        dist[u] = d;
        orig[u] = p;
        for(auto e : adj[u])
        {
            int v, w;
            tie(v, w) = e;
            if(!orig[v])
                pq.push(make_tuple(d+w, v, p));
        }
    }
    long long ans = LLONG_MAX;
    for(int u = 1; u <= n; ++u)
    {
        for(auto e : adj[u])
        {
            int v, w;
            tie(v, w) = e;
            if(orig[u] != orig[v])
                ans = min(ans, dist[u]+dist[v]+w);
        }
    }
    cout<<ans<<"\n";
}
