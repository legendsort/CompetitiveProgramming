#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int x=0;
	int ans=0;
	vector<int> vec;
	for(int i=0; i<n; i++) {
		int a;cin>>a;
		if(x>=a && a) ans=-1;
		x+=a;
		vec.push_back(x);
	}
	if(ans==-1) cout<<-1<<endl;
	else {
		for(int u : vec) cout<<u<<' ';
		cout<<endl;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin >> T;
	while(T--) solve();
}



