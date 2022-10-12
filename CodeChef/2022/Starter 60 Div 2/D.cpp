#include <bits/stdc++.h>

using namespace std;
const int mod = 998244353;
const int NN = 2222;
int C[NN][NN];
int dp[NN][NN];

void add(int &u, int v) {
	u += v;
	u %= mod;
}

int power(int a, int n, int mod, int ans=1) {
	for(; n; n>>=1, a=1ll*a*a%mod) if(n&1) ans = 1ll * ans * a % mod;
	return ans;	
}

int calc(int n, int m) {
	if(n + m - 1 & 1) return 0;
	return 1ll * C[n+m-2][n-1] * C[n+m-1][n+m-1>>1] % mod * power(2, mod - 1 - (n + m -1), mod) % mod;	
}

int solve() {
	int n, m;
	cin >> n >> m;
	return 1ll * dp[n][m] * power(2, n * m, mod) % mod;
}

void pre() {
	C[0][0] = 1;
	for(int i=1; i<NN; i++) {
		for(int j=C[i][0]=1; j<=i; j++) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}
	}
	for(int i=1; i<1011; i++) {
		for(int j=1; j<1011; j++) {
			dp[i][j] = calc(i, j);
	
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    pre();
	int T; cin >> T;
    
	while(T--) cout << solve() << endl;

}



