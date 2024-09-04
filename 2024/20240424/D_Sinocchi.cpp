#include <bits/stdc++.h>
using namespace std;
#define pb push_back

#define int long long
int INF = 1e18;
int mod = 1e9+7;
void solve(){
    vector<array<int, 2>> d = {{0, 1}, {-1, 0}, {0, -1}, {1, 0},
    {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
    int n, m; cin >> n >> m;
    vector<vector<array<int, 8>>> maxw(n,
        vector<array<int, 8>>(m, {0, 0, 0, 0, 0, 0, 0, 0}));
    vector<string> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    auto inbounds = [&](int i, int j){
        return 0 <= i && i < n && 0<=j && j < m;
    };
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) for (int k=0; k<8; k++) if (v[i][j] == '0'){
        int cx = i; int cy = j;
        while (1){
            auto [dx, dy] = d[k];
            cx += dx; cy += dy;
            if (inbounds(cx, cy) && v[cx][cy] == '0'){
                maxw[i][j][k]++;
            }
            else break;
        }
    }
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++) cout << maxw[i][j][0]; cout << "\n";
    // }
    //0, 1: 5
    //1, 2:
    int res = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            for (int k=1; k<min(m, n); k++){
                //d = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
                //right
                if (maxw[i][j][0] >= k && maxw[i][j][1] >= k && maxw[i][j+k][5] >= k) res++;
                //up
                if (maxw[i][j][1] >= k && maxw[i][j][2] >= k && maxw[i-k][j][6] >= k) res++;
                //left
                if (maxw[i][j][2] >= k && maxw[i][j][3] >= k && maxw[i][j-k][7] >= k) res++;
                //down
                if (maxw[i][j][3] >= k && maxw[i][j][0] >= k && maxw[i+k][j][4] >= k) res++;
                //topright
                if (maxw[i][j][4] >= k && maxw[i][j][5] >= k && maxw[i-k][j+k][2] >= 2*k) res++;
                //topleft
                if (maxw[i][j][5] >= k && maxw[i][j][6] >= k && maxw[i-k][j-k][3] >= 2*k) res++;
                //bottomleft
                if (maxw[i][j][6] >= k && maxw[i][j][7] >= k && maxw[i+k][j-k][0] >= 2*k) res++;
                //bottomright
                if (maxw[i][j][7] >= k && maxw[i][j][4] >= k && maxw[i+k][j+k][1] >= 2*k) res++;
            }
        }
    }
    cout << res << "\n";


}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    // inv_init();
    int t; t=1;
    // cin >> t;
    for (int i=0; i<t; i++){
        // cout << "Case " << i+1 << ": ";
        solve();
    }
}
