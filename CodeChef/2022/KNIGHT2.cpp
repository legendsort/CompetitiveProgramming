#include <bits/stdc++.h>

using namespace std;


int solve() {
	int xx, xy, yx, yy;
	cin >> xx >> xy >> yx >> yy;
	int d = abs(xx - yx) + abs(xy - yy);
	d = 100 - 3 * d;
	puts(d % 2 == 0 ? "YES":"NO");
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


