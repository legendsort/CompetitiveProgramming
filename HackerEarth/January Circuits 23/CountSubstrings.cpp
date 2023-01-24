#include <bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 1111;
const int MM = 222;
int n, m, K;
int dp[NN][MM][MM][2];
char s[NN], t[MM];
const int mod = 1e9 + 7;

void add(int &u, int v) {
	u += v;
	u %= mod;
}

void solve() {
	dp[0][0][0][1] = 1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<=m; j++) {
			for(int p=0; p<=K; p++) {
				if(dp[i][j][p][0]) {
					add(dp[i+1][j][p][1], dp[i][j][p][0]);
					if(s[i+1] == t[j+1]) {
						add(dp[i+1][j+1][p][0], dp[i][j][p][0]);
						add(dp[i+1][j+1][p+1][0], dp[i][j][p][0]);
					}
				}
				if(dp[i][j][p][1]) {
					add(dp[i+1][j][p][1], dp[i][j][p][1]);
					if(s[i+1] == t[j+1]) {
						add(dp[i+1][j+1][p+1][0], dp[i][j][p][1]);
					}
				}
				
			}
		}
	}
	int ans = (dp[n][m][K][0] + dp[n][m][K][1]) % mod;
	cout << ans << endl;
}

int main() {
    cin >> n >> m >> K;
    cin >> (s+1) >> (t+1);
	solve();
}



