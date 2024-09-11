#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin>>n;
	int a[n]; for (int i = 0; i < n; i++) cin>>a[i];
	int l = -1, r = -2, most = 0;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	for (auto x : cnt) {
		if (x.second > most) {
			most = x.second;
		}
	}
	for (auto x : cnt) {
		if (x.second==most) {
			for (int i = 0; i < n; i++) {
				if (a[i]==x.first) {
					l = i;
					r = i;
					break;
				}
			}
			break;
		}
	}
	vector<vector<int>> v;
	for (int i = l-1; i >= 0; i--) {
		if (a[i]==a[l]) continue;
		int type = 1;
		if (a[i] > a[l]) type = 2;
		v.push_back({type, i+1, i+2});
	}
	for (int i = r+1; i < n; i++) {
		if (a[i]==a[r]) continue;
		int type = 1;
		if (a[i] > a[l]) type = 2;
		v.push_back({type, i+1, i});
	}
	cout<<v.size()<<'\n';
	for (auto x : v)
		cout<<x[0]<<' '<<x[1]<<' '<<x[2]<<'\n';
	return 0;
}
