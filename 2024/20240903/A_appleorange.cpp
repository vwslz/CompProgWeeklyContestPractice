#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int sum = 0;
        while(n){
            sum += n%10;
            n /= 10;
        }
        cout << sum << endl;
    }
    return 0;
}

