#include <bits/stdc++.h>

using namespace std;

int n;

void solve() {
	cin >> n;
	int st = 1, ed = n+1;
	while(ed > st + 1) {
		int mid = st + ed >> 1;
		cout << '?' << ' ' << 1 << ' ' << mid << endl;
		fflush(stdout);
		int a=0, b=0;
		map<int, int> mp;
		for(int i=1; i<=mid; i++) {
			int x; cin >> x; mp[x]=1;
			if(x>mid) a++;
		}
		for(int i=1; i<=mid; i++) if(mp[i] == 0) b++;
		if(a < b) st = mid+1;
		else ed = mid + 1;	
	}
	cout << "!" << ' ' << st << endl;	
	fflush(stdout);
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) solve();
}


