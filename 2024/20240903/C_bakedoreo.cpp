#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>    
#define ll long long    
#define pb push_back    
#define mp make_pair
#define ii pair<int, int>
#define fst first
#define snd second
#define MOD 1000000007
using namespace std;    
const int N = 1e5 + 5;
    
    
void sol() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int ans = 1;
	int space = m;
	for (int i = 0; i < n; i++) {
		if (a[i] <= space) space -= a[i];
		else if (a[i] > space) {
			space = m - a[i];
			ans++;
		}
	}

	cout << ans << endl;

}
    
    
int main() {    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;    
	// cin >> t;    
	while (t--) {    
		sol();    
	}    
}
