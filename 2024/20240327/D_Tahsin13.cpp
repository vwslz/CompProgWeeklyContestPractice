#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    for(int t = 1; t <= tt; ++t)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if((r1+c1)%2 != (r2+c2)%2)
        {
            printf("Case %d: impossible\n", t);
            continue;
        }
        int dr = abs(r1-r2), dc = abs(c1-c2);
        printf("Case %d: %d\n", t, dr == dc ? 1 : 2);
    }
}
