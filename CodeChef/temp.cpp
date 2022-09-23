#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin >> T;
	
	while(T--) {
	    int n;
	    cin >> n;
	    map<int, int> mp;
	    int ans = 0;
	    int pre = 0;
	    mp[0]++;
	    for(int i=0; i<n; i++) {
	        int a;
	        cin >> a;
	        pre ^= a;
	        a = pre;
	        mp[a]++;
	        if(mp[a]>1) {
	            ans++;
	            mp.clear();
	            mp[0]++;
	        }
	    }
	    cout << ans << endl;
	}
	return 0;
}

