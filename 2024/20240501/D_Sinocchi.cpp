#include <bits/stdc++.h>
using namespace std;
#define pb push_back

#define int long long
int INF = 1e18;
int mod = 1e9+7;
void solve(){
    map<string, int> mmonth = {
        {"January", 1},
        {"February", 2},
        {"March", 3},
        {"April", 4},
        {"May", 5},
        {"June", 6},
        {"July", 7},
        {"August", 8},
        {"September", 9},
        {"October", 10},
        {"November", 11},
        {"December", 12}
    };
    string a, b, c; cin >> a >> b >> c;
    string d, e, f; cin >> d >> e >> f;
    auto getdays = [&](string a, string b, string c, int countlast){
        int month = mmonth[a];
        int day = stoi(b.substr(0, (int)b.size()-1));
        int year = stoi(c);
        int d4 = (year-1)/4;
        int d100 = (year-1)/100;
        int d400 = (year-1)/400;
        int total = d4 - d100 + d400;
        int cnt = 0;
        // cout << month << ' ' << day << ' ' << year << "\n";
        if (year%4 == 0){
            if (year % 100 != 0 || year % 400 == 0){
                if (month >= 3) cnt = 1;
                else if (month == 2){
                    if (countlast && day == 29) cnt = 1;
                }
            }
        }
        return total+cnt;

    };
    cout << getdays(d, e, f, 1) - getdays(a, b, c, 0) << "\n";


}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    // inv_init();
    int t; t=1;
    cin >> t;
    for (int i=0; i<t; i++){
        cout << "Case " << i+1 << ": ";
        solve();
    }
}
