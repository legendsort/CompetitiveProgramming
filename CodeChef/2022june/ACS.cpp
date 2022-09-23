#include <bits/stdc++.h>

using namespace std;

void solve() {
	int P; cin >> P;
	int ans = (P/100) + P%100;
	if(ans > 10) ans = -1;
	cout << ans << endl;
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


