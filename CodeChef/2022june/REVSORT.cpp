#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	int mx = 0;
	ans = 1;
	for(int i=1; i<=n; i++) {
		int a; cin >> a;
		if(mx > a and mx + a > x) ans = 0;
	}
	puts(ans ? "YES" : "NO");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--) solve();
}


