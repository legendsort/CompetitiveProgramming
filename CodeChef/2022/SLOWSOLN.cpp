#include <bits/stdc++.h>

using namespace std;


int solve() {
	int maxT, maxN, maxS;
	cin >> maxT >> maxN >> maxS;
	int ans = 0;
	int k = min(maxT, maxS/maxN);
	ans += maxN * maxN * k;
	maxS -= maxN * k;
	for(int i=k+1; i<=maxT; i++) {
		int now = min(maxN, maxS);
		ans += now * now;
		maxS -= now;	
	}
	cout << ans << endl;
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


