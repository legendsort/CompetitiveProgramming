#include <bits/stdc++.h>

using namespace std;

int a[100111];


int check() {
	bool res = true;
	int n; cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	long long s = 0;
	int c = 0;
	for(int i=0; i<n; i++) {
		if(a[i] == 1) c++;
	}
	
		for(int i=0; i<n; i++) {
			if(a[i] != 1) s += a[i]-1;
		}
		return s & 1;
	
	
	
	
}

void solve() {
	puts(check() ? "CHEF": "CHEFINA");
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) solve();
}


