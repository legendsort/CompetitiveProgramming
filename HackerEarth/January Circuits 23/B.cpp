#include <bits/stdc++.h>

using namespace std;

int pairs[3][3];
int cnt[3];

void solve() {
	string s, t;
	cin >> s;
	t = s;
	int n = s.size();
	vector<int> vec;
	for(int i=0; i<3; i++) vec.push_back(i), cnt[i] = 0;
	for(int i=0; i<n; i++) cnt[s[i]-'0']++;
	int ans = 1e9;
	do {
		memset(pairs, 0, sizeof pairs);
		int nt = 0;
		for(int i=0; i<3; i++) {
			for(int j=0; j<cnt[vec[i]]; j++) {
				t[nt++] = '0' + vec[i];
			}
		}
		for(int i=0; i<n; i++) pairs[s[i] - '0'][t[i] - '0']++;
		int res = 0;
		for(int i=0; i<3; i++) {
			int j=(i+1)%3;
			int mn = min(pairs[i][j], pairs[j][i]);
			pairs[i][j] -= mn;
			pairs[j][i] -= mn;
			res += mn;
		}
		assert(pairs[1][0] == pairs[2][1] and pairs[2][1] == pairs[0][2]);
		assert(pairs[0][1] == pairs[1][2] and pairs[1][2] == pairs[2][0]);
		res += (pairs[1][0] + pairs[0][1]) * 2;
		ans = min(ans, res);
	} while(next_permutation(vec.begin(), vec.end()));
	cout << ans << endl;
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) solve();

}



