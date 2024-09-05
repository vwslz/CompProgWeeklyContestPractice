#include <bits/stdc++.h>
using namespace std;
void solve() {
	int a[2], b[2]; cin>>a[0]>>a[1]>>b[0]>>b[1];
	int ans = 0;
	for (int i : {0, 1})
		for (int j : {0, 1}) {
			int cur = 0;
			if (a[i]>b[j]) cur++;
			if (a[i]<b[j]) cur--;
			if (a[i^1]>b[j^1]) cur++;
			if (a[i^1]<b[j^1]) cur--;
			if (cur>0) ans++;
		}
	cout<<ans<<'\n';
}
int main() {
	int t = 1;
	cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}
