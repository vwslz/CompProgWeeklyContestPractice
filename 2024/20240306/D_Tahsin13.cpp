#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    for(int t = 1; t <= tt; ++t)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<string>> wishes (n, vector<string>(k));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < k; ++j)
                cin >> wishes[i][j];
        int p; cin >> p;
        vector<bool> have (m+1);
        for(int i = 0; i < p; ++i)
        {
            int x; cin >> x;
            have[x] = true;
        }
        bool ok = true;
        for(int i = 0; i < n; ++i)
        {
            int cnt = 0;
            for(int j = 0; j < k; ++j)
            {
                auto s = wishes[i][j];
                int x = stoi(s.substr(1));
                if(s[0] == '+' && have[x])
                    cnt++;
                if(s[0] == '-' && !have[x])
                    cnt++;
            }
            ok = ok && cnt;
        }
        printf("Case %d: %s\n", t, ok ? "Yes" : "No");
    }
}
