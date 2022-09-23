#include <bits/stdc++.h>

using namespace std;

int x, y, n, r;

int solve() {
	cin >> x >> y >> n;
	long long ans = (n+x-1) / x * x;
	int step = 1000;
	while(step--) {
		if(ans % y != 0) return ans;
		ans += x;	
	}
	return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) cout << solve() << endl;
}


