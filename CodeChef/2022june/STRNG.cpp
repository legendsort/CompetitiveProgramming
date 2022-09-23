#include <bits/stdc++.h>

using namespace std;

const int NN = 300011;
int L[NN], R[NN], a[NN];

void solve() {
	int n; cin >> n;
	map<int, int> mp;
	int mx = 0;
	int g = 0;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		L[i] = __gcd(L[i-1], a[i]);		
	}
	R[n+1] = 0;
	for(int i=n; i>=1; i--) {
		R[i] = __gcd(R[i+1], a[i]);
	}
	int ans = 0;
	if(L[n] > 1) ans = n;
	else for(int i=1; i<=n; i++) if(__gcd(L[i-1], R[i+1]) > 1) ans ++;
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


