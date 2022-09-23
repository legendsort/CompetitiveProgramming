#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		scanf("%d %d", &n, &k);
		map<int, int> mp;
		for(int i=0; i<n; i++) {
			int a;
			scanf("%d", &a);
			mp[i%k] = max(mp[i%k], a);
		}
		long long ans = 0;
		for(int i=0; i<k; i++) {
			ans += mp[i];
		}
		cout << ans << endl;
	}
}
