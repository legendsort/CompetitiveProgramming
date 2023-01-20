#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	int n, k;
	cin >> n >> k;
	cin >> s;
	map<char, int> mp;
	for(int i=0; i<n; i++) {
		mp[s[i]]++;
	}
	int ans = 0;
	for(int i='a'; i<='z'; i++) {
		int now = (mp[i] + k - 1) / k;
		ans = max(ans, now);
	}
	cout << ans << endl;
	
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin >> T;
	while(T--) solve();
}	



