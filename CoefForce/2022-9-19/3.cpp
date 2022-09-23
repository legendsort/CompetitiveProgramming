#include <bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 5555;
char s[NN], t[NN];
INT dp[NN][3];
const INT inf = 1e18;

void smin(INT &u, INT v) {
	if(u > v) u = v;	
}

int solve(int n, int x, int y) {
	scanf("%s %s", s+1, t+1);
	dp[0][0] = 0;
	dp[0][1] = inf;
	dp[0][2] = inf;
	
	for(int i=1; i<=n; i++) {
		dp[i][0] = dp[i][1] = dp[i][2] = inf;
		if(s[i] == t[i]) {
			smin(dp[i][0], dp[i-1][0]);
			smin(dp[i][1], dp[i-1][1]);
			smin(dp[i][2], dp[i-1][2]);
			smin(dp[i][0], dp[i-1][2] + 2 * y);
		} else {
			smin(dp[i][1], dp[i-1][0] + y);
			smin(dp[i][0], dp[i-1][1]);
			smin(dp[i][2], dp[i-1][1] + y);
		}
		if(i>1 and s[i]!=t[i] and s[i-1]!=t[i-1]) {
			smin(dp[i][0], dp[i-2][0] + x);
			smin(dp[i][1], dp[i-2][1] + x);
			smin(dp[i][2], dp[i-2][2] + x);
		}
	}
	if(dp[n][0] > 1e15) dp[n][0] = -1;
	cout << dp[n][0] << endl;
	return 0;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, x, y;
		scanf("%d %d %d", &n, &x, &y);
		solve(n, x, y);	
	}
}
