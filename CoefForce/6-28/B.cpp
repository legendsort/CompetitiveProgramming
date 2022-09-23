#include <bits/stdc++.h>

using namespace std;

int a[200011];
int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
    	int n, k; cin >> n >> k;
    	for(int i=1; i<=n; i++) cin >> a[i];
    	int ans = 0;
    	for(int i=2; i<n; i++) if(a[i] > a[i-1] + a[i+1]) ans ++;
    	if(k == 1) ans = n -1  >> 1;
    	cout << ans << endl;
    }
}


