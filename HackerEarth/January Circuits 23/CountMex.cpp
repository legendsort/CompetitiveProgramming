#include <bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 300111;
int p[NN];
int pos[NN];
INT cnt[NN];
int n;

void solve() {
	cin >> n;
	for(int i=0; i<n; i++) cin >> p[i];
	for(int i=0; i<n; i++) pos[p[i]] = i;
	int L = pos[0], R = pos[0];
	for(int i=0; i<n; i++) {
		L = min(L, pos[i]);
		R = max(R, pos[i]);
		cnt[i+1] = (INT)(L+1) * (n - R);
	}
	for(int i=1; i<=n; i++) {
		cout << cnt[i] - cnt[i + 1] << ' ';
	}
	cout << endl;
	for(int i=1; i<=n; i++) cnt[i] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) solve();
}



