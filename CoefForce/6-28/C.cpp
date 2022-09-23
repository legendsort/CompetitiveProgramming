#include <bits/stdc++.h>

using namespace std;

int a[200011];

int solve() {
	int n, k; cin >> n;
    int cnt0 = 0;
	vector<int> vec;
	map<long long, int> mp;
	for(int i=1; i<=n; i++) {
		cin >> a[i], cnt0 += a[i] == 0;
		if(a[i] != 0) vec.push_back(a[i]);
		mp[a[i]] = 1;
	}
	if(cnt0 == n) return 1;
	if(cnt0) vec.push_back(0);
	if(vec.size() > 22) return 0;
	int sz = vec.size();
	for(int i=0; i<sz; i++) {
		for(int j=i+1; j<sz; j++) {
			for(int k=j+1; k<sz; k++) {
				 long long c = 0ll + a[i] + a[j] + a[k];
				if(mp[c] == 0) return 0;
			}
		}
	}
	return 1;
    
	
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
    while(T--) {
    	if(solve()) puts("YES");
    	else puts("NO");
    	
    }
}


