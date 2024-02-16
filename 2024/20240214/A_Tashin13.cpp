#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--)
    {
        int a, b, c; cin >> a >> b >> c;
        if(a == b) cout<<c<<"\n";
        else if(a == c) cout<<b<<"\n";
        else cout<<a<<"\n";
    }
}
