#include <bits/stdc++.h>

using namespace std;
const int NN = 200111;
vector<int> adj[NN];
int ans = 0;
int L[NN], R[NN];

long long dfs(int u, int fa=0) {
	long long mx = 0;
	for(int v : adj[u]) if(v != fa) {
		int res = dfs(v, u);
		mx += res;
	}
	if(mx == 0) {
		ans ++;
		mx = R[u];
	} else {
		if(mx < L[u]) ans ++, mx = R[u];
		else if(mx <= R[u]) mx = mx;
		else mx = R[u];
	}
	return mx;
}


void solve() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) adj[i].clear();
	ans  = 0;
	for(int i=2; i<=n; i++) {
		int p;
		scanf("%d", &p);
		adj[p].push_back(i);	
	}
	for(int i=1; i<=n; i++) scanf("%d %d", L+i, R+i);
	dfs(1);
	cout << ans << endl;
}
int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
//#endif
	int T;
	cin>>T;
	while(T--) solve();
	
}

