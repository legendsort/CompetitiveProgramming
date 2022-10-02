#include <bits/stdc++.h>

using namespace std;

int n, k;
const int NN = 200111;
vector<int> adj[NN];

int ok(int mid) {
		
}

void solve() {
	cin >> n >> k;
	for(int i=1; i<=n; i++) adj[i].clear();
	for(int i=2; i<=n; i++) {
		int u; cin >> u;
		adj[i].push_back(u);
	}
	int st=0, ed=n;
	while(ed>st+1) {
		int mid=st+ed>>1;
		if(ok(mid)) ed = mid;
		else st = mid;	
	}
	cout << st << endl;
	
					
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T; cin >> T;
	while(T--) solve();
}



