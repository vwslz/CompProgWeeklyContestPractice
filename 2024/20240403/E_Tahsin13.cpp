#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(const vector<vector<pair<int, int>>>& adj, int root)
{
    vector<int> dist (adj.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, root));
    while(!pq.empty())
    {
        int d, u;
        tie(d, u) = pq.top();
        pq.pop();
        if(dist[u] < INT_MAX) continue;
        dist[u] = d;
        for(auto e : adj[u])
        {
            int v, w;
            tie(v, w) = e;
            if(dist[v] == INT_MAX)
                pq.push(make_pair(d+w, v));
        }
    }
    return dist;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    for(int t = 1; t <= tt; ++t)
    {
        int n; cin >> n;
        vector<vector<pair<int, int>>> adj (n);
        for(int i = 0; i < n-1; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        auto d1 = dfs(adj, 0);
        int x = max_element(d1.begin(), d1.end())-d1.begin();
        auto d2 = dfs(adj, x);
        int y = max_element(d2.begin(), d2.end())-d2.begin();
        auto d3 = dfs(adj, y);
        cout<<"Case "<<t<<":\n";
        for(int i = 0; i < n; ++i)
            cout<<max(d2[i], d3[i])<<"\n";
    }
}
