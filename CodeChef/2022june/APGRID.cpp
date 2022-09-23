#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			int a = (2*i-1) * j;
			if((2 * n - 1) * m > (2 * m - 1) * n) a = (2 * j - 1) * i;
			cout<<a <<' ';
		}
		cout << endl;
	}
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


