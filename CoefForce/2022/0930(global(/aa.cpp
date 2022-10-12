#include <bits/stdc++.h>

using namespace std;

const int NN = 100011;
int a[NN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
	    int n; cin >> n;
	    int s=0;
	    int ans = n + 1;
	    for(int i=1; i<=n; i++) cin >> a[i];
		for(int i=1; i<=n; i++) {
		s += a[i]; int c=0;
		int temp = 0, mx=0;
		for(int j=1; j<=n; j++) {
		temp += a[j]; c++; 
		if(temp == s) temp = 0, mx=max(mx, c), c=0; 
		if(temp > s) break;
		}
		if(temp == 0) ans = min(ans, mx);
		}
		cout << ans << endl;
	}
}



