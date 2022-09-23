#include <bits/stdc++.h>

using namespace std;

int x, y, n, r;

void solve() {
	cin >> x >> y >> n >> r;
	int st = 0, ed=  n+1;
	if(1ll *x * n > r) {
		cout << -1 << endl;
		return ;
	}
	while(ed > st + 1) {
		int mid = st + ed >> 1;
		long long cost = 1ll * mid * y + 1ll * (n - mid) * x;
		if(cost <= r) st = mid;
		else ed = mid;
	}
	cout << n - st << ' ' << st << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) solve();
}


