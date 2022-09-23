#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	map<int, int> mp;
	int mx = 0;
	for(int i=0; i<n; i++) {
		int a; cin >> a;
		mp[a]++;
		mx = max(mp[a], mx);
	}
	cout << n - mx << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) solve();
}


