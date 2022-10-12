#include <bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 100011;
int a[NN];

INT	 solve() {
	int n, k;
	cin >> n >> k;
	map<int, int> mp;
	for(int i=1; i<=n; i++) cin >> a[i], mp[a[i]] = 1;
	sort(a+1, a+n+1);
	if(k == 1) {
		for(int i=1; i<=n*2; i++) if(mp[i] == 0) return max(0, a[n]-i);
	}
	INT sum = 0, ans = -1e9;
	int cnt = k;
	for(int i=1; i<=2*n; i++) {
		if(mp[i] == 0) {
			if(cnt == 1) {
				if(i < a[n]) {
					ans = 1ll * a[n] * k - sum - i;
				}
				break;
			}
			sum += i;
			cnt--;
	
		}
	}
	if(a[n] != 2 * n) {
		ans = max(ans, 2ll * n * (k-1) - sum);
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--) cout << solve() << endl;

}



