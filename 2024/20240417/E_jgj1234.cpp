#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define pii pair<int,int>
#define plli pair<long long,int>
#define piii tuple<int,int,int>
using namespace std;
ll dfs(int d, vector<int> row){
    ll dp[row.size()];
    dp[0]=1;
    priority_queue<plli> pq;
    pq.push({-1,0});
    for (int i = 1; i<row.size();i++){
        while(!pq.empty() && pq.top().second<i-d-1){
            pq.pop();
        }
        dp[i]=-1*pq.top().first+row[i]+1;
        pq.push({-1*dp[i],i});
    }
    return dp[row.size()-1];
}
void solve(){
    int n,m,k,d;
    cin>>n>>m>>k>>d;
    vector<ll> res;
    for (int i = 0; i<n;i++){
        vector<int> row (m);
        for (int j = 0; j<m;j++){
            cin>>row[j];
        }
        res.push_back(dfs(d,row));
    }
    for (int i = 1;i<res.size();i++){
        res[i]+=res[i-1];
    }
    ll minimum=res[k-1];
    for (int i = k;i<res.size();i++){
        minimum=min(minimum,res[i]-res[i-k]);
    }
    cout<<minimum<<endl;
}
int main(){
   int num_tests;
   cin>>num_tests;
   while(num_tests--){
        solve();
   }
}
