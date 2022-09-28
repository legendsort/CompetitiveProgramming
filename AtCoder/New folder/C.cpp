#include <bits/stdc++.h>

using namespace std;
using VI = vector<int>;

int n, x, y;

const int NN = 200011;
VI adj[NN];
VI path;

void dfs(int u, int fa=0) {
	path.push_back(u);
	if(u == y) {
		for(int x : path) cout << x << ' ';
		cout << endl;
		exit(0);
	}
	for(int v : adj[u]) if(v != fa) {
		dfs(v, u);	
	}
	path.pop_back();
}
	
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> x >> y;
	for(int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(x);
}



