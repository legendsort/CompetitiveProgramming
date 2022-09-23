#include <bits/stdc++.h>

using namespace std;


int solve() {
	int n, x;
	cin >> n >> x;
	x = max(0, n - x);
	cout << (x + 3) / 4 << endl;
	return 0;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) solve();
}


